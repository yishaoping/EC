# Opt5 cache-transfer attribution — 尚未证明足够大的可恢复关键路径

本轮新增的直接证据是：完整恢复 B 的 **6,735** 笔 BOOM voluntary ReleaseData，逐笔连接 L1 C 首/末 beat → L2 实际 bank 写入 → L1 ReleaseAck；全部 8/8 word 覆盖、身份与生命周期检查通过。软件 ROI 内完整事务 **2,231** 笔，首 C → ACK 的阶段区间并集 **100,915 cycles**。

这段延迟主要位于 **最后 C beat → 首个 L2 bank 写入**。每笔最终 8 次 bank 写入连续，末次写入 → ACK 中位数 2 cycles。不能把它归因成慢 ACK 回程或 bank 写入过程中大量气泡，也不能把整个阶段视作可恢复收益。

最值得继续离线审查的具体结构是 **L2 preservation 的全局 drain、单引擎逐 beat 读/发，以及外层 A multibeat 锁定**。它可阻塞同 set 的 ReleaseData/其他更新，并可影响其他 set 的调度/外层 miss。现存日志没有 checkpoint 状态时长或关键请求关联，长延迟 52-cycle 模式由该机制引起仍为 **UNPROVEN**。

`CACHE_TRANSFER_MAJOR_BOTTLENECK=NOT_PROVEN`；`MAIN_OPT5_CANDIDATE=NONE_JUSTIFIED`；`1P5_FEASIBILITY=SUB1P5_NOT_SUPPORTED`；`NEXT_ACTION=MORE_OFFLINE_ATTRIBUTION`；checker frontend 保持 `LAST_RESORT`。

目标 B ROI 1,648,923 → <1,502,513，用户 gap 146,410；严格整数最少需节省 **146,411**。80,832 只约束既有轨迹中的直接 head-load 等待，**不是全部 cache transfer、checker completion 或非head依赖的全局上界**。

## 阅读入口

- `cache_transfer_path.md`：实际模块/通道/宽度/时钟/协议链。
- request、response、refill、writeback 四份报告：资源与序列化。
- `retry_resource_mapping.md`、`critical_latency_decomposition.md`：原因映射、分布、top episodes 与未知项。
- `candidate_upper_bounds.md`、`opt5_candidate_ranking.md`：有范围的上界、5 个设计审查方向与成本。
- `frontend_last_resort_assessment.md`、`next_run_plan.md`：资源 backpressure 边界、继续离线计划、未来功能实验的诊断设计。
- `numeric_audit.json`、`release_transactions.json/.csv`、`source_evidence.json`、`provenance.json`、`validation_result.json`：机器可复核证据。

所有时间统一为 BOOM/L2 200MHz cycle；simulator time = cycle +103；checker 100MHz，不把其本地周期直接相加。软件 ROI `[698301, 2347224]`，L1 traffic `[698208, 2358291]`，L2 counter 窗口 1,660,084 cycles 比 L1 多一个采样边沿。可证明完整 optional prefix `[698301, 2192911]`；未知后缀 154,313 cycles。以上边界列表均按左闭右开 `[start,stop)` 解释。mandatory release 链完整，可覆盖全运行；optional prefix 不外推。

B correctness/capture 恢复结论保持闭合；原 host FAIL、seal、raw logs、claims 全部保留。旧 A/new B 仅 `REFERENCE_COMPARISON / STRICT_PAIRING_PENDING`；未跑 A′。本轮未修改硬件，未生成 RTL、build 或仿真，未准备新运行命令，未清理文件。

复现（仅 CPU，输出目录必须不存在）：

```bash
python3 -I -B AI/Debug/scripts/analyze_opt5_cache_transfer.py --out AI/TMP/opt5_cache_transfer_attribution_NEW_UNIQUE_TIMESTAMP
python3 -I -B AI/Debug/scripts/test_opt5_cache_transfer.py
```
