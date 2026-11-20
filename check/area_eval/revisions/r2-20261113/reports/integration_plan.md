# PALIMPSEST 最小完整集成方案（设计产物，尚未修改源码）

主分支建议从冻结 `firesim/final-opt4-20261106/C4/chipyard` 派生隔离实现，保持1 MiB/16-way几何；旧 `check/source` 用于PEEK机制取证，不直接将其512KiB构建与冻结实验相比较。本轮只制定方案和声明配置，未创建/执行新SoC build。

## 1. 三个编译变体与归属

在同一源版本、参数集和约束下增加互斥保护模式：`Unprotected`、`PEEK`、`PALIMPSEST`，统一 [matched_profiles.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/config/matched_profiles.json)。先单独隔离measurement-only counters/observer，三个变体共同排除。PEEK模式保留原snapshot/transport/LSL/checker验证，显式关闭新增EC recovery/SVB/barrier路径；PAL模式逐项复用或替换这些路径。当前冻结EC不能直接重命名为PEEK。所有 enable必须在generated hierarchy证明实际移除/保留，并保存配置hash与参数、宏清单。

对冻结现有字段建立 ownership 表：Seq32共用；CacheImageKey81保留还是替换须协议决定；slotEpoch16/sessionEpoch与RecoveryEpoch分开；SW/bitmap只留一个权威来源；SVB数据一份；PEEK capture和checker snapshot每个现有消费者一份；新增retained context只按净变化。没有完成该表前不发布净面积。

## 2. 统一接口契约

| 接口 | 必须携带与握手语义 | 原型之外的工作 |
|---|---|---|
| SegmentResult | producer、Seq32、恢复Epoch、PASS/FAIL/CANCEL、inputs_consumed，valid/ready | 会话epoch不是恢复epoch；CDC消息不能是裸脉冲，旧结果仅影响其本身资源 |
| CommittedStoreIdentity | Seq32、恢复Epoch、owner、字节mask、AMO/effect token | 段归属在架构边界确定并随STQ/replay持有；不能在晚到DCache写时读取实时段号 |
| PreserveReq | line address、不可变版本key、源/目的reservation、tid、kind、full64B/beat序号与最后拍 | 先预留目的与数据通路，再迁移；阻塞期间源数据与key不可变化 |
| PreserveAck | 完整key+tid+kind、目的已持久占有/有效、失败/取消状态 | 仅目的数据+metadata原子可用才ACK；旧ACK不能解锁新way或新epoch |
| SafeWBReq / WBAck | 地址、版本key、数据/beat、tid、终端response | 区分PreserveACK、ReleaseAck、外部write终端ACK；同地址旧事务终结前不得放行后继 |
| RecoveryLookup | address、boundary、恢复epoch/gen、各层candidate seq/key/data/valid，request-id | 先查L1/L2/保留SVB再比较全局max；没有候选的证明先于DRAM fallback |
| ContextCapture/Restore | 完整payload定义、slot、Seq/Epoch、begin/word/commit、restoreDone | 周期边界一致；旧release需身份验证；restoreDone必须来自真实架构状态完成 |
| Quiesce/Rebase | 停止准入、drain各层MSHR/probe/WB/CDC、所有旧引用归零的ACK | 处理Seq/Epoch/CurGen/TID耗尽；不能清零计数器后允许旧消息重新命中 |

最小实现可先串行：一个全局跨层preserve/WB调度器、一个恢复查询（最多16-way）、一个context stream。这样降低CAM/多端口复杂度，但要确保早派段/验证/ACK不等待同一被占资源；这种串行化会改变性能，必须用同实现重测性能，不能沿用多并行路径数据。保留有限队列并对容量施加admission反压，不能靠“通常不满”。

## 3. 修改接点和每个模块的连接

