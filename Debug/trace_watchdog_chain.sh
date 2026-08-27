#!/usr/bin/env bash
set -euo pipefail

# Trace the BOOM checker-1 watchdog ownership chain without converting the
# complete FST to text.  test.vcd is an FST file despite its suffix.
#
# Usage:
#   trace_watchdog_chain.sh [fst] [start] [end]
#
# The default window covers allocation through the saved waveform's final
# watchdog transition.  Narrow the window when inspecting a particular CDC
# transfer, for example 80435..80600.
repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fst_file=${1:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
start_time=${2:-0}
end_time=${3:-2177588}
trace_bin=${FST_TRACE_BIN:-"$repo_dir/Debug/fst_signal_trace"}

if [[ ! -x "$trace_bin" ]]; then
  printf 'missing executable FST reader: %s\n' "$trace_bin" >&2
  printf 'build it using the command in Debug/signal_chain_analysis.md\n' >&2
  exit 2
fi

"$trace_bin" "$fst_file" "$start_time" "$end_time" \
  'tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(ic_master\.(io_ic_status_1|ic_status_1|io_clear_ic_status_1|io_packet_alloc_valid|io_packet_alloc_seq|packet_seq_counter|fsm_state)|io_clear_ic_status_tomain|small_1|large_1|nextSmall_1)' \
  'tile_prci_domain_1\.tile_reset_domain_tile\.(core\.(package_seq_reg|package_check_active|icsl_copy_start_accepted|arf_paste_reg|io_arf_copy_in|io_package_result_(valid|ready|status|seq)|io_rsu_status|rsu_slave\.(packet_valid|packet_index|packet_index_ECP|rsu_status|if_RSU_packet|if_RSU_packet_ECP))|cmdRouter\.io_out_0_(valid|ready|bits_inst_(opcode|funct))|ghe_rd_val|packet_(en_0|index_vec_0|vec_0|vec_in_0)|arfsSeqAccepted|auto_core_r_arfs_c_sk_in)' \
  '^TOP\.TestHarness\.chiptop\.system\.(ghm_(u_arfs_cdc_0\.io_(enq|deq)_(valid|ready|bits)|u_data_cdc_0\.io_deq_(valid|ready|bits)|result_deq_fire|result_release_pending_0|io_clear_ic_status_tomain)|tile_prci_domain\.tile_reset_domain_boom_tile\.core\.rsu_master\.(io_rsu_merging_valid|merge_counter|io_arfs_index_0))$'
