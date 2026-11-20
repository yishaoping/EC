EC Performance-Only `6fada307`: original R6 implementation has exited with illegal routing and failed timing. Complete shell post-opt capacity FIT remains 1,023,687 / 1,303,680 LUT; this is not physical implementation FIT.

Original final routing: 741,299 / 1,790,138 nets fully routed; 1,048,839 resource conflicts, 2,702,263 overlapping nodes. WNS -19.489 ns, TNS -5,276,071.500 ns. No bitstream, certification or FPGA runtime. The original controller is inactive; do not wait on it.

Active independent recovery: `performance-only-routability-r1-20261114/state.json` (bounded equivalent netlist/MUXF physical screening), and `performance-only-memory-cdc-r2-20261114/complete-shell-r3/state.json` (four same-capacity memory-backed data queues, full-state module proof and generated-host token check admitted; full host generation in progress). New shell area and legal routing are still unmeasured.

Full EC `8491167d` and Performance-Only baseline are preserved. Model requests disabled. No FPGA access; all future board access must follow 21-only certification.
