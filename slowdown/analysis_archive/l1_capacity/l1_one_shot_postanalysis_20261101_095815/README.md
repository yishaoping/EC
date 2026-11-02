# checker_seq67 B postanalysis — 2026-11-01

**Checker / observer / integrity PASS after lossless offline capture-accounting recovery. Complete B ROI 1,648,923; reference saving 58,940 cycles (3.4511%). STRICT_BASELINE_REFRESH_JUSTIFIED; STRONG_OPT5_SIGNAL is a reference signal, not final causal acceptance.**

User named `_094628`, but that report failed RTL generation and never simulated. The completed corrected B is `_103130`, run `optimization_4_svb_20261031_024551_8fbf8937`, source fingerprint `497d232770160bea6901dc20a6d5f411bab5f685d9c560c0b3b75bf7184c7cc0`. Both reports and all source seals/claims/logs remain untouched.

Original `_103130` summary says functional FAIL/capture FAIL although exit0, checksum43439728, 320 accepted package PASSes, seq67 diagnostic PASS and complete ROI are present. Root cause of this disagreement is host identity accounting: 133 logger identities exceed the 128-entry dictionaries. Five mandatory STOP event/footer pairs remain in the raw TSV but statistics were merged into `other`; five missing producer statistics are optional. Offline reconstruction verifies all mandatory conservation before re-running the unchanged analyzer in a separate derived view. The original summary is not overwritten.

- [Correctness closure](correctness_closure.md)
- [seq67 runtime evidence](seq67_runtime_confirmation.md)
- [Observer and integrity](observer_integrity.md)
- [Performance reference](performance_comparison.md)
- [Causal attribution](causal_attribution.md)
- [Strict baseline gate](strict_baseline_gate.md)
- [Candidate ranking](next_candidate_ranking.md)
- [Decision JSON](final_decision.json)
- [Unchanged24 gates](offline_validation.json), [whole-run checker ledger](global_checker_audit.json)
- [Raw evidence hashes](original_evidence_hashes.json), [capture recovery audit](../../../../AI/TMP/l1_one_shot_postanalysis_20261101_095815/recovered_capture/capture_recovery_audit.json)

No elaboration, RTL generation, Verilator build or benchmark simulation was executed by the agent. One A-prime command is prepared only because Gates0/3/4 pass. No B rerun, geometry matrix or diagnostic-only experiment is prepared.

From `/data1/gzh/EC`, user execution only:

```bash
bash AI/Debug/scripts/run_checker_seq67_baseline_refresh.sh --report AI/TMP/l1_one_shot_postanalysis_20261101_095815/baseline_refresh --jobs 4
```

A-prime keeps all19 hardware inputs byte-identical to completed B, including checker fix, observer, causal/STOP counters, software, seed1 and checker configuration; the A config selects baseline32KiB/2way. The only host exception is two bounded identity-accounting caps128→256; event reservations, classification, record contents and performance counter definitions remain identical. See baseline_refresh for the sealed, single-use contract and static validation. Running the command is not required to inspect this completed analysis.
