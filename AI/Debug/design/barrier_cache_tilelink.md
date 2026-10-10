# Barrier、cache 与 TileLink 设计边界

真实 barrier 只限制与未安全 package 相关的 dirty writeback/跨包访问；它不等于 BOOM stall、checker PASS、result release 或 TL C-channel 完成。当前源码默认 `GH_REAL_BARRIER_ENABLED=true`。

审查一条 barrier 链时记录：candidate packet seq、safe watermark、barrier request/close ACK、TL A/C/D fire、metadata-clear fire、writeback permission（跨包 shadow writeback 需 `TtoN`）、safe watermark advancement。任何 pending/dropped/overflow 都必须可见；不要用 latency bucket “吸收”功能请求。


## 当前源码可检查的条件

InclusiveCache candidate unsafe：`candidate && dirty && packetTracked && seq != 0 && seq > l2SafeWatermark`。real barrier enabled时保存barrierSeq并阻止相应C调度；close ACK必须匹配该seq，release条件是matching ACK且`barrierSeq <= safeWatermark`。timeout/failure是错误报告，不能视为已PASS。

safe watermark经Gray encoding/同步进入L2；Scheduler实际将`barrier_allow`加入C-channel schedule ready路径。这是功能门控，与监控bucket不同。L1跨包shadow WB另有safe等待及writeback/meta-clear串行化，需追踪line provenance/packet seq和真正TL事务。

早期`references/design_snapshots/cross_package_barrier_monitoring.md`只有monitoring、不主动stall的设计口径；当前源码真实barrier默认true，不能混用。严格barrier开关性能A/B需要同software image、对应RTL、相同功能正确性口径。

源码：chipyard/generators/sifive-cache/design/craft/inclusivecache/src/{InclusiveCache,Scheduler,Directory}.scala；boom/lsu/dcache.scala；rocket-chip/r/R_IC.scala。
