#!/usr/bin/env bash
set -euo pipefail

debug_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
repo_root=$(cd "${debug_dir}/.." && pwd)

files=(
  chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala
  chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala
  chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala
  chipyard/generators/rocket-chip/src/main/scala/tile/Core.scala
  chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala
  chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_FIFO.scala
  chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala
)

cd "${repo_root}"
git diff --check -- "${files[@]}"

required_patterns=(
  'resume_state'
  'cancellation_return_pending'
  'io.context_idle'
  'package_progress_timeout'
  'dataBeatReady'
  'packet_current_seq_active'
  'io.cdc_ready_mem'
  'io.ingress_overflow'
  'u_data_cdc(i).io.deq.valid && dataHeadInOrder'
)

for pattern in "${required_patterns[@]}"; do
  if ! rg -F -q "${pattern}" "${files[@]}"; then
    echo "missing required invariant: ${pattern}" >&2
    exit 1
  fi
done

if rg -q 'packet_cdc_ready_raw|rsu_slave\.io\.cdc_ready[[:space:]]*\|' \
  chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala; then
  echo "type-insensitive packet-ready OR has returned" >&2
  exit 1
fi

if [[ "${1:-}" == "--compile" ]]; then
  cd "${repo_root}/chipyard"
  sbt 'project rocketchip' compile
fi

echo "assert24 hardware-fix static checks passed"
