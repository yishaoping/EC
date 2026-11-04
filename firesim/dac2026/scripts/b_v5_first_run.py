#!/usr/bin/env python3
"""B-only manual first boot. prepare/preflight/verify never execute a target.

Only the explicit `run` subcommand starts the native FPGA driver. It does not
program/reset/unbind a card, reload XDMA, or invoke FireSim manager deployment.
"""
import argparse
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import shlex
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from ec_dac.audit import hardware
from inspect_roi_raw import inspect_bytes

ROOT = Path('/data1/gzh/EC')
KIT = ROOT / 'firesim/dac2026'
EXPERIMENT = ROOT / 'Experiment/dac2026'
SOURCE_ID = 'be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4'
DRIVER_RECEIPT = EXPERIMENT / 'build-logs/opt4-roi-v5/B-driver-20261102T093023.904481Z/result.json'
FIRMWARE_RECEIPT = EXPERIMENT / 'build-logs/opt4-alveo-v3/firmware-20261102T085039.525331Z/result.json'
MEMORY = KIT / 'config/firesim/memory-opt4-roi-v5/manifest.json'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    # First-run files are exclusive; an interrupted run is preserved forever.
    with Path(path).open('x') as stream:
        json.dump(value, stream, indent=2); stream.write('\n')
        stream.flush(); os.fsync(stream.fileno())


def require(value, reason):
    if not value:
        raise ValueError(reason)


def check_artifacts(bindings):
    for path, expected in bindings.items():
        require(Path(path).is_file() and sha(path) == expected, 'artifact changed/missing: ' + path)


def preflight(out):
    result = hardware()
    result['time_utc'] = dt.datetime.now(dt.timezone.utc).isoformat()
    result['operation'] = 'read-only; no FPGA device opened'
    save(out, result)
    print(out)
    print(json.dumps({k: result[k] for k in ['devices', 'occupancy', 'fpga_processes',
                      'proc_permission_denied']}, indent=2))


def prepare(args):
    directory = args.out.resolve()
    require(directory.is_relative_to(EXPERIMENT), 'run directory must be under Experiment/dac2026')
    require(args.bdf in ['0000:21:00.0', '0000:e2:00.0'], 'use a full audited BDF')
    directory.mkdir(parents=True, exist_ok=False)
    driver, firmware, memory = read(DRIVER_RECEIPT), read(FIRMWARE_RECEIPT), read(MEMORY)
    require(driver['returncode'] == firmware['returncode'] == 0, 'driver/firmware build failed')
    require(driver['source_id'] == SOURCE_ID, 'B v5 driver source mismatch')
    exe = str(Path(driver['output_dir']) / 'FireSim-xilinx_alveo_u280')
    elf = str(Path(firmware['output_dir']) / 'platform/generic/firmware/fw_payload.elf')
    artifacts = {str(p): sha(p) for p in [DRIVER_RECEIPT, FIRMWARE_RECEIPT, MEMORY,
        EXPERIMENT / 'preparation/opt4-roi-v5/B-raw-bridge-compile-content-verified.json',
        EXPERIMENT / 'preparation/opt4-roi-v5/software-reuse-v4-v5-corrected.json']}
    for path, receipt in [(exe, driver), (elf, firmware)]:
        require(sha(path) == receipt['outputs'][path], 'output differs from receipt: ' + path)
        artifacts[path] = receipt['outputs'][path]
    bitstream = None
    blockers = []
    if args.bitstream_result:
        bit = read(args.bitstream_result)
        require(bit['returncode'] == 0 and bit['certified_bitstream'] is True and
                bit['source_id'] == SOURCE_ID, 'not a successful B v5 bitstream receipt')
        bitstream = str(Path(bit['output_dir']) / 'vivado_proj/firesim.bit')
        check_artifacts(bit['outputs'])
        artifacts[bitstream] = bit['outputs'][bitstream]
        artifacts[str(args.bitstream_result.resolve())] = sha(args.bitstream_result)
    else:
        blockers.append('successful B v5 bitstream receipt is absent; run is refused')
    domain, bus, slotfun = args.bdf.split(':')
    device, function = slotfun.split('.')
    argv = [exe, '+permissive', '+domain=' + domain, '+bus=' + bus,
        '+device=' + device, '+function=' + function, '+bar=0',
        '+pci-vendor=10ee', '+pci-device=903f',
        '+ec-dac-roi-log=' + str(directory / 'roi-raw.jsonl'),
        '+ec-dac-snapshot-seconds=20', '+fesvr-step-size=2004765',
        *memory['plusargs'], '+permissive-off', '+prog0=' + elf]
    # No C4, strict latency, batch collector or figure-generation gate here.
    plan = dict(schema='ec-dac-b-first-run/1', configuration='B', integration='opt4-roi-v5',
        source_id=SOURCE_ID, source_tree=driver['source_tree'],
        firesim_root=driver['source_tree'] + '/sims/firesim',
        firesim_commit=driver['firesim_commit'],
        manager_environment=str(ROOT / 'firesim/envs/manager-1.17.1'),
        manager_used_for_deployment=False, target_bdf=args.bdf, directory=str(directory),
        bitstream=bitstream, artifacts=artifacts, argv=argv, blockers=blockers,
        firmware_contains_kernel_dtb_initramfs=True, extra_disk_image_required=False,
        formal_sample=False, runtime_validation='NOT_RUN',
        effects=dict(starts_driver=True, programs_fpga=False, driver_reload=False,
                     global_xdma_operation=False, device_unbind=False, pcie_rescan=False))
    save(directory / 'plan.json', plan)
    print('B v5 driver command (only after safe deployment):\n' + shlex.join(argv))
    print('Guest: /opt/ec-dac/manual-link.sh smoke')
    print('After host observes a complete epoch: /bin/busybox sync; /bin/poweroff -f')
    print('Blockers: ' + json.dumps(blockers))
    return 0


