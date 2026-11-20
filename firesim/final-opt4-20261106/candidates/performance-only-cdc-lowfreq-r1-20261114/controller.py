#!/usr/bin/env python3
"""Serialized, proof-gated Mem + real 15/10 MHz implementation. No device/model IO."""
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

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'performance-only-cdc-lowfreq-r1-20261114'
M = D / 'performance-only-memory-cdc-r2-20261114'
FULL = M / 'complete-shell-r3'
HARDWARE = '6e1e9b966d599c442b3bdf2f3a838aae2ee5c6da'
BASE = '6fada307bb77be90b39720d3f95404fece0e431b'
UNITS = ['ec-performance-only-routability-r3-20261114.service',
         'ec-performance-only-routability-targeted-r4-20261114.service']
STATE = dict(profile='EC Performance-Only: CDC Mem + low FPGA host frequency',
             hardware_commit=HARDWARE, performance_baseline=BASE,
             frozen_full_ec='8491167d84b6d9521b151a743673c1516926a1f8',
             fpga_access=False, model_requests=False, bitstream=None,
             new_complete_shell_resources=None, candidates=[])

def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, v):
    p = Path(p); tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(v, indent=2) + '\n'); os.replace(tmp, p)
def update(status, **kw):
    STATE.update(status=status, utc=dt.datetime.now(dt.timezone.utc).isoformat(), **kw)
    save(O / 'state.json', STATE)
def active(unit):
    return subprocess.check_output(['systemctl', '--user', 'show', unit,
        '-p', 'ActiveState', '--value'], text=True).strip() in ['active', 'activating']
def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod); return mod

def delegate(name):
    """Called only by the existing Mem controller after its real post-opt gate."""
    start = time.monotonic()
    while not (O / 'result.json').is_file():
        if not any(active(u) for u in [
                'ec-performance-only-cdc-lowfreq-r1-20261114.service',
                'ec-performance-only-cdc-lowfreq-watch-recovery-r1-20261114.service',
                'ec-performance-only-cdc-lowfreq-followthrough-r1-20261114.service']):
            raise RuntimeError('Low-frequency owner exited without result; preserve evidence, no legacy duplicate implementation')
        if time.monotonic() - start > 72 * 3600:
            raise RuntimeError('Bounded wait for serialized low-frequency implementation expired')
        time.sleep(30)
    row = read(O / 'result.json')
    row['delegated_legacy_candidate'] = name
    return row

def wait_for_postopt():
    while True:
        state = read(FULL / 'cad-state.json') if (FULL / 'cad-state.json').exists() else {}
        if state.get('status') == 'COMPLETE_SHELL_POSTOPT_CAPACITY_GATE_NOT_PLACED':
            break
        if not active('ec-performance-only-memory-cdc-full-r3-20261114.service'):
            # Resume completed receipts only, with the already validated full host.
            # Never regenerate target RTL or resynthesize a successful DUT.
            for u in UNITS:
                while active(u): update('WAITING_EXISTING_PHYSICAL_OWNER_BEFORE_CAD_RECOVERY', owner=u); time.sleep(30)
            assert read(FULL / 'hardware-binding.json')['hardware_commit'] == HARDWARE
            assert read(FULL / 'rtl-state.json')['status'] == 'GOLDENGATE_COMPLETE_NOT_SYNTHESIZED'
            sys.path.insert(0, str(W / 'scripts'))
            cad = load('lowfreq_resume_postopt', W / 'candidates/performance-only-memory-cdc-r2-20261114/cad_postopt.py')
            cad.COMMIT, cad.F = HARDWARE, FULL / 'project'
            cad.O, cad.L = FULL / 'project/builds/cad-6e1e9b96', FULL
            cad.S, cad.R = FULL / 'cad-state.json', FULL / 'rtl-state.json'
            update('RESUMING_PRIVATE_CAD_FROM_VERIFIED_RECEIPTS')
            while True:
                try: cad.main(); break
                except BlockingIOError: time.sleep(30)
            break
        update('WAITING_RUNNING_MEM_DUT_AND_COMPLETE_SHELL_POSTOPT', cad_status=state.get('status'),
               cad_child=state.get('child_pid'), cad_stage=state.get('current_stage'))
        time.sleep(30)
    assert read(FULL / 'hardware-binding.json')['hardware_commit'] == HARDWARE
    assert read(M / 'formal-r4/result.json')['status'].startswith('PASS_ALL_STATE')
    assert read(M / 'host-r2/state.json')['status'].startswith('PASS_TWO_CLOCK')
    assert (FULL / 'shell-postopt.dcp').stat().st_size > 0

def make_code(m, checkpoint, frequency, directive):
    code = m.physical_code(str(checkpoint), directive)
    old = 'stage clock_contract {source {' + str(W / 'candidates/performance-only-routability-r1-20261114/clock-contract.tcl') + '}}'
    assert code.count(old) == 1
    replacement = 'set ec_frequency ' + str(frequency) + '\nstage clock_contract {source {' + str(C / 'host-clock.tcl') + '}}'
    code = code.replace(old, replacement).replace('general.maxThreads 8', 'general.maxThreads 4')
    code = code.replace('stage muxf_remap {opt_design -muxf_remap}', 'puts "EC_MEM_NO_GLOBAL_MUXF_REMAP"')
    code = code.replace('report_utilization -slr -file "$out/per-slr-placed.rpt"',
        'report_utilization -slr -file "$out/per-slr-placed.rpt"\nreport_timing_summary -file "$out/timing-placed.rpt"')
    code = code.replace('report_utilization -file "$out/utilization.rpt"',
        'report_utilization -file "$out/utilization.rpt"\nreport_utilization -slr -file "$out/per-slr-routed.rpt"')
    return code

