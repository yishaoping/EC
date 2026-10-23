#!/usr/bin/env bash
# User entry point: a fresh historical build followed by one GAPBS512 run.
set -euo pipefail
[[ $# == 0 ]] || { printf 'Use BASELINE_JOBS, BASELINE_MAX_CYCLES, BASELINE_SEED, BASELINE_MIN_FREE_GIB environment variables.\n' >&2; exit 2; }
[[ ! -L "$0" ]] || { printf 'Refusing symlinked entry point\n' >&2; exit 2; }
baseline_root=$(cd -P -- "$(dirname -- "$0")" && pwd)
[[ "$baseline_root" == /data1/gzh/EC/baseline ]] || exit 2
workload="$baseline_root/software_common_builds/gapbs512_20261023_03/workload.json"
expected_descriptor=71373bcfeb4609c9c5b4a6a8e5212c3d1ddafcb340488736785dbd873e2dc743
actual_descriptor=$(/usr/bin/sha256sum -- "$workload")
[[ "${actual_descriptor%% *}" == "$expected_descriptor" ]] || { printf 'Pinned workload descriptor changed; refusing to guess inputs\n' >&2; exit 2; }
printf 'BASELINE_GAPBS_COMPARISON_IS_APPROXIMATE\n'
exec "$baseline_root/start_baseline_experiment.sh" --all --workload "$workload" \
  --jobs "${BASELINE_JOBS:-1}" --max-cycles "${BASELINE_MAX_CYCLES:-500000000}" \
  --seed "${BASELINE_SEED:-1}" --min-free-gib "${BASELINE_MIN_FREE_GIB:-50}"
