# DAC 前四项实验：准备状态与执行入口

本目录是实验工具包，独立 FireSim 安装在 `/data1/gzh/EC/firesim/upstream`。
运行环境在 `/data1/gzh/EC/firesim/envs/manager-1.17.1`，不使用原
`/data1/gzh/EC/chipyard/sims/firesim` 作为实验安装或运行入口。
原 Chipyard 只作为 EC 设计源码输入和版本参考，修改必须在 FireSim 下的副本进行。

**当前不是可发表结果，也没有已验证的实验 bitstream。** 已准备的工具、候选配置、
源码与可运行的完整 Linux/保护系统是不同交付层级。真实阻碍见
`config/readiness.json` 和 `Experiment/dac2026/preparation` 下的环境报告。
本次没有运行 FireSim/RTL/QEMU/Spike 仿真，没有运行 PARSEC，也没有烧写、复位、解绑、
重扫 PCIe 或操作驱动。宿主机单元测试和编译语法检查不属于端到端实验验证。

## 目录与版本

```
/data1/gzh/EC/
  Software/PARSEC/                       从 /home/wtl/parsec_gc 复制的参考快照
  firesim/
    upstream/                           独立 FireSim 1.17.1
      target-design/chipyard/            FireSim 自身 gitlink 固定的 Chipyard
    envs/manager-1.17.1/                 独立环境，不改现有 Chipyard 环境
    conda-env/                          首次离线安装的失败残留，保留用于审计
    dac2026/
      config/                           矩阵、站点、工作负载、综合输入与就绪状态
      ec_dac/                           宿主机检查、计划、采集、恢复、分析代码
      measurement/                      C++ 被动统计核心、Python 参考、ROI ABI
      guest/                            单次 Linux 启动内批量执行与输出校验
      area/                             ASIC 综合 Tcl
      scripts/                          8 个阶段入口
      work/parsec-20261102/              可修改的 PARSEC 插桩副本
  Experiment/dac2026/
    preparation/                        安装记录、版本、设备/进程及源码指纹
    campaigns/<campaign>/               原始日志、逐样本状态、快照和原子结果
    build-logs/                         编译/综合记录（不存 guest 内）
    reports/<report>/                   新建的分析报告/CSV/PNG
    area/<configuration>-<run>/          target RTL 综合输出
```

固定版本：FireSim tag `1.17.1`，commit
`b473147af03edc854a5bc2a95d1bc404c8711b2a`；其 Chipyard gitlink
`336f225143590f9060ebe7101e96f235f96db985`，对应 1.10.0/Chisel 3.5.6。
EC 原树是 1.9.0/Chisel 3.5.5 加本地修改；**二者的设计移植和编译兼容性尚未验证**。
选 1.17.1 是为使用 1.17 系列已引入的原生 Alveo/XDMA 平台，并匹配其 U280
Vivado 2021.1 构建脚本；不是拼接最新分支。源码证据位于独立安装的
`CHANGELOG.md`、`.gitmodules` 和 U280 构建文档中。
上游标准 setup 会涉及额外工具或驱动步骤，本次没有调用，不能用它自动“补齐”服务器。

参考 PARSEC 是 `3.0-beta-20150206`，自身 Git commit
`654d2496b3251d5613e9114b331087453f7a3271`，带已有修改。
目录名 `amd64-linux.gcc-serial` 下的多个 ELF 实际为 RISC-V 静态程序，不能按目录名
判断 ISA。其编译配置链接了另一项目的 checker 对象，所检 blackscholes ELF 无 ROI
hook 符号，未直接准入正式矩阵。原配置和二进制均保留。
工作副本已移除该外部对象链接、加入 `gcc-dac` hooks 配置并插入 ROI 调用；尚未构建。
副本中的源内绝对符号链接已重定向，避免构建写回 `/home/wtl/parsec_gc`。

## 统一配置与就绪门槛

