"""Capture original pre-integration frame state; replay original integration phase."""
from adapter_build import *
import struct

out,src=setup('fluidanimate_real_advanceparticles_norelax')
assert not (out/'manifest.json').exists(),'Do not overwrite a bound profile'
parent=ROOT/'software/fluidanimate_serial_htif_heap64/manifest.json'
old=read(parent);ps=parent.parent/'source'
for name in ['fluid.hpp','cellpool.hpp','cellpool.cpp','original-serial-host.cpp','selected.fluid','COPYRIGHT']:
 shutil.copy2(ps/name,src/name)
capture=r'''#include "fluid.hpp"
#include <stdio.h>
#include <assert.h>
extern int numCells,numParticles,*cnumPars;extern Cell *cells;
extern void InitSim(const char*),RebuildGrid(),ComputeForces(),ProcessCollisions(),AdvanceParticles();
static void floats(FILE*f,const Vec3&v){float x[3]={v.x,v.y,v.z};assert(fwrite(x,4,3,f)==3);}
int main(){
 InitSim("selected.fluid");RebuildGrid();ComputeForces();ProcessCollisions();
 FILE *f=fopen("capture-before.bin","wb");int h[2]={numCells,numParticles};fwrite(h,4,2,f);fwrite(cnumPars,4,numCells,f);
 int max=0,n=0;
 for(int i=0;i<numCells;i++){
  if(cnumPars[i]>max)max=cnumPars[i];Cell*c=&cells[i];
  for(int j=0;j<cnumPars[i];j++,n++){int k=j%PARTICLES_PER_CELL;floats(f,c->p[k]);floats(f,c->hv[k]);floats(f,c->v[k]);floats(f,c->a[k]);if(k==PARTICLES_PER_CELL-1)c=c->next;}
 }
 fclose(f);AdvanceParticles();f=fopen("capture-after.bin","wb");
 for(int i=0;i<numCells;i++){Cell*c=&cells[i];for(int j=0;j<cnumPars[i];j++){int k=j%PARTICLES_PER_CELL;floats(f,c->p[k]);floats(f,c->hv[k]);floats(f,c->v[k]);if(k==PARTICLES_PER_CELL-1)c=c->next;}}
 fclose(f);printf("[CAPTURE] cells=%d particles=%d max_per_cell=%d sizeof_cell=%lu\n",numCells,n,max,(unsigned long)sizeof(Cell));return n==numParticles?0:1;
}
'''
(src/'capture-main.cpp').write_text(capture)
cmd=['/usr/bin/g++','-O2','-ffp-contract=off','-I'+str(src),str(src/'original-serial-host.cpp'),str(src/'cellpool.cpp'),str(src/'capture-main.cpp'),'-o',str(out/'capture-host')]
with (out/'capture-build.log').open('wb') as log:subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT)
p=subprocess.run([str(out/'capture-host')],cwd=src,check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,timeout=30)
(out/'capture.log').write_text(p.stdout)
raw=(src/'capture-before.bin').read_bytes();nc,np=struct.unpack('<ii',raw[:8]);counts=struct.unpack('<'+'i'*nc,raw[8:8+4*nc]);assert nc==4725 and np==64 and sum(counts)==64 and max(counts)<=16
values=struct.unpack('<'+'f'*(np*12),raw[8+4*nc:]);after=struct.unpack('<'+'f'*(np*9),(src/'capture-after.bin').read_bytes())
def array(name,typ,v):
 return f'static const {typ} {name}[{len(v)}]={{'+','.join(float(x).hex()+'f' if typ=='float' else str(x) for x in v)+'};\n'
