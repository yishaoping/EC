#!/usr/bin/env python3
"""Fresh implementation of this candidate only, after its measured post-opt.

Never changes another controller, shares a live project, reads an old routed
checkpoint, accesses an FPGA or starts Vivado before both CAD leases are free.
"""
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time
import types

C = Path(__file__).resolve().parent
T = C.parent.parent
W = T.parent
R = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
B = Path(sys.argv[1]).resolve()
O = Path(sys.argv[2]).resolve()


def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    return module


def save(status, **extra):
    p = O/'continuation-state.json'
    value = read(p) if p.exists() else dict(profile='EC Performance-Only',
        fpga_access=False, model_requests=False, periodic_observer=False,
        input_dir=str(B), old_route_reused=False)
    value.update(status=status, utc=dt.datetime.now(dt.timezone.utc).isoformat(), **extra)
    tmp = p.with_suffix('.tmp');tmp.write_text(json.dumps(value, indent=2)+'\n');os.replace(tmp, p)


def no_vivado():
    for p in Path('/proc').iterdir():
        if not p.name.isdigit(): continue
        try:
            if (p/'comm').read_text().strip() == 'vivado': return False
        except OSError: pass
    return True


def code(engine, directive):
    engine.EXTERNAL_HANDOFF_DISABLED = True
    engine.ST['candidates'] = []  # Every alternative opens the new raw post-opt.
    low = load('timing_r2_clock_adapter', W/'candidates/performance-only-cdc-lowfreq-r1-20261114/controller.py')
    low.C = C
    text = low.make_code(engine, B/'shell-postopt.dcp', 10, directive)
    text = text.replace(str(C/'host-clock.tcl'), str(C/'strict-host-clock.tcl'))
    text = text.replace('set_param general.maxThreads 4', 'set_param general.maxThreads [expr {8}]')
    text = text.replace('report_high_fanout_nets -timing -slr', 'report_high_fanout_nets -slr')
    text = text.replace('NAME =~ *ghm_u_data_cdc*source_valid*}',
        'NAME =~ *ghm_u_data_cdc*source_valid* || NAME =~ *dcache_*mshrs*installArb*req_* || NAME =~ *appliedEffectResultMemory_io_writeSet*}')
    text = text.replace('write_checkpoint -force "$out/physopt.dcp"', '''write_checkpoint -force "$out/physopt.dcp"
report_utilization -file "$out/utilization-after-physopt.rpt"
report_utilization -slr -file "$out/per-slr-after-physopt.rpt"
report_timing_summary -file "$out/timing-after-physopt.rpt"''')
    text = text.replace('stage postroute_opt {phys_opt_design -directive AggressiveExplore}', '''if {[get_property SLACK $hold] < 0} {
        stage postroute_hold {phys_opt_design -hold_fix}
    } else {
        stage postroute_opt {phys_opt_design -directive AggressiveExplore}
    }''')
    bit = 'stage bitstream {write_bitstream -force "$out/firesim.bit"}'
    assert text.count(bit) == 1
    final = '''report_exceptions -file "$out/final-exceptions.rpt"
set f [open "$out/final-exceptions.rpt" r];set exceptions [read $f];close $f
ec_verify_clock_group_report $exceptions $ec_groups
source {%s}
''' % (C.parent/'rtl-structure-r1/strict-final.tcl')
    text = text.replace(bit, final+bit)
    assert text.count('open_checkpoint') == 1
    assert 'open_checkpoint {'+str(B/'shell-postopt.dcp')+'}' in text
    assert 'route_design -unroute' not in text and 'opt_design -muxf_remap' not in text
    assert text.index('strict-host-clock.tcl') < text.index('stage spread') < text.index('stage routing')
    assert text.index('strict-final.tcl') < text.index(bit)
    return text


