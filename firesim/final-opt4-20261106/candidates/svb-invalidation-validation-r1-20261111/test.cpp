#include "VSVBModuleHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static unsigned cycle=0;
static void check(bool value,const char*what){if(!value){fprintf(stderr,"SVB_FAIL cycle=%u %s\n",cycle,what);exit(1);}}
static void tick(VSVBModuleHarness&d){d.clock=0;d.io_diagnosticCycle=cycle;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();cycle++;}
static void capture(VSVBModuleHarness&d,unsigned seq,unsigned line,unsigned gen){
d.io_capture_valid=1;d.io_capture_bits_line=line;d.io_capture_bits_key_valid=1;d.io_capture_bits_key_writer=1;d.io_capture_bits_key_contentSeq=seq;d.io_capture_bits_key_generation=gen;d.io_capture_bits_epoch=1;d.io_capture_bits_param=1;
for(unsigned i=0;i<4;i++){d.io_capture_bits_data_0[i]=seq*100+i;d.io_capture_bits_data_1[i]=seq*100+i+4;d.io_capture_bits_data_2[i]=seq*100+i+8;d.io_capture_bits_data_3[i]=seq*100+i+12;}
d.eval();check(d.io_capture_ready,"capture ready");tick(d);d.io_capture_valid=0;d.eval();}
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);VSVBModuleHarness dut;
dut.clock=0;
dut.reset=0;
dut.io_capture_valid=0;
dut.io_capture_bits_line=0;
dut.io_capture_bits_key_valid=0;
dut.io_capture_bits_key_writer=0;
dut.io_capture_bits_key_generation=0;
dut.io_capture_bits_key_contentSeq=0;
dut.io_capture_bits_epoch=0;
dut.io_capture_bits_param=0;
dut.io_capture_bits_data_0[0]=0;
dut.io_capture_bits_data_0[1]=0;
dut.io_capture_bits_data_0[2]=0;
dut.io_capture_bits_data_0[3]=0;
dut.io_capture_bits_data_1[0]=0;
dut.io_capture_bits_data_1[1]=0;
dut.io_capture_bits_data_1[2]=0;
dut.io_capture_bits_data_1[3]=0;
dut.io_capture_bits_data_2[0]=0;
dut.io_capture_bits_data_2[1]=0;
dut.io_capture_bits_data_2[2]=0;
dut.io_capture_bits_data_2[3]=0;
dut.io_capture_bits_data_3[0]=0;
dut.io_capture_bits_data_3[1]=0;
dut.io_capture_bits_data_3[2]=0;
dut.io_capture_bits_data_3[3]=0;
dut.io_safeWatermark=0;
dut.io_currentEpoch=0;
dut.io_diagnosticDump=0;
dut.io_diagnosticCycle=0;
dut.io_resetStats=0;
dut.io_countStats=0;
dut.io_invalidate_valid=0;
dut.io_invalidate_bits=0;
dut.io_flush=0;
dut.io_promote_ready=0;
dut.io_releaseLines_0=0;
dut.io_releaseLines_1=0;
dut.io_releaseLines_2=0;
dut.io_releaseLines_3=0;
dut.io_ack_valid=0;
dut.io_ack_bits_entry=0;
dut.io_ack_bits_key_valid=0;
dut.io_ack_bits_key_writer=0;
dut.io_ack_bits_key_generation=0;
dut.io_ack_bits_key_contentSeq=0;
 dut.reset=1;tick(dut);tick(dut);dut.reset=0;dut.io_flush=1;dut.io_resetStats=1;tick(dut);dut.io_resetStats=0;
 capture(dut,5,0x1000,1);capture(dut,7,0x1000,2);capture(dut,9,0x2000,3);check(dut.io_occupancy==3,"three immutable versions");
 dut.io_safeWatermark=7;dut.io_invalidate_valid=1;dut.io_invalidate_bits=7;dut.eval();check(dut.io_discarded==1,"only younger unsafe SPEC discarded");check(!dut.io_capture_ready,"no admission during invalidate");tick(dut);dut.io_invalidate_valid=0;dut.eval();check(dut.io_occupancy==1,"newer-safe coalescing and unsafe invalidation");
 dut.io_releaseLines_0=0x1000;dut.io_flush=0;dut.eval();check(dut.io_selected,"safe predecessor selected");tick(dut);check(dut.io_promote_valid,"promotion owner held");check(dut.io_promote_bits_key_contentSeq==7,"newest safe key");unsigned entry=dut.io_promote_bits_entry;
 for(unsigned i=0;i<4;i++)check(dut.io_promote_bits_data_0[i]==700+i,"captured data exact");
 for(unsigned i=0;i<3;i++){check(dut.io_promote_valid&&dut.io_promote_bits_entry==entry,"stable backpressured owner");tick(dut);}
 dut.io_invalidate_valid=1;dut.io_invalidate_bits=0;tick(dut);dut.io_invalidate_valid=0;check(dut.io_occupancy==1&&dut.io_promote_valid,"WB_WAIT retained even across explicit invalidate");
 dut.io_promote_ready=1;tick(dut);dut.io_promote_ready=0;check(!dut.io_promote_valid&&dut.io_occupancy==1,"C completion does not release owner");check(dut.io_releaseBlocked_0,"publication blocked until exact ACK");
 dut.io_ack_valid=1;dut.io_ack_bits_entry=entry;dut.io_ack_bits_key_valid=1;dut.io_ack_bits_key_writer=1;dut.io_ack_bits_key_generation=2;dut.io_ack_bits_key_contentSeq=7;dut.eval();check(dut.io_acked,"matching immutable completion accepted");tick(dut);dut.io_ack_valid=0;dut.eval();check(dut.io_occupancy==0&&!dut.io_releaseBlocked_0,"matched ACK releases owner");
 dut.io_flush=1;capture(dut,12,0x3000,4);dut.io_invalidate_valid=1;dut.io_invalidate_bits=7;tick(dut);dut.io_invalidate_valid=0;check(dut.io_occupancy==0,"unsafe captured version explicitly invalidated");
 puts("SVB_INVALIDATION_OWNER_DATA_LIFETIME_PASS actual_rtl=1 wb_retained=1 data_exact=1 explicit_fail_boundary=1 architectural_restart_validated=0");return 0;}
