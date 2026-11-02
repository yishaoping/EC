# 证据索引与复核方法

## 范围与标记

- DIRECT_EVIDENCE：本轮直接读到的源码、Git对象、ELF字节/符号、哈希或脚本字段。
- STATIC_INFERENCE：由明确静态控制路径/数据流推出的条件性结论；不是新运行观测。
- UNRESOLVED：没有充分匹配产物、实际运行、时序或共同验收证据。

所有 H/ 源码绝对根为 /data1/gzh/EC/baseline/source，固定commit b3d7adddd1e2d2cf428dd933529de878226420cd。
所有 C/ 路径绝对根为 /data1/gzh/EC，固定HEAD 9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f。
当前受保护工程在 C/chipyard；未修改。

## 源码索引

| ID | 精确路径/范围 | 作用 |
|---|---|---|
| S1 | H/Software/Test/test.c:39-115,119-135；test_config.h:15-55；test_workload.c:91-133；tasks.c:24-90 | 历史软件入口、START/STOP、timer/hart拓扑、混合workload、checker完成顺序。 |
| S2 | H/Software/Test/clint.c:14,44-76,95-99,112-154；ghe.h:163-247；performance.c；store_stats.c:52-65,89-110,126-136 | 旧flags、trap、旧统计ABI和0x79缺口。 |
| S3 | C/Software/Test/test.c:16-26,30-121；hw/cycle.h:7-11；core/secondary.c:17-70；core/checker.c:10-65；cfg/config.h:6-61；cfg/init.c:72-86 | 当前修复候选的控制、报告调用、退出、共享数据发布、请求的统计interval。 |
| S4 | C/Software/Test/stat/report.c:47-108,186-268,338-401,941-955,1003-1071；hw/ghe.h:63-106,110-330,340-356 | 0x7B统计向量、必须为1的有效位、drain判据、return PASS/FAIL。 |
| S5 | H/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala:49-98,124-151,176-187,197-236,245-283；同目录GH_Config.scala:9-15 | custom1解码、默认零response、ready/xd握手、监测控制、5-bit perf寄存器；WithGHE路由。 |
| S6 | C/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala:69-100,136-155,188-195,281-285；GH_GlobalParams.scala:45-48；C/chipyard/generators/boom/src/main/scala/common/tile.scala:669-671 | Current0x7B、7-bit控制及traffic_start/stop分发。 |
| S7 | C/Software/Test/hw/interrupt.h:10-25,37-65；interrupt.c:5,24-38,41-128；H/chipyard/generators/rocket-chip/src/main/scala/devices/tilelink/CLINT.scala:15-30,69-98 | 64-byte flags、普通DRAM地址、CLINT参数/读写布局；当前handler与历史实现差异。 |
| S8 | H/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:157-158,194,248-278,360-369；r/R_ICSL.scala:298-318；H/chipyard/generators/boom/src/main/scala/exu/core.scala:2130-2131；rocket/RocketCore.scala:1114-1133 | 历史checking/stop控制与持续计数；不支持统计START/STOP高位。 |
| S9 | H/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:174-191,245-247,264-274；GHE.scala:73-78,134-150；C/Software/Test/core/checker.c:37-65；core/secondary.c:18-29 | 状态、checker释放/ready和缓存资源drain的区别。 |
| S10 | H/chipyard/generators/chipyard/src/main/resources/csrc/emulator.cc:310-354,365-385；C/同路径:334-350,520-543；C/同目录stage1_exit.h:7-25 | 历史立即host退出、Current条件性host+L1/LSU quiet、reset/harness计时。 |
| S11 | H/chipyard/toolchains/libgloss/misc/crtmain.S:5-25；C/chipyard/toolchains/libgloss/misc/crt0.S:94-124,138-222；H/chipyard/toolchains/libgloss/sys/exit.c:4-10；util/htif_nano.specs:1-20；H/chipyard/toolchains/riscv-tools/riscv-isa-sim/fesvr/htif.cc:125-159,306-308；fesvr/syscall.cc:199-217 | 裸机启动/trap、静态链接、HTIF符号与退出约定。FESVR源码不是当前宿主预编译库身份的证明。 |
| S12 | C/Software/Test/bench/stage1_amo.h:6-37；Benchmark/gapbs/gapbs_bfs.c:272-307,368-447；test.c:70-78 | 实际AMO.W两lane/符号扩展自测与BFS512内置输入和验证。 |
| S13 | H/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:9-28；C/同路径:9-30；H/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:5-16；subsystem/BankedL2Params.scala:15；subsystem/RTC.scala:12-26；system/Configs.scala:13-20 | 五hart、频率、64-byte默认cacheline、timebase和硬件Config差异。 |
| S14 | H/Software/Test/compile.sh:47-55,77-103,134-148；C/Software/Test/compile.sh:55-107；H/chipyard/generators/testchipip/src/main/resources/testchipip/csrc/mm.cc:134-160 | 静态链接输入、无R-Kernel引用、历史loadmem解析。 |
| S15 | /data1/gzh/EC/baseline/launch_baseline.py:140-190,386-445,458-470；start_baseline_experiment.sh:1-7；baseline/manifests/environment.json | 描述schema/门禁、已有选项、按软件身份snapshot、harness cycles与marker成功不等于完整正确性。 |

