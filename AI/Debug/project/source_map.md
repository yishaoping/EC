# 关键源码地图

| 机制 | 主要源码 |
|---|---|
| BOOM commit / snapshot / watchdog | `chipyard/generators/boom/src/main/scala/exu/core.scala`, `rob.scala` |
| BOOM LSU / STQ / strict token | `chipyard/generators/boom/src/main/scala/lsu/lsu.scala` |
| L2 functional barrier / coherence | `chipyard/generators/sifive-cache/design/craft/inclusivecache/src/{InclusiveCache,Scheduler,Directory}.scala` |
| DCache / MSHR / replay / barrier | `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`, `mshrs.scala` |
| address statistics | `chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala` |
| packet scheduler / allocation | `rocket-chip/src/main/scala/r/R_IC.scala` |
| ARF / CSR / GHE session | `rocket-chip/src/main/scala/r/{R_RSU,R_RSUSL,R_ELU}.scala`, `rocket/CSR.scala`, `guardiancouncil/GHE.scala` |
| checker completion / tail | `rocket-chip/src/main/scala/r/R_ICSL.scala`, `rocket/RocketCore.scala` |
| LSL SyncReadMem / match / quiescent | `rocket-chip/src/main/scala/r/R_LSL.scala`, `guardiancouncil/GH_FIFO.scala` |
| GHM / CDC / DATA END / producer seal | `rocket-chip/src/main/scala/guardiancouncil/GHM.scala`, `GH_GlobalParams.scala` |
| checker fetch / redirect / BJL | `rocket-chip/src/main/scala/rocket/Frontend.scala`, `IBuf.scala`, `r/R_BJL.scala` |
| tile-level bridges | `rocket-chip/src/main/scala/tile/{BaseTile,Core,RocketTile}.scala`, `subsystem/HasTiles.scala` |
| configuration | `chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala` |

表中省略 `chipyard/generators/` 的 rocket-chip 路径均相对于该目录。源码行号随修改变化，优先按 symbol 搜索。


直接入口：[R_IC](../../../chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala)、[GHM](../../../chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala)、[RocketCore](../../../chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala)、[R_LSL](../../../chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala)、[BOOM core](../../../chipyard/generators/boom/src/main/scala/exu/core.scala)、[InclusiveCache](../../../chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala)。
