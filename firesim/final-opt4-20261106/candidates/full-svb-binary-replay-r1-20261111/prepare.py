#!/usr/bin/python3
from pathlib import Path
import hashlib,json
C=Path(__file__).resolve().parent
OBS=C.with_name('full-gg-external-observer-r5-20261111')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=D/'cycleprecise-frozen-svb-r3-20261111'
layout=json.loads((OBS/'binary-layout.json').read_text())
(C/'binary-layout.json').write_bytes((OBS/'binary-layout.json').read_bytes())
fields=layout['fields'];by={f['name']:f for f in fields}
setters=[];checks=[];zero=[];harvest=[]
for f in fields:
 if f['name'] in ['fastest_target_cycle','boom_csr_cycle','host_time','clock']:continue
 name=f['name'];width=f['width'];offset=f['word_offset'];count=f['word_count']
 if f['direction']=='input':
  if width<=64:
   setters.append(f' d.{name}=get(row,{offset},{count});')
   zero.append(f' d.{name}=0;')
  else:
   setters.append(f' for(unsigned j=0;j<{count};++j)d.{name}[j]=row[{offset}+j];')
   zero.append(f' for(unsigned j=0;j<{count};++j)d.{name}[j]=0;')
 else:
  cond='known_reset'
  if name.startswith('io_promote_bits_'):cond+='&&d.io_promote_valid'
  if name.startswith('io_active'):cond+='&&(d.io_selected||d.io_promote_valid||d.io_ack_valid)'
  if name.startswith('io_releaseBlocking'):cond+='&&d.io_releaseBlocked_3'
  for j in range(count):
   expr=f'd.{name}[{j}]' if width>64 else f'(uint64_t(d.{name})>>{32*j})'
   checks.append(f' if({cond})check("{name}[{j}]",row[{offset+j}],uint32_t({expr}));')
   harvest.append(f' row[{offset+j}]=uint32_t({expr});')
