EC Performance-Only: data preservation + cache isolation
======================================================

This profile is an independent performance prototype, NOT a complete PALIMPSEST
measurement. Its source parent is cda823f0d6edd106d3dbd8e47b0ebe84dae976ea,
derived from frozen EC 8491167d. Existing full-function optimization trees remain.

R1 removes only diagnostic hardware: PackageAddressStats (including all bucket
updates, address queue and bucketSequenceMemory); all three GHBarrierLatencyStats
instances; L1/L2 dirty-writeback diagnostic buckets, latency products/reductions;
LSU address-statistics event ports, production and read-only taps. Removed CSR
slots are zero with validity zero; zero pending is NOT a data-drain certificate.
Snapshot waits for actual LSU pending, but no longer waits for deleted monitors.
Runtime tools must explicitly accept this profile's unsupported metrics and
continue to require genuine checker completion, package drain and saved-data
checks. An old full-profile certificate cannot authorize this prototype.

R1 retains EC fault recovery logic as well as normal operation. This is a first
material cut, not a promise that every allowed recovery-only cut is implemented.
No checker simplification, cache geometry reduction or approximate/infinite
bucket has been introduced. Real LSL/SVB storage, cache versioning, actual
isolation barriers, safe-prefix verification bitmap, real package results,
normal MSHR replay, commit/release, full/capture backpressure and assertions
remain. Health counters (FAIL/CANCEL/dropped result) remain real.

The reversible pruning manifest reproduces every edit from the exact parent.
Compile and frozen parameter audit precede generated-RTL regression. The finite
DCache regression compares all surviving functional ports and read-only state
against frozen 8491167d, excluding only explicitly removed diagnostic CSR slots
and address-monitor taps. It is not a whole-system formal or a boot test.
The changed statistics snapshot latency is separately recorded as a measurement
interface change. A full post-opt SHELL report, not module subtraction, decides FIT.

Board access is not performed by the build controller. Exact new physical,
ABI/software, real checker/drain/storage checks and the existing 21-only locks
must pass before deployment on 0000:21:00.0 / serial 21770433G02LA. No e2, global
XDMA/PCIe, dual-card, CPU-session or SVB-artifact operations are authorized here.

After authentication and a functional smoke test, run blackscholes, fluidanimate,
bodytrack, freqmine, swaptions, ferret, dedup, streamcluster with simmedium, one
first sample each; preserve failures and skip ahead. Reuse Native FPGA data only
after geometry/clock/workload/measurement compatibility is checked. Label all
Slowdown samples with this prototype profile and explicit omitted mechanisms.