| 新增/复用模块 | 现有源码接点 | 最小修改与尚缺信号 |
|---|---|---|
| Seq/Epoch与段准入 | [R_IC.scala:211](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:211)；[lsu.scala:295](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/lsu.scala:295)、:1093、:2040 | 复用现有packet_seq通路，核对issue→commit→重放段边界；添加恢复epoch，统一SW/context/LSL窗口准入；early-close请求真正到R_IC并排空提交快照 |
| pal_metadata_ram | [dcache.scala:709](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:709)；[Directory.scala:74](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:74) | 先选择字段复用/重构，再和existing meta/valid/tag/dirty同一事务更新；增加冲突仲裁、同步读对齐、read/write bypass、宏wrapper。多way不同字段更新需要atomic序列或新端口 |
| pal_version_select | 旧L1 tag/permission [dcache.scala:622](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:622)；冻结L2 [Directory.scala:144](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:144) | 原Mux1H前用Current/valid/history筛选；历史重复tag不当普通coherence副本；Recovery返回候选并跨层比较；新Current升格原子化 |
| pal_store_policy + line-copy engine（缺失） | 旧L1 [dcache.scala:905](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:905)；冻结L1源身份/租约 [dcache.scala:720](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:720) | 新段首次partial store先full-line copy/merge到新way；控制source/dest lease，处理同set、ECC、probe、refill、AMO、LR/SC、跨行拆分和rollback取消；原型没有该data engine |
| pal_preserve + reader/receipt | 冻结 [dcache.scala:26](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:26)、:194、:278、:631；[speculative-version-buffer.scala:79](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala:79) | 复用WB reader/SVB immutable snapshot和matching completion；补跨层历史way目的预留及保留决策；把32位真实key/TID方案与原型8位耗尽协调；不能只有source_locked |
| L2 preserve scheduler | [Directory.scala:28](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:28)；[MSHR.scala:37](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala:37)；[Scheduler.scala:802](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:802) | Directory read/result从one winner扩展可恢复候选；MSHR/Schedule携带版本与租约；BankedStore读写beat、atomic metadata commit后ACK；历史项不向普通sharer广播为Current |
| pal_visibility | 冻结 [CacheImage.scala:25](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala:25)；L1 probe/WB和L2各Source/Sink | 复用producer key和SW，扩展恢复history-valid；区分own、checker、DMA、external，覆盖所有数据和permission出口，AMO返回旧字节也必须安全 |
| Safe DRAM WB manager（缺失） | [SourceC.scala:108](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceC.scala:108)；[ToAXI4.scala:233](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/tilelink/ToAXI4.scala:233) | 审核TL-C/CacheCork/外部manager→AXI-B实际路径；按地址抑制obsolete未发WB、保序到terminalAck，跟踪错误/取消/旧epoch排空。AXI-B是控制器完成契约，并非非易失掉电持久性 |
| pal_safe_watermark / EVT | 冻结 [dcache.scala:737](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:737)、:1745；原型 [palimpsest.sv:29](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:29)、[palimpsest.sv:285](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:285) | 只用一个SW前缀authority；对PASS hole、FAIL、旧epoch、已发WB的关系建立不变量。EVT使用仲裁共享16query或重新算端口；加GC/排空重基准 |
| pal_lsl_reclaim | 冻结 [R_LSL.scala:69](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:69)；旧dequeue [R_LSL.scala:119](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:119) | 先明确消费即释放的FIFO和恢复日志区别；若现有LSL不保留历史则不新增32个表项，仅补真实所需的描述符。若block allocator重做，需holes/cancel/free路径和CDC ACK |
| pal_context_store | [core.scala:2074](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/exu/core.scala:2074)；PEEK [R_RSU.scala:60](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:60) | 复用RSU捕获流，保留池按admission上限定容；保留段起点不是任意时刻采样；核对全部ISA/OS状态、capture commit与slot release身份 |
| pal_rollback + restore adapters（缺失） | 冻结 [core.scala:2412](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/exu/core.scala:2412)；ROB、`exu/rename/rename-stage.scala`、`rename-maptable.scala`、`rename-freelist.scala`、`register-read/regfile.scala` | halt准入，kill未提交和旧epoch效果，drain已接受事务；清ROB/LSQ/忙位，恢复ARF/FP/CSR/PC，重建rename/freelist/PRF约定；epoch更新后才restart，ordinary branch rollback不够 |

