#!/usr/bin/env python3
"""Same-binary Current experiment. Default execution is USER-ONLY and expensive.

--static-check performs identity/path/hash checks only. It cannot reach make,
SBT, compilers, native probes, or the simulator.
--preflight-only additionally executes sandboxed tool VERSION commands and
temporary-file probes, then stops before any compilation or SBT project load.
"""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import selectors
import shlex
import shutil
import signal
import subprocess
import sys
import tempfile
import time
import uuid
import zipfile

# -I deliberately removes the script directory from sys.path. Add only this
# pinned local directory so both launch and extraction use the same policy.
sys.path.insert(0, str(Path(__file__).resolve().parent))
from sandbox_support import POLICY, sandbox_command
from sbt_layout import local_build_mounts
from sbt_inputs import build_plan, checked_resource_inventory

ROOT = Path("/data1/gzh/EC")
OUT = ROOT / "slowdown"
CURRENT = ROOT / "chipyard"
BASELINE = ROOT / "baseline"
PREP = OUT / "manifests/preparation.json"
ELF = BASELINE / "software_common_builds/gapbs512_20261023_03/test.riscv"
LOADMEM = ELF.with_name("test.loadmem_hex")
ELF_SHA = "da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c"
LOADMEM_SHA = "f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad"
BASELINE_ROI = 1001675
SKIP = {".git", ".conda-env", ".sbt", ".ivy2", ".java_tmp", ".bloop", ".bsp",
        "target", "generated-src", "output", "__pycache__", "node_modules",
        ".venv", ".cache", "obj_dir"}

def stamp():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()

def sha(path):
    h = hashlib.sha256()
    with Path(path).open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()

def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True,
                                    separators=(",", ":")).encode()).hexdigest()

def record(path, data):
    path = Path(path)
    path.resolve().relative_to(OUT.resolve())
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".new")
    with tmp.open("w") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)
        f.write("\n")
    os.replace(tmp, path)

def git(*args):
    return subprocess.check_output(
        ["git", *args], cwd=ROOT,
        env=dict(os.environ, GIT_OPTIONAL_LOCKS="0")).decode().strip()

def hash_bytes(data):
    return hashlib.sha256(data).hexdigest()