def main():
    os.sched_setaffinity(0, set(range(248, 256)))
    os.nice(19)
    O.mkdir(parents=True, exist_ok=False)
    engine_path = W/'candidates/performance-only-routability-r1-20261114/campaign.py'
    engine = load('timing_r2_physical_engine', engine_path)
    controls = [Path(__file__), C/'strict-host-clock.tcl', C/'clock-exception-check.tcl',
                C/'clock-groups-original.tcldata', C.parent/'rtl-structure-r1/strict-final.tcl',
                engine_path, W/'candidates/performance-only-cdc-lowfreq-r1-20261114/controller.py']
    hashes = {str(p):sha(p) for p in controls}
    for directive in ['AltSpreadLogic_high', 'SSI_SpreadSLLs']:
        (O/(directive+'.tcl')).write_text(code(engine, directive))
    save('PREPARED_NOT_RUNNING', control_hashes=hashes, host_mhz=10)
    if '--prepare-only' in sys.argv: return
    deadline = time.monotonic()+72*3600
    save('WAITING_OWN_VERIFIED_COMPLETE_SHELL_POSTOPT')
    while not (B/'full-shell-comparison.json').exists():
        state = read(B/'state.json') if (B/'state.json').exists() else {}
        assert state.get('status') != 'FAILED_WITH_EVIDENCE', state
        if time.monotonic() > deadline: raise RuntimeError('own full-shell post-opt wait expired')
        time.sleep(30)
    measured = read(B/'full-shell-comparison.json')
    assert measured['status'] == 'REAL_COMPLETE_SHELL_POSTOPT_MEASURED'
    assert (B/'capacity.complete').read_text().strip() == 'CAPACITY_FITS_POSTOPT_TIMING_PENDING'
    rtl = read(B/'rtl-state.json')
    binding = read(B/'source-binding.json')
    assert rtl['source_id'] == binding['source_id']
    assert read(B/'target-graph-audit.json')['status'] == 'PASS_EXACT_TARGET_GRAPH_OUTSIDE_PROVEN_QUEUES'
    receipt = read(B/'implementation-result.json')
    for path, digest in {**rtl['outputs'], **receipt['outputs'], **hashes}.items(): assert sha(path) == digest
    save('WAITING_BOTH_EXISTING_CAD_LEASES', hardware_commit=rtl['hardware_commit'],
         source_id=rtl['source_id'], resources=measured['candidate'], checkpoint_sha256=sha(B/'shell-postopt.dcp'))
    with (R/'.performance-only-physical.lock').open('a') as physical:
        with (R/'.opt4-fit-cad.lock').open('a') as fit:
            for lock in [physical, fit]:
                while True:
                    try: fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB);break
                    except BlockingIOError:
                        if time.monotonic() > deadline: raise RuntimeError('CAD lease wait expired')
                        time.sleep(30)
            while not no_vivado():
                if time.monotonic() > deadline: raise RuntimeError('existing Vivado did not exit')
                time.sleep(30)
            def guarded(*args, **kwargs):
                assert no_vivado(), 'refuse competing full implementation'
                for p,h in hashes.items(): assert sha(p) == h
                env = {k:v for k,v in kwargs.get('env', os.environ).items() if k not in
                    ['PYTHONHOME', 'PYTHONPATH', 'LD_LIBRARY_PATH', 'LD_PRELOAD']}
                kwargs['env'] = env
                return subprocess.Popen(*args, **kwargs)
            engine.subprocess = types.SimpleNamespace(**{**vars(subprocess), 'Popen':guarded})
            engine.O = O/'implementation'
            (engine.O/'candidates').mkdir(parents=True);(engine.O/'tmp').mkdir()
            engine.ST.update(hardware_commit=rtl['hardware_commit'], source_id=rtl['source_id'],
                             candidates=[], profile='EC Performance-Only')
            for directive in ['AltSpreadLogic_high', 'SSI_SpreadSLLs']:
                save('RUNNING_FRESH_10MHZ_PHYSICAL_IMPLEMENTATION', directive=directive)
                row = engine.run('bjl-result-cdc-10mhz-'+directive.lower(), code(engine, directive), hours=18)
                if row.get('bitstream_generated'):
                    d = engine.O/'candidates'/row['candidate']
                    assert row['routing']['legal'] and (d/'strict-admission.complete').is_file()
                    save('BITSTREAM_GENERATED_21_ONLY_CERTIFICATION_PENDING', result=row,
                         bitstream=str(d/'firesim.bit'), bitstream_sha256=sha(d/'firesim.bit'))
                    return
                save('PHYSICAL_ATTEMPT_FAILED_WITH_EVIDENCE', result=row)
                d = engine.O/'candidates'/row['candidate']
                if not (d/'clock-replay-admission.complete').is_file():
                    save('CLOCK_CONTRACT_REJECTED_NO_REPEAT_OF_SAME_INVALID_REPLAY', result=row)
                    return
            save('FINITE_PHYSICAL_ALTERNATIVES_FAILED_NO_BITSTREAM', result=row)


if __name__ == '__main__':
    try: main()
    except Exception as error:
        if O.is_dir(): save('FAILED_WITH_EVIDENCE', error=repr(error))
        raise
