Round 26 prepares verification and module mapping for existing area-only commit
`d9d732622601ed792a2647546006b5aae986ab8e`, source ID
`1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e`.
No hardware source, frozen source, active CAD input, runtime software, or FPGA was changed.

Actual GoldenGate completed and authenticated independent 512-entry memories of
81, 32, 32, and 1 bits. All seven generated ABI files matched the baseline.
This establishes generated topology and ABI equality; it does not certify a driver,
bitstream, timing, capacity, full DCache cycle equivalence, or experiment result.

The new extractor authenticates each physical memory's single write, all raw
asynchronous read expressions, all 512 generation taps, and the emitted reset-mask
transition for every word. Its SAT cut compares actual emitted field writers with
the existing frozen-equivalent e0 register transitions. Arbitrary word payload and
mask induction uses the existing source-bound Arbiter2 exclusion proof. The proof
checks all 512 words in eight-word partitions, splits solver timeouts, and finally
requires rejection of a real write-data bit corruption in each of the four fields.
Only completed positive partitions are proven until the final receipt exists.

Failures remain immutable: initial broker requests used receipt input paths outside
W; r2 reused the wrapper's lock name in the extractor; r3 expected inline memory
read assignments. The independent r4 controller uses W snapshots, separate locks,
and the actual generated continuous-assignment definitions. None of those harness
failures is an RTL counterexample.

The independent full-map-r3 controller waits for the complete r4 proof. It keeps all
original DCache ports and named dontTouch observations, and exposes all 512x32
generation observations in the isolated map copy. It must reproduce the existing
r2 reference map input byte for byte, then reuse that reference only after its
successful receipt and report hashes exist. It synthesizes only the new full
DCache candidate and cannot launch whole CAD or runtime. Complete frozen DCache
cycle comparison and composed verification remain admission gates.

Preserve both existing live whole builds. Do not launch another whole here.
Inspect the durable proof/map receipts at normal polling intervals; on actual
certified FIT, prioritize the existing implementation and runtime path.
