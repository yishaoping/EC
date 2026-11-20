# Existing SVB routed checkpoint continuation

Observation: 2026-11-12T17:40:35.142586+08:00. Functional baseline `8491167d`; only card `0000:21:00.0` / `21770433G02LA` is allowed. No active CAD task was restarted or signalled, no active RTL/constraint input was changed, and the independent CPU PARSEC session was not controlled.

## Physical result and automatic continuation

r6 G completed at WNS -0.023 ns / TNS -0.495 ns / 39 failing Setup endpoints; H completed at **WNS -0.020 ns / TNS -0.447 ns / 45 failing Setup endpoints / WHS +0.001 ns / THS 0**. G/H are fully routed and retain all 49 original DRC Warnings, with zero Error. These results fail the Setup gate and cannot certify a bitstream.

I's legal Vivado 2021.1 post-route `phys_opt_design -clock_opt` completed successfully and saved `physical.dcp`: **WNS -0.017 ns / TNS -0.387 ns / 42 failing Setup endpoints / WHS +0.001 ns / THS 0**. This is a physical-stage snapshot, not I's final routed result. I is executing its existing TNS cleanup; intermediate router Hold values must not replace final timing. J is already queued behind I. The source-bound G/H critical path analysis is in `critical-paths-G-H.json`; all negative Setup paths are in the PCIe 500 MHz clock group, with route-dominated pointer/control fanout paths.

The installed r7 conditional services wait for r6 to exhaust and its exact controller, child identities and cgroup to exit. They reuse the same third component slot lock, 2 cores and 64 GiB envelope. K uses post-route AggressiveExplore, L AlternateReplication, and M selectively reroutes only shell SRL output nets on actual negative Setup paths. Only completed routed checkpoints with nonnegative Hold are eligible. r7 omits an otherwise redundant full-design TNS cleanup when routing is already complete. No new Vivado is running in r7 while r6 remains live.

The existing independent physical certificate, all-clock Setup/Hold, routing, pulse/bus-skew, DRC and clock coverage gates remain in force. A passing candidate automatically proceeds to certificate, locked 21-only deployment, directed SVB replay, and same-bit application replay. **No certified SVB bitstream or new FPGA sample exists at this observation.** SVB is a component result, not complete EC.

## MCRams resource evidence

The owner-only MCRams complete generated FPGATop **synth** report contains **2,421,933 LUT / 80,994 CARRY8 / 192 DSP / 1,696,044 FF / 898.5 BRAM / 0 URAM / 0 blackboxes**. Its LUT excess is **1,118,253** (185.7766% used). This scope excludes the U280 shell. `synth.dcp` is retained. The original opt_design is live in Power Optimization; the package-current critical warning is retained and no post-opt utilization report has yet been emitted. Therefore a MCRams post-opt/physical FIT result remains pending, and synth is NOT FIT.

A different, completed e0 full-shell Opt4 has authoritative post-opt **2,789,012 LUT / 81,248 CARRY8 / 195 DSP**, NOT FIT with excess 1,485,332. See the independently pinned round136 receipt. This is not the owner-only MCRams post-opt result. The already-running 8d composite DUT synthesis is preserved; no third whole-host synthesis was launched.

PackageAddressStats is the largest actionable target at 881,587 LUT inside the 1,502,470-LUT DCache (inclusive hierarchy; do not add them). GHBarrierLatencyStats instances total 187,696 LUT. Tiny synchronizer instance hierarchy entries with tens of thousands of LUTs are not evidence of intrinsic synchronizer RTL cost: synthesis rebuilt hierarchy may assign absorbed combinational logic there, so a source/netlist cone audit is needed before choosing an optimization.

The naive address 258-read/256-write MCRams layout is rejected for area: the measured one-bank pair grows **57,148 to 117,874 LUT (+60,726)**. Its already-live Golden Gate validation is preserved, but this layout is not admitted to another whole synthesis. A previously recorded group8 zero-area parse is also invalid; its raw module report actually contains 1,029,298 LUT / 55,662 CARRY8 / 389,512 FF / 216 BRAM. Historical pinned receipts are retained.

## Actual new work

A separate CPU-only local histogram validation service compiled and emitted the private packed-reduction helper and passed **8,192 actual-size vectors / 8,388,608 output checks**, including all 80 inputs, 256 buckets, four granules, overflow and reset checks. Actual bounds are [8,3,2,1], scatter widths [6,4,4,3], and packed lanes [11,9,9,8] (37 bits). The earlier 500-bit/45-bit proof is a wider synthetic arithmetic check, not this instantiated histogram. Its unbalanced miter timed out, its balanced miter passed, and a bit-flip mutant failed; none is claimed as complete PackageAddressStats equivalence. The candidate is private and not integrated: complete target parity, paired complete-module area and whole-host FIT gates remain. No new Vivado or full-host task was started for it.

