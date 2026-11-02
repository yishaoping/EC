# 最多4项设计方向与风险：没有达到run准备门槛

| Rank | Mechanism | Critical UB | Conservative gain | Complexity | Risk | Confidence |
|---|---|---|---:|---|---|---|
| 1 | SourceC预约跨checkpoint waitAck → release/acquire HOL | UNKNOWN | 0 | 中 | coherence/borrow-port中高 | 静态路径高，关键预算低 |
| 2 | preservation pre-capture global C/D drain范围 | UNKNOWN | 0 | 中到高 | snapshot hazard/forward progress高 | 条件高，冗余部分未知 |
| 3 | outer A intrinsic multibeat gap | 局部fixed-slot≤34,104；整机制UNKNOWN | 0 | 中（buffer/pipeline） | TL packet/image中高 | 局部上界高，无主线资格 |
| 4 | locked高优先C阻低优先inner A ingress | UNKNOWN | 0 | 中 | C priority/order/deadlock高 | 静态路径高，发生次数低 |

## 1. SourceC waitAck交还端口：优先继续离线审查

- RTL modules：Scheduler、L2Preservation状态/borrow信号，SourceC hazard与MSHR release/acquire。
- changed state/signals（设计，未实现）：以“checkpoint仍可能读bank”的专用phase信号控制borrow，而不是整个lock.valid；waitAck时允许非locked set的SourceC schedule/read。engine直到ACK不接受新snapshot，target-set锁全程保留。
- correctness invariant：旧image完整8beats已accepted；source2/txn/size/terminalACK原样；target set bank/dir不可mutation；无关SourceC使用自己的safe image与source0/1；matching receipt不能race mutation。
- ordering风险：SourceC pipeline可越过preservation ACK但只不同set，需核对directory/nestedWB/SourceD grantsafe/evictsafe及下一capture前重排空；不能仅改一个ready忽略schedule gate。
- TL/protocol：末A已发送不意味terminalACK已到；target锁不可释放。CacheCork C转A有自己的packet仲裁，不能让C打断仍未完全发完的checkpoint packet。
- SVB/preservation：SVB source/ACK身份、下级版本义务保持；正常victim外发安全watermark与ReleaseAck合同不变。
- area：专用phase predicate/少量控制为目标，无容量/way/MSHR/端口增加；timing：多一层schedule/borrow选择，需检查ready路径与组合环，尚未编译/生成。
- expected gain/whole UB UNKNOWN、conservative0；静态链可信，运行主因未证。

## 2. 更窄的pre-capture drain

将global idle条件收敛为目标set/way相关在途read/write排空，同时允许无关SourceD schedule。需全4stage、skid、SinkC队列及borrow读pipeline身份，不能只看MSHR set；Directory与bank跨phase hazard、write-after-read/old-image稳定和engine starvation都需证明。新增比较/scoreboard、timing/ordering风险较高，无已测预算。不是当前可低风险落地patch。

## 3. 连续发送checkpoint，保留整个TL packet锁

L2Preservation先流水读入64B bounded buffer再burst，或合法深度的小skid预取；不在beat间插入其他source。buffer512bit+控制、不新增SRAM port目标，可能增bank竞争/首beat等待；保留immutable image、target-set至terminalACK。intrinsic gap删除局部上界34,104，不足50k，不准备主线；bank/ready延迟不能由该上界或设计免费解决。

## 4. locked C入口HOL bypass

Scheduler入口优先Mux可以评估跳过暂不可服务高优先C，让其他set A前进。需证明C packet held稳定、同set order、C请求与其后data buffer/list、一致性break-deadlock优先关系；incoming source不能在未fire前推进。无新增大queue为目标，但组合仲裁和循环风险不低。统计应测“C selected but locked AND otherwise admissible A”，不是所有C.valid。

不提出“packet锁到ACK前释放”“per-source允许A beat交错”“用4子bank拆4个outerA”方案：前者已如此，后两者不符合当前物理/协议。所有方向均未改硬件，NONE_JUSTIFIED。
