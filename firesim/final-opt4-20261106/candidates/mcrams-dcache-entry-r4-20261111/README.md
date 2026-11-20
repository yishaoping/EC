# Actual DCache memory interface: target-boundary trace r4

Original functional baseline8491167d; isolated derived memory interface3656aec4. No FPGA access or production admission.

The exact emitted EntryDUT is compiled directly to RTL. An independent scoreboard checks its reset mask, synchronous reset/capture and one-writer memory updates. A pre-edge trace preserves all39 input and70 output ports. Both GoldenGate PlainConfig and MCConfig consume each row via poke-all, stable-peek-all, then step-one. Same-cycle read/write conflicts are marked undefined; their affected captured values are marked undefined on the next target boundary. Such skips are explicit coverage limitations, not proof of collision behavior equivalence.

Each of512 addresses is written and immediately read on a separate target cycle after withdrawing writeEnable, then a final512-address no-write sweep verifies committed state across all35 read ports. This demonstrates the boundary phase and real writes; no shadow array replaces the DUT. Multiple resets, reset-gated write and capture behavior are checked. A mutation of a defined expected value must be rejected in both host configs.

This is a finite memory-interface experiment; it does not represent complete DCache/EC cycle equivalence, all518 debug reads, a full-system area result, FIT or FPGA measurements. r1/r2 failures remain separate evidence.

The r3 reference generation failed because an abstract Reset was used at a stand-alone top. r4 preserves the original EntryDUT module and adds an explicit synchronous-reset test wrapper. All r3 evidence is retained.
