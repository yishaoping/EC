"""Offline regressions. No HDL simulator, benchmark, elaboration or target build."""
import contextlib
import hashlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import waveform_prepare as wp
import launch_waveform_debug as launch
from waveform_capture import WaveformRouter
from analyze_waveform import summarize


class OverlayTests(unittest.TestCase):
    def test_expression_arguments_preserve_concat_and_mux(self):
        self.assertEqual(wp.split_args("cycle, {tag, set, 6'b0}, a ? f(b,c) : d, v[idx]"),
                         ['cycle', "{tag, set, 6'b0}", 'a ? f(b,c) : d', 'v[idx]'])

    def test_only_curated_printf_enable_changes(self):
        source = '''module Fixture(input clock, ready, valid);
      if ((`PRINTF_COND_) & valid & ~reset) // source
        $fwrite(32'h80000002, "WB_BLOCK cycle=%x fire=%x\\n", cycle, valid & ready);
      if ((`PRINTF_COND_) & valid)
        $fwrite(32'h80000002, "unrelated cycle=%x\\n", cycle);
endmodule
'''
        text, aliases, events = wp.diagnostic_overlay(source, 'Fixture')
        self.assertEqual(text.replace("1'b1", '`PRINTF_COND_'), source)
        self.assertEqual(text.count('`PRINTF_COND_'), 1)
        self.assertEqual(aliases[1]['expression'], 'valid & ready')
        self.assertEqual(events, {'WB_BLOCK': 1})

    def test_missing_essential_snapshot_fails_before_build(self):
        with self.assertRaisesRegex(RuntimeError, 'mandatory existing snapshot'):
            wp.diagnostic_overlay('module BoomCore(); endmodule', 'BoomCore')

    def test_header_continuations_are_real_ports(self):
        names = wp.identifiers('module M(input clock,\n reset,\n output [7:0] count, count2);\n  reg x;\n    wire [2:0][7:0] packed_ctl;\nendmodule')
        self.assertTrue({'clock', 'reset', 'count', 'count2', 'x', 'packed_ctl'} <= names)

    def test_trace_exclusion_has_no_functional_changes(self):
        source = 'module M();\n  reg [511:0] data_0;\n  reg valid;\nendmodule\n'
        text, excluded = wp.suppress_memories(source, 'M')
        self.assertEqual(wp.restore_generated(text), source)
        self.assertEqual(excluded[0]['name'], 'data_0')
        self.assertNotIn('tracing_off*/\n  reg valid', text)

    def test_missing_compiled_alias_refuses_run(self):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d)/'V__Trace__0.cpp'
            p.write_text('tracep->declBit(c+1, "opt4_wave_kept", false, -1);\n')
            result = wp.compiled_audit(Path(d), {'aliases': [{'name': 'opt4_wave_kept'}, {'name': 'opt4_wave_lost'}]})
            self.assertEqual(result['status'], 'FAIL')
            self.assertEqual(result['missing'], ['opt4_wave_lost'])

    def test_native_trace_declarations_accepted(self):
        with tempfile.TemporaryDirectory() as d:
            (Path(d)/'V__Trace__0.cpp').write_text('VL_TRACE_DECL_BIT(c+1, "opt4_wave_required", false, -1);\n')
            self.assertEqual(wp.compiled_audit(d, {'aliases': [{'name': 'opt4_wave_required'}]})['status'], 'PASS')

    def test_failure_ring_and_full_diagnostics_independent_of_general_budget(self):
        with tempfile.TemporaryDirectory() as d:
            router = WaveformRouter(Path(d))
            for i in range(8300): router.feed(f'WB_BLOCK cycle={i:x}\n'.encode(), 0)
            router.feed(b'DCACHE_WATCHDOG_SNAPSHOT cycle=200000 fast_valid=1\n', 1)
            router.exit_status = 1; stats = router.close()
            self.assertEqual(stats['diagnostic_ringbuffer']['retained_lines'], 2)
            self.assertEqual(stats['diagnostic_ringbuffer']['duplicate_events'], 8299)
            self.assertIn('DCACHE_WATCHDOG_SNAPSHOT', (Path(d)/'stderr.log').read_text())
            self.assertEqual((Path(d)/'stdout.log').read_text().count('WB_BLOCK'), 8300)
            self.assertTrue((Path(d)/'hang_ringbuffer.tsv').exists())

    def test_success_does_not_dump_ring(self):
        with tempfile.TemporaryDirectory() as d:
            router = WaveformRouter(Path(d)); router.exit_status = 0; router.close()
            self.assertFalse((Path(d)/'hang_ringbuffer.tsv').exists())

    def test_final_index_values_do_not_invent_missing_progress(self):
        alias = 'opt4_wave_BoomCore_CORE_WATCHDOG_SNAPSHOT_0_last_commit'
        inv = {'aliases': [{'name': alias}], 'hierarchy': {'BoomCore': ['TestHarness.core']}}
        summary = summarize(f'META\t3000000\t4198001\t-12\nH\t1\t64\tTOP.TestHarness.core.{alias}\nF\t1\t1111011\n', inv)
        self.assertEqual(summary['coverage'], 'PASS')
        self.assertEqual(summary['last_commit'], 123)
        self.assertIsNone(summary['last_progress_core_cycles']['wb'])
        self.assertEqual(summary['rootcause'], 'PENDING_OFFLINE_FST_TRANSITION_ANALYSIS')

    def test_six_mshr_instances_must_all_be_present(self):
        alias = 'opt4_wave_BoomMSHR_native_state'
        inv = {'aliases': [{'name': alias}], 'hierarchy': {'BoomMSHR': ['TestHarness.mshrs_'+str(i) for i in range(6)]}}
        summary = summarize(f'META\t1\t2\t-12\nH\t1\t4\tTOP.TestHarness.mshrs_0.{alias}\nF\t1\t01\n', inv)
        self.assertEqual(summary['coverage'], 'FAIL')
        self.assertEqual(len(summary['missing_instances']), 5)

    def test_declared_but_missing_essential_values_rejects_truncated_capture(self):
        commit = 'opt4_wave_BoomCore_CORE_WATCHDOG_SNAPSHOT_0_last_commit'
        fast = 'opt4_wave_BoomNonBlockingDCache_DCACHE_WATCHDOG_SNAPSHOT_0_fast_valid'
        inv = {'aliases': [{'name': commit}, {'name': fast}], 'hierarchy': {}}
        result = summarize(f'META\t1\t2\t-12\nH\t1\t64\tTOP.{commit}\nH\t2\t1\tTOP.{fast}\nF\t1\t01\n', inv)
        self.assertEqual(result['coverage'], 'FAIL')
        self.assertEqual(result['missing_final_aliases'], [fast])


