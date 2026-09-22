# 校验包物理地址十类统计设计

## 1. 统计边界

本设计只观察 BOOM 在 ROB 架构提交点提交的、可缓存的普通 `M_XRD` 和
`M_XWR`。LR/SC、AMO、MMIO 和 uncacheable 访问均不进入本统计。统计事件
携带完整物理地址、访问大小、load/store 类型和当前校验包序号；推测执行、
squash、nack 和 replay 不会直接产生事件。

所有指标分别按以下四种粒度独立计算：

1. byte：访问实际覆盖的每个字节；
2. word4：访问覆盖的每个 4-byte 对齐单元；
3. word8：访问覆盖的每个 8-byte 对齐单元；
4. cache line：访问覆盖的每个 DCache block。

“同一地址”始终表示同一粒度下的同一物理地址单元。不同粒度拥有独立的
`seen/first-op/last-op` 状态；不能把 byte 结果除以 4、8 或 line size 得到
其他粒度结果。

包 `p` 尚未安全的定义为 `p.seq > safePacketWatermark`。水位只跨过连续
PASS 的包。任一 FAIL、CANCELLED、包槽冲突、事件队列溢出、地址表溢出、
非法跨行访问或计数算术错误都会立即冻结本统计并清除 `stats_valid`；软件只
打印错误，不把冻结值当成有效样本。

## 2. 十类指标

### 第一类：每包唯一 store 地址总和

对每个 `(包, 地址单元)`，只要包内出现过一次 store 就贡献 1；包内后续
store 不重复计数。同一物理地址出现在不同包中时分别计数。四种粒度分别
输出全测量窗口总和。

### 第二类：未安全 store 地址在线峰值

当前值为所有尚未安全包的第一类包计数之和。包达到连续 PASS 水位时从
当前值扣除该包计数；记录整个测量窗口的最大值。只要统计保持有效，该峰值
精确。

### 第三类：load-first 后续被修改地址总量的上下界

对 `(包 p, 地址 a)`，包内第一次访问 `a` 时将其永久分类为 load-first 或
store-first。严格目标只统计 load-first 且后来被本包或后续包 store 的项。
一个 `(包, 地址)` 最多贡献一次；同一地址可为多个包分别贡献。

硬件输出：

- 下界：load-first 候选在包 `p` 仍未安全时已经观察到后续 store；
- 上界：所有已观察到后续 store 的候选，加上因地址表容量压力而提前回收的
  已安全候选。仍保留在表内、到测量结束也没有后续 store 的候选不计入上界。

因此始终有 `lower3 <= exact3 <= upper3`。相比把所有 load-first 候选都直接
作为上界，本方案会继续保留已安全候选；只有容量压力迫使其提前回收时才按
“可能在未来命中”计入上界，所以通常更紧。若候选一直保留到测量结束且没有
后续 store，则不会产生假阳性。

### 第四类：未安全 load-first 已修改地址在线峰值

store 提交时，检查所有仍未安全包对该地址的首次操作。若某包为 load-first
且此前尚未被计入，则该 `(包, 地址)` 加入在线量。包达到安全水位时扣除其
累计项。store 与水位在同一拍出现时按拍前水位判断，随后再结算水位。只要
关联表未溢出，该峰值精确。

### 第五类：store-first 后续被读取地址总量的上下界

第五类是第三类交换读写后的情况。对 `(包 p, 地址 a)`，只有包内第一次访问
`a` 是 store 才成为 store-first 候选；后来由本包或后续包对 `a` 执行 load 时
命中。一个 `(包, 地址)` 最多贡献一次，同一地址可为多个包分别贡献。

硬件输出与第三类对称：

- 下界：store-first 候选在包 `p` 仍未安全时已经观察到后续 load；
- 上界：所有已观察到后续 load 的候选，加上因容量压力提前回收的已安全候选。

因此始终有 `lower5 <= exact5 <= upper5`。包 2 的第一次访问是 store 时，仍按
包 2 的 store-first 候选处理，不受包 1 最后一次操作类型影响。

### 第六类：尚未安全的 store-first 后续 load 地址在线峰值

第五类下界首次命中的 `(包, 地址单位)` 计入该包桶。当前值为尚未安全包中
已确认 store-first 后续 load 地址的总和；包达到连续 PASS 安全水位时扣除该
包桶并记录最大值。该峰值精确，不受第五类上界中的容量近似影响。

### 第七类：首次 store 后连续 load 地址总量

第七类首先要求第五类的 store-first，然后要求该 store 之后的下一次同地址单位
操作就是 load。操作序列跨包连续：包边界不会切断“下一次同地址操作”的判断。
对其他地址的访问不影响本地址的连续性。第七类按 `(首次 store 所在包, 粒度,
地址单位)` 计数，直接输出精确总量，不需要上下界。

示例：

- 包1 `S(A)`，包2 `L(A)`：计包1的一项；
- 包1 `S(A)`，包2 `S(A), L(A)`：包1不计，若包2的 `S(A)` 是包2内第一次
  访问 A，则计包2的一项；
- 包1 `S(A), S(A), L(A)`：不计，因为首次 store 后的下一次同地址操作仍是
  store；
- 包1 `L(A), S(A), L(A)`：不计，因为包1内第一次访问 A 不是 store。

### 第八类：尚未安全的第七类地址在线峰值

第七类首次命中的 `(包, 地址单位)` 在其首次 store 所在包仍未安全时计入独立
包桶；按安全水位扣除并记录尚未安全部分的最大值。第七类和第八类四种粒度
分别独立精确计算。

