# Streamcluster: epoch flush revokes a granted store's predecessor

Status: confirmed on frozen hardware `1532923803d7451b0c7843e9abad1c90ef9eb9ed`;
first correctness repair candidate under validation. The old tag is retained as historical evidence.
No results from the failed run qualify as performance data.

The pilot `streamcluster_simdev_correction_20261103_093035_f686267f`
exits with `write grant bypassed L1 preservation`, emitted
`BoomNonBlockingDCache.sv:118994` / source `dcache.scala:3126`.
A second run of the identical ELF/model with verbose diagnostics reproduces it.
Its immutable evidence is in `raw/diagnostics/streamcluster_preservation_153292380/`.
The original compact run remains in `runs/` until append-only raw export.

| BOOM cycle (hex) | Decimal | Observed event |
|---|---:|---|
| 36f08 | 225032 | SVB entry 9 captures line 0x80041400, predecessor seq 60, generation 0x582d, SVB epoch 0xf8; fast lease acquired for seq 61, slot epoch 1. |
| 36f09 | 225033 | LSU issues committed store request/effect 0xe8e4, STQ 4. |
| 36f0a | 225034 | DCache S1 accepts the identical store and resident. |
| 36f0b | 225035 | S2 grants that store to S3; on the same edge FASTLINE_RELEASE reports epoch_flush. |
| following S3 check | — | Preservation assertion fails; no physical EFFECT or terminal exists for request 0xe8e4 in the diagnostic. |

Use the explicit `cycle=` fields for BOOM timing. The simulator's formatted
`[225000]` error timestamp is not an exact BOOM cycle. In the compact run the
SC observer time is BOOM cycle +103; it is a separate time coordinate.

The assertion symptom and immediate missing predecessor permission are proven.
The upstream trigger is proven by same-edge S2 ISSUE and epoch_flush release.
Source connects `io.traffic_reset || io.lsu.exception` directly to the old flush;
the SVB epoch 0xf8 indicates repeated exceptions, but the diagnostic does not
independently identify this particular exception's architectural cause. No
checker FAIL, corruption, cache shadow estimate, or incomplete log footer is
needed to explain the assertion. Missing footers follow the abort.

The old S2 grant did not honor epoch flush, while a committed normal store is
intentionally not killed by `io.lsu.exception` (`uses_ldq` is false). Therefore
the flush revoked permission from a store that still had to execute. A held S3
write under array backpressure has the same ownership hazard.

The initial repair candidate blocked all writes while the observer reset defaulted high and prevented firmware startup. That candidate was rejected and all of its runs excluded. The revised repair blocks new write grants through the existing LSU nack / MSHR replay
retry paths only while a snapshot/lease or deferred flush is live. An already granted,
unapplied, uncancelled S3 write whose only predecessor permission is its SVB
lease drains before the actual flush. Pending state remembers a one-cycle
exception and preserves reset priority. The epoch changes on actual flush.
New captures are blocked and late issued snapshots remain discard-only; the
previous capture-cancellation fix is retained. Assertions remain enabled.

Required acceptance: emitted RTL build, directed epoch boundary witnesses,
the failing Streamcluster workload, GAPBS BFS, and Blackscholes. The first candidate failed startup and the second candidate remains provisional. Until the required regressions pass, no replacement canonical tag is claimed.
This does not implement architectural rollback or durable snapshot retention
across exceptions: the existing SPEC-flush behavior remains a recovery limit.
