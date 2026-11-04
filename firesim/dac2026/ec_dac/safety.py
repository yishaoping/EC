"""Fail-closed manual deployment/run gates. There is no global-driver path."""
from __future__ import annotations
import datetime as dt
import os
from pathlib import Path
import shutil
from .audit import hardware, source_identity
from .common import ROOT, KIT, read_json, filehash, require, digest, kit_identity
from .comparison import validate_sample_comparison

FORBIDDEN = {"infrasetup", "enumeratefpgas", "rmmod", "modprobe", "unbind", "rescan", "kill", "killall", "pkill"}

def checked_adapter(spec):
    require(isinstance(spec, dict), "missing reviewed adapter; no default deployment command")
    require(spec.get("reviewed") is True, "adapter effects and source have not been reviewed")
    path = Path(spec["executable"]).resolve()
    require(path.is_file() and os.access(path, os.X_OK), "adapter executable missing")
    require(filehash(path) == spec.get("sha256"), "adapter hash changed")
    argv = [str(path)] + spec.get("arguments", [])
    require(not any(x in FORBIDDEN for x in argv), "global/unsafe action denied")
    require(spec.get("shell") is False, "shell adapters are not accepted")
    return argv

def checked_memory_runtime(site, common=None):
    spec = site.get("memory_runtime")
    require(isinstance(spec, dict), "missing fixed common FASED runtime manifest")
    require(filehash(spec["path"]) == spec.get("sha256"), "FASED runtime manifest changed")
    memory = read_json(spec["path"])
    require(memory.get("schema") == "ec-dac-memory/1" and memory.get("model") == "LatencyBandwidthPipe" and
            memory.get("model_index") == 0 and memory.get("static_register_audit") == "PASSED",
            "unreviewed FASED runtime settings")
    require(set(memory["settings"]) == {"readLatency","writeLatency","readMaxReqs","writeMaxReqs","relaxFunctionalModel"},
            "incomplete FASED runtime settings")
    require(all(type(v) is int and 0 <= v < 2**31 for v in memory["settings"].values()),
            "invalid FASED register value")
    require(all(memory["settings"][k] >= 1 for k in ("readLatency","writeLatency","readMaxReqs","writeMaxReqs")),
            "FASED latency/request limit must be positive")
    bound = min(memory["evidence"][cid]["generated_reset_defaults"][key]
                for cid in ("B","C4") for key in ("readMaxReqs","writeMaxReqs"))
    require(max(memory["settings"]["readMaxReqs"], memory["settings"]["writeMaxReqs"]) <= bound,
            "FASED request limit exceeds the audited common range")
    require(memory["settings"]["relaxFunctionalModel"] == 0, "relaxed functional memory is not admitted")
    expected = [f"+mm_{k}_0={v}" for k,v in sorted(memory["settings"].items())]
    require(memory.get("plusargs") == expected, "FASED arguments/settings mismatch")
    args = Path(spec["path"]).parent / "fased-common.args"
    require(filehash(args) == memory["arguments_sha256"] and args.read_text().split() == expected,
            "FASED argument file changed")
    if common is not None:
        require(common.get("memory_runtime_manifest_sha256") == spec["sha256"],
                "sample refers to a different FASED runtime version")
        require(common.get("boom_mhz") == common.get("uncore_mhz") == memory["boom_uncore_mhz"],
                "FASED target/reference frequency changed")
    return str(Path(spec["path"]).resolve())

