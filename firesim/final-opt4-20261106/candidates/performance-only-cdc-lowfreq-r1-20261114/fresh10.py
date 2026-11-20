#!/usr/bin/env python3
"""Wait once for current owner; only a failed route admits fresh placement."""
import argparse
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import select
import subprocess

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'performance-only-cdc-lowfreq-r1-20261114'
F = D/'performance-only-memory-cdc-r2-20261114/complete-shell-r3'
NAME = 'mem-10mhz-fresh-ssi-r3'
PRIOR = 'mem-10mhz-recovery-r2'
HW = '6e1e9b966d599c442b3bdf2f3a838aae2ee5c6da'
FILES = ['fresh10.py', 'fresh-physical.tcl', 'fresh-host-clock.tcl',
         'fresh-routing.tcl', 'fresh-after-physical.py', 'final-bitstream-gates.tcl']


def read(p): return json.loads(p.read_text())
def sha(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''): h.update(block)
    return h.hexdigest()
def save(p, row):
    tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(row, indent=2)+'\n'); os.replace(tmp, p)
def state(status, **kw):
    save(O/'fresh10-state.json', dict(status=status,
         utc=dt.datetime.now(dt.timezone.utc).isoformat(),
         periodic_patrol=False, model_requests=False, **kw))


def admit():
    admission = read(O/'admission.json')
    receipt = read(F/'implementation-result.json')
    cp = Path(admission['checkpoint'])
    assert cp == F/'shell-postopt.dcp'
    assert admission['hardware_commit'] == receipt['hardware_commit'] == HW
    assert receipt['returncode'] == 0
    assert sha(cp) == admission['sha256'] == receipt['outputs'][str(cp)]
    assert receipt['source_id'] == read(F/'hardware-binding.json')['source_id']
    binding = read(C/'fresh10-binding.json')
    for name, digest in binding['files'].items(): assert sha(C/name) == digest, name
    assert not (O/'physical/candidates'/NAME).exists()
    code = (C/'fresh-physical.tcl').read_text()
    for token, path in [('@CHECKPOINT@', cp), ('@CLOCK@', C/'fresh-host-clock.tcl'),
                        ('@ROUTING@', C/'fresh-routing.tcl')]:
        code = code.replace(token, str(path))
    assert 'routed.dcp' not in code and 'physopt.dcp' in code
    return cp, code


