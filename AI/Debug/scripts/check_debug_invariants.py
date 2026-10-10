#!/usr/bin/env python3
"""Report high-signal EC source/protocol checks; warnings require source review."""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path


def say(kind: str, message: str, warnings: list[str]) -> None:
    print(f"{kind}: {message}")
    if kind in {"WARN", "ERROR"}:
        warnings.append(message)


def read_if(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return ""


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("repo", nargs="?", default=".", help="repository root")
    parser.add_argument("--strict", action="store_true",
                        help="exit 1 when a warning is found")
    args = parser.parse_args()
    root = Path(args.repo).resolve()
    warnings: list[str] = []

    if not (root / "chipyard").is_dir():
        print(f"INFO: {root} does not look like an EC/Chipyard repository; no domain checks run")
        return 0

    source_rel = [
        "chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala",
        "chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala",
        "chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala",
        "chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala",
        "chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala",
        "chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala",
    ]
    sources = {rel: read_if(root / rel) for rel in source_rel}
    present = [rel for rel, text in sources.items() if text]
    if not present:
        say("INFO", "no known GuardianCouncil source files found", warnings)
        return 0
    say("PASS", f"found {len(present)}/{len(source_rel)} known source files", warnings)
    all_source = "\n".join(sources.values())
    core = sources.get(source_rel[0], "")
    ghm = sources.get(source_rel[1], "")
    rsu = sources.get(source_rel[4], "")

    required = {
        "sequence-aware ARF ordering": (("dataConsumedSeq",), ("arfAfterData",)),
        "type-specific memory readiness": (("io_cdc_ready_mem", "cdc_ready_mem"),),
        "overflow reporting": (("io_ingress_overflow", "ingress_overflow"),),
        "clean executable context": (("context_idle",),),
        "bounded package progress": (("package_progress_timeout",),),
    }
    for label, groups in required.items():
        missing = ["/".join(options) for options in groups
                   if not any(option in all_source for option in options)]
        if missing:
            say("WARN", f"{label} marker(s) missing: {', '.join(missing)}", warnings)
        else:
            say("PASS", f"{label} markers present", warnings)

    if re.search(r"packet_cdc_ready_raw|rsu_slave\.io\.cdc_ready\s*\|", core):
        say("WARN", "RocketCore contains a type-insensitive packet-ready OR; inspect mixed-lane atomicity", warnings)
    else:
        say("PASS", "no known type-insensitive packet-ready OR pattern", warnings)

    if "new_package" in core and "package_result_waiting" not in core:
        say("WARN", "new-package logic has no visible package_result_waiting guard", warnings)
    else:
        say("PASS", "new-package/result-waiting guard is visible or not applicable", warnings)

    if rsu and "io.big_hang" not in rsu:
        say("WARN", "R_RSU has no visible big_hang backpressure reference", warnings)
    elif rsu:
        say("PASS", "R_RSU references big_hang backpressure", warnings)

    generated = list((root / "chipyard/sims").rglob("BoomCore.sv")) if (root / "chipyard/sims").is_dir() else []
    if generated:
        say("INFO", f"found {len(generated)} generated BoomCore.sv file(s); compare signal names/revision manually", warnings)
        source_mtime = max((root / rel).stat().st_mtime for rel in present)
        generated_mtime = max(path.stat().st_mtime for path in generated)
        if generated_mtime < source_mtime:
            say("WARN", "generated collateral is older than current source; waveform validation may be stale", warnings)
    else:
        say("INFO", "no generated BoomCore.sv found; source checks cannot validate RTL behavior", warnings)

    try:
        diff = subprocess.run(["git", "-C", str(root), "diff", "--check"],
                              text=True, capture_output=True, check=False)
    except OSError as exc:
        say("WARN", f"could not run git diff --check: {exc}", warnings)
    else:
        if diff.returncode:
            say("WARN", "git diff --check reports whitespace errors (separate pre-existing findings before judging a fix)", warnings)
            print(diff.stdout, end="")
            print(diff.stderr, end="", file=sys.stderr)
        else:
            say("PASS", "git diff --check", warnings)

    if args.strict and warnings:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
