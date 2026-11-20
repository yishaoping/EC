# FPGA hardware continuation — 2026-11-12 19:08 CST

The first original SVB component certified bitstream is already on card21. Both directed
and real-application replay completed successfully. Complete EC remains NOT FIT and has
no complete-system bitstream or FPGA PARSEC performance sample.

## Actual SVB hardware result

The existing r7 K reused r6 I's routed checkpoint. Final WNS/TNS 0.000/0.000 ns,
WHS/THS +0.001/0.000 ns; no Setup/Hold failing endpoints, all255876nets routed,
zero routing errors. DRC0Error/49 retained and reviewedWarnings. Independent clock,
STA, route, DRC, pulse/skew and CDC-report audit passed; CDC is not claimed to have
zero critical findings. No timing constraints were relaxed.

Certified bitstream SHA256: 678a5b7fa0fcf56719fd011231748daf61f437b37136f304179c515c1c0e763e.
Board: 0000:21:00.0 / serial21770433G02LA. Directed replay372targetedges and42291
output values passed. Same-bit captured real-application replay1759001targetedges,
19698670wordchecks,659capture/promote/ACK,zero mismatches passed. It has completed;
no new programming or repeat replay was initiated in this continuation.

The read-only metrics report24359.2847replaytargetcycles/hostsecond includingMMIO.
Capture-to-ACK across659 captured workload lifetimes: mean6844.2155,P958089,
max8753targetcycles. These are captured-traffic SVB component measurements, not full EC,
autonomous peak throughput, formal PARSEC performance, checker or rollback latency.

## Complete MCRams capacity

The complete generated-host owner-MCRams post-opt result is authoritative:
2420482LUT/80990CARRY8/192DSP/1696013FF/898.5BRAM/0URAM/0blackboxes.
Capacity1303680LUT; excess1116802LUT, NOTFIT. This scope excludes the U280shell.
The producer naturally completed and saved postopt.dcp; no useless physical run is admitted.
Existing8d whole-DUT synthesis, r51 route and r3 continuation remain live with original
start identities; no healthy task or checkpoint was restarted or modified.

The old high-port address prototype naturally failed in GoldenGate CheckCombLoops with
12GiB Java heap exhaustion. Its previously measured bank area already regressed from
57148 to117874LUT. Failure evidence is preserved; a heap-only repeat of that rejected
structure is excluded. This is separate from the successful owner-MCRams capacity run.

## Work actually launched

The enabled persistent user service ec-opt4-address-packed-full-module-r1-20261112.service
owns a new private complete-module regression and subsequent sequential paired full-module
area. Current state: RUNNING_PARITY-POSITIVE. Both actual source Scala variants compiled and all
four proof/production RTL elaborations passed. The model checks52public outputs,
5120bucketwords,256valid bits and256sequence words before/after6144edges, including
arbitrary equal invalid payload, resetStats, normalreset and a real invalid-register
mutation rejection. Finite parity is still pending; no complete formal equivalence is claimed.
Proof-only observations are removed from both production area targets.

The 2core214–215 task has a64GiB address-space limit. The paired maps use identical
Vivado2021.1/default directives/part and strict total/hierarchy/primitive/blackbox parsing.
They start only after actual positive and negative parity gates pass. A single-bucket
332LUT screen gain is never multiplied or substituted for complete-module/host area.

The unattended round141 independently launched r4b during the foreground preparation.
Its already-live5172-output finite validation is preserved. Future area ownership is now
explicitly unified under the existing foreground r1; the current worker handoff forbids a
second area or duplicate parity. Pinned inputs are immutable. Genuine failures require a
diagnosed versioned correction after the exact old cgroup exits, never a blind restart.

## Next structural candidate prepared

Three real post-opt barrier-statistics instances total187696LUT (inclusive entries).
A private single-writer256x160memory candidate preserves the exact virtual bucket view:
invalid count/request are zero, and an independent sequence-initialized mask retains
sequence tags after resolve. A universal160payload-bit per-bucket next-state encoding
lemma and invalid-zero induction passed; a wrong valid-only sequence-mask mutant was
rejected. Actual Scala compilation also passed. Complete-module finite parity, actual
GoldenGate port extraction and paired complete-module host area remain before integration.
No candidate area saving is claimed; arithmetic/overflow/output code is byte-identical.

All future production admission retains8491167d as the sole functional baseline, exact
target-cycle semantics, full correctness/STA/DRC/certification,21-only access, and the
independent CPU PARSEC session. FullEC FIT must precede bitstream/FireSim; then prioritize
Blackscholes,Fluidanimate,Bodytrack,Freqmine,Swaptions,Ferret,Dedup,Streamcluster first
coverage, followed by three rounds and real ROI/checker/rollback/drain evidence.

## Evidence

- Existing full SVB proof and raw samples: ../svb-r6-continuation-20261112/REPORT.md
- This continuation: continuation-receipt.json and scheduling-reconciliation.json
- Packed task: ../../build-logs/Opt4-address-packed-full-module-r1-20261112/state.json
- Barrier state lemma/compiler: ../../build-logs/Opt4-barrier-valid-masked-storage-r1-20261112/result.json


## Actual new stage at 2026-11-12 19:11 CST

Complete private address module finite parity passed:6144cycles,52public+5120bucket+256valid+256sequence=5684outputs, compared before/after each edge and initial equal arbitrary invalid payload.3733statsValid/1626idleedges. The actual candidate invalid bucket register bitflip was detected exactly atcycle1000, portio_debugBuckets_3_255_3; it was not accepted as a generic crash. Positive runtime95.228s, negative expectedfailure16.06s. This is a finite complete-module regression, not whole-target formal equivalence.

The same existing service automatically began RUNNING_MAP-REFERENCE. Actual strict paired complete-module area remains pending, with candidate map following reference naturally. No new whole-host or device operation was started. The parallel r4b naturally failed Verilator's per-line input token limit; the next autonomous round has adopted this passing r1 instead of launching another correction. All normal CAD remains. Detailed boundreceipts:full-module-parity-and-map-started.json.
