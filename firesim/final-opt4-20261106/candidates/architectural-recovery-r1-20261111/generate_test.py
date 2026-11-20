#!/usr/bin/python3
"""Generate directed, backpressure and negative tests for actual control RTL."""
from pathlib import Path
import sys

out = Path(sys.argv[1])
lines = ['#include "VPackageRecoveryController.h"', '#include "verilated.h"',
         '#include <cstdio>', '#include <cstdlib>', '#include <vector>',
         'VPackageRecoveryController d; unsigned long long cycle=0,records=0;',
         'std::vector<unsigned> kinds;',
         '#define CHECK(x) do { if(!(x)) { std::fprintf(stderr,"CONTROL_FAIL line=%d cycle=%llu phase=%u\\n",__LINE__,cycle,d.io_phase); std::exit(2); } } while(0)']
def array(ctype, name, ports):
    lines.append(f'{ctype}* {name}[]={{'+','.join('&d.'+p for p in ports)+'};')
for name, suffix in [('rq','valid'),('ready','ready')]:
    array('CData',name,[f'io_request_{i}_{suffix}' for i in range(6)])
array('CData','ack',[f'io_response_{i}_valid' for i in range(6)])
for name, suffix, ctype in [
    ('qseq','checkpoint_sequence','IData'),('qgen','checkpoint_generation','IData'),
    ('qpc','checkpoint_restartPc','QData'),('qar','checkpoint_architecturalToken','QData'),
    ('qmem','checkpoint_memoryToken','QData'),('qfail','failedSequence','IData'),
    ('qnew','recoveryGeneration','IData')]:
    array(ctype,name,[f'io_request_{i}_bits_{suffix}' for i in range(6)])
    array(ctype,'a'+name[1:],[f'io_response_{i}_bits_command_{suffix}' for i in range(6)])
array('QData','retpc',[f'io_response_{i}_bits_retiredPc' for i in range(6)])
array('CData','drain',[f'io_response_{i}_bits_allCheckerTasksDrained' for i in range(6)])
for name,suffix,ctype in [('ev','valid','CData'),('ek','bits_kind','CData'),
                         ('es','bits_recordSequence','QData'),('et','bits_targetCycle','QData')]:
    array(ctype,name,[f'io_events_{i}_{suffix}' for i in range(8)])
lines.append(r'''
void evaluate(){d.clock=0;d.io_targetCycle=cycle;d.eval();}
void tick(){
  evaluate();
  if(!d.reset) for(unsigned i=0;i<8;++i) if(*ev[i]){
    CHECK(*ek[i]==i);CHECK(*es[i]==records);CHECK(*et[i]==cycle);
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
''')
out.write_text('\n'.join(lines)+'\n')
