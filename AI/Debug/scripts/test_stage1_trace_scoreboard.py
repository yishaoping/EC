#!/usr/bin/env python3
"""Small offline regressions for the Stage 1 trace analyzer."""
import importlib.util
import pathlib
import unittest

HERE = pathlib.Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location("stage1_trace_scoreboard", HERE / "stage1_trace_scoreboard.py")
scoreboard = importlib.util.module_from_spec(spec)
spec.loader.exec_module(scoreboard)


def analyze(lines, workload=None):
    board = scoreboard.Scoreboard(workload)
    for number, line in enumerate(lines.splitlines(), 1):
        board.consume((line + "\n").encode(), number)
    return board.finish()


def drained_exit(stq=0, inflight=0):
    cache = ('s1_valid s2_valid mshr_outstanding replay_valid replay_busy replay_result_q '
             'completion_q s3_valid store_done_valid wb_valid probe_valid refill_valid '
             'install_active completion_pending killed_store slot_reserved cross_package_pending '
             'pending_response response_valid mem_finish mem_grant mem_acquire')
    return ("STAGE1_TX EXIT_DRAIN snapshot=sim_exit source=DCACHE schema=1 fence_ready=1 " +
            ' '.join(k+'=0' for k in cache.split()) + "\n" +
            "STAGE1_TX EXIT_DRAIN snapshot=sim_exit source=LSU schema=1 " +
            "stq_valid=%x stq_committed=%x stq_inflight=%x stq_done=0 hella_pending=0 force_order=0\n" % (stq, stq, inflight))


def clear_trace(check=True, epoch=2):
    return ("STAGE1_TX CLEAR cycle=1 set=0 way=0 epoch=1\n" +
            ("STAGE1_TX CLEAR_CHECK cycle=1 set=0 way=0 fire=1 s1_any=1 s2_any=0 "
             "s1_old=0 s2_old=0 s3=0 completion=0 slot_conflict=0\n" if check else "") +
            "STAGE1_TX INSTALL cycle=2 set=0 way=0 line=100 epoch=%x mshr=0 txn=1\n" % epoch +
            "STAGE1_TX REFILL cycle=3 set=0 way=0 line=100 epoch=%x mshr=0 txn=1 beat=0\n" % epoch)


