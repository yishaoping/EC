#!/usr/bin/env python3
"""Offline checks for the single-A guard and bounded host accounting overlay."""
from copy import deepcopy
import importlib.util
from pathlib import Path
import unittest
import uuid

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('refresh', HERE / 'launch_checker_seq67_baseline_refresh.py')
refresh = importlib.util.module_from_spec(spec)
spec.loader.exec_module(refresh)


class RefreshTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.out = HERE.parents[1] / 'TMP' / ('seq67_A_refresh_cpu_tests_' + uuid.uuid4().hex)
        cls.out.mkdir(parents=True)
        cls.original = refresh.module('original_capture', refresh.CAPTURE)
        code = refresh.CAPTURE.read_text().replace('len(self.observers) >= 128',
            'len(self.observers) >= 256').replace('len(self.producers) >= 128', 'len(self.producers) >= 256')
        overlay = cls.out / 'compact_capture.py'
        overlay.write_text(code)
        cls.overlay = refresh.module('overlay_capture', overlay)
        cls.contract = dict(run_target='A_PRIME_ONLY_32K_2WAY', number_of_full_runs_requested=1,
                            automatic_retry=False)

    def test_A_allowed(self):
        refresh.validate_target(self.contract, 'A')

    def test_B_rejected(self):
        with self.assertRaises(ValueError): refresh.validate_target(self.contract, 'B')

    def test_two_runs_rejected(self):
        c = dict(self.contract, number_of_full_runs_requested=2)
        with self.assertRaises(ValueError): refresh.validate_target(c, 'A')

    def test_retry_rejected(self):
        c = dict(self.contract, automatic_retry=True)
        with self.assertRaises(ValueError): refresh.validate_target(c, 'A')

    def test_second_claim_rejected(self):
        directory = self.out / uuid.uuid4().hex
        directory.mkdir()
        refresh.claim_once(directory)
        with self.assertRaises(FileExistsError): refresh.claim_once(directory)

    def test_existing_run_rejected_without_claim(self):
        directory = self.out / uuid.uuid4().hex
        run = directory / 'sealed/arms/A/runs/existing'
        run.mkdir(parents=True)
        (run / 'run_manifest.json').write_text('{}')
        with self.assertRaises(ValueError): refresh.claim_once(directory)
        self.assertFalse((directory / 'A_PRIME_LAUNCH_CLAIM.json').exists())

    def test_capture_budget_and_classification_unchanged(self):
        self.assertEqual(self.overlay.budget_contract(), self.original.budget_contract())
        self.assertTrue(all(self.overlay.optional_event(k, h) == self.original.optional_event(k, h)
                            for k in range(256) for h in range(5)))

    def make_capture(self, implementation, count):
        directory = self.out / uuid.uuid4().hex
        directory.mkdir()
        router = implementation.Router(directory)
        for h in range(count):
            router.line(('\t'.join(['SC1', '1', '1', '1', '1', '20', str(h)] + ['0' * 16] * 16) + '\n').encode(), 1)
            router.line(f'SC_END\t2\t2\t2\t1\t20\t{h}\t1\n'.encode(), 1)
            router.line(f'SC_LOG_STATS\t20\t{h}\t1\t1\t0\t200000\n'.encode(), 1)
        return router.close()

    def test_133_identities_pass_without_other_bucket(self):
        stats = self.make_capture(self.overlay, 133)
        self.assertTrue(stats['mandatory_evidence_complete'])
        self.assertEqual(len(stats['observers']), 133)
        self.assertEqual(len(stats['producers']), 133)
        self.assertNotIn('other', stats['observers'])

    def test_original_cap_reproduces_failure(self):
        stats = self.make_capture(self.original, 133)
        self.assertFalse(stats['mandatory_evidence_complete'])
        self.assertIn('too_many_observer_identities', stats['incomplete_reasons'])

    def test_new_cap_remains_bounded(self):
        stats = self.make_capture(self.overlay, 257)
        self.assertFalse(stats['mandatory_evidence_complete'])
        self.assertEqual(len(stats['producers']), 256)


if __name__ == '__main__':
    unittest.main()
