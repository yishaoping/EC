Measure the complete production AddressStats generated host after the existing
production-host-r1 validator passes all 6144 target cycles / 5684 observations
and both actual complete-module hosts pass 3003 tokens, including negative
controls. The reference is Plain and the candidate is Threaded, using identical
production source and harness. Their exact target public ABI has 52 outputs.
All proof-only bucket state ports must be absent from the measured hosts.

This is a separate continuation. It never edits or restarts production-host-r1,
complete-source-r1, r4, histogram, packed, DSP, DCache, or whole CAD. It waits for
the validator's exact service cgroup to empty, then reuses its synthesis RTL and
XDC without Scala compilation, elaboration, GoldenGate, or token-test repeats.
CPUs 212/213 and a 64 GiB cap are inherited only for its own service; ordinary
module resource guards precede each serial map. Completed byte-compatible exact
checkpoints with accepted stage receipts and identical CAD directives are reused.

r4 proof-heavy screen gains are not an admission prerequisite. This module pair
does not launch whole synthesis or access an FPGA. Whole synthesis still requires
material measured same-scope gains plus complete cycle/host/ABI validation.
