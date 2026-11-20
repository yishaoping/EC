Independent audit completed: **PASS**. This directory contains CPU RTL/GoldenGate metasimulation evidence. It contains **zero FPGA samples** and makes no architectural rollback/restart claim.

Functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`. The audit verified 388 SHA-256 bindings across 258 distinct files, completed broker outputs, original raw output, finite package identities, and complete SVB payload lifetimes. It did not start workloads, change models or RTL, access FPGA devices, deploy hardware, or modify live service inputs.

| Complete workload | ROI target cycles | ROI instructions | Total fastest target cycles | Host seconds | Allocated/full-compare/accepted PASS | Accepted-result tail after ROI |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Canneal project64 | 536,456 | 392,248 | 1,759,002 | 3,791.372085 | 131/131/131 | 332 BOOM CSR cycles |
| Blackscholes project64, 64 options × 100 rounds | 6,166,433 | 3,562,647 | 6,391,002 | 12,994.935569 | 1,122/1,122/1,122 | 9,655 BOOM CSR cycles |

Both retain the complete original baremetal protected kernel and one thread. These are not the 16-program Linux formal-input FPGA suite. Both original application outputs verify and exit successfully; the independent join proves unique allocation → matching checker begin → real `full_compare=1` local PASS → BOOM accepted PASS for every observed `(checker, package_seq)`. Both have zero failures, cancellations, duplicate identities, sample errors and outstanding packages at observation end. Pending packages at ROI stop were 2 and 3 respectively. Tail is the last BOOM accepted result minus ROI end on one CSR timebase, not strict per-package checker execution latency.

Canneal original unobserved model and external-observer run match complete application rows, both synthesized print-stream hashes and total target cycles exactly. This demonstrates finite observer transparency. The standalone target using `+dramsim` uses a different memory model from GoldenGate FASED read/write latency 30, max requests 4; its ROI count is not an equality reference or a valid architectural slowdown denominator here.

Blackscholes full raw stdout+stderr was independently decompressed through EOF: 3,193,978,964 bytes, SHA-256 `30ac9917b4b68952b087a47d8465d34304ef7ed35567b9ca61f79c8bb42124ea`. Compressed SHA-256 is `cdd2484b7da999dbd74c0c9103235606fc49ca7766d78aae199e14388a0d3031`. No raw lines were removed. Host rates are 463.949 target cycles/s Canneal and 491.807 Blackscholes; host competition was not isolated and these rates are simulator efficiency only.

| Exact Canneal SVB replay | Original target-edge records | Defined output word checks | Positive mismatches | Positive host seconds | Expected payload mutation |
| --- | ---: | ---: | ---: | ---: | --- |
| Standalone frozen target SVB RTL, CPU | 1,759,001 | 19,698,670 | 0 | 36.660018 | Rejected: exactly one mismatch; negative harness exit 0 |
| Same SVB through GoldenGate component, CPU | 1,759,001 | 19,698,670 | 0 | 7,984.405287 | Rejected at real promotion data; negative process exit 1 |

Both use the complete 710,636,420-byte binary trace (SHA-256 `b1d2243c18bb3f512c24c2ea86ddb91dd5674f92d1bdd1798e55d0b16c1122be`), fastest target ticks 2–1,759,002, including all 53 reset edges, idle and backpressure. This is the 62 original emitted SVB ports with defined masks, rather than all standalone debug observations. Positive GG replay requires `+svb-force-all-inputs`, has `input_cache_enabled=0`, and preserves all 84,432,048 input word writes. It is a host-controlled MMIO replay; its 220.305 target edges/s and FMR 228.4 include the harness and do not measure autonomous SVB throughput.

The actual negative log proves a valid application payload mismatch at source tick 1,092,660, `io_promote_bits_data_0[0]`: expected `d7700b1e`, actual `d7700b1f`. Promotion valid and ready/accepted occur at different ticks under backpressure; the acceptance event remains tick 1,092,685.

| SVB ownership lifetime, fastest BOOM target cycles | Samples | Sum | Mean | Median | P95 | P99 | Maximum |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Capture → accepted promotion | 659 | 4,456,980 | 6,763.247344 | 7,067 | 8,006 | 8,315 | 8,670 |
| Accepted promotion → ACK | 659 | 53,358 | 80.968134 | 83 | 90 | 94 | 98 |
| Capture → ACK | 659 | 4,510,338 | 6,844.215478 | 7,150 | 8,089 | 8,398 | 8,753 |

All 659 lifetimes join full entry identity and all data payload words; censored or unresolved lifetimes are zero, final observed ownership is empty. Histograms use exact one-cycle buckets and nearest-rank percentiles. ACK is writeback ReleaseAck ownership completion, **not checker execution completion**. CSR values are never subtracted across reset epochs.

Observed workload completion rate is 659 / 1,758,948 nonreset target cycles = 0.000374655760 transactions/cycle. Over the explicitly defined first-capture-to-last-ACK inclusive window it is 659 / 527,963 = 0.001248193529/cycle. These are offered-workload rates, not saturated capacity. Occupancy maximum is 32, full occupancy lasts 3,956 nonreset cycles, and mean occupancy over all nonreset cycles is 2.564224753.

The application FPGA admission files pass independent offline schema, CPU proof, full trace, guarded driver, source/header ABI, source-pinned follower and timeout checks. The only permitted card is `0000:21:00.0`, serial `21770433G02LA`; admission does not authorize e2 or global driver operations. Both follower process identities (PID, boot ID and process start ticks) were alive at the audit snapshot. They still wait for existing certified component deployment, the 42,291-value directed hardware proof and a safe card21 lock boundary. This audit deliberately does not certify that hardware gate or claim board execution.

Use `summary.json`, `complete.json` and `evidence-verification.json` as the machine-readable entry. `workloads.csv`, `replays.csv`, `svb-latency.csv`, `svb-lifetimes.csv` and `svb-latency-histogram.csv` contain the reproducible numerical exports. Raw full identities and occupancy data remain in `svb-lifetimes-recomputed.json`. Additional receipt/timeout checks are in `admission-extra-checks.json`.

Reproducer: `/usr/bin/python3 /data1/gzh/EC/firesim/final-opt4-20261106/candidates/overnight-ec-evidence-audit-r1-20261112/analyze.py`. It refuses to overwrite this completed audit; use a fresh versioned output directory for any necessary re-audit. Prior audit-only parser/serialization assertion failures are retained in r1/r2/r3 sibling directories; they changed no workload, original evidence, hardware or live service.
