# Outer A lock的精确定义

**三种锁/预约不同生命周期**：

| 资源 | 建立 | 释放 | 范围 | 阻塞对象 |
|---|---|---|---|---|
| preservation target-set | capture组合边沿或state!=idle | matching terminal ACK完成后state回idle | 当前L2 scheduler中一个set，B只有一个cache bank | 该set新request、MSHR schedule及物理mutation |
| outer A packet `beatsLeft` | idle且下游ready接受首个checkpoint A，剩余7beats | 最后A accepted减到0，**不等ACK** | 此Scheduler outer-A输出per-transaction，全set/source共享 | 唯一SourceA输出head；packet间隙也不能插入另一A |
| SourceC预约 | `preservation.lock.valid`（含capture→waitAck） | terminal ACK后lock清 | 当前scheduler的SourceC模块/借用data读port，跨全部set | 所有SourceC schedule与read ready，包含已不需bank的waitAck |

源码 TLArbiter88–125：`idle=beatsLeft==0`，`latch=idle&&sink.ready`；`beatsLeft=Mux(latch,initBeats,beatsLeft-sink.fire)`；非idle只给已选择state的ready。generated Scheduler中普通A精确ready为：

```text
SourceA.io.a.ready = io_out_a_ready & (idle ? ~preservation_io_a_valid : state_1)
```

该方程**没有preservation.lock、ACK或drainForCheckpoint输入**。L2Preservation在final A fire后state=waitAck/a.valid=0；下个cycle packet idle，normal SourceA可fire，同时target-set仍锁住。CPU contract witness中A fires4,8,…,32，cycle33可normal A，terminalACK可等到70；这是结构反例，非B实际时间。

packet保护多beat消息边界，TileLink A没有可将两个事务data交错后重新恢复的beat索引。不能“每发一beat放锁”或给不同source/set插队；source字段不同也不能豁免multibeat规则。当前B只有一个L2 bank，不能将4个SRAM subbanks误作4条outer-A输出；per-subbank A锁不能绕开单一TL通道。

lock前bank read/delay期间a.valid=0，normal A可通行；已开始packet后后续read/delay/state send ready-low均可空转保持beatsLeft。无stall accepted beat间4cycles，首末span28，内含21个强制read/delay gap slots；bank等待和下游ready-low能再拉长，未保存runtime时长。

**请求类型**：SourceA只构造AcquireBlock/AcquirePerm，无payload、单beat。inner Get hit经SourceD回包，不经过该outer arb；Get miss引起outer Acquire，随后CacheCork转Get；升级可被CacheCork本地Grant，不一定到DRAM。不能将inner Get38,633或Acquire1,914全当被outerA阻塞的请求。

CacheCork还有**第二个**A packet仲裁：SourceC ReleaseData转Put优先，原A次之；那是下游normal eviction/C→A竞争，与本Scheduler checkpoint packet锁不同。memory ready可经Cork返回，因此“outerA ready低”也不能单凭一根线归给preservation。

运行量 `OUTER_A_LOCK_CYCLES/EPISODES/MAX/P90/P99` 均null；没有beatsLeft/fire边沿。normal SourceA本身无multi-data lock，Release走C，checkpoint Put是本Scheduler A arb唯一已知multibeat数据源；不能把它们当六种互斥实测原因计数。target-set active计数器存在于RTL但B未输出，不得读source初始化值替代runtime值。
