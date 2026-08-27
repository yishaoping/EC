#!/usr/bin/env bash
set -euo pipefail

# Read-only trace helper for the 1187000 / assert__assert_24 failure.
# test.vcd is an FST container despite its suffix.
#
# Usage:
#   trace_assert24_1187.sh [trap|watchdog|rocc|backpressure|final] [fst]

repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
mode=${1:-trap}
fst_file=${2:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
trace_bin=${FST_TRACE_BIN:-"$repo_dir/Debug/fst_signal_trace"}

if [[ ! -x "$trace_bin" ]]; then
  printf 'missing executable FST reader: %s\n' "$trace_bin" >&2
  exit 2
fi

case "$mode" in
  trap)
    # seq40 postchecking -> timer interrupt -> forced pc_special return ->
    # seq45 admission while excpt_mode remains asserted.
    "$trace_bin" "$fst_file" 277350 278080 \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_3\.tile_reset_domain_tile\.core\.(excpt_mode|pc_special|wb_reg_(pc|valid)|csr\.io_(trace_0_(exception|cause|valid|iaddr)|eret)|icsl\.(fsm_state|io_(self_xcpt|self_ret|if_ret_special_pc|returned_to_special_address_valid|icsl_checkermode|if_correct_process|cleanup_done|package_exec_done)|sl_counter|package_completion_(ready|seen))|io_if_correct_process|package_(seq_reg|check_active|start_pending|start_accepted|result_event|result_fire|result_outstanding|cleanup_pending)|full_check_complete|io_package_result_(valid|ready|seq|status)|io_arf_copy_in)([[:space:]]\[[^]]+\])?$' \
      '^TOP\.TestHarness\.chiptop\.system\.(ghm_result_deq_fire_2|ghm_result_release_pending_2)$' \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(io_clear_ic_status_tomain|ic_master\.(io_ic_status_3|io_checker_segment_id_3|packet_seq_counter|io_packet_alloc_valid|crnt_target))([[:space:]]\[[^]]+\])?$'
    ;;
  watchdog)
    # The threshold edge.  2374965 - 277813 = 2^21 FST units, or 2^20
    # BOOM cycles at the observed two-FST-unit BOOM period.
    env FST_TRACE_FINAL=1 "$trace_bin" "$fst_file" 2374900 2374966 \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(large_[1-4]|small_[1-4]|nextSmall_[1-4]|io_clear_ic_status_tomain|ic_master\.io_ic_status_[1-4])([[:space:]]\[[^]]+\])?$' \
      '^TOP\.TestHarness\.chiptop\.system\.(ghm_result_deq_fire_2|ghm_result_release_pending_2)$'
    ;;
  rocc)
    # A repeated ght_get_status/funct=0x06 command on checker hart3.  The
    # checker is outside checker mode, so the local zero GHE response is used;
    # no RoCC-log dequeue is requested.
    env FST_TRACE_FINAL=1 "$trace_bin" "$fst_file" 2298990 2299035 \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_3\.tile_reset_domain_tile\.(ghe_(doBigCheckComp|bigComp_reg)|core\.(wb_reg_(pc|inst|valid)|wb_ctrl_(rocc|wxd)|io_rocc_resp_(valid|ready|bits_data|bits_rd)|lsl_req_valid_rocc|lsl_resp_replay_rocc|lsl_req_ready_rocc|lsl_resp_data_rocc|ll_(wen|wdata|waddr)|rf_(wen|wdata|waddr)|icsl\.io_icsl_checkermode|excpt_mode|package_check_active|lsl\.io_(req_valid_rocc|req_ready_rocc|resp_data_rocc)))([[:space:]]\[[^]]+\])?$'
    ;;
  backpressure)
    # checker4 seq53: LSL near-full deasserts its own ready at 320577, while
    # the type-insensitive OR keeps aggregate packet ready high until 321041.
    "$trace_bin" "$fst_file" 320520 321100 \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_4\.tile_reset_domain_tile\.core\.(io_packet_cdc_ready|io_imem_bjl_cdc_ready|rsu_slave\.io_cdc_ready|io_packet_lsl_[01]|lsl\.(io_(cdc_ready|near_full|lsl_highwatermark|req_valid|req_ready)|lsl_(enq|deq)_ptr|u_channel_[01]\.io_(empty|enq_valid|deq_ready)))([[:space:]]\[[^]]+\])?$' \
      '^TOP\.TestHarness\.chiptop\.system\.ghm_u_data_cdc_3\.io_deq_(valid|ready|bits)([[:space:]]\[[^]]+\])?$'
    ;;
  final)
    # Cross-check all four Rocket package trackers at the assertion edge.
    env FST_TRACE_FINAL=1 "$trace_bin" "$fst_file" 2374900 2374966 \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_[1-4]\.tile_reset_domain_tile\.core\.(package_(seq_reg|check_active|start_pending|data_complete|exec_waiting|exec_timeout_counter|cancelled|result_event)|full_check_complete|io_(cdc_empty|if_correct_process|rsu_status|package_result_valid)|excpt_mode|checker_local_cleanup_done|rsu_slave\.rsu_status|lsl\.io_if_empty|icsl\.(fsm_state|io_(icsl_checkermode|cleanup_done|package_exec_done|if_correct_process)|sl_counter))([[:space:]]\[[^]]+\])?$' \
      '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(ic_master\.(io_ic_status_[1-4]|io_checker_segment_id_[1-4])|io_clear_ic_status_tomain|large_[1-4])([[:space:]]\[[^]]+\])?$'
    ;;
  *)
    printf 'unknown mode: %s\n' "$mode" >&2
    exit 2
    ;;
esac
