from pathlib import Path
import datetime
import hashlib
import importlib.util
import json
import re

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112')


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def save(p, value):
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


log = (A / 'validation-final.log').read_text()
assert 'ALL_EXCEPTION_CONTRACT_VALIDATIONS_PASSED' in log and 'ERROR:' not in log
cases = []
for name, failed, expected, message in re.findall(
        r'^VALIDATION_CASE (\S+) failed=(\d) expected_pass=(\d) message=(.*)$', log, re.M):
    assert int(failed) != int(expected), (name, message)
    cases.append(dict(name=name, rejected=bool(int(failed)),
                      expected_pass=bool(int(expected)), observed_reason=message))
assert len(cases) == 9 and sum(x['rejected'] for x in cases) == 7
assert 'ALL_VALID_EXPORT_MUTATIONS_PASSED' in (A / 'parser-validation-final.log').read_text()
pins = json.loads((C / 'inputs.json').read_text())
(A / 'inputs-pre-final.json').write_bytes((C / 'inputs.json').read_bytes())
pins['files'] = {p: sha(p) for p in pins['files']}
(C / 'inputs.json').write_text(json.dumps(pins, indent=2, sort_keys=True) + '\n')
spec = importlib.util.spec_from_file_location('final_renderer', C / 'render.py')
renderer = importlib.util.module_from_spec(spec)
spec.loader.exec_module(renderer)
out = B / 'build-logs/Opt4-mcrams-shell-exception-contract-FUTURE-NOT-ADMITTED'
body = renderer.render(B / 'build-logs/Opt4-mcrams-shell-physical-r2-20261112/wrapper-host-linked.dcp', out)
(A / 'fullshell-topopt-FINAL-PREVIEW-NOT-ADMITTED.tcl').write_text(body)
assert body.index('ec_target_contract::verify') < body.index('check_timing -verbose')
assert all(cmd not in body for cmd in ['place_design', 'route_design', 'synth_design', 'write_bitstream'])
save(A / 'validation.json', dict(
    schema='ec-target-exception-contract-validation/1', tool='Vivado 2021.1',
    fixture='four FDRE and two BUFG primitive netlist', cases=cases,
    fixture_cases_passed=9, export_parser_cases_passed=5,
    fullshell_test_completed=False, installed=False, live_sources_changed=False,
    report_only_coverage_insufficient_counterexample=True,
    no_synthesis_opt_design_place_route_bitstream_or_device_operations=True,
    gate_sha256=sha(C / 'verify.tcl'), render_sha256=sha(C / 'render.py'),
    manifest_sha256=sha(C / 'inputs.json')))

(A / 'REPORT.md').write_text("""Prepared and tested a separate read-only preplace exception assertion.
It is not installed in the existing r4b observer or any active CAD flow.
Nine Vivado fixture cases passed (two valid, seven rejected); five mutations
of a real valid-exception export also passed. Negative cases must reject for
the expected reason; tool API errors do not count as successful rejection.

A proven fixture counterexample showed 100% exception coverage while one
checker path was false-pathed. The verifier now inspects the resolved clock
domains of other valid exceptions and checks user-ignored paths. It retains
the original native master, divide-by-one clocks and setup/hold 1/0 and 2/1,
and checks representative effective timing requirements and EXCEPTION fields.
It changes no constraints. The renderer adds only this assertion to the
original BD/IP top-opt script after preserving checkpoints and reports.
Unsupported export formats fail closed.

The fixture is not the full host or shell. Actual fullshell verification and
automatic integration remain pending independent versioning. Existing r4b
was preserved as instructed. The report-only source gap is proven; a physical
failure caused by missing exceptions in the actual full shell is unproven.
Its downstream risk would be admitting placement before asserting the full
exception contract. No fullshell timing or certification is claimed.

The immutable 06:59:22Z continuity capture records PID/start_ticks/boot_id and
exact cgroups for r5 E, full MCRams synthesis, r3 continuation, r4b observer,
priority follower and the original metrics consumer. At 07:08:33Z E remained
running. Global iteration 7 reached zero overlaps with intermediate WNS
-0.357 ns, TNS -183.342 ns, hold unavailable. These are not final timing or
route results. Preserve existing E hold_fix/reroute and conditional F.

At 06:59Z complete MCRams synthesis was still running without synth/postopt
counts or FIT. Owner-MC finite parity is PASS, SHA256
02025ffe79f679d0e37dc007d940d9c61eea3d8095acc1f6f234e5fa5a6eb29b.
This is captured-row/print-stream parity, not full equivalence.

The original metrics request was naturally admitted at 06:24:27Z.
PID 2813002/start_ticks 27638842 is waiting for certified FPGA application
replay: it is running, not queued. No duplicate request was created and no
memory guard changed. R4b remains a waiting observer; no conditional physical
repair was submitted. No production source, CPU comparison, device or live
CAD process was controlled. Only bounded primitive-netlist timing diagnostics
were launched; no synthesis, opt_design, placement, route or bitstream ran.
""")
files = [A / name for name in [
    'REPORT.md', 'continuity.json', 'validation.json', 'renderer-validation.json',
    'validation-final.log', 'validate-final.tcl', 'fixture.v', 'valid-exceptions.xdc',
    'parser-validation-final.log', 'parser-validation.tcl',
    'fullshell-topopt-FINAL-PREVIEW-NOT-ADMITTED.tcl', 'owner-MC-result.json',
    'r5-bounded-tail.log', 'capacity-bounded-tail.log', 'r5-followup.json',
    'r5-followup-tail.log']]
files += [C / name for name in ['inputs.json', 'verify.tcl', 'render.py', 'README.md']]
save(A / 'receipt.json', dict(
    schema='ec-round130-preplace-contract-receipt/1',
    utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
    files={str(p): sha(p) for p in files}, installed=False,
    fullshell_test_completed=False, new_production_jobs=[], new_requests=[],
    FPGA_operations=[], CPU_comparison_controls=[]))
result = dict(
    outcome='PROGRESS',
    summary='Prepared a separate exception verifier: 9 Vivado fixture cases and 5 export mutations passed; integration/fullshell validation remain pending. R5 E is routing, latest intermediate WNS -0.357 ns/hold unavailable. MCrams LUT/FIT remain pending; original metrics consumer is running.',
    changed_files=[str(C.relative_to(B.parents[1])) + '/',
                   str(A.relative_to(B.parents[1])) + '/',
                   'Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds/round130-result.json'],
    evidence=[
        'status-audits/round130-preplace-exception-contract-20261112/receipt.json sha256=' + sha(A / 'receipt.json'),
        'status-audits/round130-preplace-exception-contract-20261112/validation.json sha256=' + sha(A / 'validation.json'),
        'Owner-MC finite parity result sha256=02025ffe79f679d0e37dc007d940d9c61eea3d8095acc1f6f234e5fa5a6eb29b'],
    launched_jobs=['Completed bounded primitive-netlist timing diagnostics; no production CAD or device work.'],
    next_action='Preserve E hold_fix/reroute, conditional F, certification and board21 replay. Existing r3 awaits capacity FIT; existing r4b awaits actual r3 clock failure and exact cgroup release. Integrate the prepared assertion only through an independent version; do not edit bound sources or duplicate observers.',
    retry_after_seconds=600)
schema = json.loads((B / 'unattended-opt4/round-schema.json').read_text())
assert set(result) == set(schema['required']) and 30 <= result['retry_after_seconds'] <= 1800
save(B / 'unattended-opt4/rounds/round130-result.json', result)
print(json.dumps(result, indent=2))
