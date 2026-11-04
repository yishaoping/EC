#!/usr/bin/env python3
"""Build C4's U280 bitstream from frozen, matched compiler inputs.

Pure CAD only: this script never opens, programs, resets, or enumerates an FPGA.
Linux smoke may still be running; that state is recorded, never called PASS.
"""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import time

from build_minimal import ROOT, BASE, inventory, resource_check, sha, write

WORK = BASE / 'opt4-linux-v6'
CY = WORK / 'C4/chipyard'
VIVADO = Path('/tools/Xilinx/Vivado/2021.1/bin/vivado')
BOARDS = ROOT / 'firesim/dac2026/deps/boards'
EXPECTED_FS = '07efa6a6da18bd64d1159ae84a4701b37abb1228'


def checked(path, expected_phase, expected_source=None):
    path = Path(path).resolve()
    record = json.loads(path.read_text())
    if record.get('returncode') != 0 or record.get('phase') != expected_phase:
        raise ValueError(f'not a successful {expected_phase} receipt: {path}')
    if expected_source and record.get('source_id') != expected_source:
        raise ValueError(f'{expected_phase} source mismatch: {path}')
    for artifact, digest in record.get('outputs', {}).items():
        if not Path(artifact).is_file() or sha(artifact) != digest:
            raise ValueError('receipt output changed: ' + artifact)
    return record


