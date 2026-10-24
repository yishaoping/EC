#!/usr/bin/env python3
"""User-run bounded FST extraction with private input copy, sidecars and tmp.

Uses only the native reader already built by a completed slowdown run. Native
FST readers may create adjacent files; the original run is mounted read-only.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path("/data1/gzh/EC/slowdown")
sys.path.insert(0, str(ROOT / "scripts"))
from sandbox_support import POLICY, sandbox_command


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--run", type=Path, required=True, help="Current run directory with run_manifest.json")
    p.add_argument("--out", type=Path, required=True, help="NEW directory under slowdown/analysis/results")
    p.add_argument("--start", type=int)
    p.add_argument("--end", type=int)
    args = p.parse_args()
    run, out = args.run.resolve(), args.out.resolve()
    run.relative_to((ROOT / "runs").resolve())
    out.relative_to((ROOT / "analysis/results").resolve())
    if out.exists() or (args.end is not None and args.start is None):
        raise SystemExit("new output directory and START before END required")
    if args.start is not None and (args.start < 0 or (args.end is not None and args.end < args.start)):
        raise SystemExit("invalid tick window")
    manifest = json.loads((run / "run_manifest.json").read_text())
    reader = Path(manifest["fst_reader"]["path"])
    if sha(reader) != manifest["fst_reader"]["sha256"]:
        raise SystemExit("native reader identity mismatch")
    original = run / "waveform.fst"
    if shutil.disk_usage(ROOT).free < original.stat().st_size + 1024**3:
        raise SystemExit("insufficient space for private FST input copy")
    out.mkdir(parents=True)
    (out / "tmp").mkdir()
    local = out / "input.fst"
    shutil.copyfile(original, local)
    source_sha = sha(original)
    if sha(local) != source_sha:
        raise SystemExit("copied FST identity mismatch")
    native = [str(reader), str(local), "trace"]
    if args.start is not None:
        native.append(str(args.start))
    if args.end is not None:
        native.append(str(args.end))
    command = sandbox_command(native, out, {"TMPDIR": str(out / "tmp")},
                              out / "tmp", "/usr/bin/bwrap", out)
    with (out / "trace.tsv").open("xb") as stdout, (out / "reader.stderr").open("xb") as stderr:
        rc = subprocess.run(command, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
                            env={"PATH": "/usr/bin:/bin"}).returncode
    (out / "extraction.json").write_text(json.dumps({"command": command, "return_code": rc,
        "sandbox_policy": POLICY,
        "original": str(original), "original_sha256": source_sha, "reader_sha256": sha(reader),
        "private_copy": str(local), "run_manifest_sha256": sha(run / "run_manifest.json"),
        "originals": "READ_ONLY_ROOT; only NEW output and private tmp mounts writable"}, indent=2) + "\n")
    print(out / "trace.tsv")
    return rc


if __name__ == "__main__":
    sys.exit(main())
