#!/usr/bin/env python3
"""Reuse serial CASS/JPEG; stage bytes and metadata, retain full original scan ROI."""
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

HELPER=r'''#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <malloc.h>
#include <map>
#include <string>
#include <vector>
struct Directory {std::vector<struct dirent> entries; size_t next;};
static std::map<std::string,Directory> directories;
static std::map<std::string,struct stat> metadata;
static std::map<std::string,std::vector<char> > bytes;
static char *output_bytes; static size_t output_length;
static FILE *output_stream;
static void preload(const std::string &p) {
 struct stat st;if(stat(p.c_str(),&st))exit(125);metadata[p]=st;
 if(S_ISDIR(st.st_mode)) {
  DIR *d=opendir(p.c_str());if(!d)exit(125);struct dirent *e;
  while((e=readdir(d))) directories[p].entries.push_back(*e);
  if(closedir(d))exit(125);
  directories[p].next=0;
  for(size_t i=0;i<directories[p].entries.size();i++) {
   const char *n=directories[p].entries[i].d_name;
   if(!strcmp(n,".")||!strcmp(n,".."))continue;
   preload(p=="."?std::string(n):p+"/"+n);
  }
 } else if(S_ISREG(st.st_mode)) {
  FILE *f=fopen(p.c_str(),"rb");if(!f)exit(125);
  std::vector<char> &v=bytes[p];v.resize(st.st_size);
  if(fread(v.data(),1,v.size(),f)!=v.size()||fclose(f))exit(125);
 }
}
extern "C" void ec_ferret_prepare(const char *p) {
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *h=(volatile char*)malloc(512*1024*1024);if(!h)exit(125);
 for(size_t i=0;i<512*1024*1024;i+=4096)h[i]=0;free((void*)h);
 preload(p);
}
extern "C" DIR *ec_ferret_opendir(const char *p) {
 std::string key=p;while(key.size()>1&&key.back()=='/')key.pop_back();
 auto it=directories.find(key);if(it==directories.end())exit(125);
 it->second.next=0;return reinterpret_cast<DIR*>(&it->second);
}
extern "C" struct dirent *ec_ferret_readdir(DIR *p) {
 Directory *d=reinterpret_cast<Directory*>(p);
 return d->next==d->entries.size()?NULL:&d->entries[d->next++];
}
extern "C" int ec_ferret_closedir(DIR *) {return 0;}
extern "C" int ec_ferret_stat(const char *p,struct stat *s) {
 auto it=metadata.find(p);if(it==metadata.end())exit(125);*s=it->second;return 0;
}
extern "C" FILE *ec_ferret_input(const char *p) {
 auto it=bytes.find(p);if(it==bytes.end())exit(125);
 FILE *f=fmemopen(it->second.data(),it->second.size(),"rb");if(!f)exit(125);return f;
}
extern "C" FILE *ec_ferret_output(void) {
 output_stream=open_memstream(&output_bytes,&output_length);if(!output_stream)exit(125);return output_stream;
}
extern "C" void ec_ferret_flush(const char *p) {
 if(fflush(output_stream))exit(125);FILE *f=fopen(p,"wb");if(!f)exit(125);
 if(fwrite(output_bytes,1,output_length,f)!=output_length||fclose(f))exit(125);
}
'''

