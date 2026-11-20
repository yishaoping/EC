"""Read-only admission of measured, authenticated exact component composition.

No FPGA access, synthesis launch, or claim of full-DUT formal equivalence.
"""
from pathlib import Path
import hashlib
import importlib.util
import json
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = '8d50489af3af9e4c766509284ba3d9d7c99cfec9'
FIELD = 'd9d732622601ed792a2647546006b5aae986ab8e'
FIELD_SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'
ADDRESS = 'e21194b24e3f9bf94c57dff009ed0c3d7d7eab7e'
PROOF_STATUS = 'PASS_ACTUAL_GENERATED_FOUR_FIELD_WRITERS_512WORD_TRANSITIONS_TAPS_AND_FOUR_DATA_MUTATIONS_NOT_FULL_DCACHE'
MAP_STATUS = 'COMPLETE_REAL_FULL_DCACHE_FIELD_OBSERVED_PAIR_NOT_WHOLE_FIT_NOT_CYCLE_ADMITTED'
CYCLE_STATUS = 'PASS_COMPLETE_FROZEN_DCACHE_8192_CYCLE_OBSERVATION_REGRESSION_NOT_FULL_FORMAL_NOT_WHOLE_ADMITTED'
PRECHECK_STATUS = 'PASS_EXACT_DISJOINT_COMPOSITION_FULL_CHANGED_SOURCE_TYPECHECK_FROZEN_PARAMETERS_AND_EMITTED_ADDRESS_RTL_NOT_AREA_ADMITTED'
DEPS = {
    'precheck': ('Opt4-fit-field-address-precheck-r1-state.json', PRECHECK_STATUS),
    'proof': ('Opt4-fit-dcache-fieldbank-mutation-r5-state.json', PROOF_STATUS),
    'map': ('Opt4-fit-dcache-fieldbank-full-map-r4-state.json', MAP_STATUS),
    'address': ('Opt4-fit-address-update-sequence-r1-state.json', 'VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT'),
    'cycles': ('Opt4-fit-dcache-frozen-cycle-domain-r5-state.json', CYCLE_STATUS),
}


def read(path):
    path = Path(path)
    return json.loads(path.read_text()) if path.is_file() else {}


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def authenticate_job(name, result):
    job = read(D / 'unattended-opt4/jobs' / name / 'state.json')
    if job.get('status') != 'COMPLETE':
        return False
    assert job['returncode'] == 0
    assert job['outputs'][str(result)] == sha(result)
    return True


