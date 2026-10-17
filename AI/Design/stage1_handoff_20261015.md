# Stage 1 Handoff

## 1. 当前总路线

### Stage 1 — Base L1 correctness
状态：IN PROGRESS

目标：保证普通 cache 数据路径和 architectural effect 正确，先关闭基础 correctness 问题。

剩余核心任务：

1. 修复 AMO.W old-value sign extension。
2. 解释并关闭当前 run 中 main/checker cacheable 统计差异：
   - Store difference = 707
   - Load difference = 1715
3. 定向验证并关闭 clear / S1 / S2 / refill race。
4. 证明：
   `effect token → physical effect → terminal response → STQ release`
   exactly-once。
5. 确认仿真结束时残留的 `s_drain_rpq / replay_inflight` 是否只是 termination tail，而不是未完成 architectural transaction。

Stage 1 未完成前不要进入 Stage 2。

### Stage 2 — L1 preservation
实现：

- 同 package repeated speculative writes 可直接覆盖；
- 跨 package speculative overwrite 必须等待旧 package validation；
- safe line 被新的 speculative package 覆盖前必须先 push 到 L2；
- 建立绑定 ImageKey/content_seq/generation 的 preservation 状态；
- normal LSU、replay、SC、AMO 等不能绕过统一 overwrite gate。

### Stage 3 — L2 predecessor preservation
实现：

- 区分 same-address predecessor 与 set replacement victim；
- speculative version 进入 L2 前必须保存原最近 safe predecessor；
- safe predecessor 必须真正下推 outer level 并等待 completion/ACK；
- speculative resident 不允许直接写入 DRAM；
- L2–DRAM barrier 等待 validation 后再继续。

### Stage 4 — Recovery + end-to-end validation
实现 rollback/recovery，并验证完整 version/preservation 生命周期和系统级 invariants。

---

## 2. 最新仿真

当前已经跑通完整仿真，输出：

```text
/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd
/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log
```

注意：

`test.out` 中 `*** PASSED ***` 只说明 simulator exit code 正常。

功能统计最终仍为 FAIL。

BFS 本身：

```text
verified=1
332 packages PASS
```

但这不能证明 cache correctness 已通过。

---

## 3. 当前明确失败

### Store

```text
boom_arch    61270
boom_strict  61270
checker_sum  60563
difference   707
```

### Load

```text
boom_arch    96749
boom_strict  96749
checker_sum  95034
difference   1715
```

uncacheable traffic 一致：

```text
store uncache: 49 == 49
load  uncache: 297 == 297
```

因此差异全部来自 cacheable traffic。

当前尚未确定差异属于：

- 真正 lost/duplicate architectural access；
- replay/duplicate accounting；
- package identity；
- retirement/statistics lifecycle；
- 其他 instrumentation semantics。

必须基于当前 run 重新做 transaction/effect scoreboard，不能直接复用旧 run 的结论。

---

## 4. 已确认的 Stage 1 硬件 bug

AMO.W old-value 返回存在明确 sign-extension 错误。

位置：

```text
chipyard/generators/boom/src/main/scala/lsu/dcache.scala
```

此前定位约在 line 1855：

```scala
s3_result := Mux(duplicate, appliedEffectResult(set)(way),
  Mux(s2_sc, s2_sc_fail.asUInt, s2_data_word(0)))
```

AMO physical write 使用 `amoalu.io.out`，但返回 old value 直接使用 `s2_data_word(0)`。

AMO.W 应将 32-bit old value sign-extend 至 XLEN。

当前波形中观察：

```text
92 AMO grants
40 AMO.W return-value errors
```

例如：

```text
actual:   0x00000000ffffffff
expected: 0xffffffffffffffff
```

修复原则：

- 只修 old-value response 的宽度/符号扩展；
- physical write 仍使用 `amoalu.io.out`；
- replay/duplicate completion 必须使用相同修正后的 architectural result。

---

## 5. 已确认的 Stage 1 正向证据

### Row provenance

MSHR row capture 已限制在真正 install read：

- `state == s_commit_line`
- `installStarted`
- valid GrantData/install condition

当前 run 中约：

```text
30,596 row capture/refill pairs
```

没有发现 provenance mismatch。

但这只能证明当前 workload 中未观察到 mismatch，不能单独关闭 clear/S1/S2/refill race。

### Replay

replay entry 当前保持到 terminal result，而不是 issue 时立即释放。

