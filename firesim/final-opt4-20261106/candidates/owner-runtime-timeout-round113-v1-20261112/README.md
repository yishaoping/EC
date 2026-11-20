Reuses the existing compiled owner-memory MCRams model and the completed Plain
reference. No target, RTL, software, timing-model, checker, or board changes.

The original MC process hit its 10,800-second host timeout at target cycle
1,040,734. Round 58 derived an 18,291-second completion projection and a
29,280-second host budget. This controller preserves that measured budget and
the original five-million target-cycle / four-GiB owned-log limits.

Round 58 v1 incorrectly compared mixed UART/RTL drain order. Its v2 separated
INIT but left the application's RUN row in the other stream. This version
separates exactly the three startup rows whose format strings must occur in the
bound ELF; it checks their exact order and contents. Every remaining complete
stdout line is compared byte-for-byte and in order. No complete lines are
dropped or normalized. Partial final bytes remain hashed and counted. Eight
negative mutations check UART payload/order/missing rows, target value/cycle/
missing/duplicate rows, and unknown messages. Any real mismatch prevents runtime.

The original/v1/v2 controllers, child identities and exact systemd cgroups must
be exited and empty. The same checks and the original instance lock guard the
retry. CPUs 250-251 must be free of narrow live affinities; no second Canneal may
run. The broker and existing memory/disk guards remain in force. Original
failure evidence is immutable. This is finite CPU metasim evidence, not full
formal equivalence, full Opt4 FIT, FPGA data, or a formal PARSEC experiment.
