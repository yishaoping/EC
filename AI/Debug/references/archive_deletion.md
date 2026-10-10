# 原始大归档删除与保留边界

2026-10-10 用户明确要求删除 `/data1/gzh/EC-debug-archive/` 及全部内容，并要求 Debug 相关资料只存放于 `/data1/gzh/EC/AI/`。

删除范围：原始完整副本与 latest-run 独立备份，共 4953 文件、11,829,172,632 bytes。它们主要是 FST、信号提取、generated RTL/FIRRTL、构建对象和完整仿真输出；没有将这些大归档重新搬入 AI。

长期保留在 AI/Debug：

- 全部 60 份原始报告、130 份窄证据、16 份修复来源材料、10 份手写回归源码。
- 8 份更新维护的工具源码/脚本。清单的 original SHA256 属于旧版本；retained-updated 明确表示维护版已有修改。
- 最新 test.log、源代码/运行 manifest 和 test.out 末尾 20 行（completion_excerpt.txt），保留模拟器 PASSED 与软件 FAIL 同时存在的依据。
- original_inventory.tsv 的 4938 条来源记录、大小、SHA256、用途、保留去向和删除状态。

retained-exact 的 216 个来源条目可重新核对完整字节；8 个 retained-updated 条目通过维护文档解释修改。4714 个 temporary-generated 来源条目已删除，清单仅保留 provenance，不能凭 hash 恢复原始波形或重做全量取证。

原始报告中的旧路径与行号属于历史引用。完整原始波形已经没有独立备份；chipyard/sims/verilator/output 的原运行文件本次未修改，但它们可能被后续仿真覆盖。需要进一步分析时，先保存新运行的 manifest 与波形到 AI/TMP。

AI/TMP 保留为空目录；本次删除授权只针对指定外部归档，不延续到后续 TMP 清理。
