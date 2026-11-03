#!/usr/bin/env python3
"""Official serial kernels in the established HTIF harness; no RTL changes.

Native and protected images differ only in one initialized uint64_t mode word.
All text, kernel addresses, input, loop counts and sampling instructions match.
"""
import argparse,hashlib,io,json,os,re,shutil,struct,subprocess,tarfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=ROOT/'slowdown/parsec_evaluation_20261103'
PARSEC=Path('/data1/gzh/EC/Software/PARSEC')
TOOLS=Path('/data1/gzh/EC/chipyard/.conda-env/riscv-tools/bin')
COMMON=Path('/data1/gzh/EC/check/software_common')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.write_text(json.dumps(x,indent=2)+'\n')
def extract(app,src):
    with tarfile.open(PARSEC/'parsec-3.0-core.tar.gz') as t:
        members=[m for m in t.getmembers() if '/'+app+'/src/' in m.name and m.isfile() and '/' not in m.name.split('/src/')[1]]
        for m in members:(src/Path(m.name).name).write_bytes(t.extractfile(m).read())
def input_file(app,size,src,suffix):
    p=next((PARSEC/'pkgs').glob('*/'+app))/'inputs'/('input_'+size+'.tar')
    with tarfile.open(p) as t:
        m=next(m for m in t.getmembers() if m.name.endswith(suffix));b=t.extractfile(m).read()
    q=src/Path(m.name).name;q.write_bytes(b);return q
HARNESS=r'''
/* Same startup, interrupt ABI and checker firmware as software_common. */
volatile uint64_t eval_protected __attribute__((section(".eval_mode"))) = 1;
extern void workload_prepare(void);
extern void workload_run(void);
extern int workload_verify(void);
int main(void) {
    uint64_t hart_id=test_setup(), start_cpu,end_cpu,is,ie,session_stop;
    workload_prepare();
    if(eval_protected) {
        ROCC_INSTRUCTION(1,0x31);
        ROCC_INSTRUCTION_S(1,0x01,0x70);
    }
    __asm__ volatile(".global common_roi_start\ncommon_roi_start:\nrdcycle %0\nrdinstret %1" : "=r"(start_cpu),"=r"(is) :: "memory");
    workload_run();
    __asm__ volatile(".global common_roi_stop\ncommon_roi_stop:\nrdinstret %1\nrdcycle %0" : "=r"(end_cpu),"=r"(ie) :: "memory");
    if(eval_protected) {
        ROCC_INSTRUCTION_S(1,0x02,0x70);
        for(int i=0;i<26;i++) __asm__ volatile("nop");
        ROCC_INSTRUCTION(1,0x32);
        while(ght_get_status()<0x1ffff) {}
        __asm__ volatile("rdcycle %0":"=r"(session_stop)::"memory");
        report_end(start_cpu,end_cpu,hart_id);
    } else {
        session_stop=end_cpu;
        ghe_common_observer_stop();
        printf("[ROI] hart=0 start=%lu stop=%lu cycles=%lu\n",start_cpu,end_cpu,end_cpu-start_cpu);
    }
    int ok=workload_verify();
    printf("[APP] protected=%lu start=%lu end=%lu cycles=%lu instret=%lu session_stop=%lu\n",eval_protected,start_cpu,end_cpu,end_cpu-start_cpu,ie-is,session_stop);
    printf("[COMPUTATION] status=%s scope=official_serial_kernel\n",ok?"PASS":"FAIL");
    printf("[END] hart=0 status=%s\n",ok?"PASS":"FAIL");
    if(eval_protected) {ght_unset_satp_priv(); ROCC_INSTRUCTION(1,0x30);}
    return ok?0:1;
}
'''
def blackscholes(src,size):
    inp=input_file('blackscholes',size,src,'.txt');rows=[l.split() for l in inp.read_text().splitlines()[1:] if l.strip()];n=len(rows)
    q=src/'blackscholes.c';q.rename(src/'blackscholes.upstream.c')
    adapter='''#define main parsec_file_main
#include "blackscholes.upstream.c"
#undef main
#include <stdint.h>
static float s[N],k[N],r[N],v[N],t[N],p[N]; static int ty[N];
static const OptionData in[N]={\n'''.replace('[N]','['+str(n)+']')
    for row in rows:adapter+=' {'+','.join(x+'f' for x in row[:6])+",'"+row[6]+"',"+','.join(x+'f' for x in row[7:])+'},\n'
    adapter+='''};
void workload_prepare(void) {numOptions=N;nThreads=1;data=(OptionData*)in;prices=p;sptprice=s;strike=k;rate=r;volatility=v;otime=t;otype=ty;
for(int i=0;i<N;i++){s[i]=in[i].s;k[i]=in[i].strike;r[i]=in[i].r;v[i]=in[i].v;t[i]=in[i].t;ty[i]=(in[i].OptionType=='P');}}
void workload_run(void){int tid=0;bs_thread(&tid);}
int workload_verify(void){uint64_t h=14695981039346656037ULL;int ok=1;for(int i=0;i<N;i++){union{float f;uint32_t u;}x={p[i]};float d=fabsf(p[i]-in[i].DGrefval);if(!isfinite(p[i])||d>=0.0001f)ok=0;h^=x.u;h*=1099511628211ULL;}
printf("[OUTPUT] benchmark=blackscholes checksum=%016lx verified=%d options=N runs=%d\\n",(unsigned long)h,ok,NUM_RUNS);return ok;}
'''
    adapter=re.sub(r'\bN\b',str(n),adapter)
    (src/'adapter.c').write_text(adapter)
    return ['adapter.c'],{'input_class':size,'input_filename':inp.name,'input_sha256':sha(inp),'options':n,'iterations':100,'operations':n*100,'command_line':f'blackscholes 1 {inp.name} prices.txt','output_verification':'all options finite, abs error < 1e-4 vs official DGrefval; full bit checksum'},False
