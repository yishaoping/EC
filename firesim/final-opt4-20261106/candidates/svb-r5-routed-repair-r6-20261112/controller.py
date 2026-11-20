#!/usr/bin/python3
"""Versioned, post-route-only repair of the SHA-bound r5 E checkpoint."""
import fcntl
import importlib.util
import os
from pathlib import Path
import re
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = D/'cycleprecise-svb-host40-shell-recovery-r6-20261112'
OLD = W/'candidates/svb-host40-shell-recovery-r5-20261112'
E = D/'cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PROFILE = 'OriginalSVB32-component-trace-host40'
ST = {}


def update(status, **values):
    ST.update(status=status, updated_utc=now(), **values)
    save(OUT/'state.json', ST)


def verify():
    policy = read(D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['board_allowlist'] == ['0000:21:00.0']
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    pins = read(C/'inputs.json')
    assert pins['functional_baseline'] == BASE and pins['source_id'] == SID
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('sealed input changed', path)
    a = read(pins['resource_admission'])
    assert a['limits']['cpus'] == [224, 225] and a['limits']['max_component_vivado'] == 3
    return pins, a


def workers():
    rows = []
    for cg in Path('/sys/fs/cgroup/systemd/system.slice').glob('*svb*.service'):
        for file in cg.rglob('cgroup.procs'):
            for pid in set(map(int, file.read_text().split())):
                try:
                    argv = (Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0')
                    if argv and argv[0].decode().endswith('/unwrapped/lnx64.o/vivado'):
                        rows.append(dict(unit=cg.name, **identity(pid), argv=[x.decode() for x in argv if x]))
                except FileNotFoundError:
                    pass
    return list({r['pid']: r for r in rows}.values())


def admit():
    limits = read(read(C/'inputs.json')['resource_admission'])['limits']
    while True:
        rows = workers()
        mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk = shutil.disk_usage(W).free
        load = float(Path('/proc/loadavg').read_text().split()[0])
        a = dict(workers=rows, memory_kib=mem, disk_bytes=disk, load1=load)
        if len(rows) < 3 and mem >= limits['min_available_gib']*2**20 and disk >= limits['min_disk_gib']*2**30 and load < limits['max_load1']:
            return a
        update('WAITING_EXISTING_SMALL_COMPONENT_SLOT_NO_SIGNALS', admission=a)
        time.sleep(30)


def timing(path):
    if not path.is_file():
        return None
    text = path.read_text()
    hit = re.search(r'WNS\(ns\).*?\n\s*[-\s]+\n\s*([-\d.]+)\s+([-\d.]+)\s+(\d+)\s+\d+\s+([-\d.]+)\s+([-\d.]+)\s+(\d+)', text)
    if not hit:
        return None
    return dict(wns=float(hit[1]), tns=float(hit[2]), setup_failing=int(hit[3]), whs=float(hit[4]), ths=float(hit[5]), hold_failing=int(hit[6]))


def best():
    choices = [(E/'final.dcp', timing(E/'final-timing.rpt'))]
    for path in OUT.glob('*/result.json'):
        r = read(path)
        for tag in ['physical', 'routed', 'hold-fixed', 'routed-hold-fixed', 'final']:
            dcp = path.parent/(tag+'.dcp')
            t = timing(path.parent/(tag+'-timing.rpt'))
            if t and dcp.exists() and r.get('outputs', {}).get(str(dcp)) == sha(dcp):
                # Reuse only completed routed states, never a partial ECO.
                if tag not in ['final', 'routed', 'routed-hold-fixed']:
                    continue
                if t['whs'] >= 0:
                    choices.append((dcp, t))
    checkpoint, metrics = max(choices, key=lambda x: (x[1]['wns'], x[1]['tns'], x[1]['whs']))
    save(OUT/'selected-checkpoint.json', dict(checkpoint=str(checkpoint), sha256=sha(checkpoint), timing=metrics, utc=now()))
    return checkpoint


def attempt(mode, strategy):
    out = OUT/mode
    if (out/'result.json').exists():
        return read(out/'result.json')
    assert not (out/'recovery.log').exists(), 'partial attempt retained; adopt identity before recovery'
    admission = admit()
    checkpoint = best()
    out.mkdir(exist_ok=True)
    sealed = out/'sealed-source.dcp'
    shutil.copyfile(checkpoint, sealed)
    assert sha(sealed) == sha(checkpoint)
    probe_path = D/'cycleprecise-svb-hostclock-probe-r2-20261112/result.json'
    probe = read(probe_path)
    save(out/'sealed-inputs.json', dict(functional_baseline=BASE, source_id=SID, profile=PROFILE,
        target_rtl_changed=False, physical_only=True, host_clock_period_ns=24.9975, mmcm_clkout0_divide_f=30.0,
        probe_result=str(probe_path), probe_result_sha256=sha(probe_path), probe_input_sha256=probe['input_manifest_sha256'],
        sealed_checkpoint=str(sealed), sealed_checkpoint_sha256=sha(sealed), inputs_sha256=sha(C/'inputs.json'),
        mode=mode, source_checkpoint=str(checkpoint), source_checkpoint_sha256=sha(checkpoint), sealed_utc=now()))
    periods = read(C/'physical-clock-contract.json')['periods_ns']
    clocks = ' '.join('{'+name+'} '+str(period) for name, period in periods.items())
    code = (C/'recover.tcl.in').read_text().replace('@CHECKPOINT@', str(sealed)).replace('@OUT@', str(out)).replace('@CLOCKS@', clocks).replace('@STRATEGY@', strategy)
    assert not any(token in code for token in ['-retime', 'AddRetime', 'create_clock', 'set_false_path', 'reset_timing', 'set_multicycle_path', 'set_clock_uncertainty', 'set_property SEVERITY'])
    (out/'recover.tcl').write_text(code)
    argv = ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal', '-log', str(out/'vivado.log'), '-source', str(out/'recover.tcl')]
    start = time.monotonic()
    with (out/'recovery.log').open('xb', buffering=0) as log:
        child = subprocess.Popen(argv, cwd=out, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT,
            start_new_session=True, env={**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '2'})
        update('RUNNING_R5_E_INCREMENTAL_POSTROUTE_REPAIR', mode=mode, admission=admission, child=identity(child.pid), argv=argv)
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(log.fileno())
            update('RUNNING_R5_E_INCREMENTAL_POSTROUTE_REPAIR', mode=mode, host_wall_seconds=time.monotonic()-start,
                log_bytes=log.tell(), child=identity(child.pid), latest_timing=timing(out/'physical-timing.rpt'))
    bit = out/'original-svb-host40.bit'
    good = child.returncode == 0 and bit.is_file() and 'EC_SVB_HOST40_BITSTREAM_COMPLETE' in (out/'recovery.log').read_text(errors='replace')
    result = dict(schema='ec-original-svb-host40-shell-recovery/6', status='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION' if good else 'FAILED_WITH_EVIDENCE',
        functional_baseline=BASE, source_id=SID, profile=PROFILE, target_rtl_changed=False, host_clock_changed=True,
        host_clock_period_ns=24.9975, mmcm_clkout0_divide_f=30.0, complete_opt4=False, fpga_access=False, mode=mode,
        input_manifest_sha256=sha(C/'inputs.json'), sealed_inputs_sha256=sha(out/'sealed-inputs.json'),
        returncode=child.returncode, host_wall_seconds=time.monotonic()-start, completed_utc=now(), timing=timing(out/'final-timing.rpt'),
        bitstream=str(bit) if good else None, bitstream_sha256=sha(bit) if good else None,
        outputs={str(p): sha(p) for p in out.iterdir() if p.is_file() and p.name not in ['result.json', 'complete.json']})
    save(out/'result.json', result)
    if good:
        save(out/'complete.json', dict(result_sha256=sha(out/'result.json')))
    update(result['status'], mode=mode, child={}, result=str(out/'result.json'), latest_timing=result['timing'])
    return result


def main():
    pins, a = verify()
    OUT.mkdir(exist_ok=True)
    # Reuse the exact third component slot lock, affinity and memory envelope.
    lock = (D/'cycleprecise-svb-host40-shell-recovery-r4-20261112/extra-component-slot.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    old = read(OUT/'state.json')
    assert not live(old) and not live(old.get('child', {})), 'adopt live repair'
    if (OUT/'chosen-result.json').exists():
        return
    assert {224, 225} <= set(os.sched_getaffinity(0))
    os.sched_setaffinity(0, {224, 225})
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    ST.update(schema='ec-original-svb-host40-shell-recovery/6', **identity(), functional_baseline=BASE,
        source_id=SID, profile=PROFILE, target_rtl_changed=False, complete_opt4=False, fpga_access=False,
        cpus=[224, 225], started_utc=now(), input_manifest_sha256=sha(C/'inputs.json'))
    update('STARTING_R5_E_ROUTED_CHECKPOINT_REPAIR')
    for mode, strategy in [
        ('G-postroute-critical-routing', 'phys_opt_design -routing_opt'),
        ('H-postroute-placement-critical-cell', 'phys_opt_design -placement_opt -critical_cell_opt'),
        ('I-postroute-clock-skew', 'phys_opt_design -clock_opt'),
        ('J-postroute-targeted-delay-reroute', 'repair_critical_data_nets'),
    ]:
        r = attempt(mode, strategy)
        if r['status'] == 'HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION':
            save(OUT/'chosen-result.json', dict(result=str(OUT/mode/'result.json'), result_sha256=sha(OUT/mode/'result.json'),
                profile=PROFILE, source_id=SID, created_utc=now()))
            update('HANDED_TO_INDEPENDENT_HOST40_CERTIFICATION', child={})
            return
    update('BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED', child={})


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if OUT.exists():
            update('FAILED_WITH_EVIDENCE', error=repr(exc))
        raise
