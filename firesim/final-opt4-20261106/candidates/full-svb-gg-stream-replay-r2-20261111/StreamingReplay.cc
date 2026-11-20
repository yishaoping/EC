
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
{"reset",7,1,1,true},
{"io_capture_ready",8,1,1,false},
{"io_capture_valid",9,1,1,true},
{"io_capture_bits_line",10,2,40,true},
{"io_capture_bits_key_valid",12,1,1,true},
{"io_capture_bits_key_writer",13,1,16,true},
{"io_capture_bits_key_generation",14,1,32,true},
{"io_capture_bits_key_contentSeq",15,1,32,true},
{"io_capture_bits_epoch",16,1,16,true},
{"io_capture_bits_param",17,1,3,true},
{"io_capture_bits_data_0",18,4,128,true},
{"io_capture_bits_data_1",22,4,128,true},
{"io_capture_bits_data_2",26,4,128,true},
{"io_capture_bits_data_3",30,4,128,true},
{"io_safeWatermark",34,1,32,true},
{"io_diagnosticDump",35,1,1,true},
{"io_diagnosticCycle",36,2,64,true},
{"io_invalidate_valid",38,1,1,true},
{"io_invalidate_bits",39,1,32,true},
{"io_flush",40,1,1,true},
{"io_promote_ready",41,1,1,true},
{"io_promote_valid",42,1,1,false},
{"io_promote_bits_line",43,2,40,false},
{"io_promote_bits_key_valid",45,1,1,false},
{"io_promote_bits_key_writer",46,1,16,false},
{"io_promote_bits_key_generation",47,1,32,false},
{"io_promote_bits_key_contentSeq",48,1,32,false},
{"io_promote_bits_epoch",49,1,16,false},
{"io_promote_bits_param",50,1,3,false},
{"io_promote_bits_data_0",51,4,128,false},
{"io_promote_bits_data_1",55,4,128,false},
{"io_promote_bits_data_2",59,4,128,false},
{"io_promote_bits_data_3",63,4,128,false},
{"io_promote_bits_entry",67,1,5,false},
{"io_selected",68,1,1,false},
{"io_activeEntry",69,1,5,false},
{"io_activeLine",70,2,40,false},
{"io_activeKey_generation",72,1,32,false},
{"io_activeKey_contentSeq",73,1,32,false},
{"io_coalesced",74,1,6,false},
{"io_discarded",75,1,6,false},
{"io_releaseLines_0",76,2,40,true},
{"io_releaseLines_1",78,2,40,true},
{"io_releaseLines_2",80,2,40,true},
{"io_releaseLines_3",82,2,40,true},
{"io_releaseBlocked_0",84,1,1,false},
{"io_releaseBlocked_1",85,1,1,false},
{"io_releaseBlocked_2",86,1,1,false},
{"io_releaseBlocked_3",87,1,1,false},
{"io_releaseBlockingEntry_3",88,1,5,false},
{"io_releaseBlockingLine_3",89,2,40,false},
{"io_releaseBlockingSeq_3",91,1,32,false},
{"io_releaseBlockingGeneration_3",92,1,32,false},
{"io_ack_valid",93,1,1,true},
{"io_ack_bits_entry",94,1,5,true},
{"io_ack_bits_key_valid",95,1,1,true},
{"io_ack_bits_key_writer",96,1,16,true},
{"io_ack_bits_key_generation",97,1,32,true},
{"io_ack_bits_key_contentSeq",98,1,32,true},
{"io_occupancy",99,1,6,false},
{"io_acked",100,1,1,false},
};
static uint64_t number(const Row&r,unsigned o,unsigned c=1){uint64_t v=0;for(unsigned j=0;j<c;++j)v|=uint64_t(r[o+j])<<(32*j);return v;}
class StreamingReplay final:public TestHarness {
 std::string trace,status_path;bool negative=false,mutated=false,cache_inputs=true; Row previous{}; uint64_t input_word_writes=0;
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
  for(const auto&s:a){if(s.starts_with("+svb-trace="))trace=s.substr(11);if(s.starts_with("+svb-state="))status_path=s.substr(11);if(s=="+svb-mutate-data")negative=true;if(s=="+svb-force-all-inputs")cache_inputs=false;}
  if(trace.empty())throw std::runtime_error("missing +svb-trace");
 }
 void run_test()override{
  log=false;start=std::chrono::steady_clock::now();
  std::ifstream f(trace,std::ios::binary);char magic[16],want[16]{};memcpy(want,"ECSVBFULLBINv1",14);
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
    if(p.input){bool changed=!cache_inputs||rows==0;for(unsigned j=0;j<p.count;++j)changed|=row[p.offset+j]!=previous[p.offset+j];if(changed){mpz_import(value,p.count,-1,4,0,0,row.data()+p.offset);poke(p.name,value);stable();input_word_writes+=p.count;}}}
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
   previous=row;step(1);stable();if(row[7]){known_reset=true;++resets;}++rows;
   if((rows&4095)==0){snapshot("RUNNING");std::cout<<"SVB_GG_STREAM_PROGRESS records="<<rows<<" source_tick="<<tick<<"\n"<<std::flush;}
  }
  if(!known_reset)throw std::runtime_error("trace has no reset start");
  if(negative){expect(false,"negative mutation was not applied or rejected");snapshot("REJECTED_MISSING_NEGATIVE");}
  else snapshot("PASS_COMPLETE_BINARY_TRACE");
  std::cout<<"SVB_GG_STREAM_SUMMARY records="<<rows<<" first_source_tick="<<first_tick<<" last_source_tick="<<last_tick<<" target_cycles="<<cycles()<<" reset_edges="<<resets<<" defined_output_fields="<<checks<<" defined_output_word_checks="<<words<<" input_word_writes="<<input_word_writes<<" input_cache_enabled="<<cache_inputs<<" mismatches="<<errors<<" capture_accepted="<<captures<<" promote_accepted="<<promotions<<" acked="<<acks<<" mutation_applied="<<mutated<<" host_wall_seconds="<<std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count()<<"\n";
  mpz_clear(value);mpz_clear(actual);
 }
};TEST_MAIN(StreamingReplay)
