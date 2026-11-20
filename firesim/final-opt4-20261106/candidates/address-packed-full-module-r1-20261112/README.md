Private successor to the actual packed histogram validation and paired single-bucket screen.

Only the final combinational four-granule group reduction changes. The complete source is
bound to derived parent 3656aec4 and unique functional baseline 8491167d. All original
registers, widths, priorities, reset, overflow, retirement and public outputs are retained.
No production source, active input, timing constraint, FPGA, CPU comparison or whole-host
synthesis is touched.

The private finite test compares all 52 public outputs and every 5,120 bucket payload word,
256 valid bits and 256 sequence words before and after every edge for 6,144 cycles. Equal
arbitrary invalid payload, values near overflow, normal reset and resetStats are included.
The same monitor must reject an actual invalid candidate-register bit flip. This is a finite
complete-module regression, not formal equivalence or a new architectural feature.

Only after parity passes, two sequential default-directive full-module maps measure area
with proof-only debug ports removed. Both use the same Vivado 2021.1 part and settings.
No multiplication of the earlier one-bucket saving or full-host FIT claim is permitted.
Composition, source-bound GoldenGate/ABI/target-cycle gates and fresh whole-host post-opt
capacity remain before any production physical implementation.

One persistent user service uses CPU 214–215 and a 64 GiB address-space limit. Existing
healthy tasks are adopted, never restarted. Failed partial stages retain evidence for a
versioned correction; the continuing hardware supervisor reads this service's state.