def run(args):
    plan = read(args.plan)
    require(not plan['blockers'] and plan['bitstream'], 'bitstream receipt missing: re-prepare in a new directory')
    check_artifacts(plan['artifacts'])
    deployment = read(args.deployment_record)
    require(deployment['bdf'] == plan['target_bdf'] and
            deployment['bitstream_sha256'] == plan['artifacts'][plan['bitstream']],
            'manual deployment record does not bind this BDF and bitstream')
    require(deployment['no_global_xdma_actions'] is True and deployment['operator'],
            'deployment scope/operator missing')
    require(deployment.get('serial') in {'21770433G001A', '21770433G02LA'}, 'unknown board serial')
    expected_serial = {'0000:e2:00.0': '21770433G001A', '0000:21:00.0': '21770433G02LA'}
    require(deployment['serial'] == expected_serial[plan['target_bdf']], 'BDF/serial mismatch')
    expires = dt.datetime.fromisoformat(deployment['exclusive_until_utc'])
    require(expires.tzinfo is not None and expires > dt.datetime.now(dt.timezone.utc), 'reservation expired')
    require(set(deployment['reserved_bdfs']) >= {'0000:21:00.0', '0000:e2:00.0'},
            'both-card reservation required while per-card deployment isolation is unproved')
    directory = Path(plan['directory'])
    state = hardware()  # immediately recheck both cards and all visible tasks
    save(directory / 'pre-run-preflight.json', state)
    require(not state['fpga_processes'] and not state['open_devices'], 'existing FPGA tasks: run refused')
    require(state['proc_permission_denied'] == 0, 'incomplete /proc visibility: run with administrator visibility')
    require(any(d['bdf'] == plan['target_bdf'] and d['driver'] == 'xdma' for d in state['devices']),
            'target BDF/XDMA mapping absent')
    save(directory / 'deployment-record.json', deployment)
    save(directory / 'started.json', dict(plan_sha256=sha(args.plan),
         utc=dt.datetime.now(dt.timezone.utc).isoformat(), status='RUNNING', formal_sample=False))
    print('Starts native driver on ' + plan['target_bdf'] + '; no deployment or global driver operations.', flush=True)
    # util-linux script preserves interactive UART stdin and flushes the live
    # console transcript. Raw bridge JSONL additionally fsyncs every record.
    env = os.environ.copy()
    env['PATH'] = '/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin'
    for key in ['LD_LIBRARY_PATH', 'LD_PRELOAD']:
        env.pop(key, None)
    rc = subprocess.run(['/usr/bin/script', '--quiet', '--return', '--flush',
        '--command', shlex.join(plan['argv']), str(directory / 'console.log')],
        cwd=directory, env=env).returncode
    save(directory / 'exit.json', dict(returncode=rc, formal_sample=False,
         utc=dt.datetime.now(dt.timezone.utc).isoformat()))
    return rc


