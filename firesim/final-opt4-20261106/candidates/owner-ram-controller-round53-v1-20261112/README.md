Actual emitted 35R1W81 owner RAM controller proof.

The verification copy has reversible observation ports and a single explicit
symbolic memory-read cut. Universal reset/step/output obligations cover all
35 read transactions, arbitrary response stalls, exact read address selection,
write enable/mask/reset and cycle advance. Seven actual RTL mutations must fail.

This does not prove RAM contents/collision semantics, inactive payload values,
FAME/target-cycle composition, full DCache/Opt4 equivalence, area, or FPGA data.
No target, active job input, annotation, clock, or deployment service changes.
