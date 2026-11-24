# 同址安全基线发布

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

`HistoryValid(key.Seq) && CacheImage.safe(key, SW)` 是 authored 内容对外写的准入条件。当前恢复候选由最近存活的 `(Seq, serial)` 决定。已废弃字节不能靠改成 BASE 获得安全资格。Seq0 可信写只属于已约定的初始化和域外操作。

| 入口 | 实际顺序机制 |
|---|---|
| 缓存普通写和 AMO 跨段覆盖 | DCache 在允许新效果前复用整行 SVB 快照。旧段仍待验证时，S2 和 S3 通过同址驻留身份及快照许可确认安全覆盖。AMO 继续走原旧值返回和写终态路径。 |
| L1 victim / Probe / normal WB / recovery eviction | SVB 对地址的 `releaseBlocked` 保持至前驱的 archive exact ACK。 |
| L2 incoming C | 原两拍队列位于 SinkC 准入之前。只有 `sinkC.io.c.fire()` 才开始采集 authored C。已准入但未拼完以及等待 capture 的行都阻止直接 safe resident Put 和普通 dirty SourceC 抢跑。队列或暂存非空时，地址查询和维护 drain 继续等待。EVT 安装独立确认。 |
| Probe 与同组 History 发布 | 发布等整个 set 已发出的 refill、GrantAck 和 writeback 终态。若收据会改变 Probe 的驻留行，发布还等该 Probe 完成。不同 tag 或者比驻留内容更旧的收据不必等 Probe。 |
| Probe 与同址安全副本 | 已选中的同址安全 History 行持有完整数据。当其为同一版本或比驻留行更新时，允许 Probe 完成，不再发一次旧驻留行 Put。早于该 History 行的 Probe 数据仍结清 TileLink 响应，但不进入 History。外存 ACK 和目录收据完成后，MSHR 对落后的 hit 重新规划。 |
| 收据之后的迟到 C | 已完成外存确认的条目用现有 `image` 字段保留基线身份。当 `baselineObsolete` 置位时，bank 字节不能作读数来源。跟踪中的 C 完整行进 History 前复用目录读口查收据。旧版或同一版丢弃暂存，保留 C 协议终态。已有锁结束时用本次收据再次检查暂存。新版本仍可更新驻留行和归档。 |
| History publisher | 单索引选择最旧安全存活候选。SW 变化的当拍已经对 Scheduler 广告 `publishPending`。授权后保持完整外部 owner 到 ACK 和目录收据。 |
| direct preservation Put | 等当前安全 History 扫描、发布以及正在接收的 C 完成。未验证 resident 可走原 escape credit 存入 sidecar。 |
| 普通 SourceC / eviction / maintenance | 发射前检查该 victim 的安全资格、同址 C 收据、待发布历史和 set owner。dead 或已被精确收据覆盖的行可发权限 release。维护复用这条路径。History 压力通过原屏障请求 Main 封口，安全的 Checker victim 仍可完成外写和 ReleaseAck。 |
| 可信 A PutFull / PutPartial / Arithmetic / Logical | 在完成原 Probe/Grant/Release 后，复用共享索引扫描看同址 sidecar。命中未验证版本就把原请求和 Seq 停在 per-source 等待槽并让出 MSHR/set。只有结果有效且同址无剩余候选才进入 SourceD。扫描中和结果等待中，同址 ingress 或 EVT/SW 更新使结果失效。 |
| History ACK 后目录更新 | 通过单目录口按地址设置 `outerPreserved`，更旧 bytes 标 `baselineObsolete` 并保留确认的 key。后续 A 把其作为 victim，C 仍能结束原物理 owner。驻留目录只在持有该物理行时提供收据。 |
| 冷恢复查询与后继可信写 | 查询只是候选。Acquire 在既有 CacheImage 字段中携带候选身份；L2 在选择 SourceD 请求时按 bank SW 生成 CacheRecoverySafe，并随响应冻结。MSHR 在首个 Grant fire 时只使用该证书分类，不能用较新的 Main 本地 SW 推断旧响应。证书为真时采用 L2 排序后的真实 Grant，防止旧候选覆盖后继 host Put；为假时保留前驱。选择复用 recoveryActive/data 保持至安装结束。DCache 接收 MSHR 的同一 payload/key，不再次覆盖。Scheduler 的 publishPending 在其他 set 的 preservation 锁期间也保持 D 屏障。 |

代码入口见 `Scheduler.scala` 的 `bufferedC / pendingSafeBaseline / historyCCheckFire / trustedQuery / stage3Allowed / baselineState`，`MSHR.scala` 的 `residentHasSafeCopy / trustedWrite / parkTrusted / baselineCoversResident`，及 `PalimpsestVersionHistory` 的 `publishScan`。还需验证多个迁移及外写 owner 同时持有同址版本的整核组合。

可信主机写的旧整核反例与当前验证边界见
[冷恢复覆盖可信写](../../Debug/bugs/bug-palimpsest-trusted-refill-recovery.md)。

满C缓存的已接收数据保留原身份。后续EVT安装不等待其逐拍排空；数据最终进入
bank/History后仍按当前生存性处理。V6长期Baseline的tracked-C分支在Pending7、
Seq8四拍Probe、两拍队列满和BASE外写ACK背压下安装FAIL8→FAIL7；实际重查的
BtoN完成后只返回BASE，逐accepted外写beat也必须等于BASE。该用例通过且未修改
生产RTL；真实L1/多层迁移的覆盖边界见任务板与验证矩阵。

同址发布与回收已用长期`AI/Debug/scripts/baseline_publication/run.py`联合验收：

- 版本3外写ACK背压期间SW3→7，3/5/7依次得到实际外写/ACK，随后可信Put才生效，最终flush的可信字节不被旧历史回退。
- 同时加入迟到C6，接受的外写beat仍只包含3/5/7，C协议与保留的B权限正常终结，重取读/DRAM最终为7。
- ACK3背压期间capture安全9，可以合并未持有owner的5/7；原3的key/txn/bytes保持到精确ACK，随后只发9，最终查询无历史slot泄漏。

本批生产发布RTL不需修改。与固定来源Hierarchy的真实L1满C、Pending7、BASE外写ACK、FAIL8→FAIL7及既有SVB同Seq/EVT/WB_WAIT证据共同关闭P1-09和P3-10。其他迁移owner与压力仍按P1-03/P1-08/P4-08验收，不能由本项代替。

第四完整联合用例已在当前生产Stage3重新生成后长期入口实际PASS：同址
3/5/7、迟到C6与已接受Seq3外写ACK背压同时安装EVT5..8，然后推进SW8。
原Seq3 owner保持key/txn/bytes，死5/7/C6不出任何设备外写beat；精确ACK
后权限重规划、读和DRAM仍3，最终History查询无槽泄漏。这样将C迁移、
EVT/后台扫描、安全选择、真实外写终态及回收放在同一个硬件链中验证。
既有P1-09/P3-10通过范围扩大，额外L1/L2多迁移/压力任务仍保留原ID。


History发布继续排空同组已接受外层Grant及实际E。嵌套C可能等待该发布，因此Scheduler允许仅含E的现有调度包越过C/BC抢占；不放行附带数据、目录或park操作。真实refill延迟、C嵌套、完整发布及最终flush由grantack_preemption_test.cpp覆盖；完整Core最终验收已通过，证据见System_Acceptance。
