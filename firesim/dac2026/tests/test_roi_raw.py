"""Synthetic temporary raw-log parsing only, never target or benchmark execution."""
import importlib.util
import json
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('inspect_roi_raw', Path(__file__).parents[1]/'scripts/inspect_roi_raw.py')
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


def record(seq, state, epoch=1, tick=None, **extra):
    value = {'schema': module.SCHEMA, 'configuration': 'B', 'formal_sample': False,
             'synthetic': False, 'timebase_verified': False, 'runtime_validated': False,
             'sequence': seq, 'under_reset': 0, 'state_transition': 1, 'epoch': epoch,
             'state': state, 'source_boom_tick': 100+seq if tick is None else tick,
             'roi_begin_tick': 0 if state == 1 else 100,
             'roi_end_tick': 102 if state in (3, 4) else 0, 'faults': 0}
    value.update(extra)
    return json.dumps(value).encode()+b'\n'


class RawLogInspection(unittest.TestCase):
    def test_complete_boundary_still_cannot_become_formal_sample(self):
        result = module.inspect_bytes(b''.join(record(i, s) for i, s in enumerate([1, 2, 3, 4])))
        self.assertEqual(result['protocol_issues'], [])
        self.assertTrue(result['epochs'][0]['source_boundaries_complete'])
        self.assertEqual(result['epochs'][0]['roi_cycles'], 2)
        self.assertFalse(result['formal_sample_eligible'])

    def test_partial_drain_does_not_count_as_complete(self):
        result = module.inspect_bytes(record(0, 1)+record(1, 2)+record(2, 3)+record(3, 4)[:40])
        self.assertEqual(result['parsed_records'], 3)
        self.assertGreater(result['partial_tail_bytes'], 0)
        self.assertFalse(result['epochs'][0]['source_boundaries_complete'])

    def test_missing_sequence_bad_timestamp_or_non_integer_rejected(self):
        for raw in [record(0, 1)+record(2, 2), record(0, 1)+record(1, 3, roi_end_tick=99),
                    record(0, 1, source_boom_tick=2.0), record(0, 1)+record(1, 2, epoch=0)]:
            with self.subTest(raw=raw):
                self.assertTrue(module.inspect_bytes(raw)['protocol_issues'])

    def test_abort_and_failure_invalidate_boundaries(self):
        for ending in [record(2, 0), record(2, 3, faults=1)+record(3, 4, faults=1)]:
            result = module.inspect_bytes(record(0, 1)+record(1, 2)+ending)
            self.assertFalse(result['epochs'][0]['source_boundaries_complete'])

    def test_uint64_source_ticks_keep_exact_precision(self):
        n = 2**60
        raw = b''.join(record(i, s, tick=n+i, roi_begin_tick=n,
                            roi_end_tick=n+2 if s in (3, 4) else 0)
                       for i, s in enumerate([1, 2, 3, 4]))
        self.assertEqual(module.inspect_bytes(raw)['epochs'][0]['roi_cycles'], 2)


if __name__ == '__main__':
    unittest.main()
