# 2026-10-10 TMP 收尾记录

本次用户明确授权清空 `AI/TMP`；该授权只适用于本次收尾，不延续到后续 Debug。

## 清理前检查

- 初始 `AI/TMP` 在任务开始时为空，没有尚未整理的用户脚本、关键结论或唯一证据。
- 原 `Debug` 4,911 个文件和原 `AI/Debug` 27 个文件曾在收尾阶段完成逐文件 SHA256、大小、分类和维护去向清点；索引在 `references/original_inventory.tsv`。
- 最新完整运行当时保留了完整独立备份；后续用户授权删除该备份，长期区保留日志、manifest 和模拟器结尾节选。
- 可重生成旧产物归类为 temporary-generated；按分类将4,714个中间物副本（8,099,076,023 bytes）实际转入 TMP/closeout，清单核对后清除。

## 本轮 TMP 生成物

| 内容 | 用途 | 长期处理 |
|---|---|---|
| closeout/ | 波形、信号提取、FIRRTL/RTL/build中间物的可清理副本 | 长期结论/窄证据已提炼；原件与完整备份后续按用户要求删除 |
| validation-tools/ | Typst Python 编译包 | 可重新安装；不保留 |
| DebugFlow PDF/渲染页 | 实际编译和版面检查 | DebugFlow.typ 保留，PDF 可重生成 |
| trace-smoke.txt | FST reader smoke check | 工具、命令和验证结果写回 references/validation_20261010.md |
| workspace-smoke/ | capture_run manifest smoke check | 保留工具；测试目录可重生成 |
| tools/fst-reader/ | reader 编译缓存 | 保留 C 源码和构建脚本；二进制可重建 |

初始 TMP 无需迁移资料；本轮 TMP 的有效结论是 Typst 编译、工具实际执行和 validation 结果，已写回长期文档。运行身份由 manifest、日志和 history/evidence 中的窄证据保留。

## 清理后规则

本次仅清空 `AI/TMP` 内容，保留目录本身。后续 Agent 可以使用 `AI/TMP/<run-id>/`，但不得自行删除或清空；只有用户再次明确要求才先核对并保留唯一证据后清理。

清理前的 workspace/archive/hash、工具和 Typst 复核已在 validation_20261010.md 记录；实际清理完成：AI/TMP 保留且为空（0个文件/子目录）。

## 后续授权：删除原 Debug

2026-10-10 用户追加明确要求删除 `/data1/gzh/EC/Debug` 及目录本身。再次核对全部 4938 原始文件的独立归档 hash/size 后，已删除该目录和其中 4911 文件。原始证据当前的保留/删除边界见 archive_deletion.md 和 inventory。

`AI/Debug` 长期资料仍保留，外部大归档已删除，`AI/TMP` 仍为空；未修改硬件功能代码，437 份 BOOM/Rocket Scala 源码 hash 与整理时一致，Chipyard/Software 工作树无 Git 差异。此次删除授权不延续到其他目录或后续 TMP 清理。

## 后续授权：删除外部归档并提交同步

用户随后要求删除外部归档及其内容，相关资料仅放在 AI 下，并以 `debug整理` 提交同步。保留内容和取证限制见 archive_deletion.md；索引增加 retention_status/archive_status，工作区检查改为核对原样保留证据，不再依赖已删除的大归档。

原根目录新增的 AGENTS.md 已移除，全部工作规则保留在 AI/AGENTS.md；TMP 的 Git 排除规则放在 AI/.gitignore。所有新增 Debug 文档和工具均在 AI 内。
