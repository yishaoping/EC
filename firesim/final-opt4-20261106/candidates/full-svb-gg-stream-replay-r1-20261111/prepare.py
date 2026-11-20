#!/usr/bin/python3
from pathlib import Path
import json,hashlib,shlex,re,struct
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
F=D/'cycleprecise-frozen-svb-fpga-r2-20261111';G=F/'goldengate';OBJ=G/'VSVBProbe.csrc'
O=D/'cycleprecise-original-svb-gg-stream-replay-r1-20261111'
FS=C.parents[1]/'C4/chipyard/sims/firesim/sim'
OBS=C.with_name('full-gg-external-observer-r5-20261111')
layout=json.loads((OBS/'binary-layout.json').read_text());fields=layout['fields']
(C/'binary-layout.json').write_bytes((OBS/'binary-layout.json').read_bytes())
ports=[f for f in fields if f['name'] not in ['fastest_target_cycle','boom_csr_cycle','host_time','clock']]
defs='\n'.join('{"%s",%d,%d,%d,%s},'%(f['name'],f['word_offset'],f['word_count'],f['width'],'true' if f['direction']=='input' else 'false') for f in ports)
s=r'''
#include "TestHarness.h"
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <fcntl.h>
#include <unistd.h>
using Row=std::array<uint32_t,101>;
struct Port {const char*name;unsigned offset,count,width;bool input;};
static const Port ports[]={
@PORTS@
};
static uint64_t number(const Row&r,unsigned o,unsigned c=1){uint64_t v=0;for(unsigned j=0;j<c;++j)v|=uint64_t(r[o+j])<<(32*j);return v;}
class StreamingReplay final:public TestHarness {
 std::string trace,status_path;bool negative=false,mutated=false;
 uint64_t checks=0,words=0,rows=0,last_tick=0,first_tick=0,resets=0,errors=0,captures=0,promotions=0,acks=0;
 std::chrono::steady_clock::time_point start;
 void snapshot(const char*state){
  if(status_path.empty())return;
  const auto tmp=status_path+".tmp-"+std::to_string(getpid());
  FILE*f=fopen(tmp.c_str(),"wx");if(!f)throw std::runtime_error("snapshot open failed");
  fprintf(f,"{\"status\":\"%s\",\"processed_records\":%llu,\"last_source_target_cycle\":%llu,\"replayed_target_cycles\":%llu,\"defined_output_fields\":%llu,\"defined_output_words\":%llu,\"mismatches\":%llu,\"host_wall_seconds\":%.9f,\"restart_from_reset_required\":true}\n",state,(unsigned long long)rows,(unsigned long long)last_tick,(unsigned long long)cycles(),(unsigned long long)checks,(unsigned long long)words,(unsigned long long)errors,std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count());
  fflush(f);fsync(fileno(f));fclose(f);if(rename(tmp.c_str(),status_path.c_str()))throw std::runtime_error("snapshot rename failed");
 }
 void stable(){if(peek_poke.timeout()||peek_poke.unstable())throw std::runtime_error("peek-poke timeout or unstable target boundary");}
public:
 StreamingReplay(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n){
  for(const auto&s:a){if(s.starts_with("+svb-trace="))trace=s.substr(11);if(s.starts_with("+svb-state="))status_path=s.substr(11);if(s=="+svb-mutate-data")negative=true;}
  if(trace.empty())throw std::runtime_error("missing +svb-trace");
 }
 void run_test()override{
  log=false;start=std::chrono::steady_clock::now();
  std::ifstream f(trace,std::ios::binary);char magic[16],want[16]{};memcpy(want,"ECSVBFULLBINv1",13);
  if(!f.read(magic,16)||memcmp(magic,want,16))throw std::runtime_error("invalid full-port binary header");
  mpz_t value,actual;mpz_init(value);mpz_init(actual);
  // These three original component inputs only control omitted statistics/unused epoch.
  poke("io_currentEpoch",uint32_t(0));poke("io_resetStats",uint32_t(0));poke("io_countStats",uint32_t(0));
  Row row{};bool known_reset=false;
  while(true){
   f.read(reinterpret_cast<char*>(row.data()),sizeof(row));const auto n=f.gcount();if(n==0)break;if(n!=sizeof(row))throw std::runtime_error("partial binary record");
   const auto tick=number(row,0,2);if(rows&&tick!=last_tick+1)throw std::runtime_error("noncontiguous target cycles");
   if(row[6]!=1)throw std::runtime_error("not a sampled target edge");if(!rows)first_tick=tick;last_tick=tick;
   for(const auto&p:ports){if(p.width%32 && (row[p.offset+p.count-1]>>(p.width%32)))throw std::runtime_error("nonzero port padding");
    if(p.input){mpz_import(value,p.count,-1,4,0,0,row.data()+p.offset);poke(p.name,value);stable();}}
   // PeekPoke must synchronize all output tokens after the complete input vector.
   peek("io_occupancy");stable();
   if(negative&&!mutated&&known_reset&&row[42]){row[51]^=1;mutated=true;std::cout<<"MUTATED_EXPECTED_APPLICATION_OR_DIRECTED_PAYLOAD source_tick="<<tick<<" port=io_promote_bits_data_0 word=0\n";}
   for(const auto&p:ports){if(p.input)continue;
    const std::string name=p.name;
    bool defined=known_reset;
    if(name.starts_with("io_promote_bits_"))defined&=row[42]!=0;
    if(name.starts_with("io_active"))defined&=(row[68]||row[42]||row[93]);
    if(name.starts_with("io_releaseBlocking"))defined&=row[87]!=0;
    if(!defined)continue;
    mpz_import(value,p.count,-1,4,0,0,row.data()+p.offset);peek(p.name,actual);stable();++checks;words+=p.count;
    if(mpz_cmp(value,actual)){
     ++errors;char*ex=mpz_get_str(nullptr,16,value);char*got=mpz_get_str(nullptr,16,actual);
     std::cerr<<"SVB_GG_STREAM_MISMATCH record="<<rows<<" source_tick="<<tick<<" port="<<p.name<<" expected="<<ex<<" actual="<<got<<"\n";free(ex);free(got);
     expect(false,"full original-port comparison failed");snapshot("REJECTED_OUTPUT_MISMATCH");mpz_clear(value);mpz_clear(actual);return;
    }
   }
   if(known_reset){if(row[9]&&row[8])++captures;if(row[42]&&row[41])++promotions;if(row[100])++acks;}
   step(1);stable();if(row[7]){known_reset=true;++resets;}++rows;
   if((rows&4095)==0){snapshot("RUNNING");std::cout<<"SVB_GG_STREAM_PROGRESS records="<<rows<<" source_tick="<<tick<<"\n"<<std::flush;}
  }
  if(!known_reset)throw std::runtime_error("trace has no reset start");
  if(negative){expect(false,"negative mutation was not applied or rejected");snapshot("REJECTED_MISSING_NEGATIVE");}
  else snapshot("PASS_COMPLETE_BINARY_TRACE");
  std::cout<<"SVB_GG_STREAM_SUMMARY records="<<rows<<" first_source_tick="<<first_tick<<" last_source_tick="<<last_tick<<" target_cycles="<<cycles()<<" reset_edges="<<resets<<" defined_output_fields="<<checks<<" defined_output_word_checks="<<words<<" mismatches="<<errors<<" capture_accepted="<<captures<<" promote_accepted="<<promotions<<" acked="<<acks<<" mutation_applied="<<mutated<<" host_wall_seconds="<<std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count()<<"\n";
  mpz_clear(value);mpz_clear(actual);
 }
};TEST_MAIN(StreamingReplay)
'''.replace('@PORTS@',defs)
(C/'StreamingReplay.cc').write_text(s)
# Create a separately labeled synthetic trace using the original directed target proof.
old=D/'cycleprecise-frozen-svb-trace-r4-20261111';src=(old/'TraceTest.cc').read_text()
names={k:re.findall(r'"([^"]+)"',re.search(r'const char\* '+k+r'\[\]=\{([^}]+)\}',src).group(1)) for k in ['inputs','outputs']}
rows=[]
with (old/'target-cycles.txt').open() as f:
 tokens=iter(f.read().split())
 while True:
  try:orig=int(next(tokens))
  except StopIteration:break
  values={n:int(next(tokens),16) for n in names['inputs']+names['outputs']}
  row=[0]*101;tick=len(rows)+1;row[0]=tick;row[2]=tick;row[4]=tick;row[6]=1
  for p in ports:
   v=values[p['name']]
   for j in range(p['word_count']):row[p['word_offset']+j]=(v>>(32*j))&0xffffffff
  rows.append(struct.pack('<101I',*row))
