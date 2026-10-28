#!/usr/bin/env python3
"""Offline release checks. No SBT, native compiler, hardware or simulator."""
import copy
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

HERE = Path(__file__).resolve().parent
sys.path[:0] = [str(HERE), str(HERE.parent/'analysis')]
import launch_optimization_3_checker as launch
import opt3_summary as summary
import optimization2_comparison as comparison

ROOT = Path('/data1/gzh/EC')
SCRATCH = Path((ROOT/'AI/TMP/opt3_commit_active_path.txt').read_text().strip()) if (
    ROOT/'AI/TMP/opt3_commit_active_path.txt').is_file() else ROOT/'AI/TMP'
RUN = 'optimization_3_checker_20261028_090640_a56794e2'
DIGEST = 'reviewed-hardware-digest'


class RepeatTests(unittest.TestCase):
    def setUp(self):
        self.root = Path(tempfile.mkdtemp(prefix='release_test_', dir=SCRATCH))
        self.reference = self.root/'runs'/RUN
        self.reference.mkdir(parents=True)
        self.guard = self.reference/'SIMULATION_STARTED.json'
        self.guard.write_text('{"policy":"NO_AUTOMATIC_RETRY"}\n')
        self.manifest = dict(result='SUCCEEDED', exit_status=0, source_digest=DIGEST,
            software=dict(elf_sha256=launch.ELF_SHA, loadmem_sha256=launch.LOADMEM_SHA),
            opt3_summary=dict(validation_status='OBSERVED_CHECKS_PASS',
                              correctness=dict(coverage='COMPLETE')))
        self.save()
        self.override = patch.object(launch, 'OUT', self.root)
        self.override.start()
        self.addCleanup(self.override.stop)

    def save(self):
        (self.reference/'run_manifest.json').write_text(json.dumps(self.manifest))

    def test_default_still_refuses_second_attempt(self):
        with self.assertRaisesRegex(RuntimeError, 'no automatic retry'):
            launch.refuse_second_simulation()

    def test_explicit_success_returns_evidence_without_writing_guard(self):
        before = self.guard.read_bytes()
        result = launch.refuse_second_simulation(RUN, DIGEST)
        self.assertEqual(result['run_id'], RUN)
        self.assertEqual(before, self.guard.read_bytes())
        self.assertEqual(len(list((self.root/'runs').glob('*/SIMULATION_STARTED.json'))), 1)

    def test_failed_reference_is_not_retry_authorization(self):
        self.manifest['result'] = 'FAILED'
        self.save()
        with self.assertRaisesRegex(RuntimeError, 'successful completed'):
            launch.refuse_second_simulation(RUN, DIGEST)

    def test_incomplete_reference_is_refused(self):
        self.manifest['opt3_summary']['correctness']['coverage'] = 'INCOMPLETE'
        self.save()
        with self.assertRaisesRegex(RuntimeError, 'incomplete'):
            launch.refuse_second_simulation(RUN, DIGEST)

    def test_changed_source_is_refused(self):
        with self.assertRaisesRegex(RuntimeError, 'same reviewed hardware'):
            launch.refuse_second_simulation(RUN, 'different-digest')

    def test_changed_workload_is_refused(self):
        self.manifest['software']['elf_sha256'] = 'different-software'
        self.save()
        with self.assertRaisesRegex(RuntimeError, 'workload identity'):
            launch.refuse_second_simulation(RUN, DIGEST)

    def test_newer_failed_attempt_cannot_be_bypassed(self):
        newer = self.root/'runs/optimization_3_checker_20261028_130000_deadbeef'
        newer.mkdir()
        guard = newer/'SIMULATION_STARTED.json'
        guard.write_text('{}')
        ns = self.guard.stat().st_mtime_ns + 1_000_000_000
        os.utime(guard, ns=(ns, ns))
        with self.assertRaisesRegex(RuntimeError, 'latest attempted'):
            launch.refuse_second_simulation(RUN, DIGEST)

    def test_path_traversal_is_refused(self):
        with self.assertRaisesRegex(RuntimeError, 'Invalid'):
            launch.refuse_second_simulation('../'+RUN, DIGEST)

    def test_manifest_change_changes_repetition_identity(self):
        before = launch.refuse_second_simulation(RUN, DIGEST)
        self.manifest['note'] = 'changed during build'
        self.save()
        self.assertNotEqual(before, launch.refuse_second_simulation(RUN, DIGEST))

    def test_short_temp_never_reuses_old_directory(self):
        (self.root/'tmp').mkdir()
        one = launch.short_temporary()
        two = launch.short_temporary()
        self.assertEqual(one.name, 't')
        self.assertEqual(two.name, 'u')
        self.assertTrue(one.is_dir() and two.is_dir())


class AnalysisTests(unittest.TestCase):
    def test_reference_does_not_require_historical_run_directory(self):
        original_read = Path.read_text
        expected = Path(comparison.__file__).with_name('reference_safe_chain_summary.json')
        def read_snapshot_only(path, *args, **kwargs):
            self.assertEqual(path, expected)
            return original_read(path, *args, **kwargs)
        with patch.object(Path, 'read_text', read_snapshot_only):
            reference, before = comparison.load_safe_chain_reference()
        self.assertEqual(reference, expected)
        self.assertEqual(before['pending_cycles'], 3178984)

    def rows(self):
        rows = []
        for h in range(1, 5):
            for t, counts in ((1, [0]*9), (2, [10, 4, 2, 1, 3, 3, 8, 1, 2])):
                rows.append(dict(kind=16, hart=h, time=t, d=[1]+counts+[0]*6))
        return rows

    def test_performance_compares_opt3_to_opt2b(self):
        p = summary.performance_metrics(2928347)
        self.assertEqual(p['opt3_roi'], 2928347)
        self.assertEqual(p['opt2b_roi'], 3760243)
        self.assertEqual(p['incremental_gain_cycles'], 831896)
        self.assertAlmostEqual(p['incremental_gain_percent'], 22.123463829332305)
        self.assertEqual(p['total_gain_vs_original_cycles'], 1806534)

    def test_modes_partition_and_aggregate(self):
        self.assertEqual(summary.classify_opt3(self.rows())['classified'], 40)

    def test_broken_modes_are_refused(self):
        rows = self.rows()
        rows[1]['d'][1] += 1
        with self.assertRaisesRegex(ValueError, 'partition'):
            summary.classify_opt3(rows)

    def test_intermediate_counter_regression_is_refused(self):
        rows = self.rows()
        middle = copy.deepcopy(rows[1])
        middle['time'] = 1.5
        middle['d'][7] += 1
        rows.append(middle)
        with self.assertRaisesRegex(ValueError, 'backwards'):
            summary.classify_opt3(rows)

    def test_actual_socket_path_has_headroom(self):
        path = ROOT/'slowdown/optimization_3_checker/tmp/t/.sbt/sbt-socket-18446744073709551615/sbt-load.sock'
        self.assertEqual(len(os.fsencode(path)), 102)
        self.assertLess(len(os.fsencode(path)), 108)


if __name__ == '__main__':
    unittest.main(verbosity=2)
