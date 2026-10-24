"""Keep SBT local-build roots writable without making source files writable.

SBT 1.8.2 Resolvers.local calls File.canWrite() on each local build root.
A read-only root triggers a recursive staging copy, before any command-line
target setting takes effect. That copy dereferences unrelated dangling links.
Only shallow directory entries and build metadata are private copies here;
all ordinary source entries are bind-mounted directly from the original tree.
"""
import hashlib
import os
from pathlib import Path

PRIVATE_ENTRIES = {"project", "target", ".bsp", ".bloop", ".metals"}
LOCAL_ROOTS = (("chipyard", "."), ("firesim_shared_build", "sims/firesim/sim"))


def local_build_mounts(current, build):
    mounts, roots = [], []
    for name, relative in LOCAL_ROOTS:
        original = current / relative
        if not (original / "build.sbt").is_file():
            raise RuntimeError("Missing pinned local SBT build: " + str(original))
        backing = build / "sbt-roots" / name
        backing.mkdir(parents=True)
        mounts.append((backing, original, "rw"))
        readonly, links = [], []
        for entry in sorted(original.iterdir()):
            target = backing / entry.name
            if entry.is_symlink():
                # Preserve link semantics; never chase optional workload links.
                target.symlink_to(os.readlink(entry))
                links.append({"path": str(entry), "target": os.readlink(entry)})
            elif entry.is_dir():
                target.mkdir()
                if entry.name not in PRIVATE_ENTRIES:
                    mounts.append((entry, entry, "ro"))
                    readonly.append(str(entry))
            elif entry.is_file():
                target.touch()
                mounts.append((entry, entry, "ro"))
                readonly.append(str(entry))
            else:
                raise RuntimeError("Unsupported entry in local SBT root: " + str(entry))
        roots.append({"name": name, "virtual_root": str(original), "backing_root": str(backing),
                      "read_only_children": readonly, "preserved_links": links,
                      "build_definition_sha256": hashlib.sha256((original / "build.sbt").read_bytes()).hexdigest(),
                      "original_device_inode": [original.stat().st_dev, original.stat().st_ino],
                      "scope": "writable directory inode only; ordinary source entries read only"})
    return mounts, {"schema": 1, "roots": roots,
                    "simulator": "VERILATOR", "firesim_execution": "NOT_REQUESTED",
                    "reason": "avoid SBT local-build staging; retain shared targetutils dependency"}
