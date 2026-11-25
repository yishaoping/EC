# ARF CDC 满队列阻断 DATA 起始标记

2026-11-25。原复现使用 2026-11-24 的整核模型和 EC-Test ELF。FST 时间轴每个 BOOM 周期两点，时钟高电平为奇数点。以下时间均为 FST 点。

| 时间 | 实际事件 |
|---:|---|
| 198101–198113 | IOMSHR 受理 Seq 15 的 MSIP 写入，TL A 发射后 BOOM 看到 MSIP，TL D 返回并建立 Seq 15 journal。IOMSHR 返回 idle，journal 将中断保持到该效果通过验证。 |
| 200397 | R_IC 启动 Seq 15 ECP 和 Seq 16 CPS 的同一轮 R_RSU merge，目的 hart 分别为 3 和 4。 |
| 200421 | hart 4 的 Seq 16 ARF 首拍到达队头，DATA CDC 尚空，ARF dequeue 等待 DATA 起始标记。 |
| 200437 | hart 4 的 ARF CDC 满，R_RSU 停在索引 8。合并后的 `bigcore_hang` 同时使 GH_BUF 停止 dequeue。 |
| 200439–487837 | hart 3 的 DATA CDC 已有入队空间。GH_BUF 仍有 Seq 15 的数据，Seq 16 空包起始标记的生产端空条件无法到达。Seq 15 的 ECP 和 END 未完成，连续安全水位停在 Seq 14。 |
| 487837 | hart 3 的 `package_progress_timeout` 触发，发布 Seq 15 CANCELLED。 |
| 487969–488087 | BOOM 接收取消，安装 EVT，恢复控制进入 drain。Cache quiesced 重新变真，R_RSU 仍持有被反压的 merge，故 `snapshot_rsu_prev` 保持，无法进入 restore。 |
| 约 724000 | BOOM watchdog 报告 `Pipeline has hung`。 |

故障链从 GHM 的 `cdc_busy || arfs_cdc_busy` 开始。BoomTile 把同一聚合值用于 GH_BUF 和 R_RSU，形成 `ARF 满 → GH_BUF 不排空 → DATA 起始标记不产生 → ARF 不出队`。设备 journal 正常执行此前 P4-10 的保持规则。Seq 15 取消及 watchdog 是这段传输死锁的后续现象。此前 P4-13 的 C/E 通道依赖与此处不同。组合场景由上一轮新 EC-Test 发现，旧 P4-10/P4-13/P5-10 验收记录对应各自的输入和签名。

修复将现有 DATA busy 和 ARF busy 作为同一桥接信号的低、高半部分。GH_BUF 只看 DATA busy，R_RSU 只看 ARF busy，BOOM 的退休控制继续合并两者。两路各自尊重原 CDC 就绪条件。RocketTile 保留原有合并逻辑用于其已有的控制输入。新增硬件为每 checker 一条源域组合线，BOOM 端增加独立掩码归约。队列深度、状态机及寄存器数量保持原配置。Low FIRRTL 组合环检查覆盖实际整核连接。物理布局和 STA 需要独立签核。

仅拆分 busy 后，旧 Checker 的 LSL 仍可能先满。此时它等待 ECP，而新 Checker 等待全局 GH_BUF 排空才会得到 DATA 起始标记。修复让 GHM 在观察到指向新 Checker 的 CPS 传输时，用现有的逐 Checker 等待计数锁存该序号的起始标记资格。真实 DATA 仍具有发送优先权，END 继续要求该序号的生产端 seal。组件测试分别覆盖 ARF CDC 满和全局 GH_BUF 持续非空两种条件。整核随后得到 Seq 15、16 PASS 和真实 MSIP handler clear、xRET。 [第二处依赖与整核结果](../../TMP/ec-test-20261125/cps-anchor/v1Config/ec-fst/run.log) · [传输组件测试](../../TMP/ec-test-20261125/cps-anchor/components/seq_transport.retry-run.log)

## 后续暴露的问题

### 普通 CPS 缺少 scratch 初值

