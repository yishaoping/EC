# Round116: saved host40 paths and active continuation

At 2026-11-12T02:43:50.905713+00:00, 3 component Vivado workers remain within the max3 limit.
Existing P0/P1 CAD, CPU models and root followers were adopted by PID/start_ticks/boot_id;
their exact cgroups are in snapshot.json. No persistent job or FPGA experiment was launched.

Completed A physical-stage STA is WNS -0.417ns / WHS +0.001ns, compared with
the sealed probe -0.424ns / +0.001ns. TNS changes from -941.211 to -746.069ns;
setup failing endpoints change from 5840 to 4955. This is not final routed timing.
The target host clock has WNS +2.987ns; all 66 clock periods agree exactly between reports.
Five negative clock groups involve the XDMA/PCIe and DDR shell. The DDR representative
path has a 688-load net with 3.343ns route delay; the worst XDMA path has a 118-load
net with 3.566ns route delay after a logic stage. A PCIe hard-macro CORECLK startpoint
is outside the existing safe FD-Q replication selector. The live B query will be
recomputed on its sealed input; matching the pre-A query is not an eligibility proof.

The independent analyzer parsed 95 table rows and 267 representative paths. All 267
data-net delay sums reconcile to their reported route delays within 0.005ns; all
saved output hashes match. clock-groups.csv and negative-setup-paths.csv are under
/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-svb-host40-path-diagnosis-round116-r3-20261112. Endpoint counts/TNS from separate clock groups are not added together.
Parser failures r1/r2 were preserved; only independent r3 produced the completed result.

Resource snapshot: MemAvailable 195.44GiB, disk 299.14GiB, load1 77.08.
Admission for a new small component attempt: False.
Existing jobs are preserved regardless of current admission margin. The exact capacity
producer PID2379656 is adopted, with no Tcl injection, interruption or restart.
Actual MCRams report paths (empty means pending): {"build-logs/Opt4-mcrams-full-host-capacity-r1-20261112": [], "build-logs/Opt4-mcrams-address-bucket-area-r2-20261112": ["build-logs/Opt4-mcrams-address-bucket-area-r2-20261112/MemMC/utilization.rpt"]}.

No timing certificate, bitstream or FPGA sample is inferred from this analysis.
Native FPGA remains paused; matched Native CPU and owner MC retry remain separate
ongoing executions. Existing 21-only followers still require actual timing/hold/
route/DRC/pulse/skew certification. Strict checker latency still requires matching
BOOM executionDone and validated checker completion in the same timebase.

Next: allow live A/B and conditional C/D to complete under unchanged guards. On real
failure, use the exact path CSV and a versioned sealed checkpoint recovery. Consume
the existing MCRams whole-host utilization/parity receipts as soon as they complete;
never substitute local area gains for full shell capacity or physical FIT.
