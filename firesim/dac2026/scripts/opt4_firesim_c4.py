#!/usr/bin/env python3
"""Fail-closed manual C4 FireSim launcher and Blackscholes result verifier.

This program never programs/resets a card and never reloads or unbinds XDMA.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import signal
import subprocess
import sys
import time

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_minimal import ROOT, inventory, sha
from ec_dac.audit import hardware

KIT = ROOT / 'firesim/dac2026'
WORK = KIT / 'work/opt4-linux-v6'
RESULTS = ROOT / 'Experiment/dac2026/opt4-linux-v6/firesim'
MEMORY = KIT / 'config/firesim/memory-opt4-roi-v5/manifest.json'
EXPECTED_FS = '07efa6a6da18bd64d1159ae84a4701b37abb1228'
EXPECTED_DEVICES = {'0000:21:00.0', '0000:e2:00.0'}
SERIAL_BY_BDF = {'0000:e2:00.0': '21770433G001A', '0000:21:00.0': '21770433G02LA'}


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('x') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def save_idempotent(path, value):
    path = Path(path)
    if path.exists():
        if read(path) != value:
            raise ValueError('existing result differs: ' + str(path))
        return
    temporary = path.with_name('.' + path.name + '.' + str(os.getpid()) + '.tmp')
    try:
        with temporary.open('x') as stream:
            json.dump(value, stream, indent=2)
            stream.write('\n')
            stream.flush()
            os.fsync(stream.fileno())
        try:
            os.link(temporary, path)
        except FileExistsError:
            if read(path) != value:
                raise ValueError('concurrent result differs: ' + str(path))
        fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
        try:
            os.fsync(fd)
        finally:
            os.close(fd)
    finally:
        temporary.unlink(missing_ok=True)


def check_file_map(files, label):
    for path, digest in (files or {}).items():
        if not Path(path).is_file() or sha(path) != digest:
            raise ValueError(label + ' file missing/changed: ' + path)


def check_receipt_files(record, label):
    if record.get('returncode') != 0:
        raise ValueError(label + ' build failed')
    check_file_map(record.get('outputs'), label + ' output')
    check_file_map(record.get('input_files'), label + ' input')


def check_memory():
    memory = read(MEMORY)
    settings = memory['settings']
    expected = [f'+mm_{k}_0={v}' for k, v in sorted(settings.items())]
    args = MEMORY.parent / 'fased-common.args'
    if memory.get('model') != 'LatencyBandwidthPipe' or memory.get('model_index') != 0 or \
            memory.get('static_register_audit') != 'PASSED':
        raise ValueError('C4 FASED runtime manifest has no static register audit')
    if memory.get('plusargs') != expected or args.read_text().split() != expected or \
            sha(args) != memory['arguments_sha256']:
        raise ValueError('C4 FASED manifest and runtime arguments differ')
    return memory


def native_smoke_prerequisite(bit):
    """CAD can overlap native execution; driver preparation requires its PASS."""
    manifest_path = bit.get('stage_b_manifest')
    if manifest_path:
        manifest_path = Path(manifest_path).resolve()
        manifest = read(manifest_path)
        attempt = manifest_path.parent
        verification_path = attempt / 'verification.json'
        completion_path = ROOT / 'Experiment/dac2026/opt4-linux-v6/linux/complete' / (attempt.name + '.json')
        if not verification_path.is_file() or not completion_path.is_file():
            raise ValueError('pure CAD output is not deployment-ready: matching native Linux smoke has not committed PASS')
        verification, completion = read(verification_path), read(completion_path)
        if verification.get('identity') != manifest.get('identity') or \
                any(completion.get(k) != v for k, v in verification.items()):
            raise ValueError('native Linux smoke completion/manifest identity mismatch')
        paths = [manifest_path, verification_path, completion_path]
    elif bit.get('stage_b_result'):
        verification_path = Path(bit['stage_b_result']).resolve()
        verification = read(verification_path)
        paths = [verification_path]
    else:
        raise ValueError('bitstream receipt has no bound native smoke prerequisite')
    if verification.get('valid') is not True or verification.get('runtime_validation') != 'PASS' or \
            verification.get('mode') != 'smoke':
        raise ValueError('native Linux smoke prerequisite is not a valid real-run PASS')
    return {str(path): sha(path) for path in paths}


def artifacts(driver_path, bitstream_path):
    driver = read(driver_path)
    bit = read(bitstream_path)
    gg_path = Path(driver['input_result']).resolve()
    gg = read(gg_path)
    elab_path = Path(gg['input_result']).resolve()
    elab = read(elab_path)
    fs = read(WORK / 'firesim-software/firmware-build.json')
    fdt = read(WORK / 'firesim-software/fdt-build.json')
    kernel = read(WORK / 'kernel-build.json')
    rootfs = read(WORK / 'rootfs-build.json')
    apps = read(WORK / 'apps-build.json')
    for record, label in [(driver, 'FireSim driver'), (bit, 'C4 bitstream'),
                          (gg, 'GoldenGate'), (elab, 'FireSim elaboration'),
                          (fs, 'FireSim firmware'), (kernel, 'C4 kernel')]:
        check_receipt_files(record, label)
    check_file_map(bit.get('inputs'), 'C4 bitstream declared input')
    check_file_map(bit.get('effective_cad_inputs'), 'C4 Vivado effective input')
    for record, label in [(rootfs, 'C4 rootfs'), (apps, 'C4 applications')]:
        if record.get('returncode') != 0:
            raise ValueError(label + ' build failed')
    if driver.get('phase') != 'driver' or driver.get('config') != 'DacOpt4C4' or \
            driver.get('integration') != 'opt4-linux-v6' or \
            driver.get('platform_config') != 'DacXilinxAlveoConfig':
        raise ValueError('wrong FireSim driver receipt')
    if bit.get('phase') != 'bitstream' or bit.get('configuration') != 'C4' or \
            bit.get('integration') != 'opt4-linux-v6' or bit.get('certified_bitstream') is not True:
        raise ValueError('no certified opt4-linux-v6 C4 bitstream receipt')
    native_prerequisites = native_smoke_prerequisite(bit)
    source_id = driver.get('source_id')
    if any(x.get('source_id') != source_id for x in [gg, elab, bit]) or \
            driver.get('firesim_commit') != EXPECTED_FS or gg.get('firesim_commit') != EXPECTED_FS:
        raise ValueError('C4 hardware/driver/bitstream source identity mismatch')
    current_source_id = hashlib.sha256(json.dumps(
        inventory(WORK / 'C4/chipyard'), sort_keys=True).encode()).hexdigest()
    if source_id != current_source_id:
        raise ValueError('current C4 FireSim source differs from the compiled source identity')
    if driver.get('input_result') != str(gg_path) or \
            driver.get('input_result_sha256') != sha(gg_path) or \
            gg.get('input_result') != str(elab_path) or \
            gg.get('input_result_sha256') != sha(elab_path):
        raise ValueError('FireSim phase receipts do not bind their immediate input results')
    if fs.get('configuration') != 'C4-v6-FireSim' or fdt.get('configuration') != 'C4-v6-FireSim':
        raise ValueError('wrong FireSim Linux/FDT receipts')
    if fs.get('input_files', {}).get(fdt.get('fdt')) != fdt.get('sha256'):
        raise ValueError('OpenSBI payload does not bind the FireSim FDT')
    if fdt.get('source_dts_sha256') != elab.get('outputs', {}).get(fdt.get('source_dts')):
        raise ValueError('FireSim FDT is from another elaboration')
    if kernel.get('returncode') != 0 or rootfs.get('returncode') != 0 or apps.get('returncode') != 0:
        raise ValueError('C4 Linux/rootfs/application build failed')
    if kernel.get('input_files', {}).get(rootfs.get('initramfs')) != rootfs.get('sha256'):
        raise ValueError('kernel was built with a different initramfs')
    app_manifest = Path(apps['output_dir']) / 'manifest.json'
    if rootfs.get('apps_manifest_sha256') != sha(app_manifest):
        raise ValueError('rootfs contains a different applications build')
    app = Path(apps['output_dir']) / 'blackscholes'
    input_file = Path(apps['output_dir']) / 'inputs/test/in_4.txt'
    if sha(app) != apps['binaries']['blackscholes'] or \
            sha(input_file) != apps['inputs']['test']['files']['in_4.txt']:
        raise ValueError('Blackscholes binary/input changed')
    if 'C4-v6' not in apps.get('shared_binary_for', ['C4-v6']):
        raise ValueError('application receipt is not eligible for the C4 shared binary')
    driver_bin = Path(driver['output_dir']) / 'FireSim-xilinx_alveo_u280'
    firmware = Path(fs['output_dir']) / 'platform/generic/firmware/fw_payload.elf'
    bitstream = Path(bit['output_dir']) / 'vivado_proj/firesim.bit'
    for path, record, key in [(driver_bin, driver, 'outputs'), (firmware, fs, 'outputs'),
                              (bitstream, bit, 'outputs')]:
        if not path.is_file() or record['outputs'].get(str(path)) != sha(path):
            raise ValueError('unbound run artifact: ' + str(path))
    memory = check_memory()
    bound = dict(native_prerequisites)
    for label, path in [('driver_receipt', driver_path), ('goldengate_receipt', gg_path),
                        ('elaboration_receipt', elab_path), ('bitstream_receipt', bitstream_path),
                        ('firmware_receipt', WORK/'firesim-software/firmware-build.json'),
                        ('fdt_receipt', WORK/'firesim-software/fdt-build.json'),
                        ('kernel_receipt', WORK/'kernel-build.json'),
                        ('rootfs_receipt', WORK/'rootfs-build.json'),
                        ('apps_receipt', WORK/'apps-build.json'), ('memory_manifest', MEMORY)]:
        bound[str(Path(path).resolve())] = sha(path)
    for path in [driver_bin, firmware, bitstream, Path(fdt['fdt']), Path(rootfs['initramfs']),
                 app, input_file, app_manifest]:
        bound[str(path.resolve())] = sha(path)
    for record in [driver, bit, gg, elab, fs, kernel]:
        for files in [record.get('outputs'), record.get('input_files')]:
            for path in (files or {}):
                bound[str(Path(path).resolve())] = sha(path)
    return {'source_id': source_id, 'driver': driver, 'bitstream': bit,
            'driver_bin': str(driver_bin), 'firmware': str(firmware),
            'bitstream_file': str(bitstream), 'fdt': fdt, 'kernel': kernel,
            'rootfs': rootfs, 'apps': apps, 'app': str(app), 'input': str(input_file),
            'app_manifest': str(app_manifest), 'memory': memory, 'bound': bound}


def check_hashes(bound):
    for path, expected in bound.items():
        if not Path(path).is_file() or sha(path) != expected:
            raise ValueError('source/config/software artifact changed: ' + path)


def idle_reasons(state, target):
    reasons = []
    devices = {x['bdf']: x for x in state['devices']}
    if target not in devices or devices[target].get('driver') != 'xdma':
        reasons.append('selected BDF is absent or not bound to XDMA')
    if set(devices) != EXPECTED_DEVICES:
        reasons.append('expected both audited AU280 devices; inventory differs')
    if state['fpga_processes']:
        reasons.append('FireSim process exists on the host')
    if state['open_devices']:
        reasons.append('an XDMA/XCL/DRM device is open')
    if state['proc_permission_denied']:
        reasons.append('process/device ownership is not fully visible in /proc')
    if state['occupancy'] != 'UNKNOWN' and (state['fpga_processes'] or state['open_devices']):
        reasons.append('FPGA host reports active workload')
    return reasons


def preflight(out, target=None):
    state = hardware()
    state['time_utc'] = dt.datetime.now(dt.timezone.utc).isoformat()
    state['operation'] = 'read-only; no FPGA device opened'
    if target:
        state['target_bdf'] = target
        state['allowed_for_driver_start'] = not idle_reasons(state, target)
        state['refusal_reasons'] = idle_reasons(state, target)
    save(out, state)
    print(json.dumps(state, indent=2))
    return 0 if not target or state['allowed_for_driver_start'] else 2


def prepare(args):
    if args.bdf not in EXPECTED_DEVICES:
        raise ValueError('select an audited full BDF')
    r = artifacts(args.driver_result, args.bitstream_result)
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    attempt = RESULTS / 'partial' / stamp
    raw = RESULTS / 'raw' / stamp
    attempt.mkdir(parents=True, exist_ok=False)
    raw.mkdir(parents=True, exist_ok=False)
    domain, bus, slotfun = args.bdf.split(':')
    device, function = slotfun.split('.')
    argv = [r['driver_bin'], '+permissive', '+domain='+domain, '+bus='+bus,
        '+device='+device, '+function='+function, '+bar=0', '+pci-vendor=10ee',
        '+pci-device=903f', '+fesvr-step-size=2004765', *r['memory']['plusargs'],
        '+permissive-off', '+prog0='+r['firmware']]
    stage = {'configuration': 'C4', 'integration': 'opt4-linux-v6', 'source_id': r['source_id'],
             'driver_result': str(args.driver_result.resolve()),
             'bitstream_result': str(args.bitstream_result.resolve()), 'bdf': args.bdf,
             'bitstream_file': r['bitstream_file'], 'mode': args.mode,
             'guest_command': '/opt/ec-dac/manual-link.sh ' + args.mode,
             'created_utc': dt.datetime.now(dt.timezone.utc).isoformat(),
             'artifacts': r['bound'], 'argv': argv, 'raw_dir': str(raw),
             'identity': hashlib.sha256(json.dumps(r['bound'], sort_keys=True).encode()).hexdigest(),
             'programming_by_this_script': False,
             'effects': {'starts_driver': False, 'programs_fpga': False, 'resets_fpga': False,
                         'driver_reload': False, 'global_xdma_operation': False,
                         'device_unbind': False, 'pcie_rescan': False},
             'runtime_validation': 'NOT_RUN', 'formal_sample': False}
    save(attempt / 'plan.json', stage)
    print(attempt)
    print('This only prepares a plan. After a separately reviewed safe load, the manual deployment record is required.')


def verify_deployment(plan, path):
    record = read(path)
    if record.get('bdf') != plan['bdf'] or record.get('serial') != SERIAL_BY_BDF[plan['bdf']]:
        raise ValueError('deployment BDF/board serial mismatch')
    if record.get('loaded_bitstream_sha256') != plan['artifacts'][plan['bitstream_file']]:
        raise ValueError('recorded loaded bitstream does not match this plan')
    if not record.get('operator') or not record.get('programming_scope_reviewed') or \
            not record.get('other_card_idle_during_programming') or \
            not record.get('both_cards_idle_at_driver_start'):
        raise ValueError('deployment record lacks operator and two-card programming/start evidence')
    if not set(record.get('reserved_bdfs', [])) >= EXPECTED_DEVICES:
        raise ValueError('exclusive reservation must include both cards')
    expires = dt.datetime.fromisoformat(record['exclusive_until_utc'])
    if expires.tzinfo is None or expires <= dt.datetime.now(dt.timezone.utc):
        raise ValueError('exclusive reservation expired')
    return record


def emit_new_lines(console, offset, tail, event_stream):
    if not console.is_file():
        return offset, tail, 0
    with console.open('rb') as stream:
        stream.seek(offset)
        data = stream.read()
    offset += len(data)
    lines = (tail + data).split(b'\n')
    tail = lines.pop()
    count = 0
    for rawline in lines:
        line = rawline.decode(errors='replace').replace('\r', '')
        if 'EC_OPT4_' in line or re.search(r'Kernel panic|Assertion failed|%Error|Aborted', line, re.I):
            event_stream.write(json.dumps({'utc': dt.datetime.now(dt.timezone.utc).isoformat(),
                'line': line, 'formal_sample': False}) + '\n')
            event_stream.flush()
            os.fsync(event_stream.fileno())
            count += 1
    return offset, tail, count


def run(args):
    if os.geteuid() != 0:
        raise ValueError('run must be invoked as root so all-card /proc inspection and XDMA access are complete')
    run_lock = open(RESULTS / '.c4-host-global-run.lock', 'a')
    try:
        fcntl.flock(run_lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BlockingIOError:
        raise ValueError('another C4 FireSim driver holds the host-wide run lock')
    plan_path = args.plan.resolve()
    plan = read(plan_path)
    if plan_path.name != 'plan.json' or plan_path.parent.parent != RESULTS / 'partial':
        raise ValueError('plan is not under the C4 FireSim partial result directory')
    check_hashes(plan['artifacts'])
    deploy = verify_deployment(plan, args.deployment_record)
    state = hardware()
    pre = {'time_utc': dt.datetime.now(dt.timezone.utc).isoformat(), **state}
    save(Path(plan['raw_dir']) / 'pre-run-preflight.json', pre)
    reasons = idle_reasons(state, plan['bdf'])
    if reasons:
        raise ValueError('safe driver start refused: ' + '; '.join(reasons))
    save(Path(plan['raw_dir']) / 'deployment-record.json', deploy)
    save(plan_path.parent / 'started.json', {'identity': plan['identity'],
        'plan_sha256': sha(plan_path), 'time_utc': dt.datetime.now(dt.timezone.utc).isoformat(),
        'status': 'RUNNING', 'programming_by_this_script': False, 'formal_sample': False})
    raw = Path(plan['raw_dir'])
    console, events, progress = raw/'console.log', raw/'opt4-events.jsonl', raw/'progress.jsonl'
    argv = ['/usr/bin/script', '--quiet', '--return', '--flush', '--command',
            shlex.join(plan['argv']), str(console)]
    env = os.environ.copy()
    env['PATH'] = '/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin'
    for key in ['LD_LIBRARY_PATH', 'LD_PRELOAD']:
        env.pop(key, None)
    child = None
    def stop(sig, frame):
        if child and child.poll() is None:
            child.send_signal(signal.SIGTERM)
    signal.signal(signal.SIGTERM, stop)
    with events.open('x', buffering=1) as event_stream, progress.open('x', buffering=1) as progress_stream:
        child = subprocess.Popen(argv, cwd=plan_path.parent, env=env)
        offset = 0
        tail = b''
        evidence_count = 0
        last_sync = 0.0
        print('Starting C4 FireSim driver only on ' + plan['bdf'] +
              '; this command does not load/reset the bitstream or touch the other BDF.', flush=True)
        print('At the Linux shell run: ' + plan['guest_command'] +
              '\nAfter it reports completion run: /bin/busybox sync; /bin/busybox poweroff -f', flush=True)
        while child.poll() is None:
            offset, tail, added = emit_new_lines(console, offset, tail, event_stream)
            evidence_count += added
            now = time.monotonic()
            if now - last_sync >= 5:
                if console.exists():
                    fd = os.open(console, os.O_RDONLY)
                    try: os.fsync(fd)
                    finally: os.close(fd)
                progress_stream.write(json.dumps({'utc': dt.datetime.now(dt.timezone.utc).isoformat(),
                    'identity': plan['identity'], 'console_bytes': offset,
                    'opt4_or_error_lines': evidence_count, 'completion': 'UNCOMMITTED',
                    'formal_sample': False}) + '\n')
                progress_stream.flush()
                os.fsync(progress_stream.fileno())
                last_sync = now
            time.sleep(.5)
        offset, tail, added = emit_new_lines(console, offset, tail, event_stream)
        evidence_count += added
        if tail:
            event_stream.write(json.dumps({'utc': dt.datetime.now(dt.timezone.utc).isoformat(),
                'partial_tail': tail.decode(errors='replace'), 'formal_sample': False}) + '\n')
            event_stream.flush()
            os.fsync(event_stream.fileno())
        if console.exists():
            fd = os.open(console, os.O_RDONLY)
            try: os.fsync(fd)
            finally: os.close(fd)
        progress_stream.write(json.dumps({'utc': dt.datetime.now(dt.timezone.utc).isoformat(),
            'identity': plan['identity'], 'console_bytes': offset,
            'opt4_or_error_lines': evidence_count, 'completion': 'UNCOMMITTED',
            'formal_sample': False}) + '\n')
        progress_stream.flush()
        os.fsync(progress_stream.fileno())
    exit_record = {'returncode': child.returncode, 'identity': plan['identity'],
                   'time_utc': dt.datetime.now(dt.timezone.utc).isoformat(),
                   'formal_sample': False}
    save(plan_path.parent / 'exit.json', exit_record)
    return verify_attempt(plan_path.parent)


def verify_attempt(attempt):
    attempt = Path(attempt).resolve()
    if attempt.parent != RESULTS / 'partial':
        raise ValueError('attempt is not under the C4 FireSim partial result directory')
    plan = read(attempt / 'plan.json')
    raw = Path(plan['raw_dir'])
    console_path = raw / 'console.log'
    console_bytes = console_path.read_bytes() if console_path.is_file() else b''
    console = console_bytes.decode(errors='replace').replace('\r', '')
    rtl = '\n'.join(line for line in console.splitlines() if 'EC_OPT4_' in line)
    reasons = []
    check_hashes(plan['artifacts'])
    started_path = attempt/'started.json'
    if not started_path.is_file():
        reasons.append('no actual driver start')
    else:
        started = read(started_path)
        if started.get('identity') != plan['identity'] or \
                started.get('plan_sha256') != sha(attempt/'plan.json'):
            reasons.append('driver start evidence is bound to another plan')
    exit_path = attempt/'exit.json'
    if not exit_path.is_file():
        reasons.append('FireSim driver did not exit normally')
    else:
        exit_record = read(exit_path)
        if exit_record.get('returncode') != 0:
            reasons.append('FireSim driver did not exit normally')
        if exit_record.get('identity') != plan['identity']:
            reasons.append('driver exit evidence is bound to another plan')
    apps = read(WORK/'apps-build.json')
    mode = plan.get('mode')
    if mode not in {'smoke', 'test'}:
        reasons.append('unsupported or missing FPGA guest mode')
    if mode and console.count('EC_OPT4_LINUX_END mode=' + mode + ' correctness=PASS application_exit=0') != 1:
        reasons.append('guest success marker absent or duplicated')
    if mode == 'smoke':
        if console.count('DAC_SMOKE checksum=500500 expected=500500') != 1:
            reasons.append('smoke checksum output missing or incorrect')
    elif mode == 'test':
        if console.count('BLACKSCHOLES_OUTPUT_VALID count=4 absolute_tolerance=0.0001') != 1:
            reasons.append('four reference outputs were not validated')
        input_rel = 'inputs/test/in_4.txt'
        input_hash = apps['inputs']['test']['files']['in_4.txt']
        if console.count(input_hash + '  ' + input_rel) != 1:
            reasons.append('guest did not report the bound PARSEC input')
    if console.count(sha(plan['app_manifest']) + '  BUILD.json') != 1:
        reasons.append('guest software manifest differs')
    if console.count('EC_OPT4_APPLICATION_EXIT code=0 capture_exit=0') != 1:
        reasons.append('guest application/capture exit was not successful')
    if 'EC_OPT4_INVALID' in console or 'Kernel panic' in console:
        reasons.append('Linux checker scope or kernel failure')

    contexts = re.findall(r'EC_OPT4_CONTEXT .*satp=([0-9a-fA-F]+).*hardware_initialized=1', console)
    installed = re.findall(r'EC_OPT4_INSTALLED hart=(\d+) satp=([0-9a-fA-F]+)', console)
    if len(contexts) != 1 or len(installed) != 4 or \
            {int(h) for h, _ in installed} != {1, 2, 3, 4} or \
            any(s.lower() != contexts[0].lower() for _, s in installed if contexts):
        reasons.append('four checker harts did not install the BOOM Linux address space')

    begins = re.findall(r'EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-fA-F]+) satp=([0-9a-fA-F]+) prv=\s*(\d+)', rtl)
    results = re.findall(r'EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-fA-F]+) status=\s*(\d+) full_compare=([01]) cancelled=([01])', rtl)
    if not begins or not results:
        reasons.append('no synthesized real Opt4 package/result events captured')
    context_satp = int(contexts[0], 16) if len(contexts) == 1 else None
    if any(int(h) not in {1, 2, 3, 4} or int(s, 16) != context_satp or int(prv) != 0
           for h, seq, s, prv in begins):
        reasons.append('checker package did not execute in the expected U-mode context')
    if any(int(status) != 0 or full != '1' or cancelled != '0'
           for _, _, status, full, cancelled in results):
        reasons.append('a real Opt4 final comparison failed or was cancelled')
    begin_pairs = [(int(h), int(seq, 16)) for h, seq, _, _ in begins]
    result_pairs = [(int(h), int(seq, 16)) for h, seq, _, _, _ in results]
    if len(set(begin_pairs)) != len(begin_pairs) or set(begin_pairs) != set(result_pairs):
        reasons.append('package and comparison-result sequence IDs do not pair exactly')

    snapshots = re.findall(r'EC_OPT4_SNAPSHOT ([^\r\n]*)', console)
    fields = dict(re.findall(r'(\w+)=(\w+)', snapshots[-1])) if snapshots else {}
    counts = {}
    try:
        counts = {k: int(fields[k]) for k in ['begin', 'end', 'drain', 'generated',
            'completed', 'outstanding', 'faults', 'passed', 'failed', 'cancelled', 'dropped']}
        if not (counts['end'] > counts['begin'] and counts['drain'] >= counts['end']):
            reasons.append('ROI/drain cycles are invalid')
        if not (counts['generated'] > 0 and counts['generated'] == counts['completed'] == counts['passed']):
            reasons.append('real checker task accounting is incomplete')
        if any(counts[k] for k in ['outstanding', 'faults', 'failed', 'cancelled', 'dropped']):
            reasons.append('checker fault or undrained task reported')
    except (KeyError, ValueError):
        reasons.append('missing/malformed final hardware snapshot')
    if counts and (len(begins) != counts['generated'] or len(results) != counts['completed']):
        reasons.append('synthesized package/result events disagree with hardware counters')
    drained = re.findall(r'EC_OPT4_CONTEXT_DRAINED ([^\r\n]*)', console)
    parked = dict(re.findall(r'(\w+)=(\w+)', drained[0])) if len(drained) == 1 else {}
    try:
        if int(parked['firmware'], 16) != 15 or parked['satp'].lower() != contexts[0].lower() or \
                int(parked['generated']) != counts['generated'] or \
                int(parked['completed']) != counts['completed'] or int(parked['outstanding']) != 0:
            reasons.append('checker firmware teardown or final accounting proof failed')
    except (KeyError, ValueError, IndexError):
        reasons.append('missing checker teardown proof')

    roi_rows = []
    for row in re.findall(r'EC_OPT4_ROI ([^\r\n]*)', rtl):
        f = dict(re.findall(r'(\w+)=(\w+)', row))
        try:
            roi_rows.append({k: int(f[k], 16) for k in ['token', 'epoch', 'state', 'begin', 'end',
                'generated', 'completed', 'passed', 'failed', 'cancelled', 'dropped', 'faults']} |
                {'busy': int(f['busy'])})
        except (KeyError, ValueError):
            roi_rows.append({'malformed': row})
    commands = {row['token'] & 0xff for row in roi_rows if 'malformed' not in row}
    if not {1, 2, 3}.issubset(commands) or not roi_rows or 'malformed' in roi_rows[-1]:
        reasons.append('RTL ROI ARM/END/DRAIN evidence missing')
    elif counts and any(roi_rows[-1][k] != counts[k] for k in [
            'generated', 'completed', 'passed', 'failed', 'cancelled', 'dropped', 'faults']):
        reasons.append('RTL request snapshot disagrees with Linux hardware counters')
    if re.search(r'Assertion failed|%Error|Aborted|EC_OPT4_.*(?:FAILED|OVERFLOW)', console, re.I):
        reasons.append('FireSim/RTL assertion, fatal, or observer error')

    result = {'valid': not reasons, 'reasons': reasons, 'configuration': 'C4',
        'identity': plan['identity'], 'mode': 'test', 'roi_cycles': counts.get('end', 0)-counts.get('begin', 0),
        'drain_cycles': counts.get('drain', 0)-counts.get('end', 0), 'hardware': counts,
        'rtl_packages': len(begins), 'rtl_results': len(results), 'rtl_roi_requests': roi_rows,
        'raw_files': {str(p): sha(p) for p in raw.iterdir() if p.is_file()},
        'console_sha256': hashlib.sha256(console_bytes).hexdigest(),
        'runtime_validation': 'PASS' if not reasons else 'INVALID', 'formal_sample': False,
        'scope': 'C4 FireSim Blackscholes test/in_4.txt; not a slowdown sample until paired with B'}
    save_idempotent(attempt/'verification.json', result)
    if result['valid']:
        dest = RESULTS / 'complete' / (attempt.name + '.json')
        dest.parent.mkdir(parents=True, exist_ok=True)
        save_idempotent(dest, {**result, 'attempt': str(attempt)})
        fd = os.open(dest.parent, os.O_RDONLY | os.O_DIRECTORY)
        try: os.fsync(fd)
        finally: os.close(fd)
    print(json.dumps(result, indent=2))
    return 0 if result['valid'] else 1


def main():
    p = argparse.ArgumentParser(description=__doc__)
    sub = p.add_subparsers(dest='action', required=True)
    q = sub.add_parser('preflight', help='read-only all-card/FD/process inspection')
    q.add_argument('--bdf', choices=sorted(EXPECTED_DEVICES))
    q.add_argument('--out', type=Path, required=True)
    q = sub.add_parser('prepare', help='bind exact C4 driver, bitstream and Linux/software outputs')
    q.add_argument('--bdf', required=True, choices=sorted(EXPECTED_DEVICES))
    q.add_argument('--driver-result', type=Path, required=True)
    q.add_argument('--bitstream-result', type=Path, required=True)
    q.add_argument('--mode', choices=['smoke', 'test'], required=True)
    q = sub.add_parser('run', help='root-only driver start after safe deployment and all-card preflight')
    q.add_argument('--plan', type=Path, required=True)
    q.add_argument('--deployment-record', type=Path, required=True)
    q = sub.add_parser('verify', help='validate saved console, Opt4 events, results and teardown')
    q.add_argument('--attempt', type=Path, required=True)
    args = p.parse_args()
    try:
        if args.action == 'preflight':
            return preflight(args.out.resolve(), args.bdf)
        if args.action == 'prepare':
            return prepare(args) or 0
        if args.action == 'run':
            return run(args)
        attempt = args.attempt.resolve()
        if attempt.parent != RESULTS/'partial':
            raise ValueError('attempt is not under C4 FireSim partial results')
        return verify_attempt(attempt)
    except (OSError, ValueError, KeyError, subprocess.SubprocessError) as error:
        print('REFUSED/INVALID: ' + str(error), file=sys.stderr)
        return 2


if __name__ == '__main__':
    raise SystemExit(main())
