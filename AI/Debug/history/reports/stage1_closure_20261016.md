# Stage 1 L1 correctness closure checkpoint

> 2026-10-16 后续 readiness 审查已完成，见 [simulation readiness / closure preflight](stage1_readiness_20261016.md)。下文保留原运行的历史审计；末尾“原 test.riscv 足够”和“尚需新增 EXIT_DRAIN”建议已被新 directed AMO workload、live RTL exit probes 和新隔离脚本取代。新修改仍未经过硬件编译/仿真。

本报告只使用已有运行 `AI/TMP/stage1_trace_20261016_120118/trace.log` 和当前源码静态审计。没有在本轮启动硬件编译、Chisel/FIRRTL/Verilator、elaboration 或仿真。

## 证据边界

运行日志 SHA256 为 `f568f9b0b1d64f11496b127575af958ef94c340fa396e73f6275d64a6908f60a`。保存的 provenance 清单通过：`PROVENANCE=PASS`，simulator SHA256 为 `e7eb03e53724d4f44a64052e45116fd9b6695e6bece85aac45f738614133685c`，source/generated/binary 对该运行一致。清单没有保存本次运行的不可变 argv，因此不能把目录外的启动参数当作运行事实。当前源码在本轮已经改变，不能把该运行当作这些新修改的动态验证。

运行结尾为 `STAGE1_SIM_EXIT reason=serial_success`，软件打印 `verified=1`、`packages allocated=332 completed=332 passed=332`，没有观察到硬件 assertion、abort、timeout 或显式架构 mismatch。这个结果不能替代 L1 closure：软件最后进入 `_exit` 的 `0x800068ac/0x800068b4` 循环，仍提交了 15 个 tohost/fromhost store；`traffic_stop` 只是在该循环中的观察点，不是退出时的硬件排空快照。

## 九项判定

| 项目 | 判定 | 依据 |
|---|---|---|
| architectural data/error | PASS（本次运行未观察到） | `verified=1`，无 error/assert/mismatch 文本；AMO.W 覆盖边界另列。 |
| AMO.W | UNRESOLVED | 当前 trace 有 AMO.W，但没有覆盖 `addr[2]=1` 的上 32-bit lane，也没有 old/operand/new/return/mask 字段。已用 `LoadGen.wordData` 修正 lane 选择并加入下一轮取证字段。 |
| main/checker accounting | FAIL（当前运行） | 报告为 stores `61270-60563=707`、loads `96749-95034=1715`。BOOM 提交条件只检查 `traffic_scope_valid && packet_seq!=0`，没有使用 LSQ 锁存的 `traffic_check`；这是窗口外访问被计入的确定性归因。 |
| clear/S1/S2/refill race | UNRESOLVED | 当前运行未出现 refill fault/assert；已有 drain/epoch/owner 静态保护，但没有本轮 directed clear 同周期证据。 |
| effect -> terminal | PASS（observed effect set） | `EFFECT=144981`，每个 effect identity 恰好一个 applied terminal；流式分析未发现 duplicate/identity/order 错误。另有 59 个 `cmd=01` terminal 无 effect；旧格式没有 terminal reason，不能把它们进一步证明为 MMIO 或其它 no-effect 路径。 |
| terminal -> STQ release | PASS（observed cache transactions） | `TERMINAL=STORE_DONE=145040`、`RELEASE=145122`；release 检查 committed/done/!inflight，fence release 不当作 cache effect。 |
| duplicate effect | PASS（observed） | effect token 聚合无重复；S3 `applied`/applied-effect token 和 held completion 保护仍在当前源码。 |
| lost effect | UNRESOLVED | 15 个最终架构提交 token 在日志末尾没有 terminal，但全部落在 `_exit` tohost/fromhost 循环；没有非退出地址的 orphan，仍缺少真实退出排空快照。 |
| exit outstanding | UNRESOLVED | simulator serial success，且尾部身份明确是 `_exit` loop；当前 emulator 没有“退出且 L1/MSHR/STQ 已排空”的硬件证明。 |

