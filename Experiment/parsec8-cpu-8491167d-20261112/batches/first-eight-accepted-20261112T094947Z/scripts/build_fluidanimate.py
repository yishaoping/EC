from adapter_build import *
import struct,re

out,src=setup('fluidanimate_serial_htif_heap64')
(out/'htif.ld').write_text((out/'htif.ld').read_text().replace('PROVIDE(__heap_size = 4M)','PROVIDE(__heap_size = 64M)'))
app=EC/'Software/PARSEC/pkgs/apps/fluidanimate/src'
original={}
for name in ['serial.cpp','fluid.hpp','cellpool.cpp','cellpool.hpp','COPYRIGHT']:
 shutil.copy2(app/name,src/name);original[name]=sha(app/name)
p=src/'cellpool.cpp';p.write_text(p.read_text().replace('#include <iostream>',''))
(src/'aligned-allocation.cpp').write_text('#ifdef __riscv\n#include <malloc.h>\n#include <stddef.h>\nextern "C" int posix_memalign(void **p,size_t align,size_t bytes){*p=memalign(align,bytes);return *p?0:12;}\n#endif\n')
inputpath=W/'software/apps-fluidanimate-20261107T050619Z/inputs/fluidanimate/test/in_5K.fluid'
raw=inputpath.read_bytes();rest,total=struct.unpack('<fi',raw[:8]);count=64
selected=struct.pack('<fi',rest,count)+raw[8:8+36*count]
(src/'selected.fluid').write_bytes(selected)
# Preserve the actual serial physics functions; discard the repository's custom
# multicore experiment main and keep an independent original-file host reference.
t=(src/'serial.cpp').read_text().split('int uart_lock;')[0]
for inc in ['#include "rocc.h"','#include "custom.h"','#include <sched.h>','#include <unistd.h>','#include <pthread.h>']:
 t=t.replace(inc,'')
(src/'original-serial-host.cpp').write_text(t)
(src/'original-host-main.cpp').write_text('extern void InitSim(const char*),AdvanceFrame(),SaveFile(const char*);int main(){InitSim("selected.fluid");AdvanceFrame();SaveFile("original-reference.fluid");}\n')
with (out/'original-reference-build.log').open('wb') as log:
 cmd=['/usr/bin/g++','-O2','-I'+str(src),str(src/'original-serial-host.cpp'),str(src/'cellpool.cpp'),str(src/'original-host-main.cpp'),'-o',str(out/'original-host-reference')]
 subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT)
 proc=subprocess.run([str(out/'original-host-reference')],cwd=src,check=True,stdout=subprocess.PIPE,text=True,timeout=20)
(out/'original-reference.log').write_text(proc.stdout)
reference=(src/'original-reference.fluid').read_bytes();assert len(reference)==len(selected)
values=struct.unpack('<'+str(count*9)+'f',reference[8:])
(src/'expected.h').write_text('static const float expected[] = {'+','.join(float(v).hex()+'f' for v in values)+'};\n')
(src/'embedded-input.h').write_text('static const unsigned char embedded_input[] = {'+','.join(map(str,selected))+'};\n')
# Replace only the file stream and unneeded console output/SaveFile with RAM I/O.
begin=t.index('void SaveFile(');end=t.index('void CleanUpSim()',begin);t=t[:begin]+t[end:]
t=t.replace('#include <iostream>','#include <algorithm>\n#include <new>\n#include <stdio.h>\n#include "embedded-input.h"\nstruct InputReader {size_t cursor;InputReader():cursor(0){} void read(char*p,size_t n){assert(cursor+n<=sizeof(embedded_input));memcpy(p,embedded_input+cursor,n);cursor+=n;}};')
t=t.replace('#include <fstream>','')
start=t.index('  std::cout << "Loading file');end=t.index('  //Always use single',start)
t=t[:start]+'  InputReader file;\n'+t[end:]
t='\n'.join(line for line in t.splitlines() if 'std::cout' not in line)+'\n'
# Include assert before InputReader uses it.
t='#include <assert.h>\n'+t
(src/'serial-embedded.cpp').write_text(t)
adapter=r'''#include "fluid.hpp"
#include <stdint.h>
#include <stdio.h>
#include "expected.h"
extern int numParticles,numCells,*cnumPars;
extern Cell *cells;
extern void InitSim(const char*),AdvanceFrame();
extern "C" void workload_prepare(void){InitSim("embedded");}
extern "C" void workload_run(void){AdvanceFrame();}
extern "C" int workload_verify(void){
 int ok=numParticles==64,idx=0;uint64_t hash=14695981039346656037ULL;
 for(int i=0;i<numCells;i++){
  Cell *cell=&cells[i];
  for(int j=0;j<cnumPars[i];j++){
   int k=j%PARTICLES_PER_CELL;
   float v[9]={cell->p[k].x,cell->p[k].y,cell->p[k].z,cell->hv[k].x,cell->hv[k].y,cell->hv[k].z,cell->v[k].x,cell->v[k].y,cell->v[k].z};
   for(int q=0;q<9;q++,idx++){
    if(idx>=576 || !isfinite(v[q]) || fabsf(v[q]-expected[idx])>1e-6f+fabsf(expected[idx])*1e-5f)ok=0;
    hash^=(uint64_t)(int64_t)llround((double)v[q]*100000.0);hash*=1099511628211ULL;
   }
   if(k==PARTICLES_PER_CELL-1)cell=cell->next;
  }
 }
 ok=ok&&idx==576;
 printf("[OUTPUT] benchmark=fluidanimate checksum=%016lx verified=%d particles=64 frames=1 values=%d\n",(unsigned long)hash,ok,idx);return ok;
}
'''
(src/'fluid-adapter.cpp').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['serial-embedded.cpp','cellpool.cpp','aligned-allocation.cpp','fluid-adapter.cpp'],dict(benchmark='fluidanimate',profile='test-derived-64-particles-no-main-timer-heap64',method='CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI',original_source_sha256=original,input={'path':str(inputpath),'sha256':sha(inputpath),'original_particles':total,'selected_particles':count,'selection':'first 64 particle records, original rest density and all nine input values preserved','selected_path':str(src/'selected.fluid'),'selected_sha256':sha(src/'selected.fluid'),'frames':1},roi_scope='One complete original serial AdvanceFrame on test-derived 64-particle input; initialization and verification outside ROI',correctness={'reference':str(src/'original-reference.fluid'),'sha256':sha(src/'original-reference.fluid'),'values':count*9,'tolerance':'abs 1e-6 + rel 1e-5 per output float','checksum_quantization':1e-5},limitations=['Test-derived reduced particle population; sampling error versus official test/simmedium is uncalibrated; no extrapolation to full workload slowdown','Heap reservation raised from 4 MiB to 64 MiB for original grid and cell pools',
 'Whole original grid/domain/physics and frame phases retained; embedded input replaces filesystem only'],max_target_cycles=4000000,timeout_seconds=3600))
print(json.dumps({'manifest':str(out/'manifest.json'),'expected_output':j['expected_output']},indent=2))
