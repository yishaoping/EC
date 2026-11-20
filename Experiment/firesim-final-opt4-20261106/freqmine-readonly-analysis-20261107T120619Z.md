# Native Freqmine read-only result inspection

Observed: 2026-11-07T20:06:19.857319+08:00

Three valid formal FPGA rounds, matching software/hardware/input identities. No task stopped, restarted, or reconfigured.

| Metric | r1 | r2 | r3 |
|---|---:|---:|---:|
| Status | VALID_FORMAL_COMPLETE | VALID_FORMAL_COMPLETE | VALID_FORMAL_COMPLETE |
| ROI cycles | 89280523270 | 89411029335 | 89380362214 |
| ROI instructions | Not collected | Not collected | Not collected |
| Target interval cycles | 92449732136 | 92582048743 | 92559995965 |
| Host wall seconds | 5549.358126 | 5557.670074 | 5557.331869 |
| Simulation throughput cycles/s | 16659730.045 | 16658643.266 | 16655630.892 |
| Output hash | Exact match | Exact match | Exact match |

Formal input: simmedium, kosarak_500k.dat, 500000 transactions, support threshold 410, 1 thread, no warmups. Command: freqmine kosarak_500k.dat 410. Profile: freqmine-serial-staged-input-preallocated-heap-no-aux-timing. Target BOOM clock: 200 MHz. Linux maxcpus=1 mem=2G.

ROI cycles mean: 89357304939.667; sample SD: 68239919.953; CV: 0.076367%. Host wall mean: 5554.786690 s; sample SD: 4.704314 s; CV: 0.084689%.

Application/capture/driver exit status 0 in all rounds; no timeout, ROI faults or fatal UART markers. Native has no checker; checker statistics are not applicable. Each round has complete source ROI boundaries, exact 20-integer output hash, matching result and identity completion hashes, and matching saved evidence hashes.

The r3 driver PID 2234375, start_ticks 1494192 completed naturally at 2026-11-07T11:52:21.499442+00:00; the existing idle-repair service took over the FPGA. Dedup test and simsmall passed, then the same service started formal Dedup simmedium r1 (active run recorded in the JSON snapshot). The Native queue is waiting for remaining software/repair ownership to finish, and Coverage-first is alive waiting at its dependency boundary. C4 remains in actual synthesis with increasing CPU time and a freshly updated runme.log; no certified final bitstream exists.

Native now has 6/16 complete three-round benchmarks and 6/16 with at least one valid formal round. Opt4 0/16, paired 0/16. Dedup test is functional validation and is not counted as formal coverage.

Bound ELF SHA256: 9738afd02fba6464dceb21bc6d1713eae5c7f881c09aaa3df5282f058ca6d2fc

Bound input SHA256: 63a18321218dfbb14157e46e4c3dd28e19f3ba9162ef0b663a4c6c342b110e0b

Bound Native hardware source ID: be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4

Bound Native bitstream SHA256: bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea

Bound rootfs SHA256: c5a7bfacfd78594ff1b93503ad3bc8ec5edfd012535e4b06a94380a417cd457e

Bound firmware SHA256: 41f10c4880ea2d9a1f68f7818c20a8edcc33715c24b6cfb23d43d02e228ef265

Bound host driver SHA256: ebdbe142890c7c306396d3dc860db4a85d2e206a504ff0b361aa2bf386db7407

Detailed machine-readable evidence and complete identity: [freqmine-readonly-analysis-20261107T120619Z.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/freqmine-readonly-analysis-20261107T120619Z.json)

r1: [native-freqmine-simmedium-r1-20261107T071435Z](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r1-20261107T071435Z)

r2: [native-freqmine-simmedium-r2-20261107T084705Z](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r2-20261107T084705Z)

r3: [native-freqmine-simmedium-r3-20261107T101944Z](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/runs/native-freqmine-simmedium-r3-20261107T101944Z)
