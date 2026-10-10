# Killed-store replay S1/S2 alignment root cause

## Evidence

The saved run ends with `verified=0` and a balanced result channel:

```text
packages allocated=259 completed=259 passed=259
parent_checksum=43363075
```

The VCD contains a sustained replay loop around FST `3107395..3107425`.
The observable sequence repeats every four FST units:

```text
S2 store/nack: STQ 2, token ...0b, address ...da
killed_store_replay_valid/fire: 1
LSU request fire: the younger request is accepted
S2 store/nack: STQ 3, token ...0c, address ...db
```

The same pattern continues for hundreds of cycles. It does not converge to a
data-array write or a strict-store completion in the traced interval.

## Signal chain

The DCache pipeline has three request stages. At the cycle in which an older
request in S2 fails, a younger LSU store is already in S1 and a new request may
be entering S0:

```text
s2_store_failed
  -> s2_valid kill for the current S1 request
  -> io.lsu.nack for the failed S2 store
  -> LSU rewinds stq_execute_head
  -> DCache must replay the S1 request that was killed
```

The previous local change moved the kill predicate from `s2_valid` to
`s1_valid` and changed its operand from `s1_req` to `s0_req`:

```scala
!(s2_store_failed && io.lsu.req.fire && s0_req(w).uop.uses_stq)
```

That predicate targets the request entering S0 while the request that the
S2-wide kill removes is the request resident in S1. Consequently, the S1
store continues into S2, while the newly entering store is copied into the
single replay slot. The two stores then alternate nack/replay indefinitely.

## Fix

`boom/src/main/scala/lsu/dcache.scala` now restores the kill at the original
`s2_valid` stage using `s2_store_failed`, `s1_type`, and `s1_req`. The
compensation slot captures the same S1 request selected by that kill, with
branch-kill, exception, and validity guards:

```scala
!(s2_store_failed && s1_type === t_lsu && s1_req(w).uop.uses_stq)

val killed_store_replay_candidate = s2_store_failed && s1_valid(0) &&
  !io.lsu.s1_kill(0) &&
  !IsKilledByBranch(io.lsu.brupdate, s1_req(0).uop) &&
  !(io.lsu.exception && s1_req(0).uop.uses_ldq) &&
  s1_type === t_lsu && s1_req(0).uop.uses_stq
```

The original address, uop, STQ index, packet sequence, strict-store token,
and traffic fields are therefore replayed exactly once after the S1 kill.
The request entering S0 is no longer incorrectly captured or killed. Existing
cross-package writeback serialization, token-qualified completion, and packet
ownership changes remain unchanged.

## Package count boundary

A read-only FST count shows 259 `core.io_packet_alloc_valid` pulses and 259
DCache allocation pulses. Allocation sequence values are contiguous from 1
through 259; the final value 260 is the next counter value, not an allocated
package. The 259 count is therefore not a CDC loss.

## Validation boundary

`project boom Compile/compile` passes after the change. `git diff --check`
still reports pre-existing trailing whitespace in the user-modified
`Experiment/流量分析.typ`; no touched Scala file has a whitespace error.
No simulation, waveform regeneration, RTL generation, or hardware generation
was run.
