#include <cass.h>
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
  /* COMPUTE THE DISTANCE MATRIX */
  state->maxC = 0;
  for(i=0; i < state->n1; i++)
    for(j=0; j < state->n2; j++) 
      {
	state->C[i][j] = Dist(dim, Signature1->Features[i], Signature2->Features[j], param);
	if (state->C[i][j] > state->maxC)
	  state->maxC = state->C[i][j];
      }
	

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
