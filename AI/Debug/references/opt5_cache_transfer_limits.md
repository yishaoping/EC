# Cache transfer attribution：阶段暴露与关键收益分开

适用完成B：`optimization_4_svb_20261031_024551_8fbf8937`；报告
`AI/TMP/opt5_cache_transfer_attribution_20261101_113310/`。这是离线归因，未新跑硬件。

- mandatory SC20(L1首/末C)、SC38(L2实际ReleaseData bank写)、SC21(ACK)可完整恢复
  6,735笔source6 release，每笔8个64bit word；其他source的bank事件明确排除。
  用line/pkg/generation/writer/source和完整L1 owner/entry/key/epoch/size配对；不单用地址。
- 软件ROI内完整2,231笔，normal1,793/SVB438。`[firstC,ACK)`阶段union100,915；
  lastC→firstbank67,366，连续8个写beat的首末边沿span15,617，末bank→ACK4,546。
  三段属于同一cohort，可相加为lastC→ACK87,529；不能相加head/retry等重叠计数。
- lastC→ACK median52/p99=65/max85。52-cycle mode1,405笔，10-cycle mode690笔。
  延迟主要在bank写启动前；与checkpoint的对应关系未证实。8次bank写连续不代表
  整段L2服务无排队。firstC在WB snapshot之后，不覆盖全部source保留生命周期。
- MSHR `s_wb_resp`等victim row capture完成，WB最后采集row时返回`io.resp`，
  不是直接等ReleaseAck。source/same-set后续准入可仍等ACK，需分清反馈路径。
- full Grant capture立即创建独立E责任（`io.mem_finish.valid=grantack.valid`），
  不必等metadata/install完成才发。普通read load已从LineBuffer提前返回，
  physical final-refill可能晚于load完成；不可用不同cohort均值相减造wakeup阶段。
- active DuplicatedDataArray的bank nack常0；独立逻辑读写不支持“所有refill堵所有hit”。
  6个full-line LB slots共享写优先read访问调度；每MSHR rowValid staging可序列化，
  但不是一个全局whole-line refill锁，也没有测到refill阻critical access的时长。
- L2 preservation是旧脏image checkpoint：capture前global drain停新C/D schedule，
  capture后锁目标set；SourceC读端在锁期间给checkpoint，其他set的D可继续。
  单引擎read/delay1/delay2/send使accepted A无stall时每4cycles一次，已开始的
  multibeat A在valid gap仍锁住arb。结构明确，但B无state/critical关联，预算unknown。
- direct headpending80,832不是全部cache-transfer、非head或checker完成反馈的全局UB。
  100,915也只是post-firstC阶段暴露，不是整个writeback机制UB或可恢复100k收益。
- optional prefix[698301,2192911)中release phase92,448，scheduler unavailable280,215，
  交集151。只限该阶段/该prefix；SC7不能恢复准确ROB noCommit或flag13每cycle变化。
  不把旧image contentSeq自动当请求者package。
- 无每miss A/D/port/owner timestamps，所有七段分解、critical/noncritical join保持null。
  native hist仅给quantile bin区间；top release不是top critical miss。
- histogram加精确cohort sum可收紧长尾duration：detect→data的22/1052个>=1024cycle样本
  累计duration在[169083,189549]（phase总和211045的80.12%..89.81%）。这不是ROI
  critical budget，duration可重叠/从ROI前开始，不能拿169k作为Tier1收益。

本轮：`CACHE_TRANSFER_MAJOR_BOTTLENECK=NOT_PROVEN`，whole-mechanism独立critical UB未知，
保守授予0收益，`MAIN_OPT5_CANDIDATE=NONE_JUSTIFIED`，`SUB1P5_NOT_SUPPORTED`，
`MORE_OFFLINE_ATTRIBUTION`；frontend保持LAST_RESORT。64KiB不是最终Opt5定义；
A/new B仍REFERENCE_COMPARISON/STRICT_PAIRING_PENDING，禁止机械执行历史A′命令。

复用工具：`analyze_opt5_cache_transfer.py`、`opt5_cache_transfer_reports.py`；
`test_opt5_cache_transfer.py`含21项CPU协议/边界测试。输出新目录，旧报告/日志/fixture保留。
未来仅在具体功能候选成立后，才将bounded phase/critical diagnostics与优化同版本验证；
不安排observation-only运行，不在缺关键join时用事件数乘任意penalty估收益。
