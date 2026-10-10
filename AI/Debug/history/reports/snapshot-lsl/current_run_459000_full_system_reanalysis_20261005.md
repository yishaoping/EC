# Current 459000 Run: Full-System Reanalysis (Read Only)

## Scope and evidence boundary

This report uses only the current 459000 run and source/generated collateral that
matches it:

- log: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`
- waveform: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
- generated RTL: `chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/R_LSL.sv`, `GH_MemFIFO_1.sv`, and `BoomCore.sv`
- source: current `R_LSL.scala`, `GH_FIFO.scala`, `GHM.scala`, `RocketTile.scala`, `BoomTile/tile.scala`, and BOOM LSU/core sources

The current FST ends at 917376 while the log stops at 459000, giving an observed
2:1 FST-to-log time ratio. Historical 461000 traces are used only to explain the
change in behavior; they are not mixed into current-run event claims.

No source RTL, generated RTL, software, or simulation was changed/run for this
analysis.

## Conclusion

The 459000 assertion is a checker-ownership watchdog, not the first functional
error. The **proven immediate blocker** is a synchronous FIFO protocol deadlock
introduced by the current `R_LSL` matching logic:

```text
R_LSL compares the FIFO head type/address
  -> GH_MemFIFO only produces that head after SyncReadMem read-enable
  -> read-enable is driven by the same successful match/dequeue condition
  -> the first head remains unavailable forever
  -> no LSL dequeue/response, no checker completion, no ownership release
  -> BOOM checker watchdog reaches 2^18 and asserts at log 459000
```

This is a complete explanation for the current stop. It is distinct from the
previous 461000 run, where the old LSL logic did start a read but allowed a load
request to consume a store entry.

There is also a **strongly supported upstream stream-alignment risk**: the checker
starts its replay at the snapshot boundary around PC `0x800004ac`, while the first
current LSL entries are stores at `0x80087f58` and `0x80087f68`. The current trace
proves that these store entries reached the LSL FIFOs, but does not prove whether
the preceding BOOM loads were intentionally outside the package, delayed behind
the boundary, routed to another stream, or dropped. That question must be kept
separate from the proven FIFO deadlock.

## Assertion meaning

`BoomCore.sv:6884` maps to the checker hang assertion in BOOM core. The current
source sets `checkerHangWatchdogBit = 18`, so the assertion means that checker 1
remained owned/active without a clear for approximately `2^18` BOOM-domain
cycles. Lowering the bit changes only the stopping time.

The watchdog chain is:

```text
ic_status_1/package_owned_1 remains set
 -> checker does not reach cleanup/result release
 -> BOOM little-status counter is not reset
 -> assert__assert_22 at log 459000
```

## Current event table (FST time)

| FST time | Event | Interpretation |
|---:|---|---|
| 393085 | BOOM `rob.io_empty=1`; commit uop stream is at the `0x800004ac` region | Snapshot candidate has reached an empty ROB boundary |
| 393087-393093 | `snapshot_quiet`, `snapshot_quiet_armed`, `snapshot_accepted`, `if_dosnap` | Current run uses the armed snapshot path |
| 393093 | `packet_alloc_seq_reg=1`, `active_packet_seq=1`, allocation valid | Allocation and active sequence agree in this run |
| 393113 | checker receives `io_packet_seq=1` | Checker sees the same package sequence |
| 393107 | GH_BUF emits a CSR record | Non-memory records can precede LSL records |
| 393247-393269 | LSL channel 0/1 receive store entries; both `io_empty` become 0 | CDC/route into LSL is proven to occur |
| 393645 (current-run trace) | checker presents a load request for `0x200bff8` | Checker is waiting for the corresponding memory record |
| after queue becomes nonempty | `io_deq_ready=0`, `deq_valid=0`, `lsl_deq_fire=0` | No LSL read/dequeue handshake occurs |
| 402233 onward | checker state oscillates between checking/self-exception | It never reaches ordinary postchecking/cleanup |
| 459000 log | `assert__assert_22` | Ownership watchdog fires |

The exact current-run LSL request/handshake trace is in
`Debug/recheck_459000_lsl_core_window.txt` and
`Debug/current_run_459000_lsl_fifo_handshake.txt`.

## Proven LSL deadlock

The current source contains:

```scala
selected_head := Mux1H(..., deq_data)
lsl_req_match := nonempty && type_match && address_match && !req_kill
lsl_deq_fire := req_valid && lsl_req_match
u_channel(i).io_deq_ready := deq_valid(i) && lsl_deq_fire
```

`GH_MemFIFO` contains:

```scala
io.deq_bits := mem.read(readPtr, io.deq_ready)
```

Therefore the first nonempty state is cyclic:

```text
empty=0
 -> io.deq_ready=0 because selected_head is not valid
 -> SyncReadMem read enable=0
 -> deq_bits remains invalid/zero
 -> type/address match remains false
