#!/usr/bin/python3
"""Isolated, proof-bound host clock metadata repair; no target or live edits."""
from pathlib import Path
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
import resource
import shutil
import subprocess
import sys
import time
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-mt-clock-repair-round39-v2-20261111'
S = D / 'Opt4-mt-clock-repair-round39-v2-state.json'
A = W / 'candidates/mt-channel-audit-round38-v1-20261111'
AUDIT = D / 'build-logs/Opt4-mt-channel-audit-round38-v1-20261111/result.json'
SAVED = D / 'cycleprecise-frozen-mt-mcrams-r1-20261111/goldengate'
NAME = 'mt-clock-repair-r39-v2-8491167d'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
ST = {}

def read(path):
    return json.loads(Path(path).read_text())

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(4 * 2**20), b''):
            h.update(block)
    return h.hexdigest()

def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()

def save(path, value):
    path = Path(path)
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(temp, path)

def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p

def identity(pid):
    try:
        st = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=st[19],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}

def update(**kw):
    ST.update(kw, updated_utc=now())
    save(S, ST)

def prepare():
    policy()
    assert not O.exists() and not S.exists() and not (C / 'plan.json').exists()
    audit = read(AUDIT)
    assert audit['status'] == 'PASS_ALL_CONFLICT_CLOCKS_WIRE_IDENTICAL_NO_REPAIR_APPLIED'
    assert audit['functional_baseline'] == BASE and len(audit['conflicts']) == 24
    assert all(c['identical_payload'] and c['wire_identical_clock'] for c in audit['conflicts'])
    old = read(SAVED.parent / 'state.json')
    assert old['status'] == 'FAILED_WITH_EVIDENCE'
    assert identity(old['pid']) != {k: old[k] for k in ['pid', 'start_ticks', 'host_boot_id']}
    cfgpath = W / 'candidates/address-update-sequence-r1-20261111/config.json'
    cfg = read(cfgpath)
    sources = [C / 'controller.py', C / 'Check.scala', A / 'controller.py', cfgpath, AUDIT,
               SAVED / 'post-channel-excision.fir', SAVED / 'post-channel-excision.json']
    sources += [Path(p) for p in cfg['classpath'] + cfg['compiler']]
    originals = {str(p): sha(p) for p in dict.fromkeys(sources)}
    for name in ['post-channel-excision.fir', 'post-channel-excision.json']:
        assert originals[str(SAVED / name)] == audit['inputs'][str(SAVED / name)]
    capsule = C / 'evidence'; capsule.mkdir()
    bound, copies = {}, {}
    for name, digest in originals.items():
        path = Path(name)
        if path.resolve().is_relative_to(W):
            bound[name] = digest
        else:
            dst = capsule / (digest[:16] + '-' + path.name)
            shutil.copy2(path, dst)
            assert sha(dst) == digest
            bound[str(dst)] = digest; copies[name] = str(dst)
    plan = dict(schema='ec-opt4-isolated-host-clock-metadata-plan/1',
                functional_baseline=BASE, inputs=bound, original_inputs=originals,
                copies=copies, cfg=cfg, source_checkpoint_sha256=originals[str(SAVED / 'post-channel-excision.fir')],
                scope='Saved host compiler checkpoint only; no target source, libraries, or live inputs changed',
                whole_fit=False, fpga_access=False, memory_limit_gib=64,
                guard_memory_gib=96, guard_disk_gib=100, created_utc=now())
    save(C / 'plan.json', plan)
    bound = {**bound, str(C / 'plan.json'): sha(C / 'plan.json')}
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='rtl', cwd=str(C),
                   argv=['/usr/bin/python3', str(C / 'controller.py'), '--run'],
                   inputs=bound, outputs=[str(O / 'result.json')], checkpoints=[str(S)]))
    save(C / 'request.json', request)
    print(json.dumps(dict(request=str(C / 'request.json'), inputs=len(bound))))

def stage(name, argv, timeout):
    policy()
    log = O / (name + '.log')
    started = time.monotonic()
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str, argv)), cwd=O, stdin=subprocess.DEVNULL,
                                 stdout=f, stderr=subprocess.STDOUT,
                                 env={**os.environ, 'OMP_NUM_THREADS': '2'})
        update(status='RUNNING_' + name.upper(), child=identity(child.pid), stage_log=str(log))
        while True:
            try:
                rc = child.wait(timeout=30)
                break
            except subprocess.TimeoutExpired:
                policy(); update(stage_wall_seconds=time.monotonic() - started)
                if time.monotonic() - started > timeout:
                    child.terminate()
                    try: child.wait(timeout=30)
                    except subprocess.TimeoutExpired: child.kill(); child.wait()
                    raise RuntimeError(('owned_stage_timeout', name))
    receipt = dict(argv=list(map(str, argv)), returncode=rc, log=str(log),
                   log_sha256=sha(log), wall_seconds=time.monotonic() - started,
                   child_peak_rss_kib=resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss)
    save(O / (name + '-receipt.json'), receipt)
    update(child={})
    assert rc == 0, (name, rc, str(log))
    return receipt

