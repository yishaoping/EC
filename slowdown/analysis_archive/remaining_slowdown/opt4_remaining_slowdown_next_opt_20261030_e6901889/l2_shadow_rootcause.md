# L2 S0 failure：event语义与read-consistency根因

状态：已确认旧observer存在结构性时序保真缺陷；没有原始顺序可将本次40,220个excess miss逐个归因。
旧L2 S0 access42,225、hit1,856、miss40,369；实际directory hit42,076、miss149。
sanity FAIL；所有旧L2替代geometry结果均不可用。

## 42,225究竟是什么

|硬件观察点|旧host定义|本次值与解释|
|---|---|---|
|directory.result.valid && A优先级 && !control && opcode!=Hint|event1 / actual.access / shadow.access|42,225；包含reload/relookup，覆盖该L2的全部inner clients|
|同一event的opcode分类|loads/stores|40,454 /1,771；Acquire分类不等于CPU load/store语义|
|同一directory result的hit位|actual.hit/miss|42,076 /149；tag存在定义，并非每笔A事务最终无stall|
|inner A first beat fire|request_a|42,227；与access相差2，缺少分项证据，不能断言恰是两个Hint|
|inner C first beat fire|request_c|2,313；不进入上述demand access分母|
|C ReleaseData|event12 silent fill|为替代模型提供可能的C-only安装/dirty信息，不增加demand access|
|directory.write.fire|event5 metadata mirror更新|accepted queue input，不保证是同一lookup所见RAM状态|
|outer A Get/AcquireBlock first|memory reads|149 /9,536B；transaction不是beat|
|outer A Put或outer C ReleaseData first|memory writes|1,672 /107,008B；不是全部CPU store|

真实geometry 1MiB/1,024sets/16ways/64B/1bank；4个scheduler MSHR包含保留通道。
它们可服务directory hit和C事务，所以198,055 entry-cycles/149绝不是miss latency。

## 已证明的坏不变量

旧host在**接受directory写入**时更新latest-write mirror。
真实Directory经过一项write queue、单端口RAM read/write仲裁、可选dirReg和pending-write bypass。
delayed lookup的read image不能由“当前最新accepted写入状态”唯一推出。
source：`Directory.scala`的`Queue(io.write,1)`、`write.ready:=!io.read.valid`、
`regout/tag/set`延迟与`setQuash`；旧Scheduler event5却使用`directory.io.write.fire()`。

离线CPU fixture构造：同way先A、再接受B，当前lookup仍见A的read-consistent image；
latest-write mirror判A miss，snapshot独立tag比较判hit，重现**模型false miss**。
这是对observer不变量缺陷的可执行反例，不是旧run中某个具体transaction的第一分歧记录。
40,369−149=40,220，不能宣称已证明全部由该机制解释。

## 其他假设逐项结论

- Acquire/Release：A-priority lookup与C-first计数分开；不能拿42,225当BOOM-only L1 demand数。
- demand/writeback：C-only填充与dirty状态会影响替代模型，但不应污染demand分母；已保留独立通道。
- Probe/Release：原始metadata和C事件顺序未保存，无法逐事务排除其残余建模问题。
- address canonicalization：旧路径expand后没有一致restore；修复统一用restoreAddress(expandAddress(...))。无法证明它解释本次数量级。
- request replay：directory relookup有意计数；不是自动按TileLink source去重的一次端到端request。
- bank/channel：当前1bank，instance以bank区分；未发现“多bank相加”证据。下一版独立请求key审计避免混键。
- hit定义：actual来自directory hit；新S0从同一次read的各way有效tag自行比较，不复制actual.hit。
- cold start：旧host clear_stats保留mirror/tags，warmup metadata仍被跟踪；不能简单用冷启动解释大规模偏差。
- duplicate TileLink beats：A/C/outer采用first-beat；demand来自directory result，不是每beat采样。reload是不同语义，仍需保留。

## 当前run能否重算

不能。只保存最终cache summaries、per-set aggregate、SC lifecycle/C→bank fingerprint，
没有完整的directory read/accepted write/queue drain/A/C顺序与way snapshot。
hash证明数据链，不携带完整tag时序。当前也没有成功run的原始diagnostic ring（成功后丢弃）。
不拼造缺失事件，不把改过的observer追认成旧run已经PASS，不使用旧S1/S2/S3数字作扩容收益。

真实replacement36、dirty35、metadata replacement6、set-full lookup0、观察到valid ways最高8/16；
这些并未显示强容量/ways压力。L2 geometry无充分扩容依据。
`L2_GEOMETRY_DEFERRED_UNTIL_NEXT_FUNCTIONAL_RUN`；禁止L2-only观察实验。
