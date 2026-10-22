# Stage 2：L1 preservation 实现与手动验证（2026-10-17）

## 当前证据（2026-10-18）

最新 `AI/TMP/stage2_validation_agciqdp_/` 已完成 build/directed/system，三阶段均
PASS/exit0；33 pin wiring、10定向CASE、真实denied Put/AMO对照、整机1216 preservation
闭合及退出排空均有证据。当前11479 source/16 scripts/fixture与run记录完全一致，旧epoch
故障已消失。本轮没有功能/checker/trace改动，不需要为文档修改重复硬件运行。
`STAGE2_STATUS=CLOSED`、`NEXT_SIM_REQUIRED=NO`、已知静态blocker=0。两个精确同拍
场景是非阻塞 coverage gap，长期公平性不属于本阶段 safety acceptance；不再要求新的
Stage 2 仿真。

实际invariant、producer matrix、lowerPreserved生命周期、race/验证边界、来源和准确命令
以[最新11节审计报告](../Debug/history/reports/stage2_evidence_audit_20261018.md)为准。
本轮仅源码/日志/hash/文档，无编译、生成/elaboration、FIRRTL/Verilator、仿真或测试。
下面“待构建/待执行”的叙述保留为历史交付记录，不能覆盖本节最新已完成运行的结论。

## 历史交付与构建修复

最新构建修复（2026-10-18）：用户 `stage2_validation_r8baqbfq` 已完成模块生成、97 pin 审计、lint 和 C++ 编译，整机因旧 CAM 的 64 个孤立 source 在 WiringTransform 失败。已移除被 TL CacheImage 替代的 CAM 发布端及 fixture 对应 sink，保留 33 个真实模块接收端；整机失败可全量列出本次 annotation 连线问题，且正确显示实际 cause，见 [整机修复](../Debug/history/reports/stage2_system_wiring_fix_20261018.md)。当前源码未重建，动态仿真未运行，仍为 `PATCHED_PENDING_REBUILD`；以下为此前背景。

此前构造修复：用户 `stage2_validation_mzljfuss` 在新增审计类的反射构造阶段失败，已将其改为公开顶层无参类，报告目录从 TargetDirAnnotation 获取，并在原生成进程中提前检查实际 Dependency 构造，见 [构造修复](../Debug/history/reports/stage2_audit_ctor_fix_20261017.md)。该构造链路随后已在 r8baqbfq 的模块构建完成。

最新更新：用户后续运行已通过 Scala compile 并越过 OOM，首次失败推进至 FIRRTL WiringTransform。独立 fixture 缺失的 97 个只读 bore sink 已一次补齐；新增全量 wiring 审计和同次日志全部不同错误汇总，见 [wiring 修复](../Debug/history/reports/stage2_wiring_build_fix_20261017.md)。仍为 `PATCHED_PENDING_REBUILD`，all 不自动重跑 offline；以下 OOM 段落为此前背景，完整硬件验证仍待运行。

状态：`PATCHED_PENDING_REBUILD`。最新运行的 fixture Scala compile 已成功，生成时因 sbt 默认 1G 堆 OOM；已显式设为 8G 并加强失败检测，按用户要求从 all 移除已通过的离线检查，见 [OOM 修复与当前入口](../Debug/history/reports/stage2_emit_oom_fix_20261017.md)。单命令入口及 denied 回归背景见 [all 入口交付](../Debug/history/reports/stage2_all_entry_20261017.md)，准入审计见 [Stage 2 preflight](../Debug/history/reports/stage2_preflight_20261017.md)；下面实现语义继续适用。本轮没有执行仿真、Verilator、Scala 编译、硬件生成、Chisel elaboration、FIRRTL 或组合环检查。下述硬件场景均为**待执行**，不是通过记录。

基线是本地 `1ed07c280`（阶段一完成），开始时 `git status --short` 为空。先读取了 Stage 1 最终 closure、handoff、phase1 implementation notes、统一设计和实际代码/脚本；不以旧 handoff 的 IN PROGRESS 覆盖最新 closure。没有同步远端、reset、清理、提交或修改 `sources/`。

