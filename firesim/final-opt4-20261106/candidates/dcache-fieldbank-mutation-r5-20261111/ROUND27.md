Round 27 continues only the function- and cycle-equivalent area campaign rooted
at frozen Opt4 commit 8491167d84b6d9521b151a743673c1516926a1f8, C4/v1Config/SVB32.
No hardware source, live CAD input, software, driver, scope policy, or FPGA was
modified. Both previously live whole syntheses, 9ae and e0, remain preserved.

The existing fieldbank generated-proof-r4 job completed all 64 eight-word positive
SAT partitions, covering 512 words and all 512 generation observations. Its final
mutation-builder regex failed on multiline emitted write expressions before it
created any negative mutation. The original failed state and all artifacts remain.
The original full-map-r3 controller then stopped at the dependency gate before
launching Vivado. Both controller exits were confirmed by their known identities.

The independent mutation-r5 continuation authenticates every reused partition's
RTL and log hashes, confirms its exact output-only partition against the original
source-bound miter, and runs only the four missing negative tests. It modifies the
actual selected write-data branch for image81/generation32/packet32/tracked1 by
XORing one data bit. All four negative tests returned a real SAT counterexample;
none timed out. The immutable result is:

    D/build-logs/Opt4-fit-dcache-fieldbank-mutation-r5-20261111/result.json

It reports covered_count=512, inherited_positive_partitions=64,
positive_sat_repeated=false and actual_field_write_mutations_rejected=4. This is
actual generated field storage-transition and observation evidence, not complete
DCache formal, a cycle-regression pass, area admission, whole FIT, or FPGA data.

Full-map-r4 is the independent continuation of the stopped map controller. It
uses mutation-r5 as its proof gate and preserves the identical full-DCache mapping
boundary: all original ports and named observations, plus all 512 generation
outputs. It retains the 48 GiB/40 GiB guards and reuses the original full-pair-r2
reference only after a successful source-bound receipt and exact RTL/report hashes
exist. It starts no whole synthesis and admits no hardware to runtime.

The new frozen-cycle harness compares authenticated original C4 GoldenGate RTL
directly with d9 generated RTL. The baseline build receipt pins frozen8491167d;
its DCache Scala bytes were independently checked against the frozen backup. Both
copies have the identical 362-port interface. The harness extracts the complete
child-module closure, namespaces module types only, retains assertions and print
logic, and adds read-only ports for all original named dontTouch observations and
512 generation taps. It compares all outputs even when their valid flag is low.

Preparation-r1 preserved a naming failure: three GoldenGate IO aliases use a
double underscore, and one CacheImageKey Bundle has named field suffixes.
Preparation-r2 preserved an overbroad name-match failure: it also selected 512 new
raw memory payload wires absent from the frozen observation boundary. The r3
preparation maps the exact original scalar/vector aliases and all four original
Bundle fields explicitly. It does not omit any frozen observation. The new raw
representation state is covered by the independent arbitrary-state proof above.

The separate module regression keeps the normal memory geometry and simulation
assertions enabled. Its TileLink memory model holds responses under backpressure;
the request driver exercises cache load/store/refill/retry and checker/drain
windows, two full reset intervals, and pre-edge/post-edge/clockless observations.
It requires actual nonzero activity thresholds and complete drain before issuing
a pass receipt. Both implementations use identical zero simulation initialization;
the separate arbitrary-payload proof is required for the changed storage. An
8192-cycle regression, even if it passes, is not an exhaustive protocol proof or
an FPGA experiment. Any tool, assertion, mismatch, or coverage failure remains
evidence and requires an independent reviewed continuation.

Next: adopt the latest mutation-r5/full-map-r4/cycle-regression receipts and live
identities. Never resurrect the superseded controllers or duplicate their maps.
Use actual complete-module reports for gain selection; continue independent area
work if they fail or have insufficient gain. No third whole while current builds
remain live. Only a certified FIT can advance through the existing 21-only runtime
services to a real formal Opt4 FPGA sample.
