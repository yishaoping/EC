# FPGA continuation, 2026-11-12T04:38:33.498863+00:00

SVB r4 completed without a certified bitstream. C remains the best final
checkpoint: WNS −0.411 ns, TNS −292.970 ns, 2,130 setup failing endpoints,
WHS +0.001 ns. D completed with WNS −0.503 ns, TNS −343.017 ns,
2,299 setup failing endpoints, WHS +0.001 ns. Their routed checkpoints and
failure receipts are preserved; neither is deployable. Both have zero route
errors and 49 warning DRC violations.

Independent r5 is installed and started: RUNNING_ADMITTED_HOST40_SHELL_RECOVERY,
mode E-preroute-shell-replication, controller PID 2692645.
It holds r4's released extra-component-slot lock and uses a private copy of
the best completed checkpoint. E removes routing before bounded shell FD-Q
replication. If E fails, F automatically removes routing on a private copy
of the best final checkpoint and applies explicit fanout/placement/routing
optimization. Actual support and timing improvement must come from Vivado;
offline binding checks do not establish either. No retiming or RTL changes.

The original complete Tcl timing/route/DRC/pulse/skew/clock gate and independent
certificate are byte-identical. Three new services run physical recovery,
independent certification plus card21 directed testing, and same-bit real
application trace replay. All bitstream, source, software, locks, board serial
and correctness bindings remain required. SVB is a component, not complete EC.
The measured same-slot guard remains CPUs 224–225, 64 GiB, max3 component Vivados,
192 GiB available memory, load1 below128, disk at least150 GiB.

MCRams complete generated host synthesis and owner-MC parity remain under
their original controllers and exact cgroups. New LUT/FIT is still unknown;
the capacity/parity continuation and complete EC priority runtime remain alive.
The old completed 9ae full post-opt result is 2,847,382 LUT, NOT FIT; it is not
a new MCRams measurement. No new whole-system CAD was started.

Original r51 and resumed-r3 routing are preserved. Global unattended r2 remains
active and its next-worker instructions now identify r5, its evidence, and the
automatic failure-recovery requirement. No CPU replacement experiment was
controlled. Only0000:21:00.0/serial21770433G02LA can be admitted after certification.

Complete EC PARSEC order remains Blackscholes, Fluidanimate, Bodytrack,
Freqmine, Swaptions, Ferret, Dedup, Streamcluster; first cover r1, then r2/r3.
ROI target cycles, checker correctness/events, drain and output gates remain.
No new FPGA sample or strict detection/rollback latency is claimed.

Validation: Python compilation; unchanged gate/certificate byte comparison;
immutable source/software input verification; original runtime/application
offline binding checks; actual systemd start and process/cgroup verification.
The contemporaneous detailed evidence is in snapshot.json. No credentials
were written into artifacts.

Actual tool milestone: forced replication completed successfully after private unroute. Vivado reports 4 optimized nets and 52 added cells. New routed timing is still required; unrouted timing estimates do not certify closure.