正常配置 Seq 34 的 BOOM CPS 从 `0x8000092c` 开始。BOOM 在第二轮执行 `csrrw a0,sscratch,a5` 时读到 1，hart 4 普通包在 304437 读到物理 CSR 本地值 0。随后 304485 的 `xor a0,a0,s8` 与 304521 的 `or s6,s6,a5` 将该差异带至 x10 和 x22。307025 与 307073 的 ECP 比较分别发现两处不等。原组件测试用完整 CSR frame 预装了初值并检查写后 shadow，未覆盖普通帧以及写前读值。本次保留现有普通包和特权包执行模式，普通 CPS 在 PC/FCSR 前用一个 128 位 beat 发送两项 scratch 并复用既有保存寄存器。普通和特权 replay 均从本包 shadow 取旧值，管理态 scratch 的物理读写照常进行。无新增 CSR bank 或队列。 [写回波形](../../TMP/ec-test-20261125/cps-anchor/seq34-execution.trace) · [CSR 波形](../../TMP/ec-test-20261125/cps-anchor/seq34-cps-shadow.trace) · [ECP 波形](../../TMP/ec-test-20261125/cps-anchor/seq34-registers.trace) · [CSR 组件结果](../../TMP/ec-test-20261125/cold-owner/csr-shadow/run.log)

### 回滚后冷地址的查询结果被下一次 offer 抢占

在同一候选中，Seq 51 只收到 live count 67，未收到 END。BOOM 停在 `0x8000092c` 附近的 load。LSU 每三个周期轮转三个候选请求。在 353931，L1 接管对 `0x81020000` 的查询，354155 查询结果进入 `recoveryMiss`。此时接口上恰好是另一条冷地址 `0x81000000`。354157 新地址接管查询槽，原 owner 正好在同拍重新 offer，未获得 ready。354379、354603 等边界重复该过程。查询组件持续有握手，实际 cache ingress 没有前进，之后 Checker 超时取消。 [LSU 和 History 握手波形](../../TMP/ec-test-20261125/cps-anchor/seq51-lookup-rotation.trace) · [BOOM 边界追踪](../../TMP/ec-test-20261125/cps-anchor/seq51-master.trace)

当前候选保留单个冷查询槽，跟踪来自 LSU 的已有 ROB index、branch mask 和有序请求类别。查询结果保留给活 owner，允许更老请求或有序请求接管。分支取消、异常及 LSU 的真实转发完成释放失效 owner。活结果与新同地址 offer 可共享候选，普通已映射请求继续由原接口接收。新状态限于这一个查询槽的窄控制字段。History 查询顺序、版本键和提交路径仍由既有模块定义。带真实 ROB 年龄的 Hierarchy 回归分别验证更老请求接管和原 owner 在更年轻请求轮转时仍能完成。 [L1 冷查询](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:861) · [Hierarchy 回归](../../TMP/ec-test-20261125/lookup-retirement/hierarchy-retry/run.log)

### 正常执行从 DRAM 回填已迁入 History 的 Pending Current

修复 scratch 后，EC-Test 正常配置在 324338 周期退出 1。所有 Checker 都发出 PASS，软件最终校验依然发现 `memory.bytes` 错误。地址 `0x81010000` 的 Seq 48 字写入先提交 13，然后被 L1 写回，首拍为 `a5a5a5a500000001_000000000000000d`。Seq 48 尚未安全，L2 将该 Current 保存在 History。紧跟的字节写重取同一行。FST 366239 的 GrantData 首拍从 DRAM 带回 `a5a5a5a500000001_0000000000000009`，版本键为 BASE。FST 366285 的 S3 在这个旧基线上正确写入 byte 2 的 `0x03`，却重新创建与已迁移副本相同的 Seq 48／serial 1。后来的 C 首拍为 `a5a5a5a500030001_0000000000000009`。最终软件读到 `a5a5a5a502000001`，期望 `a5a5a5a502030001`。

L2 miss 原本直接将外层 GrantData 安装到 bank。修复在主核 miss 的外层首拍复用已有 History 查询。命中时，bank 写入存活版本的字节，目录和内层 Grant 使用同一版本键。下一次同包写继承这个键并递增 serial。查询占用到外层 D 末拍，外层 D/E 仍按原事务终结。测试用同组替换把 Pending Current 迁出，再读回、字节更新并核对末端内存。旧 RTL 在 6185 周期返回旧值。首次修复在安装脏 Current 时触发原 `S_INVALID → S_TRUNK_CD` 断言，该断言假定 Acquire 缺失只能从外层装入干净行。现仅在已锁存有效 History 版本键时允许该转换。 [字节写 RTL 日志](../../TMP/ec-test-20261125/cold-owner/v1Config/memory-byte/run.log) · [对应 TL 波形](../../TMP/ec-test-20261125/cold-owner/byte-tilelink.trace) · [旧值反例](../../TMP/ec-test-20261125/lookup-retirement/hierarchy-retry/migrated-before.run.log) · [状态断言](../../TMP/ec-test-20261125/capacity-retry/components/hierarchy.run.log)

