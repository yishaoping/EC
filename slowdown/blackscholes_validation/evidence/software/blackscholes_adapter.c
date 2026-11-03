#define main parsec_file_main
#include "blackscholes.upstream.c"
#undef main
#include <stdint.h>
static float embedded_s[4], embedded_k[4], embedded_r[4], embedded_v[4], embedded_t[4];
static int embedded_type[4];
static float embedded_prices[4];
static const OptionData embedded_data[4] = {
    {42.00f,40.00f,0.1000f,0.00f,0.20f,0.50f,'C',0.00f,4.759423036851750055f},
    {42.00f,40.00f,0.1000f,0.00f,0.20f,0.50f,'P',0.00f,0.808600016880314021f},
    {100.00f,100.00f,0.0500f,0.00f,0.15f,1.00f,'P',0.00f,3.714602051381290071f},
    {100.00f,100.00f,0.0500f,0.00f,0.15f,1.00f,'C',0.00f,8.591659601309890704f},
};
void blackscholes_prepare(void) {
    numOptions=4; nThreads=1; data=(OptionData *)embedded_data; prices=embedded_prices;
    sptprice=embedded_s; strike=embedded_k; rate=embedded_r;
    volatility=embedded_v; otime=embedded_t; otype=embedded_type;
    for(int i=0;i<4;i++) {
        sptprice[i]=data[i].s; strike[i]=data[i].strike; rate[i]=data[i].r;
        volatility[i]=data[i].v; otime[i]=data[i].t; otype[i]=(data[i].OptionType=='P');
    }
}
void blackscholes_run(void) {int tid=0; bs_thread(&tid);}
int blackscholes_verify(void) {
    uint64_t hash=UINT64_C(14695981039346656037); int ok=1;
    for(int i=0;i<4;i++) {
        union {float f; uint32_t u;} p={prices[i]};
        float delta=fabsf(prices[i]-data[i].DGrefval);
        if(!isfinite(prices[i]) || delta>=0.0001f) ok=0;
        hash^=p.u; hash*=UINT64_C(1099511628211);
        printf("[PRICE] index=%d bits=%08x ref_delta_e8=%lu\n",i,p.u,(unsigned long)(delta*100000000.0f));
    }
    printf("[BLACKSCHOLES] input=test/in_4.txt options=4 runs=%d prices=400 checksum=%016lx verified=%d\n",NUM_RUNS,(unsigned long)hash,ok);
    return ok;
}
