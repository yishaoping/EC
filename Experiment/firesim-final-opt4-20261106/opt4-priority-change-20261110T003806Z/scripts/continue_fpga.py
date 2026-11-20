#!/usr/bin/env python3
"""Wait for the certified C4 build, deploy once, and reuse it across samples."""
import argparse
import datetime as dt
import fcntl
import json
import os
import subprocess
import time
from pathlib import Path

from board_batch import D, W, save, sha

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--single-board-bdf', choices=['0000:21:00.0'], default='0000:21:00.0')
p.add_argument('--check-software-only', action='store_true')
args = p.parse_args()
BDF = args.single_board_bdf
SERIAL = '21770433G02LA'
HARDWARE_COMMIT = '8491167d84b6d9521b151a743673c1516926a1f8'
SOURCE_ID = 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
CAD_STATE = D / 'C4-runtime-cad-state.json'
STATE_PATH = D / 'fpga-continuation-state.json'
DRIVER_RECEIPT = W / 'runtime/C4-efficiency-driver.json'
FIRMWARE_RECEIPT = W / 'software/C4/formal-firmware-build.json'
APPS_RECEIPT = W / 'software/formal-apps-build.json'
ROOTFS_RECEIPT = W / 'software/formal-rootfs-build.json'

state = dict(schema='ec-final-c4-continuation/2', pid=os.getpid(),
             start_ticks=Path('/proc/self/stat').read_text().split()[21],
             host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
             started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
             status='WAITING_FOR_EXACT_C4_BITSTREAM', stage='CAD',
             hardware_commit=HARDWARE_COMMIT, target_bdf=BDF, target_serial=SERIAL,
             deployment_count=0, samples=[])


def run(label, argv, allow_nonzero=False):
    state.update(status='RUNNING', stage=label, argv=list(map(str, argv)))
    save(STATE_PATH, state)
    log_path = D / (label + '-continuation-launch.log')
    with log_path.open('ab', buffering=0) as log:
        child = subprocess.Popen(list(map(str, argv)), cwd=W, stdin=subprocess.DEVNULL,
                                 stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
        state.update(child_pid=child.pid, child_pgid=child.pid,
                     child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21],
                     active_log=str(log_path))
        save(STATE_PATH, state)
        rc = child.wait()
    state.setdefault('completed', []).append(dict(stage=label, returncode=rc,
        log=str(log_path), ended_utc=dt.datetime.now(dt.timezone.utc).isoformat()))
    state.pop('child_pid', None)
    state.pop('child_pgid', None)
    state.pop('child_start_ticks', None)
    if rc and not allow_nonzero:
        state.update(status='FAILED', last_returncode=rc)
        save(STATE_PATH, state)
        raise RuntimeError(f'{label} returned {rc}; inspect {log_path}')
    save(STATE_PATH, state)
    return rc


