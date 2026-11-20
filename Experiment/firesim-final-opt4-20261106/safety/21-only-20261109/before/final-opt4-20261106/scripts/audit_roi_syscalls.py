#!/usr/bin/env python3
"""Software-only ROI syscall diagnosis. Outputs are never eligible for FPGA runs."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('roi-syscall-diagnostic-'+stamp);out.mkdir()
    logs=D/'software'/out.name;logs.mkdir()
    manifest_path=W/'software/apps-build.json';apps=json.loads(manifest_path.read_text())
    sources=Path(apps['output_dir'])/'src';hooks=sources/'hooks'
    hook=out/'diagnostic-only-hooks.c'
    hook.write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) { (void)b; }
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) { const char m[]="EC_DIAGNOSTIC_ROI_BEGIN\\n"; write(2,m,sizeof(m)-1); }
void __parsec_roi_end(void) { const char m[]="EC_DIAGNOSTIC_ROI_END\\n"; write(2,m,sizeof(m)-1); }
''')
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-D_GNU_SOURCE','-static']
    commands=[];cases=[]
    def run(argv,cwd=out,stdout=None,stderr=None):
        commands.append(dict(argv=list(map(str,argv)),cwd=str(cwd)))
        return subprocess.run(list(map(str,argv)),cwd=cwd,stdout=stdout,stderr=stderr,stdin=subprocess.DEVNULL,timeout=300,check=True)
    with (logs/'build.log').open('wb') as build:
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-I'+str(hooks),'-c',hook,'-o',out/'hooks.o'],stdout=build,stderr=build)
        for name in ['streamcluster','canneal','blackscholes']:
            src=sources/name
            units=[src/n for n in (['annealer_thread.cpp','rng.cpp','netlist.cpp','main.cpp','netlist_elem.cpp'] if name=='canneal' else ['streamcluster.cpp'] if name=='streamcluster' else ['blackscholes.c'])]
            elf=out/(name+'-DIAGNOSTIC-NOT-FOR-FPGA')
            run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,'-std=gnu++17','-I'+str(hooks),'-I'+str(src),'-x','c++',*units,'-x','none','-DENABLE_PARSEC_HOOKS',out/'hooks.o','-lm','-pthread','-o',elf],stdout=build,stderr=build)
            case=next(c for c in apps['cases'] if c['program']==name and c['input']=='test')
            cwd=logs/name;shutil.copytree(Path(apps['output_dir'])/'inputs'/name/'test',cwd)
            trace=cwd/'qemu-strace.log'
            with trace.open('wb') as err,(cwd/'stdout.log').open('wb') as std:
                run(['/usr/bin/qemu-riscv64','-strace',elf,*case['argv']],cwd=cwd,stdout=std,stderr=err)
            lines=trace.read_text().splitlines();beg=next(i for i,x in enumerate(lines) if x.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,x in enumerate(lines) if x.endswith('EC_DIAGNOSTIC_ROI_END'))
            calls=[x for x in lines[beg+1:end] if re.match(r'^\d+ [a-zA-Z_][a-zA-Z_0-9]*\(',x)]
            # Marker writes share their lines with the marker text and are excluded above.
            counts={}
            for x in calls:
                syscall=re.match(r'^\d+ ([^(]+)',x)[1];counts[syscall]=counts.get(syscall,0)+1
            cases.append(dict(program=name,input='test',diagnostic_elf=str(elf),diagnostic_elf_sha256=sha(elf),trace=str(trace),trace_sha256=sha(trace),syscalls_between_original_roi_hooks=counts,syscall_records=calls,application_exit=0,actual_dac_hooks=False,fpga_validation='NOT_RUN',formal_eligible=False))
    result=dict(schema='ec-roi-syscall-diagnosis/1',apps_manifest_sha256=sha(manifest_path),commands=commands,cases=cases,diagnostic_only=True,fpga_validation='NOT_RUN')
    (logs/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({c['program']:c['syscalls_between_original_roi_hooks'] for c in cases}),flush=True)
if __name__=='__main__':main()
