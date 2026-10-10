# BOOM checker watchdog: signal-chain analysis

> Version boundary: this document describes an earlier generated RTL/FST
> revision whose failure was in the BootROM/Scoreboard path.  For the saved
> `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd` and
> the `assert__assert_22` investigation in the current task, use
> [`watchdog_signal_chain.md`](watchdog_signal_chain.md) and
> [`trace_watchdog_chain.sh`](trace_watchdog_chain.sh).  The two documents
> must not be merged into one causal chain.

> Latest-run note: the `wb_dcache_miss` writeback mask described below fixed
> the stale architectural write but initially removed the corresponding
> scoreboard set. The resulting `BootAddrReg` dependency failure and its
> completed fix are documented in `Debug/runtime_bootaddr_replay_analysis.md`.

## Conclusion

The assertion at `BoomCore.sv:6736` is generated from
`boom/src/main/scala/exu/core.scala:2040`:

```scala
assert(!little_status1(checkerHangWatchdogBit), "little core 1 has hung")
```

`little_status1` is cleared only while `R_IC.io.ic_status(1)` is low. The
watchdog bit therefore means that BOOM checker 1 has remained busy for more
than `1 << 20` BOOM cycles; it is not itself the source of the hang.

The observed chain has two coupled failures:

```text
CustomBootPin
  -> BootAddrReg = 0x80000000
  -> CLINT msip[0] = 1
  -> BOOM hart 0 enters BootROM _start
  -> old BootROM _start writes msip[1] while msip[0] is still 1
  -> Rocket hart 1 enters _start and branches to boot_core
  -> boot_core waits for msip[0] == 0
  -> hart 0 interrupt_loop waits for msip[1] == 0
  -> both sides issue uncached CLINT loads
  -> DCache replay response sets t0/a3, but the WB slot still writes a stale
     MEM-stage value while wb_dcache_miss is true
  -> a polling branch can therefore use a stale nonzero value (or exit early)
  -> the trace's hart 0 reaches 0x10094 by accident, while checker 1 remains
     at 0x10084/0x10088
  -> checker.c is never reached, so COPY/funct=0x60 is never issued
  -> GHE arf_copy_out and R_ICSL start remain low
  -> BOOM ic_status(1) remains high
  -> checkerHangWatchdogBit assertion fires
```

Both sides are fixed in source. `testchipip/bootrom/bootrom.S` now clears
`msip[0]` immediately after hart 0 enters `_start`, before sending secondary
wakeups. `rocket/RocketCore.scala` now excludes `wb_dcache_miss` from the
integer register write enable while retaining the miss in the scoreboard, so
a load without a DCache response can neither overwrite the register file with
stale MEM-stage data nor let a dependent instruction read the old value. The
eventual DCache response/replay remains the only writeback source for that
load. These changes leave the checker protocol, RoCC routing, retire/trace
semantics, and watchdog intact.

## Waveform evidence

From `test.vcd` (an FST file with a `.vcd` suffix):

| Time | Signal | Observation |
| ---: | --- | --- |
| 1 | `subsystem_pbus.bootAddrReg` | becomes `0x80000000` |
| 251 | `clint.ipi_0` | becomes `1` |
| 567, 639, 711, 781 | `clint.ipi_1..4` | hart 0 sends secondary wakeups |
| 681 onward | checker 1 `mem_reg_pc` | executes BootROM `0x10000` then loops at `0x10084/0x10088` (`boot_core`) |
| 841, 881 | checker 1 DCache response | `data_raw=1`, `replay=1`; the load is not architecturally complete |
| 901 | `clint.ipi_0` | becomes `0` only after the big hart's polling path reaches `0x10094` |
| 925 | checker 1 DCache response | `data_raw=0`, `replay=1`, and `ll_wen=1` writes `t0=0` |
| 933 | checker 1 writeback | `wb_dcache_miss=1` but `wb_valid=1`; stale `wb_reg_wdata` overwrites `t0`, so polling continues |
| 40669 | BOOM checker 1 status | busy state starts watchdog accounting |
| 1068000 | BOOM | `little_status1[20]` assertion fires |

In the same interval checker 1 has no `io_rocc_cmd_valid`, no
`cmdRouter.io_in_valid`, no `ghe_io_cmd_valid`, and no `ghe_io_arf_copy_out`.
Those are expected consequences of never leaving BootROM, not an opcode-route
failure. The `RoccCommandRouter` still matches `CUSTOM_1` (`opcode 0x2b`), and
GHE still maps `funct=0x60` to `arf_copy_out`.

For the replay/writeback portion, include these signals in a trace selection:
`core.(rf_wen|rf_waddr|rf_wdata|wb_valid|wb_wen|wb_dcache_miss|dmem_resp_valid|dmem_resp_replay|ll_wen|ll_waddr|replay_wb)`.

## Reusable trace

Build the existing reader once (this only reads the waveform):

```sh
cc -O2 -DFST_CONFIG_INCLUDE='"fst_config.h"' \
  -I/usr/local/share/verilator/include/gtkwave \
  Debug/fst_signal_trace.c \
  /usr/local/share/verilator/include/gtkwave/fstapi.c \
  /usr/local/share/verilator/include/gtkwave/fastlz.c \
  /usr/local/share/verilator/include/gtkwave/lz4.c \
  -lz -o Debug/fst_signal_trace
```

Then run:

```sh
Debug/trace_boot_deadlock.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  0 1200
```

Values are printed as binary by `fst_signal_trace`; for a quick conversion of
one value use `echo 'ibase=2;<bits>' | bc`.

## Scope note

The checked-in/generated BootROM image predates the source edit because this
debug session intentionally does not run hardware generation. Regenerating
the normal Chipyard collateral is required before a future run can exercise
the new instruction sequence and the RocketCore change. No generated Verilog,
VCD/FST, assertion, or checker protocol was changed here.

The PC values in the waveform table describe that old image. The inserted
`sw zero, 0(a1)` occupies `0x10010`, so every later BootROM instruction moves
by four bytes in a regenerated image; decode future traces against the new
`bootrom.rv64.dump`/`bootrom.rv32.dump`, not these old literal PCs.
