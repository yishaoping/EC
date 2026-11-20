#!/usr/bin/env python3
"""Compile PARSEC Fluidanimate serial source in an isolated Linux profile."""
import datetime as dt
import difflib
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
    receipt=W/'software/fluidanimate-apps-build.json'
    assert not receipt.exists()
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-fluidanimate-'+stamp);logs=D/'software'/out.name
    out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir'])
    src=out/'src/fluidanimate';shutil.copytree(P/'pkgs/apps/fluidanimate/src',src)
    hooks=out/'src/hooks';shutil.copytree(base/'src/hooks',hooks)
    for n in ['hooks.o','dac_roi.o','roi-smoke']:shutil.copy2(base/n,out/n)
    f=src/'serial.cpp';before=f.read_text()
    start=before.index('////////////////////////////////////////////////////////////////////////////////\nint uart_lock;')
    end=before.index('int main(int argc, char *argv[])',start)
    after=before[:start]+before[end:]
    legacy='  //pthread\n'
    start=after.index(legacy,after.index('int main('))
    end=after.index('#ifdef PARSEC_VERSION',start)
    after=after[:start]+after[end:]
    assert after.count('__parsec_roi_begin();')==1 and after.count('__parsec_roi_end();')==1
    f.write_text(after)
    (logs/'software-integration.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(P/'pkgs/apps/fluidanimate/src/serial.cpp'),tofile=str(f))))
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='fluidanimate-original-serial-no-legacy-checker-harness',formal_eligible=True,commands=[],cases=[],parsec_commit=parent['parsec_commit'],algorithm_sources_modified=False,platform_harness_removed=True,fpga_validation='NOT_RUN')
    save(logs/'state.json',state);shutil.copy2(__file__,logs/'build-script.py')
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':''}
    sources=[src/n for n in ['serial.cpp','cellpool.cpp']]
    hooks_cpp=out/'hooks.cpp';hooks_cpp.write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    def run(argv,cwd=out,stdout=None,stderr=None):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));save(logs/'state.json',state)
        subprocess.run(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,check=True,timeout=1800)
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-D_XOPEN_SOURCE=600','-Wno-invalid-offsetof','-I'+str(hooks),'-I'+str(src)]
    with (logs/'build.log').open('wb') as b:
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',hooks_cpp,'-o',out/'diagnostic-hooks.o'],stdout=b,stderr=b)
        for name,hook in [('fluidanimate',False),('fluidanimate-reference',False)]:
            cmd=[TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,'-std=gnu++17','-x','c++',*sources,'-x','none','-lm','-pthread']
            if name=='fluidanimate':cmd+=['-DENABLE_PARSEC_HOOKS',out/'hooks.o',out/'dac_roi.o']
            else:cmd+=['-DENABLE_PARSEC_HOOKS',out/'diagnostic-hooks.o']
            run([*cmd,'-o',out/name],stdout=b,stderr=b)
    binaries={}
    for name in ['fluidanimate','fluidanimate-reference']:
        binaries[name]=dict(path=str(out/name),sha256=sha(out/name),application_threads=1,algorithm_sources_modified=False)
    cases=[]
    for size in ['test','simsmall','simmedium']:
        dest=out/'inputs/fluidanimate'/size;dest.mkdir(parents=True)
        archive=P/f'pkgs/apps/fluidanimate/inputs/input_{size}.tar'
        with tarfile.open(archive) as tf:
            for m in tf.getmembers():
                if not m.isfile():continue
                p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts
                target=dest/p;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(tf.extractfile(m).read())
        conf=P/f'pkgs/apps/fluidanimate/parsec/{size}.runconf'
        argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
        ref=logs/('reference-'+size);shutil.copytree(dest,ref)
        with (ref/'stdout.log').open('wb') as so:run(['/usr/bin/qemu-riscv64',out/'fluidanimate-reference',*argv],cwd=ref,stdout=so,stderr=so)
        output=ref/argv[3];reference_hash=sha(output)
        diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag)
        with (diag/'trace.log').open('wb') as trace:run(['/usr/bin/qemu-riscv64','-strace',out/'fluidanimate-reference',*argv],cwd=diag,stdout=trace,stderr=trace)
        rows=(diag/'trace.log').read_text().splitlines();bi=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));ei=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        syscalls=[l for l in rows[bi+1:ei] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        cases.append(dict(program='fluidanimate',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archive=str(archive),input_archive_sha256=sha(archive),input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,reference_outputs={argv[3]:reference_hash},validation=dict(kind='files_sha256',files={argv[3]:reference_hash}),software_reference='QEMU_RISCV_USER_ONLY',fpga_validation='NOT_RUN',algorithm_unchanged=True,diagnostic_roi_syscalls=syscalls,diagnostic_trace=str(diag/'trace.log')))
    state.update(status='PREPARED_FPGA_NOT_RUN',binaries={k:v for k,v in binaries.items() if k=='fluidanimate'},cases=cases,smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),sources={str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()},integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),formal_input_policy='Official simmedium, 1 thread, 5 frames, full original serial AdvanceFrame ROI; check every output byte')
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state);print(json.dumps(dict(receipt=str(receipt),cases=[dict(input=c['input'],roi_syscalls=len(c['diagnostic_roi_syscalls']),output_sha256=next(iter(c['reference_outputs'].values()))) for c in cases])),flush=True)


if __name__=='__main__':main()
