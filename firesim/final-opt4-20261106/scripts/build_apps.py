#!/usr/bin/env python3
"""Build unmodified serial Linux PARSEC programs with the existing real ROI ABI.

Reference executables omit hooks and run under QEMU user mode. Those runs are
software references only and never count as DUT or FPGA validation.
"""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tarfile
import time

ROOT = Path('/data1/gzh/EC')
WORK = ROOT / 'firesim/final-opt4-20261106'
DATA = ROOT / 'Experiment/firesim-final-opt4-20261106'
PARSEC = ROOT / 'Software/PARSEC'
TOOLS = ROOT / 'firesim/envs/manager-1.17.1/riscv-tools/bin'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def atomic(p, d):
    temp = p.with_suffix(p.suffix + '.tmp')
    with temp.open('w') as f:
        json.dump(d, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    temp.replace(p)


def main():
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = WORK / 'software' / ('apps-' + stamp)
    logs = DATA / 'software' / ('apps-' + stamp)
    out.mkdir(parents=True, exist_ok=False)
    logs.mkdir(parents=True, exist_ok=False)
    record = dict(status='BUILDING', pid=os.getpid(), output_dir=str(out),
                  host_log_dir=str(logs), target_execution='NOT_RUN',
                  fpga_validation='NOT_RUN', commands=[], references=[],
                  parsec_commit=subprocess.check_output(
                      ['git', '-C', str(PARSEC), 'rev-parse', 'HEAD'], text=True).strip(),
                  script_sha256=sha(__file__))
    atomic(logs / 'state.json', record)
    shutil.copy2(__file__, logs / 'build-script.py')
    sources = out / 'src'
    sources.mkdir()
    flags = ['-O3', '-march=rv64gc', '-mabi=lp64d', '-D_GNU_SOURCE', '-static']
    hooks = sources / 'hooks'
    hooks.mkdir()
    header = PARSEC / 'pkgs/libs/hooks/src/include/hooks.h'
    shutil.copy2(header, hooks / 'hooks.h')
    for name in ['dac_roi.c', 'dac_roi.h', 'opt4_hw.h', 'ec_dac_roi_uapi.h']:
        shutil.copy2(ROOT / 'firesim/dac2026/checker-v6' / name, hooks / name)
    (hooks / 'hooks.c').write_text('''#include "hooks.h"
#include "dac_roi.h"
#include <stdio.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {
    printf("EC_PARSEC_BENCH_BEGIN id=%d\\n", (int)b); fflush(stdout);
}
void __parsec_bench_end(void) { puts("EC_PARSEC_BENCH_END"); fflush(stdout); }
void __parsec_roi_begin(void) { ec_dac_roi_begin(); }
void __parsec_roi_end(void) { ec_dac_roi_end(); }
''')
    env = os.environ.copy()
    for k in ['CFLAGS', 'CXXFLAGS', 'CPPFLAGS', 'LDFLAGS', 'LD_LIBRARY_PATH', 'LD_PRELOAD']:
        env.pop(k, None)
    env['PATH'] = '/usr/bin:/bin'
    with (logs / 'build.log').open('wb', buffering=0) as stream:
        def run(argv, cwd=out, timeout=300, stdout=stream):
            argv = list(map(str, argv))
            entry = dict(argv=argv, cwd=str(cwd), started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            record['commands'].append(entry)
            atomic(logs / 'state.json', record)
            start = time.monotonic()
            p = subprocess.run(argv, cwd=cwd, env=env, stdin=subprocess.DEVNULL,
                               stdout=stdout, stderr=stream, timeout=timeout)
            entry.update(returncode=p.returncode, wall_seconds=time.monotonic()-start)
            atomic(logs / 'state.json', record)
            if p.returncode:
                raise RuntimeError('command failed: ' + str(argv))
        gcc = TOOLS / 'riscv64-unknown-linux-gnu-gcc'
        gxx = TOOLS / 'riscv64-unknown-linux-gnu-g++'
        run([gcc, *flags, '-I'+str(hooks), '-c', hooks/'hooks.c', '-o', out/'hooks.o'])
        run([gcc, *flags, '-I'+str(hooks), '-c', hooks/'dac_roi.c', '-o', out/'dac_roi.o'])
        binaries = {}
        for name, pkg in [('streamcluster', 'kernels'), ('canneal', 'kernels'), ('blackscholes', 'apps')]:
            src = sources / name
            original = PARSEC / f'pkgs/{pkg}/{name}/src'
            shutil.copytree(original, src, ignore=shutil.ignore_patterns('*.o', '*.a', '*.dump', '*.log', name))
            if name == 'canneal':
                units = [src / n for n in ['annealer_thread.cpp','rng.cpp','netlist.cpp','main.cpp','netlist_elem.cpp']]
            else:
                units = [src / ('blackscholes.c' if name == 'blackscholes' else 'streamcluster.cpp')]
            common = [gxx, *flags, '-std=gnu++17', '-I'+str(hooks), '-I'+str(src), '-x', 'c++', *units, '-x', 'none']
            # ENABLE_THREADS stays undefined: the original serial branch runs in one Linux context.
            run([*common, '-DENABLE_PARSEC_HOOKS', out/'hooks.o', out/'dac_roi.o', '-lm', '-pthread', '-o', out/name])
            run([*common, '-lm', '-pthread', '-o', out/(name+'-reference')])
            binaries[name] = {'path': str(out/name), 'sha256': sha(out/name),
                              'reference_path': str(out/(name+'-reference')),
                              'reference_sha256': sha(out/(name+'-reference')),
                              'application_threads': 1, 'algorithm_sources_modified': False}
        cases = []
        for size in ['test', 'simsmall']:
            for name, pkg in [('streamcluster','kernels'),('canneal','kernels'),('blackscholes','apps')]:
                dest = out/'inputs'/name/size
                dest.mkdir(parents=True)
                input_hashes = {}
                if name != 'streamcluster':
                    archive = PARSEC / f'pkgs/{pkg}/{name}/inputs/input_{size}.tar'
                    input_hashes[str(archive)] = sha(archive)
                    with tarfile.open(archive) as tf:
                        for member in tf.getmembers():
                            if not member.isfile():
                                continue
                            p = Path(member.name)
                            if p.is_absolute() or '..' in p.parts:
                                raise ValueError('unsafe archive member')
                            target = dest/p
                            target.parent.mkdir(parents=True, exist_ok=True)
                            target.write_bytes(tf.extractfile(member).read())
                conf = PARSEC / f'pkgs/{pkg}/{name}/parsec/{size}.runconf'
                match = re.search(r'^run_args="(.*)"$', conf.read_text(), re.M)
                args = match.group(1).replace('${NTHREADS}', '1').split()
                case = dict(program=name, input=size, argv=args, runconf=str(conf),
                            runconf_sha256=sha(conf), input_archives=input_hashes,
                            input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},
                            warmups=0, threads=1, fpga_validation='NOT_RUN')
                ref = logs / 'references' / (name+'-'+size)
                shutil.copytree(dest, ref)
                with (ref/'stdout.log').open('wb') as output:
                    run(['/usr/bin/qemu-riscv64', out/(name+'-reference'), *args], cwd=ref, stdout=output)
                outputs = ['output.txt'] if name=='streamcluster' else ['prices.txt'] if name=='blackscholes' else ['stdout.log']
                if name=='canneal':
                    text = (ref/'stdout.log').read_text()
                    found = re.search(r'^Final routing is: (.+)$', text, re.M)
                    if not found:
                        raise RuntimeError('missing canneal routing result')
                    case['expected_final_routing'] = found.group(1)
                case['reference_outputs'] = {str(ref/n):sha(ref/n) for n in outputs}
                case['software_reference'] = 'QEMU_RISCV_USER_ONLY; not FPGA evidence'
                cases.append(case)
        run([gcc, *flags, '-I'+str(hooks), ROOT/'firesim/dac2026/guest/roi-smoke.c',
             out/'dac_roi.o', '-o', out/'roi-smoke'])
        # Real-hook execution must fail closed on a machine without the ROI device.
        with (logs/'missing-driver.log').open('wb') as output:
            p = subprocess.run(['/usr/bin/qemu-riscv64', str(out/'roi-smoke')],
                               stdout=output, stderr=subprocess.STDOUT, timeout=10)
        if p.returncode != 125:
            raise RuntimeError('missing real ROI driver did not fail closed')
        record.update(status='BUILT_REFERENCES_EXECUTED_FPGA_NOT_RUN', binaries=binaries,
                      cases=cases, missing_driver_exit=p.returncode,
                      sources={str(p.relative_to(sources)):sha(p) for p in sources.rglob('*') if p.is_file()},
                      smoke={'path':str(out/'roi-smoke'),'sha256':sha(out/'roi-smoke')},
                      compiler_sha256=sha(gxx), qemu_sha256=sha('/usr/bin/qemu-riscv64'))
        atomic(out/'manifest.json', record)
        atomic(logs/'state.json', record)
        atomic(WORK/'software/apps-build.json', record)
        print(out/'manifest.json', flush=True)


if __name__ == '__main__':
    main()
