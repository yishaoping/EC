# Package cancellation and ARF anchor fix

## Causal answer

Package 1 and package 5 are not directly cancelled by the missing sequence-7
data anchor.

* **Package 1** reaches the data/LSL drain, but the ARF compare handshake never
  reaches `if_cp_check_completed`. It is cancelled by the bounded ARF wait
  timeout. The missing sequence-7 anchor occurs later.
* **Package 5** is still active when sequence 6 is admitted. The old
  `new_package` rule treats that overlap as cancellation. It is an ownership
  and admission-ordering error, not an ARF7 event.
* **Sequence 7** is the direct cause of the later BOOM hang: ARF/CPS sequence 7
  enters a separate CDC FIFO without a consumed data anchor, so the ARF FIFO
  eventually asserts backpressure and the BOOM pipeline stops.

The common defect is that package allocation, data-anchor delivery, and ARF/CPS
delivery were independent protocol events. It is therefore correct to call
them related protocol failures, but not to claim that ARF7 directly cancelled
packages 1 or 5.

## Hardware changes in this worktree

1. `GHM.scala` emits one zero-payload data transaction only after a non-zero
   checker segment sequence has been observed and the source-side
   `ght_filters_empty` level has stayed high for a three-cycle settling window.
   A real data beat resets that window and has priority. The transaction uses
   the normal `valid + sequence + data-vector` format, is held by the
   AsyncQueue until `enq.fire`, and is remembered so it is emitted only once.
   RocketTile accepts the sequence as the data anchor while its packet filters
   ignore the all-zero payload. A one-cycle `if_data_en=0` is therefore treated
   as "data not visible yet", not as proof of an empty package.
2. `RocketCore.scala` blocks admission while a package or result is owned
   locally. A one-entry pending-sequence register captures a newer sequence
   pulse during that interval, so admission backpressure cannot lose it. A
   newer sequence is queued rather than cancelling the active package.
3. `R_IC.scala` keeps a local per-checker ownership bit. The scheduler treats
   the checker as unavailable until the matching result-release clear is
   observed, even if the broadcast status briefly appears idle.
4. `R_RSU.scala` no longer retires normal or privileged merge state while
   `big_hang` is asserted. The terminal PC/FCSR/CSR-shadow item therefore stays
   live until the CDC path can accept it.
5. `R_RSUSL.scala` exposes an ECP-tail-ready bit. RocketCore uses it only after
   both ingress and LSL are empty to retry `do_cp_check` if the original ICSL
   boundary pulse was lost; the retry is reset at the next package's ECP index
   zero and cannot compare a partial ARF stream.

These changes preserve the existing non-zero data packet encoding and result
status ABI. They do not remove the ARF timeout; a missing or malformed stream
still terminates with a bounded CANCELLED result instead of holding the checker
forever.

## Static verification performed

* `sbt -batch 'project chipyard' compile` passed using Java 17.
* `git diff --check` reports only pre-existing trailing whitespace in
  `Experiment/流量分析.typ`; the modified Scala files introduce no whitespace
  errors.
* No simulation, Verilator run, VCD/FST replay, RTL generation, or hardware
  generation was run.

## Remaining design boundary

The current GHM interface exposes a live segment-id vector rather than an
explicit `package_allocated`/`package_data_done` handshake. The empty-anchor
detector therefore uses a per-checker sequence watermark, a source-domain
empty settling window, and a `fire`-updated sent watermark. This is conservative
for delayed data, but it cannot prove producer completion if a future producer
keeps `ght_filters_empty` high and later creates data. The long-term interface
should carry an explicit allocation/data-done message with an epoch and use
modular sequence comparison.
