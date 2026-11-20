Exact 512x81 host RAM storage selected-word induction.

Nine disjoint 9-bit projections cover every payload bit at an arbitrary fixed
9-bit address across one host edge. The original emitted memory and writer are
unchanged, with reversible observer ports only. Initial memory is arbitrary.
Actual write-data and write-address mutations must yield counterexamples.

This proves storage preservation/update against the actual writer signals,
not the RAM request snapshot/collision contract or its target-cycle composition.
The controller/payload proof is separate. No reset/initialized-memory base,
DCache/full-system equivalence, area, FIT or FPGA result is claimed.
