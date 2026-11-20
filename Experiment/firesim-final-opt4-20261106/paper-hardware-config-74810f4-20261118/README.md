# Hardware configuration of the latest certified EC FPGA bitstream

Revision: `74810f4c5d70d80e471fb9f91f73131b90742004`. Bitstream SHA256: `bb6b229898c422fc43ce9d52cb3449c20523fc371a5628cc6af870e10f986850`.

| Section | Parameter | Configuration | Evidence |
|---|---|---|---|
| Big Core | Core | 1 x 3-wide OoO SonicBOOM (RV64GC) | parameters.json:2; parameters.json:5 |
| Big Core | Pipeline | 42-entry ROB; 72-entry IQ (32 INT + 16 MEM + 24 FP); 16-entry LDQ and 16-entry STQ | parameters.json:7 |
| Big Core | Registers / execution | 128 INT / 128 FP physical registers; 3 INT execution lanes, 1 MEM lane, 1 FP lane | parameters.json:26; /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/roi-retirement-checker-repair-20261117/generation/elaborate/firesim.firesim.FireSim.fir:445034; /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/roi-retirement-checker-repair-20261117/generation/elaborate/firesim.firesim.FireSim.fir:336209 |
| Big Core | Branch prediction | TAGE-L + loop/BIM/BTB/micro-BTB; 6 TAGE tables per bank, 2-64-bit histories; 16-entry RAS; BTB: 128 sets x 2 ways per bank | config-mixins.scala:491; tage.scala:186; btb.scala:15; parameters.json:56 |
| Big Core | Target frequency | 200 MHz (model assignment; not a measured FPGA core frequency) | target-clocks.txt:2; runtime-manifest.json:68 |
| Memory Hierarchy | L1 I-Cache | 32 KiB, 8-way, 2-cycle pipeline; one outstanding refill transaction | parameters.json:104; /data1/gzh/EC/firesim/final-opt4-20261106/Opt4-roi-retirement-repair-20261117/chipyard/generators/boom/src/main/scala/ifu/icache.scala:139 |
| Memory Hierarchy | L1 D-Cache | 32 KiB, 2-way, 6 MSHRs; fixed end-to-end hit latency not independently established | parameters.json:121 |
| Memory Hierarchy | Shared L2 Cache | 1 MiB, 16-way; 4 MSHRs (2 general + 2 B/C-reserved); memCycles=12 is not hit latency | parameters.json:653; L2Parameters.scala:311; /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/roi-retirement-checker-repair-20261117/generation/elaborate/firesim.firesim.FireSim.fir:56523 |
| Memory Hierarchy | Cache line | 64 B | parameters.json:117; parameters.json:138 |
| Memory Hierarchy | Target memory | 16 GiB address space; FASED Latency-Bandwidth Pipe (not DDR3-1066 timing) | parameters.json:770; runtime-manifest.json:52 |
| Memory Hierarchy | Runtime memory settings | readLatency=30, writeLatency=30 target-model cycles; 4 outstanding reads + 4 writes (hardware ceilings: 16 each) | runtime-manifest.json:15; parameters.json:784 |
| Little Cores | Cores | 4 x in-order Rocket, 5-stage pipeline; 100 MHz target model assignment | parameters.json:154; runtime-manifest.json:69 |
| Little Cores | Arithmetic | mulUnroll=8, divUnroll=8; SP/DP FMA latency: 3/4 cycles | parameters.json:200; parameters.json:207 |
| Little Cores | L1 Cache | 4 KiB, 2-way each for I/D; I-cache pipeline: 2 cycles; blocking D-cache (nMSHRs=0) | parameters.json:215; parameters.json:232 |
| Little Cores | LSL / checker | 2 x 255 x 130-bit arrays; 3.98 KiB data payload, 8.09 KiB including address/type (excluding control and CSR/RoCC queues) | RocketCore.scala:838; R_LSL.scala:70; /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/roi-retirement-checker-repair-20261117/generation/elaborate/firesim.firesim.FireSim.fir:615910; /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/roi-retirement-checker-repair-20261117/generation/elaborate/firesim.firesim.FireSim.fir:616035 |
| Little Cores | Package instruction limit | 5,000 configured instructions; early seal trigger at 4,955 plus ROB drain (not a cycle timeout) | GH_GlobalParams.scala:15; /data1/gzh/EC/firesim/final-opt4-20261106/Opt4-roi-retirement-repair-20261117/chipyard/generators/boom/src/main/scala/exu/core.scala:2294 |
| FPGA Implementation | Platform / profile | Alveo U280; EC Performance-Only, revision 74810f4 | certified-build.json:4 |
| FPGA Implementation | Physical host clock | 10.004 MHz (99.960 ns); target 2:1 clock relationship represented by FireSim scheduling and multicycle constraints | clock-contract.txt:1; target-clocks.txt:2 |

- This table describes the latest certified bitstream, not the previously failed 6fada307 build and not full PALIMPSEST.
- 200/100 MHz are target-model frequency assignments. The routed physical host clock is 10.004 MHz; generated target clocks have the same physical period and the checker domain has a multicycle contract. Do not label the model assignments as measured FPGA frequencies or replace them by 3.2/2 GHz.
- L2 memCycles=12 sizes concurrency for an assumed outer round trip. It does not enforce a 12-cycle L2 hit latency. L1D end-to-end response latency also includes EC control and backpressure; no fixed measured value is asserted here.
- LSL array capacity is 2*255*130=66,300 bits (8.093 KiB) per checker; data-only payload is 2*255*64/8=4,080 bytes (3.984 KiB). Additional queue/control storage is excluded from these two capacities.
- 16 GiB is the configured target address space. The current diagnostic Linux launch separately restricts usable memory to 2 GiB (mem=2G). Runtime latency/concurrency settings are not baked into the bitstream. No DDR3 timing model is instantiated.

Reproduction: `python3 generate_table.py`. Inputs are read only. The exact bitstream hash is verified. PNG/PDF are rendered with Matplotlib; the LaTeX source is also supplied.
