# External original GoldenGate observer

Functional baseline is `8491167d84b6d9521b151a743673c1516926a1f8`.
This is CPU metasimulation. It changes only the executable's external C++ main;
the original generated GoldenGate RTL, original compiled model archive, host
driver objects, target ELF and target inputs are reused unchanged.

The existing model is in:

`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-metasim-r1-20261111/host/`

The finite startup comparison actually passed on 2026-11-11: original binary,
replacement-main observer OFF, and observer ON each stopped at the deliberately
requested 10,001 target cycles, with byte-identical two captured printf streams.
The explicit max-cycles cutoff returns 1; it is not application success. The ON
stream has 10,000 observed actual BOOM edges, 53 reset edges and zero finite
sampling consistency errors. No SVB/checker event occurs in this startup window.

Startup evidence and subsequent results:

`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-full-gg-external-observer-r5-20261111/`

`probe-result.json`, `probe-binary-integrity.json` and
`binary-validation-negative-tests.json` preserve the actual finite checks.
The binary validator rejected truncated records, duplicate target indices,
an invalid clock field, a different functional baseline, a different generated
GoldenGate version, a wrong record size and a wrong port offset. The seven
actual mutations are in `binary-validation-negative-tests-v2.json`.
`plan.json` binds the original archive/objects/header,
host RTL, ELF and exact compile/link argument lists. `build-receipt.json` binds
the new executable; no model object was rebuilt.

`binary-layout.json` lists every one of the original emitted SVB's 62 ports,
including full four 128-bit data rows, capture/promote valid-ready, ACK identity,
watermark/invalidate/flush, occupancy and release ordering outputs. Every actual
BOOM edge is recorded, including reset, idle and backpressure. Each record has
101 little-endian 32-bit words (404 bytes), preceded by a 16-byte magic header.
The expected 1,759,002-cycle Canneal workload requires approximately 678 MiB for
this stream. The process owns a 4 GiB total output budget, 24 GiB address-space
limit and at most two CPU affinity IDs. Host time is recorded separately.

The edge is the actual generated BUFGCE output posedge, confirmed by the
generated C++ trigger expression. Captured pre-edge acceptance and payload are
checked against post-edge completed/PASS/FAIL/CANCEL counters and the stored
checker-result CSR timestamp. Performance statistics reset is handled according
to its generated priority without discarding functional acceptance or SVB edges.
This is a finite runtime consistency check, not universal formal proof.

No complete r5 application run is started by the preparation service. After the
existing r3 same-ELF Canneal run completes and passes its output/printf/cycle and
BOOM-acceptance gates, the independent system timer runs `dispatch.py` once per
five minutes. It verifies current policy, exact original inputs, executable,
startup receipts and predecessor result, then publishes a single complete
request to the existing unattended broker using an atomic hardlink. The broker
starts `run_full.py` in its own persistent system service. There is no resident
waiting CPU synthesis job and no second simultaneous full Canneal workload.

Install the independent timer with:

```
sudo /usr/bin/python3 /data1/gzh/EC/firesim/final-opt4-20261106/candidates/full-gg-external-observer-r5-20261111/install_timer.py
```

System timer: `ec-opt4-external-svb-r5-dispatch.timer`.
Dispatch state: `Experiment/firesim-final-opt4-20261106/Opt4-full-gg-external-observer-r5-dispatch-state.json`.
Full successor broker name: `full-gg-external-observer-r5-full-8491167d`.
Controller state: `Experiment/firesim-final-opt4-20261106/Opt4-full-gg-external-observer-r5-state.json`.
Final successor receipt: `full-result.json`, with `binary-integrity.json` and
original raw streams. `acceptance-pairing.json` matches local checker results
to actual BOOM acceptance by package sequence, hart and status. The local
checker clock is never assumed to share a CSR epoch. `svb-lifetimes.json`
matches complete capture/promotion/ACK payload identities and computes
capture-to-promotion, promotion-to-ACK and capture-to-ACK separately in fastest
target cycles. It preserves captures without ACK as censored samples and
reports an exact one-cycle histogram with mean/median/P95/P99. None of these
SVB metrics is checker execution completion latency. A missing final receipt or partial binary tail is never
a complete sample. Reconnect by checking PID/start_ticks/boot_id in the state;
never duplicate a live instance. Preparation and full runs use a file lock.

The full r5 trace must still be replayed against the standalone original SVB
before admitting FPGA application-trace replay. Finite r4 windows alone lack an
initial reset state and cannot be used as independent replay evidence. The
observer does not supply a same-package BOOM execution completion event, so it
cannot establish strict checkerDone minus BOOMDone latency. It does not verify
architectural restart/rollback, and never converts local checker enqueue into
BOOM completion. It performs no FPGA operations. Native remains paused and
the separate FPGA path remains restricted to `0000:21:00.0`.
