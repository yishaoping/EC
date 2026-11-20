#!/usr/bin/env python3
"""Bind complete eager im_benchmark evaluation, compare every pixel to original CLI."""
import datetime as dt
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tarfile
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC');TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')
SOURCE=r'''#include <vips/vips.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifdef ENABLE_PARSEC_HOOKS
#include "hooks.h"
#endif
static void fail(void){fprintf(stderr,"%s\n",im_error_buffer());exit(125);}
static void dump(IMAGE *im) {
 if(im_incheck(im))fail();
 FILE *f=fopen("output.pixels","wb");if(!f)exit(125);
 size_t n=(size_t)IM_IMAGE_SIZEOF_LINE(im)*im->Ysize;
 if(fwrite(im->data,1,n,f)!=n||fclose(f))exit(125);
 f=fopen("output.shape","w");if(!f)exit(125);
 fprintf(f,"%d %d %d %d %d %d %d %d %.17g %.17g\n",im->Xsize,im->Ysize,im->Bands,im->BandFmt,im->Coding,im->Type,im->Xoffset,im->Yoffset,im->Xres,im->Yres);
 if(fclose(f))exit(125);
}
int main(int argc,char **argv){
 setenv("IM_CONCURRENCY","1",1);
 if(im_init_world(argv[0]))fail();
 if(argc==3&&!strcmp(argv[1],"--dump")){
  IMAGE *in=im_open(argv[2],"r");if(!in)fail();dump(in);if(im_close(in))fail();return 0;
 }
 if(argc!=4||strcmp(argv[1],"im_benchmark"))return 125;
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *heap=(volatile char*)malloc(512*1024*1024);if(!heap)return 125;
 for(size_t i=0;i<512*1024*1024;i+=4096)heap[i]=0;free((void*)heap);
 IMAGE *in=im_open(argv[2],"r"),*out=im_open("ec-resident-output","t");
 if(!in||!out||im_incheck(in))fail();
 volatile unsigned char *pixels=in->data;volatile unsigned char touch=0;
 for(size_t i=0;i<(size_t)IM_IMAGE_SIZEOF_LINE(in)*in->Ysize;i+=4096)touch^=pixels[i];
 (void)touch;
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_bench_begin(__parsec_vips);__parsec_roi_begin();
#endif
 /* Same original dispatch target. IM_SETBUF invokes vips_sink_memory eagerly:
    all transformations and all output pixels finish before ROI end. */
 if(im_benchmarkn(in,out,1))fail();
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_roi_end();
#endif
 dump(out);
 IMAGE *file=im_open(argv[3],"w");if(!file||im_copy(out,file)||im_close(file))fail();
 if(im_close(out)||im_close(in))fail();
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_bench_end();
#endif
 return 0;
}
'''

