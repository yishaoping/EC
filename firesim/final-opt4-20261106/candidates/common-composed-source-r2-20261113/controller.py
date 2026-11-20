#!/usr/bin/python3
"""Compile exact common callers and complete DCache together; no RTL/CAD/IO."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
T = W/'Opt4-area-common-composed-source-r2-20261113'
O = D/'build-logs/Opt4-common-composed-source-r2-20261113'
CPUS = {218, 219}
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

spec = importlib.util.spec_from_file_location('unchanged_composition_guard',
    W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
m.C, m.O = C, O


def verify_binding():
    binding = read(C/'source-binding.json')
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T,
        text=True).strip() == binding['hardware_commit']
    assert all(sha(path) == digest for path, digest in binding['files'].items())
    for relative, digest in binding['committed_files'].items():
        blob = subprocess.check_output(['git', 'show', binding['hardware_commit']+':'+relative], cwd=T)
        assert hashlib.sha256(blob).hexdigest() == digest, relative
    # The composed DCache and memories remain the exact completed cycle/area
    # candidate. Common caller/bank bytes remain the geometry owner's source.
    for relative, origin in binding['source_origins'].items():
        assert (T/relative).read_bytes() == Path(origin).read_bytes(), relative
    return binding


def cpu_owners():
    owners = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit() or int(proc.name) == os.getpid(): continue
        try:
            affinity = os.sched_getaffinity(int(proc.name))
            row = identity(int(proc.name))
            if proc.stat().st_uid == os.getuid() and len(affinity) <= 8 and affinity & CPUS:
                if row and row['process_state'] not in ['X', 'Z']: owners.append(row)
        except OSError: pass
    return owners


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing exact compile owner'
    binding = verify_binding()
    assert not cpu_owners(), 'Preserve existing dedicated CPU owners'
    os.sched_setaffinity(0, CPUS); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-common-complete-source-compile/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        hardware_source_commit=binding['hardware_source_commit'],
        source_variant=binding['source_variant'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=sorted(CPUS), memory_limit_gib=64, no_elaboration=True, no_CAD=True,
        fpga_access=False, production_admission=False, full_system_fit=False,
        hardware_classes_reused=True, correction='Receipt/checker package only; no hardware edit',
        scope='Compile and constructor/class-origin closure of exact complete DCache, InclusiveCache, common AddressStats and all three barrier callers. No target/host equivalence, area or shell FIT claim.')
    m.update('ADMITTING_COMPLETE_SOURCE_COMPILE')
    cfg = read(C/'config.json')
    prior = D/'build-logs/Opt4-common-composed-source-r1-20261113'
    predecessor = 'ec-opt4-common-composed-source-r1-20261113.service'
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit(): continue
        try:
            paths = [line.split(':', 2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            assert not any(path.endswith('/'+predecessor) or '/'+predecessor+'/' in path for path in paths), 'Predecessor cgroup not released'
        except OSError: pass
    receipt = read(prior/'compile-complete-composition-receipt.json')
    assert receipt['returncode'] == 0 and sha(receipt['log']) == receipt['log_sha256']
    assert receipt['missing_outputs'] == [str(prior/'classes/freechips/rocketchip/inclusivecache/InclusiveCache.class')]
    assert all(sha(path) == digest for path, digest in receipt['outputs'].items())
    classes = prior/'classes'
    checker = O/'checker-classes'; checker.mkdir()
    assert (classes/'sifive/blocks/inclusivecache/InclusiveCache.class').is_file()
    save(O/'adopted-complete-compile.json', dict(predecessor_cgroup_released=True,
        receipt=str(prior/'compile-complete-composition-receipt.json'), receipt_sha256=sha(prior/'compile-complete-composition-receipt.json'),
        compiler_returncode=0, corrected_package='sifive.blocks.inclusivecache', hardware_classes_recompiled=False))
    java = [cfg['java'], '-Xmx24G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    m.stage('compile-corrected-checker', java+['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', str(classes)+':'+':'.join(cfg['classpath']),
        '-d', checker, C/'Composition.scala'], [checker/'eccommoncomposition/CheckComposition.class'])
    cp = str(checker)+':'+str(classes)+':'+cfg['firechip']+':'+':'.join(cfg['classpath'])
    log = m.stage('constructor-and-class-origin', java+['-cp', cp,
        'eccommoncomposition.CheckComposition', classes])
    assert 'COMMON_COMPOSITION_LINKAGE_PASS classes=9 constructors=3 no_elaboration=true' in log.read_text()
    # Check the actual DCache bytecode call, not just the callee's signature.
    javap = Path(cfg['java']).with_name('javap')
    bytecode = m.stage('dcache-constructor-bytecode', [javap, '-classpath', cp, '-c', '-p',
        'boom.lsu.BoomNonBlockingDCacheModule'])
    line = next(line for line in bytecode.read_text().splitlines()
        if 'invokespecial' in line and 'boom/lsu/PackageAddressStats.' in line)
    assert '(IIIIIIII)V' in line, line
    old = D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    legacy = m.stage('legacy-constructor-negative', [javap, '-classpath', str(old)+':'+':'.join(cfg['classpath']),
        '-c', '-p', 'boom.lsu.BoomNonBlockingDCacheModule'])
    old_line = next(line for line in legacy.read_text().splitlines()
        if 'invokespecial' in line and 'boom/lsu/PackageAddressStats.' in line)
    assert '(IIIIIII)V' in old_line and old_line != line, old_line
    save(O/'constructor-linkage.json', dict(new_DCache_call=line.strip(), legacy_DCache_call=old_line.strip(),
        old_unrecompiled_caller_rejected=True, new_address_constructor_int_parameters=8,
        exact_class_origins_checked=9, no_Chisel_module_constructed=True))
    parameters = O/'parameters.json'
    m.stage('frozen-parameters', java+['-Dec.dac.firesim=true', '-cp', cp,
        'firesim.firesim.DacParameterAudit', 'firesim.firesim.DacOpt4C4', parameters], [parameters])
    assert read(parameters) == read(cfg['frozen_parameters']), 'Frozen geometry changed'
    binding = verify_binding()
    inventory = {str(path): sha(path) for root in [classes, checker] for path in sorted(root.rglob('*.class'))}
    save(O/'compiled-classes.json', dict(files=inventory, classpath=cp,
        hardware_commit=binding['hardware_commit'], source_binding_sha256=sha(C/'source-binding.json')))
    m.update('PASS_COMPLETE_COMMON_COMPOSITION_COMPILE_FROZEN_PARAMETERS_AND_LINKAGE_NO_RTL',
        compiled_classes=len(inventory), compiled_classes_sha256=sha(O/'compiled-classes.json'),
        constructor_linkage_sha256=sha(O/'constructor-linkage.json'),
        frozen_parameters_sha256=sha(parameters), ended_utc=now(),
        target_validation=False, host_validation=False, measured_area=False,
        next='Consume exact mixed-token/area and full caller geometry results. Material measured gain gates one complete-source elaboration, frozen DCache8192cycle observation validation, actual complete threaded host/token/ABI closure and whole host/shell CAD. This compile is not FIT.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try: main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
