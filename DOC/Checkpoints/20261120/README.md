# 2026-11-20 会话与工作区归档

归档起点为主仓库 `75d41676a0f988946f416a56d198f31f5c464714`，分支为 `firesim/fpga-checkpoint-20261104`。

- [会话索引](../../Conversations/20261120/README.md)：其他 378 条本地会话，含用户请求与助手可见回复；来源缺失、损坏及恢复限制逐条记录。
- `classification-summary.json` 与 `initial-file-inventory.json.gz`：初始可见未跟踪文件的路径、大小、时间、分类。日志、波形、DCP、bitstream、编译中间文件和大型生成物继续留在原处，未删除。大型文件仅记录元数据，没有为本次整理重新计算内容哈希。
- `copied-source-manifest.json.gz` 与 `overlays/`：156,522 个复制源码文件的身份绑定。155,442 个文件可从起点提交还原，1,080 个不同文件以原始字节、权限或符号链接保存覆盖层，合计约 11 MB。C4、Native、Linux 与 OpenSBI 的来源分别记录，不能混成同一版本。
- `runtime-snapshots.json` 与 `runtime-snapshots/`：7,019 个状态/进度文件的带日期快照。原路径由后台服务继续更新并按生成物忽略；每份快照分别记录采集时间和 SHA-256，不代表跨文件原子快照。
- `nested-repositories-before.json`、`nested-status-before.json.gz` 与 `nested-commits.json`：113 个嵌套仓库的原始版本与改动，37 个新增归档提交及其分支。另有六个同级 EC worktree，检查时均已清空。
- `nested-bundles/`：37 个新增提交的增量 Git bundle，均通过对应仓库的 `git bundle verify`。恢复需要 `nested-commits.json` 中的 `before` 提交，bundle 本身不是独立完整克隆。

本次仅保存现有工作。两处尚未提交的硬件候选以 **未验证 WIP** 提交；没有重新运行硬件构建、仿真、综合、FPGA 部署或实验，也没有将候选认定为通过。原有后台任务继续运行，历史文档中的状态不代表本次的新结论。

还原复制源码时，在本目录运行：

```sh
python3 restore_sources.py --list
python3 restore_sources.py --source-prefix firesim/final-opt4-20261106/C4/chipyard --destination /tmp/ec-c4-restore
```

该工具要求目标目录为空，逐文件验证 SHA-256，只还原清单覆盖的源码集合；依赖、构建产物和原始大型证据仍需从原目录或既有备份取得。所有新提交均保留在本地，远端同步未执行。
