# EC data production: evidence boundary

Frozen functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`. Native remains paused; FPGA allowlist is `0000:21:00.0`.

Canneal project400 target RTL completed: ROI **485,329 cycles**, **392,248 instructions**, 136 generated/accepted/PASS, zero FAIL/CANCELLED; observed ROI work drain tail **262 cycles**.

Original full Golden Gate CPU metasim completed: ROI **536,456 cycles**, **392,248 instructions**, correct checksum/routing cost, 131 local checker begins and full comparisons, zero local failures/cancellations; BOOM acceptance/full drain is not observable in this run. Host wall **3,136.113 seconds**; model throughput **563.476 fastest-target cycles/second**.

The two environments differ in memory model and integration; cycles differ by **51,127 (10.5345%)**, and package counts differ by 5. This is a comparison result, **not cycle equivalence**. Same-target Plain/MCRams full-system finite parity is already running in the persistent broker service; it must finish before an equality result can be claimed.

SVB original component CAD is routing with congestion warnings; no certified bitstream or FPGA measurement exists yet. The persistent on-board service waits for route, correct physical target clock, timing and DRC authentication, then uses only21.

DCache real-memory r5 **PASS** in both PlainConfig and MCConfig on the same direct target RTL pre-edge trace:2,569 cycles,178,857 defined checks,973 explicitly undefined values,12 reset cycles,512 paired write-then-withdraw-write/read cases and512-address no-write sweep. Both deterministic event digests are `e3c422883c079803`; each deliberately corrupted defined value is rejected at cycle10. This is finite isolated memory-interface coverage, not complete DCache/EC equivalence or production admission. The35-read interface and existing written-mask/reset behavior are preserved; generation-memory518 debug reads are inventory only and are not included in this proof.

PeekPoke operation throughput is336.760(Plain)/260.328(MCRams) targetcycles/s, with FMR172.016 including MMIO and driver overhead. These are CPU metasim run-efficiency figures, not FPGA throughput or target architecture slowdown. Actual area comparison is still required.

The already measured isolated Golden Gate library35R1W81 RAM boundary maps388,931 to3,289 LUT; that is not complete EC/DCache/whole-system area. No FPGA results are included in this comparison.

Actual r5 Plain/MC host-entry area is submitted under the existing broker as `mcrams-dcache-entry-area-r2-8491167d`, pinned CPU250,251 with64GiB/2threads. This is queued pending safe slot; no actual area result is asserted. v1 was deferred and withdrawn before start to avoid P0 SVBspreadCPU254,255. Evidence and exact successor paths are in `mcrams-area-continuation.json`.


## Corrected actual entry area

The single area-r2 system service is running with CPU250–251; MC completed and Plain continues. MC actual **24,192 LUT,250 CARRY8,32,721 FF,1.5 BRAM,0 DSP/URAM**. The original controller LUT0 is a parser error: its regex missed `CLB LUTs*` in the total table and read a zero SLR row. Raw state/reports are retained. Independent corrected analysis validates device capacities, hierarchy totals and primitive counts; retained RamModel itself uses6,122 LUT and1RAMB36+1RAMB18. Current correction evidence: `../build-logs/Opt4-mcrams-dcache-entry-area-analysis-r1-20261111/partial-result.json`. Both-config savings remain pending Plain receipt. No full-DCache or whole-system FIT claim.


## Completed paired real-memory entry area

Both configurations completed in the original single system service; no re-synthesis was performed. Corrected paired totals: Plain **405,706 LUT,65,886 FF,250 CARRY8,0 BRAM/DSP/URAM**; MC **24,192 LUT,32,721 FF,250 CARRY8,1.5 BRAM,0 DSP/URAM**. Measured LUT saving **381,514 (94.0370613%)**. Both have zero blackboxes; MC RamModel remains connected. Authoritative result: `../build-logs/Opt4-mcrams-dcache-entry-area-analysis-r1-20261111/result.json`, SHA256 `f631797f8ea2445ca87340267fed159d07cce630c1a6f0e46bb9f718d24b8a3d`. Earlier queued/running and LUT0 descriptions above are historical and superseded by this completed, crosschecked pair. This is an isolated real ownerImageMemory35R1W81 host-entry, not whole DCache or a whole-system FIT result.


## Immutable area evidence and actual full-target host submission

The timer-safe authoritative paired result is now immutable analysis r2: `../build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/result.json`, SHA256 `34fc766d60d2aa577050e88f9fa125ab04096ac3df91494ad8e308f047598e4c`. Repeated analysis verifies original evidence hashes and preserves completed result bytes. Mutable r1 snapshots are historical only. The exact ownerImageMemory-only full-emitted3656aec4 host transform passed preflight and was actually submitted as `mcrams-owner-system-r1-3656aec4`;7450 original annotations are preserved and one annotation appended. Original target FIR,35 image reads,518generation/debug reads and reset-gated write semantics are unchanged. This is a CPU GoldenGate transform only; full parity and full-DCache area remain gates and no third whole-system CAD or FPGA job was started.
