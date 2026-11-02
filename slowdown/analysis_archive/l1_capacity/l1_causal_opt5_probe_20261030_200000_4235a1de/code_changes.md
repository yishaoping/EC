# 实现

新增BOOM-only WithL1CausalSets；A/B分别256/512sets，nWays=2、MSHR=6、bank=1保持。
只读ROB busy首valid load→LDQ incarnation/token bore；复用DCache输入-only DPI。
Native模型64 LDQ槽+64 STQ槽+6 MSHR槽，192 counters、3×32-bin hist、64-prefix snapshot环。
WB给出pinned common_roi_start/stop rdcycle真实返回值，使用prefix snapshot差计算精确软件半开ROI；
marker超过64cycle环、重复/缺失marker或数据关联错误均fail closed。
STOP counters40–45和L2 read-consistent snapshot保持。新native事件不落逐cycle日志，也不增加SC observer identity。
load miss采用token去重；allocation/merge/reject是实际MSHR握手；load RPQ replay与nack retry分开。
head miss是ROB首valid bank busy load、LDQ仍live且未succeeded、token匹配未返回miss三者同cycle交集。
latency histogram按末事件处于ROI的cohort统计，可包含ROI前开始的请求，不把censored未完成请求当零延迟。
默认Opt4 launcher保护保留；显式paired模式使用新immutable source seal/cumulative patch reverse-check。
源码逆变换验证没有改动functional datapath/policy（只规范化空白）。

物理实现边界：observer 增加只读扇出和 ROB/LDQ 观察读选择；没有改功能消费者、流水寄存器、仲裁或 ready/fire 规则。周期模拟证明不了这些额外观察连线的物理时序/面积成本。正式 PPA 比较应使用受控移除 observation 的等价实现，并单独验证时序；本轮不据此宣称频率或能耗收益。

R2 修正：ROI timestamp 取 `rob.io.debug_wb_wdata`，即已有 CSR architectural result mux 后的数据；R1 误取的 `wb_resps.bits.data` 是 mux 前 execution data。新增固定2条 marker records、lookup error counter，以及每 measurement epoch 至多4条 live marker diagnostics；capture 将它们作为 essential 保存并立即 flush。详见 roi_marker_rca.md。

最终离线处理：paired analyzer补齐真实abort后缺失cache/ROI summaries的fail-closed分支，不再因StopIteration而漏写结果；新增两个对应测试，最终82项unique离线tests通过。缺失B值为null/unavailable，不填0。新增有界failure evidence摘录与flags解码、完整INCONCLUSIVE报告生成器及产物hash。封存硬件/launcher/capture输入未改，未对checker3 seq67做功能patch。
