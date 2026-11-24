# 架构决策

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

| 类型 | 冻结约束 | 对应实现 |
|---|---|---|
| 环境假设 | I/O 输入正确，同一逻辑操作的重执行输入一致。 | 不要求处理外部变化或设备永久错误。 |
| 机制 | I/O 输出在前缀满足验证屏障后才对外生效，真实效果不会被重复执行。 | `PalimpsestIoBoundary` pre/post close、单步，IOMSHR0 journal 和两类终态。 |
| 故障范围 | 正常瞬时错误通过既有 FAIL、SCP、EVT 处理。永久性故障与持续 I/O mismatch 恢复不在本轮范围。 | 保留单次 mismatch 的原 SCP retry。 |
| 架构语义 | 异常按精确提交顺序处理，rollback stop 优先于本次废弃执行后缀。 | ROB 选中、CSR 延迟投递和 IFU redirect 分别按 stop 门控，使用原异常处理。 |
| 架构语义 | 多同址版本按安全资格和版本顺序发布，真实终态后才能替换历史 owner。 | L1 SVB 前驱门控、共享 History scanner、L2 set lock 和 ACK 收据，可信 A 等前驱。 |
| 成本原则 | 保留索引扫描和现有握手，最小化保存状态。 | 复用 SourceC、History 扫描、已有 per-source 等待槽及目录；普通 rollback 保持 lazy。 |
| 平台前提 | Checker replay text 和页表不由受保护代码修改。 | 为非 image-aware 取数/权限请求提供保留 way。 |

当前生产实现决策（2026-11-24）：

- 停止执行：LSU屏蔽尚未取得memory owner的执行offer；已接受响应、已提交store前缀继续收尾。I/O后置封口使用原`ioIssueReady`，年轻未提交STQ不构成前缀排空依赖。
- 包释放：GHM只有`finishPending && forwardDrained`才发FINISH；沿用实际包结果释放、源FIFO空收据和四相ACK。无新跨域busy。
- 物理CDC：Main域先寄存既有transport维护请求，每Checker1bit、共4bit，再送原8级同步器。综合前`synchronizers.xdc`保留flop及ASYNC_REG并禁止SRL；AsyncQueue数据CE/Gray偏斜物理签核单列。
- 有限标识：L1分配、refill、install统一使用原`nextSlotEpoch`跳零helper。标签宽度及终态复用规则不变。
- 容量封口：`capacityClosing`释放同时要求原`producer_seal_ready`，防止RSU先idle而CDC尚未接受seal时丢掉非空ROB边界；容量保持只匹配真实开放包owner。
- CSR：normal Checker的MSCRATCH/SSCRATCH显式写镜像到现有shadow；shadow W/S/C基于本包CPS shadow读改写。normal物理CSR、management和MPRV机制保留。不采用宽范围normal shadow读写候选。
- 设备效果：`effectPending`覆盖已接受且Seq非零的live IOMSHR及未安全journal；从A前owner到D响应/终态持续阻止中断和计划重基，已生效效果在恢复时原值重放且不再发设备A。复用原状态和连接，无新存储/FSM。
- L2前进性：仅含外层E、无A/B/C/D/X/dir/park的现有调度可越过同组C/BC抢占，解除C→History→已接受外层GrantAck→C循环。继续等待实际E，不绕过发布锁、数据门控或安全基线。

除明确列出的GHM4bit源域寄存外，上述最终修复未新增寄存器、队列或FSM。
真实反例、源码、长期测试及每项验收范围由验证矩阵关联。当前69项VERIFIED、0项IN_PROGRESS；当前Scheduler修复的组件与5配置完整整核均已通过。
系统状态以`System_Acceptance.json`为准，原69项提前关闭结论已撤回。

物理检查与69项功能独立。GHM/CSR/IoBoundary/IOMSHR已有实际OOC报告；
完整ChipTop综合使用新增owner/Scheduler修复之前的生成物，仍在执行。
无最终来源完整Core的布局布线、端口延时或AsyncQueue数据总线物理签核结论。
