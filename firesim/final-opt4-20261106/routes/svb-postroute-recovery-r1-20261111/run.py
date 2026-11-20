#!/usr/bin/python3
"""Conditional post-route repair of an exited original SVB physical branch.

Default/--inspect is read-only. This file is not installed as a service.
--run must pass failure, PID, source, disk and concurrency admission first.
No RTL synthesis, target changes, clock relaxation or device operations.
"""
import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PREP = D/'cycleprecise-frozen-svb-fpga-r2-20261111'
SPREAD = D/'cycleprecise-svb-spread-implementation-r1-20261111'
OUTPUT = D/'cycleprecise-svb-postroute-recovery-r1-20261111'
SOURCES = {
    'spread': (SPREAD/'state.json', SPREAD/'spread-routed.dcp',
               'ec-opt4-original-svb-spread-impl-r1.service'),
    'original': (PREP/'cad-state.json',
                 PREP/'project/cad/vivado_proj/firesim.runs/impl_1/design_1_wrapper_routed.dcp',
                 'ec-opt4-frozen-svb-fpga-r2.service'),
}
PHYSOPT = {
    'spread': SPREAD/'spread-physopt.dcp',
    'original': PREP/'project/cad/vivado_proj/firesim.runs/impl_1/design_1_wrapper_physopt.dcp',
}


def unit_active(unit):
    p = subprocess.run(['systemctl', 'show', unit, '-p', 'ActiveState', '--value'],
                       capture_output=True, text=True, check=True)
    return p.stdout.strip()


def unit_empty(unit):
    p = subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ControlGroup','-p','TasksCurrent'],
                       capture_output=True,text=True,check=True)
    values = dict(x.split('=',1) for x in p.stdout.splitlines() if '=' in x)
    if values.get('MainPID') != '0':
        return False
    tasks = values.get('TasksCurrent','')
    group = values.get('ControlGroup','')
    if group:
        cg = Path('/sys/fs/cgroup/systemd')/group.lstrip('/')
        if cg.exists():
            if not (cg/'cgroup.procs').is_file():
                return False
            for file in cg.rglob('cgroup.procs'):
                if file.read_text().strip():
                    return False
            return True
        return tasks == '0'
    return tasks in ['0', '', '[not set]', '18446744073709551615']


def eligibility(which, mode='postroute'):
    state, checkpoint, unit = SOURCES[which]
    if mode == 'replicate':
        checkpoint = PHYSOPT[which]
    r = read(state)
    failures = []
    if r.get('status') != 'FAILED_WITH_EVIDENCE':
        failures.append('producer has not exited with recorded failure')
    if live(r) or live(r.get('child', {})):
        failures.append('producer/controller child identity still live')
    if unit_active(unit) not in ['failed', 'inactive']:
        failures.append('producer service still active')
    if not unit_empty(unit):
        failures.append('producer service still owns tasks or task count unknown')
    if not checkpoint.is_file():
        failures.append('no saved '+('routed' if mode == 'postroute' else 'physopt')+' checkpoint')
    if r.get('functional_baseline', r.get('hardware_commit')) != BASE or r.get('source_id') != SID:
        failures.append('source identity mismatch')
    if (SPREAD/'original-svb-spread.bit').exists() or read(PREP/'cad-logs/result.json').get('certified_bitstream'):
        failures.append('existing successful physical product takes priority')
    return dict(eligible=not failures, reasons=failures, producer=which, mode=mode,
                producer_state=str(state), checkpoint=str(checkpoint),
                producer_identity={k:r[k] for k in ['pid','start_ticks','host_boot_id','status'] if k in r},
                unit=unit, fpga_access=False, target_changed=False)


def seal(which, mode, out):
    row = eligibility(which, mode)
    assert row['eligible'], row
    producer = read(PREP/'cad-state.json')
    assert producer['source_id'] == SID and producer['hardware_commit'] == BASE
    assert producer['inputs']['shell_interface_equal']
    for p, h in producer['inputs']['generated'].items():
        assert sha(p) == h, ('generated input changed', p)
    for r in producer['inputs']['shell_checkpoints']:
        assert sha(r['path']) == r['sha256']
    if which == 'spread':
        admission = read(SPREAD/'resource-admission.json')
        assert admission['producer_untouched']
        for p,h in admission['inputs'].items():
            assert sha(p) == h, ('spread input changed', p)
    p = Path(row['checkpoint'])
    target = out/('sealed-'+('routed' if mode == 'postroute' else 'physopt')+'.dcp')
    assert not target.exists(), 'adopt prior recovery checkpoint; do not overwrite'
    shutil.copyfile(p, target)
    with target.open('rb') as f:
        os.fsync(f.fileno())
    source_hash = sha(p)
    assert sha(target) == source_hash
    row.update(checkpoint_sha256=source_hash, sealed_checkpoint=str(target),
               producer_state_sha256=sha(row['producer_state']), sealed_utc=now(),
               functional_baseline=BASE, source_id=SID, board_allowlist=['0000:21:00.0'],
               source_input_hashes=producer['inputs']['generated'])
    save(out/'sealed-inputs.json', row)
    return target


