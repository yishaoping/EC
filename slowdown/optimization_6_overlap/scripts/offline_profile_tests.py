#!/usr/bin/env python3
"""Regression contracts for counter identity, clock units and censored samples."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

spec = importlib.util.spec_from_file_location('profile', Path(__file__).with_name('profile_checkers.py'))
profile = importlib.util.module_from_spec(spec); spec.loader.exec_module(profile)


def event(kind, cycle, nums):
    return dict(kind=kind, hart=1, time=cycle+100, cycle=cycle,
                nums=nums+[0]*(16-len(nums)))


class ProfileTests(unittest.TestCase):
    def run_profile(self, rows):
        with tempfile.TemporaryDirectory() as tmp:
            run=Path(tmp)
            (run/'roi.json').write_text(json.dumps(dict(start_cycle=100, stop_cycle=1000)))
            with patch.object(profile.stable, 'parse_events', return_value=rows):
                return profile.profile(run)

    def rows(self):
        return [event(11, 110, [9,0,128,0]),
                event(11, 200, [9,1,192,10,4,6]),
                event(11, 300, [9,2,227,20,8,12]+[0]*7+[8,0,0]),
                # Local timestamps are deliberately unrelated to BOOM cycle.
                event(12, 300, [9,2,227,10000,10002,10016,10021,0,0,0,0,12,0,0,8,0])]

    def test_epoch_changes_stay_one_owner_and_lifecycle_uses_local_differences(self):
        report=self.run_profile(self.rows())
        self.assertEqual(report['harts'][0]['fully_captured_packages'],1)
        p=report['packages'][0]
        self.assertEqual(p['observed_epochs'],[0,1,2])
        self.assertEqual(p['local_exec_cycles'],20)
        self.assertEqual(p['lifecycle_local_cycles']['admission_to_start'],2)
        self.assertEqual(p['lifecycle_local_cycles']['admission_to_exec_done'],21)

    def test_missing_start_or_terminal_is_excluded_instead_of_zero_filled(self):
        for rows in (self.rows()[1:],self.rows()[:2]):
            report=self.run_profile(rows)
            self.assertEqual(report['harts'][0]['fully_captured_packages'],0)
            self.assertEqual(report['excluded']['missing_start_or_result'],1)

    def test_counter_decrease_rejects_mixed_or_corrupted_owner(self):
        rows=self.rows();rows[1]['nums'][4]=9;rows[1]['nums'][5]=1
        with self.assertRaises(ValueError):
            self.run_profile(rows)

    def test_nonzero_initial_raw_count_is_not_an_exact_start(self):
        rows=self.rows();rows[0]['nums'][13]=1
        with self.assertRaises(ValueError):
            self.run_profile(rows)


if __name__=='__main__':
    unittest.main(verbosity=2)
