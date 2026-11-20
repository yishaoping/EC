#!/usr/bin/python3
"""One bounded STA experiment, never routes, writes a bitstream, or accesses FPGA."""
import fcntl
import os
from pathlib import Path
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = D/'cycleprecise-svb-hostclock-probe-r2-20261112'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
ST = {}

def update(status, **values):
    ST.update(status=status, updated_utc=now(), **values)
    save(OUT/'state.json', ST)

def main():
    pins = read(C/'inputs.json')
    p = read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == pins['functional_baseline']
    assert p['native_paused'] and p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']
    for path, expected in pins['files'].items():
        assert sha(path) == expected, ('immutable input changed', path)
    checkpoint = Path(pins['checkpoint'])
    assert sha(checkpoint) == pins['checkpoint_sha256']
    OUT.mkdir(exist_ok=True)
    lock = (OUT/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    old = read(OUT/'state.json')
    assert not live(old) and not live(old.get('child', {})), 'adopt live probe'
    assert not old and not (OUT/'probe.log').exists(), 'preserve prior evidence, use independent recovery'
    assert {250, 251} <= set(os.sched_getaffinity(0))
    os.sched_setaffinity(0, {250, 251})
    resource.setrlimit(resource.RLIMIT_AS, (32*2**30,)*2)
    ST.update(schema='ec-svb-actual-host-clock-diagnostic/1', **identity(),
              functional_baseline=pins['functional_baseline'], complete_opt4=False,
              target_rtl_changed=False, fpga_access=False, route_started=False,
              bitstream_written=False, started_utc=now())
    code=(C/'probe.tcl').read_text().replace('@CHECKPOINT@', str(checkpoint)).replace('@OUT@', str(OUT))
    assert not any(s in code for s in ['create_clock', 'create_generated_clock', 'set_false_path', 'route_design', 'write_bitstream'])
    tcl=OUT/'probe.tcl'; tcl.write_text(code)
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal', '-log', str(OUT/'vivado.log'), '-source', str(tcl)]
    started=time.monotonic()
    with (OUT/'probe.log').open('xb', buffering=0) as log:
        child=subprocess.Popen(argv, cwd=OUT, stdin=subprocess.DEVNULL, stdout=log,
            stderr=subprocess.STDOUT, env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2'})
        update('RUNNING_ISOLATED_MMCM_AND_ALL_CLOCK_STA_PROBE', child=identity(child.pid), argv=argv)
        try:
            while child.poll() is None:
                try: child.wait(timeout=300)
                except subprocess.TimeoutExpired: pass
                os.fsync(log.fileno())
                update('RUNNING_ISOLATED_MMCM_AND_ALL_CLOCK_STA_PROBE', host_wall_seconds=time.monotonic()-started)
                if time.monotonic()-started > 3600:
                    child.terminate()
                    try: child.wait(timeout=30)
                    except subprocess.TimeoutExpired: child.kill(); child.wait()
                    raise RuntimeError('bounded isolated probe timeout; no implementation signalled')
        finally: os.fsync(log.fileno())
    text=(OUT/'probe.log').read_text(errors='replace')
    good=child.returncode == 0 and 'EC_SVB_ACTUAL_HOST_CLOCK_PROBE_COMPLETE' in text
    result=dict(status='COMPLETE_DIAGNOSTIC_NOT_CERTIFIED' if good else 'FAILED_WITH_EVIDENCE',
        functional_baseline=pins['functional_baseline'], complete_opt4=False,
        fpga_access=False, target_rtl_changed=False, route_started=False, bitstream_written=False,
        input_manifest_sha256=sha(C/'inputs.json'), returncode=child.returncode,
        host_wall_seconds=time.monotonic()-started, completed_utc=now(),
        outputs={str(f):sha(f) for f in OUT.iterdir() if f.is_file() and f.name not in ['state.json','instance.lock','result.json']})
    save(OUT/'result.json', result)
    update(result['status'], child={}, result=str(OUT/'result.json'))

if __name__ == '__main__':
    try: main()
    except Exception as exc:
        if OUT.exists(): update('FAILED_WITH_EVIDENCE', error=repr(exc))
        raise
