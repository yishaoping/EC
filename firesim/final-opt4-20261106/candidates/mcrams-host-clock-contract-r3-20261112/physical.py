#!/usr/bin/python3
"""Run the existing physical pipeline with the exact generated clock contract.

Canonical output paths and independent runtime certification stay compatible.
No target, generated XDC, synthesis, resource or timing gate is relaxed.
"""
import hashlib
import importlib.util
import json
from pathlib import Path

C = Path(__file__).resolve().parent
OLD = C.parent / 'mcrams-full-host-continuation-r2-20261112'

CLOCK_GATE = r'''
set host [get_clocks -quiet host_clock]
if {[llength $host] != 1} {error "missing exact host clock"}
set host_period [get_property PERIOD $host]
foreach name {buildtop_reference_clock tileClockGroup_tile_1} {
  set c [get_clocks -quiet $name]
  if {[llength $c] != 1} {error "missing exact target clock $name"}
  if {abs([get_property PERIOD $c]-$host_period)>0.001} {
    error "clock differs from exact generated divide_by=1 contract: $name"
  }
  if {[llength [all_registers -clock $c]] < 1} {error "target clock has no registers: $name"}
}
'''


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def verify():
    pins = json.loads((C / 'inputs.json').read_text())
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('changed clock repair input', path)
    plan = json.loads((OLD / 'physical-plan.json').read_text())
    text = Path(plan['implementation_xdc']).read_text()
    clocks = ['buildtop_reference_clock', 'tileClockGroup_tile_1']
    lines = [l for l in text.splitlines() if l and not l.startswith('#')]
    assert len(lines) == 6
    for name, setup, hold, index in zip(clocks, [1, 2], [0, 1], [0, 1]):
        expected = [
            f'create_generated_clock -name {name} -source [get_pins -of [get_clocks host_clock]] '
            f'[get_pins top/sim/target/FireSim__/clockBridge_clocks_{index}_buffer/O] -divide_by 1',
            f'set_multicycle_path {setup} -setup -from [get_clocks {name}] -to [get_clocks {name}]',
            f'set_multicycle_path {hold} -hold  -from [get_clocks {name}] -to [get_clocks {name}]',
        ]
        assert lines[index*3:index*3+3] == expected, 'generated clock semantics changed'
    return pins


def rewrite(name, body):
    if name == 'timing_drc_bitstream':
        needle = 'scale {1 2}'
        assert body.count(needle) == 1, 'upstream gate changed; review independently'
        body = body.replace(needle, 'scale {1 1}')
    elif name == 'top_opt':
        assert body.endswith('exit 0')
        # Diagnose clock bindings before spending time in place/route, after
        # retaining the exact linked/optimized DCP and utilization reports.
        out = '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-shell-physical-r2-20261112'
        body = body[:-len('exit 0')] + f'report_clocks -file {{{out}/top-preplace-clocks.rpt}}\n' + CLOCK_GATE + '\nexit 0'
    return body


def main():
    pins = verify()
    spec = importlib.util.spec_from_file_location('original_mcrams_physical_r2', OLD / 'physical.py')
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    original_stage = m.stage
    original_update = m.update

    def stage(name, body, outputs):
        return original_stage(name, rewrite(name, body), outputs)

    def update(**values):
        return original_update(physical_controller_revision='r3-generated-clock-contract',
            physical_controller_source=str(C / 'physical.py'),
            physical_controller_sha256=sha(C / 'physical.py'),
            clock_repair_inputs_sha256=sha(C / 'inputs.json'),
            generated_constraints_changed=False, **values)

    m.stage = stage
    m.update = update
    try:
        m.main()
    except Exception as e:
        if m.ST:
            m.update(status='FAILED_WITH_EVIDENCE', error=repr(e), ended_utc=m.now())
            m.save(m.O / 'failure.json', m.ST)
        raise


if __name__ == '__main__':
    main()
