from __future__ import annotations
import os
from pathlib import Path
import re
import shutil
import subprocess
from .common import KIT, ROOT, read_json, atomic_json, require, filehash, digest

def prepare_area(config_id, output, execute=False):
    config = read_json(KIT / "config/area.json")
    require(config_id in config["configurations"], "missing pre-FireSim target RTL recipe: " + config_id)
    recipe = config["configurations"][config_id]
    require(recipe.get("pre_firesim_target_only") is True, "area input is not confirmed target-only RTL")
    require(recipe.get("observation_logic_excluded") is True, "observation logic has not been excluded")
    require(config["memory_policy"] in ("mapped-macros", "synthesized-flops"), "memory policy must be explicit")
    require(bool(config["target_libraries"]) and bool(config["clocks"]), "missing ASIC libraries/clock constraints")
    require(bool(config.get("area_unit")), "library area units unknown; supply area_unit from the library")
    require(bool(config.get("constraint_file")) and Path(config["constraint_file"]).is_file(), "missing reviewed multi-clock SDC")
    require(recipe.get("target_manifest_path") and Path(recipe["target_manifest_path"]).is_file(), "missing target RTL manifest shared with performance builds")
    require(1 <= config["max_cores"] <= 4, "synthesis concurrency must be <=4")
    files = recipe["rtl_files"]
    require(files and all(Path(p).is_file() for p in files), "missing target RTL files")
    require(all(Path(p).is_file() for p in config["target_libraries"]+config["link_libraries"]), "missing .db libraries")
    require(all("\n" not in str(p) for p in files+config["target_libraries"]+config["link_libraries"]), "newline in paths")
    require(re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*",recipe["top"]) is not None, "invalid top module")
    for c in config["clocks"]:
        require(re.fullmatch(r"[A-Za-z_][A-Za-z0-9_/]*", c["port"]) is not None and c["period_ns"]>0, "invalid clock")
    out = Path(output).resolve()
    require(not out.exists(), "area output exists; choose a new directory")
    # Tool, library and timing recipe are recorded separately from the RTL identity.
    common = {k:v for k,v in config.items() if k not in ("configurations", "notes")}
    common["constraint_sha256"] = filehash(config["constraint_file"])
    manifest = {"configuration":config_id,"common":common,"common_id":digest(common),"recipe":recipe,
                "rtl_hashes":{p:filehash(p) for p in files},
                "library_hashes":{p:filehash(p) for p in config["target_libraries"]+config["link_libraries"]},
                "target_manifest_sha256":filehash(recipe["target_manifest_path"]),
                "stage":"prepared","not_an_fpga_area_report":True}
    out.mkdir(parents=True)
    atomic_json(out / "manifest.json", manifest)
    env = os.environ.copy()
    env.update({"DAC_AREA_OUT":str(out),"DAC_TOP":recipe["top"],
                "DAC_RTL_FILES":"\n".join(files),"DAC_TARGET_LIBS":"\n".join(config["target_libraries"]),
                "DAC_LINK_LIBS":"\n".join(config["link_libraries"]),"DAC_MAX_CORES":str(config["max_cores"]),
                "DAC_IO_DELAY":str(config["io_delay_ns"]),"DAC_CLOCK_UNCERTAINTY":str(config["clock_uncertainty_ns"]),
                "DAC_CLOCKS":"\n".join(f'{c["port"]} {c["period_ns"]}' for c in config["clocks"]),
                "DAC_SDC":str(Path(config["constraint_file"]).resolve())})
    argv = [config["dc_shell"], "-no_init", "-no_home_init", "-no_local_init", "-f", str(KIT / "area/synth.tcl")]
    if execute:
        require(Path(config["dc_shell"]).is_file(), "dc_shell missing/inaccessible; license not tested")
        require(shutil.disk_usage(ROOT).free > 80*2**30, "need >=80 GiB free disk")
        with open(out / "dc.log", "xb") as log:
            result = subprocess.run(["nice", "-n", "10"]+argv, cwd=out, env=env, stdout=log, stderr=subprocess.STDOUT)
        require(result.returncode == 0 and (out / "SUCCESS").exists(), "synthesis failed; inspect dc.log")
        manifest["stage"] = "synthesized"
        atomic_json(out / "manifest.json", manifest)
    return {"output":str(out),"argv":argv,"executed":execute}

def import_area(directory):
    directory = Path(directory).resolve()
    m = read_json(directory / "manifest.json")
    require(m["stage"] == "synthesized" and (directory / "SUCCESS").exists(), "no successful mapped ASIC synthesis")
    review=read_json(directory / "review.json")
    for key in ("mapped_memory_policy_verified","no_unresolved_references","all_required_clocks_constrained",
                "no_unconstrained_required_paths","target_only_no_observer","timing_reports_reviewed"):
        require(review.get(key) is True, "ASIC report review missing: " + key)
    require(review.get("manifest_sha256")==filehash(directory/"manifest.json"),"ASIC review refers to a different synthesis manifest")
    reports=("area.rpt","timing.rpt","hierarchy.rpt","references.rpt","constraints.rpt","check_timing.rpt","clocks.rpt","check.rpt")
    for name in reports:
        require(review.get("report_hashes",{}).get(name)==filehash(directory/name),"ASIC reviewed report changed: "+name)
    report = (directory / "area.rpt").read_text()
    timing = (directory / "timing.rpt").read_text()
    a = re.search(r"Total cell area:\s*([\d.eE+-]+)",report)
    slacks = re.findall(r"slack\s*(?:\(\w+\))?\s+([-+\d.eE]+)",timing)
    require(a and slacks, "area/slack not found; do not substitute FPGA LUT counts")
    result = {"configuration":m["configuration"],"common_id":m["common_id"],"common":m["common"],
              "area":float(a.group(1)),"area_unit":m["common"]["area_unit"],
              "worst_reported_slack_ns":min(map(float,slacks)),
              "reports":{str(directory/n):filehash(directory/n) for n in reports+("review.json",)},
              "library_hashes":m["library_hashes"],"rtl_hashes":m["rtl_hashes"],"valid":True}
    result["target_manifest_sha256"]=m["target_manifest_sha256"]
    atomic_json(directory / "result.json",result)
    return result

def area_analysis(paths, output, measurements, ratios, plots):
    from .analysis import write_csv
    data = [read_json(p) for p in paths]
    groups = {}
    for r in data:
        require(r.get("valid") is True and r["area"]>0, "invalid ASIC result")
        for p, sha in r["reports"].items():
            require(filehash(p) == sha, "area source report changed")
        for p, sha in {**r["library_hashes"],**r["rtl_hashes"]}.items():
            require(filehash(p)==sha, "area library/RTL changed")
        group = digest([r["common_id"],r["library_hashes"]])
        require(r["configuration"] not in groups.setdefault(group, {}), "duplicate area configuration")
        groups[group][r["configuration"]] = r
    rows=[]
    for group, by_config in groups.items():
        for cid,r in by_config.items():
            b=by_config.get("B")
            rows.append({**r,"area_over_B":r["area"]/b["area"] if b else None,
                         "group_id":group})
    atomic_json(output / "area-comparison.json",rows)
    write_csv(output / "area-timing.csv",rows,["group_id","configuration","area","area_unit","area_over_B","worst_reported_slack_ns"])
    tradeoffs=[]
    unmatched=[]
    for r in rows:
        candidates=[m for m in measurements if m["configuration"]==r["configuration"]]
        for m in candidates:
            if m.get("target_manifest_sha256") != r.get("target_manifest_sha256"):
                unmatched.append({"configuration":r["configuration"],"case_id":m["case_id"],"reason":"ASIC/performance target RTL manifest mismatch"})
                continue
            slowdown=next((s["slowdown"] for s in ratios if s["case_id"]==m["case_id"] and s["configuration"]==m["configuration"]),None)
            if slowdown is not None and r["area_over_B"] is not None:
                tradeoffs.append({"configuration":r["configuration"],"benchmark":m["benchmark"],"case_id":m["case_id"],
                                  "area_over_B":r["area_over_B"],"slowdown":slowdown,"p99_hi":m["p99_hi"],"group_id":r["group_id"]})
    atomic_json(output / "area-performance-latency.json",{"points":tradeoffs,"unmatched":unmatched})
    # Join performance to ASIC RTL only with an explicit matching target manifest hash.
    # The two workflows do not necessarily build from the same RTL artifact automatically.
    if plots:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
        for group, data in groups.items():
            fig, axes=plt.subplots(1,2,figsize=(10,4))
            ordered=sorted(data.values(),key=lambda x:x["configuration"])
            axes[0].bar([r["configuration"] for r in ordered],[r["area"] for r in ordered])
            axes[0].set_ylabel(ordered[0]["area_unit"])
            axes[1].bar([r["configuration"] for r in ordered],[r["worst_reported_slack_ns"] for r in ordered])
            axes[1].set_ylabel("Worst reported slack (ns)")
            fig.tight_layout();fig.savefig(output/("area-timing-"+group[:8]+".png"));plt.close(fig)
        for group in groups:
            pts=[r for r in tradeoffs if r["group_id"]==group and r["p99_hi"] is not None]
            if pts:
                fig,ax=plt.subplots(figsize=(7,5))
                sc=ax.scatter([r["area_over_B"] for r in pts],[r["slowdown"] for r in pts],c=[r["p99_hi"] for r in pts],cmap="viridis")
                for r in pts:ax.annotate(r["configuration"]+":"+r["benchmark"],(r["area_over_B"],r["slowdown"]),fontsize=7)
                ax.set(xlabel="Mapped ASIC area / B",ylabel="ROI slowdown")
                fig.colorbar(sc,ax=ax,label="P99 latency upper bucket bound (BOOM cycles)")
                fig.tight_layout();fig.savefig(output/("area-performance-latency-"+group[:8]+".png"));plt.close(fig)
    return rows
