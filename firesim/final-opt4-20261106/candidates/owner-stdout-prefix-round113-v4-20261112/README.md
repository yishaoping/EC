Offline comparison of the two immutable original owner-memory metasim stdout
logs. This controller cannot launch a simulator, Vivado, or any FPGA operation.

Both original logs have exactly the same six startup UART rows: INIT twice,
RUN, CONFIG, locs-created and locs-assigned. Their format strings must exist in
the exact bound Canneal ELF. Each UART byte and row is retained and compared in
program order; every remaining complete line is compared exactly in order. All
raw bytes, including any incomplete tail, are hashed and counted. Ten deliberate
UART/target data/cycle/order/missing/duplicate mutations must be rejected.

The previous round113-v1 and v2 failed comparisons remain immutable. Round113-v3
was never submitted: its preparation stopped on the newly observed existing
owner-MC runtime r2 CPU affinity. That runtime wins; it is not restarted or
modified. This audit uses CPU248 after checking the periodic snapshot and live
broker/checkpoint records. It is streamed under a 2GiB process limit, retaining
the 256GiB available-memory / load<96 guards for a light auxiliary.

Passing establishes only equality of this incomplete stdout prefix within its
two source transports. It does not establish completed ROI, all-state/cycle
equivalence, whole-system FIT, FPGA data, or a formal PARSEC result.