def verify(args):
    directory = args.run_dir.resolve()
    plan = read(directory / 'plan.json')
    check_artifacts(plan['artifacts'])
    console_bytes = (directory / 'console.log').read_bytes()
    console = console_bytes.decode(errors='replace').replace('\r', '')
    raw = inspect_bytes((directory / 'roi-raw.jsonl').read_bytes())
    complete = [e for e in raw['epochs'] if e['source_boundaries_complete']]
    issues = []
    if plan['blockers'] or not plan['bitstream'] or not (directory / 'started.json').exists():
        issues.append('bound bitstream and actual launcher start not established')
    elif read(directory / 'started.json')['plan_sha256'] != sha(directory / 'plan.json'):
        issues.append('plan changed after launcher start')
    if raw['protocol_issues'] or raw['partial_tail_bytes']:
        issues.append('raw transport invalid/partial')
    if len(raw['epochs']) != 1 or len(complete) != 1:
        issues.append('expected exactly one complete nonfaulted ROI epoch')
    for expected in ['Linux version ', 'DAC_SMOKE checksum=500500 expected=500500',
                     'EC_DAC_PREREQUISITE_END mode=smoke output_valid=true formal_sample=false']:
        if expected not in console:
            issues.append('missing console evidence: ' + expected)
    if 'EC_DAC_ROI_OBSERVER_FAILED' in console:
        issues.append('observer failed')
    exit_path = directory / 'exit.json'
    if not exit_path.exists() or read(exit_path)['returncode'] != 0:
        issues.append('driver normal exit not established')
    result = dict(schema='ec-dac-b-first-run-result/1', source_id=plan['source_id'],
        plan_sha256=sha(directory / 'plan.json'), raw_sha256=sha(directory / 'roi-raw.jsonl'),
        console_sha256=hashlib.sha256(console_bytes).hexdigest(),
        status='FIRST_RUN_PASSED' if not issues else 'INCOMPLETE_OR_FAILED', issues=issues,
        roi_cycles=complete[0]['roi_cycles'] if len(complete) == 1 else None,
        correctness=not any('console evidence' in i for i in issues),
        generated_checks=0, completed_checks=0, count_basis='B has no checker; B Linux driver also requires zero counters',
        checker_latency=None, raw=raw, formal_sample=False,
        scope='one B smoke run only; no C4, slowdown, latency or formal experiment admission')
    save(args.out, result)
    print(json.dumps({k: result[k] for k in ['status', 'roi_cycles', 'issues', 'formal_sample']}, indent=2))
    return 0 if not issues else 2


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    subs = parser.add_subparsers(dest='command', required=True)
    p = subs.add_parser('preflight'); p.add_argument('--out', type=Path, required=True)
    p = subs.add_parser('prepare'); p.add_argument('--bdf', required=True)
    p.add_argument('--out', type=Path, required=True); p.add_argument('--bitstream-result', type=Path)
    p = subs.add_parser('run'); p.add_argument('--plan', type=Path, required=True)
    p.add_argument('--deployment-record', type=Path, required=True)
    p = subs.add_parser('verify'); p.add_argument('--run-dir', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    try:
        if args.command == 'preflight':
            preflight(args.out); return 0
        return {'prepare': prepare, 'run': run, 'verify': verify}[args.command](args)
    except (ValueError, KeyError, OSError) as error:
        print('REFUSED: ' + str(error), file=sys.stderr); return 2


if __name__ == '__main__':
    sys.exit(main())
