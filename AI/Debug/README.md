# EC Debug Workspace

这是 Chipyard/BOOM/Rocket/GuardianCouncil 协同校验项目的长期 Debug 入口。BOOM 产生架构提交，Rocket checker 通过 GuardianCouncil/CDC 重放并比较，package sequence、DATA/ARF/CPS/END、LSL、snapshot/drain、cache/TileLink barrier 和 result/safe watermark 共同决定一次校验是否真正完成。

先读：

1. [`state/current_debug_state.md`](state/current_debug_state.md)：唯一当前状态、最新运行和下一步。
2. [`project/architecture.md`](project/architecture.md)：架构、数据流和核心 invariant。
3. [`project/source_map.md`](project/source_map.md)：关键源码路径；[`design/`](design/) 解释 barrier、snapshot/LSL/drain 和 Frontend/BJL，[`references/signal_map.md`](references/signal_map.md) 给窄信号入口。
4. [`bugs/`](bugs/)：已确认 bug、根因链、修复和验证边界。
5. [`history/timeline.md`](history/timeline.md)：按运行演化的历史；完整报告在 `history/reports/`。
6. [`scripts/README.md`](scripts/README.md)、[`skills/`](skills/)、[`checks/`](checks/)：可复用工具和审查流程。

长期结论、脚本、invariant 和小型证据放这里；VCD/FST、提取文本、generated RTL、对象文件和一次性日志放 `/data1/gzh/EC/AI/TMP`。原始 `Debug/` 和外部大归档均已按用户后续要求删除；删除记录、逐文件 SHA256 索引和保留边界见 [`references/archive_deletion.md`](references/archive_deletion.md)。

TMP 后续不得自行清空，只有用户再次明确要求清理才执行（见 [`../AGENTS.md`](../AGENTS.md)）。状态回写规则见 [`state/maintenance.md`](state/maintenance.md)，版本冲突见 [`references/conflicts.md`](references/conflicts.md)。

新一轮 Debug：保存现场和 manifest → 更新 current state → 先查旧 first-bad → RCA → 明确 invariant/Fix Design → risk review → implementation → Scala/Chisel/FIRRTL/static → module tests → simulation → independent validation → 回写 Debug 资料。可直接使用 `../DebugFlow.typ` 查看快速流程和 prompts。
