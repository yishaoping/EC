# Stage3 SerialTL echo 修复 — 2026-10-19

`STAGE3_STATUS=PATCHED_PENDING_REBUILD`；`STAGE3_CLOSURE=NO`。
本轮仅静态分析与修复，没有启动构建、生成、仿真或测试。

## 最新证据及根因

用户现场 `AI/TMP/stage3_runs/run_vsb0kdix/`，HEAD
`1ed07c28067fad6d8aed697323b465b925895914`。该次 BUILD 中模块 Scala compile、
Stage3Harness 生成、Verilator lint 和模型 C++ 编译均 exit0（原 commands.jsonl）；
旧 SinkC chiselTypeOf 编译错误消失。随后整机 runMain 的 FIRRTL 检查失败，
make 最终 exit2；DIRECTED/SYSTEM 均 NOT_RUN。

原 `build/system.build.wrapper.log` 第635、637、639行分别报告：

| 原模块 | 原引用 | 未驱动字段 |
|---|---|---|
| TLSerdesser | bundleIn_0_d_bits_d（Serdes.scala:457） | echo.cache_preserve_txn |
| TLSerdesser_1 | x1_a_bits_a（Serdes.scala:371） | echo.cache_preserve_txn |
| TLSerdesser_1 | c（Serdes.scala:429） | echo.cache_preserve_txn |

第641行明确3个错误；原批量报告11条包括字段上下文、聚合异常及 make 汇总，
不是11个独立根因。annotation 连线审计130 pin、0数量异常仅排除了该项阻塞。

日志 SHA256：`a1fca3867616e3ca85efb9a4e4a3221dbc650cd35e4c7c2fe02d22f7f5fcb22f`。
修复前 Serdes.scala SHA256：
`fff3b3363045ae50acb33fee2d4e6e3452213f1cdae1ad47fcf25b80147404ce`，
与该 run 的 inputs.json 一致；SRAM.scala、BootROM.scala 也逐项匹配。

直接症状（已证实）：三个 decode Wire 的 echo 未初始化。立即阻塞（已证实）：
CheckInitialization 终止整机 FIRRTL。上游原因（源码与旧 FIRRTL 已证实）：
TLMergedBundle 只有基础 TL 字段，无 echo；编码和 toA/toC/toD 均遗漏 echo。
Stage3 的64位 preservation transaction identity 已沿 diplomacy 传播到串行端口，
旧传输格式无法承载。后续影响（已证实）：runMain、make 和 BUILD 失败汇总；
尚无定向、运行时 stale ACK、deadlock 或整机功能验证证据。

原 FIRRTL 中 TLSerdesser 从2199440行开始，merged 第2199525行无 echo，
D Wire 第2199824行带64位 echo 却无驱动。TLSerdesser_1 从2222538行开始，
其 A/C Wire 第2222823/2222909行亦如此。证据抽取只读原 `.fir`，没有重新运行 pass。

## 修复及同路径检查

1. Serdes.scala：merged packet 增加 `BundleMap(params.echoFields)`；A/C/D 编码和
   解码均使用真实对应 echo。TLSerdesser 原 union 参数继续为两端提供共同格式，
   原 `connectHarnessRAM` 的两端 mergedParams 一致性检查保留。
   只有协议本来不含 echo 的 B/E 将新增的无效 payload 置零；不会把 A/C/D txn 置零。
   不增加队列或改变 valid/ready、last、仲裁、原基础 TL 字段和回包匹配。

2. TLRAM/TLROM 同路径缺口（静态已证实）：原 FIRRTL 的 TLRAM（2225174行）与
   TLROM_1（2227975行）端口已有 echo64；SRAM.scala 没有 echo 寄存器或 D 驱动，
   TLROM 的 edge.AccessAck 构造只填写基础字段，没有填 echo。原串行编码未读取 D
   echo，使这些输出缺口未出现在此次三个报错中；补串行传输后必须同时补返回端。
   没有将它们冒充此次日志已经报出的额外错误。

3. SRAM.scala：r_echo 在 in.a.fire 时与 r_source/r_size 同时捕获；d_echo 在
   r_full && r_ready 时与 d_source/d_size 同时前移；D echo 使用同一个 d_mux。
   因此 R 直接响应、D/ECC/AMO/子字写响应、ECC replay 及 backpressure 均沿原
   metadata ownership，不能用当前 A 的身份替换滞留回复。full/valid 屏蔽无效状态，
   不引入新的 completion 或 write permission。

4. BootROM.scala：先填 edge.AccessAck 临时 response 的 echo，再连接到 D。
   ROM 的零延迟 valid/ready 关系原样保留，响应 echo 来自同一有效 A 请求。

5. stage2_validation.py：共享 first_error 对 FIRRTL PassExceptions 聚合异常选择
   后续首个具体 exception/error，避免固定摘要只有通用 wrapper；原11条批量诊断、
   错误严重度、退出码、日志 hash 和错误报告保留。没有执行 Stage2 runner。

没有修改 preservation FSM、receipt、victim/probe gate、stale/duplicate ACK 检查或
18 CASE，也未修改生成物、旧运行或软件。当前 v1Config 的 SerialTL harness RAM/ROM
确实已在此次旧 FIRRTL 中实例化，本修复有实际路径证据。

## 静态审查与恢复规则

`STATIC_REVIEW=PASS`：Python AST、bash -n、git diff --check，以及上述源码/旧 FIRRTL、
BundleMap/:<= API、echo source/size enable/response mux 的静态检查通过。
证据在 `AI/TMP/stage3_serdes_echo_fix_v5355woc/`：源码修复前副本、原现场 hash、
旧 FIRRTL echo inventory、最终差异/检查记录。完整用户 run 保持原样。

未运行 Scala compile、build、elaboration、RTL generation、FIRRTL、Verilator、
simulation、regression、runner 或单元测试。当前新代码的类型/生成和端到端 echo
返回仍待 fresh build/directed/system；有限静态审查不能声称全交错功能 PASS。
echo 非空时串行 packet 格式变化，两端需同源重新生成，不可与旧模型混用。
echo 为空时新增 BundleMap 无 payload 位；本轮没有扩大 request/response user 字段支持。

保持唯一无参 `stage3/stage3_run.sh`，无新入口。source 和 shared helper 身份变化会
使 BUILD 及下游失效；该失败 run 无 BUILD seal，模块局部 exit0 不足以复用整个阶段。
用户再次执行同一命令会新建目录，自动 BUILD → DIRECTED → SYSTEM，任一 FAIL 即停。
不手动指定 root、stage 或清理目录；原模型和失败现场不覆盖。

本轮修改：

- chipyard/generators/testchipip/src/main/scala/Serdes.scala
- chipyard/generators/rocket-chip/src/main/scala/tilelink/SRAM.scala
- chipyard/generators/rocket-chip/src/main/scala/devices/tilelink/BootROM.scala
- AI/Debug/scripts/stage2_validation.py
- AI/Debug/scripts/README.md
- AI/Debug/state/current_debug_state.md
- AI/Debug/history/timeline.md
- AI/Debug/history/reports/stage3_serdes_echo_fix_20261019.md
