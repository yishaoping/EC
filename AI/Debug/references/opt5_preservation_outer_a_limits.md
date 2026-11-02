# Preservation / outer-A attribution：已闭合的锁语义与仍缺的运行链

报告：`AI/TMP/opt5_preservation_outerA_attribution_20261101_135133/`，完成B身份仍是
`optimization_4_svb_20261031_024551_8fbf8937`，A/newB reference-only，未跑A′。

- outer A packet锁是TLArbiter beatsLeft，首Put accepted后至末A accepted清0，
  **不覆盖pre-capture drain或waitAck**。target-set preservation锁才至terminalACK。
  generated普通A ready只看io_out_a_ready、idle、preservation.a.valid、state_1，
  无target lock或ACK输入。不能设计“将outer packet锁从ACK提前释放”的伪修复。
- SourceA只有AcquireBlock/Perm，内部depth2 FIFO；inner Get hit走SourceD，不经outerA。
  一个连续packet锁中FIFO不dequeue，直接呈现的unique normal head最多1个；反复valid
  不是新请求/retry。队尾/内层需求仍可间接受阻，运行amplification分子/分母均未知。
- 单packet固定read/delay gap slots为7×3=21，较大traffic窗口memory writes1623含
  checkpoint A及SourceC data C，checkpoint firstA≤1623；singleton允许carry-in≤1。
  **只删固定gap的fixed-trace slot UB≤34,104**。不是全部lock/preservation UB，
  不含bank stall、ready-low、drain、waitAck或时序反馈。局部<50k，停止作为Opt5主线。
- 真正跨ACK的全局预约在SourceC：Scheduler stage3Allowed的C分支要求!lock；
  SourceC.bs_adr.ready也要求!lock。checkpoint waitAck不再需bank读，却仍挡无关set
  victim Release。MSHR A valid要求s_release&&w_releaseack，因此可形成
  **checkpoint waitAck→全局SourceC预约→unrelated victim Release→Acquire HOL**。
  这是静态可能链，未证明B发生次数/critical预算；下一离线对象，未patch。
- candidate在resident/schedule/firstProbe输入组合创建，snapshot仅capture一份，
  引发者可以ReleaseData、ProbeAckData或trusted A写。首C就能触发req，candidate可能
  在lastC之前；T1–T5不能当统一正时间串行分解。SC38是新image实际写，不是旧image
  checkpoint读。incoming image seq也不是resident image或请求者package。
- checkpoint借SourceC bank端优先级仅低于SinkC，normal SinkD/SourceD不能从该arb
  饿死它。SinkC可有noop reservation/valid gap，不能用Probe包数×8上限bank阻塞。
- target-set锁已per-set，但入口priority Mux先选C再检查locked，可对无关A造成HOL；
  与SourceC预约、CacheCork的C→A优先、多beat arb分别分析，不能合为一个global A锁。
- 67,366 prebank duration仍可测，内部capture/drain/arb/ACK未保存，UB1–UB4、真实
  preservation/lock top20、blocked request→ROB链保持null。只列20笔真实release代理。
  optional prefix prebank×scheduler=94cycles，非outer lock correlation。
- direct headmiss交集union≤53,845/all headpending≤80,832是局部包络，不是非head/
  checker整个传输收益全局UB；unknown不允许选择>=100k candidate。

结论：AMPLIFICATION_PROVEN=NOT_PROVEN、MAIN_MECHANISM/OPT5_STATUS=NONE_JUSTIFIED，
SUB1P5_FEASIBILITY=NOT_SUPPORTED，独立critical UB未知、保守credit0，frontend LAST_RESORT。
NEXT_ACTION=MOVE_TO_NEXT_OFFLINE_BOTTLENECK，下一对象SourceC waitAck预约/release-acquire
HOL，再看L2入口/SourceD，尚无正式功能run。仅未来成立候选才把episode counter/top20
与优化同版验证；无observation-only。没有硬件生成/build/仿真/硬件修改或清理。

工具：`analyze_opt5_preservation_outer_a.py`和renderer；
`test_opt5_preservation_outer_a.py` 19项CPU测试。CPU contract witness是结构反例，
不是运行trace/RTL仿真，不能将其中32/70cycle用于B动态结论。
