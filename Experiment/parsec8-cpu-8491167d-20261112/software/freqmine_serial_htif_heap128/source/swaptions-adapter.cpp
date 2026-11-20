#define main parsec_original_main
#include "HJM_Securities.cpp"
#undef main
#include <stdint.h>
#include <math.h>
extern "C" void workload_prepare(void) {
    nThreads=1; nSwaptions=1; NUM_TRIALS=16;
    seed=1979; swaption_seed=(long)(2147483647L*RanUnif(&seed));
    FTYPE **factors=dmatrix(0,iFactors-1,0,iN-2);
    double a[3][10]={{.01,.01,.01,.01,.01,.01,.01,.01,.01,.01},
        {.009048,.008187,.007408,.006703,.006065,.005488,.004966,.004493,.004066,.003679},
        {.001000,.000750,.000500,.000250,.000000,-.000250,-.000500,-.000750,-.001000,-.001250}};
    for(int k=0;k<3;k++)for(int j=0;j<10;j++)factors[k][j]=a[k][j];
    swaptions=(parm*)malloc(sizeof(parm));
    swaptions[0].Id=0; swaptions[0].iN=iN; swaptions[0].iFactors=iFactors;
    swaptions[0].dYears=5.0+((int)(60*RanUnif(&seed)))*0.25;
    swaptions[0].dStrike=.1+((int)(49*RanUnif(&seed)))*.1;
    swaptions[0].dCompounding=0;swaptions[0].dMaturity=1.0;swaptions[0].dTenor=2.0;swaptions[0].dPaymentInterval=1.0;
    swaptions[0].pdYield=dvector(0,iN-1);
    swaptions[0].pdYield[0]=.1;for(int j=1;j<=iN-1;j++)swaptions[0].pdYield[j]=swaptions[0].pdYield[j-1]+.005;
    swaptions[0].ppdFactors=dmatrix(0,iFactors-1,0,iN-2);
    for(int k=0;k<iFactors;k++)for(int j=0;j<iN-1;j++)swaptions[0].ppdFactors[k][j]=factors[k][j];
}
extern "C" void workload_run(void) { int tid=0; worker(&tid); }
extern "C" int workload_verify(void) {
    FTYPE mean=swaptions[0].dSimSwaptionMeanPrice, se=swaptions[0].dSimSwaptionStdError;
    int ok=isfinite(mean)&&isfinite(se)&&mean>=0&&se>=0;
    uint64_t h=14695981039346656037ULL;
    h^=(uint64_t)llround(mean*1000.0);h*=1099511628211ULL;
    h^=(uint64_t)llround(se*1000.0);h*=1099511628211ULL;
    printf("[OUTPUT] benchmark=swaptions checksum=%016lx verified=%d swaptions=1 trials=16 seed=1979\n",(unsigned long)h,ok);
    return ok;
}