def wait_for_certified_bitstream():
    while True:
        if not CAD_STATE.exists():
            raise RuntimeError(f'missing final C4 CAD state: {CAD_STATE}')
        cad = json.loads(CAD_STATE.read_text())
        state.update(cad_status=cad.get('status'), cad_updated_utc=cad.get('updated_utc'),
                     cad_elapsed_seconds=cad.get('elapsed_seconds'))
        if cad.get('status') == 'BUILT_NOT_RUN' and cad.get('durable_bitstream_sha256'):
            assert cad.get('returncode') == 0 and cad.get('certified_bitstream')
            assert cad.get('hardware_commit') == HARDWARE_COMMIT and cad.get('source_id') == SOURCE_ID
            bit = Path(cad['durable_bitstream'])
            assert bit.is_file() and sha(bit) == cad['durable_bitstream_sha256']
            assert cad['outputs'].get(str(Path(cad['output_dir']) / 'vivado_proj/firesim.bit')) == cad['durable_bitstream_sha256']
            runtime_receipt = json.loads((W / 'bitstream-runtime-build.json').read_text())
            assert runtime_receipt['durable_bitstream_sha256'] == cad['durable_bitstream_sha256']
            assert runtime_receipt['hardware_commit'] == HARDWARE_COMMIT
            save(W / 'bitstream-build.json', runtime_receipt)
            state.update(status='C4_BITSTREAM_CERTIFIED', selected_cad_receipt=str(CAD_STATE),
                         bitstream=str(bit), bitstream_sha256=cad['durable_bitstream_sha256'])
            save(STATE_PATH, state)
            return runtime_receipt
        if cad.get('status') in ['FAILED', 'INTERRUPTED', 'SOURCE_CHANGED', 'CAD_INPUT_CHANGED',
                                 'RESOURCE_LIMIT_OR_TIMEOUT']:
            raise RuntimeError(f'final C4 CAD stopped with status {cad["status"]}')
        state.update(status='WAITING_FOR_EXACT_C4_BITSTREAM', stage='CAD',
                     heartbeat_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(STATE_PATH, state)
        time.sleep(300)


def check_software_receipts():
    driver = json.loads(DRIVER_RECEIPT.read_text())
    firmware = json.loads(FIRMWARE_RECEIPT.read_text())
    apps = json.loads(APPS_RECEIPT.read_text())
    rootfs = json.loads(ROOTFS_RECEIPT.read_text())
    exe = Path(driver['output_dir']) / 'FireSim-xilinx_alveo_u280'
    elf = Path(firmware['output_dir']) / 'platform/generic/firmware/fw_payload.elf'
    assert driver['returncode'] == firmware['returncode'] == 0
    assert driver['hardware_source_id'] == SOURCE_ID
    assert sha(exe) == driver['outputs'][str(exe)]
    assert sha(elf) == firmware['outputs'][str(elf)]
    assert rootfs['apps_manifest_sha256'] == sha(APPS_RECEIPT)
    assert sha(rootfs['path']) == rootfs['sha256']
    assert any(c['program'] == 'blackscholes' and c['input'] == 'simsmall' for c in apps['cases'])
    assert any(c['program'] == 'blackscholes' and c['input'] == 'simmedium' for c in apps['cases'])
    assert any(c['program'] == 'blackscholes' and c['input'] == 'test' for c in apps['cases'])
    assert apps['binaries']['blackscholes']['sha256'] == '75b4e2923b0a7b1d096023daa6610f5c622bf04771b4e2966bbdee006e5270ea'
    expected_case = next(c for c in apps['cases']
                         if c['program'] == 'blackscholes' and c['input'] == 'simmedium')
    native = []
    for result_path in sorted((D / 'runs').glob('native-blackscholes-simmedium-r*/result.json')):
        result = json.loads(result_path.read_text())
        ident = result['identity']
        complete_path = result_path.parent / 'complete.json'
        if (result.get('valid') and complete_path.is_file() and result.get('formal')
                and ident.get('configuration') == 'Native'
                and ident.get('input') == 'simmedium'):
            assert ident['apps_manifest_sha256'] == sha(APPS_RECEIPT)
            assert ident['rootfs_sha256'] == rootfs['sha256']
            assert ident['elf_sha256'] == apps['binaries']['blackscholes']['sha256']
            assert ident['case']['input_files'] == expected_case['input_files']
            assert ident['threads'] == 1 and ident['warmups'] == 0
            complete=json.loads(complete_path.read_text())
            assert complete['result_sha256']==sha(result_path)
            assert complete['identity_sha256']==result['identity_sha256']
            native.append(result)
    assert len(native) >= 3, 'need three valid Native simmedium samples for the C4 paired batch'
    return driver, firmware, apps, rootfs


def deploy():
    # Wait for known instance locks before requesting global XDMA maintenance.
    # board_batch re-acquires this lock and rechecks devices immediately before
    # any global operation; a race then stops deployment safely.
    while True:
        maintenance=(D/'locks/maintenance-0000_21_00.0.lock').open('a')
        try:
            fcntl.flock(maintenance,fcntl.LOCK_EX|fcntl.LOCK_NB)
            maintenance.close()
            break
        except BlockingIOError:
            maintenance.close()
            state.update(status='WAITING_FOR_ACTIVE_FPGA_SAMPLES',stage='C4-single-deploy')
            save(STATE_PATH,state)
            time.sleep(60)
    run('C4-single-deploy', ['python3', str(W / 'scripts/board_batch.py'),
                            '--deploy-only', '--single-c4-bdf', BDF])
    deployment = json.loads((D / 'latest-deployment.json').read_text())
    assert deployment['status'] == 'DEPLOYED_NOT_RUN' and deployment['configuration'] == 'C4'
    assert deployment['bdfs'] == [BDF] and deployment['serials'] == [SERIAL]
    card = deployment['completed_cards'][0]
    assert card['bdf'] == BDF and card['serial'] == SERIAL
    assert card['source_id'] == SOURCE_ID
    assert card['bitstream_sha256'] == state['bitstream_sha256']
    state['deployment_count'] += 1
    state['latest_deployment'] = dict(receipt=str(D / 'latest-deployment.json'),
                                      started_utc=deployment['started_utc'],
                                      bitstream_sha256=card['bitstream_sha256'])
    save(STATE_PATH, state)
    return deployment


def launch_sample(label, program, inp, repetition, formal, target_reset_probe):
    argv = ['python3', str(W / 'scripts/run_isolated_sample.py'), 'C4', program, inp,
            '--bdf', BDF, '--repetition', str(repetition), '--timeout', '3600',
            '--driver-receipt', str(DRIVER_RECEIPT), '--firmware-receipt', str(FIRMWARE_RECEIPT),
            '--apps-receipt', str(APPS_RECEIPT), '--rootfs-receipt', str(ROOTFS_RECEIPT)]
    if formal:
        argv.append('--formal')
    if target_reset_probe:
        argv.append('--target-reset-probe')
    before=json.loads((D / ('active-' + BDF.replace(':', '_') + '.json')).read_text()) if (D / ('active-' + BDF.replace(':', '_') + '.json')).exists() else {}
    rc = run(label, argv, allow_nonzero=True)
    active = json.loads((D / ('active-' + BDF.replace(':', '_') + '.json')).read_text())
    assert active.get('run_id') != before.get('run_id'), f'{label} did not create a new sample; inspect launch log'
    result_path = Path(active['run_dir']) / 'result.json'
    if result_path.exists():
        result = json.loads(result_path.read_text())
        row = dict(label=label, run_id=result['identity']['run_id'], run_dir=active['run_dir'],
                   returncode=rc, valid=result['valid'], status=active['status'],
                   roi_cycles=result.get('roi_cycles'), issues=result.get('issues', []),
                   target_reset_validation=result.get('target_reset_validation'))
    else:
        row = dict(label=label, run_dir=active.get('run_dir'), returncode=rc,
                   valid=False, status=active.get('status'), issues=['missing result.json'])
    state['samples'].append(row)
    save(STATE_PATH, state)
    return row


def committed_sample(program, inp, repetition, formal):
    for path in sorted((D/'runs').glob('c4-*/result.json'),reverse=True):
        result=json.loads(path.read_text());ident=result['identity'];complete_path=path.parent/'complete.json'
        if not (result.get('valid') and complete_path.exists() and result.get('formal')==formal):continue
        if not (ident['configuration']=='C4' and ident['program']==program and ident['input']==inp
                and ident['repetition']==repetition and ident['bitstream_sha256']==state['bitstream_sha256']
                and ident['firmware_receipt_sha256']==sha(FIRMWARE_RECEIPT)
                and ident['driver_receipt_sha256']==sha(DRIVER_RECEIPT)
                and ident['apps_manifest_sha256']==state['apps_manifest_sha256']
                and ident['rootfs_sha256']==state['rootfs_sha256']):continue
        complete=json.loads(complete_path.read_text())
        assert complete['result_sha256']==sha(path) and complete['identity_sha256']==result['identity_sha256']
        return dict(run_id=ident['run_id'],run_dir=str(path.parent),valid=True,status='COMPLETE',
                    roi_cycles=result['roi_cycles'],resumed=True,issues=[])


if args.check_software_only:
    check_software_receipts()
    print(json.dumps(dict(status='SOFTWARE_AND_NATIVE_BINDINGS_VALID', fpga_access=False)))
    raise SystemExit(0)

assert os.geteuid() == 0, 'administrator execution required for FPGA deployment'
lock = (D / 'locks/final-c4-continuation.lock').open('a')
fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
if STATE_PATH.exists():
    previous_state=json.loads(STATE_PATH.read_text())
    archive=D/('fpga-continuation-state-before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json')
    archive.write_bytes(STATE_PATH.read_bytes())
save(STATE_PATH, state)
try:
    driver, firmware, apps, rootfs = check_software_receipts()
    state.update(software_receipts=dict(driver=str(DRIVER_RECEIPT), firmware=str(FIRMWARE_RECEIPT),
        apps=str(APPS_RECEIPT), rootfs=str(ROOTFS_RECEIPT)),
        firmware_sha256=firmware['outputs'][str(Path(firmware['output_dir']) / 'platform/generic/firmware/fw_payload.elf')],
        apps_manifest_sha256=sha(APPS_RECEIPT), rootfs_sha256=rootfs['sha256'])
    save(STATE_PATH, state)
    bitstream_receipt = wait_for_certified_bitstream()

    # Keep only the bring-up gates here. The coverage-first service owns all
    # formal C4 repetitions so every ready benchmark gets r1 before r2/r3.
    samples = [('C4-smoke', 'smoke', 'test', 1, False),
               ('C4-blackscholes-test', 'blackscholes', 'test', 1, False),
               ('C4-blackscholes-simsmall', 'blackscholes', 'simsmall', 1, False)]
    driver_supports_restart = bool(driver.get('supports_target_restart'))
    deployment_ready = False
    reset_validated = driver_supports_restart
    samples_on_deployment = 0
    for label, program, inp, repetition, formal in samples:
        prior=committed_sample(program,inp,repetition,formal)
        if prior:
            state['samples'].append(dict(label=label,**prior));save(STATE_PATH,state)
            continue
        if not deployment_ready:
            deploy()
            deployment_ready = True
            reset_validated = driver_supports_restart
            samples_on_deployment = 0
        target_reset_probe = samples_on_deployment > 0 and not reset_validated
        row = launch_sample(label, program, inp, repetition, formal, target_reset_probe)
        samples_on_deployment += 1
        if not row['valid']:
            deployment_ready = False
            reset_validated = driver_supports_restart
        elif target_reset_probe:
            reset_validated = (row.get('target_reset_validation') or {}).get('status') == 'VALIDATED'
            if not reset_validated:
                deployment_ready = False
        run(label + '-summary', ['python3', str(W / 'scripts/summarize_results.py')], allow_nonzero=True)
        run(label + '-publish', ['python3', str(W / 'scripts/publish_live.py')], allow_nonzero=True)
        if not row['valid'] and not formal:
            if target_reset_probe and row.get('status')=='TIMEOUT':
                # A boot timeout can be a host bridge reset incompatibility.
                # Retry the same functional sample once on a fresh deployment;
                # this reuses the bitstream and retains the failed attempt.
                deploy()
                row=launch_sample(label+'-fresh-deployment-retry',program,inp,repetition,False,False)
                samples_on_deployment=1
                deployment_ready=row['valid']
                reset_validated=False
                if not row['valid']:
                    raise RuntimeError(f'{label} failed on fresh deployment; formal sampling remains gated')
            else:
                raise RuntimeError(f'{label} failed; formal sampling remains gated')
    failed = [s for s in state['samples'] if not s['valid']]
    state.update(status='C4_INITIAL_BATCH_COMPLETE' if not failed else 'C4_INITIAL_BATCH_FINISHED_WITH_FAILURES',
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 failed_samples=[s['run_id'] if 'run_id' in s else s['label'] for s in failed],
                 final_bitstream_sha256=bitstream_receipt['durable_bitstream_sha256'])
except Exception as exc:
    state.update(status='STOPPED_ON_CONCRETE_FAILURE', error=repr(exc),
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    raise
finally:
    save(STATE_PATH, state)
