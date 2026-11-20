#!/usr/bin/python3
"""Exercise sealed r2 Tcl admission branches with Tcl mocks, without Vivado.

This is control-flow validation only: no DCP is opened, no physical timing is
measured, no bit is generated, and no certificate or FPGA result is produced.
The real templates stay immutable. Each case uses its own retained directory.
"""
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = W / 'candidates/svb-host40-shell-recovery-r2-20261112'
OUT = D / 'build-logs/Opt4-svb-host40-gate-audit-round115-r1-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def save(p, value):
    temp = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with temp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(temp, p)


MOCKS = r'''
# All vendor operations are explicit mocks. Unknown commands raise Tcl errors.
proc set_param {args} {}
proc current_design {} {return TEST_DESIGN}
proc open_checkpoint {path} {
  if {$path ne "MOCK_CHECKPOINT_NEVER_OPENED"} {error "unexpected checkpoint"}
}
proc get_cells {args} {
  if {[string match *IS_BLACKBOX* $args]} {
    if {$::scenario eq "blackbox"} {return TEST_BLACKBOX};return {}
  }
  return TEST_MMCM
}
proc get_pins {args} {
  if {$::scenario eq "missing_target"} {return {}}
  return TEST_TARGET_PIN
}
proc get_clocks {args} {
  if {[llength $args]} {
    if {$::scenario eq "ambiguous_target"} {return {TEST_CLOCK1 TEST_CLOCK2}}
    return clk_out1_design_1_clk_wiz_0_0
  }
  set clocks [dict keys $::periods]
  if {$::scenario eq "missing_clock"} {return [lrange $clocks 1 end]}
  return $clocks
}
proc get_property {prop object} {
  switch -- $prop {
    PART {
      if {$::scenario eq "wrong_part"} {return WRONG_PART}
      return xcu280-fsvh2892-2L-e
    }
    REF_NAME {return MMCME4_ADV}
    CLKOUT0_DIVIDE_F {
      if {$::scenario eq "wrong_divider"} {return 24.0};return 30.0
    }
    CLKFBOUT_MULT_F {
      if {$::scenario eq "wrong_multiplier"} {return 5.0};return 4.0
    }
    DIVCLK_DIVIDE {
      if {$::scenario eq "wrong_input_divider"} {return 2};return 1
    }
    NAME {return $object}
    PERIOD {
      set value [dict get $::periods $object]
      if {$::scenario eq "wrong_host_period" && $object eq "clk_out1_design_1_clk_wiz_0_0"} {return 19.998}
      if {$::scenario eq "wrong_shell_period" && $object eq "xdma_0_axi_aclk"} {return 5.0}
      return $value
    }
    SLACK {
      if {$object eq "TEST_SETUP"} {
        if {$::scenario eq "negative_setup"} {return -0.001};return 0.001
      }
      if {$object eq "TEST_HOLD"} {
        if {$::scenario eq "negative_hold"} {return -0.001};return 0.001
      }
      error "unexpected timing object $object"
    }
    default {error "unexpected property $prop"}
  }
}
proc all_registers {args} {
  if {$::scenario eq "missing_register_coverage"} {return [lrepeat 999 TEST_REG]}
  return [lrepeat 1000 TEST_REG]
}
proc get_timing_paths {args} {
  if {[lsearch -exact $args -slack_lesser_than]>=0} {return {}}
  if {[lsearch -exact $args max]>=0} {
    if {$::scenario eq "missing_setup"} {return {}};return TEST_SETUP
  }
  if {[lsearch -exact $args min]>=0} {
    if {$::scenario eq "missing_hold"} {return {}};return TEST_HOLD
  }
  error "unexpected timing query"
}
proc get_nets {args} {
  if {$::scenario eq "bad_route"} {return TEST_UNROUTED};return {}
}
proc get_drc_violations {args} {
  if {$::scenario eq "bad_drc"} {return TEST_DRC_ERROR};return {}
}
proc phys_opt_design {args} {}
proc route_design {args} {}
proc write_checkpoint {args} {}
proc report_stub {args} {
  set index [lsearch -exact $args -file]
  if {$index>=0} {set f [open [lindex $args [expr {$index+1}]] w];puts $f MOCK_REPORT_NOT_PHYSICAL_EVIDENCE;close $f}
}
foreach command {report_timing_summary report_utilization report_clocks report_route_status report_drc report_cdc} {
  proc $command {args} {report_stub {*}$args}
}
proc check_timing {args} {
  set index [lsearch -exact $args -file]
  set f [open [lindex $args [expr {$index+1}]] w]
  set nc 0;set ue 0
  if {$::scenario eq "no_clock"} {set nc 1}
  if {$::scenario eq "unconstrained_endpoint"} {set ue 1}
  puts $f "checking no_clock ($nc)"
  puts $f "checking unconstrained_internal_endpoints ($ue)"
  close $f
}
proc report_pulse_width {args} {
  if {$::scenario eq "pulse_violated"} {return {Pulse width VIOLATED}}
  if {$::scenario eq "pulse_negative"} {return {TEST_SLACK -0.001 ns}}
  return {No pulse-width violations MOCK}
}
proc report_bus_skew {args} {
  if {$::scenario eq "skew_violated"} {return {Bus skew VIOLATED}}
  return {No bus-skew violations MOCK}
}
proc write_bitstream {args} {set ::mock_bitgen_gate_reached 1}
'''


