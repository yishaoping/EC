# seq67 completed B: 133 logger identities exceed 128 host slots

2026-11-01 analysis-only closure. Actual run:
`AI/TMP/checker_seq67_one_shot_20261031_103130/sealed/arms/B/runs/optimization_4_svb_20261031_024551_8fbf8937`.
The user-named `_094628` is the earlier generation failure, not this completed run.

**Confirmed host bookkeeping defect, with no mandatory data loss in this run.**
`compact_capture.Router.observer` merges identities beyond128 into `other`, while
`producer` rejects new IDs after128 as malformed. The historical STOP schema had127
identities; new mandatory SC46 (2 active harts here) and SC47 (all4) increase this to133.
This produces an overall functional/capture FAIL despite exit0, verified1,
checksum43439728, complete ROI1,648,923 and320 accepted package PASSes.

Five missing observer identities16:0,17:0,18:0,30:0,31:0 have all5 raw events and all5
raw footers preserved, plus produced=emitted1/omitted0. `other` is exactly their10
records, omitted0. Five rejected producer-stat identities4:3,4:4,5:2,5:3,5:4 are all
optional. They remain explicitly unknown; no producer statistic is fabricated.

The recovery tool checks all133 raw identities, one footer per identity, every
mandatory producer/event/footer conservation equality, retained accounting for
known identities and exact `other` conservation. It rejects unrelated failure
reasons, mandatory loss/limits, malformed records or changed bucket contents.
Optional evidence stays incomplete. A separate derived capture summary removes
only the now-resolved mandatory bookkeeping failure. Re-running the unchanged
analyzer there passes all24 unchanged arm gates. Original summary/logs/seals/claims
remain byte-identical and keep the original FAIL history.

For the independently justified one A-prime baseline, an explicitly sealed host
capture copy changes only the two dictionary caps128→256. This is enough for all
possible135 active identities in this instrumentation. Event budgets, line
classification, raw formats, RTL and counters do not change. The canonical B
capture source remains untouched so its original sealed source checks still pass.
The separate A-only launcher binds the overlay hash and exact two-line inverse,
calls all original source/software/patch guards, rejects B and uses a one-use claim.
No build or simulation was executed by the agent.

Validation:10 negative recovery tests and10 baseline/capture-guard tests, plus24
existing one-shot and11 strict-pair arm tests, all PASS. Real B recovery and24 gates
PASS; A-only static preflight and actual B rejection PASS. A runtime remains pending.

[Report](../../TMP/l1_one_shot_postanalysis_20261101_095815/README.md)
· [Recovery audit](../../TMP/l1_one_shot_postanalysis_20261101_095815/recovered_capture/capture_recovery_audit.json)
· [New recovery tool](../scripts/recover_seq67_capture.py)
· [A-prime wrapper](../scripts/launch_checker_seq67_baseline_refresh.py).
