#!/usr/bin/python3
"""Exact component composition/typecheck/parameter/address-RTL preparation.

This controller starts no GoldenGate, mapping, whole synthesis or FPGA task.
Actual component area and final combined generated equivalence remain gates.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import shutil
import subprocess
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-fit-field-read-address-compose-round33-v1-20261111'
S = D / 'Opt4-fit-field-read-address-compose-round33-v1-state.json'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
FIELD = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ADDRESS = 'e21194b24e3f9bf94c57dff009ed0c3d7d7eab7e'
PARENT = '8d50489af3af9e4c766509284ba3d9d7c99cfec9'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def save(path, value):
    path = Path(path)
    temporary = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temporary.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temporary, path)


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def identity(pid):
    fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
    return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())


def policy():
    value = read(D / 'unattended-opt4/campaign-policy.json')
    assert value['functional_baseline_commit'] == FROZEN
    assert value['area_equivalence_only'] and not value['functional_extensions_allowed']
    assert value['native_paused'] and not value['fpga_access']
    return value


def resources():
    memory = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                      if line.startswith('MemAvailable:'))) / 2**20
    return dict(available_memory_gib=memory, free_disk_gib=shutil.disk_usage(W).free / 2**30,
                load_1min=os.getloadavg()[0])


def main():
    current_policy = policy()
    assert not S.exists(), 'Preserve prior evidence; use a new version after confirmed exit.'
    L.mkdir(exist_ok=False)
    lock = (L / 'instance.lock').open('x')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    cfg = read(C / 'config.json')
    binding = cfg['binding']
    tree = Path(cfg['worktree'])
    commit = binding['hardware_commit']
    st = dict(schema='ec-opt4-pre-area-field-read-address-composition/1',
              **identity(os.getpid()), hardware_commit=commit, source_id=binding['source_id'],
              functional_baseline_commit=FROZEN, status='VERIFYING_BOUND_COMPONENTS',
              started_utc=now(), fpga_access=False, area_admitted=False,
              production_selected=False, whole_dut_formal=False, stages={})

    def update(**values):
        st.update(values)
        st['updated_utc'] = now()
        save(S, st)

    update()
    inputs = read(C / 'input-hashes.json')
    assert inputs and all(sha(path) == digest for path, digest in inputs.items())
    git = lambda *args: subprocess.check_output(['git', *args], cwd=tree)
    get = lambda revision, path: git('show', revision + ':' + path)
    assert git('rev-parse', 'HEAD').decode().strip() == commit
    assert not git('diff', '--name-only') and not git('diff', '--cached', '--name-only')
    assert binding['parent_commit'] == PARENT
    assert binding['component_commits'] == [FIELD, ADDRESS]
    assert binding['frozen_commit'] == FROZEN
    for forbidden in current_policy['forbidden_extension_commits']:
        rc = subprocess.run(['git', 'merge-base', '--is-ancestor', forbidden, commit],
                            cwd=tree, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE).returncode
        assert rc == 1, ('revoked functional ancestor', forbidden, rc)
    expected_delta = {REL + 'dcache.scala', 'lineage.json'}
    assert set(git('diff', '--name-only', PARENT, commit).decode().splitlines()) == expected_delta
    assert (tree / REL / 'dcache.scala').read_bytes() == get(FIELD, REL + 'dcache.scala')
    for name in ['PackageAddressStats.scala', 'AddressBucketSequenceMemory.scala']:
        assert (tree / REL / name).read_bytes() == get(ADDRESS, REL + name)
    for path in binding['changed_files']:
        assert (tree / path).read_bytes() == get(commit, path)
        if path != REL + 'dcache.scala':
            assert (tree / path).read_bytes() == get(PARENT, path)
    allowed = {REL + name for name in ['dcache.scala', 'PackageAddressStats.scala',
                                      'AddressBucketSequenceMemory.scala']} | {'lineage.json'}
    assert set(git('diff', '--name-only', binding['common_equivalent_parent'], commit)
               .decode().splitlines()) == allowed
    # Authenticate this new source inventory once; do not repeatedly hash live CAD inputs.
    spec = importlib.util.spec_from_file_location('round33_inventory', W / 'scripts/build_hw.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    inventory = module.inventory(tree / 'chipyard')
    assert inventory == read(C / 'inventory.json')
    assert hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest() == binding['source_id']

    evidence = read(C / 'evidence-bindings.json')
    inherited = {}
    for role, row in evidence.items():
        assert sha(row['copy']) == row['sha256'] == sha(row['original'])
        inherited[role] = read(row['copy'])
    strict = inherited['strict-generated-identity']
    assert strict['hardware_commit'] == FIELD
    assert strict['source_id'] == '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
    assert strict['status'] == ('PASS_COMPLETE_GENERATED_DCACHE_RESTRICTED_PREDICATE_IDENTITY_'
                                'ALL_STATE_OUTPUTS_OBSERVATIONS_AND_STATEMENTS_NOT_WHOLE_DUT')
    assert strict['comparison']['identical'] and strict['actual_memory_write_mutation_rejected']
    assert strict['original_observations_preserved'] and strict['all_other_generated_modules_identical']
    assert strict['comparison']['checked_observations'] == 2529
    assert strict['comparison']['register_and_memory_objects'] == 28142
    for row in strict['inputs'].values():
        assert sha(row['path']) == row['sha256']
        assert sha(row['annotation']) == row['annotation_sha256']
    strict_result = Path(evidence['strict-generated-identity']['original'])
    broker = read(D / 'unattended-opt4/jobs/field-read-exact-identity-r31-v4-3656aec4/state.json')
    assert broker['status'] == 'COMPLETE' and broker['returncode'] == 0
    assert broker['outputs'][str(strict_result)] == sha(strict_result)
    cycles = inherited['parent-frozen-cycles']
    assert cycles['hardware_commit'] == strict['parent_commit']
    assert cycles['functional_baseline_commit'] == FROZEN
    assert cycles['complete_dcache_cycles_verified']
    for role in ['candidate', 'frozen']:
        assert cycles['preparation']['authenticated_rtl'][role]['assertions_preserved'] is True
    provenance = read(C / 'cycle-assertion-provenance.json')
    for key in ['command', 'emitted_procedural_fatal']:
        assert sha(provenance[key]['path']) == provenance[key]['sha256']
    command = Path(provenance['command']['path']).read_text()
    assert all(flag in command for flag in provenance['required_defines'])
    assert '--no-assert' not in command
    fatal = Path(provenance['emitted_procedural_fatal']['path']).read_text()
    marker = 'INTEGRITY-2: simultaneous occupancy accounting'
    position = fatal.index(marker)
    assert 'VL_STOP_MT(' in fatal[position:position + 1800]
    assert 'candidate.sv' in fatal[position:position + 1800]
    assert not cycles['rtl_changed'] and cycles['preparation']['compared_signals'] == 2534
    assert cycles['preparation']['authenticated_rtl']['candidate']['sha256'] == strict['inputs']['parent']['sha256']
    assert sha(evidence['parent-frozen-cycles']['copy']) == strict['parent_frozen_cycle_result_sha256']
    domain_cycles = inherited['parent-domain-frozen-cycles']
    assert domain_cycles['hardware_commit'] == strict['parent_commit']
    assert domain_cycles['functional_baseline_commit'] == FROZEN
    assert domain_cycles['complete_dcache_cycles_verified']
    assert not domain_cycles['assertions_disabled'] and not domain_cycles['rtl_changed']
    assert domain_cycles['preparation'] == cycles['preparation']
    assert cycles['preparation']['generation_taps'] == 512
    for receipt in [cycles, domain_cycles]:
        comparison = receipt['stages']['comparison']
        assert comparison['returncode'] == 0
        assert sha(comparison['log']) == comparison['log_sha256']
        assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in Path(comparison['log']).read_text()
    assert cycles['stages']['comparison']['log_sha256'] == domain_cycles['stages']['comparison']['log_sha256']
    source = inherited['field-source-validation']
    assert source['hardware_commit'] == FIELD and source['exact_parent_reversal']
    prior = inherited['parent-composition-precheck']
    assert prior['hardware_commit'] == PARENT and prior['normalized_component_rtl_equal']
    address = read(D / 'Opt4-fit-address-update-sequence-r1-state.json')
    assert address['hardware_commit'] == ADDRESS and address['exact_parent_reversal']
    assert address['full_module_regression'].startswith('PASS_6144')
    update(status='EXACT_COMPONENT_SOURCE_AND_INHERITED_PROOFS_AUTHENTICATED',
           exact_component_source=True, no_revoked_functional_ancestors=True,
           inherited_proof_bindings=evidence, inherited_generated_identity_observations=2529,
           inherited_parent_frozen_cycle_observations=2534,
           cycle_assertion_provenance=provenance)

    classes = L / 'classes'
    classes.mkdir()
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'JAVA_TOOL_OPTIONS': '',
           'CCACHE_DISABLE': '1', 'OMP_NUM_THREADS': '4', 'TMPDIR': str(L)}

    def stage(name, argv):
        policy()
        while True:
            available = resources()
            if (available['available_memory_gib'] >= 256 and available['free_disk_gib'] >= 40
                    and available['load_1min'] < 96):
                break
            update(status='WAITING_LIGHT_AUXILIARY_RESOURCE_GUARD', next_stage=name,
                   resource_gate=available)
            time.sleep(300)
            policy()
        log = L / (name + '-attempt-1.log')
        with log.open('xb', buffering=0) as stream:
            args = ['nice', '-n', '15', *map(str, argv)]
            child = subprocess.Popen(args, cwd=tree / 'chipyard', env=env,
                                     stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
            update(status='RUNNING_' + name.upper(), child=identity(child.pid), resource_gate=available)
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update()
                os.fsync(stream.fileno())
        row = dict(returncode=child.returncode, argv=args, log=str(log), log_sha256=sha(log))
        save(L / (name + '-result.json'), row)
        st['stages'][name] = row
        update(child={})
        assert child.returncode == 0, (name, child.returncode, str(log))

    sources = [tree / path for path in binding['changed_files']]
    emit = W / 'candidates/address-update-sequence-r1-20261111/Emit.scala'
    cp = ':'.join(cfg['classpath'])
    java = [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4']
    stage('compile', java + ['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
                            '-classpath', cp, '-Xplugin:' + cfg['plugin'], '-d', classes, *sources, emit])
    assert (classes / 'boom/lsu/BoomNonBlockingDCacheModule.class').is_file()
    assert (classes / 'boom/lsu/AddressBucketSequenceReplica.class').is_file()
    cp = str(classes) + ':' + cfg['firechip'] + ':' + cp
    parameters = L / 'parameters.json'
    stage('parameters', java + ['-Dec.dac.firesim=true', '-cp', cp, 'firesim.firesim.DacParameterAudit',
                               'firesim.firesim.DacOpt4C4', parameters])
    assert read(parameters) == read(cfg['frozen_parameters'])
    output = L / 'address'
    output.mkdir()
    stage('emit-address', java + ['-Dec.dac.firesim=true', '-cp', cp,
                                 'opt4retirestatic.Emit', 'address', output])
    actual = output / 'PackageAddressStats.v'
    reference = D / 'build-logs/Opt4-fit-address-update-sequence-r1-20261111/address/PackageAddressStats.v'

    def normalized(path):
        return re.sub(r'\s+', ' ', re.sub(r'//[^\n]*', '', Path(path).read_text())).strip()

    assert normalized(actual) == normalized(reference), 'composed address RTL differs from verified component'
    update(status='PASS_EXACT_FIELD_READ_ADDRESS_COMPOSITION_TYPECHECK_FROZEN_PARAMETERS_EMITTED_ADDRESS_NOT_AREA_ADMITTED',
           ended_utc=now(), normalized_component_address_rtl_equal=True,
           address_rtl_sha256=sha(actual), component_address_rtl_sha256=sha(reference),
           frozen_parameters_match=True, parameters_sha256=sha(parameters),
           changed_source_sha256={str(path): sha(path) for path in sources},
           class_sha256={str(path.relative_to(classes)): sha(path) for path in sorted(classes.rglob('*.class'))},
           final_generated_composed_dcache_equivalence_pending=True,
           actual_component_area_pending=True, no_goldengate_or_cad_requested=True,
           proof_limits='Exact disjoint source composition with inherited restricted generated DCache identity to d9, d9 frozen8192-cycle observations, and e211 frozen6144-cycle address regression. New combined changed-source typecheck, frozen parameters and emitted address identity only. Final combined generated equivalence, significant actual module maps, ABI and whole post-opt capacity/timing/DRC still required; no FIT or FPGA admission.')
    save(L / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.is_file():
            state = read(S)
            if state.get('pid') == os.getpid():
                state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
                save(S, state)
        raise
