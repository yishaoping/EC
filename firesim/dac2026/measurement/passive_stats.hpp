#pragma once
// Host-side, in-process observer core for a FireSim bridge. No instruction/event
// printf, MMIO writes to the target, or target ready/valid gating in this class.
// Integration into a supported FireSim bridge remains a separately gated task.
#include <algorithm>
#include <cstdint>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

namespace ec_dac {
using tick_t = uint64_t;
inline void ensure(bool v, const char *s) { if (!v) throw std::runtime_error(s); }
inline uint64_t add_checked(uint64_t a, uint64_t b) {
  ensure(b <= std::numeric_limits<uint64_t>::max()-a, "counter overflow"); return a+b;
}
inline std::pair<uint64_t,uint64_t> bucket(uint64_t n) {
  if (n<256) return {n,n};
  unsigned power=0; for (uint64_t t=n;t>>=1;) ++power;
  uint64_t width=uint64_t(1)<<(power-4),lo=(n/width)*width;
  return {lo,lo+(width-1)};
}
struct Instruction { uint64_t epoch, serial, rob_index; };
using InstKey=std::tuple<uint64_t,uint64_t,uint64_t>;
inline InstKey key(Instruction i) { return {i.epoch,i.serial,i.rob_index}; }
struct Task {
  tick_t allocated=0, last_execution=0, compare_time=0;
  bool has_instruction=false, sealed=false, compared=false;
};
// Execution tracking is deliberately independent of commit time. A new monotonic
// dispatch serial disambiguates ROB wrap/reuse. Killed/replayed old generations
// cannot donate a timestamp to a later instruction at the same ROB index.
class ExecutionTracker {
  std::map<InstKey,tick_t> executions;
  std::set<InstKey> dispatched;
public:
  void dispatch(Instruction i) {
    ensure(dispatched.insert(key(i)).second,"duplicate dispatch identity");
  }
  void execution_complete(Instruction i,tick_t original_execution_time) {
    ensure(dispatched.count(key(i)),"execution of unknown instruction");
    executions[key(i)]=original_execution_time; // final successful replay replaces earlier attempt
  }
  void replay(Instruction i) {
    ensure(dispatched.count(key(i)),"replay of unknown instruction");
    executions.erase(key(i));
  }
  void kill(Instruction i) { executions.erase(key(i)); dispatched.erase(key(i)); }
  tick_t retire_survivor(Instruction i) {
    auto it=executions.find(key(i)); ensure(it!=executions.end(),"surviving instruction lacks execution timestamp");
    tick_t result=it->second; executions.erase(it); dispatched.erase(key(i)); return result;
  }
  bool empty() const { return dispatched.empty(); }
};
class PassiveStats {
  unsigned rockets;
  uint64_t epoch;
  tick_t start_time=0,end_time=0,drain_time=0;
  bool started=false,ended=false,drained_flag=false;
  std::map<uint64_t,Task> tasks;
  std::set<uint64_t> terminal_sequences;
  uint64_t generated=0,completed=0,sum=0,maximum=0;
  std::map<std::pair<uint64_t,uint64_t>,uint64_t> hist;
  uint64_t queue_sum=0,queue_max=0,full_ticks=0,blocked_ticks=0;
  std::vector<uint64_t> busy_roi,busy_drain;
  std::map<std::string,uint64_t> reasons;
  void join(uint64_t seq) {
    Task &t=tasks.at(seq);
    if (!t.sealed || !t.compared) return;
    // Allocation/membership may be observed at retirement after execution.
    ensure(t.last_execution<=t.compare_time,"timestamp/CDC order violation");
    uint64_t latency=t.compare_time-t.last_execution;
    auto b=bucket(latency); hist[b]=add_checked(hist[b],1);
    completed=add_checked(completed,1);sum=add_checked(sum,latency);maximum=std::max(maximum,latency);
    tasks.erase(seq);terminal_sequences.insert(seq);
  }
public:
  PassiveStats(unsigned n,uint64_t e):rockets(n),epoch(e),busy_roi(n,0),busy_drain(n,0) {}
  void begin(tick_t now,bool clean_package_boundary,uint64_t old_outstanding) {
    ensure(!started && clean_package_boundary && old_outstanding==0,"dirty ROI entry");
    started=true;start_time=now;
  }
  void allocate(uint64_t seq,tick_t now) {
    ensure(started && !ended && seq && !tasks.count(seq) && !terminal_sequences.count(seq),"bad package allocation");
    tasks[seq]=Task{};tasks[seq].allocated=now;generated=add_checked(generated,1);
  }
  void surviving_instruction(uint64_t seq,tick_t execution_time) {
    Task &t=tasks.at(seq);ensure(!t.sealed,"instruction after producer seal");
    t.has_instruction=true;t.last_execution=std::max(t.last_execution,execution_time);
  }
  void seal(uint64_t seq) {
    Task &t=tasks.at(seq);ensure(!t.sealed && t.has_instruction,"duplicate seal or missing empty-package boundary");
    t.sealed=true;join(seq);
  }
  void seal_empty(uint64_t seq,tick_t explicit_execution_boundary) {
    Task &t=tasks.at(seq);ensure(!t.sealed && !t.has_instruction,"not an empty package");
    t.last_execution=explicit_execution_boundary;t.sealed=true;join(seq);
  }
  void final_compare(uint64_t seq,tick_t original_source_time,unsigned status) {
    Task &t=tasks.at(seq);ensure(!t.compared && status==0,"duplicate/FAIL/CANCELLED result invalidates sample");
    t.compare_time=original_source_time;t.compared=true;join(seq);
  }
  // Each disjoint interval is measured in BOOM reference ticks, not host cycles.
  // Sample each physical domain only on its own target token; the adapter must
  // convert edge times using exact clock-bridge ratios and preserve timestamps.
  void pressure(uint64_t ticks,uint64_t occupancy,uint64_t capacity,bool blocked,
                const std::set<std::string>& why,const std::vector<bool>& busy) {
    ensure(started && !drained_flag && ticks && capacity && occupancy<=capacity && busy.size()==rockets,"bad pressure interval");
    if (!ended) {
      ensure(!occupancy || ticks<=std::numeric_limits<uint64_t>::max()/occupancy,"queue integral overflow");
      queue_sum=add_checked(queue_sum,occupancy*ticks);queue_max=std::max(queue_max,occupancy);
      if (occupancy==capacity) full_ticks=add_checked(full_ticks,ticks);
      if (blocked) blocked_ticks=add_checked(blocked_ticks,ticks);
      for (auto& r:why) reasons[r]=add_checked(reasons[r],ticks);
    }
    auto& v=ended?busy_drain:busy_roi;
    for (unsigned i=0;i<rockets;++i) if(busy[i]) v[i]=add_checked(v[i],ticks);
  }
  void end(tick_t now,bool producer_sealed) {
    ensure(started && !ended && producer_sealed && now>start_time,"bad ROI end");ended=true;end_time=now;
  }
  void drained(tick_t now,bool all_transports_empty,bool all_released) {
    ensure(ended && !drained_flag && tasks.empty() && all_transports_empty && all_released && now>=end_time,"incomplete drain");
    drained_flag=true;drain_time=now;
  }
  std::string metrics_json(bool final,bool output_correct,const std::string& output_digest) const {
    ensure(!final || drained_flag,"final before drain");
    ensure(output_digest.empty() || (output_digest.size()==64 && output_digest.find_first_not_of("0123456789abcdef")==std::string::npos),"bad output digest");
    std::ostringstream o;
    o<<"{\"definition\":\"package-exec-to-final-compare/1\",\"epoch\":"<<epoch
     <<",\"synthetic\":false,\"final\":"<<(final?"true":"false")
     <<",\"roi_cycles\":"<<(ended?std::to_string(end_time-start_time):"null")
     <<",\"drain_cycles\":"<<(drained_flag?std::to_string(drain_time-end_time):"null")
     <<",\"generated\":"<<generated<<",\"completed\":"<<completed<<",\"exceptions\":0,\"outstanding\":"<<tasks.size()
     <<",\"latency_count\":"<<completed<<",\"latency_sum\":"<<sum<<",\"latency_max\":"<<maximum
     <<",\"queue_occupancy_tick_sum\":"<<queue_sum<<",\"queue_max\":"<<queue_max
     <<",\"queue_full_ticks\":"<<full_ticks<<",\"boom_protection_blocked_ticks\":"<<blocked_ticks<<",\"histogram\":[";
    bool first=true;
    for(auto& kv:hist) {if(!first)o<<",";first=false;o<<"{\"lo\":"<<kv.first.first<<",\"hi\":"<<kv.first.second<<",\"count\":"<<kv.second<<"}";}
    o<<"],\"busy_roi_ticks\":[";first=true;for(auto n:busy_roi){if(!first)o<<",";first=false;o<<n;}
    o<<"],\"busy_drain_ticks\":[";first=true;for(auto n:busy_drain){if(!first)o<<",";first=false;o<<n;}
    o<<"],\"blocking_reasons\":{";first=true;
    for(auto& kv:reasons){ensure(kv.first.find_first_not_of("abcdefghijklmnopqrstuvwxyz_0123456789")==std::string::npos,"bad reason label");if(!first)o<<",";first=false;o<<"\""<<kv.first<<"\":"<<kv.second;}
    o<<"},\"blocking_reasons_exclusive\":false,\"overflow\":false,\"dropped_events\":0,\"protocol_errors\":[]"
     <<",\"roi_start_drained\":"<<(started?"true":"false")<<",\"roi_end_sealed\":"<<(ended?"true":"false")
     <<",\"all_released\":"<<(drained_flag?"true":"false")
     <<",\"timebase_verified\":false,\"execution_timestamp_verified\":"<<(rockets?"false":"null")
     <<",\"final_compare_verified\":"<<(rockets?"false":"null")
     <<",\"output_correct\":"<<(output_correct?"true":"false")<<",\"output_digest\":\""<<output_digest<<"\"}";
    // The three *_verified fields intentionally default FALSE. A source-hashed
    // bridge adapter may set them TRUE only after the evidence gate is passed.
    return o.str();
  }
};
} // namespace ec_dac