def main():
    policy = json.loads((D / 'unattended-opt4/campaign-policy.json').read_text())
    assert policy['functional_baseline_commit'] == BASE
    assert policy['native_paused'] and not policy['fpga_access']
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    assert not OUT.exists(), 'immutable completed/partial audit must be retained'
    OUT.mkdir()
    tclsh = shutil.which('tclsh')
    assert tclsh
    contract_path = C / 'physical-clock-contract.json'
    periods = json.loads(contract_path.read_text())['periods_ns']
    assert len(periods) == 66
    period_code = ' '.join('{' + k + '} ' + str(v) for k, v in periods.items())
    cert_source = (C / 'certificate.py').read_text()
    coverage_regexes = re.findall(r"assert re.search\(r'([^']+)',timing\)", cert_source)
    assert len(coverage_regexes) == 2
    install = json.loads((C / 'installation.json').read_text())
    installation_checks = {}
    for name, digest in install['manifests'].items():
        assert sha(C / name) == digest
        installation_checks[name] = digest
    inputs = json.loads((C / 'inputs.json').read_text())['files']
    scenarios = {
        'valid': None,
        'wrong_part': ('wrong device', 'wrong part'),
        'blackbox': ('unresolved IP', 'unresolved cells'),
        'wrong_divider': ('host40 MMCM changed', 'actual physical host40 MMCM mismatch'),
        'wrong_multiplier': ('host40 MMCM changed', 'actual physical host40 MMCM mismatch'),
        'wrong_input_divider': ('host40 MMCM changed', 'actual physical host40 MMCM mismatch'),
        'missing_target': ('target clock buffer absent/ambiguous', 'target buffer ambiguous'),
        'ambiguous_target': ('host40 target coverage invalid', 'target clock ambiguous'),
        'missing_clock': ('clock set changed', 'clock set changed'),
        'wrong_host_period': ('clock period changed', 'host40 clock/coverage failed'),
        'wrong_shell_period': ('clock period changed', 'clock period changed'),
        'missing_register_coverage': ('host40 target coverage invalid', 'host40 clock/coverage failed'),
        'missing_setup': ('missing timing paths', 'missing timing'),
        'missing_hold': ('missing timing paths', 'missing timing'),
        'negative_setup': ('setup/hold gate failed', 'setup/hold failed'),
        'negative_hold': ('setup/hold gate failed', 'setup/hold failed'),
        'bad_route': ('route coverage failed', 'route coverage failed'),
        'bad_drc': ('DRC errors', 'DRC failed'),
        'pulse_violated': ('pulse width failed', 'pulse width failed'),
        'pulse_negative': ('pulse width failed', 'pulse width failed'),
        'skew_violated': ('bus skew failed', 'bus skew failed'),
        'no_clock': ('clock coverage failed', 'PYTHON_COVERAGE_REJECTED'),
        'unconstrained_endpoint': ('clock coverage failed', 'PYTHON_COVERAGE_REJECTED'),
    }
    rows = []
    templates = {}
    for index, name in enumerate(['recover.tcl.in', 'audit.tcl.in']):
        template_path = C / name
        template = template_path.read_text()
        assert inputs[str(template_path)] == sha(template_path)
        assert template.count('exit 0\n') == 1
        templates[name] = sha(template_path)
        for scenario, expected in scenarios.items():
            out = OUT / (name + '--' + scenario)
            out.mkdir()
            code = template.replace('@CHECKPOINT@', 'MOCK_CHECKPOINT_NEVER_OPENED')
            code = code.replace('@OUT@', str(out)).replace('@CLOCKS@', period_code)
            code = code.replace('@SHELL_QUERY@', (C / 'shell-nets.tcl').read_text())
            code = code.replace('@STRATEGY@', 'phys_opt_design -routing_opt -placement_opt')
            # Only the copied success exit is replaced, so the wrapper can
            # record whether the actual admission branch completed.
            code = code.replace('exit 0\n', 'set ::completed 1\n')
            candidate = out / 'template-under-test.tcl'
            candidate.write_text(code)
            wrapper = out / 'mock-runner.tcl'
            wrapper.write_text('set scenario {' + scenario + '}\n'
                               + 'set periods [dict create ' + period_code + ']\n'
                               + MOCKS + '\n'
                               + 'if {[catch {source {' + str(candidate) + '}} message options]} {\n'
                               + ' puts stderr $message;exit 1\n}\n'
                               + 'if {![info exists ::completed]} {error "template success missing"}\n'
                               + 'puts MOCK_GATE_COMPLETED_NO_VIVADO_NO_BITSTREAM\n')
            proc = subprocess.run([tclsh, str(wrapper)], capture_output=True, text=True, timeout=10)
            text = proc.stdout + proc.stderr
            effective_ok = proc.returncode == 0
            if index == 1 and effective_ok:
                # Execute the two exact regular expressions used by the real
                # independent Python certificate after its Vivado audit exits.
                timing = (out / 'check-timing.rpt').read_text()
                if not all(re.search(pattern, timing) for pattern in coverage_regexes):
                    effective_ok = False
                    text += '\nPYTHON_COVERAGE_REJECTED\n'
            log = out / 'mock.log'
            log.write_text(text)
            expected_message = expected[index] if expected else None
            valid = effective_ok if expected is None else not effective_ok and expected_message in text
            row = dict(template=name, scenario=scenario, passed=valid,
                       mock_tcl_returncode=proc.returncode, effective_gate_accepted=effective_ok,
                       expected_rejection=expected_message, mock_log_sha256=sha(log),
                       copied_template_sha256=sha(candidate))
            rows.append(row)
            assert valid, row
    result = dict(schema='ec-host40-gate-control-flow-audit/1',
                  status='PASS_MOCKED_TCL_GATE_REJECTIONS_NOT_PHYSICAL_CERTIFICATION',
                  functional_baseline=BASE, source_capsule=str(C),
                  audit_script_sha256=sha(__file__), templates_sha256=templates,
                  clock_contract_sha256=sha(contract_path), clock_count=len(periods),
                  installation_manifest_checks=installation_checks,
                  certificate_sha256=sha(C / 'certificate.py'),
                  exact_python_clock_coverage_regexes=coverage_regexes,
                  cases=rows, case_count=len(rows),
                  positive_cases=sum(x['scenario'] == 'valid' for x in rows),
                  negative_cases=sum(x['scenario'] != 'valid' for x in rows),
                  no_vivado_executed=True, no_bitstream_generated=True,
                  fpga_access=False, physical_timing_pass=False,
                  limitations=['Vendor APIs and timing/report values are mocked.',
                               'Does not validate Vivado command availability, actual routing or timing.',
                               'Does not certify full Python artifact/hash transport or measured hardware.',
                               'Installed/live source capsules and inputs were not edited.'],
                  completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    save(OUT / 'result.json', result)
    save(OUT / 'complete.json', dict(result_sha256=sha(OUT / 'result.json')))
    print(json.dumps({k: result[k] for k in ['status', 'case_count', 'positive_cases', 'negative_cases', 'fpga_access']}))


if __name__ == '__main__':
    main()
