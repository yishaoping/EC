# Stage 2 整机残留 CAM 连线与错误摘要修复（2026-10-18）

`PATCHED_PENDING_REBUILD`。用户 run `AI/TMP/stage2_validation_r8baqbfq/` 已完成定向 fixture 的 Scala compile、生成、wiring 审计、Verilator lint 和模型 C++ 编译；整机在 Scala FIRRTL WiringTransform 失败，未进入定向/整机仿真。本轮修复已确认的全部 64 条同源连线问题及日志误报，没有运行编译、生成、elaboration、FIRRTL transform、Verilator 或任何仿真。

## 根因与证据边界

- 直接现象（已证实）：`system.build.wrapper.log:697` 为 `NoSuchElementException: key not found: gh_l1_l2_packet_tracked_15`，`:702` 落在 WiringTransform.scala:80。make 原始返回码为 2，后续阶段 NOT_RUN。
- 直接阻塞（已证实）：该次实际 FIRRTL 命令使用 `system.build/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.appended.anno.json`；完整清单有 194 个 pin，其中 64 个恰好是旧 CAM 的 valid/address/seq/tracked 各 16 项，每项一个 source、零 sink。其余 130 个 pin 均一 source 且至少一 sink。没有将多个中间 annotation 合并计数。
- 上游原因（已证实）：Stage 2 的 SinkC 已改为从 C.user(CacheImage) 读取完整 image 和 packet provenance，去掉了 CAM 接收端；dcache.scala 仍发布旧 CAM，造成整机孤立 source。上一轮独立 fixture 用只读 sink 消费它们，所以该模块成功并不能证明整机拓扑完整。
- 诊断放大因素（已证实）：FIRRTL 只抛出一个 map key；sbt 把 fork JVM stderr 的普通 `Picked up JAVA_TOOL_OPTIONS` 提示标为 `[error]`，旧摘要错误地选择它作为首个错误，并保留 ANSI 控制序列。

本次 module.emit.log 明确有 `STAGE2_WIRING=PASS pins=97 errors=0` 和 `STAGE2_EMIT=PASS`，commands.jsonl 记录 module.emit/lint/build 均返回 0。此结论仅属于该次未修复 CAM 的源码与模型；当前删除残留后的 33 pin fixture 尚未重建。整机未生成完整模型，不能称 build PASS。

## 实际修改

1. `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`：移除已经无消费者的 CAM 寄存器、更新逻辑与全部 64 个 BoringUtils source；保留 WB 的 packet fields、真实 TL CacheImage、计数器、preservation gate、ACK 匹配与所有断言。没有以虚构接收端掩盖问题，也没有移除真实统计/控制连接。
2. `AI/Debug/scripts/stage2/Stage2Generate.scala`：同步移除对应 64 个 fixture sink，保留 33 个真实 L1 source 的只读接收端及全量审计；显式调用 getObject()，消除本次新增的 auto-application warning。
3. `SinkC.scala`：仅更新 CAM 已移除的说明，功能不变，身份继续来自同一 C transaction。
4. `stage2_validation.py`：汇总清除 ANSI、过滤三类 JVM options 普通提示，保留原始文本、行号与上下文；FIRRTL generic Internal Error 的摘要选其实际 Caused by。真实编译错误、OOM、门禁失败和原始退出码仍保留。生成完成检查共用同一诊断解析，普通提示不会单独把完整生成误判为失败。
5. 整机构建失败时，原运行器读取该次最终 appended annotation，输出所有 source/sink 数量异常及完整目标到 `system.wiring.out/json`，并并入 `.errors.out/json` 和 status 的 diagnostics。输入路径及 hash 随报告保存；文件缺失、损坏、无 wiring 和仅数量一致分别记录为 UNAVAILABLE、READ_ERROR、NO_WIRING、COUNTS_ONLY，均不称硬件 PASS。这只是同次失败后的诊断，不增加构建/仿真，不改变阶段门禁。
6. `test_stage2_validation.py`：补充彩色日志、stderr banner、cause 选择、原文保留、64 条批量 inventory、缺失/重复 source、缺失/坏 annotation、原始失败码和完整产物门禁回归。`all` 仍为 build→directed→system，不恢复已通过的 offline。

## 本轮实际检查

证据目录：`AI/TMP/stage2_system_wiring_fix_oo_upv1_/`。

- 56 项纯运行器回归通过（`runner.tests.out/json`），新增 9 项；最外层禁止 subprocess.Popen，硬件动作均为 mock，没有启动编译器或模拟器。
- 只读重判用户原日志副本，正确选择 `Caused by: ... gh_l1_l2_packet_tracked_15`；普通 options 提示不再算错误，保留 5 条实际错误/失败诊断，并完整列出 64 条孤立 pin。原日志及 annotation 未改写，见 `original.failure.reanalysis.json`。
- 源码精确差异核对、Python AST、shell syntax 和 diff whitespace 检查见 `checks.json`。旧 annotation 减去与源码删除严格对应的 64 个发布端后，余下 130 个 pin 没有数量异常；这是源码对应关系检查，不是重新生成或硬件验证。
- 保存修改前源码/用户改动快照、精确本轮 patch、原失败关键文件 hashes；原失败现场保持不变。未同步远端、reset、清理、提交或修改 sources/。

没有已知需要在新构建前先修复的阻塞。用户仍执行原绝对路径 `stage2_build_and_run.sh all`，自动新建 root、严格串行、失败停止。失败先看新 root 的 `system.build.wrapper.log.errors.out`；若为连线问题同时有 `system.wiring.out`，原始完整日志为 `system.build.wrapper.log`。

仍待用户验证：当前源码完整 Scala/Chisel/FIRRTL/firtool 与整机 C++ 编译、当前 33 pin fixture 的生成及结构检查、定向动态场景、整机运行和覆盖。旧运行器回归与旧模块构建成功均不能证明当前硬件行为正确，也不能排除更后阶段才会暴露的错误。
