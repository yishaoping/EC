#!/usr/bin/python3
"""Actual archived ABI/assets and deliberate rejection checks, no new host claim."""
from pathlib import Path
import builtins
import copy
import importlib.util
import json
import symtable
import tempfile

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('offline_common_host_abi', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
table = symtable.symtable((C/'controller.py').read_text(), str(C/'controller.py'), 'exec')
for function in table.get_children():
    missing = [s.get_name() for s in function.get_symbols() if s.is_referenced() and s.is_global()
        and s.get_name() not in vars(m) and not hasattr(builtins, s.get_name())]
    assert not missing, (function.get_name(), missing)
old = m.read(m.PARENT/'driver-compatibility.json')
generated = {r['role']:r['derived'] for r in old['generated_inputs']}
assert m.compare_files(generated, old)['software_ABI_byte_equal']
assets = m.software_assets()
assert len(assets['programs']) == 8 and assets['program_order'] == list(m.PROGRAMS)
rejections = []


def reject(name, call):
    try:
        call()
    except (AssertionError, KeyError, FileNotFoundError):
        rejections.append(name)
        return
    raise AssertionError(('negative unexpectedly accepted', name))


with tempfile.TemporaryDirectory(prefix='ec-common-host-abi-offline-') as directory:
    root = Path(directory)
    header = root/'mutated.const.h'
    header.write_bytes(Path(generated[m.SOFTWARE[0]]).read_bytes()+b'\n#define EC_ABI_NEGATIVE 1\n')
    changed = {**generated, m.SOFTWARE[0]:str(header)}
    assert not m.compare_files(changed, old)['software_ABI_byte_equal']
    rejections.append('actual-header-byte-mutation-refuses-driver-reuse')
    constraint = root/'changed.xdc'
    constraint.write_bytes(Path(generated[m.CONSTRAINTS[1]]).read_bytes()+b'\n# offline constraint mutation\n')
    audit = m.compare_files({**generated, m.CONSTRAINTS[1]:str(constraint)}, old)
    assert audit['software_ABI_byte_equal'] and audit['new_shell_link_and_all_physical_checks_required']
    assert any(not r['byte_equal'] and r['physical_validation_required'] for r in audit['generated_inputs'])
    reject('missing-seventh-file', lambda:m.compare_files(
        {k:v for k,v in generated.items() if k!=m.CONSTRAINTS[0]}, old))
    forged = copy.deepcopy(old); forged['generated_inputs'][0]['derived_sha256'] = '0'*64
    reject('unauthenticated-parent-header', lambda:m.compare_files(generated, forged))
    log = root/'stage.log'; log.write_text('actual local negative stage\n')
    receipt = root/'stage.json'
    m.save(receipt, dict(returncode=0, missing_outputs=[], outputs={}, log=str(log), log_sha256=m.sha(log)))
    assert m.accepted(receipt)
    log.write_text('changed after receipt\n')
    reject('changed-stage-log', lambda:m.accepted(receipt))

# This future-result fixture exercises identity rejection only. It is not saved
# as a generation/target/host validation result and cannot start the successor.
fixture = dict(status=m.READY, hardware_commit=m.HW, functional_baseline=m.BASE,
    source_variant=m.VARIANT, complete_dcache_cycles_verified=True, target_cycles=8192,
    observations=24575, selected_instances=64, selected_model_types=['StatsBank'],
    full_system_fit=False, fpga_access=False,
    source_binding_sha256=m.sha(m.W/'candidates/common-composed-validate-r2-20261113/source-binding.json'))
m.validate_result(fixture)
for key, value in [('hardware_commit','3656'), ('source_variant','wrong'), ('observations',24574),
                   ('selected_instances',63), ('selected_model_types',['Unrelated']), ('fpga_access',True)]:
    reject('future-gate-'+key, lambda key=key,value=value:m.validate_result({**fixture,key:value}))
report = dict(schema='ec-exact-common-host-offline-abi-preflight/1', utc=m.now(),
    actual_parent_seven_files=7, actual_parent_software_files_equal=5,
    actual_software_programs=8, actual_software_receipts=len(assets['receipt_hashes']),
    actual_authenticated_asset_files=len(assets['assets']),
    checks=rejections, changed_constraint_requires_physical_validation=True,
    future_result_fixture_is_synthetic=True, current_common_host_validation=False,
    no_CAD=True, no_FPGA_IO=True, no_runtime_execution=True)
out = m.D/'status-audits/full-ec-structural-priority-20261112/round180-common-host-abi'
out.mkdir(exist_ok=True)
m.exact_json(out/'offline-preflight.json', report)
print(json.dumps(report, indent=2))