def run():
    policy()
    assert not O.exists() and not S.exists(), 'Adopt existing job; never overwrite partial evidence'
    plan = read(C / 'plan.json')
    for path, digest in plan['inputs'].items():
        assert sha(path) == digest, ('changed_bound_input', path)
    O.mkdir()
    lock = (O / 'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    ST.update(schema='ec-opt4-isolated-host-clock-metadata-state/1', **identity(os.getpid()),
              functional_baseline=BASE, fpga_access=False, started_utc=now())
    update(status='WAITING_MEMORY_DISK_GUARDS')
    while True:
        policy()
        avail = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
        if avail >= plan['guard_memory_gib'] * 2**20 and shutil.disk_usage(O).free >= plan['guard_disk_gib'] * 2**30:
            break
        time.sleep(300)
    resource.setrlimit(resource.RLIMIT_AS, (plan['memory_limit_gib'] * 2**30,) * 2)
    auditmod = importlib.util.spec_from_file_location('clock_audit', A / 'controller.py')
    audit = importlib.util.module_from_spec(auditmod); auditmod.loader.exec_module(audit)
    fir = Path(plan['copies'][str(SAVED / 'post-channel-excision.fir')])
    anno = Path(plan['copies'][str(SAVED / 'post-channel-excision.json')])
    annos = read(anno)
    circuit, modules = audit.parse_fir(fir)
    proof = audit.analyze(circuit, modules, annos)
    assert len(proof['conflicts']) == 24
    for chain in proof['clock_proofs'].values():
        assert chain['status'] == 'WIRE_ALIAS_RESOLVED'
        for step in chain['chain']:
            m = modules[step['module']]; ref = step['reference']
            if '.' in ref:
                instance, port = ref.split('.')
                assert modules[m['instances'][instance]]['ports'][port]['type'] == 'Clock'
            else:
                assert m['ports'][ref]['type'] == 'Clock'
    assert all(c['identical_payload'] and c['wire_identical_clock'] for c in proof['conflicts'])
    channels = {c[k]['channel'] for c in proof['conflicts'] for k in ['a', 'b']}
    canonical = '~FAMETop|FAMETop>synthesizedPrintf_clockBridge_clocks_1'
    repaired = json.loads(json.dumps(annos)); delta = []
    for a, b in zip(annos, repaired):
        if a.get('globalName') in channels and a.get('clock') != canonical:
            delta.append(dict(channel=a['globalName'], old_clock=a['clock'], canonical_clock=canonical))
            b['clock'] = canonical
        assert {k:v for k,v in a.items() if k != 'clock'} == {k:v for k,v in b.items() if k != 'clock'}
    assert len(delta) == 12 and len(annos) == len(repaired)
    # The parser independently reproduces zero overlaps after canonicalization.
    try:
        audit.analyze(circuit, modules, repaired)
    except AssertionError as e:
        assert str(e) == 'Saved failure not reproduced by independent port audit'
    else:
        raise AssertionError('Unresolved overlaps remain')
    save(O / 'wire-proof-and-delta.json', dict(proof=proof, delta=delta, negative_checks=audit.negative_checks(),
          original_channel_count=1747, preserved_all_payloads_and_other_metadata=True,
          target_circuit_changed=False, checkpoint_sha256=plan['source_checkpoint_sha256']))
    save(O / 'repaired-channel-metadata.json', repaired)
    del modules, proof, annos, repaired
    cfg = plan['cfg']; cp = ':'.join(cfg['classpath'])
    classes = O / 'classes'; classes.mkdir()
    compile_receipt = stage('compile-check', [cfg['java'], '-Xmx4G', '-Xss8M', '-XX:ActiveProcessorCount=2',
        '-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', cp,
        '-d', classes, C / 'Check.scala'], 300)
    check_receipt = stage('original-pass-check', [cfg['java'], '-Xmx32G', '-Xss8M', '-XX:ActiveProcessorCount=2',
        '-cp', str(classes) + ':' + cp, 'opt4hostclockrepair.Check', fir, anno,
        O / 'repaired-channel-metadata.json', O], 3600)
    assert 'ORIGINAL_FAME_TRANSFORM_AND_RESOLVE_PASS' in (O / 'original-pass-check.log').read_text()
    result = dict(schema='ec-opt4-isolated-host-clock-metadata-result/1',
        status='PASS_ORIGINAL_INFER_AND_FAME_WITH_PROVEN_CLOCK_METADATA_ONLY_NOT_FULL_HOST_OR_MT_SHARING',
        functional_baseline=BASE, changed_clock_annotations=12, channel_count=1747,
        exact_wire_alias_conflicts=24, target_circuit_changed=False, live_inputs_changed=False,
        original_rejection_preserved=True, restored_clock_mutation_rejected=True,
        compile=compile_receipt, check=check_receipt, plan_sha256=sha(C / 'plan.json'),
        outputs={str(p): sha(p) for p in O.iterdir() if p.is_file()},
        whole_fit=False, fpga_access=False, formal_fpga_sample=False, completed_utc=now(),
        limitations=['Original passes validate a saved checkpoint; no universal equivalence claim',
                     'Full GoldenGate continuation and same-target runtime parity still required',
                     'All five annotated tile module classes are singletons; no MT sharing gain inferred',
                     'Specialized Rocket sharing requires separate equivalence before enabling it'])
    save(O / 'result.json', result); update(status=result['status'], result=str(O / 'result.json'))
    print(result['status'], flush=True)

if __name__ == '__main__':
    if '--prepare' in sys.argv:
        prepare()
    elif '--run' in sys.argv:
        try: run()
        except BaseException as e:
            if O.exists():
                save(O / 'failure.json', dict(error=repr(e), traceback=traceback.format_exc(), utc=now()))
                update(status='FAILED_WITH_EVIDENCE', error=repr(e))
            raise
    else:
        raise SystemExit('Use --prepare or --run')