(C/'directed-original-svb.bin').write_bytes(b'ECSVBFULLBINv1'.ljust(16,b'\0')+b''.join(rows))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
line=[l for l in (F/'adapter-metasim.log').read_text().splitlines() if l.startswith('clang++ ') and ' -o ' in l][-1]
link=shlex.split(line);link[0]=clang
for i,a in enumerate(link):
 if a=='TraceTest.o':link[i]=str(C/'StreamingReplay.o')
 elif a.endswith('.o') or a.endswith('.a'):link[i]=str(OBJ/a)
 if i and link[i-1]=='-o':link[i]=str(C/'VSVBStreamingReplay')
hline=[l for l in (F/'hardware-driver.log').read_text().splitlines() if l.startswith(clang) and ' -o ' in l][-1]
hlink=shlex.split(hline)
for i,a in enumerate(hlink):
 if a==str(old/'TraceTest.cc'):hlink[i]=str(C/'StreamingReplay.cc')
 if i and hlink[i-1]=='-o':hlink[i]=str(C/'SVBStreamingReplay-xilinx_alveo_u280')
compile_cmd=[clang,'-O1','-std=c++20','-I'+str(F/'external-headers'),'-I'+str(FS/'src/main/cc/midasexamples'),'-I'+str(FS/'midas/src/main/cc'),'-I'+str(G),'-include',str(G/'FireSim-generated.const.h'),'-c',str(C/'StreamingReplay.cc'),'-o',str(C/'StreamingReplay.o')]
objects=set(a for a in link+hlink if a.endswith('.o') or a.endswith('.a'))-{str(C/'StreamingReplay.o')}
inputs={str(p):sha(p) for p in map(Path,sorted(objects))}
for p in [G/'FireSim-generated.sv',G/'FireSim-generated.const.h',F/'hardware-driver.json',F/'simif_xilinx_alveo_u280_21_only.cc',F/'binding.json',C/'binary-layout.json',C/'StreamingReplay.cc',C/'directed-original-svb.bin']:inputs[str(p)]=sha(p)
plan=dict(schema='ec-svb-gg-stream-replay-plan/1',functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',profile='OriginalSVB32-component-trace',source_id='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f',compile=compile_cmd,cpu_link=link,hardware_link=hlink,inputs=inputs,board_allowlist=['0000:21:00.0'],fpga_access=False,target_or_model_modified=False,synthetic_directed_records=len(rows),bitstream_rebuild_required=False,extra_component_inputs={'io_currentEpoch':0,'io_countStats':0,'io_resetStats':0},scope='Streaming original62port binary through unchanged GG PeekPoke ABI; all defined pre-edge outputs compared; functional latency target cycles and host replay throughput kept separate. Component not wholeOpt4/checker/rollback proof.')
(C/'plan.json').write_text(json.dumps(plan,indent=2,sort_keys=True)+'\n')
print(C/'plan.json')
