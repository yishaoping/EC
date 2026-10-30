# Latest: final integrated integrity validation prepared (2026-10-30)

Current-run recertification status: **CURRENT_DATA_FUNDAMENTALLY_INSUFFICIENT**.
76 of84 mismatch increments proved observer duplicates; 8 final hash failures have no
recorded per-lifecycle key/hash. Old ROI1707863 remains pending integrity closure.
Histogram STOP-edge mismatch is fixed offline; SVB16 sufficient; no geometry change.

Final launcher mode `corrected_svb16_integrity_v2` adds allocation serial,
capture/stored/promotion/C/L2 hash and terminal ledger, corrected histogram window
and shadow models. 120 offline tests and fresh Scala/FIRRTL/firtool/comb-loops PASS.
No hardware simulation performed while preparing. Next user run is one fresh
**FINAL_OPT4_VALIDATION**, no --resume, FST/VCD or pure diagnostic rerun:

```bash
cd /data1/gzh/EC
source chipyard/env.sh
bash slowdown/run_optimization_4_svb.sh --jobs 8
```

[Evidence and limitations](/data1/gzh/EC/AI/TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/README.md).
Older preparation/result statements below are historical.

# Optimization 4: corrected SVB16 + cache opportunity

Current status (2026-10-30): **READY_TO_RERUN_OPT4_SVB_AFTER_FST_FIX**.

The final saved FST confirms an orphaned fast-line lease: the saved way/epoch/key
was replaced, the original store completed in another way, but the global lease
blocked unrelated preservation. At the watchdog the ROB was empty, STQ full, and
WB/probe/MSHR/SVB idle. There is no observed WB/probe/MSHR ABBA cycle.

DCache now revokes stale leases, checks complete S2/S3 identities, scopes legacy
preservation conflicts by line, and serializes capture/legacy handoff on the
single freeze descriptor. SVB16, same-line retained-version ordering, watermark,
source/ACK, checker and cache geometry/shadow models remain intact.

Final Scala compile, fresh v1Config elaboration/FIRRTL/firtool/CheckCombLoops,
102 offline tests (including 12 directed tests), syntax/lint, patch reverse-check
and launcher identity checks passed. No hardware simulator was started in this
fix turn. Correctness, checksum/verified and ROI still require the formal run.

Run the formal fresh validation once:

```bash
cd /data1/gzh/EC
source chipyard/env.sh
bash slowdown/run_optimization_4_svb.sh --jobs 8
```

No --resume or waveform launcher. The non-trace build retains compact counters,
shadow observers, and an 8192-event/1MiB failure-only ring; identical wait states
are coalesced with repeat counts, while lifecycle/C/D events preserve time.
Fresh generated diagnostics are enabled by an exact inverse-verified overlay,
without +verbose. SUCCEEDED requires protocol/cache/benchmark/performance PASS.

[Full evidence, 26 answers, patches and static/runtime boundary](../../AI/TMP/opt4_svb_fst_rootcause_fix_20261030_114113_773ea77d/README.md).

The notes below are historical preparation records; their READY/UNRESOLVED
statuses and diagnostic commands are superseded by the formal-run procedure above.

Preparation update (2026-10-30): **READY_FOR_OPT4_SVB_WAVEFORM_RUN**. User-only,
one-time final FST diagnostic entry: `bash /data1/gzh/EC/slowdown/run_optimization_4_svb_waveform_debug.sh --jobs 8`.
It always elaborates/builds fresh, traces from simulator time1500000 until termination,
checks broad ROB/LSU/cache/ownership/TL control coverage before starting, and saves one
FST under `waveform_debug/<run_id>/` with SHA256. Essential existing diagnostics are
independent of verbose. No functional RTL, normal launcher or default capture changed.
No new simulation was run during preparation; the hardware root cause remains unresolved.
See [scope, checks and single-run procedure](../../AI/TMP/opt4_svb_waveform_debug_prepare_20261030_091449_2f46ad8a/README.md).

The following status records the prior failed run; its "no additional observation
simulation prepared" statement is superseded by the waveform preparation above.

Current status (2026-10-30): **HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT**.

Latest user run `optimization_4_svb_20261029_120415_a83514b4` exited1 at the pipeline
watchdog (time2099000), without complete benchmark/ROI. Diagnostic Chisel printfs were
disabled by `PRINTF_COND=verbose&&done_reset`; the launcher left verbose false, so
the8192-event failure ring contains only2 fatal rows and no ownership snapshot.
The hang analyzer now recognizes the native same-run watchdog assertion rather
than reporting NO_WATCHDOG_OBSERVED. Protocol analysis uses manifest SVB16 capacity
when STOP counters are absent, while missing final footer still rejects PASS.
No functional RTL fix or official fixed-run readiness is claimed. No additional
observation simulation is prepared. See [latest evidence and limits](../../AI/TMP/opt4_svb_hang_rootcause_fix_20261030_a83514b4_7c92e1d0/README.md).

The remaining delivery notes and run command below describe the previous preparation;
their historical READY status does not establish readiness of a functional hang fix.

Update 2026-10-29: the later user run `optimization_4_svb_20261029_020351_481d089a`
passed generation/build but was killed by the old capture's 48MiB event limit. It has no
final checksum/ROI/footer and provides no valid performance result. Kind14/15 forced
one record per Store/blocked cycle and accounted for about75% of saved events.