## 语义与范围

`ImageKey = (block address, valid, writer, generation, contentSeq)`。地址由 C header、MSHR 地址和 directory tag/set 携带；其余字段由新的 TileLink `CacheImage` control field 真实传递。`writer` 是当前单 BOOM 配置的静态 tile ID，`generation` 是该 writer 跨所有 line 单调递增的 32-bit serial。每次真正的本地语义写都分配新 generation，即使字节值相同或仍属同包；串号耗尽会断言，不能回绕。复制/搬移、权限转换、包变 safe 不新建 generation。

`valid=false` 的全零 key 表示 BASE：从当前 coherent lower image 收到的可信初始数据。它不表示 L1 slot 无效。L1 slot 是否已有完整 image 由 `imageValid` 表示。实际的 BOOM 非包写也有 `valid=true` 的新 generation，`contentSeq=0` 表示可信 safe 写，不能与 BASE 混为同一种身份；它也不能绕过旧 unsafe image 的保护。可信外部客户端没有该字段时按 BASE 接入。该信任边界和原系统的单 BOOM package watermark 一致，不扩展为多 BOOM 全局版本协议。

`safe(K) = BASE || contentSeq==0 || contentSeq<=functional safe watermark`。watermark 继续使用 Stage 1 连续 PASS 机制，measurement START/STOP/RESET 不改变 image 身份和保存状态。

每个 slot 的 `lowerPreserved`（设计语义 `lower_preserved`）仅证明**当前准确 key 的完整 image 已由下层接管保存**，不表示当前 image 已 safe，也不表示最近发送过请求。bool 不另存一份 key：它与 slot 的 `imageKey` 原子维护，任何语义修改均清零。

| 事件 | image/key 与 receipt 更新 |
|---|---|
| 同包重复 speculative 写 | 直接允许；每次 physical effect 新 generation、当前 receipt 清零；最近 safe predecessor 的原保存义务沿同包更新继承 |
| 跨包写，旧 image unsafe | 阻塞；即使当前 receipt 为真，也不能跳过 wait-safe |
| 新包写，旧 image safe 且 receipt=false | freeze → drain → 完整 ReleaseData → 匹配的 commit-time ReleaseAck → receipt=true → invalidate → refetch/retry |
| 新包写，旧 image safe 且 receipt=true | 可直接进入统一 write grant；新 image 的 receipt 清零 |
| 非包写覆盖 unsafe image | 等旧 image safe；不会用 seq=0 清掉 unsafe 归属 |
| 完整 GrantData 安装 | 保留传入 key；最后一个真实 refill row fire 原子提交 image/presence/receipt=true；每拍都检查 install owner 与传入 key |
| 只有权限的 Grant | 保留 key、generation、receipt；不写 refill rows |
| probe invalidate / shadow clear | 无独占 install owner 时撤销 image presence 和 receipt，并推进 slot epoch；有 owner 时沿用 Stage 1 的保留/重查规则 |
| 包 validation | 只改变 safe 判定，不改 key、generation、receipt |
| 延迟/过期 ACK | 必须匹配唯一 pending voluntary source 与完整 key；done 还绑定 snapshot epoch；当前 resident/tag/key/epoch 不符或同拍 probe revoke 时，不设置 receipt |

本轮沿用实际 Stage 1 的 T→N shadow handoff，再重取新写。对已经降为 B 的 resident 使用实际 metadata 推导 B→N。统一设计中的 T→B/升级优化没有在本轮引入；现有失效与 owner/drain 接口更适合完成本阶段的保守实现。没有把 T→N 伪装为保留写权限，也没有用 WB idle 代替保存确认。

Stage 2 负责 L1 创建新 image 的 gate。L2 收到 speculative Q 时如何继续保存原 P 到 DRAM，仍是 Stage 3；本轮没有实现 L2 predecessor FSM、parent_key 传递、escape 或 rollback。因此不能据本轮修改宣布端到端 recovery/任意资源压力下的进度成立。复制同一个 speculative key 是既有 image 的搬移，不是重新创建一个无来源的新 speculative image。

