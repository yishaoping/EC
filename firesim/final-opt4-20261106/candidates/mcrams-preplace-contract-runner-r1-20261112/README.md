Independent runner integrating the pinned round-130 exception verifier into
the r4b BD/IP loading flow. This version is prepared, not installed or queued.
The existing r3 consumer and r4b observer remain authoritative and unchanged.

The runner refuses admission while the exact installed r4b observer identity,
service or cgroup is active, or its physical request/output already exists.
It never stops an observer or creates a request. It is a concrete successor
for a separately selected continuation after that observer releases; it must
not be submitted alongside r4b. A changed observer identity requires review.

It retains actual failed r3/top-opt evidence and exact empty predecessor
cgroup requirements, capacity FIT and finite target parity hashes, original
resource guards and locks, successful stub/wrapper checkpoint reuse, all
generated BD/IP collateral and the separately source-bound target XDC.
No complete-host synthesis can run. Physical clocks and multicycles retain
the r4b semantics: native BUFG binding, divide-by-one, setup/hold 1/0 and 2/1.

The top-opt stage must produce the assertion result as a hashed stage output.
Placement checks that receipt again. Final timing/DRC/route/pulse/skew gates
are retained, with the same assertion repeated before write_bitstream.
The final assertion is also a required stage output. Checkpoints and reports
precede assertions so failures retain evidence. Canonical runtime publication
requires an unchanged failed predecessor and released exact cgroups again.
Existing independent certification/software/21-only runtime gates still apply.

Offline runner tests exercise admission refusal, stage failure propagation,
checkpoint reuse, required assertion outputs, tamper rejection, NOT_FIT and
canonical preservation. They do not prove actual fullshell constraints,
physical FIT/timing/DRC, certification or FPGA application measurements.
