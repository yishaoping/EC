#!/usr/bin/python3
"""Serial report-only timing on completed checkpoints. Never resynthesize."""
from pathlib import Path
import fcntl
import os
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-checkpoint-timing-r1-20261113'
DSP = D/'build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112'
BANK = D/'build-logs/Opt4-address-banked-production-area-pair-r5-20261113'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha
ST = {}
CPUS = {228, 229}


def update(status, **kw):
    ST.update(status=status, updated_utc=now(), **kw)
    save(O/'state.json', ST)


def available():
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit() or int(proc.name) == os.getpid():
            continue
        try:
            af = os.sched_getaffinity(int(proc.name))
            if proc.stat().st_uid == os.getuid() and len(af) <= 8 and af & CPUS:
                return False
        except OSError:
            pass
    mem = {line.split(':')[0]: int(line.split()[1]) for line in Path('/proc/meminfo').read_text().splitlines()}
    return mem['MemAvailable'] >= 80*2**20


def tcl(checkpoint, out):
    return f'''set_param general.maxThreads 2
open_checkpoint {{{checkpoint}}}
if {{[llength [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]]}} {{error "unresolved cells"}}
if {{[llength [get_ports clock]] != 1}} {{error "exact clock port required"}}
if {{[llength [get_clocks -quiet]]}} {{delete_clocks [get_clocks]}}
create_clock -name EC_SCREEN_100MHZ -period 10.000 [get_ports clock]
set data_inputs [remove_from_collection [all_inputs] [get_ports clock]]
if {{[llength $data_inputs]}} {{set_input_delay 0.000 -clock EC_SCREEN_100MHZ $data_inputs}}
set_output_delay 0.000 -clock EC_SCREEN_100MHZ [all_outputs]
report_timing_summary -delay_type min_max -report_unconstrained -file {{{out/'timing-summary.rpt'}}}
report_timing -delay_type max -path_type full_clock_expanded -max_paths 10 -file {{{out/'setup-paths.rpt'}}}
report_timing -delay_type min -path_type full_clock_expanded -max_paths 10 -file {{{out/'hold-paths.rpt'}}}
report_utilization -file {{{out/'utilization.rpt'}}}
set f [open {{{out/'metrics.txt'}}} w]
foreach delay {{max min}} {{
  set p [get_timing_paths -delay_type $delay -max_paths 1]
  if {{![llength $p]}} {{error "missing $delay timing paths"}}
  puts $f "$delay.slack=[get_property SLACK $p]"
  puts $f "$delay.data_path_delay=[get_property DATAPATH_DELAY $p]"
  puts $f "$delay.startpoint=[get_property STARTPOINT_PIN $p]"
  puts $f "$delay.endpoint=[get_property ENDPOINT_PIN $p]"
}}
close $f
puts "EC_REPORT_ONLY_CHECKPOINT_TIMING_COMPLETE"
exit 0
'''