### 容量等待者在槽位恢复后仍等待自己的包退休

25 MHz EC-Test 在 Seq 4 达到 History 64/64。BOOM 在 `0x8000039c`（`amoadd.w.aq`）等缓存 miss，L2 在 tick 100219 左右把同组请求停放到 per-source wait 槽，等待 Seq 4，彼时安全水位为 2。Seq 3 PASS 后已有 27 个空槽，wait 槽仍只以 Seq 4 SAFE 为唤醒条件。后续 barrier 要求封口 Seq 4，ROB 中这个未完成的 AMO 需要该 miss 才能继续退休。修复给既有 wait 记录编码容量停放原因，容量停放也可由逃生槽重新可用唤醒。peer 和 trusted 等待继续使用其安全条件。定向回归将较老的其他行推进至安全水位 5，保留 Seq 200 的 victim 未验证。旧 RTL 等待超时，修复版重新发出原请求并收到 Grant，DRAM 在验证 Seq 200 前仍为旧值。 [L2 与 ROB trace](../../TMP/ec-test-20261125/cps-anchor/PalimpsestSlowCheckerPressureTestConfig/ec-pressure-trace/run.log) · [实际容量观察](../../TMP/ec-test-20261125/cps-anchor/PalimpsestSlowCheckerPressureTestConfig/ec-pressure/irq.log) · [旧版组件结果](../../TMP/ec-test-20261125/dirty-refill/pressure-capacity-history-refill/run.log) · [修复后组件结果](../../TMP/ec-test-20261125/dirty-refill/pressure-capacity-capacity-retry/run.log)

### 维护开始时 LSU 仍持有已提交 store

低阈值重基配置在第二次重基的 Seq 16 装入 EVT。LSU 已提交的 `0x814d0000` store 属于仍存活的 Seq 15，从 `0x3aaf0` 起反复发出同一 token `0x1f6a`。EVT 后冷查询完成，LSU 在 `0x3ac81` 把该 store 交给 L1。L1 MSHR 3 在 `0x3ac85` 接受本地 Acquire 并进入等 Grant，L2 同期在物理 sweep 中按 way 发送维护请求。Watchdog 时安全水位已到 16，L1 仍有一个 MSHR owner，LSU 未结束这次写入。

原维护入口只检查 L1 自身的排空状态和 Checker 收尾。FST 481443 的 `maintenanceLocalDrained` 为 1，481445 同时开始冷查询并置位 `maintenanceRequest`。481461 L2 `maintActive` 置位，关闭 A admission。481743 冷查询进入 `recoveryMiss`，L1 可接收 store，Acquire 进了既有跨域队列，等待 Grant 的 MSHR 挡住 L1 drain。修复复用 LSU 原有 `rollbackDrained`，让 DCache 发起维护和收集维护回执时使用同一项已提交前缀排空条件。新增一条本域组合连线。 [波形](../../TMP/ec-test-20261125/dirty-refill/PalimpsestSeqRebaseTestConfig/ec-rebase-fst/maintenance.trace:8) · [完整复现](../../TMP/ec-test-20261125/dirty-refill/PalimpsestSeqRebaseTestConfig/ec-rebase-verbose/run.log:760309) · [DCache 入口](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:1035) · [LSU 排空判据](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/lsu.scala:618) · [L2 A 门控](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:203)

### 回滚时跳过已完成项覆盖较老 store 的 NACK 回退

加入 LSU 排空条件后，低阈值重基组合运行通过前三次物理重基。第四次在恢复控制 `drain` 中停住，L1 无活跃 MSHR，L2 未进入维护。tick 505300，STQ 2 的已提交字节写 `0x8107000b` 发出。tick 505301 指针跳过已取消的 STQ 3。tick 505302，STQ 2 的 inflight 清零并留下 `done=0`，同拍指针继续从 STQ 4 走向 5。指针随后走到空槽 7，存活的 STQ 2 无法重试。现有 NACK 分支已判断其年龄并设置重试指针，但后写的回滚跳过分支覆盖该赋值。复用 `olderStoreNackForcesReplay` 赋予旧 NACK 优先级，与原 STORE_DONE 分支一致。改动为一项现有组合条件，无状态扩展。 [STQ 逐拍记录](../../TMP/ec-test-20261125/maintenance-drain/PalimpsestSeqRebaseTestConfig/ec-rebase-stq/run.log) · [LSU 条件](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/lsu.scala:2368)

