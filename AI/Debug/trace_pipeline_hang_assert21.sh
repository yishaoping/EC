#!/usr/bin/env bash
set -euo pipefail

# Trace the BOOM main-pipeline hang watchdog and its Guardian upstream causes.
# The saved test.vcd is an FST container.  Times are FST time units; with the
# current waveform, the Verilator log cycle is approximately FST/2.
#
# Usage:
#   trace_pipeline_hang_assert21.sh [fst] [start] [end]
#
# The default window is the last 2,000 FST units before assert__assert_21.
repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fst_file=${1:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
start_time=${2:-2200000}
end_time=${3:-2202728}
trace_bin=${FST_TRACE_BIN:-"$repo_dir/Debug/fst_signal_trace"}

if [[ ! -x "$trace_bin" ]]; then
  printf 'missing executable FST reader: %s\n' "$trace_bin" >&2
  printf 'build it using the command in Debug/signal_chain_analysis.md\n' >&2
  exit 2
fi

"$trace_bin" "$fst_file" "$start_time" "$end_time" \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(reset|small_0|large_0|nextSmall|io_big_hang|io_gh_stall|rob\.io_commit_valids_[0-2]|csr\.io_csr_stall|io_rocc_busy|io_checker_segment_id_[1-4]|ic_master\.(fsm_state|crnt_target|io_if_pipeline_stall|io_if_dosnap|io_if_dosnap_priv|io_if_ready_snap_shot|io_if_correct_process|io_rsu_busy|io_ic_status_[1-4]|io_packet_alloc_(valid|seq)|io_active_packet_seq|packet_seq_counter|io_checker_segment_id_[1-4])|rsu_master\.(io_big_hang|io_core_hang_up|merging|merge_counter|merge_cdc_counter|io_rsu_busy))([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.gh_buf\.(io_cdc_not_ready|io_packet_out|io_gh_packet_dest|io_ght_filters_empty|io_ght_buffer_status|buf_all_empty|new_packet_[0-2]|buffer_(enq|deq)_ptr)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.(ghm_(dataConsumedSeq(_[0-3])?|data_cdc_ready_[0-3]|cdc_busy_[0-3]|if_no_inflight_packets_[0-3]|checkerSessionDone_[0-3]_checkerDone|result_deq_fire(_[0-3])?|result_release_pending(_[0-3])?)|ghm_u_(data|arfs)_cdc_[0-3]\.io_(enq|deq)_(valid|ready|bits)|ghm__u_(data|arfs)_cdc_[0-3]_io_deq_ready_T(_[0-3])?|ghm__packet_out_wires_[0-3]_T)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.(hang_bits|mask_bits|_cdc_not_ready_T)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\..*bigcore_hang.*([[:space:]]\[[^]]+\])?$'
