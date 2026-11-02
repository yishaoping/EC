# 已实现范围与验证分层

**已实现：observer/analyzer修复。未实现：任何functional optimization。**

|源文件|改动|
|---|---|
|boom/exu/core.scala|只读6-bit ROB状态bore；kind44 gate/ROB no-commit计数|
|boom/lsu/dcache.scala|traffic窗口bore；kind40活动、41逐项ROB交集、42实际admission guard优先分区|
|boom/lsu/lsu.scala|kind43 load/store pending、request wait、nack、queue full和ROB交集|
|rocket-chip/r/R_IC.scala|kind45精确FSM histogram、pipeline stall、correct-process scheduler wait与barrier|
|rocket-chip/util/SafeChainObservation.scala|只读STOP计数公共接口；START inclusive/STOP exclusive|
|inclusivecache/Directory.scala|read-consistent rows/key只读出口|
|inclusivecache/Scheduler.scala|快照先于demand；独立key审计；A/C opcode；地址restore一致性|
|rocket-chip/resources/csrc/cache_opportunity.cc|独立snapshot tag compare，完整性审计与语义字段|
|slowdown/optimization_4_svb/analysis/analyze_svb.py|functional/shadow门控分离；无效delta置null；新计数守恒检查|
|AI/Debug/scripts/analyze_opt4_remaining.py|只读旧run重分析、区间并集/交集、容量局部上限|
|AI/Debug/scripts/test_opt4_remaining.py|7个CPU/offline测试，包括native C++模型fixtures|
|AI/Debug/references/remaining_slowdown_observer_schema.json|kind40–45字段、预算和禁止纯观察run契约|

kind42只把full、unsupported event、legacy pending、capture drain、same-line fast lease、other fast lease、other
作为**互斥优先标签**。probe/replacement的实际同line releaseBlocked单独计数，
不会把它们和Store等待的偶然同周期出现伪装成cause。原4,774 unsupported事件定义包含资源guard，
与新class_unsupported_event不是同一统计。

新增6个STOP records；observer identities121→127，router limit128。没有增加逐周期文本trace。
新counter是硬件traffic window，不是软件ROI；各活动可重叠，只有kind42分区守恒。
它们不能替代逐MSHR/ROB身份join，也不直接证明strict counterfactual opportunity。

## 已执行验证

- 18 integrity +22 capacity/cache +11 protocol +7 remaining = **58项PASS**。
- native C++ fixture用CPU g++构建并运行；不是Verilator、硬件或benchmark。
- 7个改动Scala源以缓存依赖直接`scala.tools.nsc.Main -Ystop-after:typer`检查，exit0，仅warnings。
- 7个硬件文件移除观察改动后与preimage逐字节一致；2个functional配置与HEAD一致。
- 8个原始证据文件hash/size不变；`git diff --check`与最终产物检查见validation_result.json。

明确未做：Chisel elaboration、RTL generation、FIRRTL/组合环检查、Verilator build、硬件仿真、benchmark、PPA/timing。
所以只称“源码/类型/CPU测试通过”，不称新observer动态已验证。

原Opt4 launcher锁定旧cumulative patch并reverse-check源码。
当前新增观察源码是**待下一功能实验集成**状态，不是旧Opt4可直接重复运行的READY revision。
没有放宽launcher保护，也没有把增量patch冒充完整可运行Opt5。
