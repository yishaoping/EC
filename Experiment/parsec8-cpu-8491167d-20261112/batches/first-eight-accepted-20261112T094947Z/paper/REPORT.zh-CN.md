# 八项PARSEC来源软件范围的CPU周期实验

更新时间：2026-11-12T09:49:45.245060+00:00。有效首轮配对 **8/8**。冻结EC唯一功能基线：`8491167d84b6d9521b151a743673c1516926a1f8`。仅运行CPU软件仿真和离线分析，未操作FPGA、Vivado、bitstream或CAD。

下表是声明范围在保留Golden Gate模型上的实测target cycles。**它不是八个完整PARSEC应用的性能表。** Bodytrack、Fluidanimate和Ferret为真实应用状态的组件重放；其余包含缩减输入或更改的软件配置。代表性及完整应用覆盖误差未校准，不提供整程序外推。

| 程序 | 测量范围 | Native cycles | EC cycles | EC/Native | ROI指令数各侧 | 有效配对n |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| blackscholes | 64条期权、原bs_thread单次迭代 | 60832 | 63547 | 1.044631 | 35605 | 3 |
| fluidanimate | 真实帧状态中的AdvanceParticles组件，64粒子、4725网格 | 16949 | 28077 | 1.656558 | 31613 | 1 |
| bodytrack | 真实frame0状态中的原始似然误差组件 | 125929 | 146905 | 1.166570 | 81179 | 3 |
| freqmine | 官方3事务test；hot4缓存配置、安静ROI | 166379 | 467929 | 2.812428 | 273900 | 2 |
| swaptions | 16次trial的完整定价计算 | 167237 | 337633 | 2.018889 | 157123 | 3 |
| ferret | 真实EMD输入的126对距离矩阵组件 | 24720 | 34184 | 1.382848 | 16460 | 3 |
| dedup | 官方6字节test完整串行管线；16MiB缓冲与预载表 | 211667 | 407603 | 1.925680 | 344184 | 3 |
| streamcluster | 16点输入的完整streamCluster计算 | 303982 | 609828 | 2.006132 | 406074 | 2 |

八个已声明范围的描述性Geomean：**1.672531×**。它包含不同软件范围，只作为这些范围的描述性指标。完整应用Geomean始终为空。按范围分组的Geomean和包含项目见[geomeans.csv](geomeans.csv)。

## 可比性与证据

双方单应用线程，匹配BOOM核、总线、缓存参数；BOOM200MHz，EC四个checker各100MHz；FASED读写延迟30、最大请求4、relax0。清除主hart MTIE后再准备软件状态，checker固件保持冻结版本。双方共享编译应用对象、输入、准备流程、ROI和验证器。接受条件包括：输出行一致、ROI退休指令数一致、绑定manifest一致、源码/输入/ELF/对象哈希一致、完整原始日志重解析通过，以及每个EC allocation→begin→full_compare→BOOM接受的完整链，零pending/fail/cancel/duplicate。

双方启动ELF和链接地址不同，cache初态效应尚未校准；ABI和共享对象一致不能消除此混杂因素。Spike仅用于功能与指令计数预检，未使用其周期作性能数据。固定FASED模型上的整数CSR差具有一周期分辨率，但没有到真实DRAM/FPGA的经验误差界。重复确定性仿真得到零方差只证明当前配置的可重复性，不能证明工作负载代表性。

[主表CSV](parsec8-native-ec.csv)、[绘图数据](plot-data.csv)、[性能图PDF](parsec8-slowdown.pdf)、[SVG](parsec8-slowdown.svg)、[重复统计](repeatability.csv)、[逐样本记录](samples.csv)、[方法说明](methods.md)、[正确性合同](correctness-contracts.csv)、[误差与限制](measurement-uncertainty.csv)、[独立发布核验](release-verification.json)。主CSV逐行指向原始result、stdout完整性收据与manifest。每个run目录保存完整host-complete.log.gz、绑定命令及SHA-256、EC事件和严格接受链。重现原测量命令见[reproduction-plan.json](reproduction-plan.json)。

## 真实失败和范围选择限制

原Fluidanimate完整帧、Ferret完整EMD及Dedup128MiB缓冲配置出现真实checker取消，不能计入任何有效性能配对。[失败摘要](superseded-failures.csv)保留首次事件周期、原始日志与四层因果分析入口；上游硬件根因尚未证实。缩窄组件或改变软件初始化配置后的通过结果不构成硬件修复，也不验证原失败计算。范围选择受到这些失败影响，论文必须披露；不可把当前表描述成所有原应用都正常运行的结果。

旧Linux Native FPGA simmedium、bare-metal project400与新CPU仿真范围不混配。Canneal只验证流程，排除八项Geomean；历史数据的独立审计和排除说明见methods.md及historical-native-fpga-excluded.csv。

## Checker、SVB与延迟

[checker本地事件统计](checker-local-metrics.csv)、[SVB统计](svb-metrics.csv)及其repeats文件由真实事件生成。本地checker间隔从实际new_package到结果入队，使用100MHz checker时钟，包含服务和等待；不能叫严格检错延迟。四个并发checker的间隔总和不能解释为应用开销。

`checker_acceptance_tail_boom_cycles`是max(0,最后BOOM接受结果CSR周期−ROI结束CSR周期)，可见[尾部数据](checker-acceptance-tail-plot-data.csv)。它不包括EC启用开销，不证明架构或完整SVB排空。SVB按entry/line/sequence/generation匹配capture/promotion/ACK，缺失、合并或未验证payload的范围单独标注。严格检错延迟和完整rollback延迟均缺真实起止端点，保持空值，取消或watchdog不作为rollback。

## 封存与继续执行

首轮八项全部接受后，`batches/first-eight-accepted-*`自动封存论文产物、脚本、manifest、收据和原始日志哈希引用。原始gzip始终保留在runs。三轮完整配对接受后再生成第二份不可变快照。当前任务与资源约束见实验根目录campaign-v3-state.json和execution-policy.json；调度只管理本实验的进程身份，不管理其他会话。