def main():
    p=argparse.ArgumentParser();p.add_argument('benchmark',choices=['blackscholes']);p.add_argument('size',choices=['test','simdev','simsmall']);a=p.parse_args()
    out=OUT/'build'/(a.benchmark+'_'+a.size);out.mkdir(parents=True,exist_ok=False)
    src=out/'source';shutil.copytree(COMMON,src)
    extract(a.benchmark,src)
    upstream={p.name:sha(p) for p in src.iterdir() if p.is_file()}
    files,meta,cpp=blackscholes(src,a.size)
    common=(src/'test.c').read_text();idx=common.index('/* 执行');common=common[:idx]
    common=common.replace('#include "Benchmark/gapbs/gapbs_bfs.h"\n#include "bench/stage1_amo.h"','extern volatile uint64_t eval_protected;')
    common=common.replace('    ght_set_satp_priv();','    if(eval_protected) ght_set_satp_priv();')
    (src/'test.c').write_text(common+HARNESS)
    linker=(ROOT/'slowdown/blackscholes_validation/build/parsec_test4/htif.ld').read_text()
    linker=linker.replace('    .data ALIGN(64)', '    .eval_mode : ALIGN(64) { KEEP (*(.eval_mode)) }\n\n    .data ALIGN(64)')
    linker=linker.replace('PROVIDE(__heap_size = 128K)','PROVIDE(__heap_size = 4M)')
    (out/'htif.ld').write_text(linker)
    flags=['-fno-common','-fno-builtin-printf','-fdata-sections','-ffunction-sections','-specs='+str(src/'support/htif_nano.specs'),'-L'+str(src/'support'),'-I'+str(src/'support'),'-I'+str(src),'-march=rv64imafd','-O2','-static']
    units=['hw/interrupt.c','test.c','stat/report.c','core/secondary.c','cfg/init.c','core/checker.c','hw/spin_lock.c']+files
    env=dict(os.environ,PATH=str(TOOLS)+':/usr/bin:/bin');commands=[];objects=[]
    with (out/'build.log').open('xb') as log:
        for i,f in enumerate(units):
            obj=out/(str(i)+'.o');tool='g++' if Path(f).suffix=='.cpp' else 'gcc'
            cmd=[str(TOOLS/('riscv64-unknown-elf-'+tool)),*flags,'-c',str(src/f),'-o',str(obj)]
            commands.append(cmd);subprocess.run(cmd,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT,check=True);objects.append(str(obj))
        cmd=[str(TOOLS/('riscv64-unknown-elf-'+('g++' if cpp else 'gcc'))),*flags,*objects,'-Wl,--gc-sections','-Wl,-Map='+str(out/'test.map'),'-lm','-o',str(out/'protected.riscv')]
        commands.append(cmd);subprocess.run(cmd,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT,check=True)
    sym=subprocess.check_output([str(TOOLS/'riscv64-unknown-elf-nm'),'-n',str(out/'protected.riscv')],text=True)
    (out/'symbols.txt').write_text(sym);symbols={l.split()[2]:int(l.split()[0],16) for l in sym.splitlines() if len(l.split())==3}
    elf=bytearray((out/'protected.riscv').read_bytes());h=struct.unpack_from('<16sHHIQQQIHHHHHH',elf);assert h[4]==0x80000000
    segments=[];modeoff=None
    for i in range(h[10]):
        typ,fl,off,va,pa,fs,ms,al=struct.unpack_from('<IIQQQQQQ',elf,h[5]+i*h[9])
        if typ!=1:continue
        assert va==pa and va>=0x80000000
        segments.append((off,va,fs,ms))
        if va<=symbols['eval_protected']<va+fs:modeoff=off+symbols['eval_protected']-va
    assert modeoff is not None and struct.unpack_from('<Q',elf,modeoff)[0]==1
    artifacts={}
    for mode in ['protected','native']:
        b=bytearray(elf);struct.pack_into('<Q',b,modeoff,int(mode=='protected'))
        (out/(mode+'.riscv')).write_bytes(b)
        size=((max(va+ms for off,va,fs,ms in segments)-0x80000000+4095)//4096)*4096
        image=bytearray(size)
        for off,va,fs,ms in segments:image[va-0x80000000:va-0x80000000+fs]=b[off:off+fs]
        q=out/(mode+'.loadmem_hex')
        with q.open('x') as f:
            for i in range(0,size,64):f.write(image[i:i+64][::-1].hex()+'\n')
        artifacts[mode]={'elf_sha256':sha(out/(mode+'.riscv')),'loadmem_sha256':sha(q)}
    subprocess.run([str(TOOLS/'riscv64-unknown-elf-objdump'),'-d',str(out/'protected.riscv')],stdout=(out/'test.dump').open('wb'),check=True)
    dump(out/'build.manifest.json',dict(benchmark=a.benchmark,**meta,threads=1,commands=commands,compiler=subprocess.check_output([str(TOOLS/'riscv64-unknown-elf-gcc'),'--version'],text=True),upstream_sha256=upstream,source_sha256={str(p.relative_to(src)):sha(p) for p in sorted(src.rglob('*')) if p.is_file()},artifacts=artifacts,symbols={k:hex(symbols[k]) for k in ['common_roi_start','common_roi_stop','eval_protected']},mode_word_file_offset=modeoff,roi_scope='workload_run call only, two adjacent CSR samples at each boundary; setup/STOP/checker completion/output excluded',native_scope='same correction hardware, protected session never started; passive checker cores retained; requires runtime zero-package/version evidence',canonical_hardware='1532923803d7451b0c7843e9abad1c90ef9eb9ed'))
    print(out,flush=True)
if __name__=='__main__':main()
