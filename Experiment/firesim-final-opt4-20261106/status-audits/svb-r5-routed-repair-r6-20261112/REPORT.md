# r5 routed checkpoint repair and complete MCRams resource evidence

Observation: 2026-11-12 16:54 CST. Functional baseline remains `8491167d84b6d9521b151a743673c1516926a1f8`. No target RTL or timing constraint was changed in this repair.

The F failure was caused by globally unrouting E and then using the post-route-only `phys_opt_design -routing_opt` option in post-placement mode. Versioned r6 instead opens an SHA-bound copy of E's fully routed checkpoint and runs routing optimization directly. Vivado 2021.1 explicitly accepted the operation in post-route mode, with 100% of nets fully routed. r5 inputs, failed receipts and checkpoints remain unchanged.

G physical optimization completed successfully with no warnings or errors. It optimized six nets without adding or removing cells. The saved `physical-timing.rpt` reports WNS **−0.023 ns**, TNS **−0.495 ns**, **39 failing Setup endpoints**, WHS **+0.001 ns**, THS **0**, and **zero failing Hold endpoints**. E originally had WNS −0.029 ns, TNS −0.864 ns and 51 Setup failures. G is now running `route_design -directive Explore -tns_cleanup` from the routed state. These are intermediate results, not final certification.

The r6 physical controller and separate certificate/deployment/application followers are active system services. The physical worker reuses CPUs 224–225, 64 GiB and the existing third-component lock. resume-r3, r51, complete MCRams and independent CPU PARSEC tasks were preserved. The bounded recovery sequence is routed critical-net optimization, placement/critical-cell optimization, clock-skew optimization, and bounded shell data-net delay rerouting. Completed Hold-clean routed checkpoints are ranked for reuse. There is no global unroute or new synthesis in this sequence.

All 49 saved E DRC warnings were parsed and reviewed in [drc-review.json](drc-review.json). There are zero Errors and zero Critical Warnings. The 16 NTCN-8 and 22 REQP-1858 warning details exactly match r4. The 10 PDCN-1569 warnings concern the same logical input set as r4; their printed equations do not use the warned physical inputs. The upstream GT segment clock-delay-group assignments are present in the sealed scoped input XDC alongside the CORECLK/USERCLK assignments. All constraints and warning severities are retained. The PCIe BRAM collision advisory is not a proof of collision freedom, and RTSTAT lists are truncated; the receipt preserves these evidence limits. Final r6 reports and all certification gates remain required.

Complete generated MCRams FPGATop OOC synthesis has now emitted matching utilization, hierarchy and primitive reports, with zero blackboxes:

| Resource | Used | U280 capacity |
| --- | ---: | ---: |
| CLB LUTs | 2,421,933 | 1,303,680 |
| CARRY8 | 80,994 | 162,960 |
| DSP | 192 | 9,024 |
| Registers | 1,696,044 | 2,607,360 |
| BRAM tile | 898.5 | 2,016 |

This is **185.78% LUT utilization**, a **1,118,253 LUT excess at synthesis**. It excludes the U280 shell and is not a physical FIT result. Post-opt continues in the existing producer. The largest measured relevant hierarchy entries are complete DCache at 1,502,470 LUT and its PackageAddressStats at 881,587 LUT. Parent/child entries overlap and must not be summed. The already-running complete address-memory prototype continues; no duplicate whole synthesis was launched. Full counts, original report hashes and inclusive rankings are in [mcrams-synth-resource-audit.json](mcrams-synth-resource-audit.json).

No certified SVB bitstream or new SVB FPGA sample exists at this observation. Once final Setup/Hold, route, clock coverage, DRC, pulse-width and bus-skew gates pass, the controller generates the bitstream. An independent audit then controls deployment under both shared 21 locks, restricted to BDF `0000:21:00.0`, serial `21770433G02LA`, followed by the directed component trace and same-bitstream application replay. SVB results remain component results, never full EC or paired PARSEC performance.

Live recovery: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/state.json`.

Live MCRams producer: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-full-host-capacity-r1-state.json`.

Follow-up observation at 16:58 CST: resume-r3's saved log confirms it naturally exited at 16:47 with final WNS −1.117 ns / WHS +0.001 ns and preserved `final.dcp`; it was not killed or restarted. r51 and r6 remain active. The G router's intermediate timing currently differs from the saved physical STA (including a transient −0.002 ns Hold slack); no intermediate value is accepted as final certification. The original complete-MCRams consumer has independently captured `early-synth-capacity.json` and agrees with the counts above. MCRams is saving its synthesis checkpoint before post-opt.

At 17:01 CST, G completed routing successfully. Its actual **Post Routing Timing Summary is WNS −0.023 ns, TNS −0.495 ns, WHS +0.001 ns, THS 0**. The transient Hold violation cleared after the router reverted its degraded cleanup result. Setup still fails, so this is not bitstream certification. The controller is saving routed/final checkpoints and reports before automatically continuing to H (`phys_opt_design -placement_opt -critical_cell_opt`) from the best completed Hold-clean routed result.
