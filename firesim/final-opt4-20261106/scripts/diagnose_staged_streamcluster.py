#!/usr/bin/env python3
"""Evaluate a separately labelled software integration, preserving original ROI hooks/math.
QEMU evidence only; never installs this diagnostic into the FPGA image.
"""
from pathlib import Path
import datetime as dt,difflib,hashlib,json,re,shutil,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'software'/('streamcluster-staged-diagnostic-'+stamp);out.mkdir()
    logs=D/'software'/out.name;logs.mkdir();apps=json.loads((W/'software/apps-build.json').read_text())
    original=Path(apps['output_dir'])/'src/streamcluster/streamcluster.cpp';before=original.read_text();text=before
    header='''#include <malloc.h>
// Software integration only: defer external IO; retain all original math,
// formatting, synthetic input generation, and original parsec ROI hook sites.
static FILE *ec_staged_output;
static FILE *ec_staged_messages;
static char ec_stderr_buffer[1024*1024];
static char ec_output_buffer[1024*1024];
static void ec_prepare_external_io(const char *path) {
  // Bound this candidate to current single-thread synthetic-input cases.
  ec_staged_messages=fmemopen(ec_stderr_buffer,sizeof(ec_stderr_buffer),"w");
  if (!ec_staged_messages) exit(125);
  ec_staged_output=fopen(path,"w");
  if (!ec_staged_output || setvbuf(ec_staged_output,ec_output_buffer,_IOFBF,sizeof(ec_output_buffer))) exit(125);
  mallopt(M_TRIM_THRESHOLD,-1); mallopt(M_MMAP_MAX,0);
  volatile char *reserve=(volatile char*)malloc(32*1024*1024);
  if (!reserve) exit(125);
  for (size_t i=0;i<32*1024*1024;i+=4096) reserve[i]=0;
  free((void*)reserve);
}
static void ec_finish_external_io(void) {
  if (fclose(ec_staged_output) || fflush(ec_staged_messages)) exit(125);
  long n=ftell(ec_staged_messages);
  if (n<0 || (size_t)n>=sizeof(ec_stderr_buffer) ||
      fwrite(ec_stderr_buffer,1,n,stderr)!=(size_t)n ||
      fclose(ec_staged_messages) || fflush(stderr)) exit(125);
}
'''
    anchor='void outcenterIDs('
    assert text.count(anchor)==1;text=text.replace(anchor,header+'\n'+anchor)
    assert text.count('FILE* fp = fopen(outfile, "w");')==1
    text=text.replace('FILE* fp = fopen(outfile, "w");','FILE* fp = ec_staged_output;')
    start=text.index('void outcenterIDs(');end=text.index('void streamCluster(',start)
    part=text[start:end];assert part.count('fclose(fp);')==1
    text=text[:start]+part.replace('fclose(fp);','/* close/flush is deferred to original ROI end */')+text[end:]
    start=text.index('void streamCluster(');end=text.index('int main(',start)
    text=text[:start]+text[start:end].replace('fprintf(stderr,','fprintf(ec_staged_messages,')+text[end:]
    anchor='#ifdef ENABLE_PARSEC_HOOKS\n  __parsec_roi_begin();'
    assert text.count(anchor)==1;text=text.replace(anchor,'if (n <= 0) { fprintf(stderr,"staged-IO diagnostic supports synthetic input only\\n"); return 125; }\n  ec_prepare_external_io(outfilename);\n\n'+anchor)
    anchor='  __parsec_roi_end();\n#endif'
    assert text.count(anchor)==1;text=text.replace(anchor,anchor+'\n  ec_finish_external_io();')
    source=out/'streamcluster.cpp';source.write_text(text)
    (logs/'software-integration.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),text.splitlines(True),fromfile=str(original),tofile=str(source))))
    hook=out/'diagnostic-hooks.c';hook.write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    inc=Path(apps['output_dir'])/'src/hooks';tools=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin');commands=[]
    def run(argv,**kw):
        argv=list(map(str,argv));commands.append(argv);return subprocess.run(argv,stdin=subprocess.DEVNULL,timeout=300,check=True,**kw)
    elf=out/'streamcluster-STAGED-DIAGNOSTIC-NOT-FOR-FPGA'
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-I'+str(inc)]
    with (logs/'build.log').open('wb') as f:
        run([tools/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',hook,'-o',out/'hooks.o'],stdout=f,stderr=f)
        run([tools/'riscv64-unknown-linux-gnu-g++',*flags,'-std=gnu++17','-DENABLE_PARSEC_HOOKS',source,out/'hooks.o','-lm','-pthread','-o',elf],stdout=f,stderr=f)
    cases=[]
    for size in ['test','simsmall']:
        c=next(c for c in apps['cases'] if c['program']=='streamcluster' and c['input']==size);cwd=logs/size;cwd.mkdir()
        with (cwd/'trace.log').open('wb') as err,(cwd/'stdout.log').open('wb') as std:
            run(['/usr/bin/qemu-riscv64','-strace',elf,*c['argv']],cwd=cwd,stdout=std,stderr=err)
        lines=(cwd/'trace.log').read_text().splitlines();beg=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        calls=[l for l in lines[beg+1:end] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
        expected=next(iter(c['reference_outputs'].values()));actual=sha(cwd/'output.txt')
        assert actual==expected,'staged output differs from original algorithm reference'
        cases.append(dict(input=size,argv=c['argv'],syscalls_in_original_roi=calls,output_sha256=actual,expected_sha256=expected,output_matches=True,trace=str(cwd/'trace.log')))
    r=dict(schema='ec-streamcluster-staged-io-diagnostic/1',original_source=str(original),original_sha256=sha(original),candidate_source=str(source),candidate_sha256=sha(source),diagnostic_elf=str(elf),diagnostic_sha256=sha(elf),commands=commands,cases=cases,installed_in_fpga_image=False,fpga_validation='NOT_RUN',formal_eligible=False,limitations=['Synthetic-input serial test/simsmall candidate only','External IO scheduling and allocator residency differ; must use identically in both groups and label as staged IO','No proof yet for asynchronous interrupts, checker task matching or drain'])
    (logs/'result.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({'receipt':str(logs/'result.json'),'cases':cases}),flush=True)
if __name__=='__main__':main()
