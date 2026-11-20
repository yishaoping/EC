Independent banked complete bucket-state screen, round 153

The new full-size geometry is 16 identical BucketBank instances, each with
16 parallel lanes, retaining all 256 target slots. Only BucketBank receives
EnableModelMultiThreadingAnnotation. The same target harness is generated with
plain and threaded configurations. No installed compiler source is changed.
The existing r6 256-thread histogram prototype and all its pins remain intact.

Each bank contains the five existing four-granule 64-bit bucket state vectors,
valid bits and 32-bit sequences; complete read, histogram, exact 65-bit addition,
allocation, write, retirement and stats reset are inside the selected model.
There are no additional target registers or target pipeline stages. Retirement
uses old validity, and assignment priority remains process, retirement, stats
reset. Global target reset invalidates RegInit valid bits while retaining the
original unreset sequence/payload registers. Counts remain the actual touched
mask bounds [8,3,2,1]. Package histograms have eight sources each; the strict
histogram has 16 primary plus64 overflow sources. The original grouped helper
reverses byte-for-byte after removal of the added single-key lookup and package
rename. Bank projection is manually source-bound, not whole formal equivalence.

This is the bucket-state subsystem, NOT complete PackageAddressStats: upstream
queues, source qualification, errors, online/global counters and membership
checks remain outside. Inputs processCommit and safeError are prequalified as
in the original. Source composition and complete-module equivalence remain
mandatory before integration. This candidate neither changes nor disables
architectural functions, and is not admitted to production.

First generate actual 2/4-bank threaded hosts and check every state bit after
48 target tokens against an independent integer transition oracle, including
reset, invalid payload, allocation, bank boundaries, retirement, blocked
retirement and simultaneous control priority. A deliberately wrong oracle must
fail at token7/slot0. These bounded traces cannot reach64-bit overflow; carry
outputs are checked but overflow reachability remains unproved. Next generate
full16-bank plain and threaded hosts, check all256slots, compare token digests,
and only then serialize identical-directive Vivado OOC maps. Both map sides
include the same exact observation bridge. This is actual full-size screening
area, not complete-module/EC area. No multiplication of a single-bank result.

Host cycles include bridge I/O. Sixteen selected instances is not a measured
FMR, MHz, EC cycle count, slowdown or completion prediction. This choice follows
the deadline throughput constraint; it makes no performance claim. No validated
FIT route currently establishes completion of all eight fullEC FPGA workloads
by November18. No board I/O, whole-host synthesis or physical work is submitted.

Reuse released CPUs218/219 only after exact barrier r2 completion, old PID
absence and systemd cgroup release. Preserve all negative barrier evidence.
Use the existing admission guard:256GiB available, load<64, free disk>=60GiB,
project Vivado count<8, no pinned CPU overlap. Hard memory64GiB, two cores,
serial stages, no restart, no signals to any existing process. The r6 immutable
Python stage/resource/map helpers are imported under private module state; no
r6 files or running Python objects are changed. Packed and DSP remain their
existing independent owners. No CPU PARSEC or SVB work is performed.
