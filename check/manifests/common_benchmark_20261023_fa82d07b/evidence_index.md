# 证据索引与保全

## 读到的原始身份

- [DIRECT_EVIDENCE] 根Git HEAD `9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f`；开始时tracked已有 `Experiment/流量分析.typ` 修改、`DOC/` 与 `baseline/` 未跟踪。保留这些状态，没有checkout、worktree、reset、stash或index操作。
- [DIRECT_EVIDENCE] Baseline源码HEAD `b3d7adddd1e2d2cf428dd933529de878226420cd`，与root工作区独立；没有恢复历史文件到Current，也没有修改baseline/source。
- [DIRECT_EVIDENCE] 既有ABI报告位于 `/data1/gzh/EC/baseline/manifests/software_abi_preflight_20261023_9aa2542c/`。本轮以源码/ELF重新核查关键接口，未覆盖任何旧报告或manifest。
- [DIRECT_EVIDENCE] 本输出目录、software_common和builder在首次写入前确认不存在。初始保全快照 `preservation.before.json` 记录126个精确文件hash、root与baseline index、Current chipyard的117154个tracked路径内容摘要、工作区状态和空build/runs/tmp。

## 精确源码证据

| ID | 路径/范围 | 支撑内容 |
|---|---|---|
| SW1 | C/Software/Test/test.c:16-121；hw/cycle.h:7-11 | fixed_candidate原START/STOP、AMO+BFS、GHT poll、rdcycle、report、无条件return0、finite exit |
| SW2 | C/Software/Test/stat/report.c:47-108,1003-1071；hw/ghe.h:63-106,318-356 | 7B valid/drain/failed计数作为旧报告验收；perf0x76、interval0x79、mask读写 |
| SW3 | C/Software/Test/core/checker.c:10-65；core/secondary.c:18-29 | release/unset先于checker snapshot，main stop没有软件先后保证；per-hart ready只表软件完成 |
| SW4 | C/Software/Test/Benchmark/gapbs/gapbs_bfs.c:272-447；bench/stage1_amo.h:6-37；cfg/config.h:6-19 | 固定BFS512输入/算法/结果与AMO.W lane/sign-extension检查；harts/timer常量 |
| SW5 | C/Software/Test/hw/interrupt.h:10-65；interrupt.c:5-128 | timer64结构、CLINT MMIO、interrupt handler、timer limit/delta |
| SW6 | C/Software/Test/cfg/init.c:13-86；hw/ght.h:8-100；hw/rocc.h:10-97 | GHT filter/map、START/STOP/status、custom编码及specialJLR |
| HW1 | H/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala:49-98,124-151,176-187,197-283 | b3 functors、默认零resp、低5bit perf、mask、context/replay；65/66/79/7B缺失解码 |
| HW2 | C/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHE.scala:69-100,136-155,281-285；boom/common/tile.scala:669-671 | Current 7B traffic vector、7bitperf、高位observer控制进入DCache |
| HW3 | C/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:498-512,1619-1705,1724-1746,1837-1840,1906-1934,2612-2629 | 统计enable/reset、functionalPacketAlloc不依赖trafficCounting、结果bitmap与safe watermark持续更新；observer snapshot不等于功能释放 |
| HW4 | C/chipyard/generators/boom/src/main/scala/lsu/lsu.scala:390-425,2147-2176；H/rocket-chip/r/R_ICSL.scala:298-343；C/r/R_ICSL.scala:554-573 | 调试计数reset/selector与功能控制分离；不通过删除统计去关闭barrier；低位reset应释放 |
| HW5 | H/rocket-chip/rocket/CSR.scala:699-703,847,864,1363-1366；C/同路径:773-777,921,938,1450-1453；H/C tile/Core.scala:140；H/C BOOM/exu/core.scala:1421/1453 | cycle语义、ungated clock、WFI/CEASE/inhibit条件；不要混淆enableCommitLogPrintf与enableCommitLog |
| HW6 | H/rocket-chip/rocket/RocketCore.scala:526-528,689,725,1049-1084,1194-1200；C相应上下文路径 | record/copy/ELU/JLR的用途；不能把所有“record”接口当统计 |
| HW7 | H/rocket-chip/guardiancouncil/GHM.scala:174-191,245-274；GHE.scala:73-78,139 | GHT session完成/route状态、bigComp锁存；不是逐包释放或cache drain |
| RT1 | C/chipyard/toolchains/libgloss/misc/crt0.S:94-124,138-222；crtmain.S:5-36；misc/htif.c:7-40；sys/write.c:6-9；util/htif_nano.specs、htif.ld | 静态runtime、trap返回、hart分流、HTIF I/O；不是R-Kernel ABI |
| RT2 | H/chipyard/generators/chipyard/src/main/resources/csrc/emulator.cc:310-354；C对应:334-350；C/stage1_exit.h:7-25 | 历史host exit和Current条件性L1/LSU quiet差异，全部独立于主ROI |
| GIT1 | `git show b3d7add... -- GHE.scala`；b87f893...同文件blob | b3移除先前0x79 storecounter实现；新增mask/state并非Current-only |
| GIT2 | `git log b3d7add... -S 'val doGetTrafficCounter' -- GHE.scala` 无匹配；`git show d5585b36... -- GHE.scala`；ancestor检查 | b3该历史线无7B，2026-08-05后加入；不靠提交标题定义功能 |

HW表中省略的H/rocket-chip、C/rocket-chip前缀均为各自 `chipyard/generators/rocket-chip/src/main/scala/`；BOOM前缀为 `chipyard/generators/boom/src/main/scala/`。不把这些源码版本等同于任意现有generated RTL或simulator。

## 新增文件证据

- `abi_sites.json`：f5f84a17... ELF的全部custom1/CSR/specialJLR位置；8056条dump位置逐字节与PT_LOAD映射核对。没有假定PC是周期，未把静态位置数称为动态次数。
- `library_symbol_sites.json`：实际ELF函数符号，例如htif_syscall=0x80006622、_write=0x80006706，解决库调用PC归属。
- `source_manifest.json`：共用树每文件SHA256、与原始Software/Test的差异、复制的已有库输入、构建/启动脚本身份。
- `static_checks.json`：Bash -n、Python AST、只读布局/源码一致性、纯文本synthetic parser校验；不是编译/仿真PASS。
- `preservation.after.json`：受保护原件hash及index/HEAD/Current tracked摘要复核、仅允许两个baseline启动器原文件变化、build/runs/tmp仍空。

## 本轮工具边界

[DIRECT_EVIDENCE] 读取使用限定路径的git show/log/status、sed/rg/nl、ELF readelf/objdump与标准库解析、SHA256；没有读取FST或调用native reader。未运行任何launcher/builder模式、原compile.sh、gcc/ld/as、make/SBT、elaboration、RTL生成、Verilator、simulator、workload或硬件测试。

[DIRECT_EVIDENCE] `bash -n`只解析两个shell脚本；Python AST只解析源码。额外只调用无顶层副作用的纯文本contract parser，对手写虚构日志检查拒绝重复/缺失/错误hart/算术错/FAIL等规则。这不是新真实运行日志，也不产生可报告性能样本。

[DIRECT_EVIDENCE] 写入范围仅 `/data1/gzh/EC/baseline/`：独立源码副本、新builder/helper、新报告，以及用户明确授权修改的两个启动器。既有libgloss archive复制为链接输入，不是新编译结果。没有修改Current软件、Current硬件、baseline/source硬件或任何原始运行证据。

[UNRESOLVED] `RUN_PROVENANCE=UNRESOLVED`，不因通过静态校验或准备script而升级。
