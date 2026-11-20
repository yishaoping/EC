# EC Performance-Only SVB / MSHR 筛选记录（2026-11-16）

冻结功能参考为 `4915b82` 中的 Performance-Only SVB/MSHR；完整 EC `8491167d`
及正在进行的 `4915b82` SSI_SpreadSLLs 实现均未改动。本轮工作区分支为
`ec-performance-only-physical-root-r4-20261116`。

## 当前可以和不能下的结论

截至补充验证时，唯一 Vivado 仍在第二轮 routing Phase 4.1。
日志重叠节点依次为 555609 → 98741 → 32224 → 14929 → 6352 → 3004 →
1512 → 922 → 575 → 384。这是中间路由器计数，不是最终合法性结果。

**898fda1 的实际 Vivado 模块 LUT/FF/MUXF 和新的完整 shell LUT 尚未取得。**
两把 CAD 锁仍归原控制器；模块综合在其退出和失败 DCP 只读提取之后自动接续。
完整 shell 的最后实测仍为 824809 LUT / 448466 FF，不把局部比较数折算成整机收益。

## 已完成的额外功能验证

- `svb-boundary-r4`：12 个 reset epoch、12288 周期，全部输出及原断言对照通过。
  实际发生 4269 次 capture、528 次 ACK、152 次 capture+ACK、489 次
  capture+select、1986 次 coalesce、1397 次 discard、7071 次 full fallback。
  flush 持有快照 900 周期，invalidate 时持有快照 132 次。
- 任意布尔硬件状态、仅 validity 初始化为 reset 值的关系归纳证明：2x64、
  4x8、3x16，包含任意覆盖写、reset、任意子集 kill。原 X 状态归纳不收敛的
  失败日志保留，未把有限周期测试称为全 SVB 形式等价。
- `svb-host-boundary-r2`：复用已完成的实际 Golden Gate RTL，无重复转换，
  2775 个 emulated target cycles；边界部分 128 条捕获、12 次精确 ACK，
  含 flush/invalidate、同 key/line、序号边界位型及真实 RAM token。
  故意破坏参考 payload 的负向测试检出 `SVB_HOST_MISMATCH`。
- 序号使用基线原始 unsigned 位序；测试 0、1、0xfffffffe、0xffffffff
  不表示新增协议回绕支持。Performance-Only 已删除的 architectural
  rollback/replay FSM 不在本次验证范围内；原 SVB invalidate/flush/reset 保留。

## 第一轮捕获排序关系：连接证据

`svb-unmapped-control-audit-r1.json` 基于实际生成 RTL 的 Yosys proc/opt 图，
按比较器两个输入确实连接的 slot key/line 分类，未用源码表达式计数替代网表。
这是**映射前算子图**，不是 Vivado primitive、LUT 或物理时延报告。

| 连接结构 | 4915b82 | 898fda1 |
|---|---:|---:|
| 常驻 slot-key 对 slot-key 64 位 less | 496 | 0 |
| 常驻 slot-key 对 slot-key 64 位 equal | 496 | 0 |
| incoming-key 对 slot-key 64 位 less/equal | 0 / 0 | 32 / 32 |
| 常驻 40 位 line 对 line equal | 496 | 496 |
| 新派生关系状态位 | 0 | 992 |
| key_0_contentSeq 每位最大直接算子端口消费者 | 73 | 13 |

992 个关系位均为无 reset 的 `$dffe`；496 个 enable 各驱动两个关系位。
因此该图没有出现“992 个派生位都接到一个共同 reset”结构。
capture-fire 在候选图连接 168 个直接算子端口；不能将这一数值与 FPGA
post-opt fanout 混用，也不能由此断言最终没有高扇出。

实际综合后，`module-cones.tcl` 会提取 primitive 类型、key 源 FF 的实际 Q
fanout、派生 FF 的 D/CE/reset 网络、比较输入逻辑锥、setup/min-path 估计。
未布局模块的 min/max 报告仅用于筛选，不能声称已修复整机 WHS。

