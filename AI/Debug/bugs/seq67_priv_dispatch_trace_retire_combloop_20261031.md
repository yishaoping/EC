# seq67 privileged-dispatch trace/retire feedback

Confirmed source/generation blocker in the user-run seal1fc6abc9. The attempt
`optimization_4_svb_20261031_021006_49d07b20` failed RTL_GENERATION; no benchmark started.

Loop in Rocket/Rocket_1/Rocket_2/Rocket_3:
`check_exception -> !check_exception -> wb_valid -> csr.retire -> geq(retire,0)
-> csr.trace[0].exception -> privileged_start_ready -> check_exception`.

The previous analysis incorrectly treated slot0's unsigned retire>=0 as eliminating
its structural dependency before CheckCombLoops. Type checking did not detect this.

Corrected RocketCore's privileged_start_ready to read existing raw CSR r_exception
(insn_call || insn_break || io.exception) instead. This preserves the same Boolean
slot0 exception test and current-trap priority, without a delayed gate or new CSR IO.
No cleanup/result/watchdog/R_ICSL/observer change in this correction.

New report: `AI/TMP/checker_seq67_one_shot_20261031_103130/`.
`dispatch_dependency_audit.json` reproduces all4 loops from the saved FIRRTL and
removes them under the one-input in-memory substitution. This proves the scoped
reported feedback is cut, not a new full FIRRTL validation. Scala typer and45 offline
CPU tests PASS. All new hardware phases are user-pending; agent ran none.

Old failed artifacts/seal/claim are immutable. A new B-only seal/claim is prepared.
The one-full-benchmark budget is unspent; no A or diagnostic-only run is scheduled.
