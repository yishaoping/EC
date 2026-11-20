#!/usr/bin/env python3
"""Original serial/preload Dedup with explicitly staged output IO.

All fragmentation, hashing, compression, deduplication and serialization stay
within the original ROI. Only OS output IO is deferred. Both FPGA groups use
the same ELF; originals supply byte-for-byte and full decode references.
"""
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
    receipt=W/'software/dedup-apps-build.json';assert not receipt.exists()
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-dedup-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir'])
    original=P/'pkgs/kernels/dedup/src';src=out/'src/dedup';shutil.copytree(original,src)
    hooks=out/'src/hooks';shutil.copytree(base/'src/hooks',hooks)
    for n in ['hooks.o','dac_roi.o','roi-smoke']:shutil.copy2(base/n,out/n)
    zsrc=out/'src/zlib';shutil.copytree(P/'pkgs/libs/zlib/src',zsrc)
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile='dedup-serial-preload-staged-output',formal_eligible=True,commands=[],cases=[],parsec_commit=parent['parsec_commit'],algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    save(logs/'state.json',state);shutil.copy2(__file__,logs/'build-script.py')
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':''}
    def run(argv,cwd=out,stdout=None,stderr=None,timeout=1800):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));save(logs/'state.json',state)
        subprocess.run(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,check=True,timeout=timeout)
    common=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-D_XOPEN_SOURCE=600','-fcommon','-fno-strict-aliasing','-I'+str(src),'-I'+str(zsrc),'-I'+str(hooks)]
    (out/'diagnostic-hooks.c').write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    units=['hashtable.c','util.c','dedup.c','rabin.c','encoder.c','decoder.c','mbuffer.c','sha.c']
    with (logs/'build.log').open('wb') as build:
        objects=[]
        for n in ['adler32','compress','crc32','gzio','uncompr','deflate','trees','zutil','inflate','infback','inftrees','inffast']:
            obj=out/(n+'.o');run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*common,'-c',zsrc/(n+'.c'),'-o',obj],stdout=build,stderr=build);objects.append(obj)
        run([TOOLS/'riscv64-unknown-linux-gnu-ar','rcs',out/'libz.a',*objects],stdout=build,stderr=build)
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*common,'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=build,stderr=build)
        def compile(target,objects,source_tree=src):
            run([TOOLS/'riscv64-unknown-linux-gnu-gcc',*common,'-DENABLE_GZIP_COMPRESSION',*(['-DENABLE_PARSEC_HOOKS'] if objects else []),*[source_tree/n for n in units],*objects,out/'libz.a','-lm','-pthread','-o',out/target],stdout=build,stderr=build)
        compile('dedup-reference',[])
        for n in ['encoder.c','util.c']:shutil.copy2(src/n,out/('original-'+n))
        encoder=(src/'encoder.c').read_text()
        header='''#include <malloc.h>
extern int ec_staged_fd;
extern unsigned char *ec_staged_data;
extern size_t ec_staged_size, ec_staged_capacity;
static void ec_prepare_output(const char *path, size_t input_size) {
  ec_staged_capacity=input_size*2+1024*1024;
  ec_staged_data=malloc(ec_staged_capacity);
  if (!ec_staged_data) exit(125);
  for(size_t i=0;i<ec_staged_capacity;i+=4096) ec_staged_data[i]=0;
  ec_staged_fd=open(path,O_CREAT|O_TRUNC|O_WRONLY,0644);
  if(ec_staged_fd<0) exit(125);
  mallopt(M_TRIM_THRESHOLD,-1); mallopt(M_MMAP_MAX,0);
  volatile char *heap=(volatile char*)malloc(128*1024*1024);
  if(!heap) exit(125);
  for(size_t i=0;i<128*1024*1024;i+=4096) heap[i]=0;
  free((void*)heap);
}
static void ec_finish_output(void) {
  int fd=ec_staged_fd; ec_staged_fd=-1;
  if(xwrite(fd,ec_staged_data,ec_staged_size)!=(int)ec_staged_size || close(fd)) exit(125);
  free(ec_staged_data);
}
'''
        enc=encoder.replace('static int create_output_file(char *outfile) {',header+'\nstatic int create_output_file(char *outfile) {')
        needle='fd = open(outfile, O_CREAT|O_TRUNC|O_WRONLY|O_TRUNC, S_IRGRP | S_IWUSR | S_IRUSR | S_IROTH);'
        assert enc.count(needle)==1;enc=enc.replace(needle,'fd = ec_staged_fd;')
        assert enc.count('close(fd_out);')==1;enc=enc.replace('close(fd_out);','/* OS output close deferred until original ROI has ended */')
        anchor='  //Do the processing\n  SerialIntegratedPipeline(&generic_args);'
        assert enc.count(anchor)==1
        roi='#ifdef ENABLE_PARSEC_HOOKS\n  __parsec_roi_begin();\n#endif\n\n'+anchor
        assert enc.count(roi)==1
        enc=enc.replace(roi,'  ec_prepare_output(conf->outfile,filestat.st_size);\n\n'+roi)
        anchor='  SerialIntegratedPipeline(&generic_args);\n\n#ifdef ENABLE_PARSEC_HOOKS\n  __parsec_roi_end();\n#endif'
        assert enc.count(anchor)==1;enc=enc.replace(anchor,anchor+'\n  ec_finish_output();')
        (src/'encoder.c').write_text(enc)
        util=(src/'util.c').read_text()
        extra='''#include <stdlib.h>
#include <string.h>
int ec_staged_fd=-1;
unsigned char *ec_staged_data;
size_t ec_staged_size, ec_staged_capacity;
'''
        staged=extra+util.replace('int xwrite(int sd, const void *buf, size_t len) {','''int xwrite(int sd, const void *buf, size_t len) {
  if(sd==ec_staged_fd && ec_staged_fd>=0) {
    if(len>ec_staged_capacity-ec_staged_size) exit(125);
    memcpy(ec_staged_data+ec_staged_size,buf,len);ec_staged_size+=len;
    return len;
  }''')
        (src/'util.c').write_text(staged)
        patch=''.join(difflib.unified_diff(encoder.splitlines(True),enc.splitlines(True),fromfile=str(original/'encoder.c'),tofile=str(src/'encoder.c')))+''.join(difflib.unified_diff(util.splitlines(True),staged.splitlines(True),fromfile=str(original/'util.c'),tofile=str(src/'util.c')))
        (logs/'software-integration.patch').write_text(patch)
        compile('dedup',[out/'hooks.o',out/'dac_roi.o'])
        compile('dedup-diagnostic',[out/'diagnostic-hooks.o'])
    cases=[]
    for size in ['test','simsmall','simmedium']:
        dest=out/'inputs/dedup'/size;dest.mkdir(parents=True)
        archive=P/f'pkgs/kernels/dedup/inputs/input_{size}.tar'
        with tarfile.open(archive) as tf:
            for m in tf.getmembers():
                if not m.isfile():continue
                p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts
                target=dest/p;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(tf.extractfile(m).read())
        conf=P/f'pkgs/kernels/dedup/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
        ref=logs/('reference-'+size);shutil.copytree(dest,ref)
        with (ref/'stdout.log').open('wb') as so:
            run(['/usr/bin/qemu-riscv64',out/'dedup-reference',*argv],cwd=ref,stdout=so,stderr=so)
            run(['/usr/bin/qemu-riscv64',out/'dedup-reference','-u','-i','output.dat.ddp','-o','decoded.dat'],cwd=ref,stdout=so,stderr=so)
        assert sha(ref/'decoded.dat')==sha(dest/'media.dat'),'full decompression mismatch'
        diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag)
        with (diag/'trace.log').open('wb') as trace:run(['/usr/bin/qemu-riscv64','-strace',out/'dedup-diagnostic',*argv],cwd=diag,stdout=trace,stderr=trace)
        assert sha(diag/'output.dat.ddp')==sha(ref/'output.dat.ddp'),'staged compression changed bytes'
        rows=(diag/'trace.log').read_text().splitlines();bi=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));ei=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        calls=[l for l in rows[bi+1:ei] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        cases.append(dict(program='dedup',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,reference_outputs={str(ref/'output.dat.ddp'):sha(ref/'output.dat.ddp')},validation=dict(kind='files_sha256',files={'output.dat.ddp':sha(ref/'output.dat.ddp')}),full_decode_matches_input=True,diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),algorithm_unchanged=True,fpga_validation='NOT_RUN'))
    binary=out/'dedup';reference=out/'dedup-reference'
    state.update(status='PREPARED_FPGA_NOT_RUN',cases=cases,c4_incompatible_reason='Synchronous syscalls remain in staged ROI' if any(c['diagnostic_roi_syscalls'] for c in cases) else None,binaries=dict(dedup=dict(path=str(binary),sha256=sha(binary),reference_path=str(reference),reference_sha256=sha(reference),application_threads=1,algorithm_sources_modified=False)),smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),sources={str(p.relative_to(out/'src')):sha(p) for p in (out/'src').rglob('*') if p.is_file()},integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),formal_input_policy='Official simmedium, original serial preload mode, full original pipeline ROI, staged OS output with original compression/serialization; exact original output and full decompression reference')
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state);print(json.dumps(dict(receipt=str(receipt),roi_syscalls={c['input']:c['diagnostic_roi_syscalls'] for c in cases})),flush=True)


if __name__=='__main__':main()