(src/'captured-state.h').write_text(array('captured_counts','int',counts)+array('captured_values','float',values)+array('expected_values','float',after))
original=(src/'original-serial-host.cpp').read_text();phase=original[original.index('void AdvanceParticles()'):original.index('\n////////////////////////////////////////////////////////////////////////////////',original.index('void AdvanceParticles()'))]
adapter=r'''#include "fluid.hpp"
#include <new>
#include <stdint.h>
#include <stdio.h>
#include "captured-state.h"
int numCells=4725;static int counts[4725];int*cnumPars=counts;
alignas(128) static unsigned char storage[4725*sizeof(Cell)] __attribute__((section(".data.fluid_cells")))={0};
Cell*cells;
PHASE
extern "C" void workload_prepare(void){
 cells=new(storage) Cell[4725];int n=0;
 for(int i=0;i<numCells;i++){
  counts[i]=captured_counts[i];
  for(int j=0;j<counts[i];j++,n++){
   const float*x=captured_values+12*n;Cell&c=cells[i];
   c.p[j]=Vec3(x[0],x[1],x[2]);c.hv[j]=Vec3(x[3],x[4],x[5]);c.v[j]=Vec3(x[6],x[7],x[8]);c.a[j]=Vec3(x[9],x[10],x[11]);
  }
 }
}
extern "C" void workload_run(void){AdvanceParticles();}
extern "C" int workload_verify(void){
 int ok=1,idx=0,n=0;uint64_t h=14695981039346656037ULL;
 for(int i=0;i<numCells;i++){
  if(counts[i]!=captured_counts[i])ok=0;
  for(int j=0;j<counts[i];j++,n++){
   Cell&c=cells[i];float v[9]={c.p[j].x,c.p[j].y,c.p[j].z,c.hv[j].x,c.hv[j].y,c.hv[j].z,c.v[j].x,c.v[j].y,c.v[j].z};
   for(int k=0;k<9;k++,idx++){
    if(idx>=576||!isfinite(v[k])||fabsf(v[k]-expected_values[idx])>1e-6f+fabsf(expected_values[idx])*1e-5f)ok=0;
    h^=(uint64_t)(int64_t)llround((double)v[k]*100000.0);h*=1099511628211ULL;
   }
  }
 }
 ok=ok&&idx==576&&n==64;
 printf("[OUTPUT] benchmark=fluidanimate checksum=%016lx verified=%d particles=64 values=%d phase=AdvanceParticles grid_cells=4725\n",(unsigned long)h,ok,idx);return ok;
}
'''.replace('PHASE',phase)
(src/'advance-replay.cpp').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['advance-replay.cpp'],dict(benchmark='fluidanimate',profile='real-test64-preintegration-AdvanceParticles-4725-cells-norelax',method='CPU_GG_REAL_TRACE_COMPONENT_REPLAY',extra_flags=['-ffp-contract=off'],target_extra_flags=['-mno-relax','-Wl,--no-relax'],input={**old['input'],'trace_path':str(src/'capture-before.bin'),'trace_sha256':sha(src/'capture-before.bin'),'selected_path':str(src/'selected.fluid'),'selected_sha256':sha(src/'selected.fluid')},capture_parent_manifest=str(parent),capture_parent_manifest_sha256=sha(parent),original_source_sha256=old['original_source_sha256'],correctness={'reference':str(src/'capture-after.bin'),'sha256':sha(src/'capture-after.bin'),'capture_log':str(out/'capture.log'),'capture_log_sha256':sha(out/'capture.log'),'values':576,'tolerance':'abs1e-6 + rel1e-5 for every output float','phase_source_sha256':hashlib.sha256(phase.encode()).hexdigest(),'maximum_particles_per_cell':max(counts)},roi_scope='Verbatim original AdvanceParticles over original4725-cell grid and64 particles; p/hv/v/a captured after original RebuildGrid, ComputeForces, ProcessCollisions on first64 official-test input particles; excludes other frame phases',limitations=['Original AdvanceParticles subphase replay only, not complete AdvanceFrame or Fluidanimate','Input population is reduced to first64 official-test records; full-frame/application time coverage and sampling error uncalibrated; no extrapolation','Full AdvanceFrame profile produced actual checker CANCELLED result; this component does not repair or validate the failed full computation','Cell storage is explicitly preloaded zero ELF data; Cell lifetimes and real captured state established outsideROI; warm/cache layout differs from complete frame'],adaptations=['Disable compiler/linker relaxation in both modes because prior profile linked one fewer AUIPC instruction for EC cells load; both original kernels/data unchanged','Preserve all4725 original grid cells, indices, counts and sizeof(Cell) stride; maximum occupancy proven <=16 so no overflow cell is needed','Captured all12 floating-point state components per particle before original integration; original host AdvanceParticles produces all9 output values per particle','Both modes share exact application objects, trace, preparation, ROI and correctness check'],output_acceptance='verified_fields_checksum_may_differ_from_host',max_target_cycles=1500000,timeout_seconds=3600))
save(out/'capture-receipt.json',dict(created_utc=now(),command=cmd,capture_binary_sha256=sha(out/'capture-host'),before_sha256=sha(src/'capture-before.bin'),after_sha256=sha(src/'capture-after.bin'),original_phase=phase,original_phase_sha256=hashlib.sha256(phase.encode()).hexdigest(),cells=nc,particles=np,max_per_cell=max(counts),nonempty_cells=sum(x>0 for x in counts),parent_manifest_sha256=sha(parent)))
print(out/'manifest.json')
