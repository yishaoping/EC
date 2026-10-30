#!/usr/bin/env python3
"""Offline event fixtures only: never instantiate or run a hardware simulator."""
import importlib.util
from pathlib import Path
import json
import tempfile
import unittest
from collections import Counter

spec = importlib.util.spec_from_file_location('svb_analysis', Path(__file__).parents[1] / 'analysis/analyze_svb.py')
a = importlib.util.module_from_spec(spec)
spec.loader.exec_module(a)


def event(kind, cycle, owner=1, entry=2, first=0, last=0, opcode=None, **changes):
    n = [1, owner, entry if owner else 255, 0x80050000, 15, 6,
         opcode if opcode is not None else (7 if kind in (19, 20, 23) else 6),
         0x123, 0, 1, 0, first, last, 1, 0, 6]
    for name, value in changes.items():
        n[int(name[1:])] = value
    return dict(kind=kind, cycle=cycle, time=cycle, episode=1, hart=0, nums=n)


def stats(cycle=40, issued=1, acks=1, svb_issued=1, svb_acks=1, outstanding=0):
    e = event(25, cycle)
    e['nums'] = [1] + [0] * 15
    for i, value in ((6, issued), (7, acks), (13, svb_issued), (14, svb_acks), (8, outstanding)):
        e['nums'][i] = value
    return e


def svb_sequence(start=1):
    return [event(19, start), event(20, start+2, first=1),
            event(20, start+5, last=1), event(21, start+25), event(22, start+26)]


class ProtocolTests(unittest.TestCase):
    def analyze(self, rows, stdout='', roi=None, footers=True):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d)
            text = ''
            for r in rows:
                text += '\t'.join(map(str, ['SC1', r['time'], r['cycle'], r['cycle'],
                                            r['episode'], r['kind'], r['hart']]))
                text += '\t' + '\t'.join(f'{n:016x}' for n in r['nums']) + '\n'
            if footers:
                for (kind, hart), count in Counter((r['kind'], r['hart']) for r in rows).items():
                    text += f'SC_END\t99\t99\t99\t1\t{kind}\t{hart}\t{count}\n'
            (p / 'safe_chain_events.tsv').write_text(text)
            (p / 'stdout.log').write_text(stdout)
            (p / 'roi.json').write_text(json.dumps(roi or {}))
            return a.run_summary(p)

    def test_delayed_ack_and_normal_eviction_share_source(self):
        rows = svb_sequence() + [event(20, 29, owner=0, first=1),
                                event(20, 30, owner=0, last=1),
                                event(21, 39, owner=0), stats(issued=2, acks=2)]
        p = self.analyze(rows)['protocol']
        self.assertEqual(p['status'], 'PASS')
        self.assertEqual((p['releases_issued'], p['release_acks_matched'], p['svb_completions']), (2, 2, 1))

    def test_multibeat_source_is_not_free_on_last_c(self):
        rows = svb_sequence()[:3] + [event(20, 8, owner=0, first=1), stats()]
        self.assertEqual(self.analyze(rows)['protocol']['status'], 'FAIL')

    def test_wrong_ack_source_opcode_key_size(self):
        for index, value in ((5, 7), (6, 4), (7, 0x456), (15, 5)):
            with self.subTest(index=index):
                rows = svb_sequence() + [stats()]
                rows[3]['nums'][index] = value
                p = self.analyze(rows)['protocol']
                self.assertEqual(p['status'], 'FAIL')
                self.assertEqual(p['invalid_ack'], 1)

    def test_ack_before_final_c_beat(self):
        rows = [event(19, 1), event(20, 2, first=1), event(21, 3), stats()]
        self.assertEqual(self.analyze(rows)['protocol']['invalid_ack'], 1)

    def test_duplicate_ack_or_completion(self):
        for kind in (21, 22):
            with self.subTest(kind=kind):
                self.assertEqual(self.analyze(svb_sequence() + [event(kind, 35), stats()])['protocol']['status'], 'FAIL')

    def test_pending_retained_is_not_full_drain(self):
        p = self.analyze(svb_sequence()[:3] + [stats(acks=0, svb_acks=0, outstanding=1)])
        self.assertEqual(p['protocol']['status'], 'PENDING_RETAINED')
        self.assertTrue(p['protocol']['svb_entry_retained_at_end'])
        self.assertFalse(p['performance_valid'])

    def test_missing_stats_and_footer_cannot_pass(self):
        self.assertEqual(self.analyze(svb_sequence())['protocol']['status'], 'UNOBSERVED')
        self.assertEqual(self.analyze(svb_sequence() + [stats()], footers=False)['protocol']['status'], 'FAIL')

    def test_frontend_hart16_is_not_svb(self):
        e = event(16, 5)
        e['hart'] = 1
        p = self.analyze([e])
        self.assertIsNone(p['svb']['allocations'])
        self.assertEqual(p['observer_status'], 'UNKNOWN_FROM_MISSING_SVB_EVENT')

    def test_performance_requires_protocol_and_benchmark(self):
        stdout = '[RUN] benchmark=gapbs_bfs nodes=512 verified=1\n[COMPUTATION] status=PASS scope=bfs\n[END] hart=0 status=PASS\n'
        p = self.analyze(svb_sequence() + [stats()], stdout, {'safe_chain_roi_cycles': 2000000})
        self.assertTrue(p['performance_valid'])
        self.assertFalse(self.analyze(svb_sequence() + [stats()], '', {'roi_cycles': 2000000})['performance_valid'])

    def test_stop_counter_and_same_edge_boundary(self):
        self.assertEqual(self.analyze([stats()])['protocol']['status'], 'FAIL')
        rows = [event(19, 1), event(20, 2, first=1, last=1), event(21, 3), event(22, 4),
                stats(cycle=2, issued=0, acks=0, svb_issued=0, svb_acks=0)]
        self.assertEqual(self.analyze(rows)['protocol']['status'], 'PASS')

    def test_single_beat_release_and_wrong_entry_completion(self):
        rows = [event(19, 1), event(20, 2, first=1, last=1), event(21, 3), event(22, 4), stats()]
        self.assertEqual(self.analyze(rows)['protocol']['status'], 'PASS')
        rows[3]['nums'][2] = 3
        self.assertEqual(self.analyze(rows)['protocol']['status'], 'FAIL')


if __name__ == '__main__':
    unittest.main()