def source_inventory():
    """Capture exact Current Git drift without hashing generated/vendor trees."""
    status = subprocess.check_output(
        ["git", "status", "--porcelain=v1", "--untracked-files=all", "--", "chipyard"],
        cwd=ROOT, env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    diff = subprocess.check_output(
        ["git", "diff", "--no-ext-diff", "--no-textconv", "HEAD", "--binary", "--", "chipyard"], cwd=ROOT,
        env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    staged = subprocess.check_output(
        ["git", "diff", "--no-ext-diff", "--no-textconv", "--cached", "--binary", "--", "chipyard"], cwd=ROOT,
        env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    untracked = subprocess.check_output(
        ["git", "ls-files", "--others", "--exclude-standard", "-z", "--", "chipyard"],
        cwd=ROOT, env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    untracked_files = {os.fsdecode(rel): sha(ROOT / os.fsdecode(rel))
                       for rel in untracked.split(b"\0") if rel}
    files = {}
    for rel in ("generators/boom/src/main/scala/lsu/dcache.scala",
                "generators/boom/src/main/scala/lsu/mshrs.scala",
                "generators/boom/src/main/scala/exu/rob.scala",
                "generators/boom/src/main/scala/exu/core.scala",
                "generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala",
                "generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala",
                "generators/chipyard/src/main/scala/config/RocketConfigs.scala",
                "sims/verilator/Makefile", "common.mk", "variables.mk",
                "build.sbt", "project/plugins.sbt",
                "generators/chipyard/src/main/resources/csrc/emulator.cc",
                "generators/chipyard/src/main/resources/csrc/stage1_exit.h"):
        path = CURRENT / rel
        files["chipyard/" + rel] = {"sha256": sha(path), "size": path.stat().st_size}
    result = {"chipyard_head": subprocess.check_output(
                  ["git", "rev-parse", "HEAD"], cwd=ROOT,
                  env=dict(os.environ, GIT_OPTIONAL_LOCKS="0")).decode().strip(),
              "status": status.decode(), "diff_sha256": hash_bytes(diff),
              "staged_diff_sha256": hash_bytes(staged), "untracked_files": untracked_files,
              "files": files}
    result["source_digest"] = digest(result)
    return result

def ensure_inputs():
    for p, expected in [(ELF, ELF_SHA), (LOADMEM, LOADMEM_SHA)]:
        if not p.is_file() or sha(p) != expected:
            raise RuntimeError("Fixed Baseline software hash mismatch: " + str(p))
    descriptor = json.loads(ELF.with_name("workload.json").read_text())
    if descriptor["elf_sha256"] != ELF_SHA or descriptor["loadmem_sha256"] != LOADMEM_SHA:
        raise RuntimeError("Software descriptor does not identify the pinned binary")
    return descriptor

def tool_config():
    env_record = json.loads((BASELINE / "manifests/environment.json").read_text())
    native = json.loads((BASELINE / "native_environment.json").read_text())
    env = dict(env_record["environment"])
    env.update(native["environment"])
    tools = dict(env_record["tools"])
    tools["java"] = str(Path(env["JAVA_HOME"]) / "bin/java")
    tools["cc"] = env["CC"]
    tools["cxx"] = env["CXX"]
    tools["gcc"] = env["CC"]
    tools["g++"] = env["CXX"]
    tools["sbt_jar"] = env_record["sbt_launch_jar"]
    tools["gtkwave"] = str(CURRENT / ".conda-env/share/verilator/include/gtkwave")
    tools["native_zlib"] = str(BASELINE / "cache/native-zlib")
    return env, tools

def identity_check():
    if not PREP.is_file():
        raise RuntimeError("Missing preparation manifest; experiment is not prepared")
    p = json.loads(PREP.read_text())
    errors = []
    try:
        checked_resource_inventory(build_plan(CURRENT, OUT / 'build/static-plan/scala'),
                                   OUT / 'manifests/sbt_resource_inputs.json')
    except Exception as exc:
        errors.append('SBT/BlackBox input closure: ' + str(exc))
    if git("rev-parse", "HEAD") != p["git_head"]:
        errors.append("Git HEAD changed since preparation; refusing silent source drift")
    patch = OUT / "manifests/current_trace_only.patch"
    if not patch.is_file() or p["trace_patch_sha256"] != sha(patch):
        errors.append("Trace-only patch missing or changed")
    try:
        now = source_inventory()
        if now != p["source_inventory"] or p["source_digest"] != now["source_digest"]:
            errors.append("Current source Git state or trace-source fingerprint changed since preparation")
    except Exception as exc:
        errors.append("Current source inventory: " + str(exc))
    for rel, expected in p["preparation_files"].items():
        path = ROOT / rel
        if not path.is_file() or sha(path) != expected:
            errors.append("Prepared script/trace artifact changed: " + rel)
    try:
        ensure_inputs()
    except Exception as exc:
        errors.append("Software identity: " + str(exc))
    env, tools = tool_config()
    for name, path in tools.items():
        q = Path(path)
        if not q.exists():
            errors.append("Missing tool/dependency " + name + ": " + path)
        elif name not in ("sbt_jar", "gtkwave", "native_zlib") and not os.access(q, os.X_OK):
            errors.append("Tool is not executable " + name + ": " + path)
    for name in ("fstapi.h", "fstapi.c", "fastlz.c", "lz4.c", "fst_config.h"):
        if not (Path(tools["gtkwave"]) / name).is_file():
            errors.append("Missing offline FST reader dependency: " + name)
    config = CURRENT / "generators/chipyard/src/main/scala/config/RocketConfigs.scala"
    if "class v1Config extends Config(" not in config.read_text():
        errors.append("Expected Current chipyard.v1Config not found")
    for rel, expected in p["fixed_files"].items():
        if not (ROOT / rel).is_file() or sha(ROOT / rel) != expected:
            errors.append("Pinned experiment dependency changed: " + rel)
    for rel in ("build", "runs", "tmp", "cache", "manifests"):
        directory = OUT / rel
        if not directory.is_dir() or directory.is_symlink():
            errors.append("Expected local output directory: " + str(directory))
    if OUT.resolve() != OUT:
        errors.append("slowdown output root must not be a symlink")
    baseline = json.loads((ROOT / p["baseline_identity"]["run_manifest"]).read_text())
    if (baseline.get("ROI_cycles") != BASELINE_ROI or
            baseline.get("elf_sha256") != ELF_SHA or
            baseline.get("loadmem_sha256") != LOADMEM_SHA or
            baseline.get("simulator_exit_code") != 0 or
            not baseline.get("process_and_marker_success")):
        errors.append("Baseline comparison anchor does not satisfy pinned ROI/software checks")
    if errors:
        raise RuntimeError("Identity/path preflight failures:\n- " + "\n- ".join(errors))
    return p, env, tools

def static_check(min_free_gib=30):
    p, env, tools = identity_check()
    free = shutil.disk_usage(OUT).free
    if free < min_free_gib * 1024**3:
        raise RuntimeError("Insufficient slowdown disk space: free bytes=" + str(free))
    resources = checked_resource_inventory(build_plan(CURRENT, OUT / 'build/static-plan/scala'),
                                           OUT / 'manifests/sbt_resource_inputs.json')
    # No make -n, SBT, Scala compilation, Java invocation, or tool probe here.
    return {"status": "PASS", "checked_at": stamp(), "git_head": p["git_head"],
            "config": "chipyard.v1Config", "current_source_digest": p["source_digest"],
            "source_file_count": len(p["source_inventory"]["files"]),
            "sbt_resource_preflight": {"status": "PASS", "dependency_projects": len(resources['projects']),
                                       "scala_files_scanned": resources['scala_files'],
                                       "references": len(resources['references']),
                                       "reviewed_dynamic": len(resources['dynamic']),
                                       "ambiguous_names_checked_in_actual_classpath_before_generator": resources['ambiguous_names']},
            "elf_sha256": ELF_SHA, "loadmem_sha256": LOADMEM_SHA,
            "tools": tools, "free_bytes": free, "minimum_free_gib": min_free_gib,
            "hardware_generation": "NOT_EXECUTED", "compilation": "NOT_EXECUTED",
            "simulation": "NOT_EXECUTED"}

def sandbox(argv, cwd, env, temporary, tools, mounts=()):
    return sandbox_command(argv, cwd, env, temporary, tools["bwrap"], OUT, mounts)

def save_progress(manifest):
    record(Path(manifest["run_directory"]) / "run_manifest.json", manifest)


def stop_process(proc):
    if proc.poll() is None:
        proc.terminate()
        try:
            proc.wait(timeout=10)
        except subprocess.TimeoutExpired:
            proc.kill()
            proc.wait()


def invoke(argv, cwd, logfile, env, temporary, tools, manifest, mounts=(), timeout=None):
    wrapped = sandbox(argv, cwd, env, temporary, tools, mounts)
    manifest["commands"].append({"argv": list(map(str, argv)), "cwd": str(cwd),
                                "sandbox_argv": wrapped, "log": str(logfile),
                                "started": stamp()})
    save_progress(manifest)
    print("COMMAND=" + shlex.join(list(map(str, argv))), flush=True)
    print("LOG=" + str(logfile), flush=True)
    with Path(logfile).open("xb") as f:
        proc = subprocess.Popen(wrapped, stdout=f, stderr=subprocess.STDOUT,
                                stdin=subprocess.DEVNULL,
                                env={"PATH": "/usr/bin:/bin"})
        started = last = time.monotonic()
        try:
            while proc.poll() is None:
                time.sleep(0.1 if timeout else 1)
                if timeout and time.monotonic() - started > timeout:
                    raise RuntimeError("Command exceeded preflight timeout: " + str(logfile))
                if time.monotonic() - last > 60:
                    print("IN_PROGRESS=" + str(logfile) +
                          "; bytes=" + str(Path(logfile).stat().st_size), flush=True)
                    last = time.monotonic()
        finally:
            stop_process(proc)
            manifest["commands"][-1].update(return_code=proc.returncode, ended=stamp())
            save_progress(manifest)
    if proc.returncode:
        with Path(logfile).open("rb") as f:
            f.seek(max(0, Path(logfile).stat().st_size - 16000))
            print(f.read().decode(errors="replace"), file=sys.stderr)
        raise RuntimeError("Command failed; outputs retained: " + str(logfile))

def runtime_env(original, temporary, build, jobs, tools):
    env = dict(original)
    sbt_props = " ".join([
        "-Dsbt.ivy.home=" + str(OUT / "cache/ivy2"),
        "-Dsbt.global.base=" + str(OUT / "cache/sbt"),
        "-Dsbt.boot.directory=" + str(OUT / "cache/sbt/boot"),
        "-Dsbt.offline=true", "-Dsbt.server.autostart=false"])
    env.update({
        # Make invokes verilator/firtool/etc. by name. The inherited PATH puts
        # Conda's different Verilator before the pinned Nix tool. Pin the
        # actual build-time resolution, not just the --version command.
        "PATH": str(build / "tool-bin") + ":" + original["PATH"],
        "HOME": os.environ.get("HOME", "/home/guozh"), "LANG": "C.UTF-8", "LC_ALL": "C.UTF-8",
        "TMPDIR": str(temporary), "TMP": str(temporary), "TEMP": str(temporary),
        "PYTHONDONTWRITEBYTECODE": "1", "GIT_OPTIONAL_LOCKS": "0",
        "GIT_CONFIG_NOSYSTEM": "1", "GIT_CONFIG_GLOBAL": "/dev/null",
        "XDG_CACHE_HOME": str(OUT / "cache/xdg"),
        "XDG_CONFIG_HOME": str(OUT / "cache/config"),
        "XDG_DATA_HOME": str(OUT / "cache/data"),
        "COURSIER_CACHE": str(OUT / "cache/coursier/v1"),
        "SBT_OPTS": sbt_props,
        "CCACHE_DISABLE": "1", "CCACHE_DIR": str(OUT / "cache/ccache"),
        "SLOWDOWN_SBT_TARGET": str(build / "scala"),
        "SLOWDOWN_SBT_JAR": tools["sbt_jar"],
        "SLOWDOWN_SBT_LAYOUT": str(build / "sbt_layout.json"),
        "SLOWDOWN_EXPECT_TOOLS": json.dumps(tool_aliases(tools), sort_keys=True),
        "SLOWDOWN_NATIVE_ZLIB": tools["native_zlib"],
        "SLOWDOWN_HOST_NETNS": os.readlink("/proc/self/ns/net"),
        "MAKEFLAGS": "", "MFLAGS": "",
        "JAVA_TOOL_OPTIONS": " ".join([
            "-Xmx8G", "-Xss8M", "-XX:-UsePerfData", "-XX:ActiveProcessorCount=" + str(jobs),
            "-Dsbt.task.cpus=" + str(jobs), "-Dsbt.supershell=false", "-Dsbt.color=false",
            "-Dsbt.log.noformat=true", "-Dsbt.server.autostart=false", "-Dsbt.offline=true",
            "-Dlog4j2.disable.jmx=true", "-Djava.io.tmpdir=" + str(temporary),
            "-Duser.home=" + str(OUT / "cache/java-home"),
            "-Dsbt.ivy.home=" + str(OUT / "cache/ivy2"),
            "-Dsbt.global.base=" + str(OUT / "cache/sbt"),
            "-Dsbt.boot.directory=" + str(OUT / "cache/sbt/boot"),
            "-Dcoursier.cache=" + str(OUT / "cache/coursier/v1")])})
    return env


def tool_aliases(tools):
    names = ("java", "make", "verilator", "firtool", "dtc", "jq", "perl",
             "riscv64-unknown-elf-gcc", "riscv64-unknown-elf-objcopy", "cc", "gcc", "g++")
    return dict({name: tools[name] for name in names}, **{"c++": tools["cxx"]})


def prepare_tool_bin(build, tools):
    directory = build / "tool-bin"
    directory.mkdir()
    for name, target in tool_aliases(tools).items():
        if not Path(target).is_file() or not os.access(target, os.X_OK):
            raise RuntimeError("Pinned tool is not executable: " + name + ": " + target)
        (directory / name).symlink_to(target)


def cache_and_mounts(build):
    # Byte copies of dependency caches and SBT meta-build inputs only. Current
    # hardware source is read directly from CURRENT, not copied or hardlinked.
    for rel in ("sbt/boot", "coursier/v1"):
        dst = OUT / "cache" / rel
        if not dst.exists():
            dst.parent.mkdir(parents=True, exist_ok=True)
            # An interrupted copy must never masquerade as a usable cache.
            stage = dst.with_name(dst.name + ".copy-" + uuid.uuid4().hex[:8])
            shutil.copytree(BASELINE / "cache" / rel, stage, symlinks=True)
            os.rename(stage, dst)
    # SBT resolves local ProjectRefs BEFORE explicit project target settings.
    # A read-only local build root causes it to copy the entire source tree to
    # staging, including unrelated broken workload links. Give only those root
    # directory inodes private writable backing, with all source entries RO.
    mounts, layout = local_build_mounts(CURRENT, build)
    record(build / "sbt_layout.json", layout)
    record(build / 'sbt_project_plan.json', build_plan(CURRENT, build / 'scala'))
    projects, local_targets = [], []
    for directory, dirs, files in os.walk(CURRENT, followlinks=False):
        if "target" in dirs:
            local_targets.append(Path(directory) / "target")
        dirs[:] = [d for d in dirs if d not in SKIP]
        path = Path(directory)
        if path.name == "project":
            projects.append(path)
            dirs[:] = []
    for n, path in enumerate(sorted(projects)):
        dst = build / "sbt-meta" / str(n)
        shutil.copytree(path, dst, symlinks=True,
                        ignore=shutil.ignore_patterns("target", ".git", ".bloop", ".bsp"))
        mounts.append((dst, path))
    # Some SBT plugins touch the root target during build load, before the
    # scoped target override. Back it by a fresh external directory as well.
    root_target = build / "sbt-load-target"
    root_target.mkdir()
    if not (CURRENT / "target").is_dir():
        raise RuntimeError("Missing target mountpoint; refusing writes to Current source")
    mounts.append((root_target, CURRENT / "target"))
    # Keep other existing target mountpoints private as well. This covers
    # plugin load-time caches before explicit target settings run. Main source
    # files remain read directly at their original paths.
    for n, path in enumerate(sorted(local_targets)):
        if path == CURRENT / "target" or any(project in path.parents for project in projects):
            continue
        dst = build / "sbt-load-targets" / str(n)
        dst.mkdir(parents=True)
        mounts.append((dst, path))
    return mounts


def environment_preflight(build, env, temporary, tools, manifest, mounts):
    """Batch independent infrastructure checks; no build or SBT project load."""
    report = {"sandbox_policy": POLICY, "checks": {}, "errors": [],
              "hardware_generation": "NOT_EXECUTED", "compilation": "NOT_EXECUTED",
              "sbt_project_load": "NOT_EXECUTED", "simulation": "NOT_EXECUTED"}
    versions = {}
    # Exercise the same name lookup used by Make, including executable wrapper
    # behavior through tool-bin, instead of only probing absolute tool paths.
    commands = [(name, ["c++" if name == "cxx" else name, option]) for name, option in [
        ("java", "-version"), ("make", "--version"), ("verilator", "--version"),
        ("firtool", "--version"), ("cc", "--version"), ("cxx", "--version"),
        ("riscv64-unknown-elf-gcc", "--version"),
        ("riscv64-unknown-elf-objcopy", "--version"), ("dtc", "--version"),
        ("jq", "--version"), ("perl", "-v")]]
    commands += [("runtime_probe", ["/usr/bin/python3", "-I", "-B", str(OUT / "scripts/runtime_probe.py")]),
                 ("sbt_adapter_command", ["/usr/bin/python3", "-I", "-B",
                                          str(OUT / "scripts/sbt_external.py"), "--print-command"])]
    for name, argv in commands:
        log = build / (name + ".preflight.log")
        try:
            invoke(argv, build, log, env, temporary, tools, manifest, mounts, timeout=30)
            report["checks"][name] = {"status": "PASS", "log": str(log)}
            if name in tools:
                versions[name] = {"path": tools[name], "sha256": sha(tools[name]),
                                  "output": log.read_text(errors="replace")}
        except Exception as exc:
            report["checks"][name] = {"status": "FAIL", "log": str(log), "error": str(exc)}
            report["errors"].append(name + ": " + str(exc))
    # Inspect launcher ZIP and copied dependency JAR presence without running
    # SBT: even `sbt --version` may load/compile the meta-build.
    try:
        with zipfile.ZipFile(tools["sbt_jar"]) as jar:
            jar.getinfo("xsbt/boot/Boot.class")
        cache_counts = {}
        for rel in ("sbt/boot", "coursier/v1"):
            source = BASELINE / "cache" / rel
            target = OUT / "cache" / rel
            jars = list(source.rglob("*.jar"))
            if not jars:
                raise RuntimeError("Baseline dependency cache is empty: " + rel)
            missing = [str(p.relative_to(source)) for p in jars
                       if not (target / p.relative_to(source)).is_file() or
                       (target / p.relative_to(source)).stat().st_size != p.stat().st_size]
            if missing:
                raise RuntimeError("Incomplete private dependency cache " + rel + ": " + ", ".join(missing))
            cache_counts[rel] = len(jars)
        versions["sbt"] = {"version": (CURRENT / "project/build.properties").read_text().strip(),
                           "launcher": tools["sbt_jar"], "sha256": sha(tools["sbt_jar"])}
        report["checks"]["sbt_static_dependencies"] = {
            "status": "PASS", "jar_counts": cache_counts,
            "scope": "launcher ZIP header/class and copied JAR presence/size; not a dependency-resolution proof"}
    except Exception as exc:
        report["checks"]["sbt_static_dependencies"] = {"status": "FAIL", "error": str(exc)}
        report["errors"].append("sbt_static_dependencies: " + str(exc))
    report["status"] = "FAIL" if report["errors"] else "PASS"
    record(build / "environment_preflight.json", report)
    record(build / "tool_versions.json", versions)
    manifest["environment_preflight"] = report
    manifest["tool_versions"] = versions
    save_progress(manifest)
    if report["errors"]:
        raise RuntimeError("Environment preflight failed (all independent checks completed); see " +
                           str(build / "environment_preflight.json"))
    return report


def model_identity(generated):
    entries = {}
    for p in sorted(generated.rglob("*")):
        if p.is_file() and (p.suffix in {".v", ".sv", ".fir", ".json", ".f", ".img"}):
            entries[str(p.relative_to(generated))] = {"size": p.stat().st_size, "sha256": sha(p)}
    if not any(k.endswith((".v", ".sv")) for k in entries):
        raise RuntimeError("No generated RTL found")
    return {"files": entries, "sha256": digest(entries)}

def run_simulator(argv, directory, env, temporary, tools, manifest):
    wrapped = sandbox(argv, directory, env, temporary, tools)
    manifest["commands"].append({"argv": list(map(str, argv)), "sandbox_argv": wrapped,
                                "cwd": str(directory), "started": stamp()})
    save_progress(manifest)
    (directory / "command.txt").write_text(shlex.join(list(map(str, argv))) + "\n")
    print("PHASE=SIMULATION\nRUN_DIRECTORY=" + str(directory), flush=True)
    proc = subprocess.Popen(wrapped, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                            stdin=subprocess.DEVNULL, env={"PATH": "/usr/bin:/bin"})
    sel = selectors.DefaultSelector()
    logs = [open(directory / "stdout.log", "xb"), open(directory / "stderr.log", "xb")]
    sel.register(proc.stdout, selectors.EVENT_READ, logs[0])
    sel.register(proc.stderr, selectors.EVENT_READ, logs[1])
    last = time.monotonic()
    try:
        with (directory / "test.log").open("xb") as combined:
            while sel.get_map():
                for key, _ in sel.select(timeout=1):
                    data = os.read(key.fileobj.fileno(), 65536)
                    if data:
                        key.data.write(data); key.data.flush()
                        combined.write(data)
                    else:
                        sel.unregister(key.fileobj)
                if time.monotonic() - last > 60:
                    print("SIMULATION_IN_PROGRESS=" + str(directory), flush=True)
                    last = time.monotonic()
        rc = proc.wait()
    except BaseException:
        stop_process(proc)
        raise
    finally:
        sel.close()
        for f in logs:
            f.close()
    manifest["commands"][-1].update(return_code=rc, ended=stamp())
    return rc

def roi_result(directory, rc, descriptor):
    errors = []
    required = {pat: False for pat in descriptor["required_pass_patterns"]}
    matches = []
    for file in ("stdout.log", "stderr.log"):
        # Inspect streaming lines; verbose simulator logs may exceed RAM.
        with (directory / file).open(errors="replace") as f:
            for line in f:
                if file == "stdout.log":
                    for pat in required:
                        required[pat] |= bool(re.search(pat, line))
                    roi_match = re.fullmatch(r"\[ROI\] hart=0 start=(\d+) stop=(\d+) cycles=(\d+)\s*", line)
                    if roi_match and len(matches) < 3:
                        matches.append(roi_match.groups())
                if len(errors) < 10 and any(re.search(pat, line) for pat in descriptor["failure_patterns"]):
                    errors.append("failure marker: " + line.strip()[:350])
    for pat, seen in required.items():
        if not seen:
            errors.append("missing PASS marker: " + pat)
    if len(matches) != 1:
        errors.append("exactly one complete hart0 ROI marker required")
    result = {"comparison": "CURRENT_RUN_NOT_COMPARABLE", "baseline_roi_cycles": BASELINE_ROI,
              "elf_sha256": ELF_SHA, "loadmem_sha256": LOADMEM_SHA,
              "simulator_exit_code": rc, "errors": errors,
              "cache_package_dram_drain": "UNRESOLVED",
              "old_current_RUN_PROVENANCE": "UNRESOLVED"}
    result["baseline_RUN_PROVENANCE"] = "UNRESOLVED"
    result["baseline_correctness_scope"] = "expected software markers only; full cache/package/DRAM drain unresolved"
    if rc != 0:
        errors.append("simulator returned nonzero")
    if matches:
        start, stop, cycles = map(int, matches[0])
        if stop <= start or stop - start != cycles:
            errors.append("inconsistent ROI arithmetic")
        result.update(start_cycle=start, stop_cycle=stop, current_roi_cycles=cycles)
    ensure_inputs()
    if not errors and len(matches) == 1:
        delta = cycles - BASELINE_ROI
        result.update(comparison="SAME_SOFTWARE_ROI_COMPARABLE", delta_cycles=delta,
                      slowdown_percent=delta / BASELINE_ROI * 100,
                      ratio=cycles / BASELINE_ROI,
                      interpretation="whole Current-vs-b3 implementation/config comparison; not an isolated protection-mechanism cost")
    return result

def hierarchy_check(path):
    names = []
    meta = None
    for row in Path(path).read_text().splitlines():
        fields = row.split("\t")
        if fields[0] == "META":
            meta = {"start_tick": int(fields[1]), "end_tick": int(fields[2]),
                    "timescale_exponent": int(fields[3])}
        if fields[0] == "H" and len(fields) == 4:
            names.append(fields[3])
    groups = json.loads((OUT / "manifests/required_signal_groups.json").read_text())
    missing = {group: [token for token in tokens
                       if not any(re.search(r"(^|\.)" + re.escape(token) +
                                            r"(_\d+)?(\s|\[|$)", name)
                                  for name in names)]
               for group, tokens in groups.items()}
    missing = {k: v for k, v in missing.items() if v}
    return {"status": "TRACE_INCOMPLETE" if missing else "TRACE_HIERARCHY_COMPLETE",
            "missing": missing, "selected_names": len(names), "time": meta,
            "transition_visibility": "requires offline event analysis; hierarchy alone is insufficient"}

def execute(args):
    check = static_check(args.min_free_gib)
    prepared, original_env, tools = identity_check()
    prefix = "current_preflight_" if args.preflight_only else "current_"
    run_id = prefix + datetime.datetime.now().strftime("%Y%m%d_%H%M%S") + "_" + uuid.uuid4().hex[:8]
    directory = OUT / "runs" / run_id
    build = OUT / "build" / run_id
    directory.mkdir(); build.mkdir()
    temporary = Path(tempfile.mkdtemp(prefix="t", dir=OUT / "tmp"))
    if len(os.fsencode(temporary / ".sbt/sbt-socket-18446744073709551615/sbt-load.sock")) >= 108:
        raise RuntimeError("Private Java temporary socket path is too long")
    env = runtime_env(original_env, temporary, build, args.jobs, tools)
    env["SLOWDOWN_SOURCE_HASHES"] = json.dumps({str(ROOT / rel): item["sha256"]
        for rel, item in prepared["source_inventory"]["files"].items()}, sort_keys=True)
    manifest = {"schema": 1, "kind": "environment_preflight" if args.preflight_only else "current_same_binary_gapbs512", "start": stamp(),
                "result": "IN_PROGRESS", "RUN_PROVENANCE": "UNRESOLVED",
                "sandbox_policy": POLICY,
                "old_current_RUN_PROVENANCE": "UNRESOLVED", "git_head": prepared["git_head"],
                "current_source_digest": prepared["source_digest"], "config": "chipyard.v1Config",
                "source_preparation": str(PREP), "source_preparation_sha256": sha(PREP),
                "preexisting_diff_sha256": sha(OUT / "manifests/current_preexisting_diff.patch"),
                "trace_patch_sha256": sha(OUT / "manifests/current_trace_only.patch"),
                "software": {"elf": str(ELF), "elf_sha256": ELF_SHA,
                             "loadmem": str(LOADMEM), "loadmem_sha256": LOADMEM_SHA},
                "baseline": prepared["baseline_identity"], "environment": env,
                "jobs": args.jobs, "seed": args.seed, "max_cycles": args.max_cycles,
                "run_directory": str(directory), "build_directory": str(build),
                "temporary": str(temporary), "commands": [], "preflight": check,
                "exit_policy": "existing Current STAGE1_EXIT_PORTS: host success and stage1_l1_drained; cache/package/DRAM drain not independently proven"}
    path = directory / "run_manifest.json"
    record(path, manifest)
    try:
        print("PHASE=PREFLIGHT\nRUN_DIRECTORY=" + str(directory), flush=True)
        prepare_tool_bin(build, tools)
        mounts = cache_and_mounts(build)
        for rel in ("java-home", "ivy2", "xdg", "config", "data", "ccache"):
            (OUT / "cache" / rel).mkdir(parents=True, exist_ok=True)
        manifest["sbt_meta_mounts"] = [{"backing": str(entry[0]), "source_virtual_path": str(entry[1]),
                                        "mode": entry[2] if len(entry) == 3 else "rw"} for entry in mounts]
        manifest["sbt_layout"] = {"path": str(build / "sbt_layout.json"),
                                  "sha256": sha(build / "sbt_layout.json")}
        record(path, manifest)
        environment_preflight(build, env, temporary, tools, manifest, mounts)
        identity_check()
        if args.preflight_only:
            manifest["result"] = "ENVIRONMENT_PREFLIGHT_PASSED"
            print("ENVIRONMENT_PREFLIGHT=PASS\nBUILD_AND_SIMULATION=NOT_EXECUTED\nRUN_MANIFEST=" + str(path), flush=True)
            return 0
        descriptor = ensure_inputs()
        gtkwave = Path(tools["gtkwave"])
        reader = build / "fst_extract"
        native = Path(tools["native_zlib"])
        compile_reader = [tools["cc"], "-O2", '-DFST_CONFIG_INCLUDE="fst_config.h"',
                          "-I" + str(gtkwave), "-I" + str(native / "include"),
                          str(OUT / "scripts/fst_extract.c"), str(gtkwave / "fstapi.c"),
                          str(gtkwave / "fastlz.c"), str(gtkwave / "lz4.c"),
                          "-L" + str(native / "lib"), "-Wl,-rpath," + str(native / "lib"),
                          "-lz", "-o", str(reader)]
        invoke(compile_reader, build, build / "fst_reader_build.log",
               env, temporary, tools, manifest)
        manifest["fst_reader"] = {"path": str(reader), "sha256": sha(reader)}
        generated = build / "generated"
        sim_dir = build / "verilator"; sim_dir.mkdir()
        (sim_dir / "Makefile").symlink_to(CURRENT / "sims/verilator/Makefile")
        dram = build / "dramsim"
        shutil.copytree(CURRENT / "tools/DRAMSim2", dram, symlinks=True,
                        ignore=shutil.ignore_patterns("*.o", "*.a", "*.so", "results", ".git"))
        make = [tools["make"], "-C", str(sim_dir), "-f", str(CURRENT / "sims/verilator/Makefile"),
                "base_dir=" + str(CURRENT), "sim_dir=" + str(sim_dir),
                "gen_dir=" + str(generated), "build_dir=" + str(generated),
                "output_dir=" + str(build / "make-output"), "dramsim_dir=" + str(dram),
                "CONFIG=v1Config", "VERILATOR_FST_MODE=1", "VERILATOR_THREADS=1",
                "EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS", "JAVA_TMP_DIR=" + str(temporary),
                "SBT_BIN=/usr/bin/python3 -I -B " + str(OUT / "scripts/sbt_external.py"),
                "CHIPYARD_ENV_PREFIX=" + tools["native_zlib"],
                "CC=" + env["CC"], "CXX=" + env["CXX"], "-j" + str(args.jobs)]
        for stage, target in [("RTL_GENERATION", "verilog"), ("VERILATOR_BUILD", "debug")]:
            print("PHASE=" + stage, flush=True)
            record(path, manifest)
            invoke(make + [target], sim_dir, build / (stage.lower() + ".log"),
                   env, temporary, tools, manifest, mounts)
            identity_check()
        model = model_identity(generated)
        record(build / "generated_identity.json", model)
        simulator = sim_dir / "simulator-chipyard-v1Config-debug"
        if not simulator.is_file() or not os.access(simulator, os.X_OK):
            raise RuntimeError("Expected independently built simulator not found")
        manifest.update(generated_model_sha256=model["sha256"],
                        generated_identity=str(build / "generated_identity.json"),
                        simulator=str(simulator), simulator_sha256=sha(simulator))
        record(path, manifest)
        waveform = directory / "waveform.fst"
        argv = [str(simulator), "-v", str(waveform), "-s", str(args.seed),
                "+cycle-count", "+verbose", "+permissive", "+dramsim",
                "+dramsim_ini_dir=" + str(CURRENT / "generators/testchipip/src/main/resources/dramsim2_ini"),
                "+max-cycles=" + str(args.max_cycles), "+loadmem=" + str(LOADMEM),
                "+loadmem_addr=80000000", "+permissive-off", str(ELF)]
        rc = run_simulator(argv, directory, env, temporary, tools, manifest)
        identity_check()
        manifest["exit_status"] = rc
        roi = roi_result(directory, rc, descriptor)
        record(directory / "roi.json", roi)
        manifest["roi"] = roi
        if not waveform.is_file() or waveform.stat().st_size < 1024:
            raise RuntimeError("Waveform missing or empty; valid ROI alone does not make trace complete")
        inventory = directory / "waveform_hierarchy.txt"
        invoke([str(reader), str(waveform), "hierarchy"], directory, inventory,
               env, temporary, tools, manifest)
        trace = hierarchy_check(inventory)
        record(directory / "trace_completeness.json", trace)
        manifest["trace"] = trace
        manifest["artifacts"] = {name: {"path": str(directory / name),
                                      "size": (directory / name).stat().st_size,
                                      "sha256": sha(directory / name)}
                                 for name in ["test.log", "stdout.log", "stderr.log", "command.txt",
                                              "waveform.fst", "roi.json", "waveform_hierarchy.txt"]}
        manifest["RUN_PROVENANCE"] = "COMPLETE_FOR_THIS_NEW_RUN_IDENTITY_ONLY"
        manifest["correctness_scope"] = "software markers only; hierarchy check is not correctness validation"
        if roi["comparison"] != "SAME_SOFTWARE_ROI_COMPARABLE":
            raise RuntimeError("CURRENT_RUN_NOT_COMPARABLE; see roi.json")
        manifest["result"] = "SUCCEEDED" if trace["status"] == "TRACE_HIERARCHY_COMPLETE" else "TRACE_INCOMPLETE"
        print(f"Baseline ROI : {BASELINE_ROI}\nCurrent ROI  : {roi['current_roi_cycles']}\n"
              f"Delta        : {roi['delta_cycles']}\nSlowdown     : {roi['slowdown_percent']:.3f} %\n"
              f"Ratio        : {roi['ratio']:.4f} x", flush=True)
        print("TRACE_STATUS=" + trace["status"], flush=True)
        print("RUN_MANIFEST=" + str(path), flush=True)
        return 0 if manifest["result"] == "SUCCEEDED" else 3
    except BaseException as exc:
        manifest.update(result="INTERRUPTED" if isinstance(exc, (KeyboardInterrupt, SystemExit)) else "FAILED",
                        error=str(exc) or type(exc).__name__)
        print("EXPERIMENT_FAILED=" + str(exc), file=sys.stderr, flush=True)
        return 1
    finally:
        manifest["end"] = stamp()
        record(path, manifest)

def main():
    p = argparse.ArgumentParser(description=__doc__)
    mode = p.add_mutually_exclusive_group()
    mode.add_argument("--static-check", action="store_true",
                   help="identity/path/hash checks only; never executes build tools")
    mode.add_argument("--preflight-only", action="store_true",
                      help="sandboxed tool version/tmp/path checks only; no SBT load, compilation or simulation")
    p.add_argument("--jobs", type=int, default=1)
    p.add_argument("--seed", type=int, default=1)
    p.add_argument("--max-cycles", type=int, default=500000000)
    p.add_argument("--min-free-gib", type=int, default=30)
    args = p.parse_args()
    if args.jobs < 1 or args.max_cycles < 1 or args.min_free_gib < 0:
        p.error("invalid resource limit")
    if args.static_check:
        result = static_check(args.min_free_gib)
        target = OUT / "manifests" / ("static_preflight_" + uuid.uuid4().hex[:10] + ".json")
        record(target, result)
        print(json.dumps(result, ensure_ascii=False, indent=2))
        return 0
    def interrupted(signum, frame):
        raise SystemExit(128 + signum)
    signal.signal(signal.SIGTERM, interrupted)
    with (OUT / "manifests/experiment.lock").open("a") as lock:
        try:
            fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            raise RuntimeError("Another slowdown launcher owns the experiment cache")
        return execute(args)

if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except Exception as exc:
        # Preserve early identity failures too; no run directory exists yet.
        try:
            target = OUT / "manifests" / ("preflight_failure_" + uuid.uuid4().hex[:10] + ".json")
            record(target, {"status": "FAIL", "checked_at": stamp(), "error": str(exc),
                            "hardware_generation": "NOT_EXECUTED", "compilation": "NOT_EXECUTED",
                            "simulation": "NOT_EXECUTED"})
            print("PREFLIGHT_REPORT=" + str(target), file=sys.stderr)
        except Exception:
            pass
        print("PREFLIGHT_FAILED=" + str(exc), file=sys.stderr)
        raise SystemExit(1)
