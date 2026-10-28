#!/usr/bin/env python3
"""User-run preflight for private libc temporary files and mmap, no simulation."""
import ctypes
import hashlib
import json
import mmap
import os
from pathlib import Path
import shutil
import socket
import sys

root = Path("/data1/gzh/EC/slowdown/optimization_3_checker").resolve()
project_root = root.parents[1]
tmp = Path(os.environ["TMPDIR"]).resolve()
tmp.relative_to(root)
# Check mount flags before attempting writes. Never create a test file in a
# protected directory, even if an incorrectly configured sandbox exposed it.
for protected in (root.parent, project_root / "chipyard/generators",
                  project_root / "chipyard/build.sbt",
                  project_root / "baseline", project_root / ".git",
                  Path.home(), Path("/proc")):
    if not os.statvfs(protected).f_flag & os.ST_RDONLY:
        raise RuntimeError("protected path is not mounted read only: " + str(protected))
if os.statvfs(tmp).f_flag & os.ST_RDONLY:
    raise RuntimeError("private temporary directory is mounted read only")
layout_path = os.environ.get("SLOWDOWN_SBT_LAYOUT")
if layout_path:
    layout = json.loads(Path(layout_path).read_text())
    for record in layout["roots"]:
        virtual, backing = Path(record["virtual_root"]), Path(record["backing_root"])
        current_stat, backing_stat = virtual.stat(), backing.stat()
        if (current_stat.st_dev, current_stat.st_ino) != (backing_stat.st_dev, backing_stat.st_ino):
            raise RuntimeError("local SBT build root does not use its private backing: " + str(virtual))
        if [current_stat.st_dev, current_stat.st_ino] == record["original_device_inode"]:
            raise RuntimeError("local SBT build root still exposes the original directory inode")
        if not os.access(virtual, os.W_OK) or os.statvfs(virtual).f_flag & os.ST_RDONLY:
            raise RuntimeError("SBT would stage a read-only local build: " + str(virtual))
        for child in record["read_only_children"]:
            if not os.statvfs(child).f_flag & os.ST_RDONLY:
                raise RuntimeError("original SBT source entry is writable: " + child)
        if hashlib.sha256((virtual / "build.sbt").read_bytes()).hexdigest() != record["build_definition_sha256"]:
            raise RuntimeError("SBT build definition changed through the private directory view")
sys.path.insert(0, str(root / 'scripts'))
from sbt_inputs import build_plan, checked_resource_inventory
resources = checked_resource_inventory(
    build_plan(project_root / 'chipyard', Path(os.environ['SLOWDOWN_SBT_TARGET'])),
    root / 'manifests/sbt_resource_inputs.json')
for path, expected in json.loads(os.environ.get("SLOWDOWN_SOURCE_HASHES", "{}")).items():
    if hashlib.sha256(Path(path).read_bytes()).hexdigest() != expected:
        raise RuntimeError("source bytes changed through sandbox mount layout: " + path)
expected_tools = json.loads(os.environ.get("SLOWDOWN_EXPECT_TOOLS", "{}"))
path_errors = []
for name, expected in expected_tools.items():
    found = shutil.which(name)
    if found is None or Path(found).resolve() != Path(expected).resolve():
        path_errors.append(name + ": " + str(found) + "; expected " + str(expected))
if path_errors:
    raise RuntimeError("PATH resolves unexpected tools: " + "; ".join(path_errors))
host_netns = os.environ.get("SLOWDOWN_HOST_NETNS")
if host_netns and os.readlink("/proc/self/ns/net") == host_netns:
    raise RuntimeError("sandbox unexpectedly shares the host network namespace")
native_zlib = os.environ.get("SLOWDOWN_NATIVE_ZLIB")
if native_zlib:
    library = ctypes.CDLL(str(Path(native_zlib) / "lib/libz.so.1"))
    library.zlibVersion.restype = ctypes.c_char_p
    if library.zlibVersion().decode() != "1.2.13":
        raise RuntimeError("unexpected native zlib ABI")
libc = ctypes.CDLL(None, use_errno=True)
libc.tmpfile.restype = ctypes.c_void_p
libc.fileno.argtypes = [ctypes.c_void_p]
libc.fileno.restype = ctypes.c_int
libc.fclose.argtypes = [ctypes.c_void_p]
handles = []
try:
    for _ in range(4):
        handle = libc.tmpfile()
        if not handle:
            raise OSError(ctypes.get_errno(), "libc tmpfile failed")
        handles.append(handle)
        fd = libc.fileno(handle)
        os.ftruncate(fd, 4096)
        with mmap.mmap(fd, 4096) as view:
            view[:4] = b"test"
    for path in [tmp / "optimization_3_checker_probe", Path("/tmp/slowdown_probe"), Path("/var/tmp/slowdown_probe")]:
        with path.open("xb") as f:
            f.write(b"write probe\n")
        path.unlink()
    path = tmp / ".sbt/sbt-socket-18446744073709551615/sbt-load.sock"
    path.parent.mkdir(parents=True, exist_ok=True)
    with socket.socket(socket.AF_UNIX) as s:
        s.bind(str(path))
    path.unlink()
    print("LIBC_TMPFILE_4=PASS\nMMAP=PASS\nPRIVATE_CAPTURE_TMP=PASS\n"
          "PRIVATE_TMP_MOUNTS=PASS\nSBT_SOCKET=PASS\n"
          "CURRENT_SOURCE_BASELINE_GIT_HOME_PROC_READ_ONLY=PASS\n"
          "SBT_LOCAL_ROOTS=" + ("PRIVATE_WRITABLE_SOURCES_READ_ONLY" if layout_path else "NOT_REQUESTED") + "\n"
          "CURRENT_SOURCE_BYTES=" + ("PASS" if os.environ.get("SLOWDOWN_SOURCE_HASHES") else "NOT_REQUESTED") + "\n"
          "SBT_BLACKBOX_SOURCE_RESOURCES=PASS\n"
          "SBT_RESOURCE_REFERENCES=" + str(len(resources['references'])) + "\n"
          "PATH_IDENTITY=" + ("PASS" if expected_tools else "NOT_REQUESTED") + "\n"
          "NATIVE_ZLIB_ABI=" + ("PASS" if native_zlib else "NOT_REQUESTED") + "\n"
          "NETWORK_NAMESPACE=" + ("ISOLATED" if host_netns else "NOT_REQUESTED"))
finally:
    for handle in handles:
        libc.fclose(handle)