class TraceScoreboardTest(unittest.TestCase):
    def test_software_failure_is_not_silently_ignored_or_mislabeled_data_error(self):
        result = analyze('[ASSERT] store arch=1 strict=1 checker=2 result=FAIL\n'
                         '[END] hart=0 status=FAIL\n')
        self.assertEqual(result['gates']['software_report'], 'FAIL')
        self.assertEqual(len(result['software_failures']), 2)
        self.assertEqual(result['architectural_errors'], [])
        self.assertEqual(analyze('[END] hart=0 status=PASS\n')['gates']['software_report'], 'PASS')

    def test_negative_pc_delta_and_exact_occurrence_sets(self):
        rows = ['STAGE1_TX BOOM_STAT class=ARCH kind=LOAD token=%x seq=1 pc=%x addr=300 cacheable=1' % (i, 0x200+i)
                for i in range(40)]
        rows += ['STAGE1_TX CHECKER_STAT kind=LOAD token=1 pc=%x addr=300 cacheable=1' % (0x200+i)
                 for i in range(40)]
        rows += ['STAGE1_TX CHECKER_STAT kind=LOAD token=1 pc=900 addr=300 cacheable=1']
        result = analyze('\n'.join(rows))
        self.assertEqual(result['full_trace_pc_delta'], [dict(kind='LOAD', pc='0x900', cacheable=1, delta=-1)])
        self.assertEqual(len(result['accounting_sets']['CHECKER_ONLY']), 1)
        self.assertEqual(result['checker_duplicate_identity'], 'UNAVAILABLE_IN_TRACE')

    def test_equal_package_totals_do_not_hide_different_addresses(self):
        trace = ('STAGE1_TX BOOM_STAT class=ARCH kind=LOAD token=1 seq=2 pc=200 addr=300 cacheable=1\n'
                 'STAGE1_TX CHECKER_STAT kind=LOAD token=2 pc=200 addr=400 cacheable=1\n'
                 '[TRAFFIC] boom_arch 0 0 0 1 1 0\n[TRAFFIC] checker_sum 0 0 0 1 1 0\n')
        result = analyze(trace)
        self.assertEqual(result['gates']['main_checker'], 'FAIL')
        self.assertEqual(len(result['accounting_sets']['MAIN_ONLY']), 1)

    def test_loop_occurrences_are_not_duplicates(self):
        rows = []
        for i in range(3):
            rows += ['STAGE1_TX BOOM_STAT class=ARCH kind=LOAD token=%x seq=2 pc=200 addr=300 cacheable=1' % i,
                     'STAGE1_TX CHECKER_STAT kind=LOAD token=2 pc=200 addr=300 cacheable=1 hart=1 ordinal=%x' % i]
        result = analyze('\n'.join(rows))
        self.assertFalse(any(result['accounting_sets'].values()))
        self.assertEqual(result['checker_duplicate_identity'], 'AVAILABLE')
        result = analyze('\n'.join(rows + [rows[0], rows[1]]))
        self.assertEqual(len(result['accounting_sets']['DUP_IN_MAIN']), 1)
        self.assertEqual(len(result['accounting_sets']['DUP_IN_CHECKER']), 1)

    def test_counter_snapshot_must_agree_with_trace(self):
        result = analyze('STAGE1_TX BOOM_STAT class=ARCH kind=LOAD token=1 seq=2 pc=200 addr=300 cacheable=1\n'
                         'STAGE1_TX CHECKER_STAT kind=LOAD token=2 pc=200 addr=300 cacheable=1\n'
                         '[TRAFFIC] boom_arch 0 0 0 5 5 0\n[TRAFFIC] checker_sum 0 0 0 5 5 0\n')
        self.assertEqual(result['errors']['STAT_COUNTER_MISMATCH_MAIN'], 1)
        self.assertEqual(result['gates']['main_checker'], 'FAIL')

    def test_closure_requires_counter_events_and_checker_identity(self):
        report = '[TRAFFIC] boom_arch 0 0 0 1 1 0\n[TRAFFIC] checker_sum 0 0 0 1 1 0\n'
        result = analyze(report)
        self.assertEqual(result['errors']['STAT_COUNTER_MISMATCH_MAIN'], 1)
        trace = ('STAGE1_TX BOOM_STAT class=ARCH kind=LOAD token=1 seq=2 pc=200 addr=300 cacheable=1\n'
                 'STAGE1_TX CHECKER_STAT kind=LOAD token=2 pc=200 addr=300 cacheable=1\n')
        self.assertEqual(analyze(trace + report)['gates']['main_checker'], 'UNRESOLVED')
        self.assertEqual(analyze('')['gates']['software_report'], 'UNRESOLVED')

    def test_overlap_counts_do_not_confuse_other_slots_with_collision(self):
        trace = clear_trace() + ('STAGE1_TX INSTALL cycle=5 set=1 way=0 line=140 epoch=1 mshr=1 txn=2\n'
            'STAGE1_TX S2 cycle=5 req=1 admission=7 set=2 way=0\n'
            'STAGE1_TX RACE_OBSERVE cycle=5 kill_replay=1 s1_replay_killed=0 s2_replay_killed=1\n')
        result = analyze(trace)
        self.assertEqual(result['race_coverage']['install_hit'], 1)
        self.assertEqual(result['race_coverage']['kill_replay'], 1)
        self.assertEqual(result['race_violations'], 0)

    def test_architectural_s3_kill_cannot_have_effect(self):
        result = analyze('STAGE1_TX KILL cycle=1 req=9 phase=S3\n'
                         'STAGE1_TX EFFECT cycle=2 req=9 cmd=1 data=1\n')
        self.assertEqual(result['errors']['KILLED_EFFECT'], 1)
        self.assertEqual(result['gates']['clear_s1_s2_refill'], 'FAIL')

    def test_effect_terminal_release_exactly_once(self):
        result = analyze("""
STAGE1_TX ISSUE cmd=01 size=3 stq=0 req=1 effect=1 seq=1 addr=100
STAGE1_TX EFFECT cycle=1 cmd=01 size=3 stq=0 req=1 effect=1 txn=1 epoch=1 gen=1 addr=100 data=2
STAGE1_TX TERMINAL cycle=2 status=0 cmd=01 size=3 stq=0 req=1 effect=1 txn=1 data=2
STAGE1_TX STORE_DONE cmd=01 size=3 stq=0 req=1 effect=1 status=0 data=2
STAGE1_TX RELEASE stq=0 req=1 committed=1 done=1 inflight=0
""")
        self.assertEqual(result["errors"], {})
        self.assertEqual(result["gates"]["effect_terminal"], "PASS")
        self.assertEqual(result["gates"]["terminal_release"], "PASS")

    def test_amo_w_upper_lane_sign_extension(self):
        result = analyze("""
STAGE1_TX ISSUE cmd=04 size=2 stq=0 req=2 effect=2 seq=1 addr=104
STAGE1_TX EFFECT cycle=1 cmd=04 size=2 stq=0 req=2 effect=2 txn=1 epoch=1 gen=1 addr=104 data=8000000000000000 old=7fffffff00000000 operand=8000000080000000 new=8000000000000000 returned=000000007fffffff mask=f0
STAGE1_TX TERMINAL cycle=2 status=0 cmd=04 size=2 stq=0 req=2 effect=2 txn=1 data=000000007fffffff
STAGE1_TX STORE_DONE cmd=04 size=2 stq=0 req=2 effect=2 status=0 data=000000007fffffff
STAGE1_TX RELEASE stq=0 req=2 committed=1 done=1 inflight=0
""")
        self.assertNotIn("AMO_SEMANTICS", result["errors"])
        self.assertNotIn("AMO_RETURN", result["errors"])
        self.assertEqual(result["amo_coverage"], [{"cmd": 4, "size": 2, "lane": 4, "count": 1}])

    def test_effect_without_terminal_is_reported(self):
        result = analyze("STAGE1_TX EFFECT cmd=01 size=3 stq=0 req=3 effect=3 txn=1 data=1\n")
        self.assertEqual(result["errors"]["EFFECT_WITHOUT_TERMINAL"], 1)
        self.assertEqual(result["gates"]["lost_effect"], "FAIL")


    def test_clear_check_same_cycle_printf_order(self):
        trace = clear_trace().splitlines()
        trace[0], trace[1] = trace[1], trace[0]
        result = analyze('\n'.join(trace))
        self.assertEqual(result['gates']['clear_s1_s2_refill'], 'PASS')
        self.assertEqual(result['race_coverage']['s1_any'], 1)

    def test_clear_missing_check_is_failure(self):
        result = analyze(clear_trace(check=False))
        self.assertEqual(result['gates']['clear_s1_s2_refill'], 'FAIL')
        self.assertEqual(result['errors']['CLEAR_CHECK_MISSING'], 1)

    def test_clear_stale_epoch_is_failure(self):
        result = analyze(clear_trace(epoch=1))
        self.assertEqual(result['errors']['STALE_POST_CLEAR_REFILL'], 1)

    def test_refill_wrong_owner_and_duplicate_beat(self):
        trace = clear_trace() + 'STAGE1_TX REFILL cycle=4 set=0 way=0 line=100 epoch=2 mshr=0 txn=2 beat=0\n'
        result = analyze(trace)
        self.assertEqual(result['errors']['REFILL_OWNER_MISMATCH'], 1)
        self.assertEqual(result['errors']['REFILL_BEAT_ORDER'], 1)

    def test_exit_loop_unissued_commit_requires_exact_live_owner(self):
        workload = dict(exit_pc_range=[0x200, 0x210], exit_addresses=[0x300])
        trace = ('STAGE1_TX ARCH_STORE token=7 stq=0 pc=204 addr=300 cmd=1 size=3 fence=0\n' +
                 drained_exit(stq=1) +
                 'STAGE1_TX EXIT_STQ snapshot=sim_exit token=7 stq=0 pc=204 addr=300 flags=a3\n')
        result = analyze(trace, workload)
        self.assertNotIn('LOST_ARCH_STORE', result['errors'])
        self.assertEqual(len(result['exit_tail']), 1)
        self.assertEqual(result['exit_real_outstanding'], 0)
        # The same exit PC does not hide an owner that vanished from the STQ.
        result = analyze(trace.replace('token=7 stq=0 pc=204 addr=300 flags=a3',
                                       'token=8 stq=0 pc=204 addr=300 flags=a3'), workload)
        self.assertEqual(result['errors']['LOST_ARCH_STORE'], 1)
        self.assertEqual(result['gates']['lost_effect'], 'FAIL')

    def test_exit_loop_issued_transaction_is_real_outstanding(self):
        trace = ('STAGE1_TX ARCH_STORE token=7 stq=0 pc=204 addr=300 cmd=1 size=3 fence=0\n' +
                 drained_exit(stq=1, inflight=1) +
                 'STAGE1_TX EXIT_STQ snapshot=sim_exit token=7 stq=0 pc=204 addr=300 flags=a7\n')
        result = analyze(trace, dict(exit_pc_range=[0x200, 0x210], exit_addresses=[0x300]))
        self.assertEqual(result['exit_real_outstanding'], 1)
        self.assertEqual(result['gates']['exit_outstanding'], 'FAIL')
        self.assertEqual([t['token'] for t in result['real_outstanding']], [7])

    def test_exit_snapshot_cannot_waive_effect_without_terminal(self):
        result = analyze('STAGE1_TX EFFECT req=7 effect=7 cmd=1 data=1\n' + drained_exit())
        self.assertEqual(result['errors']['EFFECT_WITHOUT_TERMINAL'], 1)

    def test_terminal_with_no_release_event_is_failure(self):
        result = analyze('STAGE1_TX TERMINAL req=7 effect=7 cmd=1 status=0 data=1\n')
        self.assertEqual(result['gates']['terminal_release'], 'FAIL')

    def test_missing_exit_snapshot_is_unresolved(self):
        self.assertEqual(analyze('')['gates']['exit_outstanding'], 'UNRESOLVED')

    def test_missing_fence_ready_snapshot_is_unresolved(self):
        result = analyze(drained_exit().replace('fence_ready=1 ', ''))
        self.assertEqual(result['gates']['exit_outstanding'], 'UNRESOLVED')

    def test_parked_prefetch_owner_is_not_an_active_transaction(self):
        trace = drained_exit().replace('mshr_outstanding=0', 'mshr_outstanding=0 mshr_owners=1')
        self.assertEqual(analyze(trace)['exit_real_outstanding'], 0)
        self.assertEqual(analyze(trace.replace('mshr_outstanding=0', 'mshr_outstanding=1'))[
            'gates']['exit_outstanding'], 'FAIL')

    def test_unknown_committed_stq_owner_cannot_disappear(self):
        trace = drained_exit(stq=1) + 'STAGE1_TX EXIT_STQ snapshot=sim_exit token=8 stq=0 pc=204 addr=300 flags=a3\n'
        result = analyze(trace)
        self.assertEqual(result['errors']['EXIT_STQ_WITHOUT_ARCH'], 1)
        self.assertEqual(result['gates']['lost_effect'], 'FAIL')
        self.assertEqual(result['gates']['exit_outstanding'], 'FAIL')

    def test_exit_loop_exemption_requires_ready_physical_owner_and_no_grant(self):
        trace = ('STAGE1_TX ARCH_STORE token=7 stq=0 pc=204 addr=300 cmd=1 size=3 fence=0\n' +
                 drained_exit(stq=1) +
                 'STAGE1_TX EXIT_STQ snapshot=sim_exit token=7 stq=0 pc=204 addr=300 flags=%s\n')
        workload = dict(exit_pc_range=[0x200, 0x210], exit_addresses=[0x300])
        for flags in ('3', 'e3'):
            self.assertEqual(analyze(trace % flags, workload)['gates']['exit_outstanding'], 'FAIL')
        accepted = 'STAGE1_TX ISSUE source=DCACHE req=7 stq=0 pc=204 addr=300 cmd=1 size=3\n'
        self.assertEqual(analyze(accepted + trace % 'a3', workload)['gates']['exit_outstanding'], 'FAIL')

    def test_main_checker_cancelling_total_differences_still_fail(self):
        result = analyze('[TRAFFIC] boom_arch 5 5 0 3 3 0\n'
                         '[TRAFFIC] checker_sum 4 4 0 4 4 0\n')
        self.assertEqual(result['gates']['main_checker'], 'FAIL')
        self.assertEqual(sum(result['reported_diff'][i] for i in (0,3)), 0)

    def test_package_identity_catches_balanced_global_counts(self):
        result = analyze('STAGE1_TX BOOM_STAT kind=LOAD class=ARCH token=1 pc=200 addr=300 cacheable=1 seq=2\n'
                         'STAGE1_TX CHECKER_STAT kind=LOAD token=3 pc=200 addr=300 cacheable=1\n'
                         '[TRAFFIC] boom_arch 0 0 0 1 1 0\n'
                         '[TRAFFIC] checker_sum 0 0 0 1 1 0\n')
        self.assertEqual(result['gates']['main_checker'], 'FAIL')

    def test_serial_success_requires_verified_data(self):
        self.assertEqual(analyze('STAGE1_SIM_EXIT reason=serial_success cycles=1\n')['gates']['architectural_data'], 'UNRESOLVED')
        trace = '[RUN] benchmark=bfs verified=0\nSTAGE1_SIM_EXIT reason=serial_success cycles=1\n'
        self.assertEqual(analyze(trace)['gates']['architectural_data'], 'FAIL')

    def test_complete_closure_can_pass_without_vacuous_race_or_amo(self):
        trace = clear_trace() + """
STAGE1_TX ARCH_STORE token=1 stq=0 pc=200 addr=100 cmd=4 size=2 fence=0
STAGE1_TX EFFECT cycle=4 cmd=4 size=2 stq=0 req=1 effect=1 txn=1 epoch=2 addr=100 data=fffffffc76543210 old=fffffffc80000001 operand=7654321076543210 new=fffffffc76543210 returned=ffffffff80000001 mask=0f set=0 way=0 owner_match=1
STAGE1_TX TERMINAL cycle=5 status=0 cmd=4 size=2 stq=0 req=1 effect=1 data=ffffffff80000001
STAGE1_TX STORE_DONE cmd=4 stq=0 req=1 status=0 data=ffffffff80000001
STAGE1_TX RELEASE stq=0 req=1 committed=1 done=1 inflight=0 fence=0
STAGE1_TX ARCH_STORE token=2 stq=1 pc=204 addr=104 cmd=8 size=2 fence=0
STAGE1_TX EFFECT cycle=6 cmd=8 size=2 stq=1 req=2 effect=2 txn=1 epoch=2 addr=104 data=0000000376543210 old=fffffffc76543210 operand=0000000700000007 new=0000000376543210 returned=fffffffffffffffc mask=f0 set=0 way=0 owner_match=1
STAGE1_TX TERMINAL cycle=7 status=0 cmd=8 size=2 stq=1 req=2 effect=2 data=fffffffffffffffc
STAGE1_TX STORE_DONE cmd=8 stq=1 req=2 status=0 data=fffffffffffffffc
STAGE1_TX RELEASE stq=1 req=2 committed=1 done=1 inflight=0 fence=0
STAGE1_TX REPLAY_GRANT mshr=0 txn=1 req=1
STAGE1_TX REPLAY_RESULT mshr=0 txn=1 req=1 status=0
STAGE1_TX BOOM_STAT kind=LOAD class=ARCH token=3 pc=208 addr=104 cacheable=1 seq=1
STAGE1_TX CHECKER_STAT kind=LOAD token=1 pc=208 addr=104 cacheable=1 hart=1 ordinal=1
[TRAFFIC] boom_arch 0 0 0 1 1 0
[TRAFFIC] checker_sum 0 0 0 1 1 0
[RUN] benchmark=bfs verified=1
[END] hart=0 status=PASS
STAGE1_SIM_EXIT reason=serial_success cycles=8
""" + drained_exit()
        result = analyze(trace)
        self.assertEqual(result['errors'], {})
        self.assertEqual(result['status'], 'PASS')

    def test_mmio_no_array_effect_and_hella_no_stq(self):
        trace = ('STAGE1_TX TERMINAL status=0 cmd=1 req=8 effect=8 data=1 admission=4 is_hella=1\n')
        self.assertEqual(analyze(trace)['errors'], {})


if __name__ == "__main__":
    unittest.main()
