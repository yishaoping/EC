# Current 259-package run: checker traffic window mismatch

## Observed failure

The saved run reports balanced package results but fails the BOOM/checker
traffic comparison:

```text
packages allocated=259 completed=259 passed=259
boom_arch   store=61556 load=84966
checker_sum store=61674 load=85132
delta       store=118   load=166
```

`boom_arch == boom_strict`, so this delta is not a BOOM strict-completion
double count. The benchmark result is also independently wrong in this run:
`verified=0`; the traffic fix must therefore not be treated as proof that the
data-coherence failure is solved.

## Signal chain

The checker software sends `ghe_fpga_perf_start()` before entering its first
checking package (`Software/Test/core/checker.c`). `R_ICSL` latches that pulse
in `trafficEnabled` and, before this fix, used:

```scala
trafficCounting = (trafficEnabled || io.debug_perf_start) &&
  !io.debug_perf_stop && !io.debug_perf_reset
```

That predicate counted every checker dequeue while the command remained armed,
including setup/nonchecking execution before a package and the return to
nonchecking between packages. BOOM starts its window separately from hart 0,
so those operations have no matching BOOM measurement event.

The existing waveform gives direct boundary evidence:

| Event | FST time |
| --- | ---: |
| checker hart 4 starts traffic | 361905 |
| checker hart 2 starts traffic | 364229 |
| checker hart 3 starts traffic | 364241 |
| checker hart 1 starts traffic | 364277 |
| BOOM starts traffic | 394935 |
| checker hart 4 enters `fsm_checking` | 3300529 |
| checker hart 2 stops traffic | 3349589 |
| checker hart 3 stops traffic | 3352733 |
| BOOM stops traffic | 3360115 |

For example, hart 4 has checker `io_st_cache_deq` and `io_ld_cache_deq`
events around `3300009..3300041`, before its `fsm_state` reaches checking at
`3300529`. These are included by the old level-only predicate. The same issue
occurs at nonchecking gaps and explains why checker totals exceed BOOM by 118
stores and 166 loads.

## Source fix

`chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala` now defines
`checkerTrafficState` as the four package-owned states:

```scala
fsm_checking || fsm_checking_priv ||
fsm_postchecking || fsm_postchecking_priv
```

`trafficCounting` requires both the latched performance enable and this state.
The postchecking states remain enabled so tail completions for the package
being drained are retained; reset/stop still disable counting immediately.

This keeps checker and BOOM event ownership aligned without adding a constant
offset or changing package allocation/result handling.

## Related fixes already present

- BOOM LSQ entries carry stable `packet_seq` and `traffic_scope_valid`; commit
  statistics use the saved entry ownership rather than live R_IC state.
- Address statistics accept an event at the same sequence as the safe
  watermark (`<`, not `<=`), allowing legal same-package tail commits.
- Cross-package shadow writeback is serialized until metadata clear and sends
  `TLPermissions.TtoN`, matching the local metadata invalidation.

The current VCD confirms the cross-package path uses C-channel `param=001`
(`TtoN`) and has no writeback request while `crossPackageMetaClearPending` is
asserted.

## Verification

Static BOOM compile passed:

```text
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

The compile produced only existing warnings in `R_ICSL.scala`; it did not run
Verilator, simulation, or RTL generation. `git diff --check` passed for the
touched Scala sources.

The saved VCD predates this source change, so runtime confirmation still needs
a later user-invoked run. The expected checks are `verified=1`, valid address
statistics, and `boom_arch == boom_strict == checker_sum`.
