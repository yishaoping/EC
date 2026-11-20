#!/usr/bin/env python3
"""Port the existing no-display path; preserve renderer, camera and full frame loop."""
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
    receipt=W/'software/raytrace-headless-apps-build.json'
    if receipt.exists():
        subprocess.run(['python3',W/'scripts/prepare_profile_system.py','raytrace-headless'],check=True);return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-raytrace-headless-'+stamp);logs=D/'software'/out.name
    out.mkdir();logs.mkdir();src=out/'src';shutil.copytree(P/'pkgs/apps/raytrace/src',src)
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir'])
    hooks=base/'src/hooks'
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),
               software_profile='raytrace-original-headless-memory-framebuffer',formal_eligible=True,
               parsec_commit=parent['parsec_commit'],commands=[],cases=[],fpga_validation='NOT_RUN',
               algorithm_sources_modified=False,portability_changes=['remove unreachable GL front end; explicitly reject display','RISC-V seq_cst add-fetch replaces x86 xadd with same returned new value','POSIX names remain POSIX on Linux'],
               output_observation='copy every original written 8x8 pixel tile after each render into preallocated memory within ROI; serialize after ROI; identical overhead in both groups',
               original_test_limitation='Official test -res 1 1 executes no 8x8 ray packet. Excluded as compute smoke; use official simsmall without changing render dimensions.')
    path=D/'software/raytrace-headless-preparation-state.json'
    def update(**kw):state.update(kw);save(path,state);save(logs/'state.json',state)
    def run(argv,cwd=out,log=None,timeout=7200):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));update()
        with (log or logs/'build.log').open('ab',buffering=0) as f:
            c=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            update(child_pid=c.pid)
            try:rc=c.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                import signal
                os.killpg(c.pid,signal.SIGTERM);c.wait(timeout=20);raise
        assert rc==0,(rc,str(log or logs/'build.log'))
    original={}
    def edit(n,text):
        p=src/n;original[n]=p.read_text();p.write_text(text)
    try:
        p=src/'LRT/FrameBuffer.hxx';t=p.read_text();start=t.index('#define GL_GLEXT_PROTOTYPES');end=t.index('#define BEGIN_NAMESPACE',start);edit('LRT/FrameBuffer.hxx',t[:start]+t[end:])
        p=src/'LRT/FrameBuffer.cxx';t=p.read_text().replace('#include "FrameBuffer/PBOFrameBuffer.hxx"','').replace('#include "FrameBuffer/GLTextureFB.hxx"','')
        b=t.index('  if (Options::usePBOs)');e=t.index('\n  return frameBuffer;',b)
        t=t[:b]+'  FATAL("headless build requires memory framebuffer");\n'+t[e:];edit('LRT/FrameBuffer.cxx',t)
        p=src/'RTTL/common/RTThread.hxx';t=p.read_text();b=t.index('  int i = c;');e=t.index('\n}',b)
        t=t[:b]+'  return __atomic_add_fetch(v,c,__ATOMIC_SEQ_CST);'+t[e:];edit('RTTL/common/RTThread.hxx',t)
        p=src/'RTTL/common/RTInclude.hxx';t=p.read_text();b=t.index('#define getcwd');e=t.index('// default includes',b)
        t=t[:b]+'#ifdef _WIN32\n'+t[b:e]+'#endif\n'+t[e:];edit('RTTL/common/RTInclude.hxx',t)
        edit('RTTL/common/cmake_autoconfig.h','#define USE_PBOS 0\n#define DO_STATS_BVH 0\nnamespace RTTL { static const char *defaultBVHBuilder="default"; }\n')
        p=src/'MiniView/rtview.cxx';t=p.read_text().replace('#include "LRT/FrameBuffer/PBOFrameBuffer.hxx"','')
        b=t.index('void InitGL()');e=t.index('void render()',b);t=t[:b]+t[e:]
        b=t.index('void display(void)');e=t.index('void parseRTVec3f(',b);t=t[:b]+t[e:]
        b=t.index('  if (glDisplay) {',t.index('int main('));e=t.index('  /* create LRT',b)
        t=t[:b]+'  if(glDisplay) FATAL("display unavailable in headless build");\n  LRT::FrameBuffer::Options::useMemoryFB=true;\n'+t[e:]
        b=t.index('  if (glDisplay) {',t.index('lrtBuildContext(lrtContext);'));e=t.index('    cout << "Rendering ',b)
        t=t[:b]+'  {\n'+t[e:]
        anchor='    int frame = 0;'
        # Allocate snapshots before the original ROI, leaving all original
        # rendering and camera motion inside the existing begin/end pair.
        prep='''    if(framesToRender<=0) FATAL("finite frame count required");
    LRT::FrameBuffer *ec_fb=reinterpret_cast<LRT::FrameBuffer*>(lrtFrameBuffer);
    const size_t ec_w=(resX/8)*8,ec_h=(resY/8)*8,ec_bytes=ec_w*ec_h*4;
    if(!ec_bytes) FATAL("official dimensions render no complete packet");
    unsigned char *ec_frames=(unsigned char*)malloc(ec_bytes*framesToRender);
    if(!ec_frames) exit(125);
    memset(ec_frames,0,ec_bytes*framesToRender);
    mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
    volatile char *ec_heap=(volatile char*)malloc(128*1024*1024);if(!ec_heap)exit(125);
    for(size_t i=0;i<128*1024*1024;i+=4096)ec_heap[i]=0;free((void*)ec_heap);
'''
        t=t.replace('#include <stdio.h>','#include <stdio.h>\n#include <string.h>\n#include <malloc.h>')
        begin='#ifdef ENABLE_PARSEC_HOOKS\n    __parsec_roi_begin();'
        assert t.count(begin)==1;t=t.replace(begin,prep+begin)
        t=t.replace('      render();\n      frame++;','      render();\n      for(size_t y=0;y<ec_h;y++) memcpy(ec_frames+frame*ec_bytes+y*ec_w*4,ec_fb->fb+y*ec_fb->res.x*4,ec_w*4);\n      frame++;')
        end='    __parsec_roi_end();\n#endif'
        assert t.count(end)==1
        t=t.replace(end,end+'''\n    FILE *ec_file=fopen("frames.rgba","wb");if(!ec_file)exit(125);
    if(fwrite(ec_frames,1,ec_bytes*frame,ec_file)!=ec_bytes*frame || fclose(ec_file))exit(125);
    ec_file=fopen("frames.shape","w");if(!ec_file)exit(125);
    fprintf(ec_file,"requested=%dx%d rendered=%zux%zu frames=%d RGBA8\\n",resX,resY,ec_w,ec_h,frame);
    if(fclose(ec_file))exit(125);
''');edit('MiniView/rtview.cxx',t)
        patch=logs/'software-integration.patch';patch.write_text(''.join(''.join(difflib.unified_diff(before.splitlines(True),(src/n).read_text().splitlines(True),fromfile=str(P/'pkgs/apps/raytrace/src'/n),tofile=str(src/n))) for n,before in original.items()))
        (out/'diagnostic-hooks.c').write_text('#include "hooks.h"\n#include <unistd.h>\nvoid __parsec_bench_begin(enum __parsec_benchmark b){(void)b;}\nvoid __parsec_bench_end(void){}\nvoid __parsec_roi_begin(void){write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}\nvoid __parsec_roi_end(void){write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}\n')
        flags=['-O3','-fno-strict-aliasing','-fpermissive','-std=gnu++98','-march=rv64gc','-mabi=lp64d','-DTHIS_IS_CMAKE','-I'+str(src),'-I'+str(src/'RTTL'),'-I'+str(src/'RTTL/common'),'-I'+str(src/'RTTL/BVH'),'-I'+str(src/'SG'),'-I'+str(src/'LRT/include'),'-I'+str(src/'LRT'),'-I'+str(hooks)]
        gcc=TOOLS/'riscv64-unknown-linux-gnu-gcc';gxx=TOOLS/'riscv64-unknown-linux-gnu-g++'
        run([gcc,'-I'+str(hooks),'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'])
        names=['RTTL/BVH/BVH','RTTL/BVH/Builder/Builder','RTTL/BVH/Builder/Sweep','RTTL/BVH/Builder/BinnedAllDims','RTTL/BVH/Builder/BinnedAllDimsSaveSpace','RTTL/BVH/Builder/OnDemandBuilder','RTTL/common/RTThread','RTTL/common/MapOptions','RTTL/API/ISG','LRT/Init','LRT/FrameBuffer','LRT/render']
        objects=[]
        for i,n in enumerate(names):
            obj=out/(str(i)+'.o');run([gxx,*flags,'-c',src/(n+'.cxx'),'-o',obj]);objects.append(obj)
        for target,h in [('raytrace',[base/'hooks.o',base/'dac_roi.o']),('raytrace-diagnostic',[out/'diagnostic-hooks.o']),('raytrace-reference',[])]:
            obj=out/(target+'.o');run([gxx,*flags,*(['-DENABLE_PARSEC_HOOKS'] if h else []),'-c',src/'MiniView/rtview.cxx','-o',obj])
            run([gxx,'-static','-o',out/target,obj,*objects,*h,'-lm','-pthread','-lrt'])
        for size in ['simsmall','simmedium']:
            dest=out/'inputs/raytrace'/size;dest.mkdir(parents=True);ar=P/f'pkgs/apps/raytrace/inputs/input_{size}.tar'
            with tarfile.open(ar) as tf:
                for m in tf.getmembers():
                    if m.isfile():
                        n=Path(m.name);assert not n.is_absolute() and '..' not in n.parts;p=dest/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(tf.extractfile(m).read())
            conf=P/f'pkgs/apps/raytrace/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
            ref=logs/('reference-'+size);diag=logs/('diagnostic-'+size);shutil.copytree(dest,ref);shutil.copytree(dest,diag)
            update(status='QEMU_REFERENCE_RUNNING',input=size);run(['/usr/bin/qemu-riscv64',out/'raytrace-reference',*argv],ref,ref/'stdout.log')
            files={n:sha(ref/n) for n in ['frames.rgba','frames.shape']}
            update(status='QEMU_DIAGNOSTIC_RUNNING');run(['/usr/bin/qemu-riscv64','-strace',out/'raytrace-diagnostic',*argv],diag,diag/'trace.log')
            assert all(sha(diag/n)==h for n,h in files.items())
            lines=(diag/'trace.log').read_text().splitlines();b=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));e=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
            calls=[l for l in lines[b+1:e] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
            state['cases'].append(dict(program='raytrace',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(ar):sha(ar)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,validation=dict(kind='files_sha256',files=files),reference_outputs={str(ref/n):h for n,h in files.items()},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),roi='original complete multi-frame render and automove loop, plus identical per-frame output copy observation',fpga_validation='NOT_RUN',algorithm_unchanged=True));update()
        update(status='PREPARED_FPGA_NOT_RUN',binaries=dict(raytrace=dict(path=str(out/'raytrace'),sha256=sha(out/'raytrace'),reference_path=str(out/'raytrace-reference'),reference_sha256=sha(out/'raytrace-reference'),application_threads=1)),smoke=parent['smoke'],integration_patch=str(patch),integration_patch_sha256=sha(patch),c4_incompatible_reason='Synchronous syscall in complete render ROI; see diagnostic' if any(c['diagnostic_roi_syscalls'] for c in state['cases']) else None)
        save(receipt,state);save(out/'manifest.json',state);save(logs/'result.json',state)
    except Exception as exc:update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    subprocess.run(['python3',W/'scripts/prepare_profile_system.py','raytrace-headless'],check=True)


if __name__=='__main__':main()