def measure(label, checkpoint, expected):
    assert sha(checkpoint) == expected, 'Exact area-producer checkpoint required'
    while not available():
        update('WAITING_IDLE_CAMPAIGN_CPUS_FOR_REPORT_ONLY', checkpoint_label=label)
        time.sleep(30)
    os.sched_setaffinity(0, CPUS)
    out = O/label; out.mkdir()
    script = out/'timing.tcl'; script.write_text(tcl(checkpoint, out))
    log = out/'vivado.log'
    argv = ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
        '-log', str(out/'tool.log'), '-source', str(script)]
    with log.open('w') as stream:
        child = subprocess.Popen(argv, cwd=out, stdout=stream, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '2'})
        start = time.monotonic()
        while child.poll() is None:
            update('RUNNING_REPORT_ONLY_'+label.upper(), child=identity(child.pid),
                checkpoint_label=label, seconds=time.monotonic()-start)
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
        assert child.returncode == 0, (label, child.returncode, str(log))
    outputs = [out/name for name in ['timing-summary.rpt', 'setup-paths.rpt', 'hold-paths.rpt',
        'metrics.txt', 'utilization.rpt']]
    assert all(path.is_file() and path.stat().st_size for path in outputs)
    assert 'EC_REPORT_ONLY_CHECKPOINT_TIMING_COMPLETE' in log.read_text()
    assert sha(checkpoint) == expected, 'Original checkpoint changed'
    result = dict(checkpoint=str(checkpoint), checkpoint_sha256=expected,
        metrics=dict(line.split('=', 1) for line in (out/'metrics.txt').read_text().splitlines()),
        outputs={str(path): sha(path) for path in outputs}, log_sha256=sha(log),
        clock_period_ns=10, input_output_delay_ns=0, no_resynthesis=True,
        synthesis_estimates_only=True, no_placement_or_route=True)
    save(out/'result.json', result)
    # Wait stages consume no dedicated campaign pins.
    os.sched_setaffinity(0, INITIAL_AFFINITY)
    return result


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing owner'
    binding = read(C/'source-binding.json')
    assert all(sha(path) == digest for path, digest in binding['files'].items())
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    ST.update(schema='ec-address-checkpoint-report-only-timing/1', **identity(), started_utc=now(),
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8', cpus_after_admission=sorted(CPUS),
        no_resynthesis=True, no_place_route=True, fpga_access=False, whole_fit=False,
        scope='Two separate matched checkpoint pairs. DSP leaf timing compares only its own Reference; production Plain/Threaded compares only its own host pair. No cross-harness or full-shell timing certification.')
    pairs = {}
    dsp = read(DSP/'result.json')
    assert dsp['status'] == 'COMPLETE_ACTUAL_FULL_ADDRESS_DSP_AREA_PAIR_NOT_WHOLE_FIT'
    assert sha(DSP/'result.json') == binding['DSP_area_result_sha256']
    save(O/'dsp-source-result.json', dict(path=str(DSP/'result.json'), sha256=sha(DSP/'result.json')))
    pairs['DSPLeaf'] = {name: measure('DSP-'+name, DSP/name/'module.dcp',
        binding['DSP_checkpoints'][name]) for name in ['Reference', 'Candidate']}
    save(O/'completed-pairs.json', pairs)
    while not (BANK/'result.json').is_file():
        state = read(BANK/'state.json')
        if str(state.get('status')).startswith('FAILED'):
            update('PRODUCTION_AREA_FAILED_DSP_PAIR_RETAINED', upstream_status=state.get('status'), pairs=pairs)
            save(O/'result.json', ST); return
        update('WAITING_SOLE_PRODUCTION_AREA_PAIR_NO_CAD_RESTART', upstream_status=state.get('status'), pairs=pairs)
        time.sleep(30)
    bank = read(BANK/'result.json')
    assert bank['status'] in ['PASS_COMPLETE_PRODUCTION_HOST_PAIRED_AREA_GAIN_NOT_FULL_EC',
        'REJECTED_COMPLETE_PRODUCTION_HOST_NO_LUT_GAIN']
    area = bank['area']
    assert set(area) == {'Plain', 'Threaded'}
    for name in ['Plain', 'Threaded']:
        checkpoint = BANK/name/'host.dcp'
        assert str(checkpoint) in area[name]['outputs']
        pairs.setdefault('ProductionHost', {})[name] = measure('Bank-'+name, checkpoint,
            area[name]['outputs'][str(checkpoint)])
    update('COMPLETE_TWO_MATCHED_CHECKPOINT_TIMING_PAIRS_NOT_PHYSICAL_TIMING',
        pairs=pairs, production_area_result=str(BANK/'result.json'),
        production_area_result_sha256=sha(BANK/'result.json'), ended_utc=now(),
        next='Compare matched area/estimated timing and token cost. Select only compatible material gain; actual complete-shell post-route STA remains required. Never rank unmatched leaf/host WNS as whole-system superiority.')
    save(O/'result.json', ST)


INITIAL_AFFINITY = os.sched_getaffinity(0)
if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        update('FAILED_WITH_EVIDENCE_REPORT_ONLY', error=repr(exc), ended_utc=now())
        save(O/'failure.json', ST)
        raise
