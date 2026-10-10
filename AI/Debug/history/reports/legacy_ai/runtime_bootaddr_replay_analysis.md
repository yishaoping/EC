# Runtime BootAddr replay loop

## Conclusion

The run ending at FST time `1020981` is not stuck in the checker result
protocol. BOOM allocated packet sequences 1 through 4 and left all four
checker status bits busy, but every Rocket remained in R_ICSL nonchecking
state and produced no package result because none of them completed its first
BootROM exit into checker software.

The failure in this FST is the interaction between the intermediate
stale-write fix and the Rocket integer scoreboard:

```text
BootROM 0x10098: li a0, 0x4000
  -> 0x1009c: ld a0, 0(a0) requests BootAddrReg
  -> uncached response is not available in the WB slot
  -> wb_dcache_miss = 1
  -> the intermediate source makes wb_valid = 0 to prevent stale
     wb_reg_wdata from writing a0 (the write suppression is required)
  -> wb_wen = 0 also prevents the original sboard.set for a0 (bug)
  -> 0x100a0: csrw mepc, a0 observes no dependency
  -> CSR receives the old a0 value 0x4000
  -> 0x100b8: mret jumps to 0x4000 instead of 0x80000000
  -> instruction access fault: mcause=1, mtval=mepc=0x4000
  -> mtvec=0x10000 returns to BootROM _start
  -> all four checkers repeat the loop indefinitely
  -> no checker reaches checker() at 0x80001708
  -> r_ini() still prints "Initialisation is completed" unconditionally
  -> before ownership exists, GHM's owned-checker AND contributes 0x7 for
     every unowned checker, so ght_get_initialisation() also passes vacuously
  -> BOOM starts monitoring and allocates packet sequences 1 through 4
  -> no funct=0x60 COPY command and no R_ICSL start
  -> BOOM ic_status[1:4] can never be released
```

`RocketCore.scala` now preserves the original `wb_valid` retire/trace
semantics and blocks only `wb_wen` while `wb_dcache_miss` is asserted. The
same miss independently sets the integer or floating-point scoreboard, so a
consumer cannot read the old destination value. The eventual replay response
writes the real data through the existing `ll_wen` path and clears the
dependency.

## Final waveform evidence

At FST time `1020981`:

- `subsystem_pbus.bootAddrReg = 0x80000000`.
- BOOM `packet_seq_counter = 4`, and `ic_status[1:4] = 1`.
- Checker packet sequence registers are 1, 2, 3, and 4, respectively.
- All four `package_check_active = 0`; R_ICSL state is nonchecking.
- Checker PCs cycle through `0x10000..0x100b8`, briefly execute
  `0x4000/0x4002/0x4004`, and return to `0x10000`.
- Every checker has `reg_mtvec=0x10000`, `reg_mepc=0x4000`,
  `reg_mcause=1`, and `reg_mtval=0x4000`.
- The first repeated `_start` appears at times 1165, 1193, 1221, and 1289
  for checker harts 1 through 4; this precedes all packet allocations.

The generated BootROM image is still the old 192-byte image. Its relevant
instructions are `ld a0,0(a0)` at `0x1009c`, `csrw mepc,a0` at `0x100a0`,
and `mret` at `0x100b8`. The separate BootROM source edit has not entered this
image and is not what makes this run reach or fail the runtime path.

The initialization query's owner-based empty-AND behavior explains why the
BOOM software log advances despite all checker software being absent. It is
not changed in this fix: once the load dependency is restored, all four
Rocket harts execute their existing checker initialization before BOOM's long
configuration sequence finishes. Keeping that protocol unchanged preserves
the current multi-big-core ownership semantics.

## Reusable trace

Print the transition window with:

```sh
Debug/trace_runtime_bootaddr_replay.sh
```

Print a final snapshot for any selected signals with:

```sh
FST_TRACE_FINAL=1 Debug/fst_signal_trace test.vcd 2 1 '<signal-regex>'
```

The reversed time range suppresses normal transition output; the optional
final-summary mode still reports the last value of every selected signal.
