# 离线因果分析

工具本身不启动硬件、构建或 workload。先完成用户的一键实验，再选择完整波形
或有上下文的 tick 窗口提取。以真实 run_id 替换下列占位符：

```bash
python3 -I -B /data1/gzh/EC/slowdown/analysis/extract_trace.py \
  --run /data1/gzh/EC/slowdown/runs/<run_id> \
  --out /data1/gzh/EC/slowdown/analysis/results/<new_extraction_id>
python3 -I -B /data1/gzh/EC/slowdown/analysis/analyze_trace.py \
  /data1/gzh/EC/slowdown/analysis/results/<new_extraction_id>/trace.tsv \
  --roi /data1/gzh/EC/slowdown/runs/<run_id>/roi.json \
  --out /data1/gzh/EC/slowdown/analysis/results/<new_analysis_id>
```

输出目录必须尚不存在。提取器使用本次 run 已构建且 SHA 已验证的 reader，
复制 FST 到新目录，原目录挂载只读；所有 sidecar、C tmpfile、mmap 临时文件
都限于新输出目录。可用 `--start <tick> --end <tick>` 缩小范围。需要磁盘空间
容纳私有 FST 副本及文本 transition，不能对旧波形直接裸跑 native reader。
隔离参数与启动器共用 `scripts/sandbox_support.py`；复用现有只读 `/proc`，
避免本机 `bwrap --proc` 的挂载权限错误，同时保留独立网络和私有临时目录。

`DIRECT_EVIDENCE`：reader 的 TSV 包含 `META`（原始范围与 timescale exponent）、
`WINDOW`（本次选区）、`H`（handle/width/层级）、`V`（tick/handle/binary）。
分析器按 tick 合并所有变化，在 `slowdown_core_clock` 上升沿之前采样上一
稳定状态，避免将更新后的 ready 与更新前 valid 配对。不用 FST timescale 猜
BOOM 周期；输出实际采样 edge 数及观测到的每周期 ticks 分布。

ROI 用同一 run 的 `roi.json` 配合 `slowdown_csr_cycle`，范围为
`[start_cycle,stop_cycle)`；必须核对采样覆盖度是否等于 ROI cycles，reset、
clock gating、CSR 写入或选区裁剪都要单独复核。未知值不能当 0。一个以上的 LSU
或 ROB scope 时要求显式 `--lsu-scope` / `--rob-scope`，不猜选哪个核心。

`summary.json` 分别给出 pending/freeze 活动、真实 `valid&&!ready`、各 lane
same-set/different-tag 阻塞、不同 set 的 collateral 阻塞、exclusive freeze
入口条件、ROB gate、can/will_commit、直接 GC gate 丢失的提交机会，以及与
MSHR admission、Scheduler、TileLink、barrier/preservation 的交集和目标并集。
`intervals.jsonl` 保留半开 sample 区间、tick、CSR cycle、请求身份及首尾的
pending/ROB context；`accepted_requests.jsonl` 保留 lane fire，供 blocked→fire
事务对应。event count 是身份连续的观察区间；unique request keys 不是跨 wrap
的架构唯一 ID。截断区间的 wait distribution 也只是观察片段。

`STATIC_INFERENCE`：`freeze_only_admission_condition` 要求有效请求被挡、
freeze conflict 为真、killed replay 为假且 pipeline ready 为真，直接对应
`dcache.scala:671-686` 的 ready predicate。若多个条件同时为真，另记
`freeze_sufficient_block`，不能把它们当互斥根因。

`UNRESOLVED`：same-set/different-line 需要同 lane 地址/set/tag；packed UInt
Vec 若没有可证元素宽度，不作猜测。冻结解除之后的请求可能换 lane、被杀或重试，
必须用 PC/ROB/token/packet 和请求生命周期人工闭合；仅看到后续 fire 或 ROB
commit 恢复不证明因果。`confirmed_direct_gc_commit_opportunity` 只证明直接 GC
门控条件，不证明是 freeze 引起该 gate，也不等于可避免损失。MSHR 活动不能当
full；缺少 full/反事实与安全收窄方案时，MSHR full、freeze→ROB 的已确认子集
和可避免 cycles 均保留 UNRESOLVED。不会将活动、请求等待和 ROB 重叠直接相加。

已有 S2 nack、safe watermark、writeback/meta-clear、store completion 等 debug
字段由 reader 的精确白名单同时选出，可按对应 TSV 和源码深入复核；分析器只自动
计算可明确表达的谓词。输出不估算某个机制的净整机 slowdown。