def main():
    os.sched_setaffinity(0, set(range(240, 248)))
    with (O / 'owner.lock').open('a') as owner:
        fcntl.flock(owner, fcntl.LOCK_EX | fcntl.LOCK_NB)
        update('STARTING_SERIALIZED_MEM_LOW_FREQUENCY_OWNER')
        recipes = read(C / 'config_build_recipes.yaml')  # JSON is a YAML subset.
        assert [recipes['ec_performance_only_mem_'+str(f)+'mhz']['platform_config_args'] for f in [15, 10]] == [
            dict(fpga_frequency=15, build_strategy='TIMING'), dict(fpga_frequency=10, build_strategy='TIMING')]
        while not (O / 'clock-ooc/complete').exists():
            update('WAITING_PHYSICAL_MMCM_OOC_CLOCK_PROOF'); time.sleep(15)
        wait_for_postopt()
        sys.path.insert(0, str(W / 'scripts'))
        from summarize_c4_capacity import utilization
        resources = utilization(FULL / 'top-postopt-utilization.rpt')
        assert len(resources) >= 5
        STATE['new_complete_shell_resources'] = resources
        if any(v['used'] > v['available'] for v in resources.values()):
            update('NOT_FIT_REAL_MEM_COMPLETE_SHELL', resources=resources)
            save(O / 'result.json', dict(candidate='no-capacity-fit', bitstream_generated=False, resources=resources)); return
        # Existing placement finishes untouched. Its not-yet-started 50 MHz
        # alternatives are deferred by the priority handoff in their clock hook.
        for unit in UNITS:
            while active(unit):
                update('WAITING_EXISTING_PLACEMENT_OWNER_NO_CONCURRENT_FULL_IMPLEMENTATION', owner=unit)
                time.sleep(30)
        # A clock probe may load a checkpoint for configuration verification,
        # but it never places/routes. Wait for its receipt before implementation.
        for probe in ['ec-performance-only-lowfreq-clock-probe-r1-20261114.service',
                      'ec-performance-only-lowfreq-clock-probe-r2-20261114.service']:
            while active(probe): update('WAITING_CLOCK_SCOPE_REPLAY_PROBE', clock_probe=probe); time.sleep(15)
        assert (O / 'clock-probe/complete').exists(), 'Clock/scope probe must pass before implementation'
        with (D / '.performance-only-physical.lock').open('a') as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            m = load('lowfreq_physical_engine', W / 'candidates/performance-only-routability-r1-20261114/campaign.py')
            m.EXTERNAL_HANDOFF_DISABLED = True
            m.O = O / 'physical'; m.O.mkdir(exist_ok=True)
            (m.O / 'candidates').mkdir(exist_ok=True); (m.O / 'tmp').mkdir(exist_ok=True)
            m.ST.update(hardware_commit=HARDWARE, functional_baseline=BASE, candidates=[], profile=STATE['profile'])
            checkpoint = FULL / 'shell-postopt.dcp'
            save(O / 'admission.json', dict(checkpoint=str(checkpoint), sha256=sha(checkpoint),
                hardware_commit=HARDWARE, module_admission_sha256=sha(FULL / 'module-admission.json'),
                full_resources=resources, recipes_sha256=sha(C / 'config_build_recipes.yaml'),
                physical_clock_gate='real MMCM divider and derived clock period, same target clock-enable semantics',
                strategy='TIMING with congestion-aware placement and fanout physical optimization'))
            choices = [(15, 'AltSpreadLogic_high'), (10, 'SSI_SpreadSLLs')]
            last = None
            for frequency, directive in choices:
                name = 'mem-'+str(frequency)+'mhz-'+directive.lower()
                receipt = m.O / 'candidates' / name / 'result.json'
                if receipt.exists():
                    # A waiting-owner recovery reuses a completed measured
                    # candidate; it never re-runs a failed physical strategy.
                    last = read(receipt)
                    assert last['candidate'] == name
                    assert sha(receipt.parent/'run.tcl') == last['tcl_sha256']
                    m.ST['candidates'].append(last)
                    STATE['candidates'].append(last)
                    if last.get('routing', {}).get('legal') and last.get('bitstream_generated'):
                        bit = receipt.parent/'firesim.bit'
                        assert bit.is_file() and bit.stat().st_size > 0
                        update('BITSTREAM_GENERATED_21_ONLY_CERTIFICATION_PENDING', bitstream=str(bit))
                        save(O/'result.json', last); return
                    continue
                update('RUNNING_COMPLETE_IMPLEMENTATION', nominal_host_mhz=frequency, candidate=name)
                last = m.run(name, make_code(m, checkpoint, frequency, directive))
                last['nominal_host_mhz'] = frequency
                STATE['candidates'].append(last)
                if last.get('routing', {}).get('legal') and last.get('bitstream_generated'):
                    update('BITSTREAM_GENERATED_21_ONLY_CERTIFICATION_PENDING', bitstream=str(m.O/'candidates'/name/'firesim.bit'))
                    save(O/'result.json', last); return
                # A legal route is retained even when timing/clock gates fail;
                # the measured next candidate changes the physical host clock.
                update('CANDIDATE_FAILED_WITH_EVIDENCE_NEXT_DISTINCT_FREQUENCY_AND_SLR_STRATEGY', last_result=last)
            save(O/'result.json', last)
            update('MEASURED_LOW_FREQUENCY_IMPLEMENTATIONS_FAILED_RESTRUCTURING_REQUIRED', last_result=last)

if __name__ == '__main__':
    try: main()
    except Exception as e:
        update('FAILED_WITH_EVIDENCE', error=repr(e))
        raise
