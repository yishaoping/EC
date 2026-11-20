Isolated candidate a5ca9940e35ba34b5ef65b62ce624bec31facd17 replaces only the
uninitialized installedImage register array with an asynchronous Mem. Its parent
is e0c3737f; no source from a revoked architectural extension enters this tree.

The exact CacheImageKey is 81 bits: valid 1, writer 16, generation 32 and
contentSeq 32. The 146-bit ownership-memory candidate is a different storage
boundary. Geometry remains 256 sets and 2 ways. The flat index is Cat(set, way).
There is one install-fire write and one combinational refill read. No register,
valid mask, initialization, reset operation or bypass is introduced.

The candidate is not selected for production. The controller requires exact
source reversal to e0 and an authenticated inherited scanner-only DCache delta
to frozen Opt4. It retains all assertions, print instrumentation and observations.

The brokered proof stage checks the arbitrary-state 512-word transition and
address bijection independently for every payload bit, rejects a write-data
mutation, inspects the actual emitted 512x81 asynchronous 1R1W memory topology,
and compares the actual CacheImageKey storage implementations for 8192 cycles.
The regression fills every word through the real write interface before complete
scanning; it checks pre/post edge reads, same-address activity, clockless changes,
all-one payloads, writes during reset and final scanning of all 512 words. The
proof makes no zero-initial-state assumption for this uninitialized payload.

The separate paired map uses identical complete storage ports. Its result is
local storage area evidence only. Complete frozen DCache cycle/observation
comparison, full DCache mapping and composed verification are required before
whole admission. No whole synthesis, driver, FPGA or software service is started
by this candidate. Existing whole builds and foreground jobs remain independent.
