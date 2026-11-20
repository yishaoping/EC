# Audited EC experiment exports

Native FPGA: 45 valid formal samples, 15/16 programs with three rounds. The ordinary 13-program set contributes 39 samples; Netdedup/Netstreamcluster contribute six appendix samples. Netferret is missing. Historical e2 BDFs remain historical evidence; this export touches no board. Native hardware commit was not recorded; source ID and bitstream hash are retained rather than inventing a commit.

EC full-system CPU GoldenGate metasim: Canneal project400 and Blackscholes project64, frozen 8491167d. The original audit mislabeled Canneal project64 in prose; the corrected label here preserves the exact ELF, input, cycles and evidence. Both programs passed output checks, strict allocation/begin/full-compare/result/BOOM-accept joins, and drained pending packages to zero. These are CPU metasim data, not full Opt4 FPGA data.

SVB: 659 complete finite-trace lifetimes from Canneal. ACK denotes ownership/writeback completion, not checker completion. CDFs use original one-cycle samples, nearest-rank percentiles. Observed rates include offered-workload idle/backpressure and are not saturated capacity. CPU replay wall time is a host execution rate.

Checker local package intervals are BEGIN to validated full PASS local RESULT enqueue at 100 MHz. They include waiting within that interval; they are not the requested BOOM-execution-complete to checker-complete latency. No strict cross-domain latency is invented.

Native Linux simmedium and EC baremetal project400/project64 are deliberately not paired. There is no full Opt4 FPGA slowdown in this package. The separate matching clean-Native CPU experiment preserves algorithm/input sources and ROI scope but uses a different startup ELF/link layout; its consumer must validate complete/hash/FASED/BOOM/cache/software and instruction counts before producing a source-matched CPU ratio.

Figures: PDF/SVG from matplotlib. Native error bars are sample standard deviation over n=3. Host wall time includes guest boot and is not architectural slowdown. Raw large host-log hashes are inherited from the completed independent audit; small result/complete/identity, UART and raw ROI hashes were independently rechecked here. Original failures remain linked in preserved-failures.json.
