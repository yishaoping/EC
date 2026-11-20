#!/usr/bin/env python3
"""One diagnosed environment recovery, directly from the saved routed DCP."""
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'performance-only-cdc-lowfreq-r1-20261114'
NAME = 'mem-10mhz-recovery-r2'


def save(p, row):
    tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(row, indent=2)+'\n'); os.replace(tmp, p)


def main():
    os.sched_setaffinity(0, set(range(240, 248)))
    # No healthy CAD is restarted; the old attempt exited before clock replay.
    failed = O/'physical/candidates/mem-10mhz-ssi_spreadslls'
    prior = json.loads((failed/'result.json').read_text())
    assert prior['returncode'] == 1 and not prior['bitstream_generated']
    assert "No module named 'encodings'" in (failed/'vivado.log').read_text()
    with (O/'owner.lock').open('a') as owner, (D/'.performance-only-physical.lock').open('a') as lock:
        fcntl.flock(owner, fcntl.LOCK_EX | fcntl.LOCK_NB)
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        spec = importlib.util.spec_from_file_location('mem_recover_physical',
            W/'candidates/performance-only-routability-r1-20261114/campaign.py')
        m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
        m.EXTERNAL_HANDOFF_DISABLED = True
        m.O = O/'physical'
        m.ST.update(hardware_commit='6e1e9b966d599c442b3bdf2f3a838aae2ee5c6da',
                    functional_baseline='6fada307bb77be90b39720d3f95404fece0e431b',
                    profile='EC Performance-Only: CDC Mem 10 MHz physical recovery', candidates=[])
        clean = {k:v for k,v in os.environ.items()
                 if k not in ['PYTHONHOME', 'PYTHONPATH', 'LD_LIBRARY_PATH', 'LD_PRELOAD']}
        cp = subprocess.check_output(['/usr/bin/python3', '-I', str(C/'select_route_checkpoint.py'),
             str(m.O/'candidates'/NAME), '--check-only'], env=clean, text=True).strip()
        assert Path(cp).name == 'routed.dcp', 'Reuse actual 15 MHz routed checkpoint, not a fresh placement'
        state = json.loads((O/'state.json').read_text())
        save(O/'environment-failure-state-preserved.json', state)
        state.update(status='RUNNING_ENVIRONMENT_FIXED_10MHZ_PHYSICAL_RECOVERY',
             candidate=NAME, nominal_host_mhz=10, bitstream=None,
             utc=dt.datetime.now(dt.timezone.utc).isoformat(), checkpoint=cp,
             cad_status='RECOVERY_CONTROLLER_ACTIVE', cad_child=None,
             cad_stage='open_saved_routed_checkpoint',
             live_physical_state=str(m.O/'state.json'))
        save(O/'state.json', state)
        # Direct checkpoint open: no duplicate post-opt load, synthesis,
        # unplacement, or place_design in this recovery.
        code = '''set_param general.maxThreads 8
set out {@OUT@}
proc stage {name script} {
    global out
    set f [open "$out/current-stage.txt" w]; puts $f $name; close $f
    puts "EC_PHYSICAL_STAGE $name"
    uplevel 1 $script
}
set ec_frequency 10
set ec_resume_checkpoint [exec /usr/bin/env -u PYTHONHOME -u PYTHONPATH -u LD_LIBRARY_PATH -u LD_PRELOAD /usr/bin/python3 -I {@SELECT@} $out]
stage open {open_checkpoint $ec_resume_checkpoint}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved functional cells"}
stage clock_contract {source {@CLOCK@}}
error "strict routing flow returned without final bitstream gate"
'''.replace('@SELECT@', str(C/'select_route_checkpoint.py')).replace('@CLOCK@', str(C/'host-clock.tcl'))
        row = m.run(NAME, code)
        row['nominal_host_mhz'] = 10
        save(O/'result.json', row)
        state.update(status='BITSTREAM_GENERATED_21_ONLY_CERTIFICATION_PENDING' if row['bitstream_generated']
             else '10MHZ_PHYSICAL_RECOVERY_FAILED_WITH_EVIDENCE',
             utc=dt.datetime.now(dt.timezone.utc).isoformat(), last_result=row,
             cad_status='COMPLETED' if row['bitstream_generated'] else 'EXITED_WITH_FAILURE',
             cad_child=None, cad_stage='physical_complete',
             bitstream=str(m.O/'candidates'/NAME/'firesim.bit') if row['bitstream_generated'] else None)
        state.setdefault('candidates', []).append(row)
        save(O/'state.json', state)
    # Invoke exactly once at completion; no observer or periodic巡检.
    subprocess.run(['/usr/bin/python3', '-I', str(C/'after_physical.py')], env=clean, check=True)


if __name__ == '__main__':
    try: main()
    except Exception as exc:
        save(O/'environment-recovery-error.json', dict(error=repr(exc),
             utc=dt.datetime.now(dt.timezone.utc).isoformat(), model_requests=False))
        current = json.loads((O/'state.json').read_text())
        if current.get('candidate') == NAME:
            current.update(status='10MHZ_RECOVERY_CONTROLLER_FAILED_WITH_EVIDENCE',
                           cad_status='EXITED_WITH_ERROR', error=repr(exc))
            save(O/'state.json', current)
        raise
