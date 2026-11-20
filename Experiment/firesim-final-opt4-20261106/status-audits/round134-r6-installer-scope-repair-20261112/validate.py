#!/usr/bin/python3
"""Exercise installer orchestration in temporary files; never call systemctl."""
import hashlib
import importlib.util
import json
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace

sys.dont_write_bytecode = True
ROOT = Path('/data1/gzh/EC')
CANDIDATES = ROOT / 'firesim/final-opt4-20261106/candidates'
OLD = CANDIDATES / 'svb-host40-shell-recovery-r6-20261112/install.py'
NEW = CANDIDATES / 'svb-host40-shell-recovery-r6-installer-r2-20261112/install.py'
AUDIT = Path(__file__).resolve().parent


def load(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def simulate(path, *, uid=0, installed=False):
    with tempfile.TemporaryDirectory(prefix='r6-installer-test-') as temporary:
        root = Path(temporary)
        module = load(path, 'installer_test')
        module.C = root / 'candidate'
        module.C.mkdir()
        for name in ['controller.py', 'install.py', 'runtime.py', 'application.py',
                     'certificate.py', 'recover.tcl.in', 'physical-clock-contract.json',
                     'inputs.json', 'runtime-inputs.json', 'application-inputs.json',
                     'rebind_inputs.py']:
            (module.C / name).write_text('sandbox fixture\n')
        if installed:
            (module.C / 'installation.json').write_text('{}')
        module.W = root / 'work'
        module.D = root / 'experiment'
        module.D.mkdir()
        module.AUDIT = root / 'audit'
        etc = root / 'etc/systemd/system'
        etc.mkdir(parents=True)
        calls = []

        def mapped_path(*args):
            value = Path(*args)
            if value == Path('/etc/systemd/system'):
                return etc
            return value

        def save(path, value):
            path = Path(path)
            assert path.is_relative_to(root), 'sandbox write escaped'
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(json.dumps(value))

        def read(path):
            if Path(path) == module.C / 'inputs.json':
                return {'resource_admission': str(root / 'admission.json')}
            return {'limits': {'cpus': [224, 225], 'min_available_gib': 192,
                               'memory_limit_gib': 64, 'max_component_vivado': 3}}

        controller = SimpleNamespace(
            admitted=lambda: (True, {'sandbox_only': True}),
            SID='source', BASE='baseline', PROFILE='profile',
            FRESULT=root / 'predecessor-result.json',
            FCHECKPOINT=root / 'sealed-source.dcp',
            SLOTLOCK=root / 'shared-slot.lock')
        controller.FRESULT.write_text('{}')
        controller.FCHECKPOINT.write_text('fixture checkpoint')
        module.Path = mapped_path
        module.os = SimpleNamespace(geteuid=lambda: uid,
                                    chown=lambda *args: calls.append(('chown', args)))
        module.subprocess = SimpleNamespace(
            run=lambda argv, **kwargs: calls.append(('subprocess', argv)))
        module.save = save
        module.read = read
        module.sha = digest
        module.now = lambda: 'sandbox-time'
        # Preserve the old validate() return value to reproduce the actual bug.
        module.validate = lambda: controller if path == NEW else None
        original_argv = sys.argv
        sys.argv = [str(path)]
        error = None
        try:
            module.main()
        except Exception as exc:
            error = exc
        finally:
            sys.argv = original_argv
        units = {p.name: p.read_text().replace(str(root), '@SANDBOX@')
                 for p in etc.iterdir()}
        return error, units, calls, module.AUDIT.exists()


def main():
    cases = []
    error, old_units, calls, _ = simulate(OLD)
    assert isinstance(error, NameError) and error.name == 'controller', repr(error)
    assert len(old_units) == 3
    assert not any(kind == 'subprocess' for kind, _ in calls)
    cases.append('original NameError reproduced after three unit writes')

    error, new_units, calls, audit_exists = simulate(NEW)
    assert error is None, repr(error)
    assert new_units == old_units, 'unit specifications changed'
    commands = [argv for kind, argv in calls if kind == 'subprocess']
    assert commands == [
        ['systemctl', 'daemon-reload'],
        ['systemctl', 'enable', '--now',
         'ec-opt4-svb-host40-shell-physical-r6.service',
         'ec-opt4-svb-host40-shell-follow-r6.service',
         'ec-opt4-svb-host40-shell-application-follow-r6.service']]
    assert audit_exists
    cases.append('repaired full installation reaches mocked enable with identical units')

    for options, label in [({'uid': 1008}, 'nonroot install rejected before unit writes'),
                           ({'installed': True}, 'existing installation preserved')]:
        error, units, calls, audit_exists = simulate(NEW, **options)
        assert isinstance(error, AssertionError)
        assert not units and not calls and not audit_exists
        cases.append(label)

    with tempfile.TemporaryDirectory(prefix='r6-pin-test-') as temporary:
        root = Path(temporary)
        module = load(NEW, 'pin_validation_test')
        dependency = root / 'dependency'
        dependency.write_text('changed')
        (root / 'inputs.json').write_text(json.dumps({
            'candidate': str(module.C), 'files': {str(dependency): '0' * 64}}))
        module.DRIVER = root / 'install.py'
        module.subprocess = SimpleNamespace(
            run=lambda *args, **kwargs: (_ for _ in ()).throw(
                AssertionError('unexpected subprocess before pin rejection')))
        try:
            module.validate()
        except AssertionError as exc:
            assert 'installer dependency changed' in str(exc), repr(exc)
        else:
            raise AssertionError('changed dependency accepted')
    cases.append('changed pinned dependency rejected before subprocesses')
    result = {'status': 'PASS', 'cases': cases, 'case_count': len(cases),
              'real_systemctl_calls': 0, 'CAD_jobs_launched': [],
              'FPGA_operations': [], 'original_installer_sha256': digest(OLD),
              'repaired_installer_sha256': digest(NEW)}
    (AUDIT / 'sandbox-validation.json').write_text(
        json.dumps(result, indent=2, sort_keys=True) + '\n')
    print(json.dumps(result))


if __name__ == '__main__':
    main()
