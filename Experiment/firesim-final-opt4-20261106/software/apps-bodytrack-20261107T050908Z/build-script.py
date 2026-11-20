#!/usr/bin/env python3
"""Build original serial Bodytrack/Freqmine and audit their complete official ROI."""
import argparse
import datetime as dt
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tarfile
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC')
TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    ap=argparse.ArgumentParser();ap.add_argument('program',choices=['bodytrack','freqmine']);a=ap.parse_args();name=a.program
    receipt=W/f'software/{name}-apps-build.json';assert not receipt.exists()
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-'+name+'-'+stamp);logs=D/'software'/out.name
    out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir'])
    src=out/'src'/name;shutil.copytree(P/f'pkgs/apps/{name}/src',src)
    hooks=out/'src/hooks';shutil.copytree(base/'src/hooks',hooks)
    for n in ['hooks.o','dac_roi.o','roi-smoke']:shutil.copy2(base/n,out/n)
    units=([src/'TrackingBenchmark'/n for n in ['AnnealingFactor.cpp','BodyGeometry.cpp','BodyPose.cpp','CameraModel.cpp','CovarianceMatrix.cpp','ImageMeasurements.cpp','ImageProjection.cpp','RandomGenerator.cpp','TrackingModel.cpp','main.cpp']]+[src/'FlexImageLib/FlexImage.cpp',src/'FlexImageLib/FlexIO.cpp']) if name=='bodytrack' else [src/n for n in ['fpmax.cpp','data.cpp','fp_tree.cpp','buffer.cpp','fsout.cpp','fp_node.cpp','wtime.cpp']]
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='original-'+name+'-serial',formal_eligible=True,commands=[],cases=[],parsec_commit=parent['parsec_commit'],algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    save(logs/'state.json',state);shutil.copy2(__file__,logs/'build-script.py')
    (out/'diagnostic-hooks.c').write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1'}
    def run(argv,cwd=out,stdout=None,stderr=None):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));save(logs/'state.json',state)
        subprocess.run(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,check=True,timeout=1800)
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-std=gnu++17','-I'+str(hooks),'-I'+str(src)]
    if name=='bodytrack':flags+=['-I'+str(src/'FlexImageLib'),'-I'+str(src/'TrackingBenchmark')]
    with (logs/'build.log').open('wb') as build:
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc','-static','-march=rv64gc','-mabi=lp64d','-I'+str(hooks),'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=build,stderr=build)
        for target,objects in [(name,[out/'hooks.o',out/'dac_roi.o']),(name+'-reference',[]),(name+'-diagnostic',[out/'diagnostic-hooks.o'])]:
            run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,*(['-DENABLE_PARSEC_HOOKS'] if objects else []),*units,*objects,'-lm','-pthread','-o',out/target],stdout=build,stderr=build)
    cases=[]
    for size in ['test','simsmall','simmedium']:
        dest=out/'inputs'/name/size;dest.mkdir(parents=True)
        archive=P/f'pkgs/apps/{name}/inputs/input_{size}.tar'
        with tarfile.open(archive) as tf:
            for m in tf.getmembers():
                if not m.isfile():continue
                p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts
                target=dest/p;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(tf.extractfile(m).read())
        conf=P/f'pkgs/apps/{name}/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
        ref=logs/('reference-'+size);shutil.copytree(dest,ref)
        with (ref/'stdout.log').open('wb') as so:run(['/usr/bin/qemu-riscv64',out/(name+'-reference'),*argv],cwd=ref,stdout=so,stderr=so)
        if name=='bodytrack':
            result_file=argv[0]+'/poses.txt';expected=ref/result_file;assert len(expected.read_text().splitlines())==int(argv[2]);validation=dict(kind='files_sha256',files={result_file:sha(expected)})
        else:
            expected=ref/'counts.txt';lines=re.findall(r'^\d+$',(ref/'stdout.log').read_text(),re.M);assert lines
            expected.write_text('\n'.join(lines)+'\n');validation=dict(kind='stdout_integer_hash',reference=str(expected),reference_sha256=sha(expected))
        diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag)
        with (diag/'trace.log').open('wb') as trace:run(['/usr/bin/qemu-riscv64','-strace',out/(name+'-diagnostic'),*argv],cwd=diag,stdout=trace,stderr=trace)
        rows=(diag/'trace.log').read_text().splitlines();begin=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        calls=[l for l in rows[begin+1:end] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        if name=='bodytrack':assert sha(diag/result_file)==sha(expected)
        cases.append(dict(program=name,input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,reference_outputs={str(expected):sha(expected)},validation=validation,software_reference='QEMU_RISCV_USER_ONLY',fpga_validation='NOT_RUN',algorithm_unchanged=True,diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log')))
    binary=out/name;reference=out/(name+'-reference')
    state.update(status='PREPARED_FPGA_NOT_RUN',cases=cases,
        c4_incompatible_reason='Synchronous syscalls in original ROI; software staging or protocol support required' if any(c['diagnostic_roi_syscalls'] for c in cases) else None,
        binaries={name:dict(path=str(binary),sha256=sha(binary),reference_path=str(reference),reference_sha256=sha(reference),application_threads=1,algorithm_sources_modified=False)},smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),sources={str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()},formal_input_policy='Official simmedium, one thread, original full computation ROI, no warmup; exact complete output check')
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state);print(json.dumps(dict(receipt=str(receipt),roi_syscall_counts={c['input']:len(c['diagnostic_roi_syscalls']) for c in cases})),flush=True)


if __name__=='__main__':main()
