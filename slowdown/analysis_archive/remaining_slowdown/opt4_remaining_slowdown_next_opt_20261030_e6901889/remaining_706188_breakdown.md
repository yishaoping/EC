# 剩余 706,188 cycles：可证明的暴露与未知项

Opt4 correctness **PASS**，`performance_valid=true`。baseline 1,001,675；Opt3 2,928,347；Opt4 1,707,863。
Opt4/baseline **1.705007113×**；相对 Opt3 ROI 减少 **41.6783%**。
绝对差 **706,188** 是唯一精确的 baseline 差额。现有证据不能把它互斥分摊给全部 stall 类型。


证据范围：唯一有效 run `optimization_4_svb_20261030_072604_18475a92`。
软件 ROI `[712114,2419977)`；DCache traffic `[712021,2430802)`。
optional 事件只使用已证明完整前缀 `[712114,2289264)`，未知后缀 **130,713 cycles**。
所有区间为半开区间；主核 raw simulator timestamp = CSR cycle +103。
活动、阻塞、ROB 重叠和反事实可恢复时间分开，不相加凑出 706,188。


## 当前 Opt4 活动与阻塞证据

| 项目 | 数值 | 窗口与解释 |
|---|---:|---|
| semantic writes |61,219 events|traffic；不是 WaitSafe cycles|
| 原始 pre-bypass WaitSafe 条件 |UNOBSERVED|旧 run 没有该条件的逐周期总计|
| post-bypass 条件且无 legacy pending |5,183 cycles / 5,183 episodes|旧精确计数定义；多为单周期发起观察，不代表完整 legacy wait|
| SVB eligible / allocations / bypass |409 /406 /406 events|full-run/traffic 对应定义见原 summary|
| SVB full / unsupported fallback |1 /4,774 events|上升沿事件；不能当作等待周期|
| SVB occupancy=16 |4,888 cycles|traffic；0.2844%|
| legacy pending |52,702 cycles|完整前缀；全软件 ROI 范围[52,702,183,415]|
| legacy unsafe / safe |4,875 /47,827 cycles|前缀内安全状态切分；safe 不等于已经完成|
| legacy issued / metadata-clear / drain / kill |45,819 /699 /10 /10|前缀；条件可重叠|
| promotion source busy / queue waiting |23,788 /15,714 cycles|traffic；彼此可能重叠|
| safe→terminal 并集 |24,569 cycles|软件 ROI；包含 safe wait 和 inflight 重叠|
| L1 MSHR busy并集 / entry-cycles |315,637 /317,542|traffic；资源占用，不是 ROB stall|
| L1 MSHR full |0 cycles|没有资源全满证据；不证明 miss 都被隐藏|
| L2 MSHR busy / entry-cycles |190,049 /198,055|原 L2 自身采样；含 hit/C事务，不是149次miss的服务时间|
| scheduler unavailable in fsm_sch |267,087 cycles|完整前缀；最大可辨识控制等待暴露|
| fsm_sch total |267,163 cycles|同上；不能将两行相加|
| transfer / snapshot-state |28,661 /7,344 cycles|前缀；状态周期不自动等于可避免阻塞|
| snapshot/cooling且ROB非空 |6,376 cycles|前缀；没有精确 commit-qualified 交集|
| RSU busy / barrier close |28,372 /168 cycles|前缀；与状态活动重叠|
| LSU load/store stall、replay/nack、DCache request wait |UNOBSERVED|现有稀疏日志不足以恢复逐周期计数|
| ROB nonempty/no-commit 与各活动的精确交集 |UNOBSERVED|不能编造 miss→MSHR→ROB identity join|

原 L2 样本数1,718,782，而主核 traffic1,718,781：沿用各层原始采样边界，不做跨层一周期相等假设。
L2外存方向读149次/9,536B，写1,672次/107,008B；是观测接口流量，不是实测DRAM延迟。

## 实际计算的交集

legacy pending ∩ scheduler unavailable = **0**（完整前缀）；∩transfer=1,031；∩snapshot-state=126；
∩snapshot/cooling且ROB非空=95；∩RSU busy=1,024。
safe→terminal ∩ legacy pending=1,171。safe-wait并集15,563与inflight并集22,837不可相加。

287个保存的scheduler-state样本均显示pipeline-stall位13为真，支持控制停顿解释。
但该位被有意排除在原change key外，不能声称267,087每周期均有精确gate/ROB证明。

## 能回答与不能回答

当前最值得追查的是 **L1 miss相关资源活动** 与 **package/checker scheduler等待**。
前者315,637为全L1 MSHR资源包络，后者267,087是完整前缀中的控制状态暴露；窗口与语义不同，
既不能直接排序为已归因slowdown，也不能相加。尚不能证明其中哪一个是最大可恢复关键路径贡献。
其他baseline基础工作本来也会占用这些资源，缺少对应baseline交集数据。

缺失的旧数据保持未知。新增kind40–45只读STOP counters将捕捉精确活动、ROB no-commit交集和优先分类，
只随下一次有独立功能依据的实验携带；这些聚合计数本身仍不是严格反事实收益。