## 入口、状态与握手审计

L1 data array 只有 `dataWriteArb` 两个实际入口，检查了所有 valid/ready/fire 和 metadata/owner 交互：

| 入口 | 保护位置与结果 |
|---|---|
| normal / 被 S2 kill 后补发的 store | S2 `L1Preservation.allow` 同时约束 hit 和 permission-miss 的 MSHR admission；阻塞按原 LSU nack/reissue 保留 token |
| replay | 相同 S2 predicate；不满足时返回带身份的 `CacheTerminal.retry`，RPQ head/SDQ 不释放；最终 physical write 再检查同一 predicate |
| SC / AMO | 都经过统一 S2 write grant 和 S3 data fire；SC failure 只有无写 terminal，不新建 key、不撤销 receipt |
| Hella/PTW 等可缓存请求 | 仍从 normal pipeline 汇入同一 grant/data port；seq=0 不绕过 unsafe 保护 |
| primary/secondary miss | permission miss 在占用 slot 前保护旧 resident；沿用 Stage 1 单包 MSHR write domain，拒绝跨包 secondary merge |
| refill / prefetch install | `copyAllowed` + install owner/transaction/epoch/key 授权；每个 row fire 重查；同址不同 key 不能毁掉未保存旧 image；新地址 victim 继续经过原 WB/owner drain |
| MMIO/uncached | 走 IOMSHR，不写 L1 array；新 TL control field 的 BASE 默认值已补齐 |
| probe / replacement / metadata publish | 不创建本地语义新 image；保留 Stage 1 freeze/drain 和 terminal ownership；probe 可在 voluntary ACK 等待期间使用 WB 数据缓冲 |

shadow coordinator 在 WaitSafe 阶段不占 WB；排空 freeze 前的 S1/S2/S3/completion 后才锁住最终 snapshot key。WB 接受请求、捕获完整数据、C 全部发送、下层保存 ACK、metadata clear 是不同事件。只允许一个 pending voluntary source；C 最后一拍后释放数据缓冲供 probe 使用，pending ACK descriptor 单独保存 key/epoch/set。源 ID 在 receipt 消费前不复用。等待 ACK 被纳入 fence ordered 与 Stage 1 退出观察，避免新路径从排空统计中消失。

L2 SourceD 为 C 单独生成延后 ReleaseAck：最后真实 bank write fire 后入 held-valid queue；clean Release 也经过完成点，但不进入 data bypass。多拍 GrantData 与 ACK 用 TileLink beat-lock arbiter 仲裁；开始 D 前检查较早 s4 是否可前进，避免 ACK queue 满 → 较早 C 卡 s4 → 新 Grant 锁住 D → ACK 无法排空的环。C plan 同时接受 directory publish，SourceD 的既有 set/way hazard 持续保护数据提交。这个确认点证明 lower bank commit/有序 directory publication，不是 C request accepted 或 WB capture。

ImageKey 随 C request、L2 queued request、directory、nested writeback 和 GrantData/ReleaseAck 传递。去掉了 SinkC 对统计地址 CAM 的功能身份依赖和 max(seq) 推断；2026-10-18 同步移除 L1 已失去消费者的旧 CAM 发布端及 fixture 对应 sink，消除整机 64 条孤立连线。任何 ReleaseData 都要求 directory plan 更新，即使 dirty/client bits 没变化；否则 bytes 和 key 可能分离。

## 上一轮实现修改清单与离线检查（本轮增补见 preflight）

生产代码：

