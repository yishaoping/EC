#include "VPackageRecoveryController.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
VPackageRecoveryController d; unsigned long long cycle=0,records=0;
std::vector<unsigned> kinds;
#define CHECK(x) do { if(!(x)) { std::fprintf(stderr,"CONTROL_FAIL line=%d cycle=%llu phase=%u\n",__LINE__,cycle,d.io_phase); std::exit(2); } } while(0)
CData* rq[]={&d.io_request_0_valid,&d.io_request_1_valid,&d.io_request_2_valid,&d.io_request_3_valid,&d.io_request_4_valid,&d.io_request_5_valid};
CData* ready[]={&d.io_request_0_ready,&d.io_request_1_ready,&d.io_request_2_ready,&d.io_request_3_ready,&d.io_request_4_ready,&d.io_request_5_ready};
CData* ack[]={&d.io_response_0_valid,&d.io_response_1_valid,&d.io_response_2_valid,&d.io_response_3_valid,&d.io_response_4_valid,&d.io_response_5_valid};
IData* qseq[]={&d.io_request_0_bits_checkpoint_sequence,&d.io_request_1_bits_checkpoint_sequence,&d.io_request_2_bits_checkpoint_sequence,&d.io_request_3_bits_checkpoint_sequence,&d.io_request_4_bits_checkpoint_sequence,&d.io_request_5_bits_checkpoint_sequence};
IData* aseq[]={&d.io_response_0_bits_command_checkpoint_sequence,&d.io_response_1_bits_command_checkpoint_sequence,&d.io_response_2_bits_command_checkpoint_sequence,&d.io_response_3_bits_command_checkpoint_sequence,&d.io_response_4_bits_command_checkpoint_sequence,&d.io_response_5_bits_command_checkpoint_sequence};
IData* qgen[]={&d.io_request_0_bits_checkpoint_generation,&d.io_request_1_bits_checkpoint_generation,&d.io_request_2_bits_checkpoint_generation,&d.io_request_3_bits_checkpoint_generation,&d.io_request_4_bits_checkpoint_generation,&d.io_request_5_bits_checkpoint_generation};
IData* agen[]={&d.io_response_0_bits_command_checkpoint_generation,&d.io_response_1_bits_command_checkpoint_generation,&d.io_response_2_bits_command_checkpoint_generation,&d.io_response_3_bits_command_checkpoint_generation,&d.io_response_4_bits_command_checkpoint_generation,&d.io_response_5_bits_command_checkpoint_generation};
QData* qpc[]={&d.io_request_0_bits_checkpoint_restartPc,&d.io_request_1_bits_checkpoint_restartPc,&d.io_request_2_bits_checkpoint_restartPc,&d.io_request_3_bits_checkpoint_restartPc,&d.io_request_4_bits_checkpoint_restartPc,&d.io_request_5_bits_checkpoint_restartPc};
QData* apc[]={&d.io_response_0_bits_command_checkpoint_restartPc,&d.io_response_1_bits_command_checkpoint_restartPc,&d.io_response_2_bits_command_checkpoint_restartPc,&d.io_response_3_bits_command_checkpoint_restartPc,&d.io_response_4_bits_command_checkpoint_restartPc,&d.io_response_5_bits_command_checkpoint_restartPc};
QData* qar[]={&d.io_request_0_bits_checkpoint_architecturalToken,&d.io_request_1_bits_checkpoint_architecturalToken,&d.io_request_2_bits_checkpoint_architecturalToken,&d.io_request_3_bits_checkpoint_architecturalToken,&d.io_request_4_bits_checkpoint_architecturalToken,&d.io_request_5_bits_checkpoint_architecturalToken};
QData* aar[]={&d.io_response_0_bits_command_checkpoint_architecturalToken,&d.io_response_1_bits_command_checkpoint_architecturalToken,&d.io_response_2_bits_command_checkpoint_architecturalToken,&d.io_response_3_bits_command_checkpoint_architecturalToken,&d.io_response_4_bits_command_checkpoint_architecturalToken,&d.io_response_5_bits_command_checkpoint_architecturalToken};
QData* qmem[]={&d.io_request_0_bits_checkpoint_memoryToken,&d.io_request_1_bits_checkpoint_memoryToken,&d.io_request_2_bits_checkpoint_memoryToken,&d.io_request_3_bits_checkpoint_memoryToken,&d.io_request_4_bits_checkpoint_memoryToken,&d.io_request_5_bits_checkpoint_memoryToken};
QData* amem[]={&d.io_response_0_bits_command_checkpoint_memoryToken,&d.io_response_1_bits_command_checkpoint_memoryToken,&d.io_response_2_bits_command_checkpoint_memoryToken,&d.io_response_3_bits_command_checkpoint_memoryToken,&d.io_response_4_bits_command_checkpoint_memoryToken,&d.io_response_5_bits_command_checkpoint_memoryToken};
IData* qfail[]={&d.io_request_0_bits_failedSequence,&d.io_request_1_bits_failedSequence,&d.io_request_2_bits_failedSequence,&d.io_request_3_bits_failedSequence,&d.io_request_4_bits_failedSequence,&d.io_request_5_bits_failedSequence};
IData* afail[]={&d.io_response_0_bits_command_failedSequence,&d.io_response_1_bits_command_failedSequence,&d.io_response_2_bits_command_failedSequence,&d.io_response_3_bits_command_failedSequence,&d.io_response_4_bits_command_failedSequence,&d.io_response_5_bits_command_failedSequence};
IData* qnew[]={&d.io_request_0_bits_recoveryGeneration,&d.io_request_1_bits_recoveryGeneration,&d.io_request_2_bits_recoveryGeneration,&d.io_request_3_bits_recoveryGeneration,&d.io_request_4_bits_recoveryGeneration,&d.io_request_5_bits_recoveryGeneration};
IData* anew[]={&d.io_response_0_bits_command_recoveryGeneration,&d.io_response_1_bits_command_recoveryGeneration,&d.io_response_2_bits_command_recoveryGeneration,&d.io_response_3_bits_command_recoveryGeneration,&d.io_response_4_bits_command_recoveryGeneration,&d.io_response_5_bits_command_recoveryGeneration};
QData* retpc[]={&d.io_response_0_bits_retiredPc,&d.io_response_1_bits_retiredPc,&d.io_response_2_bits_retiredPc,&d.io_response_3_bits_retiredPc,&d.io_response_4_bits_retiredPc,&d.io_response_5_bits_retiredPc};
CData* drain[]={&d.io_response_0_bits_allCheckerTasksDrained,&d.io_response_1_bits_allCheckerTasksDrained,&d.io_response_2_bits_allCheckerTasksDrained,&d.io_response_3_bits_allCheckerTasksDrained,&d.io_response_4_bits_allCheckerTasksDrained,&d.io_response_5_bits_allCheckerTasksDrained};
CData* ev[]={&d.io_events_0_valid,&d.io_events_1_valid,&d.io_events_2_valid,&d.io_events_3_valid,&d.io_events_4_valid,&d.io_events_5_valid,&d.io_events_6_valid,&d.io_events_7_valid};
CData* ek[]={&d.io_events_0_bits_kind,&d.io_events_1_bits_kind,&d.io_events_2_bits_kind,&d.io_events_3_bits_kind,&d.io_events_4_bits_kind,&d.io_events_5_bits_kind,&d.io_events_6_bits_kind,&d.io_events_7_bits_kind};
QData* es[]={&d.io_events_0_bits_recordSequence,&d.io_events_1_bits_recordSequence,&d.io_events_2_bits_recordSequence,&d.io_events_3_bits_recordSequence,&d.io_events_4_bits_recordSequence,&d.io_events_5_bits_recordSequence,&d.io_events_6_bits_recordSequence,&d.io_events_7_bits_recordSequence};
QData* et[]={&d.io_events_0_bits_targetCycle,&d.io_events_1_bits_targetCycle,&d.io_events_2_bits_targetCycle,&d.io_events_3_bits_targetCycle,&d.io_events_4_bits_targetCycle,&d.io_events_5_bits_targetCycle,&d.io_events_6_bits_targetCycle,&d.io_events_7_bits_targetCycle};

