# 状态维护与收尾

1. 新问题建 `AI/TMP/<run-id>/`，保存 run manifest 和现场。
2. 先把 failure、已知事实、证据身份与下一步更新到 `current_debug_state.md`；未定位 first bad 就写“未定位”。
3. RCA、Design、Implementation、Validation 每阶段记录独立 evidence boundary。一个 root cause 一个 bug ID；revised RCA 显式说明旧判断被什么证据修正。
4. 完成一轮后，用最新状态替换 current 文件；完成的 chain 进入 `bugs/<id>.md` 与 `history/timeline.md`。新风险/方法进入 checks/skills，工具进入 scripts 并记录验证边界。
5. TMP 中保留完整中间现场。清理仅由用户手动决定，或用户再次明确授权后执行；先保留唯一证据和长期结论。
6. 本轮 2026-10-10 已获清空 TMP 的一次性授权；最终清理结果见 `references/cleanup_report.md`。

## Bug 最小记录

使用 `prompts/bug_record_template.md`；至少写 failure、last good/first bad、causal chain、broken invariant、root cause、fix、validation、regression、状态和 provenance。无法测到的项目写 unresolved，不补造事实。
