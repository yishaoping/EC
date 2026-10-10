# GuardianCouncil / BOOM-Rocket Protocol Audit

This note records the static audit of the worktree at 2026-08-15. It uses the
checked-in Rocket/BOOM sources and the existing waveform/log; it does not run a
simulation or generate RTL.

The Scala/Chisel source compiles with Java 17 using
`sbt -batch 'project chipyard' compile`; this check does not elaborate a target
or update `generated-src`.

## Observed failure chain

The first failing run reaches the BootROM load on each Rocket checker. The
relevant sequence is:

1. A checker executes the BootROM load of the BOOM entry address.
2. `wb_dcache_miss` is asserted and the load destination must be marked busy
   until `ll_wen` receives the response.
3. The current `Scoreboard.clearAll(icsl_start_accepted)` is implemented as an
   unconditional `update(en, 0.U)`. Because `Scoreboard.update` uses the final
   `_next` value when any earlier update enabled the register, the generated
   priority is effectively `if (wb_miss || copy_start) scoreboard := 0`, even
   when `copy_start` is false. The dependency is therefore lost.
4. The following `csrw mepc,a0` observes the stale `a0=0x4000` instead of the
   outstanding load value `0x80000000`, then `mret` jumps to `0x4000`.
5. The instruction access faults and the checker loops through the trap vector.
   No checker reaches COPY/R_ICSL, so no package result can ever release BOOM.

The same sequence is visible for checker harts 1--4; the failure is not
hart-specific.

## Signal contract

| Stage | Producer | Signal/field | Consumer | Contract |
|---|---|---|---|---|
| Package allocation | BOOM `R_IC` | `packet_alloc_valid`, `packet_alloc_seq` | BOOM DCache | One monotonically increasing non-zero sequence per accepted CPS. |
| Segment attribution | BOOM `R_IC` | `checker_segment_id` | GHM | The target checker keeps the CPS sequence until result release. |
| Data CDC | GHM | `valid + seq + 2*136-bit packet` | Rocket checker | Dequeue only the oldest sequence shared with the ARF/CSR stream. |
| ARF/CSR CDC | GHM | `valid + seq + ARF payload` | Rocket checker | Routing metadata is consumed in GHM; sequence is not truncated. |
| Checker execution | Rocket `R_ICSL`/RSUSL/CSR | LSL empty, ARF complete, CSR required/complete | RocketCore package tracker | These are independent completion facts; no single one is the package tail. |
| Result CDC | Rocket checker | `valid + seq + PASS/FAIL/CANCELLED` | GHM then BOOM | The result is held until enqueue and released only on BOOM-domain dequeue. |
| BOOM release | GHM | `clear_ic_status_tomain` | BOOM `R_IC` | Exactly one pulse per dequeued sequenced result. |
| Dirty writeback stats | BOOM DCache | first accepted C beat and line attribution | traffic counters | Data-bearing C messages are dirty writebacks; attribution is sampled from the line, not current checker state. |

## Classification

### Must remain for the requested feature

- Packet sequence constants and fixed counter indices.
- Sequence propagation through R_IC, GHM packet/ARF CDC, RocketTile, RocketCore,
  BOOM LSU/MSHR/DCache, and result CDC.
- Package completion tracking and result status encoding.
- DCache line attribution and first C-beat dirty-writeback accounting.
- START/STOP/RESET counter plumbing and the 35-entry software readback vector.

### Compatibility changes that need to be retained but constrained

- The GHM producer-empty indication must be a synchronized level; a pulse can
  be missed by a checker clock and a level can otherwise fill the control FIFO.
- Result release must not be replaced by the old unordered clear pulse; the
  sequenced result is the ownership point for BOOM release.
- ARF mismatch detection must report the final compared entry without changing
  the legacy mismatch FIFO protocol.
- CSR shadow state must be initialized and must not be cleared merely by entering
  checker mode, otherwise CSR post-check never starts.

### Unrelated changes to restore to the baseline design

- Rocket `wb_wen` and scoreboard behavior, except for the required result and
  sequence plumbing. In particular, `Scoreboard.clearAll` must not be used as a
  normal combinational update when its enable is false.
- COPY acceptance/waiting logic that introduces a second start handshake and
  stalls the whole Rocket pipeline. The original one-cycle `arf_paste_reg` and
  `icsl_run` contract is sufficient once scoreboard state is not corrupted.
- R_IC scheduler availability gates that are not needed to carry a packet
  sequence and can prevent the original scheduler FSM from advancing.
- Extra control-path changes that reinterpret a level as a completion pulse.

## Deadlock checks

1. A checker result must remain valid while its CDC enqueue is not ready.
2. BOOM `ic_status` must clear only after that result is dequeued in BOOM's
   clock domain; an early local reset must not release the slot.
3. A failed/cancelled result is a terminal diagnostic state, not a reason to
   leave an allocated bitmap entry permanently pending without reporting it.
