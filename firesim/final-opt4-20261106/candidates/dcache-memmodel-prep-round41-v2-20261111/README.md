# Exact target memory annotation preparation

This version stages four `FirrtlMemModelAnnotation` entries for the actual
`3656aec4` DCache memories. It retains the emitted target FIRRTL byte for byte
and preserves every existing annotation, including ten core RF memory
annotations and all observation/bridge/MT metadata. It parses that target with
the installed FIRRTL compiler and resolves all fourteen memory targets. Four
malformed metadata cases must be rejected.

The input candidate is derived from frozen functional baseline `8491167d`.
Its existing restricted generated-DCache identity receipt is required and
retained as a separate dependency, not promoted to complete-system proof.

The generation memory has **518 read ports**, including its full 512-word
generation observation. Nothing removes, samples or compresses those reads.
The address module has 24 existing synchronous memory declarations and 37
register declarations. Its dominant RegVec state is not made into a memory by
adding annotations; this version does not annotate or modify that state.

This is preparation only. No GoldenGate transformation, synthesis, runtime,
or FPGA operation is launched. It neither proves complete DCache MCRams
equivalence nor measures any area saving. After corrected complete real-entry
area evidence, a separate full-module host transformation and cycle comparison
must retain the reset/written mask, collision rules, every original observation,
and all target clocks before area or whole-system admission.
