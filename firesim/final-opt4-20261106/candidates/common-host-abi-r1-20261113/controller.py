#!/usr/bin/python3
"""Offline exact-host identity and seven-file ABI/software admission, no device IO."""
from pathlib import Path
import fcntl
import hashlib
import json
import os
import re
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-common-host-abi-r1-20261113'
TREE = W/'Opt4-area-common-host-abi-r1-20261113'
VALID = D/'build-logs/Opt4-common-composed-validate-r2-20261113'
OWNER = 'ec-opt4-common-composed-validate-r2-20261113.service'
PARENT = W/'runtime/Opt4-fit-mcrams-owner-r1'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = 'bcd40636f8581240400f5fcd67ca59edc87a8f49'
VARIANT = '2de2849801c1fd346048eee9072c59218d698e7b10bb56ffcb94efd17c476846'
READY = 'PASS_EXACT_COMMON_COMPOSED_DCACHE_CYCLES_AND_THREADED_HOST_GENERATION_NO_AREA_OR_FIT'
SOFTWARE = ('FireSim-generated.const.h', 'FireSim-generated.const.vh',
    'FireSim-generated.defines.vh', 'firesim.firesim.FireSim.dts',
    'firesim.firesim.FireSim.dromajo_params.h')
CONSTRAINTS = ('FireSim-generated.synthesis.xdc', 'FireSim-generated.implementation.xdc')
PROGRAMS = ('blackscholes', 'fluidanimate', 'bodytrack', 'freqmine',
    'swaptions', 'ferret', 'dedup', 'streamcluster')
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha
ST = {}


def update(status, **kw):
    ST.update(status=status, updated_utc=now(), **kw)
    save(O/'state.json', ST)


def exact(path, data):
    path = Path(path)
    if path.exists():
        assert path.read_bytes() == data, ('preserve immutable artifact', str(path))
    else:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open('xb') as stream:
            stream.write(data)


def exact_json(path, value):
    exact(path, (json.dumps(value, indent=2, sort_keys=True)+'\n').encode())


