#!/usr/bin/env python3
"""Compile the frozen B v5 RTL with the native FireSim U280 flow. No device access."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

from build_minimal import ROOT, BASE, inventory, resource_check, sha, write

SOURCE_ID = 'be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4'
CY = BASE / 'opt4-roi-v5/B/chipyard'
GG = ROOT / 'Experiment/dac2026/build-logs/opt4-roi-v5/B-goldengate-20261102T092249.372031Z/result.json'
VIVADO = Path('/tools/Xilinx/Vivado/2021.1/bin/vivado')


def main():
    lock = open(BASE / '.dac-compile.lock', 'a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    resources = resource_check()
    current = inventory(CY)
    if hashlib.sha256(json.dumps(current, sort_keys=True).encode()).hexdigest() != SOURCE_ID:
        raise RuntimeError('frozen B v5 source content changed')
    gg = json.loads(GG.read_text())
    if gg['returncode'] or gg['source_id'] != SOURCE_ID:
        raise RuntimeError('GoldenGate receipt mismatch')
    generated = Path(gg['output_dir'])
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    name = 'B-bitstream-' + stamp
    logs = ROOT / 'Experiment/dac2026/build-logs/opt4-roi-v5' / name
    logs.mkdir()
    out = BASE / 'opt4-roi-v5/builds' / name
    # Dereference the official U280 -> U250 links into an isolated CAD directory.
    # The frozen source and generated RTL remain untouched.
    platform = CY / 'sims/firesim/platforms/xilinx_alveo_u280/cl_firesim'
    shutil.copytree(platform, out, symlinks=False)
    inputs = {str(GG): sha(GG)}
    for path in sorted(out.rglob('*')):
        if path.is_file():
            inputs[str(path)] = sha(path)
    for suffix in ['sv', 'defines.vh', 'synthesis.xdc', 'implementation.xdc']:
        src = generated / ('FireSim-generated.' + suffix)
        if gg['outputs'].get(str(src)) != sha(src):
            raise RuntimeError('generated input changed: ' + str(src))
        shutil.copy2(src, out / 'design' / src.name)
        inputs[str(src)] = sha(src)
    # Resource-only edits in the CAD copy; the normal native platform integration
    # (main.tcl, board BD, synthesis and timing-gated implementation) is retained.
    (out / 'scripts/platform_env.tcl').write_text('set jobs 2\n')
    wrapper = out / 'scripts/dac_compile.tcl'
    wrapper.write_text('set_param general.maxThreads 2\nsource [file join [pwd] scripts main.tcl]\n')
    env = os.environ.copy()
    env.update(OMP_NUM_THREADS='2', MAKEFLAGS='-j1')
    argv = ['nice', '-n', '15', str(VIVADO), '-mode', 'batch', '-nojournal',
            '-log', str(logs / 'vivado.log'), '-source', str(wrapper),
            '-tclargs', '50', 'TIMING', 'au280']
    receipt = dict(configuration='B', integration='opt4-roi-v5', phase='bitstream',
                   source_id=SOURCE_ID, source_tree=str(CY), output_dir=str(out),
                   golden_gate_receipt=str(GG), inputs=inputs, argv=argv,
                   cwd=str(out), resources=resources, host_fpga_clock_mhz=50,
                   target_boom_clock_mhz=200, jobs=2, max_threads=2,
                   no_target_execution=True, runtime_validation='NOT_RUN',
                   status='RUNNING', returncode=None, certified_bitstream=False)
    write(logs / 'command.json', receipt)
    shutil.copy2(__file__, logs / 'build-script.py')
    print(logs, flush=True)
    with (logs / 'build.log').open('wb', buffering=0) as stream:
        rc = subprocess.run(argv, cwd=out, env=env, stdout=stream, stderr=subprocess.STDOUT).returncode
    bit = out / 'vivado_proj/firesim.bit'
    if rc == 0 and (not bit.is_file() or not bit.stat().st_size):
        rc = 1
    if inventory(CY) != current:
        rc = 1
        receipt['error'] = 'source changed during CAD compilation'
    receipt.update(returncode=rc, status='PASSED' if rc == 0 else 'FAILED',
                   certified_bitstream=(rc == 0),
                   outputs={str(bit): sha(bit)} if bit.is_file() else {})
    write(logs / 'result.json', receipt)
    print('returncode=' + str(rc), flush=True)
    return rc


if __name__ == '__main__':
    sys.exit(main())
