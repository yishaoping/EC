#!/usr/bin/python3
"""Stage the already verified da8 compiler outputs for a future selected build.

No elaborate, GoldenGate, synthesis or FPGA process is started. The future
build still requires actual area selection and final composed RTL verification.
"""
from pathlib import Path
import datetime
import hashlib
import json
import os
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
P = W / 'candidates/field-read-address-compose-round33-v2-20261111'
R = D / 'build-logs/Opt4-fit-field-read-address-compose-round33-v2-20261111'
L = D / 'build-logs/Opt4-field-read-address-rtl-prep-round34-v1-20261111'
S = D / 'Opt4-field-read-address-rtl-prep-round34-v1-state.json'
COMMIT = 'da8b51a691cc104a5b32e13d2532ed9c836eb639'
SID = '4be542018125c2ba698f210e2bc769a789ba77a4e55432466552f14fceb11a9a'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    path = Path(path)
    q = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, path)


def main():
    policy = read(D / 'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == FROZEN
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['native_paused'] and not policy['fpga_access']
    assert not L.exists() and not S.exists(), 'Preserve prior outputs; use a new version.'
    inputs = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items())
    result = read(R / 'result.json')
    assert result['hardware_commit'] == COMMIT and result['source_id'] == SID
    assert result['status'] == 'PASS_EXACT_FIELD_READ_ADDRESS_COMPOSITION_TYPECHECK_FROZEN_PARAMETERS_EMITTED_ADDRESS_NOT_AREA_ADMITTED'
    assert result['normalized_component_address_rtl_equal'] and result['exact_component_source']
    assert result['frozen_parameters_match'] and result['no_revoked_functional_ancestors']
    job = read(D / 'unattended-opt4/jobs/field-read-address-precheck-r33-v2-da8b51a6/state.json')
    assert job['status'] == 'COMPLETE' and job['returncode'] == 0
    assert job['outputs'][str(R / 'result.json')] == sha(R / 'result.json')
    cfg = read(P / 'config.json')
    tree = Path(cfg['worktree'])
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=tree, text=True).strip() == COMMIT
    assert not subprocess.check_output(['git', 'diff', '--name-only', 'HEAD'], cwd=tree)
    for path, digest in result['changed_source_sha256'].items():
        assert sha(path) == digest
    for path, digest in result['class_sha256'].items():
        assert sha(R / 'classes' / path) == digest
    # The precheck's compiler classpath is preserved, including every dependency
    # hash. Do not regenerate or touch a live worktree's source/classes.
    dependency_inputs = read(P / 'input-hashes.json')
    assert all(sha(path) == digest for path, digest in dependency_inputs.items())
    L.mkdir()
    classes = L / 'prepared/source-classes'
    for rel, digest in result['class_sha256'].items():
        dst = classes / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(R / 'classes' / rel, dst)
        assert sha(dst) == digest
    sources = {}
    for path, digest in result['changed_source_sha256'].items():
        rel = Path(path).relative_to(tree)
        dst = L / 'prepared/source' / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(path, dst)
        assert sha(dst) == digest
        sources[str(dst)] = digest
    frozen_parameters = L / 'prepared/frozen-parameters.json'
    shutil.copy2(cfg['frozen_parameters'], frozen_parameters)
    cp = ':'.join([str(classes), cfg['firechip'], *cfg['classpath']])
    java = [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-Dec.dac.firesim=true', '-cp', cp]
    future = L / 'future-rtl'
    parameters = future / 'parameters/parameters.json'
    elab = future / 'elaborate'
    gg = future / 'goldengate'
    fir = elab / 'firesim.firesim.FireSim.fir'
    anno = elab / 'firesim.firesim.FireSim.anno.json'
    abi = read(cfg['baseline_driver_compatibility'])
    roles = [row['role'] for row in abi['generated_abi_and_target_description']]
    assert len(roles) == 7 and len(set(roles)) == 7
    stages = [
        dict(name='parameters', argv=java + ['firesim.firesim.DacParameterAudit', 'firesim.firesim.DacOpt4C4', str(parameters)],
             required_outputs=[str(parameters)], gate='Exact JSON equality with prepared frozen parameters.'),
        dict(name='elaborate', argv=java[:1] + ['-verbose:class'] + java[1:] + ['chipyard.Generator',
             '--target-dir', str(elab), '--name', 'firesim.firesim.FireSim', '--top-module',
             'firesim.firesim.FireSim', '--legacy-configs', 'firesim.firesim:DacOpt4C4'],
             required_outputs=[str(fir), str(anno)], gate='Require every changed class to originate in the private prepared classes.'),
        dict(name='goldengate', argv=java + ['midas.stage.GoldenGateMain', '-i', str(fir), '-td', str(gg),
             '-faf', str(anno), '-ggcp', 'firesim.configs', '-ggcs', 'DacXilinxAlveoConfig',
             '--output-filename-base', 'FireSim-generated', '--no-dedup'],
             required_outputs=[str(gg / n) for n in ['FireSim-generated.sv', 'FireSim-generated.const.h',
                'FireSim-generated.const.vh', 'FireSim-generated.defines.vh',
                'FireSim-generated.synthesis.xdc', 'FireSim-generated.implementation.xdc']],
             gate='Preserve blackbox list and append only source-bound resources; authenticate final RTL and annotations.')]
    plan = dict(schema='ec-opt4-prepared-composed-rtl-plan/1', hardware_commit=COMMIT, source_id=SID,
        functional_baseline_commit=FROZEN, component_commits=cfg['binding']['component_commits'],
        worktree=str(tree), cwd=str(tree / 'chipyard'), stages=stages,
        private_classes={str(classes / p): h for p, h in result['class_sha256'].items()},
        staged_sources=sources, inherited_input_sha256=dependency_inputs,
        frozen_parameters=dict(path=str(frozen_parameters), sha256=sha(frozen_parameters)),
        precheck=dict(path=str(R / 'result.json'), sha256=sha(R / 'result.json')),
        generated_abi_roles=roles,
        minimum_memory_gib=96, minimum_disk_gib=100, max_cpu=4,
        prerequisites=['Read current campaign policy before every stage.',
            'Wait for existing actual 3656 and e211 complete module maps; compare the common reference and d9/221 alternatives.',
            'Choose only a materially better verified combination. Existing 8d consumer remains adopted and untouched.',
            'Submit a new source-bound broker RTL spec only after selection; this preparation submits no generation request.'],
        mandatory_after_generation=['Complete composed generated DCache and address equivalence with all observations/assertions and cycle semantics.',
            'Authenticate all seven real generated ABI files; rebuild driver with a separate receipt on any mismatch.',
            'No whole admission from this plan or compiler completion. Whole post-opt capacity, timing, DRC and bitstream binding remain required.',
            'Only existing certified runtime broker services may operate 21:00.0; no worker FPGA access.'],
        full_composed_generated_equivalence_pending=True, expensive_stages_started=False,
        production_selected=False, fpga_access=False)
    save(L / 'build-plan.json', plan)
    final = dict(schema='ec-opt4-prepared-composed-rtl/1',
        status='PASS_STAGED_AUTHENTICATED_DA8_CLASSES_SOURCES_AND_RTL_COMMANDS_NOT_SELECTED_OR_GENERATED',
        hardware_commit=COMMIT, source_id=SID, functional_baseline_commit=FROZEN,
        class_count=len(result['class_sha256']), changed_source_count=len(sources),
        reused_compiler_outputs_without_recompile=True, no_live_input_changes=True,
        build_plan=str(L / 'build-plan.json'), build_plan_sha256=sha(L / 'build-plan.json'),
        actual_area_pending=True, whole_synthesis_started=False, fpga_access=False,
        ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    save(L / 'result.json', final)
    save(S, final)


if __name__ == '__main__':
    main()
