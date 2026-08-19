#!/usr/bin/env bash
set -euo pipefail

# Usage: trace_runtime_bootaddr_replay.sh [fst] [start] [end]
# The repository's .vcd file is an FST file despite its extension.
repo_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fst_file=${1:-"$repo_dir/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd"}
start_time=${2:-1020800}
end_time=${3:-1020981}

"$repo_dir/Debug/fst_signal_trace" "$fst_file" "$start_time" "$end_time" \
  'subsystem_pbus\.bootAddrReg' \
  'clint\.ipi_[0-4]' \
  'domain_[1-4]\.tile_reset_domain_tile\.core\.(mem_reg_pc|mem_reg_inst|wb_reg_pc|wb_reg_inst|wb_reg_valid|wb_valid|wb_dcache_miss|replay_wb|dmem_resp_valid|dmem_resp_replay|io_dmem_req_valid|io_dmem_req_bits_addr|io_dmem_resp_valid|io_dmem_resp_bits_data|io_dmem_resp_bits_data_raw|io_dmem_resp_bits_replay|ll_wen|ll_waddr|rf_wen|rf_waddr|rf_wdata)' \
  'domain_[1-4]\.tile_reset_domain_tile\.core\.csr\.(reg_mtvec|reg_mepc|reg_mcause|reg_mtval|io_evec)'
