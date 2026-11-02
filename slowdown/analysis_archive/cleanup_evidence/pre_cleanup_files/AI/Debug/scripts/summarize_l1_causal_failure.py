#!/usr/bin/env python3
"""Extract saved checker3/sequence67 evidence without interpreting failed performance."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
report = Path((ROOT / 'AI/TMP/.l1_causal_active').read_text().strip())
revision = Path((ROOT / 'AI/TMP/.l1_causal_revision').read_text().strip())
run = next((revision / 'arms/B/runs').iterdir())
checker_names = ['package_check_active', 'package_start_pending', 'producer_sealed_for_package',
    'packet_ingress_drained', 'lsl_quiescent', 'arf_check_complete', 'csr_check_required',
    'csr_check_complete', 'package_exec_done', 'full_check_complete', 'checker_cleanup_done',
    'package_result_handoff_allowed', 'package_result_waiting', 'package_result_outstanding',
    'package_cleanup_pending', 'result_queue_deq_valid', 'package_result_fire',
    'package_result_handoff_fire', 'package_cancelled', 'arf_done_owned', 'new_package',
    'package_start_accepted', 'package_error', 'package_transport_error', 'ecp_complete',
    'compare_busy', 'ic_counter_valid']
context_names = ['context_idle', 'return_pending', 'excpt_mode', 'checker_clear_pending',
    'checker_clear_done', 'compare_idle', 'ecp_idle', 'arch_compare_ready',
    'arf_wait_timeout', 'package_exec_timeout', 'package_progress_timeout']
rows = []
for line_number, line in enumerate((run / 'safe_chain_events.tsv').read_text().splitlines(), 1):
    fields = line.split('\t')
    if len(fields) != 23 or fields[0] != 'SC1':
        continue
    nums = [int(x, 16) for x in fields[7:]]
    kind, hart = int(fields[5]), int(fields[6])
    if kind not in [3, 6, 13]:
        continue
    if not ((hart == 3 and nums[0] in [63, 67]) or (kind == 3 and nums[1] & 48)):
        continue
    row = dict(source_line=line_number, kind=kind, hart=hart, host_tick=int(fields[1]),
        global_cycle=int(fields[2]), local_cycle=int(fields[3]), nums=nums)
    if kind == 6:
        row['checker_flags'] = {name: bool(nums[2] & (1 << i)) for i, name in enumerate(checker_names)}
        row['context_flags'] = {name: bool(nums[3] & (1 << i)) for i, name in enumerate(context_names)}
        row['icsl_trap_depth'] = nums[3] >> 11
        row['result_queue_status'] = nums[6] >> 32
        row['result_queue_seq'] = nums[6] & 0xffffffff
    rows.append(row)
hashes = {}
for path in [run / 'stdout.log', run / 'stderr.log', run / 'safe_chain_events.tsv',
             run / 'hang_ringbuffer.tsv',
             ROOT / 'chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala',
             ROOT / 'chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala',
             ROOT / 'chipyard/generators/rocket-chip/src/main/scala/util/Counters.scala']:
    hashes[str(path)] = hashlib.sha256(path.read_bytes()).hexdigest()
out = dict(scope='r2 B failed runtime; no ROI or performance attribution', run=str(run),
    counter_unit='SC column2 global BOOM cycle; column3 local checker cycle; no invented clock ratio',
    assertion='BoomCore.sv:6977 assert_24 / core.scala:2211 little_status3(18)',
    threshold_cycles=1 << 18, rows=rows, sha256=hashes,
    conclusions={
        'proven_symptom': 'checker3 ownership watchdog assertion; benchmark and software ROI did not complete',
        'proven_immediate_block': 'sequence67 CANCEL enqueued locally but cleanup/context_idle and result handoff remain false in final lifecycle record',
        'supported_trigger': 'sequence67 executes no new frontend accepted-response progress after admission; excpt_mode stays set in recorded lifecycle transitions',
        'unproven_root': 'exact trap/start/return or instruction-boundary trigger; no waveform was captured for this run',
        'not_established': 'L2 observer mismatch, actual corrupted cache data, MSHR exhaustion or SVB capacity root cause'})
(report / 'r2_B_failure_evidence.json').write_text(json.dumps(out, indent=2) + '\n')
last = [row for row in rows if row['kind'] == 6 and row['nums'][0] == 67][-1]
print(json.dumps({'selected_rows': len(rows), 'last_checker3': last}, indent=2))
