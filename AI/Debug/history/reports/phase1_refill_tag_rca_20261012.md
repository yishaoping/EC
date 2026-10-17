# Phase-1 启动期 [1000] assertion RCA

2026-10-12 只读分析；没有修改功能源码、编译、生成 RTL 或运行新仿真。

**已确认根因：新 refill owner 检查从14-bit数组地址提取完整物理tag，结果恒为0。** `BoomCacheRefill`继承Rocket `L1DataWriteReq.addr=Bits(untagBits.W)`，v1Config为14位；`mshrs.scala:470`输出正常array addr，`dcache.scala:1169`却右移14位与reservedTag比较。生成RTL把该条件化简为reservedTag==0。

当前用户运行在首个normal cacheable store line `0x80087fc0`失败：descriptor地址`0x80087ff0`，set255/way0，reserved tag`0x20021`、epoch1、transaction1、MSHR0；refill addr`0x3fc0`。FST2861处context/install/slot/epoch/transaction/MSHR/resident-epoch关系全部正确，只有tag失败；array arbiter ready1、valid0，refill ready0/fault1。下一上升沿触发`BoomMSHR.sv:578`（源码`mshrs.scala:208`），不是AMO或replay-result assertion。

first observable interface disagreement在FST2857，first valid refill违例在2861。FST=2*trace_count+half_cycle，500-cycle窗口1862..2862已按实际DCache clock确认。最后低沿2862 / trace_count1431；abort沿未dump。日志[1000]使用Verilator `VL_TIME_UNITED_Q(1000)`格式化，不能当精确cycle。

旧保存日志实际是[264000]。旧run同一line在FST2785已经descriptor epoch0 vs slot1、2787错误secondary再次推进slot2，首refill2859即卡死，迟至watchdog才报错。当前这条事务descriptor/reservation一致，STQ6保留、STQ7因older-effect gate尚未issue；旧错误在此没有重现。当前新增tag检查造成新的正常路径错误，并被即时assert捕获。不能称旧版本正确运行至264000，也不能将旧LineBuffer长期饥饿动态结论套到新立即abort的run。

修复原则（未实施）：BoomCacheRefill增加足够宽、block对齐的完整physical line侧带；MSHR从immutable descriptor驱动并经过同一个refill arbiter；DCache用该字段校验tag，并核对array set一致。保留14-bitarray addr语义和所有owner assertions。不得删除tag校验、默认tag0、伪造BASE/cert或放宽watchdog。

本run无semantic write/replay/cross-package clear/WB，safe watermark0，outer C valid0。完整ImageKey/certificate/TtoB→BtoT/L2 predecessor保存尚属Phase-2未实施，不能作为此次首因。独立AMO.W terminal-result静态问题仍未修；当前request为普通M_XWR，不触发该路径。

完整设计invariant、语义diff、500-cycle时间线、根因排序、代码位置及验证建议：[完整RCA](../../../TMP/rca_phase1_1000_20261012_175456/report.md)。逐条件动态证明：[predicate-proof.json](../../../TMP/rca_phase1_1000_20261012_175456/predicate-proof.json)。来源：[manifest.json](../../../TMP/rca_phase1_1000_20261012_175456/manifest.json)。四个旧核心源码由HEAD+旧diff重建，hash均与旧manifest一致；原旧完整FST未找到，仅使用保存窄trace，不补造旧outer/cert信号。

下一步是用户授权实施后的接口修复和定向动态验收。当前源码尚不能通过该normal refill；没有宣称Phase-1完成或unified preservation正确。
