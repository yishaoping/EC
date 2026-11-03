#!/usr/bin/env python3
"""Adapt official serial PARSEC to the existing common bare-metal harness.
No hardware generation; originals remain read-only. NUM_RUNS and pricing code unchanged.
"""
import hashlib, io, json, os, re, shutil, struct, subprocess, tarfile
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT/'slowdown/blackscholes_validation'
CHECK = Path('/data1/gzh/EC/check')
PARSEC = Path('/data1/gzh/EC/Software/PARSEC')
TOOLS = Path('/data1/gzh/EC/chipyard/.conda-env/riscv-tools/bin')
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x): p.write_text(json.dumps(x,indent=2)+'\n')
def main():
    out=OUT/'build/parsec_test4';out.mkdir(parents=True,exist_ok=False)
    src=out/'source';shutil.copytree(CHECK/'software_common',src)
    with tarfile.open(PARSEC/'parsec-3.0-core.tar.gz') as archive:
        app='parsec-3.0/pkgs/apps/blackscholes/'
        upstream=archive.extractfile(app+'src/blackscholes.c').read()
        inp=archive.extractfile(app+'inputs/input_test.tar').read()
    (src/'blackscholes.upstream.c').write_bytes(upstream)
    with tarfile.open(fileobj=io.BytesIO(inp)) as archive:
        member=next(m for m in archive.getmembers() if m.name.endswith('in_4.txt'))
        data=archive.extractfile(member).read()
    (src/'in_4.txt').write_bytes(data)
    lines=data.decode().splitlines();assert int(lines[0])==4
    rows=[line.split() for line in lines[1:] if line.strip()];assert len(rows)==4
    # Include the unmodified file, retain original bs_thread, discard file-I/O main at link.
    adapter='''#define main parsec_file_main
#include "blackscholes.upstream.c"
#undef main
#include <stdint.h>
static float embedded_s[4], embedded_k[4], embedded_r[4], embedded_v[4], embedded_t[4];
static int embedded_type[4];
static float embedded_prices[4];
static const OptionData embedded_data[4] = {\n'''
    for row in rows:
        adapter+='    {'+','.join(v+'f' for v in row[:6])+",'"+row[6]+"',"+','.join(v+'f' for v in row[7:])+'},\n'
    adapter+='''};
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
        printf("[PRICE] index=%d bits=%08x ref_delta_e8=%lu\\n",i,p.u,(unsigned long)(delta*100000000.0f));
    }
    printf("[BLACKSCHOLES] input=test/in_4.txt options=4 runs=%d prices=400 checksum=%016lx verified=%d\\n",NUM_RUNS,(unsigned long)hash,ok);
    return ok;
}
'''
    (src/'blackscholes_adapter.c').write_text(adapter)
    common=(src/'test.c').read_text();common=common.replace('#include "Benchmark/gapbs/gapbs_bfs.h"\n#include "bench/stage1_amo.h"',
    'extern void blackscholes_prepare(void);\nextern void blackscholes_run(void);\nextern int blackscholes_verify(void);\nstatic uint64_t retired_start, retired_stop;')
    start=common.index('/* 执行');common=common[:start]+'''/* Same protected-session start/stop and completion protocol as common BFS. */
int main(void) {
    uint64_t hart_id=test_setup(), start_cpu, end_cpu;
    blackscholes_prepare();
    ROCC_INSTRUCTION(1,0x31);
    ROCC_INSTRUCTION_S(1,0x01,0x70);
    __asm__ volatile(".global common_roi_start\\ncommon_roi_start:\\nrdcycle %0" : "=r"(start_cpu) :: "memory");
    __asm__ volatile("rdinstret %0" : "=r"(retired_start) :: "memory");
    blackscholes_run();
    ROCC_INSTRUCTION_S(1,0x02,0x70);
    for(int i=0;i<26;i++) __asm__ volatile("nop");
    ROCC_INSTRUCTION(1,0x32);
    while(ght_get_status()<0x1ffff) {}
    __asm__ volatile("rdinstret %0" : "=r"(retired_stop) :: "memory");
    __asm__ volatile(".global common_roi_stop\\ncommon_roi_stop:\\nrdcycle %0" : "=r"(end_cpu) :: "memory");
    int ok=blackscholes_verify();
    ok=report_end(start_cpu,end_cpu,hart_id) && ok;
    printf("[WORK] roi_instret=%lu expected_pricings=400\\n",(unsigned long)(retired_stop-retired_start));
    printf("[COMPUTATION] status=%s scope=parsec_blackscholes_test4_100runs\\n",ok?"PASS":"FAIL");
    printf("[END] hart=0 status=%s\\n",ok?"PASS":"FAIL");
    ght_unset_satp_priv(); ROCC_INSTRUCTION(1,0x30);
    return ok?0:1;
}
'''
    (src/'test.c').write_text(common)
    # Reuse HTIF script; replace BFS-only pinned memory layout with ordinary aligned BSS.
    linker=(src/'support/htif.ld').read_text()
    linker=linker.replace('.htif 0x80007d00', '.htif ALIGN(64)').replace('.data 0x80007d10', '.data ALIGN(64)').replace('.sdata 0x80007dc0', '.sdata ALIGN(64)')
    a=linker.index('    /* Preserve the saved');b=linker.index('    . = ALIGN (8);',a)
    linker=linker[:a]+'''    .bss (NOLOAD) : ALIGN(64) {
        PROVIDE_HIDDEN (__bss_start = .);
        *(.sbss .sbss.*) *(.gnu.linkonce.sb.*)
        *(.bss .bss.*) *(.gnu.linkonce.b.*) *(COMMON)
        . = ALIGN(64);
        PROVIDE_HIDDEN (__bss_end = .);
    }

'''+linker[b:]
    (src/'support/htif.ld').write_text(linker);(out/'htif.ld').write_text(linker)
    command=[str(TOOLS/'riscv64-unknown-elf-gcc'),'-fno-common','-fno-builtin-printf','-fdata-sections','-ffunction-sections',
        '-specs='+str(src/'support/htif_nano.specs'),'-L'+str(src/'support'),'-I'+str(src/'support'),'-I'+str(src),
        '-march=rv64imafd','-O2','-static','-Wl,--gc-sections','-Wl,-Map='+str(out/'test.map')]
    command += [str(src/f) for f in ['hw/interrupt.c','test.c','blackscholes_adapter.c','stat/report.c','core/secondary.c','cfg/init.c','core/checker.c','hw/spin_lock.c']]
    command += ['-lm','-o',str(out/'test.riscv')]
    env=dict(os.environ,PATH=str(TOOLS)+':/usr/bin:/bin');records={'command':command}
    with (out/'build.log').open('wb') as log:subprocess.run(command,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT,check=True)
    for name,args in [('test.dump',['objdump','-d']),('test.symbols',['readelf','-sW'])]:
        tool,*flags=args
        with (out/name).open('wb') as f:subprocess.run([str(TOOLS/('riscv64-unknown-elf-'+tool)),*flags,str(out/'test.riscv')],stdout=f,check=True)
    elf=(out/'test.riscv').read_bytes();header=struct.unpack_from('<16sHHIQQQIHHHHHH',elf);assert header[4]==0x80000000
    image=bytearray(1024*1024);segments=[]
    for i in range(header[10]):
        typ,flags,offset,va,pa,fs,ms,align=struct.unpack_from('<IIQQQQQQ',elf,header[5]+i*header[9])
        if typ!=1:continue
        assert va==pa and 0x80000000<=va and va+ms<=0x80100000
        image[va-0x80000000:va-0x80000000+fs]=elf[offset:offset+fs];segments.append(dict(va=hex(va),filesz=fs,memsz=ms))
    with (out/'test.loadmem_hex').open('w') as f:
        for i in range(0,len(image),64):f.write(image[i:i+64][::-1].hex()+'\n')
    sym=(out/'test.symbols').read_text();pcs={}
    for n in ['common_roi_start','common_roi_stop','__stack_start','__stack_size','timer_flags']:
        match=re.search(r'^\s*\d+: ([0-9a-f]+)\s+\S+\s+\S+\s+\S+\s+\S+\s+\S+\s+'+n+r'$',sym,re.M);assert match,n;pcs[n]='0x'+match[1]
    records.update(source_archive=str(PARSEC/'parsec-3.0-core.tar.gz'),upstream_sha256=sha(src/'blackscholes.upstream.c'),input_sha256=sha(src/'in_4.txt'),input='PARSEC 3.0 official test/in_4.txt',options=4,runs=100,pricings=400,threads=1,isa='rv64imafd/lp64d',optimization='-O2, no fast-math',roi_scope='original bs_thread 100 runs, plus common STOP/session completion; initialization/output excluded',segments=segments,symbols=pcs,elf_sha256=sha(out/'test.riscv'),loadmem_sha256=sha(out/'test.loadmem_hex'),compiler_version=subprocess.check_output([str(TOOLS/'riscv64-unknown-elf-gcc'),'--version'],text=True),source_hashes={str(p.relative_to(src)):sha(p) for p in sorted(src.rglob('*')) if p.is_file()})
    dump(out/'build.manifest.json',records);print(json.dumps({k:v for k,v in records.items() if k not in ['source_hashes','command']},indent=2))
if __name__=='__main__':main()
