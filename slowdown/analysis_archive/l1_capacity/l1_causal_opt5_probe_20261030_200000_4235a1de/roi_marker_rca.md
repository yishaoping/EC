# ROI marker measurement defect, r1 → r2

Direct observation: r1 A completed exit0, verified1/checksum43439728, exact software ROI1707863 [712114,2419977). Functional/integrity/protocol/STOP40–45 and corrected L2 snapshot checks PASS. Native causal status FAIL: errors2, zero accepted start/stop snapshots. Its all-zero output counts are deliberately invalidated measurements, not observations of zero stalls.

Immediate blocking condition: two failed bounded64-cycle marker lookups are strongly supported by errors2 plus zero accepted start/stop snapshots, but r1 did not log error subtypes, so each individual increment is not retrospectively classified. The upstream marker source defect is proven in `core.scala`: integer RF and ROB debug writeback use the CSR-result mux `Mux(csr_cmd != CSR.N, csr.io.rw.rdata, data)`, while `rob.io.wb_resps.bits.data` carries pre-mux execution data. The ROI observer incorrectly read that pre-mux field. No captured raw requested timestamps existed in r1, so their exact wrong values are not reconstructed or guessed. Dynamic closure requires r2 marker records and exact software ROI agreement.

Fix principle: retain the existing marker PC/valid matching and 64-cycle ring, but take the same CSR-muxed `rob.io.debug_wb_wdata` value used by architectural writeback. No functional datapath, MSHR, scheduler, replay or cache policy changes.

Bounded verification improvement: preserve two marker records (observer cycle, requested cycle, lookup found), plus separate snapshot-lookup error count in final JSON. Print at most4 marker lines per measurement epoch; capture them as essential and flush those lines, allowing immediate live validation at ROI start. New diagnostics have no hardware outputs or functional feedback.

R1 B shares the same proven measurement defect. It was deliberately interrupted before ROI; r1 artifacts, immutable seal, binaries, raw logs and execution provenance remain under `revisions/r1/`. R1 is not a valid paired causal comparison. R2 must rebuild/run BOTH configurations with one new immutable seal and identical corrected instrumentation. No r1 performance delta is interpreted, and no old baseline substitutes for r2 A.
