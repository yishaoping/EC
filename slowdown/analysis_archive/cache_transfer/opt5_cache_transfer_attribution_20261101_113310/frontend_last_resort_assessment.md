# BOOM/checker backpressure 与 frontend 最后手段门槛

B scheduler unavailable 347,409cycles，scheduler∩MSHRbusy269、scheduler∩headmiss0。optional prefix scheduler unavailable 280,215；与已测post-firstC release阶段交集仅151。已量化control暴露，但不能把它归因到frontend，或声称因与BOOM miss少重叠所以与所有cache transfer无关。

BOOM private L1统计不覆盖checker私有cache/async A、L2 shared Get服务、source-indexed peerWait、水位安全gate。checker后端memory wait可能使package finish延迟并传播到scheduler availability，仍属优先检查的资源链。现有mandatory package生命周期可恢复allocation/result/handoff，但缺少对应cache transaction/source stage，尚无“哪个缓存请求拖慢哪个package”的闭合链。

| frontend提升条件 | 当前状态 |
|---|---|
| 全部cache-transfer opportunity<100k | **未证明**，whole-mechanism UB未知；仅一段ACK回程很小 |
| LSU/retry/refill不足 | 直接head范围不足达标已知；非head与传输整机制未闭合 |
| BOOM/checker backpressure不足 | **未证明**，347,409为状态暴露，不能排除或授予收益 |
| frontend stall有大规模critical overlap | 无保存的stage→package→result→BOOM关键join |
| frontend真正拖慢package completion | 无反事实/依赖归因；utilization不是证据 |

未满足提升条件，`CHECKER_FRONTEND_PRIORITY=LAST_RESORT`，不修改frontend，也不因当前缺数据而随意选它。下一步资源归因顺序：缓存transfer和peerWait → LSU progress/retry → package ownership/result availability → 最后frontend。
