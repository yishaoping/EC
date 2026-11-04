from __future__ import annotations
import csv
from collections import Counter, defaultdict
import math
from pathlib import Path
import statistics
from .common import atomic_json, read_json, require, digest
from .ledger import status
from .measurement import quantile_interval

def write_csv(path, rows, columns):
    with open(path, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=columns, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)

def summarize(campaigns, output, area_results=None, plots=True):
    output = Path(output)
    output.mkdir(parents=True, exist_ok=False) # each report is a new preserved artifact
    expected, completed, progress, issues, blockers = {}, {}, [], [], []
    for path in map(Path, campaigns):
        manifest = read_json(path / "manifest.json")
        blockers.extend(manifest.get("blockers", []))
        states, damaged = status(path)
        issues.extend({"campaign":str(path),**x} for x in damaged)
        for row in states:
            sample = row["sample"]
            sid = sample["sample_id"]
            if sid in expected:
                require(expected[sid] == sample, "sample identity collision")
            expected[sid] = sample
            progress.append({"campaign":str(path),"sample_id":sid,"configuration":sample["configuration"]["id"],
                             "benchmark":sample["case"]["benchmark"],"repetition":sample["repetition"],
                             "state":row["state"],"errors":"; ".join(row["errors"])})
            if row["state"] == "complete":
                r = read_json(path / "results" / (sid + ".json"))
                if sid in completed:
                    require(completed[sid]["metrics_digest"] == r["metrics_digest"], "conflicting completed duplicate sample")
                completed[sid] = r
    # Match the exact workload, source identity and full artifact/site mapping.
    def grouping(sample):
        return sample["comparison_key"], sample["source_id"], sample["site_id"], sample.get("kit_id")
    cases = defaultdict(lambda:defaultdict(list))
    for sid, s in expected.items():
        cases[grouping(s)][s["configuration"]["id"]].append(sid)
    aggregate, details, ratios, sets = [], [], [], []
    all_ratio_data = defaultdict(dict)
    for group, by_config in cases.items():
        valid = {}
        for cid, sample_ids in by_config.items():
            first = expected[sample_ids[0]]
            # Partial samples remain in progress but never become full measurement rows.
            if not all(sid in completed for sid in sample_ids):
                continue
            ms = [completed[sid]["metrics"] for sid in sample_ids]
            cycles = [m["roi_cycles"] for m in ms]
            hist = Counter()
            for m in ms:
                for b in m["histogram"]:
                    hist[(b["lo"],b["hi"])] += b["count"]
            bins = [{"lo":a,"hi":b,"count":n} for (a,b),n in sorted(hist.items())]
            n = sum(m["latency_count"] for m in ms)
            row = {"case_id":digest(group),"benchmark":first["case"]["benchmark"],"configuration":cid,
                   "rockets":first["configuration"]["rockets"],"mode":first["configuration"]["mode"],
                   "repeats":len(ms),"roi_cycles_mean":statistics.mean(cycles),
                   "target_manifest_sha256":first["artifacts"].get("rtl_manifest",{}).get("sha256"),
                   "roi_cycles_stdev":statistics.stdev(cycles) if len(cycles)>1 else None,
                   "coefficient_of_variation":statistics.stdev(cycles)/statistics.mean(cycles) if len(cycles)>1 else None,
                   "latency_count":n,"latency_mean":sum(m["latency_sum"] for m in ms)/n if n else None,
                   "latency_max":max(m["latency_max"] for m in ms) if n else None,
                   "drain_cycles_mean":statistics.mean(m["drain_cycles"] for m in ms),
                   "queue_mean":statistics.mean(m["queue_occupancy_tick_sum"]/m["roi_cycles"] for m in ms),
                   "queue_max":max(m["queue_max"] for m in ms),
                   "queue_full_fraction":statistics.mean(m["queue_full_ticks"]/m["roi_cycles"] for m in ms),
                   "boom_blocked_fraction":statistics.mean(m["boom_protection_blocked_ticks"]/m["roi_cycles"] for m in ms)}
            for label, q in [("median",0.5),("p95",0.95),("p99",0.99)]:
                interval = quantile_interval(bins, q)
                row[label+"_lo"],row[label+"_hi"] = interval if interval else (None,None)
            row["variation_warning"] = bool(row["coefficient_of_variation"] is not None and row["coefficient_of_variation"] > .02)
            aggregate.append(row)
            valid[cid] = row
            details.append({"case_id":row["case_id"],"benchmark":row["benchmark"],"configuration":cid,"histogram":bins,
                            "blocking_reasons_exclusive":all(m.get("blocking_reasons_exclusive") is True for m in ms),
                            "blocking_reasons_per_sample":[m["blocking_reasons"] for m in ms],
                            "busy_roi_fraction_per_sample":[[t/m["roi_cycles"] for t in m["busy_roi_ticks"]] for m in ms],
                            "busy_drain_fraction_per_sample":[[t/m["drain_cycles"] if m["drain_cycles"] else 0
                                                               for t in m["busy_drain_ticks"]] for m in ms]})
        sets.append({"case_id":digest(group),"planned_configurations":sorted(by_config),"valid_configurations":sorted(valid),
                     "missing_or_invalid_configurations":sorted(set(by_config)-set(valid))})
        if "B" not in valid:
            continue
        b = valid["B"]["roi_cycles_mean"]
        for cid, r in valid.items():
            d_id = "D" + str(r["rockets"])
            ratio = {"case_id":r["case_id"],"benchmark":r["benchmark"],"configuration":cid,
                     "slowdown":r["roi_cycles_mean"]/b,"overhead_percent":100*(r["roi_cycles_mean"]/b-1),
                     "increment_vs_detection":r["roi_cycles_mean"]/valid[d_id]["roi_cycles_mean"] if cid.startswith("C") and d_id in valid else None,
                     "increment_vs_C4":r["roi_cycles_mean"]/valid["C4"]["roi_cycles_mean"] if r["mode"]=="diagnostic" and "C4" in valid else None}
            ratios.append(ratio)
            all_ratio_data[r["case_id"]][cid] = ratio["slowdown"]
    groups = {"default":["B","D4","C4"],"count_scan":["B","D2","C2","D4","C4","D8","C8"],
              "ablation":["B","D4","C4","C4-no-real-barrier"]}
    geometric = []
    for label, configs in groups.items():
        common = sorted(k for k, v in all_ratio_data.items() if all(c in v for c in configs))
        for cid in configs:
            vals = [all_ratio_data[k][cid] for k in common]
            geometric.append({"comparison":label,"configuration":cid,"geomean_slowdown":math.exp(statistics.mean(map(math.log,vals))) if vals else None,
                              "benchmark_cases":len(common),"common_case_ids":common,
                              "excluded_case_ids":sorted(set(all_ratio_data)-set(common))})
    summary = {"schema":"ec-dac/1","expected_samples":len(expected),"valid_complete_samples":len(completed),
               "completion_rate":len(completed)/len(expected) if expected else None,
               "states_including_duplicate_campaigns":dict(Counter(p["state"] for p in progress)),
               "geometric_means":geometric,"comparison_sets":sets,"journal_issues":issues,
               "preparation_blockers":sorted(set(blockers)),
               "warning":"Only common benchmark sets enter each geometric mean. Missing/incomplete samples never enter numeric results. CV >2% is a diagnostic flag, not an acceptance rule."}
    atomic_json(output / "summary.json", summary)
    atomic_json(output / "latency-utilization-blocking.json", details)
    write_csv(output / "progress.csv",progress,["campaign","sample_id","configuration","benchmark","repetition","state","errors"])
    missing = [p for p in progress if p["state"] != "complete"]
    write_csv(output / "missing-failed.csv",missing,["campaign","sample_id","configuration","benchmark","repetition","state","errors"])
    write_csv(output / "measurements.csv",aggregate,list(aggregate[0]) if aggregate else ["case_id","benchmark","configuration","roi_cycles_mean","latency_mean","p95_lo","p95_hi","p99_lo","p99_hi","drain_cycles_mean"])
    write_csv(output / "slowdown.csv",ratios,["case_id","benchmark","configuration","slowdown","overhead_percent","increment_vs_detection","increment_vs_C4"])
    plot_errors = []
    if plots and aggregate:
        try:
            plot_results(output, aggregate, ratios, details, geometric)
        except ImportError as e:
            plot_errors.append(str(e))
    area = []
    if area_results:
        from .area import area_analysis
        area = area_analysis(area_results, output, aggregate, ratios, plots)
    report = ["# DAC 实验汇总", "",f"有效完成 {len(completed)} / {len(expected)} 个计划样本。", "",
              "仅完整 ROI、完整排空、无异常/溢出/丢包、输出校验成功的样本进入统计。",
              "分位数以 [lo, hi] 区间报告；0–255 周期精确，之后每 octave 16 桶（最大桶宽约 6.25%）。",
              "BOOM ROI 周期用于 slowdown；ROI 到全部校验及释放完成的 drain 单独报告。",
              "阻塞原因默认允许重叠，因此不绘制可加总堆叠图。", "",
              "## 缺项与限制", *["- " + b for b in sorted(set(blockers))],
              *["- 绘图依赖缺失："+e for e in plot_errors],
              "- 尚无有效综合结果。" if not area else "- 面积只比较相同工艺、约束和存储器策略。"]
    (output / "report.md").write_text("\n".join(report)+"\n")
    return {"report":str(output),**summary}

