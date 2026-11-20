# Independent architectural recovery implementation

User decision: recover/replay integer and floating registers, PC, CSR and memory
from the last contiguous PASS package, exporting actual completion events.
Original frozen commit 8491167d84b6d9521b151a743673c1516926a1f8 is preserved.
This is a functional extension, not a fault-behavior-equivalent area rewrite.
No recovery component is instantiated in the active 9ae9a7fc whole synthesis.

## Versioned evidence

* a4477d7241d80826f5d47a679fa05a2571d413c7: initial controller. Actual
  generated Verilator RTL passed 64 transactions and 10 negative cases.
  `Opt4-architectural-recovery-r1-state.json` is control-component evidence only.
* e4a9d5177673f097ed07adf7579c59b6d75fda88: actual snapshot store/restore and
  reverse memory journal components. Six snapshot slots retain a safe anchor
  and C4 outstanding packages. Every word is captured in order and sealed;
  out-of-order PASS never bypasses a missing predecessor. Capacity backpressures.
  The 64-entry journal owns predecessor bytes until exact write/readback ACK,
  undoes repeated/overlapping writes in reverse order and checks cursor bounds.
  Actual generated RTL passed 16 state transactions × 96 words, 22 negative
  cases, and 16 memory transactions × 64 records, 24 negative cases.
  Evidence: `build-logs/Opt4-architectural-recovery-state-r2-20261111/result.json`.
* 24633f1a0333e9515a5b38dcfb38d4b23ca09082: independent successor. Re-arm
  generation AFTER completed memory/state restore and checker initialization
  but BEFORE redirect. Waiting for first retirement before enabling the undo
  log could otherwise deadlock a store at restart PC. Also finish propagating
  already observed contiguous PASS before selecting a failure checkpoint;
  freezeRequested blocks retirement immediately during that bounded walk.
  Events now carry actual response retiredPc/drained values, not just command
  PC or a sampled cycle. See `Opt4-architectural-recovery-state-r3-state.json`
  for actual validation outcome; submission alone is not a pass.

The 96-word and 64-entry test geometries validate component behavior. They do
NOT establish a complete CSR inventory or adequate real workload journal size.
No component/mock-device test is a real BOOM or coherent-memory restoration.

## Required next integration work (automated worker must continue)

1. Build a coherent orchestrator in a NEW version from the successful r3 commit.
   Synchronize the snapshot safe header with the journal released header before
   controller failure acceptance. Retirement/publication must freeze on the
   real FAIL immediately, while already-recorded PASS pointer propagation and
   journal release finish. Never manufacture PASS for bootstrap or cancellation.
2. Capture all architectural words from the actual core at the matching package
   boundary. `exu/core.scala:2034` arfs/farfs are observation mirrors updated on
   `rob.io.commit.arch_valids`; x0 is not initialized there. Explicitly supply
   x0=0 and account for same-cycle commit writes, PC and boundary ownership.
   `R_RSU.scala` exports snapshots; it is not physical-register writeback.
3. Restore actual physical registers plus rename/free/busy ownership, OR implement
   a verified precise privileged restore/restart mechanism. Writing only arfs/
   farfs mirrors is invalid. Existing ROB speculative rollback does not recover
   a retired checker package. Freeze the right pipeline/LSU boundaries and
   establish quiescent completion, including outstanding load/store/MSHR work.
4. Inventory actual CSR configuration from CSR.scala/parameters. Cover writable
   privilege, FCSR, trap/delegation, translation/protection, counters and enabled
   extension state; document external timer/interrupt semantics. The existing
   13-word checker shadow is insufficient as a full CSR checkpoint. Reject any
   unsupported configuration explicitly rather than silently skipping state.
5. Connect memory predecessor capture BEFORE each relevant semantic cache write,
   including merged writes and AMOs, and stall at log capacity. Cover real
   dataWriteArb, MSHR/refill, SVB and L2/probe/release visibility. Do not equate
   SVB invalidate/ReleaseAck with full memory restore. MMIO/external side effects
   require defined ordering barriers, not replayed/ignored irreversible writes.
   Match coherent completion/readback by command generation, sequence, cursor,
   address and byte mask; never echo a request as completion.
6. Re-arm both restored backends before allowing redirect acceptance. Restore
   completion, checker-generation initialization, actual restart-PC retirement
   and eventual checker drain are separate events. The controller active flag
   must not keep all snapshot/log capture locked during resumed execution.
7. Independent firmware version: current software/C4/opensbi/lib/sbi/ec_opt4.c
   lines 45–46 permit one checker context per boot; ec_opt4_entry.S trap/park
   is not a generation-safe restart. Add and verify a real context lifecycle
   without host reset or changing the current live software profile.
8. Validate complete source-bound DUT with real compare-input fault injection,
   saved/restored integer/floating/PC/CSR/memory comparison, actual retirement,
   checker-generation correspondence, full output and zero unfinished tasks.
   Normal-path equivalence and area/timing admission are distinct requirements.
   Only then compose with the selected area version and admit whole synthesis.

## Continuous workflow and deployment boundary

New proof jobs use the existing hash-bound request broker and detached systemd
CPU services. State includes PID/start_ticks/boot_id; successful stage receipts
are immutable. Adopt live processes; resume only exact valid outputs after exit.
Failed stages remain evidence and require a separately versioned recovery.
The WORKER_PROMPT.md instructs future rounds to continue this functional branch
alongside area work after interactive ownership is RELEASED.

The supervisor's opt4_recovery_goal_gate.py requires actual 21-card target
events, atomic result/complete files and exact hardware/performance identity.
Neither fault-free performance nor the component tests end full recovery work.
Native remains paused. Only 0000:21:00.0 / 21770433G02LA may be used by the
existing certified runtime service; no e2/global FPGA/driver operation here.