Kind14/15 now retain one example per4096 traffic-window events, with at most1024
examples per producer. Kind31 adds exact64-bit semantic-write, blocked-cycle and
blocked-episode counters at STOP. Counters cover `trafficCounting`, sampled before
the STOP edge; this is not automatically identical to the software ROI interval.
Once example sampling reaches the producer limit, these counters continue counting.

The Opt4 launcher opts into `+safe-chain-budgeted`. Producer limits and host byte
limits count omissions and keep draining output so the workload can finish. The48MiB
event budget reserves39MiB for mandatory protocol records,8MiB for optional examples
and1MiB for snapshots/footers. Each2MiB diagnostic stream reserves a quarter for
final/failure markers; cache summaries retain their separate4MiB limit.
`capture_summary.json` records transport loss and producer/footer accounting.
Optional example loss can coexist with valid correctness/performance; mandatory loss,
missing final accounting, failure markers or nonzero/incomplete workload exit prevent PASS.
Finite budgets cannot guarantee complete mandatory evidence for an arbitrarily long run.
Capture exceptions now record `simulation=ABORTED` instead of leaving `STARTED`.
The cumulative patch and evidence are in
[observation budget fix](../../AI/TMP/opt4_observation_budget_fix_20261029_0802a3c4/README.md).

Earlier update: user attempt `optimization_4_svb_20261029_013322_1d198f2e` stopped during
Chisel elaboration, before simulator build or simulation. The new L2 observer tried to Mux
`QueuedRequest` with `FullRequest`. The observer now projects the incoming request into a
`QueuedRequest` using the existing functional path's field-connection idiom. Functional
scheduler logic is unchanged. Scala/source checks do not prove full elaboration; fresh
hardware generation remains user-run. The earlier cumulative patch is preserved at
[observer Mux fix](../../AI/TMP/opt4_observer_mux_fix_20261029_df6ad056/README.md).

The previous source-lifecycle-fixed run `optimization_4_svb_20261028_104359_b1e0aeee` completed with exit1,
verified0 and checksum43440224 instead of43439728. Its ROI1720057 is invalid as a performance result.
The compact ledger exposes17 same-line/writer generation regressions: a younger normal writeback was
followed by an older SVB ReleaseData. Current changes block normal WB/probes behind retained same-line
SVB entries through ACK, freeze/drain the pre-overwrite capture, and order/coalesce safe versions by
generation when package sequence ties. The shared source/ACK/completion engine body is preserved.

`SVBEntries` is parameterized with default16. Global storage expands; safety/watermark/fallback and
per-line protocol remain. Shadow8 counters report accepted captures at occupancy>=8, cycles>8,
17-bin occupancy/depth, max, capture failures and actual full fallback. They do not predict 8-entry ROI.

Actual BOOM L1D32KiB(256sets×2ways,64B,6MSHRs) and L2 1MiB(1024×16,64B,onebank) are unchanged.
Input-only observers collect pressure/traffic counters and update host-only S0 current,
S1 same-capacity/double-ways, S2 double-capacity/same-ways, S3 double-capacity/double-ways models.
The random-family replacement is approximate; S0 miss error>10% prevents geometry recommendations.
All alternate results are `COUNTERFACTUAL_CACHE_TRAFFIC_ESTIMATE`, with no predicted ROI.

Run exactly one fresh combined hardware experiment (user only):

```bash
bash /data1/gzh/EC/slowdown/run_optimization_4_svb.sh
```

Do not reuse the failed simulator or pass --resume for it. The launcher hashes all ten hardware/resources,
capture/analyzer/launcher and pinned software, checks the cumulative patch, then fresh-generates/builds and runs once.
Generic --resume is only for identical-source builds whose simulation was never attempted. No automatic retry.
Phase/heartbeat prints every30seconds; errors record phase/exit/tail/manifest. No full FST/VCD or new address TSV.
Capture caps are48MiB events,2MiB each stdout/stderr,4MiB final cache JSON: total56MiB.

Inspect `analysis/<fresh-run-id>/summary.json`: checksum43439728 and verified1; assertions/protocol;
C generation ordering; snapshot→C→L2-bank hashes; final entry conservation/occupancy; complete SC/host hist.
Only correctness PASS publishes performance_valid and ROI versusOpt3 2928347/Baseline1001675.
Then evaluate SVB capacity and at most one cache candidate with S0 sanity. One combined result cannot
isolate correctness-fix versus8→16 ROI contributions. Exit empty is not a full durable-drain/failure-recovery proof.

Offline checks (no hardware simulator):

```bash
python3 -I -B slowdown/optimization_4_svb/scripts/offline_launcher_tests.py -v
python3 -I -B slowdown/optimization_4_svb/scripts/offline_protocol_tests.py -v
python3 -I -B slowdown/optimization_4_svb/scripts/offline_capacity_cache_tests.py -v
python3 -I -B slowdown/optimization_4_svb/scripts/offline_observation_budget_tests.py -v
bash slowdown/run_optimization_4_svb.sh --static-check
```

Full report, three patches, provenance and static/runtime boundaries:
[Opt4 SVB16 delivery](../../AI/TMP/opt4_svb_fix_capacity_cache_opportunity_20261029_b1e0aeee/README.md).
No hardware generation, Verilator model build or simulation was executed during this preparation.
