# Round 49 — completed module maps, owner-token audit, and read-only recovery

Frozen functional/cycle baseline: `8491167d84b6d9521b151a743673c1516926a1f8`, v1Config/C4/SVB32. Native remains paused; no target RTL/config changes or FPGA I/O were made by this worker. Existing physical routes, followers, and e0 remain untouched.

The latest completed whole result remains **9ae NOT FIT: 2,847,382 LUT / 1,303,680, excess 1,543,702**. e0 is live in DUT Timing Optimization, with no new complete resource report. There is no authentic new component/full-Opt4 FPGA sample. These facts do not stop either evidence route.

## Actual complete-DCache maps

Authenticated the main CLB totals and immutable producer/report hashes in `actual-full-dcache-ranking.json`. All alternatives share the same e0 reference and preserve original observed ports.

| Exact candidate | Complete DCache LUT | Saving versus 1,770,518-LUT reference |
|---|---:|---:|
| 3656aec4 field reads | 1,629,524 | 140,994 (7.9634%) |
| d9d73262 field banks | 1,634,951 | 135,567 (7.6569%) |
| 2210930f packed owner | 1,698,302 | 72,216 (4.0788%) |

Each has 221 BRAM / 66,607 CARRY8 / 48 DSP. These inclusive alternatives must not be summed. They are actual full-module OOC measurements, not MCRams host-area results or whole post-opt capacity. The 99c consumer rejected its own below-threshold 72,216-LUT gain. The existing unique 8d consumer automatically advanced to GoldenGate; no duplicate consumer, GG, map, or whole CAD was submitted.

## New proof and recovered real wrapper area

Source-bound owner-token audit v3 passed on the exact emitted module: 301 owner-interface ports, 35 response channels, 74 command channels, 1,308 finishing conjuncts, two clock domains, and 3,210 exhaustive scalar valuations. Five mutations were rejected. Incoming response state consumes the next clock token, while outgoing command state uses the current enabled clock; this distinction must be retained. Result SHA256: `44488671a2f22ca9861dc2251c8a7846c20e79e20d670824959d78efcc9fcddd`.

The v1 recursion failure and v2 ineffective whitespace mutation remain sealed. This audit checks exact emitted token/clock Boolean identities; it does not prove RAM data semantics, full-DCache equivalence, or a smaller composed host area boundary.

The already-running generated-owner map had completed synthesis and saved reports/DCP, then failed its parser because Vivado omits zero-use primitives. Main-table CARRY8 was exactly zero, but the parser required an explicit primitive row. Confirmed the failed producer and child identities absent, MainPID0, and the exact systemd cgroup absent/empty. Preserved the original failure, inputs, log, and DCP.

Independent read-only recovery validated main totals against hierarchy, BRAM/FF/carry primitives, all 294 RAM-wrapper ports, exact module bytes, and zero blackboxes. Starred/unstarred total rows, SLR separation, capacity checks, duplicate/missing rows, resource disagreements, and blackbox mutations were tested without relaxing original checks. Actual emitted `ownerImageMemory_flattened` + `RamModel` closure is **3,245 LUT / 2,906 FF / 1.5 BRAM / 0 CARRY8 / 0 DSP / 0 URAM**. It excludes DCache and the FAMETop scheduler and has no paired full-system gain claim. The 294 RAM-wrapper ports and 301 DCache-side owner-interface ports describe different boundaries.

The first analysis request r2 was rejected before execution because broker inputs directly referenced D outside the permitted W input root. r3 pins W sources plus sealed report copies and still validates original report hashes. r3 STARTED and completed exit0, broker PID2048581/start22634258, analysis child PID2048582/start22634262, boot `d6c6e410-10ad-4326-86ba-79b657eabd96`. It ran no CAD or FPGA tool. Recovery result SHA256: `7d09040b3f35d85e5377ff0b7dfba3a0528559ef332cb2c2da6da289934676a3`.

## P0 continuation and capacity risks

At 16:28 UTC, actual PID/start/boot checks adopted the existing full force-all GG SVB replay, owner Plain→MC sequential Canneal pair, Blackscholes GG run, unique8d GG, original/spread physical routes and waiting 21-only followers. These jobs were automatically admitted existing requests, not newly launched jobs of this worker. No extra Canneal or workload was started.

The existing round47 binary coverage audit completed: 1,759,001 target edges, 659 captures/promotions/ACKs each, 19,698,670 defined output-word checks, zero mismatches, 53 reset edges. This counts the bound original binary stream and is not an additional replay or FPGA result. Full GG stream positive/mutation checks still have to complete before board admission; existing followers enforce the source/ABI/bit/timing/DRC/card binding and both21 locks. No authentic bitstream or hardware sample is claimed.

Latest observed component route logs had intermediate WNS −2.711ns for spread and −6.568ns for original, with routing still active. These are not timing passes. Conditional recovery must wait for explicit producer failure/exit and empty exact cgroups; no recovery CAD was launched here.

The sprint watcher is MONITORING, with deadline 2026-11-12T08:52:10.022583+00:00. Latest independent resource observation at 16:28 UTC: 214.22GiB available memory, 311.12GiB free disk, load64.64. The 256GiB light-auxiliary gate remains unchanged. Current assessment is HIGH RISK: large measured whole LUT excess, pending e0 capacity, incomplete owner full-target parity/area, negative component route timing, and no valid FPGA sample. CPU throughput and finite simulator observations remain separately labeled; no slowdown, architectural restart, or strict checkerDone-minus-BOOMDone claim is made.

## Next safe action

After at least300s, adopt incremental completion receipts for the live SVB force-all replay and owner Plain→MC runtime and preserve failures for independent versioned recovery. Check e0 no more frequently than600s. Let unique8d finish its existing GG/ABI/composition gates; do not create another whole while e0 is live. On actual certified timing/DRC component completion, the installed matching21-only follower owns deployment and replay; worker performs no FPGA I/O. Continue the exact composed DCache/RAM/token-boundary verification required before claiming broader area savings. No policy, live source, target parameter, controller, follower, device, or native task was changed.

All new files and hashes are listed in `changed-files.json`. Raw adoptions, rankings, recovery receipts, failure history, and source bindings are retained alongside this report.