| 逻辑配置 | Rocket 实际结构数 | 实现准备状态 |
|---|---:|---|
| B | 0（候选的真实无保护定义） | 缺同参数、无保护 RTL；不能把关闭 GHE 当成 B |
| D2 / D4 / D8 | 2 / 4 / 8 | 历史检错源码可用，但须移植同一 BOOM/cache 与测量接口 |
| C2 / C4 / C8 | 2 / 4 / 8 | 当前纠错源码可用；结构数量和新 FireSim 接入待构建验证 |
| C4-no-real-barrier | 4 | 选定的一项诊断消融，完整保护能力被削弱 |

共同候选参数：单 BOOM、应用线程 1、BOOM/uncore 200 MHz、Rocket 100 MHz、
ParaMedic 3-wide/ROB42、L1I 32 KiB、L1D 32 KiB/2-way/6 MSHR、L2 1 MiB/16-way。
本阶段输入候选 `simsmall`，无预热、每样本新进程、保留 Linux page cache、每次排空 checker。
这是明确的共同实验策略，不代表真实冷缓存。若改策略、线程或输入，需新 campaign。
FASED 必须为 200 MHz 校准，不能沿用 1 GHz 默认时序。

仅发出候选 Scala 文件，不会直接覆盖设计源码。8 Rocket 需要 hart 8，现有 3 bit
target/control 路径不足，不能只改 `GH_NUM_CORES`。未验证运行时 mask 等价性，默认
不复用 bitstream；7 是逻辑主配置数，当前认证的 bitstream 数是 **0**。
D4/C4 在主实验执行后直接复用于扫描，不再重复设置一套“默认”实验。
历史 D 的 BOOM、L2 与 C 不一致，现有历史数据不作为本论文 B 或公平 D 对照。

选定消融使用真实存在的 `GH_REAL_BARRIER_ENABLED=false`，观察无故障下 L2 barrier
请求及 BOOM force-close 的代价；它不关闭全部 L1/SVB preservation，也不是 D。
可与 C4 的差值解释这个开关覆盖的机制，不能称为全部纠错开销，更不能把各差值相加。

尚需：同参数 B/D、8 核编号路径、Linux checker 运行时/DT 预留、ROI 驱动与被动桥接、
精确执行完成与最终比较事件、CDC 时间基准、核实卡型号/序列号、独立构建与输入验证。
`config/site.json` 的布尔门槛必须由实际证据和对应文件 hash 支持，不能为绕过门槛手改为 true。

## 可复制命令与影响范围

以下命令均从根目录开始；除明确带 `--execute` 的运行/部署入口外，不启动实验。
所有已有输出目录都保留，分析、候选和准备目录重名时退出，不能覆盖旧实验。

```bash
cd /data1/gzh/EC
source firesim/dac2026/env.sh
python3 firesim/dac2026/dac.py --help
command -v firesim python3 riscv64-unknown-linux-gnu-gcc
```

环境加载只设置路径和并行度，不加载驱动、不启动 ssh-agent 或仿真。
应看到 FireSim 来自 `firesim/upstream/deploy`，Python 来自独立 manager 环境。
`firesim --help` 已通过；这只验证 manager 导入/CLI，不证明 EC target 可构建。
Manager 配置候选与使用边界见 `config/firesim/README.md`。

### 1. 只读检查、候选和编译准备

