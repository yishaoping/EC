#!/usr/bin/env python3
"""One completion event: bind actual physical evidence, then deploy card 21.

No periodic monitoring, model requests, synthesis, or parallel implementation.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import select
import shutil
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'performance-only-cdc-lowfreq-r1-20261114'
F = D/'performance-only-memory-cdc-r2-20261114/complete-shell-r3'
R = W/'runtime/Opt4-performance-only-cdc-mem-6e1e9b96-r1'
HW = '6e1e9b966d599c442b3bdf2f3a838aae2ee5c6da'
BDF = '0000:21:00.0'
SERIAL = '21770433G02LA'


def read(p): return json.loads(Path(p).read_text())
def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''): h.update(block)
    return h.hexdigest()
def save(p, row):
    p = Path(p); tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(row, indent=2)+'\n'); os.replace(tmp, p)
def state(status, **kw):
    save(O/'completion-handoff-state.json', dict(status=status,
         utc=dt.datetime.now(dt.timezone.utc).isoformat(), model_requests=False, **kw))


def certify():
    result = read(O/'result.json')
    assert result.get('returncode') == 0 and result.get('bitstream_generated') is True
    p = O/'physical/candidates'/result['candidate']
    assert p.parent == O/'physical/candidates'
    assert result['candidate'] in ['mem-15mhz-altspreadlogic_high', 'mem-10mhz-ssi_spreadslls', 'mem-10mhz-recovery-r2', 'mem-10mhz-fresh-ssi-r3']
    assert sha(p/'run.tcl') == result['tcl_sha256']
    spec = importlib.util.spec_from_file_location('physical_metrics',
        W/'candidates/performance-only-routability-r1-20261114/campaign.py')
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    route = m.route_metrics(p/'route-status.rpt')
    timing = m.timing_metrics(p/'timing.rpt')
    assert route['legal'] and route['routable'] > 0
    assert all(timing[k] >= 0 for k in ['wns', 'tns', 'whs', 'ths'])
    assert timing['setup_endpoints'] == timing['hold_endpoints'] == 0
    text = (p/'timing.rpt').read_text()
    assert 'Timing constraints are not met' not in text
    row = next(l.split() for l in text.splitlines()
               if re.match(r'^\s*[-0-9.]+\s+[-0-9.]+\s+\d+\s+\d+\s+[-0-9.]+', l))
    assert len(row) >= 12 and float(row[8]) >= 0 and float(row[9]) >= 0
    for name in ['drc.rpt', 'methodology.rpt']:
        assert not re.search(r'\|\s*(Error|Critical Warning)\s*\|', (p/name).read_text())
    assert not re.search(r'VIOLATED|constraints are not met', (p/'bus-skew.rpt').read_text(), re.I)
    assert not re.search(r'checking [a-z_]+ \([1-9][0-9]*\)', (p/'check-timing.rpt').read_text())
    assert 'EC_PHYSICAL_BITSTREAM_GENERATED_NOT_RUNTIME_CERTIFIED' in (p/'vivado.log').read_text()
    cad = read(F/'cad-state.json'); binding = read(F/'hardware-binding.json')
    assert cad['hardware_commit'] == binding['hardware_commit'] == HW
    assert cad['source_id'] == binding['source_id']
    for filename, digest in cad['inputs']['generated'].items(): assert sha(filename) == digest
    for stage in ['dut_synth', 'top_synth', 'implementation']:
        receipt = read(F/(stage+'-result.json'))
        assert receipt['returncode'] == 0 and receipt['hardware_commit'] == HW
        assert receipt['source_id'] == binding['source_id']
        for filename, digest in receipt['outputs'].items(): assert sha(filename) == digest
    for item in cad['top_postopt_resources'].values(): assert 0 <= item['used'] <= item['available']
    audit = read(O/'driver-interface-audit.json')
    assert audit['hardware_commit'] == HW and audit['software_abi_byte_equal']
    for item in audit['generated_inputs']:
        assert item['byte_equal'] and sha(item['original']) == sha(item['current']) == item['current_sha256']
    prior_driver = W/'runtime/Opt4-performance-only-6fada307-bound-r1/driver-receipt.json'
    driver = read(prior_driver)
    exe = Path(driver['output_dir'])/'FireSim-xilinx_alveo_u280'
    assert driver['returncode'] == 0 and sha(exe) == driver['outputs'][str(exe)]
    R.mkdir(exist_ok=True)
    bit = R/'firesim.bit'
    if bit.exists(): assert sha(bit) == sha(p/'firesim.bit')
    else: shutil.copy2(p/'firesim.bit', bit)
    assert bit.stat().st_size > 0
    evidence = [p/n for n in ['result.json', 'run.tcl', 'route-status.rpt', 'timing.rpt',
        'drc.rpt', 'methodology.rpt', 'bus-skew.rpt', 'check-timing.rpt',
        'final-clocks.rpt', 'final-clock-interaction.rpt', 'clock-contract.txt',
        'certification-input.dcp', 'utilization.rpt', 'per-slr-final.rpt']]
    evidence += [F/n for n in ['dut_synth-result.json', 'top_synth-result.json',
        'implementation-result.json', 'hardware-binding.json', 'module-admission.json']]
    save(R/'certified-build.json', dict(schema='ec-performance-only-cdc-mem-physical-certificate/1',
        status='PHYSICAL_TIMING_DRC_CERTIFIED_NOT_FPGA_VALIDATED', hardware_commit=HW,
        source_id=binding['source_id'], frozen_full_ec=cad['frozen_parent_commit'],
        performance_baseline='6fada307bb77be90b39720d3f95404fece0e431b', full_PALIMPSEST=False,
        profile='EC Performance-Only: CDC Mem data preservation + cache isolation',
        part=cad['part'], configuration=cad['configuration'], candidate=result['candidate'],
        bitstream=str(bit), bitstream_sha256=sha(bit), routing=route, timing=timing,
        evidence={str(q): sha(q) for q in evidence},
        driver_compatibility_audit=str(O/'driver-interface-audit.json'),
        driver_compatibility_audit_sha256=sha(O/'driver-interface-audit.json'),
        compatible_driver=str(exe), compatible_driver_sha256=sha(exe),
        prior_driver_receipt=str(prior_driver), prior_driver_receipt_sha256=sha(prior_driver),
        board_bdf=BDF, board_serial=SERIAL, fpga_runtime_validated=False))
    return R/'certified-build.json'


def deploy(cert):
    assert os.geteuid() == 0, 'target-card deployment requires administrator privileges'
    assert cert.resolve() == (R/'certified-build.json').resolve()
    row = read(cert)
    assert row['hardware_commit'] == HW and row['board_bdf'] == BDF and row['board_serial'] == SERIAL
    assert row['status'] == 'PHYSICAL_TIMING_DRC_CERTIFIED_NOT_FPGA_VALIDATED'
    assert sha(row['bitstream']) == row['bitstream_sha256']
    for filename, digest in row['evidence'].items(): assert sha(filename) == digest
    sys.path.insert(0, str(W/'scripts')); import board_batch as b
    # The same per-card lock used by existing runners; block until a safe
    # boundary, without signalling an active sample or another board.
    lock = (D/'locks/maintenance-0000_21_00.0.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX)
    out = O/'deployment21'; out.mkdir(exist_ok=True)
    check = b.precheck(target_bdfs=[BDF]); b.save(out/'pre-deployment.json', check)
    assert not check['open_devices'] and not check['simulation_processes']
    b.ensure_jtag_server(out, [SERIAL])
    check = b.precheck(target_bdfs=[BDF]); b.save(out/'pre-maintenance.json', check)
    assert not check['open_devices'] and not check['simulation_processes']
    b.command(['/usr/bin/python3', W/'deployment-tools/fpga-util.py', '--extended-bdf', BDF,
        '--bitstream', row['bitstream'], '--vivado-bin', '/tools/Xilinx/Vivado/2021.1/bin/vivado',
        '--hw-server-bin', '/tools/Xilinx/Vivado/2021.1/bin/hw_server'],
        out, out/'deployment.log', timeout=900)
    b.save(out/'deployment.json', dict(status='DEPLOYED_CARD21_NOT_RUNTIME_VALIDATED',
        board_bdf=BDF, board_serial=SERIAL, hardware_commit=HW,
        certificate_sha256=sha(cert), bitstream_sha256=row['bitstream_sha256'],
        global_driver_operations=[], other_boards_touched=False,
        postcheck=b.precheck(target_bdfs=[BDF])))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--wait-pid', type=int); ap.add_argument('--start-ticks')
    ap.add_argument('--deploy21', type=Path); a = ap.parse_args()
    if a.deploy21: deploy(a.deploy21); return
    if a.wait_pid:
        fd = os.pidfd_open(a.wait_pid)
        fields = Path(f'/proc/{a.wait_pid}/stat').read_text().rsplit(') ', 1)[1].split()
        assert fields[19] == a.start_ticks
        state('WAITING_SINGLE_PHYSICAL_COMPLETION_EVENT', owner_pid=a.wait_pid, periodic_checks=False)
        poller = select.poll(); poller.register(fd, select.POLLIN); poller.poll(); os.close(fd)
    result = read(O/'result.json')
    if not result.get('bitstream_generated'):
        state('PHYSICAL_ATTEMPTS_FAILED_EVIDENCE_RETAINED', result=result, fpga_access=False)
        return
    cert = certify()
    state('PHYSICAL_CERTIFIED_ATTEMPTING_STRICT_CARD21_DEPLOYMENT', certificate=str(cert))
    with (O/'deployment21-command.log').open('ab') as log:
        cmd = ['/usr/bin/python3', str(C/'fresh-after-physical.py'), '--deploy21', str(cert)]
        if os.geteuid() != 0: cmd = ['/usr/bin/sudo', '-n', *cmd]
        completed = subprocess.run(cmd, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
    state('CARD21_DEPLOYED_RUNTIME_VALIDATION_PENDING' if completed.returncode == 0 else
          'CARD21_DEPLOYMENT_BLOCKED_SEE_EXACT_LOG', certificate=str(cert),
          returncode=completed.returncode, log=str(O/'deployment21-command.log'))


if __name__ == '__main__':
    try: main()
    except Exception as e:
        state('COMPLETION_HANDOFF_FAILED_WITH_EVIDENCE', error=repr(e))
        raise