def timing_evidence(directory):
    report = directory/'timing.rpt'
    if not report.exists(): return dict(status='FINAL_TIMING_REPORT_NOT_AVAILABLE')
    rows = []
    for block in re.split(r'(?=Slack \()', report.read_text()):
        match = re.match(r'Slack \([^)]*\)\s*:\s*([-\d.]+)', block)
        if not match or not re.search(r'Path Type:\s*Setup', block): continue
        keep = block.split('    Location', 1)[0]
        rows.append(dict(slack_ns=float(match[1]), path=keep))
    return dict(report=str(report), sha256=sha(report),
                worst_setup_paths=sorted(rows, key=lambda r:r['slack_ns'])[:3],
                host_clock_contract=(directory/'clock-contract.txt').read_text())


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--wait-pid', type=int)
    ap.add_argument('--start-ticks')
    ap.add_argument('--check-only', action='store_true')
    a = ap.parse_args()
    cp, code = admit()
    if a.check_only:
        print(json.dumps(dict(status='PASS', checkpoint=str(cp),
              sha256=sha(cp), candidate=NAME, synthesis=False,
              prior_physical_checkpoint_reused=False)))
        return
    assert a.wait_pid and a.start_ticks
    # pidfd is a single completion event, not a periodic observer. It cannot
    # signal or stop the current implementation and is safe against PID reuse.
    try:
        fd = os.pidfd_open(a.wait_pid)
        fields = Path(f'/proc/{a.wait_pid}/stat').read_text().rsplit(') ', 1)[1].split()
        assert fields[19] == a.start_ticks, 'Owner PID identity changed'
        state('WAITING_CURRENT_OWNER_COMPLETION_EVENT', owner_pid=a.wait_pid,
              next_candidate=NAME, checkpoint=str(cp))
        poller = select.poll(); poller.register(fd, select.POLLIN)
        poller.poll(); os.close(fd)
    except ProcessLookupError:
        assert (O/'physical/candidates'/PRIOR/'result.json').exists()
    prior_dir = O/'physical/candidates'/PRIOR
    prior = read(prior_dir/'result.json')
    assert prior['candidate'] == PRIOR and sha(prior_dir/'run.tcl') == prior['tcl_sha256']
    save(O/'fresh10-prior-timing-evidence.json', timing_evidence(prior_dir))
    if prior.get('bitstream_generated'):
        state('CURRENT_RECOVERY_SUCCEEDED_NO_FRESH_CAD_STARTED', result=prior)
        return
    spec = importlib.util.spec_from_file_location('fresh_physical_engine',
        W/'candidates/performance-only-routability-r1-20261114/campaign.py')
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    if (prior_dir/'route-status.rpt').exists() and m.route_metrics(prior_dir/'route-status.rpt')['legal']:
        state('CURRENT_ROUTE_LEGAL_PRESERVE_FOR_TIMING_REPAIR', result=prior)
        return
    os.sched_setaffinity(0, set(range(240, 248)))
    with (O/'owner.lock').open('a') as owner, (D/'.performance-only-physical.lock').open('a') as lock:
        # Waiting for the completed owner and taking its lock serialize CAD.
        fcntl.flock(owner, fcntl.LOCK_EX)
        fcntl.flock(lock, fcntl.LOCK_EX)
        cp, code = admit()
        state('STARTING_FRESH_POSTOPT_10MHZ_IMPLEMENTATION', checkpoint=str(cp), prior=prior)
        save(O/'fresh10-input-receipt.json', dict(checkpoint=str(cp), sha256=sha(cp),
             hardware_commit=HW, baseline='6fada307', full_EC=False,
             synthesis_repeated=False, prior_physical_checkpoint_reused=False,
             placement='SSI_SpreadLogic_high', physical='fanout/placement/SLR crossing',
             routing='Explore', files=read(C/'fresh10-binding.json')['files']))
        root = read(O/'state.json')
        root.update(status='RUNNING_FRESH_POSTOPT_10MHZ_IMPLEMENTATION', candidate=NAME,
             cad_status='RECOVERY_CONTROLLER_ACTIVE', cad_child=None, cad_stage='fresh_postopt_open',
             checkpoint=str(cp), live_physical_state=str(O/'physical/state.json'))
        save(O/'state.json', root)
        m.EXTERNAL_HANDOFF_DISABLED = True; m.O = O/'physical'
        m.ST.update(hardware_commit=HW, functional_baseline='6fada307bb77be90b39720d3f95404fece0e431b',
             profile='EC Performance-Only: CDC Mem fresh 10 MHz SSI placement', candidates=[])
        result = m.run(NAME, code)
        result['nominal_host_mhz'] = 10
        save(O/'result.json', result)
        root.update(status='BITSTREAM_GENERATED_21_ONLY_CERTIFICATION_PENDING' if result['bitstream_generated']
             else 'FRESH_10MHZ_IMPLEMENTATION_FAILED_WITH_EVIDENCE',
             cad_status='COMPLETED' if result['bitstream_generated'] else 'EXITED_WITH_FAILURE',
             cad_child=None, cad_stage='physical_complete', last_result=result,
             bitstream=str(m.O/'candidates'/NAME/'firesim.bit') if result['bitstream_generated'] else None)
        root.setdefault('candidates', []).append(result); save(O/'state.json', root)
        save(O/'fresh10-final-timing-evidence.json', timing_evidence(m.O/'candidates'/NAME))
        state('BITSTREAM_GENERATED' if result['bitstream_generated'] else 'FAILED_WITH_EVIDENCE', result=result)
    clean = {k:v for k,v in os.environ.items()
             if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD']}
    subprocess.run(['/usr/bin/python3','-I',str(C/'fresh-after-physical.py')], env=clean, check=True)


if __name__ == '__main__':
    try: main()
    except Exception as exc:
        state('FRESH_IMPLEMENTATION_CONTROLLER_FAILED_WITH_EVIDENCE', error=repr(exc))
        root = read(O/'state.json')
        if root.get('candidate') == NAME:
            root.update(status='FRESH_10MHZ_CONTROLLER_FAILED_WITH_EVIDENCE',
                        cad_status='EXITED_WITH_ERROR', error=repr(exc))
            save(O/'state.json', root)
        raise
