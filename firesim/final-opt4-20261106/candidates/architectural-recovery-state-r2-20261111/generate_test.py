#!/usr/bin/python3
"""Actual RTL tests; external devices are test models, never DUT evidence."""
from pathlib import Path
import sys

kind, output = sys.argv[1:]
top = 'PackageRecoveryState' if kind == 'state' else 'PackageRecoveryMemory'
lines = [f'#include "V{top}.h"', '#include "verilated.h"',
         '#include <cstdio>', '#include <cstdlib>', '#include <cstdint>',
         '#include <array>', '#include <vector>', '#include <algorithm>',
         f'V{top} d;', 'uint64_t cycle=0, completed=0, released=0;',
         '#define CHECK(x) do { if(!(x)) { std::fprintf(stderr,"RECOVERY_BACKEND_FAIL line=%d cycle=%llu error=%u\\n",__LINE__,(unsigned long long)cycle,d.io_protocolError); std::exit(2); } } while(0)']
fields = [('sequence','uint32_t'), ('generation','uint32_t'), ('restartPc','uint64_t'),
          ('architecturalToken','uint64_t'), ('memoryToken','uint64_t')]
lines += ['struct Header { uint32_t sequence,generation; uint64_t restartPc,architecturalToken,memoryToken; };',
          'Header header(unsigned s,unsigned g=7,uint64_t token=63){return {s,g,0x1000ULL+s*4,0xa000ULL+s,token};}']
for port in (['allocate', 'seal'] if kind == 'state' else ['initialize', 'release']):
    lines += [f'void set_{port}(Header h){{'+''.join(f'd.io_{port}_bits_{f}=h.{f};' for f,_ in fields)+'}']
for port in ['restore', 'writeCompleted_command', 'rebase_command']:
    prefix = f'io_{port}_bits_' if port == 'restore' else f'io_{port.split("_")[0]}_bits_command_'
    lines += [f'void set_{port}(Header h,unsigned failed){{'+
              ''.join(f'd.{prefix}checkpoint_{f}=h.{f};' for f,_ in fields)+
              f'd.{prefix}failedSequence=failed;d.{prefix}recoveryGeneration=h.generation+1;'+'}']
