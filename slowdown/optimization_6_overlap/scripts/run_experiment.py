#!/usr/bin/env python3
"""Build and measure private Opt4 overlap experiments using the pinned workload.

Build targets live in this worktree. Frozen Opt4 tools/evidence are never edited.
Each simulation has a fresh directory and an exclusive start marker; --resume
only reuses a build whose simulator has never started and whose seal still matches.
"""
import argparse
import datetime as dt
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "slowdown/optimization_6_overlap"
STABLE = ROOT / "slowdown/optimization_4_svb"
CHIPYARD = ROOT / "chipyard"
BASE_HEAD = "2ea467ba0"
SOFTWARE = Path("/data1/gzh/EC/check/software_common_builds/gapbs512_20261023_03")
REVIEWED = {
    "chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala",
    "chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala",
    "chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala",
    "chipyard/generators/boom/src/main/scala/lsu/dcache.scala",
    "chipyard/generators/boom/src/main/scala/lsu/lsu.scala",
    "chipyard/generators/rocket-chip/src/main/scala/rocket/IBuf.scala",
    "chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala",
    "chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala",
}
sys.path.insert(0, str(STABLE / "scripts"))
sys.path.insert(0, str(STABLE / "analysis"))
from compact_capture import capture, budget_contract
from prepare_failure_diagnostics import prepare
from analyze_svb import run_summary


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True)


def record(path, data):
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")


def identity():
    frozen = json.loads((ROOT / "slowdown/opt4/frozen_manifest.json").read_text())
    changed = set(git("diff", "--name-only", BASE_HEAD, "--", "chipyard").splitlines())
    untracked = set(git("ls-files", "--others", "--exclude-standard", "--", "chipyard").splitlines())
    # The directory-only upstream ignore does not cover our read-only tool
    # symlink. It supplies executables/libraries, never hardware source.
    tool_link = CHIPYARD / ".conda-env"
    if tool_link.is_symlink() and tool_link.resolve() == Path("/data1/gzh/EC/chipyard/.conda-env"):
        untracked.discard("chipyard/.conda-env")
    if (changed | untracked) - REVIEWED:
        raise RuntimeError("unreviewed hardware inputs: " + repr(sorted((changed | untracked) - REVIEWED)))
    protected = frozen["frozen_source_sha256"]
    for rel, expected in protected.items():
        if rel not in REVIEWED and sha(ROOT / rel) != expected:
            raise RuntimeError("protected Opt4 source changed: " + rel)
    for name, expected in (("test.riscv", frozen["software"]["elf_sha256"]),
                           ("test.loadmem_hex", frozen["software"]["loadmem_sha256"])):
        if sha(SOFTWARE / name) != expected:
            raise RuntimeError("pinned software changed: " + name)
    patch = git("diff", "--binary", BASE_HEAD, "--", "chipyard")
    paths = sorted(set(protected) | REVIEWED)
    resources = json.loads((OUT / "restored_resources.json").read_text())
    for rel, expected in resources.items():
        if sha(ROOT / rel) != expected:
            raise RuntimeError("restored frozen BlackBox resource changed: " + rel)
    return dict(git_head=git("rev-parse", "HEAD").strip(), base_head=BASE_HEAD,
                hardware_sha256={rel: sha(ROOT / rel) for rel in paths},
                restored_resource_sha256=resources,
                patch_sha256=hashlib.sha256(patch.encode()).hexdigest(),
                elf_sha256=sha(SOFTWARE / "test.riscv"),
                loadmem_sha256=sha(SOFTWARE / "test.loadmem_hex"),
                n_svb_entries=16, config="v1Config", checker_harts=[1, 2, 3, 4],
                experiment="opt4_overlap", revision_mode="corrected_svb16_integrity_v2",
                observation_policy=budget_contract()["policy"],
                observation_budget=budget_contract(), trace_enabled=False,
                runner_sha256=sha(__file__),
                tool_sha256={str(p.relative_to(ROOT)): sha(p) for p in (
                    STABLE / "scripts/compact_capture.py", STABLE / "analysis/analyze_svb.py",
                    STABLE / "analysis/integrity_ledger.py", STABLE / "scripts/prepare_failure_diagnostics.py")})


