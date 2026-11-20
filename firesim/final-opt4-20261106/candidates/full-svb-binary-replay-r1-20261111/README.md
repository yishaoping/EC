# Original target SVB replay

This candidate reuses the existing standalone **frozen target** SVB Verilator
archive and global objects from
`Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-r3-20261111/obj/`.
It compiles only `replay.cpp` and links a new independent executable. It does
not extract or modify the FAME host module and does not rebuild the model.
`plan.json` binds the original RTL, archive, header, model objects and the
original verification receipts. The unique functional baseline is `8491167d`.

The source stream is the r5 external observer's complete original GoldenGate
SVB input/output stream. The 62 emitted original ports include every capture
and promotion payload bit, ACK identity, watermark, invalidate/flush and
release ordering. Each record advances exactly one target clock. Host stalls
are represented by their target ordering rather than extra target clocks;
idle and backpressure target cycles are never removed.

Two standalone target inputs optimized out of the emitted host interface are
set to zero: `io_resetStats` and `io_countStats`. In the original frozen source
they drive only diagnostic maximum/histogram outputs, which are absent from
the captured 62-port interface. They do not drive capture, data storage,
selection, promotion, invalidation, ACK or the compared outputs. The unused
`currentEpoch` port is also absent from the existing standalone emitted RTL.
This boundary does not claim preservation or replay of unobserved diagnostic
histograms or complete DUT state.

The comparator checks every defined output among the original 62 ports before
each target edge. It does not compare uninitialized storage payload when
`promote.valid=0`, unowned active-slot outputs, or blocking-slot outputs when
`releaseBlocked_3=0`. After an observed reset edge, ready/valid, selection,
occupancy, release blocking, coalescing/discarding and ACK outputs are checked
on every target cycle. The explicit comparison conditions are generated in
`replay.cpp`. A finite mismatch rejects the run and keeps the original binary
trace and comparison log.

The preparation request is already in the existing unattended broker as
`full-svb-binary-replay-r1-8491167d`. It compiles the small replacement replay
main, replays the actual 10,000-cycle r5 startup binary and runs an independent
directed full-data mutation check against the original target model. The
startup stream has no actual SVB capture/promotion, so startup pass cannot
prove application replay correctness. The directed mutation is labeled
synthetic and cannot replace the future real application data mutation.

Preparation actually passed at `2026-11-11T13:10:45Z`: 10,000 real target edges,
53 reset edges, 109,989 defined output-word comparisons and zero mismatches.
The separate directed data mutation changed one valid promotion data word;
the comparator rejected it with exactly one mismatch among 41 defined checks.
Preparation reused all model objects and compiled only the new replay main.

After both preparation and the r5 complete workload trace pass, the separate
five-minute system timer `ec-opt4-original-svb-replay-r1-dispatch.timer`
submits one immutable full-replay request to the same broker. It requires real
application captures and promotions, then replays every target cycle and
injects a bit error into an actually valid promotion's expected full payload
to prove comparison sensitivity. No additional waiting CPU job occupies a
synthesis slot. Install with:

```
sudo /usr/bin/python3 /data1/gzh/EC/firesim/final-opt4-20261106/candidates/full-svb-binary-replay-r1-20261111/install_timer.py
```

Data and persistent service evidence are under:

`Experiment/firesim-final-opt4-20261106/cycleprecise-original-svb-binary-replay-r1-20261111/`

State:
`Experiment/firesim-final-opt4-20261106/Opt4-original-svb-binary-replay-r1-state.json`

Dispatch state:
`Experiment/firesim-final-opt4-20261106/Opt4-original-svb-binary-replay-r1-dispatch-state.json`

Reconnect by checking PID, start_ticks and boot_id before adopting monitoring;
never restart a live instance. Outputs and receipts are atomic and distinct
for preparation and full replay. A missing full receipt is not a pass.

This work performs no FPGA access. Successful CPU replay is an admission
requirement for later application-trace FPGA replay, not FPGA evidence by
itself, not complete Opt4 equivalence, and not architectural restart validation.