def main():
    receipt=W/'software/ferret-apps-build.json';assert not receipt.exists()
    cpath=W/'software/ferret-candidate-build.json';c=json.loads(cpath.read_text());assert c['status']=='COMPILED_NOT_FPGA_READY'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-ferret-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    src=Path(c['source_dir']);prefix=Path(c['output_dir'])/'dependencies'
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir']);hooks=base/'src/hooks'
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='ferret-serial-staged-external-io',formal_eligible=True,parsec_commit=parent['parsec_commit'],commands=[],cases=[],candidate_receipt=str(cpath),candidate_receipt_sha256=sha(cpath),algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    status=D/'software/ferret-preparation-state.json'
    def update(**kw):state.update(kw);save(status,state);save(logs/'state.json',state)
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1'}
    def run(argv,cwd=out,stdout=None,stderr=None,timeout=3600):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));update()
        child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,start_new_session=True);update(child_pid=child.pid)
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            import signal
            os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);raise
        assert rc==0,(rc,argv)
    try:
        before=(src/'benchmark/ferret-serial.c').read_text();after=before.replace('#include <cass.h>','#include <cass.h>\nextern void ec_ferret_prepare(const char *);\nextern FILE *ec_ferret_input(const char *);\nextern FILE *ec_ferret_output(void);\nextern void ec_ferret_flush(const char *);\nextern DIR *ec_ferret_opendir(const char *);\nextern struct dirent *ec_ferret_readdir(DIR *);\nextern int ec_ferret_closedir(DIR *);\nextern int ec_ferret_stat(const char *,struct stat *);')
        # DIR declarations need the existing dirent include, already above cass.h.
        after=after.replace('opendir(dir)','ec_ferret_opendir(dir)').replace('readdir(pd)','ec_ferret_readdir(pd)').replace('closedir(pd)','ec_ferret_closedir(pd)').replace('stat(path, &st)','ec_ferret_stat(path, &st)')
        after=after.replace('fopen(output_path, "w")','ec_ferret_output()').replace('stimer_tick(&tmr);','ec_ferret_prepare(query_dir);\n\tstimer_tick(&tmr);').replace('stimer_tuck(&tmr, "QUERY TIME");','ec_ferret_flush(output_path);\n\tstimer_tuck(&tmr, "QUERY TIME");')
        (out/'ferret.c').write_text(after)
        image_before=(src/'image/image.c').read_text();image_after=image_before.replace('int image_read_rgb_hsv (','extern FILE *ec_ferret_input(const char *);\nint image_read_rgb_hsv (').replace('infile = fopen(filename, "rb")','infile = ec_ferret_input(filename)');assert image_after!=image_before
        (out/'image.c').write_text(image_after);(out/'stage.cc').write_text(HELPER)
        patch=''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(src/'benchmark/ferret-serial.c'),tofile=str(out/'ferret.c')))+''.join(difflib.unified_diff(image_before.splitlines(True),image_after.splitlines(True),fromfile=str(src/'image/image.c'),tofile=str(out/'image.c')))
        (logs/'software-integration.patch').write_text(patch+'\nNew staging helper (no image/query arithmetic):\n'+HELPER)
        (out/'diagnostic-hooks.c').write_text('#include "hooks.h"\n#include <unistd.h>\nvoid __parsec_bench_begin(enum __parsec_benchmark b){(void)b;}\nvoid __parsec_bench_end(void){}\nvoid __parsec_roi_begin(void){write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}\nvoid __parsec_roi_end(void){write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}\n')
        flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-fcommon','-D_GNU_SOURCE','-I'+str(prefix/'include'),'-I'+str(src/'include'),'-I'+str(src/'image'),'-I'+str(hooks)]
        with (logs/'build.log').open('wb') as f:
            run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',out/'image.c','-o',out/'image.o'],stdout=f,stderr=f)
            run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,'-std=gnu++17','-c',out/'stage.cc','-o',out/'stage.o'],stdout=f,stderr=f)
            run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=f,stderr=f)
            for target,objects in [('ferret',[base/'hooks.o',base/'dac_roi.o']),('ferret-diagnostic',[out/'diagnostic-hooks.o'])]:
                run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*flags,'-DENABLE_PARSEC_HOOKS','-c',out/'ferret.c','-o',out/(target+'.o')],stdout=f,stderr=f)
                run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,out/(target+'.o'),out/'image.o',out/'stage.o',*objects,'-L'+str(src/'parsec/lib'),'-L'+str(prefix/'lib'),'-lcass','-lcassimage','-lcass','-lgsl','-lgslcblas','-ljpeg','-lrt','-lm','-pthread','-o',out/target],stdout=f,stderr=f)
        for size in ['test','simsmall','simmedium']:
            dest=out/'inputs/ferret'/size;dest.mkdir(parents=True);archive=P/f'pkgs/apps/ferret/inputs/input_{size}.tar'
            with tarfile.open(archive) as tf:
                for m in tf.getmembers():
                    if m.isfile():
                        p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=dest/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
            conf=P/f'pkgs/apps/ferret/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
            ref=logs/('reference-'+size);shutil.copytree(dest,ref);update(status='QEMU_REFERENCE_RUNNING',input=size)
            with (ref/'stdout.log').open('wb') as f:run(['/usr/bin/qemu-riscv64',c['binary']['path'],*argv],cwd=ref,stdout=f,stderr=f)
            result=ref/'output.txt';assert result.stat().st_size>0;expected=sha(result)
            diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag);update(status='QEMU_DIAGNOSTIC_RUNNING',input=size)
            with (diag/'trace.log').open('wb') as f:run(['/usr/bin/qemu-riscv64','-strace',out/'ferret-diagnostic',*argv],cwd=diag,stdout=f,stderr=f)
            assert sha(diag/'output.txt')==expected, 'full query ranking differs from original serial reference'
            rows=(diag/'trace.log').read_text().splitlines();b=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));e=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
            calls=[l for l in rows[b+1:e] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
            state['cases'].append(dict(program='ferret',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,validation=dict(kind='files_sha256',files={'output.txt':expected}),reference_outputs={str(result):expected},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),fpga_validation='NOT_RUN',algorithm_unchanged=True))
        binary=out/'ferret';update(status='PREPARED_FPGA_NOT_RUN',binaries=dict(ferret=dict(path=str(binary),sha256=sha(binary),reference_path=c['binary']['path'],reference_sha256=c['binary']['sha256'],application_threads=1,algorithm_sources_modified=False)),smoke=parent['smoke'],integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),c4_incompatible_reason='Synchronous syscall remains in original full scan ROI; inspect diagnostic traces' if any(c['diagnostic_roi_syscalls'] for c in state['cases']) else None,formal_input_policy='Official simmedium, sole serial worker, complete original scan/JPEG decode/features/query/ranking/output formatting ROI; external bytes/metadata staged equally in Native/C4')
        save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state)
    except Exception as exc:update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    print(json.dumps(dict(receipt=str(receipt),status=state['status'],roi_syscalls={c['input']:len(c['diagnostic_roi_syscalls']) for c in state['cases']})),flush=True)

if __name__=='__main__':main()
