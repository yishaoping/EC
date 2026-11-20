Prepared a runnable, independently versioned integration of the round-130
exception assertion. The new runner is not installed or queued. The installed
r3 consumer, r4b observer and all observed bound sources remain unchanged.

The runner retains the pinned r4b BD/IP loader and all original physical,
capacity/parity, resource, checkpoint-reuse and canonical-publication gates.
It adds a required hashed exception-contract output to top-opt, checks that
receipt before placement, and repeats the assertion before write_bitstream.
Final timing/DRC reports precede the added final assertion. No clock period,
physical clock name, generated XDC command or multicycle is changed by this
integration. Removing the additions reproduces the r4b stage bodies.

Thirteen offline ownership and pipeline tests passed. Tests include successful
checkpoint reuse, NOT_FIT without placement, missing/tampered preplace proof,
missing final proof, canonical-state races, exact-service/cgroup ownership and
singleton-lock contention. The real active r4b observer was rejected by the
new admission check. Full inherited source/collateral pin verification passed.
No Vivado, synthesis, opt_design, placement, routing, bitstream or simulation
was run for this round's validation. Actual fullshell assertions remain unrun.

The evidence boundaries are:

- Proven source symptom: r4b reports exceptions but does not invoke the
  separately prepared verifier. Round-130 fixture tests establish the
  assertion's diagnostic behavior, not complete-host behavior.
- Proven immediate admission blocker for this successor: the original r4b
  observer remains active. The new runner refuses it, a live exact service,
  orphaned cgroup members, or any already submitted r4b repair. It also holds
  the observer's existing instance lock for its entire admitted run.
- Proven upstream distinction: the original manual r2 flow omitted the BD/IP
  loading mechanism. The prepared r4b loader already addresses that source
  gap. Missing effective exceptions in an actual fullshell remain unproven.
- Unproven downstream risk: a report alone could permit placement without
  asserting the full effective target exception contract. The successor adds
  that assertion; it does not claim a demonstrated fullshell failure or repair.

The immutable 07:35:01Z capture records matching PID/start_ticks/boot_id/exact
cgroups for the observed r5 services/router, full MCrams synthesis, continuation,
r4b observer, priority follower and original metrics consumer. Bound source
hashes match round 130. R5 router PID2692703/start26961377 remains active with
55 overlaps; latest router intermediate WNS=-0.190 ns, TNS=-52.806 ns,
WHS/THS unavailable. These are not final route/timing/DRC or bitstream results.

Original full MCrams PID2379656/start25825451 finished technology mapping and
entered final netlist cleanup. Synth/postopt utilization, result, postopt DCP
and early capacity JSONs were absent at capture; LUT/FIT remain pending.
Owner-MC finite captured-cycle/output-event parity is PASS, result SHA256
02025ffe79f679d0e37dc007d940d9c61eea3d8095acc1f6f234e5fa5a6eb29b.
This is not full equivalence or FPGA certification.

The unique original metrics job is RUNNING; its consumer waits for certified
application FPGA replay and performs no device IO. R4b is an active waiting
observer with no physical repair submitted. The new integration has no job
or request. No live process was signalled and no CPU comparison was controlled.

Next automatic actions remain with existing services: E hold_fix/reroute and
conditional F, unchanged physical certification, then 21-only directed and
same-bit application replay. MCrams FIT plus finite parity admits r3; only an
actual matching r3 clock failure and released exact cgroup admit the existing
r4b repair. Preserve this successor for independent selection after that
observer releases without submitting a repair; never run it alongside r4b.
