#!/usr/bin/python3
"""One exact composition -> complete U280 shell CAD, without device access.

The existing intelligent optimizer owns decisions and immutable recoveries.
This deterministic successor does not elaborate, resynthesize modules or
require a software build before offline area screening.
"""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-common-composed-shell-cad-r3-20261113'
UP = D/'build-logs/Opt4-common-composed-validate-r2-20261113'
UC = W/'candidates/common-composed-validate-r2-20261113'
PROJECT = C/'project'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = 'bcd40636f8581240400f5fcd67ca59edc87a8f49'
VARIANT = '2de2849801c1fd346048eee9072c59218d698e7b10bb56ffcb94efd17c476846'
CPUS = set(range(222, 230))
STATUS = 'PASS_EXACT_COMMON_COMPOSED_DCACHE_CYCLES_AND_THREADED_HOST_GENERATION_NO_AREA_OR_FIT'
UPUNIT = 'ec-opt4-common-composed-validate-r2-20261113.service'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def admissible(result):
    assert result['status'] == STATUS
    assert result['functional_baseline'] == BASE
    assert result['hardware_commit'] == COMMIT
    assert result['source_variant'] == VARIANT
    assert result['complete_dcache_cycles_verified']
    assert result['target_cycles'] == 8192 and result['observations'] == 24575
    assert result['selected_instances'] == 64
    assert len(result['selected_model_types']) == 1
    assert result['full_system_fit'] is False and result['fpga_access'] is False


def validate_cycle_receipt(receipt, expected_binding):
    # Upstream intentionally replaces the generic stage receipt with this
    # exact full-cycle contract. It has no returncode/missing_outputs fields.
    assert receipt['hardware_commit'] == COMMIT and receipt['source_variant'] == VARIANT
    assert receipt['source_binding_sha256'] == expected_binding
    assert receipt['assertions_enabled'] and receipt['target_cycles'] == 8192
    assert receipt['observations'] == 24575 and sha(receipt['log']) == receipt['log_sha256']
    text = Path(receipt['log']).read_text()
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in text
    assert 'observations=24575' in text


def wait_original_release(st):
    previous = D/'build-logs/Opt4-common-composed-shell-cad-r1-20261113'
    unit = 'ec-opt4-common-composed-shell-cad-r1-20261113.service'
    up = load('original_shell_release_check', UC/'controller.py')
    while True:
        row = read(previous/'state.json')
        failure = read(previous/'failure.json')
        if failure and not up.members(unit):
            assert failure['status'] == 'FAILED_WITH_EVIDENCE'
            assert failure['error'] == "KeyError('returncode')", 'Only diagnosed receipt-format recovery'
            assert not (previous/'host-binding.json').exists(), 'Never duplicate a started CAD'
            assert not (previous/'cad-state.json').exists(), 'Never duplicate a started CAD'
            save(O/'predecessor-release.json', dict(utc=now(), unit=unit,
                failure_sha256=sha(previous/'failure.json'), cgroup_released=True,
                no_host_copy_or_CAD_started=True, hardware_changed=False))
            return True
        if (previous/'result.json').exists() and row.get('status') != 'FAILED_WITH_EVIDENCE' and not up.members(unit):
            st.update(status='ORIGINAL_TERMINAL_NO_RECOVERY_NEEDED', original_status=row.get('status'), ended_utc=now())
            save(O/'state.json', st); save(O/'result.json', st)
            return False
        st.update(status='WAITING_ORIGINAL_SHELL_RECEIPT_FORMAT_TERMINAL_AND_RELEASE',
            original_status=row.get('status'), updated_utc=now())
        save(O/'state.json', st)
        time.sleep(30)


def owners():
    found = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit() or int(proc.name) == os.getpid():
            continue
        try:
            if proc.stat().st_uid != os.getuid():
                continue
            affinity = os.sched_getaffinity(int(proc.name))
            if len(affinity) <= 8 and affinity & CPUS:
                found.append(identity(int(proc.name)))
        except OSError:
            pass
    return found


