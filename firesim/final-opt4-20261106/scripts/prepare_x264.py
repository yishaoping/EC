#!/usr/bin/env python3
"""Reuse original encoder archive; bind complete encoding and delayed-frame drain."""
import datetime as dt
import difflib
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import tarfile
from board_batch import W,D,save,sha
P=Path('/data1/gzh/EC/Software/PARSEC');TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')
HELPER=r'''#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
static char *ec_output_bytes;static size_t ec_output_length;static FILE *ec_output_stream;static char *ec_output_name;
FILE *ec_x264_input(const char *p) {
 FILE *f=fopen(p,"rb");if(!f||fseek(f,0,SEEK_END))exit(125);long n=ftell(f);if(n<=0||fseek(f,0,SEEK_SET))exit(125);
 char *b=malloc(n);if(!b||fread(b,1,n,f)!=(size_t)n||fclose(f))exit(125);
 f=fmemopen(b,n,"rb");if(!f)exit(125);return f;
}
FILE *ec_x264_output(const char *p) {
 ec_output_name=strdup(p);ec_output_stream=open_memstream(&ec_output_bytes,&ec_output_length);if(!ec_output_stream)exit(125);return ec_output_stream;
}
void ec_x264_prepare(void) {
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *h=(volatile char*)malloc(768*1024*1024);if(!h)exit(125);
 for(size_t i=0;i<768*1024*1024;i+=4096)h[i]=0;free((void*)h);
}
int ec_x264_close(FILE *f) {
 if(fclose(f))return -1;FILE *out=fopen(ec_output_name,"wb");if(!out)return -1;
 if(fwrite(ec_output_bytes,1,ec_output_length,out)!=ec_output_length)return -1;
 return fclose(out);
}
'''
def main():
    receipt=W/'software/x264-apps-build.json'
    if receipt.exists():return
    cp=W/'software/x264-candidate-build.json';c=json.loads(cp.read_text());assert c['status']=='COMPILED_NOT_FPGA_READY';src=Path(c['source_dir'])
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'software'/('apps-x264-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir']);hooks=base/'src/hooks'
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='x264-original-encoder-staged-io',formal_eligible=True,parsec_commit=parent['parsec_commit'],commands=[],cases=[],candidate_receipt=str(cp),candidate_receipt_sha256=sha(cp),algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    def update(**kw):state.update(kw);save(D/'software/x264-preparation-state.json',state);save(logs/'state.json',state)
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':''}
    def run(argv,cwd=out,stdout=None,stderr=None,timeout=7200):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));update();child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,start_new_session=True);update(child_pid=child.pid)
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            import signal
            os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);raise
        assert rc==0,(rc,argv)
    try:
        (out/'diagnostic-hooks.c').write_text('#include "hooks.h"\n#include <unistd.h>\nvoid __parsec_bench_begin(enum __parsec_benchmark b){(void)b;}\nvoid __parsec_bench_end(void){}\nvoid __parsec_roi_begin(void){write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}\nvoid __parsec_roi_end(void){write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}\n')
        helper=HELPER.replace('#include <stdlib.h>','#include <stdlib.h>\n#include <string.h>');(out/'stage.c').write_text(helper)
        patches=[]
        for n in ['x264.c','input/y4m.c','output/raw.c']:
            before=(src/n).read_text();after=before
            if n=='x264.c':
                after=after.replace('static int encode( x264_param_t *param, cli_opt_t *opt )','extern void ec_x264_prepare(void);\n#include "hooks.h"\nstatic int encode( x264_param_t *param, cli_opt_t *opt )')
                after=after.replace('int     retval = 0;','int     retval = 0;\n    int ec_roi_started=0;')
                after=after.replace('    h = x264_encoder_open( param );','    ec_x264_prepare();\n    i_start=x264_mdate();\n    __parsec_bench_begin(__parsec_x264);\n    __parsec_roi_begin();ec_roi_started=1;\n    h = x264_encoder_open( param );')
                after=after.replace('    i_start = x264_mdate();','    /* Host timing sampled before original encode work starts. */')
                after=after.replace('fail:\n    if( pts_warning_cnt','fail:\n    if(ec_roi_started){__parsec_roi_end();__parsec_bench_end();}\n    if( pts_warning_cnt')
                assert after.count('__parsec_roi_begin()')==1 and after.count('__parsec_roi_end()')==1
            elif n=='input/y4m.c':
                after=after.replace('#include "input.h"','#include "input.h"\nextern FILE *ec_x264_input(const char *);')
                after=after.replace('x264_fopen(psz_filename, "rb")','ec_x264_input(psz_filename)')
                after=after.replace('x264_is_regular_file( h->fh )','1 /* seekable staged official file */')
                after=after.replace('h->use_mmap = !x264_cli_mmap_init( &h->mmap, h->fh );','h->use_mmap = 0; /* resident bytes; preserve original read/parse path */')
            else:
                after=after.replace('#include "output.h"','#include "output.h"\nextern FILE *ec_x264_output(const char *);\nextern int ec_x264_close(FILE *);')
                after=after.replace('x264_fopen( psz_filename, "w+b" )','ec_x264_output(psz_filename)').replace('return fclose( (FILE*)handle );','return ec_x264_close((FILE*)handle);')
            target=out/Path(n).name;target.write_text(after);patches.append(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(src/n),tofile=str(target))))
        (logs/'software-integration.patch').write_text(''.join(patches)+'\nNew external-I/O helper:\n'+helper)
        # Query make-expanded CLI object list; reuse exact compiled encoder and
        # unmodified CLI/filter object files. No rebuilding libx264.a.
        fragment=out/'objects.mk';fragment.write_text('ec_print_objects:\n\t@echo $(OBJCLI)\n')
        objects=shlex.split(subprocess.check_output(['make','--no-print-directory','-s','-f','Makefile','-f',str(fragment),'ec_print_objects'],cwd=src,text=True))
        flags=shlex.split(re.search(r'^CFLAGS=(.*)$',(src/'config.mak').read_text(),re.M)[1].replace('$(SRCPATH)',str(src)))
        flags=[x for x in flags if x!='-I.']+['-I'+str(src),'-I'+str(src/'input'),'-I'+str(src/'output'),'-I'+str(hooks)]
        gcc=TOOLS/'riscv64-unknown-linux-gnu-gcc'
        with (logs/'build.log').open('wb') as f:
            for n in ['stage.c','diagnostic-hooks.c','y4m.c','raw.c']:run([gcc,*flags,'-c',out/n,'-o',out/(n+'.o')],stdout=f,stderr=f)
            for target,hook in [('x264',[base/'hooks.o',base/'dac_roi.o']),('x264-diagnostic',[out/'diagnostic-hooks.c.o'])]:
                run([gcc,*flags,'-c',out/'x264.c','-o',out/(target+'.o')],stdout=f,stderr=f)
                repl={'x264.o':out/(target+'.o'),'input/y4m.o':out/'y4m.c.o','output/raw.o':out/'raw.c.o'}
                run([gcc,'-static','-o',out/target,*[repl.get(n,src/n) for n in objects],out/'stage.c.o',*hook,src/'libx264.a','-ldl','-lm','-pthread'],stdout=f,stderr=f)
        cases=[]
        for size in ['test','simsmall','simmedium']:
            dest=out/'inputs/x264'/size;dest.mkdir(parents=True);ar=P/f'pkgs/apps/x264/inputs/input_{size}.tar'
            with tarfile.open(ar) as tf:
                for m in tf.getmembers():
                    if m.isfile():
                        p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=dest/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
            conf=P/f'pkgs/apps/x264/parsec/{size}.runconf';official=shlex.split(re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1'));argv=official[:];i=argv.index('--b-pyramid');argv.insert(i+1,'normal')
            ref=logs/('reference-'+size);shutil.copytree(dest,ref);update(status='QEMU_REFERENCE_RUNNING',input=size)
            with (ref/'stdout.log').open('wb') as f:run(['/usr/bin/qemu-riscv64',c['binary']['path'],*argv],cwd=ref,stdout=f,stderr=f)
            expected=sha(ref/'eledream.264');diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag);update(status='QEMU_DIAGNOSTIC_RUNNING',input=size)
            with (diag/'trace.log').open('wb') as f:run(['/usr/bin/qemu-riscv64','-strace',out/'x264-diagnostic',*argv],cwd=diag,stdout=f,stderr=f)
            assert sha(diag/'eledream.264')==expected,'encoded bitstream differs from same original encoder/reference flags'
            rows=(diag/'trace.log').read_text().splitlines();b=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));e=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'));calls=[l for l in rows[b+1:e] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
            cases.append(dict(program='x264',input=size,argv=argv,original_official_argv=official,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(ar):sha(ar)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,validation=dict(kind='files_sha256',files={'eledream.264':expected}),reference_outputs={str(ref/'eledream.264'):expected},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),fpga_validation='NOT_RUN',algorithm_unchanged=True,legacy_option_integration='bare --b-pyramid maps explicitly to normal (enabled pyramid); all remaining official flags retained identically in Native/C4/reference',roi='encoder open/initialization, headers, every input frame encode and full delayed-frame drain; cleanup/report/external flush outside'))
            state['cases']=cases;update()
        b=out/'x264';update(status='PREPARED_FPGA_NOT_RUN',binaries=dict(x264=dict(path=str(b),sha256=sha(b),reference_path=c['binary']['path'],reference_sha256=c['binary']['sha256'],application_threads=1,algorithm_sources_modified=False)),smoke=parent['smoke'],integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),c4_incompatible_reason='Synchronous syscall remains in complete encode ROI; diagnostic evidence retained' if any(c['diagnostic_roi_syscalls'] for c in cases) else None,reused_original_encoder_sha256=sha(src/'libx264.a'))
        save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state)
    except Exception as exc:update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    print(json.dumps(dict(receipt=str(receipt),roi_syscalls={c['input']:len(c['diagnostic_roi_syscalls']) for c in cases})),flush=True)
if __name__=='__main__':main()
