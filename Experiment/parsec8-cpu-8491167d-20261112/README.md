# PARSEC eight-program CPU experiment

Unique EC functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`.
This independent directory uses CPU software simulation and offline analysis only.

<!-- LIVE-RESULTS-BEGIN -->
Accepted first-round pairs: **8/8**, updated 2026-11-12T10:24:51.276571+00:00. The table reports exact target cycles of the declared profiles; full-application extrapolation is uncalibrated.

| Program | Native cycles | EC cycles | EC / Native | ROI instructions each | Paired n |
| --- | ---: | ---: | ---: | ---: | ---: |
| Blackscholes | 60832 | 63547 | 1.044631 | 35605 | 3 |
| Fluidanimate | 16949 | 28077 | 1.656558 | 31613 | 3 |
| Bodytrack | 125929 | 146905 | 1.166570 | 81179 | 3 |
| Freqmine | 166379 | 467929 | 2.812428 | 273900 | 3 |
| Swaptions | 167237 | 337633 | 2.018889 | 157123 | 3 |
| Ferret | 24720 | 34184 | 1.382848 | 16460 | 3 |
| Dedup | 211667 | 407603 | 1.925680 | 344184 | 3 |
| Streamcluster | 303982 | 609828 | 2.006132 | 406074 | 3 |

Eight declared-profile Geomean: **1.672531x**. Full-application Geomean is unavailable.
<!-- LIVE-RESULTS-END -->

The live table records the current selected-profile Native, EC and functional/reference checks. Current acceptance and repetition counts are shown above. The immutable first-three snapshot is in `batches/first-three-accepted-20261112T0605Z/`. The live [CSV](paper/parsec8-native-ec.csv), [figure](paper/parsec8-slowdown.pdf), [summary](paper/summary.json), and [methods](paper/methods.md) refresh automatically. Empty rows mean no accepted sample. The eight-profile Geomean remains null until eight accepted pairs use the same exact CPU GG engine. It is explicitly an index of the declared heterogeneous workload scopes; full-application Geomean remains unavailable. Scope subsets are also reported separately.

The queue uses at most four simulator slots on CPUs 200, 201, 202 and 204, nice 19. CPU 201 prioritizes EC and can prefetch comparable repeats after all eight first EC runs have been dispatched; after all eight selected first Native runs pass, CPU 200 prioritizes remaining first-round EC work before Native repeats. A shared CPU lock prevents auxiliary EC and Native from overlapping. Extra EC slots on CPUs 202 and 204 check host pressure every 10 seconds and pause only their own simulator process groups when global CPU utilization exceeds 65%, their sibling hardware thread exceeds 20%, or available memory falls below 64 GiB; pause/resume events are retained per run. CPUs 202/204 may serve first Native samples and prefetch a missing earlier Native repeat before a later EC repeat, under the same CPU lock and pressure guard. Each simulator is single-threaded, with 64 GiB virtual-address reservation and a 16 GiB resident-memory ceiling. `campaign_v3.py` independently selects ready modes, prioritizes shorter validated Native profiles for EC, skips failed Native inputs and dispatches all ready first-round profiles before interrupted-run retries and idle-slot repeats 2 and 3. Published pairs and EC repeats require first-round output, instruction, timer-policy and manifest comparability. After all eight first EC dispatches, idle slots may prefetch Native repeats while a Native-passed profile awaits its first EC result; completed noncomparable first contracts remain ineligible. Idle-slot repeat prefetch cannot displace remaining first-round EC work. Normally advancing simulations retain their bounded target-cycle and active host-time budgets. The original CPU 208 extra slot was retired after sustained sibling-thread pressure; its interrupted evidence is retained, and new attempts use CPU 204. No other session's task is managed here. `policy.json` preserves the initial two-slot resource policy; current resource and timeout settings are in `execution-policy.json`, with each run retaining the policy that governed it.

Bodytrack and Streamcluster first EC attempts were deliberately interrupted while advancing. Bodytrack and Streamcluster attempt2 passed. Ferret's initial CPU208 attempt was resource-interrupted and retained. Its full warmed-EMD retry later produced actual cancellations seq101/102 with SVB/MSHR long waits, preserved in diagnostics/ferret-full-emd-failure-chain.json. The selected profile is now the original EMD cost-matrix stage on all126 real captured region pairs; it excludes the flow solution and is not complete Ferret or EMD performance. Failed/interrupted attempts never provide ratios. Freqmine hot4 is an explicitly changed cache profile, checked against exact frequent-itemset counts. Its selected quiet-ROI profile removes a parser progress printf whose HTIF polling otherwise changes ROI instruction counts. Dedup's original 128 MiB-buffer EC attempt produced real cancellations and a checker watchdog fatal; its complete raw evidence and four-level causal assessment are in diagnostics/dedup-buffer128-failure-chain.json. The selected independent profile retains the full 98,317-entry table and pipeline, changes MAXBUF to 16 MiB, and preloads the zero table through ELF PROGBITS before ROI. It has identical functional output and 344,184 ROI instructions, but its cycle pair must be measured anew. This is a changed buffer/initialization profile, not a hardware fix or original default configuration. Older failed and setup variants remain excluded.

- `queue.json`: selected eight software/profile manifests.
- `diagnostics/fluid-full-frame-failure-chain.json`: actual full-frame cancellation and later pipeline hang; superseded by explicitly scoped original AdvanceParticles replay from real captured state, without claiming a hardware repair or full-frame performance.
- `campaign-v3-state.json`, `queue-{native,ec}-state.json`: scheduler identities and work state; inherited live runners can hold slots without appearing in the restarted controller's child list.
- `runs/*/binding.json`, `state.json`, `result.json`, `complete.json`: per-run commands, identities, results and completion receipts.
- `runs/*/host-complete.log.gz`, `stdout-integrity.json`: complete raw output and raw/compressed SHA-256 bindings.
- `runs/*/external-events.jsonl`, `strict-acceptance.json`: real EC event and package-join evidence.
- `audit/existing-data-audit.json`: immutable initial audit of CPU Golden Gate, RTL and historical Native FPGA evidence.
- `audit/abi-audit.json`: eight paired ELF ABI and shared-object checks; linked addresses/cache state can still differ.
- `paper/diagnostic-pairs-excluded.csv`: earlier Blackscholes/Swaptions output-valid but timer/instruction-mismatched pairs. These never enter the primary plot or Geomean.
- `paper/canneal-flow-validation-excluded.csv`: Canneal flow check only, excluded from the requested eight.
- `paper/samples.csv`, `repeatability.csv`: complete paired repeats and explicitly labeled n=1 uncertainty gaps.
- `paper/run-attempts.csv`: selected and excluded attempts with their evidence, including deliberate interruptions.
- `runs/*/raw-audit.json`: independent decompression/hash/binding validation required before a pair enters the plot.
- `runs/*/svb-metrics.json`, `svb-lifetimes.csv`: actual per-key capture/promotion/C/ACK event joins; no rollback inference.

Reproduce software with the corresponding `scripts/build_*.py` in a fresh independent directory; existing bound run images must not be overwritten. Run `/data1/gzh/EC/chipyard/.conda-env/bin/python3 scripts/export.py` to verify evidence and regenerate paper exports. Attempt selection takes the earliest successful completed attempt, never the fastest result. Read per-profile limitations in the manifest/methods before citing a number. Reduced ROIs and component replay do not establish complete application performance, strict detection latency or full rollback latency.
