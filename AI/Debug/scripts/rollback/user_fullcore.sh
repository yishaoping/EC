#!/usr/bin/env bash
set -eo pipefail
repo=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../.." && pwd)
: "${PALIMPSEST_FULL_OUT:?Set a fresh absolute directory under AI/TMP}"
case "$PALIMPSEST_FULL_OUT" in "$repo"/AI/TMP/*) ;; *) exit 2;; esac
case "${PALIMPSEST_CONFIG:-v1Config}" in
  v1Config|PalimpsestFault8Config|PalimpsestFault18TestConfig|PalimpsestFault40TestConfig|PalimpsestSeqRebaseTestConfig|PalimpsestTwoFaultTestConfig|PalimpsestFault40Seq41TestConfig) ;;
  *) printf 'Unsupported PALIMPSEST_CONFIG\n' >&2; exit 2;;
esac
config=${PALIMPSEST_CONFIG:-v1Config}
failed_seq=40
[[ "$config" != PalimpsestFault18TestConfig ]] || failed_seq=18
cy="$repo/chipyard"
scripts="$repo/AI/Debug/scripts/rollback"
normal_log=${PALIMPSEST_IO_NORMAL_LOG:-}
if [[ -n "$normal_log" ]]; then
  [[ ( "$config" == PalimpsestFault40TestConfig || "$config" == PalimpsestFault18TestConfig ) && -n ${PALIMPSEST_BINARY:-} &&
     "$normal_log" = /* && -s "$normal_log" ]] || {
    echo 'PALIMPSEST_IO_NORMAL_LOG requires Fault18/Fault40, a workload ELF and an absolute normal log path' >&2
    exit 2
  }
fi
if [[ -n ${PALIMPSEST_BINARY:-} ]]; then
  [[ "$PALIMPSEST_BINARY" = /* && -s "$PALIMPSEST_BINARY" && "$PALIMPSEST_BINARY" != *[[:space:]]* ]]
fi
mkdir "$PALIMPSEST_FULL_OUT"
ln -s "$cy/sims/verilator/Makefile" "$PALIMPSEST_FULL_OUT/Makefile"
python3 -B "$repo/AI/Debug/scripts/rollback/source_manifest.py" "$PALIMPSEST_FULL_OUT/sources.before.json"
source "$cy/env.sh"
make -j "${PALIMPSEST_BUILD_JOBS:-12}" -C "$PALIMPSEST_FULL_OUT" default \
  base_dir="$cy" sim_dir="$PALIMPSEST_FULL_OUT" CONFIG="$config" \
  SIM_OPT_CXXFLAGS="${PALIMPSEST_CXX_OPT:--O1}" \
  SBT_BIN="${PALIMPSEST_SBT:-$cy/.conda-env/bin/sbt} -java-home ${PALIMPSEST_JAVA_DIR:-$cy/.conda-env/lib/jvm}" \
  2>&1 | tee "$PALIMPSEST_FULL_OUT/build.log"
python3 -B "$repo/AI/Debug/scripts/rollback/source_manifest.py" "$PALIMPSEST_FULL_OUT/sources.after.json"
cmp "$PALIMPSEST_FULL_OUT/sources.before.json" "$PALIMPSEST_FULL_OUT/sources.after.json"
if [[ -n ${PALIMPSEST_BINARY:-} ]]; then
  loadmem="$PALIMPSEST_FULL_OUT/workload.hex"
  bash "$cy/scripts/smartelf2hex.sh" "$PALIMPSEST_BINARY" > "$loadmem"
  test -s "$loadmem"
  sha256sum "$PALIMPSEST_BINARY" "$loadmem" > "$PALIMPSEST_FULL_OUT/workload.sha256"
  sim="$PALIMPSEST_FULL_OUT/simulator-chipyard-$config"
  if [[ -n "$normal_log" ]]; then
    model="chipyard.TestHarness.$config"
    if [[ -f "${normal_log%/*}/workload.sha256" ]]; then
      read -r normal_binary_hash _ < "${normal_log%/*}/workload.sha256"
      read -r fault_binary_hash _ < "$PALIMPSEST_FULL_OUT/workload.sha256"
      [[ "$normal_binary_hash" == "$fault_binary_hash" ]] || { echo 'The normal and fault ELFs differ' >&2; exit 2; }
    fi
    sim=$(python3 -B "$scripts/build_io_observer.py" \
      --model-dir "$PALIMPSEST_FULL_OUT/generated-src/$model/$model" --out "$PALIMPSEST_FULL_OUT/io-observer")
    export PALIMPSEST_IO_EFFECT_LOG="$PALIMPSEST_FULL_OUT/effects.log"
  fi
  sha256sum "$sim" > "$PALIMPSEST_FULL_OUT/simulator.sha256"
  run_status=0
  (cd "$PALIMPSEST_FULL_OUT"; ulimit -c 0; "$sim" \
    --verbose +permissive "+max-cycles=${PALIMPSEST_MAX_CYCLES:-50000000}" \
    "+loadmem=$loadmem" +loadmem_addr=80000000 +permissive-off "$PALIMPSEST_BINARY") \
    > "$PALIMPSEST_FULL_OUT/run.log" 2>&1 || run_status=$?
  printf '%s\n' "$run_status" > "$PALIMPSEST_FULL_OUT/run.exit"
  ((run_status == 0)) || exit "$run_status"
  scoreboard=(python3 -B "$scripts/fullcore_scoreboard.py" --single "$PALIMPSEST_FULL_OUT/run.log")
  if [[ -n "$normal_log" ]]; then
    scoreboard=(python3 -B "$scripts/io_effect_scoreboard.py" --effects "$PALIMPSEST_IO_EFFECT_LOG"
      --normal "$normal_log" --fault "$PALIMPSEST_FULL_OUT/run.log" --failed-seq "$failed_seq"
      --report "$PALIMPSEST_FULL_OUT/io_effect_report.json")
    if [[ ${PALIMPSEST_IO_PROFILE:-output} == amo ]]; then
      scoreboard+=(--require-amo)
    else
      [[ ${PALIMPSEST_IO_PROFILE:-output} == output ]] || exit 2
      [[ "$failed_seq" != 18 ]] || scoreboard+=(--require-output)
    fi
  fi
  score_status=0
  "${scoreboard[@]}" > "$PALIMPSEST_FULL_OUT/scoreboard.log" 2>&1 || score_status=$?
  printf '%s\n' "$score_status" > "$PALIMPSEST_FULL_OUT/scoreboard.exit"
  cat "$PALIMPSEST_FULL_OUT/scoreboard.log"
  exit "$score_status"
fi
