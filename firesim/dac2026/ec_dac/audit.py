"""Read-only inventories. Never opens FPGA character devices or runs platform utilities."""
from __future__ import annotations
import datetime as dt
import glob
import os
from pathlib import Path
import re
import shutil
import subprocess
from .common import ROOT, FIRESIM, MANAGER_ENV, digest, filehash

def command(argv, cwd=None, timeout=20):
    try:
        p = subprocess.run(argv, cwd=cwd, capture_output=True, text=True,
                           errors="replace", timeout=timeout)
        return {"argv":argv,"rc":p.returncode,"stdout":p.stdout,"stderr":p.stderr}
    except (OSError, subprocess.TimeoutExpired) as e:
        return {"argv":argv,"rc":None,"error":str(e)}

def git_identity(path):
    # --no-optional-locks prevents a read-only inventory refreshing someone else's index.
    args = ["git", "--no-optional-locks", "-c", "safe.directory=" + str(path), "-C", str(path)]
    h = command(args + ["rev-parse", "HEAD"])
    status = command(args + ["status", "--porcelain=v1", "--untracked-files=normal"])
    diff = command(args + ["diff", "--binary", "HEAD", "--", "."])
    return {"commit":h,"status":status,"diff_sha256":digest(diff),
            "has_own_git_metadata":(Path(path) / ".git").exists()}

def source_identity():
    # Cover all source/build inputs, excluding compiler outputs, images and tooling binaries.
    work = "firesim/dac2026/work/opt4-alveo-v3"
    prefixes = [f"{work}/{cid}/chipyard/{part}" for cid in ("B","C4")
                for part in ("generators","tools","project","sims/firesim/sim/src",
                             "sims/firesim/sim/midas/src","sims/firesim/sim/midas/targetutils/src",
                             "sims/firesim/sim/firesim-lib/src","sims/firesim/deploy")]
    exts = {".scala", ".sbt", ".mk", ".sv", ".v", ".h", ".cc", ".cpp", ".yaml", ".json", ".py", ".tcl"}
    files = {}
    for prefix in prefixes:
        base = ROOT / prefix
        for directory, dirs, names in os.walk(base, followlinks=False):
            dirs[:] = [d for d in dirs if d not in {"target", ".git", "generated-src", "output", "build", "node_modules"}]
            for n in names:
                p = Path(directory) / n
                if (p.suffix in exts or n in {"Makefile"}) and p.is_file():
                    files[str(p.relative_to(ROOT))] = filehash(p)
    for p in [ROOT/work/cid/"chipyard"/part/n for cid in ("B","C4")
              for part in (".","sims/firesim/sim")
              for n in ("build.sbt", "variables.mk", "common.mk", ".gitmodules", "Makefile")]:
        if p.is_file():
            files[str(p.relative_to(ROOT))] = filehash(p)
    head = command(["git", "--no-optional-locks", "-C", str(ROOT), "rev-parse", "HEAD"])
    fs_commit=command(["git","--no-optional-locks","-C",str(FIRESIM),"rev-parse","HEAD"]).get("stdout","").strip()
    return {"commit":head.get("stdout", "").strip(),"files":files,"firesim_commit":fs_commit,
            "id":digest({"files":files,"firesim_commit":fs_commit})}

def hardware():
    devices = []
    for p in sorted(Path("/sys/bus/pci/devices").glob("*")):
        try:
            if (p / "vendor").read_text().strip() != "0x10ee":
                continue
            devices.append({"bdf":p.name,"device":(p / "device").read_text().strip(),
                            "subsystem_device":(p / "subsystem_device").read_text().strip(),
                            "driver":(p / "driver").resolve().name if (p / "driver").exists() else None})
        except OSError:
            continue
    nodes = {p.name:{"sysfs":str(p.resolve()),"device_node":"/dev/" + p.name}
             for p in Path("/sys/class/xdma").glob("*")}
    processes, denied, opened = [], 0, []
    for p in Path("/proc").glob("[0-9]*"):
        try:
            cmd = (p / "cmdline").read_bytes().replace(b"\x00", b" ").decode(errors="replace")
            exe = (p / "comm").read_text().strip()
            if ("FireSim-" in exe or "firesim" in exe.lower() or
                ("python" in exe.lower() and re.search(r'(?:^|[/ ])firesim(?: |$)', cmd))):
                processes.append({"pid":int(p.name),"cmdline":cmd})
            for f in (p / "fd").iterdir():
                try:
                    target = os.readlink(f)
                    if re.match(r"/dev/(xdma|xclmgmt|dri/render)", target):
                        opened.append({"pid":int(p.name),"fd":f.name,"target":target})
                except PermissionError:
                    denied += 1
                except OSError:
                    pass
        except PermissionError:
            denied += 1
        except (FileNotFoundError, ProcessLookupError):
            pass
    return {"devices":devices,"nodes":nodes,"fpga_processes":processes,
            "open_devices":opened,"proc_permission_denied":denied,
            "occupancy":"BUSY" if processes or opened else "UNKNOWN",
            "note":"No process/FD evidence never proves idle. No FPGA device has been opened."}

def parsec_inventory(path=None):
    p = Path(path or ROOT / "Software/PARSEC")
    binaries = []
    for pattern in ("pkgs/apps/*/inst/*/bin/*", "pkgs/kernels/*/inst/*/bin/*"):
        for b in sorted(p.glob(pattern)):
            if b.is_file():
                binaries.append({"path":str(b.relative_to(p)),"sha256":filehash(b),
                                 "elf":command(["file", "-b", str(b)]).get("stdout", "").strip()})
    hooks = p / "pkgs/libs/hooks/src/hooks.c"
    return {"path":str(p),"version":(p / "version").read_text().strip() if (p / "version").exists() else None,
            "git":git_identity(p) if (p / ".git").exists() else None,
            "binaries":binaries,"hooks_sha256":filehash(hooks) if hooks.exists() else None,
            "riscv_binary_count":sum("RISC-V" in b["elf"] for b in binaries),
            "roi_target_bridge_verified":False}

def inventory():
    versions = {}
    for exe, args in [("vivado",["-version"]),("python3",["--version"]),("java",["-version"]),
                      ("riscv64-unknown-linux-gnu-gcc",["--version"]),("yosys",["-V"])]:
        versions[exe] = {"path":shutil.which(exe),"version":command([exe] + args)}
    fs = FIRESIM
    return {"time":dt.datetime.now(dt.timezone(dt.timedelta(hours=8))).isoformat(),
            "host":command(["uname", "-a"]),"hardware":hardware(),"versions":versions,
            "resources":{"disk":shutil.disk_usage(ROOT)._asdict(),"load":os.getloadavg()},
            "repository":git_identity(ROOT),"source":source_identity(),
            "fireSim":{"own_git_metadata":(fs / ".git").exists(),
                       "platforms":sorted(x.name for x in (fs / "platforms").iterdir()),
                       "path":str(fs),"git":git_identity(fs),
                       "selected_release":"1.17.0 (native Alveo candidate, Chipyard 1.9.0 API adapters; see actual per-phase results)",
                       "selected_commit":git_identity(fs)["commit"].get("stdout", "").strip(),
                       "chipyard_gitlink":"7475bfb1a05802ac4dfc3990a889f93164b8d798",
                       "upstream_chipyard_release":"1.9.0; B clean upstream, C4 frozen EC/opt4; integration under actual build verification",
                       "manager_environment":str(MANAGER_ENV),
                       "bundled_legacy_firesim_used_for_runtime":False},
            "parsec":parsec_inventory()}
