Prepared and tested a separate read-only preplace exception assertion.
It is not installed in the existing r4b observer or any active CAD flow.
Nine Vivado fixture cases passed (two valid, seven rejected); five mutations
of a real valid-exception export also passed. Negative cases must reject for
the expected reason; tool API errors do not count as successful rejection.

A proven fixture counterexample showed 100% exception coverage while one
checker path was false-pathed. The verifier now inspects the resolved clock
domains of other valid exceptions and checks user-ignored paths. It retains
the original native master, divide-by-one clocks and setup/hold 1/0 and 2/1,
and checks representative effective timing requirements and EXCEPTION fields.
It changes no constraints. The renderer adds only this assertion to the
original BD/IP top-opt script after preserving checkpoints and reports.
Unsupported export formats fail closed.

The fixture is not the full host or shell. Actual fullshell verification and
automatic integration remain pending independent versioning. Existing r4b
was preserved as instructed. The report-only source gap is proven; a physical
failure caused by missing exceptions in the actual full shell is unproven.
Its downstream risk would be admitting placement before asserting the full
exception contract. No fullshell timing or certification is claimed.

The immutable 06:59:22Z continuity capture records PID/start_ticks/boot_id and
exact cgroups for r5 E, full MCRams synthesis, r3 continuation, r4b observer,
priority follower and the original metrics consumer. At 07:08:33Z E remained
running. Global iteration 7 reached zero overlaps with intermediate WNS
-0.357 ns, TNS -183.342 ns, hold unavailable. These are not final timing or
route results. Preserve existing E hold_fix/reroute and conditional F.

At 06:59Z complete MCRams synthesis was still running without synth/postopt
counts or FIT. Owner-MC finite parity is PASS, SHA256
02025ffe79f679d0e37dc007d940d9c61eea3d8095acc1f6f234e5fa5a6eb29b.
This is captured-row/print-stream parity, not full equivalence.

The original metrics request was naturally admitted at 06:24:27Z.
PID 2813002/start_ticks 27638842 is waiting for certified FPGA application
replay: it is running, not queued. No duplicate request was created and no
memory guard changed. R4b remains a waiting observer; no conditional physical
repair was submitted. No production source, CPU comparison, device or live
CAD process was controlled. Only bounded primitive-netlist timing diagnostics
were launched; no synthesis, opt_design, placement, route or bitstream ran.