```

The generated RTL confirms that `mem_ext.R0_en` is driven by `io_deq_ready` and
that no current-run `R0_en`, `deq_valid`, or `lsl_deq_fire` event follows the LSL
enqueue. The queue is nonempty at the waveform tail, while the selected head and
response remain unavailable.

This is a handshake invariant violation, not a CDC enqueue loss.

## Upstream stream and boundary observations

The current snapshot boundary is materially better than the older 461000 run:

- `packet_alloc_seq_reg=1`, `active_packet_seq=1`, LSU/DCache allocation sequence,
  and checker `io_packet_seq` all agree at the first package.
- The old half-cycle symptom (`packet_alloc_valid` visible while the sequential
  active sequence missed it) is not present at the first current boundary.
- BOOM continues retiring after the accepted snapshot, which is expected for
  instructions after the captured architectural boundary.

The remaining stream concern is real but not yet a proven loss:

1. The software image has `0x800004ac: lw a5,-8(a4)` with `a4=0x200c000`, giving
   address `0x200bff8`; the checker trace presents exactly this load address.
2. BOOM commits in the same boundary region include the `0x800004ac`/`0x800004b0`
   load PCs.
3. The first memory entries observed in the current checker LSL FIFOs are stores
   at `0x80087f58`/`0x80087f68`.
4. GH_BUF forwards commit-derived records through a one-cycle registered commit
   interface and derives `ldq_header` from the delayed LSU head view. This creates
   an ordering/ownership point that must be checked against the exact commit lane,
   LDQ index, destination, and package sequence.

The evidence does **not** justify saying yet that the `0x200bff8` load was dropped.
It may be outside the package's BOOM data segment, delayed until after the boundary,
or present in a stream not selected by checker 1. The necessary join key is the
package sequence plus the BOOM commit/LSQ entry, not timestamp alone.

## Historical issue separation

The previous 461000 run had a different proven immediate error: old `R_LSL`
dequeue logic consumed a store head for a load request, returned `0x80087f58`, and
raised the ELU load-address error. The current type/address checks prevent that
wrong-type consumption, but placing those checks directly in the synchronous RAM
read-enable path created the new deadlock. Thus:

```text
old run: unsafe consume -> functional mismatch -> cancellation/watchdog
current run: no consume at all -> completion/release starvation -> watchdog
```

The snapshot sequence alignment and watchdog threshold changes are not the current
first blocker. The historical package-count/statistics findings remain downstream
validation items and cannot explain the first current 459000 stall.

## Causal classification

- **Assertion symptom (proven):** BOOM checker ownership watchdog at log 459000.
- **Immediate blocking condition (proven):** nonempty LSL FIFO with no synchronous
  read/dequeue because `deq_ready` depends on data that the read has not produced.
- **Upstream trigger (strongly supported, not fully proven):** checker/BOOM memory
  stream boundary and lane/LSQ-head alignment around the snapshot may explain why
  the requested load does not match the first visible LSL records.
- **Downstream amplifier (proven):** checker replay/self-exception state prevents
  completion; package result and BOOM clear/release never occur, so the watchdog
  accumulates.

## Reusable evidence files

- `Debug/current_run_459000_lsl_fifo_handshake.txt`
- `Debug/current_run_459000_lsl_enq_first.txt`
- `Debug/current_run_459000_lsl_final_state.txt`
- `Debug/recheck_459000_lsl_core_window.txt`
- `Debug/recheck_459000_snapshot_boundary.txt`
- `Debug/current_run_459000_boom_checker1_chain.txt`
- `Debug/current_run_459000_root_cause_full_system_20261005.md`

