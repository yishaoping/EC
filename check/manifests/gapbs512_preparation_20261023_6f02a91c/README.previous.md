# 历史检错版 Baseline 独立实验入口

完整提交：**b3d7adddd1e2d2cf428dd933529de878226420cd**；父提交：`6d899a71d68e5e15cb4c108a48375ea60edb2280`。独立源码位于 `source/`，Config 为历史 `chipyard.v1Config`。活动源码采用 `main/scala`，inclusive cache 采用 `design/craft`，没有混入 current 的保护机制或修改硬件语义。

**本轮没有执行启动脚本，包括 --help、--check；没有执行硬件生成、elaboration、编译、仿真、测试或 workload。** 只执行源码恢复、独立文件复制、只读审阅及静态语法检查。

## 用户手动使用

查看帮助和只做静态环境检查：

```bash
/data1/gzh/EC/baseline/start_baseline_experiment.sh --help
/data1/gzh/EC/baseline/start_baseline_experiment.sh --check
```

`--check` 不运行 make、SBT、工具版本探测或 simulator。单独构建无需先选软件；用户执行以下命令后，才会生成硬件和编译 simulator：

```bash
/data1/gzh/EC/baseline/start_baseline_experiment.sh --build --jobs 1
```

每次创建新的 `build/b3_<时间>_<随机后缀>/`，并输出 `BUILD_COMPLETE=<绝对目录>`。先检查隔离和工具版本，失败立即停止。保留全部失败输出，不自动清理，不使用失败产物启动仿真。

运行前须在 `software/` 下准备新的、已核对的软件描述 JSON，可参考 `software/historical_workload.template.json`。原模板保持 UNRESOLVED，不能直接运行。描述文件记录 ELF 路径与 SHA-256、软件来源、b3 硬件 ABI 兼容性依据、计时边界、退出/drain 依据及程序正确性标记。只有具备具体依据后才将 `baseline_compatibility` 填写为 `REVIEWED_FOR_BASELINE`；仅修改字符串不构成兼容性证据。保留原始模板和候选描述。

填写并审阅一个新文件，例如 `software/reviewed_workload.json` 后，用户可执行：

```bash
/data1/gzh/EC/baseline/start_baseline_experiment.sh --check \
  --workload /data1/gzh/EC/baseline/software/reviewed_workload.json

# 将下面占位目录替换为脚本实际输出的 BUILD_COMPLETE 路径。
/data1/gzh/EC/baseline/start_baseline_experiment.sh \
  --run /data1/gzh/EC/baseline/build/<BUILD_COMPLETE目录名> \
  --workload /data1/gzh/EC/baseline/software/reviewed_workload.json

# 或明确启动一次新构建和一次仿真的完整流程：
/data1/gzh/EC/baseline/start_baseline_experiment.sh --all --jobs 1 \
  --workload /data1/gzh/EC/baseline/software/reviewed_workload.json
```

不传阶段参数时只显示帮助，不隐式选择软件。可显式设置 `--seed`（默认 1）和 `--max-cycles`（默认 500000000）。`inputs` 当前须为空：尚无证据支持其他输入的历史 argv/文件映射，脚本会拒绝猜测。

## 隔离与复用依据

- 源码采用独立 `git clone --no-local --no-checkout --no-tags`，仅在 baseline clone 内 detach 至完整 SHA；无 alternates、硬链接或 worktree。
- 每次构建将完整历史源码和独立 Git 元数据复制到该次 `build/.../source/`。历史 Makefile 会在源码树内生成 SBT target 和 DRAMSim 对象，因此副本属于本次构建目录；规范的 `baseline/source/` 在执行隔离中只读挂载。
- 所有实际工具、构建和 simulator 子进程通过 `/usr/bin/bwrap`：宿主文件系统只读，仅 baseline 可写，规范源码及本次副本 Git 元数据只读，网络隔离。隔离不可用即停止，没有无隔离后备路径。本轮未启动隔离进程，其运行可用性尚未验证。
- 复用本机 `.conda-env` 的 RISC-V、JDK、firtool、SBT launcher，以及现有 Verilator/Nix 编译环境作为外部只读工具。未安装、升级或重建工具链。精确路径在 `manifests/environment.json`，实际版本和哈希由用户构建/运行时采集。
- 已独立复制 `/home/guozh/.cache/coursier` 和 current 的 `.sbt/boot` 至 `baseline/cache/`，未使用硬链接或符号链接，未复制全局 SBT 插件或 current 硬件 target。缓存完整性未经构建验证；网络隔离下缺失依赖就停止，不自动下载或升级工具链。
- TMPDIR、Java tmp、Ivy/SBT/Coursier、XDG、ccache 均指向 baseline。保留 HOME 环境变量原值，Java `user.home` 显式重定向；宿主 home 只读，未知固定写入将失败。
- make 命令结构取自 `AI/TMP/control_stop_sync_20261021_audit/source/stage1_build_and_run.sh`，并核对 b3 的 `sims/verilator/Makefile`、`variables.mk`、`common.mk`。采用 `debug`、`CONFIG=v1Config`、`VERILATOR_FST_MODE=1`，不带 current 的 `STAGE1_EXIT_PORTS`。
- 仿真参数参考同目录 `stage1_run_trace.sh`；`-v`、`-s`、`+cycle-count`、`+max-cycles` 与退出条件对照 b3 `emulator.cc`，DRAM/loadmem 参数对照 b3 `variables.mk` 及 testchipip。不会调用 current 的 AI/Debug 脚本、生成模型或 simulator。
- 每次运行新建 `runs/b3_<时间>_<随机后缀>/`，保存输入副本、实际 argv、白名单环境、工具版本/哈希、源码和模型身份、日志、FST、退出码、周期提取及 marker 结果。仅接受本入口成功构建并通过哈希核验的模型和 simulator。

