#!/usr/bin/python3
"""Freeze the tag-compression candidate inputs and submit isolated validation."""
from pathlib import Path
import ast
import datetime as dt
import hashlib
import importlib.util
import json
import os
import shutil
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-tagcompress-r1-20261111'
F = W/'Opt4-fit-address-tagcompress-r1-20261111'
T = W/'candidates/address-group4-r1-20261111'
O = D/'build-logs/Opt4-fit-address-tagcompress-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
PARENT = '981b890d870130f99ec24a0c5e37acb39362318a'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
PARENT_STATE = D/'Opt4-fit-address-group4-r1-state.json'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def atomic(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, f'immutable conflict: {path}'
        return
    tmp = path.with_name(path.name+'.tmp-'+str(os.getpid()))
    with tmp.open('wb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def save(path, value):
    atomic(path, (json.dumps(value, indent=2, sort_keys=True)+'\n').encode())


def refresh_manifest(path, value, request_path, runtime_request, rejected_request):
    data = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    path = Path(path)
    if path.exists() and path.read_bytes() != data:
        assert not request_path.exists(), 'submitted candidate inputs are immutable'
        assert not (D/'Opt4-fit-address-tagcompress-r1-state.json').exists(), \
            'candidate state exists; inputs are immutable'
        if Path(rejected_request).exists():
            old_name = Path(rejected_request).stem
            result = json.loads((U/'request-results'/(old_name+'.json')).read_text())
            runtime_result = json.loads((U/'request-results'/(Path(runtime_request).stem+'.json')).read_text())
            assert result.get('status') == 'REJECTED_WITH_EVIDENCE', \
                'previous broker request was not rejected'
            assert not (U/'jobs'/old_name).exists(), 'previous broker job exists; inputs are immutable'
            assert runtime_result.get('status') == 'TEMPLATES_PREPARED_NO_FPGA_ACCESS'
        else:
            assert not runtime_request.exists(), 'runtime request exists; inputs are immutable'
        atomic_replace(path, data)
    else:
        atomic(path, data)


def replace_config_template(path, value, commit, template_bytes, template_worktree):
    path = Path(path)
    data = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    if path.exists():
        old = json.loads(path.read_text())
        if old.get('binding', {}).get('hardware_commit') == commit and old.get('worktree') == str(F):
            atomic(path, data)
            return
        assert old.get('binding', {}).get('hardware_commit') == PARENT
        assert old.get('worktree') == str(template_worktree)
        assert path.read_bytes() == template_bytes
    atomic_replace(path, data)


def atomic_replace(path, data):
    path = Path(path)
    tmp = path.with_name(path.name+'.tmp-'+str(os.getpid()))
    with tmp.open('wb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def main():
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip() == PARENT
    assert subprocess.check_output(['git', 'rev-parse', FROZEN], cwd=F, text=True).strip() == FROZEN
    assert subprocess.check_output(['git', 'diff', '--name-only', PARENT, commit], cwd=F, text=True).splitlines() == [
        REL+'PackageAddressStats.scala', 'lineage.json']
    assert subprocess.check_output(['git', 'diff', '--check', PARENT, commit], cwd=F).decode() == ''
    ast.parse((C/'controller.py').read_text())
    ast.parse((C/'prepare.py').read_text())
    for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']:
        source = F/REL/name
        assert source.read_bytes() == subprocess.check_output(
            ['git', 'show', commit+':'+REL+name], cwd=F)

    parent_state = json.loads(PARENT_STATE.read_text())
    assert parent_state['hardware_commit'] == PARENT
    assert parent_state['status'] == 'VERIFIED_AND_MAPPED_MODULE_ONLY'
    assert parent_state['full_module_regression'] == 'PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
    touch = parent_state['inherited_touch_bounds']
    assert touch['status'] == 'PASS_UNIVERSAL_96_INPUT_BITS'
    assert touch['bounds'] == [8, 3, 2, 1]
    assert 'SUCCESS' in Path(touch['log']).read_text()

    sys.path.insert(0, str(W/'scripts'))
    spec = importlib.util.spec_from_file_location('tagcompress_build_hw', W/'scripts/build_hw.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    inventory = module.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    patch = subprocess.check_output(['git', 'show', '--format=', '--binary', commit], cwd=F)
    binding = dict(schema='ec-opt4-address-tagcompress-binding/1', hardware_commit=commit,
        source_id=source_id, parent_commit=PARENT, frozen_commit=FROZEN,
        profile='Opt4-fit-address-tagcompress-r1-candidate',
        candidate_change=('Store the high sequence-tag bits per bucket and reconstruct the low bits from the fixed slot index. '
            'Full 32-bit collision checks remain exact under the valid-slot invariant. Bucket count, all counter widths, '
            'checkers, event/cycle behavior, reset, overflow, drain and instrumentation are retained.'),
        patch_sha256=hashlib.sha256(patch).hexdigest(), formal_admission=False, production_selected=False)

    save(F/'source-inventory.json', inventory)
    atomic(F/'candidate.patch', patch)
    save(F/'candidate-binding.json', binding)
    save(F/'bindings'/(commit+'.json'), binding)
    save(C/'binding.json', binding)
    config_path = C/'config.json'
    template_path = T/'config.json'
    template_config = json.loads(template_path.read_text())
    TEMPLATE_WORKTREE = Path(template_config['worktree'])
    CONFIG_BYTES = config_path.read_bytes() if config_path.exists() else template_path.read_bytes()
    config = json.loads(CONFIG_BYTES)
    if config.get('binding', {}).get('hardware_commit') == PARENT:
        assert config['worktree'] == str(TEMPLATE_WORKTREE)
    else:
        assert config.get('binding', {}).get('hardware_commit') == commit
        assert config.get('worktree') == str(F)
    config.update(binding=binding, worktree=str(F), parent_local_receipt=str(PARENT_STATE))
    replace_config_template(config_path, config, commit, CONFIG_BYTES, TEMPLATE_WORKTREE)

    paths = [F/REL/name for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']]
    paths += [C/name for name in ['controller.py', 'prepare.py', 'EmitGroup.scala',
        'tag-compress-proof.v', 'binding.json', 'config.json', 'frozen-original.v', 'frozen-tb.v']]
    paths += [F/'lineage.json', F/'source-inventory.json', F/'candidate.patch',
        F/'candidate-binding.json', F/'bindings'/(commit+'.json'), W/'scripts/build_hw.py',
        PARENT_STATE, Path(touch['log'])]
    paths += [Path(p) for p in config['classpath']+config['compiler']+[config['plugin']]]
    hashes = {str(path): sha(path) for path in sorted(set(paths), key=str)}
    descriptor = dict(schema='ec-opt4-runtime-candidate/1', commit=commit, source_id=source_id,
        profile='Opt4-fit-C4-SVB32-address-tagcompress-20261111',
        state_prefix='Opt4-fit-address-tagcompress', worktree=str(F),
        cad_state=str(D/'Opt4-fit-address-tagcompress-cad-state.json'),
        rtl_state=str(D/'Opt4-fit-address-tagcompress-rtl-state.json'),
        board_bdf='0000:21:00.0', board_serial='21770433G02LA')
    descriptor_path = W/'runtime-candidates'/(commit[:8]+'.json')
    save(descriptor_path, descriptor)

    name = 'address-tagcompress-r1-bind2-'+commit[:8]
    request_path = U/'requests'/(name+'.json')
    runtime_request = U/'requests'/(commit[:8]+'-prepare_runtime.json')
    rejected_request = U/'requests'/('address-tagcompress-r1-'+commit[:8]+'.json')
    refresh_manifest(C/'input-hashes.json', hashes, request_path, runtime_request, rejected_request)
    broker_inputs = {path: digest for path, digest in hashes.items()
                     if Path(path).resolve().is_relative_to(W)}
    assert set(hashes)-set(broker_inputs) == {str(PARENT_STATE), str(Path(touch['log']))}, \
        'only the explicit inherited evidence may be outside the worktree'
    broker_inputs[str(C/'input-hashes.json')] = sha(C/'input-hashes.json')
    request = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(F/'chipyard'),
        argv=['/usr/bin/python3', str(C/'controller.py')],
        inputs=broker_inputs,
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-tagcompress-r1-state.json'), str(O/'verified-local.json')]))
    memory_gib = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
        if line.startswith('MemAvailable:')))/2**20
    disk_gib = shutil.disk_usage(W).free/2**30
    manifest_sha256 = sha(C/'input-hashes.json')
    preflight = dict(schema='ec-opt4-address-tagcompress-preflight/2', status='BOUND_NO_VERIFICATION_YET',
        hardware_commit=commit, source_id=source_id, input_manifest_sha256=sha(C/'input-hashes.json'),
        parent_commit=PARENT, frozen_commit=FROZEN, request=str(request_path),
        runtime_descriptor=str(descriptor_path),
        supporting_evidence_sha256={path: hashes[path] for path in sorted(set(hashes)-set(broker_inputs))},
        max_threads=8, minimum_memory_gib=48, minimum_disk_gib=40, fpga_access=False,
        full_dut_synthesis=False, formal_admission=False,
        proof_limits=['SAT establishes the valid-slot tag invariant step and exact compare under the invariant.',
            'Actual-size combinational tests and the finite complete-module comparison are not full-DUT formal equivalence.'])
    preflight_path = O/('candidate-preflight-'+manifest_sha256[:12]+'.json')
    save(preflight_path, preflight)

    if '--submit' in sys.argv:
        assert memory_gib >= 48 and disk_gib >= 40, 'module resource gate closed'
        atomic(request_path, (json.dumps(request, indent=2, sort_keys=True)+'\n').encode())
        atomic(runtime_request, (json.dumps(dict(action='prepare_runtime', descriptor=str(descriptor_path)),
            indent=2, sort_keys=True)+'\n').encode())
        preflight['status'] = 'REQUEST_READY'
        preflight['request_submitted'] = True
        preflight['runtime_request'] = str(runtime_request)
        preflight.update(available_memory_gib=memory_gib, free_disk_gib=disk_gib,
                         submission_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        attempt_path = O/'submission-attempts'/(
            manifest_sha256[:12]+'-'+str(os.getpid())+'.json')
        save(attempt_path, preflight)
    print(json.dumps(dict(**preflight, preflight_path=str(preflight_path)), sort_keys=True))


if __name__ == '__main__':
    main()
