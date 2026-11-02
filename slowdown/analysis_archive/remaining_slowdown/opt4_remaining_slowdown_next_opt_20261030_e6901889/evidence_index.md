# Evidence index 与复现入口

## 不可变原始证据

Run根：`/data1/gzh/EC/slowdown/optimization_4_svb/runs/optimization_4_svb_20261030_072604_18475a92`；原始文件hash/size见[provenance.json](provenance.json)，最终复核见[source_scope_audit.json](source_scope_audit.json)。

|证据|用途|
|---|---|
|run_manifest.json|唯一run身份；roi_validation_status=VALIDATED_OPT4_ROI；result=ROI_VALIDATED_CACHE_SHADOW_FAILED|
|roi.json / stdout.log / stderr.log|ROI窗口、verified1、checksum43439728、simulation退出与assertion|
|safe_chain_events.tsv|SC生命周期、完整强制计数、optional状态前缀与footer|
|cache_opportunity.jsonl|实际L1/L2与四种shadow原始aggregate、MSHR histogram和流量|
|capture_summary.json|optional omitted3099、8MiB reservation、ring丢弃、mandatory coverage|
|analysis/integrity_ledger.json|完整406 allocations、391promotion+12coalesced+3discarded|
|analysis/summary.json|旧cache-fidelity与functional门控混淆；保留原样，不作为新判定结果|

Baseline1,001,675与Opt3 2,928,347沿用用户已验证基线及既有analyzer常量；没有借用旧stall比例。
本次仅用指定Opt4 run的活动重新分析，没有混入前一个044205 run的失败observer数据。
当前新Scala源与该run旧generated RTL分开：旧生成物位于
`slowdown/optimization_4_svb/build/optimization_4_svb_20261030_072604_18475a92/generated/gen-collateral/`，
没有重新生成或修改。

## 新分析与验证

- [closure_analysis/metrics.json](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/closure_analysis/metrics.json)：最终compact指标与决策。
- [closure_analysis/corrected_summary.json](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/closure_analysis/corrected_summary.json)：独立修正summary，functional PASS/L1 PASS/L2 FAIL。
- [closure_analysis/reconstructed_intervals.json](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/closure_analysis/reconstructed_intervals.json)：可审计半开区间、source TSV行号。
- [observer_schema.json](observer_schema.json)：kind40–45的字段、优先分区、窗口和预算。
- [offline_test_closure_results.json](offline_test_closure_results.json)：4套58 tests及日志。
- [scala_typer_command.json](scala_typer_command.json)、[scala_typer_final.log](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/scala_typer_final.log)、[scala_typer_final_exit.json](scala_typer_final_exit.json)：确切typer-only argv/exit。
- [source_scope_audit.py](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/source_scope_audit.py) / [source_scope_audit.json](source_scope_audit.json)：7个硬件文件逆变换，原始输入hash复核。
- [incremental_changes.patch](../../../../AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/incremental_changes.patch)、[source_hashes.json](source_hashes.json)、[source_anchors.json](source_anchors.json)、[validation_result.json](validation_result.json)：最终源码边界与收尾结果。
- `preimage/`：9个原有编辑源及state更新前像；旧analysis/、final_analysis/、verified_analysis/保留作中间产物，最终以closure_analysis为准。

## 允许的离线复现

从仓库根执行，只输出到一个全新的AI/TMP目录：

```bash
python3 -B AI/Debug/scripts/analyze_opt4_remaining.py --out AI/TMP/opt4_remaining_replay_<new_unique_suffix>
python3 -B AI/Debug/scripts/test_opt4_remaining.py
python3 -B AI/TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/source_scope_audit.py
```

analyzer拒绝覆盖已有输出。不要对缺optional suffix的run运行旧compact_causality.py并外推最后状态。
不提供本轮禁止的硬件generation/build/simulation命令。
