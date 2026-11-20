from adapter_build import *
import struct,math

out,src=setup('ferret_real_emd_costmatrix')
parent=ROOT/'software/ferret_serial_htif_qword_setup/manifest.json';old=read(parent)
assert not (out/'manifest.json').exists(),'Do not overwrite a bound profile'
for p in (parent.parent/'source').glob('*.h'):shutil.copy2(p,src/p.name)
trace=Path(old['input']['trace_path']).read_bytes();dim,n1,n2,distance=struct.unpack('<iiif',trace[:16]);assert (dim,n1,n2)==(14,14,9)
v=struct.unpack('<'+'f'*((len(trace)-16)//4),trace[16:]);q=[];c=[];cursor=0
for n,dest in [(n1,q),(n2,c)]:
 for _ in range(n):dest.append(v[cursor+1:cursor+1+dim]);cursor+=dim+1
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
expected=[]
for a in q:
 for b in c:
  total=0.0
  for x,y in zip(a,b):t=f32(x-y);total=f32(total+f32(t*t))
  expected.append(f32(math.sqrt(total)))
(src/'expected-costs.h').write_text('static const float expected_costs[126]={'+','.join(float(x).hex()+'f' for x in expected)+'};\n')
original=(parent.parent/'source/emd.c').read_text()
loop=original[original.index('  /* COMPUTE THE DISTANCE MATRIX */'):original.index('  /* SUM UP THE SUPPLY AND DEMAND */')]
adapter=r'''#include <cass.h>
#include "emd.h"
#include "emd-trace.h"
#include "expected-costs.h"
#include <stdint.h>
static signature_t a,b;static feature_t fa[256],fb[256];
static emd_state_t saved_state;
/* Preserve original double allocation's 257-double row stride, with the
 * original emd_state_t float row interpretation. No allocator is in ROI. */
static double matrix[257][257] __attribute__((section(".data.ferret_matrix")))={0};
static float *rows[257];
static float ground(cass_size_t d,feature_t a,feature_t b,void*p){return dist_L2_float(d,a,b);}
static void original_matrix_phase(emd_state_t *state,signature_t *Signature1,signature_t *Signature2,float(*Dist)(cass_size_t,feature_t,feature_t,void*),cass_size_t dim,void *param){
 int i,j;
LOOP
}
void workload_prepare(void){
 a.n=14;b.n=9;a.Features=fa;b.Features=fb;a.Weights=weights0;b.Weights=weights1;
 for(int i=0;i<14;i++)fa[i]=features0+14*i;
 for(int i=0;i<9;i++)fb[i]=features1+14*i;
 for(int i=0;i<257;i++)rows[i]=(float*)matrix[i];
 saved_state.n1=14;saved_state.n2=9;saved_state.C=rows;
}
void workload_run(void){original_matrix_phase(&saved_state,&a,&b,ground,14,NULL);}
int workload_verify(void){
 int ok=1,k=0;uint64_t h=14695981039346656037ULL;float max=0;
 for(int i=0;i<14;i++)for(int j=0;j<9;j++,k++){
  float x=saved_state.C[i][j];if(!isfinite(x)||fabsf(x-expected_costs[k])>2e-6f+fabsf(expected_costs[k])*1e-6f)ok=0;
  if(x>max)max=x;h^=(uint64_t)llround((double)x*100000.0);h*=1099511628211ULL;
 }
 ok=ok&&k==126&&max==saved_state.maxC;
 printf("[OUTPUT] benchmark=ferret checksum=%016lx verified=%d captured_pairs=126 dimensions=14 phase=emd_distance_matrix\n",(unsigned long)h,ok);return ok;
}
'''.replace('LOOP',loop)
(src/'ferret-costmatrix.c').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['ferret-costmatrix.c'],dict(benchmark='ferret',profile='real-test-emd-distance-matrix-126-pairs',method='CPU_GG_REAL_TRACE_COMPONENT_REPLAY',extra_flags=['-ffp-contract=off'],input=old['input'],capture_parent_manifest=str(parent),capture_parent_manifest_sha256=sha(parent),correctness={'oracle':'Independent Python binary32 subtract/multiply/accumulate then sqrt, every one of126 cost values','absolute_tolerance':2e-6,'relative_tolerance':1e-6,'expected_costs_sha256':sha(src/'expected-costs.h'),'original_matrix_loop_sha256':hashlib.sha256(loop.encode()).hexdigest(),'actual_capture_log':old['correctness']['capture_log']},output_acceptance='verified_fields_checksum_may_differ_from_host',original_source_sha256=old['original_source_sha256'],roi_scope='Original emdinit distance-matrix loop over all126 region pairs from actual official-test first EMD query/candidate capture; original inline14-dimensional ground distance; excludes EMD flow solution',limitations=['Real captured EMD subphase only, not complete EMD or Ferret','Original warmed full-EMD profile produced actual checker cancellations; this narrower scope does not repair or validate that full computation','Full-application and full-EMD time coverage/sampling error uncalibrated; no extrapolation','Explicit preloaded matrix and global state change cache/stack setup relative to full EMD; original full257-double row stride and original float-row interpretation retained'],adaptations=['Matrix rows are explicitly loaded zero ELF data before target execution; pointer setup outsideROI; same software objects/input in both modes','Exact original emdinit distance-matrix loop copied verbatim from retained source; independent oracle checks all126 results'],max_target_cycles=1500000,timeout_seconds=3600))
save(out/'independent-reference.json',dict(passed=True,method='Pure Python binary32 oracle for actual captured126pairs; host target adapter verifies all126 values',trace_sha256=hashlib.sha256(trace).hexdigest(),expected_costs=expected,original_loop=loop,original_loop_sha256=hashlib.sha256(loop.encode()).hexdigest()))
print(out/'manifest.json')
