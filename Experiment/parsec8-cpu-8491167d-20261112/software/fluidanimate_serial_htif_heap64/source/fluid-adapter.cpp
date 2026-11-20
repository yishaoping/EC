#include "fluid.hpp"
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
