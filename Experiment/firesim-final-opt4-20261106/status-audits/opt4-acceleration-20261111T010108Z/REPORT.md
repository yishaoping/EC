# Opt4 acceleration evidence — 2026-11-11T01:01:08.712094+00:00

Complete top **NOT FIT** for 8da24a26 after opt_design:
LUT **3,215,683 / 1,303,680 (246.662%)**, CARRY8 **92,789 / 162,960**,
DSP **195 / 9,024**. FF1,796,777; BRAM1,028.5; URAM0.
LUT excess **1,912,003**, requiring59.4587% reduction of this measured total.
`capacity.complete` now confirms NOT_FIT_POSTOPT; original Vivado/controller
naturally exited after DRC. Optimized DCP and all original reports preserved.
No placement/routing was started; no restart or duplicate old build.

The largest selected non-overlapping target subtrees are addressStats
**1,265,491 LUT**, BOOM core **244,938**, MSHRFile **222,552**. L2 is168,544;
SVB117,870; direct DCache112,594. DCache ancestor2,124,812 includes many of
these children and must not be summed. MSHR0's187,591 includes moved DCache
metadata cones; EDIF/source audit rejects naive source-local attribution.
Even eliminating all addressStats would still leave646,512 excess LUT: address
optimization alone cannot establish FIT. No functionality is removed.

**9ae9a7fc** is actually in whole-DUT synthesis, controllerPID1737960/start16778336
on boot`d6c6e410-10ad-4326-86ba-79b657eabd96`; use live state to revalidate.
State`Opt4-fit-bucket-tag-cad-state.json`; persistent service
`ec-opt4-auto-bucket-tag-cad-r1-9ae9a7fc.service`. Its complete address OOC map
is990,905LUT/55,418CARRY8/0DSP,509,666LUT lower than1,500,571.
Private source compile, actual class origins, exact frozen parameter equality,
elaboration, GoldenGate and all7realABI/description files are verified.
This local gain is not a new complete-top resource result or FIT prediction.
Only11hash-verified unchanged platform shell DCPs are reused, never old DUT.
New whole CAD has NOT FIT pre-placement gate and FIT implementation/timing/
DRC/bitstream continuation. No unproved candidate was stacked into this build.

**SVB selector f2d2ca3e**: repaired the failed C++ test oracle in separate r7;
monolithic32-slotSAT timed out and remains explicitly not passed. Local
arbitrary69-bit mergeSAT plus negative mutation and exact actual32-leaf/31-merge
topology certificate passed, along with8192vectors. Exact substitution audit
preserves all state/update/ports/cycles. Same-selector OOC:
**43,898→3,230LUT (-40,668)**, **5,952→124CARRY8 (-5,828)**,0DSP.
Complete candidateSVB map is130,912LUT/10,474CARRY8/33,684FF/0DSP.
Do not compare that OOC total directly against prior top post-optSVB117,870;
the exact same-harness reference full-SVB map is separately queued. No whole-DUT
admission or FPGA validation is claimed.

Other live independent maps include full-width retirement-read decoder sharing,
valid global-reset-safe update sharing, async current-bucket memory and tag
compression. Each retains its own proof/source/area receipts. Stale-invalid
assumption-dependent update-share-r1 has an admission hold; r2 separately fixes
it. Group8 proof/CEC attempts that time out are never counted as pass.
Direct synchronousBRAM/URAM substitutions were rejected as changing current
combinational multiport reads and same-cycle ownership guards. Asynchronous
memory/decoder sharing is investigated without reducing sizes or event widths.

**13 ordinary programs' exact derived software is now prepared**, not just a
future script. Artifact`runtime/Opt4-fit-9ae9a7fc/software-suite.json` has exact
ELF/rootfs/firmware/driver hashes and3valid matching Native references per app.
Actual driver reuse is byte-certified across7ABI/description files, with a
separate derived receipt. First-round coverage order remains before r2/r3.
The existing runtime request waits real certified timing/DRC bitstream and21
safe locks. No Native experiment resumed and no FPGA operation occurred.

Real-RTL SVB invalidation/512-bit payload/backpressure/owner-lifetime and negative
mismatchedACK assertion validation r2 is queued after fixing missing exact
SafeChainEventLogger input and capture-admission stimulus. Assertions enabled;
all r1 failure evidence retained. These tests do not establish real checkerFAIL,
CDC cleanup, architectural restore or instruction restart. The architectural
injection/restore/restart interface is still unestablished and remains an explicit
validation gap. Synthetic collector rejection fixtures are not FPGA samples.

ccache/ledger/manifest recovery tests passed. Repaired only derived9ae runtime
output directory ownership so the user-owned preparation job can write; no
bound script or existing live input was edited. Broker caps8CPUjobs and one new
whole CAD, with memory/disk gates; pending jobs are honestly queued, not running.
Supervisor/module/CAD services remain detached and preserve PID/start/boot
identity, atomic states, per-stage receipts and logs. New AI iterations retain
the documented external model-proxy dependency. Native remains paused; all
future FPGA access must use0000:21:00.0/21770433G02LA. Never touch e2 or globalXDMA.

Full immutable snapshot: [audit.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T010108Z/audit.json).
