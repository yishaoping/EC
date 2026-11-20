# Address probes4 measured decisions

No production hardware changes; active whole-DUT and FPGA inputs unchanged.

| 16 x 64-bit + 10-bit update and overflow | LUT | CARRY8 | DSP |
|---|---:|---:|---:|
| Original wide arithmetic | 160 | 144 | 0 |
| DSP attribute on wire | 160 | 144 | 0 |
| DSP attribute on module | 160 | 144 | 0 |

Reject both DSP-inference hints for production: no mapped improvement.
The 74-input-bit universal proofs cover RTL arithmetic, not the mapped netlist.
These are micro probes, not complete address-module or DUT reports.

Heap8 bounded universal equivalence: PASS (136 input bits).
Heap80: proof TIMEOUT after 240 seconds; not mapped, not admitted, not installed.
Original failure logs and previous state are preserved. The failed probe exited
before software repair; no live task was restarted.

Frozen complete address OOC baseline: 1,702,895 LUT, 58,190 CARRY8,
391,057 FF, 216 BRAM tile, 0 DSP. This is the frozen-source module baseline;
it does not establish current whole-DUT capacity.
