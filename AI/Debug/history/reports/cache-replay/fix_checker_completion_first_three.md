# Checker completion fix: first three hardware changes

## Scope

This change set addresses the three confirmed causes in
`verified0_cross_package_coherence_root_cause.md`. The goal of this step is to
let checker execution complete while preserving the existing architecture and
strict Store/Load accounting. No simulation or RTL generation was run.

## Changes

### 1. Serialize shadow writeback and metadata clear

`boom/src/main/scala/lsu/dcache.scala` now suppresses
`crossPackageWbReq.valid` while `crossPackageMetaClearPending` is set. The
existing handshake remains:

```text
writeback fire -> wait until wb.io.idx.valid is low
               -> metadata clear pending
               -> metadata clear fire
               -> release the blocked line
```

This prevents a second writeback from being accepted in the cycle after the
first writeback becomes idle but before the metadata write has fired.

### 2. Report the correct TileLink permission

The shadow writeback now uses `TLPermissions.TtoN`. The subsequent local
metadata clear writes `ClientMetadata.onReset` (Nothing), so the C-channel
permission report and the L1 metadata agree. The previous literal `0.U` was
`TtoB`, which left the shared L2 with Branch permission for a line removed from
the BOOM L1.

### 3. Preserve the active packet sequence for LSU events

`boom/src/main/scala/exu/core.scala` now drives LSU `active_packet_seq` from
R_IC's current active sequence whenever a new packet is not being allocated.
The previous `debug_maincore_status === 2.U` mux drove zero outside
`fsm_check`, even though stores and loads could still retire and emit address
events. The new packet allocation path retains priority for the newly allocated
sequence; the initial no-package value remains zero.

This keeps existing statistic qualification unchanged: ordinary architectural
events remain gated by `traffic_counting`, while strict token acceptance and
packet result accounting remain intact. Events with an invalid sequence are
not silently discarded.

## Verification performed

```text
sbt 'project boom' compile
```

Result: success. The check compiled the BOOM Scala sources only; it did not run
Verilator, a benchmark, simulation, or RTL generation. The repository-wide
invariant script also passed its known EC protocol checks. Existing unrelated
whitespace findings in `Experiment/流量分析.typ` were left untouched.

## Required runtime follow-up

The next runtime run should check, in order:

1. `verified=1` and the parent checksum;
2. no repeated `crossPackageWbReq` while metadata clear is pending, and C-channel
   param `TtoN`;
3. `[ADDRESS_STATS] status=PASS valid=1 error=0`;
4. `boom_arch == boom_strict == checker_sum` for the measured window.

