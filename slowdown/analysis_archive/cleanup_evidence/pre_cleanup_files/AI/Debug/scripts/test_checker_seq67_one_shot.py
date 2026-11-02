#!/usr/bin/env python3
"""CPU/offline tests only. Protocol model is not an RTL simulation."""
import copy
import importlib.util
import hashlib
import itertools
import json
from pathlib import Path
import sys
import unittest
from unittest.mock import patch
import uuid
from types import SimpleNamespace

ROOT=Path(__file__).resolve().parents[3]
SCRIPTS=Path(__file__).resolve().parent


def module(name,file):
    s=importlib.util.spec_from_file_location(name,SCRIPTS/file)
    m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m


analyzer=module('seq67_test_analyzer','analyze_checker_seq67_one_shot.py')
launcher=module('seq67_test_launcher','launch_checker_seq67_one_shot.py')
dependency=module('seq67_test_dependency','audit_seq67_dispatch_dependencies.py')


class ProtocolModel:
    """Small executable specification: held CPS, real trap priority, xRET."""
    def __init__(self):
        self.pending=False;self.depth=0

    def step(self,cps=False,exception=False,eret=False):
        dispatch=self.pending and not self.depth and not exception and not eret
        # exception has priority over CSR's overloaded eret (ECALL/EBREAK).
        if exception:self.depth+=1
        elif eret and self.depth:self.depth-=1
        self.pending=True if cps else False if dispatch else self.pending
        return bool(dispatch)


class DependencyAuditTests(unittest.TestCase):
    def test_structural_constant_comparison_still_depends_on_retire(self):
        g,_=dependency.parse(['    node p = geq(io.retire, UInt<1>("h0"))\n'])
        self.assertIn('io.retire',g['p'])

    def test_register_is_a_sequential_boundary(self):
        g,_=dependency.parse(['    reg pending : UInt<1>, clock\n',
            '    pending <= check_exception\n','    node ready = not(pending)\n'])
        self.assertNotIn('pending',g);self.assertIn('pending',g['ready'])

    def test_reported_loop_and_raw_exception_counterfactual(self):
        core=['    inst csr of CSRFile_1\n','    node wb_valid = not(check_exception)\n',
            '    csr.io.retire <= wb_valid\n',
            '    node _privileged_start_ready_T_1 = not(csr.io.trace[0].exception)\n',
            '    check_exception <= _privileged_start_ready_T_1\n']
        csr=['    node trace = and(io.retire, io.exception)\n',
            '    io.trace[0].exception <= trace\n','    io.r_exception <= io.exception\n']
        modules={n:core for n in ['Rocket','Rocket_1','Rocket_2','Rocket_3']}
        modules['CSRFile_1']=csr
        self.assertTrue(all(r['status']=='PASS' for r in dependency.audit_modules(modules).values()))


class ProtocolTests(unittest.TestCase):
    def test_trap_free_timing_unchanged(self):
        m=ProtocolModel()
        self.assertFalse(m.step(cps=True));self.assertTrue(m.step());self.assertFalse(m.step())

    def test_original_collision_counterexample_is_blocked(self):
        m=ProtocolModel();m.step(cps=True)
        original_dispatch=True # original delayed CPS checked registered mode=0
        self.assertTrue(original_dispatch)
        self.assertFalse(m.step(exception=True,eret=True))
        self.assertTrue(m.pending);self.assertEqual(m.depth,1)
        for _ in range(20):self.assertFalse(m.step())
        self.assertFalse(m.step(eret=True));self.assertTrue(m.step())

    def test_nested_return_is_not_context_idle(self):
        m=ProtocolModel();m.step(exception=True);m.step(cps=True,exception=True)
        self.assertFalse(m.step(eret=True));self.assertEqual(m.depth,1)
        self.assertFalse(m.step());self.assertTrue(m.pending)
        m.step(eret=True);self.assertTrue(m.step())

    def test_current_xret_cannot_share_synthetic_redirect(self):
        m=ProtocolModel();m.step(cps=True)
        self.assertFalse(m.step(eret=True));self.assertTrue(m.step())

    def test_hold_through_arbitrary_trap_length(self):
        for length in [0,1,2,15,4096]:
            m=ProtocolModel();m.step(cps=True,exception=True)
            for _ in range(length):self.assertFalse(m.step())
            self.assertTrue(m.pending);m.step(eret=True)
            self.assertTrue(m.step());self.assertFalse(m.pending)

    def test_truth_table_never_dispatches_with_live_trap(self):
        for pending,depth,exception,eret in itertools.product([False,True],[0,1,2,15],[False,True],[False,True]):
            m=ProtocolModel();m.pending=pending;m.depth=depth
            self.assertEqual(m.step(exception=exception,eret=eret),pending and not depth and not exception and not eret)

    def test_scala_implements_the_reviewed_priority(self):
        core=(ROOT/'chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala').read_text()
        csr=(ROOT/'chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala').read_text()
        fsm=(ROOT/'chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala').read_text()
        self.assertIn('check_exception := privileged_start_requested && privileged_start_ready',core)
        self.assertIn('val privileged_start_ready = !excpt_mode && !csr.io.r_exception.asBool && !csr.io.eret',core)
        self.assertTrue('io.r_exception := exception' in csr)
        self.assertIn('io.eret := insn_call || insn_break || insn_ret',csr)
        self.assertIn('when (io.if_check_privrun && !icsl_run.asBool && io.self_xcpt)',fsm)
        self.assertIn('resume_state                            := fsm_checking_priv',fsm)
        self.assertIn('io.package_result_valid := package_result_queue.io.deq.valid &&',core)
        boom=(ROOT/'chipyard/generators/boom/src/main/scala/exu/core.scala').read_text()
        self.assertTrue('assert(!little_status3(checkerHangWatchdogBit), "little core 3 has hung")' in boom)
        rel='chipyard/generators/boom/src/main/scala/exu/core.scala'
        seal=json.loads((ROOT/'AI/TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/revisions/r2/source_seal.json').read_text())
        self.assertEqual(hashlib.sha256((ROOT/rel).read_bytes()).hexdigest(),seal['hardware_sha256'][rel])

    def test_diagnostics_are_bounded_and_not_control_inputs(self):
        core=(ROOT/'chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala').read_text()
        start=core.index('// SEQ67_BOUNDED_DIAGNOSTICS_BEGIN');end=core.index('// SEQ67_BOUNDED_DIAGNOSTICS_END')
        block=core[start:end]
        self.assertIn('seq67TargetRows < 64.U',block);self.assertIn('seq67ConflictRows < 16.U',block)
        self.assertIn('seq67SummaryRows < 128.U',block)
        self.assertIn('safeChainCheckerKey, icsl.io.debug_state',block)
        self.assertIn('Seq.fill(10)(0.U(32.W))',block)
        self.assertNotIn('seq67',core[end+len('// SEQ67_BOUNDED_DIAGNOSTICS_END'):])
        self.assertNotIn('check_exception :=',block)


