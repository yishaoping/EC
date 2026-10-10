#!/usr/bin/env bash
set -euo pipefail
repo=${EC_REPO_DIR:-$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)}
fst=${1:?FST/VCD path required}; profile=${2:?profile required}; start=${3:-0}; end=${4:-0}
[[ -r "$fst" ]] || { echo "cannot read $fst" >&2; exit 2; }
[[ "$end" != 0 ]] || end=999999999999
trace="$repo/AI/Debug/scripts/ec_fst_trace.sh"
case "$profile" in
  watchdog) re='(idle_cycles|io_big_hang|io_gh_stall|io_ic_status_|io_clear_ic_status_tomain|result_deq_fire|result_release_pending)' ;;
  assert21) re='(assert__assert_21|lsl\.|package_(seq|owned|result|cancel)|io_(dmem|imem)_req|rob\.io_commit)' ;;
  assert22) re='(assert__assert_22|package_(seq|owned|result|cleanup)|ghm_.*(cdc|result)|lsl\.)' ;;
  assert24) re='(assert__assert_24|excpt_mode|trap_depth|context_idle|io_packet.*ready|io_cdc_ready|ingress_overflow|lsl\.)' ;;
  boot-deadlock) re='(bootAddrReg|ipi_|wb_reg_(pc|inst|valid)|dmem_req|dmem_resp|replay|csr\.)' ;;
  *) echo "unknown profile: $profile" >&2; exit 2 ;;
esac
"$trace" "$fst" "$start" "$end" "$re"