## 产物与检查

[DIRECT_EVIDENCE] 本轮主产物：
- /data1/gzh/EC/baseline/software/fixed_candidate/{test.riscv,test.loadmem_hex,test.dump,origin.stage1_workload.json,workload.json}。
- /data1/gzh/EC/baseline/source/Software/Test/{test.riscv,test.dump}。
- 既有环境/准备manifest：baseline/manifests/{environment.json,source_identity.json,preparation.before.json,preparation.static_checks.json}。

哈希详见本目录 preservation.before.json。没有将历史TC_OverTaking.riscv.loadmem_hex当成test.riscv的配对loadmem。

只读命令类型（均已执行静态读取，未执行被读脚本）：

1. git --no-optional-locks rev-parse / status / diff / log / ls-tree / show / cat-file，固定SHA及限定路径；GIT_OPTIONAL_LOCKS=0。
2. sha256sum、标准库hashlib，对精确文件核对；没有全仓库搜索或扫描波形。
3. nl/sed/rg/find/ls 仅对上述软件、guardian/core接口、harness、启动脚本、manifest和R-Kernel空目录；少数猜测文件路径不存在，随后用rg --files定位真实路径，没有执行替代脚本。
4. /data1/gzh/EC/chipyard/.conda-env/riscv-tools/bin/riscv64-unknown-elf-readelf -h -A -s / ...、-p .comment -d：只读ELF。
5. 同目录 riscv64-unknown-elf-objdump -d --disassemble=main / handle_trap / report_end / _exit：只读反汇编到stdout，没有产生新dump。
6. PYTHONDONTWRITEBYTECODE=1 python3 标准库pathlib/hashlib/json/struct/re/subprocess：解析ELF头/PT_LOAD、现有dump和hex字节；只读输入。报告文件由apply_patch写到本独立输出目录。

### 二进制检查的计算方法

- ELF64 little endian header格式 <16sHHIQQQIHHHHHH，program header <IIQQQQQQ。
- dump行锚点：地址后跟4或8个hex指令字符；指令hex按little endian变成2/4字节，映射到PT_LOAD的文件offset=segment_offset+PC-vaddr，与实际ELF字节比较。
- custom指令列表按已有dump可识别位置解码opcode=word&0x7f，funct=word>>25，xd=(word>>14)&1、xs1=(word>>13)&1、xs2=(word>>12)&1。它是静态位置/次数，不是动态执行频次。
- loadmem逐行bytes.fromhex(line)[::-1]拼接，与ELF文件段比较，并检查memsz-filesz的BSS和后续padding全零。
- 候选read-only manifest验证：40项绝对文件的SHA256与origin.stage1_workload.json的sources逐一比较，mismatches=[]；关键7个当前源文件另外与git show HEAD:path字节相等，历史GHE/harness/test/clint与b3 blob相等。
- binary_evidence.json保存指令核对数量、异常列表、custom1位置与loadmem结果；指令位置不是周期区间，不生成任何性能估值。

## 未闭合证据

[UNRESOLVED] 1. 不存在一个本轮已审定、能让b3按真实接口满足共同软件成功/drain条件的软件描述。现候选的0x7B有效位约束是明确静态阻塞。
[UNRESOLVED] 2. Baseline的host成功之后缓存/LSU/L2/DRAM资源真正静止点；历史harness没有等待/采集配置。
[UNRESOLVED] 3. 两版对相同BFS/AMO及timer handler的实际功能和checker结果、异常、hart完成、超时行为。
[UNRESOLVED] 4. Current实际生成模型/simulator是否启用STAGE1_EXIT_PORTS；不得仅从源文件存在推断运行产物。
[UNRESOLVED] 5. 完整编译工具链身份与候选源码到ELF重建链；已知hash和实际指令支持本次静态判断，但不是完整build provenance。
[UNRESOLVED] 6. R-Kernel精确历史对象/副本未闭合；对现有静态ELF不是运行前置条件。
[UNRESOLVED] 7. 正式paired software comparison、ROB关键路径及净slowdown，本轮无新运行不能给数值。

## 保护边界

[DIRECT_EVIDENCE] 首先确认输出目录不存在，之后所有新文件仅写本目录。保留原有tracked Experiment/流量分析.typ和未跟踪DOC/Prompt.typ；保留原root/baseline Git index、分支/HEAD、既有启动脚本/软件描述/产物/manifest。没有checkout、worktree、stash、reset或清理工作区。

保护状态见 preservation.before.json / preservation.after.json。build/runs/tmp原来为空；最终仍须为空。没有调用FST reader或任何可能在原始波形目录创建临时文件的工具。没有运行launcher任何模式、make/SBT/编译器/链接器/elaboration/RTL生成/仿真/测试/workload。

方法参考 /home/guozh/.codex/skills/ec-debug-analysis/SKILL.md 及 static-audit.md、protocol-invariants.md；没有执行其构建、trace或验证建议，因为用户本轮仅授权静态审查。

[UNRESOLVED] RUN_PROVENANCE=UNRESOLVED。