def command(argv, log):
    print("PHASE=" + log.stem + " LOG=" + str(log), flush=True)
    with log.open("x") as f:
        f.write("COMMAND " + " ".join(map(str, argv)) + "\n")
        f.flush()
        p = subprocess.Popen(list(map(str, argv)), cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
        try:
            while True:
                try:
                    rc = p.wait(timeout=30)
                    break
                except subprocess.TimeoutExpired:
                    print("PHASE_IN_PROGRESS=" + log.stem, flush=True)
        except BaseException:
            p.terminate()
            p.wait()
            raise
    if rc:
        raise RuntimeError("command failed: " + str(log) + "\n" + "\n".join(log.read_text(errors="replace").splitlines()[-20:]))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--label", default="overlap")
    ap.add_argument("--build-only", action="store_true")
    ap.add_argument("--static-check", action="store_true")
    ap.add_argument("--resume", help="run ID with an identical seal and no simulation attempt")
    args = ap.parse_args()
    if args.jobs < 1 or not re.fullmatch(r"[a-z0-9_]+", args.label):
        ap.error("invalid jobs or label")
    source = identity()
    if args.static_check:
        print(json.dumps(source, indent=2))
        return 0
    # Pin tool paths while retaining the host's Verilator version. This is a
    # normal private build, without writable links to the original sources.
    conda = CHIPYARD / ".conda-env"
    verilator = shutil.which("verilator")
    os.environ["PATH"] = str(Path(verilator).parent) + ":" + str(conda / "bin") + ":" + os.environ["PATH"]
    os.environ["JAVA_HOME"] = str(conda / "lib/jvm")
    os.environ["RISCV"] = str(conda / "riscv-tools")
    os.environ["JAVA_TOOL_OPTIONS"] = "-Xmx12G -Xss8M -XX:ActiveProcessorCount=8 -Dsbt.supershell=false"
    os.environ["SBT_OPTS"] = (f"-Dsbt.ivy.home={CHIPYARD}/.ivy2 -Dsbt.global.base={CHIPYARD}/.sbt "
                              f"-Dsbt.boot.directory={CHIPYARD}/.sbt/boot -Dsbt.color=false")
    if args.resume:
        if not re.fullmatch(r"overlap_[a-z0-9_]+_[0-9]{8}_[0-9]{6}_[a-f0-9]{8}", args.resume):
            raise RuntimeError("invalid resume ID")
        run_id = args.resume
    else:
        run_id = "overlap_" + args.label + "_" + dt.datetime.now(dt.timezone.utc).strftime("%Y%m%d_%H%M%S_") + uuid.uuid4().hex[:8]
    run, build = OUT / "runs" / run_id, OUT / "build" / run_id
    if args.resume:
        manifest = json.loads((run / "run_manifest.json").read_text())
        if manifest["source"] != source or (run / "SIMULATION_STARTED.json").exists():
            raise RuntimeError("resume requires unchanged source and no simulation attempt")
        simulator = build / "verilator/simulator-chipyard-v1Config"
        if (manifest.get("hardware_generation") != "PASS" or
                manifest.get("verilator_build") != "PASS" or not simulator.is_file()):
            raise RuntimeError("resume requires a completed successful build and existing simulator")
    else:
        run.mkdir(parents=True)
        build.mkdir(parents=True)
        shutil.copytree(CHIPYARD / "tools/DRAMSim2", build / "dramsim", symlinks=True,
                        ignore=shutil.ignore_patterns("*.o", "*.a", "*.so", "results", ".git"))
        (build / "verilator").mkdir()
        (build / "verilator/Makefile").symlink_to(CHIPYARD / "sims/verilator/Makefile")
        (run / "source.patch").write_text(git("diff", "--binary", BASE_HEAD, "--", "chipyard"))
        manifest = dict(schema=2, run_id=run_id, source=source, simulation="NOT_STARTED",
                        software=dict(elf=str(SOFTWARE / "test.riscv"), elf_sha256=source["elf_sha256"],
                                      loadmem=str(SOFTWARE / "test.loadmem_hex"), loadmem_sha256=source["loadmem_sha256"]))
    print("RUN_DIRECTORY=" + str(run), flush=True)
    record(run / "run_manifest.json", manifest)
    make = ["make", "-C", build / "verilator", "-f", CHIPYARD / "sims/verilator/Makefile",
            "base_dir=" + str(CHIPYARD), "sim_dir=" + str(build / "verilator"),
            "gen_dir=" + str(build / "generated"), "build_dir=" + str(build / "generated"),
            "output_dir=" + str(build / "make-output"), "dramsim_dir=" + str(build / "dramsim"),
            "CONFIG=v1Config", "VERILATOR_THREADS=1", "EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS -DSAFE_CHAIN_EVENTS",
            "SBT_BIN=" + str(conda / "bin/sbt") + " -java-home " + str(conda / "lib/jvm"),
            "-j" + str(args.jobs)]
    try:
        if not args.resume:
            command(make + ["verilog"], build / "rtl_generation.log")
            manifest["hardware_generation"] = "PASS"
            manifest["failure_diagnostics"] = prepare(build / "generated")
            record(run / "run_manifest.json", manifest)
            command(make + ["default"], build / "verilator_build.log")
            manifest["verilator_build"] = "PASS"
            record(run / "run_manifest.json", manifest)
        if args.build_only:
            return 0
        if identity() != source:
            raise RuntimeError("source changed during build")
        simulator = build / "verilator/simulator-chipyard-v1Config"
        argv = [str(simulator), "-s", "1", "+cycle-count", "+permissive", "+safe-chain-events",
                "+safe-chain-budgeted", "+cache-opportunity", "+dramsim",
                "+dramsim_ini_dir=" + str(CHIPYARD / "generators/testchipip/src/main/resources/dramsim2_ini"),
                "+max-cycles=500000000", "+loadmem=" + str(SOFTWARE / "test.loadmem_hex"),
                "+loadmem_addr=80000000", "+permissive-off", str(SOFTWARE / "test.riscv")]
        with (run / "SIMULATION_STARTED.json").open("x") as f:
            json.dump(dict(source=source, argv=argv), f)
        manifest["simulation"] = "STARTED"
        record(run / "run_manifest.json", manifest)
        os.chdir(run)  # DRAMSim's numbered logs are confined to the new run.
        rc, stats = capture(argv, run)
        manifest.update(simulation="COMPLETED", exit_status=rc, capture=stats)
        record(run / "run_manifest.json", manifest)
        stdout = (run / "stdout.log").read_text(errors="replace")
        matches = re.findall(r"\[ROI\] hart=0 start=(\d+) stop=(\d+) cycles=(\d+)", stdout)
        if len(matches) == 1:
            start, stop, cycles = map(int, matches[0])
            if stop - start != cycles:
                raise RuntimeError("inconsistent ROI marker")
            record(run / "roi.json", dict(comparison="SAME_SOFTWARE_ROI_COMPARABLE",
                   start_cycle=start, stop_cycle=stop, safe_chain_roi_cycles=cycles))
        summary = run_summary(run)
        record(run / "summary.json", summary)
        print(json.dumps(dict(correctness=summary.get("correctness", {}).get("status"),
                              performance_valid=summary.get("performance_valid"),
                              opt4_roi_cycles=summary.get("opt4_roi_cycles"),
                              slowdown_vs_native=summary.get("opt4_ratio_to_baseline")), indent=2))
        return 0 if summary.get("performance_valid") else 1
    except BaseException as exc:
        manifest["error"] = str(exc)
        record(run / "run_manifest.json", manifest)
        raise


if __name__ == "__main__":
    raise SystemExit(main())