class DiagnosticTests(unittest.TestCase):
    def fixture(self):
        report=Path((ROOT/'AI/TMP/.checker_seq67_one_shot').read_text().strip())
        r=report/'offline_test_cases'/uuid.uuid4().hex;r.mkdir(parents=True)
        (r/'SYNTHETIC_ONLY.txt').write_text('Offline synthetic diagnostic fixture; NOT hardware evidence.\n')
        rows=[]
        def add(cycle,kind,hart,n):
            rows.append(dict(cycle=cycle,kind=kind,hart=hart,n=n+[0]*(16-len(n))))
        def life(cycle,bits,ctx):
            add(cycle,46,3,[67,1,0,sum(1<<b for b in bits),ctx,1,0,0,0,0,0,0,0,0,cycle,0])
        life(0,[20],1);life(2,[21],1);life(8,[8,9,16],0);life(10,[8,17],1)
        add(12,3,3,[67,3,67,7])
        for h in range(1,5):add(10,47,h,[67 if h==3 else 68+h,1,0]+[0]*10+[4,0,1])
        self.write(r,rows);return r,rows

    def write(self,r,rows):
        lines=[];capture=dict(observers={},producers={})
        for row in rows:
            lines.append('\t'.join(['SC1',str(row['cycle']),str(row['cycle']),str(row['cycle']), '1',str(row['kind']),str(row['hart'])]+[f'{v:016x}' for v in row['n']]))
            if row['kind'] not in [46,47]:continue
            key=f'{row["kind"]}:{row["hart"]}'
            capture['observers'].setdefault(key,dict(events_seen=0,omitted=0,footers_seen=1))['events_seen']+=1
        for key,obs in capture['observers'].items():
            obs['footer_emitted_count']=obs['events_seen']
            capture['producers'][key]=dict(produced=obs['events_seen'],emitted=obs['events_seen'],omitted=0)
        (r/'safe_chain_events.tsv').write_text('\n'.join(lines)+'\n')
        (r/'capture_summary.json').write_text(json.dumps(capture))

    def test_complete_lifecycle(self):
        r,_=self.fixture();self.assertEqual(analyzer.diagnostic_validation(r)['status'],'PASS')

    def test_missing_exec_done_rejected(self):
        r,rows=self.fixture()
        for row in rows:
            if row['kind']==46:row['n'][3]&=~(1<<8)
        self.write(r,rows);self.assertEqual(analyzer.diagnostic_validation(r)['status'],'FAIL')

    def test_missing_start_rejected_without_exception(self):
        r,rows=self.fixture();rows=[x for x in rows if x['cycle']!=2]
        self.write(r,rows);self.assertFalse(analyzer.diagnostic_validation(r)['gates']['ordered_lifecycle'])

    def test_dirty_handoff_rejected(self):
        r,rows=self.fixture();rows[3]['n'][4]=5;self.write(r,rows)
        self.assertFalse(analyzer.diagnostic_validation(r)['gates']['handoff_context_clean'])

    def test_cancel_count_rejected(self):
        r,rows=self.fixture();rows[-1]['n'][8]=1;self.write(r,rows)
        self.assertFalse(analyzer.diagnostic_validation(r)['gates']['no_global_cancel'])

    def test_bad_start_count_rejected(self):
        r,rows=self.fixture();rows[-1]['n'][7]=1;self.write(r,rows)
        self.assertFalse(analyzer.diagnostic_validation(r)['gates']['no_stale_trap_start'])

    def test_mandatory_loss_rejected(self):
        r,_=self.fixture();p=r/'capture_summary.json';c=json.loads(p.read_text())
        c['observers']['46:3']['omitted']=1;p.write_text(json.dumps(c))
        self.assertFalse(analyzer.diagnostic_validation(r)['gates']['mandatory_capture'])

    def test_early_boom_accept_rejected(self):
        r,rows=self.fixture();rows[4]['cycle']=4;self.write(r,rows)
        self.assertFalse(analyzer.diagnostic_validation(r)['gates']['ordered_lifecycle'])

    def test_claim_and_static_check_never_launch_hardware(self):
        with patch.object(sys,'argv',['one-shot','--report','AI/TMP/synthetic','--static-check']), \
             patch.object(launcher,'preflight',return_value={'run_target':'B_ONLY_64K_2WAY'}), \
             patch.object(launcher.subprocess,'run') as run:
            self.assertEqual(launcher.main(),0);run.assert_not_called()

    def test_existing_claim_prevents_second_launch(self):
        r,_=self.fixture();(r/'B_LAUNCH_CLAIM.json').write_text('{}')
        with patch.object(sys,'argv',['one-shot','--report',str(r)]), \
             patch.object(launcher,'preflight',return_value={'run_target':'B_ONLY_64K_2WAY'}), \
             patch.object(launcher.subprocess,'run') as run:
            with self.assertRaises(FileExistsError):launcher.main()
            run.assert_not_called()

    def test_real_entry_point_requests_one_B_and_offline_analysis_only(self):
        r,_=self.fixture()
        with patch.object(sys,'argv',['one-shot','--report',str(r)]), \
             patch.object(launcher,'preflight',return_value={'run_target':'B_ONLY_64K_2WAY'}), \
             patch.object(launcher.subprocess,'run',return_value=SimpleNamespace(returncode=0)) as run:
            self.assertEqual(launcher.main(),0)
            self.assertEqual(run.call_count,2)
            launch_argv=run.call_args_list[0].args[0]
            self.assertEqual(launch_argv[launch_argv.index('--l1-causal-arm')+1],'B')
            self.assertIn('analyze_checker_seq67_one_shot.py',run.call_args_list[1].args[0][3])

    def analysis_fixture(self,diag_status='PASS'):
        r,_=self.fixture();run=r/'sealed/arms/B/runs/synthetic';run.mkdir(parents=True)
        (run/'analysis').mkdir();(run/'run_manifest.json').write_text('{}')
        (r/'one_shot_contract.json').write_text(json.dumps({'a_revision':'/synthetic'}))
        (r/'a_non_interference_proof.json').write_text(json.dumps({'proven':False,'complete_dynamic_coverage':False}))
        a=dict(valid=True,manifest='/synthetic/A',gates={'fixture':True},roi_cycles=1707863,
            causal={'counts':{'sample_cycles':1707863,'mshr_busy_cycles':313150},'latency_histograms':[]},actual_l1={'miss':3272})
        b=copy.deepcopy(a);b.update(manifest=str(run/'run_manifest.json'),roi_cycles=1600000)
        b['causal']['counts'].update(sample_cycles=1600000,mshr_busy_cycles=200000);b['actual_l1']['miss']=1500
        with patch.object(analyzer,'module',return_value=SimpleNamespace(preflight=lambda _:None)), \
             patch.object(analyzer.pair,'arm',side_effect=[a,b]), \
             patch.object(analyzer,'diagnostic_validation',return_value={'status':diag_status,'gates':{'fixture':diag_status=='PASS'}}), \
             patch.object(analyzer,'collect_provenance',return_value={'status':'PASS','checks':{'fixture':True}}):
            return analyzer.analyze(r)

    def test_B_pass_with_unproven_A_stays_explicitly_unpaired(self):
        result=self.analysis_fixture()
        self.assertEqual(result['status'],'CORRECTNESS_CLOSED_BUT_STRICT_PAIRING_REQUIRES_BASELINE_REFRESH')
        self.assertFalse(result['comparison']['strict_causal_interpretation_allowed'])
        self.assertEqual(result['strict_performance_decision'],'NOT_ESTABLISHED')
        self.assertEqual(result['additional_runs_scheduled'],0)

    def test_diagnostic_failure_blocks_all_performance_differences(self):
        result=self.analysis_fixture('FAIL')
        self.assertEqual(result['status'],'INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT')
        self.assertIsNone(result['comparison'])


if __name__=='__main__':unittest.main()
