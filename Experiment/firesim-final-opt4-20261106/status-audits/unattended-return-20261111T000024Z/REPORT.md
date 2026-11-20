# Opt4 无人值守返回只读核查

2026-11-11T08:00:24.917173+08:00

整机尚未 FIT：DUT 综合 LUT 3,131,870 / 1,303,680（240.23%），超出 1,828,190。顶层 post-opt 尚未产生，不能冒称最终 post-opt 判定。
当前实现服务处于顶层 link_design / Preparing netlist for logic optimization，不是 place/route 或 timing closure。
新增 DUT DCP 1,784,060,724 字节及顶层 shell DCP；精确版本和哈希见 audit.json。

| 候选 | LUT | CARRY8 | 相对第一fit地址 LUT变化 | 原状态统计是否正确 |
|---|---:|---:|---:|---|
| 9ae9a7fc | 990,905 | 55,418 | -33.96% | 否：以报告首个总量行核实 |
| aeabe5ab | 1,602,717 | 56,064 | +6.81% | 否：以报告首个总量行核实 |
| 579904b2 | 1,326,431 | 56,070 | -11.60% | 否：以报告首个总量行核实 |
| 64421513 | 1,262,145 | 32,861 | -15.89% | 否：以报告首个总量行核实 |
| 981b890d | 1,030,558 | 55,499 | -31.32% | 否：以报告首个总量行核实 |
| 470f1291 | 1,559,184 | 57,429 | +3.91% | 否：以报告首个总量行核实 |
| aca893e0 | 1,153,226 | 55,392 | -23.15% | 否：以报告首个总量行核实 |
| 11edd719 | 1,197,215 | 56,065 | -20.22% | 否：以报告首个总量行核实 |
| 67e6fa3c | 1,181,317 | 55,394 | -21.28% | 否：以报告首个总量行核实 |

所有候选数据为完整地址 OOC，不能替代整机容量；局部 SAT 与 6144周期/52输出回归不等于完整DUT形式等价。
最佳 9ae9a7fc：990,905 LUT / 55,418 CARRY8 / 0 DSP；比第一fit完整地址减少509,666 LUT（33.96%）。
没有派生认证bitstream，没有Opt4上板/正式样本；最新部署仍为历史21卡Native。
监督器11轮已退出（8轮退出0、3轮API截断退出1），第12轮仍执行；并未整体停止，不需要恢复/重启。
SSH代理同一进程昨夜仍存活；不能据此声称真正断链后模型网络独立。

## 异常与处理边界

- Mapped whole DUT LUTs exceed U280 by 1828190; top postopt verdict pending.
- Decode r1/r2/tag-read original zero resource fields are parser defects; authoritative report totals recorded separately.
- Three AI rounds failed upstream_truncated and later rounds resumed.
- Tagcompression failed ccache write permission; active round12 prepares separate cache-fix job.
- ledger.jsonl remains root:root 0644; completed CPU jobs may fail final event append after saving valid stage receipts.
- No demonstrated software fault injection plus architectural rollback/restart validation interface.
- Same SSH proxy owner remained alive; no actual SSH-disconnection survival of model transport proven.

本轮仅只读检查并新建这份独立审计证据，没有修改任务/源码/服务，没有向进程发信号，没有FPGA操作；Native仍暂停。

更新：tagcompression cache-fix r2虽然broker曾记录STARTED，实际已退出1；controller在外部证据manifest白名单校验处断言失败，未进入证明或模块综合。证据 `unattended-opt4/jobs/address-tagcompress-cachefix-r2-3fb8a7f7/{state.json,console.log}`。主优化器仍执行第12轮，未因单任务失败整体停止。
