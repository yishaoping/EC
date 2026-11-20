# Round 53: actual owner memory lemmas and preserved two-route execution

Sealed 2026-11-11T18:25:10.803190+00:00. Sole target function/cycle baseline remains
8491167d84b6d9521b151a743673c1516926a1f8, C4/v1Config/SVB32. No target RTL,
experiment parameters, source/driver profiles, live job inputs or FPGA state was
changed. Native remains paused. All new work was CPU proof/analysis through the
existing broker; no nested agents, third whole synthesis or board I/O.

## Completed verification

The exact emitted owner RamModel SHA256 is
46428dc8d9868145ee7636f7da186ea61906da0bb3e0fad3dc756ffd95c135a4.
This is the actual35R1W,512x81 model previously matched by explicit port bijection
to the full owner-only GG output for3656aec4. Three separate lemma groups now pass:

| Actual-source obligation | Positive checks | Rejected mutations | Scope |
|---|---:|---:|---|
| Controller/payload reset, relational induction, all outputs/address/writer gates, read-before-write |82|7|One explicit symbolic read-word cut; no memory-content claim|
|512x81 storage step at arbitrary stable watched address, nine9-bit projections|9|2|Actual uncut storage/writer; all41,472stored bits covered; reference uses actual writer controls|
| Actual async-read/pipeline snapshot, same-address read/write old-word semantics, nine9-bit projections|9|3|No read-data cut; reset unconstrained; selected word related before edge|

The controller v1 conjunction timed out. v2 reset and all37 induction factors
passed, then its combined observation query timed out. Both failures and raw
logs are preserved. v3 independently regenerated the exact v2 harness, validated
and adopted all38 successful source/script/log/exit checkpoints, and proved all43
output factors under the same full relation plus the read-before-write guard.
Added verification aliases are exactly reversible. No successful stage was rerun.
Timeouts were never promoted to PASS.

Storage mutations changed the actual writer payload/address. Read-snapshot
mutations corrupted bit80, changed async read address, and introduced same-edge
write forwarding. All produced rejected counterexamples. Controller mutations
covered priority/address/mask/stalled-payload/reset/advance/pipeline.

The independent ledger revalidated100positive obligations and12rejected actual
source mutations, final receipts, source/script/log hashes and exact SAT command
constraints, after all three producers exited. Ledger result SHA256:
9837f6e6c7727b46c7b8832733bc3111d502f02d8b7f7604916fb05d83ac69d4.

Receipts:

- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-owner-ram-controller-round53-v3-20261112/result.json
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-owner-ram-storage-round53-v1-20261112/result.json
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-owner-ram-read-snapshot-round53-v1-20261112/result.json
- /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-owner-memory-proof-ledger-round53-v1-20261112/result.json

The prior actual queue induction and109-channel wiring audit remain separate
receipts. These combined records do **not** prove complete adapter/FAME
target-advance/clock/reset composition, all-history frozen DCache/Opt4 equivalence,
full-system area/FIT or FPGA success. Initial memory contents are arbitrary,
not zero-initialized. Valid-only payload comparison and the controller read cut
remain explicit. The watched address is held stable across the induction edge.

## Route A: existing execution adopted

At 2026-11-11T18:23:48.395554+00:00, SVB force-all replay reached
1,691,648targetcycles and
18,957,787defined output-word checks, with
0mismatches. This is incomplete positive CPU replay,
not final PASS or FPGA data. Controller2025116/start22545747 and child2025119/
start22545758 matched the boot-bound identities. Required +svb-force-all-inputs
is retained.

Owner-only Plain run is complete with correct Canneal checksum andROI536456/
392248instructions. MCRams runtime controller2025367/start22546057 and child
2086926/start22779600 remain live. No paired-final parity receipt exists yet.
The prepared round52 four-memory submit.py --check returned
DEFERRED_EXISTING_P0_RECEIPTS for both final results. No request was submitted;
use the existing singleton only after exact successful receipts and producer exit.

Both original and spread physical attempts failed timing. Preserved original
WNS/WHS=-10.999/-0.084ns; spread WNS/WHS=-2.010/+0.001ns at actual19.998ns
clock/56,584registers. No timing relaxation or target change. Original/spread
certification followers failed closed on those CAD failures with fpga_access=false.
Existing recovered certificate/application followers remain waiting; the
resource-aware recovery controller2118833/start22940221 is live and deferred by
unchanged load<48 guard. No CAD restart or duplicate recovery was launched.
No authentic new bitstream or FPGA sample exists.

## Route B: actual measurements, no whole saving inference

Full9ae post-opt remains NOT FIT:2,847,382LUT/90,740CARRY8/195DSP;
LUT excess1,543,702. Existing e0 is the sole live whole. At18:16:56Z its
controller2484108/start18403856 and Vivado2484262/start18404293 matched the
boot identity; worker CPU ticks4,894,438 advanced. Log remains TimingOptimization;
no new complete capacity report. Do not interrupt for log silence.

Completed actual observed full-DCache pair reports were hash-verified and ranked
against the samee0 reference1,770,518LUT:

| Candidate | Actual full-DCache LUT | Module LUT delta |
|---|---:|---:|
|3656aec4 field-read|1,629,524|140,994|
|d9d73262 fieldbank|1,634,951|135,567|
|2210930f full pair|1,698,302|72,216|

Separate e211 complete address module:761,398LUT/47,797CARRY8/374,783FF/
216BRAM. These scopes overlap and are not summed or subtracted from whole LUT gap.
The exact generated owner wrapper map remains3,245LUT/2,906FF/1.5BRAM,
zero blackboxes,294ports; not fullDCache/whole area. Existing8d successor
and all source/cycle/ABI gates are adopted; no duplicate whole or GG preparation.
See measured-module-ranking.json for precise reports/hashes and source IDs.

##24-hour risk and next safe work

Snapshot 2026-11-11T18:22:12.819390+00:00: available memory247.79GiB,
free disk306.61GiB, load57.84 57.76 57.73 56/24148 2168996. At sealing,
about14.45hours remain before2026-11-12T08:52:10.022583Z. Hardware
delivery risk remains high: the whole LUT gap is large, both component physical
attempts failed timing, and recovery waits load<48. Memory below256GiB does not
permit extra light auxiliaries. Guards were preserved; CPU simulator results stay
separately labelled.

After>=300seconds, adopt SVB replay and owner runtime final receipts and exact
identities. Continue the prepared four-memory singleton only once both actual
P0 results/negative checks and exits pass its own admission. Develop the remaining
adapter/FAME target-boundary composition proof on sealed verification copies;
do not label the separate lemmas complete Opt4 equivalence. Check whole e0 no
sooner than18:26:56Z and then at>=600second intervals. Existing recovery/followers
own physical repair and21-only certification/deployment; worker never does FPGA I/O.
On a genuinely certified FIT, prioritize existing implementation/runtime services.

All source/job versions, failed evidence, raw logs and results remain immutable.
