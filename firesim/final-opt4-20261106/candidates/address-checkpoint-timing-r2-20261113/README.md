Report-only timing of existing immutable AddressStats checkpoints. No design
change, resynthesis, optimization, placement, route, checkpoint write or FPGA IO.

First measure the completed DSP leaf Reference/Candidate pair, then wait for
the sole live production-areaR5 and measure its Plain/Threaded complete hosts.
Use the same 10ns clock and zero input/output delays within each pair. These
are synthesis estimates, not routed timing and not complete-shell closure.
DSP leaf and production host scopes differ; never rank their WNS directly.
Resource totals and host-token costs must accompany any implementation choice.

Two idle campaign CPUs228/229 and memory admission prevent overlap with the
future complete-shell service, which checks those CPU owners before starting.
The current area synthesis remains untouched. Hashes before/after each report
bind unchanged input checkpoints and output timing/resource reports.

R2 fixes only the unsupported Tcl remove_from_collection command from R1,
using Vivado native get_ports with DIRECTION/NAME filtering. R1 failure and
source remain; exact cgroup release precedes this report-only continuation.
