# Stage 2 构建准入复核（2026-10-17）

后续入口已收敛为一条绝对路径命令，新增实际 MSHR→SourceD denied Put/AMO 回归和 denied 数据/bypass 修复，见 [all 入口交付](stage2_all_entry_20261017.md)。本报告的 64 tests、8 CASE 与分步命令属于当时交付；最新为 10 CASE，仍未运行硬件验证。

结论：`PREFLIGHT_READY_PENDING_BUILD`。本轮发现的确定连接、握手和验证判据问题已修复；建议开始下面的 build 阶段，没有已知必须先修复的构建阻塞。该结论是源码与离线流程准入，不是 Scala 编译、组合环、RTL 或仿真通过。

继续保留本地 `1ed07c280` 的 Stage 1 和上一轮 Stage 2 未提交工作；本轮没有同步、reset、清理、提交或写入 `sources/`。没有运行 sbt、make、Verilator、硬件生成、elaboration、FIRRTL 或任何仿真。实际只执行了离线检查，包括声明 stub 的 C++ `-fsyntax-only`。

## 本轮实际发现与修复

1. **TL 字段初始化遗漏。** `SourceD` 的内部 `Atomics.io.a` 是完整 TL A bundle，旧逐字段连接没有驱动新增的 `user(CacheImage)`。先对整个 bundle 赋 BASE/零值，再覆盖实际 ALU 操作数；early D response 也先整体初始化，避免 optional user/echo 遗漏。生产 outer L2 A/C 不协商本阶段字段，因此不向 DRAM 伪造保存协议。
2. **probe 的完成条件不再可靠。** `BoomProbeUnit.s_writeback_resp` 原先读 WB 仲裁器 `ready` 判断完成；ACK descriptor 分离后，该 ready 会受另一条 voluntary request/credit 影响，与先前 probe 的发送没有一一对应关系。现在 WB 只在 non-voluntary 最后 C beat fire 产生 `probe_done`，接入 prober `wb_done` 后推进 metadata；增加 orphan completion 断言。pending voluntary ACK 不再占用 probe 的完成条件。
3. **matching-key ACK 可过早锁存。** 原先 ACK 比较只看 pending/source/key，在 C 完整发送前也可置 `acked`。现在还要求 `pending_sent`、正确 opcode/size、非 denied/corrupt；WB 断言 full-C 已发送且未重复确认。fixture 新增 C 被阻塞时注入完整正确 key 的过早 ACK，必须消费但不释放当前写。
4. **fixture 丢掉了 128-bit 数据高半部分。** SourceD 的写与读观察口原来截成 64-bit，激励上下半也相同。现在分别导出两个 64-bit 半部，用互补数据同时检查 bank write 和 clean-release 后的读；保存 predecessor 时检查整个 64-byte image。增加 RV64/16-byte beat/address/source/seq 参数约束，并让 fixture 的 packet provenance 与 ImageKey 一致。
5. **freeze 边界缺少直接观察。** 原功能 drain 包括 S1/S2 pre-freeze、S3、completion 和 MSHR slot owner。新增 snapshot admission 与 snapshot 后 semantic/refill 实际写口断言；没有以请求发出或 WB idle 替代排空/确认。
6. **验证可假覆盖或漏掉提前 effect。** 原脚本只数 8 个 CASE，现检查准确名称、重复和缺项。C++ 独立激励标记 FORBID/ALLOW，离线判据核对生产 `STAGE1_TX EFFECT`（真实 data-port fire），不以 terminal 仍被阻塞替代无写证明。Stage 2 analyzer 要求 snapshot → lower commit → matched ACK → 同 line/epoch/key 的 PRESERVE_DONE 闭合，receipt 也匹配 epoch；伪造 accepted、旧 epoch、ACK 后漏 done 均被拒绝。
7. **denied A 操作错误重标身份。** L2 MSHR 原新增的 trusted A Put/AMO → BASE 更新位于 bad_grant 保留旧 metadata 的分支之后，会覆盖其旧 key。现要求非 denied 才建立 BASE 语义写，失败操作保留旧 bytes/key，避免将旧 speculative image 误标 safe。该 denied 路径需整机/后续 targeted coverage，当前 fixture 的下层不产生 denied。
8. **脚本阶段与来源隔离不足。** 新增 `stage2_validation.py`，原 shell 入口保留。四阶段独立，每阶段先检查之前所有阶段 PASS；Stage 1 只新增 `STAGE1_BUILD_ONLY=1` 的显式出口，原默认 build+run 行为不变。构建失败不会进入任何模拟器。

主要位置：`boom/.../lsu/dcache.scala` 的 WB/prober、ACK matcher 与 S3 assertions；`inclusivecache/src/SourceD.scala` 的 earlyD/Atomics defaults 与 `MSHR.scala` 的 denied identity；`scripts/stage2/Stage2Generate.scala` 与 `stage2_test.cpp`；`stage2_trace_scoreboard.py`、`stage2_validation.py`、两个 Stage 2 离线测试；`stage1_build_and_run.sh` 的 build-only 出口。

## 六项针对性源码检查

