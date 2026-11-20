EC Performance-Only: data preservation + cache isolation — round 193

Hardware remains 6fada307bb77be90b39720d3f95404fece0e431b. Existing R6
cef2d0b controller PID 355419 / start 35248517 / boot
d6c6e410-10ad-4326-86ba-79b657eabd96 remained the sole complete-shell owner through a
715-second observation. Current stage: dut_synth. No completed
prototype shell post-opt LUT, FIT verdict, bitstream or runtime certificate exists.
No hardware cut, target/host regeneration, driver rebuild, CAD restart, new service,
FPGA operation, CPU-session control or SVB-session control occurred.

Runtime-only support commit 6115b44948c922c33a465090fbeb973843602e21 on the separate
runtime-bind branch stages runtime/Opt4-performance-only-6fada307-bound-r1.
It binds R6 source ID 461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369, actual host RTL d2cfb704..., the seven
actual generated ABI/constraint files, the already completed freshly compiled
prototype driver, and all thirteen software entries with actual payload/rootfs/
application file hashes. The eight requested programs retain first-round priority.
Hardware source differences against 6fada307 are empty.

Offline checks authenticated the bundle and all software rows; rejected old
hardware/host/RTL, the wrong board/serial/profile and full-PALIMPSEST identity;
and verified that missing physical evidence cannot certify. Synthetic parser
fixtures confirmed that missing checker RESULT, missing full comparison and
unowned results fail even with zero diagnostic pending. Those fixtures provide
no hardware runtime evidence. Omitted diagnostic/traffic metrics are unsupported,
with null output values; genuine positive checker accounting, context, per-package
BEGIN/RESULT, storage/drain and the existing card21 locks remain mandatory.

The staged bundle is not activated and no new runtime owner was installed.
The existing root runtime still holds the shared opt4-fit-runtime.lock. The
handoff explicitly requires the existing owner to adopt at a safe boundary,
without bypassing that lock. R6's inner certified_bitstream flag alone cannot
admit this bundle. Actual source-bound complete-shell all-STA (setup/hold/pulse/
skew/clock coverage/unconstrained endpoints), route and DRC checks and the exact
bitstream certificate remain pending. Integrated card21 checker, LSL/SVB data
preservation, cache isolation and safe-drain evidence must precede simmedium.

Existing foreground checker identity (100 generated modules), finite DCache
preservation and real LSL module tests are preserved and not repeated. They do
not establish integrated checker execution. All prototype evidence stays outside
the full EC / PALIMPSEST shell ledger. Preserve R6 to actual shell post-opt;
NOTFIT uses its actual new hierarchy for targeted cuts; FIT continues physical
and exact artifact/runtime gates before card21 and eight first PARSEC samples.