source=r'''
#include "VSpeculativeVersionBuffer.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdexcept>
using Row=std::array<uint32_t,@WORDS@>;
static uint64_t get(const Row& row,unsigned offset,unsigned count) {
 uint64_t v=0;for(unsigned j=0;j<count;++j)v|=uint64_t(row[offset+j])<<(32*j);return v;
}
static void drive(VSpeculativeVersionBuffer& d,const Row& row) {
@SETTERS@
 d.io_resetStats=0;d.io_countStats=0;
}
struct Compare {
 uint64_t fields=0,errors=0,tick=0;
 void check(const char* name,uint32_t expected,uint32_t actual) {
  ++fields;if(expected!=actual){++errors;if(errors<=8)fprintf(stderr,"MISMATCH tick=%llu port=%s expected=%08x actual=%08x\n",(unsigned long long)tick,name,expected,actual);}
 }
 void outputs(VSpeculativeVersionBuffer& d,const Row& row,bool known_reset) {
@CHECKS@
 }
};
static void step(VSpeculativeVersionBuffer& d) {d.clock=1;d.eval();d.clock=0;d.eval();}
int main(int argc,char**argv) {
 Verilated::commandArgs(argc,argv);
 VSpeculativeVersionBuffer d;
 d.clock=0;
@ZERO@
 d.io_resetStats=0;d.io_countStats=0;
 if(argc==2 && std::string(argv[1])=="--self-test-data") {
  d.reset=1;d.eval();step(d);step(d);d.reset=0;d.eval();
  d.io_capture_valid=1;d.io_capture_bits_line=0x80001000;
  d.io_capture_bits_key_valid=1;d.io_capture_bits_key_writer=3;
  d.io_capture_bits_key_generation=17;d.io_capture_bits_key_contentSeq=1;
  d.io_capture_bits_epoch=4;d.io_capture_bits_param=3;
  for(unsigned j=0;j<4;++j){d.io_capture_bits_data_0[j]=0x1100+j;d.io_capture_bits_data_1[j]=0x2200+j;d.io_capture_bits_data_2[j]=0x3300+j;d.io_capture_bits_data_3[j]=0x4400+j;}
  d.eval();if(!d.io_capture_ready)return 20;step(d);
  d.io_capture_valid=0;d.io_safeWatermark=1;d.eval();step(d);step(d);
  if(!d.io_promote_valid)return 21;
  Row row{};
@HARVEST@
  Compare equal;equal.tick=0;equal.outputs(d,row,true);if(equal.errors)return 22;
  row[@DATA_OFFSET@]^=1;
  Compare negative;negative.tick=0;negative.outputs(d,row,true);
  if(negative.errors!=1)return 23;
  printf("REPLAY_DATA_MUTATION_REJECTED defined_output_checks=%llu errors=%llu scope=directed_original_frozen_component\n",(unsigned long long)negative.fields,(unsigned long long)negative.errors);
  d.final();return 0;
 }
 if(argc<2)return 2;
 FILE* input=fopen(argv[1],"rb");if(!input)return 3;
 char magic[16];if(fread(magic,1,16,input)!=16||memcmp(magic,"ECSVBFULLBINv1",13))return 4;
 Row row{};Compare c;uint64_t cycles=0,last=0,first=0,reset_edges=0;
 bool known_reset=false;bool mutate=argc==3&&std::string(argv[2])=="--mutate-data";bool mutated=false;
 while(true) {
  const size_t n=fread(row.data(),1,sizeof(row),input);if(!n)break;if(n!=sizeof(row))return 5;
  const auto tick=get(row,0,2);if(cycles&&tick!=last+1)return 6;if(!cycles)first=tick;last=tick;
  drive(d,row);d.clock=0;d.eval();
  if(mutate&&!mutated&&d.io_promote_valid){row[@DATA_OFFSET@]^=1;mutated=true;}
  c.tick=tick;c.outputs(d,row,known_reset);
  step(d);if(d.reset){known_reset=true;++reset_edges;}
  ++cycles;
 }
 fclose(input);d.final();
 printf("REPLAY_SUMMARY cycles=%llu first_tick=%llu last_tick=%llu reset_edges=%llu defined_output_word_checks=%llu mismatches=%llu mutation_applied=%u\n",(unsigned long long)cycles,(unsigned long long)first,(unsigned long long)last,(unsigned long long)reset_edges,(unsigned long long)c.fields,(unsigned long long)c.errors,unsigned(mutated));
 if(mutate)return mutated&&c.errors>0?0:7;
 return c.errors?8:0;
}
'''
for a,b in {'@WORDS@':str(layout['record_words']),'@SETTERS@':'\n'.join(setters),'@CHECKS@':'\n'.join(checks),'@ZERO@':'\n'.join(zero),'@HARVEST@':'\n'.join(harvest),'@DATA_OFFSET@':str(by['io_promote_bits_data_0']['word_offset'])}.items():source=source.replace(a,b)
(C/'replay.cpp').write_text(source)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
plan=dict(schema='ec-original-svb-replay-plan/1',functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
 model_kind='Reused standalone frozen target SpeculativeVersionBuffer archive; not FAME transformed host module',
 archive=str(R/'obj/VSpeculativeVersionBuffer__ALL.a'),archive_sha256=sha(R/'obj/VSpeculativeVersionBuffer__ALL.a'),
 frozen_rtl=str(R/'SpeculativeVersionBuffer.sv'),frozen_rtl_sha256=sha(R/'SpeculativeVersionBuffer.sv'),
 model_object_inputs={str(p):sha(p) for p in [R/'obj/verilated.o',R/'obj/verilated_threads.o',R/'obj/VSpeculativeVersionBuffer.h',R/'binding.json',R/'harness-adaptation.json']},
 replay_source_sha256=sha(C/'replay.cpp'),layout_sha256=sha(C/'binary-layout.json'),
 observation_contract='Every defined output among the 62 original host ports is compared pre-target-edge. Invalid payload/uninitialized slot-index outputs are not counted as defined. All reset/idle/backpressure cycles are preserved. Standalone target takes one target clock per binary record.',
 extra_target_inputs={'io_countStats':0,'io_resetStats':0},
 extra_input_scope='Only diagnostic max/histogram outputs not emitted among62ports use these statistics inputs; original SVB source lines197-225. currentEpoch is optimized out. No capture/selection/ACK/retention behavior depends on them.',
 compile_only_new_replay_main=True,target_or_host_rtl_modified=False,fpga_access=False)
(C/'plan.json').write_text(json.dumps(plan,indent=2,sort_keys=True)+'\n')
print(C/'plan.json')
