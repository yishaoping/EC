#!/usr/bin/env python3
"""Prepare actual RISC-V Vips dependencies and serial application privately."""
import argparse
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC');TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--resume',action='store_true');a=ap.parse_args()
    receipt=W/'software/vips-candidate-build.json';assert not receipt.exists() or a.resume
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    if a.resume:
        old=json.loads(receipt.read_text());out=Path(old['output_dir']);logs=D/'software'/('candidate-vips-resume-'+stamp);logs.mkdir()
    else:out=W/'software'/('candidate-vips-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    prefix=out/'dependencies';prefix.mkdir(exist_ok=True)
    hostbin=out/'host-tools';hostbin.mkdir(exist_ok=True)
    if not(hostbin/'ls').exists():(hostbin/'ls').symlink_to('/data1/gzh/EC/firesim/envs/manager-1.17.1/bin/ls')
    state=dict(program='vips',status='BUILDING',pid=os.getpid(),output_dir=str(out),log_dir=str(logs),commands=[],fpga_execution=False,formal_eligible=False,started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    env={**os.environ,'PATH':str(hostbin)+':'+str(TOOLS)+':/usr/bin:/bin','LD_LIBRARY_PATH':'','CC':str(TOOLS/'riscv64-unknown-linux-gnu-gcc'),'CXX':str(TOOLS/'riscv64-unknown-linux-gnu-g++'),'AR':str(TOOLS/'riscv64-unknown-linux-gnu-ar'),'RANLIB':str(TOOLS/'riscv64-unknown-linux-gnu-ranlib'),'CFLAGS':'-O3 -march=rv64gc -mabi=lp64d -fcommon -I'+str(prefix/'include'),'CXXFLAGS':'-O3 -march=rv64gc -mabi=lp64d -fpermissive','LDFLAGS':'-static -L'+str(prefix/'lib'),'PKG_CONFIG_LIBDIR':str(prefix/'lib/pkgconfig'),'glib_cv_stack_grows':'no','glib_cv_uscore':'no','ac_cv_func_posix_getpwuid_r':'yes','ac_cv_func_posix_getgrgid_r':'yes','glib_cv_long_long_format':'ll','glib_cv_rtldglobal_broken':'no','glib_cv_working_bcopy':'no','ac_cv_c_bigendian':'no'}
    def run(argv,cwd,timeout=7200):
        argv=list(map(str,argv));log=logs/('command-'+str(len(state['commands']))+'.log');entry=dict(argv=argv,cwd=str(cwd),log=str(log));state['commands'].append(entry)
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,active_log=str(log));save(D/'software/vips-candidate-build-state.json',state);rc=child.wait(timeout=timeout)
        entry['returncode']=rc
        if rc:raise RuntimeError(f'command failed {rc}: {log}')
    try:
        z=json.loads((W/'software/dedup-staged-apps-build.json').read_text());zroot=Path(z['output_dir'])
        for n,source in [('lib/libz.a',zroot/'libz.a'),('include/zlib.h',zroot/'src/zlib/zlib.h'),('include/zconf.h',zroot/'src/zlib/zconf.h')]:
            dest=prefix/n;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(source,dest)
            state.setdefault('reused_zlib',{})[str(source)]=sha(source)
        for name,options,library in [('glib',['--with-pcre=internal','--disable-selinux','--disable-fam'],'libglib-2.0.a'),('libxml2',['--without-python','--without-lzma','--without-iconv'],'libxml2.a')]:
            if a.resume and (prefix/'lib'/library).exists():continue
            source=out/name
            if not source.exists():shutil.copytree(P/f'pkgs/libs/{name}/src',source)
            run(['bash','configure','--host=riscv64-unknown-linux-gnu','--build=x86_64-pc-linux-gnu','--prefix='+str(prefix),'--disable-shared','--enable-static',*options],cwd=source)
            run(['make','-j2'],cwd=source);run(['make','install'],cwd=source)
        src=out/'src'
        if not src.exists():shutil.copytree(P/'pkgs/apps/vips/src',src)
        options=['--disable-shared','--disable-cxx','--disable-threads','--without-fftw3','--without-magick','--without-liboil','--without-lcms','--without-OpenEXR','--without-matio','--without-pangoft2','--without-tiff','--without-jpeg','--without-zip','--without-png','--without-libexif','--without-python','--without-x','--without-perl','--without-v4l','--without-cimg']
        run(['bash','configure','--host=riscv64-unknown-linux-gnu','--build=x86_64-pc-linux-gnu','--prefix='+str(out/'install'),*options],cwd=src)
        run(['make','-j2'],cwd=src);run(['make','install'],cwd=src)
        binary=out/'install/bin/vips';state.update(status='COMPILED_NOT_FPGA_READY',source_dir=str(src),binary=dict(path=str(binary),sha256=sha(binary)),roi_status='No original PARSEC hooks found. Must bind complete im_benchmark evaluation and output correctness before FPGA.')
    except Exception as exc:state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc))
    finally:
        state.update(ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(logs/'result.json',state);save(receipt,state);save(D/'software/vips-candidate-build-state.json',state);print(json.dumps(dict(status=state['status'],receipt=str(receipt),error=state.get('error'))),flush=True)


if __name__=='__main__':main()