def members(unit):
    rows = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit():
            continue
        try:
            paths = [line.split(':', 2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            if any(p.endswith('/'+unit) or '/'+unit+'/' in p for p in paths):
                row = identity(int(proc.name))
                if row and row['process_state'] not in ['X', 'Z']:
                    rows.append(row)
        except OSError:
            pass
    return rows


def verify_binding():
    binding = read(C/'source-binding.json')
    assert binding['hardware_commit'] == HW and binding['source_variant'] == VARIANT
    assert binding['functional_baseline'] == BASE
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE,
        text=True).strip() == binding['experiment_commit']
    for path, digest in binding['files'].items():
        assert sha(path) == digest, ('pinned input changed', path)
    for path, digest in binding['committed_files'].items():
        data = subprocess.check_output(['git', 'show', binding['experiment_commit']+':'+path], cwd=TREE)
        assert hashlib.sha256(data).hexdigest() == digest, path
    return binding


def accepted(path):
    row = read(path)
    assert row and row['returncode'] == 0 and not row['missing_outputs'], str(path)
    assert row.get('accepted', True) and sha(row['log']) == row['log_sha256'], str(path)
    for name, digest in row['outputs'].items():
        assert sha(name) == digest, name
    return row


def validate_result(row):
    assert row['status'] == READY and row['hardware_commit'] == HW
    assert row['functional_baseline'] == BASE and row['source_variant'] == VARIANT
    assert row['complete_dcache_cycles_verified'] and row['target_cycles'] == 8192
    assert row['observations'] == 24575 and row['selected_instances'] == 64
    assert len(row['selected_model_types']) == 1
    assert re.fullmatch(r'StatsBank(?:_\d+)?', row['selected_model_types'][0])
    assert row['full_system_fit'] is False and row['fpga_access'] is False
    assert row['source_binding_sha256'] == sha(W/'candidates/common-composed-validate-r2-20261113/source-binding.json')


def compare_files(generated, old):
    """Every file has a role; changed constraints never establish physical validity."""
    assert set(generated) == set(SOFTWARE+CONSTRAINTS), 'all seven files required'
    inputs = old['generated_inputs']
    assert len(inputs) == 7 and {r['role'] for r in inputs} == set(generated)
    rows = []
    for role in SOFTWARE+CONSTRAINTS:
        previous = next(r for r in inputs if r['role'] == role)
        before, after = Path(previous['derived']), Path(generated[role])
        assert sha(before) == previous['derived_sha256'], role
        rows.append(dict(role=role, kind='software_abi' if role in SOFTWARE else 'physical_constraint',
            original=str(before), original_sha256=sha(before), derived=str(after),
            derived_sha256=sha(after), byte_equal=before.read_bytes() == after.read_bytes(),
            physical_validation_required=role in CONSTRAINTS))
    return dict(generated_inputs=rows, seven_files_accounted=True,
        software_ABI_byte_equal=all(r['byte_equal'] for r in rows if r['kind']=='software_abi'),
        new_shell_link_and_all_physical_checks_required=True)


def software_assets():
    """Authenticate prepared guest assets only; do not read CPU/SVB result records."""
    suite = read(PARENT/'software-suite.json')
    assert suite['board_bdf'] == '0000:21:00.0' and suite['board_serial'] == '21770433G02LA'
    assert len({r['program'] for r in suite['programs']}) == suite['program_count']
    checks, assets, selected = {}, {}, []
    for program in PROGRAMS:
        entry = next(r for r in suite['programs'] if r['program'] == program)
        receipts = {}
        for role in ['apps', 'rootfs', 'firmware']:
            path = entry['receipts'][role]
            assert sha(path) == entry['receipt_sha256'][role], (program, role)
            row = read(path); checks[path] = sha(path); receipts[role] = row
        binary = receipts['apps']['binaries'][program]
        assert binary['sha256'] == entry['elf_sha256'] and sha(binary['path']) == binary['sha256']
        root = receipts['rootfs']
        assert root['returncode'] == 0 and root['sha256'] == entry['rootfs_sha256']
        assert sha(root['path']) == root['sha256']
        assert root['files']['opt/ec-fpga/'+program] == binary['sha256']
        assets[binary['path']] = binary['sha256']; assets[root['path']] = root['sha256']
        firmware = receipts['firmware']
        assert firmware['returncode'] == 0 and firmware['outputs']
        for path, digest in firmware['outputs'].items():
            assert sha(path) == digest, path
            assets[path] = digest
        # No historical runtime/Native/CPU performance references are exported.
        selected.append(dict(program=program, formal_input=entry['formal_input'],
            input_sizes=entry['input_sizes'], threads=entry['threads'],
            elf=binary['path'], elf_sha256=binary['sha256'], rootfs=root['path'],
            rootfs_sha256=root['sha256'], receipts={k:entry['receipts'][k] for k in receipts},
            receipt_sha256={k:entry['receipt_sha256'][k] for k in receipts},
            status='PREPARED_GUEST_ASSETS_REQUIRE_EXACT_NEW_FPGA_VALIDATION'))
    return dict(programs=selected, receipt_hashes=checks, assets=assets,
        program_order=list(PROGRAMS), no_runtime_measurements_read_or_exported=True)


def prepare(binding):
    result = read(VALID/'result.json'); validate_result(result)
    assert not members(OWNER), 'exact generation predecessor still owns inputs'
    for name in ['class-origin-linkage', 'frozen-parameters', 'elaborate-complete-source',
                 'goldengate-target', 'compile-full-dcache-cycle', 'full-dcache-cycle',
                 'goldengate-threaded-complete-host']:
        accepted(VALID/(name+'-receipt.json'))
    source = read(W/'candidates/common-composed-validate-r2-20261113/source-binding.json')
    assert all(sha(path) == digest for path, digest in source['files'].items())
    assert source['hardware_commit'] == HW and source['source_variant'] == VARIANT
    host = VALID/'threaded-host'; rtl = host/'FireSim-generated.sv'
    assert sha(rtl) == result['host_RTL_sha256']
    generated = {role:str(host/role if role.startswith('FireSim-') else VALID/'elaborate'/role)
        for role in SOFTWARE+CONSTRAINTS}
    files = {str(rtl):sha(rtl), **{path:sha(path) for path in generated.values()}}
    artifacts = {str(VALID/name):sha(VALID/name) for name in ['result.json',
        'material-prerequisites.json', 'full-dcache-cycle-receipt.json', 'parameters.json']}
    exact_identity = dict(hardware_commit=HW, functional_baseline=BASE, source_variant=VARIANT,
        host_rtl_sha256=sha(rtl), generated=files, validation=artifacts,
        source_binding_sha256=sha(W/'candidates/common-composed-validate-r2-20261113/source-binding.json'))
    sid = hashlib.sha256(json.dumps(exact_identity, sort_keys=True).encode()).hexdigest()
    assert sid != read(PARENT/'bundle.json')['host_transform_id']
    exact_json(O/'host-identity.json', dict(exact_identity, host_transform_id=sid,
        experiment_commit=binding['experiment_commit'], no_physical_or_runtime_admission=True))
    audit = dict(compare_files(generated, read(PARENT/'driver-compatibility.json')),
        hardware_commit=HW, functional_baseline=BASE, source_variant=VARIANT,
        host_transform_id=sid, host_rtl_sha256=sha(rtl), FPGA_IO=False)
    exact_json(O/'abi-audit.json', audit)
    software = software_assets()
    exact_json(O/'software-assets.json', dict(software, hardware_commit=HW, host_transform_id=sid,
        FPGA_IO=False, FPGA_validation=False))
    if not audit['software_ABI_byte_equal']:
        update('GENERATED_SOFTWARE_ABI_CHANGED_PRIVATE_DRIVER_REBUILD_REQUIRED',
            host_transform_id=sid, driver_reuse_refused=True, ended_utc=now(),
            next='Build a private driver against these exact generated headers; keep original driver and all hardware/token/physical gates. No device admission.')
        exact_json(O/'result.json', ST); return
    previous = read(PARENT/'driver-receipt.json')
    assert previous['returncode'] == 0
    exe = PARENT/'FireSim-xilinx_alveo_u280'
    assert sha(exe) == previous['outputs'][str(exe)]
    dest = O/'offline-driver/FireSim-xilinx_alveo_u280'
    exact(dest, exe.read_bytes()); dest.chmod(exe.stat().st_mode & 0o777)
    receipt = dict(status='EXACT_SOFTWARE_ABI_IDENTICAL_DRIVER_REUSE_NOT_EXECUTED',
        hardware_commit=HW, functional_baseline=BASE, host_transform_id=sid,
        host_rtl_sha256=sha(rtl), parent_receipt=str(PARENT/'driver-receipt.json'),
        parent_receipt_sha256=sha(PARENT/'driver-receipt.json'),
        abi_audit_sha256=sha(O/'abi-audit.json'), outputs={str(dest):sha(dest)},
        recompiled=False, executed=False, FPGA_IO=False, FPGA_runtime_validated=False)
    exact_json(O/'driver-receipt.json', receipt)
    verify_binding()
    update('PASS_EXACT_COMMON_HOST_SEVEN_FILE_ABI_GUEST_ASSETS_AND_DRIVER_REUSE_NO_RUNTIME_ADMISSION',
        host_transform_id=sid, generated=files, driver=str(dest),
        seven_file_audit_sha256=sha(O/'abi-audit.json'), software_assets_sha256=sha(O/'software-assets.json'),
        driver_receipt_sha256=sha(O/'driver-receipt.json'), ended_utc=now(),
        next='Validate exact complete generated-host target tokens before one complete-host/shell area measurement. Shell capacity, physical/certification and a versioned card21 runtime rebind remain mandatory; this receipt cannot authorize FPGA IO.')
    exact_json(O/'result.json', ST)


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'adopt existing owner or preserved result'
    binding = verify_binding()
    ST.update(schema='ec-exact-common-host-offline-abi-software/1', **identity(), started_utc=now(),
        hardware_commit=HW, experiment_commit=binding['experiment_commit'], functional_baseline=BASE,
        source_variant=VARIANT, source_binding_sha256=sha(C/'source-binding.json'),
        no_CAD=True, FPGA_IO=False, no_waiting_CPU_pins=True, no_new_intelligent_supervisor=True,
        full_system_fit=False, certified_bitstream=False, production_admission=False,
        complete_generated_host_token_validation=False)
    while True:
        state = read(VALID/'state.json'); result = read(VALID/'result.json')
        if str(state.get('status', '')).startswith(('FAILED', 'PREREQUISITE_FAILED', 'INSUFFICIENT')):
            update('PREREQUISITE_FAILED_NO_ABI_OR_DRIVER_ADMISSION',
                prerequisite_status=state.get('status'), ended_utc=now())
            exact_json(O/'result.json', ST); return
        if result:
            validate_result(result)
            if not members(OWNER):
                break
        update('QUEUED_FOR_EXACT_COMMON_HOST_VALIDATION_AND_CGROUP_RELEASE',
            prerequisite_status=state.get('status'), no_elaboration_or_host_transform_started=True)
        time.sleep(30)
    prepare(binding)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_IMMUTABLE_DIAGNOSED_SUCCESSOR_REQUIRED',
                error=repr(exc), ended_utc=now())
            exact_json(O/'failure.json', ST)
        raise