`store-replay` 的完整运行通过第四次重基，六次物理 reset 的旧尾依次为 20、16、16、16、16、21。每次 reset 后的首个 Seq 1 都有 Checker PASS。程序完成最终内存、CSR、浮点、设备和计数器判据，689767 周期、602.823 秒、退出 0。软件读到 105 个 PASS，结束前硬件另发布 1 个 PASS。冻结的历史重基 ELF 同样通过严格计分，2085846 周期内有 23 次真实 reset 和 23 个新 Seq 1 PASS。 [组合计分](../../TMP/ec-test-20261125/store-replay/acceptance/ec-rebase.json) · [组合日志](../../TMP/ec-test-20261125/store-replay/PalimpsestSeqRebaseTestConfig/ec-rebase/run.log) · [历史重基计分](../../TMP/ec-test-20261125/store-replay/historical-rebase-driver.log)

## `store-replay` 阶段动态验收

工作区改动的 RTL 及 EC-Test ELF、dump 已与 `store-replay` 来源清单核对。下表耗时为各次完整运行的墙钟时间。 [哈希](../../TMP/ec-test-20261125/store-replay/acceptance/rtl-sha256.txt)

| 运行 | 周期 | 秒 | 结果 |
|---|---:|---:|---|
| v1Config 无波形 | 341064 | 291.41 | 退出 0，97 PASS、0 FAIL。 |
| v1Config FST | 341064 | 558.06 | 退出 0，同一软件结果。 |
| Fault8 | 431903 | 329.07 | 退出 0，123 PASS，唯一预期 FAIL 为 Seq 8。 |
| 12.5 MHz EC-Test | 1234316 | 993.248 | 退出 0，真实 History 64/64，重分配、回收、最终空表。 |

正常和 Fault8 的只读观测各得到四次物理 MSIP set/clear、四次精确 trap 与匹配 xRET、四次设备 AMO 和读回。历史 Fault18 设备回归各 16 轮通过，原故障效果到 journal 重放之间只有一次物理 TL A。Sv39 正常版有 16 次物理访问，Fault8 有 18 次，其中 2 次因回滚废弃，两种配置实际存活提交均为 16 次。 [正常与 Fault8 观测](../../TMP/ec-test-20261125/store-replay/acceptance/ec-observer.json) · [Fault18](../../TMP/ec-test-20261125/store-replay/acceptance/historical-io.log) · [Sv39](../../TMP/ec-test-20261125/store-replay/sv39-1t-driver.log)

生产组件回归七组均通过。Hierarchy 复现 Current 同组迁移、按版本回填、同 Seq 字节更新及二次驱逐，验证前外层内存为 `0xa1`，验证后为 `0x8877`。SeqTransport 填满 ARF CDC，再送 DATA 和 END，核对 ARF 出队、Seq 和载荷。CSR shadow 回归以同一版本的 CSR/RSU 来源覆盖普通 CPS、scratch W/S/C 和管理态隔离。 [最终组件](../../TMP/ec-test-20261125/store-replay/components/) · [CSR 组件](../../TMP/ec-test-20261125/cold-owner/csr-shadow/run.log)

现用 12.5 MHz EC-Test 在 tick 93127 实际填满 History，156838 重新分配，196573 有 48 个空槽且 Seq 3 推进，1234163 恢复 64 个空槽。冻结的 16 轮旧压力 ELF 在 25 MHz 软件通过，753709 周期、595.040 秒、退出 0。该次 Seq 1 END/count 为 16，峰值 42/64，原计分器要求 Seq 1 END/count 64，严格结果为 FAIL。 [现用压力计分](../../TMP/ec-test-20261125/store-replay/acceptance/12p5-ec-pressure.json) · [旧判据](../../TMP/ec-test-20261125/store-replay/acceptance/25mhz-frozen-strict.log)

## 满 History 暂存挡住无数据 ProbeAck