def resources_ready():
    mem = {line.split(':')[0]: int(line.split()[1])
        for line in Path('/proc/meminfo').read_text().splitlines()}
    ready = mem['MemAvailable'] >= 128*2**20 and shutil.disk_usage(C).free >= 110*2**30
    # All complete-shell pipelines share the original CAD lease.
    with (D/'.opt4-fit-cad.lock').open('a') as lease:
        try:
            fcntl.flock(lease, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            return False
    return ready and not owners()


def upstream_binding():
    result = read(UP/'result.json')
    admissible(result)
    assert sha(UC/'source-binding.json') == result['source_binding_sha256']
    upstream = load('bound_common_composition', UC/'controller.py')
    binding, _ = upstream.verify_binding()
    assert binding['hardware_commit'] == COMMIT and binding['source_variant'] == VARIANT
    assert not upstream.members(UPUNIT), 'Wait for exact predecessor cgroup release'
    for stage in ['frozen-parameters', 'class-origin-linkage', 'elaborate-complete-source',
                  'goldengate-threaded-complete-host']:
        upstream.accepted(UP/(stage+'-receipt.json'))
    receipt = read(UP/'full-dcache-cycle-receipt.json')
    validate_cycle_receipt(receipt, sha(UC/'source-binding.json'))
    assert receipt['hardware_commit'] == COMMIT and receipt['source_variant'] == VARIANT
    assert receipt['assertions_enabled'] and receipt['target_cycles'] == 8192
    assert receipt['observations'] == 24575 and sha(receipt['log']) == receipt['log_sha256']
    host = UP/'threaded-host'
    assert sha(host/'FireSim-generated.sv') == result['host_RTL_sha256']
    return result, binding, host


def prepare_host(result, binding, host):
    """Copy once; append required blackbox resources only in our private RTL."""
    target = PROJECT/'bound-host'
    target.mkdir(parents=True)
    required = ['FireSim-generated.sv', 'FireSim-generated.defines.vh',
        'FireSim-generated.synthesis.xdc', 'FireSim-generated.implementation.xdc']
    generated = {str(host/name): sha(host/name) for name in required}
    for path in host.iterdir():
        if path.is_file() and path.suffix in ['.sv', '.v', '.vh', '.h', '.xdc', '.json']:
            shutil.copy2(path, target/path.name)
    appended = {}
    listing = host/'firrtl_black_box_resource_files.f'
    if listing.exists():
        with (target/'FireSim-generated.sv').open('ab') as stream:
            for line in listing.read_text().splitlines():
                if not line.strip():
                    continue
                path = Path(line.strip())
                if not path.is_absolute():
                    path = host/path
                # Original generation ends before blackbox append. Check exact
                # stage hash above and retain every external source hash here.
                stream.write(path.read_bytes()); stream.write(b'\n')
                appended[str(path)] = sha(path)
            stream.flush(); os.fsync(stream.fileno())
    immutable = dict(schema='ec-common-composed-shell-input/1', hardware_commit=COMMIT,
        functional_baseline=BASE, source_variant=VARIANT,
        upstream_result=str(UP/'result.json'), upstream_result_sha256=sha(UP/'result.json'),
        upstream_source_binding_sha256=sha(UC/'source-binding.json'),
        upstream_RTL=generated, appended_blackboxes=appended,
        generated={str(target/name): sha(target/name) for name in required},
        compiler_fixes_inherited=True, shell_included=True,
        runtime_certified=False, fpga_access=False)
    sid = hashlib.sha256(json.dumps(immutable, sort_keys=True).encode()).hexdigest()
    immutable['source_id'] = sid
    save(O/'host-binding.json', immutable)
    save(PROJECT/'bindings'/f'{COMMIT}.json', dict(source_id=sid,
        frozen_commit=BASE, hardware_commit=COMMIT, source_variant=VARIANT))
    save(O/'rtl-state.json', dict(status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',
        hardware_commit=COMMIT, source_id=sid, goldengate_dir=str(target),
        configuration_matches_frozen_parameters=True, modified_class_origins_verified=True,
        outputs=immutable['generated']))
    return sid


def publish(cad, source_id):
    state = read(cad.S)
    resources = cad.utilization(O/'top-postopt-utilization.rpt')
    out = dict(schema='ec-common-composed-complete-shell-result/1', **identity(),
        ended_utc=now(), functional_baseline=BASE, hardware_commit=COMMIT,
        source_variant=VARIANT, source_id=source_id, shell_included=True,
        certified_bitstream=False, fpga_access=False,
        physical_bitstream_generated=bool(state.get('bitstream')),
        physical_bitstream=state.get('bitstream'),
        status=state.get('status', 'FAILED_WITH_EVIDENCE'),
        top_postopt_resources=resources, cad_state=str(cad.S),
        source_binding=str(O/'host-binding.json'),
        source_binding_sha256=sha(O/'host-binding.json'),
        next='Existing optimizer adopts exact hierarchy after NOT FIT; FIT physical output requires exact host/software/ABI/board21 certification before FPGA IO.')
    util, hier = O/'top-postopt-utilization.rpt', O/'top-postopt-hierarchical.rpt'
    if util.exists() and hier.exists():
        required = ['CLB LUTs', 'CLB Registers', 'CARRY8', 'DSPs', 'Block RAM Tile', 'URAM']
        assert all(key in resources for key in required)
        values = {key: resources[key]['used'] for key in required}
        available = resources['CLB LUTs']['available']
        # The implementation link gate ran before the resource reports.
        logs = list(O.glob('implementation-attempt-*.log'))
        assert any('EC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX' in p.read_text(errors='replace') for p in logs)
        fit = all(resources[key]['used'] <= resources[key]['available'] for key in required)
        out.update(scope='complete_u280_shell_postopt', resources=values,
            capacity=available, lut_gap=values['CLB LUTs']-available,
            full_system_fit=fit, blackboxes=0,
            utilization=str(util), utilization_sha256=sha(util),
            hierarchical=str(hier), hierarchical_sha256=sha(hier))
        save(O/'postopt-result.json', out)
        # Existing collector consumes immutable complete-shell adoptions.
        adoption = D/'area-sprint-20261112/fullshell-adoptions.json'
        with (D/'area-sprint-20261112/fullshell-adoptions.lock').open('a') as lease:
            fcntl.flock(lease, fcntl.LOCK_EX)
            ledger = read(adoption)
            rows = ledger.setdefault('results', [])
            rows.append(dict(scope=out['scope'], hardware_commit=COMMIT,
                result=str(O/'postopt-result.json'), result_sha256=sha(O/'postopt-result.json'),
                utilization=str(util), utilization_sha256=sha(util),
                source_binding=str(O/'host-binding.json'), source_binding_sha256=sha(O/'host-binding.json')))
            save(adoption, ledger)
    save(O/'state.json', out); save(O/'result.json', out)


def main():
    O.mkdir(exist_ok=True)
    with (O/'instance.lock').open('a') as lease:
        fcntl.flock(lease, fcntl.LOCK_EX | fcntl.LOCK_NB)
        assert not (O/'state.json').exists(), 'Adopt live or completed owner'
        recovery_owner = load('launch_recovery_release', UC/'controller.py')
        previous = D/'build-logs/Opt4-common-composed-shell-cad-r2-20261113'
        assert not recovery_owner.members('ec-opt4-common-composed-shell-cad-r2-20261113.service')
        failure = read(previous/'failure.json')
        assert failure['status'] == 'FAILED_WITH_EVIDENCE' and failure['error'] == 'AssertionError()'
        trace = (previous/'service.log').read_text()
        assert 'line 241, in main' in trace and "['git', 'rev-parse', 'HEAD'], cwd=tree" in trace
        assert not (previous/'host-binding.json').exists() and not (previous/'cad-state.json').exists()
        save(O/'launch-recovery-handoff.json', dict(utc=now(), no_host_copy_or_CAD_started=True,
            R2cgroup_released=True, failure_sha256=sha(previous/'failure.json'),
            traceback_sha256=sha(previous/'service.log'), hardware_changed=False))
        own = read(C/'source-binding.json')
        assert all(sha(path) == digest for path, digest in own['files'].items())
        tree = W/'Opt4-area-common-shell-cad-r3-20261113'
        assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=tree,
            text=True).strip() == own['experiment_commit']
        for name, digest in own['committed_files'].items():
            blob = subprocess.check_output(['git', 'show', own['experiment_commit']+':'+name], cwd=tree)
            assert hashlib.sha256(blob).hexdigest() == digest, name
        st = dict(schema='ec-common-composed-shell-successor/1', **identity(),
            started_utc=now(), functional_baseline=BASE, hardware_commit=COMMIT,
            source_variant=VARIANT, cpus_after_admission=sorted(CPUS), memory_limit_gib=128,
            source_binding_sha256=sha(C/'source-binding.json'),
            no_waiting_CPU_pins=True, no_new_elaboration=True, fpga_access=False,
            full_system_fit=False, certified_bitstream=False)
        if not wait_original_release(st):
            return
        while True:
            result, state = read(UP/'result.json'), read(UP/'state.json')
            if result and result.get('status') == STATUS:
                up = load('release_check', UC/'controller.py')
                if not up.members(UPUNIT) and resources_ready():
                    break
            elif result or str(state.get('status')).startswith(('FAILED', 'PREREQUISITE_FAILED')):
                st.update(status='UPSTREAM_TERMINAL_NO_CAD', upstream_status=result.get('status', state.get('status')), ended_utc=now())
                save(O/'state.json', st); save(O/'result.json', st); return
            st.update(status='WAITING_EXACT_COMPOSED_VALIDATION_AND_CAD_LEASE',
                upstream_status=state.get('status'), updated_utc=now())
            save(O/'state.json', st)
            time.sleep(30)
        result, binding, host = upstream_binding()
        os.sched_setaffinity(0, CPUS)
        resource.setrlimit(resource.RLIMIT_AS, (128*2**30,)*2)
        source_id = prepare_host(result, binding, host)
        cad = load('common_shell_bound_engine', C/'cad_engine.py')
        cad.COMMIT, cad.F = COMMIT, PROJECT
        cad.O, cad.L = PROJECT/'builds'/('cad-'+COMMIT[:8]), O
        cad.S, cad.R = O/'cad-state.json', O/'rtl-state.json'
        st.update(status='RUNNING_COMPLETE_SHELL_CAD', no_waiting_CPU_pins=False, source_id=source_id,
            cad_state=str(cad.S), updated_utc=now())
        save(O/'state.json', st)
        try:
            cad.main()
        except Exception as exc:
            failure = read(cad.S)
            cap = O/'capacity.complete'
            failure.update(status='NOT_FIT_POSTOPT' if cap.exists() and cap.read_text().startswith('NOT_FIT') else 'FAILED_WITH_EVIDENCE',
                error=repr(exc), ended_utc=now())
            save(cad.S, failure)
        publish(cad, source_id)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        state = read(O/'state.json')
        state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
        save(O/'state.json', state); save(O/'failure.json', state)
        raise
