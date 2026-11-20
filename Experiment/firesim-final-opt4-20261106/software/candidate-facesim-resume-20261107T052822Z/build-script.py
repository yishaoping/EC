#!/usr/bin/env python3
"""Actually compile local remaining PARSEC sources without touching their checkout.

Build receipts explicitly do not imply usable ROI/checker/FPGA results.
"""
import argparse
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC')
TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    ap=argparse.ArgumentParser();ap.add_argument('program',choices=['facesim','x264','raytrace']);ap.add_argument('--resume',action='store_true');a=ap.parse_args();name=a.program
    receipt=W/f'software/{name}-candidate-build.json';assert not receipt.exists() or a.resume
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    if a.resume:
        previous=json.loads(receipt.read_text());out=Path(previous['output_dir']);src=Path(previous['source_dir'])
        logs=D/'software'/('candidate-'+name+'-resume-'+stamp);logs.mkdir()
    else:
        out=W/'software'/('candidate-'+name+'-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
        src=out/'src';shutil.copytree(P/f'pkgs/apps/{name}/src',src)
    gcc=TOOLS/'riscv64-unknown-linux-gnu-gcc';gxx=TOOLS/'riscv64-unknown-linux-gnu-g++'
    state=dict(schema='ec-local-parsec-candidate-build/1',program=name,status='BUILDING',pid=os.getpid(),output_dir=str(out),source_dir=str(src),log_dir=str(logs),commands=[],
        parsec_commit=subprocess.check_output(['git','-C',str(P),'rev-parse','HEAD'],text=True).strip(),fpga_execution=False,formal_eligible=False,started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(logs/'state.json',state);save(D/f'software/{name}-candidate-build-state.json',state);shutil.copy2(__file__,logs/'build-script.py')
    env={**os.environ,'PATH':str(TOOLS)+':/usr/bin:/bin','LD_LIBRARY_PATH':'','MAKEFLAGS':'-j2','CC':str(gcc),'CXX':str(gxx),'AR':str(TOOLS/'riscv64-unknown-linux-gnu-ar'),'RANLIB':str(TOOLS/'riscv64-unknown-linux-gnu-ranlib')}
    def run(argv,cwd=src,timeout=7200,allowed=False):
        argv=list(map(str,argv));log=logs/('command-'+str(len(state['commands']))+'.log');entry=dict(argv=argv,cwd=str(cwd),log=str(log));state['commands'].append(entry)
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,active_log=str(log));save(logs/'state.json',state);save(D/f'software/{name}-candidate-build-state.json',state)
            rc=child.wait(timeout=timeout)
        entry['returncode']=rc
        if rc and not allowed:raise RuntimeError(f'command failed {rc}: {log}')
        return rc
    flags='-O3 -march=rv64gc -mabi=lp64d -static -fpermissive'
    try:
        if name=='x264':
            run(['bash','configure','--host=riscv64-unknown-linux-gnu','--cross-prefix='+str(TOOLS/'riscv64-unknown-linux-gnu-'),'--disable-asm','--disable-thread','--disable-opencl','--disable-lavf','--disable-swscale','--disable-ffms','--enable-static','--extra-cflags=-O3 -march=rv64gc -mabi=lp64d','--extra-ldflags=-static'])
            run(['make','-j2','x264'])
            binary=src/'x264'
            # Execute exact official test flags, preserving parser failures.
            conf=P/'pkgs/apps/x264/parsec/test.runconf'
            import re,tarfile
            argv=re.search(r'^run_args="(.*)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
            cwd=out/'test';cwd.mkdir()
            with tarfile.open(P/'pkgs/apps/x264/inputs/input_test.tar') as tf:
                for m in tf.getmembers():
                    if m.isfile():
                        p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=cwd/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
            rc=run(['/usr/bin/qemu-riscv64',binary,*argv],cwd=cwd,allowed=True,timeout=300)
            state['official_test_parser_returncode']=rc
            state['roi_status']='No PARSEC ROI hooks in local x264.c. Binding full encoding ROI and legacy b-pyramid semantics requires explicit integration; not FPGA ready.'
        elif name=='facesim':
            common=['make','-j2','version=serial','PHYSBAM='+str(src),'PHYSBAM_LIBDIR='+str(out/'lib'),'CXX='+str(gxx),'CC='+str(gcc),'PHYSBAM_CC='+str(gxx),'AR='+str(TOOLS/'riscv64-unknown-linux-gnu-ar'),'CXXFLAGS='+flags+' -fexceptions -DNEW_SERIAL_IMPLEMENTATIOM','LDFLAGS=-static','LIBS=-lpthread','USE_ALAMERE_TASKQ=yes','USE_ALAMERE_PTHREADS=no']
            (out/'lib').mkdir(exist_ok=True)
            run([*common,'-C',src/'TaskQ/lib'])
            run([*common,'-C',src/'Benchmarks/facesim'])
            binary=src/'Benchmarks/facesim/facesim'
            state['roi_status']='Original SOLIDS_FLUIDS_DRIVER hooks retained. Input/output and auxiliary timers require subsequent diagnostic; no FPGA run.'
        else:
            build=out/'build';build.mkdir()
            run(['cmake','-S',src,'-B',build,'-DCMAKE_SYSTEM_NAME=Linux','-DCMAKE_SYSTEM_PROCESSOR=riscv64','-DCMAKE_C_COMPILER='+str(gcc),'-DCMAKE_CXX_COMPILER='+str(gxx),'-DCMAKE_CXX_FLAGS='+flags,'-DBUILD_SHARED_LIBS=OFF'],allowed=False)
            run(['cmake','--build',build,'--parallel','2'])
            binary=build/'bin/rtview'
            state['roi_status']='Built-in RT_EMULATE_SSE exists; port must preserve frame loop and rendering output. No FPGA validation.'
        state.update(status='COMPILED_NOT_FPGA_READY',binary=dict(path=str(binary),sha256=sha(binary)))
    except Exception as exc:
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc))
    finally:
        state.update(ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(logs/'state.json',state);save(logs/'result.json',state);save(receipt,state);save(D/f'software/{name}-candidate-build-state.json',state)
        print(json.dumps(dict(program=name,status=state['status'],receipt=str(receipt),error=state.get('error'))),flush=True)


if __name__=='__main__':main()