同一冻结 ELF 在 12.5 MHz 的 `store-replay` 模型中于 tick 588000 退出 1，断言为 `little core 3 has hung`。该断言统计 BOOM 持有的 Checker 槽位时长，在 Checker 本地 package timeout 前到达。下面的 tick 是仿真器的主时钟周期，Checker 每 16 个周期有一个上升沿。

| tick | 信号与事件 |
|---:|---|
| 371081 | 受跟踪的 Seq 12 `ProbeAckData`（`0x81170000`）已到末拍。History 64/64，完整行留在 `historyCLine`，`historyCPending=1`。 |
| 371259–371261 | 某个 Checker 的 `0x80039ec0` Acquire 占有 set `0x27b` 的普通 MSHR。它对旧行 `0x80049ec0` 发 Probe，等待 `w_rprobeacklast`。 |
| 371365 | `0x80049ec0` 的 opcode 4 无数据 `ProbeAck` 到达 `bufferedC` 队头，`CacheImage.valid=0`。`historyCPending` 令该项的 dequeue 始终为 0。 |
| 371936–371956 | hart 3 的本地 trap 在 `0x8000014a` 执行 `sd ra,8(sp)`。DCache 对 `0x80049ec8` 发出 Acquire 并 NACK 该指令令其重试。该 Acquire 到达 L2，被排入仍等 ProbeAck 的同组 MSHR。 |
| 372000 | 取指返回重试 PC `0x8000014a`。DCache 仍处于 `cached_grant_wait`，译码被 `dcache_blocked` 停住。 |
| 588000 | hart 3 的 Seq 11 无法从本地 trap 返回并完成，BOOM 的 owner 计数触发断言。 |

安全水位停在 10。Seq 11 需要先处理栈写才能生成 PASS。满表中剩余版本仍待验证，Seq 12 的暂存行继续等待捕获。由此形成 `History 暂存 → C 队头 ProbeAck → 同组 Acquire → Checker trap 返回 → Seq 11 安全水位 → History 释放`。原 `0x8000014c` 是被旧 replay 取消的下一条 CSR 指令，实际重试的栈写位于 `0x8000014a`。 [C 队头](../../TMP/ec-test-20261125/store-replay/pressure-12p5/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure-c-channel/run.log) · [MSHR 与 DCache](../../TMP/ec-test-20261125/store-replay/pressure-12p5/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure-trap-grant/run.log) · [断言](../../TMP/ec-test-20261125/store-replay/pressure-12p5/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure-owners/run.log)

`probe-ack` 候选先让无数据 ProbeAck 通过。第二次复现在 499000 周期触发同一 owner watchdog，最后完成 Seq 6。tick 273365 和 274357，无数据 ProbeAck 在 `historyCPending=1` 时实际出队，相应 `w_rprobeacklast` 在次拍置位。tick 274917，带数据的同组 ProbeAckData（`0x80049ec0`、`CacheImage.valid=0`）成为新队头，再次被堵住。hart 3 已执行到 trap 读栈返回路径，tick 276800 因同组 Grant 等待失去进展。 [第二次复现](../../TMP/ec-test-20261125/probe-ack/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure/run.log) · [第二次逐拍证据](../../TMP/ec-test-20261125/probe-ack/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure-first-block/run.log)

生产 `Scheduler` 复用采集条件 `hasData && CacheImage.valid` 作为暂存的准入条件。需要暂存的带版本数据保持原队头等待，其他 C 拍依旧按 FIFO 顺序与 SinkC 握手。ProbeAckData 继续经过原有的同址版本及 bank 检查。改动复用既有字段、采集条件与回执路径，增加零寄存器、零队列。新版整核和组件回归写入 `c-staging`。 [修复入口](/data1/gzh/EC/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:217) · [新版构建](../../TMP/ec-test-20261125/c-staging/)

### 冻结程序的 HTIF 终态停顿

`c-staging` 的冻结 16 轮程序用 12.5 MHz Checker 越过前两处停点，54 个包全部 PASS，实际软件签名为 `974ea63763416da0`。最后进入一次 HTIF 输出时仍触发主核 watchdog，tick 1421000、退出 1。最后一个主核活 MSHR 对 `fromhost=0x80007348` 等待 Grant。最后一次真实 capture 是 HTIF `0x80007340` 的 Seq 54 行，当时其他 History 槽全部空闲。 [完整失败](../../TMP/ec-test-20261125/c-staging/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure/run.log) · [逐拍 owner](../../TMP/ec-test-20261125/c-staging/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure-exit-owner/run.log)

