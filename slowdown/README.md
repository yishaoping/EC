# Current 同软件 GAPBS 512 实验准备

准备完成后由用户执行：

```bash
/data1/gzh/EC/slowdown/run_current_gapbs512.sh
```

默认 `--jobs 1 --seed 1 --max-cycles 500000000`。该命令将真实生成硬件、
构建独立 Verilator simulator 并仿真；本次 Codex 准备阶段没有执行这些操作。
只做身份/哈希/路径检查可直接调用 `scripts/launch_current.py --static-check`。

只核实运行环境、且在任何编译之前停止：

```bash
/data1/gzh/EC/slowdown/run_current_gapbs512.sh --preflight-only
```

该模式在正式运行相同的沙箱及 SBT 私有挂载中，批量检查 11 项工具版本、
实际 PATH 解析、只读挂载、网络 namespace、4 个 libc tmpfile/mmap、FST sidecar、
SBT socket、zlib ABI、SBT adapter 命令以及缓存 JAR 的存在性/大小。
还检查 SBT 两个本地 build 根目录使用独立可写 backing、源码条目保持只读、
14 个关键 Current 文件及两份 `build.sbt` 在挂载视图中的字节身份没有变化。
批量扫描 26 个编译依赖项目的 987 个 Scala 文件，校验 75 个 BlackBox 资源引用，
7 个动态引用按固定 Config 和源码哈希审阅；缺失或身份改变时在编译前统一报错。
工具版本命令不编译；adapter 只打印命令，不启动 SBT 或加载 project。
独立检查出错后继续收集其余结果，统一写入新建 build 目录的
`environment_preflight.json`，失败时正式构建不会开始。默认一键运行也执行同样的检查。
源码、脚本、软件或固定依赖身份漂移仍会拒绝运行，不自动接受新哈希。

软件固定为 Baseline 实际运行文件，运行时重新校验，绝不重新编译：

| 文件 | SHA256 |
| --- | --- |
| `/data1/gzh/EC/baseline/software_common_builds/gapbs512_20261023_03/test.riscv` | `da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c` |
| `/data1/gzh/EC/baseline/software_common_builds/gapbs512_20261023_03/test.loadmem_hex` | `f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad` |

`DIRECT_EVIDENCE`：Baseline 参考运行
`baseline/runs/b3_20261023_162309_15ywsnjz/run_manifest.json` 的 ROI 为
`1,001,675`，hart0 rdcycle 从 `181025` 到 `1182700`，软件 PASS、退出码 0。
Current 使用同一 ELF 的 `common_roi_start` / `common_roi_stop`，PC 分别为
`0x80000340` / `0x8000039c`。ROI 包括 AMO.W self-check、BFS512 和
STOP/session completion，不包括随后打印、HTIF 退出和 drain。interval 不使用。
输入是确定性 directed ring+1..16，512 nodes、8192 edges、source 0，无外部输入。
timer flag 保留每 hart 64-byte 布局；BOOM hart0，checker harts1–4。

`STATIC_INFERENCE`：软件 PASS 且恰好一条完整一致的 ROI 时，脚本才按
`delta=current-1001675`、`slowdown=delta/1001675*100` 和
`ratio=current/1001675` 计算；其他情况写 `CURRENT_RUN_NOT_COMPARABLE`。
这是当前整体实现及 Config 与 b3 的同软件 ROI 对比；现有 BOOM/L1/L2 参数
差异仍存在，不能把差值单独归因给 preservation 或 set freeze。

`UNRESOLVED`：旧 Current 的 `RUN_PROVENANCE=UNRESOLVED` 不变。
Baseline 原 manifest 的 provenance、完整正确性和 cache/package/DRAM drain
限制不变。新 run 独立记录身份；运行身份完整不等于完整正确性证明。
Current 按已有 driver 的 `STAGE1_EXIT_PORTS` 路径，在 host success 且
`stage1_l1_drained` 后退出；退出 drain 在 ROI 之外，且不证明外层全部 drain。

源文件只有 trace alias/dontTouch 增量，见
`manifests/current_trace_only.patch`、`donttouch_inventory.md` 和
`trace_change_review.md`。`scripts/prepare_trace_visibility.py` 已改为可重复的
只读检查器，不能再插入 alias 或覆盖源码。没有 reset/stash/checkout/clean，
没有修改 index、软件、Config、cache 控制或屏障。

