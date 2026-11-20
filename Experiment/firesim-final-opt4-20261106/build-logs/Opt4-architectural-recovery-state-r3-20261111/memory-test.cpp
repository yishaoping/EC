#include "VPackageRecoveryMemory.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <vector>
#include <algorithm>
VPackageRecoveryMemory d;
uint64_t cycle=0, completed=0, released=0;
#define CHECK(x) do { if(!(x)) { std::fprintf(stderr,"RECOVERY_BACKEND_FAIL line=%d cycle=%llu error=%u\n",__LINE__,(unsigned long long)cycle,d.io_protocolError); std::exit(2); } } while(0)
struct Header { uint32_t sequence,generation; uint64_t restartPc,architecturalToken,memoryToken; };
Header header(unsigned s,unsigned g=7,uint64_t token=63){return {s,g,0x1000ULL+s*4,0xa000ULL+s,token};}
void set_initialize(Header h){d.io_initialize_bits_sequence=h.sequence;d.io_initialize_bits_generation=h.generation;d.io_initialize_bits_restartPc=h.restartPc;d.io_initialize_bits_architecturalToken=h.architecturalToken;d.io_initialize_bits_memoryToken=h.memoryToken;}
void set_release(Header h){d.io_release_bits_sequence=h.sequence;d.io_release_bits_generation=h.generation;d.io_release_bits_restartPc=h.restartPc;d.io_release_bits_architecturalToken=h.architecturalToken;d.io_release_bits_memoryToken=h.memoryToken;}
void set_restore(Header h,unsigned failed){d.io_restore_bits_checkpoint_sequence=h.sequence;d.io_restore_bits_checkpoint_generation=h.generation;d.io_restore_bits_checkpoint_restartPc=h.restartPc;d.io_restore_bits_checkpoint_architecturalToken=h.architecturalToken;d.io_restore_bits_checkpoint_memoryToken=h.memoryToken;d.io_restore_bits_failedSequence=failed;d.io_restore_bits_recoveryGeneration=h.generation+1;}
void set_writeCompleted_command(Header h,unsigned failed){d.io_writeCompleted_bits_command_checkpoint_sequence=h.sequence;d.io_writeCompleted_bits_command_checkpoint_generation=h.generation;d.io_writeCompleted_bits_command_checkpoint_restartPc=h.restartPc;d.io_writeCompleted_bits_command_checkpoint_architecturalToken=h.architecturalToken;d.io_writeCompleted_bits_command_checkpoint_memoryToken=h.memoryToken;d.io_writeCompleted_bits_command_failedSequence=failed;d.io_writeCompleted_bits_command_recoveryGeneration=h.generation+1;}
void set_rebase_command(Header h,unsigned failed){d.io_rebase_bits_command_checkpoint_sequence=h.sequence;d.io_rebase_bits_command_checkpoint_generation=h.generation;d.io_rebase_bits_command_checkpoint_restartPc=h.restartPc;d.io_rebase_bits_command_checkpoint_architecturalToken=h.architecturalToken;d.io_rebase_bits_command_checkpoint_memoryToken=h.memoryToken;d.io_rebase_bits_command_failedSequence=failed;d.io_rebase_bits_command_recoveryGeneration=h.generation+1;}

void evaluate(){d.clock=0;d.eval();}
void tick(){
  evaluate();
  if(!d.reset){if(d.io_restored_valid)++completed;if(d.io_released_valid)++released;}
  d.clock=1;d.eval();d.clock=0;d.eval();++cycle;
}
void error(){
  evaluate();CHECK(d.io_protocolError);auto before=completed;
  d.io_writeCompleted_valid=0;
  for(unsigned k=0;k<4;++k){tick();CHECK(d.io_protocolError);CHECK(!d.io_write_valid);CHECK(completed==before);}
}


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
  set_rebase_command(h,failed);d.io_rebase_bits_pipelineQuiescent=1;d.io_rebase_bits_memoryRestored=1;
  d.io_rebase_bits_architectureRestored=1;d.io_rebase_bits_checkersInitialized=1;d.io_rebase_valid=1;
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
  for(unsigned scenario=0;scenario<4;++scenario){
    initialize();startRestore(header(10));tick();CHECK(completed==1);
    set_rebase_command(header(10),14);d.io_rebase_bits_pipelineQuiescent=scenario!=0;
    d.io_rebase_bits_memoryRestored=scenario!=1;d.io_rebase_bits_architectureRestored=scenario!=2;
    d.io_rebase_bits_checkersInitialized=scenario!=3;d.io_rebase_valid=1;
    tick();d.io_rebase_valid=0;error();++negatives;
  }
  initialize();startRestore(header(10));tick();CHECK(completed==1);
  rebase(header(10));evaluate();CHECK(d.io_log_ready);log(11,0,8);CHECK(!d.io_protocolError);
  std::printf("RECOVERY_MEMORY_PASS reverse_transactions=16 records_per_transaction=64 masked_overlap=1 cursor_ring_wrap=1 ownership_until_ack=1 negative_cases=%u real_cache_integration=0\n",negatives);
  d.final();return 0;
}

