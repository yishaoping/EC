#!/usr/bin/env python3
"""Budget adversaries and saved-record fixtures; never run a hardware simulator."""
from collections import Counter
import contextlib
import importlib.util
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

HERE = Path(__file__).resolve().parent


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


c = module('budget_capture', HERE/'compact_capture.py')
a = module('budget_analysis', HERE.parent/'analysis/analyze_svb.py')
fixtures = module('budget_fixtures', HERE/'offline_capacity_cache_tests.py')
p = fixtures.p


def record(row):
    header = ['SC1', row['time'], row['cycle'], row['cycle'], row['episode'], row['kind'], row['hart']]
    return ('\t'.join(map(str, header))+'\t'+'\t'.join(f'{n:016x}' for n in row['nums'])+'\n').encode()


def finals(kind, hart, emitted, omitted=0):
    return (f'SC_END\t99\t99\t99\t1\t{kind}\t{hart}\t{emitted}\n'
            f'SC_LOG_STATS\t{kind}\t{hart}\t{emitted+omitted}\t{emitted}\t{omitted}\t200000\n').encode()


SUCCESS = (b'[ROI] hart=0 start=1 stop=2000001 cycles=2000000\n'
           b'[RUN] benchmark=gapbs_bfs verified=1 parent_checksum=43439728\n'
           b'[COMPUTATION] status=PASS\n[END] hart=0 status=PASS\n')