```bash
scripts=firesim/dac2026/scripts
bash "$scripts/01_static.sh"                 # 新报告；就绪阻断时退出 2 是预期结果
python3 firesim/dac2026/dac.py candidates --out firesim/dac2026/work/config-candidates-NEXT

# 只读逐文件哈希/符号链接核验；新建报告，不修补或覆盖参考源码：
nice -n 10 python3 firesim/dac2026/scripts/verify_parsec_copy.py \
  --out Experiment/dac2026/preparation/parsec-copy-check-NEXT

# 已有 parsec-20261102 副本无需重复创建。新副本按新名字准备：
python3 firesim/dac2026/dac.py prepare-parsec \
  --destination /data1/gzh/EC/firesim/dac2026/work/parsec-NEXT   # 仅预览
# 加 --execute 只复制/插桩源文件，不执行 benchmark。

python3 firesim/dac2026/dac.py build-parsec \
  --work /data1/gzh/EC/firesim/dac2026/work/parsec-20261102 \
  --benchmarks blackscholes swaptions --jobs 2               # 仅预览
# 加 --execute 仅编译；本次未执行。须先确认交叉 configure 不启动 QEMU。
# execute 还要求工作副本 DAC_BUILD_REVIEW.json 的脚本审查/hash；
# 字段见 config/parsec-build-review.example.json。--host/--build 本身不能替代审查。

python3 firesim/dac2026/dac.py build-hardware \
  --recipe firesim/dac2026/config/build-recipe.example.json  # 模板未就绪，明确退出
```

只读检查不打开 FPGA 字符设备。进程、sysfs、设备节点及可见 FD 共同记录；没看到 FD
绝不等于空闲。初始观察：`e2:00.0 -> xdma0`、`21:00.0 -> xdma1`，两卡均有 FireSim
进程；普通账号也无法读取所有进程 FD，所以部署被阻断。驱动器名提示 U280，完整板卡
型号/序列号尚不能仅凭 `10ee:903f` 确认。

依赖镜像准备见 `images/README.md`；不能把 FireMarshal 的 build 当成绝不调用 QEMU。

### 2. 短程序及少量 PARSEC 测量链路

先完成 `measurement/INTEGRATION.md` 中的实际接入。`guest/roi-smoke.c` 只供手动执行。
它在没有真实 `/dev/ec_dac_roi` 驱动时退出 125，绝不伪造有效 ROI。
工作负载准入前，用 RISC-V `nm/objdump` 检查 hooks 和两条 marker，校验输出和输入 hash，
再按 `config/benchmark.example.json` 填入 `config/benchmarks.json` 的 `benchmarks`。
输入列表必须包含 validator 用到的可信 reference 文件。短 smoke 可设 `stages:["link","recovery"]`，
避免混入正式 PARSEC 矩阵；未指定 stages 的 PARSEC 默认在各阶段可用。
初始优先 smoke、blackscholes、swaptions；其他候选见该注册表，不静默删除失败项目。
注意需要 guest Python3、可读输入、可信输出 verifier；已有二进制不能因 ELF 合法就准入。

```bash
python3 firesim/dac2026/dac.py plan --campaign link-v1 --stage link --reps 1
bash "$scripts/02_link.sh" --campaign link-v1                 # 预览
# 门槛及链路前置检查满足后，由你添加 --execute；涉及目标卡部署、复位和仿真启动。
```

首次链路使用 `deploy --phase link`。它要求实际结构/镜像/checker/observer 审查证据及
`structural_ready`，正式实验另要求完整运行验证；字段见 `config/compatibility.example.json`。
可先 `plan --stage link --configs C4` 只验证已具备结构的 C4；不能将它当作 B/D/C 已可比。

### 3. 中断恢复（只由你启动）

至少准备同配置两个可完成的样本，使用专用 recovery campaign，避免正式数据混入链路验证。
`--interrupt-after 1` 在一项完成、下一项已写 start 之后中断本脚本创建的 adapter 进程组。
它不杀既有任务；部分数据和日志继续保留。中断点不是指令检查点。

```bash
python3 firesim/dac2026/dac.py plan --campaign recovery-v1 --stage recovery --reps 3
python3 firesim/dac2026/dac.py deploy --config C4              # 预览目标卡/影响范围
# 部署通过且你准备运行后，手动执行带 --execute 的 deploy。
bash "$scripts/03_recovery.sh" --campaign recovery-v1 --config C4   # 预览
# 手动在上一条加 --execute 才启动恢复验证仿真。
python3 firesim/dac2026/dac.py status --campaign recovery-v1
python3 firesim/dac2026/dac.py recover --campaign recovery-v1
python3 firesim/dac2026/dac.py pending --campaign recovery-v1 --configs C4
python3 firesim/dac2026/dac.py run --campaign recovery-v1 --config C4   # 预览补跑
# 手动添加 --execute，完成后再次 status；比较 results 中原完成文件的 sha256 应保持不变。
```

