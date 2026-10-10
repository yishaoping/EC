# 2026-10-10 整理验证记录

- 整理阶段的原始文件 hash/size 清点完成；逐文件索引保存在 `references/original_inventory.tsv`。
- `check_debug_invariants.py .`：PASS；源码 marker、sequence-aware ordering、type-specific readiness、overflow、context/progress marker 可见；这是 triage，不是语义证明。
- `check_assert24_hardware_fix.sh`：PASS；当前检查名为 source-marker check，不是 invariant/dynamic proof。
- 4 个本地 skill：`skill-creator quick_validate.py` PASS。
- 所有 maintained shell/Python scripts：syntax/compile PASS。
- FST reader：在独立 archive latest-run/test.vcd 上成功读取 `0..1200` 和 profile；无匹配信号、START>END 会明确报错。
- `summarize_trace.py`：smoke JSON PASS；默认不保存全量 event list。
- `DebugFlow.typ`：Typst 0.15 实际编译为 2 页 PDF，pdftoppm 页面渲染检查通过。
- 437 份 BOOM/Rocket Scala source hash 与收集时一致；`git diff --name-only -- chipyard Software` 为空，未修改正式功能代码。
- 未在本轮运行 Chipyard compile/elaboration/simulation；整理任务只验证 Debug infrastructure。历史编译/生成/仿真结论按原 report 的 evidence boundary 保存。

## 用户追加删除原 Debug 后的复核

- 删除外部归档前已核对 4938 个来源索引条目；原 `Debug/` 及全部 4911 文件和外部归档已按用户明确要求删除。
- `AI/Debug` 保留长期资料与窄证据，`AI/TMP` 仅作为后续中间产物目录。
- 437 份 BOOM/Rocket Scala 源码 SHA256 仍与 manifest 一致；`git diff --name-only -- chipyard Software` 与相应 Git status 均为空。

## 删除外部归档并准备同步后的复核

- 外部归档目录已删除（4953 文件、11,829,172,632 bytes），所有保留 Debug 资料均在 AI 内。
- 更新后的 `check_workspace.py --verify-retained-hashes`：PASS；216 个原样保留来源条目 hash/size 匹配，8 个维护版脚本明确标记 retained-updated，4714 个临时来源条目明确标记 deleted-by-user-request。
- 未发布的大提交仅排除旧 Debug 路径；与原基线比较，chipyard/Software tree 完全一致，437 份 Scala 文件 hash 没有变化。Git HEAD 映射见 git_sync_manifest.json。
- Scala/硬件内容不变，本轮没有重复硬件 compile/elaboration/simulation；工具 Python 语法、维护链接和 AI 路径检查通过。
