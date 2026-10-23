"""Focused launcher regression checks. Never invoke a build or simulator."""
import importlib.util
import copy
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
resources = load('source_resource_audit')
runtime_checks = load('runtime_io_probe')


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

    def test_resource_metadata_preserves_internal_and_optional_dangling_links(self):
        source = self.directory / 'fixture_source'
        resource_dir = source / 'generators/cva6/src/main/resources'
        resource_dir.mkdir(parents=True)
        (resource_dir / 'data.txt').write_text('fixture\n')
        (resource_dir / 'valid_link').symlink_to('data.txt')
        (resource_dir / 'optional_missing_link').symlink_to('missing.txt')
        proxy = SimpleNamespace(CHIPYARD=source, SOURCE=launcher.SOURCE,
                                ROOT=ROOT, REV=launcher.REV, inside=launcher.inside,
                                read_json=launcher.read_json, sha=launcher.sha,
                                record=launcher.record, fail=launcher.fail,
                                resource_checks=lambda: resources)
        destination = checks.metadata_copy(proxy, self.directory, resources=True)
        copied = destination / resource_dir.relative_to(source)
        self.assertEqual((copied / 'valid_link').read_text(), 'fixture\n')
        self.assertTrue((copied / 'optional_missing_link').is_symlink())
        self.assertFalse((copied / 'optional_missing_link').exists())

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

    def test_historical_omissions_are_all_reported_before_hardware(self):
        report = resources.inventory(launcher.CHIPYARD)
        self.assertEqual({x['resource'] for x in report['missing']}, {
            '/vsrc/plusarg_reader.v', '/vsrc/SimJTAG.v',
            '/vsrc/ClockDivider2.v', '/vsrc/ClockDivider3.v', '/vsrc/EICG_wrapper.v'})
        restored = resources.checked_inventory(launcher)
        self.assertEqual(restored['status'], 'PASS')
        self.assertEqual(restored['missing'], [])
        self.assertEqual(restored['unreviewed_dynamic'], [])

    def test_resource_names_are_exact_and_comments_ignored(self):
        source = self.directory / 'fixture'
        scala = source / 'generators/rocket-chip/src/main/scala/Fixture.scala'
        scala.parent.mkdir(parents=True)
        scala.write_text('// addResource("/ignored.v")\n'
                         'addResource("/vsrc/missing_a.v")\n'
                         '/* addResource("/ignored2.v") */\n'
                         'addResource("/vsrc/missing_b.v")\n')
        wrong = source / 'generators/rocket-chip/src/main/resources/wrong/missing_a.v'
        wrong.parent.mkdir(parents=True)
        wrong.write_text('// incorrect classpath directory\n')
        missing = {x['resource'] for x in resources.inventory(source)['missing']}
        self.assertIn('/vsrc/missing_a.v', missing)
        self.assertIn('/vsrc/missing_b.v', missing)
        self.assertNotIn('/ignored.v', missing)
        self.assertNotIn('/ignored2.v', missing)

    def test_restoration_is_only_in_fresh_copy_and_collision_fails(self):
        destination = self.directory / 'execution_chipyard'
        identity = resources.apply_restoration(launcher, destination)
        copied = launcher.copy_identity(destination)
        self.assertEqual(len(copied), identity['file_count'])
        launcher.verify_copy(destination, copied)
        with self.assertRaisesRegex(RuntimeError, 'collision'):
            resources.apply_restoration(launcher, destination)
        with self.assertRaisesRegex(RuntimeError, 'canonical'):
            resources.apply_restoration(launcher, launcher.CHIPYARD)

    def test_corrupt_overlay_blocks_before_any_child_process(self):
        config = copy.deepcopy(launcher.read_json(ROOT / 'resource_restoration.json'))
        damaged = self.directory / 'damaged.v'
        damaged.write_text('deliberately damaged test payload\n')
        config['files'][0]['payload'] = str(damaged.relative_to(ROOT))
        with patch.object(launcher, 'read_json', return_value=config), \
                patch.object(launcher.subprocess, 'Popen', side_effect=AssertionError('child process forbidden')):
            with self.assertRaisesRegex(RuntimeError, 'payload missing/corrupt'):
                resources.restored_inputs(launcher)

    def test_changed_dynamic_reference_is_not_silently_approved(self):
        report = resources.inventory(launcher.CHIPYARD)
        report['dynamic'][0]['source_sha256'] = 'changed'
        with patch.object(resources, 'inventory', return_value=report):
            checked = resources.checked_inventory(launcher)
        self.assertEqual(checked['status'], 'FAIL')
        self.assertEqual(len(checked['unreviewed_dynamic']), 1)

    def test_actual_copy_detects_resource_corruption_and_missing_scala(self):
        source = self.directory / 'execution_fixture'
        scala = source / 'generators/rocket-chip/src/main/scala/Fixture.scala'
        scala.parent.mkdir(parents=True)
        scala.write_text('addResource("/vsrc/EICG_wrapper.v")\n')
        resource = source / 'generators/rocket-chip/src/main/resources/vsrc/EICG_wrapper.v'
        resource.parent.mkdir(parents=True)
        resource.write_text('// fixture, never compiled\n')
        expected = resources.inventory(source)
        with patch.object(resources, 'checked_inventory', return_value=expected):
            resources.verify_execution_inputs(launcher, source)
            resource.write_text('// corrupted fixture\n')
            with self.assertRaisesRegex(RuntimeError, 'execution-copy resources differ'):
                resources.verify_execution_inputs(launcher, source)
            resource.write_text('// fixture, never compiled\n')
            scala.unlink()
            with self.assertRaisesRegex(RuntimeError, 'execution-copy resources differ'):
                resources.verify_execution_inputs(launcher, source)

    def test_failure_summary_surfaces_saved_blackbox_cause(self):
        log = self.directory / 'failure.log'
        log.write_text('[info] regular output\n' * 100 +
                       "[error] firrtl.transforms.BlackBoxNotFoundException: BlackBox '/vsrc/plusarg_reader.v' not found.\n" +
                       'make: *** [firrtl] Error 1\n')
        excerpt = resources.failure_summary(log)
        self.assertTrue(any('BlackBoxNotFoundException' in x['text'] and
                            'plusarg_reader.v' in x['text'] for x in excerpt))

    def test_real_sandbox_supports_libc_tmpfile_mmap_and_preserves_isolation(self):
        temporary = self.directory / 'private_tmp'
        temporary.mkdir(mode=0o700)
        environment = launcher.sandbox_environment(launcher.configured_environment(), temporary)
        host_tmp = {p: (Path(p).stat().st_dev, Path(p).stat().st_ino)
                    for p in ('/tmp', '/var/tmp')}
        manifest = {'commands': []}
        result = launcher.runtime_io_probe(self.directory, environment, manifest)
        self.assertEqual(result['return_code'], 0)
        report = result['checks']
        self.assertEqual(report['status'], 'PASS')
        self.assertEqual(report['checks']['libc_tmpfile_and_mmap']['detail']
                         ['simultaneous_libc_tmpfiles'], 4)
        self.assertEqual(report['checks']['mount_isolation']['detail']
                         ['current_and_canonical_source'], 'READ_ONLY')
        self.assertEqual(list(temporary.iterdir()), [])
        self.assertEqual(host_tmp, {p: (Path(p).stat().st_dev, Path(p).stat().st_ino)
                                    for p in host_tmp})

    def test_unsafe_tmpdir_rejected_before_child_process(self):
        environment = launcher.sandbox_environment(launcher.configured_environment(), self.directory)
        for path in ('/tmp', str(launcher.SOURCE)):
            environment['TMPDIR'] = path
            with patch.object(launcher.subprocess, 'Popen', side_effect=AssertionError('child forbidden')):
                with self.assertRaises(RuntimeError):
                    launcher.invoke(['/bin/true'], self.directory, self.directory / 'never.log',
                                    environment, {'commands': []})

    def test_native_io_failure_is_fatal_and_keeps_probe_diagnostics(self):
        manifest = {'commands': []}

        def failed_probe(command, cwd, log, environment, description):
            launcher.record(log, {'status': 'FAIL', 'error': 'injected libc tmpfile EROFS'})
            return 1

        with patch.object(launcher, 'invoke', side_effect=failed_probe) as invoked:
            with self.assertRaisesRegex(RuntimeError, 'Runtime temporary-file/waveform I/O preflight failed'):
                launcher.runtime_io_probe(self.directory, {}, manifest)
        self.assertEqual(invoked.call_count, 1)
        self.assertIn('runtime_io_probe.py', invoked.call_args.args[0][-1])
        self.assertEqual(manifest['runtime_io']['return_code'], 1)
        self.assertEqual(launcher.read_json(manifest['runtime_io']['log'])['status'], 'FAIL')

    def test_runtime_probe_refuses_native_io_outside_sandbox(self):
        with patch.dict(runtime_checks.os.environ, {'TMPDIR': str(self.directory)}), \
                patch.object(runtime_checks.ctypes, 'CDLL', side_effect=AssertionError('native I/O forbidden')), \
                patch.object(runtime_checks.tempfile, 'TemporaryDirectory',
                             side_effect=AssertionError('file creation forbidden')):
            report = runtime_checks.probe()
        self.assertEqual(report['status'], 'FAIL')
        self.assertEqual(report['checks']['mount_isolation']['status'], 'FAIL')
        self.assertEqual(report['checks']['libc_tmpfile_and_mmap']['status'], 'SKIPPED_ISOLATION_FAILED')
        self.assertEqual(report['checks']['waveform_directory_io']['status'], 'SKIPPED_ISOLATION_FAILED')

    def write_run_fixture(self, malformed_roi=False):
        contract = launcher.common_contract()
        descriptor = {'schema': 2, 'required_pass_patterns': contract.PASS_PATTERNS,
                      'failure_patterns': contract.FAILURE_PATTERNS, 'name': 'fixture',
                      'elf_sha256': 'fixture-only'}
        lines = ['[INIT] checker_mask=0xf status=ready',
                 '[COMPUTATION] status=PASS scope=amo_w_and_bfs_result',
                 '[END] hart=0 status=PASS',
                 '[COMPLETION] checker_software_ready=4 cache_drain=UNRESOLVED',
                 '[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728',
                 '[ROI] hart=0 start=181025 stop=1182700 cycles=' +
                 ('1' if malformed_roi else '1001675')]
        (self.directory / 'stdout.log').write_text('\n'.join(lines) + '\n')
        (self.directory / 'stderr.log').write_text('*** PASSED *** Completed after 1200611 cycles\n')
        return descriptor

    def test_empty_waveform_fails_run_but_preserves_roi_and_harness_success(self):
        descriptor = self.write_run_fixture()
        build = self.directory / 'build'
        build.mkdir()
        launcher.record(build / 'manifest.json', {'fixture': True})
        elf = self.directory / 'fixture.elf'
        elf.write_bytes(b'\x7fELFfixture, never executed')
        run_dir = self.directory / 'run'
        run_dir.mkdir()
        bm = {'simulator_sha256': 'fixture-only', 'generated_identity_sha256': 'fixture-only',
              'execution_chipyard': str(build)}

        def fake_invoke(command, cwd, log, environment, manifest, stdout_log, stderr_log):
            shutil.copyfile(self.directory / 'stdout.log', stdout_log)
            shutil.copyfile(self.directory / 'stderr.log', stderr_log)
            log.write_bytes(b'fixture only\n')
            (cwd / 'test.fst').touch()
            return 0

        args = SimpleNamespace(seed=1, max_cycles=500000000)
        with patch.object(launcher, 'verified_build', return_value=(build, bm, build / 'never-executed')), \
                patch.object(launcher.tempfile, 'mkdtemp', return_value=str(run_dir)), \
                patch.object(launcher, 'runtime_io_probe', return_value={'status': 'PASS_FIXTURE_ONLY'}), \
                patch.object(launcher, 'version_records', return_value={}), \
                patch.object(launcher, 'invoke', side_effect=fake_invoke):
            with self.assertRaisesRegex(RuntimeError, 'Missing/empty required FST'):
                launcher.run(args, build, (descriptor, [('elf', str(elf), launcher.sha(elf))]),
                             {'status': ''}, launcher.configured_environment())
        saved = launcher.read_json(run_dir / 'run_manifest.json')
        self.assertEqual(saved['result'], 'FAILED')
        self.assertTrue(saved['process_and_marker_success'])
        self.assertEqual(saved['ROI_cycles'], 1001675)
        self.assertEqual(saved['harness_cycles'], 1200611)
        self.assertEqual(saved['waveform_status'], 'MISSING_OR_EMPTY')
        self.assertEqual(saved['RUN_PROVENANCE'], 'UNRESOLVED')
        self.assertEqual(saved['complete_experiment_success'], 'UNRESOLVED_REQUIRES_CORRECTNESS_REVIEW')

    def test_log_parser_rejects_bad_roi_and_process_failure_independently(self):
        descriptor = self.write_run_fixture(malformed_roi=True)
        observed = launcher.observe_run_logs(self.directory, descriptor, 0)
        self.assertTrue(observed['process_and_marker_success'])
        self.assertIn('software_roi_error', observed)
        self.assertNotIn('ROI_cycles', observed)
        descriptor = self.write_run_fixture()
        with (self.directory / 'stderr.log').open('a') as stream:
            stream.write('*** FAILED *** assertion fixture\n')
        observed = launcher.observe_run_logs(self.directory, descriptor, 1)
        self.assertFalse(observed['process_and_marker_success'])
        self.assertEqual(observed['ROI_cycles'], 1001675)
        self.assertTrue(observed['failure_marker_seen'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
