#!/usr/bin/python3
"""Diagnosed annotation-remap recovery; compiler proof then exact host generation."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import re
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-common-stats-host-r6-20261113'
P = D/'build-logs/Opt4-common-stats-host-r5-20261113'
R1 = D/'build-logs/Opt4-common-stats-host-r1-20261113'
TREE = W/'Opt4-area-common-stats-host-r6-20261113'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha
spec = importlib.util.spec_from_file_location('unchanged_resource_guard',
    W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
m.C, m.O, m.CPUS = C, O, {206, 207}


def members(unit):
    expected = '/user.slice/user-1008.slice/user@1008.service/'+unit
    result = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit(): continue
        try:
            paths = [line.split(':', 2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            if any(path == expected or path.startswith(expected+'/') for path in paths):
                row = identity(int(proc.name))
                if row and row['process_state'] not in ['Z', 'X']: result.append(row)
        except OSError: pass
    return result


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt exact compiler recovery owner'
    unit = 'ec-opt4-common-stats-host-r5-20261113.service'
    assert not members(unit)
    failure = read(P/'failure.json'); log = (P/'goldengate-Threaded.log').read_text()
    assert failure['active_stage'] == 'goldengate-Threaded'
    assert 'java.lang.OutOfMemoryError: Java heap space' in log
    assert 'firrtl.transforms.CombinationalPath.update' in log
    binding = read(C/'source-binding.json')
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE, text=True).strip() == binding['experiment_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(
            ['git', 'show', binding['experiment_commit']+':'+rel], cwd=TREE)).hexdigest() == h
    os.sched_setaffinity(0, {206, 207}); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-mixed-host-batch-remap-recovery/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        experiment_commit=binding['experiment_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=[206, 207], memory_limit_gib=64, java_heap_gib=48, fpga_access=False, no_CAD=True,
        full_system_fit=False, target_or_host_validation_claim=False, hardware_changed=False,
        scope='Actual mixed-role production host generation with per-call shared annotation propagation; no token, area or whole EC claim')
    m.update('ADMITTING_DIAGNOSED_BATCH_ANNOTATION_REMAP_RECOVERY')
    save(O/'predecessor-release.json', dict(utc=now(), unit=unit, members=[],
        failure_sha256=sha(P/'failure.json'), log_sha256=sha(P/'goldengate-Threaded.log')))
    save(O/'admission.json', m.admission())
    prior = read(P/'checker-semantic-regression-receipt.json')
    assert prior['accepted'] and sha(prior['log']) == prior['log_sha256']
    assert 'EC_COMPACT_CHECKER_REGRESSION_PASS passed=261 rejected=5' in Path(prior['log']).read_text()
    gate = read(P/'compiler-recovery-gate.json')
    assert all(sha(path) == h for path, h in gate['classes'].items())
    save(O/'reused-compact-checker-regression.json', dict(
        receipt_sha256=sha(P/'checker-semantic-regression-receipt.json'), classes=gate['classes'],
        loop_checks_enabled=True, no_repeat_unchanged_compact_checker=True))
    cfg = read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java = [cfg['java'], '-Xmx48G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    checker = P/'checker-classes'
    classes = O/'mapper-classes'; classes.mkdir()
    compilecp = str(checker)+':'+':'.join(cfg['classpath'])
    m.stage('compile-batch-mapper', java+['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
        '-classpath', compilecp, '-d', classes]+[C/name for name in
        ['ECBatchAnnotationRemap.scala', 'CheckBatchRemap.scala', 'SimulationMapping.scala']],
        [classes/'firrtl/ECBatchAnnotationRemap.class', classes/'firrtl/CheckBatchRemap.class',
         classes/'midas/passes/SimulationMapping.class'])
    proofcp = str(classes)+':'+compilecp
    m.stage('batch-remap-semantic-regression', java+['-cp', proofcp, 'firrtl.CheckBatchRemap'],
        marker='EC_BATCH_REMAP_REGRESSION_PASS cases=288')
    save(O/'batch-remap-gate.json', dict(
        receipt_sha256=sha(O/'batch-remap-semantic-regression-receipt.json'),
        identical_order_values_deduplication=True, ordinary_annotations_retained=True,
        per_invocation_cache_scope=True, hardware_or_target_cycles_changed=False,
        mapper_classes={str(path): sha(path) for path in classes.rglob('*.class')}))
    target = R1/'Host-target'
    receipt = read(R1/'elaborate-mixed-host-receipt.json')
    assert receipt['accepted'] and all(sha(path) == h for path, h in receipt['outputs'].items())
    assert 'DontCheckCombLoopsAnnotation' not in (target/'MixedStats.anno.json').read_text()
    selected = [annotation for annotation in read(target/'MixedStats.anno.json')
        if annotation.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected) == 64
    save(O/'reused-target-elaboration.json', dict(
        receipt_sha256=sha(R1/'elaborate-mixed-host-receipt.json'), files=receipt['outputs'],
        selected_instances=64, production_slots=256, public_outputs=73, no_reelaboration=True))
    bank = D/'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
    composed = D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    cp = ':'.join(map(str, [classes, checker, R1/'classes', bank, composed]))+':'+':'.join(cfg['classpath'])
    for name in ['Threaded', 'Plain']:
        host = O/name; host.mkdir()
        m.stage('goldengate-'+name, java+['-cp', cp, 'midas.stage.GoldenGateMain',
            '-i', target/'MixedStats.fir', '-td', host, '-faf', target/'MixedStats.anno.json',
            '-ggcp', 'commonstatshost', '-ggcs', name+'Config', '--output-filename-base', 'FireSim-generated'],
            [host/'FireSim-generated.sv', host/'FireSim-generated.synthesis.xdc'])
        text = (O/('goldengate-'+name+'.log')).read_text()
        assert 'EC_BATCH_ANNOTATION_REMAP input=' in text
        assert 'Skipping Combinational Loop Detection' not in text
        fame = (host/'post-fame-transform.fir').read_text()
        types = re.findall(r'(?m)^\s*inst \w+ of (StatsBank(?:_\d+)?)\b', fame)
        assert len(types) == 64 and len(set(types)) == 1
        fir = (host/'post-gen-sram-models.fir').read_text()
        assert ('module StatsBank_threaded :' in fir) == (name == 'Threaded')
        assert not any(word in fir for word in ['io_observe', 'io_debugBuckets', 'io_debugValid', 'io_debugSeq'])
        save(O/(name+'-threading-audit.json'), dict(selected_instances=64, selected_types=['StatsBank'],
            address_banks=16, barrier_banks=48, slots=256, lanes=16, public_outputs=73,
            proof_outputs=False, host_RTL_sha256=sha(host/'FireSim-generated.sv')))
    assert all(sha(path) == h for path, h in binding['files'].items())
    m.update('PASS_MIXED_HOST_BATCH_REMAP_AND_EXACT_HOST_GENERATION_TOKEN_VALIDATION_PENDING',
        ended_utc=now(), target_tokens_verified=False, area_gain_unknown=True,
        next='Adopt exact generated hosts for corrected complete73-output token/negative checks; no area before tokens and no whole EC claim')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
