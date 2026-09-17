#!/usr/bin/env bash
set -euo pipefail

# Usage: trace_boot_deadlock.sh [fst] [start] [end]
# The repository's .vcd file is an FST file despite its extension.
repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fst_file=${1:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
start_time=${2:-0}
end_time=${3:-1200}

"$repo_dir/Debug/fst_signal_trace" "$fst_file" "$start_time" "$end_time" \
  'subsystem_pbus\.bootAddrReg' \
  'clint\.ipi_[0-4]' \
  'domain_[1-4]\.tile_reset_domain_tile\.core\.(mem_reg_pc|mem_reg_inst|mem_reg_valid|io_dmem_req_valid|io_dmem_req_bits_addr|io_dmem_resp_valid|io_dmem_resp_bits_data|io_dmem_resp_bits_data_raw|io_dmem_resp_bits_replay|dmem_resp_valid|dmem_resp_replay|rf_wen|rf_waddr|rf_wdata|wb_valid|wb_wen|wb_dcache_miss|ll_wen|ll_waddr|replay_wb|replay_wb_common)' \
  'domain_[1-4]\.tile_reset_domain_tile\.core\.csr\.(io_interrupts_msip|io_interrupt|io_evec|io_exception)'