恢复只能在前一 runner/collector 已停止后进行。独占 writer lock 防止误将正在运行的样本
标成 interrupted。完成文件与输入/源码身份都有效才跳过；running 恢复为 interrupted；
没有开始的样本保持 pending；失败、超时和中断样本整项重跑，不能从快照继续指令现场。

### 4—6. 正式主实验、数量扫描、消融

```bash
python3 firesim/dac2026/dac.py plan --campaign paper-v1 --stage all --reps 3
bash "$scripts/04_main.sh" --campaign paper-v1 --repeats 1    # 先各一轮，预览
# 你确认后加 --execute；确认有效，再补齐余下重复：
bash "$scripts/04_main.sh" --campaign paper-v1 --repeats 2 3  # 预览
bash "$scripts/05_scan.sh" --campaign paper-v1 --repeats 1    # D2 C2 D8 C8
bash "$scripts/05_scan.sh" --campaign paper-v1 --repeats 2 3
bash "$scripts/06_ablation.sh" --campaign paper-v1 --repeats 1
bash "$scripts/06_ablation.sh" --campaign paper-v1 --repeats 2 3
```

阶段入口以硬件配置分组：每配置至多部署一次、启动一个 adapter/Linux，内部顺序执行全部
待运行 benchmark 和重复；应用每次是独立新进程。失败一项先 seal/drain，再继续下一项；
排空失败则整批停止以防污染。模板尚无可用 backend 时拒绝启动，不回退为无保护执行。

### 7. 失败、超时、中断和缺项补跑

```bash
python3 firesim/dac2026/dac.py recover --campaign paper-v1
python3 firesim/dac2026/dac.py pending --campaign paper-v1
bash "$scripts/07_rerun.sh" --campaign paper-v1 --config C4 \
  --benchmarks blackscholes --repeats 2                     # 预览；手动加 --execute
```

### 8. 汇总与出图

```bash
bash "$scripts/08_analyze.sh" --campaigns paper-v1 \
  --out /data1/gzh/EC/Experiment/dac2026/reports/paper-v1-r1
# 多 campaign 时可列多个；同 sample_id 的冲突完成记录会报错。
```

分析不会调用仿真，输出 measurements/slowdown/progress/missing-failed CSV、summary JSON、
分位数区间、CDF、2/4/8 曲线、消融、排空/队列/阻塞/小核利用率图。某阶段数据不足时
明确列缺项，不画虚构图。默认、扫描、消融各自只在相同 benchmark 交集上计算几何均值，
同时列出被排除的 case。三次重复只完成两次的配置不进入完整比较。CV >2% 仅是波动
诊断提示，需排查并增加重复；不是伪造置信区间或自动剔除慢样本的规则。

## 持续保存、日志与有效性

宿主机 adapter 必须把桥内累计快照通过 stdout 的聚合 JSONL 持续交给 runner；每个样本
start/snapshot/end 带 sample_id、attempt、递增 event_seq、identity_digest 和统计定义版本。
不逐指令/逐包打印。宿主机每 20 秒（配置可改）保存一次 heartbeat，并 fsync 原始记录；
实际快照必须由 bridge 提供。heartbeat 内 `measurement_age_seconds/stale` 能区分旧快照，
不能将宿主时钟当成新测量。每项结束立即提交，不依赖 guest 关机后的结果回收。
在线运行连续 3 个快照间隔无新 bridge 累计快照，会保留部分统计、标记 timeout 并停止
本次 adapter；重试重建 epoch 和累计统计，不延续旧样本的快照。

