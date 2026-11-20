This source-bound proof joins the emitted frozen FireSim owner-token controls
to the existing connected 109-queue, owner adapter, and actual 512x81 RAM
proof. It checks command one-shot behavior, response acceptance only at the
target-cycle finishing event, and the emitted enabled-clock state transition.

The exact all-token finishing equation is factored against the same emitted
FireSim RTL. All 74 owner command completions and 35 response-valid conditions
are connected to actual queues; only unrelated finishing factors are grouped
into one unconstrained Boolean. The next clock token and target command payloads
remain arbitrary. Exact emitted fired-state and enabled-clock updates are
extracted and connected. The previous proof supplies its stated FIFO lemma. No target RTL,
memory annotation, experiment input, or live job is changed.

The proof checks two-host-edge relational base/step obligations for all 81
payload bits in nine 9-bit slices, plus delivered-data/write-order observations,
three actual control mutations, and a related-state target-edge nonvacuity
witness. It does not prove target payload/reset transitions, reachable-state
initialization, complete DCache/full-system equivalence, liveness, whole-device
FIT, timing, bitstream certification, or an FPGA sample. The broker owns execution
and preserves all proof logs.
