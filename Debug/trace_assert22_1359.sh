#!/usr/bin/env bash
set -euo pipefail

# Trace the assert__assert_22 ownership chain without converting the complete
# FST to text.  test.vcd is an FST file despite its suffix.
#
# Usage:
#   trace_assert22_1359.sh [fst] [start] [end]
#
# The default window covers seq=1 release and seq=57 ingress.  Pass a second
# window (for example 2717300 2717360) to inspect the watchdog edge.
repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fst_file=${1:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
start_time=${2:-620150}
end_time=${3:-620700}
trace_bin=${FST_TRACE_BIN:-"$repo_dir/Debug/fst_signal_trace"}

if [[ ! -x "$trace_bin" ]]; then
  printf 'missing executable FST reader: %s\n' "$trace_bin" >&2
  printf 'build it using the command in Debug/signal_chain_analysis.md\n' >&2
  exit 2
fi

"$trace_bin" "$fst_file" "$start_time" "$end_time" \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain\.tile_reset_domain_boom_tile\.core\.(ic_master\.(fsm_state|packet_seq_counter|active_packet_seq|io_(ic_status_1|clear_ic_status_1|packet_alloc_(valid|seq)))|io_clear_ic_status_tomain|small_1|large_1|nextSmall_1)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.ghm_(result_deq_fire|result_release_pending_0|u_(data|arfs)_cdc_0\.io_(enq|deq)_(valid|ready|bits))([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_1\.tile_reset_domain_tile\.core\.(package_seq_reg|package_check_active|package_start_pending|package_start_accepted|pending_package_seq(_valid)?|pending_new_package|incoming_package_seq|new_package|checker_cleanup_done|package_data_complete|package_exec_waiting|package_exec_timeout_counter|package_cancelled|package_result_event|package_result_fire|package_result_outstanding|package_result_waiting|io_(packet_seq(_valid)?|arf_copy_in|package_result_(valid|ready|status|seq)|rsu_status)|rsu_slave\.(rsu_status|packet_valid(_ECP)?|packet_index(_ECP)?|if_RSU_packet(_ECP)?)|lsl\.io_if_empty|io_cdc_empty)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_1\.tile_reset_domain_tile\.(arfsSeqAccepted|packet_(en|index_vec|vec(_in)?)_0)([[:space:]]\[[^]]+\])?$' \
  '^TOP\.TestHarness\.chiptop\.system\.tile_prci_domain_1\.tile_reset_domain_tile\.auto_core_r_arfs_c_sk_in([[:space:]]\[[^]]+\])?$'