void evaluate(){d.clock=0;d.io_targetCycle=cycle;d.eval();}
void tick(){
  evaluate();
  if(!d.reset) for(unsigned i=0;i<8;++i) if(*ev[i]){
    CHECK(*ek[i]==i);CHECK(*es[i]==records);CHECK(*et[i]==cycle);
    if(i==6)CHECK(d.io_events_6_bits_retiredPc==0x1000);
    if(i==7)CHECK(d.io_events_7_bits_allCheckerTasksDrained);
    kinds.push_back(i);++records;
  }
  d.clock=1;d.eval();d.clock=0;d.eval();++cycle;
}
void initialize(){
  d.io_failure_valid=0;d.io_checkpoint_valid=0;
  for(unsigned p=0;p<6;++p){*ready[p]=0;*ack[p]=0;*drain[p]=0;*retpc[p]=0;}
  d.reset=1;tick();tick();d.reset=0;records=0;kinds.clear();tick();
  CHECK(d.io_phase==0);CHECK(!d.io_protocolError);
}
void prepare(){
  d.io_checkpoint_valid=1;d.io_checkpoint_bits_sequence=10;
  d.io_checkpoint_bits_generation=7;d.io_checkpoint_bits_restartPc=0x1000;
  d.io_checkpoint_bits_architecturalToken=0xabcdef0123456789ULL;
  d.io_checkpoint_bits_memoryToken=0xfedcba9876543210ULL;
  d.io_failure_bits_sequence=12;d.io_failure_bits_generation=7;
  d.io_failure_bits_allocated=1;d.io_failure_bits_comparedMismatch=1;
}
void begin(){
  prepare();d.io_failure_valid=1;evaluate();CHECK(d.io_freezeRetirement);
  tick();d.io_failure_valid=0;evaluate();CHECK(d.io_phase==1);CHECK(records==2);
  // Later checkpoint/PASS inputs cannot overwrite the selected safe checkpoint.
  d.io_checkpoint_bits_sequence=999;d.io_checkpoint_bits_generation=123;
  d.io_checkpoint_bits_restartPc=0xdead;
}
void command(unsigned p){
  CHECK(*qseq[p]==10);CHECK(*qgen[p]==7);CHECK(*qnew[p]==8);CHECK(*qfail[p]==12);
  CHECK(*qpc[p]==0x1000);CHECK(*qar[p]==0xabcdef0123456789ULL);
  CHECK(*qmem[p]==0xfedcba9876543210ULL);
}
void acknowledge(unsigned p){
  *aseq[p]=10;*agen[p]=7;*anew[p]=8;*afail[p]=12;*apc[p]=0x1000;
  *aar[p]=0xabcdef0123456789ULL;*amem[p]=0xfedcba9876543210ULL;
  *retpc[p]=0x1000;*drain[p]=1;*ack[p]=1;
}
void send(unsigned p,unsigned delay=3){
  evaluate();CHECK(d.io_phase==p+1);CHECK(*rq[p]);command(p);
  auto before=records;
  for(unsigned k=0;k<delay;++k){CHECK(*rq[p]);command(p);tick();CHECK(records==before);}
  *ready[p]=1;tick();*ready[p]=0;evaluate();
  CHECK(d.io_phase==p+1);CHECK(!*rq[p]);CHECK(records==before);
  for(unsigned k=0;k<2;++k){tick();CHECK(records==before);}
}
void complete(unsigned p,unsigned delay=3){
  send(p,delay);acknowledge(p);tick();*ack[p]=0;evaluate();
  CHECK(records==p+3);CHECK(d.io_phase==(p==5?0:p+2));
}
void error(){
  evaluate();CHECK(d.io_protocolError);CHECK(d.io_freezeRetirement);CHECK(d.io_freezeNewPackages);
  auto before=records;
  for(unsigned p=0;p<6;++p){*ack[p]=0;CHECK(!*rq[p]);}
  for(unsigned k=0;k<3;++k){tick();CHECK(d.io_protocolError);CHECK(records==before);}
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);
  for(unsigned run=0;run<64;++run){
    initialize();begin();
    for(unsigned p=0;p<6;++p)complete(p,(run*7+p*3)%9);
    CHECK(records==8);for(unsigned i=0;i<8;++i)CHECK(kinds[i]==i);
    CHECK(!d.io_active);CHECK(!d.io_freezeRetirement);
  }
  // Neither a FAIL marker without a real comparison nor stale allocation passes.
  for(unsigned scenario=0;scenario<5;++scenario){
    initialize();prepare();
    if(scenario==0)d.io_failure_bits_comparedMismatch=0;
    if(scenario==1)d.io_failure_bits_allocated=0;
    if(scenario==2)d.io_failure_bits_generation=6;
    if(scenario==3)d.io_failure_bits_sequence=10;
    if(scenario==4){d.io_failure_bits_generation=0xffffffff;d.io_checkpoint_bits_generation=0xffffffff;}
    d.io_failure_valid=1;tick();d.io_failure_valid=0;error();CHECK(records==0);
  }
  initialize();begin();send(0);acknowledge(0);*anew[0]=9;tick();*ack[0]=0;error();CHECK(records==2);
  initialize();begin();acknowledge(2);tick();*ack[2]=0;error();CHECK(records==2);
  initialize();begin();acknowledge(0);tick();*ack[0]=0;error();CHECK(records==2);
  initialize();begin();for(unsigned p=0;p<4;++p)complete(p);
  send(4);acknowledge(4);*retpc[4]=0x1004;evaluate();CHECK(d.io_freezeRetirement);
  tick();*ack[4]=0;error();CHECK(records==6);
  initialize();begin();for(unsigned p=0;p<5;++p)complete(p);
  send(5);acknowledge(5);*drain[5]=0;evaluate();CHECK(d.io_freezeRetirement);
  tick();*ack[5]=0;error();CHECK(records==7);
  std::puts("RECOVERY_CONTROL_COMPONENT_PASS positive_transactions=64 negative_cases=10 accepted_command_is_not_completion=1 frozen_checkpoint_tokens=1 real_response_event_order=1 not_architectural_recovery=1");
  d.final();return 0;
}

