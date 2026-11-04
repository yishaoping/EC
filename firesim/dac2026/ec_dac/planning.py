from __future__ import annotations
import shlex
from pathlib import Path
from . import SCHEMA, DEFINITION
from .audit import source_identity
from .common import KIT, DATA, ROOT, read_json, atomic_json, digest, filehash, require, name, kit_identity
from .comparison import admit_sample

def make_manifest(campaign, stage, repetitions=1, config_filter=None, bench_filter=None, repeat_filter=None):
    cfg = read_json(KIT / "config/experiment.json")
    benches = read_json(KIT / "config/benchmarks.json")["benchmarks"]
    require(1 <= repetitions <= 100, "repetitions must be between 1 and 100")
    source = source_identity()
    kit=kit_identity()
    site = read_json(KIT / "config/site.json")
    ids = cfg["stages"][stage] if stage != "all" else [c["id"] for c in cfg["configurations"]]
    require(not config_filter or set(config_filter)<=set(ids),"selected configuration is outside this stage")
    require(not bench_filter or set(bench_filter)<={b["name"] for b in benches},"unknown/unadmitted benchmark filter")
    require(not repeat_filter or all(1<=v<=repetitions for v in repeat_filter),"repeat filter outside planned range")
    samples, blockers = [], []
    if not benches:
        blockers.append("No admitted benchmark: audit copied PARSEC, ROI linkage and output validators first")
    for c in cfg["configurations"]:
        if c["id"] not in ids or (config_filter and c["id"] not in config_filter):
            continue
        readiness_key="structural_ready" if stage=="link" else "ready"
        if not c.get(readiness_key):
            blockers.append(c["id"] + ": configuration not validated")
        artifacts = site["per_config_artifacts"].get(c["id"], {})
        for bench in benches:
            bench_stages=bench.get("stages",["link","recovery","main","scan","ablation"])
            if stage=="all" and not set(bench_stages)&{"main","scan","ablation"}:
                continue
            if stage!="all" and stage not in bench_stages:
                continue
            if bench_filter and bench["name"] not in bench_filter:
                continue
            require(bench["threads"] == cfg["common"]["app_threads"], "application thread mismatch")
            require(bench["input_name"] == cfg["common"]["input"], "input-set mismatch")
            require(bench.get("roi_hooks_verified") is True, "unverified hooks: " + bench["name"])
            require(bool(bench.get("guest_verify_argv")) and bool(bench.get("validator")), "missing output validator")
            paths = [bench["binary"], bench["validator"]] + bench["inputs"]
            hashes = {p:filehash(p) for p in paths}
            case = {"benchmark":bench["name"],"input":bench["input_name"],"threads":bench["threads"],
                    "argv":bench["guest_argv"],"cwd":bench["guest_cwd"],
                    "verify_argv":bench["guest_verify_argv"],"files":hashes,"common":cfg["common"]}
            for repeat in range(1, repetitions + 1):
                if repeat_filter and repeat not in repeat_filter:
                    continue
                identity = {"schema":SCHEMA,"definition":DEFINITION,"experiment_id":cfg["experiment_id"],
                            "configuration":c,"case":case,"comparison_key":digest(case),
                            "repetition":repeat,"source_id":source["id"],"artifacts":artifacts,
                            "site_id":digest(site),"kit_id":kit["id"]}
                proof = admit_sample(site, identity)
                if proof is not None:
                    identity["comparison"] = proof
                elif stage != "link":
                    blockers.append("Missing reviewed common comparison context/admission; public B reuse is not admitted")
                samples.append({**identity,"sample_id":digest(identity)[:24]})
    if not samples:
        blockers.append("No admitted samples selected for this stage; no execution plan is runnable")
    manifest = {"schema":SCHEMA,"campaign":name(campaign),"stage":stage,"source":source,
                "site_id":digest(site),"kit":kit,"samples":samples,"blockers":sorted(set(blockers)),
                "execution_allowed":False}
    out = DATA / "campaigns" / name(campaign)
    manifest_path = out / "manifest.json"
    if manifest_path.exists():
        existing = read_json(manifest_path)
        require(existing == manifest, "campaign is immutable; choose a new campaign id after changing inputs/config/code")
    else:
        atomic_json(manifest_path, manifest, replace=False)
    jobs = {}
    for s in samples:
        jobs.setdefault(s["configuration"]["id"], []).append(s)
    for cid, items in jobs.items():
        atomic_json(out / "jobs" / (cid + ".json"), {"schema":SCHEMA,"samples":items})
    return {"path":str(manifest_path),"samples":len(samples),"blockers":manifest["blockers"],
            "configuration_boots":len(jobs),"launches_performed":0}

def select_pending(campaign, config_filter=None, bench_filter=None, repeat_filter=None):
    from .ledger import status
    rows, issues = status(campaign)
    selected = []
    for row in rows:
        s = row["sample"]
        if row["state"] == "complete":
            continue
        if config_filter and s["configuration"]["id"] not in config_filter:
            continue
        if bench_filter and s["case"]["benchmark"] not in bench_filter:
            continue
        if repeat_filter and s["repetition"] not in repeat_filter:
            continue
        selected.append({**s,"previous_state":row["state"]})
    return selected, issues
