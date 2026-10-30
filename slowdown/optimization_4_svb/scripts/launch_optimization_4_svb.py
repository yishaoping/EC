#!/usr/bin/env python3
"""Single user-run SVB launcher.

`--static-check` performs only source, patch, and software identity checks.
`--analysis-only RUN_DIR` validates the recorded run identity and executes only
offline post-analysis, without RTL generation, a Verilator build, or simulation.
The default path is intentionally user-only: it generates RTL, builds the
non-trace Verilator model, runs the pinned GAPBS512 image once, and invokes the
compact analyzer. It never retries a started simulation automatically.
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
import time
import uuid

ROOT = Path("/data1/gzh/EC")
CHIPYARD = ROOT / "chipyard"
OUT = ROOT / "slowdown/optimization_4_svb"
BASELINE = ROOT / "baseline/software_common_builds/gapbs512_20261023_03"
ELF = BASELINE / "test.riscv"
LOADMEM = BASELINE / "test.loadmem_hex"
OPT3_HEAD = "9afd806830ce32e2e8ad317a4530747e852c881f"
ELF_SHA = "da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c"
LOADMEM_SHA = "f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad"
ALLOWED_HARDWARE = {
    "chipyard/generators/boom/src/main/scala/exu/core.scala",
    "chipyard/generators/boom/src/main/scala/lsu/dcache.scala",
    "chipyard/generators/boom/src/main/scala/lsu/mshrs.scala",
    "chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala",
    "chipyard/generators/rocket-chip/src/main/scala/rocket/NBDcache.scala",
    "chipyard/generators/rocket-chip/src/main/scala/util/CacheOpportunityObservation.scala",
    "chipyard/generators/rocket-chip/src/main/resources/vsrc/CacheOpportunityObserver.sv",
    "chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v",
    "chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc",
    "chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala",
    "chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceD.scala",
    "chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala",
}


def sha(path):
    h = hashlib.sha256()
    with Path(path).open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def identity():
    subprocess.check_call(["git", "cat-file", "-e", OPT3_HEAD + "^{commit}"], cwd=ROOT)
    if subprocess.call(["git", "merge-base", "--is-ancestor", OPT3_HEAD, "HEAD"], cwd=ROOT):
        raise RuntimeError("HEAD is not based on the validated Opt3 commit")
    changed = set(git("diff", "--name-only", OPT3_HEAD, "--", "chipyard").splitlines())
    untracked = set(git("ls-files", "--others", "--exclude-standard", "--", "chipyard").splitlines())
    unexpected = (changed | untracked) - ALLOWED_HARDWARE
    if unexpected:
        raise RuntimeError("unreviewed hardware changes: " + repr(sorted(unexpected)))
    patch = ROOT / "AI/TMP/opt4_one_shot_closure_20261030_143326_a1dcf391/opt4_integrity_cumulative.patch"
    if not patch.is_file():
        raise RuntimeError("SVB patch artifact missing: " + str(patch))
    patch_text = patch.read_text(errors="replace")
    if "new file mode" not in patch_text or "svb_capture" not in patch_text:
        raise RuntimeError("SVB patch artifact does not contain the reviewed RTL changes")
    subprocess.check_call(["git", "apply", "--reverse", "--check", str(patch)], cwd=ROOT)
    dcache = CHIPYARD / "generators/boom/src/main/scala/lsu/dcache.scala"
    svb = CHIPYARD / "generators/boom/src/main/scala/lsu/speculative-version-buffer.scala"
    dcache_text = dcache.read_text()
    core_text = (CHIPYARD / "generators/boom/src/main/scala/exu/core.scala").read_text()
    if ("new SpeculativeVersionBuffer(entries = nSVBEntries)" not in dcache_text or
            "case object SVBEntries extends Field[Int](16)" not in svb.read_text() or
            "gate_would_handoff_without_fastline" not in dcache_text or
            "DEADLOCK-1: stale fast-line lease survived revocation" not in dcache_text or
            "!svbFastPreservationConflict" not in dcache_text or
            "integrityPendingSerial" not in dcache_text or
            "INTEGRITY-1: retained SVB snapshot changed" not in svb.read_text() or
            "CORE_WATCHDOG_SNAPSHOT" not in core_text):
        raise RuntimeError("SVB hang diagnostic source markers missing")
    for path, expected in ((ELF, ELF_SHA), (LOADMEM, LOADMEM_SHA)):
        if not path.is_file() or sha(path) != expected:
            raise RuntimeError("pinned software hash mismatch: " + str(path))
    spec = importlib.util.spec_from_file_location("opt4_capture_policy", OUT / "scripts/compact_capture.py")
    policy = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(policy)
    budget = policy.budget_contract()
    if budget["policy"] != "priority_reserved_v2":
        raise RuntimeError("unsupported observation budget policy")
    return {
        "opt3_head": OPT3_HEAD,
        "git_head": git("rev-parse", "HEAD"),
        "hardware_files": sorted(changed | untracked),
        "hardware_sha256": {path: sha(ROOT / path) for path in sorted(ALLOWED_HARDWARE)},
        "patch_sha256": sha(patch),
        "elf_sha256": sha(ELF),
        "loadmem_sha256": sha(LOADMEM),
        "revision_mode": "corrected_svb16_integrity_v2",
        "validation_purpose": "FINAL_OPT4_VALIDATION",
        "integrity_schema": 2,
        "trace_enabled": False,
        "diagnostics": "allocation-scoped hash/terminal ledger; 8192-event failure ring; no verbose",
        "n_svb_entries": 16,
        "observation_policy": "priority_reserved_v2",
        "observation_budget": budget,
        "tool_sha256": {str(p.relative_to(ROOT)): sha(p) for p in
                       (OUT / "scripts/compact_capture.py", OUT / "analysis/analyze_svb.py",
                        OUT / "analysis/analyze_hang.py", OUT / "analysis/integrity_ledger.py",
                        OUT / "scripts/offline_integrity_tests.py",
                        OUT / "scripts/prepare_failure_diagnostics.py",
                        OUT / "scripts/offline_fastline_tests.py",
                        OUT / "scripts/launch_optimization_4_svb.py", OUT.parent / "run_optimization_4_svb.sh")},
    }


def static_check():
    result = identity()
    result.update(status="PASS", hardware_generation="NOT_EXECUTED",
                  verilator_build="NOT_EXECUTED", simulation="NOT_EXECUTED")
    print(json.dumps(result, indent=2, sort_keys=True))


def prepare_diagnostics(generated):
    from prepare_failure_diagnostics import prepare
    return prepare(generated)


def command(argv, cwd, log):
    log.parent.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    print("PHASE_START=" + log.stem + " LOG=" + str(log), flush=True)
    with log.open("x") as f:
        print("COMMAND", " ".join(map(str, argv)), file=f, flush=True)
        proc = subprocess.Popen(list(map(str, argv)), cwd=cwd, stdout=f,
                                stderr=subprocess.STDOUT, env=os.environ.copy())
        try:
            while True:
                try:
                    status = proc.wait(timeout=30)
                    break
                except subprocess.TimeoutExpired:
                    elapsed = int(time.monotonic() - started)
                    print("PHASE_IN_PROGRESS=" + log.stem + " ELAPSED_SECONDS=" +
                          str(elapsed) + " LOG=" + str(log), flush=True)
        except BaseException:
            proc.terminate()
            try:
                proc.wait(timeout=10)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait()
            raise
    if status:
        with log.open(errors="replace") as f:
            from collections import deque
            tail = "".join(deque(f, maxlen=20))
        print("PHASE_FAILED=" + log.stem + " EXIT_STATUS=" + str(status) +
              "\n" + tail, file=sys.stderr, flush=True)
        raise RuntimeError("command failed (exit " + str(status) + "); see " + str(log))
    print("PHASE_PASS=" + log.stem + " ELAPSED_SECONDS=" +
          str(int(time.monotonic() - started)), flush=True)


def record(path, data):
    temporary = path.with_name(path.name + ".new")
    temporary.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n")
    temporary.replace(path)


def post_analysis_plan(run, analysis_dir, log_dir, tool_root=None, python=sys.executable):
    tool_root = Path(tool_root or OUT)
    run = Path(run)
    analysis_dir = Path(analysis_dir)
    log_dir = Path(log_dir)
    return [
        ("hang_analysis", [python, tool_root / "analysis/analyze_hang.py", run],
         log_dir / "hang_analysis.log"),
        ("integrity_ledger", [python, tool_root / "analysis/integrity_ledger.py", run,
                               "--output-dir", analysis_dir / "integrity"],
         log_dir / "integrity_ledger.log"),
        ("offline_integrity_tests", [python, tool_root / "scripts/offline_integrity_tests.py"],
         log_dir / "offline_integrity_tests.log"),
        ("offline_capacity_cache_tests", [python, tool_root / "scripts/offline_capacity_cache_tests.py"],
         log_dir / "offline_capacity_cache_tests.log"),
        ("roi_result_summary", [python, tool_root / "analysis/analyze_svb.py", run,
                                 "--output", analysis_dir / "summary.json"],
         log_dir / "roi_result_summary.log"),
    ]


def validate_analysis_only(run_path):
    run = Path(run_path).resolve(strict=True)
    runs_root = (OUT / "runs").resolve()
    try:
        run.relative_to(runs_root)
    except ValueError as exc:
        raise RuntimeError("--analysis-only requires a run inside " + str(runs_root)) from exc
    manifest_path = run / "run_manifest.json"
    if not manifest_path.is_file():
        raise RuntimeError("analysis-only run manifest missing: " + str(manifest_path))
    manifest = json.loads(manifest_path.read_text())
    if manifest.get("run_id") != run.name:
        raise RuntimeError("run ID does not match its manifest")
    source = manifest.get("source") or {}
    hardware = source.get("hardware_sha256") or {}
    if not hardware:
        raise RuntimeError("run manifest has no hardware source fingerprint")
    for relative, expected in hardware.items():
        path = ROOT / relative
        if not path.is_file() or sha(path) != expected:
            raise RuntimeError("hardware identity mismatch for analysis-only input: " + relative)
    software = manifest.get("software") or {}
    for path_key, hash_key in (("elf", "elf_sha256"), ("loadmem", "loadmem_sha256")):
        path_value, expected = software.get(path_key), software.get(hash_key)
        if path_value and expected:
            path = Path(path_value)
            if not path.is_file() or sha(path) != expected:
                raise RuntimeError("software identity mismatch for analysis-only input: " + str(path))
    if manifest.get("simulation") != "COMPLETED" or manifest.get("exit_status") != 0:
        raise RuntimeError("analysis-only requires a completed simulation with exit status 0")
    if not (run / "SIMULATION_STARTED.json").is_file():
        raise RuntimeError("simulation start marker missing from analysis-only input")
    capture = manifest.get("capture") or {}
    if capture.get("mandatory_evidence_complete") is not True:
        raise RuntimeError("mandatory captured evidence is incomplete")
    for name in ("stdout.log", "stderr.log", "safe_chain_events.tsv"):
        if not (run / name).is_file():
            raise RuntimeError("analysis-only input missing required artifact: " + name)
    return run, manifest


def benchmark_evidence(run):
    stdout = (Path(run) / "stdout.log").read_text(errors="replace")
    stderr = (Path(run) / "stderr.log").read_text(errors="replace")
    result = {}
    for line in stdout.splitlines():
        match = re.fullmatch(r"\[RUN\] benchmark=gapbs_bfs nodes=(\d+) source=(\d+) reached=(\d+) edges=(\d+) verified=(\d+) parent_checksum=(\d+)", line)
        if match:
            result = dict(nodes=int(match[1]), source=int(match[2]), reached=int(match[3]),
                          edges=int(match[4]), verified=int(match[5]), checksum=int(match[6]))
    roi = None
    for line in stdout.splitlines():
        match = re.fullmatch(r"\[ROI\] hart=0 start=(\d+) stop=(\d+) cycles=(\d+)", line)
        if match:
            roi = dict(start_cycle=int(match[1]), stop_cycle=int(match[2]),
                       safe_chain_roi_cycles=int(match[3]),
                       comparison="SAME_SOFTWARE_ROI_COMPARABLE")
    passed = bool(result and result.get("verified") == 1 and
                  re.search(r"^\[COMPUTATION\] status=PASS(?:\s|$)", stdout, re.M) and
                  re.search(r"^\[END\] hart=0 status=PASS$", stdout, re.M) and
                  "*** PASSED ***" in stderr and
                  "STAGE1_SIM_EXIT reason=serial_success io_success=1" in stderr and roi)
    return dict(status="PASS" if passed else "FAIL", result=result or None, roi=roi)


def run_post_analysis(run, manifest, execute_phase, log_dir):
    run = Path(run)
    analysis_started_at = dt.datetime.now(dt.timezone.utc).isoformat()
    analysis_dir = run / "analysis"
    analysis_dir.mkdir(parents=True, exist_ok=True)
    evidence = benchmark_evidence(run)
    if evidence["roi"]:
        record(run / "roi.json", evidence["roi"])
    manifest["benchmark_status"] = evidence["status"]
    manifest["benchmark_result"] = evidence["result"]
    failures = []
    phase_results = []
    for name, argv, log in post_analysis_plan(run, analysis_dir, log_dir):
        try:
            execute_phase(name, argv, log)
            phase_results.append(dict(phase=name, status="PASS", log=str(log), argv=list(map(str, argv))))
        except Exception as exc:
            failures.append(name)
            phase_results.append(dict(phase=name, status="FAILED", log=str(log),
                                      argv=list(map(str, argv)), error=str(exc)))

    summary_path = analysis_dir / "summary.json"
    ledger_path = analysis_dir / "integrity/integrity_ledger.json"
    summary = json.loads(summary_path.read_text()) if summary_path.is_file() else None
    lifecycle = json.loads(ledger_path.read_text()) if ledger_path.is_file() else None
    if summary is not None:
        manifest["analysis"] = summary
    checks = summary or {}
    checks_pass = bool(
        checks.get("correctness", {}).get("status") == "PASS" and
        checks.get("protocol", {}).get("status") == "PASS" and
        checks.get("data_ordering", {}).get("status") == "PASS" and
        checks.get("cache_opportunity", {}).get("status") == "PASS" and
        checks.get("performance_valid") is True and lifecycle and lifecycle.get("status") == "PASS")
    simulation_pass = manifest.get("simulation") == "COMPLETED" and manifest.get("exit_status") == 0
    accounting = checks.get("cache_opportunity", {}).get("entry_accounting", {})
    terminal_counts = (lifecycle or {}).get("terminal_counts", {})
    terminal_accounting_pass = bool(
        lifecycle and lifecycle.get("status") == "PASS" and
        sum(terminal_counts.values()) == lifecycle.get("allocations") and
        accounting.get("conserved") is True and
        accounting.get("allocations") == lifecycle.get("allocations"))
    roi_valid = bool(
        simulation_pass and evidence["status"] == "PASS" and not failures and
        checks.get("benchmark_result", {}).get("verified") == 1 and
        checks.get("integrity", {}).get("status") == "PASS" and
        checks.get("protocol", {}).get("status") == "PASS" and
        checks.get("data_ordering", {}).get("status") == "PASS" and
        checks.get("capture_evidence", {}).get("status") == "PASS" and terminal_accounting_pass)
    post_status = "SUCCEEDED" if not failures and summary is not None and lifecycle is not None else "FAILED"
    status = ("FAILED" if not simulation_pass or post_status != "SUCCEEDED" else
              "SUCCEEDED" if checks_pass else "PARTIALLY_VALIDATED" if roi_valid else "NOT_VALIDATED")
    blockers = checks.get("cache_opportunity", {}).get("errors", []) if not checks_pass else []
    manifest.update(simulation_status="SUCCEEDED" if simulation_pass else "FAILED",
                    post_analysis_status=post_status,
                    analysis_validation_status="PASS" if checks_pass else
                    "FAIL" if summary is not None else "UNOBSERVED",
                    roi_validation_status="VALIDATED_OPT4_ROI" if roi_valid else "NOT_VALIDATED",
                    cache_shadow_status=checks.get("cache_opportunity", {}).get("status", "UNOBSERVED"),
                    analysis_validation_blockers=blockers,
                    overall_validation_status=status,
                    post_analysis_runs=manifest.get("post_analysis_runs", []) + [
                        dict(log_dir=str(log_dir), phases=phase_results,
                             summary=str(summary_path), lifecycle_ledger=str(ledger_path),
                             benchmark=evidence, roi_validation_status=(
                                 "VALIDATED_OPT4_ROI" if roi_valid else "NOT_VALIDATED"),
                             analysis_validation_status=("PASS" if checks_pass else
                                                         "FAIL" if summary is not None else "UNOBSERVED"),
                             blockers=blockers, started_at=analysis_started_at,
                             finished_at=dt.datetime.now(dt.timezone.utc).isoformat())],
                    result=("SUCCEEDED" if status == "SUCCEEDED" else
                            "ROI_VALIDATED_CACHE_SHADOW_FAILED" if roi_valid else status),
                    phase="POST_ANALYSIS_COMPLETE",
                    updated_at=dt.datetime.now(dt.timezone.utc).isoformat())
    record(run / "run_manifest.json", manifest)
    return status, evidence, summary, lifecycle, failures


def prepare_sim_dir(build):
    sim_dir = build / "verilator"
    sim_dir.mkdir(parents=True, exist_ok=True)
    makefile = sim_dir / "Makefile"
    target = CHIPYARD / "sims/verilator/Makefile"
    if makefile.exists() or makefile.is_symlink():
        if not makefile.is_symlink() or makefile.resolve() != target.resolve():
            raise RuntimeError("unexpected existing Verilator Makefile: " + str(makefile))
    else:
        # VTestHarness.mk depends on $(sim_dir)/Makefile even when the outer
        # make invocation supplies the repository Makefile with -f.
        makefile.symlink_to(target)
    return sim_dir


def make_argv(build, jobs):
    return ["make", "-C", build / "verilator", "-f", CHIPYARD / "sims/verilator/Makefile",
            "base_dir=" + str(CHIPYARD), "sim_dir=" + str(build / "verilator"),
            "gen_dir=" + str(build / "generated"), "build_dir=" + str(build / "generated"),
            "output_dir=" + str(build / "make-output"),
            "dramsim_dir=" + str(build / "dramsim"), "CONFIG=v1Config",
            "VERILATOR_THREADS=1", "EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS -DSAFE_CHAIN_EVENTS",
            "-j" + str(jobs)]


def resume_manifest(run_id, ident):
    if not re.fullmatch(r"optimization_4_svb_[0-9]{8}_[0-9]{6}_[0-9a-f]{8}", run_id):
        raise RuntimeError("invalid --resume run ID")
    run = OUT / "runs" / run_id
    build = OUT / "build" / run_id
    manifest = json.loads((run / "run_manifest.json").read_text())
    previous = manifest["source"]
    for key in ("opt3_head", "git_head", "patch_sha256", "elf_sha256", "loadmem_sha256"):
        if previous.get(key) != ident[key]:
            raise RuntimeError("cannot resume with changed source/software identity: " + key)
    if previous.get("hardware_sha256", ident["hardware_sha256"]) != ident["hardware_sha256"]:
        raise RuntimeError("cannot resume with changed RTL file contents")
    for key in ("tool_sha256", "observation_policy"):
        if previous.get(key) != ident.get(key):
            raise RuntimeError("cannot resume with changed observation identity: " + key)
    # Old launchers wrote SIMULATION_STARTED before RTL generation. Permit
    # repair only with concrete evidence of the known pre-simulation failure.
    capture_files = ("stdout.log", "stderr.log", "safe_chain_events.tsv",
                     "hang_ringbuffer.tsv", "failure_diagnostics.log", "roi.json")
    if any((run / name).exists() for name in capture_files) or "exit_status" in manifest:
        raise RuntimeError("simulation already attempted; resume would repeat it")
    marker = run / "SIMULATION_STARTED.json"
    if marker.exists():
        legacy = json.loads(marker.read_text())
        failure_log = build / "verilator_build.log"
        if set(legacy) != {"source"} or not failure_log.is_file() or not all(
                term in failure_log.read_text(errors="replace") for term in
                ("No rule to make target", "/verilator/Makefile", "Stop.")):
            raise RuntimeError("existing simulation guard is not a proven premature legacy marker")
    generated = build / "generated"
    for name in ("model_module_hierarchy.json", "sim_files.common.f",
                 "chipyard.TestHarness.v1Config.all.f"):
        if not (generated / name).is_file():
            raise RuntimeError("completed RTL artifact missing: " + name)
    generation_log = build / "rtl_generation.log"
    if not generation_log.is_file() or "make: Leaving directory" not in generation_log.read_text(errors="replace"):
        raise RuntimeError("no completed RTL generation log; cannot skip generation")
    return build, run, manifest


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--static-check", action="store_true")
    ap.add_argument("--resume", metavar="RUN_ID", help="reuse completed RTL from a run that never started simulation")
    ap.add_argument("--analysis-only", metavar="RUN_DIR",
                    help="reanalyze a completed run after validating its recorded hardware/software identity")
    ap.add_argument("--build-only", action="store_true", help="stop after Verilator build; do not start simulation")
    ap.add_argument("--jobs", type=int, default=1)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--max-cycles", type=int, default=500000000)
    args = ap.parse_args()
    if args.jobs < 1 or args.seed != 1 or args.max_cycles != 500000000:
        ap.error("paired run requires --jobs >= 1, seed=1, max-cycles=500000000")
    if args.analysis_only and (args.static_check or args.resume or args.build_only):
        ap.error("--analysis-only cannot be combined with --static-check, --resume, or --build-only")
    manifest = None
    run = None
    phase = "SOURCE_IDENTITY"

    def execute_phase(name, argv, log):
        nonlocal phase
        phase = name
        manifest.update(phase=name, updated_at=dt.datetime.now(dt.timezone.utc).isoformat())
        entry = {"phase": name, "argv": list(map(str, argv)), "log": str(log), "status": "RUNNING"}
        manifest.setdefault("commands", []).append(entry)
        record(run / "run_manifest.json", manifest)
        try:
            command(argv, ROOT, log)
        except BaseException:
            entry["status"] = "FAILED"
            record(run / "run_manifest.json", manifest)
            raise
        entry["status"] = "PASS"
        record(run / "run_manifest.json", manifest)

    try:
        print("PHASE_START=source_identity", flush=True)
        ident = identity()
        resumed = resume_manifest(args.resume, ident) if args.resume else None
        if args.static_check:
            ident.update(status="PASS", hardware_generation="NOT_EXECUTED",
                         verilator_build="NOT_EXECUTED", simulation="NOT_EXECUTED")
            if resumed:
                ident["resume_run"] = args.resume
                ident["resume_eligibility"] = "PASS; completed RTL, simulation never started"
            print(json.dumps(ident, indent=2, sort_keys=True))
            return 0
        if args.analysis_only:
            run, manifest = validate_analysis_only(args.analysis_only)
            benchmark = benchmark_evidence(run)
            manifest.update(simulation_status="SUCCEEDED", benchmark_status=benchmark["status"],
                            benchmark_result=benchmark["result"], post_analysis_status="IN_PROGRESS",
                            overall_validation_status="IN_PROGRESS", result="POST_ANALYSIS_IN_PROGRESS")
            manifest.setdefault("commands", [])
            record(run / "run_manifest.json", manifest)
            attempt = dt.datetime.now(dt.timezone.utc).strftime("%Y%m%d_%H%M%S") + "_" + uuid.uuid4().hex[:8]
            log_dir = run / "post_analysis" / attempt
            status, benchmark, summary, lifecycle, failures = run_post_analysis(
                run, manifest, execute_phase, log_dir)
            print("SIMULATION_STATUS=" + manifest["simulation_status"] +
                  "\nSIMULATION_EXIT_CODE=" + str(manifest.get("exit_status")) +
                  "\nBENCHMARK_STATUS=" + benchmark["status"] +
                  "\nPOST_ANALYSIS_STATUS=" + manifest["post_analysis_status"] +
                  "\nANALYSIS_VALIDATION_STATUS=" + manifest["analysis_validation_status"] +
                  "\nROI_VALIDATION_STATUS=" + manifest["roi_validation_status"] +
                  "\nCACHE_SHADOW_STATUS=" + manifest["cache_shadow_status"] +
                  "\nOVERALL_VALIDATION_STATUS=" + status +
                  "\nFAILED_ANALYSIS_PHASES=" + (",".join(failures) if failures else "NONE") +
                  "\nRUN_MANIFEST=" + str(run / "run_manifest.json"), flush=True)
            return 0 if status == "SUCCEEDED" else 3
        # Import dependencies before spending time on generation/build.
        sys.path.insert(0, str(OUT / "scripts"))
        from compact_capture import capture
        phase = "PREPARE_BUILD"
        if resumed:
            build, run, manifest = resumed
            run_id = args.resume
            marker = run / "SIMULATION_STARTED.json"
            if marker.exists():
                marker.rename(run / "LEGACY_PREMATURE_SIMULATION_STARTED.json")
                manifest["legacy_marker_correction"] = "created before generation by old launcher; no simulation process was started"
            manifest.setdefault("resumptions", []).append(dt.datetime.now(dt.timezone.utc).isoformat())
        else:
            stamp = dt.datetime.now(dt.timezone.utc).strftime("%Y%m%d_%H%M%S")
            run_id = "optimization_4_svb_" + stamp + "_" + uuid.uuid4().hex[:8]
            build = OUT / "build" / run_id
            run = OUT / "runs" / run_id
            build.mkdir(parents=True)
            run.mkdir(parents=True)
            dramsim_src = CHIPYARD / "tools/DRAMSim2"
            if not dramsim_src.is_dir():
                raise RuntimeError("DRAMSim2 source missing: " + str(dramsim_src))
            shutil.copytree(dramsim_src, build / "dramsim", symlinks=True,
                            ignore=shutil.ignore_patterns("*.o", "*.a", "*.so", "results", ".git"))
            manifest = {"schema": 2, "run_id": run_id, "source": ident,
                        "software": {"elf": str(ELF), "elf_sha256": ELF_SHA,
                                     "loadmem": str(LOADMEM), "loadmem_sha256": LOADMEM_SHA},
                        "commands": [], "hardware_generation": "NOT_STARTED"}
        prepare_sim_dir(build)
        manifest.update(result="IN_PROGRESS", phase=phase, simulation="NOT_STARTED")
        record(run / "run_manifest.json", manifest)
        print("RUN_DIRECTORY=" + str(run) + "\nBUILD_DIRECTORY=" + str(build), flush=True)
        make = make_argv(build, args.jobs)

        if resumed:
            print("RTL_GENERATION=REUSED_FROM_COMPLETED_RUN", flush=True)
        else:
            execute_phase("RTL_GENERATION", make + ["verilog"], build / "rtl_generation.log")
        manifest["hardware_generation"] = "PASS"
        phase = "FAILURE_DIAGNOSTICS_PREPARATION"
        manifest["failure_diagnostics"] = prepare_diagnostics(build / "generated")
        record(run / "run_manifest.json", manifest)
        build_log = build / "verilator_build.log"
        if build_log.exists():
            build_log = build / ("verilator_build.resume_" + uuid.uuid4().hex[:8] + ".log")
        execute_phase("VERILATOR_BUILD", make + ["default"], build_log)
        manifest["verilator_build"] = "PASS"
        simulator = build / "verilator" / "simulator-chipyard-v1Config"
        if not simulator.is_file() or not os.access(simulator, os.X_OK):
            raise RuntimeError("generated simulator missing: " + str(simulator))
        record(run / "run_manifest.json", manifest)
        if args.build_only:
            manifest.update(result="BUILD_PASSED", phase="BUILD_COMPLETE", simulation="NOT_STARTED")
            record(run / "run_manifest.json", manifest)
            print("BUILD=PASS\nSIMULATION=NOT_STARTED\nRUN_MANIFEST=" + str(run / "run_manifest.json"), flush=True)
            return 0
        if identity() != ident:
            raise RuntimeError("source identity changed during build; simulation refused")
        argv = [str(simulator), "-s", str(args.seed), "+cycle-count", "+permissive",
                "+safe-chain-events", "+safe-chain-budgeted", "+cache-opportunity", "+dramsim",
                "+dramsim_ini_dir=" + str(CHIPYARD / "generators/testchipip/src/main/resources/dramsim2_ini"),
                "+max-cycles=" + str(args.max_cycles), "+loadmem=" + str(LOADMEM),
                "+loadmem_addr=80000000", "+permissive-off", str(ELF)]
        phase = "SIMULATION"
        # The guard belongs immediately before capture/Popen, never before
        # hardware generation. A failed build can then be safely resumed.
        with (run / "SIMULATION_STARTED.json").open("x") as f:
            json.dump({"source": ident, "at": dt.datetime.now(dt.timezone.utc).isoformat(),
                       "policy": "NO_AUTOMATIC_RETRY"}, f, indent=2)
            f.write("\n")
        manifest.update(phase=phase, simulation="STARTED")
        record(run / "run_manifest.json", manifest)
        print("PHASE_START=simulation", flush=True)
        rc, stats = capture(argv, run)
        manifest["capture"] = stats
        manifest["exit_status"] = rc
        manifest["simulation"] = "COMPLETED"
        manifest["simulation_status"] = "SUCCEEDED" if rc == 0 else "FAILED"
        record(run / "run_manifest.json", manifest)
        attempt = dt.datetime.now(dt.timezone.utc).strftime("%Y%m%d_%H%M%S") + "_" + uuid.uuid4().hex[:8]
        status, evidence, summary, lifecycle, failures = run_post_analysis(
            run, manifest, execute_phase, run / "post_analysis" / attempt)
        print("SIMULATION_STATUS=" + manifest["simulation_status"] +
              "\nSIMULATION_EXIT_CODE=" + str(rc) +
              "\nBENCHMARK_STATUS=" + evidence["status"] +
              "\nPOST_ANALYSIS_STATUS=" + manifest["post_analysis_status"] +
              "\nANALYSIS_VALIDATION_STATUS=" + manifest["analysis_validation_status"] +
              "\nROI_VALIDATION_STATUS=" + manifest["roi_validation_status"] +
              "\nCACHE_SHADOW_STATUS=" + manifest["cache_shadow_status"] +
              "\nOVERALL_VALIDATION_STATUS=" + status +
              "\nFAILED_ANALYSIS_PHASES=" + (",".join(failures) if failures else "NONE"), flush=True)
        print("RUN_MANIFEST=" + str(run / "run_manifest.json"), flush=True)
        return 0 if status == "SUCCEEDED" else 3
    except BaseException as exc:
        if manifest is not None and run is not None:
            post_phase = phase in {name for name in
                                   ("hang_analysis", "integrity_ledger", "offline_integrity_tests",
                                    "offline_capacity_cache_tests", "roi_result_summary")}
            manifest.update(result=("POST_ANALYSIS_FAILED" if post_phase else
                                    "INTERRUPTED" if isinstance(exc, KeyboardInterrupt) else "FAILED"),
                            phase=phase, error=str(exc) or type(exc).__name__,
                            updated_at=dt.datetime.now(dt.timezone.utc).isoformat())
            if post_phase:
                manifest["post_analysis_status"] = "FAILED"
                manifest["overall_validation_status"] = "FAILED"
                if manifest.get("simulation") == "COMPLETED" and manifest.get("exit_status") == 0:
                    manifest["simulation_status"] = "SUCCEEDED"
            elif phase == "SIMULATION":
                manifest["simulation"] = "ABORTED"
                manifest["simulation_status"] = "FAILED"
            if hasattr(exc, "capture_stats"):
                manifest["capture"] = exc.capture_stats
                manifest["exit_status"] = getattr(exc, "simulator_return_code", None)
            record(run / "run_manifest.json", manifest)
        print("OPT4_SVB_FAILED phase=" + phase + " error=" + (str(exc) or type(exc).__name__), file=sys.stderr, flush=True)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