def plot_results(output, rows, ratios, details, geometric):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    by_case = defaultdict(list)
    for r in rows:
        by_case[r["case_id"]].append(r)
    for case, data in by_case.items():
        label = data[0]["benchmark"] + "-" + case[:8]
        fig, ax = plt.subplots(figsize=(8,4))
        selected = [r for r in ratios if r["case_id"] == case]
        ax.bar([r["configuration"] for r in selected],[r["slowdown"] for r in selected])
        ax.set(ylabel="ROI target cycles / B", title=label)
        fig.tight_layout(); fig.savefig(output / (label+"-slowdown.png")); plt.close(fig)
        fig, axes = plt.subplots(1,2,figsize=(10,4))
        for mode in ("D","C"):
            pts = sorted((r["rockets"],next((s["slowdown"] for s in selected if s["configuration"]==r["configuration"]),None))
                         for r in data if r["configuration"] in [mode+str(n) for n in (2,4,8)])
            pts = [(x,y) for x,y in pts if y is not None]
            if pts:
                axes[0].plot(*zip(*pts),marker="o",label=mode)
        axes[0].set(xlabel="Rocket count",ylabel="Slowdown",xticks=[2,4,8]); axes[0].legend()
        for d in details:
            if d["case_id"] != case or not d["histogram"]:
                continue
            hs, acc, total, xs, ys = d["histogram"],0,sum(b["count"] for b in d["histogram"]),[],[]
            for b in hs:
                acc += b["count"]; xs.append(b["hi"]); ys.append(acc/total)
            axes[1].step(xs,ys,where="post",label=d["configuration"])
        axes[1].set(xlabel="Validation latency, upper bucket bound (BOOM cycles)",ylabel="CDF"); axes[1].legend()
        fig.tight_layout(); fig.savefig(output / (label+"-count-latency.png")); plt.close(fig)
        fig, axes = plt.subplots(1,3,figsize=(13,4))
        labels = [r["configuration"] for r in data]
        axes[0].bar(labels,[r["drain_cycles_mean"] for r in data]); axes[0].set_ylabel("Drain target cycles")
        axes[1].bar(labels,[r["boom_blocked_fraction"] for r in data]); axes[1].set_ylabel("BOOM blocked / ROI")
        axes[2].bar(labels,[r["queue_full_fraction"] for r in data]); axes[2].set_ylabel("Queue full / ROI")
        for ax in axes: ax.tick_params(axis="x",rotation=70)
        fig.tight_layout(); fig.savefig(output / (label+"-drain-pressure.png")); plt.close(fig)
        fig,axes=plt.subplots(1,2,figsize=(12,4))
        for d in details:
            if d["case_id"]!=case:continue
            if d["busy_roi_fraction_per_sample"] and d["busy_roi_fraction_per_sample"][0]:
                n=len(d["busy_roi_fraction_per_sample"][0])
                means=[statistics.mean(v[i] for v in d["busy_roi_fraction_per_sample"]) for i in range(n)]
                axes[0].plot(range(1,n+1),means,marker="o",label=d["configuration"])
            for reason in sorted({k for v in d["blocking_reasons_per_sample"] for k in v}):
                value=statistics.mean(v.get(reason,0) for v in d["blocking_reasons_per_sample"])
                axes[1].bar(d["configuration"]+":"+reason,value)
        axes[0].set(xlabel="Checker hart index",ylabel="Busy ticks / ROI ticks");axes[0].legend()
        axes[1].set_ylabel("Reason ticks (may overlap)");axes[1].tick_params(axis="x",rotation=90)
        fig.tight_layout();fig.savefig(output/(label+"-utilization-reasons.png"));plt.close(fig)
