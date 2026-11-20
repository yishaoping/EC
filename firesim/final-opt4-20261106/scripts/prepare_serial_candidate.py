#!/usr/bin/env python3
"""Build original serial Bodytrack/Freqmine and audit their complete official ROI."""
import argparse
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
    ap=argparse.ArgumentParser();ap.add_argument('program',choices=['bodytrack','freqmine']);ap.add_argument('--stage',action='store_true');a=ap.parse_args();name=a.program
    profile=(name+'-staged-output' if name=='bodytrack' else name+'-staged-resident') if a.stage else name
    receipt=W/f'software/{profile}-apps-build.json';assert not receipt.exists()
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-'+profile+'-'+stamp);logs=D/'software'/out.name
    out.mkdir();logs.mkdir()
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir'])
    src=out/'src'/name;shutil.copytree(P/f'pkgs/apps/{name}/src',src)
    hooks=out/'src/hooks';shutil.copytree(base/'src/hooks',hooks)
    for n in ['hooks.o','dac_roi.o','roi-smoke']:shutil.copy2(base/n,out/n)
    units=([src/'TrackingBenchmark'/n for n in ['AnnealingFactor.cpp','BodyGeometry.cpp','BodyPose.cpp','CameraModel.cpp','CovarianceMatrix.cpp','ImageMeasurements.cpp','ImageProjection.cpp','RandomGenerator.cpp','TrackingModel.cpp','main.cpp']]+[src/'FlexImageLib/FlexImage.cpp',src/'FlexImageLib/FlexIO.cpp']) if name=='bodytrack' else [src/n for n in ['fpmax.cpp','data.cpp','fp_tree.cpp','buffer.cpp','fsout.cpp','fp_node.cpp','wtime.cpp']]
    reference_units=units
    if a.stage:
        pristine=out/'pristine';shutil.copytree(src,pristine)
        reference_units=[pristine/p.relative_to(src) for p in units]
    if a.stage and name=='freqmine':
        before={n:(src/n).read_text() for n in ['fpmax.cpp','fp_tree.cpp','data.cpp','data.h']}
        main=before['fpmax.cpp'].replace('#include <stdio.h>','#include <stdio.h>\n#include <malloc.h>\n#include <sched.h>')
        roi='#ifdef ENABLE_PARSEC_HOOKS\n\t__parsec_roi_begin();'
        assert main.count(roi)==1
        prepare='''// Same sole hart0 context; move auxiliary affinity before the ROI.
        cpu_set_t ec_mask; CPU_ZERO(&ec_mask); CPU_SET(0,&ec_mask);
        if(sched_setaffinity(0,sizeof(ec_mask),&ec_mask)) exit(125);
        mallopt(M_TRIM_THRESHOLD,-1); mallopt(M_MMAP_MAX,0);
        volatile char *ec_heap=(volatile char*)malloc(512*1024*1024);
        if(!ec_heap) exit(125);
        for(size_t ec_i=0;ec_i<512*1024*1024;ec_i+=4096) ec_heap[ec_i]=0;
        free((void*)ec_heap);
'''
        anchor='\tData* fdat=new Data(argv[1]);'
        assert main.count(anchor)==1
        main=main.replace(anchor,prepare+anchor)
        main=main.replace('__parsec_roi_end();\n#endif','__parsec_roi_end();\n#endif\n        fdat->ec_close_after_roi();')
        tree=before['fp_tree.cpp']
        start=tree.index('#ifdef __linux__',tree.index('CPU_ZERO')-200)
        end=tree.index('#endif\n#endif',start)+len('#endif\n#endif')
        tree=tree[:start]+'/* Sole-worker affinity set before original ROI. */'+tree[end:]
        # These variables serve only diagnostic timing/prints, never FP-growth.
        # Remove timing instrumentation and its report, do not invent timestamps.
        main=re.sub(r'^\s*wtime\(&\w+\);', '\n/* auxiliary wall-clock sampling removed; FPGA ROI is measured */',main,flags=re.M)
        main=re.sub(r'^\s*printf \("the data preparation cost[^\n]*\n','\n/* Auxiliary timing report unavailable in staged profile. */\n',main,flags=re.M)
        tree=re.sub(r'^\s*wtime\(&\w+\);','\n/* auxiliary wall-clock sampling removed */',tree,flags=re.M)
        data=before['data.cpp'];start=data.index('#ifndef BINARY');end=data.index('#endif',start)+len('#endif')
        data=data[:start]+'''// Preload bytes only; all transaction parsing remains in the ROI.
  FILE *source=fopen(filename,"rb");
  if(!source) { in=NULL; return; }
  if(fseek(source,0,SEEK_END)) exit(125);
  long size=ftell(source); if(size<0 || fseek(source,0,SEEK_SET)) exit(125);
  void *bytes=malloc(size?size:1); if(!bytes) exit(125);
  if(fread(bytes,1,size,source)!=(size_t)size || fclose(source)) exit(125);
  in=fmemopen(bytes,size,"rb"); if(!in) exit(125);
'''+data[end:]
        hdr=before['data.h'].replace('void close(){if(in)fclose(in);}','void close(){/* OS close deferred after original ROI */}\n        void ec_close_after_roi(){if(in){fclose(in);in=NULL;}}')
        after={'fpmax.cpp':main,'fp_tree.cpp':tree,'data.cpp':data,'data.h':hdr}
        for n,t in after.items():(src/n).write_text(t)
        (logs/'software-integration.patch').write_text(''.join(''.join(difflib.unified_diff(before[n].splitlines(True),after[n].splitlines(True),fromfile=str(pristine/n),tofile=str(src/n))) for n in before))
    if a.stage and name=='bodytrack':
        mainpath=src/'TrackingBenchmark/main.cpp';flexpath=src/'FlexImageLib/FlexIO.cpp';flexheader=src/'FlexImageLib/FlexIO.h'
        before={str(p.relative_to(src)):p.read_text() for p in [mainpath,flexpath,flexheader]}
        main=mainpath.read_text()
        anchor='//Body tracking Single Threaded'
        assert main.count(anchor)==1
        helper='''#include <map>
#include <sstream>
#include <malloc.h>
static std::map<std::string,std::vector<char> > ec_images;
static std::map<std::string,std::vector<char> > ec_output_images;
static std::map<FILE*,std::string> ec_output_handles;
static std::map<std::string,long> ec_output_lengths;
FILE *ec_bodytrack_output(const char *path) {
  std::map<std::string,std::vector<char> >::iterator it=ec_output_images.find(path);
  if(it==ec_output_images.end()) exit(125);
  FILE *f=fmemopen(it->second.data(),it->second.size(),"wb");if(!f)exit(125);
  ec_output_handles[f]=path;return f;
}
void ec_bodytrack_close_output(FILE *f) {
  long n=ftell(f);if(n<0)exit(125);
  ec_output_lengths[ec_output_handles[f]]=n;
  if(fclose(f))exit(125);
}
static void ec_finish_images(void) {
  for(std::map<std::string,long>::iterator it=ec_output_lengths.begin();it!=ec_output_lengths.end();it++) {
    FILE *f=fopen(it->first.c_str(),"wb");if(!f)exit(125);
    if(fwrite(ec_output_images[it->first].data(),1,it->second,f)!=(size_t)it->second||fclose(f))exit(125);
  }
}
FILE *ec_bodytrack_input(const char *path) {
  std::map<std::string,std::vector<char> >::iterator it=ec_images.find(path);
  if(it==ec_images.end()) {fprintf(stderr,"unstaged input %s\\n",path);exit(125);}
  FILE *f=fmemopen(it->second.data(),it->second.size(),"rb");
  if(!f) exit(125);return f;
}
static void ec_prepare_images(const std::string &path,int cameras,int frames) {
  mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
  volatile char *heap=(volatile char*)malloc(128*1024*1024);
  if(!heap) exit(125);
  for(size_t i=0;i<128*1024*1024;i+=4096) heap[i]=0;
  free((void*)heap);
  for(int frame=0;frame<frames;frame++) for(int camera=1;camera<=cameras;camera++) for(int kind=0;kind<2;kind++) {
    char suffix[128];snprintf(suffix,sizeof(suffix),"%s%d/image%04d.bmp",kind?"CAM":"FG",camera,frame);
    std::string name=path+suffix;FILE *f=fopen(name.c_str(),"rb");if(!f)exit(125);
    if(fseek(f,0,SEEK_END))exit(125);long n=ftell(f);if(n<=0||fseek(f,0,SEEK_SET))exit(125);
    std::vector<char> &bytes=ec_images[name];bytes.resize(n);
    if(fread(bytes.data(),1,n,f)!=(size_t)n||fclose(f))exit(125);
  }
  for(int frame=0;frame<frames;frame++) {
    char suffix[128];snprintf(suffix,sizeof(suffix),"Result%04d.bmp",frame);
    ec_output_images[path+suffix].resize(8*1024*1024);
  }
}
'''
        main=main.replace(anchor,helper+'\n'+anchor)
        start=main.index('int mainSingleThread(');end=main.index('int main(int argc',start)
        single=main[start:end]
        single=single.replace('TrackingModel model;','ec_prepare_images(path,cameras,frames);\n\tTrackingModel model;')
        needle='ofstream outputFileAvg((path + "poses.txt").c_str());'
        assert single.count(needle)==1
        single=single.replace(needle,'ofstream ec_actual_output((path + "poses.txt").c_str());\n\tif(!ec_actual_output)exit(125);\n\tostringstream outputFileAvg;\n\tostringstream ec_messages;\n\tstreambuf *ec_old_messages=cout.rdbuf(ec_messages.rdbuf());')
        roiend='__parsec_roi_end();\n#endif'
        assert single.count(roiend)==1
        single=single.replace(roiend,roiend+'\n\tcout.rdbuf(ec_old_messages);\n\tcout << ec_messages.str();\n\tec_actual_output << outputFileAvg.str();\n\tec_actual_output.flush();\n\tif(!ec_actual_output)exit(125);\n\tec_finish_images();')
        main=main[:start]+single+main[end:];mainpath.write_text(main)
        flex=flexpath.read_text();assert flex.count('in=fopen(file,"rb");')==4
        flex=flex.replace('#include "FlexIO.h"','#include "FlexIO.h"\nextern FILE *ec_bodytrack_input(const char *);')
        flex=flex.replace('in=fopen(file,"rb");','in=ec_bodytrack_input(file);');flexpath.write_text(flex)
        header=flexheader.read_text().replace('#include <stdio.h>','#include <stdio.h>\nextern FILE *ec_bodytrack_output(const char *);\nextern void ec_bodytrack_close_output(FILE *);')
        assert header.count('f=fopen(file,"wb");')==1 and header.count('fclose(f);')==1
        header=header.replace('f=fopen(file,"wb");','f=ec_bodytrack_output(file);').replace('fclose(f);','ec_bodytrack_close_output(f);');flexheader.write_text(header)
        (logs/'software-integration.patch').write_text(''.join(''.join(difflib.unified_diff(t.splitlines(True),(src/n).read_text().splitlines(True),fromfile=str(pristine/n),tofile=str(src/n))) for n,t in before.items()))
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile=name+'-serial-staged-input-preallocated-heap-no-aux-timing' if a.stage else 'original-'+name+'-serial',formal_eligible=True,commands=[],cases=[],parsec_commit=parent['parsec_commit'],algorithm_sources_modified=False,fpga_validation='NOT_RUN')
    save(logs/'state.json',state);shutil.copy2(__file__,logs/'build-script.py')
    (out/'diagnostic-hooks.c').write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1'}
    def run(argv,cwd=out,stdout=None,stderr=None):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));save(logs/'state.json',state)
        subprocess.run(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,check=True,timeout=1800)
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-std=gnu++17','-I'+str(hooks),'-I'+str(src)]
    if name=='bodytrack':flags+=['-DHAVE_STDINT_H=1','-I'+str(src/'FlexImageLib'),'-I'+str(src/'TrackingBenchmark')]
    with (logs/'build.log').open('wb') as build:
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc','-static','-march=rv64gc','-mabi=lp64d','-I'+str(hooks),'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=build,stderr=build)
        for target,objects in [(name,[out/'hooks.o',out/'dac_roi.o']),(name+'-reference',[]),(name+'-diagnostic',[out/'diagnostic-hooks.o'])]:
            target_flags=[f.replace(str(src),str(pristine)) for f in flags] if a.stage and target==name+'-reference' else flags
            run([TOOLS/'riscv64-unknown-linux-gnu-g++',*target_flags,*(['-DENABLE_PARSEC_HOOKS'] if objects else []),*(reference_units if target==name+'-reference' else units),*objects,'-lm','-pthread','-o',out/target],stdout=build,stderr=build)
    cases=[]
    for size in ['test','simsmall','simmedium']:
        dest=out/'inputs'/name/size;dest.mkdir(parents=True)
        archive=P/f'pkgs/apps/{name}/inputs/input_{size}.tar'
        with tarfile.open(archive) as tf:
            for m in tf.getmembers():
                if not m.isfile():continue
                p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts
                target=dest/p;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(tf.extractfile(m).read())
        conf=P/f'pkgs/apps/{name}/parsec/{size}.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
        ref=logs/('reference-'+size);shutil.copytree(dest,ref)
        with (ref/'stdout.log').open('wb') as so:run(['/usr/bin/qemu-riscv64',out/(name+'-reference'),*argv],cwd=ref,stdout=so,stderr=so)
        if name=='bodytrack':
            result_file=argv[0]+'/poses.txt';expected=ref/result_file;assert len(expected.read_text().splitlines())==int(argv[2]);files={result_file:sha(expected)}
            files.update({str(p.relative_to(ref)):sha(p) for p in (ref/argv[0]).glob('Result*.bmp')})
            validation=dict(kind='files_sha256',files=files)
        else:
            expected=ref/'counts.txt';lines=re.findall(r'^\d+$',(ref/'stdout.log').read_text(),re.M);assert lines
            expected.write_text('\n'.join(lines)+'\n');validation=dict(kind='stdout_integer_hash',reference=str(expected),reference_sha256=sha(expected))
        diag=logs/('diagnostic-'+size);shutil.copytree(dest,diag)
        with (diag/'combined.log').open('wb') as so:run(['/usr/bin/qemu-riscv64',out/(name+'-diagnostic'),*argv],cwd=diag,stdout=so,stderr=so)
        if name=='freqmine':assert re.findall(r'^\d+$',(diag/'combined.log').read_text(),re.M)==lines, 'integration changed mining counts'
        with (diag/'trace.log').open('wb') as trace:run(['/usr/bin/qemu-riscv64','-strace',out/(name+'-diagnostic'),*argv],cwd=diag,stdout=trace,stderr=trace)
        rows=(diag/'trace.log').read_text().splitlines();begin=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        calls=[l for l in rows[begin+1:end] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        if name=='bodytrack':assert all(sha(diag/p)==h for p,h in validation['files'].items()), 'pose or rendered BMP differs from original'
        cases.append(dict(program=name,input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},threads=1,warmups=0,reference_outputs={str(expected):sha(expected)},validation=validation,software_reference='QEMU_RISCV_USER_ONLY',fpga_validation='NOT_RUN',algorithm_unchanged=True,diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log')))
    binary=out/name;reference=out/(name+'-reference')
    state.update(status='PREPARED_FPGA_NOT_RUN',cases=cases,
        c4_incompatible_reason='Synchronous syscalls in original ROI; software staging or protocol support required' if any(c['diagnostic_roi_syscalls'] for c in cases) else None,
        binaries={name:dict(path=str(binary),sha256=sha(binary),reference_path=str(reference),reference_sha256=sha(reference),application_threads=1,algorithm_sources_modified=False)},smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),sources={str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()},formal_input_policy='Official simmedium, one thread, original full computation ROI, no warmup; exact complete output check')
    if a.stage:state.update(integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),auxiliary_wallclock_report='removed only for freqmine; FPGA ROI target cycles are authoritative',heap_preallocation_bytes=(512 if name=='freqmine' else 128)*1024*1024)
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state);print(json.dumps(dict(receipt=str(receipt),roi_syscall_counts={c['input']:len(c['diagnostic_roi_syscalls']) for c in cases})),flush=True)


if __name__=='__main__':main()
