from adapter_build import *
import re,struct
out,src=setup('ferret_serial_htif')
app=EC/'Software/PARSEC/pkgs/apps/ferret/src'
candidate=W/'software/candidate-ferret-20261107T052719Z'
original={}
for p in (app/'include').glob('*.h'):
 shutil.copy2(p,src/p.name);original['include/'+p.name]=sha(p)
for name in ['emd.c','emd.h','cass_dist.c','matrix.c']:
 p=app/'src'/name;shutil.copy2(p,src/p.name);original['src/'+name]=sha(p)
shutil.copy2(app/'benchmark/ferret-serial.c',src/'capture-driver.c')
original['benchmark/ferret-serial.c']=sha(app/'benchmark/ferret-serial.c')
shutil.copy2(app/'image/image.h',src/'image.h')
p=src/'capture-driver.c';p.write_text(p.read_text().replace('<../image/image.h>','<image.h>'))
# Interpose the original EMD entry only in a complete Linux/QEMU reference run.
text=(src/'emd.c').read_text().replace('\nemd(signature_t *Signature1','\ncapture_original_emd(signature_t *Signature1')
wrapper=r'''
static unsigned long trace_calls;
static void trace_report(void){printf("[CAPTURE] actual_emd_calls=%lu retained_calls=1 query=official_test_coast\n",trace_calls);}
float emd(signature_t*a,signature_t*b,float(*dist)(cass_size_t,feature_t,feature_t,void*),cass_size_t d,void*p,flow_t*f,int*n){
 float value=capture_original_emd(a,b,dist,d,p,f,n);
 if(trace_calls++==0){
  atexit(trace_report);FILE*out=fopen("emd-trace.bin","wb");assert(out);int dim=d;
  fwrite(&dim,4,1,out);fwrite(&a->n,4,1,out);fwrite(&b->n,4,1,out);fwrite(&value,4,1,out);
  signature_t*s[2]={a,b};for(int k=0;k<2;k++)for(int i=0;i<s[k]->n;i++){
   fwrite(s[k]->Weights+i,4,1,out);fwrite(s[k]->Features[i],4,d,out);
  }fclose(out);printf("[CAPTURE] dim=%d regions_query=%d regions_candidate=%d distance=%.9g\n",dim,a->n,b->n,value);
 }return value;
}
'''
(src/'capture-emd.c').write_text(text+wrapper)
cc=EC/'firesim/envs/manager-1.17.1/riscv-tools/bin/riscv64-unknown-linux-gnu-gcc'
lib=candidate/'src/parsec/lib';deps=candidate/'dependencies'
cmd=[str(cc),'-O2','-ffp-contract=off','-fcommon','-static','-I'+str(src),'-I'+str(deps/'include'),str(src/'capture-driver.c'),str(src/'capture-emd.c'),'-L'+str(lib),'-L'+str(deps/'lib'),'-lcass','-lcassimage','-lcass','-lgsl','-lgslcblas','-ljpeg','-lrt','-lm','-pthread','-o',str(out/'capture-linux.riscv')]
inputs=W/'software/apps-ferret-20261107T055439Z/inputs/ferret/test'
# The original code opens environment read/write. Give this experiment its own input copy.
if not (out/'reference-input').exists():shutil.copytree(inputs,out/'reference-input')
qargs=['corel','lsh','queries','5','5','1','capture-output.txt']
with (out/'capture-build.log').open('wb') as log:subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT)
ref=out/'reference-input'
proc=subprocess.run(['/usr/bin/qemu-riscv64',str(out/'capture-linux.riscv'),*qargs],cwd=ref,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,timeout=180)
(out/'capture.log').write_text(proc.stdout+proc.stderr);assert proc.returncode==0,proc.stderr
assert '[CAPTURE] dim=14' in proc.stdout and (ref/'capture-output.txt').stat().st_size>0,proc.stdout
shutil.copy2(ref/'emd-trace.bin',out/'emd-trace.bin')
trace=(out/'emd-trace.bin').read_bytes();dim,n1,n2,expected=struct.unpack('<iiif',trace[:16]);assert dim==14 and 0<n1<=256 and 0<n2<=256
# Aligned binary32 arrays preserve the captured application's operands exactly.
vals=struct.unpack('<'+'f'*((len(trace)-16)//4),trace[16:]);cursor=0;weights=[];features=[]
for n in [n1,n2]:
 w=[];v=[]
 for _ in range(n):w.append(vals[cursor]);v.extend(vals[cursor+1:cursor+1+dim]);cursor+=1+dim
 weights.append(w);features.append(v)
assert cursor==len(vals)
lines=[]
for k in range(2):
 for label,v in [('weights',weights[k]),('features',features[k])]:
  lines.append('static float '+label+str(k)+'[] = {'+','.join(float(x).hex()+'f' for x in v)+'};')
lines.append('static const float expected_distance='+float(expected).hex()+'f;')
(src/'emd-trace.h').write_text('\n'.join(lines)+'\n')
(src/'values.h').write_text('#pragma once\n#include <float.h>\n#include <limits.h>\n#ifndef MAXFLOAT\n#define MAXFLOAT FLT_MAX\n#endif\n')
# Keep the computational EMD and distance source byte-for-byte. Matrix allocation
# is extracted verbatim to avoid compiling unused Linux mmap/file functions.
mat=(src/'matrix.c').read_text();begin=mat.index('void **__matrix_alloc (');end=mat.index('\nvoid __matrix_free',begin)
(src/'matrix-alloc.c').write_text('#include <cass.h>\n'+mat[begin:end])
shutil.copy2(app/'src/chunk_cnt.inc',src/'chunk_cnt.inc')
(src/'chunk-count.c').write_text('#include <stdint.h>\n#include \"chunk_cnt.inc\"\n')
# The original EMD uses ~100 KiB of automatic working arrays.
ld=(out/'htif.ld').read_text().replace('__stack_size_min = 24K','__stack_size_min = 512K');(out/'htif.ld').write_text(ld)
adapter=r'''#include <cass.h>
#include "emd.h"
#include "emd-trace.h"
static signature_t a,b;static feature_t fa[256],fb[256];static float result;
static float ground(cass_size_t d,feature_t a,feature_t b,void*p){return dist_L2_float(d,a,b);}
void workload_prepare(void){
 a.n=N1;b.n=N2;a.Features=fa;b.Features=fb;a.Weights=weights0;b.Weights=weights1;
 for(int i=0;i<a.n;i++)fa[i]=features0+14*i;
 for(int i=0;i<b.n;i++)fb[i]=features1+14*i;
 /* Warm the original thread-local cost-matrix allocation before the measured replay. */
 result=emd(&a,&b,ground,14,NULL,NULL,NULL);
}
void workload_run(void){result=emd(&a,&b,ground,14,NULL,NULL,NULL);}
int workload_verify(void){
 int ok=isfinite(result)&&fabsf(result-expected_distance)<=1e-5f+1e-5f*fabsf(expected_distance);
 uint64_t h=14695981039346656037ULL;h^=(uint64_t)llround(result*10000.0);h*=1099511628211ULL;
 printf("[OUTPUT] benchmark=ferret checksum=%016lx verified=%d trace_calls=1 dimensions=14\n",(unsigned long)h,ok);return ok;
}
'''.replace('N1',str(n1)).replace('N2',str(n2))
(src/'ferret-adapter.c').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
metadata=dict(benchmark='ferret',profile='real-test-first-emd-warm-replay',method='CPU_GG_REAL_TRACE_COMPONENT_REPLAY',extra_flags=['-ffp-contract=off'],original_source_sha256=original,input={'official_test_path':str(inputs),'files_sha256':{str(p.relative_to(inputs)):sha(p) for p in inputs.rglob('*') if p.is_file()},'trace_path':str(out/'emd-trace.bin'),'trace_sha256':sha(out/'emd-trace.bin'),'dimensions':dim,'regions_query':n1,'regions_candidate':n2},roi_scope='One original EMD distance computation using first real query/candidate signature pair captured during the complete original serial Ferret official-test query; cost matrix allocation warmed outside ROI',correctness={'reference_distance':expected,'tolerance':'abs 1e-5 + rel 1e-5','capture_log':str(out/'capture.log'),'capture_driver_sha256':sha(out/'capture-linux.riscv'),'capture_command':cmd,'qemu_command':['/usr/bin/qemu-riscv64',str(out/'capture-linux.riscv'),*qargs]},limitations=['Actual first EMD invocation operands from official full test, not a synthetic vector microbenchmark','One component invocation only; excludes decode, segmentation, extraction, LSH lookup, candidate control and result IO','Component frequency/time coverage and extrapolation error against full Ferret are uncalibrated; do not publish as full Ferret slowdown','Original cost-matrix allocation is warmed before ROI equally in both modes; original EMD and cass_dist source unchanged','Main stack reservation raised to 512 KiB for original automatic EMD arrays'],max_target_cycles=3000000,timeout_seconds=3600)
j=build(out,['emd.c','cass_dist.c','matrix-alloc.c','ferret-adapter.c','chunk-count.c'],metadata)
print(out/'manifest.json')