| 项目 | 源码结论与边界 |
|---|---|
| ImageKey/TL/directory | key 的有效载荷为 81 bits：valid=1、writer=16、generation=32、contentSeq=32；当前 GH sequence 也是 32 bits。A/C 使用 negotiated requestFields，D 使用 responseFields，控制字段穿过 WidthWidget/Buffer/Xbar 时随完整 bundle 连接。BOOM/MMIO/无数据 probe 的 BASE defaults、L2 SinkA/X、SinkC 的 C transaction key、MSHR/nestedwb/directory、GrantData/ReleaseAck 逐一检查。directory 按完整 bundle.getWidth 存储、reset 全零，既有 <=256 约束仍在；实际宽度和所有连接仍由 elaboration/FIRRTL 确认。 |
| ReleaseAck/bank | C 不走原 S3 early ACK；最后一拍到 s4 后，bank write 与 ACK enqueue 都需要 bank ready 和 ACK queue credit。credit 缺失时最后一拍 bank valid 被抑制、s4 保持；bank 背压时不 enqueue；两者 fire 同拍后 s4 只退休一次。普通 Queue 不 flow，ACK 最早随后一拍可见。clean Release 无 bank write，只产生一次 completion，不进数据 bypass。 |
| buffer/credit/D/probe | C 最后一拍后释放 WB 数据 FSM，pending source/key/epoch 保留到 ACK done。probe 用独立最后 C fire 完成；新 voluntary source 在 pending ACK 清除前不能复用。D 用 beat-lock arbiter；需要经过 s4 的多拍 Grant 首拍在旧 s4 无 credit 时不能启动，避开“Grant 锁 D → ACK 无法排空 → 旧 C 卡 s4 → Grant 后续拍被挡”的环。SourceD s1 busy 保持一个请求的所有 beats，后来的 C 不能穿插到已开始的 Grant 之前。源码上消除了这些具体环；公平性、跨模块 ready 环和全系统进度仍待结构与动态验证。 |
| freeze/drain | shadow acceptance 等待 S1/S2 pre-freeze、S3 与 completion、相同 slot 的 install/MSHR owner、同 set probe；drain 前允许已获准 S3 完成，再在 WB accept 捕获最终 key。freeze 后 normal/补发写被统一 gate/owner 阻塞；replay 与 refill 由 slot owner 冲突互锁，额外断言直接检查实际两个 data write ports。同拍新 probe 在后续 lookup 被 WB idx/drain 阻挡，不能修改已捕获字节。 |
| ACK 生命周期 | ACK 要求唯一 voluntary source + full C 已发送 + 完整 key + opcode/size/非错误。done 携带 snapshot epoch；设置 receipt 前再比 resident tag/key/epoch，并排除同拍 probe revoke。probe invalidate/clear 推进 epoch、撤销 image/receipt；refill 完整末行原子建立新 key/receipt；no-data Grant 保留 key；validation 不修改身份。pending idx 阻止相同 set 的新 install 越过 ACK，probe 可以撤销旧 resident，但不能清掉等待中的 descriptor。epoch 是本地 slot 身份，不是额外 TL wire token；相同 key 的合法复制是同一 image，遵循 TL 每个 source 每次请求恰好一个响应的契约，不能宣称支持任意重复/乱序同 key 协议故障或非协调 reset。 |
| 验证真实性 | fixture 实例化实际 BOOM L1 pipeline/MSHR/replay/WB 及实际 SourceD；下层 agent 只供可控数据/ACK，未实现 gate。独立检查旧/新数据、AMO old value、SC result、完整 C header/key、多拍 bank writes、ACK 数与保持、无提前/重复 physical effect。生产 TL monitor 仅在故障注入 fixture 关闭，整机保持。真实 directory、BankedStore、多 tile Xbar/width/crossing、checker watermark 与退出排空依赖整机验证。 |

这里“下层保存完成”的实际保证是 **L2 已接受并写入其 data bank，且 directory 更新已按原 scheduler/directory queue 的顺序发布**。`BankedStore` 没有更晚的 write response：ready 表示本拍所有所需 bank 获准，fire 在该边沿使 SRAM write 生效。directory queue/bypass 与 SourceD set/way hazards 保持该顺序。ACK 不表示 DRAM 持久化，也不提供多版本 retention；Stage 3 的 lower predecessor FSM/rollback/escape 仍不在本轮。

## 分阶段手动命令

先进入已有 Stage 1 环境；四步使用相同终端环境和同一个新 root。root 一旦有某阶段尝试记录便不覆盖/重跑该阶段；修复失败后新建 root，保留第一次失败。

```bash
cd /data1/gzh/EC
export STAGE2_ROOT="/data1/gzh/EC/AI/TMP/stage2_validation_$(date +%Y%m%d_%H%M%S)"
AI/Debug/scripts/stage2_build_and_run.sh offline
AI/Debug/scripts/stage2_build_and_run.sh build
AI/Debug/scripts/stage2_build_and_run.sh directed
AI/Debug/scripts/stage2_build_and_run.sh system
```

可逐条执行并查看摘要。即使手动误运行后续命令，脚本也会检查前置状态，拒绝越过失败；也可用 `... all` 自动依次执行并失败即停。本轮仅执行了 `offline`，没有调用后三个阶段。