A new **read-only r2 metrics consumer** now accepts the exact certified r6/r7 application receipts; the old live r1 consumer only accepted r5 and was preserved. The new consumer passed all 659 reference lifetime bindings and count/cache/target-cycle mutation rejection, and is waiting in its own user service. It performs no board or replay operation. It will export capture/promote/ACK target-edge intervals and replay throughput only after exact real FPGA replay passes. Host replay rates include MMIO overhead; captured workload ACK rate is not autonomous peak throughput. Strict checker/rollback latency remains unavailable for this component trace.

Evidence and live identities: `execution.json`. All versioned services and complete manifests are pinned there. FPGA access remains strictly gated; no target-cycle semantics or timing constraints were relaxed.


## Stage changes at 18:02 CST

I completed with final WNS -0.017 ns / TNS -0.387 ns / 42 Setup violations / WHS +0.001 ns / THS 0. All255876 routable nets are fully routed, zero routing errors; final DRC retains49Warning/0Error. Its Setup gate correctly failed. J terminated because Vivado2021.1 timing_path has no POINTS property, before any net unroute. All checkpoints remain. This script error is distinct from hardware timing failure.

The installed r7 automatically adopted the best I final checkpoint after r6 naturally exited. **K AggressiveExplore has now completed phys_opt with WNS0.000 / TNS0.000 / WHS+0.001 / THS0.000, optimizing16nets without changing cell count.** This is still a phase result; final reports, bitstream and independent certification remain pending. No new FPGA measurement has begun.

An actual read-only Vivado API probe on I's exact checkpoint enumerated every timing_path property, confirmed POINTS/TIMING_POINTS absent and confirmed `get_pins -quiet -of_objects $path` returns the four pins on the worst path. Versioned r8 N/O selectors use this actual supported query, retain the same bounded shell-only filters, no DONT_TOUCH or clock nets, and share the same component slot. Its3system services are installed but wait for r7failure+emptyexactcgroup; a successful r7 cancels physical successor CAD. No r7input was edited or task restarted. Probe evidence is in `vivado-api-probe/`; all42I negativepaths were independently parsed in `critical-paths-I.json`.

The actual-source paired **singlebucket** area screen has also completed: reference **5211LUT/102CARRY8**, candidate **4879LUT/139CARRY8**, both zeroFF/DSP/BRAM/URAM/blackboxes. It includes actual80inputgroup4compaction/scatter, uses identical default Vivado directives, and changes only the packed finalgroupreduction. The measured saving is **332LUT for this onebucketcut**; there is no multiplication claim or complete-module/hostFIT assertion. Fullmoduleparity and fullmodulearea remain required before integration. Exact evidence: `build-logs/Opt4-address-packed-bucket-area-r3-20261112/result.json`. These local probes have finished and no extra Vivado remains from them.

The new r2read-only metrics consumer passed positive reference bindings and count/cache/targetcycle negative tests; enabled persistent user unit and accountlinger preserve this consumer across logout without restarting its livePID. It accepts r6/r7actualreplay; r8runtimefollowers are also installed but r8metrics attribution is not yet added (only needed if r8wins). All normalCAD and CPUbenchmarkowners remain unchanged.


## Actual bitstream and complete MCRams post-opt at 18:14 CST

**SVB bitgen completed successfully** at18:11:58CST. The exact bytecount is recorded in the result receipt (current file42842607bytes); K's bound result and chosen-result have been written. It is still pending independent certification; do not infer FPGA access from a bitstream file. The original follow-r7 service began the independent checkpoint/clock/timing/route/DRC/pulse/skew/CDC audit at18:14:15. The conditional r8 observed the r7 winner and exited without starting CAD. All r8selectors, runtime/certificate and read-only metrics fallback remain prepared for a genuine later need.

The owner-only MCRams complete FPGATop **post-opt** report is now authoritative: **2,420,482LUT / 80,990CARRY8 / 192DSP / 1,696,013FF / 898.5BRAM / 0URAM / 0blackboxes**. It is **NOTFIT**, over theU280LUTcapacity by **1,116,802LUT**. Compared with this same run's synth snapshot, opt_design removed1451LUT/4CARRY8/31FF; no large area recovery occurred. The full generated-host scope excludes the U280shell, so this already-negative capacity result cannot admit full physical Opt4. Both top totals and primitive/hierarchy totals agree; see `mcrams-postopt-resource-audit.json`. The complete postoptDCP write remains live and is preserved. The old capacity consumer will naturally ingest its final result and prevent pointless place/route.