def main():
    receipt=W/'software/vips-apps-build.json';assert not receipt.exists()
    cpath=W/'software/vips-candidate-build.json';c=json.loads(cpath.read_text());assert c['status']=='COMPILED_NOT_FPGA_READY'
    src=Path(c['source_dir']);prefix=Path(c['output_dir'])/'dependencies'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'software'/('apps-vips-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir']);hooks=base/'src/hooks'
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='vips-complete-im-benchmark-resident-io',formal_eligible=True,parsec_commit=parent['parsec_commit'],commands=[],cases=[],candidate_receipt=str(cpath),candidate_receipt_sha256=sha(cpath),algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    def update(**kw):state.update(kw);save(D/'software/vips-preparation-state.json',state);save(logs/'state.json',state)
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','IM_CONCURRENCY':'1'}
    def run(argv,cwd=out,stdout=None,stderr=None,timeout=3600):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));update()
        child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,start_new_session=True);update(child_pid=child.pid)
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            import signal
            os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);raise
        assert rc==0,(rc,argv)
    try:
        (out/'vips-runner.c').write_text(SOURCE)
        (out/'diagnostic-hooks.c').write_text('#include "hooks.h"\n#include <unistd.h>\nvoid __parsec_bench_begin(enum __parsec_benchmark b){(void)b;}\nvoid __parsec_bench_end(void){}\nvoid __parsec_roi_begin(void){write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}\nvoid __parsec_roi_end(void){write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}\n')
        (logs/'software-integration.c').write_text(SOURCE)
        flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-I'+str(src/'libvips/include'),'-I'+str(prefix/'include/glib-2.0'),'-I'+str(prefix/'lib/glib-2.0/include'),'-I'+str(prefix/'include/libxml2'),'-I'+str(hooks)]
        libs=[str(src/'libvips/.libs/libvips.a'),'-L'+str(prefix/'lib'),'-lgmodule-2.0','-lxml2','-lgobject-2.0','-lgthread-2.0','-lglib-2.0','-ldl','-lz','-lm','-pthread']
        with (logs/'build.log').open('wb') as f:
            # Libtool's -static did not fully static-link the candidate CLI.
            # Relink its unchanged original object against already-built archives.
            run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,src/'tools/iofuncs/vips.o',*libs,'-o',out/'vips-original-reference'],stdout=f,stderr=f)
            run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=f,stderr=f)
            for target,objects in [('vips',[base/'hooks.o',base/'dac_roi.o']),('vips-diagnostic',[out/'diagnostic-hooks.o'])]:
                run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-DENABLE_PARSEC_HOOKS',out/'vips-runner.c',*objects,*libs,'-o',out/target],stdout=f,stderr=f)
        for size in ['test','simsmall','simmedium']:
            dest=out/'inputs/vips'/size;dest.mkdir(parents=True);archive=P/f'pkgs/apps/vips/inputs/input_{size}.tar'
            with tarfile.open(archive) as tf:
                for m in tf.getmembers():
                    if m.isfile():
                        p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=dest/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
            conf=P/f'pkgs/apps/vips/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split();assert argv[0]=='im_benchmark'
            ref=logs/('reference-'+size);shutil.copytree(dest,ref);update(status='QEMU_REFERENCE_RUNNING',input=size)
            with (ref/'stdout.log').open('wb') as f:
                run(['/usr/bin/qemu-riscv64',out/'vips-original-reference',*argv],cwd=ref,stdout=f,stderr=f)
                run(['/usr/bin/qemu-riscv64',out/'vips-diagnostic','--dump',argv[-1]],cwd=ref,stdout=f,stderr=f)
            outputs={n:sha(ref/n) for n in ['output.pixels','output.shape']};assert (ref/'output.pixels').stat().st_size>0
            diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag);update(status='QEMU_DIAGNOSTIC_RUNNING',input=size)
            with (diag/'trace.log').open('wb') as f:run(['/usr/bin/qemu-riscv64','-strace',out/'vips-diagnostic',*argv],cwd=diag,stdout=f,stderr=f)
            assert all(sha(diag/n)==h for n,h in outputs.items()),'complete pixel/shape mismatch against original im_benchmark CLI'
            rows=(diag/'trace.log').read_text().splitlines();b=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));e=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'));calls=[l for l in rows[b+1:e] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
            state['cases'].append(dict(program='vips',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,validation=dict(kind='files_sha256',files=outputs),reference_outputs={str(ref/n):h for n,h in outputs.items()},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),fpga_validation='NOT_RUN',algorithm_unchanged=True,roi='Full original im_benchmarkn(in,out,1), eager IM_SETBUF/vips_sink_memory completes every output pixel inside ROI'))
        binary=out/'vips';ref=out/'vips-original-reference';update(status='PREPARED_FPGA_NOT_RUN',binaries=dict(vips=dict(path=str(binary),sha256=sha(binary),reference_path=str(ref),reference_sha256=sha(ref),application_threads=1,algorithm_sources_modified=False)),smoke=parent['smoke'],integration_patch=str(logs/'software-integration.c'),integration_patch_sha256=sha(logs/'software-integration.c'),c4_incompatible_reason='Synchronous syscalls in complete eager image ROI; inspect diagnostic evidence' if any(c['diagnostic_roi_syscalls'] for c in state['cases']) else None,formal_input_policy='Official simmedium im_benchmark/input/one thread; same complete graph and full pixel evaluation on both configurations. IO staging outside ROI, no computation removed.')
        save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state)
    except Exception as exc:update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    print(json.dumps(dict(receipt=str(receipt),roi_syscalls={c['input']:len(c['diagnostic_roi_syscalls']) for c in state['cases']})),flush=True)

if __name__=='__main__':main()
