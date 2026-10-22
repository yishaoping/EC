#!/usr/bin/env python3
"""Pure offline orchestration/coverage gates. All hardware actions are mocked."""
import contextlib
import io
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
from types import SimpleNamespace
import stage2_validation as v


class ValidationTests(unittest.TestCase):
    def directory(self):
        # Retain all test evidence under AI/TMP, including failures.
        return Path(tempfile.mkdtemp(prefix='stage2_gate_unit_',dir=v.REPO/'AI/TMP'))

    def trace(self):
        text=''.join('CASE '+name+' PASS\n' for name in v.CASES)
        text+=''.join(f'STAGE2_MSHR opcode={op} denied={deny} observed_events\n'
                      for op in (0,2) for deny in (0,1))
        for req in range(1,5):
            text+=f'STAGE2_STIM FORBID req={req:x}\nSTAGE2_STIM ALLOW req={req:x}\n'
            text+=f'STAGE1_TX EFFECT cycle=1 req={req:x} data=0\n'
        return text+'STAGE2_DIRECTED=PASS cycles=123\n'

    def test_exact_cases_and_events(self):
        self.assertEqual(v.case_report(self.trace())['status'],'PASS')

    def test_empty_is_uncovered(self):
        self.assertEqual(v.case_report('')['status'],'UNCOVERED')

    def test_case_count_cannot_hide_missing_case(self):
        text=self.trace().replace('CASE '+v.CASES[0]+' PASS\n','')+'CASE '+v.CASES[1]+' PASS\n'
        self.assertEqual(v.case_report(text)['status'],'FAIL')

    def test_missing_case_is_coverage_failure(self):
        self.assertEqual(v.case_report(self.trace().replace('CASE '+v.CASES[0]+' PASS\n',''))['status'],'UNCOVERED')

    def test_denied_case_name_without_dynamic_events_is_uncovered(self):
        text=self.trace().replace('STAGE2_MSHR opcode=0 denied=1 observed_events\n','')
        self.assertEqual(v.case_report(text)['status'],'UNCOVERED')

    def test_duplicate_trusted_a_event_is_failure(self):
        text=self.trace()+'STAGE2_MSHR opcode=2 denied=1 observed_events\n'
        self.assertEqual(v.case_report(text)['status'],'FAIL')

    def test_nonzero_simulator_cannot_pass(self):
        self.assertEqual(v.case_report(self.trace(),1)['status'],'FAIL')

    def test_failure_marker_cannot_pass(self):
        self.assertEqual(v.case_report(self.trace()+'STAGE2_DIRECTED=FAIL reason=bad\n')['status'],'FAIL')

    def test_multiple_directed_failures_are_all_reported(self):
        text=self.trace().replace('STAGE2_DIRECTED=PASS cycles=123\n',
            'STAGE2_CHECK_FAIL case=wb reason=ack-before-c-fire\n'
            'STAGE2_CHECK_FAIL case=sourceD reason=bank-stall\n'
            'STAGE2_DIRECTED=FAIL reason=wb and SourceD\n')
        report=v.case_report(text)
        self.assertEqual(report['status'],'FAIL')
        self.assertEqual(report['directed_failures'],['wb and SourceD'])
        self.assertEqual(report['check_failures'],[
            {'case':'wb','reason':'ack-before-c-fire'},
            {'case':'sourceD','reason':'bank-stall'}])
        summary=v.directed_failure_summary(report)
        self.assertIn('case=wb reason=ack-before-c-fire',summary)
        self.assertIn('case=sourceD reason=bank-stall',summary)

    def test_early_effect_independent_of_terminal(self):
        text=self.trace().replace('STAGE2_STIM ALLOW req=1\nSTAGE1_TX EFFECT cycle=1 req=1 data=0\n',
                                 'STAGE1_TX EFFECT cycle=1 req=1 data=0\nSTAGE2_STIM ALLOW req=1\n')
        self.assertIn('effect_before_independent_permission',v.case_report(text)['event_errors'])

    def test_duplicate_effect(self):
        self.assertEqual(v.case_report(self.trace()+'STAGE1_TX EFFECT cycle=2 req=1 data=0\n')['status'],'FAIL')

    def test_unclosed_guard(self):
        self.assertEqual(v.case_report(self.trace()+'STAGE2_STIM FORBID req=6\n')['status'],'FAIL')

    def test_build_requires_input_snapshot_without_offline_dependency(self):
        root=self.directory()
        with patch.object(v,'build') as build:
            with self.assertRaises(v.Stop): v.execute(root,'build')
            build.assert_not_called()
        self.assertIn('BUILD=FAIL',(root/'summary.out').read_text())
        self.assertIn('input snapshot missing',v.read(root/'build.status.json')['reason'])

    def test_failed_build_blocks_both_simulators(self):
        root=self.directory()
        v.save(root/'offline.status.json',dict(status='PASS'))
        v.save(root/'build.status.json',dict(status='FAIL'))
        for phase in ('directed','system'):
            with patch.object(v,phase) as action:
                with self.assertRaises(v.Stop): v.execute(root,phase)
                action.assert_not_called()

    def test_system_requires_directed_pass(self):
        root=self.directory()
        for phase in ('offline','build'): v.save(root/(phase+'.status.json'),dict(status='PASS'))
        v.save(root/'directed.status.json',dict(status='UNCOVERED'))
        with patch.object(v,'system') as action:
            with self.assertRaises(v.Stop): v.execute(root,'system')
            action.assert_not_called()

    def test_changed_inputs_block_action_and_record_reason(self):
        root=self.directory()
        v.save(root/'offline.status.json',dict(status='PASS'))
        v.save(root/'inputs.json',dict(source='before'))
        with patch.object(v,'inputs',return_value=dict(source='after')),patch.object(v,'build') as action:
            with self.assertRaises(v.Stop): v.execute(root,'build')
            action.assert_not_called()
        self.assertEqual(v.read(root/'build.status.json')['status'],'FAIL')
        self.assertIn('inputs changed',v.read(root/'build.status.json')['reason'])

    def test_failed_phase_is_not_retried_or_overwritten(self):
        root=self.directory()
        original=dict(status='FAIL',reason='preserved first failure')
        v.save(root/'build.status.json',original)
        with self.assertRaises(v.Stop): v.execute(root,'build')
        self.assertEqual(v.read(root/'build.status.json'),original)

    def test_coverage_exit_three_is_preserved(self):
        root=self.directory()
        for phase in ('offline','build'): v.save(root/(phase+'.status.json'),dict(status='PASS'))
        with patch.object(v,'require_inputs',return_value={}),patch.object(v,'directed',side_effect=v.Stop('missing case',3,uncovered=True)):
            with self.assertRaises(v.Stop) as caught: v.execute(root,'directed')
        self.assertEqual(caught.exception.code,3)
        self.assertEqual(v.read(root/'directed.status.json')['status'],'UNCOVERED')

    def test_tampered_copied_fixture_is_rejected(self):
        root=self.directory()
        record=dict(scripts={'AI/Debug/scripts/stage2/x.scala':'expected'})
        v.save(root/'inputs.json',record)
        (root/'fixture').mkdir(); (root/'fixture/x.scala').write_text('changed')
        with patch.object(v,'inputs',return_value=record):
            with self.assertRaisesRegex(v.Stop,'copied fixture changed'): v.require_inputs(root)

    def test_missing_copied_fixture_is_rejected(self):
        root=self.directory(); record=dict(scripts={})
        v.save(root/'inputs.json',record)
        with patch.object(v,'inputs',return_value=record):
            with self.assertRaisesRegex(v.Stop,'copied fixture missing'): v.require_inputs(root)

    def test_missing_model_cannot_be_reused(self):
        root=self.directory()
        with self.assertRaisesRegex(v.Stop,'products missing'): v.module_artifacts(root)

    def test_all_always_creates_unique_root_even_with_inherited_root(self):
        inherited=self.directory()
        (inherited/'evidence').write_text('keep')
        with patch.dict(os.environ,{'STAGE2_ROOT':str(inherited)}):
            first=v.choose_root('all'); second=v.choose_root('all')
        self.assertNotEqual(first,second)
        self.assertNotEqual(first,inherited)
        self.assertEqual((inherited/'evidence').read_text(),'keep')
        self.assertEqual(first.parent,v.REPO/'AI/TMP')

    def test_build_can_start_fresh_without_offline_root(self):
        with patch.dict(os.environ,{},clear=True): root=v.choose_root('build')
        self.assertEqual(root.parent,v.REPO/'AI/TMP')
        self.assertFalse((root/'offline.status.json').exists())

    def test_build_rejects_existing_uninitialized_root_without_overwrite(self):
        root=self.directory(); evidence=root/'summary.out'; evidence.write_text('keep failure')
        with patch.dict(os.environ,{'STAGE2_ROOT':str(root)}):
            with self.assertRaisesRegex(v.Stop,'no input snapshot'): v.choose_root('build')
        self.assertEqual(evidence.read_text(),'keep failure')

    def test_all_is_serial_and_stops_at_each_possible_failure(self):
        # Dispatch only: every hardware/offline phase action is replaced.
        for failing in v.PHASES:
            root=self.directory(); calls=[]
            def action(phase):
                def run(*args):
                    calls.append(phase)
                    if phase==failing: raise v.Stop('synthetic command failure',7)
                return run
            with contextlib.ExitStack() as stack:
                stack.enter_context(patch.object(v,'inputs',return_value={}))
                stack.enter_context(patch.object(v,'capture_sources'))
                stack.enter_context(patch.object(v,'require_inputs',return_value={}))
                stack.enter_context(patch.object(v,'offline',side_effect=AssertionError('offline must not run in all')))
                for phase in v.PHASES: stack.enter_context(patch.object(v,phase,side_effect=action(phase)))
                with self.assertRaises(v.Stop) as caught: v.run_phases(root,'all')
            self.assertEqual(caught.exception.code,7)
            self.assertEqual(calls,list(v.PHASES[:v.PHASES.index(failing)+1]))
            for later in v.PHASES[v.PHASES.index(failing)+1:]:
                self.assertFalse((root/(later+'.status.json')).exists())

    def test_all_summary_does_not_turn_not_run_into_pass(self):
        root=self.directory()
        v.save(root/'offline.status.json',dict(status='PASS'))
        v.save(root/'build.status.json',dict(status='FAIL'))
        output=io.StringIO()
        error=v.Stop('synthetic build failure',7,log=root/'module.emit.log',first_error='[error] missing field')
        with contextlib.redirect_stdout(output): v.finish(root,'all',error)
        text=output.getvalue()
        self.assertIn('失败阶段：编译/硬件生成',text)
        self.assertIn('定向仿真 (directed)：未运行',text)
        self.assertIn('[error] missing field',text)
        self.assertIn(str(root/'module.emit.log'),text)
        self.assertIn('退出码：7',text)

    def test_summary_points_to_all_errors_and_retains_not_run(self):
        root=self.directory(); v.save(root/'build.status.json',dict(status='FAIL'))
        diagnostics=dict(count=2,text=str(root/'module.emit.log.errors.out'),json=str(root/'module.emit.log.errors.json'))
        error=v.Stop('compile failed',1,log=root/'module.emit.log',diagnostics=diagnostics)
        with contextlib.redirect_stdout(io.StringIO()) as output: v.finish(root,'all',error)
        self.assertIn('本次日志错误/失败诊断数：2',output.getvalue())
        self.assertIn(diagnostics['text'],output.getvalue())
        self.assertIn('定向仿真 (directed)：未运行',output.getvalue())

    def test_all_success_dispatches_each_phase_once_in_order(self):
        root=self.directory(); calls=[]
        with contextlib.ExitStack() as stack:
            stack.enter_context(patch.object(v,'inputs',return_value={}))
            capture=stack.enter_context(patch.object(v,'capture_sources',side_effect=lambda *args:calls.append('snapshot')))
            stack.enter_context(patch.object(v,'require_inputs',return_value={}))
            offline=stack.enter_context(patch.object(v,'offline',side_effect=AssertionError('offline must not run in all')))
            for phase in v.PHASES:
                stack.enter_context(patch.object(v,phase,side_effect=lambda *args,p=phase:calls.append(p)))
            v.run_phases(root,'all')
        self.assertEqual(calls,['snapshot','build','directed','system'])
        capture.assert_called_once_with(root,{})
        offline.assert_not_called()
        self.assertFalse((root/'offline.status.json').exists())
        self.assertNotIn('OFFLINE=PASS',(root/'summary.out').read_text())
        self.assertTrue(all(v.read(root/(p+'.status.json'))['status']=='PASS' for p in v.PHASES))

    def test_inventory_failure_stops_before_dispatch_and_retains_reason(self):
        root=self.directory()
        with patch.object(v,'inputs',side_effect=v.Stop('missing executable: synthetic-tool',2)),patch.object(v,'execute') as dispatch:
            with self.assertRaises(v.Stop): v.run_phases(root,'all')
            dispatch.assert_not_called()
        self.assertIn('synthetic-tool',v.read(root/'build.status.json')['reason'])
        self.assertFalse((root/'offline.status.json').exists())

    def test_snapshot_failure_stops_before_build(self):
        root=self.directory()
        with patch.object(v,'inputs',return_value={}),patch.object(v,'capture_sources',side_effect=OSError('snapshot failure')),patch.object(v,'build') as build:
            with self.assertRaisesRegex(v.Stop,'snapshot failure'): v.run_phases(root,'all')
            build.assert_not_called()
        self.assertEqual(v.read(root/'build.status.json')['status'],'FAIL')

    def test_offline_remains_an_explicit_option(self):
        root=self.directory()
        with patch.object(v,'inputs',return_value={}),patch.object(v,'capture_sources') as capture,patch.object(v,'require_inputs',return_value={}),patch.object(v,'offline') as offline:
            v.run_phases(root,'offline')
        capture.assert_called_once_with(root,{})
        offline.assert_called_once_with(root,{})
        self.assertEqual(v.read(root/'offline.status.json')['status'],'PASS')
        self.assertFalse((root/'build.status.json').exists())

    def test_existing_initialized_root_is_not_overwritten(self):
        root=self.directory(); v.save(root/'inputs.json',dict(original=True))
        (root/'summary.out').write_text('original evidence')
        with patch.object(v,'inputs') as inventory:
            with self.assertRaisesRegex(v.Stop,'already initialized'): v.run_phases(root,'all')
            inventory.assert_not_called()
        self.assertEqual((root/'summary.out').read_text(),'original evidence')

    def test_success_summary_is_current_tests_only(self):
        root=self.directory()
        for phase in v.PHASES: v.save(root/(phase+'.status.json'),dict(status='PASS'))
        with contextlib.redirect_stdout(io.StringIO()): v.finish(root,'all')
        self.assertIn('当前测试通过；不等于已证明所有硬件行为正确',(root/'summary.out').read_text())

    def test_command_retains_raw_exit_code_and_first_error(self):
        root=self.directory()
        def failed_run(*args,**kwargs):
            kwargs['stdout'].write('setup warning\n[error] real compile error\nmake: Error 7\n')
            return SimpleNamespace(returncode=7)
        with patch.object(v.subprocess,'run',side_effect=failed_run):
            with self.assertRaises(v.Stop) as caught: v.command(root,'compile.log',['mock-compiler'])
        self.assertEqual(caught.exception.code,7)
        self.assertEqual(caught.exception.raw_code,7)
        self.assertEqual(caught.exception.first_error,'[error] real compile error')
        self.assertEqual(caught.exception.log,str(root/'compile.log'))
        self.assertGreater(caught.exception.diagnostics['count'],0)
        self.assertTrue(Path(caught.exception.diagnostics['json']).is_file())

    def test_error_summary_collects_multiple_errors_and_skips_stack_noise(self):
        root=self.directory(); log=root/'compile.log'
        log.write_text('[error] first real error\n[error] \tat scala.collection.List.map(List.scala:1)\n'+
                       '[error] second real error\n[error] \tat firrtl.Transform.run(Transform.scala:1)\n'+
                       '[error] first real error\n[error] Total time: 130 s\n')
        entries=v.error_entries(log)
        self.assertEqual([e['message'] for e in entries],['[error] first real error','[error] second real error'])
        self.assertEqual(entries[0]['occurrences'],2)
        self.assertEqual(entries[1]['line'],3)
        with contextlib.redirect_stdout(io.StringIO()) as output: report=v.failure_diagnostics(log,1)
        self.assertIn('second real error',output.getvalue())
        self.assertEqual(report['count'],2)
        saved=v.read(Path(report['json']))
        self.assertEqual(saved['raw_exit_code'],1)
        self.assertEqual(saved['log_sha256'],v.sha(log))

    def test_colored_fork_banner_is_not_an_error_and_cause_is_selected(self):
        root=self.directory(); log=root/'compile.log'
        color=lambda text:'\x1b[0m[\x1b[31merror\x1b[0m] '+text+'\x1b[0m'
        banner=color('Picked up JAVA_TOOL_OPTIONS: -Xmx8G')
        wrapper=color('Exception in thread "main" firrtl.FirrtlInternalException: Internal Error!')
        cause=color('Caused by: java.util.NoSuchElementException: key not found: gh_l1_l2_packet_tracked_15')
        log.write_text(banner+'\n'+wrapper+'\n'+color('\tat firrtl.Pass.execute(Pass.scala:1)')+'\n'+cause+'\n'+
                       '\x1b[0Jmake: *** [common.mk:225: target] Error 1\n')
        entries=v.error_entries(log)
        self.assertEqual(len(entries),3)
        self.assertFalse(any('Picked up' in e['message'] or '\x1b' in e['message'] for e in entries))
        self.assertEqual(entries[1]['line'],4)
        self.assertEqual(entries[1]['raw_message'],cause)
        self.assertIn('key not found:',v.first_error(log))
        self.assertEqual(entries[-1]['message'],'make: *** [common.mk:225: target] Error 1')

    def test_jvm_banners_do_not_hide_other_real_errors_or_oom(self):
        root=self.directory(); log=root/'compile.log'
        log.write_text('[error] Picked up JAVA_TOOL_OPTIONS: -Xmx8G\n'+
                       '[error] Picked up _JAVA_OPTIONS: -Xmx8G\n'+
                       '[error] NOTE: Picked up JDK_JAVA_OPTIONS: -Xmx8G\n'+
                       '[error] Main.scala:12: first type error\n'+
                       '[error] Other.scala:19: second type error\n'+
                       'Exception in thread "main" java.lang.OutOfMemoryError: Java heap space\n')
        entries=v.error_entries(log)
        self.assertEqual(len(entries),3)
        self.assertIn('first type error',v.first_error(log))
        self.assertTrue(any('second type error' in e['message'] for e in entries))
        self.assertTrue(any('OutOfMemoryError' in e['message'] for e in entries))

    def test_colored_compiler_context_and_original_bytes_are_both_kept(self):
        root=self.directory(); log=root/'compile.log'
        original='\x1b[31m[error]\x1b[0m Main.scala:1: value missing is not a member'
        context='\x1b[31m[error]\x1b[0m foo.missing'
        log.write_text(original+'\n'+context+'\n\x1b[31m[error]\x1b[0m     ^\n')
        entry=v.error_entries(log)[0]
        self.assertEqual(entry['message'],'[error] Main.scala:1: value missing is not a member')
        self.assertEqual(entry['context'],['[error] foo.missing','[error]     ^'])
        self.assertEqual(entry['raw_message'],original)
        self.assertEqual(entry['raw_context'][0],context)

    def system_annotations(self, root, annotations):
        path=root/'system.build/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.appended.anno.json'
        path.parent.mkdir(parents=True,exist_ok=True)
        v.save(path,annotations)
        return path

    def test_system_wiring_reports_all_64_orphans_from_one_actual_input(self):
        root=self.directory()
        pins=[f'gh_l1_l2_packet_{field}_{i}' for field in ('addr','addr_valid','seq','tracked') for i in range(16)]
        source=lambda pin:{'class':'firrtl.passes.wiring.SourceAnnotation','pin':pin,'target':'TestHarness.DCache.'+pin}
        annotations=[source(pin) for pin in pins]
        annotations += [source('valid'),dict(**{'class':'firrtl.passes.wiring.SinkAnnotation'},pin='valid',target='TestHarness.L2.input')]
        path=self.system_annotations(root,annotations)
        # The final file already contains these annotations. An audit that
        # concatenates intermediates would falsely count duplicate producers.
        v.save(path.with_name('chipyard.TestHarness.v1Config.anno.json'),annotations)
        identity=v.sha(path)
        report,lines=v.system_wiring_diagnostics(root)
        saved=v.read(Path(report['json']))
        self.assertEqual(report['status'],'INVALID_COUNTS')
        self.assertEqual(report['count'],64)
        self.assertEqual(saved['pins'],65)
        self.assertEqual({e['pin'] for e in saved['errors']},set(pins))
        self.assertEqual(saved['annotation_sha256'],identity)
        self.assertEqual(v.sha(path),identity)
        self.assertFalse(any('pin=valid ' in line for line in lines))

    def test_system_wiring_catches_missing_and_duplicate_sources(self):
        root=self.directory()
        annotation=lambda kind,pin,target:{'class':'firrtl.passes.wiring.'+kind+'Annotation','pin':pin,'target':target}
        self.system_annotations(root,[annotation('Sink','missing','Top.L2.in'),
            annotation('Source','duplicate','Top.A.out'),annotation('Source','duplicate','Top.B.out'),
            annotation('Sink','duplicate','Top.C.in')])
        report,_=v.system_wiring_diagnostics(root)
        errors={e['pin']:e for e in v.read(Path(report['json']))['errors']}
        self.assertEqual(report['count'],2)
        self.assertEqual(len(errors['missing']['sources']),0)
        self.assertEqual(len(errors['duplicate']['sources']),2)

    def test_system_wiring_absent_empty_or_unreadable_is_never_hardware_pass(self):
        root=self.directory()
        report,_=v.system_wiring_diagnostics(root)
        self.assertEqual(report['status'],'UNAVAILABLE')
        path=self.system_annotations(root,[])
        report,_=v.system_wiring_diagnostics(root)
        self.assertEqual(report['status'],'NO_WIRING')
        path.write_text('{truncated')
        report,_=v.system_wiring_diagnostics(root)
        self.assertEqual(report['status'],'READ_ERROR')
        self.system_annotations(root,[{'class':'firrtl.passes.wiring.SourceAnnotation','pin':'a','target':'Top.out'},
                                      {'class':'firrtl.passes.wiring.SinkAnnotation','pin':'a','target':'Top.in'}])
        report,_=v.system_wiring_diagnostics(root)
        self.assertEqual(report['status'],'COUNTS_ONLY')

    def test_failed_system_command_saves_all_wiring_errors_and_keeps_exit_code(self):
        root=self.directory()
        self.system_annotations(root,[{'class':'firrtl.passes.wiring.SourceAnnotation','pin':pin,'target':'Top.'+pin}
                                      for pin in ('missing_a','missing_b')])
        def failed_run(*args,**kwargs):
            kwargs['stdout'].write('[error] Picked up JAVA_TOOL_OPTIONS: -Xmx8G\n'+
                '[error] Exception in thread "main" firrtl.FirrtlInternalException: Internal Error!\n'+
                '[error] Caused by: java.util.NoSuchElementException: key not found: missing_b\n')
            return SimpleNamespace(returncode=2)
        with patch.object(v.subprocess,'run',side_effect=failed_run),contextlib.redirect_stdout(io.StringIO()) as output:
            with self.assertRaises(v.Stop) as caught: v.command(root,'system.build.wrapper.log',['mock-make'])
        self.assertEqual(caught.exception.code,2)
        self.assertEqual(caught.exception.raw_code,2)
        self.assertIn('key not found: missing_b',caught.exception.first_error)
        self.assertEqual(caught.exception.diagnostics['wiring']['count'],2)
        self.assertIn('pin=missing_a',output.getvalue())
        self.assertIn('pin=missing_b',output.getvalue())
        self.assertNotIn('Picked up',output.getvalue())

    def test_wiring_summary_reports_all_pins_with_zero_tool_exit(self):
        root=self.emit_fixture('STAGE2_WIRING_ERROR pin=a sources=1 sinks=0\n'+
                               'STAGE2_WIRING_ERROR pin=b sources=2 sinks=1\n'+
                               'STAGE2_WIRING=FAIL pins=2 errors=2\n[error] requirement failed\n',False)
        with contextlib.redirect_stdout(io.StringIO()) as output:
            with self.assertRaises(v.Stop) as caught: v.emitted_rtl(root)
        self.assertIn('pin=a',output.getvalue())
        self.assertIn('pin=b',output.getvalue())
        self.assertIn('pin=a',caught.exception.first_error)
        self.assertEqual(caught.exception.raw_code,0)

    def test_all_existing_log_errors_are_printed_even_before_long_stack_tail(self):
        root=self.directory()
        def failed_run(*args,**kwargs):
            kwargs['stdout'].write('[error] first type error\n[error] second type error\n'+
                                   ''.join('[error] \tat firrtl.Pass.run(Pass.scala:1)\n' for _ in range(80)))
            return SimpleNamespace(returncode=1)
        with patch.object(v.subprocess,'run',side_effect=failed_run),contextlib.redirect_stdout(io.StringIO()) as output:
            with self.assertRaises(v.Stop): v.command(root,'compile.log',['mock-compiler'])
        self.assertIn('first type error',output.getvalue())
        self.assertIn('second type error',output.getvalue())
        self.assertNotIn('firrtl.Pass.run',output.getvalue())

    def test_compiler_diagnostic_context_is_preserved(self):
        root=self.directory(); log=root/'compile.log'
        log.write_text('[error] Main.scala:1: value missing is not a member\n[error] foo.missing\n[error]     ^\n')
        entries=v.error_entries(log)
        self.assertEqual(entries[0]['context'],['[error] foo.missing','[error]     ^'])

    def emit_fixture(self, text, rtl=True):
        root=self.directory(); (root/'module.emit.log').write_text(text)
        (root/'generated').mkdir()
        if rtl: (root/'generated/Stage2Harness.v').write_text('module Stage2Harness; endmodule\n')
        (root/'generated/stage2.wiring.out').write_text('STAGE2_WIRING=PASS pins=33 errors=0\n')
        return root

    def test_sbt_exit_zero_with_background_oom_cannot_pass(self):
        message='Exception in thread "sbt-bg-threads-1" java.lang.OutOfMemoryError: Java heap space'
        root=self.emit_fixture('[info] done compiling\n'+message+'\n[success] Total time: 32 s\n',False)
        with self.assertRaises(v.Stop) as caught: v.emitted_rtl(root)
        self.assertEqual(caught.exception.raw_code,0)
        self.assertEqual(caught.exception.first_error,message)
        self.assertEqual(caught.exception.log,str(root/'module.emit.log'))
        self.assertEqual(v.first_error(root/'module.emit.log'),message)

    def test_emission_exception_is_failure_even_with_partial_rtl_and_pass_marker(self):
        root=self.emit_fixture('Exception in thread "sbt-bg-threads-1" java.lang.IllegalStateException: bad\nSTAGE2_EMIT=PASS top=Stage2Harness\n')
        with self.assertRaisesRegex(v.Stop,'IllegalStateException'): v.emitted_rtl(root)

    def test_zero_exit_oom_stops_build_before_lint_or_simulation_and_records_cause(self):
        root=self.directory()
        message='Exception in thread "sbt-bg-threads-1" java.lang.OutOfMemoryError: Java heap space'
        record=dict(tools={'sbt':{'path':'mock-sbt'}},java_dir='/mock-java',riscv='/mock-riscv',
                    build=dict(module_jvm_args=list(v.MODULE_JVM_ARGS)))
        def fake_emit(root,log,*args,**kwargs):
            (root/log).write_text(message+'\n[success] Total time: 32 s\n')
        with patch.object(v,'require_inputs',return_value=record),patch.object(v,'command',side_effect=fake_emit) as command:
            with self.assertRaises(v.Stop): v.execute(root,'build')
            for phase in ('directed','system'):
                with self.assertRaises(v.Stop): v.execute(root,phase)
        command.assert_called_once()
        state=v.read(root/'build.status.json')
        self.assertEqual(state['status'],'FAIL')
        self.assertEqual(state['exit_code'],1)
        self.assertEqual(state['raw_exit_code'],0)
        self.assertEqual(state['first_error'],message)
        self.assertEqual(state['log'],str(root/'module.emit.log'))
        self.assertFalse((root/'directed.status.json').exists())
        self.assertFalse((root/'system.status.json').exists())

    def test_emission_missing_rtl_keeps_original_log(self):
        root=self.emit_fixture('[success] Total time: 1 s\n',False)
        with self.assertRaises(v.Stop) as caught: v.emitted_rtl(root)
        self.assertIn('Stage2Harness.v',str(caught.exception))
        self.assertEqual(caught.exception.log,str(root/'module.emit.log'))

    def test_partial_rtl_without_emission_completion_is_failure(self):
        root=self.emit_fixture('[success] Total time: 1 s\n')
        with self.assertRaisesRegex(v.Stop,'STAGE2_EMIT'): v.emitted_rtl(root)

    def test_emission_requires_complete_rtl_and_marker(self):
        root=self.emit_fixture('STAGE2_EMIT=PASS top=Stage2Harness\n[success] Total time: 1 s\n')
        self.assertEqual(v.emitted_rtl(root),[root/'generated/Stage2Harness.v'])

    def test_emission_requires_real_successful_wiring_report(self):
        root=self.emit_fixture('STAGE2_EMIT=PASS top=Stage2Harness\n')
        (root/'generated/stage2.wiring.out').write_text('STAGE2_WIRING=FAIL pins=33 errors=1\n')
        with self.assertRaisesRegex(v.Stop,'wiring'): v.emitted_rtl(root)

    def test_informational_jvm_banner_cannot_fail_complete_emission(self):
        root=self.emit_fixture('[error] Picked up JAVA_TOOL_OPTIONS: -Xmx8G\nSTAGE2_EMIT=PASS top=Stage2Harness\n')
        self.assertEqual(v.emitted_rtl(root),[root/'generated/Stage2Harness.v'])

    def test_module_heap_and_oom_exit_are_fingerprinted(self):
        root=self.directory(); workload=root/'workload.json'; workload.write_text('{}')
        verified={k+'_sha256':k+'-hash' for k in ('benchmark','loadmem','dump')}
        with patch.dict(os.environ,{'STAGE1_WORKLOAD':str(workload)},clear=True),patch('stage1_provenance.source_record',return_value={}),patch('stage1_workload.verify',return_value=verified),patch.object(v,'tool',return_value={'path':'mock-tool','sha256':'mock-hash'}),patch.object(v.subprocess,'check_output',return_value='mock-head\n'):
            record=v.inputs()
        self.assertEqual(record['build']['module_jvm_args'],list(v.MODULE_JVM_ARGS))
        self.assertIn('-J-Xmx8G',record['build']['module_jvm_args'])
        self.assertIn('-J-XX:+ExitOnOutOfMemoryError',record['build']['module_jvm_args'])
        self.assertEqual(record['build']['module_error_limit'],'0')
        self.assertTrue(record['build']['module_wiring_audit'])

    def test_build_passes_fingerprinted_jvm_args_before_sbt_commands(self):
        root=self.directory()
        record=dict(tools={name:dict(path='mock-'+name) for name in ('sbt','verilator')},
                    java_dir='/mock-java',riscv='/mock-riscv',workload='/mock-workload',
                    build=dict(module_jvm_args=list(v.MODULE_JVM_ARGS),module_error_limit='0'))
        with patch.object(v,'command') as command,patch.object(v,'emitted_rtl',return_value=[root/'generated/Stage2Harness.v']),patch.object(v,'require_inputs'),patch.object(v,'module_artifacts',return_value={}),patch.object(v,'verify_build'):
            v.build(root,record)
        argv=command.call_args_list[0].args[2]
        self.assertEqual(argv[:3],['mock-sbt','-java-home','/mock-java'])
        self.assertEqual(argv[3:3+len(v.MODULE_JVM_ARGS)],list(v.MODULE_JVM_ARGS))
        for call in command.call_args_list[1:3]:
            argv=call.args[2]
            self.assertEqual(argv[argv.index('--error-limit')+1],'0')

    def test_raw_exit_three_is_failure_not_missing_coverage(self):
        root=self.directory(); v.save(root/'offline.status.json',dict(status='PASS'))
        with patch.object(v,'require_inputs',return_value={}),patch.object(v,'build',side_effect=v.Stop('tool exit three',3,raw_code=3)):
            with self.assertRaises(v.Stop): v.execute(root,'build')
        self.assertEqual(v.read(root/'build.status.json')['status'],'FAIL')
        self.assertEqual(v.read(root/'build.status.json')['raw_exit_code'],3)

    def test_signal_code_and_runner_log(self):
        self.assertEqual(v.process_code(-15),143)
        root=self.directory(); terminal=io.StringIO()
        with (root/'runner.log').open('w') as log:
            tee=v.Tee(terminal,log); tee.write('失败原因\n')
        self.assertEqual(terminal.getvalue(),(root/'runner.log').read_text())


if __name__=='__main__':
    unittest.main()