### 第九类：第一次操作为 store 的地址单元总量

对每个 `(包 p, 地址单元)`，只有包内第一次访问该地址单元是 store 时计 1。
后续访问不改变分类，包内重复访问不重复计数；第一次是 load 的地址不计入。
四种粒度分别独立统计。

### 第十类：尚未安全的第一次 store 地址在线峰值

第九类地址在其所属包仍未安全时计入在线量，包达到连续 PASS 安全水位后扣除，
并记录在线量峰值。该峰值精确测量，不需要上下界。

同一粒度下通常满足：

```text
strict_write_read_peak <= store_first_peak <= first_store_peak <= store_peak
```

## 3. 硬件结构

LSU 在提交点最多产生 `coreWidth` 个有序事件。DCache 侧多入单出事件队列
保存事件发生时的安全水位，并按 ROB lane 顺序串行处理。处理器先追赶到事件
携带的水位，再处理该事件，从而保持“提交事件—安全水位”时间顺序；STOP
后继续排空，快照只在严格 store pending 和地址统计队列都清空后冻结。

普通包地址表按 `(packet_seq, physical line)` 查找，每个表项分别保存四种粒度的：

- `seen`：包内是否已经访问；
- `storeSeen`：第一、二类唯一 store 去重；
- `loadFirst`：第三类尚未由后续 store 确认的候选；
- `storeFirst`：第五类尚未由后续 load 确认的候选。

第九类直接使用 `newStoreFirstMask` 在首次 store 发生时结算，因此不需要额外的
地址表状态字段；其总量和按包在线桶独立保存。

每次访问会扫描同一物理行对应 set 的所有 way，因此可同时确认多个包留下的
第三/第五类候选。

同一提交事件可能同时命中多个包的候选；硬件先按候选所属包序号聚合增量，再
对每个包桶单次写回，避免多路寄存器写入造成后写覆盖前写而漏计。

第七类的 `strictStoreFirst` 不放在普通表中，而放在独立的 strict 主表中；主表使用
更高的 set 关联度，另有全局 strict 溢出表处理单个 hash set 的集中冲突。strict 表项的
唯一键仍是 `(packet_seq, physical line)`，掩码中的每一位对应一个粒度下的地址单元。
任意后续同地址 load/store 都清除对应候选，仅当该后续操作是 load 时增加第七类；这一
状态跨包保留。新候选在主表和溢出表之间采用互斥选择，避免同一 `(包, 行)` 同时占据两处。

表项保存完整物理行 tag，采用有限容量 set-associative 组织。优先回收无候选的
已安全表项；仍有第三/第五类候选但已经安全的表项可在容量压力下回收，并把
未决候选计入对应上界。strict 主表和溢出表中的候选不能近似回收。普通表、strict 主表
和 strict 溢出表都没有合法位置时统计失败并冻结，因而第七/八类不会因 hash collision
静默失真。

事件队列深度为 256，普通包地址表为 1024 set x 8 way，strict 主表为
1024 set x 16 way，并配置 64 项全局 strict 溢出表。它们都是有界的测量结构，
不是静默近似结构；容量不足都会令整次地址统计无效。START 当拍属于测量窗口，
STOP 当拍之后不再接收新事件，但会继续处理已经进入队列的事件并追赶安全水位。

## 4. 软件可见结果

每种粒度通过 RoCC 读取十项 64-bit 结果，另通过追加计数器读取第九、十类：

1. `store_total`（第一类）；
2. `store_peak`（第二类）；
3. `load_first_lower`（第三类下界）；
4. `load_first_upper`（第三类上界）；
5. `load_first_peak`（第四类）；
6. `store_first_lower`（第五类下界）；
7. `store_first_upper`（第五类上界）；
8. `store_first_peak`（第六类）；
9. `strict_write_read_total`（第七类）；
10. `strict_write_read_peak`（第八类）。

追加计数器 99--106：byte、word4、word8、line 各自的
`first_store_total`（第九类）和 `first_store_peak`（第十类）。

另导出 `stats_valid`、错误位图和未处理事件数。软件仅在 `stats_valid == 1`、
错误位图为零且 pending 为零时打印四行有效数据，否则打印诊断并判定本次
报告失败。

错误位图定义如下：

- bit 0：提交事件队列溢出；
- bit 1：包地址表目标 set 无可用 way；
- bit 2：保留，当前实现不使用；
- bit 3：包序号槽位冲突或顺序错误；
- bit 4：事件包序号非法或访问跨越 cache line；
- bit 5：64-bit 计数溢出或在线量扣减下溢；
- bit 6：包协议错误、FAIL 或 CANCELLED。

RoCC traffic-counter ABI 保留原有 0--55 不变。byte、word4、word8 和 line 的
十项结果分别从 56、66、76 和 86 开始；`stats_valid`、错误位图和 pending
分别位于 96、97 和 98；第九、十类追加在 99--106。

## 5. 实现位置

- `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`：在 ROB 提交点产生
  有序物理地址事件；
- `chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala`：事件
  队列、包地址表、包桶、十类计算和 fail-closed 诊断；
- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`：安全水位、错误信号、
  STOP 排空及 traffic-counter 快照集成；
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`：
  硬件 ABI 常量；
- `Software/Test/hw/ghe.h` 和 `Software/Test/stat/report.c`：软件 ABI、轮询、
  错误诊断和四粒度结果打印。
