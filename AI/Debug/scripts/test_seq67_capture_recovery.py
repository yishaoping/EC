#!/usr/bin/env python3
"""CPU-only negative evidence tests; no simulator or source generation."""
from copy import deepcopy
import importlib.util
import json
from pathlib import Path
import unittest
import uuid

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('recovery', HERE / 'recover_seq67_capture.py')
recovery = importlib.util.module_from_spec(spec)
spec.loader.exec_module(recovery)


class RecoveryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.out = HERE.parents[1] / 'TMP' / ('seq67_capture_cpu_tests_' + uuid.uuid4().hex)
        cls.out.mkdir(parents=True)
        optional = {'4:3', '4:4', '5:2', '5:3', '5:4'}
        keys = sorted(recovery.RECOVERABLE | optional | {f'20:{h}' for h in range(123)})
        cls.lines = []
        obs = {}
        prod = {}
        for key in keys:
            kind, hart = key.split(':')
            cls.lines.extend(['\t'.join(['SC1', '1', '1', '1', '1', kind, hart] + ['0' * 16] * 16) + '\n',
                              '\t'.join(['SC_END', '2', '2', '2', '1', kind, hart, '1']) + '\n'])
            if key not in recovery.RECOVERABLE:
                obs[key] = dict(seen=2, kept=2, omitted=0, events_seen=1,
                                footers_seen=1, footer_emitted_count=1)
            if key not in optional:
                prod[key] = dict(produced=1, emitted=1, omitted=0, limit=200000)
        obs['other'] = dict(seen=10, kept=10, omitted=0, events_seen=5,
                            footers_seen=5, footer_emitted_count=1)
        cls.capture = dict(schema=2, policy='priority_reserved_v2', closed=True,
                           incomplete_reasons=sorted(recovery.REASONS),
                           observers=obs, producers=prod, counts={})

    def invoke(self, capture=None, lines=None):
        path = self.out / (uuid.uuid4().hex + '.tsv')
        path.write_text(''.join(self.lines if lines is None else lines))
        return recovery.recover(deepcopy(self.capture) if capture is None else capture, path)

    def test_lossless_deaggregation_retains_unknown_optional_stats(self):
        derived, audit = self.invoke()
        self.assertTrue(derived['mandatory_evidence_complete'])
        self.assertFalse(derived['optional_evidence_complete'])
        self.assertEqual(len(derived['observers']), 133)
        self.assertEqual(len(derived['producers']), 128)
        self.assertEqual(len(audit['unknown_optional_producer_statistics']), 5)

    def test_missing_mandatory_event_is_rejected(self):
        lines = list(self.lines)
        lines.pop(next(i for i, line in enumerate(lines) if line.startswith('SC1\t') and '\t31\t0\t' in line))
        with self.assertRaises(ValueError): self.invoke(lines=lines)

    def test_missing_footer_is_rejected(self):
        lines = list(self.lines)
        lines.pop(next(i for i, line in enumerate(lines) if line.startswith('SC_END\t') and '\t31\t0\t' in line))
        with self.assertRaises(ValueError): self.invoke(lines=lines)

    def test_duplicate_footer_is_rejected(self):
        with self.assertRaises(ValueError): self.invoke(lines=self.lines + [self.lines[-1]])

    def test_mandatory_producer_omission_is_rejected(self):
        capture = deepcopy(self.capture)
        capture['producers']['31:0'].update(produced=2, omitted=1)
        with self.assertRaises(ValueError): self.invoke(capture)

    def test_mandatory_producer_statistics_required(self):
        capture = deepcopy(self.capture)
        capture['producers']['20:0'] = capture['producers'].pop('31:0')
        with self.assertRaises(ValueError): self.invoke(capture)

    def test_unrelated_failure_cannot_be_cleared(self):
        capture = deepcopy(self.capture)
        capture['incomplete_reasons'].append('protocol_budget_exhausted')
        with self.assertRaises(ValueError): self.invoke(capture)

    def test_runtime_failure_cannot_be_cleared(self):
        capture = deepcopy(self.capture)
        capture['counts']['failure_markers_seen'] = 1
        with self.assertRaises(ValueError): self.invoke(capture)

    def test_changed_other_bucket_is_rejected(self):
        capture = deepcopy(self.capture)
        capture['observers']['other']['omitted'] = 1
        with self.assertRaises(ValueError): self.invoke(capture)

    def test_malformed_record_is_rejected(self):
        with self.assertRaises(ValueError): self.invoke(lines=self.lines + ['SC1\tbroken\n'])


if __name__ == '__main__':
    unittest.main()