主要实现位于：

```text
chipyard/generators/boom/src/main/scala/lsu/mshrs.scala
```

此前约在 line 504。

### L2 barrier

L2→DRAM speculative barrier 已经实际参与调度。

相关代码：

```text
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala
```

但现有 barrier 只能阻止 tracked speculative candidate 直接下推，不能替代 Stage 3 的 predecessor preservation。

---

## 6. Stage 1 仍未关闭的问题

### clear / S1 / S2 / refill race

当前 `crossPackageMetaClear.fire` 会立即：

- 清 pending；
- 更新 epoch；
- 更新 imageValid。

相关实现：

```text
chipyard/generators/boom/src/main/scala/lsu/dcache.scala
```

此前约在 line 1422。

仍需验证：

```text
clear
→ 已进入 S1/S2 的旧 lookup/hit
→ store/effect
→ refill/install
```

是否可能产生 stale metadata/data 使用或覆盖。

必须有 directed evidence，不能因为当前 VCD 没看到 mismatch 就标 PASS。

### effect / terminal closure

需要为普通 Store、AMO、成功/失败 SC 建立严格 scoreboard：

```text
effect token
→ physical effect
→ terminal response
→ STQ free
```

要求：

- no lost effect
- no duplicate physical effect
- exactly one terminal completion
- exactly one STQ release

### Exit quiescence

仿真结束时曾观察：

```text
MSHR state = s_drain_rpq
replay_inflight = 1
```

可能只是 tohost/termination tail，但尚未严格证明。

---

## 7. 目标协议 correctness contract

### L1 Store

同一个 speculation package 对同一 line 的多次 speculative Store 可以直接覆盖。

跨 package 时：

如果旧 line 仍 speculative：

```text
block new Store
→ wait validation watermark
→ old line becomes safe
→ push latest safe value to L2
→ confirm preservation
→ allow new speculative overwrite
```

如果旧 line 已 safe：

```text
push safe line to L2
→ confirm preservation
→ allow new speculative overwrite
```

因此所有从 safe image 到新 speculative ownership 的转换都必须遵守：

```text
safe-old push-before-overwrite
```

### L1 replacement

safe victim：

```text
normal writeback to L2
```

speculative victim：

必须先保证 L2 中最近 safe predecessor 不会被覆盖丢失。

### L2

例如：

```text
L1: Q speculative
L2: P safe
DRAM: O safe
```

Q 进入 L2 前：

```text
P → DRAM
wait completion/ACK
Q → L2
```

如果 L2 resident P 仍 speculative：

```text
barrier
→ wait P validation
→ P becomes safe
→ P → DRAM
→ ACK
→ Q → L2
```

speculative version 绝不能直接成为 DRAM-visible value。

系统核心 invariant：

```text
任何 speculative image 的下面，始终存在其最近 safe predecessor。
```

---

## 8. 当前尚未实现的后续协议功能

### L1 safe-old preservation

当前跨包逻辑主要只在：

```text
old_packet_seq > safePacketWatermark
```

时等待。

旧 line 已 safe 时，当前没有完整的 safe-old push-before-overwrite。

也没有完成绑定完整：

```text
content_seq + generation
```

的 `lower_preserved` 证书语义。

### L2 predecessor preservation

L2 Directory 当前主要只有类似：

```text
packetSeq
packetTracked
```

不能充分区分：

```text
same-address predecessor
vs
set replacement victim
```

因此 Stage 3 仍需要独立实现。

---

## 9. Stage 1 Exit Criteria

只有下面条件都满足，才能宣布 Stage 1 DONE：

1. AMO.W old-value 正确。
2. 707/1715 差异被完全解释；若为硬件 bug 则修复。
3. clear/S1/S2/refill race 有 directed closure。
4. row provenance 无错误。
5. Store/SC/AMO effect→terminal→STQ release exactly-once。
6. 无 duplicate/lost physical effect。
7. 仿真结束时 architectural outstanding transaction 可完全解释。

---

## 10. 新对话的第一任务

不要重新做全系统 roadmap。

直接继续 Stage 1。

优先任务：

```text
建立当前 run 的 transaction/effect scoreboard，
解释 store 707 / load 1715 差异，
并同步验证 Store/SC/AMO 的
effect → terminal → STQ release 映射。
```

在这一步完成前，不进入 Stage 2，也不要继续做 Verilator 性能优化或 L2 preservation 实现。