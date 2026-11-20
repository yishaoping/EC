This is a versioned continuation of the unsubmitted round48-v2 four-memory
GoldenGate plan. It preserves all 7450 original annotations and adds the same
four owner memory annotations, retaining 35/518/4/4 asynchronous reads, all
observations and reset/written-mask behavior. No target RTL changes.

The predecessor expected a stale owner-runtime result status, omitting TARGET.
This controller checks the actual documented status and binds both completed
prerequisite receipts by SHA256. The original prepared candidate is preserved.

Run `python3 submit.py --check` to inspect the gate without writing anything.
Run `python3 submit.py --submit` to publish one broker kind=rtl job only after
the existing full force-all GG SVB replay, its payload negative, and exact owner
Plain/MCRams Canneal finite parity have passed and their producers have exited.
It adopts any existing four-memory request and never duplicates a partial stage.
There is no new timer or waiting CPU service. CPU selection consults existing
bound process identities and reserves 254/255 for SVB physical recovery.

Normal broker guards remain mandatory; the controller also retains its existing
128GiB available memory/100GiB disk/load<96 thresholds and 2CPU/64GiB limit.
The entire post-bridge target FIR must remain byte-identical. Raw generated SV
and blackbox-appended SV are separate immutable artifacts. Subsequent full host
parity and actual complete resource evidence remain necessary. This is neither
full Opt4 equivalence/FIT nor a workload, deployment, or FPGA sample.
