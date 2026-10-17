# Stage 1 Trace Preparation

This preparation adds observation-only transaction events to the current BOOM
LSU/DCache sources and an exit marker to the emulator. The events are enabled
by the existing `+verbose` Chisel printf gate; they do not drive control,
handshakes, counters, or benchmark inputs.

The event identity is the functional request/effect/transaction token, with
slot epoch and line generation where a cache image is involved. The event
families are `ISSUE`, `EFFECT`, `TERMINAL`, `REPLAY_GRANT`, `REPLAY_RESULT`,
`REFILL`, `CLEAR`, `STORE_DONE`, and `RELEASE`. `STAGE1_SIM_EXIT` records the
emulator termination reason. The scoreboard requires Store, SC, AMO, replay,
clear, refill, and resource-release coverage; missing coverage is UNKNOWN and
fails the run.

`stage1_provenance.py` refuses a simulator without both trace markers and
checks the source, generated-model, and simulator hashes from a manifest.
`stage1_run_trace.sh` fixes the existing benchmark and loadmem hashes, uses a
fresh run directory, requires `reason=serial_success`, and then runs the
scoreboard. No simulator, hardware generation, or compilation was run while
preparing this report. The existing simulators therefore remain outside the
new trace provenance until a fresh isolated debug build is made.
