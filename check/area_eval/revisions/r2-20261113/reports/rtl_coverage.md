# 10 个独立 RTL 原语的机制覆盖审计

所有结论指向未经修改的 [palimpsest.sv](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv)。原测试通过意味着原语测试范围内成立；generic 可综合也不代表 Cache/SoC 集成成立。论文机制来源为 [DAC_2027_EC.txt:327](/data1/gzh/EC/check/area_eval/evidence/DAC_2027_EC.txt:327)（§IV-A）、:330（§IV-C）、:387（§IV-D）、:370（§IV-E）。本轮没有修补原 RTL，以下缺口仍然存在。

| 原语 | 已提供 | 接入缺口 / 对面积和行为的影响 | 证据 |
|---|---|---|---|
| pal_metadata_ram | packed synchronous sidecar，masked write | 没有字段bundle、cache valid/reset gating、tag/way bypass对齐；同一写数据只能广播到mask选中的ways，不能同拍清旧Cur并写新版本不同字段，需串行atomic更新或重做端口。多请求调度/宏wrapper未计 | [palimpsest.sv:8](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:8) |
| pal_evt | 历史interval截断、history-valid查询、有限容量拒绝 | 4-bit恢复Epoch/深度16无生命周期证明；没有reference GC/rebase；查询端口数量要随实际并行需求定；旧8-query不足16-way同时查询 | [palimpsest.sv:29](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:29) |
| pal_version_select | 单层set内Normal/Recovery选择，取max Seq&lt;boundary | 没有数据返回、跨L1/L2/SVB候选比较、下层promotion、CurGen原子更新；normal还依赖history_valid，须解决命中路径时序；多个Current仅报flag。现有Mux1H只允许一个tag hit，不能原样接入重复tag | [palimpsest.sv:75](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:75)；旧 [dcache.scala:646](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:646)；冻结 [Directory.scala:144](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:144) |
| pal_visibility | safe=history-valid且Seq≤producer SW；允许自身unsafe | 依赖外部可信producer/requester，必须遍历Get/Acquire/Probe/Release/AMO/uncached/DMA/DRAM每个出口及所有data beats；不是单个load信号相与即可。多producer SW查找未计 | [palimpsest.sv:107](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:107) |
| pal_store_policy | 同段in-place，否则选择reusable/victim，阻止未保全覆盖 | `victim_requires_history`/`secured`由外部提供，无保留策略；**新way部分写必须先复制/填充旧Current完整64B**，否则未写字节是旧垃圾。缺line-copy、mask合并、AMO/LRSC、异常/重放原子性及租约 | [palimpsest.sv:122](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:122)；真实部分写接点 [dcache.scala:905](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:905) |
| pal_preserve | 源锁、key/tid/type匹配ACK、cancel后等待已发事务完成 | 没有payload/目的way reservation/目的数据落盘；不能自行证明PreserveACK；只有所有WB共享该入口才能全局串行；缺obsolete未发WB抑制、跨路径每地址排序、drain/rebase。8-bit TID255后停止，ADDR40/key宽也未与实际物理地址契约统一 | [palimpsest.sv:159](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:159)；[limits-1.log](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/limits-1.log) |
| pal_lsl_reclaim | descriptor alloc、PASS+inputs_consumed、held release | 不含data/block allocator，8/checker无依据；缺holes reuse、rollback/cancel回收、stale release隔离。现有LSL已经消费即出队，必须先确认新增表必要性 | [palimpsest.sv:219](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:219)；[R_LSL.scala:119](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:119) |
| pal_safe_watermark | 有界PASS前缀、epoch过滤、静止rebase接口 | 没有回滚后保留旧epoch有效PASS与新结果的协调；WINDOW16与context8/32descriptors未统一admission；冻结已有256-entrybitmap，不应双重实例化 | [palimpsest.sv:285](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:285)；[dcache.scala:1741](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:1741) |
| pal_rollback | halt→flush→EVT→context→restart握手骨架 | fault请求没有epoch，旧FAIL可能触发新恢复；没有真实BOOM ARF/PRF/CSR恢复、rename map/freelist重建、ROB/LSQ/前端/旧响应drain；一般branch rollback不能代替提交段恢复 | [palimpsest.sv:317](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:317)；冻结主核CSR恢复仍tie-off [core.scala:2412](/data1/gzh/EC/firesim/final-opt4-20261106/C4/chipyard/generators/boom/src/main/scala/exu/core.scala:2412) |
| pal_context_store | 8×80×64流式写完才commit；按slot+seq+epoch读 | payload完整性、段边界原子capture、allocation/retention、实际恢复端口未实现；release只有slot，依赖可信allocator防止旧释放。PEEK checkpoint不是可自动替代的保留池 | [palimpsest.sv:357](/data1/gzh/EC/check/area_eval/rtl/palimpsest.sv:357)；[R_RSU.scala:60](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:60) |

## 机制层面的完成度

| 论文 Section IV 机制 | 状态 | 必须完成的闭环 |
|---|---|---|
| 跨层保存 / Preserve ACK | PARTIAL | L1源锁→reader→L2目的预留→历史payload+key原子安装→matching ACK→源复用；L2有victim时递归保存 |
| SW可见性 | PARTIAL | 对每条跨核/DRAM路径生效；SW来自完整可靠的checker结果前缀，回滚重建不混epoch |
| Safe DRAM版本与顺序 | PARTIAL | 最老/最新允许版本的WB抑制、逐地址ACK前串行、真实外层终端ACK契约；C.last/CacheGrant不是证明 |
| LSL提前回收 | PARTIAL / 基线语义待定 | PASS且输入不再需要后真实allocator释放，与恢复版本存储解耦；确认相对PEEK是否新增收益 |
| EVT / Epoch有效性 | 原语测试通过，系统PARTIAL | 跨Cache/MSHR/ACK/结果的身份一致；回绕/GC/重基准后还能长期运行 |
| 回滚Current重建 | PARTIAL | 查询整个可恢复域（含保留的SVB），选全局max-valid Seq&lt;n，再原子提升；只有证明无候选才取safe DRAM |
| Checkpoint恢复 | PARTIAL | 完整架构状态、PRF/rename/freelist/CSR/PC加载、kill旧请求、恢复执行结果一致 |
| Backpressure / 前进性 | PARTIAL | 真实early close/dispatch，资源预留、无环依赖、事务排空、bitmap/context准入；有限身份停止问题解决 |

源代码里的 `Scheduler.evict_safe/grant_safe` 是数据端口hazard互锁，不能拿来代替验证安全性（旧 [Scheduler.scala:329](/data1/gzh/EC/check/source/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala:329)）。冻结SVB/receipt实现提供了可复用接口，但没有由这些原语构成完整的Epoch/Current/architectural rollback链路。短测试明确观察有限容量停止，不是system liveness通过。新Seq32参数形态本轮完成generic检查；没有声称完成所有Seq32功能回归。