The post-opt inclusive hierarchy still attributes881587LUT to PackageAddressStats,1501447LUT to the enclosing DCache,153416LUT to MSHRs, and187696LUT across the three barrier-statistics instances. Next equivalent optimizations must be selected from these real report boundaries. The measured332LUTonebucketpacked saving is a private screen; no complete-module/host reduction or target-parity claim follows. Naive256-writeraddressMCRams remains rejected by actual negative area evidence.


## First certified real card21 SVB sample at18:20CST

Independent audit completed with `EC_SVB_HOST40_INDEPENDENT_AUDIT_PASS WNS=0.000 WHS=0.001 period=24.997`. The certified bitstream SHA256 is `678a5b7fa0fcf56719fd011231748daf61f437b37136f304179c515c1c0e763e`. It was actually programmed only to card21/serial21770433G02LA. The directed component replay then passed on real FPGA at18:20:18CST: **372replaytargetcycles,333definedcycles,42291definedoutputvalues,returncode0**. Raw log includes the exact21BDF, FireSimfingerprint, `PASS_SVB_TRACE`, `[SVBProbe]PASS Test`, and `*** PASSED *** after373cycles` (the driver/simulation completioncount differs from the trace's372replayededges; do not conflate). Host driver reports40.007MHz, which is not architectural targetfrequency. The exact receipt and rawloghash are bound in `first-real-svb-fpga.json`.

The hardwarevalidated directedtraffic's15completeACKlifetimes have capture-to-ACK mean17.733333targetedges,max32,p95=32; promotionfire-to-ACK mean6.2,max13. These are syntheticdirectedcomponentlatencies, not fullECchecker/rollback measurements. The automatic samebitrealapplicationreplayfollower is preserved and will wake from its existing300swait; no duplicate replay or restart was launched.


## Application replay actually running and capacity producer complete at18:24CST

The real application follower woke naturally and began `RUNNING_REAL_APPLICATION_SVB_FPGA_REPLAY` at18:24:17CST using the same deployed certified bitstream. It made actual board progress beyond540672records by18:24:39, no mismatch yet; full replay success must await all1759001records and the bound summary. No reflash, duplicate run or restart was issued.

The MCRams producer has now completed and saved `postopt.dcp`, its exact hash and formal result: `NOT_FIT_FULL_GENERATED_HOST_NO_PLACE_RUN`, no place/route executed. `mcrams-postopt-resource-audit.json` now binds that final producer result and checkpoint hash. The capacity and continuation services were not restarted.


## Real application FPGA replay PASS and automatic metrics at18:25CST

The samebit21-only real application replay **completedPASS** at18:25:29CST. Actual summary: **1759001records/targetedges,53resetedges,19537248definedoutputfields,19698670outputwordchecks,84432048inputwordwrites,inputcachedisabled,mismatches0,capture/promote/ACK659each**. CPUcapturedtraffic expectedcounts and every replay summary count match; returncode0 and `[SVBProbe]PASS Test` are in the hashbound hardwarelog. Replaydriver wall72.2107s; inclusivehostwall72.345587s. Trace targetedges1759001 differ from simulationcompletion1759374cycles due driver/setup sequencing; retain bothdefinitions.

The read-only r2consumer published automatically at18:25:30CST. A separate read-only recheck of exact board/serial, certificate/bitstream, admission/trace/driver, replayrawlogandfullsummary, all659reference lifetimes, outputhashandCSVcomplete gates passed. Compact results are in `real-application-fpga-verified.json` and `real-application-svb-latency-summary.csv`; all659rows remain in the consumer's `matched-lifetimes.csv`.

Measured replay rate: **24359.2847targetcycles/hostsecond** for thedriverloop and24313.8671includinghostsetup. They includeMMIOoverhead, not autonomous peakSVB throughput. Capture-to-ACK across659complete capturedworkload lifetimes: **mean6844.2155,median7150,P958089,P998398,max8753 targetcycles**. The exact capturedtraffic was completely validated onSVB hardware; this is not fullECorformalPARSECperformance. Strict checker, detection/rollback and autonomouspeakthroughput remain unavailable from this componenttrace.

Both directed and application follower services exitedsuccessfully after their complete receipts. The21 card remains programmed with the certifiedSVBbitstream and no active replay is running. Normalr51,8dwholeDUT and remainingGoldenGate/addressprerequisite services are retained. OwnerMCRamscapacityproducer exitednaturally aftercheckpoint and its r3consumer now publishes `NOT_FIT_NO_PHYSICAL_IMPLEMENTATION_ADDRESS_PROTOTYPE_CONTINUES`. Unattendedstructural optimization continues from the measured post-opt bottlenecks, without blind replacement, repeatedwhole synthesis or CPUcomparisoncontrol.
