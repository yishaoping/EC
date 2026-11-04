#!/usr/bin/env python3
"""Read files/symlinks only; save content inventories in a NEW report directory."""
import argparse
import json
import os
from pathlib import Path
import stat
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from ec_dac.common import atomic_json, digest, filehash

def inventory(root):
    root = Path(root)
    records, unstable, errors = {}, [], []
    for directory, dirs, files in os.walk(root, followlinks=False):
        for name in sorted(dirs + files):
            path = Path(directory) / name
            rel = str(path.relative_to(root))
            try:
                before = path.lstat()
                if stat.S_ISLNK(before.st_mode):
                    records[rel] = {"kind":"symlink", "target":os.readlink(path)}
                elif stat.S_ISDIR(before.st_mode):
                    records[rel] = {"kind":"directory"}
                elif stat.S_ISREG(before.st_mode):
                    sha = filehash(path)
                    after = path.lstat()
                    if (before.st_size, before.st_mtime_ns, before.st_ctime_ns) != (after.st_size, after.st_mtime_ns, after.st_ctime_ns):
                        unstable.append(rel)
                    records[rel] = {"kind":"file", "bytes":before.st_size, "sha256":sha}
                else:
                    records[rel] = {"kind":"special", "mode":before.st_mode}
            except OSError as exc:
                errors.append({"path":rel, "error":str(exc)})
    return {"root":str(root), "entries":records, "identity":digest(records),
            "changed_while_reading":unstable, "errors":errors}

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--source", default="/home/wtl/parsec_gc")
    p.add_argument("--destination", default="/data1/gzh/EC/Software/PARSEC")
    p.add_argument("--out", required=True)
    a = p.parse_args()
    out = Path(a.out)
    if not Path(a.source).is_dir() or not Path(a.destination).is_dir():
        p.error("both source and destination must exist")
    out.mkdir(parents=True, exist_ok=False)
    source, destination = inventory(a.source), inventory(a.destination)
    atomic_json(out/"source.json", source, replace=False)
    atomic_json(out/"destination.json", destination, replace=False)
    left, right = source["entries"], destination["entries"]
    differences = [{"path":k, "source":left.get(k), "destination":right.get(k)}
                   for k in sorted(set(left)|set(right)) if left.get(k) != right.get(k)]
    stable=not any(v["errors"] or v["changed_while_reading"] for v in (source, destination))
    worktree_differences=[v for v in differences if not (v["path"]==".git" or v["path"].startswith(".git/"))]
    valid=stable and not worktree_differences
    state=("MATCH_AT_READ_TIMES" if not differences else "WORKTREE_MATCH_WITH_GIT_METADATA_DIFFERENCES") if valid else "DIFFERENCES_OR_UNSTABLE_SOURCE"
    result = {"status":state,"exact_all_entries_match":stable and not differences,
              "worktree_content_match":valid,"worktree_differences":worktree_differences,
              "source":a.source, "destination":a.destination, "source_entries":len(left), "destination_entries":len(right),
              "source_identity":source["identity"], "destination_identity":destination["identity"],
              "differences":differences, "errors":source["errors"]+destination["errors"],
              "changed_while_reading":source["changed_while_reading"]+destination["changed_while_reading"],
              "note":"Read-only content/symlink validation; not an atomic filesystem snapshot. Git metadata differences are retained separately; index stat caches may change after a copy. No file was repaired or deleted."}
    atomic_json(out/"comparison.json", result, replace=False)
    print(json.dumps({k:v for k,v in result.items() if k not in ("differences","worktree_differences","errors","changed_while_reading")}, ensure_ascii=False, indent=2))
    print(json.dumps({"differences":len(differences), "report":str(out)}, ensure_ascii=False))
    return 0 if valid else 2

if __name__ == "__main__":
    sys.exit(main())
