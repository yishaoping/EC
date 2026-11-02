# Offline Rocket Chip resource restoration

These files are unmodified upstream inputs, not generated RTL. No downloaded
script is executed. Their upstream Git blob identities and SHA256 are recorded
in `../../manifests/resource_closure_20261023_QFzhRhSA/restoration_provenance.json`.

Upstream revision: `25e2c63567689ebe1fc5e60fdfe3375a8dba071c`, the Rocket Chip
submodule pointer published by Chipyard 1.9.1. Of 358 overlapping Scala/C++
source files, 341 match that revision exactly. PlusArg, ClockGate and ClockDivider
Scala files match exactly; both simulation debug BlackBox classes match exactly.
This supports compatible input restoration. It does not recover the original
EC upstream gitlink or close historical run provenance.

Only the five files explicitly listed in `../../resource_restoration.json` are
copied into new execution/metadata trees. The canonical `../../source/` is never
modified. Active files are `plusarg_reader.v`, `SimJTAG.v`, `ClockDivider2.v`,
`ClockDivider3.v`, and `EICG_wrapper.v`.

Four other downloaded upstream files remain reference evidence only. In
particular, `SimDTM.v` would collide with a different classpath resource supplied
by Sodor, and v1Config selects JTAG. `RoccBlackBox.v` differs from Current and
is not selected by v1Config. Neither is silently injected. TestDriver is VCS
collateral, and b3 implements AsyncResetReg in Chisel.

Runtime launchers use the local verified payloads only and never download them.
