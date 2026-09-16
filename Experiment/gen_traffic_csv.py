#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""解析 Experiment/流量分析.typ 的 gapbs 运行日志，生成指标对比 CSV。

输出: Experiment/traffic_metrics.csv
  - 纵轴(行) = 各项指标
  - 横轴(列) = 四种配置 nodes = 512 / 1024 / 2048 / 4096

除原始计数外，派生:
  * 每包平均 store/load 等访存"指令"数量（包 = [VERIFY] packages）
  * 延迟事件发生频率（平均每多少周期/纳秒发生一次）
  * 每次延迟平均耗时（周期 / 纳秒）
"""

import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "流量分析.typ"
OUT = ROOT / "traffic_metrics.csv"

NS_PER_CYCLE = 5.0  # boom / l2 均为 200MHz

CONFIGS = [512, 1024, 2048, 4096]


# --------------------------------------------------------------------------- #
# 解析
# --------------------------------------------------------------------------- #
def pick(body, pat, *groups, cast=float):
    m = re.search(pat, body, flags=re.M)
    if not m:
        raise SystemExit("未匹配: " + pat)
    vals = [m.group(g) for g in groups]
    return cast(vals[0]) if len(vals) == 1 else tuple(cast(v) for v in vals)


def parse(nodes, body):
    d = {"nodes": nodes}

    d["edges"], d["reached"] = pick(body, r"\[RUN\] benchmark=gapbs_bfs nodes=\d+ source=\d+ "
                                          r"reached=(\d+) edges=(\d+)", 2, 1, cast=int)
    d["boom_cycles"], d["boom_inst"] = pick(
        body, r"\[PERF\] boom_cycles=(\d+) boom_inst=(\d+)", 1, 2, cast=int)

    # [TRAFFIC] boom / c1..c4 : store[total/cache/unc]  load[total/cache/unc/fwd]
    (d["store_total"], d["store_cache"], d["store_unc"],
     d["load_total"], d["load_cache"], d["load_unc"], d["load_fwd"]) = pick(
        body, r"\[TRAFFIC\]\s+boom\s+(\d+)/(\d+)/(\d+)\s+(\d+)/(\d+)/(\d+)/(\d+)",
        1, 2, 3, 4, 5, 6, 7, cast=int)

    for c in range(1, 5):
        (d[f"c{c}_store"], d[f"c{c}_store_c"], d[f"c{c}_store_u"],
         d[f"c{c}_load"], d[f"c{c}_load_c"], d[f"c{c}_load_u"], d[f"c{c}_load_f"]) = pick(
            body, rf"\[TRAFFIC\]\s+c{c}\s+(\d+)/(\d+)/(\d+)\s+(\d+)/(\d+)/(\d+)/(\d+)",
            1, 2, 3, 4, 5, 6, 7, cast=int)

    d["checker_store"], d["checker_load"] = pick(
        body, r"\[TRAFFIC\] checker_sum store=(\d+) load=(\d+)", 1, 2, cast=int)

    d["l1_l2_c"], d["wb_dirty_dcache"], d["verify_required"] = pick(
        body, r"\[TRAFFIC\] dcache l1_l2_c=(\d+) wb_dirty=(\d+) verify_required=(\d+)",
        1, 2, 3, cast=int)

    d["l2_wb_total"], d["l2_wb_dirty"] = pick(
        body, r"\[TRAFFIC\] dram l2_wb_total=(\d+) l2_wb_dirty=(\d+)", 1, 2, cast=int)

    (d["dv_req"], d["dv_ver"], d["dv_unver"], d["dv_res"],
     d["dv_pend"], d["dv_other"]) = pick(
        body, r"\[TRAFFIC\] dram_verify required=(\d+) verified=(\d+) unverified=(\d+) "
              r"resolved=(\d+) pending=(\d+) other=(\d+)", 1, 2, 3, 4, 5, 6, cast=int)

    d["dv_wb_cyc"], d["dv_ver_cyc"] = pick(
        body, r"\[TRAFFIC\] dram_verify_cycle_sum writeback=(\d+) verification=(\d+)",
        1, 2, cast=int)

    d["load_cache_resp"], d["load_forward_strict"] = pick(
        body, r"\[TRAFFIC_STRICT\].*load_cache_response=(\d+) load_forward=(\d+)", 1, 2, cast=int)
    d["strict_pending"] = pick(body, r"\[TRAFFIC_STRICT\].*pending=(\d+)", 1, cast=int)

    (d["pkg_alloc"], d["pkg_done"], d["pkg_pass"],
     d["pkg_fail"], d["pkg_cancel"]) = pick(
        body, r"\[VERIFY\] packages allocated=(\d+) completed=(\d+) passed=(\d+) "
              r"failed=(\d+) cancelled=(\d+)", 1, 2, 3, 4, 5, cast=int)

    (d["wb_total"], d["wb_verified"], d["wb_unverified"], d["wb_resolved"],
     d["wb_pend"], d["wb_other"]) = pick(
        body, r"\[VERIFY\] dirty_wb total=(\d+) verified=(\d+) unverified=(\d+) "
              r"resolved=(\d+) pending=(\d+) other=(\d+)", 1, 2, 3, 4, 5, 6, cast=int)

    d["wb_cycle_sum"], d["ver_cycle_sum"] = pick(
        body, r"\[VERIFY\] dirty_wb_cycle_sum writeback_cycle_sum=(\d+) "
              r"verification_cycle_sum=(\d+)", 1, 2, cast=int)

    d["wb_events"], d["wb_avg_cyc"], d["wb_avg_ns"] = pick(
        body, r"\[LATENCY\] dirty_wb events=(\d+) average=([\d.]+)cycles/([\d.]+)ns",
        1, 2, 3)

    d["l2wb_events"], d["l2wb_avg_cyc"], d["l2wb_avg_ns"] = pick(
        body, r"\[LATENCY\] l2_dram_dirty_wb events=(\d+) average=([\d.]+)cycles/([\d.]+)ns",
        1, 2, 3)

    (d["unc_boom_events"], d["unc_checker_events"],
     d["unc_avg_cyc"], d["unc_avg_ns"]) = pick(
        body, r"\[LATENCY\] store_uncache events=boom=(\d+) checker=(\d+) "
              r"average=([\d.]+)cycles/([\d.]+)ns", 1, 2, 3, 4, cast=float)

    d["unc_events"] = int(d["unc_boom_events"])
    return d


# --------------------------------------------------------------------------- #
# 派生指标
# --------------------------------------------------------------------------- #
def derive(d):
    d["ipc"] = d["boom_inst"] / d["boom_cycles"]
    d["cyc_per_node"] = d["boom_cycles"] / d["nodes"]
    d["inst_per_node"] = d["boom_inst"] / d["nodes"]
    d["store_per_node"] = d["store_total"] / d["nodes"]
    d["load_per_node"] = d["load_total"] / d["nodes"]
    d["mem_per_node"] = (d["store_total"] + d["load_total"]) / d["nodes"]
    d["edges_per_node"] = d["edges"] / d["nodes"]

    # ---- 每包平均（包 = [VERIFY] packages allocated）----
    p = d["pkg_alloc"]
    d["store_per_pkg"] = d["store_total"] / p
    d["load_per_pkg"] = d["load_total"] / p
    d["mem_per_pkg"] = (d["store_total"] + d["load_total"]) / p
    d["store_cache_per_pkg"] = d["store_cache"] / p
    d["store_unc_per_pkg"] = d["store_unc"] / p
    d["load_cache_per_pkg"] = d["load_cache"] / p
    d["load_unc_per_pkg"] = d["load_unc"] / p
    d["load_fwd_per_pkg"] = d["load_fwd"] / p
    d["l1l2_per_pkg"] = d["l1_l2_c"] / p
    d["wb_dirty_per_pkg"] = d["wb_dirty_dcache"] / p
    d["verify_req_per_pkg"] = d["verify_required"] / p
    d["cyc_per_pkg"] = d["boom_cycles"] / p
    d["inst_per_pkg"] = d["boom_inst"] / p

    # ---- 比例 ----
    d["store_cache_ratio"] = 100.0 * d["store_cache"] / d["store_total"]
    d["load_cache_ratio"] = 100.0 * d["load_cache"] / d["load_total"]
    d["load_fwd_ratio"] = 100.0 * d["load_fwd"] / d["load_total"]
    d["store_unc_ratio"] = 100.0 * d["store_unc"] / d["store_total"]
    d["load_unc_ratio"] = 100.0 * d["load_unc"] / d["load_total"]
    d["verify_ratio"] = 100.0 * d["verify_required"] / d["wb_dirty_dcache"]
    d["wb_unver_ratio"] = 100.0 * d["wb_unverified"] / d["wb_total"]
    d["dv_unver_ratio"] = 100.0 * d["dv_unver"] / d["dv_req"]
    d["l2_dirty_ratio"] = 100.0 * d["l2_wb_dirty"] / d["l2_wb_total"]

    # ---- 频率 ----
    d["l1l2_per_kcyc"] = d["l1_l2_c"] / (d["boom_cycles"] / 1000.0)
    d["store_per_kcyc"] = d["store_total"] / (d["boom_cycles"] / 1000.0)
    d["load_per_kcyc"] = d["load_total"] / (d["boom_cycles"] / 1000.0)
    d["pkg_per_kcyc"] = d["pkg_alloc"] / (d["boom_cycles"] / 1000.0)
    d["wb_events_per_kcyc"] = d["wb_events"] / (d["boom_cycles"] / 1000.0)
    d["l2wb_events_per_kcyc"] = d["l2wb_events"] / (d["boom_cycles"] / 1000.0)
    d["unc_events_per_kcyc"] = d["unc_events"] / (d["boom_cycles"] / 1000.0)
    d["dv_req_per_kcyc"] = d["dv_req"] / (d["boom_cycles"] / 1000.0)

    # 两次延迟事件之间的平均间隔
    d["wb_interval_cyc"] = d["boom_cycles"] / d["wb_events"]
    d["wb_interval_ns"] = d["wb_interval_cyc"] * NS_PER_CYCLE
    d["l2wb_interval_cyc"] = d["boom_cycles"] / d["l2wb_events"]
    d["l2wb_interval_ns"] = d["l2wb_interval_cyc"] * NS_PER_CYCLE
    d["unc_interval_cyc"] = d["boom_cycles"] / d["unc_events"]
    d["unc_interval_ns"] = d["unc_interval_cyc"] * NS_PER_CYCLE
    d["dv_interval_cyc"] = d["boom_cycles"] / d["dv_req"]
    d["dv_interval_ns"] = d["dv_interval_cyc"] * NS_PER_CYCLE

    # 三种延迟：平均耗时 / 发生间隔（即延迟"占空比"）
    d["wb_avg_over_interval"] = d["wb_avg_cyc"] / d["wb_interval_cyc"]
    d["l2wb_avg_over_interval"] = d["l2wb_avg_cyc"] / d["l2wb_interval_cyc"]
    d["unc_avg_over_interval"] = d["unc_avg_cyc"] / d["unc_interval_cyc"]

    # 平均每次（每个 strobe）的周期开销
    d["wb_cyc_per_strobe"] = d["wb_cycle_sum"] / d["wb_total"]
    d["ver_cyc_per_strobe"] = d["ver_cycle_sum"] / d["wb_total"]
    d["ver_over_wb"] = d["ver_cycle_sum"] / d["wb_cycle_sum"]
    d["dv_wb_cyc_per_req"] = d["dv_wb_cyc"] / d["dv_req"]
    d["dv_ver_cyc_per_req"] = d["dv_ver_cyc"] / d["dv_req"]
    d["dv_ver_over_wb"] = d["dv_ver_cyc"] / d["dv_wb_cyc"]

    # 归一化（每节点 / 每千周期）
    d["l1l2_per_kcyc_per_node"] = d["l1l2_per_kcyc"] / d["nodes"] * 1e3
    return d


# --------------------------------------------------------------------------- #
# 输出行定义: (类别, 指标, 单位, key)
# --------------------------------------------------------------------------- #
ROWS = [
    ("规模", "nodes（图节点数）", "-", "nodes"),
    ("规模", "edges（边数）", "-", "edges"),
    ("规模", "edges/nodes（平均度数）", "-", "edges_per_node"),

    ("性能", "boom_cycles", "cycle", "boom_cycles"),
    ("性能", "boom_inst", "inst", "boom_inst"),
    ("性能", "IPC", "inst/cycle", "ipc"),
    ("性能", "cycles/node", "cycle", "cyc_per_node"),
    ("性能", "inst/node", "inst", "inst_per_node"),
    ("性能", "访存指令/node", "inst", "mem_per_node"),

    ("访存总量", "store 总数（arch）", "条", "store_total"),
    ("访存总量", "store cacheable", "条", "store_cache"),
    ("访存总量", "store uncacheable", "条", "store_unc"),
    ("访存总量", "load 总数（arch）", "条", "load_total"),
    ("访存总量", "load cacheable", "条", "load_cache"),
    ("访存总量", "load uncacheable", "条", "load_unc"),
    ("访存总量", "load forward（旁路命中）", "条", "load_fwd"),
    ("访存总量", "load L2 响应数（strict）", "条", "load_cache_resp"),
    ("访存总量", "checker 统计 store", "条", "checker_store"),
    ("访存总量", "checker 统计 load", "条", "checker_load"),
    ("访存总量", "store/node", "条", "store_per_node"),
    ("访存总量", "load/node", "条", "load_per_node"),

    ("每包平均", "包数（VERIFY packages allocated）", "个", "pkg_alloc"),
    ("每包平均", "store/包", "条/包", "store_per_pkg"),
    ("每包平均", "  ├ cacheable store/包", "条/包", "store_cache_per_pkg"),
    ("每包平均", "  └ uncacheable store/包", "条/包", "store_unc_per_pkg"),
    ("每包平均", "load/包", "条/包", "load_per_pkg"),
    ("每包平均", "  ├ cacheable load/包", "条/包", "load_cache_per_pkg"),
    ("每包平均", "  ├ uncacheable load/包", "条/包", "load_unc_per_pkg"),
    ("每包平均", "  └ load forward/包", "条/包", "load_fwd_per_pkg"),
    ("每包平均", "访存总数/包", "条/包", "mem_per_pkg"),
    ("每包平均", "L1→L2 请求/包", "条/包", "l1l2_per_pkg"),
    ("每包平均", "dcache 脏写回/包", "条/包", "wb_dirty_per_pkg"),
    ("每包平均", "需校验写回/包", "条/包", "verify_req_per_pkg"),
    ("每包平均", "cycles/包", "cycle/包", "cyc_per_pkg"),
    ("每包平均", "inst/包", "inst/包", "inst_per_pkg"),

    ("访存行为", "store cacheable 占比", "%", "store_cache_ratio"),
    ("访存行为", "store uncacheable 占比", "%", "store_unc_ratio"),
    ("访存行为", "load cacheable 占比", "%", "load_cache_ratio"),
    ("访存行为", "load uncacheable 占比", "%", "load_unc_ratio"),
    ("访存行为", "load forward 占比", "%", "load_fwd_ratio"),
    ("访存行为", "store/1000 cycles", "条", "store_per_kcyc"),
    ("访存行为", "load/1000 cycles", "条", "load_per_kcyc"),
    ("访存行为", "包/1000 cycles", "个", "pkg_per_kcyc"),
    ("访存行为", "L1→L2 cache line 请求 l1_l2_c", "条", "l1_l2_c"),
    ("访存行为", "L1→L2 请求/1000 cycles", "条", "l1l2_per_kcyc"),
    ("访存行为", "L1→L2 请求/1000 cycles/节点", "条", "l1l2_per_kcyc_per_node"),

    ("dcache 写回", "dcache wb_dirty", "条", "wb_dirty_dcache"),
    ("dcache 写回", "verify_required（=dirty_wb total）", "条", "verify_required"),
    ("dcache 写回", "verify_required / wb_dirty", "%", "verify_ratio"),
    ("dcache 写回", "写回时已校验 verified", "条", "wb_verified"),
    ("dcache 写回", "写回时未校验 unverified", "条", "wb_unverified"),
    ("dcache 写回", "事后消解 resolved", "条", "wb_resolved"),
    ("dcache 写回", "未校验占比", "%", "wb_unver_ratio"),
    ("dcache 写回", "残留 pending", "条", "wb_pend"),

    ("L2→DRAM", "l2_wb_total", "条", "l2_wb_total"),
    ("L2→DRAM", "l2_wb_dirty", "条", "l2_wb_dirty"),
    ("L2→DRAM", "dirty 占比", "%", "l2_dirty_ratio"),
    ("L2→DRAM", "需校验 required", "条", "dv_req"),
    ("L2→DRAM", "写回时已校验 verified", "条", "dv_ver"),
    ("L2→DRAM", "写回时未校验 unverified", "条", "dv_unver"),
    ("L2→DRAM", "事后消解 resolved", "条", "dv_res"),
    ("L2→DRAM", "非 dirty/其他 other", "条", "dv_other"),
    ("L2→DRAM", "未校验占比", "%", "dv_unver_ratio"),
    ("L2→DRAM", "需校验/1000 cycles", "条", "dv_req_per_kcyc"),

    ("延迟-脏写回", "延迟事件数 events", "次", "wb_events"),
    ("延迟-脏写回", "事件频率", "次/1000 cycles", "wb_events_per_kcyc"),
    ("延迟-脏写回", "平均多久发生一次（间隔）", "cycle", "wb_interval_cyc"),
    ("延迟-脏写回", "平均多久发生一次（间隔）", "ns", "wb_interval_ns"),
    ("延迟-脏写回", "每次延迟平均耗时", "cycle", "wb_avg_cyc"),
    ("延迟-脏写回", "每次延迟平均耗时", "ns", "wb_avg_ns"),
    ("延迟-脏写回", "平均耗时/发生间隔", "x", "wb_avg_over_interval"),
    ("延迟-脏写回", "writeback_cycle_sum", "cycle", "wb_cycle_sum"),
    ("延迟-脏写回", "verification_cycle_sum", "cycle", "ver_cycle_sum"),
    ("延迟-脏写回", "平均每次写回占用", "cycle", "wb_cyc_per_strobe"),
    ("延迟-脏写回", "平均每次校验占用", "cycle", "ver_cyc_per_strobe"),
    ("延迟-脏写回", "校验/写回 周期比", "x", "ver_over_wb"),

    ("延迟-L2→DRAM", "延迟事件数 events", "次", "l2wb_events"),
    ("延迟-L2→DRAM", "事件频率", "次/1000 cycles", "l2wb_events_per_kcyc"),
    ("延迟-L2→DRAM", "平均多久发生一次（间隔）", "cycle", "l2wb_interval_cyc"),
    ("延迟-L2→DRAM", "平均多久发生一次（间隔）", "ns", "l2wb_interval_ns"),
    ("延迟-L2→DRAM", "每次延迟平均耗时", "cycle", "l2wb_avg_cyc"),
    ("延迟-L2→DRAM", "每次延迟平均耗时", "ns", "l2wb_avg_ns"),
    ("延迟-L2→DRAM", "平均耗时/发生间隔", "x", "l2wb_avg_over_interval"),
    ("延迟-L2→DRAM", "dram_verify_cycle_sum writeback", "cycle", "dv_wb_cyc"),
    ("延迟-L2→DRAM", "dram_verify_cycle_sum verification", "cycle", "dv_ver_cyc"),
    ("延迟-L2→DRAM", "平均每个需校验请求的写回周期", "cycle", "dv_wb_cyc_per_req"),
    ("延迟-L2→DRAM", "平均每个需校验请求的校验周期", "cycle", "dv_ver_cyc_per_req"),
    ("延迟-L2→DRAM", "校验/写回 周期比", "x", "dv_ver_over_wb"),
    ("延迟-L2→DRAM", "需校验请求发生间隔", "cycle", "dv_interval_cyc"),
    ("延迟-L2→DRAM", "需校验请求发生间隔", "ns", "dv_interval_ns"),

    ("延迟-uncache store", "延迟事件数 events", "次", "unc_events"),
    ("延迟-uncache store", "事件频率", "次/1000 cycles", "unc_events_per_kcyc"),
    ("延迟-uncache store", "平均多久发生一次（间隔）", "cycle", "unc_interval_cyc"),
    ("延迟-uncache store", "平均多久发生一次（间隔）", "ns", "unc_interval_ns"),
    ("延迟-uncache store", "每次延迟平均耗时", "cycle", "unc_avg_cyc"),
    ("延迟-uncache store", "每次延迟平均耗时", "ns", "unc_avg_ns"),
    ("延迟-uncache store", "平均耗时/发生间隔", "x", "unc_avg_over_interval"),

    ("校验完整性", "packages allocated", "个", "pkg_alloc"),
    ("校验完整性", "packages completed", "个", "pkg_done"),
    ("校验完整性", "packages passed", "个", "pkg_pass"),
    ("校验完整性", "packages failed", "个", "pkg_fail"),
    ("校验完整性", "packages cancelled", "个", "pkg_cancel"),
    ("校验完整性", "traffic strict pending", "条", "strict_pending"),
]


def fmt(v):
    if isinstance(v, int):
        return str(v)
    if isinstance(v, float):
        if abs(v - round(v)) < 1e-9 and abs(v) < 1e15:
            return str(int(round(v)))
        digits = 6 if 0 < abs(v) < 0.01 else 3
        s = f"{v:.{digits}f}"
        return s.rstrip("0").rstrip(".")
    return str(v)


def main():
    text = SRC.read_text(encoding="utf-8")
    parts = re.split(r"^-\s*(\d+)\s*$", text, flags=re.M)
    blocks = {int(parts[i]): parts[i + 1] for i in range(1, len(parts) - 1, 2)}

    data = {c: derive(parse(c, blocks[c])) for c in CONFIGS}

    with OUT.open("w", encoding="utf-8-sig", newline="") as fp:
        w = csv.writer(fp)
        w.writerow(["类别", "指标", "单位"] + [f"nodes={c}" for c in CONFIGS])
        for cat, name, unit, key in ROWS:
            w.writerow([cat, name, unit] + [fmt(data[c][key]) for c in CONFIGS])

    print(f"已写出: {OUT}  ({len(ROWS)} 行指标 × {len(CONFIGS)} 配置)")


if __name__ == "__main__":
    main()