tick 1158810，HTIF 行的 ProbeAckData 末拍完成，另一组 `0x800075c0` 的 ProbeAckData 已在 C 队头，持有 dirty 且未写回的旧驻留行。1158813 起，HTIF 历史行已交给 History，`publishPending` 阻止队头的安全前驱直接写回。1158854，HTIF MSHR 新一轮 Probe 进入等回执状态。队头一直未出队，History 保留发布 owner，两个普通 MSHR 各等一个 Probe 末拍，preservation FSM 空闲。旧准入规则能释放 History 暂存与无版本 C 回执的循环。此处还需处理已选中发布的 History 与跨组 C 队头的依赖。

16:51 CST。新版复用 History 已有空槽计数证明发布行是唯一的历史条目，并要求 C 暂存无数据、队头前驱已安全且前驱属于不同组。发布方等该组事务结束的条件仍保留。Scheduler 在这组条件同时成立时允许队头的前驱按原外写和精确 ACK 路径完成，从而释放队头和后续 Probe。改动为现有空槽计数的一次比较及写回仲裁条件，没有新增状态。组件对照中旧版在 944 周期仍未取得前驱写回 owner，修复版核对先写前驱、ACK 后接收 Probe、发布正确 History 字节、两次读均终结和最终 DRAM 字节，589 周期 PASS。[旧定向反例](../../TMP/ec-test-20261125/probe-publication/directed-c-staging.log) · [新定向结果](../../TMP/ec-test-20261125/probe-publication/directed-probe-publication.log)

同一冻结 16 轮 ELF 在最终模型以 1162441 周期、930.117 秒、退出 0 完成。严格计分要求的 Seq 1 seal/END/count 64、History 实测 64/64、回收到 48 空槽且检查包继续推进、最终 64 空槽均通过。54 个 Checker 结果全 PASS，软件签名匹配 `974ea63763416da0`，HTIF 完成报告和退出。该定向用例也已加入现有组件回归。 [完整退出](../../TMP/ec-test-20261125/probe-publication/Palimpsest12p5MHzHistoryPressureConfig/historical-pressure/run.log) · [严格计分](../../TMP/ec-test-20261125/probe-publication/acceptance/12p5-frozen-strict.json) · [组件回归](../../TMP/ec-test-20261125/probe-publication/baseline-with-directed.run.log)


## 最终整核验收

`probe-publication` 六个整核模型完成 Chisel、FIRRTL、RTL 生成和 C++ 构建。基线、Hierarchy、History 压力、Seq 传输、LSU 恢复和两组设备组件通过，其中基线回归包含跨组双 Probe 用例。 [构建和组件日志](../../TMP/ec-test-20261125/probe-publication/)

| 运行 | 周期 | 墙钟秒 | 退出与判据 |
|---|---:|---:|---|
| v1Config 日常 | 345597 | 321.686 | 退出 0，97 PASS，0 FAIL。 |
| v1Config FST | 345597 | 507.045 | 退出 0，与日常软件结果一致。 |
| Fault8 | 422873 | 341.397 | 退出 0，126 PASS，唯一 FAIL 为 Seq 8。 |
| 强制物理重基 | 677729 | 593.563 | 退出 0，6 次物理 reset，6 个新的 Seq 1 PASS。 |
| 12.5 MHz EC-Test | 1234316 | 1013.127 | 退出 0，实际 64/64、再分配、回收和最终空表。 |
| 12.5 MHz 冻结压力 ELF | 1162441 | 930.117 | 退出 0，严格计分通过，54 PASS。 |
| 25 MHz 冻结压力 ELF | 759165 | 664.462 | 退出 0，原计分因 Seq 1 END/count 16 未达 64，实际峰值 40/64。 |

日常、FST、Fault8 的运行日志和 12.5 MHz 两组容量计分都保存在最终验收目录。25 MHz 的严格失败保留，按原判据通过满容量验收的配置为 12.5 MHz。 [最终验收](../../TMP/ec-test-20261125/probe-publication/acceptance/)

