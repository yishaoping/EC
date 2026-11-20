# Opt4 implementation acceleration — 2026-11-11T00:46:42.730096+00:00

Complete-top post-opt **NOT FIT**: **3,215,683 LUT / 1,303,680**,
**92,789 CARRY8**, **195 DSP**. Excess **1,912,003 LUT**, requiring
59.4587% reduction of current total. Optimized DCP saved; existing capacity gate
will stop before place/route after DRC report finishes. Full reports in
`build-logs/Opt4-fit-cad-8da24a26/`.

Largest disjoint target subtrees in the real post-opt hierarchy:
addressStats **1,265,491 LUT**, BOOM core **244,938**, MSHRFile **222,552**;
L2 **168,544**, SVB **117,870**. DCache parent **2,124,812** includes children;
never sum ancestors. MSHR0 **187,591** includes moved DCache metadata cones.
EDIF attribution crosschecks exact CARRY8/FF/DSP/BRAM; raw LUT primitive counts
are kept separate from packed physical LUT usage.

New exact validated combined candidate **9ae9a7fc**, source
`3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561`:
private compile, parameters, modified class origins, elaboration, GoldenGate
and actual seven-file ABI audit completed. Whole DUT synthesis really running
in `ec-opt4-auto-bucket-tag-cad-r1-9ae9a7fc.service`, controller PID1737960,
Vivado launcher1886240 (recheck boot/start identity on reconnect).
Worktree `Opt4-fit-address-bucket-tag-r3-20261111`, CAD outputs
`builds/cad-9ae9a7fc`, state `Opt4-fit-bucket-tag-cad-state.json`.
Address OOC measured **990,905 LUT / 55,418 CARRY8 / 0 DSP**, reduction509,666
LUT (33.96%) versus 1,500,571 baseline. This is not new whole-system area/FIT.
No update-share/epoch/SVB combination was silently added.

Parallel independent candidates: f2d2ca3e SVB balanced argmax (local arbitrary
69-bit merge SAT, negative mutation and generated 32-leaf/31-merge topology
passed; monolithic SAT/map still pending); 7e68d3df shared retirement read
(first exact arbitrary256x64 bank SAT, mutation and8192 vector boundary passed,
complete frozen6144-cycle/52-output regression passed, module map running).
Full reports and errors stay in their separate build-log directories. Pending
proof/map never admitted as verified whole RTL.

Recovery repair: ledger writable for UID1008 and root-created append fixes;
private ccache real compiler probes passed; explicit evidence_inputs under
Experiment/build-logs get exact hashes while executable/source inputs stay in
firesim. Completed jobs reuse only when input/output hashes still match.
Snapshot discovers candidate checkpoints dynamically. At most8 campaign jobs,
extra beyond6 require192GiB available; one newCAD, only newDUT synthesis may
overlap predecessor completed-DUT opt; top implementation is serialized.
Only supervisor was reloaded; old CAD/GG/worker PID identities preserved.
Do not restart live tasks. systemd jobs and broker requests remain independent
of this terminal, ledger/state atomically persisted.

Runtime request `unattended-opt4/requests/9ae9a7fc-start-runtime.json` automatically
waits for exact successful CAD timing/DRC/bitstream, then existing shared locks
and 21-only tools. No e2/global FPGA operations. Native stays paused.
13 synthetic collector fixtures passed rejection checks; these are never
FPGA samples. Actual SVB invalidation/WB-owner/data test is separately queued.
Architectural fault injection + restore/restart interface remains unestablished;
normal checker/drain, promotion ACK or host reset must not be called rollback.
No bitstream, FPGA Opt4 sample or placement/routing has yet been produced.

Evidence: [audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T0046Z/audit.json).
