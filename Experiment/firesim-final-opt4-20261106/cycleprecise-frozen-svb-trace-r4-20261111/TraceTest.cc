
#include "TestHarness.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
class TraceTest final:public TestHarness {
bool negative=false;
public:TraceTest(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n){for(auto&s:a)if(s=="+negative")negative=true;}
void run_test()override{log=false;
std::ifstream f("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-trace-r4-20261111/target-cycles.txt");std::string text;mpz_t value,got;mpz_init(value);mpz_init(got);
uint64_t checks=0;unsigned rows=0;
const char* inputs[]={"reset","io_capture_valid","io_capture_bits_line","io_capture_bits_key_valid","io_capture_bits_key_writer","io_capture_bits_key_generation","io_capture_bits_key_contentSeq","io_capture_bits_epoch","io_capture_bits_param","io_capture_bits_data_0","io_capture_bits_data_1","io_capture_bits_data_2","io_capture_bits_data_3","io_safeWatermark","io_currentEpoch","io_diagnosticDump","io_diagnosticCycle","io_resetStats","io_countStats","io_invalidate_valid","io_invalidate_bits","io_flush","io_promote_ready","io_releaseLines_0","io_releaseLines_1","io_releaseLines_2","io_releaseLines_3","io_ack_valid","io_ack_bits_entry","io_ack_bits_key_valid","io_ack_bits_key_writer","io_ack_bits_key_generation","io_ack_bits_key_contentSeq"};const char* outputs[]={"io_capture_ready","io_promote_valid","io_promote_bits_line","io_promote_bits_key_valid","io_promote_bits_key_writer","io_promote_bits_key_generation","io_promote_bits_key_contentSeq","io_promote_bits_epoch","io_promote_bits_param","io_promote_bits_data_0","io_promote_bits_data_1","io_promote_bits_data_2","io_promote_bits_data_3","io_promote_bits_entry","io_selected","io_activeEntry","io_activeLine","io_activeKey_valid","io_activeKey_writer","io_activeKey_generation","io_activeKey_contentSeq","io_activeEpoch","io_queued","io_coalesced","io_discarded","io_releaseBlocked_0","io_releaseBlocked_1","io_releaseBlocked_2","io_releaseBlocked_3","io_releaseBlockingEntry_0","io_releaseBlockingEntry_1","io_releaseBlockingEntry_2","io_releaseBlockingEntry_3","io_releaseBlockingLine_0","io_releaseBlockingLine_1","io_releaseBlockingLine_2","io_releaseBlockingLine_3","io_releaseBlockingSeq_0","io_releaseBlockingSeq_1","io_releaseBlockingSeq_2","io_releaseBlockingSeq_3","io_releaseBlockingGeneration_0","io_releaseBlockingGeneration_1","io_releaseBlockingGeneration_2","io_releaseBlockingGeneration_3","io_occupancy","io_maxOccupancy","io_maxDepth","io_depth","io_occupancyHistogram_0","io_occupancyHistogram_1","io_occupancyHistogram_2","io_occupancyHistogram_3","io_occupancyHistogram_4","io_occupancyHistogram_5","io_occupancyHistogram_6","io_occupancyHistogram_7","io_occupancyHistogram_8","io_occupancyHistogram_9","io_occupancyHistogram_10","io_occupancyHistogram_11","io_occupancyHistogram_12","io_occupancyHistogram_13","io_occupancyHistogram_14","io_occupancyHistogram_15","io_occupancyHistogram_16","io_occupancyHistogram_17","io_occupancyHistogram_18","io_occupancyHistogram_19","io_occupancyHistogram_20","io_occupancyHistogram_21","io_occupancyHistogram_22","io_occupancyHistogram_23","io_occupancyHistogram_24","io_occupancyHistogram_25","io_occupancyHistogram_26","io_occupancyHistogram_27","io_occupancyHistogram_28","io_occupancyHistogram_29","io_occupancyHistogram_30","io_occupancyHistogram_31","io_occupancyHistogram_32","io_depthHistogram_0","io_depthHistogram_1","io_depthHistogram_2","io_depthHistogram_3","io_depthHistogram_4","io_depthHistogram_5","io_depthHistogram_6","io_depthHistogram_7","io_depthHistogram_8","io_depthHistogram_9","io_depthHistogram_10","io_depthHistogram_11","io_depthHistogram_12","io_depthHistogram_13","io_depthHistogram_14","io_depthHistogram_15","io_depthHistogram_16","io_depthHistogram_17","io_depthHistogram_18","io_depthHistogram_19","io_depthHistogram_20","io_depthHistogram_21","io_depthHistogram_22","io_depthHistogram_23","io_depthHistogram_24","io_depthHistogram_25","io_depthHistogram_26","io_depthHistogram_27","io_depthHistogram_28","io_depthHistogram_29","io_depthHistogram_30","io_depthHistogram_31","io_depthHistogram_32","io_observationSerial","io_allocation","io_allocatedEntry","io_entryAccounting_0","io_entryAccounting_1","io_entryAccounting_2","io_entryAccounting_3","io_entryAccounting_4","io_fullFallback","io_promotion","io_acked","io_recoveryFromSvb"};
while(f>>rows){
 for(auto n:inputs){f>>text;if(!f||mpz_set_str(value,text.c_str(),16))throw std::runtime_error("input trace corruption");poke(n,value);}
 // Synchronize all output tokens, not just the first MMIO data read.
 peek("io_occupancy");
 unsigned index=0;
 for(auto n:outputs){f>>text;if(!f||mpz_set_str(value,text.c_str(),16))throw std::runtime_error("output trace corruption");
  peek(n,got);
  if(rows>=39){
   if(negative&&rows==39+1&&index==0)mpz_combit(value,0);
   if(mpz_cmp(got,value)){std::cerr<<"TARGET_HOST_MISMATCH cycle="<<rows<<" port="<<n<<" expected="<<mpz_get_str(nullptr,16,value)<<" actual="<<mpz_get_str(nullptr,16,got)<<"\n";throw std::runtime_error("target boundary mismatch");}
   checks++;
  }index++;
 }
 step(1);
}
std::cout<<"PASS_SVB_TRACE target_cycles="<<cycles()<<" compared_fields="<<checks<<" compare_from="<<39<<"\n";
mpz_clear(value);mpz_clear(got);
}};TEST_MAIN(TraceTest)