- `boom/.../lsu/dcache.scala`：当前 key/receipt、统一 gate、coordinator、WB 数据/ACK owner 分离、refill 准入、probe/clear 互锁、排空与 Stage 2 trace。
- `boom/.../lsu/phase1.scala`：共享 gate 与 install/refill 传入身份；`mshrs.scala`：GrantData key 固定与传递、A/MMIO control 字段初始化；`lsu.scala`：仅更新 image_valid 注释。
- `rocket-chip/.../tilelink/CacheImage.scala`：key、negotiated field 和 BASE 初始化 helper。
- InclusiveCache `Directory/QueuedRequest/InclusiveCache/SinkA/SinkX/SinkC/MSHR/Scheduler/SourceD.scala`：协商、准确身份、nested 更新及保存确认点。
- `AI/Debug/scripts/stage2*`、`scripts/stage2/`：新手动运行器、真实模块 fixture、C++ 字节/完成检查和离线 trace analyzer；Stage 1 运行脚本、workload 和 analyzer 原样复用。

源码审计一并处理的关联问题：safe-old 漏保护、replay gate bypass、WB idle 被当确认、早 ReleaseAck、等待 ACK 占满 probe 数据 owner、同拍 ACK/probe revoke、probe 与 clear metadata 覆盖、B 权限误用 T→N、refill 身份清零、seq=0 擦掉 unsafe 归属、max(seq)/CAM 错配、dirty 位不变时漏 publish、新 control 字段未初始化、clean Release 污染 bypass、ACK credit 与多拍 D 的依赖环。

已检查：

- 44 项纯离线 analyzer/provenance 单元测试通过（Stage 1 原有 31 项 + Stage 2 13 项），没有运行模型或硬件。
- shell `bash -n`、Python AST、`git diff --check` 通过。
- 15 个 Scala 文件的词法括号平衡、35 处 printf 参数数检查通过；这不是 Scala 类型检查或 elaboration。
- C++ driver 仅用声明 stub 执行 `g++ -fsyntax-only -Wall -Wextra -Werror`；已补显式整数转换。没有链接或执行 fixture；真实生成端口名仍待 build。
- 证据：`AI/TMP/stage2_static_1zfnyy2_/checks.json`、各 `.out`、源码 hashes 和 `source.patch`。更早失败的 host syntax 现场仍保留，未清理。

尚待运行：全部 Scala 类型检查、真实 fixture elaboration/FIRRTL/组合环、Verilator 编译、定向运行、整机运行和新 trace 验证。旧 Stage 1 的 PASS 不覆盖本轮新 RTL。

## 手动执行（以本轮 preflight 为准）

