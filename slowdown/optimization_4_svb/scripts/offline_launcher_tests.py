#!/usr/bin/env python3
"""Launcher regressions with temporary files and mocked build/simulation calls."""
import contextlib
import importlib.util
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import types
import unittest
from unittest.mock import patch


class LauncherTests(unittest.TestCase):
    def setUp(self):
        source = Path(__file__).with_name("launch_optimization_4_svb.py")
        spec = importlib.util.spec_from_file_location("launcher_under_test", source)
        self.launcher = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(self.launcher)
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        root = Path(self.temporary.name)
        self.launcher.ROOT = root
        self.launcher.CHIPYARD = root / "chipyard"
        self.launcher.OUT = root / "opt4"
        makefile = self.launcher.CHIPYARD / "sims/verilator/Makefile"
        makefile.parent.mkdir(parents=True)
        makefile.write_text("default:\n\t@true\n")
        self.ident = {name: name for name in
                      ("opt3_head", "git_head", "patch_sha256", "elf_sha256", "loadmem_sha256")}
        self.ident["hardware_sha256"] = {"hardware.scala": "unchanged"}
        self.run_id = "optimization_4_svb_20261028_054141_eff5a3cd"
        self.build = self.launcher.OUT / "build" / self.run_id
        self.run = self.launcher.OUT / "runs" / self.run_id
        (self.build / "generated").mkdir(parents=True)
        self.run.mkdir(parents=True)
        self.manifest = {"source": self.ident, "commands": []}
        self.launcher.record(self.run / "run_manifest.json", self.manifest)
        self.launcher.record(self.run / "SIMULATION_STARTED.json", {"source": self.ident})
        (self.build / "rtl_generation.log").write_text("make: Leaving directory 'verilator'\n")
        (self.build / "verilator_build.log").write_text(
            "make: *** No rule to make target '/verilator/Makefile'. Stop.\n")
        for name in ("model_module_hierarchy.json", "sim_files.common.f",
                     "chipyard.TestHarness.v1Config.all.f"):
            (self.build / "generated" / name).write_text("fixture\n")

    def main(self, arguments, command, capturer=None):
        capture = types.SimpleNamespace(capture=capturer or (lambda *args: self.fail("unexpected simulation")))
        with patch.object(self.launcher, "identity", return_value=self.ident), \
                patch.object(self.launcher, "prepare_diagnostics", return_value={"status": "PASS"}), \
                patch.object(self.launcher, "command", side_effect=command), \
                patch.dict(sys.modules, {"compact_capture": capture}), \
                patch.object(sys, "argv", ["launcher", *arguments]), \
                contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            return self.launcher.main()

    def test_makefile_dependency_is_present_and_idempotent(self):
        sim = self.launcher.prepare_sim_dir(self.build)
        self.assertEqual((sim / "Makefile").resolve(),
                         self.launcher.CHIPYARD / "sims/verilator/Makefile")
        self.assertEqual(self.launcher.prepare_sim_dir(self.build), sim)

    def test_resume_build_only_skips_generation_and_simulation(self):
        calls = []

        def build(argv, cwd, log):
            calls.append(argv[-1])
            self.assertFalse((self.run / "SIMULATION_STARTED.json").exists())
            self.assertTrue((self.build / "verilator/Makefile").is_file())
            simulator = self.build / "verilator/simulator-chipyard-v1Config"
            simulator.write_text("fixture")
            simulator.chmod(0o700)

        self.assertEqual(self.main(["--resume", self.run_id, "--build-only"], build), 0)
        self.assertEqual(calls, ["default"])
        result = json.loads((self.run / "run_manifest.json").read_text())
        self.assertEqual(result["result"], "BUILD_PASSED")
        self.assertEqual(result["simulation"], "NOT_STARTED")
        self.assertTrue((self.run / "LEGACY_PREMATURE_SIMULATION_STARTED.json").is_file())

    def test_build_failure_is_recorded_without_simulation_guard(self):
        def failure(*args):
            raise RuntimeError("build failed fixture")

        self.assertEqual(self.main(["--resume", self.run_id], failure), 1)
        result = json.loads((self.run / "run_manifest.json").read_text())
        self.assertEqual(result["phase"], "VERILATOR_BUILD")
        self.assertEqual(result["result"], "FAILED")
        self.assertEqual(result["commands"][-1]["status"], "FAILED")
        self.assertFalse((self.run / "SIMULATION_STARTED.json").exists())

    def test_started_simulation_cannot_be_resumed(self):
        (self.run / "stdout.log").write_text("simulation attempted\n")
        with self.assertRaisesRegex(RuntimeError, "already attempted"):
            self.launcher.resume_manifest(self.run_id, self.ident)

    def test_changed_source_cannot_reuse_generated_rtl(self):
        changed = dict(self.ident, patch_sha256="changed")
        with self.assertRaisesRegex(RuntimeError, "changed source"):
            self.launcher.resume_manifest(self.run_id, changed)

    def test_changed_observation_identity_cannot_resume(self):
        for key in ("tool_sha256", "observation_policy"):
            with self.subTest(key=key), self.assertRaisesRegex(RuntimeError, "changed observation identity"):
                self.launcher.resume_manifest(self.run_id, dict(self.ident, **{key: "changed"}))

    def test_capture_exception_records_aborted_instead_of_started(self):
        def build(*args):
            simulator = self.build / "verilator/simulator-chipyard-v1Config"
            simulator.write_text("fixture, never executed")
            simulator.chmod(0o700)

        def failure(argv, run):
            self.assertIn("+safe-chain-budgeted", argv)
            exc = RuntimeError("capture I/O failure fixture")
            exc.capture_stats = {"mandatory_evidence_complete": False}
            exc.simulator_return_code = -15
            raise exc

        self.assertEqual(self.main(["--resume", self.run_id], build, failure), 1)
        result = json.loads((self.run / "run_manifest.json").read_text())
        self.assertEqual(result["simulation"], "ABORTED")
        self.assertEqual(result["exit_status"], -15)
        self.assertEqual(result["result"], "FAILED")

    def test_static_resume_does_not_modify_run(self):
        before = {p.name: p.read_bytes() for p in self.run.iterdir()}
        self.assertEqual(self.main(["--static-check", "--resume", self.run_id],
                                   lambda *args: self.fail("unexpected build")), 0)
        self.assertEqual(before, {p.name: p.read_bytes() for p in self.run.iterdir()})
        self.assertFalse((self.build / "verilator").exists())

    def test_post_analysis_scripts_are_independent_commands(self):
        tools = self.launcher.OUT
        scripts = {
            "hang_analysis": tools / "analysis/analyze_hang.py",
            "integrity_ledger": tools / "analysis/integrity_ledger.py",
            "offline_integrity_tests": tools / "scripts/offline_integrity_tests.py",
            "offline_capacity_cache_tests": tools / "scripts/offline_capacity_cache_tests.py",
            "roi_result_summary": tools / "analysis/analyze_svb.py",
        }
        for path in scripts.values():
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("import json,sys; print(json.dumps(sys.argv[1:]))\n")
        analysis_dir = self.run / "analysis"
        log_dir = self.run / "post_analysis/test"
        plan = self.launcher.post_analysis_plan(self.run, analysis_dir, log_dir, tool_root=tools)
        self.assertEqual([row[0] for row in plan], list(scripts))
        for name, argv, _ in plan:
            self.assertEqual(Path(argv[1]), scripts[name])
            foreign_scripts = {str(path) for other, path in scripts.items() if other != name}
            self.assertFalse(foreign_scripts.intersection(map(str, argv)))
            completed = subprocess.run(list(map(str, argv)), check=True, text=True,
                                       capture_output=True)
            self.assertNotIn(".py", " ".join(json.loads(completed.stdout)))

    def test_analysis_only_validates_existing_run_identity(self):
        hardware = self.launcher.ROOT / "hardware.scala"
        hardware.write_text("unchanged")
        manifest = json.loads((self.run / "run_manifest.json").read_text())
        manifest["source"]["hardware_sha256"] = {"hardware.scala": self.launcher.sha(hardware)}
        manifest.update(run_id=self.run_id, simulation="COMPLETED", exit_status=0,
                        capture={"mandatory_evidence_complete": True})
        self.launcher.record(self.run / "run_manifest.json", manifest)
        (self.run / "stdout.log").write_text(
            "[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=42\n"
            "[ROI] hart=0 start=10 stop=20 cycles=10\n[COMPUTATION] status=PASS\n[END] hart=0 status=PASS\n")
        (self.run / "stderr.log").write_text(
            "*** PASSED ***\nSTAGE1_SIM_EXIT reason=serial_success io_success=1\n")
        (self.run / "safe_chain_events.tsv").write_text("")
        run, checked = self.launcher.validate_analysis_only(self.run)
        self.assertEqual(run, self.run.resolve())
        self.assertEqual(checked["exit_status"], 0)

        hardware.write_text("changed")
        with self.assertRaisesRegex(RuntimeError, "hardware identity mismatch"):
            self.launcher.validate_analysis_only(self.run)


if __name__ == "__main__":
    unittest.main()
