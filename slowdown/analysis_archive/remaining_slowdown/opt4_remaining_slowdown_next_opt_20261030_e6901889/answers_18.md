# 最终18问

## 1. 当前Opt4是否完全有效？

是。指定有效run的simulation exit0、verified1、checksum43439728、完整406身份/terminal/数据/协议/histogram通过；ROI有效。L2 shadow fidelity单独FAIL不推翻functional结果。

## 2. 剩余slowdown是多少？

706,188 cycles；Opt4 1,707,863−baseline1,001,675；ratio1.705007×。

## 3. 剩余最大的可优化瓶颈是什么？

最大已观测memory资源活动是L1 MSHR busy315,637，最大可辨识控制暴露是完整前缀scheduler-unavailable267,087。缺少ROB临界归因，不能确认最大可恢复贡献是哪项。

## 4. SVB32最多能带来多少收益？

固定记录轨迹、唯一full相关legacy episode局部删除上限5,254 cycles（0.3076% ROI）；ROB交集未知，实际局部贡献可为0；不是有反馈系统的全局严格上界。

## 5. 是否保留SVB16？

是：KEEP_SVB16 / DO_NOT_EXPAND_SVB。

## 6. promotion throughput是否值得优化？

不作下一主方向；safe→terminal并集24,569，legacy交集1,171；唯一full开始时16owner均unsafe。

## 7. L1 S0 sanity是否通过？

PASS；shadow3,286 vs actual3,272 misses，误差0.427873%。

## 8. 32K/4way的机会？

减少1,792 shadow misses /54.5344%；equal-service proxy173,911 cycles，非ROI预测或严格上限。

## 9. 64K/2way的机会？

减少1,985 /60.4078%；proxy192,641；临界收益尚未证明，保留2比较器。

## 10. 64K/4way的机会？

减少2,108 /64.1509%；proxy204,578；比S2仅多123 misses，却额外承担4way成本。

## 11. L1最推荐哪种geometry？

条件性64KiB/2-way；当前没有functional GO，不修改geometry。

## 12. L2 shadow S0失败根因？

旧accepted-write mirror与delayed directory read+pending bypass并非同一状态；结构性缺陷已由源码/CPU反例确认。没有证明本run40,220 excess全部源于此。地址restore与独立key审计一并修复。

## 13. 能否用当前run离线修复L2分析？

不能精确重放；只有aggregate/per-set/hash，没有完整metadata/read/A/C顺序或lookup snapshot。

## 14. L2是否值得真实扩容？

证据不足；旧S1–S3失效，actual149miss、set-full0、最高8/16 valid ways，defer。

## 15. 下一唯一functional optimization？

NEXT_OPTIMIZATION = NONE_JUSTIFIED；状态NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED。原因同时包括L1/控制critical-path缺证，不仅是L2失败。

## 16. 是否已经实现？

没有functional实现；已实现L2观察修复、剩余活动/ROB交集计数、离线analyzer和tests。

## 17. 下一次是否带修好的L2 observer？

是，只随下一次独立获GO的功能实验集成；源码/类型/CPU测试通过，动态sanity未跑。

## 18. 用户下一次是否只需跑一个完整实验？

当前还不能给READY Opt5命令。功能方向获独立依据并实现后，应一次集成其ROI/correctness/L2/SVB观察；不要求或准备纯观察前置实验。
