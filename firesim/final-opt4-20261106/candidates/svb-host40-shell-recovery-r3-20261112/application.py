#!/usr/bin/python3
"""Replay proven real SVB traffic on the already certified component on card21.

This follower never programs a device. The existing component deployment and
short directed test must have completed first. No full-Opt4 admission.
"""
import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import signal
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D/'cycleprecise-original-svb-host40-shell-application-onboard-r3-20261112'
PREP = D/'cycleprecise-frozen-svb-fpga-r2-20261111'
CPU = D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
DRIVER = W/'candidates/full-svb-gg-stream-replay-r2-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PROFILE = 'OriginalSVB32-component-trace-host40'
sys.path.insert(0, str(W/'scripts'))
import board_batch as bb
from coverage_first import sample_busy
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}


def update(status, **values):
    ST.update(status=status, updated_utc=now(), **values)
    save(L/'state.json', ST)


def whole_priority():
    p = read(D/'Opt4-fit-runtime-priority.json')
    if p.get('status') in ['REQUESTED_AT_SAFE_BOUNDARY', 'ACTIVE']:
        return True
    return any(read(p).get('certified_bitstream') for p in
               (W/'runtime').glob('Opt4-fit-*/certified-build.json'))


def completed_component():
    for name in ['cycleprecise-original-svb-host40-shell-onboard-r3-20261112']:
        root = D/name
        r = read(root/'result.json')
        marker = read(root/'complete.json')
        if r.get('status') != 'VALID_COMPONENT_FPGA_TRACE' or not marker:
            continue
        assert marker['result_sha256'] == sha(root/'result.json')
        assert r['certificate_sha256'] == sha(root/'certified-component.json')
        assert r['returncode'] == 0 and r['compared_output_values'] == 42291
        assert r['board_bdf'] == bb.TARGET_BDF and r['board_serial'] == bb.TARGET_SERIAL
        cert = read(root/'certified-component.json')
        assert cert['functional_baseline'] == BASE and cert['source_id'] == SID
        assert cert['profile'] == PROFILE and not cert['complete_opt4']
        assert cert['status'] == 'CERTIFIED_ORIGINAL_SVB_COMPONENT_HOST40_NOT_FULL_OPT4'
        return root, cert
    return None


def verify_ready(root, cert):
    admission = read(CPU/'board-admission-ready.json')
    assert admission['status'] == 'READY_FOR_CONTROLLED_21_ONLY_BOARD_ADMISSION_NOT_EXECUTED'
    assert admission['functional_baseline'] == BASE and admission['source_id'] == SID
    assert admission['profile'] == 'OriginalSVB32-component-trace' and not admission['complete_opt4']
    required_args = ['+svb-force-all-inputs', '+domain=0000', '+bus=21', '+device=00',
                     '+function=0', '+bar=0', '+svb-trace='+admission['trace']]
    assert admission['required_driver_args'] == required_args
    assert admission['board_allowlist'] == [bb.TARGET_BDF] and not admission['fpga_access']
    assert admission['cpu_proof'] == str(CPU/'full-result.json')
    assert sha(admission['cpu_proof']) == admission['cpu_proof_sha256']
    proof = read(admission['cpu_proof'])
    assert proof['passed'] and proof['real_application_payload_mutation_rejected']
    assert not proof['fpga_access']
    assert proof['positive']['returncode'] == 0
    assert '+svb-force-all-inputs' in proof['positive']['argv']
    assert proof['negative']['returncode'] != 0
    summary = proof['positive']['summary']
    assert summary['records'] > 0 and summary['mismatches'] == 0
    assert summary['capture_accepted'] > 0 and summary['promote_accepted'] > 0
    assert summary['acked'] > 0 and summary['mutation_applied'] == 0
    assert summary['input_cache_enabled'] == 0
    driver = Path(admission['driver']).resolve()
    assert driver == DRIVER/'SVBStreamingReplay-xilinx_alveo_u280'
    assert sha(driver) == admission['driver_sha256']
    assert sha(admission['trace']) == admission['trace_sha256'] == proof['trace_sha256']
    plan = read(DRIVER/'plan.json')
    assert plan['board_allowlist'] == [bb.TARGET_BDF] and not plan['target_or_model_modified']
    assert plan['functional_baseline'] == BASE and plan['source_id'] == SID
    for path, expected in plan['inputs'].items():
        assert sha(path) == expected, ('driver input changed', path)
    assert sha(PREP/'goldengate/FireSim-generated.sv') == admission['host_rtl_sha256']
    assert sha(PREP/'goldengate/FireSim-generated.const.h') == admission['control_header_sha256']
    parent_driver = read(PREP/'hardware-driver.json')
    assert admission['control_header_sha256'] == parent_driver['control_header_sha256']
    assert parent_driver['board_allowlist'] == [bb.TARGET_BDF]
    assert sha(PREP/'simif_xilinx_alveo_u280_21_only.cc') == cert['driver']['guarded_source_sha256']
    assert sha(cert['bitstream']) == cert['bitstream_sha256']
    assert read(root/'result.json')['source_id'] == SID
    budget = read(CPU/'measured-full-budget.json')['per_run_timeout_seconds']
    assert 0 < budget <= 86400
    return admission, summary, int(budget)


