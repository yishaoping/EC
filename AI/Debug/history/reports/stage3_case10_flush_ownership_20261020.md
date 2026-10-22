# Stage 3 CASE 10 flush ownership RCA (2026-10-20)

## Evidence boundary

User run: `AI/TMP/stage3_runs/run_igda2knt/`.
HEAD is `1ed07c28067fad6d8aed697323b465b925895914`. The recorded HEAD matches
the current checkout. CacheImage, Scheduler, MSHR, Directory, L2Preservation,
SinkC, SourceC, SourceD, Stage3Generate and the C++ fixture match their input
hashes; the saved generated `Stage3Harness.v` matches `build/result.json`.
The reviewed event window is `AI/TMP/stage3_case10_flush_audit_ao_r8k0l/module.trace.case10.log`.

## Finding

CASE 10's same-package supersede body completed. The fixture's checks before
its `CASE ... PASS` line proved the newer ReleaseData received its ReleaseAck,
made a real bank write, did not add a preservation Put, and was returned by a
subsequent Get with the new key/data. The failure happened after that marker,
during cleanup.

The host's readback `Acquire(a)` installs the speculative Q3 line in TRUNK with
one inner client. The trace shows cleanup validation at cycle 484, flush
accepted at cycle 512, flush MSHR lookup at hardware cycle 506 (`hit=1`, dirty,
clients=1), and a Probe at host cycle 515. At timeout, the ledger reports one
pending Probe, one active MSHR, no pending preservation, SourceC/SourceD idle,
no outer write acknowledgement in flight, and watermark 2. There is no C
ProbeAck afterward. The MSHR waits for the last inner ProbeAck before its
flush Release can be scheduled. Thus no flush Release was sent, no ReleaseAck
was awaited, and no directory invalidation occurred.

Classification: harness sequencing/lifecycle bug. The host does not implement
an automatic Probe responder; the dedicated ProbeAckData case enqueues its
response explicitly. After this case's readback Acquire, cleanup flushes
without returning the newly acquired ownership. The preservation and
validation logic are not the blocker: Q3 has already been validated, and the
checkpoint FSM is idle.

## Fix

After checking Q3 readback, CASE 10 now issues a real clean Release with
`TtoN`, waits for ReleaseAck and drain, then uses the existing cleanup to
validate and flush. It checks that the durable outer bytes equal Q3 before
printing CASE PASS. The clean permission return does not change data identity,
validate the package, or send speculative bytes to outer memory.

A read-only flush status bundle now reports the active control MSHR, stable
coverage-state name, address/set/way, complete image key, safety, dirty,
clients, receipt, Probe progress, Release issue/send/ACK, and final commit
handshake. The fixture preserves `FLUSH_ACCEPT`, Probe, commit, and response
events and emits a single `FLUSH_BLOCKER` classification on timeout. Removing
the new observation wiring/logs reconstructs the pre-turn MSHR and Scheduler
source byte-for-byte. No transition row, assertion, handshake gate, barrier,
or preservation protocol behavior changed.

## Static review

Passed: the `(p,c,m,r,f)=(false,true,true,false,true)` transition audit (18
ordinary allowed, 54 forbidden, 9 implicit self pairs, 6 separate flush
commit states, all 18 CASE markers); all diagnostic fields assigned once;
Python AST; shell syntax; C++ syntax using declarations based on the saved
generated model's port widths; `git diff --check`.

No Scala compile, elaboration, RTL generation, Verilator, model compile/link,
runner, or simulation was run. Consequently the modified Chisel diagnostic
bundle still needs a fresh build, and the cleanup fix needs a fresh directed
run. Stage 3 closure remains NO.