def check(cfg):
    policy = read(D / 'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == FROZEN
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['native_paused'] and not policy['fpga_access']
    rows = {key: read(D / path) for key, (path, _) in DEPS.items()}
    statuses = {key: row.get('status', 'NOT_STARTED') for key, row in rows.items()}
    if any('FAILED' in status for status in statuses.values()):
        return 'DEPENDENCY_FAILED_WITH_EVIDENCE', statuses
    if any(rows[key].get('status') != expected for key, (_, expected) in DEPS.items()):
        return 'WAITING', statuses
    b = cfg['binding']
    assert b['hardware_commit'] == COMMIT and b['frozen_commit'] == FROZEN
    assert b['component_commits'] == [FIELD, ADDRESS]
    for key in ['proof', 'map', 'cycles']:
        assert rows[key]['hardware_commit'] == FIELD and rows[key]['source_id'] == FIELD_SID
    pre = rows['precheck']
    assert pre['hardware_commit'] == COMMIT and pre['source_id'] == b['source_id']
    for path, digest in pre['changed_source_sha256'].items():
        assert sha(path) == digest
    assert pre['normalized_component_rtl_equal']
    root = D / 'build-logs/Opt4-fit-field-address-precheck-r1-20261111'
    assert read(root / 'result.json') == pre
    for path, digest in pre['class_sha256'].items():
        assert sha(root / 'classes' / path) == digest
    assert sha(root / 'address/PackageAddressStats.v') == pre['address_rtl_sha256']
    source = read(D / 'Opt4-fit-dcache-owner-fieldbanks-r1-state.json')
    assert source['hardware_commit'] == FIELD and source['source_id'] == FIELD_SID
    assert source['exact_parent_reversal'] and source['frozen_parameters_match']

    proof_root = D / 'build-logs/Opt4-fit-dcache-fieldbank-mutation-r5-20261111'
    result = proof_root / 'result.json'
    assert read(result) == rows['proof']
    if not authenticate_job('dcache-fieldbank-mutation-r5-d9d73262', result):
        return 'WAITING', dict(statuses, proof_job='WAITING_ATOMIC_COMPLETE')
    proof = rows['proof']
    assert proof['covered_count'] == 512 and not proof['positive_sat_repeated']
    assert proof['actual_field_write_mutations_rejected'] == 4
    assert not proof['whole_dut_formal']
    positive_root = D / 'build-logs/Opt4-fit-dcache-fieldbank-generated-proof-r4-20261111'
    contract = positive_root / 'extraction-contract.json'
    assert sha(contract) == proof['extraction_contract_sha256']
    contract_data = read(contract)
    assert contract_data['hardware_commit'] == FIELD and contract_data['source_id'] == FIELD_SID
    assert sha(positive_root / 'GeneratedOwnerTransition.v') == contract_data['miter_sha256']
    for row in contract_data['inputs'].values():
        assert sha(row['path']) == row['sha256']
    covered = set()
    for record in proof['inherited_positive_partitions']:
        assert sha(record['path']) == record['sha256']
        row = read(record['path'])
        assert row['accepted'] and row['returncode'] == 0 and not row['timeout']
        assert row['mutation'] is None and row['slots'] == record['slots']
        assert sha(row['log']) == row['log_sha256']
        assert sha(Path(record['path']).with_name(Path(record['path']).name.replace('-result.json', '.v'))) == row['miter_sha256']
        covered.update(row['slots'])
    assert covered == set(range(512))
    assert set(proof['stages']) == set(contract_data['physical_writers'])
    for memory, row in proof['stages'].items():
        assert row['mutation_rejected'] and row['returncode'] != 0
        assert row['actual_write_data_branch_xor'] == 1
        assert sha(row['log']) == row['log_sha256']
        assert sha(proof_root / ('mutation-' + memory + '.v')) == row['miter_sha256']

    mapped = rows['map']
    assert mapped['parent_area_reference_commit'] == 'e0c3737f989c563f99a00f3fd26c1cbd27421775'
    assert mapped['reference_reused_without_duplicate_mapping']
    assert set(mapped['maps']) == {'candidate', 'reference'}
    for row in list(mapped['maps'].values()) + [rows['address']['full_module_map']]:
        assert sha(row['report']) == row['report_sha256']
        assert row['resources']['CLB LUTs'] > 0
    actual_saved = mapped['maps']['reference']['resources']['CLB LUTs'] - mapped['maps']['candidate']['resources']['CLB LUTs']
    assert actual_saved == mapped['lut_saved']
    if actual_saved < 75000 or rows['address']['full_module_map']['resources']['CLB LUTs'] >= 872880:
        return 'NOT_SELECTED_NO_SIGNIFICANT_COMBINED_MODULE_GAIN', statuses
    address = rows['address']
    assert address['hardware_commit'] == ADDRESS and address['exact_parent_reversal']
    assert address['full_module_regression'].startswith('PASS_6144')

    cycles = rows['cycles']
    assert cycles['functional_baseline_commit'] == FROZEN
    assert cycles['complete_dcache_cycles_verified'] and not cycles['full_dut_formal']
    cycle_result = D / 'build-logs/Opt4-fit-dcache-frozen-cycle-domain-r5-20261111/result.json'
    assert read(cycle_result) == cycles
    if not authenticate_job('dcache-frozen-cycle-domain-r5b-d9d73262', cycle_result):
        return 'WAITING', dict(statuses, cycle_job='WAITING_ATOMIC_COMPLETE')
    assert not cycles['rtl_changed'] and not cycles['assertions_disabled']
    assert cycles['preparation']['compared_signals'] == 2534
    assert cycles['preparation']['compared_bits'] == 71589
    prior_cycle = read(W / 'candidates/dcache-frozen-cycle-domain-r5-20261111/prior-state.json')
    assert prior_cycle['status'] == 'FAILED_WITH_EVIDENCE'
    assert prior_cycle['stages']['compile']['returncode'] == 0
    assert cycles['preparation'] == prior_cycle['preparation']
    prep = cycles['preparation']
    assert prep['all_original_outputs'] and prep['all_original_donttouch_observations']
    assert prep['generation_taps'] == 512 and prep['functional_baseline_commit'] == FROZEN
    for row in cycles['stages'].values():
        assert row['returncode'] == 0 and sha(row['log']) == row['log_sha256']
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in Path(cycles['stages']['comparison']['log']).read_text()
    for row in prep['authenticated_rtl'].values():
        assert sha(row['path']) == row['sha256']
        assert sha(row['closure']) == row['closure_sha256']

    tree = Path(cfg['worktree'])
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=tree, text=True).strip() == COMMIT
    rel = 'chipyard/generators/boom/src/main/scala/lsu/'
    get = lambda commit, path: subprocess.check_output(['git', 'show', commit + ':' + path], cwd=tree)
    assert (tree / rel / 'dcache.scala').read_bytes() == get(FIELD, rel + 'dcache.scala')
    for name in ['PackageAddressStats.scala', 'AddressBucketSequenceMemory.scala']:
        assert (tree / rel / name).read_bytes() == get(ADDRESS, rel + name)
    allowed = {rel + name for name in ['dcache.scala', 'PackageAddressStats.scala', 'AddressBucketSequenceMemory.scala']} | {'lineage.json'}
    assert set(subprocess.check_output(['git', 'diff', '--name-only', b['common_equivalent_parent'], COMMIT], cwd=tree, text=True).splitlines()) == allowed
    spec = importlib.util.spec_from_file_location('field_inventory', W / 'scripts/build_hw.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    assert hashlib.sha256(json.dumps(module.inventory(tree / 'chipyard'), sort_keys=True).encode()).hexdigest() == b['source_id']
    return 'READY', dict(
        schema='ec-opt4-field-address-composition-admission/1',
        status='PASS_EXACT_COMPONENT_COMPOSITION_GENERATED_STORAGE_PROOF_COMPLETE_CYCLE_REGRESSION_AND_MEASURED_MODULE_AREA',
        hardware_commit=COMMIT, source_id=b['source_id'], frozen_commit=FROZEN,
        component_commits=[FIELD, ADDRESS], source_files_exact_components=True,
        architectural_recovery_added=False, full_dut_formal=False, fpga_access=False,
        actual_dcache_lut_saving=actual_saved,
        dependency_receipts={key: dict(path=str(D / path), sha256=sha(D / path)) for key, (path, _) in DEPS.items()},
        whole_dut_fit_not_inferred=True,
        proof_limits='Compositional source/actual generated storage induction plus complete-module8192cycle observations and frozenaddress6144cycle regression. Not monolithic fullDUT formal; whole capacity and timing remain required.')