所有表中“复用”均为待实现的明确方案，不代表本轮完成连接。需逐个实际验证frozen接口，不能将旧版行号直接作为补丁位置。

## 4. 最小依赖顺序与验收测试

| 阶段 | 最小交付 | 功能测试 / 不变量 | 完成判据 |
|---|---|---|---|
| A：统一基线 | 三模式同参数、production边界、字段ownership、payload及准入证明 | 自动比对generated core/cache/memory参数；每块资源只归一个owner | 参数manifest一致，差异仅保护逻辑；当前尚未完成 |
| B：L1多版本 | meta/selector/store+full-line copy+租约，先2-way | 两段写同地址不同字节，未写字节保持；duplicate tag、same-set conflict、AMO/LRSC、refill/probe/replay、source/dest并发rollback | 与逐字节参考模型一致，无多Current/早复用 |
| C：跨层保存/可见性 | L1→L2→safe外存闭环，shared transaction arbiter | A8→保存A7→L2 victimD6不安全→等待SW→WB终端ACK→PreserveACK；checker/DMA请求unsafe必须阻塞；旧ACK/重复ACK/乱序ACK | 所有path逐拍检查key/data，source hold到matchingACK，无unsafe外泄 |
| D：LSL/context | 生命周期分离、bounded admission、real allocator | PASS乱序/FAIL/Cancel、输入尚未消耗、holes、FIFO消耗、所有slot满、capture中断 | 无丢日志/早释放/永久占位；8slots是否够用有上界证明 |
| E：恢复闭环 | 完整checkpoint恢复、EVT、跨层max候选和Cur提升 | 段8失败选A7而非DRAMA1；不同层/SVB的较新候选、连续两次rollback、旧FAIL/response、无候选safe fallback、trap/CSR/页表/中断、PRF复用 | 与checkpoint参考执行得到相同架构状态和内存；不是只有restoreDone脉冲 |
| F：前进性 | early dispatch、drain/rebase、全资源饱和模型 | 超过15rollbacks、255preserves、255CurGen；seq边界；bitmap满、context满、SVB满、MSHR/probe竞争、64B隔离timer flags | 在公平ACK/checker假设下持续完成，或有明确可恢复的受控排空；有限ID不永久停机 |
| G：物理面积 | 同库同PVT同约束三基线，真实macro映射 | 未映射memory检查，macro读写/mask/latency契约，STA setup/hold和约束覆盖；防DCE删保护状态 | 标准单元+各macro分表及总计，PPA日志/网表/脚本/hash可复现 |

本轮只做了原语资源与有限容量特性验证；A–G没有被整体完成。无需先跑PARSEC或完整综合就可开展B–F的小型cache/coherence测试，但发表系统综合必须在闭环后运行G。性能/latency实验应使用G相同机制和并行度的可执行模型；串行最小实现的面积不能配用另一吞吐实现的性能结果。

## 5. 最终面积报告应保存的证据

三模式的源码commit/patch、配置manifest、generated RTL及memory清单；同一标准单元库/28nm工艺与PVT、SRAM宏型号/端口/面积表、synthesis constraints、compile和area原始日志、被排除observer清单、timing coverage及STA、必要的clock/CDC约束。分别给出标准单元面积、L1/L2 data/tag宏、checkpoint/LSL宏和总面积；统一计算 `Δ=A_PAL−A_PEEK` 及 `Δ/A_PEEK`。保留外部DRAM的容量/时序模型描述，但不把16GiB外部颗粒计入SoC mm²。
