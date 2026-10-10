# EC Debug 工作区规则

本文件适用于 AI 下的资料、工具和 Debug 临时文件；正式 Chipyard 功能改动必须遵循用户当轮任务范围。

所有 Debug 基础设施、文档、来源清单和临时产物只允许存放在本 `AI/` 目录下；原 `Debug/` 和外部归档已按用户要求删除。

- 新 Agent 先读 `Debug/README.md`，再读 `Debug/state/current_debug_state.md`。架构在 `Debug/project/`，历史在 `Debug/history/` 和 `Debug/bugs/`。
- root cause 未确认前不 patch；先找当前运行的 first bad / first divergence，核对旧 first-bad 是否消失。
- FST/VCD、generated RTL、编译对象、信号提取和一次性输出写 `TMP/<run-id>/`；长期结论、脚本、skill 与小型关键证据写 `Debug/`。
- **后续 Debug 不得自行删除文件或清空 `AI/TMP`。只有用户再次明确要求清理时，才先检查并保留有效脚本、关键结论和唯一证据，再执行删除。** 本次 2026-10-10 收尾授权只适用于本次任务，不延续到下一轮。
- 每轮完成 RCA → Design → Implementation → Validation 后更新 current state；历史结论进入 bug/history，通用经验进入 skill/check，复用脚本进入 scripts。未动态验证的问题继续写 unresolved。
- 保存 provenance；旧报告中的 current/源码行号/time window 只属于原运行。禁止把新源码、旧生成物和不同波形静默拼接。
- Scala compile、elaboration、FIRRTL/组合环、模块测试、整机 validation 分别记录；程序退出/package PASS 数平衡不能替代功能正确。
