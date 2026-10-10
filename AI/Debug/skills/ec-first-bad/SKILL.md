---
name: ec-first-bad
description: Locate evidence-backed first divergence in EC BOOM/Rocket FST/VCD failures; use for RCA and watchdog causality before patching.
---

# ec-first-bad

1. Read ../../state/current_debug_state.md and ../../project/evidence_contract.md. Record the run identity before using any old report.
2. Follow ../vcd_first_bad.md. Reproduce narrow trace with ../../scripts/ec_fst_trace.sh; output only into AI/TMP/<run-id>.
3. Group complete timestamps and use pre-rising-edge state for sequential fire/commit. Build last good, first bad, and symptom tables.
4. Use ../deadlock_wait_for.md when progress stops. Separate actual wait-for cycles from combinational loops, and prove every dependency edge.
5. Report broken invariant, causal hierarchy, excluded hypotheses and unresolved evidence; do not patch until root cause is confirmed. Persist findings in bugs/history and current state.
