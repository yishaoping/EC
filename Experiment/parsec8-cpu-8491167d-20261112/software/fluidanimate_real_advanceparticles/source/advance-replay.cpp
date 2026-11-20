#include "fluid.hpp"
#include <new>
#include <stdint.h>
#include <stdio.h>
#include "captured-state.h"
int numCells=4725;static int counts[4725];int*cnumPars=counts;
alignas(128) static unsigned char storage[4725*sizeof(Cell)] __attribute__((section(".data.fluid_cells")))={0};
Cell*cells;
void AdvanceParticles()
{
  for(int i = 0; i < numCells; ++i)
  {
    Cell *cell = &cells[i];
    int np = cnumPars[i];
    for(int j = 0; j < np; ++j)
    {
      Vec3 v_half = cell->hv[j % PARTICLES_PER_CELL] + cell->a[j % PARTICLES_PER_CELL]*timeStep;
#if defined(USE_ImpeneratableWall)
	  // N.B. The integration of the position can place the particle
	  // outside the domain. Although we could place a test in this loop
	  // we would be unnecessarily testing particles on interior cells.
	  // Therefore, to reduce the amount of computations we make a later
	  // pass on the perimiter cells to account for particle migration
	  // beyond domain
#endif
      cell->p[j % PARTICLES_PER_CELL] += v_half * timeStep;
      cell->v[j % PARTICLES_PER_CELL] = cell->hv[j % PARTICLES_PER_CELL] + v_half;
      cell->v[j % PARTICLES_PER_CELL] *= 0.5;
      cell->hv[j % PARTICLES_PER_CELL] = v_half;

      //move pointer to next cell in list if end of array is reached
      if(j % PARTICLES_PER_CELL == PARTICLES_PER_CELL-1) {
        cell = cell->next;
      }
    }
  }
}

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