冻结历史重基完整退出 0，2085846 周期、1679.60 秒，原计分确认 23 次实际 reset 与 23 个新 Seq 1 PASS。正常和 Fault8 的 Sv39 组合分别在 547623、589140 周期退出 0，原计分确认 16、18 次物理读及各 16 次存活提交。历史 Fault18 的中断、设备 journal 和不可缓存 AMO 回归严格通过，原效果到重放仅发射一次物理 TL A。 [重基计分](../../TMP/ec-test-20261125/probe-publication/PalimpsestSeqRebaseTestConfig/historical-rebase/oracle.log) · [Sv39 计分](../../TMP/ec-test-20261125/probe-publication/sv39-driver.log) · [设备计分](../../TMP/ec-test-20261125/probe-publication/acceptance/historical-io.log)

正常与 Fault8 EC-Test 的独立观测各通过四次物理 MSIP set/clear、四次精确 trap/xRET、四次设备 AMO 和读回的联合计分。正常运行中原 Seq 15、16 各产生 PASS，日常和 Fault8 的软件均执行到最终判据。 [联合计分](../../TMP/ec-test-20261125/probe-publication/acceptance/ec-observer.json)

## 运行命令

以下保留本次历史验收的实际命令。正式日常入口现已恢复，后续请使用 [正式 Verilator 环境命令](../history/reports/verilator-formal-environment-20261125.md#直接使用)，无需临时目录和 `BREAK_SIM_PREREQ`。

在项目工具链环境中，从下列目录运行。三条 Make 命令直接使用已构建的四线程模型和统一的 EC-Test ELF。make 按依赖关系复用已生成的 HEX。

```sh
cd /data1/gzh/EC/chipyard/sims/verilator
simroot=/data1/gzh/EC/AI/TMP/ec-test-20261125/probe-publication
make CONFIG=v1Config sim_dir="$simroot/v1Config" BREAK_SIM_PREREQ=1 \
  timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
```

FST 调试和独立 S8 验证沿用同一 `simroot`。

```sh
make CONFIG=v1Config sim_dir="$simroot/v1Config" BREAK_SIM_PREREQ=1 \
  timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count VERBOSE_FLAGS= \
  WAVEFORM_FLAG="-v$simroot/v1Config/output/chipyard.TestHarness.v1Config/test.fst" \
  run-binary-debug-hex BINARY=../../../Software/Test/test.riscv

make CONFIG=PalimpsestFault8Config sim_dir="$simroot/PalimpsestFault8Config" \
  BREAK_SIM_PREREQ=1 timeout_cycles=750000 EXTRA_SIM_FLAGS='+cycle-count +verbose' \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
```

12.5 MHz 极限测试使用预编译模型、只读观测器及预生成 HEX。每次运行将观测记录保存在新目录。

```sh
(
  model="$simroot/Palimpsest12p5MHzHistoryPressureConfig"
  run=$(mktemp -d "$model/run.XXXXXX") || exit
  cd "$run" || exit
  PALIMPSEST_IRQ_LOG="$run/irq.log" PALIMPSEST_IO_EFFECT_LOG="$run/effects.log" \
    "$model/pressure-observer/simulator" --verbose +permissive +max-cycles=2000000 \
    "+loadmem=$model/ec-pressure/test.loadmem_hex" +loadmem_addr=80000000 \
    +dramsim +dramsim_ini_dir=/data1/gzh/EC/chipyard/generators/testchipip/src/main/resources/dramsim2_ini \
    +permissive-off /data1/gzh/EC/Software/Test/test.riscv >run.log 2>&1
  status=$?
  printf '%s\n' "$status" >run.exit
  rg 'EC-Test (PASS|FAIL)|Completed after|Assertion|%Error' run.log
  printf 'Logs: %s\n' "$run"
  exit "$status"
)
```

同主机、相邻 RTL、同 ELF 的 30000 周期测量中，1 线程 59.337 秒，4 线程 26.767 秒。1 线程的 NUMA 绑定和默认调度为 53.50 和 53.63 秒。日常使用四线程预编译模型及默认 NUMA 调度。构建时的 `-j24` 作用于 C++ 并行编译。Verilator 5.048 默认生成优化为 `-O3`，本轮 C++ 构建使用 `-O1` 并对超大翻译单元用 `-O0` 控制编译成本。最终 v1Config Chisel 44.37 秒，低 FIRRTL 阶段 373 秒，Verilator 生成 234.651 秒（fast）和 281.943 秒（debug），两个模型的 Make 后端构建整体 1340.57 秒。 [构建日志](../../TMP/ec-test-20261125/probe-publication/v1Config/build.log) · [线程对比](../../TMP/ec-test-20261125/maintenance-drain/v1Config/)
