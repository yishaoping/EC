
#include "VSpeculativeVersionBuffer.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdexcept>
using Row=std::array<uint32_t,101>;
static uint64_t get(const Row& row,unsigned offset,unsigned count) {
 uint64_t v=0;for(unsigned j=0;j<count;++j)v|=uint64_t(row[offset+j])<<(32*j);return v;
}
static void drive(VSpeculativeVersionBuffer& d,const Row& row) {
 d.reset=get(row,7,1);
 d.io_capture_valid=get(row,9,1);
 d.io_capture_bits_line=get(row,10,2);
 d.io_capture_bits_key_valid=get(row,12,1);
 d.io_capture_bits_key_writer=get(row,13,1);
 d.io_capture_bits_key_generation=get(row,14,1);
 d.io_capture_bits_key_contentSeq=get(row,15,1);
 d.io_capture_bits_epoch=get(row,16,1);
 d.io_capture_bits_param=get(row,17,1);
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_0[j]=row[18+j];
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_1[j]=row[22+j];
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_2[j]=row[26+j];
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_3[j]=row[30+j];
 d.io_safeWatermark=get(row,34,1);
 d.io_diagnosticDump=get(row,35,1);
 d.io_diagnosticCycle=get(row,36,2);
 d.io_invalidate_valid=get(row,38,1);
 d.io_invalidate_bits=get(row,39,1);
 d.io_flush=get(row,40,1);
 d.io_promote_ready=get(row,41,1);
 d.io_releaseLines_0=get(row,76,2);
 d.io_releaseLines_1=get(row,78,2);
 d.io_releaseLines_2=get(row,80,2);
 d.io_releaseLines_3=get(row,82,2);
 d.io_ack_valid=get(row,93,1);
 d.io_ack_bits_entry=get(row,94,1);
 d.io_ack_bits_key_valid=get(row,95,1);
 d.io_ack_bits_key_writer=get(row,96,1);
 d.io_ack_bits_key_generation=get(row,97,1);
 d.io_ack_bits_key_contentSeq=get(row,98,1);
 d.io_resetStats=0;d.io_countStats=0;
}
struct Compare {
 uint64_t fields=0,errors=0,tick=0;
 void check(const char* name,uint32_t expected,uint32_t actual) {
  ++fields;if(expected!=actual){++errors;if(errors<=8)fprintf(stderr,"MISMATCH tick=%llu port=%s expected=%08x actual=%08x\n",(unsigned long long)tick,name,expected,actual);}
 }
 void outputs(VSpeculativeVersionBuffer& d,const Row& row,bool known_reset) {
 if(known_reset)check("io_capture_ready[0]",row[8],uint32_t((uint64_t(d.io_capture_ready)>>0)));
 if(known_reset)check("io_promote_valid[0]",row[42],uint32_t((uint64_t(d.io_promote_valid)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_line[0]",row[43],uint32_t((uint64_t(d.io_promote_bits_line)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_line[1]",row[44],uint32_t((uint64_t(d.io_promote_bits_line)>>32)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_key_valid[0]",row[45],uint32_t((uint64_t(d.io_promote_bits_key_valid)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_key_writer[0]",row[46],uint32_t((uint64_t(d.io_promote_bits_key_writer)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_key_generation[0]",row[47],uint32_t((uint64_t(d.io_promote_bits_key_generation)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_key_contentSeq[0]",row[48],uint32_t((uint64_t(d.io_promote_bits_key_contentSeq)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_epoch[0]",row[49],uint32_t((uint64_t(d.io_promote_bits_epoch)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_param[0]",row[50],uint32_t((uint64_t(d.io_promote_bits_param)>>0)));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_0[0]",row[51],uint32_t(d.io_promote_bits_data_0[0]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_0[1]",row[52],uint32_t(d.io_promote_bits_data_0[1]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_0[2]",row[53],uint32_t(d.io_promote_bits_data_0[2]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_0[3]",row[54],uint32_t(d.io_promote_bits_data_0[3]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_1[0]",row[55],uint32_t(d.io_promote_bits_data_1[0]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_1[1]",row[56],uint32_t(d.io_promote_bits_data_1[1]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_1[2]",row[57],uint32_t(d.io_promote_bits_data_1[2]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_1[3]",row[58],uint32_t(d.io_promote_bits_data_1[3]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_2[0]",row[59],uint32_t(d.io_promote_bits_data_2[0]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_2[1]",row[60],uint32_t(d.io_promote_bits_data_2[1]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_2[2]",row[61],uint32_t(d.io_promote_bits_data_2[2]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_2[3]",row[62],uint32_t(d.io_promote_bits_data_2[3]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_3[0]",row[63],uint32_t(d.io_promote_bits_data_3[0]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_3[1]",row[64],uint32_t(d.io_promote_bits_data_3[1]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_3[2]",row[65],uint32_t(d.io_promote_bits_data_3[2]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_data_3[3]",row[66],uint32_t(d.io_promote_bits_data_3[3]));
 if(known_reset&&d.io_promote_valid)check("io_promote_bits_entry[0]",row[67],uint32_t((uint64_t(d.io_promote_bits_entry)>>0)));
 if(known_reset)check("io_selected[0]",row[68],uint32_t((uint64_t(d.io_selected)>>0)));
 if(known_reset&&(d.io_selected||d.io_promote_valid||d.io_ack_valid))check("io_activeEntry[0]",row[69],uint32_t((uint64_t(d.io_activeEntry)>>0)));
 if(known_reset&&(d.io_selected||d.io_promote_valid||d.io_ack_valid))check("io_activeLine[0]",row[70],uint32_t((uint64_t(d.io_activeLine)>>0)));
 if(known_reset&&(d.io_selected||d.io_promote_valid||d.io_ack_valid))check("io_activeLine[1]",row[71],uint32_t((uint64_t(d.io_activeLine)>>32)));
 if(known_reset&&(d.io_selected||d.io_promote_valid||d.io_ack_valid))check("io_activeKey_generation[0]",row[72],uint32_t((uint64_t(d.io_activeKey_generation)>>0)));
 if(known_reset&&(d.io_selected||d.io_promote_valid||d.io_ack_valid))check("io_activeKey_contentSeq[0]",row[73],uint32_t((uint64_t(d.io_activeKey_contentSeq)>>0)));
 if(known_reset)check("io_coalesced[0]",row[74],uint32_t((uint64_t(d.io_coalesced)>>0)));
 if(known_reset)check("io_discarded[0]",row[75],uint32_t((uint64_t(d.io_discarded)>>0)));
 if(known_reset)check("io_releaseBlocked_0[0]",row[84],uint32_t((uint64_t(d.io_releaseBlocked_0)>>0)));
 if(known_reset)check("io_releaseBlocked_1[0]",row[85],uint32_t((uint64_t(d.io_releaseBlocked_1)>>0)));
 if(known_reset)check("io_releaseBlocked_2[0]",row[86],uint32_t((uint64_t(d.io_releaseBlocked_2)>>0)));
 if(known_reset)check("io_releaseBlocked_3[0]",row[87],uint32_t((uint64_t(d.io_releaseBlocked_3)>>0)));
 if(known_reset&&d.io_releaseBlocked_3)check("io_releaseBlockingEntry_3[0]",row[88],uint32_t((uint64_t(d.io_releaseBlockingEntry_3)>>0)));
 if(known_reset&&d.io_releaseBlocked_3)check("io_releaseBlockingLine_3[0]",row[89],uint32_t((uint64_t(d.io_releaseBlockingLine_3)>>0)));
 if(known_reset&&d.io_releaseBlocked_3)check("io_releaseBlockingLine_3[1]",row[90],uint32_t((uint64_t(d.io_releaseBlockingLine_3)>>32)));
 if(known_reset&&d.io_releaseBlocked_3)check("io_releaseBlockingSeq_3[0]",row[91],uint32_t((uint64_t(d.io_releaseBlockingSeq_3)>>0)));
 if(known_reset&&d.io_releaseBlocked_3)check("io_releaseBlockingGeneration_3[0]",row[92],uint32_t((uint64_t(d.io_releaseBlockingGeneration_3)>>0)));
 if(known_reset)check("io_occupancy[0]",row[99],uint32_t((uint64_t(d.io_occupancy)>>0)));
 if(known_reset)check("io_acked[0]",row[100],uint32_t((uint64_t(d.io_acked)>>0)));
 }
};
static void step(VSpeculativeVersionBuffer& d) {d.clock=1;d.eval();d.clock=0;d.eval();}
int main(int argc,char**argv) {
 Verilated::commandArgs(argc,argv);
 VSpeculativeVersionBuffer d;
 d.clock=0;
 d.reset=0;
 d.io_capture_valid=0;
 d.io_capture_bits_line=0;
 d.io_capture_bits_key_valid=0;
 d.io_capture_bits_key_writer=0;
 d.io_capture_bits_key_generation=0;
 d.io_capture_bits_key_contentSeq=0;
 d.io_capture_bits_epoch=0;
 d.io_capture_bits_param=0;
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_0[j]=0;
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_1[j]=0;
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_2[j]=0;
 for(unsigned j=0;j<4;++j)d.io_capture_bits_data_3[j]=0;
 d.io_safeWatermark=0;
 d.io_diagnosticDump=0;
 d.io_diagnosticCycle=0;
 d.io_invalidate_valid=0;
 d.io_invalidate_bits=0;
 d.io_flush=0;
 d.io_promote_ready=0;
 d.io_releaseLines_0=0;
 d.io_releaseLines_1=0;
 d.io_releaseLines_2=0;
 d.io_releaseLines_3=0;
 d.io_ack_valid=0;
 d.io_ack_bits_entry=0;
 d.io_ack_bits_key_valid=0;
 d.io_ack_bits_key_writer=0;
 d.io_ack_bits_key_generation=0;
 d.io_ack_bits_key_contentSeq=0;
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
 row[8]=uint32_t((uint64_t(d.io_capture_ready)>>0));
 row[42]=uint32_t((uint64_t(d.io_promote_valid)>>0));
 row[43]=uint32_t((uint64_t(d.io_promote_bits_line)>>0));
 row[44]=uint32_t((uint64_t(d.io_promote_bits_line)>>32));
 row[45]=uint32_t((uint64_t(d.io_promote_bits_key_valid)>>0));
 row[46]=uint32_t((uint64_t(d.io_promote_bits_key_writer)>>0));
 row[47]=uint32_t((uint64_t(d.io_promote_bits_key_generation)>>0));
 row[48]=uint32_t((uint64_t(d.io_promote_bits_key_contentSeq)>>0));
 row[49]=uint32_t((uint64_t(d.io_promote_bits_epoch)>>0));
 row[50]=uint32_t((uint64_t(d.io_promote_bits_param)>>0));
 row[51]=uint32_t(d.io_promote_bits_data_0[0]);
 row[52]=uint32_t(d.io_promote_bits_data_0[1]);
 row[53]=uint32_t(d.io_promote_bits_data_0[2]);
 row[54]=uint32_t(d.io_promote_bits_data_0[3]);
 row[55]=uint32_t(d.io_promote_bits_data_1[0]);
 row[56]=uint32_t(d.io_promote_bits_data_1[1]);
 row[57]=uint32_t(d.io_promote_bits_data_1[2]);
 row[58]=uint32_t(d.io_promote_bits_data_1[3]);
 row[59]=uint32_t(d.io_promote_bits_data_2[0]);
 row[60]=uint32_t(d.io_promote_bits_data_2[1]);
 row[61]=uint32_t(d.io_promote_bits_data_2[2]);
 row[62]=uint32_t(d.io_promote_bits_data_2[3]);
 row[63]=uint32_t(d.io_promote_bits_data_3[0]);
 row[64]=uint32_t(d.io_promote_bits_data_3[1]);
 row[65]=uint32_t(d.io_promote_bits_data_3[2]);
 row[66]=uint32_t(d.io_promote_bits_data_3[3]);
 row[67]=uint32_t((uint64_t(d.io_promote_bits_entry)>>0));
 row[68]=uint32_t((uint64_t(d.io_selected)>>0));
 row[69]=uint32_t((uint64_t(d.io_activeEntry)>>0));
 row[70]=uint32_t((uint64_t(d.io_activeLine)>>0));
 row[71]=uint32_t((uint64_t(d.io_activeLine)>>32));
 row[72]=uint32_t((uint64_t(d.io_activeKey_generation)>>0));
 row[73]=uint32_t((uint64_t(d.io_activeKey_contentSeq)>>0));
 row[74]=uint32_t((uint64_t(d.io_coalesced)>>0));
 row[75]=uint32_t((uint64_t(d.io_discarded)>>0));
 row[84]=uint32_t((uint64_t(d.io_releaseBlocked_0)>>0));
 row[85]=uint32_t((uint64_t(d.io_releaseBlocked_1)>>0));
 row[86]=uint32_t((uint64_t(d.io_releaseBlocked_2)>>0));
 row[87]=uint32_t((uint64_t(d.io_releaseBlocked_3)>>0));
 row[88]=uint32_t((uint64_t(d.io_releaseBlockingEntry_3)>>0));
 row[89]=uint32_t((uint64_t(d.io_releaseBlockingLine_3)>>0));
 row[90]=uint32_t((uint64_t(d.io_releaseBlockingLine_3)>>32));
 row[91]=uint32_t((uint64_t(d.io_releaseBlockingSeq_3)>>0));
 row[92]=uint32_t((uint64_t(d.io_releaseBlockingGeneration_3)>>0));
 row[99]=uint32_t((uint64_t(d.io_occupancy)>>0));
 row[100]=uint32_t((uint64_t(d.io_acked)>>0));
  Compare equal;equal.tick=0;equal.outputs(d,row,true);if(equal.errors)return 22;
  row[51]^=1;
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
  if(mutate&&!mutated&&d.io_promote_valid){row[51]^=1;mutated=true;}
  c.tick=tick;c.outputs(d,row,known_reset);
  step(d);if(d.reset){known_reset=true;++reset_edges;}
  ++cycles;
 }
 fclose(input);d.final();
 printf("REPLAY_SUMMARY cycles=%llu first_tick=%llu last_tick=%llu reset_edges=%llu defined_output_word_checks=%llu mismatches=%llu mutation_applied=%u\n",(unsigned long long)cycles,(unsigned long long)first,(unsigned long long)last,(unsigned long long)reset_edges,(unsigned long long)c.fields,(unsigned long long)c.errors,unsigned(mutated));
 if(mutate)return mutated&&c.errors>0?0:7;
 return c.errors?8:0;
}