lines += [r'''
void evaluate(){d.clock=0;d.eval();}
void tick(){
  evaluate();
  if(!d.reset){if(d.io_restored_valid)++completed;'''+
          ('if(d.io_released_valid)++released;' if kind == 'memory' else '')+r'''}
  d.clock=1;d.eval();d.clock=0;d.eval();++cycle;
}
void error(){
  evaluate();CHECK(d.io_protocolError);auto before=completed;
  d.io_writeCompleted_valid=0;
  for(unsigned k=0;k<4;++k){tick();CHECK(d.io_protocolError);CHECK(!d.io_write_valid);CHECK(completed==before);}
}
''']
if kind == 'state':
    lines += [r'''
uint64_t value(Header h,unsigned w){
  if(w==0)return 0;if(w==64)return h.restartPc;if(w==65)return 1;
  return 0x1020304050607080ULL ^ (uint64_t(h.sequence)<<32) ^ w;
}
void initialize(){
  d.io_lock=0;d.io_allocate_valid=0;d.io_word_valid=0;d.io_seal_valid=0;
  d.io_result_valid=0;d.io_restore_valid=0;d.io_write_ready=0;
  d.io_writeCompleted_valid=0;d.io_rebase_valid=0;d.io_failure_ready=0;
  d.reset=1;tick();tick();d.reset=0;completed=0;tick();CHECK(!d.io_protocolError);
}
void allocate(Header h){
  set_allocate(h);d.io_allocate_valid=1;evaluate();CHECK(d.io_allocate_ready);
  tick();d.io_allocate_valid=0;
}
void word(Header h,unsigned w){
  d.io_word_bits_sequence=h.sequence;d.io_word_bits_generation=h.generation;
  d.io_word_bits_index=w;d.io_word_bits_data=value(h,w);d.io_word_valid=1;
  evaluate();CHECK(d.io_word_ready);tick();d.io_word_valid=0;
}
void snapshot(Header h){
  allocate(h);for(unsigned w=0;w<96;++w)word(h,w);
  set_seal(h);d.io_seal_valid=1;evaluate();CHECK(d.io_seal_ready);
  tick();d.io_seal_valid=0;
}
void result(unsigned s,bool passed=true,unsigned g=7){
  d.io_result_bits_sequence=s;d.io_result_bits_generation=g;
  d.io_result_bits_compared=1;d.io_result_bits_passed=passed;
  d.io_result_valid=1;evaluate();CHECK(d.io_result_ready);tick();d.io_result_valid=0;
}
void expect(unsigned s,unsigned g=7){
  evaluate();CHECK(d.io_checkpoint_valid);CHECK(d.io_checkpoint_bits_sequence==s);
  CHECK(d.io_checkpoint_bits_generation==g);
}
void failureSetup(){
  snapshot(header(1));result(1);tick();expect(1);
  for(unsigned s=2;s<=5;++s)snapshot(header(s));
  result(5);tick();expect(1);result(3);tick();expect(1);
  result(2);tick();tick();expect(3);
  result(4,false);tick();expect(3);CHECK(d.io_failure_valid);
  CHECK(d.io_failure_bits_sequence==4);CHECK(d.io_failure_bits_comparedMismatch);
  d.io_failure_ready=1;tick();d.io_failure_ready=0;evaluate();CHECK(!d.io_failure_valid);
}
void startRestore(Header h,unsigned failed=4){
  d.io_lock=1;set_restore(h,failed);d.io_restore_valid=1;
  evaluate();CHECK(d.io_restore_ready);tick();d.io_restore_valid=0;
}
void restoreAll(Header h,unsigned round){
  std::array<uint64_t,96> actual{};actual.fill(0xdeadbeef);
  for(unsigned w=0;w<96;++w){
    evaluate();CHECK(d.io_write_valid);CHECK(d.io_write_bits_index==w);
    CHECK(d.io_write_bits_data==value(h,w));CHECK(completed==0);
    CHECK(d.io_write_bits_command_checkpoint_sequence==h.sequence);
    for(unsigned delay=0;delay<(w+round)%5;++delay){
      tick();CHECK(d.io_write_valid);CHECK(d.io_write_bits_index==w);CHECK(completed==0);
    }
    d.io_write_ready=1;tick();d.io_write_ready=0;evaluate();
    CHECK(!d.io_write_valid);CHECK(completed==0);
    for(unsigned delay=0;delay<(w+round)%3;++delay)tick();
    actual[w]=value(h,w); // simulated device commits, then supplies observed readback
    set_writeCompleted_command(h,4);d.io_writeCompleted_bits_index=w;
    d.io_writeCompleted_bits_data=actual[w];d.io_writeCompleted_valid=1;
    tick();d.io_writeCompleted_valid=0;
    CHECK(completed==(w==95?1u:0u));
  }
  for(unsigned w=0;w<96;++w)CHECK(actual[w]==value(h,w));
  CHECK(!d.io_restoreActive);expect(h.sequence,h.generation);
}
void rebase(Header h,unsigned failed=4){
  set_rebase_command(h,failed);d.io_rebase_bits_retiredPc=h.restartPc;
  d.io_rebase_bits_allCheckerTasksDrained=1;d.io_rebase_valid=1;
  evaluate();CHECK(d.io_rebase_ready);tick();d.io_rebase_valid=0;d.io_lock=0;
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);
  for(unsigned round=0;round<16;++round){
    initialize();failureSetup();startRestore(header(3));restoreAll(header(3),round);
    CHECK(d.io_occupancy==3); // safe 3 + failed 4 + later PASS 5, preserved until rebase
    rebase(header(3));expect(3,8);CHECK(d.io_occupancy==1);
    snapshot(header(4,8));result(4,true,8);tick();expect(4,8);
  }
  // Full slots backpressure; a gap or unsealed PASS cannot expose a checkpoint.
  initialize();for(unsigned s=1;s<=6;++s)snapshot(header(s));
  d.io_allocate_valid=1;set_allocate(header(7));evaluate();CHECK(!d.io_allocate_ready);
  tick();d.io_allocate_valid=0;CHECK(d.io_occupancy==6);CHECK(!d.io_checkpoint_valid);
  result(1);tick();expect(1);result(2);tick();expect(2);evaluate();CHECK(d.io_allocate_ready);
  initialize();allocate(header(1));result(1);tick();CHECK(!d.io_checkpoint_valid);
  for(unsigned w=0;w<96;++w)word(header(1),w);
  CHECK(!d.io_checkpoint_valid);set_seal(header(1));d.io_seal_valid=1;tick();d.io_seal_valid=0;expect(1);
  unsigned negatives=0;
  for(unsigned scenario=0;scenario<6;++scenario){
    initialize();allocate(header(1));
    d.io_word_bits_sequence=1;d.io_word_bits_generation=7;d.io_word_bits_index=0;d.io_word_bits_data=0;
    if(scenario==0)d.io_word_bits_index=1;
    if(scenario==1)d.io_word_bits_sequence=2;
    if(scenario==2)d.io_word_bits_generation=8;
    if(scenario==3)d.io_word_bits_data=1;
    if(scenario>=4){for(unsigned w=0;w<(scenario==4?64u:65u);++w)word(header(1),w);
      d.io_word_bits_index=scenario==4?64:65;d.io_word_bits_data=scenario==4?0xdead:2;}
    d.io_word_valid=1;tick();d.io_word_valid=0;error();++negatives;
  }
  for(unsigned scenario=0;scenario<4;++scenario){
    initialize();snapshot(header(1));
    d.io_result_bits_sequence=scenario==0?2:1;d.io_result_bits_generation=scenario==1?8:7;
    d.io_result_bits_compared=scenario!=2;d.io_result_bits_passed=1;
    if(scenario==3)result(1);
    d.io_result_valid=1;tick();d.io_result_valid=0;error();++negatives;
  }
  for(unsigned scenario=0;scenario<6;++scenario){
    initialize();failureSetup();Header h=header(3);
    if(scenario==0)++h.architecturalToken;
    if(scenario==1)++h.memoryToken;
    if(scenario==2)++h.generation;
    d.io_lock=scenario!=3;set_restore(h,scenario==4?5:4);
    if(scenario==5)++d.io_restore_bits_recoveryGeneration;
    d.io_restore_valid=1;tick();d.io_restore_valid=0;error();++negatives;
  }
  for(unsigned scenario=0;scenario<5;++scenario){
    initialize();failureSetup();startRestore(header(3));
    if(scenario!=0){d.io_write_ready=1;tick();d.io_write_ready=0;}
    set_writeCompleted_command(header(3),4);d.io_writeCompleted_bits_index=0;
    d.io_writeCompleted_bits_data=0;
    if(scenario==1)++d.io_writeCompleted_bits_command_recoveryGeneration;
    if(scenario==2)++d.io_writeCompleted_bits_index;
    if(scenario==3)++d.io_writeCompleted_bits_data;
    if(scenario==4)++d.io_writeCompleted_bits_command_checkpoint_memoryToken;
    d.io_writeCompleted_valid=1;tick();d.io_writeCompleted_valid=0;error();++negatives;
    CHECK(completed==0);
  }
  initialize();failureSetup();startRestore(header(3));restoreAll(header(3),0);
  set_rebase_command(header(3),4);d.io_rebase_bits_retiredPc=header(3).restartPc;
  d.io_rebase_bits_allCheckerTasksDrained=0;d.io_rebase_valid=1;tick();d.io_rebase_valid=0;error();++negatives;
  std::printf("RECOVERY_STATE_PASS restore_transactions=16 words_per_snapshot=96 negative_cases=%u contiguous_prefix=1 full_backpressure=1 incomplete_snapshot_rejected=1 real_dut_integration=0\n",negatives);
  d.final();return 0;
}
''']
else:
    lines += [r'''
using Memory=std::array<uint64_t,8>;
struct Undo {uint64_t cursor,address,data;unsigned mask;};
std::vector<Undo> undo;Memory memory{},expected{};
uint64_t mask64(unsigned mask){uint64_t v=0;for(unsigned i=0;i<8;++i)if(mask&(1u<<i))v|=0xffULL<<(8*i);return v;}
void initialize(Header h=header(10)){
  d.io_lock=0;d.io_initialize_valid=0;d.io_log_valid=0;d.io_release_valid=0;
  d.io_restore_valid=0;d.io_write_ready=0;d.io_writeCompleted_valid=0;d.io_rebase_valid=0;
  d.reset=1;tick();tick();d.reset=0;completed=0;released=0;tick();
  set_initialize(h);d.io_initialize_valid=1;evaluate();CHECK(d.io_initialize_ready);
  tick();d.io_initialize_valid=0;undo.clear();
  for(unsigned i=0;i<8;++i)memory[i]=0x1020304050607080ULL+i;
}
void log(unsigned s,unsigned n,unsigned g=7){
  unsigned a=n%8,mask=(n%255)+1;uint64_t old=memory[a];
  d.io_log_bits_sequence=s;d.io_log_bits_generation=g;d.io_log_bits_address=0x80000000ULL+a*8;
  d.io_log_bits_previousData=old;d.io_log_bits_mask=mask;d.io_log_valid=1;
  evaluate();CHECK(d.io_log_ready);
  undo.push_back({d.io_nextToken,d.io_log_bits_address,old,mask});
  tick();d.io_log_valid=0;
  uint64_t m=mask64(mask);memory[a]=(old&~m)|((0xfefdfcfbfaf9f8f7ULL+n)&m);
}
void release(Header h){
  set_release(h);d.io_release_valid=1;evaluate();CHECK(d.io_release_ready);
  tick();d.io_release_valid=0;
  for(unsigned k=0;k<70&&released==0&&!d.io_protocolError;++k)tick();
}
void startRestore(Header h,unsigned failed=14){
  d.io_lock=1;set_restore(h,failed);d.io_restore_valid=1;evaluate();CHECK(d.io_restore_ready);
  tick();d.io_restore_valid=0;
}
void rebase(Header h,unsigned failed=14){
  set_rebase_command(h,failed);d.io_rebase_bits_retiredPc=h.restartPc;
  d.io_rebase_bits_allCheckerTasksDrained=1;d.io_rebase_valid=1;
  evaluate();CHECK(d.io_rebase_ready);tick();d.io_rebase_valid=0;d.io_lock=0;
}
void fill(){
  for(unsigned n=0;n<64;++n){log(11+n/16,n);if(n==15)expected=memory;}
}
void acceptedWrite(){evaluate();CHECK(d.io_write_valid);d.io_write_ready=1;tick();d.io_write_ready=0;}
void ack(Undo u,Header h=header(10),unsigned failed=14){
  set_writeCompleted_command(h,failed);d.io_writeCompleted_bits_cursor=u.cursor;
  d.io_writeCompleted_bits_address=u.address;d.io_writeCompleted_bits_mask=u.mask;
  d.io_writeCompleted_bits_data=u.data;d.io_writeCompleted_valid=1;
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);
  for(unsigned run=0;run<16;++run){
    initialize();fill();CHECK(d.io_occupancy==64);CHECK(d.io_nextToken==127);
    d.io_log_valid=1;evaluate();CHECK(!d.io_log_ready);tick();d.io_log_valid=0;CHECK(d.io_occupancy==64);
    Header h=header(11,7,79);release(h);CHECK(released==1);CHECK(d.io_occupancy==48);
    startRestore(h);
    for(unsigned n=64;n>16;--n){
      Undo u=undo[n-1];evaluate();CHECK(d.io_write_valid);CHECK(completed==0);
      CHECK(d.io_write_bits_cursor==u.cursor);CHECK(d.io_write_bits_address==u.address);
      CHECK(d.io_write_bits_mask==u.mask);CHECK(d.io_write_bits_data==u.data);
      for(unsigned k=0;k<(run+n)%4;++k){tick();CHECK(d.io_occupancy==n-16);CHECK(d.io_write_valid);}
      acceptedWrite();CHECK(d.io_occupancy==n-16);CHECK(completed==0);
      for(unsigned k=0;k<n%3;++k)tick();
      unsigned a=(u.address-0x80000000ULL)/8;uint64_t m=mask64(u.mask);
      memory[a]=(memory[a]&~m)|(u.data&m);ack(u,h);d.io_writeCompleted_bits_data=memory[a];
      tick();d.io_writeCompleted_valid=0;CHECK(d.io_occupancy==n-17);
    }
    CHECK(memory==expected);CHECK(completed==0);tick();CHECK(completed==1);
    CHECK(d.io_nextToken==79);rebase(h);CHECK(!d.io_active);
    Header h2=header(11,8,79);startRestore(h2,12);tick();CHECK(completed==2);rebase(h2,12);
    CHECK(!d.io_protocolError);log(12,0,9);CHECK(!d.io_protocolError);
  }
  unsigned negatives=0;
  for(unsigned scenario=0;scenario<6;++scenario){
    initialize();if(scenario==5)log(12,0);
    d.io_log_bits_sequence=scenario==0?10:11;d.io_log_bits_generation=scenario==1?8:7;
    d.io_log_bits_address=scenario==2?0x80000001:0x80000000;
    d.io_log_bits_previousData=0;d.io_log_bits_mask=scenario==3?0:255;
    if(scenario==4){initialize(header(10,7,UINT64_MAX));}
    d.io_log_valid=1;tick();d.io_log_valid=0;error();++negatives;
  }
  for(unsigned scenario=0;scenario<4;++scenario){
    initialize();log(11,0);Header h=header(11,7,64);
    if(scenario==0)h.memoryToken=65;if(scenario==1)h.generation=8;
    if(scenario==2)h.sequence=10;if(scenario==3)h.memoryToken=63;
    release(h);error();++negatives;
  }
  for(unsigned scenario=0;scenario<5;++scenario){
    initialize();log(11,0);Header h=header(10);
    if(scenario==0)++h.memoryToken;if(scenario==1)++h.architecturalToken;
    d.io_lock=scenario!=2;set_restore(h,scenario==3?10:14);
    if(scenario==4)++d.io_restore_bits_recoveryGeneration;
    d.io_restore_valid=1;tick();d.io_restore_valid=0;error();++negatives;
  }
  for(unsigned scenario=0;scenario<7;++scenario){
    initialize();log(11,0);startRestore(header(10));if(scenario!=0)acceptedWrite();
    ack(undo.back());
    if(scenario==1)++d.io_writeCompleted_bits_cursor;
    if(scenario==2)d.io_writeCompleted_bits_address+=8;
    if(scenario==3)d.io_writeCompleted_bits_mask^=1;
    if(scenario==4)d.io_writeCompleted_bits_data^=1;
    if(scenario==5)++d.io_writeCompleted_bits_command_recoveryGeneration;
    if(scenario==6)++d.io_writeCompleted_bits_command_checkpoint_memoryToken;
    tick();d.io_writeCompleted_valid=0;error();++negatives;CHECK(d.io_occupancy==1);CHECK(completed==0);
  }
  initialize();startRestore(header(10));
  ack({62,0x80000000,0,255});tick();d.io_writeCompleted_valid=0;error();++negatives;CHECK(completed==0);
  initialize();startRestore(header(10));tick();CHECK(completed==1);
  set_rebase_command(header(10),14);d.io_rebase_bits_retiredPc=0xdead;
  d.io_rebase_bits_allCheckerTasksDrained=1;d.io_rebase_valid=1;tick();d.io_rebase_valid=0;error();++negatives;
  std::printf("RECOVERY_MEMORY_PASS reverse_transactions=16 records_per_transaction=64 masked_overlap=1 cursor_ring_wrap=1 ownership_until_ack=1 negative_cases=%u real_cache_integration=0\n",negatives);
  d.final();return 0;
}
''']
Path(output).write_text('\n'.join(lines)+'\n')
