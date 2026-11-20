#!/usr/bin/env python3
"""Cross-build this checkout's GSL/JPEG and actual serial Ferret dependencies."""
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
    ap=argparse.ArgumentParser();ap.add_argument('--resume',action='store_true');a=ap.parse_args()
    receipt=W/'software/ferret-candidate-build.json';assert not receipt.exists() or a.resume
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    if a.resume:
        previous=json.loads(receipt.read_text());out=Path(previous['output_dir']);src=Path(previous['source_dir']);logs=D/'software'/('candidate-ferret-resume-'+stamp);logs.mkdir()
    else:
        out=W/'software'/('candidate-ferret-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
        src=out/'src';shutil.copytree(P/'pkgs/apps/ferret/src',src)
    prefix=out/'dependencies';prefix.mkdir(exist_ok=True)
    hostbin=out/'host-tools';hostbin.mkdir(exist_ok=True)
    if not (hostbin/'ls').exists():(hostbin/'ls').symlink_to('/data1/gzh/EC/firesim/envs/manager-1.17.1/bin/ls')
    state=dict(program='ferret',status='BUILDING',pid=os.getpid(),output_dir=str(out),source_dir=str(src),log_dir=str(logs),commands=[],fpga_execution=False,formal_eligible=False,started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(D/'software/ferret-candidate-build-state.json',state)
    env={**os.environ,'PATH':str(hostbin)+':'+str(TOOLS)+':/usr/bin:/bin','LD_LIBRARY_PATH':'','CC':str(TOOLS/'riscv64-unknown-linux-gnu-gcc'),'CXX':str(TOOLS/'riscv64-unknown-linux-gnu-g++'),'AR':str(TOOLS/'riscv64-unknown-linux-gnu-ar'),'RANLIB':str(TOOLS/'riscv64-unknown-linux-gnu-ranlib'),'CFLAGS':'-O3 -march=rv64gc -mabi=lp64d -fcommon','CXXFLAGS':'-O3 -march=rv64gc -mabi=lp64d -fpermissive','LDFLAGS':'-static'}
    state['host_tool_workaround']=dict(ls=str(hostbin/'ls'),sha256=sha(hostbin/'ls'),reason='system /usr/bin/ls prints correct output but returns255; existing conda ls returns0; no system tools modified')
    def run(argv,cwd,timeout=3600):
        argv=list(map(str,argv));log=logs/('command-'+str(len(state['commands']))+'.log');entry=dict(argv=argv,cwd=str(cwd),log=str(log));state['commands'].append(entry)
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,active_log=str(log));save(D/'software/ferret-candidate-build-state.json',state);rc=child.wait(timeout=timeout)
        entry['returncode']=rc
        if rc:raise RuntimeError(f'command failed {rc}: {log}')
    try:
        for name in ['gsl','libjpeg']:
            library=prefix/('lib/libgsl.a' if name=='gsl' else 'lib/libjpeg.a')
            if a.resume and library.exists():
                state.setdefault('reused_dependencies',{})[str(library)]=sha(library);continue
            source=out/name
            if not source.exists():shutil.copytree(P/f'pkgs/libs/{name}/src',source)
            run(['bash','configure','--host=riscv64-unknown-linux-gnu','--build=x86_64-pc-linux-gnu','--prefix='+str(prefix),'--disable-shared','--enable-static'],cwd=source)
            run(['make','-j2'],cwd=source);run(['make','install'],cwd=source)
        # The serial source uses plural hook names not supplied by hooks.h.
        # Correct only that existing integration typo at its original sites.
        f=src/'benchmark/ferret-serial.c';before=f.read_text();after=before.replace('__parsec_roi_begins();','__parsec_roi_begin();').replace('__parsec_roi_ends();','__parsec_roi_end();');f.write_text(after)
        import difflib
        (logs/'roi-hook-integration.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(P/'pkgs/apps/ferret/src/benchmark/ferret-serial.c'),tofile=str(f))))
        flags=env['CFLAGS']+' -I'+str(prefix/'include')+' -I'+str(src/'include')
        ldflags='-static -L'+str(prefix/'lib')+' -L'+str(src/'parsec/lib')
        run(['make','-j2','dirs','lib','version=serial','CC='+env['CC'],'CXX='+env['CXX'],'AR='+env['AR'],'CFLAGS='+flags,'LDFLAGS='+ldflags],cwd=src)
        run(['make','-j2','benchmark','version=serial','CC='+env['CC'],'CXX='+env['CXX'],'AR='+env['AR'],'CFLAGS='+flags,'LDFLAGS='+ldflags],cwd=src)
        binary=src/'parsec/bin/ferret-serial';state.update(status='COMPILED_NOT_FPGA_READY',binary=dict(path=str(binary),sha256=sha(binary)),roi_status='Original serial scan() ROI sites retained; next audit full image/query/output IO and correctness before FPGA')
    except Exception as exc:state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc))
    finally:
        state.update(ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(logs/'result.json',state);save(receipt,state);save(D/'software/ferret-candidate-build-state.json',state);print(json.dumps(dict(status=state['status'],receipt=str(receipt),error=state.get('error'))),flush=True)


if __name__=='__main__':main()
