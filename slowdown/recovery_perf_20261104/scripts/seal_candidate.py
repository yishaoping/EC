#!/usr/bin/env python3
"""Seal a private candidate; never replace the accepted hardware revision."""
import argparse
import hashlib
import json
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "slowdown/recovery_perf_20261104"


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def seal(build_id):
    base = ROOT / "slowdown/optimization_6_overlap"
    manifest = base / "runs" / build_id / "run_manifest.json"
    m = json.loads(manifest.read_text())
    assert m["hardware_generation"] == m["verilator_build"] == "PASS"
    for group in ["hardware_sha256", "restored_resource_sha256"]:
        for name, digest in m["source"][group].items():
            assert sha(ROOT / name) == digest, name
    build = base / "build" / build_id
    sim = build / "verilator/simulator-chipyard-v1Config"
    dest = OUT / "build" / build_id
    dest.mkdir(parents=True, exist_ok=False)
    sealed = dest / "run_manifest.json"
    sealed.write_bytes(manifest.read_bytes())
    revision = {"status": "CANDIDATE", "canonical_hardware_commit": m["source"]["git_head"],
        "parent_hardware_revision": "a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1",
        "build_id": build_id, "build_manifest": str(sealed.relative_to(ROOT)),
        "build_manifest_sha256": sha(sealed), "simulator": str(sim.relative_to(ROOT)),
        "simulator_sha256": sha(sim),
        "emitted_DCache_sha256": sha(build / "generated/gen-collateral/BoomNonBlockingDCache.sv"),
        "scope": "private recovery performance candidate; acceptance pending"}
    path = dest / "revision.json"
    path.write_text(json.dumps(revision, indent=2) + "\n")
    return path


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("build_id")
    print(seal(parser.parse_args().build_id))
