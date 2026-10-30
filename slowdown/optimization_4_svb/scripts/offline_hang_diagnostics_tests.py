#!/usr/bin/env python3
"""Offline fixtures for Opt4 hang artifacts; no hardware simulator is run."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest


HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location(
    'opt4_hang_analysis', HERE.parent/'analysis/analyze_hang.py')
analysis = importlib.util.module_from_spec(spec)
spec.loader.exec_module(analysis)


class HangAnalysisTests(unittest.TestCase):
    def test_watchdog_artifacts_keep_progress_and_only_proven_gate_edge(self):
        with tempfile.TemporaryDirectory() as temporary:
            run = Path(temporary)
            ring = [
                'stream\tevent',
                'stderr\tCORE_WATCHDOG_SNAPSHOT cycle=3e8 idle=40000 last_progress=320 last_commit=2bc commit=0 csr_stall=0 rocc_busy=0',
                'stderr\tDCACHE_WATCHDOG_SNAPSHOT cycle=3e8 watermark=a fast_valid=1 fast_line=80008040 fast_set=2 fast_tag=20002 fast_seq=b fast_epoch=1 fast_generation=4 fast_state=5 fast_s1=0 fast_s2=0 fast_s3=0 fast_acquire_cycle=190 fast_release_cycle=0 capture_pending=0 capture_issued=0 svb_occupancy=1 svb_active=0 svb_entry=0 svb_line=0 svb_seq=0 wb_state=0 wb_owner_type=0 wb_owner_source=0 wb_valid=0 wb_pending=0 wb_pending_svb=0 wb_entry=0 wb_line=0 wb_sent=0 source_busy=0 source_sent=0 probe_valid=0 probe_line=0 probe_state=0 probe_drain_ready=1 probe_svb_blocked=0 mshr_active=0 mshr_same_line=0 preservation_wait=0 preservation_line=0 preservation_seq=0 preservation_pending=0 preservation_block_condition=0 promotion_valid=0 promotion_entry=0 promotion_line=0 promotion_seq=0 pending_target=0 pending_target_seq=0 safe_watermark=a c_source_busy=0 c_source_sent=0 d_ack_pending=0 d_ack_matched=0 last_lsu=2f0 last_watermark=2e0 last_checker_result=2d0 last_wb=2c0 last_probe=2b0 last_mshr_free=2a0 last_svb=290',
                'stderr\tFASTLINE_BLOCK_OTHER_LINE cycle=3d0 line=80008100 request_type=1 package_seq=c request_token=9 blocked_by=svbFastLineValid owner=SVB fast_valid=1 fast_line=80008040 fast_set=2 fast_tag=20002 fast_seq=b fast_epoch=1 fast_generation=4 owner_state=2 acquire_cycle=190 release_cycle=0 gate_fast_valid=1 gate_other_line=1 gate_capture_pending=0 gate_fast_match=0 gate_slot_free=1 gate_nack_clear=1 gate_epoch_match=1 gate_no_pending_handoff=1 gate_would_handoff_without_fastline=1 cross_package_block_condition=0',
                'stderr\tSVB_HANG_ENTRY cycle=3e8 entry=3 state=1 active=0 line=80008200 seq=b generation=5 writer=1 key_valid=1 epoch=1',
            ]
            (run/'hang_ringbuffer.tsv').write_text('\n'.join(ring)+'\n')
            report = analysis.analyze(run)
            progress = json.loads((run/'last_progress.json').read_text())
            graph = json.loads((run/'wait_for_graph.json').read_text())
            markdown = (run/'hang_rootcause.md').read_text()

            self.assertEqual(report['status'], 'HANG_ROOT_CAUSE_STILL_UNRESOLVED')
            self.assertEqual(progress['last_progress_cycle_by_category']['commit']['cycle'], 700)
            self.assertEqual(progress['last_progress_cycle_by_category']['checker_result']['cycle'], 720)
            self.assertEqual(len(graph['unrelated_lines_blocked_by_fast_line']), 1)
            self.assertTrue(any(edge['from_node'].startswith('PRESERVATION:') and
                                edge['to_node'].startswith('FAST_LINE:') for edge in graph['edges']))
            self.assertTrue(any(edge['to_node'].startswith('WATERMARK:') for edge in graph['edges']))
            self.assertFalse(graph['cycles'])
            self.assertIn('root cause remains unresolved', markdown)

    def test_cycle_detector_reports_complete_node_sequence(self):
        edges = [
            dict(from_node='FAST_LINE', to_node='PRESERVATION', relation='waits_for'),
            dict(from_node='PRESERVATION', to_node='FAST_LINE', relation='waits_for'),
        ]
        self.assertEqual(analysis.find_cycles(edges), [['FAST_LINE', 'PRESERVATION', 'FAST_LINE']])

    def test_missing_watchdog_does_not_invent_hang(self):
        records = [analysis.parse_record('FASTLINE_ACQUIRE cycle=10 line=80008040 seq=1', 'fixture')]
        progress = analysis.progress_report(records)
        graph = analysis.graph_report(records, progress)
        self.assertEqual(graph['status'], 'NO_WATCHDOG_OBSERVED')
        self.assertFalse(graph['cycles'])

    def native_failure(self, assertion=None, message=None):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        root = Path(temporary.name)
        run = root/'runs'/'run_fixture'
        run.mkdir(parents=True)
        (run/'stdout.log').write_text(message or
            '[2099000] %Error: BoomCore.sv:2: Assertion failed in TOP.core.assert__assert_21\n')
        if assertion:
            generated = root/'build'/run.name/'generated'/'gen-collateral'
            generated.mkdir(parents=True)
            (generated/'BoomCore.sv').write_text('// fixture\n'+assertion+'\n')
        return run

    def test_native_watchdog_with_printf_disabled_is_insufficient_not_absent(self):
        run = self.native_failure('assert__assert_21: assert(~ecWatchdogImminent);')
        result = analysis.analyze(run)
        progress = json.loads((run/'last_progress.json').read_text())
        self.assertEqual(result['status'], 'HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT')
        self.assertTrue(progress['watchdog_detected'])
        self.assertEqual(progress['watchdog_simulator_time'], 2099000)
        self.assertIsNone(progress['watchdog_cycle'])
        self.assertIsNone(progress['last_progress_cycle_by_category']['commit']['cycle'])
        self.assertFalse(result['cycles'])

    def test_same_assertion_number_for_other_condition_is_not_watchdog(self):
        run = self.native_failure('assert__assert_21: assert(~unrelatedFailure);')
        self.assertEqual(analysis.analyze(run)['status'], 'ABNORMAL_EXIT_WITHOUT_WATCHDOG_EVIDENCE')

    def test_missing_generated_assertion_does_not_guess_from_label(self):
        run = self.native_failure()
        self.assertFalse(analysis.failure_report(run)['watchdog_detected'])

    def test_explicit_watchdog_message_needs_no_generated_file(self):
        run = self.native_failure(message='Assertion failed: Pipeline has hung.\n')
        self.assertEqual(analysis.analyze(run)['status'], 'HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT')

    def test_other_run_generated_assertion_cannot_be_used(self):
        run = self.native_failure()
        generated = run.parent.parent/'build'/'other_run'/'generated'/'gen-collateral'
        generated.mkdir(parents=True)
        (generated/'BoomCore.sv').write_text('// fixture\nassert(~ecWatchdogImminent);\n')
        self.assertFalse(analysis.failure_report(run)['watchdog_detected'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
