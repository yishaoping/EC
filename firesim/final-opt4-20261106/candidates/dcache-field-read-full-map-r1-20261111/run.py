#!/usr/bin/python3
"""Map authenticated field-read-pruned complete DCache; reuse only a completed exact e0 reference.

This controller neither starts whole CAD nor admits hardware to runtime.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import re
import shutil
import subprocess
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-fit-dcache-field-read-full-map-r1-20261111'
S = D / 'Opt4-fit-dcache-field-read-full-map-r1-state.json'
COMMIT = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SID = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
BASE = 'e0c3737f989c563f99a00f3fd26c1cbd27421775'
TOP = 'BoomNonBlockingDCache'
REFERENCE_ROOT = D / 'build-logs/Opt4-fit-dcache-full-pair-r2-20261111'
PROOF_PASS = 'PASS_COMPLETE_GENERATED_DCACHE_SYMBOLIC_IDENTITY_ALL_STATE_OUTPUTS_OBSERVATIONS_AND_STATEMENTS_NOT_WHOLE_DUT'


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def read(p):
    p = Path(p)
    return json.loads(p.read_text()) if p.is_file() else {}


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(p, j):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def ident(pid):
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def live(j):
    current = ident(j.get('pid', 0))
    return bool(current and current['start_ticks'] == str(j.get('start_ticks'))
                and current['host_boot_id'] == j.get('host_boot_id')
                and current['process_state'] not in ['X', 'Z'])


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access'] and p['native_paused']


def resources_ready():
    memory = int(next(s.split()[1] for s in Path('/proc/meminfo').read_text().splitlines()
                      if s.startswith('MemAvailable:')))
    return memory >= 48 * 2**20 and shutil.disk_usage(W).free >= 40 * 2**30


def main():
    policy()
    L.mkdir(exist_ok=True)
    lock = (L / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    # Independent field-read implementation; the original d9 map and its
    # single exact reference producer remain live and immutable.
    prior = read(S)
    assert not live(prior) and not live(prior.get('child', {})), 'adopt live identity'
    assert not prior, 'use a reviewed versioned recovery for partial stages'
    manifest = read(C / 'input-hashes.json')
    assert manifest and all(sha(p) == h for p, h in manifest.items())
    st = dict(schema='ec-opt4-full-dcache-fieldbank-map/1', **ident(os.getpid()),
              hardware_commit=COMMIT, source_id=SID, parent_area_reference_commit=BASE,
              status='WAITING_ACTUAL_GENERATED_FIELD_PROOF', started_utc=now(),
              maps={}, fpga_access=False, production_admission=False,
              complete_dcache_cycles_verified=False, full_dut_formal=False,
              scope='Full DCache OOC area with all original ports and original dontTouch observations plus all512 generation outputs. Not whole capacity or FIT; complete frozen DCache cycle comparison remains required.')

    def update(**kw):
        st.update(kw)
        st['updated_utc'] = now()
        save(S, st)

    update()
    while True:
        policy()
        proof = read(D / 'Opt4-fit-dcache-field-read-generated-r1-state.json')
        if proof.get('status') == PROOF_PASS:
            assert proof['hardware_commit'] == COMMIT and proof['source_id'] == SID
            pr = D / 'build-logs/Opt4-fit-dcache-field-read-generated-r1-20261111/result.json'
            job = read(D / 'unattended-opt4/jobs/dcache-field-read-generated-r1-3656aec4/state.json')
            if job.get('status') != 'COMPLETE':
                update(status='WAITING_PROOF_ATOMIC_COMPLETION')
                time.sleep(60)
                continue
            assert job['returncode'] == 0 and job['outputs'][str(pr)] == sha(pr)
            assert read(pr) == proof
            assert proof['all_other_generated_modules_identical'] and proof['original_observations_preserved']
            break
        if proof.get('status') in ['FAILED_WITH_EVIDENCE', 'DEPENDENCY_FAILED_WITH_EVIDENCE', 'UNPROVEN_GENERATED_IDENTITY_MISMATCH_REQUIRES_REVIEW_NO_ADMISSION']:
            update(status='DEPENDENCY_FAILED_WITH_EVIDENCE', dependency_status=proof['status'])
            save(L / 'result.json', st)
            return
        update(dependency_status=proof.get('status'))
        time.sleep(300)
    save(L / 'generated-proof-receipt.json', proof)
    refs = dict(reference=read(D / 'Opt4-fit-update-share-svb-rtl-state.json'),
                candidate=read(D / 'Opt4-fit-dcache-field-read-rtl-state.json'))
    assert refs['reference']['hardware_commit'] == BASE
    assert refs['candidate']['hardware_commit'] == COMMIT and refs['candidate']['source_id'] == SID
    headers = {}
    observations = {}
    for label, receipt in refs.items():
        policy()
        src = Path(receipt['goldengate_dir']) / 'FireSim-generated.sv'
        assert sha(src) == receipt['outputs'][str(src)]
        text = src.read_text()
        match = re.search(r'^module ' + TOP + r'\((.*?)\);', text, re.M | re.S)
        assert match
        end = text.index('\nendmodule', match.end())
        body = text[match.end():end]
        headers[label] = re.sub(r'\s+', ' ', match.group(1)).strip()
        taps = set(re.findall(r'\bwire\s+\[31:0\]\s+(debug_line_generation_\d+)\s*=', body))
        assert taps == {'debug_line_generation_' + str(i) for i in range(512)}
        annotation = Path(receipt['elaboration_dir']) / 'firesim.firesim.FireSim.anno.json'
        names = []
        for row in read(annotation):
            if (row.get('class') == 'firrtl.transforms.DontTouchAnnotation'
                    and row.get('target', '').startswith('~FireSim|' + TOP + '>')):
                name = re.sub(r'[^A-Za-z0-9_$]', '_', row['target'].split('>', 1)[1]).rstrip('_')
                names.append(name)
        kept = []
        for name in sorted(set(names)):
            pat = (r'(?m)^(\s*)(wire|reg)(\s+(?:\[[^\]\n]+\]\s+)?)('
                   + re.escape(name) + r'(?:_\d+)*)(\s*(?:=|;))')

            def mark(m):
                kept.append(m.group(4))
                return m.group(1) + '(* keep = "true" *) ' + ''.join(m.group(i) for i in range(2, 6))

            body = re.sub(pat, mark, body)
        header = match.group(0)[:-2] + ',\n  output [16383:0] opt4_complete_generation_observation\n);'
        assign = '\n  assign opt4_complete_generation_observation = {' + ', '.join(
            'debug_line_generation_' + str(i) for i in reversed(range(512))) + '};\n'
        instrumented = text[:match.start()] + header + body + assign + text[end:]
        # Reference instrumentation must exactly reproduce the existing r2
        # area input; preserve that input and its in-flight mapping job.
        if label == 'reference':
            observed = REFERENCE_ROOT / 'reference/full-dcache-observed.sv'
            assert sha(observed) == hashlib.sha256(instrumented.encode()).hexdigest()
        else:
            observed = L / 'full-dcache-observed.sv'
            assert not observed.exists()
            observed.write_text(instrumented)
        observations[label] = dict(original=str(src), original_sha256=sha(src),
                                   observed=str(observed), observed_sha256=sha(observed),
                                   all_original_ports_preserved=True,
                                   generation_ports=512, generation_bits=16384,
                                   annotation_kept_signals=sorted(set(kept)))
    assert headers['candidate'] == headers['reference'], 'full interface must match'
    assert observations['candidate']['annotation_kept_signals'] == observations['reference']['annotation_kept_signals']
    save(L / 'paired-rtl-inputs.json', dict(inputs=observations, hardware_commit=COMMIT,
                                          source_id=SID, original_annotations_preserved=True))
    update(inputs=observations, status='READY_ACTUAL_FULL_DCACHE_CANDIDATE_MAPPING')
    while not resources_ready():
        policy()
        update(status='WAITING_MODULE_MEMORY_DISK_GATE')
        time.sleep(300)
    policy()
    report = L / 'utilization.rpt'
    dcp = L / 'module.dcp'
    tcl = L / 'map.tcl'
    tcl.write_text('set_param general.maxThreads 2\n'
                   'set_param synth.elaboration.rodinMoreOptions {rt::set_parameter dissolveMemorySizeLimit 74752}\n'
                   f'read_verilog -sv {{{observations["candidate"]["observed"]}}}\n'
                   f'synth_design -mode out_of_context -top {TOP} -part xcu280-fsvh2892-2L-e\n'
                   'set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]\n'
                   'if {[llength $bb]} {error "unresolved DCache dependencies"}\n'
                   f'report_utilization -file {{{report}}}\n'
                   f'report_utilization -hierarchical -hierarchical_depth 25 -file {{{L/"hierarchical.rpt"}}}\n'
                   f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
    log = L / 'map-attempt-1.log'
    assert not log.exists()
    argv = ['nice', '-n', '15', '/tools/Xilinx/Vivado/2021.1/bin/vivado',
            '-mode', 'batch', '-nojournal', '-log', str(L / 'vivado-attempt-1.log'), '-source', str(tcl)]
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(argv, cwd=L, env={**os.environ, 'LD_LIBRARY_PATH': '',
                                 'OMP_NUM_THREADS': '2', 'TMPDIR': str(L)},
                                 stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
        update(status='RUNNING_ACTUAL_FULL_DCACHE_FIELD_CANDIDATE_SYNTH', child=ident(child.pid))
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(f.fileno())
            update()
    assert child.returncode == 0 and report.is_file() and dcp.is_file(), (child.returncode, str(log))
    counts = {}
    for line in report.read_text().splitlines():
        match = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)\s*\|', line)
        if match:
            counts.setdefault(match[1].rstrip('*'), float(match[2].replace(',', '')))
    assert len(counts) == 5 and counts['CLB LUTs'] > 0
    row = dict(hardware_commit=COMMIT, source_id=SID, returncode=0, resources=counts,
               rtl_sha256=observations['candidate']['observed_sha256'], report=str(report),
               report_sha256=sha(report), checkpoint=str(dcp), checkpoint_sha256=sha(dcp),
               log=str(log), log_sha256=sha(log), tcl_sha256=sha(tcl))
    save(L / 'candidate-map-result.json', row)
    st['maps']['candidate'] = row
    update(status='CANDIDATE_MAPPED_WAITING_EXISTING_EXACT_REFERENCE', child={})
    while True:
        policy()
        ref = read(REFERENCE_ROOT / 'reference/map-result.json')
        if ref.get('returncode') == 0:
            break
        producer = read(D / 'Opt4-fit-dcache-full-pair-r2-state.json')
        if producer.get('status') == 'FAILED_WITH_EVIDENCE' and not live(producer) and not live(producer.get('child', {})):
            update(status='CANDIDATE_MAPPED_REFERENCE_FAILURE_REQUIRES_REVIEWED_CONTINUATION',
                   reference_status=producer['status'])
            save(L / 'result.json', st)
            return
        update(reference_status=producer.get('status'))
        time.sleep(300)
    assert ref['hardware_commit'] == BASE
    assert ref['rtl_sha256'] == observations['reference']['observed_sha256']
    assert sha(ref['report']) == ref['report_sha256']
    assert Path(ref['checkpoint']).is_file()
    st['maps']['reference'] = ref
    saved = ref['resources']['CLB LUTs'] - counts['CLB LUTs']
    update(status='COMPLETE_REAL_FULL_DCACHE_FIELD_OBSERVED_PAIR_NOT_WHOLE_FIT_NOT_CYCLE_ADMITTED',
           lut_saved=saved, significant_area_gain=saved >= 75000,
           reference_reused_without_duplicate_mapping=True, ended_utc=now())
    save(L / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        st = read(S)
        if st.get('pid') == os.getpid():
            st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
            save(S, st)
        raise