def gate(config_id, operation, campaign_manifest=None, phase="main"):
    site = read_json(KIT / "config/site.json")
    h = hardware()  # recheck immediately, never reuse an old inventory
    effects = site["effects"]
    display = {"operation":operation,"phase":phase,"target_bdf":site["target_bdf"],"effects":effects,
               "occupancy":h["occupancy"],"processes":h["fpga_processes"],
               "proc_permission_denied":h["proc_permission_denied"]}
    # All-device idle/reservation required even for isolated adapters. Conservative by design.
    reasons = []
    if not site["target_bdf"] or site["target_bdf"] not in {x["bdf"] for x in h["devices"]}:
        reasons.append("target card is not selected or not present")
    if h["fpga_processes"] or h["open_devices"]:
        reasons.append("existing FPGA tasks/device users detected; no deployment or new run is allowed")
    if h["proc_permission_denied"]:
        reasons.append("cannot inspect all process/device users; administrator/scheduler isolation is unresolved")
    for k in ("driver_unload","driver_reload","global_reset","pcie_rescan","device_unbind"):
        if effects.get(k) is not False:
            reasons.append("effect denied: " + k)
    if effects.get("isolation_verified") is not True:
        reasons.append("per-card isolation is unverified")
    reservation = site.get("reservation")
    if not isinstance(reservation, dict):
        reasons.append("missing scheduler/administrator reservation (absence of FD users is not proof of idle)")
    else:
        try:
            r = read_json(reservation["path"])
            require(filehash(reservation["path"]) == reservation["sha256"], "reservation changed")
            expires = dt.datetime.fromisoformat(r["expires_utc"])
            require(expires.tzinfo is not None and expires > dt.datetime.now(dt.timezone.utc), "reservation expired")
            require(set(r["bdfs"]) >= {x["bdf"] for x in h["devices"]}, "reservation does not cover both cards")
            require(r["exclusive"] is True and bool(r["issuer"]), "reservation is not exclusive")
        except (OSError, ValueError, KeyError) as e:
            reasons.append(str(e))
    evidence_path = site.get("compatibility_evidence")
    memory_runtime = None
    try:
        require(bool(evidence_path), "missing compatibility/measurement/ Linux checker evidence")
        evidence = read_json(evidence_path)
        require(evidence["source_id"] == source_identity()["id"], "source changed since compatibility validation")
        required=["platform_compatible","linux_checker_runtime","roi_boundary_test","passive_observer",
                  "execution_timestamp_test","final_compare_test","cdc_timestamp_test","single_boot_batch_test",
                  "output_validator_test","image_verified","configuration_comparability","memory_runtime_readback_test"]
        if phase=="link":
            required=["platform_compatible","linux_checker_runtime","image_verified","passive_observer","taps_source_reviewed"]
        for k in required:
            require(evidence.get(k) is True, "missing compatibility evidence: " + k)
        key="validated_structural_configurations" if phase=="link" else "validated_configurations"
        require(config_id in evidence[key], "logical configuration unvalidated")
        require(bool(evidence.get("test_artifacts")), "evidence has no referenced test artifacts")
        for p, sha in evidence["test_artifacts"].items():
            require(filehash(p) == sha, "validation evidence changed: " + p)
        artifacts = site["per_config_artifacts"][config_id]
        for k in ("bitstream","driver","kernel","rootfs","rtl_manifest","observer_manifest"):
            a = artifacts[k]
            require(filehash(a["path"]) == a["sha256"], "artifact changed: " + k)
        if campaign_manifest is not None:
            require(campaign_manifest["source"]["id"] == evidence["source_id"], "campaign source mismatch")
            require(campaign_manifest["site_id"] == digest(site), "campaign site/bitstream/image mismatch")
            require(campaign_manifest["kit"]["id"]==kit_identity()["id"],"measurement/runner code changed since planning")
            require(not campaign_manifest.get("blockers"), "campaign has unresolved preparation blockers")
            if phase != "link":
                for sample in campaign_manifest["samples"]:
                    if sample["configuration"]["id"] == config_id:
                        validate_sample_comparison(sample)
            ready_key="structural_ready" if phase=="link" else "ready"
            require(all(s["configuration"].get(ready_key) is True for s in campaign_manifest["samples"]
                        if s["configuration"]["id"]==config_id), "campaign contains unready configuration")
            require(all(not (isinstance(v,str) and "BLOCKED" in v) for s in campaign_manifest["samples"]
                        for v in s["case"]["common"].values()),"unresolved common parameter (for example FASED memory timing)")
        if operation == "run":
            selected = [s for s in campaign_manifest["samples"] if s["configuration"]["id"]==config_id] if campaign_manifest else []
            memory_runtime = checked_memory_runtime(site)
            for sample in selected:
                checked_memory_runtime(site, sample["case"]["common"])
    except (OSError, ValueError, KeyError) as e:
        reasons.append(str(e))
    limits = site["limits"]
    if shutil.disk_usage(ROOT).free < limits["min_free_gib"] * 2**30:
        reasons.append("insufficient free disk")
    if os.getloadavg()[0] > limits["max_load"]:
        reasons.append("shared-server load exceeds configured limit")
    try:
        adapter = checked_adapter(site["deployment_adapter" if operation == "deploy" else "run_adapter"])
    except (OSError, ValueError, KeyError) as e:
        reasons.append(str(e))
        adapter = None
    return {**display,"allowed":not reasons,"reasons":reasons,"argv":adapter,
            "memory_runtime":memory_runtime}