def main():
    import argparse
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--goldengate-result', type=Path, required=True)
    p.add_argument('--driver-result', type=Path, required=True)
    p.add_argument('--stage-a-result', type=Path, required=True,
                   help='valid complete Stage A result, not only a prepared manifest')
    linux = p.add_mutually_exclusive_group(required=True)
    linux.add_argument('--stage-b-result', type=Path,
                   help='valid C4 Linux smoke verification.json')
    linux.add_argument('--stage-b-attempt', type=Path,
                   help='already running, version-bound native smoke; pure CAD only, not runtime certification')
    a = p.parse_args()

    lock = open(BASE / '.dac-compile.lock', 'a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    resources = resource_check()
    if not VIVADO.is_file():
        raise ValueError('Vivado 2021.1 executable missing: ' + str(VIVADO))

    gg = checked(a.goldengate_result, 'goldengate')
    driver = checked(a.driver_result, 'driver', gg['source_id'])
    if gg.get('integration') != 'opt4-linux-v6' or driver.get('integration') != 'opt4-linux-v6':
        raise ValueError('receipt is not from the isolated opt4-linux-v6 source tree')
    if gg.get('config') != 'DacOpt4C4' or driver.get('platform_config') != 'DacXilinxAlveoConfig':
        raise ValueError('wrong C4 FireSim target/platform configuration')
    if gg.get('firesim_commit') != EXPECTED_FS or driver.get('firesim_commit') != EXPECTED_FS:
        raise ValueError('FireSim submodule commit mismatch')

    stage_a = json.loads(a.stage_a_result.read_text())
    if stage_a.get('valid') is not True or stage_a.get('runtime_validation') != 'PASS':
        raise ValueError('Stage A has no valid real-run completion evidence')
    if a.stage_b_result:
        stage_b_input = a.stage_b_result.resolve()
        stage_b = json.loads(stage_b_input.read_text())
        if stage_b.get('valid') is not True or stage_b.get('runtime_validation') != 'PASS' or \
                stage_b.get('mode') != 'smoke':
            raise ValueError('C4 Linux smoke has no valid real-run completion evidence')
        linux_validation = 'PASS'
        stage_b_process = None
    else:
        from opt4_linux_run import receipts, identity, RESULTS
        attempt = a.stage_b_attempt.resolve()
        if attempt.parent != RESULTS / 'partial':
            raise ValueError('not an isolated native Linux attempt')
        stage_b_input = attempt / 'manifest.json'
        stage_b = json.loads(stage_b_input.read_text())
        stage_b_process = attempt / 'STARTED.json'
        started = json.loads(stage_b_process.read_text())
        if (stage_b.get('mode') != 'smoke' or
                stage_b['receipts']['native']['value'].get('configuration') != 'chipyard.DacLinuxC4' or
                started.get('identity') != stage_b.get('identity') or
                identity(receipts(stage_b.get('console', 'uart'), stage_b['receipts'])) != stage_b['identity']):
            raise ValueError('native smoke artifact/identity mismatch')
        if (attempt / 'exit.json').exists() or (attempt / 'verification.json').exists():
            raise ValueError('smoke already ended; inspect its result and use a valid verification receipt')
        linux_validation = 'RUNNING_NOT_VALIDATED'

    current = inventory(CY)
    source_id = hashlib.sha256(json.dumps(current, sort_keys=True).encode()).hexdigest()
    if source_id != gg['source_id'] or source_id != driver['source_id']:
        raise ValueError('current C4 source differs from compiled FireSim source')
    generated = Path(gg['output_dir'])
    for suffix in ['sv', 'defines.vh', 'synthesis.xdc', 'implementation.xdc']:
        src = generated / ('FireSim-generated.' + suffix)
        if gg['outputs'].get(str(src)) != sha(src):
            raise ValueError('GoldenGate input changed: ' + str(src))

    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    name = 'C4-bitstream-' + stamp
    logs = ROOT / 'Experiment/dac2026/build-logs/opt4-linux-v6' / name
    logs.mkdir(parents=True, exist_ok=False)
    out = WORK / 'builds' / name
    out.mkdir(parents=True, exist_ok=False)
    platform = CY / 'sims/firesim/platforms/xilinx_alveo_u280/cl_firesim'
    shutil.copytree(platform, out, symlinks=False, dirs_exist_ok=True)
    inputs = {
        str(a.goldengate_result.resolve()): sha(a.goldengate_result),
        str(a.driver_result.resolve()): sha(a.driver_result),
        str(a.stage_a_result.resolve()): sha(a.stage_a_result),
        str(stage_b_input): sha(stage_b_input),
    }
    if stage_b_process:
        inputs[str(stage_b_process)] = sha(stage_b_process)
    for path in sorted(out.rglob('*')):
        if path.is_file():
            inputs[str(platform / path.relative_to(out))] = sha(path)
    for suffix in ['sv', 'defines.vh', 'synthesis.xdc', 'implementation.xdc']:
        src = generated / ('FireSim-generated.' + suffix)
        shutil.copy2(src, out / 'design' / src.name)
        inputs[str(src)] = sha(src)
    (out / 'scripts/platform_env.tcl').write_text('set jobs 2\n')
    board_script = out / 'scripts/au280.tcl'
    board_script.write_text(board_script.read_text().replace(
        'xilinx.com:au280:part0:1.2', 'xilinx.com:au280:part0:1.1'))
    for path in sorted(BOARDS.rglob('*')):
        if path.is_file():
            inputs[str(path)] = sha(path)
    wrapper = out / 'scripts/dac_compile.tcl'
    wrapper.write_text('set_param general.maxThreads 2\nset_param board.repoPaths {' +
                       str(BOARDS) + '}\nsource [file join [pwd] scripts main.tcl]\n')
    effective_cad_inputs = {str(path): sha(path) for path in sorted(out.rglob('*')) if path.is_file()}
    argv = ['nice', '-n', '15', str(VIVADO), '-mode', 'batch', '-nojournal',
            '-log', str(logs / 'vivado.log'), '-source', str(wrapper),
            '-tclargs', '50', 'TIMING', 'au280']
    receipt = dict(configuration='C4', integration='opt4-linux-v6', phase='bitstream',
        source_id=source_id, source_tree=str(CY), firesim_commit=EXPECTED_FS,
        platform='xilinx_alveo_u280', target_config='DacOpt4C4',
        platform_config='DacXilinxAlveoConfig', output_dir=str(out),
        golden_gate_result=str(a.goldengate_result.resolve()), driver_result=str(a.driver_result.resolve()),
        stage_a_result=str(a.stage_a_result.resolve()),
        stage_b_result=str(a.stage_b_result.resolve()) if a.stage_b_result else None,
        stage_b_manifest=str(stage_b_input) if a.stage_b_attempt else None,
        linux_runtime_validation_at_build_start=linux_validation,
        deployment_eligible=False,
        inputs=inputs, effective_cad_inputs=effective_cad_inputs, argv=argv, cwd=str(out),
        resources=resources, host_fpga_clock_mhz=50, target_boom_clock_mhz=200,
        target_checker_clocks_mhz=[100, 100, 100, 100], jobs=2, max_threads=2,
        board_definition='xilinx.com:au280:part0:1.1 (physical revision 1.2)',
        no_fpga_device_access=True, target_execution='NOT_RUN', runtime_validation='NOT_RUN',
        status='RUNNING', returncode=None, certified_bitstream=False)
    write(logs / 'command.json', receipt)
    shutil.copy2(__file__, logs / 'build-script.py')
    print(logs, flush=True)
    start = time.monotonic()
    with (logs / 'build.log').open('wb', buffering=0) as stream:
        rc = subprocess.run(argv, cwd=out, stdout=stream, stderr=subprocess.STDOUT,
                            env={**os.environ, 'OMP_NUM_THREADS': '2', 'MAKEFLAGS': '-j1'}).returncode
    bit = out / 'vivado_proj/firesim.bit'
    if rc == 0 and (not bit.is_file() or not bit.stat().st_size):
        rc = 1
    if inventory(CY) != current:
        rc = 1
        receipt['error'] = 'C4 source changed during CAD compilation'
    if any(not Path(path).is_file() or sha(path) != digest
           for path, digest in effective_cad_inputs.items()):
        rc = 1
        receipt['error'] = 'effective CAD inputs changed during compilation'
    outputs = {str(bit): sha(bit)} if bit.is_file() else {}
    receipt.update(returncode=rc, wall_seconds=time.monotonic()-start,
        status='PASSED' if rc == 0 else 'FAILED', certified_bitstream=(rc == 0),
        runtime_validation='NOT_RUN', outputs=outputs)
    write(logs / 'result.json', receipt)
    print('returncode=' + str(rc), flush=True)
    return rc


if __name__ == '__main__':
    raise SystemExit(main())
