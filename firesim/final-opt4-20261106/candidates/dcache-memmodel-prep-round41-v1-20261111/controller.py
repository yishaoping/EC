#!/usr/bin/python3
"""Prepare exact-target host annotations only; no GG, synthesis, or FPGA I/O."""
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
L = D / 'build-logs/Opt4-dcache-memmodel-prep-round41-v1-20261111'
S = D / 'Opt4-dcache-memmodel-prep-round41-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SOURCE_ID = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
ST = {}


def read(p):
    return json.loads(Path(p).read_text())


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def save(p, value):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def identity(pid):
    fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
    return dict(pid=pid, start_ticks=fields[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and p['native_paused']
    assert not p['functional_extensions_allowed'] and not p['fpga_access']
    return p


def update(**kw):
    ST.update(kw, updated_utc=now())
    save(S, ST)


def stage(name, argv, outputs):
    policy()
    log = L / (name + '.log')
    receipt = L / 'receipts' / (name + '.json')
    if receipt.exists():
        old = read(receipt)
        assert old['returncode'] == 0 and all(sha(p) == h for p, h in old['outputs'].items())
        return
    assert not log.exists(), 'Preserve partial stage; independent recovery required'
    start = time.monotonic()
    with log.open('xb') as f:
        proc = subprocess.Popen(argv, cwd=C, stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
        update(status='RUNNING_' + name.upper(), child=identity(proc.pid), stage_log=str(log))
        try:
            rc = proc.wait(timeout=1200)
        except subprocess.TimeoutExpired:
            proc.terminate()
            try:
                proc.wait(timeout=20)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait()
            rc = 'TIMEOUT_OWN_CHILD'
        f.flush()
        os.fsync(f.fileno())
    save(receipt, dict(argv=argv, returncode=rc, completed_utc=now(), wall_seconds=time.monotonic()-start,
                       log=str(log), log_sha256=sha(log), outputs={str(p): sha(p) for p in outputs if p.is_file()}))
    update(child={})
    assert rc == 0 and all(p.is_file() for p in outputs), (name, rc, str(log))


def main():
    policy()
    L.mkdir(parents=True, exist_ok=True)
    lock = (L / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if (L / 'result.json').exists():
        assert read(L / 'result.json')['status'].startswith('PASS_')
        return
    os.sched_setaffinity(0, sorted(os.sched_getaffinity(0))[:2])
    resource.setrlimit(resource.RLIMIT_AS, (24*2**30, 24*2**30))
    ST.update(schema='ec-opt4-exact-target-memmodel-preparation/1', **identity(os.getpid()),
              functional_baseline=BASE, derived_hardware_commit=HW, source_id=SOURCE_ID,
              fpga_access=False, production_admission=False, target_transformed=False,
              full_dut_equivalence=False, started_utc=now(), cpus=sorted(os.sched_getaffinity(0)))
    update(status='VERIFYING_BOUND_INPUTS')
    plan = read(C / 'plan.json')
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    cfg = read(plan['config'])
    inv = read(plan['entry_inventory'])
    assert inv['derived_hardware_commit'] == HW and inv['functional_baseline'] == BASE
    assert all(sha(p) == h for p, h in inv['inputs'].items())
    proof = read(plan['generated_identity'])
    assert proof['hardware_commit'] == HW and proof['source_id'] == SOURCE_ID
    assert proof['status'] == 'PASS_COMPLETE_GENERATED_DCACHE_RESTRICTED_PREDICATE_IDENTITY_ALL_STATE_OUTPUTS_OBSERVATIONS_AND_STATEMENTS_NOT_WHOLE_DUT'
    raw, anno, low = map(Path, (plan['target_fir'], plan['target_annotations'], plan['lowered_target']))
    annotations = read(anno)
    cls = 'midas.targetutils.FirrtlMemModelAnnotation'
    existing = [a for a in annotations if a.get('class') == cls]
    assert len(existing) == 10
    wanted = ['ownerImageMemory', 'ownerGenerationMemory', 'ownerPacketMemory', 'ownerTrackedMemory']
    added = [dict(**{'class': cls}, target='~FireSim|BoomNonBlockingDCache>' + name) for name in wanted]
    assert not {a['target'] for a in existing} & {a['target'] for a in added}
    # Copy every original observation/bridge/MT annotation exactly in order.
    staged = L / 'four-owner-memories.anno.json'
    save(staged, annotations + added)
    assert read(staged)[:-4] == annotations
    # Inventory the entire address module without pretending its RegVec state
    # is DefMemory. Existing actual RAMs are distinct from dominant RegVecs.
    module = None
    address_memories = []
    address_regs = []
    dcache_memories = {}
    with raw.open() as f:
        for line in f:
            found = re.match(r'  module (\w+) :', line)
            if found:
                module = found[1]
            if module == 'PackageAddressStats':
                if re.match(r'    (?:cmem|smem|mem) ', line):
                    address_memories.append(line.strip())
                if line.startswith('    reg '):
                    address_regs.append(line.strip())
            if module == 'BoomNonBlockingDCache':
                found = re.match(r'    cmem (owner\w+Memory) : (.*)', line)
                if found:
                    dcache_memories[found[1]] = found[2]
    assert set(dcache_memories) == set(wanted)
    assert len(address_memories) == 24 and len(address_regs) == 37
    expected_reads = dict(ownerImageMemory_flattened=35, ownerGenerationMemory=518, ownerPacketMemory=4, ownerTrackedMemory=4)
    lowered = {name: {k: v for k, v in inv['memories'][name].items() if k != 'text'} for name in expected_reads}
    assert all(len(lowered[name]['readers']) == reads for name, reads in expected_reads.items())
    # Preserve the actual full generation fanout in the downstream contract.
    assert lowered['ownerGenerationMemory']['depth'] == 512
    assert all(x['read_latency'] == 0 and x['write_latency'] == 1 and x['read_under_write'] == 'undefined' for x in lowered.values())
    save(L / 'memory-coverage.json', dict(added=added, preserved_original_memory_annotations=existing,
         dcache_raw_declarations=dcache_memories, lowered_memories=lowered,
         address_existing_memory_declarations=address_memories, address_register_declarations=address_regs,
         address_annotation_added=False, generation_observation_readers_preserved=518,
         limitations=['No target transition or host MCRams equivalence proved by annotation preparation.',
                      'All512 generation observations and all518 generation read ports must survive later transformation.',
                      'Dominant address RegVec state requires separately verified structural conversion; annotations cannot convert registers.',
                      'Corrected complete Plain/MC area pair, transformed full-module comparison and metasim are still required.']))
    classes = L / 'classes'
    classes.mkdir(exist_ok=True)
    java = [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=2']
    stage('compile', java + ['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']),
          '-d', str(classes), str(C / 'Check.scala')], [classes / 'opt4memmodelprep/Check.class'])
    stage('resolve', java + ['-cp', str(classes) + ':' + ':'.join(cfg['classpath']), 'opt4memmodelprep.Check',
          str(raw), str(anno), str(staged)], [])
    assert 'PASS_UNCHANGED_TARGET_AST_MEMORY_ANNOTATION_RESOLUTION' in (L / 'resolve.log').read_text()
    assert sha(raw) == plan['inputs'][str(raw)] and sha(anno) == plan['inputs'][str(anno)]
    update(status='PASS_EXACT_TARGET_FOUR_MEMORY_ANNOTATIONS_RESOLVED_NOT_TRANSFORMED_OR_ADMITTED',
           target_fir=str(raw), target_fir_sha256=plan['inputs'][str(raw)], annotated_json=str(staged),
           annotated_json_sha256=sha(staged), added_annotations=4, preserved_memory_annotations=10,
           negative_cases_rejected=4, generation_read_ports=518,
           next='Wait corrected complete real-entry area. Run independent full-module MCRams transformation/parity with every original observation and all518generation readers; no whole CAD admission or area inference.')
    save(L / 'result.json', ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if L.exists():
            update(status='FAILED_WITH_EVIDENCE', error=repr(exc))
            save(L / 'failure.json', ST)
        raise
