# 单核功能闭环验收记录

当前64 VERIFIED、5 IN_PROGRESS、0 CODE_READY。全部69项原定义、逐项实现阶段与依赖见 [盘点](Function_Closure_Audit.md)，实际证据/命令见 [验证矩阵](Verification_Matrix.md) 和 implementation_manifest.json。状态提升均有任务板status_history。

| 工作流 | 已取得的完整闭环 | 剩余必要验收 |
|---|---|---|
| A 版本管理与基线 | History生命周期、跨段保留、preserve-before-reuse、精确ACK、全部同址发布入口和回收；逐accepted外写beat验证3/5/7、迟到C6、SW并发、可信Put、安全9合并及EVT/外写竞争 | 与D/E共同做完整Core实际满History压力 |
| B Seq32与CDC | 真实高位32位DATA/ARF/END/result、慢Checker和四相清空后Seq1复用；生产最终组合整核23次重基/新Seq1 PASS；16位slot和32位CurGen真实边界/维护证书 | 数字协议已闭合；1742项数据CE warning的保持/Gray偏斜及完整Core物理时序未签核 |
| C Checker到Restart | 真实FAIL/SCP/EVT/Restore/Lazy/Restart，同PC、实时owner重查、会话FINISH收据、pipeline清理；正常/Fault8/Sv39/Fault18写/AMO完整配对通过 | 同一完整程序第二次独立比较器FAIL，P3-14 |
| D 缓存与Scheduler | 真实dirty L1/fullC/Pending7/BASE外写ACK/两EVT、跨层lookup/晋升/旧响应隔离、有限slot终态；组件满64 History/park/Checker逃生 | 完整Core实际满History封口与资源释放后成功退出，P4-12 |
| E 整核协同 | 9个所选完整程序/5项严格计分PASS；128ecall、Sv39物理+提交、CLINT16写/16回读、AMO16旧值/16回读且恢复不重复A；最终增量23次重基 | 真实中断交叠、双FAIL、Fault40+Seq41完整程序与满资源压力 |

本批关闭原任务：

- Seq32：P2-09、P3-03、P5-09，`seq_lifecycle_closure.json`。
- 同址基线：P1-09、P3-10，`baseline_publication_closure.json`。
- 设备效果：P4-09，`io_barrier_closure.json`。
- 有限slot：P4-06，`finite_slot_owner_closure.json`。先以真实反例从CODE_READY回退，修复并动态验收后关闭。
- 版本生命周期：P1-03、P1-05、P1-07、P1-08、P4-04、P4-07、P4-08，`version_lifecycle_closure.json`。
- 最终恢复集成：P2-05、P2-08、P2-10、P3-04、P3-05、P3-08、P3-09、P3-11、P3-12、P3-13、P3-15、P4-01、P4-02、P4-03、P4-05，`recovery_integration_closure.json`。
- 原3项P5-02/P5-03/P5-06继续保留。

以上closure在`AI/TMP/singlecore_function_closure_20261123/`。其中生产GHM/DCache最终增量已由重新生成的真实组件/边界、同源组合Core完整程序验收。新双故障验证参数不改变默认正常配置的状态转移，另行记录当前来源编译及回归。

原失败与边界：`control_chain_fullcore.driver.exit=1`不覆盖；严格reviewed里程碑选择同model/ELF/source完整成功程序。旧Sv39“Fault也恰好16次物理读”错误oracle已修正，18次尝试中2次SCP后被恢复废弃，所有18次payload仍核验且存活恰好16；4个负例拒绝。直接写Verilator内部优化字段而未真正加速的owner测试不算边界覆盖。早期350000周期Fault40+Seq41仅首段通过，不算完整程序。

必要RTL修复均源于实际反例：FINISH越过待执行包、LSU stop执行offer、uncached AMO旧包归属/重复ROB响应、三处slot增量不一致、GHM物理CDC组合前置/ACK提取SRL。没有新增队列或恢复FSM；GHM源域请求共增4bit，双故障测试配置每Checker增加1个测试专用已用位，默认空不增加。


原CODE_READY任务后续逐项验收：7项前置盘点/映射/范围/信号/接口定义/DAG见`prerequisite_closure.json`；23项已实现功能与测试任务见`reviewed_code_ready_closure.json`。后者逐项关联当前真实组件和已完成整核/层次里程碑，并核验沿用的SVB、PRF、rename源哈希不变。P5-07保持CODE_READY，等待当前同一完整Core第二次独立真实FAIL，6项IN_PROGRESS仍有具体动态缺口；没有更改原任务定义。

下一功能工作流的新真实反例：实际CLINT MSIP与journal/stop交叠已观察到，normal无注入却在Seq23因普通checker模式的CSR写未更新影子而FAIL，后触发pipeline hang。原RTL真实CSRFile反例FAIL，无新寄存器/队列的两模式bank选择候选PASS且长期runner已实际运行。生产源码仍未合入该候选；完整normal/Fault18原IRQ与既有trap/Sv39/设备回归构建中。详见`AI/Debug/bugs/bug-palimpsest-interrupt-csr-compare.md`，不能将当前中断功能标为通过。


## 完整设备效果与物理重基协同

真实完整Core与原compact-trap-io程序1277543周期成功退出，唯一Fault40经SCP/EVT/
Restore/Restart同PC恢复，journal原值重放无重复设备A。Seq41在未结效果期间不预留，
效果释放后Seq45才重基；共8次实际reset/新Seq1 PASS、16轮48次设备读及完整架构oracle。
9种真实记录破坏全部拒绝。证据为`AI/TMP/singlecore_function_closure_20261123/io_rebase_complete_closure.json`。

本里程碑关闭P4-13/P5-10的完整I/O+重基子任务，整项仍依赖真实IRQ与History压力，
所以69项保持64 VERIFIED、5 IN_PROGRESS。没有靠改分类增加完成数。

同批已完成必要生产RTL：容量前缀保持等到现有producer seal receipt；两个scratch
的影子W/S/C以CPS为旧值、保留原物理CSR/MPRV。0新增状态。原容量first bad的真实
END/PASS与当前生产CSRFile12命令全PASS；最终组合原完整程序在途，结果独立记录。
