"""Focused launcher regression checks. Never invoke a build or simulator."""
import importlib.util
from pathlib import Path
import shutil
import stat
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

ROOT = Path('/data1/gzh/EC/baseline')


def load(name):
    spec = importlib.util.spec_from_file_location(name, ROOT / (name + '.py'))
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


launcher = load('launch_baseline')
checks = load('baseline_preflight')


class InfrastructureChecks(unittest.TestCase):
    def setUp(self):
        self.directory = Path(tempfile.mkdtemp(prefix='launcher_check_', dir=ROOT / 'manifests'))

    def test_exact_coursier_cache_and_baseline_native_identity(self):
        env = launcher.configured_environment()
        result = launcher.sandbox_environment(env, self.directory)
        options = result['JAVA_TOOL_OPTIONS'].split()
        self.assertFalse(any(x.startswith('-Dsbt.coursier.home=') for x in options))
        self.assertIn('-Dcoursier.cache=' + result['COURSIER_CACHE'], options)
        self.assertIn('-Dlog4j2.disable.jmx=true', options)
        self.assertNotIn('', result['LIBRARY_PATH'].split(':'))
        for value in result['CPLUS_INCLUDE_PATH'].split(':'):
            self.assertTrue(Path(value).is_dir())

    def test_source_copy_preserves_modes_and_detects_mode_changes(self):
        original = self.directory / 'original'
        original.mkdir()
        script = original / 'script.py'
        script.write_text('print("not executed")\n')
        script.chmod(0o755)
        destination = self.directory / 'copy'
        shutil.copytree(original, destination, symlinks=True, copy_function=shutil.copy2)
        identity = launcher.copy_identity(destination)
        launcher.verify_copy(destination, identity)
        self.assertEqual(stat.S_IMODE((destination / 'script.py').stat().st_mode), 0o755)
        (destination / 'script.py').chmod(0o644)
        with self.assertRaisesRegex(RuntimeError, 'permissions changed'):
            launcher.verify_copy(destination, identity)

    def test_metadata_copy_excludes_hardware_and_target(self):
        source = self.directory / 'fixture_source'
        for name in ('build.sbt', 'project/plugins.sbt', 'project/Helper.scala',
                     'src/main/scala/Hardware.scala', 'target/old.sbt'):
            path = source / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('// fixture only\n')
        proxy = SimpleNamespace(CHIPYARD=source, sha=launcher.sha,
                                record=launcher.record, fail=launcher.fail)
        destination = checks.metadata_copy(proxy, self.directory)
        self.assertTrue((destination / 'project/Helper.scala').is_file())
        self.assertTrue((destination / 'build.sbt').is_file())
        self.assertFalse((destination / 'src').exists())
        self.assertFalse((destination / 'target').exists())

    def test_static_preflight_collects_multiple_failures(self):
        source = self.directory / 'empty_source'
        source.mkdir()
        env = launcher.configured_environment()
        env['tools'] = {'missing_a': '/does/not/exist/a', 'missing_b': '/does/not/exist/b'}
        with patch.object(launcher, 'SOURCE', source), \
                patch.object(launcher, 'CHIPYARD', source / 'chipyard'), \
                patch.object(launcher, 'source_identity', return_value={}), \
                patch.object(launcher, 'configured_environment', return_value=env), \
                patch.object(sys, 'argv', ['launcher', str(ROOT)]), \
                patch.object(launcher.subprocess, 'Popen', side_effect=AssertionError('subprocess forbidden')):
            with self.assertRaises(RuntimeError) as caught:
                launcher.preflight(1)
        message = str(caught.exception)
        self.assertIn('missing_a', message)
        self.assertIn('missing_b', message)
        self.assertIn('Historical build input missing', message)

    def test_native_failures_do_not_stop_other_checks(self):
        source = self.directory / 'fixture_source'
        for name in ('split-module-files.py', 'split-bb-files.py', 'split-mems-conf.py'):
            p = source / 'scripts' / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text('# fixture, never executed\n')
            p.chmod(0o755)
        invoked = []

        def fake_invoke(command, cwd, log, environment, manifest):
            invoked.append(log.name)
            log.write_text('injected failure\n')
            return 1

        env = launcher.configured_environment()
        proxy = SimpleNamespace(CHIPYARD=source, ROOT=ROOT, sha=launcher.sha,
                                record=launcher.record, invoke=fake_invoke)
        result = checks.native_probe(proxy, self.directory, env['environment'], env, {})
        self.assertEqual(len(invoked), 8)
        self.assertEqual(result['configured_CXX']['status'], 'FAIL')
        self.assertEqual(result['verilator_historical_options']['status'], 'FAIL')
        self.assertEqual(result['source_copy_executable_modes']['status'], 'PASS')


if __name__ == '__main__':
    unittest.main(verbosity=2)