class BudgetTests(unittest.TestCase):
    def router(self, **kwargs):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        path = Path(temporary.name)
        router = c.Router(path, **kwargs)
        self.addCleanup(router.close)
        return path, router

    def test_fixed_48mib_reservations_and_56mib_total(self):
        contract = c.budget_contract()
        self.assertEqual(sum(contract['event_budgets'].values()), 48*1024**2)
        self.assertEqual(contract['total_stream_limit_bytes'], 56*1024**2)
        self.assertEqual(contract['event_budgets'],
                         dict(protocol=39*1024**2, diagnostic=8*1024**2, summary=1024**2))

    def test_optional_flood_preserves_protocol_footers_and_success(self):
        path, router = self.router(event_limit=8192, diagnostic_limit=1024)
        for _ in range(1000):router.feed(record(p.event(15, 1)), 1)
        router.feed(record(p.event(20, 2))+finals(20, 0, 1)+finals(15, 0, 1000), 1)
        router.feed(SUCCESS, 0)
        stats = router.close()
        self.assertTrue(stats['mandatory_evidence_complete'])
        self.assertFalse(stats['optional_evidence_complete'])
        self.assertGreater(stats['optional_records_omitted'], 900)
        self.assertEqual(stats['observers']['20:0']['omitted'], 0)
        self.assertIn(b'[END] hart=0 status=PASS', (path/'stdout.log').read_bytes())
        self.assertEqual(a.capture_evidence(path, True)['status'], 'PASS')
        self.assertLessEqual(stats['sizes']['safe_chain_events.tsv'], 8192)

    def test_mandatory_flood_drains_but_rejects_evidence(self):
        path, router = self.router(event_limit=8192, diagnostic_limit=1024)
        for _ in range(100):router.feed(record(p.event(20, 1)), 1)
        router.feed(finals(20, 0, 100), 1)
        router.feed(SUCCESS, 0)
        stats = router.close()
        self.assertFalse(stats['mandatory_evidence_complete'])
        self.assertIn('protocol_budget_exhausted', stats['incomplete_reasons'])
        self.assertIn(b'[END] hart=0 status=PASS', (path/'stdout.log').read_bytes())
        self.assertEqual(a.capture_evidence(path, True)['status'], 'FAIL')

    def test_producer_omission_is_optional_only_for_examples(self):
        for kind, complete in ((15, True), (20, False), (31, False)):
            with self.subTest(kind=kind):
                path, router = self.router()
                router.feed(record(p.event(kind, 1)), 1)
                router.feed(f'SC_LIMIT\t{kind}\t0\t1\t1\t{int(not c.optional_event(kind, 0))}\n'.encode(), 1)
                router.feed(finals(kind, 0, 1, omitted=7), 1)
                self.assertEqual(router.close()['mandatory_evidence_complete'], complete)
                self.assertEqual(a.capture_evidence(path, True)['status'], 'PASS' if complete else 'FAIL')

    def test_producer_and_footer_conservation_fail_closed(self):
        for suffix in (b'', finals(20, 0, 2),
                       b'SC_END\t99\t99\t99\t1\t20\t0\t1\nSC_LOG_STATS\t20\t0\t3\t1\t0\t10\n',
                       finals(20, 0, 1)*2):
            with self.subTest(suffix=suffix):
                path, router = self.router()
                router.feed(record(p.event(20, 1))+suffix, 1)
                self.assertFalse(router.close()['mandatory_evidence_complete'])
                self.assertEqual(a.capture_evidence(path, True)['status'], 'FAIL')

    def test_general_diagnostics_cannot_consume_final_marker_reservation(self):
        path, router = self.router(diagnostic_limit=1024)
        for _ in range(1000):router.feed(b'[progress] routine diagnostic\n', 0)
        router.feed(SUCCESS, 0)
        stats = router.close()
        self.assertTrue(stats['mandatory_evidence_complete'])
        self.assertGreater(stats['counts']['stdout.log_general_omitted'], 900)
        self.assertTrue((path/'stdout.log').read_bytes().endswith(SUCCESS))
        self.assertLessEqual(stats['sizes']['stdout.log'], 1024)

    def test_failure_survives_diagnostic_overflow_and_blocks_pass(self):
        path, router = self.router(diagnostic_limit=128)
        router.feed(b'[progress] '+b'x'*110+b'\n', 1)
        router.feed(b'%Error: assertion failed\n', 1)
        stats = router.close()
        result = a.capture_evidence(path, True)
        self.assertEqual(result['status'], 'FAIL')
        self.assertIn('runtime failure marker observed by capture', result['errors'])
        self.assertTrue(stats['diagnostic_ringbuffer']['dumped'])
        self.assertIn(b'%Error: assertion failed', (path/'hang_ringbuffer.tsv').read_bytes())

    def test_raw_diagnostics_are_bounded_and_flushed_only_on_failure(self):
        path, router = self.router(ring_byte_limit=128, ring_line_limit=3)
        for line in (b'FASTLINE_ACQUIRE old\n', b'WB_START older\n',
                     b'CACHE_HANG_SNAPSHOT current\n', b'%Error: watchdog\n'):
            router.feed(line, 1)
        stats = router.close()
        ring = (path/'hang_ringbuffer.tsv').read_bytes()
        data = b'\n'.join(row.rsplit(b'\t', 1)[0] for row in ring.splitlines()[1:]) + b'\n'
        self.assertLessEqual(stats['diagnostic_ringbuffer']['retained_bytes'], 128)
        self.assertNotIn(b'FASTLINE_ACQUIRE old', ring)
        self.assertIn(b'stream\tevent', ring)
        self.assertIn(b'CACHE_HANG_SNAPSHOT current', ring)
        self.assertIn(b'%Error: watchdog', ring)
        self.assertEqual(stats['diagnostic_ringbuffer']['retained_lines'], 2)
        self.assertEqual(stats['diagnostic_ringbuffer']['file'], 'hang_ringbuffer.tsv')

    def test_ring_keeps_only_named_diagnostics_and_failure_lines(self):
        path, router = self.router()
        router.feed(b'STAGE2_TX BLOCK cycle=10 line=deadbeef\n', 1)
        router.feed(b'FASTLINE_BLOCK_OTHER_LINE cycle=11 line=deadbeef\n', 1)
        router.feed(b'%Error: assertion failed\n', 1)
        stats = router.close()
        self.assertEqual(stats['diagnostic_ringbuffer']['retained_lines'], 2)
        data = (path/'hang_ringbuffer.tsv').read_bytes()
        self.assertNotIn(b'STAGE2_TX BLOCK', data)
        self.assertIn(b'FASTLINE_BLOCK_OTHER_LINE', data)

    def test_ring_coalesces_retry_events_without_evicting_owner_lifecycle(self):
        path, router = self.router(ring_line_limit=8)
        router.feed(b'FASTLINE_ACQUIRE cycle=10 line=800123c0 seq=b7 epoch=16 generation=158a8\n', 1)
        for cycle in range(11, 1011):
            router.feed(f'FASTLINE_BLOCK_OTHER_LINE cycle={cycle} line=80008040 request_token=1cc34 fast_line=800123c0 fast_seq=b7 fast_epoch=16\n'.encode(), 1)
        router.feed(b'DCACHE_WATCHDOG_SNAPSHOT cycle=1000 fast_valid=1 fast_line=800123c0\n', 1)
        router.exit_status = 1
        stats = router.close()
        ring = (path/'hang_ringbuffer.tsv').read_text()
        self.assertIn('FASTLINE_ACQUIRE', ring)
        self.assertIn('DCACHE_WATCHDOG_SNAPSHOT', ring)
        self.assertIn('repeats', ring.splitlines()[0])
        self.assertIn('\t1000', ring)
        self.assertEqual(stats['diagnostic_ringbuffer']['duplicate_events'], 999)

    def test_distinct_lifecycle_events_keep_8192_cap_and_evicted_wait_can_return(self):
        path, router = self.router()
        for cycle in range(8300):
            router.feed(f'WB_START cycle={cycle:x} line=80008040\n'.encode(), 1)
        router.exit_status = 1
        stats = router.close()
        self.assertEqual(stats['diagnostic_ringbuffer']['retained_lines'], 8192)
        self.assertEqual(stats['diagnostic_ringbuffer']['duplicate_events'], 0)
        self.assertLessEqual(stats['diagnostic_ringbuffer']['retained_bytes'], 1024**2)
        self.assertEqual(len(router.raw_ring_index), 8192)
        path, router = self.router(ring_line_limit=1)
        router.feed(b'WB_BLOCK cycle=1 line=10\n', 1)
        router.feed(b'WB_START cycle=2 line=20\n', 1)
        router.feed(b'WB_BLOCK cycle=3 line=10\n', 1)
        router.exit_status = 1
        router.close()
        self.assertIn('WB_BLOCK cycle=3', (path/'hang_ringbuffer.tsv').read_text())

    def test_success_does_not_materialize_raw_diagnostic_ring(self):
        path, router = self.router()
        router.feed(b'STAGE1_TX routine\n', 1)
        router.feed(SUCCESS, 0)
        stats = router.close()
        self.assertFalse(stats['diagnostic_ringbuffer']['dumped'])
        self.assertFalse((path/'hang_ringbuffer.tsv').exists())

    def test_oversized_record_buffer_is_bounded_and_later_success_is_drained(self):
        path, router = self.router()
        for _ in range(100):
            router.feed(b'x'*65536, 0)
            self.assertLessEqual(len(router.buffers[0]), c.MAX_RECORD)
        router.feed(b'\n'+SUCCESS, 0)
        stats = router.close()
        self.assertFalse(stats['mandatory_evidence_complete'])
        self.assertEqual(stats['counts']['oversized_records'], 1)
        self.assertIn(b'[END] hart=0 status=PASS', (path/'stdout.log').read_bytes())

    def test_unterminated_tail_cannot_invent_a_success_marker(self):
        path, router = self.router()
        router.feed(b'[END] hart=0 status=PASS', 0)
        self.assertIn('unterminated_output_record', router.close()['incomplete_reasons'])
        self.assertEqual((path/'stdout.log').read_bytes(), b'')

    def test_cache_summary_budget_overflow_continues(self):
        path, router = self.router()
        with patch.object(c, 'OPPORTUNITY_LIMIT', 32):
            router.feed(b'CACHE_OPPORTUNITY '+b'x'*33+b'\n'+SUCCESS, 0)
            stats = router.close()
        self.assertIn('cache_summary_budget_exhausted', stats['incomplete_reasons'])
        self.assertIn(b'[END] hart=0 status=PASS', (path/'stdout.log').read_bytes())

    def test_invalid_or_unbounded_metadata_is_rejected(self):
        _, router = self.router()
        for data in (b'SC_LOG_STATS\t20\t0\t-1\t0\t0\t10\n',
                     f'SC_LOG_STATS\t20\t0\t{2**64}\t0\t0\t10\n'.encode(),
                     record(p.event(20, 1)).replace(b'SC1\t1\t', b'SC1\tbad\t', 1)):
            router.feed(data, 1)
        self.assertFalse(router.close()['mandatory_evidence_complete'])

    def test_identity_table_is_bounded(self):
        _, router = self.router()
        for hart in range(1000):
            row = p.event(4, 1);row['hart'] = hart
            router.feed(record(row), 1)
        self.assertLessEqual(len(router.observers), 129)
        self.assertFalse(router.close()['mandatory_evidence_complete'])

    def test_plain_python_child_exits_zero_after_budget_overflow(self):
        # This is a native output producer, not RTL/model/simulator execution.
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        path = Path(temporary.name)
        router_type = c.Router
        for kind, complete in ((15, True), (20, False)):
            with self.subTest(kind=kind):
                output = path/str(kind);output.mkdir()
                child = ('import sys\n'
                         f'sys.stderr.buffer.write({record(p.event(kind, 1))!r}*3000)\n'
                         f'sys.stderr.buffer.write({finals(kind, 0, 3000)!r})\n'
                         f'sys.stdout.buffer.write({SUCCESS!r})\n')
                with patch.object(c, 'Router', side_effect=lambda directory:
                                  router_type(directory, event_limit=8192, diagnostic_limit=1024)):
                    rc, stats = c.capture([sys.executable, '-I', '-B', '-c', child], output)
                self.assertEqual(rc, 0)
                self.assertTrue(stats['closed'])
                self.assertEqual(stats['mandatory_evidence_complete'], complete)
                self.assertEqual(a.capture_evidence(output, True)['status'], 'PASS' if complete else 'FAIL')
                self.assertIn(b'[END] hart=0 status=PASS', (output/'stdout.log').read_bytes())

    def bounded_run(self, optional_flood=False, modify=None):
        path, router = self.router(event_limit=65536)
        rows = p.svb_sequence()+[p.stats()]
        capacity = p.event(30, 40);capacity['nums'] = [2, 16]+[0]*14;rows.append(capacity)
        pressure = p.event(31, 40);pressure['nums'] = [1, 42582, 81121, 12, 4096]+[0]*11;rows.append(pressure)
        for kind in (17, 18):
            for chunk in (0, 1):
                row = p.event(kind, 40);row['hart'] = chunk;row['nums'] = [chunk]+[10]*15;rows.append(row)
        if optional_flood:rows += [p.event(15, 1)]*500
        for row in rows:router.feed(record(row), 1)
        for (kind, hart), count in Counter((r['kind'], r['hart']) for r in rows).items():
            router.feed(finals(kind, hart, count), 1)
        for row in fixtures.cache_rows():
            router.feed(('CACHE_OPPORTUNITY '+json.dumps(row)+'\n').encode(), 1)
        router.feed(SUCCESS, 0);router.close()
        (path/'roi.json').write_text(json.dumps(dict(roi_cycles=2000000)))
        (path/'run_manifest.json').write_text(json.dumps(dict(simulation='COMPLETED', exit_status=0, source=dict(
            revision_mode='corrected_svb16_cache_opportunity_v1', observation_policy=c.POLICY))))
        if modify:modify(path)
        return a.run_summary(path)

    def test_complete_bounded_run_can_publish_roi_with_exact_pressure(self):
        result = self.bounded_run()
        self.assertEqual(result['correctness']['status'], 'PASS')
        self.assertTrue(result['performance_valid'])
        self.assertEqual(result['traffic_pressure_counters']['blocked_cycles'], 81121)

    def test_optional_loss_does_not_remove_exact_counters_or_invalidate_roi(self):
        result = self.bounded_run(optional_flood=True)
        self.assertTrue(result['performance_valid'])
        self.assertFalse(result['capture_evidence']['summary']['optional_evidence_complete'])
        self.assertEqual(result['traffic_pressure_counters']['semantic_writes'], 42582)

    def test_missing_or_corrupt_capture_cannot_publish_roi(self):
        for change in ('missing', 'producers', 'accounting', 'loss'):
            def modify(path):
                target = path/'capture_summary.json'
                summary = json.loads(target.read_text())
                if change == 'missing':target.unlink();return
                if change == 'producers':summary['producers'] = {}
                if change == 'accounting':summary['producers']['20:0']['produced'] += 1
                if change == 'loss':summary['observers']['20:0']['omitted'] = 1
                target.write_text(json.dumps(summary))
            with self.subTest(change=change):
                result = self.bounded_run(modify=modify)
                self.assertEqual(result['correctness']['status'], 'FAIL')
                self.assertFalse(result['performance_valid'])

    def test_missing_exact_pressure_snapshot_cannot_publish_roi(self):
        def modify(path):
            target = path/'safe_chain_events.tsv'
            target.write_text(''.join(line for line in target.read_text().splitlines(True)
                                     if not (line.startswith('SC1\t') and line.split('\t')[5] == '31')))
        self.assertFalse(self.bounded_run(modify=modify)['performance_valid'])

    def test_nonzero_or_unfinished_workload_cannot_publish_roi(self):
        for state, status in (('ABORTED', -9), ('STARTED', 0), ('COMPLETED', 1)):
            def modify(path):
                target = path/'run_manifest.json'
                manifest = json.loads(target.read_text())
                manifest.update(simulation=state, exit_status=status)
                target.write_text(json.dumps(manifest))
            with self.subTest(state=state, status=status):
                self.assertFalse(self.bounded_run(modify=modify)['performance_valid'])


if __name__ == '__main__':
    with contextlib.redirect_stdout(io.StringIO()):
        unittest.main()
