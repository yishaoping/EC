
#define main parsec_file_main
#include "streamcluster.cpp"
#undef main
#include <stdint.h>
static Points saved;static long *ids;
static void eval_capture(Points* p,long* x){saved=*p;ids=x;}
extern "C" void workload_prepare(void){nproc=1;srand48(SEED);}
extern "C" void workload_run(void){SimStream stream(16);streamCluster(&stream,3,5,3,16,16,(char*)"unused");}
extern "C" int workload_verify(void){uint64_t h=14695981039346656037ULL;double weight=0;int count=0;int ok=1;
for(int i=0;i<saved.num;i++){int median=0;for(int j=0;j<saved.num;j++)if(saved.p[j].assign==i)median=1;
if(median){count++;weight+=saved.p[i].weight;h^=(uint64_t)ids[i];h*=1099511628211ULL;
union{float f;uint32_t u;}v={saved.p[i].weight};h^=v.u;h*=1099511628211ULL;
for(int k=0;k<saved.dim;k++){v.f=saved.p[i].coord[k];if(!isfinite(v.f))ok=0;h^=v.u;h*=1099511628211ULL;}}}
ok=ok&&count>=3&&count<=5&&fabs(weight-16)<0.001;
printf("[OUTPUT] benchmark=streamcluster checksum=%016lx verified=%d centers=%d weight=%lu\n",(unsigned long)h,ok,count,(unsigned long)weight);return ok;}