| 阶段 | 实际操作 | 继续条件 / 停止条件 |
|---|---|---|
| offline | 读取并核对源码/工作负载/工具身份；Python AST、shell syntax、git diff --check、64 项纯离线 tests；声明 stub 的 C++ -fsyntax-only。没有链接或执行模型。 | `OFFLINE=PASS` 且 exit 0 才可 build；工具/工作负载/语法/测试失败即停。 |
| build | sbt Compile/compile 后 fixture emitVerilog（含 FIRRTL 检查）；Verilator lint-only（UNOPTFLAT/PINMISSING 为 error）及实际模型编译；原 Stage 1 全新 v1Config debug build-only、provenance 验证。**会生成硬件，绝不运行模拟器。** | 所有命令 exit 0、源码未变化、两个模型存在、完整 model/binary attestation 匹配，才 `BUILD=PASS`。Scala/FIRRTL/lint/C++/系统 build/provenance 任一失败则 directed/system 均 NOT_RUN。其余 lint warnings 保留，不能把 lint exit 0 当无警告。 |
| directed | 校验 build products；运行一次 VStage2Harness；分析 C++ 数据/握手断言、准确 8 CASE 及独立 effect guard。 | 模拟器 exit 0、CASE 无重复/缺项、effect 无提前/重复，才 `DIRECTED=PASS`。失败退出 1，缺覆盖退出 3，均禁止 system。 |
| system | 再次校验来源、build products 与 directed 证据；调用原 Stage 1 verify-only run_trace，一次整机进程；Stage 1 + Stage 2 analyzer。 | 模拟器和原 Stage 1 closure 全部通过、Stage 2 trace=PASS 且覆盖齐全，才 `SYSTEM=PASS`。失败/缺覆盖保留原日志与 JSON；trace 缺失为 NOT_RUN_NO_TRACE，不能变成 PASS。 |

退出码：0=当前阶段通过；1=执行/功能/来源失败；2=参数或缺少工具等使用错误；3=缺覆盖。日志保留工具原始退出码与错误尾部。phase 的 `*.status.json` 为准，`summary.out` 是总摘要；`RUNNING` 残留说明被中断，也不能复用为 PASS。

每阶段记录并复核：本地 HEAD 和实际 source hashes（含未提交/未跟踪源码）、AI 运行脚本/fixture、工具路径/可执行文件 hashes、固定 argv、环境与 make override fingerprints、工作负载 manifest/ELF/loadmem；fixture 副本也要匹配。复用前还检查生成 RTL/FIRRTL/模型 C++/header/Makefile、模拟器哈希和原 Stage 1 generated manifest。没有仅凭旧目录存在复用产物。环境非固定项按 hash 记录，避免泄漏凭据；改变环境也会保守拒绝复用。

日志位置：

- `inputs.json`、`source.before.json`、`source.patch`、`commands.jsonl`、四个 `*.status.json`、`summary.out`。
- `offline.tests.log`、`host.syntax.log`、`*.syntax.log`、`diff.check.log`、`scala.lexical.json`（词法检查，非类型检查）。
- `module.emit.log`、`module.lint.log`、`module.build.log`、`generated/`、`lint/`、`obj/`、`build.artifacts.json`。
- `system.build.wrapper.log`、`system.build/build.log`、`system.build/provenance.json`。
- `module.trace.log`、`directed.coverage.json`、`directed.artifacts.json`。
- `system.run.wrapper.log`、`system.run/trace.log`、可选 `trace.fst`、Stage 1 `scoreboard.out/json` 与 Stage 2 `stage2.scoreboard.out/json`。

原先 `module` 名称保留为 `directed` 别名，现要求已成功完成 offline/build；不会隐式生成硬件。`system` 也只运行已有 attested 模型，不隐式 build。

## 已检查与待验证

本轮最新离线检查实际结果和源码身份记录在 `AI/TMP/stage2_validation_u_xd___4/`：64 tests（原 31 + Stage 2 analyzer 16 + phase/coverage gates 17）、shell/Python 语法、diff、declaration-stub C++ syntax-only 通过。早期 root 保留；后续源码改变会被 provenance gate 拒绝，不能拿旧 offline PASS 覆盖新源码。

尚未检查：真实 Scala 类型/API、Chisel 跨模块连接、实际 directory 宽度、FIRRTL initialization/组合环、真实 generated ports 与 C++ linkage、所有动态场景、整机资源竞争与进度、性能。本次可控 fixture 不包含真实 directory/BankedStore，也不主动构造所有 freeze 前获准 S3/ACK 与 probe 同拍组合；这些由新增 RTL assertions、build 结构检查和整机并发覆盖共同检查，未发生的组合不能称为覆盖完成。单一 BFS run 和有限定向 case 也不构成任意压力下无死锁证明。

Stage 1 历史 PASS 继续保留，但不用于证明本轮 RTL。建议现在进入 build，以真实编译/生成检查剩余结构风险；没有因尚未仿真而阻止进入验证，也没有把源码检查当硬件正确。
