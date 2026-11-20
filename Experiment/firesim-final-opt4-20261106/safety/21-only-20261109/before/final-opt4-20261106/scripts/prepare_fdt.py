#!/usr/bin/env python3
"""Bind Linux DTs to actual hardware elaboration receipts, without changing RAM."""
import argparse
import datetime as dt
import hashlib
import json
from pathlib import Path
import re
import subprocess
from normalize_isa import normalize_dts

WORK = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
ENV = Path('/data1/gzh/EC/firesim/envs/manager-1.17.1')


def sha(f):
    return hashlib.sha256(Path(f).read_bytes()).hexdigest()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('configuration', choices=['Native', 'C4'])
    p.add_argument('--elaboration-result', type=Path, required=True)
    a = p.parse_args()
    r = json.loads(a.elaboration_result.read_text())
    assert r['phase'] == 'elaborate' and r['returncode'] == 0
    assert r['config'] == ('DacBaseline' if a.configuration == 'Native' else 'DacOpt4C4')
    files = [(Path(f), h) for f, h in r['outputs'].items() if f.endswith('.dts')]
    assert len(files) == 1
    src, digest = files[0]
    assert sha(src) == digest
    text = src.read_text()
    assert '"ec,dac-roi-v1"' in text and 'chosen {' not in text
    cpus = list(re.finditer(r'cpu@([0-9]+)\s*\{', text))
    harts = [int(m[1]) for m in cpus]
    assert harts == ([0] if a.configuration == 'Native' else [0, 1, 2, 3, 4])
    memory = re.search(r'memory@80000000\s*\{([^}]+)\}', text).group(1)
    assert 'reg = <0x0 0x80000000 0x4 0x0>;' in memory
    for m in reversed(cpus):
        pos = m.end()
        depth = 1
        while depth:
            depth += (text[pos] == '{') - (text[pos] == '}')
            pos += 1
        block = text[m.start():pos]
        hart = int(m[1])
        block, n = re.subn(r'status = "okay";', 'status = "'+('okay' if hart == 0 else 'disabled')+'";', block)
        assert n == 1
        block = block.replace('clock-frequency = <0>;', f'clock-frequency = <{200000000 if hart == 0 else 100000000}>;')
        text = text[:m.start()]+block+text[pos:]
    text, isa_normalization = normalize_dts(text)
    bootargs = 'console=ttySIF0,3686400 earlycon=sbi loglevel=7 rdinit=/init panic=-1 maxcpus=1'
    pos = text.rfind('};')
    text = text[:pos]+f'\tchosen {{\n\t\tbootargs = "{bootargs}";\n\t\tstdout-path = "serial0:3686400n8";\n\t}};\n'+text[pos:]
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out = WORK/'software'/a.configuration/('fdt-'+stamp)
    out.mkdir()
    dts = out/(a.configuration+'.dts')
    fdt = out/(a.configuration+'.dtb')
    dts.write_text(text)
    argv = [str(ENV/'bin/dtc'), '-I', 'dts', '-O', 'dtb', '-p', '4096', '-o', str(fdt), str(dts)]
    with (out/'dtc.log').open('wb') as log:
        subprocess.run(argv, stdout=log, stderr=subprocess.STDOUT, check=True)
    result = dict(schema='ec-firesim-fdt/1', phase='fdt', configuration=a.configuration, returncode=0,
                  elaboration_result=str(a.elaboration_result.resolve()), elaboration_result_sha256=sha(a.elaboration_result),
                  source_dts=str(src), source_dts_sha256=digest, dts=str(dts), dts_sha256=sha(dts),
                  fdt=str(fdt), sha256=sha(fdt), command=argv, bootargs=bootargs,
                  linux_harts=[0], firmware_checker_harts=harts[1:], target_memory_base=0x80000000,
                  target_memory_bytes=0x400000000, linux_mem_cap=None,
                  linux_profile_sha256=sha(WORK/'software/linux-profile.json'),
                  target_boom_hz=200000000, target_checker_hz=100000000 if a.configuration == 'C4' else None,
                  isa_normalization=isa_normalization, runtime_validation='NOT_RUN')
    content = json.dumps(result, indent=2)+'\n'
    (out/'result.json').write_text(content)
    (WORK/'software'/a.configuration/'fdt-build.json').write_text(content)
    print(out/'result.json')


if __name__ == '__main__':
    main()
