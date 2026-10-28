#!/usr/bin/env python3
"""Opt3 fused checker classification (retains Opt1, Opt2 and Opt2b). Default execution is USER-ONLY and expensive.

--static-check performs identity/path/hash checks only. It cannot reach make,
SBT, compilers, native probes, or the simulator.
--preflight-only additionally executes sandboxed tool VERSION commands and
temporary-file probes, then stops before any compilation or SBT project load.
"""
import argparse
import datetime
import difflib
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
OUT = ROOT / "slowdown" / "optimization_3_checker"
CURRENT = ROOT / "chipyard"
BASELINE = ROOT / "baseline"
PREP = OUT / "manifests/preparation.json"
ELF = BASELINE / "software_common_builds/gapbs512_20261023_03/test.riscv"
LOADMEM = ELF.with_name("test.loadmem_hex")
ELF_SHA = "da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c"
LOADMEM_SHA = "f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad"
BASELINE_ROI = 1001675
REFERENCE_CURRENT_ROI = 4734881
REFERENCE_CURRENT_RUN = ROOT / "slowdown/runs/current_20261023_222009_3cebcab2"
BASE_SOURCE_HEAD = "ab4f1f48811f9a4037b1f980fa94ddf611d9cb07"
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

def optimization_patch():
    """Return the complete source delta relative to the reviewed base.

    This is deliberately independent of the worktree/index state and of a
    later commit containing identical source bytes.  The user may commit the
    prepared implementation before running it without silently changing the
    hardware identity.
    """
    subprocess.check_call(["git", "cat-file", "-e", BASE_SOURCE_HEAD + "^{commit}"],
                          cwd=ROOT, env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"),
                          stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    extras = ("chipyard/generators/rocket-chip/src/main/scala/util/SafeChainObservation.scala",
              "chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v")
    patch = subprocess.check_output(
        ["git", "diff", "--no-ext-diff", "--no-textconv", BASE_SOURCE_HEAD,
         "--binary", "--", "chipyard", *[":(exclude)"+p for p in extras]], cwd=ROOT,
        env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    for rel in extras:
        patch += ''.join(difflib.unified_diff([], (ROOT/rel).read_text().splitlines(True),
                         fromfile='/dev/null', tofile='b/'+rel)).encode()
    return patch



def source_inventory():
    """Fingerprint reviewed Safe-chain observation source content, not Git checkout state."""
    untracked = subprocess.check_output(
        ["git", "ls-files", "--others", "--exclude-standard", "-z", "--", "chipyard"],
        cwd=ROOT, env=dict(os.environ, GIT_OPTIONAL_LOCKS="0"))
    extras = ("chipyard/generators/rocket-chip/src/main/scala/util/SafeChainObservation.scala",
              "chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v")
    unexpected = {os.fsdecode(rel) for rel in untracked.split(b"\0") if rel} - set(extras)
    if unexpected:
        raise RuntimeError("Unreviewed untracked hardware input: " + repr(sorted(unexpected)))
    untracked_files = {rel: sha(ROOT/rel) for rel in extras}
    files = {}
    for rel in ("generators/boom/src/main/scala/lsu/dcache.scala",
                "generators/rocket-chip/.gitignore",
                "generators/boom/src/main/scala/lsu/mshrs.scala",
                "generators/boom/src/main/scala/exu/rob.scala",
                "generators/boom/src/main/scala/exu/core.scala",
                "generators/rocket-chip/src/main/scala/r/R_IC.scala",
                "generators/rocket-chip/src/main/scala/guardiancouncil/ght_sch.scala",
                "generators/rocket-chip/src/main/scala/rocket/RocketCore.scala",
                "generators/rocket-chip/src/main/scala/rocket/Frontend.scala",
                "generators/rocket-chip/src/main/scala/r/R_ICSL.scala",
                "generators/rocket-chip/src/main/scala/r/R_LSL.scala",
                "generators/rocket-chip/src/main/scala/r/R_BJL.scala",
                "generators/boom/src/main/scala/lsu/phase1.scala",
                "generators/rocket-chip/src/main/scala/util/SafeChainObservation.scala",
                "generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v",
                "generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala",
                "generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala",
                "generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala",
                "generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala",
                "generators/chipyard/src/main/scala/config/RocketConfigs.scala",
                "sims/verilator/Makefile", "common.mk", "variables.mk",
                "build.sbt", "project/plugins.sbt",
                "generators/chipyard/src/main/resources/csrc/emulator.cc",
                "generators/chipyard/src/main/resources/csrc/stage1_exit.h"):
        path = CURRENT / rel
        files["chipyard/" + rel] = {"sha256": sha(path), "size": path.stat().st_size}
    patch = optimization_patch()
    result = {"base_source_head": BASE_SOURCE_HEAD,
              "base_to_optimization_patch_sha256": hash_bytes(patch),
              "untracked_files": untracked_files,
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
    errors = []
    try:
        runtime_dependencies()
    except Exception as exc:
        errors.append('Capture/analysis dependencies: ' + str(exc))
    try:
        checked_resource_inventory(build_plan(CURRENT, OUT / 'build/static-plan/scala'),
                                   OUT / 'manifests/sbt_resource_inputs.json')
    except Exception as exc:
        errors.append('SBT/BlackBox input closure: ' + str(exc))
    try:
        inventory = source_inventory()
    except Exception as exc:
        inventory = None
        errors.append('Current source inventory: ' + str(exc))
    try:
        ensure_inputs()
    except Exception as exc:
        errors.append('Software identity: ' + str(exc))
    env, tools = tool_config()
    for name, path in tools.items():
        q = Path(path)
        if not q.exists():
            errors.append('Missing tool/dependency ' + name + ': ' + path)
        elif name not in ('sbt_jar', 'gtkwave', 'native_zlib') and not os.access(q, os.X_OK):
            errors.append('Tool is not executable ' + name + ': ' + path)
    config = CURRENT / 'generators/chipyard/src/main/scala/config/RocketConfigs.scala'
    if 'class v1Config extends Config(' not in config.read_text():
        errors.append('Expected Current chipyard.v1Config not found')
    for rel in ('build', 'runs', 'tmp', 'cache', 'manifests'):
        directory = OUT / rel
        if not directory.is_dir() or directory.is_symlink():
            errors.append('Expected local output directory: ' + str(directory))
    if OUT.resolve() != OUT:
        errors.append('slowdown output root must not be a symlink')
    if errors:
        raise RuntimeError('Identity/path preflight failures:\n- ' + '\n- '.join(errors))
    if PREP.is_file():
        frozen = json.loads(PREP.read_text())
        if inventory['source_digest'] != frozen['source_digest']:
            raise RuntimeError('Hardware differs from reviewed Opt3 preparation; do not silently run changed source')
    else:
        raise RuntimeError('Reviewed Opt3 preparation manifest missing')
    return inventory, env, tools


def runtime_dependencies():
    # Imports are pure Python and must succeed before any build or attempt
    # marker. The previous launcher discovered a missing capture module only
    # after its expensive build and after consuming the simulation guard.
    from compact_capture import capture
    analysis_path = str(ROOT/'slowdown/optimization_3_checker/analysis')
    if analysis_path not in sys.path:
        sys.path.insert(0, analysis_path)
    from compact_causality import analyze_events
    from opt3_summary import extend_analysis
    if not all(callable(f) for f in (capture, analyze_events, extend_analysis)):
        raise RuntimeError('Capture/analyzer entrypoint missing')
    reference = json.loads((Path(analysis_path)/'reference_safe_chain_metrics.json').read_text())
    if (reference['performance']['measured_roi'] != 4706513 or
            reference['pending_cycles'] != 3178984 or reference['event_coverage'] != 'COMPLETE'):
        raise RuntimeError('Pinned safe-chain metrics reference missing or changed')
    from opt3_summary import load_reference
    load_reference()
    from optimization2_comparison import load_safe_chain_reference
    load_safe_chain_reference()
    return analyze_events, extend_analysis


def ensure_output_layout():
    # Empty runtime directories are intentionally absent from Git archives.
    # Recreate only this experiment's own output directories, without cleanup.
    if OUT.resolve() != OUT:
        raise RuntimeError('slowdown output root must not be a symlink')
    for name in ('build', 'runs', 'tmp', 'cache', 'manifests'):
        path = OUT/name
        if path.is_symlink():
            raise RuntimeError('Output directory cannot be a symlink: '+str(path))
        path.mkdir(parents=True, exist_ok=True)


def static_check(min_free_gib=30):
    p, env, tools = identity_check()
    free = shutil.disk_usage(OUT).free
    if free < min_free_gib * 1024**3:
        raise RuntimeError("Insufficient slowdown disk space: free bytes=" + str(free))
    resources = checked_resource_inventory(build_plan(CURRENT, OUT / 'build/static-plan/scala'),
                                           OUT / 'manifests/sbt_resource_inputs.json')
    # No make -n, SBT, Scala compilation, Java invocation, or tool probe here.
    return {"status": "PASS", "checked_at": stamp(),
            "base_source_head": p["base_source_head"],
            "config": "chipyard.v1Config", "optimization_3_checker_source_digest": p["source_digest"],
            "source_file_count": len(p["files"]),
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

def run_simulator(argv, directory, env, temporary, tools, manifest, mounts=()):
    from compact_capture import capture
    wrapped = sandbox(argv, directory, env, temporary, tools, mounts)
    manifest['commands'].append({'argv': list(map(str, argv)), 'sandbox_argv': wrapped,
        'cwd': str(directory), 'started': stamp()})
    save_progress(manifest)
    (directory / 'command.txt').write_text(shlex.join(list(map(str, argv))) + '\n')
    try:
        rc, stats = capture(wrapped, directory)
    except BaseException as exc:
        manifest['capture'] = getattr(exc, 'capture_stats', {'status': 'INCOMPLETE'})
        manifest['commands'][-1].update(return_code=getattr(exc, 'simulator_return_code', None),
                                        ended=stamp(), capture_error=str(exc))
        save_progress(manifest)
        raise
    manifest['capture'] = stats
    manifest['commands'][-1].update(return_code=rc, ended=stamp())
    save_progress(manifest)
    return rc

def roi_result(directory, rc, descriptor):
    errors = []
    required = {pat: False for pat in descriptor["required_pass_patterns"]}
    matches = []
    workload_results, drain, host_success = [], {}, False
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
                    workload = re.fullmatch(r"\[RUN\] benchmark=gapbs_bfs nodes=(\d+) source=(\d+) reached=(\d+) edges=(\d+) verified=(\d+) parent_checksum=(\d+)\s*", line)
                    if workload and len(workload_results) < 3:
                        workload_results.append(tuple(map(int, workload.groups())))
                if line.startswith('STAGE1_HOST_SUCCESS cycles='):
                    host_success = True
                if line.startswith('STAGE1_TX EXIT_DRAIN snapshot=sim_exit source='):
                    source = re.search(r'\bsource=(DCACHE|LSU)\b', line)
                    if source:
                        if source[1] in drain:
                            errors.append('duplicate exit drain snapshot: ' + source[1])
                        drain[source[1]] = {key: int(val, 16) for key, val in
                                           re.findall(r'\b([a-z][a-z0-9_]*)=([0-9a-f]+)(?=\s|$)', line)}
                if len(errors) < 10 and any(re.search(pat, line) for pat in descriptor["failure_patterns"]):
                    errors.append("failure marker: " + line.strip()[:350])
    for pat, seen in required.items():
        if not seen:
            errors.append("missing PASS marker: " + pat)
    if len(matches) != 1:
        errors.append("exactly one complete hart0 ROI marker required")
    if workload_results != [(512, 0, 512, 8192, 1, 43439728)]:
        errors.append('exactly one expected BFS architectural-result marker required')
    dcache_idle = ('s1_valid', 's2_valid', 'mshr_outstanding', 'replay_valid', 'replay_busy',
                   'replay_result_q', 'completion_q', 's3_valid', 'store_done_valid', 'wb_valid',
                   'probe_valid', 'refill_valid', 'install_active', 'completion_pending',
                   'killed_store', 'slot_reserved', 'cross_package_pending', 'pending_response',
                   'response_valid', 'mem_finish', 'mem_grant', 'mem_acquire')
    lsu_idle = ('stq_valid', 'stq_committed', 'stq_inflight', 'stq_done', 'ldq_valid',
                'ldq_pending', 'hella_pending', 'request_valid', 'force_order')
    drain_ok = host_success and all(drain.get(source, {}).get('schema') == 1 for source in ('DCACHE', 'LSU'))
    drain_ok = drain_ok and drain.get('DCACHE', {}).get('fence_ready') == 1
    drain_ok = drain_ok and all(drain.get('DCACHE', {}).get(key) == 0 for key in dcache_idle)
    drain_ok = drain_ok and all(drain.get('LSU', {}).get(key) == 0 for key in lsu_idle)
    if not drain_ok:
        errors.append('host success plus exact Stage1 L1/LSU exit quiescence evidence missing or failed')
    result = {"comparison": "SAFE_CHAIN_RUN_NOT_COMPARABLE", "baseline_roi_cycles": BASELINE_ROI,
              "reference_current_roi_cycles": REFERENCE_CURRENT_ROI,
              "reference_current_run": str(REFERENCE_CURRENT_RUN),
              "elf_sha256": ELF_SHA, "loadmem_sha256": LOADMEM_SHA,
              "simulator_exit_code": rc, "errors": errors,
              "cache_package_dram_drain": "UNRESOLVED",
              "safe_chain_RUN_PROVENANCE": "UNRESOLVED"}
    result['workload_result'] = workload_results
    result['stage1_l1_lsu_exit_drain'] = {'status': 'PASS' if drain_ok else 'FAIL',
                                        'host_success': host_success, 'snapshots': drain,
                                        'scope': 'stage1_exit.h predicate only; not full cache/package/DRAM drain'}
    result["baseline_RUN_PROVENANCE"] = "UNRESOLVED"
    result["baseline_correctness_scope"] = "expected software markers only; full cache/package/DRAM drain unresolved"
    if rc != 0:
        errors.append("simulator returned nonzero")
    if matches:
        start, stop, cycles = map(int, matches[0])
        if stop <= start or stop - start != cycles:
            errors.append("inconsistent ROI arithmetic")
        result.update(start_cycle=start, stop_cycle=stop, safe_chain_roi_cycles=cycles)
    ensure_inputs()
    if not errors and len(matches) == 1:
        delta = cycles - BASELINE_ROI
        current_delta = cycles - REFERENCE_CURRENT_ROI
        result.update(comparison="SAME_SOFTWARE_ROI_COMPARABLE", delta_cycles=delta,
                      slowdown_percent=delta / BASELINE_ROI * 100,
                      ratio=cycles / BASELINE_ROI,
                      safe_chain_vs_reference_current_delta_cycles=current_delta,
                      safe_chain_vs_reference_current_percent=current_delta / REFERENCE_CURRENT_ROI * 100,
                      improvement_cycles=REFERENCE_CURRENT_ROI-cycles,
                      roi_reduction_percent=(REFERENCE_CURRENT_ROI-cycles)/REFERENCE_CURRENT_ROI*100,
                      throughput_speedup_percent=(REFERENCE_CURRENT_ROI/cycles-1)*100,
                      interpretation="same-software ROI comparison to b3 and the pinned reference Current run; not an isolated mechanism-cost proof")
    return result


def generated_observer_audit(generated):
    # firtool --dedup may emit one Rocket module definition used by all four
    # checker cores. Count logger *instances* in the expanded TestHarness
    # hierarchy, resolving KIND from each parent's emitted RTL definition.
    # Counting .KIND text occurrences mistakes shared definitions for missing
    # hardware; accepting one KIND=6 would hide a genuinely missing checker.
    generated = Path(generated)
    counts, definitions, modules, errors = {}, {}, [], []
    module_names, input_only = set(), False
    module_pattern = r'\bmodule\s+(\w+)\b([\s\S]*?)\bendmodule\b'
    logger_pattern = (r'\bSafeChainEventLogger\s*#\s*\(\s*\.KIND\s*\(\s*'
                      r"(?:(\d+)'[sS]?([dDhH]))?([0-9a-fA-F]+)\s*\)\s*\)\s+(\w+)\s*\(")
    for path in sorted(generated.rglob('*')):
        if path.suffix not in ('.v', '.sv') or not path.is_file():
            continue
        source = re.sub(r'/\*[\s\S]*?\*/|//[^\n]*', '', path.read_text())
        for module in re.finditer(module_pattern, source):
            name, body = module[1], module[2]
            if name in module_names:
                errors.append('duplicate generated module definition '+name)
            module_names.add(name)
            if name == 'SafeChainEventLogger':
                modules.append(str(path))
                header = body.split(');', 1)[0]
                input_only = bool(re.search(r'\binput\b', header)) and not re.search(r'\b(output|inout)\b', header)
            for match in re.finditer(logger_pattern, body):
                kind = int(match[3], 16 if (match[2] or '').lower() == 'h' else 10)
                key = name, match[4]
                if key in definitions:
                    errors.append('duplicate logger definition '+'.'.join(key))
                definitions[key] = kind

    instances = []
    hierarchy = generated/'model_module_hierarchy.json'
    hierarchy_sha256 = None

    def visit(node, parents=(), parent_module=None):
        if not isinstance(node, dict) or any(not isinstance(node.get(k), str) or not node[k]
                                             for k in ('instance_name', 'module_name')):
            raise ValueError('malformed hierarchy node')
        children = node.get('instances')
        if not isinstance(children, list):
            raise ValueError('hierarchy node has no instances list')
        path = parents + (node['instance_name'],)
        if node['module_name'] == 'SafeChainEventLogger':
            key = parent_module, node['instance_name']
            if key not in definitions:
                errors.append('hierarchy logger has no matching RTL KIND: '+'.'.join(path))
            else:
                kind = definitions[key]
                counts[kind] = counts.get(kind, 0)+1
                instances.append(dict(path='.'.join(path), parent_module=parent_module, kind=kind))
        names = set()
        for child in children:
            if isinstance(child, dict):
                name = child.get('instance_name')
                if name in names:
                    raise ValueError('duplicate hierarchy instance '+'.'.join(path+(str(name),)))
                names.add(name)
            visit(child, path, node['module_name'])

    try:
        tree = json.loads(hierarchy.read_text())
        hierarchy_sha256 = sha(hierarchy)
        if not isinstance(tree, dict) or tree.get('module_name') != 'TestHarness':
            raise ValueError('expected full TestHarness hierarchy')
        visit(tree)
    except (OSError, ValueError, TypeError) as exc:
        errors.append('generated instance hierarchy unavailable/invalid: '+str(exc))
    expected = {kind: 32 if kind == 9 else 4 if kind in (3, 4, 5, 6, 11, 12, 13, 16) else 1
                for kind in range(1, 17)}
    for kind in sorted(set(expected) | set(counts)):
        if counts.get(kind, 0) != expected.get(kind, 0):
            errors.append('observer instance count KIND='+str(kind)+': expected '+
                          str(expected.get(kind, 0))+', found '+str(counts.get(kind, 0)))
    if len(modules) != 1 or not input_only:
        errors.append('input-only logger resource missing/changed')
    definition_counts = {}
    for kind in definitions.values():
        definition_counts[kind] = definition_counts.get(kind, 0)+1
    return dict(status='FAIL' if errors else 'PASS', errors=errors, kinds=sorted(counts),
                parameter_instances=counts, parameter_definition_counts=definition_counts,
                expected_instances=expected, instance_total=sum(counts.values()),
                count_basis='expanded TestHarness hierarchy joined to parent RTL logger KIND',
                hierarchy=str(hierarchy), hierarchy_sha256=hierarchy_sha256, instances=instances,
                logger_modules=modules, input_only=input_only,
                scope='generated RTL structural instances; runtime hart/footer/count/time checks remain mandatory')


def compiled_observer_audit(generated):
    required = ('SC1', 'SC_END', 'SC_OVERFLOW', 'safe-chain-events')
    found = set(); final_files = []
    for path in generated.rglob('*.cpp'):
        source = path.read_text(errors='strict')
        found.update(s for s in required if s in source)
        if 'SC_END' in source: final_files.append(str(path))
    missing = sorted(set(required)-found)
    return dict(status='FAIL' if missing or not final_files else 'PASS', missing=missing,
                footer_translation_units=final_files,
                scope='nontrace compiled model event/final strings; runtime completeness verified by every observer footer')


def refuse_second_simulation(repeat_from=None, source_digest=None):
    attempts = sorted((OUT/'runs').glob('*/SIMULATION_STARTED.json'))
    if repeat_from is None:
        if attempts:
            raise RuntimeError('One Opt3 checker full simulation already attempted; no automatic retry. '
                               'To explicitly repeat a successful run use --repeat-from RUN_ID: '+str(attempts))
        return None
    if not re.fullmatch(r'optimization_3_checker_[0-9]{8}_[0-9]{6}_[0-9a-f]{8}', repeat_from):
        raise RuntimeError('Invalid --repeat-from run ID')
    reference = OUT/'runs'/repeat_from
    guard = reference/'SIMULATION_STARTED.json'
    if not attempts or max(attempts, key=lambda p: p.stat().st_mtime_ns) != guard:
        raise RuntimeError('--repeat-from must name the latest attempted simulation; no failed-attempt bypass')
    manifest_path = reference/'run_manifest.json'
    manifest = json.loads(manifest_path.read_text())
    if manifest.get('result') != 'SUCCEEDED' or manifest.get('exit_status') != 0:
        raise RuntimeError('Only a successful completed run can authorize an explicit repetition')
    summary = manifest.get('opt3_summary', {})
    if (summary.get('validation_status') != 'OBSERVED_CHECKS_PASS' or
            summary.get('correctness', {}).get('coverage') != 'COMPLETE'):
        raise RuntimeError('Reference run has incomplete correctness/observer evidence')
    if source_digest is None or manifest.get('source_digest') != source_digest:
        raise RuntimeError('Explicit repetition requires the same reviewed hardware source')
    if (manifest['software']['elf_sha256'] != ELF_SHA or
            manifest['software']['loadmem_sha256'] != LOADMEM_SHA):
        raise RuntimeError('Reference repetition workload identity differs')
    return dict(run_id=repeat_from, manifest_sha256=sha(manifest_path),
                guard_sha256=sha(guard), policy='EXPLICIT_REPEAT_OF_SUCCESS; NO_AUTOMATIC_RETRY')


def make_argv(build, temporary, tools, env, jobs):
    return [tools['make'], '-C', str(build/'verilator'), '-f', str(CURRENT/'sims/verilator/Makefile'),
            'base_dir='+str(CURRENT), 'sim_dir='+str(build/'verilator'),
            'gen_dir='+str(build/'generated'), 'build_dir='+str(build/'generated'),
            'output_dir='+str(build/'make-output'), 'dramsim_dir='+str(build/'dramsim'),
            'CONFIG=v1Config', 'VERILATOR_THREADS=1',
            'EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS -DSAFE_CHAIN_EVENTS',
            'JAVA_TMP_DIR='+str(temporary),
            'SBT_BIN=/usr/bin/python3 -I -B '+str(OUT/'scripts/sbt_external.py'),
            'CHIPYARD_ENV_PREFIX='+tools['native_zlib'], 'CC='+env['CC'], 'CXX='+env['CXX'], '-j'+str(jobs)]


def simulation_argv(simulator, seed, max_cycles):
    # Diagnostic plusargs belong within the existing permissive block.
    # No +verbose, -v, debug target, or waveform path.
    return [str(simulator), '-s', str(seed), '+cycle-count', '+permissive',
            '+safe-chain-events', '+dramsim',
            '+dramsim_ini_dir='+str(CURRENT/'generators/testchipip/src/main/resources/dramsim2_ini'),
            '+max-cycles='+str(max_cycles), '+loadmem='+str(LOADMEM),
            '+loadmem_addr=80000000', '+permissive-off', str(ELF)]


def short_temporary():
    """Allocate a short private directory for the SBT Unix socket.

    The socket limit applies to the path visible inside the build namespace.
    Keep this directory under OUT so sandbox_support can bind it as private
    /tmp, but use a one-character leaf so the full SBT path stays below 108
    bytes. The experiment lock serializes these candidates.
    """
    for name in ('t', 'u', 'v', 'w', 'x', 'y', 'z'):
        path = OUT / 'tmp' / name
        try:
            path.mkdir()
            return path
        except FileExistsError:
            continue
    raise RuntimeError('No short private temporary directory is available')


def execute(args):
    check = static_check(args.min_free_gib)
    prepared, original_env, tools = identity_check()
    recovery = None
    if not args.preflight_only and not args.rtl_only:
        recovery = refuse_second_simulation(args.repeat_from, prepared['source_digest'])
    prefix = 'optimization_3_checker_preflight_' if args.preflight_only else ('optimization_3_checker_rtl_' if args.rtl_only else 'optimization_3_checker_')
    run_id = prefix + datetime.datetime.now().strftime('%Y%m%d_%H%M%S')+'_'+uuid.uuid4().hex[:8]
    directory, build = OUT/'runs'/run_id, OUT/'build'/run_id
    directory.mkdir(); build.mkdir()
    temporary = short_temporary()
    if len(os.fsencode(temporary/'.sbt/sbt-socket-18446744073709551615/sbt-load.sock')) >= 108:
        raise RuntimeError('Private SBT socket path too long')
    env = runtime_env(original_env, temporary, build, args.jobs, tools)
    env['SLOWDOWN_SOURCE_HASHES'] = json.dumps({str(ROOT/rel): item['sha256']
        for rel, item in prepared['files'].items()}, sort_keys=True)
    manifest = dict(schema=1, kind='optimization_3_checker_preflight' if args.preflight_only else ('optimization_3_checker_rtl_only' if args.rtl_only else 'optimization_3_checker_gapbs512'),
        start=stamp(), result='IN_PROGRESS', RUN_PROVENANCE='UNRESOLVED',
        run_git_head=git('rev-parse','HEAD'), base_source_head=BASE_SOURCE_HEAD,
        source_digest=prepared['source_digest'], source_preparation='OPT3_REVIEWED_SOURCE_INVENTORY', source_preparation_sha256=sha(PREP),
        observation_only=False, optimization_3_checker='CHECKER_FUSED_RESPONSE_CLASSIFICATION', retained_optimizations=['OPT1','OPT2_ROUND_ROBIN','OPT2B_HANDOFF'], waveform='DISABLED_NO_TRACE_BUILD',
        config='chipyard.v1Config', software=dict(elf=str(ELF), elf_sha256=ELF_SHA, loadmem=str(LOADMEM),loadmem_sha256=LOADMEM_SHA),
        run_directory=str(directory), build_directory=str(build), temporary=str(temporary),
        seed=args.seed, max_cycles=args.max_cycles, jobs=args.jobs, environment=env, commands=[], preflight=check,
        observer_overflow_recovery=None, explicit_repetition=recovery,
        exit_policy='unchanged Stage1 host success + exact L1/LSU drain; full package/cache/DRAM drain UNRESOLVED')
    save_progress(manifest)
    try:
        print('PHASE=PREFLIGHT\nRUN_DIRECTORY='+str(directory),flush=True)
        prepare_tool_bin(build,tools)
        mounts=cache_and_mounts(build)
        for rel in ('java-home','ivy2','xdg','config','data','ccache'):
            (OUT/'cache'/rel).mkdir(parents=True,exist_ok=True)
        manifest['sbt_layout'] = dict(path=str(build/'sbt_layout.json'),sha256=sha(build/'sbt_layout.json'))
        manifest['sandbox_policy'] = POLICY
        manifest['sbt_meta_mounts'] = [list(map(str,m)) for m in mounts]
        environment_preflight(build,env,temporary,tools,manifest,mounts)
        identity_check()
        if args.preflight_only:
            manifest['result']='ENVIRONMENT_PREFLIGHT_PASSED'; return 0
        descriptor=ensure_inputs()
        sim_dir=build/'verilator';sim_dir.mkdir()
        (sim_dir/'Makefile').symlink_to(CURRENT/'sims/verilator/Makefile')
        shutil.copytree(CURRENT/'tools/DRAMSim2',build/'dramsim',symlinks=True,
            ignore=shutil.ignore_patterns('*.o','*.a','*.so','results','.git'))
        make=make_argv(build,temporary,tools,env,args.jobs)
        phases = [('RTL_GENERATION','verilog')] if args.rtl_only else [('RTL_GENERATION','verilog'),('VERILATOR_BUILD','default')]
        for phase,target in phases:
            print('PHASE='+phase,flush=True)
            invoke(make+[target],sim_dir,build/(phase.lower()+'.log'),env,temporary,tools,manifest,mounts)
            identity_check()
            if phase=='RTL_GENERATION':
                audit=generated_observer_audit(build/'generated')
                record(build/'generated_observer_audit.json',audit)
                if audit['status']!='PASS': raise RuntimeError('Generated observer audit failed; simulation not started: '+repr(audit))
                if args.rtl_only:
                    manifest['result']='RTL_GENERATION_PASSED'
                    manifest['simulation']='NOT_EXECUTED'
                    print('RTL_GENERATION=PASS\nBUILD_AND_SIMULATION=NOT_EXECUTED\nRUN_MANIFEST='+str(directory/'run_manifest.json'),flush=True)
                    return 0
        audit=compiled_observer_audit(build/'generated')
        record(build/'compiled_observer_audit.json',audit)
        if audit['status']!='PASS': raise RuntimeError('Compiled observer audit failed; simulation not started: '+repr(audit))
        model=model_identity(build/'generated');record(build/'generated_identity.json',model)
        simulator=sim_dir/'simulator-chipyard-v1Config'
        if not simulator.is_file() or not os.access(simulator,os.X_OK): raise RuntimeError('Nontrace simulator missing')
        manifest.update(simulator=str(simulator),simulator_sha256=sha(simulator),generated_model_sha256=model['sha256'])
        if refuse_second_simulation(args.repeat_from, prepared['source_digest']) != recovery:
            raise RuntimeError('Prior successful-run repetition evidence changed during build; simulation refused')
        runtime_dependencies()
        if source_inventory()['source_digest'] != prepared['source_digest']:
            raise RuntimeError('Hardware source changed during build')
        # A durable guard precedes process creation. Failed capture/analysis
        # cannot authorize a second expensive simulation.
        with (directory/'SIMULATION_STARTED.json').open('x') as f:
            json.dump(dict(at=stamp(),source_digest=prepared['source_digest'],policy='NO_AUTOMATIC_RETRY',
                           explicit_repetition=recovery),f)
        rc=run_simulator(simulation_argv(simulator,args.seed,args.max_cycles),directory,env,temporary,tools,manifest)
        manifest['exit_status']=rc
        current, _, _ = identity_check()
        if current['source_digest'] != prepared['source_digest']:
            raise RuntimeError('Hardware source changed while simulation was active')
        roi=roi_result(directory,rc,descriptor);record(directory/'roi.json',roi);manifest['roi']=roi
        events=directory/'safe_chain_events.tsv'
        manifest['events']=dict(path=str(events),size=events.stat().st_size,sha256=sha(events))
        if 'start_cycle' not in roi or 'stop_cycle' not in roi: raise RuntimeError('Software ROI missing; ROOT_CAUSE_STILL_UNRESOLVED; no retry')
        result_out=directory/'analysis'
        sys.path.insert(0,str(ROOT/'slowdown/optimization_3_checker/analysis'))
        from compact_causality import analyze_events
        summary=analyze_events(events,roi,result_out)
        _, extend = runtime_dependencies()
        manifest['opt3_summary'] = extend(events, roi, result_out)
        record(directory/'opt3_summary.json', manifest['opt3_summary'])
        valid=(roi['comparison']=='SAME_SOFTWARE_ROI_COMPARABLE' and summary['coverage']=='COMPLETE'
               and manifest['opt3_summary']['validation_status']=='OBSERVED_CHECKS_PASS')
        manifest['decision']=summary['decision'] if valid else 'ROOT_CAUSE_STILL_UNRESOLVED'
        record(directory/'decision.json',dict(decision=manifest['decision'],activity_decision=summary['decision'],
            valid_software_roi=roi['comparison']=='SAME_SOFTWARE_ROI_COMPARABLE',coverage=summary['coverage'],
            implementation_authorization='USER_REQUESTED_OPT3_CHECKER; runtime performance is measured, not presumed',
            ROB_critical_path_cycles='UNRESOLVED',avoidable_cycles='UNRESOLVED'))
        manifest['result']='SUCCEEDED' if valid else 'EVIDENCE_INCOMPLETE_FINISH_OFFLINE'
        print('ROOT_CAUSE_DECISION='+manifest['decision']+'\nRUN_MANIFEST='+str(directory/'run_manifest.json'),flush=True)
        return 0 if valid else 3
    except BaseException as exc:
        record(directory/'decision.json', dict(decision='ROOT_CAUSE_STILL_UNRESOLVED', error=str(exc),
            evidence_status='FAILED_OR_INCOMPLETE; NO_AUTOMATIC_RETRY'))
        manifest.update(result='INTERRUPTED' if isinstance(exc,(KeyboardInterrupt,SystemExit)) else 'FAILED',
                        error=str(exc) or type(exc).__name__,decision='ROOT_CAUSE_STILL_UNRESOLVED')
        print('EXPERIMENT_FAILED='+str(exc)+'; NO_AUTOMATIC_RETRY',file=sys.stderr,flush=True)
        return 1
    finally:
        manifest['end']=stamp();save_progress(manifest)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    mode=p.add_mutually_exclusive_group()
    mode.add_argument('--static-check',action='store_true')
    mode.add_argument('--preflight-only',action='store_true')
    mode.add_argument('--rtl-only',action='store_true',help='run environment checks and RTL generation, then stop before Verilator build/simulation')
    p.add_argument('--jobs',type=int,default=1)
    p.add_argument('--seed',type=int,default=1)
    p.add_argument('--max-cycles',type=int,default=500000000)
    p.add_argument('--min-free-gib',type=int,default=30)
    p.add_argument('--repeat-from',help='explicitly repeat the latest SUCCEEDED run in a fresh directory; never retries failure')
    args=p.parse_args()
    if args.jobs<1 or args.min_free_gib<0: p.error('invalid resource bound')
    if args.seed!=1 or args.max_cycles!=500000000: p.error('paired workload seed/max-cycles are fixed at 1/500000000')
    if args.repeat_from and (args.preflight_only or args.rtl_only):
        p.error('--repeat-from applies only to a full run or --static-check')
    ensure_output_layout()
    if args.static_check:
        result = static_check(args.min_free_gib)
        if args.repeat_from:
            result['explicit_repetition'] = refuse_second_simulation(args.repeat_from,
                result['optimization_3_checker_source_digest'])
        print(json.dumps(result, indent=2)); return 0
    def interrupted(signum,frame): raise SystemExit(128+signum)
    signal.signal(signal.SIGTERM,interrupted)
    with (OUT/'manifests/experiment.lock').open('a') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
        return execute(args)


if __name__=='__main__':
    try: raise SystemExit(main())
    except Exception as exc:
        print('PREFLIGHT_FAILED='+str(exc),file=sys.stderr);raise SystemExit(1)
