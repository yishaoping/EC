# 源码审查与成对设计

审查先于 instrumentation 修改。Opt4 有效ROI1,707,863只是历史sanity，不作为新paired A。
A=Opt4/SVB16 +256sets/2way/64B/6MSHR；B只将BOOM L1D sets改512，容量32→64KiB。
配置通过 v1Config 外层 BOOM-only tile参数覆盖；不修改checker caches。

源码选择numDCacheBanks=1的BoomDuplicatedDataArray，SRAM深度nSets*refillCycles；
增加sets不添加流水寄存器，逻辑读响应级数、metadata read、replacement policy、64B refill、
MSHR6、bank数量均保持。index8→9bits，tag少1bit，data/逐line metadata容量翻倍。
真实物理hit timing/layout/能耗不由cycle模拟证明；绝不宣称频率或1-cycle物理访问保证。

已有：unique S2 token lookup、MSHR owner occupancy、actual admission primary/secondary/upgrade、
refill handshake、LSU request token/LDQ/ROB IDs、matched load response/nack、RPQ replay和ROB busy。
上一轮kind40–45是activity/粗ROB交集，没有miss-token→head的直接关联和服务histogram。
现有com_load_is_at_rob_head还延迟1cycle且不携带identity，不能用于精确同cycle关联。

必要新增：只读ROB首valid bank的busy load身份bore，LSU校验LDQ incarnation/functional token，
DCache复用既有CacheOpportunity DPI发送不落盘的有限事件，host只保留64个LDQ/STQ槽和6MSHR状态；
统计精确同cycle head-miss/MSHR/scheduler交集、allocation/merge/reject/refill、RPQ replay与nack retry、
三类latency histogram、返回时是否仍为head blocker。窗口跨界和未完成项明确censor。
不新增SC observer identity（现127/128），不输出无界trace。保留read-consistent L2 snapshot与STOP counters。

复用现有launch_optimization_4_svb.py的generation/build/capture/postanalysis链，只加严格sealed causal arm模式，
保留原Opt4默认guard。A/B两种Config源码同时存在且整个实验锁定相同source fingerprint；只选不同Config。
seed=1、maxcycles500000000、软件ELF/loadmem哈希、仿真参数、clock/checkers、ROI软件定义完全一致。
先完成离线/类型/observer/counter tests，再生成RTL/build，真实跑A和B各一次。

## Geometry-dependent maintenance timing

`rocket/HellaCache.scala:L1MetadataArray` uses `rst_cnt < nSets` and writes one metadata set per reset cycle. A/B therefore have 256/512-set initialization sweeps; B has 256 additional initial metadata-reset cycles. The same reset/software warmup definition is retained, and the actual rdcycle ROI boundaries are measured independently for each arm rather than forced to identical absolute cycle numbers. This intrinsic geometry initialization change does not insert a hit-pipeline stage. The BOOM cross-package freeze continues to select its existing pending set/line (`clearFreezeSet`); no new full-cache sweep or policy is added. Array depths and per-line register state grow with sets, so physical fanout/SRAM timing and host build/runtime cost may change even though modeled hit/refill pipeline registers do not.
