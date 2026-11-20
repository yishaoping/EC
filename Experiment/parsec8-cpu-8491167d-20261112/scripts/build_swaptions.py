from common import *
import shutil,subprocess
out=ROOT/'software/swaptions_test-attempt5';app=EC/'Software/PARSEC/pkgs/apps/swaptions/src'
assert not out.exists()
out.mkdir(parents=True)
manifest=read(ROOT/'software/streamcluster_project64/manifest.json')
shutil.copytree(SOURCE/'source',out/'source',ignore=shutil.ignore_patterns('adapter.cpp','streamcluster.cpp'))
shutil.copy2(SOURCE/'htif.ld',out/'htif.ld')
for p in app.iterdir():
 if p.is_file() and p.suffix.lower() in ['.cpp','.c','.h']:
  shutil.copy2(p,out/'source'/p.name)
adapter=r'''#define main parsec_original_main
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
'''
(out/'source/swaptions-adapter.cpp').write_text(adapter)
(out/'source/host-reference.cpp').write_text('extern "C" void workload_prepare(void); extern "C" void workload_run(void); extern "C" int workload_verify(void); int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
base_cmds=manifest['shared_kernel_objects']
refcommands=read(ROOT/'software/streamcluster_project64/manifest.json')['commands']
flags=refcommands[0][1:refcommands[0].index('-c')]
gcc=str(TOOLS/'riscv64-unknown-elf-gcc');gxx=str(TOOLS/'riscv64-unknown-elf-g++')
src=out/'source';objects=[];commands=[]
for i,name in enumerate(['hw/interrupt.c','test.c','stat/report.c','core/secondary.c','cfg/init.c','core/checker.c','hw/spin_lock.c']):
 cmd=[gcc,*flags,'-c',str(src/name),'-o',str(out/f'{i}.o')]
 subprocess.run(cmd,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);objects.append(str(out/f'{i}.o'));commands.append(cmd)
files=['CumNormalInv.cpp','MaxFunction.cpp','RanUnif.cpp','nr_routines.c','icdf.cpp','HJM_SimPath_Forward_Blocking.cpp','HJM.cpp','HJM_Swaption_Blocking.cpp','swaptions-adapter.cpp']
for name in files:
 i=len(objects);tool=gxx if name.endswith('.cpp') or name=='nr_routines.c' else gcc
 cmd=[tool,*flags,*(['-x','c++'] if name=='nr_routines.c' else []),'-c',str(src/name),'-o',str(out/f'{i}.o')]
 subprocess.run(cmd,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);objects.append(str(out/f'{i}.o'));commands.append(cmd)
(src/'cxx_runtime.c').write_text('void *__dso_handle;\n')
i=len(objects);cmd=[gcc,*flags,'-c',str(src/'cxx_runtime.c'),'-o',str(out/f'{i}.o')]
subprocess.run(cmd,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);objects.append(str(out/f'{i}.o'));commands.append(cmd)
ecelf=out/'ec.riscv';link=[gxx,*flags,*objects,'-Wl,--gc-sections','-Wl,-Map='+str(out/'ec.map'),'-lm','-o',str(ecelf)]
subprocess.run(link,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);commands.append(link)
native_main=out/'source/native-main.c';native_main.write_text(module(W/'candidates/matched-single-boom-gg-r1-20261112/controller.py','native_main_source').NATIVE_MAIN)
i=len(objects);ncmd=[gcc,*flags,'-c',str(native_main),'-o',str(out/f'{i}.o')]
subprocess.run(ncmd,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);commands.append(ncmd)
nelf=out/'native.riscv';nlink=[gxx,*flags,*objects[:-len(files)-1],*objects[7:-1],str(out/f'{i}.o'),'-Wl,--gc-sections','-Wl,-Map='+str(out/'native.map'),'-lm','-o',str(nelf)]
# The protected test.c object is excluded and replaced by the clean Native main.
native_objects=[objects[0],*objects[2:7],*objects[7:-1],str(out/f'{i}.o'),objects[-1]]
nlink=[gxx,*flags,*native_objects,'-Wl,--gc-sections','-Wl,-Map='+str(out/'native.map'),'-lm','-o',str(nelf)]
subprocess.run(nlink,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);commands.append(nlink)
host='/usr/bin/g++';host_objects=[]
host_files=['CumNormalInv.cpp','MaxFunction.cpp','RanUnif.cpp','nr_routines.c','icdf.cpp','HJM_SimPath_Forward_Blocking.cpp','HJM.cpp','HJM_Swaption_Blocking.cpp','swaptions-adapter.cpp','host-reference.cpp']
for i,name in enumerate(host_files):
 q=out/(f'host-{i}.o');cmd=[host,'-O2','-I'+str(src),'-c',str(src/name),'-o',str(q)]
 subprocess.run(cmd,cwd=out,check=True,stdout=subprocess.DEVNULL,stderr=subprocess.PIPE);host_objects.append(str(q))
href=out/'host-reference';subprocess.run([host,*host_objects,'-lm','-o',str(href)],cwd=out,check=True)
refout=subprocess.check_output([str(href)],cwd=out,text=True).strip().splitlines()[-1]
assert 'verified=1' in refout,refout
source_hash={str(p.relative_to(src)):sha(p) for p in sorted(src.rglob('*')) if p.is_file()}
objhash={str(out/f'{i}.o'):sha(out/f'{i}.o') for i in range(len(objects)) if i!=1}
j=dict(benchmark='swaptions',profile='representative-16-trial-test',method='CPU_GG_REPRESENTATIVE_TEST_PROFILE',functional_baseline=BASE,threads=1,
 input={'class':'PARSEC test-derived representative ROI','arguments':['-ns','1','-sm','16','-nt','1'],'seed':1979,'input_data':'deterministic original Swaptions parameter initialization; trial count aligned to the 16-wide HJM kernel block','initialization_source_sha256':source_hash['HJM_Securities.cpp']},
 roi_scope='serial worker call only; workload setup/pricing-structure initialization and output verification outside ROI',expected_output=[refout.split('[OUTPUT] ',1)[1]],host_reference={'path':str(href),'sha256':sha(href),'output':refout},source_sha256=source_hash,shared_kernel_objects=objhash,commands=commands,
 elf={k:{'path':str(out/(k+'.riscv')),'sha256':sha(out/(k+'.riscv'))} for k in ['native','ec']},max_target_cycles=1500000,timeout_seconds=1800,same_elf=False,
 differences='Separate Native startup ABI; application worker and setup source identical; one swaption and 16 trials are used to align with the HJM 16-wide block; differs from official five-trial test and simsmall')
save(out/'manifest.json',j)
print(json.dumps({'manifest':str(out/'manifest.json'),'host_reference':refout,'elf':j['elf'],'source_files':len(source_hash)},indent=2))