def policy_check():
    policy = read(D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['area_equivalence_only'] and policy['native_paused']
    assert policy['board_allowlist'] == [bb.TARGET_BDF]
    assert not policy['fpga_access']  # AI worker cannot bypass runtime services.


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--offline', action='store_true')
    args = ap.parse_args()
    policy_check()
    pins = read(C/'application-inputs.json')
    assert pins['board_allowlist'] == ['0000:21:00.0'] and pins['no_deployment_operations']
    for path, expected in pins['files'].items():
        assert sha(path) == expected, ('follower source changed', path)
    if args.offline:
        print(json.dumps(dict(status='FOLLOWER_BINDING_PASS_NO_DEVICE_ACCESS',
                              component_ready=bool(completed_component()),
                              application_cpu_proof_ready=(CPU/'board-admission-ready.json').exists())))
        return
    assert os.geteuid() == 0
    L.mkdir(exist_ok=True)
    lock = (L/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    old = read(L/'state.json')
    assert not live(old) and not live(old.get('child', {})), 'adopt live instance'
    assert not (L/'result.json').exists() and not (L/'run-started.json').exists(), 'preserve completed or partial sample; versioned recovery required'
    ST.update(schema='ec-original-svb-application-onboard/1', **identity(),
              functional_baseline=BASE, source_id=SID, profile=PROFILE,
              board_bdf=bb.TARGET_BDF, board_serial=bb.TARGET_SERIAL,
              complete_opt4=False, native_paused=True, fpga_access=False,
              deployment_operations=[])
    while True:
        policy_check()
        component = completed_component()
        for winner in ['cycleprecise-original-svb-application-onboard-r1-20261111','cycleprecise-original-svb-application-onboard-recovered-r1-20261111','cycleprecise-original-svb-host40-application-onboard-r1-20261112','cycleprecise-original-svb-host40-shell-application-onboard-r2-20261112']:
            root=D/winner;done=read(root/'complete.json');result=read(root/'result.json')
            if result.get('status')=='VALID_ORIGINAL_SVB_REAL_APPLICATION_FPGA_TRACE' and done:
                assert done['result_sha256']==sha(root/'result.json')
                assert result['source_id']==SID and result['board_bdf']==bb.TARGET_BDF
                update('EXISTING_VALID_REAL_APPLICATION_TRACE_WINS_NO_DUPLICATE',winner=str(root));return
        if not component or not (CPU/'board-admission-ready.json').exists():
            update('WAITING_CERTIFIED_COMPONENT_AND_REAL_APPLICATION_CPU_REPLAY')
            time.sleep(300)
            continue
        if whole_priority() or sample_busy():
            update('WAITING_SAFE_21_BOUNDARY_OR_FULL_OPT4_PRIORITY')
            time.sleep(300)
            continue
        held = []
        try:
            for name in ['maintenance-0000_21_00.0.lock', 'card-0000_21_00.0.lock']:
                f = (D/'locks'/name).open('a')
                held.append(f)
                fcntl.flock(f, fcntl.LOCK_EX|fcntl.LOCK_NB)
        except BlockingIOError:
            for f in held:
                f.close()
            update('WAITING_EXISTING_21_LOCK_OWNER')
            time.sleep(300)
            continue
        root, cert = component
        latest = read(D/'latest-deployment.json')
        current = latest.get('source_id') == SID and latest.get('bitstream_sha256') == cert['bitstream_sha256']
        current = current and latest.get('bdfs') == [bb.TARGET_BDF]
        if not current or whole_priority() or sample_busy():
            for f in held:
                f.close()
            update('WAITING_MATCHING_COMPONENT_DEPLOYMENT_NO_REFLASH')
            time.sleep(300)
            continue
        admission, expected, budget = verify_ready(root, cert)
        check = bb.precheck(target_bdfs=[bb.TARGET_BDF])
        save(L/'pre-run.json', check)
        if check['open_devices'] or check['simulation_processes']:
            for f in held:
                f.close()
            update('WAITING_CONCRETE_21_DEVICE_CONFLICT', conflict=check)
            time.sleep(300)
            continue
        break
    save(L/'certified-component.json', cert)
    save(L/'application-admission.json', admission)
    save(L/'run-started.json', dict(utc=now(), inherited_deployment_sha256=sha(D/'latest-deployment.json'),
         cpu_proof_sha256=admission['cpu_proof_sha256'], trace_sha256=admission['trace_sha256'],
         bitstream_sha256=cert['bitstream_sha256'], timeout_seconds=budget,
         reuse_existing_certified_bitstream=True, deployment_operations=[]))
    argv = [admission['driver'], '+permissive', '+domain=0000', '+bus=21', '+device=00',
            '+function=0', '+bar=0', '+pci-vendor=10ee', '+pci-device=903f',
            '+svb-trace='+admission['trace'], '+svb-state='+str(L/'target-progress.json'),
            '+svb-force-all-inputs',
            '+seed=8491167', '+permissive-off']
    start = time.monotonic()
    log = L/'hardware-replay.log'
    with log.open('xb', buffering=0) as output:
        child = subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*argv], cwd=L,
            stdin=subprocess.DEVNULL, stdout=output, stderr=subprocess.STDOUT,
            start_new_session=True, env={**os.environ, 'LD_LIBRARY_PATH':''})
        active = dict(schema='ec-original-component-run/1', run_id=L.name, run_dir=str(L),
                      status='RUNNING', configuration=PROFILE, board_bdf=bb.TARGET_BDF,
                      board_serial=bb.TARGET_SERIAL, **identity(child.pid))
        save(D/'active-0000_21_00.0.json', active)
        update('RUNNING_REAL_APPLICATION_SVB_FPGA_REPLAY', child=identity(child.pid), fpga_access=True)
        deadline = start+budget
        while child.poll() is None:
            try:
                child.wait(timeout=min(30, max(1, deadline-time.monotonic())))
            except subprocess.TimeoutExpired:
                pass
            progress = read(L/'target-progress.json')
            update('RUNNING_REAL_APPLICATION_SVB_FPGA_REPLAY', progress=progress,
                   host_wall_seconds=time.monotonic()-start)
            os.fsync(output.fileno())
            if child.poll() is None and (time.monotonic() >= deadline or log.stat().st_size > 256*2**20):
                os.killpg(child.pid, signal.SIGTERM)
                try:
                    child.wait(timeout=20)
                except subprocess.TimeoutExpired:
                    os.killpg(child.pid, signal.SIGKILL)
                    child.wait()
                update('OWNED_REPLAY_TIMEOUT_OR_LOG_LIMIT', child={})
                break
        os.fsync(output.fileno())
    text = log.read_text(errors='replace')
    summary = re.search(r'^SVB_GG_STREAM_SUMMARY (.*)$', text, re.M)
    got = {k: float(v) if '.' in v else int(v) for k,v in
           (item.split('=',1) for item in summary[1].split())} if summary else {}
    keys = ['records','first_source_tick','last_source_tick','target_cycles','reset_edges',
            'defined_output_fields','defined_output_word_checks','mismatches',
            'capture_accepted','promote_accepted','acked','mutation_applied']
    keys += ['input_cache_enabled', 'input_word_writes']
    good = child.returncode == 0 and all(got.get(k) == expected[k] for k in keys)
    good = good and '[SVBProbe]PASS Test' in text and not any(s in text for s in
        ['SVB_GG_STREAM_MISMATCH','unstable value','*** FAILED','Assertion failed'])
    result = dict(schema='ec-real-application-svb-fpga-replay/1',
        status='VALID_ORIGINAL_SVB_REAL_APPLICATION_FPGA_TRACE' if good else 'FAILED_WITH_EVIDENCE',
        kind='FPGA_COMPONENT_HOST40_TRACE_REPLAY_NOT_WHOLE_OPT4_OR_FORMAL_PARSEC',
        profile=PROFILE,physical_host_clock_period_ns=24.9975,physical_host_clock_frequency_hz=1e9/24.9975,target_frequency_hz=None,target_cycle_definition_changed=False,
        functional_baseline=BASE, source_id=SID, board_bdf=bb.TARGET_BDF,
        board_serial=bb.TARGET_SERIAL, returncode=child.returncode,
        summary=got, expected_cpu_summary=expected, host_wall_seconds=time.monotonic()-start,
        trace_sha256=admission['trace_sha256'], driver_sha256=admission['driver_sha256'],
        bitstream_sha256=cert['bitstream_sha256'], certificate_sha256=sha(L/'certified-component.json'),
        application_admission_sha256=sha(L/'application-admission.json'), raw_log=str(log),
        raw_log_sha256=sha(log), full_opt4=False, architectural_restart_tested=False,
        strict_checker_latency_measured=False, deployment_operations=[], completed_utc=now())
    save(L/'result.json', result)
    if good:
        save(L/'complete.json', dict(result_sha256=sha(L/'result.json')))
    active.update(status=result['status'], ended_utc=now())
    save(D/'active-0000_21_00.0.json', active)
    update(result['status'], child={}, result=str(L/'result.json'))


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        if L.exists():
            update('FAILED_WITH_EVIDENCE', error=repr(error))
        raise
