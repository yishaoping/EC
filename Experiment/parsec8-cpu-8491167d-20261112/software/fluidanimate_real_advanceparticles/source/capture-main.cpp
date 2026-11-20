#include "fluid.hpp"
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
