#!/usr/bin/python3
"""Diagnosed nested-selection recovery, reusing exact completed target proof.

Only the host harness ownership scope changes. No CAD or board IO.
"""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import re
import resource
import shutil
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-address-banked-production-host-r2-20261113'
OLD = D / 'build-logs/Opt4-address-banked-production-host-r1-20261112'
T = W / 'Opt4-area-address-production-host-r2-20261113'
SOURCE = W / 'candidates/address-banked-production-host-r1-20261112'
from prepare import derive
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
# The old validator imports its immutable source preparation module by name.
spec = importlib.util.spec_from_file_location('original_production_prepare', SOURCE / 'prepare.py')
oldprepare = importlib.util.module_from_spec(spec)
spec.loader.exec_module(oldprepare)
sys.modules['prepare'] = oldprepare
spec = importlib.util.spec_from_file_location('direct_recovery_validator', SOURCE / 'controller.py')
p = importlib.util.module_from_spec(spec)
spec.loader.exec_module(p)
p.O, p.C, p.m.O, p.m.C = O, C, O, C


def members(unit):
    found = []
    for path in Path('/proc').iterdir():
        if not path.name.isdigit():
            continue
        try:
            if any(line.split(':', 2)[-1].endswith('/' + unit) or
                   ('/' + unit + '/') in line.split(':', 2)[-1]
                   for line in (path / 'cgroup').read_text().splitlines()):
                found.append(identity(int(path.name)))
        except OSError:
            pass
    return found


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt exact owner'
    prior = ['ec-opt4-address-banked-production-host-r1-20261112.service',
             'ec-opt4-address-banked-production-area-pair-r1-20261112.service',
             'ec-opt4-sprint-production-stack-recovery-r1-20261112.service']
    release = {unit: members(unit) for unit in prior}
    assert not any(release.values()), 'Wait for exact predecessor cgroup release'
    save(O / 'predecessor-release.json', dict(utc=now(), members=release))
    failed = read(OLD / 'failure.json')
    assert failed['active_stage'] == 'goldengate-Threaded' and not live(failed)
    failure_log = (OLD / 'goldengate-Threaded.log').read_text()
    assert 'PromoteSubmodule.findPromotedInstances' in failure_log and 'must be local' in failure_log
    assert 'java.lang.StackOverflowError' not in failure_log
    os.sched_setaffinity(0, {212, 213})
    resource.setrlimit(resource.RLIMIT_AS, (64 * 2**30,) * 2)
    binding = read(C / 'source-binding.json')
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T, text=True).strip() == binding['hardware_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show', binding['hardware_commit'] + ':' + rel], cwd=T)).hexdigest() == h
    generated, derivation = derive()
    assert generated == (C / 'Direct.scala').read_text() and derivation == binding['derivation']
    for stage in ['full-target-parity', 'full-target-negative', 'elaborate-Module']:
        receipt = read(OLD / (stage + '-receipt.json'))
        assert receipt['accepted'] and not receipt['missing_outputs']
        assert sha(receipt['log']) == receipt['log_sha256']
        assert all(sha(path) == h for path, h in receipt['outputs'].items())
    oldpins = read(OLD / 'inputs.json')
    assert all(sha(path) == h for path, h in oldpins['files'].items())
    p.m.ST.update(schema='ec-complete-production-direct-host-recovery/1', **identity(),
        started_utc=now(), hardware_commit=binding['hardware_commit'],
        functional_baseline=binding['functional_baseline'], cpus=[212, 213], memory_limit_gib=64,
        geometry=dict(banks=16, lanes=16, slots=256), fpga_access=False, no_CAD=True,
        full_system_fit=False, production_admission=False, finite_parity=True,
        monitor_outputs=5684, target_cycles=6144,
        source_binding_sha256=sha(C / 'source-binding.json'),
        actual_target_RTL_reused=True, unchanged_target_body=True,
        scope='Exact completed production target proof and direct-bank host scope recovery, with original3003token/52output oracle. No area or FIT claim.')
    p.m.update('ADMITTING_DIAGNOSED_LOCAL_SELECTED_BANK_RECOVERY')
    save(O / 'admission.json', p.m.admission())
    save(O / 'diagnosed-recovery.json', dict(
        predecessor=str(OLD / 'failure.json'), predecessor_sha256=sha(OLD / 'failure.json'),
        cause='ExtractModel WrapTop rebases nested selected bank annotations to nonlocal instance targets; PromoteSubmodule rejects them.',
        correction='Place byte-equal actual caller body under RawModule so selected banks are direct children; rebind IO and remove method-local private visibility only.',
        hardware_registers_or_target_cycles_added=0, stack_only_recovery_applicable=False,
        target_validation_repeated=False, compiler_loop_checks_enabled=True))
    save(O / 'inputs.json', dict(files={**oldpins['files'], **binding['files'],
         str(C / 'source-binding.json'): sha(C / 'source-binding.json')}))
    for name in ['full-target-parity-receipt.json', 'full-target-negative-receipt.json', 'trace-ports.h']:
        shutil.copyfile(OLD / name, O / name)
    (O / 'Module-target').symlink_to(OLD / 'Module-target', target_is_directory=True)
    cfg = read(W / 'candidates/dcache-field-read-system-r1-20261111/config.json')
    java = [cfg['java'], '-Xmx48G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    base = str(OLD / 'classes-Module') + ':' + ':'.join(cfg['classpath'])
    classes = O / 'classes'
    classes.mkdir()
    p.m.stage('compile-direct-wrapper', java + ['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', base, '-Xplugin:' + cfg['plugin'],
        '-d', classes, C / 'Direct.scala'], [classes / 'opt4productiondirect/CompleteHost.class'])
    checker = D / 'build-logs/Opt4-common-stats-host-r4-20261113/checker-classes'
    gate = read(checker.parent / 'compiler-recovery-gate.json')
    assert gate['unchanged_circuit_and_exact_port_paths_tested'] and not gate['bypassed_comb_loop_checks']
    assert all(sha(path) == h for path, h in gate['classes'].items())
    receipt = read(checker.parent / 'checker-semantic-regression-receipt.json')
    assert receipt['accepted'] and sha(checker.parent / 'checker-semantic-regression-receipt.json') == gate['regression_receipt_sha256']
    save(O / 'adopted-compiler-regression.json', dict(
        compiler_gate=str(checker.parent / 'compiler-recovery-gate.json'),
        compiler_gate_sha256=sha(checker.parent / 'compiler-recovery-gate.json'),
        classes=gate['classes'], packed_graph_only=True, loop_checks_enabled=True))
    cp = ':'.join(map(str, [checker, classes])) + ':' + base
    target = O / 'Host-target'
    target.mkdir()
    p.m.stage('elaborate-host', java + ['-cp', cp, 'freechips.rocketchip.system.Generator',
        '--target-dir', target, '--name', 'CompleteAddressStats',
        '--top-module', 'opt4productiondirect.CompleteHost', '--configs', 'firesim.midasexamples.NoConfig'],
        [target / 'CompleteAddressStats.fir', target / 'CompleteAddressStats.anno.json'])
    selected = [a for a in read(target / 'CompleteAddressStats.anno.json')
                if a.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected) == 16
    assert all(re.fullmatch(r'~CompleteHost\|CompleteHost/bucketBanks_\d+:BucketBank(?:_\d+)?', a['target']) for a in selected), selected
    save(O / 'direct-child-selection.json', dict(selected=selected, count=16, direct_children=True, single_model_type_after_dedup_required=True))
    trace = OLD / 'positive-reference-public-tokens.txt'
    assert len(trace.read_text().splitlines()) == 3003
    tokens = {}
    for name in ['Threaded', 'Plain']:
        host = O / name
        host.mkdir()
        p.m.stage('goldengate-' + name, java + ['-cp', cp, 'midas.stage.GoldenGateMain',
            '-i', target / 'CompleteAddressStats.fir', '-td', host,
            '-faf', target / 'CompleteAddressStats.anno.json', '-ggcp', 'opt4bankedproduction',
            '-ggcs', name + 'Config', '--output-filename-base', 'FireSim-generated'],
            [host / 'FireSim-generated.sv', host / 'FireSim-generated.synthesis.xdc'])
        post = (host / 'post-gen-sram-models.fir').read_text()
        assert ('module BucketBank_threaded :' in post) == (name == 'Threaded')
        assert not re.search(r'io_debug(?:Buckets|Valid|Seq|Bucket)', post)
        fame = (host / 'post-fame-transform.fir').read_text()
        banktypes = re.findall(r'(?m)^\s*inst \w+ of (BucketBank(?:_\d+)?)\b', fame)
        assert len(banktypes) == 16 and len(set(banktypes)) == 1
        assert 'Skipping Combinational Loop Detection' not in (O / ('goldengate-' + name + '.log')).read_text()
        save(O / (name + '-threading-audit.json'), dict(selected_count=16, proof_ports_absent=True,
            host_RTL_sha256=sha(host / 'FireSim-generated.sv'),
            transformed_bank_type='BucketBank_threaded' if name == 'Threaded' else 'BucketBank'))
        tokens[name] = p.simulate(host, name, trace)
        save(O / 'token-progress.json', tokens)
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    assert all(sha(path) == h for path, h in read(O / 'inputs.json')['files'].items())
    p.m.update('PASS_COMPLETE_TARGET_FINITE_PARITY_AND_COMPLETE_HOST_TOKENS_NO_AREA_OR_FIT',
        tokens=tokens, host_tokens=3003, production_public_outputs=52, full_formal=False,
        host_area_gain_unknown=True, ended_utc=now(),
        next='The bound serial same-harness area pair may run after this exact validator cgroup releases; require material actual gain and all composition gates before any complete-host build.')
    save(O / 'result.json', p.m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            save(O / 'failure.json', p.m.ST)
        raise