## 未解决的软件与依赖

1. b3 记录 `Software/R-Kernel` gitlink `9978da2da42a5f53f690d99d92c64013a0cb72b9`，本机对象不可用，根 `.gitmodules` 缺少映射；未以 current 替代。所查硬件 build 和 Software/Test 不引用它，故保留硬件构建入口；不能声称完整历史依赖闭合或可重建该内核。
2. 历史 `source/Software/Test/test.riscv` 为 18040 bytes，SHA-256 `5b27ff378ac84ac4c0c0a6f07999e456adffe0866c071ed17be56ed200454b34`。ELF 是 RISC-V，入口 `0x80000000`，含 tohost/fromhost。可以显式选择历史驱动支持的 ELF/HTIF 加载方式（loadmem 为 null），但软件正确性和退出/drain 尚未运行确认。历史 `TC_OverTaking.riscv.loadmem_hex` 不被当作该 ELF 的配套输入。
3. 已核验并保存 `AI/TMP/stage1_workload.json` 对应的修复后软件至 `software/fixed_candidate/`，包括 ELF、loadmem、dump 和原 manifest。ELF 哈希 `f5f84a1727e1c5466bd69e5e89c96410f1622297c1e62bf31408f176a2b65610`，loadmem 哈希 `a3b7a4f8e50cc28101b0a51f55406595fb113f9695ca54ee912555138fe7894c`。这些是显式候选，没有自动选用。
4. **不能直接认定修复后软件兼容 b3。** b3 `Software/Test/ghe.h:165` 和 `GHE.scala:279` 表明 funct 0x76 只有 reset 与 5-bit selector；current `Software/Test/hw/ghe.h:69` 的 START/STOP 使用 bit 5/6，interval 使用 funct 0x79，且存在新增流量统计/退出接口。统计 ABI 不同，候选描述保持 UNRESOLVED，脚本默认拒绝启动它。本轮未编译兼容软件或修改硬件协议。
5. 配套 loadmem 如使用，须显式记录来源、哈希和地址；格式须符合历史 mm.cc 的小写、偶数字节十六进制行。无配套 loadmem 时可以显式选择 ELF/HTIF，不能静默换用另一份 ELF 或 loadmem。

## 统计与正确性边界

历史 emulator 的 Completed after N cycles 是 harness `trace_count`：包括 100 次 reset 循环，再按 harness 循环递增，直到 dtm/tsi/jtag done、io_success 或 timeout。不能自动视为 BOOM 时钟周期、软件 ROI 或退出 drain 周期，更不能直接用于已闭合的成对性能比较。

脚本分别记录 simulator 返回值、软件自定义 marker 和 harness cycle 字段。marker 全部出现也只标为 `PROCESS_AND_EXPECTED_MARKERS_PASSED`；架构、包完成及 drain 正确性和 `complete_experiment_success` 仍须审阅。ROB gate、冲突等待和关键路径周期没有新增计数器，保持 UNRESOLVED。

`RUN_PROVENANCE=UNRESOLVED` 保持不变。未来比较 current，须使用同一 ELF、loadmem、输入、配置容量/频率、seed、计时边界和退出规则，并分别记录模型/simulator 哈希及正确性证据。当前只完成环境准备。