## 第二轮：复用分配 one-hot（独立补丁，尚未采用）

生成 RTL 中，新关系状态使用 `32'h1 << io_allocatedEntry`；原 metadata
已有 `allocOH`。独立补丁 `svb-slot-local-r2.patch` 复用后者，消除表达式层的
encode/decode 往返；未修改 898fda1 生产源码。
该补丁使用零上下文，重放命令为 `git apply --unidiff-zero svb-slot-local-r2.patch`。

已通过：1/2/6/32 槽位分配译码的全输入 SAT，8192 周期全输出 SVB 对照，
12288 周期边界对照、关系归纳证明，实际 Golden Gate token 和负向控制，
以及独立 host 边界测试。复用 Verilator 对象时发现系统 glibc 与 Nix glibc
的 C23 链接不一致，已改用匹配的 Nix clang/sysroot 重新链接；原失败日志保留。

本候选目前**没有证明物理收益**：映射前关系 D 路径最大通用深度仍为 35，
MUX 算子计数 33→34，allocOH 单位最大算子端口消费者 3→4。这些不是物理
路径数据，但足以反对“少一个解码表达式就一定更快”的判断。
仅安排一次同口径 GG-control 映射，与第一轮实际报告比较；无明确网络或
资源收益即淘汰，不为此启动完整布局布线。

## MSHR / 40 位比较的准入

MSHR 六路选择器的固定优先级、无匹配时 bits/chosen 默认值、所有 ready 和
全部真实 payload 位已通过 n=1/2/6/8 的组合 SAT 与实际 GG token 对照。
未平衡和平衡 OR 两个版本均保留；最终只根据真实 LUT/MUXF、输出驱动类型
和控制 fanout 筛选。3,212 个下游负载没有删除，不宣称模块级 one-hot 已经
降低整机该网络的 fanout。若 req_addr/req_way_en 仍由 MUXF 驱动，不整合。

40 位 line clique 仍存在；line_0 每位有 37 个直接算子端口消费者。
这支持继续测量其成本，不足以直接增加另 496 位关系状态。
第三轮同线缓存保持未实施，等待前两轮映射与全量失败网络归因。

## 有界自动接续

原实现 → 失败时只读 DCP 全量取证 → 原定七个模块综合 → 实际模块逻辑锥
提取 → 第二轮单模块筛选 → 有证据的候选选择 → 完整 GG/post-opt → 一次
新网表的物理实现。每一步用 pidfd 等待前一个进程退出；没有周期巡检。

`screened-followthrough.py` 的保守自动准入规则写入 selection.json：
SVB 至少节省 500 LUT 且达到 10% 的控制 LUT，并有 >=512 CARRY8 或 >=20%
key 源 fanout 改善，新增 FF <=1200、不增加 RAM；MSHR 必须有可复制 LUT
输出驱动及实际 MUXF 减少。第二轮只有更大实测收益时替代第一轮。
准入不足则保存报告，禁止给未改变的网表自动再试布局策略。

完整 SVB＋MSHR balanced 组合的 Golden Gate 转换已经完成。外层 target 图审计已经通过：仅 SVB
和 `BoomMSHRFile/installArb` 两个已独立证明的边界不同，其余递归图相同。
整机参数及 host 外接口必须一致；不能将组件 token 证明冒充整机运行认证。

新网表最多自动尝试一次 SSI_SpreadSLLs；使用原严格时钟回放与最终准入逻辑，
host 99.960ns、DDR 3.332ns 保留，不导入失败的 placed/routed DCP。
setup/hold、合法布线、DRC/methodology 全通过才 write_bitstream。
bitstream 生成和 21-only 认证是两个独立状态，脚本不得把 pending 标为认证成功。

主证据目录：`/var/tmp/guozh-ec-physical-root-r4-20261116`。
持久证据/队列目录：
`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-physical-root-r4-20261116`。
