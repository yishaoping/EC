#!/usr/bin/env python3
"""Build the frozen96-line same-L2-set complete History pressure workload."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
sys.path.insert(0, str(HERE.parent / 'rollback'))
from build_io_observer import digest


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--out', type=Path, required=True)
    a = p.parse_args()
    out = a.out.resolve()
    assert out.is_relative_to(ROOT / 'AI/TMP') and not out.exists()
    out.mkdir()
    include = out / 'include/riscv-pk'
    include.mkdir(parents=True)
    (include / 'encoding.h').symlink_to(ROOT / 'chipyard/toolchains/riscv-tools/riscv-pk/machine/encoding.h')
    gloss = ROOT / 'chipyard/toolchains/libgloss'
    (out / 'htif.ld').symlink_to(gloss / 'util/htif.ld')
    sw = ROOT / 'Software/Test'
    tool = ROOT / 'chipyard/.conda-env/riscv-tools/bin/riscv64-unknown-elf-'
    sources = [HERE / 'history_pressure_workload.c', sw / 'hw/interrupt.c',
               sw / 'stat/report.c', sw / 'core/secondary.c', sw / 'cfg/init.c',
               sw / 'core/checker.c', sw / 'hw/spin_lock.c']
    inputs = sources + list(sw.rglob('*.h')) + [Path(__file__).resolve(),
        include / 'encoding.h', out / 'htif.ld', gloss / 'util/htif_nano.specs']
    hashes = {str(x): digest(x) for x in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    args = [str(tool) + 'gcc', '-fno-common', '-fno-builtin-printf',
        '-specs=' + str(gloss / 'util/htif_nano.specs'), '-L' + str(gloss / 'build'),
        '-I' + str(out / 'include'), '-I' + str(sw), '-I' + str(sw / 'hw'),
        '-march=rv64imafd', '-O2', '-static',
        '-DMEEK_ENABLE_BIG_CORE_PERF=0', '-DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1']
    args += list(map(str, sources)) + ['-o', str(out / 'palimpsest.riscv')]
    (out / 'compile.command.json').write_text(json.dumps(args, indent=2) + '\n')
    with (out / 'compile.log').open('x') as log:
        ret = subprocess.run(args, cwd=out, stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'compile.exit').write_text(str(ret) + '\n')
    assert not ret
    with (out / 'palimpsest.hex').open('xb') as image:
        subprocess.run(['bash', str(ROOT / 'chipyard/scripts/smartelf2hex.sh'),
                       str(out / 'palimpsest.riscv')], cwd=out, stdout=image, check=True)
    with (out / 'palimpsest.dump').open('xb') as listing:
        subprocess.run([str(tool) + 'objdump', '-d', '-S', str(out / 'palimpsest.riscv')],
                       cwd=out, stdout=listing, check=True)
    assert all(digest(Path(x)) == h for x, h in hashes.items()), 'workload input changed'
    (out / 'outputs.json').write_text(json.dumps({str(out / x): digest(out / x)
        for x in ('palimpsest.riscv', 'palimpsest.hex', 'palimpsest.dump')}, indent=2) + '\n')
    print(out / 'palimpsest.riscv')


if __name__ == '__main__':
    main()