`raw.jsonseq` 使用 `RS(0x1e) + JSON + LF` 追加帧，每批 fsync，batch_seq 全局递增。
尾部撕裂记录保留原字节，下一条 RS 可重新同步；损坏/重复冲突会报告。磁盘写入、fsync、
原子提交失败直接停止准入，不继续宣称完成。原始事件含完整配置、代码、输入、线程、
重复和产物身份。正式 `results/<sample_id>.json` 临时文件 fsync 后 rename，再 fsync 目录。
Python 解析 64 bit 整数，禁止先经过会丢失 >2^53 精度的 JS Number。

完成要求：ROI 非空、开始前排空、结束 producer seal、同 epoch/seq 全部任务完成、最终
比较 PASS、传输与 ownership 全释放、无异常/丢包/溢出、直方图/计数/总和一致、应用输出
校验成功。B 无 checker 延迟样本（N=0，分位数为空）；D/C N 必须 >0。
仅完整样本算 slowdown/latency，部分统计保留但不混入总体分布，尾部未排空不能截短 P99。
公共 B 仅按相同二进制/输入/线程/缓存与时钟策略/源码及站点产物身份复用。
变更上述任一身份就新建 campaign，不误用旧完成标记。

## ASIC 面积与时序（不执行 PARSEC）

先填写 `config/area.json`：实际 `.db` 工艺库、面积单位、RAM 处理政策、共同多时钟 SDC、
每配置 FireSim 转换前 target RTL 文件表、top 和与性能构建一致的 target manifest。
现有 DC 可执行文件存在不等于许可证/工艺库可用，尚未申请许可证或运行综合。

```bash
python3 firesim/dac2026/dac.py area-prepare --config C4 \
  --out /data1/gzh/EC/Experiment/dac2026/area/C4-v1            # 未配置时明确退出
# 补齐后手动加 --execute 仅执行 ASIC 综合，不烧写、不运行仿真或 benchmark。
# 综合后审查 check_timing/clocks/constraints/存储器映射并填写输出目录中的 review.json，
# 字段见 config/area-review.example.json；SUCCESS 文件本身不代表时序/存储器策略通过。
python3 firesim/dac2026/dac.py area-import \
  --directory /data1/gzh/EC/Experiment/dac2026/area/C4-v1
bash "$scripts/08_analyze.sh" --campaigns paper-v1 \
  --area-results /data1/gzh/EC/Experiment/dac2026/area/B-v1/result.json \
                 /data1/gzh/EC/Experiment/dac2026/area/C4-v1/result.json \
  --out /data1/gzh/EC/Experiment/dac2026/reports/paper-area-v1
```

综合保留实际层次面积、reference、时钟、约束和 timing 报告；不把 FireSim wrapper、FAME
逻辑或被动 observer 算进目标面积，不把停用 Rocket 当作移除。相同库/约束/RAM 政策
才计算相对 B 和 C 相对 D 的增量。RTL manifest 不一致不拼面积—性能—延迟图。
FPGA LUT/FF/BRAM/DSP 只能另列部署资源；没有 ASIC 库时不生成“ASIC 面积估计值”。
有实际 Vivado `report_utilization` 后，可只读导入另列的部署资源报告：

```bash
python3 firesim/dac2026/dac.py fpga-import --config C4 \
  --report /ABSOLUTE/build/utilization.rpt --rtl-manifest /ABSOLUTE/target-manifest.json \
  --out /data1/gzh/EC/Experiment/dac2026/reports/C4-fpga-NEXT
```

该入口不运行 Vivado、不操作 FPGA，也不会把资源计数转成 ASIC 面积。

## 未验证的真实工作

独立安装不等于 EC 移植成功；工具测试不等于测量链路通过；候选 Scala 不等于已综合硬件。
Linux checker/ROI 内核驱动、FireSim custom bridge 接线、准确执行时间戳、8 核协议及
公平 B/D 是主要待完成项。还没有本论文的 rootfs/kernel/bitstream、综合结果或任何实验数值。
`measurement/INTEGRATION.md` 列出应接的真实信号、不能替换的事件和验收条件。
