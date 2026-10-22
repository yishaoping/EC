# Stage3 编译错误与批量诊断 — 2026-10-18

STAGE3_STATUS=PATCHED_PENDING_REBUILD；STAGE3_CLOSURE=NO。

用户失败现场为 `AI/TMP/stage3_runs/run_5hyf3lau/`，HEAD 为
`1ed07c28067fad6d8aed697323b465b925895914`。BUILD 在 Scala compile 退出1；
DIRECTED/SYSTEM 未运行。原目录和日志保持原样。

## 证据与根因

`build/module.emit.log:90` 报 SinkC.scala:74:30 找不到 chiselTypeOf；
日志第112行明确 `one error found`，其余是源代码、编译失败汇总或 warning。
完整日志 SHA256 为
`1e215ef0c19136c25256b672546c7f4ea55f65fa0e5872275ba20cc10de008e7`。

直接症状：Scala 名称解析失败（已证实）。立即阻塞：InclusiveCache 编译失败，
Stage3 fixture 尚未进入 elaboration（已证实）。原因：该文件使用 legacy
`Chisel._`，新增 tie-off 以未导入的 chiselTypeOf 引用 API（已证实）。
下游影响：BUILD fail-fast，18 CASE 和整机均没有证据；未发现或推断协议故障。
即使 firstLevel 分支未被当前配置选中，Scala 仍需类型检查该分支。

修复仅把该处改为 `chisel3.chiselTypeOf(io.probe)`，不改变 tie-off 的硬件语义。
修复前 SinkC SHA256
`7e6d342aae1cec7c732761a80d4bc17f573dcc4f5d16a78a9895060843aced3a`
与该 run 的 inputs.json 完全一致；修复后为
`23d596fc2702696a0a6d10bd50371305e9afaa796b874ea323c4943275f29eae`。
静态搜索该 InclusiveCache 目录没有其他未限定的 chiselTypeOf；Stage3 fixture
已有 `import chisel3._`，不作无依据修改。

## 批量诊断与执行边界

Stage3 runner 复用 Stage2 已有的 failure_diagnostics；命令非零退出、wall timeout，
或退出0但 module 的错误/完成标记/RTL 门禁失败时，打印同一次日志的全部不同
错误/失败诊断及行号、上下文，保存 `<log>.errors.out` 和 `<log>.errors.json`。
JSON 保留日志 hash、原始行/上下文、重复次数和原始退出码；整机 build 失败继续
从该次实际 annotation 列出 wiring 数量异常。不降低错误严重度。

failure.json 增加 raw_exit_code、first_error 和 diagnostics。固定 summary 增加
RAW_EXIT_CODE、FAILURE_DIAGNOSTIC_COUNT、FAILURE_ERRORS_TEXT、FAILURE_ERRORS_JSON。
计数是去重后的日志诊断数，可包含编译器汇总/源码行，不声称是独立根因数。
本次日志实际只有一个编译错误；未编译到的后续源码/elaboration 问题不能凭空列出。
诊断写入异常不覆盖原始工具退出状态；timeout 仍返回124并保留子进程实际退出码。

诊断只写本次新建的日志旁边，不修改复用阶段或旧失败现场。仍使用唯一无参入口，
BUILD → DIRECTED → SYSTEM，失败立即停止，不为收集更多错误启动后续阶段。
本次 source 和 runner core identity 改变，旧失败 BUILD 不存在可复用的 seal，
原单一命令将新建目录重建；其他 identity/model/upstream 校验规则保持原样。

## 静态检查与待验证

仅 Python AST syntax、bash -n、git diff --check、完整原日志和源码/控制流静态 review。
STATIC_REVIEW=PASS。未执行 runner、单元测试、Scala compile、build、elaboration、
RTL generation、FIRRTL、Verilator、simulation 或 regression；新诊断运行分支和
当前硬件编译/功能行为仍待真实运行，不把静态 PASS 当成 BUILD PASS。

本轮文件：SinkC.scala、stage3_validation.py、scripts/README.md、
state/current_debug_state.md、history/timeline.md、本报告。未增加或删除用户入口，
未更改 preservation protocol；全部既有用户/Stage1/2/3 改动和现场保留。

下一步由用户执行原无参单一命令，agent 本轮没有执行。