class LauncherTests(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory(); self.addCleanup(temp.cleanup)
        self.root = Path(temp.name); self.out = self.root/'opt4'; self.chipyard = self.root/'chipyard'
        (self.chipyard/'tools/DRAMSim2').mkdir(parents=True)
        (self.chipyard/'sims/verilator').mkdir(parents=True)
        (self.chipyard/'sims/verilator/Makefile').write_text('fixture, never executed\n')
        self.calls = []; self.captures = []
        self.audit_status = 'PASS'
        for obj, attr, value in [(launch, 'ROOT', self.root), (launch, 'OUT', self.out),
                                 (launch, 'CHIPYARD', self.chipyard), (launch, 'WAVE', self.out/'waveform_debug'),
                                 (launch.base, 'CHIPYARD', self.chipyard)]:
            p = patch.object(obj, attr, value); p.start(); self.addCleanup(p.stop)

    def command(self, argv, cwd, log):
        self.calls.append(list(map(str, argv)))
        log.write_text('offline mock; no subprocess\n')
        if str(argv[-1]) == 'debug':
            build = log.parent
            sim = build/'verilator/simulator-chipyard-v1Config-debug'
            sim.write_text('never executed'); sim.chmod(0o700)
        if 'FST_INITIAL_ANALYSIS' == log.stem: self.fail('unexpected name')
        if log.name == 'waveform_analysis.log':
            (log.parent/'waveform_summary.json').write_text('{"coverage":"PASS"}')

    def prepare(self, generated, runtime):
        p = generated/'gen-collateral/emulator.cc'; p.parent.mkdir(parents=True)
        p.write_text('mock trace-safe emulator')
        return dict(aliases=[], files={}, emulator={'observed_sha256': launch.base.sha(p)})

    def capture(self, argv, run):
        self.captures.append(argv); (run/'hang.fst').write_bytes(b'host fixture; not HDL simulation')
        return 1, {'test': 'mock assertion'}

    def main(self, args):
        with patch.object(launch, 'identity', return_value={'hardware_sha256': {}}), \
             patch.object(launch.base, 'command', side_effect=self.command), \
             patch.object(launch.wp, 'prepare', side_effect=self.prepare), \
             patch.object(launch.wp, 'compiled_audit', side_effect=lambda *a: {'status': self.audit_status}), \
             patch.object(launch, 'capture', side_effect=self.capture), \
             patch.object(sys, 'argv', ['waveform', *args]), \
             contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            return launch.main()

    def test_static_check_does_not_create_run_or_call_build(self):
        self.assertEqual(self.main(['--static-check']), 0)
        self.assertFalse(self.out.exists()); self.assertEqual(self.calls, [])

    def test_resume_is_rejected_by_argument_parser(self):
        with self.assertRaises(SystemExit): self.main(['--resume', 'old'])
        self.assertEqual(self.calls, [])

    def test_fresh_fst_build_window_and_failure_postprocessing(self):
        self.assertEqual(self.main([]), 3)
        self.assertEqual([a[-1] for a in self.calls[:3]], ['verilog', str(next((self.out/'build').iterdir())/'generated/sim_files.f'), 'debug'])
        build = self.calls[2]
        self.assertIn('VERILATOR_FST_MODE=1', build)
        self.assertTrue(any('--trace-fst' in a for a in build))
        argv = self.captures[0]
        self.assertIn('--dump-start=1500000', argv)
        self.assertNotIn('+verbose', argv); self.assertNotIn('-V', argv)
        run = next((self.out/'waveform_debug').glob('optimization_*'))
        manifest = json.loads((run/'run_manifest.json').read_text())
        self.assertEqual(manifest['simulation'], 'COMPLETED')
        self.assertEqual(manifest['exit_status'], 1)
        self.assertEqual(manifest['waveform']['sha256'], hashlib.sha256((run/'hang.fst').read_bytes()).hexdigest())
        self.assertEqual(manifest['result'], 'DIAGNOSTIC_CAPTURE_COMPLETE')

    def test_second_attempt_is_rejected_before_any_build(self):
        self.assertEqual(self.main([]), 3); calls = len(self.calls)
        self.assertEqual(self.main([]), 1)
        self.assertEqual(len(self.calls), calls); self.assertEqual(len(self.captures), 1)

    def test_missing_compiled_trace_prevents_simulation(self):
        self.audit_status = 'FAIL'
        self.assertEqual(self.main([]), 1)
        self.assertEqual(self.captures, [])
        self.assertFalse((self.out/'waveform_debug/FINAL_DIAGNOSTIC_SIMULATION_STARTED.json').exists())

    def test_build_failure_is_saved_without_start_guard(self):
        self.command = lambda *a: (_ for _ in ()).throw(RuntimeError('mock build failure'))
        self.assertEqual(self.main([]), 1)
        self.assertEqual(self.captures, [])
        self.assertFalse((self.out/'waveform_debug/FINAL_DIAGNOSTIC_SIMULATION_STARTED.json').exists())


if __name__ == '__main__': unittest.main()
