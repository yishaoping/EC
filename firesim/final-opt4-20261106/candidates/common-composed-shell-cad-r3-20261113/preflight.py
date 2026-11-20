#!/usr/bin/python3
"""Offline checks for the deterministic shell successor; never runs CAD."""
from pathlib import Path
import builtins
import copy
import importlib.util
import json
import symtable
import tempfile

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('shell_successor_preflight', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
for path in [C/'controller.py', C/'cad_engine.py', C/'install.py']:
    compile(path.read_text(), str(path), 'exec')
table = symtable.symtable((C/'controller.py').read_text(), str(C/'controller.py'), 'exec')
for function in table.get_children():
    missing = [symbol.get_name() for symbol in function.get_symbols()
        if symbol.is_referenced() and symbol.is_global()
        and symbol.get_name() not in vars(m) and not hasattr(builtins, symbol.get_name())]
    assert not missing, (function.get_name(), missing)

# Synthetic future-result fixtures exercise rejection, not hardware validation.
fixture = dict(status=m.STATUS, functional_baseline=m.BASE, hardware_commit=m.COMMIT,
    source_variant=m.VARIANT, complete_dcache_cycles_verified=True, target_cycles=8192,
    observations=24575, selected_instances=64, selected_model_types=['StatsBank'],
    full_system_fit=False, fpga_access=False)
m.admissible(fixture)
rejected = []
for field, value in [('status', 'partial'), ('functional_baseline', 'wrong'),
                     ('hardware_commit', 'wrong'), ('source_variant', 'wrong'),
                     ('complete_dcache_cycles_verified', False), ('target_cycles', 8191),
                     ('observations', 24574), ('selected_instances', 63),
                     ('selected_model_types', []), ('full_system_fit', True), ('fpga_access', True)]:
    changed = copy.deepcopy(fixture); changed[field] = value
    try:
        m.admissible(changed)
    except AssertionError:
        rejected.append(field)
    else:
        raise AssertionError(('accepted invalid prerequisite', field))

# The upstream cycle receipt intentionally has no generic command fields.
# Check its real contract and reject each altered assertion/source/count/log.
with tempfile.TemporaryDirectory(prefix='ec-shell-receipt-contract-') as directory:
    log = Path(directory)/'cycle.log'
    log.write_text('COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192 observations=24575\n')
    receipt = dict(hardware_commit=m.COMMIT, source_variant=m.VARIANT,
        source_binding_sha256='binding', assertions_enabled=True, target_cycles=8192,
        observations=24575, log=str(log), log_sha256=m.sha(log))
    assert 'returncode' not in receipt and 'missing_outputs' not in receipt
    m.validate_cycle_receipt(receipt, 'binding')
    for key, value in [('hardware_commit', 'wrong'), ('source_variant', 'wrong'),
                       ('source_binding_sha256', 'wrong'), ('assertions_enabled', False),
                       ('target_cycles', 8191), ('observations', 24574), ('log_sha256', 'wrong')]:
        changed = copy.deepcopy(receipt); changed[key] = value
        try:
            m.validate_cycle_receipt(changed, 'binding')
        except AssertionError:
            rejected.append('cycle-'+key)
        else:
            raise AssertionError(('accepted invalid cycle receipt', key))
    log.write_text('INCOMPLETE cycles=8192 observations=24575\n')
    receipt['log_sha256'] = m.sha(log)
    try:
        m.validate_cycle_receipt(receipt, 'binding')
    except AssertionError:
        rejected.append('cycle-completion-marker')
    else:
        raise AssertionError('accepted partial cycle log')

engine = m.load('offline_shell_engine', C/'cad_engine.py')
old = (m.W/'scripts/build_opt4_fit_cad.py').read_text()
expected = old.replace("    old = read(D/'C4-runtime-cad-state.json')\n    original = Path(old['output_dir'])",
    "    # Stable snapshot contains the relocated tool-generated scripts.\n    # The original /var/tmp CAD directory has been retired.\n    original = N")
assert (C/'cad_engine.py').read_text() == expected, 'Only retired-path recovery is permitted'
snapshot = engine.read(engine.N/'snapshot.complete.json')
shell = [row for row in snapshot['dcps'] if Path(row['snapshot']).stem != engine.DUT]
assert len(shell) == 11
for row in shell:
    path = engine.N/'reused-checkpoints'/Path(row['snapshot']).name
    assert engine.sha(path) == row['sha256'], path
impl = (engine.N/'vivado_proj/firesim.runs/impl_1/design_1_wrapper.tcl').read_text()
assert impl.count('  link_design -top design_1_wrapper -part '+engine.PART) == 1
assert impl.count('OPTRACE "opt_design reports" START { REPORT }') == 1
assert impl.count('    implement_debug_core ') == 1
assert impl.index('write_checkpoint -force design_1_wrapper_opt.dcp') < impl.index('OPTRACE "opt_design reports" START { REPORT }')
synth = engine.N/'vivado_proj/firesim.runs'/(engine.DUT+'_synth_1')/(engine.DUT+'.tcl')
assert 'OPTRACE "Configure IP Cache" START' in synth.read_text()
actual = engine.utilization(m.D/'build-logs/Opt4-fit-field-address-cad-8d50489a/top-postopt-utilization.rpt')
assert actual['CLB LUTs']['used'] == 2478437 and actual['CLB LUTs']['available'] == 1303680
up = m.load('authenticated_composition_preflight', m.UC/'controller.py')
binding, inventory = up.verify_binding()
assert binding['source_variant'] == m.VARIANT and binding['hardware_commit'] == m.COMMIT
report = dict(status='PASS_OFFLINE_SHELL_SUCCESSOR_PREREQUISITE_REJECTIONS_SNAPSHOT_AND_RECOVERY_ONLY',
    utc=m.now(), rejected_fixture_fields=rejected, shell_checkpoint_hashes_verified=11,
    authenticated_composition_class_files=len(inventory['files']),
    retired_original_CAD_path_dependency_removed=True, actual_old_shell_parser_checked=True,
    hardware_validation_claim=False, no_CAD=True, no_FPGA_IO=True)
print(json.dumps(report, indent=2, sort_keys=True))