所有运行和构建产物均在新建的 `slowdown/build/<run_id>` 和
`slowdown/runs/<run_id>`。脚本以只读 host root 的 bwrap 环境调用工具，仅
`slowdown/`、私有 `/tmp` / `/var/tmp` 以及映射到 `slowdown/build` 的 SBT
build 根目录条目、meta-build/target 可写。Current 功能源码仍直接读取原路径。
其中 Chipyard 和 `sims/firesim/sim` 两个本地 SBT build 只有根目录 inode 由
`slowdown/build/<run_id>/sbt-roots/` 私有 backing 提供；普通源码文件及子目录
逐项只读绑定，project/target 使用本次构建副本。这样 SBT 的 `File.canWrite()`
可以直接使用本地 build，避免在命令行 target 设置生效前递归 staging 整棵源码。
不会恢复、编译或运行 FireSim workload；共享的 `targetutils` Scala 库依赖保留。
`/proc` 复用现有只读挂载，不调用本机拒绝的 `bwrap --proc`；
不以关闭沙箱或联网作为回退。启动与离线提取共用 `scripts/sandbox_support.py`。
各次 build 的 `tool-bin` 把 Make 实际按名称调用的工具绑定到记录的路径，避免
记录 Nix Verilator、实际却因 Conda PATH 优先级使用另一版本的问题。
34 个 SBT project 使用带 build 身份的显式 `ProjectRef / target` 和独立输出路径。
禁止旧的 `set every target ... thisProject.value.id` 写法：该写法曾将所有项目指向
`chipyardRoot`，导致 classes、增量缓存和 copyResources 互相覆盖。
project/target 的预加载写入另用私有 mount；DRAMSim 编译使用外置副本。
共享工具与 Baseline 缓存只读复用，依赖缓存
的写副本放在 `slowdown/cache`。脚本持有独占锁，每次创建唯一目录，不复用旧模型。

`DIRECT_EVIDENCE`：2026-10-23 修复阶段已经执行工具版本和临时文件环境预检；
原始复现与修复记录见 `manifests/launcher_repair_20261023_j737m2s1/repair_report.md`。
后续 SBT 只读目录 staging 修复及实际预编译 resolver 方法验证，见
`manifests/sbt_local_project_fix_20261023_ybzwpsob/repair_report.md`。
本轮 BlackBox 输出隔离修复及批量资源检查见
`manifests/sbt_resource_isolation_20261023_t7op9sjg/repair_report.md`。
`UNRESOLVED`：修复检查没有执行 SBT project load、Scala/C++ 编译、硬件生成
或仿真。此前用户正式启动已进入 Scala 编译并在 BlackBox 处理阶段失败，
不能把本轮环境预检通过描述成修复后的完整构建或运行成功。
遇到未覆盖的硬编码写路径，沙箱仍会拒绝写入并保留日志。

正式运行时，adapter 先读取 SBT 实际求值的 34 组 target/classDirectory，确认独立
且没有目录逃逸；随后单独完成 Scala 打包，读取实际 runtime classpath，批量检查
资源所属 JAR 的内容哈希和同名资源的首选提供者，全部通过后才执行 Generator。
这两项运行检查仅由用户正式启动时执行，`--preflight-only` 不会加载 SBT project。
每步日志写入新建的 `build/<run_id>/sbt_input_guard_*/`；资源检查不解压 JAR、
不恢复缺失 RTL，也不从 Baseline 混入资源。旧失败 build 保留，不复用其中产物。

新运行预期保留：`test.log`、`stdout.log`、`stderr.log`、`command.txt`、
`run_manifest.json`、`roi.json`、`waveform.fst`、`waveform_hierarchy.txt`、
`trace_completeness.json`，以及 generated model、simulator 和工具身份。
缺少最低信号组返回 `TRACE_INCOMPLETE`；hierarchy 完整也不保证每个值有有效
transition。大波形的哈希和复制可能耗时，构建/仿真阶段每 60 秒输出进度。

离线工具用法见 `analysis/README.md`。这轮没有对旧波形运行新 native reader。
