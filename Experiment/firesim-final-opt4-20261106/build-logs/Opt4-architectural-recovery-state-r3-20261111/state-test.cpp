#include "VPackageRecoveryState.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <vector>
#include <algorithm>
VPackageRecoveryState d;
uint64_t cycle=0, completed=0, released=0;
#define CHECK(x) do { if(!(x)) { std::fprintf(stderr,"RECOVERY_BACKEND_FAIL line=%d cycle=%llu error=%u\n",__LINE__,(unsigned long long)cycle,d.io_protocolError); std::exit(2); } } while(0)
struct Header { uint32_t sequence,generation; uint64_t restartPc,architecturalToken,memoryToken; };
Header header(unsigned s,unsigned g=7,uint64_t token=63){return {s,g,0x1000ULL+s*4,0xa000ULL+s,token};}
void set_allocate(Header h){d.io_allocate_bits_sequence=h.sequence;d.io_allocate_bits_generation=h.generation;d.io_allocate_bits_restartPc=h.restartPc;d.io_allocate_bits_architecturalToken=h.architecturalToken;d.io_allocate_bits_memoryToken=h.memoryToken;}
void set_seal(Header h){d.io_seal_bits_sequence=h.sequence;d.io_seal_bits_generation=h.generation;d.io_seal_bits_restartPc=h.restartPc;d.io_seal_bits_architecturalToken=h.architecturalToken;d.io_seal_bits_memoryToken=h.memoryToken;}
void set_restore(Header h,unsigned failed){d.io_restore_bits_checkpoint_sequence=h.sequence;d.io_restore_bits_checkpoint_generation=h.generation;d.io_restore_bits_checkpoint_restartPc=h.restartPc;d.io_restore_bits_checkpoint_architecturalToken=h.architecturalToken;d.io_restore_bits_checkpoint_memoryToken=h.memoryToken;d.io_restore_bits_failedSequence=failed;d.io_restore_bits_recoveryGeneration=h.generation+1;}
void set_writeCompleted_command(Header h,unsigned failed){d.io_writeCompleted_bits_command_checkpoint_sequence=h.sequence;d.io_writeCompleted_bits_command_checkpoint_generation=h.generation;d.io_writeCompleted_bits_command_checkpoint_restartPc=h.restartPc;d.io_writeCompleted_bits_command_checkpoint_architecturalToken=h.architecturalToken;d.io_writeCompleted_bits_command_checkpoint_memoryToken=h.memoryToken;d.io_writeCompleted_bits_command_failedSequence=failed;d.io_writeCompleted_bits_command_recoveryGeneration=h.generation+1;}
void set_rebase_command(Header h,unsigned failed){d.io_rebase_bits_command_checkpoint_sequence=h.sequence;d.io_rebase_bits_command_checkpoint_generation=h.generation;d.io_rebase_bits_command_checkpoint_restartPc=h.restartPc;d.io_rebase_bits_command_checkpoint_architecturalToken=h.architecturalToken;d.io_rebase_bits_command_checkpoint_memoryToken=h.memoryToken;d.io_rebase_bits_command_failedSequence=failed;d.io_rebase_bits_command_recoveryGeneration=h.generation+1;}

void evaluate(){d.clock=0;d.eval();}
void tick(){
  evaluate();
  if(!d.reset){if(d.io_restored_valid)++completed;}
  d.clock=1;d.eval();d.clock=0;d.eval();++cycle;
}
void error(){
  evaluate();CHECK(d.io_protocolError);auto before=completed;
  d.io_writeCompleted_valid=0;
  for(unsigned k=0;k<4;++k){tick();CHECK(d.io_protocolError);CHECK(!d.io_write_valid);CHECK(completed==before);}
}


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
  set_rebase_command(h,failed);d.io_rebase_bits_pipelineQuiescent=1;d.io_rebase_bits_memoryRestored=1;
  d.io_rebase_bits_architectureRestored=1;d.io_rebase_bits_checkersInitialized=1;d.io_rebase_valid=1;
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
  for(unsigned scenario=0;scenario<4;++scenario){
    initialize();failureSetup();startRestore(header(3));restoreAll(header(3),0);
    set_rebase_command(header(3),4);d.io_rebase_bits_pipelineQuiescent=scenario!=0;
    d.io_rebase_bits_memoryRestored=scenario!=1;d.io_rebase_bits_architectureRestored=scenario!=2;
    d.io_rebase_bits_checkersInitialized=scenario!=3;d.io_rebase_valid=1;
    tick();d.io_rebase_valid=0;error();++negatives;
  }
  initialize();snapshot(header(1));result(1);tick();
  for(unsigned s=2;s<=4;++s)snapshot(header(s));
  result(2);result(3);result(4,false);evaluate();CHECK(d.io_freezeRequested);
  d.io_lock=1;for(unsigned k=0;k<4;++k)tick();expect(3);CHECK(d.io_failure_valid);
  CHECK(d.io_checkpoint_bits_sequence==3);
  std::printf("RECOVERY_STATE_PASS restore_transactions=16 words_per_snapshot=96 negative_cases=%u contiguous_prefix=1 full_backpressure=1 incomplete_snapshot_rejected=1 real_dut_integration=0\n",negatives);
  d.final();return 0;
}