详细流式输出在 `AI/TMP/stage1_closure_20261016/scoreboard_after.out` 和 `scoreboard_after.json`；原始计数/PC 差异分解在 `accounting.json`。旧日志中 `S1=1755252`、`S2=1705836`、`REPLAY_GRANT=7891`、`REPLAY_RESULT=7891`、`CLEAR=187`、`REFILL=30596`，未见孤立 replay result；按 cmd 汇总为 `EFFECT(cmd01)=144889`、`TERMINAL(cmd01)=144948`、`EFFECT(cmd04)=TERMINAL(cmd04)=92`。

## 根因与修改

1. `lsu.scala` 的架构统计把“已捕获 tag”误当成“窗口内 tag”。现在 store/load 归属同时要求 `traffic_scope_valid && traffic_check && packet_seq!=0`；`traffic_check` 在地址翻译时锁存，能保留 STOP 后延迟提交而排除 setup/post-window 访问。
2. `dcache.scala` 的 AMO.W 旧值原来固定 `bits(31,0)`。现在用 `LoadGen.wordData` 按 `addr[2]` 选择 word 并符号扩展；S3 额外锁存 old/operand，并在 EFFECT 输出 `addr/old/operand/new/returned/mask`，下一轮可直接检查 RV64 AMO.W 语义。
3. `RocketCore.scala` 的 checker 统计 debug token 改用 checker-owned `package_seq_reg`，避免延迟 WB 响应采样到已经推进的外部 `io.packet_seq`。
4. `stage1_trace_scoreboard.py` 改为逐行流式、保留 identity summary；修正文本字段解析、AMO opcode 集合、replay/terminal exemption、退出尾部分类，并输出 `PASS/FAIL/UNRESOLVED` gates。`test_stage1_trace_scoreboard.py` 覆盖 exactly-once、AMO.W 上 lane sign-extension、effect-without-terminal 三个离线回归，当前 `unittest` PASS。

关键源码位置：`dcache.scala:1921-1927,2048-2053`，`lsu.scala:1959-1964`，`RocketCore.scala:1225-1229`。本轮新增脚本的 source hashes 已记录在工作区审计中；未修改 generated collateral。

## 修改后 invariant

- AMO.W 返回值使用被访问的 32-bit lane，且按 signed RV64 sign-extension 返回；物理写 mask 只更新该 lane。
- 一条 effect identity 最多一次物理 data-array effect；applied effect 才能进入 terminal，terminal 才能进入 matching STQ completion/release。
- 已锁存的 `traffic_check` 是架构统计唯一窗口资格；live checker state 或仅非零 sequence 不能重新授予资格。
- replay 的 grant/result 必须保持 mshr、transaction、request、effect、slot epoch、owner way 一致；RETRY 不退休。
- clear/freeze、S1/S2、held S3/completion 和 refill/install 不能同时撤销同一 owner；旧 image 不得产生新 effect。

## 下一轮最小验证

必须重新编译：**YES**，因为修改了 BOOM DCache/LSU、RocketCore 和 observation printf。只需一轮隔离 debug build 加一轮原 `test.riscv` Stage 1 run；不要复用当前 simulator。该轮应启用现有 FST 选项以便在 serial success 后检查 drain。

自动 closure gates：`ARCH_ERROR=0`、AMO.W 同时覆盖 `size=2,lane=0/4` 且 `AMO_SEMANTICS=0`、`MAIN_CHECKER_DIFF=0`、`DUP_EFFECT=0`、`EFFECT_WITHOUT_TERMINAL=0`、`TERMINAL_WITHOUT_EFFECT` 只允许有明确 `MMIO/noWriteSC/cancel` reason、`TERMINAL_WITHOUT_STQ_RELEASE=0`、`DUP_STQ_RELEASE=0`、`REPLAY_GRANT=REPLAY_RESULT`、clear/refill owner assertions=0。最后必须新增一个明确的 `EXIT_DRAIN` snapshot，证明 MSHR/replay/completion/S3/store_done/STQ inflight 均为零；仅 `STAGE1_SIM_EXIT` 或 `_exit` 循环不能代替它。