def run(which, mode):
    pins=read(C/'inputs.json')
    assert pins['functional_baseline']==BASE and pins['source_id']==SID
    for path,expected in pins['files'].items():
        assert sha(path)==expected, ('recovery input changed',path)
    current = eligibility(which, mode)
    assert current['eligible'], current
    # A completed successful alternate branch takes precedence. A replacement
    # replaces one exited route slot. It never preempts or modifies another
    # task. The parent must apply the external service CPU/memory admission.
    active_routes = sum(unit_active(x[2]) not in ['failed','inactive'] for x in SOURCES.values())
    assert active_routes <= 1, 'would create a third component route'
    mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
    assert mem >= 128*2**20 and shutil.disk_usage(W).free >= 96*2**30
    assert float(Path('/proc/loadavg').read_text().split()[0]) < 48
    out = OUTPUT/(which+'-'+mode)
    out.mkdir(parents=True, exist_ok=True)
    lock = (OUTPUT/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (out/'state.json').exists(), 'preserve previous recovery; version required'
    cpus = sorted(os.sched_getaffinity(0))[-2:]
    os.sched_setaffinity(0, cpus)
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,64*2**30))
    state = dict(schema='ec-original-svb-postroute-recovery/1', **identity(),
                 status='SEALING_EXITED_FAILED_PRODUCER', functional_baseline=BASE,
                 source_id=SID, target_changed=False, fpga_access=False,
                 native_paused=True, producer=which, mode=mode, cpus=cpus, started_utc=now())
    save(out/'state.json', state)
    checkpoint = seal(which, mode, out)
    tcl = out/'recover.tcl'
    code = (C/'recover.tcl.in').read_text()
    if mode == 'replicate':
        physical = (C/'replicate.tcl.in').read_text()
        code = code.replace('target_clock\nsaved_reports initial', physical+'\ntarget_clock\nsaved_reports initial')
    tcl.write_text(code.replace('@CHECKPOINT@',str(checkpoint)).replace('@OUT@',str(out)))
    argv = ['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
            '-log',str(out/'vivado.log'),'-source',str(tcl)]
    started = time.monotonic()
    with (out/'recovery.log').open('xb', buffering=0) as log:
        p = subprocess.Popen(argv, cwd=out, stdin=subprocess.DEVNULL, stdout=log,
                             stderr=subprocess.STDOUT, start_new_session=True,
                             env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2'})
        state.update(status='RUNNING_POST_ROUTE_RECOVERY', child=identity(p.pid), argv=argv)
        save(out/'state.json',state)
        try:
            rc = p.wait(timeout=12*3600)
        except subprocess.TimeoutExpired:
            # Only this controller's own recovery group, never existing jobs.
            import signal
            os.killpg(p.pid,signal.SIGTERM)
            try:p.wait(timeout=20)
            except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
            rc = 'OWNED_RECOVERY_TIMEOUT'
        os.fsync(log.fileno())
    bit = out/'original-svb-recovered.bit'
    text = (out/'recovery.log').read_text(errors='replace')
    good = rc == 0 and bit.is_file() and 'EC_SVB_RECOVERY_BITSTREAM_COMPLETE' in text
    result = dict(status='BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
                  functional_baseline=BASE, source_id=SID, complete_opt4=False,
                  target_changed=False, fpga_access=False, producer=which, mode=mode,
                  input_manifest_sha256=sha(out/'sealed-inputs.json'), returncode=rc,
                  capsule_inputs_sha256=sha(C/'inputs.json'),
                  host_wall_seconds=time.monotonic()-started, completed_utc=now(),
                  bitstream=str(bit) if good else None,
                  bitstream_sha256=sha(bit) if good else None,
                  outputs={str(p):sha(p) for p in out.iterdir() if p.is_file() and p.name not in ['state.json','result.json','complete.json']})
    save(out/'result.json',result)
    if good:save(out/'complete.json',dict(result_sha256=sha(out/'result.json')))
    state.update(status=result['status'], child={}, result=str(out/'result.json'), updated_utc=now())
    save(out/'state.json',state)


if __name__ == '__main__':
    ap=argparse.ArgumentParser()
    ap.add_argument('--producer',choices=sorted(SOURCES),default='spread')
    ap.add_argument('--mode',choices=['postroute','replicate'],default='postroute')
    ap.add_argument('--run',action='store_true')
    args=ap.parse_args()
    try:
        if args.run:run(args.producer,args.mode)
        else:print(json.dumps(eligibility(args.producer,args.mode),indent=2))
    except Exception as error:
        out = OUTPUT/(args.producer+'-'+args.mode)
        previous = read(out/'state.json')
        if previous.get('pid') == os.getpid():
            previous.update(status='FAILED_WITH_EVIDENCE',error=repr(error),updated_utc=now())
            save(out/'state.json',previous)
            save(out/'failure.json',previous)
        raise
