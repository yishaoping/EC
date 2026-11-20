#include "common.h"
#include <stdint.h>
#include <stdio.h>
static FP_tree *tree;
static Data *data;
extern "C" void workload_prepare(void) {
 THRESHOLD=1;data=new Data((char*)"embedded");
 fp_buf=new memory*[1];fp_tree_buf=new memory*[1];
 fp_buf[0]=new memory(60,10485760,20971520,2);
 fp_tree_buf[0]=new memory(80,10485760,20971520,2);
 database_buf=new memory(60,4194304L,4194304L,2);
 tree=(FP_tree*)fp_buf[0]->newbuf(1,sizeof(FP_tree));tree->init(-1,0,0);
}
extern "C" void workload_run(void) {tree->scan1_DB(data);tree->scan2_DB(1);tree->FP_growth_first(NULL);}
extern "C" int workload_verify(void) {
 const int expected[16]={32,192,736,2100,4676,8246,11568,12916,11450,8009,4368,1820,560,120,16,1};
 uint64_t h=14695981039346656037ULL;int ok=TRANSACTION_NO==3;
 for(int k=0;k<16;k++){ok=ok && ITlen[0][k]==expected[k];printf("[COUNT] length=%d count=%d\n",k+1,ITlen[0][k]);h^=(uint64_t)ITlen[0][k];h*=1099511628211ULL;}
 printf("[OUTPUT] benchmark=freqmine checksum=%016lx verified=%d transactions=%d threshold=1\n",(unsigned long)h,ok,TRANSACTION_NO);return ok;
}