4. The package tail must not depend on a one-cycle empty pulse crossing CDC.
5. All checker harts use the same sequence slice `(hartId - NUM_BIG_CORES)`;
   no special case may be applied only to hart1.
6. Normal and privileged `R_ICSL` postchecking use the same latched
   `if_check_completed` predicate. A completion arriving before postchecking is
   retained, while a pulse arriving after reset is not inherited by a later
   package.

## Unified package tail

Normal COPY and privileged checking keep independent start paths, but use the
same terminal predicate:

```text
full_check_complete = package_check_active
                   && packet_ingress_drained
                   && lsl_empty
                   && arf_check_complete
                   && (!csr_check_required || csr_check_complete)
```

This single event determines PASS/FAIL and enqueues the sequenced result used by
the BOOM completion bitmap. Both `fsm_postchecking` states wait for the same
latched event before returning. `R_ICSL.clear_ic_status` is therefore local
cleanup/release ordering only; it does not define package completion.

The result queue preserves the complete result and package sequence until the
local cleanup is visible. GHM dequeues the result in the BOOM clock domain and
uses the same edge for `checker_results_out` and `clear_ic_status_tomain`, so
the bitmap update and BOOM ownership release refer to the same package.

## Source versus generated collateral

The checked-in source and the RTL used by the saved waveform are currently
different revisions.  In particular, the generated `gen-collateral/Rocket.sv`
still contains the intermediate `icsl_start_pending`/`icsl_start_valid` path,
clears the scoreboard when `icsl_start_accepted` is asserted, and masks
`wb_wen` with `!wb_dcache_miss`.  Those signals are absent from the current
`RocketCore.scala`; the current source uses the baseline one-cycle
`arf_paste_reg` path, baseline `wb_wen`, and only sets/clears the scoreboard at
the original load-response points.  Therefore the assertion and the 100-MiB
FST/VCD are evidence for the stale generated revision, not a validation of the
current source tree.

The same warning applies to the generated `BoomCore.sv`: its assertion line
number and signal names describe the old elaborated collateral.  No generated
RTL has been changed in this audit, per the request to avoid hardware
generation.  A future validation run must regenerate collateral before the
new packet-result and sequence wiring can be observed in a waveform.

## Static statistics risks

The result bitmap deliberately advances `safePacketWatermark` only across
PASS results.  FAIL/CANCELLED results are counted and invalidate the latency
window, but they do not advance the PASS watermark; subsequent packages then
remain pending by design.  Software must treat `stats_valid == 0` or a
non-zero `pending` count as an invalid measurement, rather than interpreting
the partial latency sum as a completed sample.  This is a measurement-policy
choice, not a BOOM checker-release deadlock: BOOM `ic_status` is released by
the result CDC dequeue independently of the statistics bitmap.

## 会话控制 CDC 协议

旧实现把 `ghm_status` 放入 BOOM 到 Rocket 的 22 位控制 FIFO，并把
`deq.fire` 当作 checker 完成通知。该值只存在一个 Rocket 时钟周期；保存的
波形中 hart1 恰好取到 `0x02`，hart2--4 在该周期未取到，所以软件轮询
`ghe_checkght_status()` 时会永久等待。该路径没有交付确认，也不能把 FIFO
出队事件作为跨时钟的完成状态。

当前源代码保留软件和 RoCC ABI：`0x31` 仍表示 START，`0x32` 仍表示
FINISH，`ghe_go()`、`ghe_initailised()`、`ghe_checkght_status()` 与
`ghe_release()` 都不需要改动。GHM 另外为每个 checker 使用深度为 4 的
`AsyncQueue` 传输以下控制消息：

```text
version[1:0] | type[1:0] | epoch[15:0] | status[4:0]
```

源端在 BOOM 时钟域把 START 或 FINISH 保存在 pending 寄存器中，直至
`enq.fire`，故 checker 时钟停止、同步延迟或 FIFO 反压不会吞掉边界消息。
接收端只在 `deq.fire` 更新本地状态；只有 epoch 与已经收到的 START 相同的
FINISH 才有效。START 会清除上一次的完成位。收到有效 FINISH 后，checker
等待本时钟域的 packet/ARF CDC 均为空且同步后的 BOOM producer-empty 为真，
然后将完成位保持为 `0x02`；下一轮 START 前则为 `0x00`。GHE 同样在收到
`0x00` 时清除其状态寄存器，避免软件读到陈旧完成结果。

这个完成位仅用于与既有软件 ABI 兼容的统计等待。BOOM 的 checker 资源释放
仍严格由带 sequence 的结果 CDC 在 BOOM 域 `deq.fire` 触发，不能用
`ghe_release()` 或会话 FINISH 替代，否则会破坏包结果与资源所有权的顺序。

保存的波形和生成的 RTL 属于旧实现，只能说明旧脉冲丢失问题，不能验证这里的
新源代码。本文档与本次改动都没有运行仿真或硬件生成；后续验证必须使用重新
生成且与当前 Scala 源一致的 RTL。
