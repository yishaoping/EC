#!/usr/bin/env python3
"""Audit the completed triplets directly, without rerunning any benchmark."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "slowdown/recovery_perf_20261104"
EVAL = ROOT / "slowdown/parsec_evaluation_20261103"


def main():
    selected = json.loads((OUT / "baseline/primary_selection.json").read_text())
    evidence = {}
    for workload, ids in selected.items():
        runs = {mode: EVAL / "runs" / rid for mode, rid in ids.items()}
        manifests = {mode: json.loads((p / "run_manifest.json").read_text())
                     for mode, p in runs.items()}
        for key in ["roi_instret", "output", "software"]:
            assert len({json.dumps(m[key], sort_keys=True) for m in manifests.values()}) == 1, (workload, key)
        assert manifests["check"]["elf_sha256"] == manifests["correction"]["elf_sha256"]
        assert manifests["native"]["simulator_sha256"] == manifests["check"]["simulator_sha256"]
        images = {mode: (p / "test.riscv").read_bytes() for mode, p in runs.items()}
        for mode, data in images.items():
            assert hashlib.sha256(data).hexdigest() == manifests[mode]["elf_sha256"]
        assert images["check"] == images["correction"]
        a, b = images["native"], images["check"]
        assert len(a) == len(b)
        differences = [(i, x, y) for i, (x, y) in enumerate(zip(a, b)) if x != y]
        assert len(differences) == 1 and differences[0][1:] == (0, 1)
        for mode, p in runs.items():
            analysis = json.loads((p / "analysis.json").read_text())
            assert analysis["status"] == "PASS", (workload, mode)
            assert manifests[mode]["software_correct"]
        correction = json.loads((runs["correction"] / "analysis.json").read_text())
        assert correction["packages"]["FAIL"] == correction["packages"]["CANCELLED"] == 0
        assert manifests["correction"]["canonical_hardware_commit"] == "a6e63c75947739dfbb411b32bfe0eb5ed55c5bb1"
        evidence[workload] = {"status": "PASS", "runs": ids,
            "roi_instructions": manifests["check"]["roi_instret"],
            "roi_cycles": {mode: m["roi_cycles"] for mode, m in manifests.items()},
            "output": manifests["check"]["output"],
            "native_protected_elf_difference": differences,
            "protected_elf_sha256": manifests["check"]["elf_sha256"],
            "scope": "same software manifest, executable bytes except mode byte, instructions, output and application ROI; internal detection coverage counters unavailable"}
    path = OUT / "baseline/consistency.json"
    path.write_text(json.dumps(evidence, indent=2) + "\n")
    print("PASS: " + ", ".join(evidence))


if __name__ == "__main__":
    main()
