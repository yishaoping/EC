#include <cass.h>
#include "emd.h"
#include "emd-trace.h"
static signature_t a,b;static feature_t fa[256],fb[256];static float result;
static float ground(cass_size_t d,feature_t a,feature_t b,void*p){return dist_L2_float(d,a,b);}
void workload_prepare(void){
 a.n=14;b.n=9;a.Features=fa;b.Features=fb;a.Weights=weights0;b.Weights=weights1;
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
