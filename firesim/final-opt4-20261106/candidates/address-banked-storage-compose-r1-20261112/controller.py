#!/usr/bin/python3
"""Compile private composed source; never elaborate, map or deploy it."""
import fcntl
import importlib.util
import os
from pathlib import Path
import resource
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112'
spec = importlib.util.spec_from_file_location('immutable_compile_stages',
    W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.O = O
from opt4_unattended_common import identity, now, read, save, sha
from prepare import prepare


def check_pins(binding, pins):
    for group in [binding['files'], binding['dependencies'], pins]:
        assert all(sha(p) == h for p, h in group.items()), 'Composed source inputs changed'


def dedicated_owners():
    owners = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit() or int(proc.name) == os.getpid():
            continue
        try:
            affinity = os.sched_getaffinity(int(proc.name))
            if proc.stat().st_uid == os.getuid() and len(affinity) <= 8 and affinity & {218,219}:
                row = identity(int(proc.name))
                if row and row['process_state'] not in ['X','Z']:
                    owners.append(dict(row, cgroup=(proc/'cgroup').read_text()))
        except (FileNotFoundError, ProcessLookupError, PermissionError):
            continue
    return owners


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing compile owner'
    binding = prepare()
    pins = {str(p):sha(p) for p in [C/n for n in
            ['prepare.py','controller.py','install.py','README.md','source-binding.json','config.json']]}
    pins[str(Path(m.__file__))] = sha(m.__file__)
    check_pins(binding, pins)
    owners = dedicated_owners()
    assert not owners, ('Preserve existing dedicated owners', owners)
    os.sched_setaffinity(0, {218,219})
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    cfg = read(C/'config.json')
    m.ST.update(schema='ec-private-composed-source-compile/1', **identity(),
        started_utc=now(), source_variant=binding['source_variant'],
        functional_baseline=binding['functional_baseline'], parent_commit=binding['parent_commit'],
        cpus=[218,219], memory_limit_gib=64, geometry=binding['geometry'],
        production_admission=False, production_selected=False,
        no_elaboration=True, no_CAD=True, fpga_access=False,
        scope=binding['scope'])
    save(O/'inputs.json', dict(files=pins, source_binding_sha256=sha(C/'source-binding.json')))
    m.update('CHECKING_COMPOSED_SOURCE_AND_RESOURCE_GUARDS')
    classes = O/'source-classes'
    classes.mkdir()
    java = [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=2']
    required = [classes/name for name in ['boom/lsu/BoomNonBlockingDCache.class',
        'boom/lsu/PackageAddressStats.class','boom/lsu/AppliedEffectResultMemory.class',
        'opt4bankedproduction/BucketBank.class', 'sourceprojected/AddressBucketGrouped$.class']]
    m.stage('compile-composed-source', java+['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']),
        '-Xplugin:'+cfg['plugin'], '-d', classes, *cfg['compile_sources']], required)
    # Parameter audit instantiates the frozen Config only; it emits no RTL.
    parameters = O/'parameters.json'
    cp = str(classes)+':'+cfg['firechip']+':'+':'.join(cfg['classpath'])
    m.stage('frozen-parameter-audit', java+['-Dec.dac.firesim=true', '-cp', cp,
        'firesim.firesim.DacParameterAudit', 'firesim.firesim.DacOpt4C4', parameters], [parameters])
    assert read(parameters) == read(cfg['frozen_parameters']), 'Frozen geometry changed'
    check_pins(binding, pins)
    m.update('PASS_PRIVATE_COMPOSED_SOURCE_COMPILE_AND_FROZEN_PARAMETERS_NO_ELABORATION_OR_AREA',
        ended_utc=now(), compiled_classes={str(p):sha(p) for p in required},
        frozen_parameters_sha256=sha(parameters), source_binding_sha256=sha(C/'source-binding.json'),
        complete_target_parity=False, generated_host_validation=False,
        area_gain_unknown=True, full_system_fit=False,
        next='Await actual production target/host token validation and complete same-harness module area gain. Then version a full-source RTL/ABI/complete-cycle validator. Whole synthesis remains separately gated.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
