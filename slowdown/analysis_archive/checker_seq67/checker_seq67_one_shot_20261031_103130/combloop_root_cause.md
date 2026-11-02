# Confirmed generation blocker

The user-run parent build failed CheckCombLoops in Rocket, Rocket_1, Rocket_2 and Rocket_3. Exact cycle:

```text
check_exception -> !check_exception -> wb_valid -> csr.io.retire
 -> CSR trace slot0 geq(retire,0) -> trace.exception
 -> privileged_start_ready -> check_exception
```

Type checking cannot detect a hardware dependency cycle. Although UInt retire>=0 is
mathematically true, this dependency still exists in FIRRTL when CheckCombLoops runs.
The earlier source-only reasoning claiming it had disappeared was incorrect.

Minimal correction: use existing CSR `r_exception = insn_call || insn_break || io.exception`.
It has the same slot0 Boolean exception semantics without retire dependence. The gate
still excludes the current trap/return; there is no extra RegNext or lost-pulse window.
R_ICSL entry trap capture, diagnostics, cleanup, result handoff and watchdog are unchanged.

`dispatch_dependency_audit.json` reconstructs the reported cycle from the archived
238403999-byte FIRRTL in all4 module pairs, then substitutes only the reviewed gate
input in memory. All4 scoped cycles disappear; raw exception has no path to retire.
This is an offline scoped graph audit, NOT a new full FIRRTL compile. The new full
CheckCombLoops result remains pending the user command.

Old failed seal, source snapshots, claim, manifest, log and generated artifacts are
preserved. Old simulation NOT_STARTED and no SIMULATION_STARTED marker: zero new full
benchmark runs have been spent. This revision still requests exactly one B, no A,
no diagnostic-only benchmark and no clean-all.
