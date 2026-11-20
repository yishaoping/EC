#!/usr/bin/python3
"""Source-bound composition audit and Scala typecheck; no whole-DUT CAD."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = W/'candidates/update-share-svb-compose-r1'
F = W/'Opt4-fit-update-share-svb-r1-20261111'
O = D/'build-logs/Opt4-fit-update-share-svb-r1-20261111'
S = D/'Opt4-fit-update-share-svb-r1-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()

def read(path):
    return json.loads(Path(path).read_text())

def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()

def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name+'.tmp-'+str(os.getpid()))
    with tmp.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)

def identity(pid):
    try:
        fields = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}

def update(state, **values):
    state.update(values)
    state['updated_utc'] = now()
    save(S, state)

def git(*args):
    return subprocess.check_output(['git', *args], cwd=F, text=True).strip()

def main():
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    binding = read(C/'binding.json')
    policy = read(D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == binding['frozen_commit']
    assert policy['area_equivalence_only'] and policy['functional_extensions_allowed'] is False
    assert policy['current_live_whole_commit'] == binding['area_parent']
    assert not policy['fpga_access']
    commit = binding['hardware_commit']
    assert git('rev-parse', 'HEAD') == commit
    assert git('rev-parse', 'HEAD^') == binding['svb_commit']
    assert git('merge-base', '--is-ancestor', binding['area_parent'], commit) == ''
    expected_delta = {
        'lineage.json',
        REL+'PackageAddressStats.scala',
        REL+'NewestSafeEntry.scala',
        REL+'speculative-version-buffer.scala',
    }
    assert set(git('diff', '--name-only', binding['area_parent'], commit).splitlines()) == expected_delta
    assert set(git('diff', '--name-only', binding['svb_commit'], commit).splitlines()) == {
        'lineage.json', REL+'PackageAddressStats.scala'}
    for forbidden in policy['forbidden_extension_commits']:
        assert subprocess.run(['git', 'merge-base', '--is-ancestor', forbidden, commit],
                              cwd=F, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode != 0

    package = F/(REL+'PackageAddressStats.scala')
    address_tree = W/'Opt4-fit-address-update-share-r2-20261111'
    svb_tree = W/'Opt4-fit-svb-tree-r1-20261111'
    assert package.read_bytes() == subprocess.check_output(
        ['git', 'show', binding['address_commit']+':chipyard/'+REL+'PackageAddressStats.scala'], cwd=F)
    for name in ['NewestSafeEntry.scala', 'speculative-version-buffer.scala']:
        assert (F/(REL+name)).read_bytes() == subprocess.check_output(
            ['git', 'show', binding['svb_commit']+':chipyard/'+REL+name], cwd=F)
    changed_sources = [package, F/(REL+'NewestSafeEntry.scala'),
                       F/(REL+'speculative-version-buffer.scala')]
    forbidden_tokens = [b'PackageRecoveryController', b'PackageRecoveryState', b'PackageRecoveryMemory']
    assert not any(token in path.read_bytes() for path in changed_sources for token in forbidden_tokens)

    address_state = read(D/'Opt4-fit-address-update-share-r2-state.json')
    address_proof = read(O.parent/'Opt4-fit-address-update-share-r2-20261111/verified-local.json')
    address_local = read(D/'build-logs/Opt4-fit-address-update-share-r2-20261111/verified-local.json')
    address_map = address_state['full_module_map']
    assert address_state['hardware_commit'] == binding['address_commit']
    assert address_state['source_id'] == binding['address_source_id']
    assert address_local['hardware_commit'] == binding['address_commit']
    assert address_proof['local_formal'].startswith('PASS_')
    assert address_local['local_formal'] == 'PASS_UNCONDITIONAL_64BIT_ALLOCATION_UPDATE_RESET_AND_256_SLOT_QUALIFICATION'
    assert address_local['actual_size_boundary'] == 'PASS_8192_VECTORS_256_SLOTS_1280_64BIT_COUNTERS_STALE_INVALID_OVERFLOW_RESET_RETIRE'
    assert address_local['full_module_regression'] == 'PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
    assert address_state['status'] == 'VERIFIED_AND_MAPPED_MODULE_ONLY'
    assert address_map['resources']['CLB LUTs'] == 872880
    assert sha(address_map['report']) == address_map['report_sha256']
    address_log = D/'build-logs/Opt4-fit-address-update-share-r2-20261111/compare/compare-attempt-1.log'
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS vectors=6144' in address_log.read_text(errors='replace')

    svb_state = read(D/'Opt4-fit-svb-system-r2-state.json')
    svb_proof = read(D/'build-logs/Opt4-fit-svb-system-r2-20261111/combined-equivalence.json')
    svb_cfg = read(W/'candidates/svb-system-r2-20261111/config.json')
    svb_binding = svb_cfg['binding']
    svb_compare_path = (svb_tree/'builds/system-f2d2ca3e-r2/svb-comparison/comparison/result.json')
    svb_compare = read(svb_compare_path)
    assert svb_state['status'] == 'RTL_READY_REAL_ABI_CHECKED'
    assert svb_state['hardware_commit'] == binding['svb_commit']
    assert svb_state['source_id'] == binding['svb_source_id']
    assert svb_state['configuration_matches_frozen_parameters'] is True
    assert svb_state['modified_class_origins_verified'] is True
    assert svb_proof['status'] == 'PASS_SOURCE_BOUND_COMPOSITIONAL_SVB_DELTA_TO_VERIFIED_9AE_PARENT'
    assert svb_proof['hardware_commit'] == binding['svb_commit']
    assert svb_proof['parent_commit'] == binding['area_parent']
    assert svb_compare['status'] == 'PASS_FULL_SVB_DIRECTED_AND_4096_RANDOM_CYCLES_ALL_OUTPUTS'
    assert svb_compare['output_ports'] == 127
    assert svb_binding['changed_files'][0] == 'chipyard/'+REL+'PackageAddressStats.scala'
    reference_rtl = Path(svb_compare['reference_rtl'])
    candidate_rtl = Path(svb_compare['candidate_rtl'])

    sys.path.insert(0, str(W/'scripts'))
    spec = importlib.util.spec_from_file_location('compose_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()

    old = read(S) if S.is_file() else {}
    state = dict(schema='ec-opt4-composed-area-proof/1', **identity(os.getpid()),
                 hardware_commit=commit, source_id=source_id, parent_commit=binding['svb_commit'],
                 status='VERIFYING_SOURCE_BOUND_COMPONENT_EVIDENCE', started_utc=now(),
                 full_dut_formal=False, whole_dut_synthesis=False, fpga_access=False,
                 stages=old.get('stages', {}))
    save(S, state)

    expected_classes = [
        'boom/lsu/PackageAddressStats.class',
        'boom/lsu/NewestSafeEntry$.class',
        'boom/lsu/SpeculativeVersionBuffer.class',
    ]
    sources = [F/path for path in svb_binding['changed_files']]
    assert all(path.is_file() for path in sources)
    build = O/'compile-composed'; classes = build/'classes'; classes.mkdir(parents=True, exist_ok=True)
    log = build/'compile-attempt-1.log'
    assert not log.exists(), 'partial compile evidence exists; use a reviewed recovery controller'
    cmd = [svb_cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4',
           '-cp', ':'.join(svb_cfg['compiler']), 'scala.tools.nsc.Main',
           '-classpath', ':'.join(svb_cfg['classpath']), '-Xplugin:'+svb_cfg['plugin'],
           '-d', str(classes), *map(str, sources)]
    env = {**os.environ, 'LD_LIBRARY_PATH':'', 'JAVA_TOOL_OPTIONS':'', 'CCACHE_DISABLE':'1',
           'OMP_NUM_THREADS':'4', 'TMPDIR':str(build/'tmp')}
    (build/'tmp').mkdir(exist_ok=True)
    with log.open('xb', buffering=0) as out:
        proc = subprocess.Popen(cmd, cwd=F/'chipyard', env=env, stdin=subprocess.DEVNULL,
                                stdout=out, stderr=subprocess.STDOUT)
        child = identity(proc.pid)
        update(state, status='RUNNING_COMPOSED_SCALA_TYPECHECK', child=child,
               active_stage='compile-composed', compiler_argv=cmd)
        while proc.poll() is None:
            try:
                proc.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            update(state, child=identity(proc.pid))
            os.fsync(out.fileno())
    assert proc.returncode == 0, ('combined Scala typecheck failed', str(log))
    class_hashes = {}
    for relative in expected_classes:
        path = classes/relative
        assert path.is_file(), str(path)
        class_hashes[relative] = sha(path)

    result_path = O/'composed-equivalence.json'
    assert not result_path.exists(), 'existing final receipt is immutable'
    result = dict(
        schema='ec-opt4-composed-area-equivalence/1',
        status='PASS_COMPOSED_SOURCE_BOUND_MODULE_EQUIVALENCE_TYPECHECKED_NOT_FULL_DUT_FORMAL_OR_CAD',
        hardware_commit=commit, source_id=source_id, parent_commit=binding['svb_commit'],
        area_parent=binding['area_parent'], address_candidate=binding['address_commit'],
        svb_candidate=binding['svb_commit'], changed_files=sorted(expected_delta),
        address_evidence=dict(local_proof=address_local, compare_log=str(address_log),
                              compare_log_sha256=sha(address_log), module_map=address_map),
        svb_evidence=dict(composition_proof=str(D/'build-logs/Opt4-fit-svb-system-r2-20261111/combined-equivalence.json'),
                          composition_proof_sha256=sha(D/'build-logs/Opt4-fit-svb-system-r2-20261111/combined-equivalence.json'),
                          comparison=str(svb_compare_path), comparison_sha256=sha(svb_compare_path),
                          reference_rtl_sha256=sha(reference_rtl), candidate_rtl_sha256=sha(candidate_rtl)),
        combined_typecheck=dict(log=str(log), log_sha256=sha(log), class_hashes=class_hashes),
        equivalence_scope='Changed hardware modules are disjoint: PackageAddressStats has an exact frozen 6144-cycle/52-output comparison plus unconditional update SAT; SVB has source-bound combinational SAT and 4096 randomized cycles with all 127 outputs. Their same-cycle state transitions are independent. No full-DUT formal result is claimed.',
        module_only_resources=dict(address_candidate_luts=872880, address_parent_luts=990905,
                                   measured_address_lut_delta=118025,
                                   svb_area_not_combined_or_whole_dut_measured=True),
        full_dut_formal=False, whole_dut_fit=False, whole_dut_synthesis=False, fpga_access=False,
        architectural_recovery_added=False, configuration_matches_frozen_parameters=True,
    )
    save(result_path, result)
    update(state, status=result['status'], child={}, ended_utc=now(),
           output=str(result_path), output_sha256=sha(result_path), class_hashes=class_hashes)
    print(result['status'])

if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.is_file():
            state = read(S)
            if state.get('pid') == os.getpid():
                update(state, status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
        raise