在原 Stage 1 环境终端的任意目录执行一条命令，脚本自动创建唯一 root，严格按 build → directed → system 执行，失败即停：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all
```

`all` 不再重复已通过的离线检查，仍在构建前捕获源码、fixture、参数、工具、环境与工作负载清单。`offline` 保留为独立显式选项，不运行硬件；`build` 显式进行 Scala 编译、硬件生成、FIRRTL/Verilator 结构与模型编译，并在整机 build-only 后停止；`directed` 和 `system` 各运行一个进程。`module` 现为 directed 别名，要求已 build，不能再作为隐式 build+run 使用。fixture sbt 显式使用 8G 堆与 OOM 退出；生成还必须有正常完成标记及顶层 RTL，不能用 sbt exit 0 代替完成。

所有日志与三阶段状态保留在终端打印的 root，总摘要 `summary.out`、终端记录 `runner.log`；不会将未运行的 offline 标为 PASS。退出码 0=当前测试通过；工具失败保留原始码（信号为128+信号），判据失败1、使用错误2、覆盖缺失3；通过 status 区分工具退出3与覆盖不足。失败不覆盖重跑。复用仍要求源码、参数、环境、工具、工作负载、fixture 副本、生成模型及 binary 全部匹配。本轮没有执行 build/directed/system。

## 定向场景的预期结果（全部待执行）

| CASE | 激励与独立预期 |
|---|---|
| safe_predecessor_backpressure_delayed_stale_ack | 先有 safe seq0 数据；C 背压、D 延迟时新包均无提前 physical effect；C 未完整发送前注入 matching-key ACK 也不能释放；下层完整字节必须为旧 safe 值；错误 key ACK 不释放；等待 voluntary ACK 时另一个 dirty line 的 probe 仍完成 |
| same_package_repeat | 同包两次写和读回正确，voluntary preservation 请求数不增加 |
| cross_package_wait_safe_then_receipt | old 包未 PASS 前不发 shadow ReleaseData、不覆盖；PASS 后保存旧包最后值；ACK 前继续等待，准确 ACK 后完成 |
| normal_amo_sc_success_failure | normal/AMO old-new 值正确；同包 LR/SC 成功；无 reservation 的 SC 返回失败且无数据修改 |
| cross_package_amo_sc_invalidation_refill | 跨包 AMO/SC 不能绕 gate；AMO old value 正确，SC 失败无写；probe invalidate 后 refill 字节正确 |
| speculative_refill_replay_gate | 将 unsafe image 从 lower 重填，另一个包的 RPQ 写必须 RETRY 保留 owner，旧包 PASS 后才完成；不额外发丢失的 shadow 请求 |
| continuous_replacement_refill_seq0_terminal_backpressure | 同 set 多于 associativity 的连续覆盖/重填保留字节；trusted seq0 等 unsafe old safe；terminal 背压不会重复 AMO effect |
| real_sourced_commit_before_ack | 真实 SourceD 在 bank 背压下提交恰好四拍完整 128-bit 数据后才 ACK；ACK 保持且 key 正确；clean Release 不写 bank、不污染后续读；ACK queue 满/第三个 C/多拍 Grant 全部排空，无丢失或自锁 |
| denied_a_put_preserves_image | 真实 L2 MSHR 的 BRANCH hit 发 BtoT，延迟 Grant 并背压 schedule；denied 后实际 directory/D 保留完整旧 key/provenance、bank 零写；成功 Put 对照建立 BASE、正确写入且响应一次 |
| denied_a_amo_preserves_image | 同上，用 ArithmeticData ADD；denied 后零写、保留旧 key；成功 AMO 对照返回旧值、写入 old+operand 且建立 BASE |

fixture 的下层 agent 只提供可控的 coherent 数据、ACK 和故障注入，不实现被测 gate；L1 pipeline/MSHR/replay/WB 和 SourceD 都来自生产源码。为注入故意错误的 D key，仅 fixture 关闭 TL monitors，生产整机保留原 monitor 设置。SourceD 的 bank 接口在 fixture 中受控，实际 BankedStore、directory 与跨模块组合环由随后整机 build/run 检查；不能把模块结果当作全系统任意压力证明。

整机要求 Stage 1 所有原 closure gates 继续通过，并且 `STAGE2_TRACE=PASS`、无重复 effect/无未闭合 preservation、每个匹配 ACK 都有先前 lower commit、每个跨包 speculative effect 都有准确旧 key 的 import/receipt。缺覆盖返回 3，不硬编码旧 run 的 package/counter 总数。

## 实际风险与后续边界

新增 TL field、L2 directory 宽度、D arbiter/ready 依赖和 fixture 端口尚未经过 Scala/elaboration/组合环/真实编译；这是当前最直接的未验证风险，不能以词法检查代替。

T→N 需要额外 miss/refill，吞吐和包边界时序会变化；本轮选择与 Stage 1 ownership 风格一致的保守协议，尚无新性能数据。协议要求最终有 matching ACK、公平仲裁和旧包 functional PASS；失败/取消不会伪造 safe，永久背压也不会被 timeout 旁路。没有完成任意资源压力下的全系统无死锁证明，原有 L2 barrier/active-package 资源依赖仍由后续阶段处理。

同址不同 key 的 refill 若会破坏 unsafe/未保存旧 image，硬件拒绝并断言；当前正常 T→N/refetch 和 permission-only upgrade 不需要这种覆盖。多 writer 扩展、任意外部写与 live speculative owner 的恢复语义需要完整跨层版本协议，不能凭 BASE/seq0 自动豁免。

L2 predecessor 保存到 DRAM、外层 ACK、跨层 parent key、FAIL rollback 和 escape/pressure-close 没有在本轮实现或验证。Stage 2 当前交付是代码和可执行验证入口，尚不能宣布动态完成。
