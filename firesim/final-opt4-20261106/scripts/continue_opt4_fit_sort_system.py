#!/usr/bin/env python3
"""Prepare the next exact hardware candidate only after measured module gates.

Current 8da CAD is never stopped/restarted/edited. New whole-DUT synthesis
waits for its real NOT FIT verdict; if current hardware fits, use it first.
This job cannot deploy, admit runtime results, or modify frozen receipts.
"""
from pathlib import Path
import datetime as dt
import fcntl
import json
import os
import subprocess
import sys
import time

from board_batch import W, D, save, sha
from job_service import proc, boot

C = '11edd71981aa30ff3a26aab1f2f7327ac0266ee1'
F = W / 'Opt4-fit-address-sort-20261110'
P = F / 'pipeline'
S = D / 'Opt4-fit-sort-system-continuation-state.json'
L = D / 'build-logs/Opt4-fit-sort-system-continuation-11edd719'
now = lambda: dt.datetime.now(dt.timezone.utc).isoformat()


def read(path):
    return json.loads(path.read_text()) if path.exists() else {}


def main():
    lock = (D / '.opt4-fit-sort-system-continuation.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    L.mkdir(exist_ok=True)
    manifest = read(P / 'templates.json')
    assert manifest['hardware_commit'] == C
    for r in manifest['scripts'].values():
        assert sha(r['isolated_script']) == r['sha256']
    st = dict(schema='ec-opt4-fit-next-system/1', hardware_commit=C,
        source_id=manifest['source_id'], pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'], host_boot_id=boot(),
        started_utc=now(), status='WAITING_FOR_VERIFIED_MODULE_MAP',
        fpga_access=False, formal_admission=False, current_8da_unchanged=True,
        policy='Measured >=25% address LUT reduction plus exact validations; prepare isolated RTL; new CAD only after 8da NOT FIT; current FIT takes precedence')
    save(S, st)
    while True:
        current = read(D / 'Opt4-fit-cad-state.json')
        if current.get('certified_bitstream'):
            st.update(status='SKIPPED_CURRENT_SYSTEM_BITSTREAM_READY', ended_utc=now()); save(S, st); return
        module = read(D / 'Opt4-fit-address-sort-state.json')
        assert module.get('hardware_commit') in [None, C]
        if module.get('status') == 'VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED':
            break
        if module.get('status') == 'FAILED_WITH_EVIDENCE':
            st.update(status='BLOCKED_MODULE_FAILURE_EVIDENCE_RETAINED', module_error=module.get('error'), ended_utc=now()); save(S, st); return
        st.update(updated_utc=now(), module_status=module.get('status')); save(S, st)
        time.sleep(300)
    assert module['source_id'] == manifest['source_id']
    assert module['local_formal'] == 'PASS' and module['negative_mutation_rejected']
    assert module['invariant_outside_bucket_delta_unchanged']
    assert module['real_size_combinational_regression'] == 'PASS_8192_VECTORS_1024_OUTPUTS'
    assert module['full_module_regression'] == 'PASS_6144_CYCLES_52_OUTPUTS_NOT_FULL_FORMAL'
    report = module['full_module_map']
    assert sha(report['report']) == report['report_sha256']
    lut = report['resources']['CLB LUTs']
    st.update(measured_module_resources=report['resources'], module_report=report['report'],
        module_map_state_sha256=sha(D / 'Opt4-fit-address-sort-state.json'))
    if lut > 1500571 * 0.75:
        st.update(status='REJECTED_INSUFFICIENT_MEASURED_AREA_GAIN', ended_utc=now()); save(S, st); return
    st.update(module_area_gate='PASS_AT_LEAST_25_PERCENT_LUT_REDUCTION', status='PREPARING_ISOLATED_WHOLE_SYSTEM_RTL'); save(S, st)
    def run(name):
        script = P / name
        assert sha(script) == manifest['scripts'][name]['sha256']
        attempt = len(list(L.glob(name + '-attempt-*.log'))) + 1
        log = L / (name + f'-attempt-{attempt}.log')
        with log.open('ab', buffering=0) as stream:
            child = subprocess.Popen([sys.executable, str(script)], cwd=W,
                env={**os.environ, 'PYTHONPATH': str(W / 'scripts')},
                stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
            st.update(child_pid=child.pid, child_start_ticks=proc(child.pid)['start_ticks'],
                active_script=name, log=str(log)); save(S, st)
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                st.update(updated_utc=now()); save(S, st); os.fsync(stream.fileno())
            assert child.returncode == 0, (name, child.returncode, str(log))
        st.pop('child_pid', None); st.pop('child_start_ticks', None); save(S, st)
    compiled = read(D / 'Opt4-fit-sort-integration-compile-state.json')
    if not (compiled.get('status') == 'PASS_SIX_MODIFIED_SOURCES_COMPILE_ONLY' and compiled.get('fit_commit') == C):
        run('compile_opt4_fit_integration.py')
    rtl = read(D / 'Opt4-fit-sort-rtl-state.json')
    if not (rtl.get('status') == 'GOLDENGATE_COMPLETE_NOT_SYNTHESIZED' and rtl.get('hardware_commit') == C):
        run('build_opt4_fit_rtl.py')
    st.update(status='BOUND_NEXT_RTL_READY_WAITING_CURRENT_CAPACITY_VERDICT'); save(S, st)
    while True:
        current = read(D / 'Opt4-fit-cad-state.json')
        if current.get('status') == 'NOT_FIT_POSTOPT':
            st.update(previous_system_not_fit=current.get('top_postopt_resources'), previous_capacity_state_sha256=sha(D / 'Opt4-fit-cad-state.json')); save(S, st)
            break
        if current.get('certified_bitstream'):
            st.update(status='SKIPPED_CURRENT_SYSTEM_BITSTREAM_READY', ended_utc=now()); save(S, st); return
        if current.get('status') == 'FAILED_WITH_EVIDENCE':
            st.update(status='BLOCKED_CURRENT_CAD_TOOL_FAILURE_NOT_CAPACITY_VERDICT', current_error=current.get('error'), ended_utc=now()); save(S, st); return
        st.update(updated_utc=now(), previous_system_status=current.get('status')); save(S, st)
        time.sleep(300)
    st.update(status='RUNNING_VALIDATED_NEXT_CAD'); save(S, st)
    run('build_opt4_fit_cad.py')
    cad = read(D / 'Opt4-fit-sort-cad-state.json')
    st.update(status=cad['status'], resources=cad.get('top_postopt_resources'),
        bitstream=cad.get('bitstream'), ended_utc=now()); save(S, st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            st = read(S); st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now()); save(S, st)
        raise
