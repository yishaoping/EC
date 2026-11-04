#!/usr/bin/env python3
"""Actual emitted SVB retention/invalidation tests; no architectural rollback claim."""
import argparse
import hashlib
import json
import re
import subprocess
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("generated", type=Path)
    args = parser.parse_args()
    collateral = args.generated.resolve() / "gen-collateral"
    source = collateral / "SpeculativeVersionBuffer.sv"
    emitted = source.read_text()
    assertion = re.search(r"if \((\w+)\)[^\n]*\n\s+assert__assert: assert\(_io_acked_output\)", emitted)
    assert assertion
    guard = re.search(r"wire\s+" + assertion[1] + r" = ([^;]+);", emitted)
    assert guard and "io_ack_valid" in guard[1] and "reset" in guard[1]
    driver = OUT / "scripts/svb_retention_driver.cpp"
    run = OUT / "build" / ("svb_retention_" + uuid.uuid4().hex[:8])
    run.mkdir(parents=True, exist_ok=False)
    command = ["verilator", "--cc", "--exe", "--build", "--assert", "-Wno-fatal",
               "--top-module", "SpeculativeVersionBuffer", "--Mdir", str(run / "obj"),
               "-j", "2", "-CFLAGS", "-O2 -std=c++17", "-I" + str(collateral),
               str(source), str(driver), "-o", "svb_retention_test"]
    with (run / "build.log").open("xb") as stream:
        subprocess.run(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT, check=True)
    tests = []
    for name, arguments in [("normal", []), ("wrong_key", ["wrong_key"]), ("wrong_entry", ["wrong_entry"])]:
        process = subprocess.run([str(run / "obj/svb_retention_test")] + arguments,
                                 cwd=run, capture_output=True, text=True)
        (run / (name + ".stdout.log")).write_text(process.stdout)
        (run / (name + ".stderr.log")).write_text(process.stderr)
        ok = (process.returncode == 0 and "PASS persistent_full=" in process.stdout) if not arguments else (
            process.returncode != 0 and "TOP.SpeculativeVersionBuffer.assert__assert" in process.stdout + process.stderr)
        tests.append(dict(test=name, exit_status=process.returncode, passed=ok))
    result = {"status": "PASS" if all(t["passed"] for t in tests) else "FAIL", "tests": tests,
              "emitted_source": str(source), "emitted_source_sha256": sha(source),
              "driver_sha256": sha(driver), "command": command,
              "expected_ACK_assertion": "assert__assert", "ACK_assertion_guard": guard[1],
              "scope": "Full emitted SVB with assertions: persistent data, same-line versions, invalidation boundary, backpressure, safe SPEC across flush/epoch (including reused epoch), durable coalescing successor, simultaneous flush/coalescing, delayed/mismatching ACK. Component publication test; does not simulate architectural register/PC/memory rollback."}
    (run / "result.json").write_text(json.dumps(result, indent=2) + "\n")
    print("RESULT=" + str(run / "result.json"), flush=True)
    print(json.dumps(result), flush=True)
    return int(result["status"] != "PASS")


if __name__ == "__main__":
    raise SystemExit(main())
