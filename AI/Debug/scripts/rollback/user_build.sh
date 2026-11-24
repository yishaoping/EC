#!/usr/bin/env bash
# P5-12. Builds hardware and records the sources used for each simulator.
set -euo pipefail
repo=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../.." && pwd)
: "${PALIMPSEST_OUT:?Set an unused absolute directory under /data1/gzh/EC/AI/TMP}"
case "$PALIMPSEST_OUT" in "$repo"/AI/TMP/*) ;; *) exit 2;; esac
[[ ! -e "$PALIMPSEST_OUT" ]] || { echo 'Output exists; choose a fresh directory' >&2; exit 2; }
[[ "$PALIMPSEST_OUT" != *[!a-zA-Z0-9_./-]* ]] || { echo 'Use a path without spaces or shell metacharacters' >&2; exit 2; }
mkdir -p "$PALIMPSEST_OUT"/generated
sbt_bin=${PALIMPSEST_SBT:-"$repo/chipyard/.conda-env/bin/sbt"}
fixture="$repo/AI/Debug/scripts/rollback/RecoveryGenerate.scala"
hierarchy_fixture="$repo/AI/Debug/scripts/rollback/HierarchyGenerate.scala"
checker_fixture="$repo/AI/Debug/scripts/rollback/CheckerRecoveryGenerate.scala"
seq_fixture="$repo/AI/Debug/scripts/rollback/SeqTransportGenerate.scala"
translation_fixture="$repo/AI/Debug/scripts/rollback/TranslationRecoveryGenerate.scala"
baseline_fixture="$repo/AI/Debug/scripts/stage3/Stage3Generate.scala"
declare -A emitters=(
  [Recovery]=palimpsesttest.EmitRecovery [F0]=palimpsesttest.EmitF0
  [FaultInjection]=palimpsesttest.EmitFaultInjection
  [CheckerRecovery]=palimpsesttest.EmitCheckerRecovery [Svb]=palimpsesttest.EmitSvb
  [Identity]=palimpsesttest.EmitIdentity [Restore]=palimpsesttest.EmitRestore
  [Io]=palimpsesttest.EmitIo [IoBoundary]=palimpsesttest.EmitIoBoundary
  [PreciseException]=palimpsesttest.EmitPreciseException
  [LsuRecovery]=palimpsesttest.EmitLsuRecovery
  [Hierarchy]=palimpsesttest.EmitHierarchy [Baseline]=stage3.EmitModule
  [Pressure]=stage3.EmitModule [SeqTransport]=palimpsesttest.EmitSeqTransport
  [TranslationRecovery]=palimpsesttest.EmitTranslationRecovery [PtwRecovery]=palimpsesttest.EmitPtwRecovery
)
read -ra items <<< "${PALIMPSEST_TESTS:-Recovery F0 CheckerRecovery Svb Identity Restore Io IoBoundary PreciseException LsuRecovery Baseline Pressure SeqTransport Hierarchy TranslationRecovery PtwRecovery}"
declare -A emitted=()
emit_commands=()
for item in "${items[@]}"; do
  emitter=${emitters[$item]:?Unknown test $item}
  if [[ ! ${emitted[$emitter]:-} ]]; then
    emit_commands+=("runMain $emitter $PALIMPSEST_OUT/generated")
    emitted[$emitter]=1
  fi
done
git -C "$repo" diff --binary -- chipyard AI/Debug/scripts/rollback > "$PALIMPSEST_OUT/source.patch"
python3 "$repo/AI/Debug/scripts/rollback/source_manifest.py" "$PALIMPSEST_OUT/sources.before.json"
sha256sum "$fixture" "$hierarchy_fixture" "$checker_fixture" "$seq_fixture" "$translation_fixture" "$baseline_fixture" "$repo/AI/Debug/scripts/stage3/stage3_test.cpp" "$repo"/AI/Debug/scripts/rollback/*_test.cpp > "$PALIMPSEST_OUT/fixtures.sha256"
cd "$repo/chipyard"
test_status=0
if ! "$sbt_bin" -java-home "${PALIMPSEST_JAVA_DIR:-$repo/chipyard/.conda-env/lib/jvm}" \
  -J-Xmx8G -J-Xss8M -J-Dsbt.supershell=false \
  "set chipyard / Compile / unmanagedSources ++= Seq(file(\"$fixture\"), file(\"$hierarchy_fixture\"), file(\"$checker_fixture\"), file(\"$seq_fixture\"), file(\"$translation_fixture\"), file(\"$baseline_fixture\"))" \
  'project chipyard' 'Compile / compile' \
  "${emit_commands[@]}" 2>&1 | tee "$PALIMPSEST_OUT/emit.log"; then
  test_status=1
fi
blackboxes=()
for resource in CacheOpportunityObserver.sv cache_opportunity.cc; do
  if [[ -f "$PALIMPSEST_OUT/generated/$resource" ]]; then
    blackboxes+=("$PALIMPSEST_OUT/generated/$resource")
  fi
done
for item in "${items[@]}"; do
  top="${item}Harness"
  case "$item" in Recovery) bench=recovery;; F0) bench=f0;; FaultInjection) bench=fault_injection;; CheckerRecovery) bench=checker_recovery;; Svb) bench=svb;; Identity) bench=identity;; Restore) bench=restore;; Io) bench=io;; IoBoundary) bench=io_boundary;; PreciseException) bench=precise_exception;; LsuRecovery) bench=lsu_recovery;; Hierarchy) bench=hierarchy;; SeqTransport) bench=seq_transport;; TranslationRecovery) bench=translation_recovery;; PtwRecovery) bench=ptw_recovery;; Baseline) bench=baseline; top=Stage3Harness;; Pressure) bench=pressure; top=Stage3Harness;; esac
  if [[ ! -s "$PALIMPSEST_OUT/generated/$top.v" ]]; then
    printf 'No generated Verilog for %s. See emit.log.\n' "$item" > "$PALIMPSEST_OUT/build_$bench.log"
    test_status=1
    continue
  fi
  if ! "${PALIMPSEST_VERILATOR:-verilator}" --cc --exe --build -j "${PALIMPSEST_BUILD_JOBS:-4}" \
    --assert -Wno-fatal -Werror-UNOPTFLAT -Werror-PINMISSING -y "$PALIMPSEST_OUT/generated" \
    --top-module "$top" --Mdir "$PALIMPSEST_OUT/obj_$bench" \
    -CFLAGS '-std=c++17' "$PALIMPSEST_OUT/generated/$top.v" \
    "${blackboxes[@]}" \
    "$repo/AI/Debug/scripts/rollback/${bench}_test.cpp" 2>&1 | tee "$PALIMPSEST_OUT/build_$bench.log"; then
    test_status=1
    continue
  fi
  if [[ ${PALIMPSEST_RUN:-0} == 1 ]]; then
    if ! (ulimit -c 0; "$PALIMPSEST_OUT/obj_$bench/V$top") 2>&1 | tee "$PALIMPSEST_OUT/run_$bench.log" ||
       ! rg -q '^PALIMPSEST_[A-Z0-9_]+=PASS( |$)' "$PALIMPSEST_OUT/run_$bench.log" ||
       rg -q 'UNCOVERED|Assertion failed' "$PALIMPSEST_OUT/run_$bench.log"; then
      test_status=1
    fi
  fi
done
python3 "$repo/AI/Debug/scripts/rollback/source_manifest.py" "$PALIMPSEST_OUT/sources.after.json"
cmp "$PALIMPSEST_OUT/sources.before.json" "$PALIMPSEST_OUT/sources.after.json"
printf 'Selected builds complete in %s\n' "$PALIMPSEST_OUT"
exit "$test_status"
