#!/usr/bin/env python3
"""Build this checkout's original serial Swaptions and official inputs.

QEMU references are correctness evidence only. Real-hook FPGA results are
produced separately, through the existing bound sample runner.
"""
import argparse
import datetime as dt
import difflib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

from board_batch import W, D, save, sha

P = Path('/data1/gzh/EC/Software/PARSEC')
TOOLS = Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--preallocate',action='store_true')
    args=parser.parse_args()
    profile='swaptions-preallocated' if args.preallocate else 'swaptions'
    receipt = W/('software/'+profile+'-apps-build.json')
    assert not receipt.exists(), 'reuse the bound existing profile'
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = W/'software'/('apps-'+profile+'-'+stamp)
    logs = D/'software'/out.name
    out.mkdir(); logs.mkdir()
    parent_path = W/'software/apps-build.json'
    parent = json.loads(parent_path.read_text())
    hooks_parent = Path(parent['output_dir'])
    src = out/'src/swaptions'
    shutil.copytree(P/'pkgs/apps/swaptions/src', src)
    hooks = out/'src/hooks'
    shutil.copytree(hooks_parent/'src/hooks', hooks)
    for name in ['hooks.o', 'dac_roi.o', 'roi-smoke']:
        shutil.copy2(hooks_parent/name, out/name)
    units = [src/n for n in ['CumNormalInv.cpp','MaxFunction.cpp','RanUnif.cpp',
        'nr_routines.c','icdf.cpp','HJM_SimPath_Forward_Blocking.cpp','HJM.cpp',
        'HJM_Swaption_Blocking.cpp','HJM_Securities.cpp']]
    pristine=out/'pristine-HJM_Securities.cpp'
    shutil.copy2(src/'HJM_Securities.cpp',pristine)
    if args.preallocate:
        main_source=src/'HJM_Securities.cpp'
        before=main_source.read_text()
        after=before.replace('#include <stdlib.h>','#include <stdlib.h>\n#include <malloc.h>')
        anchor='#ifdef ENABLE_PARSEC_HOOKS\n\t__parsec_roi_begin();'
        assert after.count(anchor)==1
        prepare='''// Integration: make heap storage resident before the unchanged ROI.
        // All HJM allocation/free calls and all pricing computation remain inside.
        mallopt(M_TRIM_THRESHOLD,-1); mallopt(M_MMAP_MAX,0);
        volatile char *ec_reserve=(volatile char*)malloc(32*1024*1024);
        if (!ec_reserve) return 125;
        for (size_t ec_i=0;ec_i<32*1024*1024;ec_i+=4096) ec_reserve[ec_i]=0;
        free((void*)ec_reserve);
'''
        after=after.replace(anchor,prepare+anchor)
        main_source.write_text(after)
        (logs/'software-integration.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(pristine),tofile=str(main_source))))
    state = dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),
        commands=[],cases=[],parsec_commit=subprocess.check_output(['git','-C',str(P),'rev-parse','HEAD'],text=True).strip(),
        software_profile='swaptions-serial-preallocated-heap' if args.preallocate else 'original-swaptions-serial',formal_eligible=True,
        fpga_validation='NOT_RUN',script_sha256=sha(__file__))
    save(logs/'state.json',state)
    shutil.copy2(__file__,logs/'build-script.py')
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':''}
    def run(argv,cwd=out,timeout=600,stdout=None,stderr=None):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)))
        save(logs/'state.json',state)
        subprocess.run(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,
            stdout=stdout,stderr=stderr,timeout=timeout,check=True)
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE',
           '-std=gnu++17','-I'+str(hooks),'-I'+str(src)]
    common=[TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,'-x','c++',*units,'-x','none']
    with (logs/'build.log').open('wb') as log:
        run([*common,'-DENABLE_PARSEC_HOOKS',out/'hooks.o',out/'dac_roi.o','-lm','-pthread','-o',out/'swaptions'],stdout=log,stderr=log)
        reference_units=[pristine if p.name=='HJM_Securities.cpp' else p for p in units]
        run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,'-x','c++',*reference_units,'-x','none','-lm','-pthread','-o',out/'swaptions-reference'],stdout=log,stderr=log)
        # Original hook sites delimit a narrow syscall audit, not the real ROI ABI.
        (out/'diagnostic-hooks.c').write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags[:-4],'-I'+str(hooks),'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=log,stderr=log)
        run([*common,'-DENABLE_PARSEC_HOOKS',out/'diagnostic-hooks.o','-lm','-pthread','-o',out/'swaptions-diagnostic'],stdout=log,stderr=log)
    for size in ['test','simsmall','simmedium']:
        dest=out/'inputs/swaptions'/size;dest.mkdir(parents=True)
        conf=P/f'pkgs/apps/swaptions/parsec/{size}.runconf'
        argv=re.search(r'^run_args="(.*)"$',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
        ref=logs/('reference-'+size);ref.mkdir()
        with (ref/'combined.log').open('wb') as log:
            run(['/usr/bin/qemu-riscv64',out/'swaptions-reference',*argv],cwd=ref,stdout=log,stderr=log)
        lines=[l for l in (ref/'combined.log').read_text().splitlines(True) if l.startswith('Swaption ')]
        assert len(lines)==int(argv[1]), 'must validate every swaption result'
        expected=ref/'validation.txt';expected.write_text(''.join(lines))
        diag=logs/('diagnostic-'+size);diag.mkdir()
        with (diag/'trace.log').open('wb') as log:
            run(['/usr/bin/qemu-riscv64','-strace',out/'swaptions-diagnostic',*argv],cwd=diag,stdout=log,stderr=log)
        text=(diag/'trace.log').read_text();rows=text.splitlines()
        begin=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'))
        end=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        calls=[l for l in rows[begin+1:end] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        actual_lines=[l+'\n' for l in rows if l.startswith('Swaption ')]
        assert actual_lines==lines, 'integration changed pricing output'
        if args.preallocate:
            assert not calls, 'preallocation did not eliminate synchronous ROI syscalls'
        state['cases'].append(dict(program='swaptions',input=size,argv=argv,
            runconf=str(conf),runconf_sha256=sha(conf),threads=1,warmups=0,
            input_archives={},input_files={},input_generation='original deterministic seed1979',
            algorithm_unchanged=True,heap_preallocation_bytes=32*1024*1024 if args.preallocate else 0,fpga_validation='NOT_RUN',
            software_reference='QEMU_RISCV_USER_ONLY',
            reference_outputs={str(expected):sha(expected)},
            validation=dict(kind='stdout_prefix_hash',prefix='Swaption ',reference=str(expected),reference_sha256=sha(expected)),
            diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log')))
        save(logs/'state.json',state)
    binary=out/'swaptions';ref=out/'swaptions-reference'
    state.update(status='PREPARED_FPGA_NOT_RUN',
        binaries=dict(swaptions=dict(path=str(binary),sha256=sha(binary),reference_path=str(ref),reference_sha256=sha(ref),application_threads=1,algorithm_sources_modified=False,software_integration=args.preallocate)),
        smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),
        sources={str(p.relative_to(out/'src')):sha(p) for p in (out/'src').rglob('*') if p.is_file()},
        reused_hooks={str(hooks_parent/n):sha(hooks_parent/n) for n in ['hooks.o','dac_roi.o','roi-smoke']},
        formal_input_policy='official simmedium, 32 swaptions, 20000 trials, original full worker ROI, one thread/no warmup; require matching FPGA simsmall gate')
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state)
    print(json.dumps(dict(receipt=str(receipt),cases=[dict(input=c['input'],roi_syscalls=c['diagnostic_roi_syscalls']) for c in state['cases']])),flush=True)


if __name__=='__main__':main()
