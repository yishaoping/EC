// Observation-only host models. No Verilator/RTL state is ever written here.
// Input stream and policy limits are emitted with every final summary.
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

namespace ec_observation {
using U = unsigned long long;
struct Counts { U access=0, hit=0, miss=0, replacement=0, dirty_victim=0, set_full_miss=0; };
struct Tag {
  U line; bool valid, dirty;
  Tag(U l=0,bool v=false,bool d=false):line(l),valid(v),dirty(d) {}
};
static U rotate(U x, unsigned n) { n%=64; return n ? (x<<n)|(x>>(64-n)) : x; }

struct Shadow {
  unsigned sets, ways, block; int level; uint16_t random=1;
  std::vector<Tag> tags; Counts c;
  Shadow(unsigned s,unsigned w,unsigned b,int l):sets(s),ways(w),block(b),level(l),tags(s*w) {}
  void access(U address,bool write,bool count,bool allocate=true,bool countFill=false) {
    U line=address/block; unsigned set=line%sets;
    if(count) ++c.access;
    for(unsigned w=0;w<ways;++w) { auto &t=tags[set*ways+w];
      if(t.valid && t.line==line) { if(count) ++c.hit; t.dirty|=write; return; }
    }
    if(count) ++c.miss;
    if(count) {
      bool full=true;
      for(unsigned w=0;w<ways;++w) full &= tags[set*ways+w].valid;
      c.set_full_miss+=full;
    }
    if(!allocate) return;
    // Same random-replacement family as both real caches. Advance on this
    // model's misses; this is intentionally not a cycle-exact RTL LFSR replay.
    unsigned bits=level==2 ? (random&1023u) : random;
    unsigned victim=(static_cast<U>(bits)*ways)/(level==2 ? 1024u:65536u);
    auto &t=tags[set*ways+victim];
    if((count || countFill) && t.valid) { ++c.replacement; c.dirty_victim+=t.dirty; }
    t={line,true,write};
    unsigned feedback=((random>>0)^(random>>2)^(random>>3)^(random>>5))&1;
    random=static_cast<uint16_t>((random>>1)|(feedback<<15));
  }
  void invalidate(U address) {
    U line=address/block; unsigned set=line%sets;
    for(unsigned w=0;w<ways;++w) if(tags[set*ways+w].line==line) tags[set*ways+w].valid=false;
  }
};

// Hash checking lives in the allocation-scoped SC schema2 ledger. Keeping a
// global (line,generation,writer) XOR here merged legal repeated transactions.
static std::string data_summary() {
  return "{\"schema\":2,\"status\":\"SC_LIFECYCLE_LEDGER_REQUIRED\"}";
}


// L1_CAUSAL_OBSERVATION_BEGIN: fixed-size native state; no per-cycle output.
struct Causal {
  static const unsigned N=192, BINS=32, HIST=64, OCC=48, RING=64;
  enum {Samples,Busy,Full,LoadMiss,StoreMiss,LoadAttempts,StoreAttempts,
    Primary,Upgrade,Merge,AllocationReject,Refill,LoadReplay,LoadReplayCycles,
    LoadNack,LoadNackCycles,Retry,RetryCycles,HeadMiss,HeadBusy,HeadFull,
    Scheduler,SchedulerBusy,SchedulerFull,HeadScheduler,HeadPending,
    MissPending,ReplayBusy,ReplayFull,NackMshr,NackVictim,NackData,NackWb,NackHit,
    DetectAllocN,DetectAllocSum,AllocRefillN,AllocRefillSum,DetectDataN,DetectDataSum,
    MissReturnHead,MissEverHead,HeadEpisodeCycles,Recycled,PermissionLoad,PermissionStore};
  struct Slot { U token=0,detect=0,alloc=0,headCycles=0; bool known=false,miss=false,detected=false,allocated=false,nack=false,everHead=false; };
  struct Tx { U token=0,born=0; bool valid=false; };
  struct Snapshot { U cycle=~U(0); std::vector<U> counters; Snapshot():counters(N,0) {} };
  std::vector<U> c,begin,end;
  std::vector<Slot> loads,stores;
  std::vector<Tx> tx;
  std::vector<Snapshot> history;
  U cycle=0,start=0,stop=0,errors=0,startMarkers=0,stopMarkers=0;
  U markerEvents=0,markerSnapshotErrors=0,markerObserved[2]={0,0},markerRequested[2]={0,0};
  bool markerFound[2]={false,false};
  U lastReplay=~U(0),lastNack=~U(0),lastRetry=~U(0);
  bool busy=false,full=false,headCurrent=false;
  U headToken=0;
  Causal():c(N,0),begin(N,0),end(N,0),loads(64),stores(64),tx(6),history(RING) {}
  void clear() {
    std::fill(c.begin(),c.end(),0);start=stop=errors=startMarkers=stopMarkers=0;
    markerEvents=markerSnapshotErrors=0;
    std::fill(markerObserved,markerObserved+2,0);std::fill(markerRequested,markerRequested+2,0);
    std::fill(markerFound,markerFound+2,false);
    for(auto &h:history) h.cycle=~U(0);
    lastReplay=lastNack=lastRetry=~U(0);
  }
  void tick(U now,unsigned occupied,bool all) {
    cycle=now;busy=occupied!=0;full=all;
    auto &h=history[cycle%RING];h.cycle=cycle;h.counters=c;
    ++c[Samples];c[Busy]+=busy;c[Full]+=full;
    if(occupied<=6) ++c[OCC+occupied]; else ++errors;
  }
  Slot &touch(std::vector<Slot> &slots,unsigned index,U token) {
    if(index>=slots.size()) { ++errors;index=0; }
    auto &x=slots[index];
    if(!x.known || x.token!=token) { if(x.miss) ++c[Recycled];x=Slot();x.known=true;x.token=token; }
    return x;
  }
  void latency(unsigned which,U delta) {
    unsigned b=0;U v=delta;while(v && b<BINS-1) { ++b;v>>=1; }
    ++c[HIST+which*BINS+b];
  }
  void event(int kind,unsigned flags,U address,U token,U value,unsigned index,unsigned way) {
    (void)address;
    if(kind==14) {
      bool load=flags&1,store=flags&2;
      if(!load && !store)return;
      c[load?LoadAttempts:StoreAttempts]++;
      auto &x=touch(load?loads:stores,index,token);
      if(!x.detected) {
        x.detected=x.miss=true;x.detect=cycle;
        if(flags&4)++c[load?LoadMiss:StoreMiss];
        if(flags&8)++c[load?PermissionLoad:PermissionStore];
      }
    } else if(kind==15) {
      c[Primary]+=(flags&4)!=0;c[Merge]+=(flags&8)!=0;c[Upgrade]+=(flags&16)!=0;
      if(way>=tx.size()) { ++errors;return; }
      if(flags&(4|16)) { tx[way].token=value;tx[way].born=cycle;tx[way].valid=true; }
      if(flags&1) {
        auto &x=touch(loads,index,token);
        if(x.miss && !x.allocated) {
          x.allocated=true;x.alloc=cycle;++c[DetectAllocN];c[DetectAllocSum]+=cycle-x.detect;
          latency(0,cycle-x.detect);
        }
      }
    } else if(kind==16) {
      ++c[Refill];if(way>=tx.size()) { ++errors;return; }
      auto &t=tx[way];
      if(t.valid && t.token==token) {
        ++c[AllocRefillN];c[AllocRefillSum]+=cycle-t.born;latency(1,cycle-t.born);t.valid=false;
      } else ++errors;
    } else if(kind==17) {
      if(index>=loads.size()) { ++errors;return; }
      auto &x=loads[index];
      if(x.known && x.token==token && x.miss) {
        ++c[DetectDataN];c[DetectDataSum]+=cycle-x.detect;latency(2,cycle-x.detect);
        c[MissReturnHead]+=headCurrent && headToken==token;
        c[MissEverHead]+=x.everHead;c[HeadEpisodeCycles]+=x.headCycles;
        x.miss=false;
      }
    } else if(kind==18) {
      if(index>=loads.size()) { ++errors;return; }
      for(unsigned i=0;i<loads.size();++i) if(!(value&(U(1)<<i))) loads[i].miss=false;
      auto &x=loads[index];
      bool head=(flags&1) && x.known && x.token==token && x.miss;
      bool sched=flags&2;
      headCurrent=head;headToken=token;
      c[HeadPending]+=(flags&1)!=0;c[HeadMiss]+=head;c[HeadBusy]+=head&&busy;c[HeadFull]+=head&&full;
      c[Scheduler]+=sched;c[SchedulerBusy]+=sched&&busy;c[SchedulerFull]+=sched&&full;
      c[HeadScheduler]+=head&&sched;
      bool any=false;for(const auto &slot:loads)any|=slot.miss;c[MissPending]+=any;
      if(head) {x.everHead=true;++x.headCycles;}
    } else if(kind==20) {
      ++c[LoadReplay];c[ReplayBusy]+=busy;c[ReplayFull]+=full;
      if(lastReplay!=cycle) {++c[LoadReplayCycles];lastReplay=cycle;}
    } else if(kind==21) {
      auto &x=touch(loads,index,token);x.nack=true;++c[LoadNack];
      if(lastNack!=cycle) {++c[LoadNackCycles];lastNack=cycle;}
      c[NackMshr]+=(flags&16)!=0;c[NackVictim]+=(flags&32)!=0;c[NackData]+=(flags&64)!=0;
      c[NackWb]+=(flags&128)!=0;c[NackHit]+=(flags&256)!=0;
    } else if(kind==22) {
      auto &x=touch(loads,index,token);
      if(x.nack) { ++c[Retry];if(lastRetry!=cycle) {++c[RetryCycles];lastRetry=cycle;}x.nack=false; }
    } else if(kind==23) {
      const auto &h=history[token%RING];
      unsigned markerIndex=(flags&2)?0:1;
      markerObserved[markerIndex]=cycle;markerRequested[markerIndex]=token;markerFound[markerIndex]=h.cycle==token;
      if(++markerEvents<=4) {
        std::fprintf(stderr,"[CAUSAL_ROI_MARKER] flags=%u observer_cycle=%llu sample_cycle=%llu lookup_valid=%u\n",
          flags,(unsigned long long)cycle,(unsigned long long)token,unsigned(h.cycle==token));
        std::fflush(stderr);
      }
      if(h.cycle!=token) {++errors;++markerSnapshotErrors;return;}
      if(flags&2) {++startMarkers;start=token;begin=h.counters;}
      if(flags&1) {++stopMarkers;stop=token;end=h.counters;}
    } else if(kind==24) ++c[AllocationReject];
  }
  std::string json() const {
    static const char *names[]={"sample_cycles","mshr_busy_cycles","mshr_full_cycles",
      "load_tag_miss_requests","store_tag_miss_requests","load_miss_lookup_attempts","store_miss_lookup_attempts",
      "mshr_primary_allocations","mshr_upgrade_allocations","mshr_merges","mshr_request_rejects",
      "refill_completions","load_rpq_replays","load_rpq_replay_cycles","load_nacks","load_nack_cycles",
      "load_nack_retries","load_nack_retry_cycles","ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES",
      "ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES","ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES",
      "scheduler_unavailable_cycles","SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES",
      "SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES","ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES",
      "rob_head_load_pending_cycles","any_ldq_miss_pending_cycles","load_rpq_replay_and_mshr_busy_events",
      "load_rpq_replay_and_mshr_full_events","nack_mshr_not_ready","nack_victim","nack_data","nack_writeback","nack_hit",
      "detect_alloc_samples","detect_alloc_sum","alloc_refill_samples","alloc_refill_sum",
      "detect_data_samples","detect_data_sum","miss_returns_still_head","completed_misses_ever_head",
      "completed_miss_head_episode_cycles","recycled_pending_slots","load_permission_miss_requests","store_permission_miss_requests"};
    bool valid=startMarkers==1 && stopMarkers==1 && stop>start && !errors && end[Samples]-begin[Samples]==stop-start;
    std::ostringstream o;o<<"{\"schema\":1,\"bounded_slots\":64,\"mshr_slots\":6,\"snapshot_ring\":64"
      <<",\"roi_start\":"<<start<<",\"roi_stop\":"<<stop<<",\"errors\":"<<errors
      <<",\"start_markers\":"<<startMarkers<<",\"stop_markers\":"<<stopMarkers
      <<",\"roi_marker_events\":"<<markerEvents<<",\"roi_snapshot_lookup_errors\":"<<markerSnapshotErrors
      <<",\"roi_marker_observed_cycles\":["<<markerObserved[0]<<','<<markerObserved[1]<<']'
      <<",\"roi_marker_requested_cycles\":["<<markerRequested[0]<<','<<markerRequested[1]<<']'
      <<",\"roi_marker_snapshot_found\":["<<unsigned(markerFound[0])<<','<<unsigned(markerFound[1])<<']'
      <<",\"status\":\""<<(valid?"PASS":"FAIL")<<"\",\"window\":\"exact_software_rdcycle_half_open_via_bounded_prefix_snapshots\""
      <<",\"counts\":{";
    for(unsigned i=0;i<sizeof(names)/sizeof(names[0]);++i) {if(i)o<<',';o<<'"'<<names[i]<<"\":"<<(valid?end[i]-begin[i]:0);}
    o<<"},\"mshr_occupancy_histogram\":[";
    for(unsigned i=0;i<=6;++i){if(i)o<<',';o<<(valid?end[OCC+i]-begin[OCC+i]:0);}o<<']';
    o<<",\"latency_bin_definition\":\"bin0=0; binN=[2^(N-1),2^N-1]; bin31_saturates\""
      <<",\"latency_cohort\":\"completion_in_ROI; may_start_before_ROI; unfinished_censored\",\"latency_histograms\":[";
    for(unsigned j=0;j<3;++j){if(j)o<<',';o<<'[';for(unsigned i=0;i<BINS;++i){if(i)o<<',';o<<(valid?end[HIST+j*BINS+i]-begin[HIST+j*BINS+i]:0);}o<<']';}
    o<<"]}";return o.str();
  }
};
// L1_CAUSAL_OBSERVATION_END

struct Cache {
  int level,id; unsigned sets,ways,block,mshrs;
  Causal causal;
  bool enabled=false,seen_clear=false,seen_reset=false,finished=false,stop_seen=false;
  U cycle=0,cycles=0,loads=0,stores=0,permission_miss=0,request_a=0,request_c=0;
  U compulsory_like=0,set_full=0,set_conflict_replacements=0,repeated_set_miss=0,repeated_line_miss=0;
  U probe_evictions=0,svb_full=0,svb_unsupported=0,writebacks=0;
  U memory_reads=0,memory_writes=0,memory_read_bytes=0,memory_write_bytes=0,mshr_full_cycles=0;
  U metadata_replacements=0,metadata_invalidations=0,dirty_metadata_retirements=0;
  Counts actual;
  U svb_allocated=0,svb_completed=0,svb_coalesced=0,svb_discarded=0,svb_occupancy=0;
  U would_full_at_8=0,cycles_above_8=0,capture_failures=0,max_svb_occupancy=0,max_svb_depth=0;
  unsigned svb_entries=0; bool svb_frame=false,capacity_frame=false;
  std::vector<Shadow> models;
  std::vector<Tag> mirror;
  std::vector<Tag> lookup_view;
  std::vector<bool> lookup_seen;
  unsigned lookup_set=0;
  U lookup_snapshots=0,lookup_snapshot_errors=0,lookup_key_errors=0,temporal_mirror_disagreements=0;
  std::vector<U> a_opcodes,c_opcodes,lookup_opcodes;
  bool lookup_snapshot_mode=false,lookup_frame_open=false;
  std::vector<U> valid_hist, mshr_hist, set_access, set_miss, set_full_hist, last_miss;
  std::vector<U> svb_occupancy_hist,svb_depth_hist;
  std::vector<bool> had_miss;
  std::unordered_set<U> tokens,seen_lines;
  Cache(int l,int i,unsigned s,unsigned w,unsigned b,unsigned m):
    level(l),id(i),sets(s),ways(w),block(b),mshrs(m),mirror(s*w),
    lookup_view(w),lookup_seen(w),a_opcodes(8),c_opcodes(8),lookup_opcodes(8),
    valid_hist(w+1),mshr_hist(m+1),set_access(s),set_miss(s),set_full_hist(s),last_miss(s),had_miss(s) {
    models.emplace_back(s,w,b,l);
    if(s>=2) models.emplace_back(s/2,w*2,b,l);
    models.emplace_back(s*2,w,b,l);
    models.emplace_back(s,w*2,b,l);
  }
  void clear_stats() {
    if(level==1) causal.clear();
    cycles=loads=stores=permission_miss=request_a=request_c=compulsory_like=set_full=set_conflict_replacements=0;
    repeated_set_miss=repeated_line_miss=probe_evictions=svb_full=svb_unsupported=writebacks=0;
    memory_reads=memory_writes=memory_read_bytes=memory_write_bytes=mshr_full_cycles=0;
    metadata_replacements=metadata_invalidations=dirty_metadata_retirements=0; actual={};
    lookup_snapshots=lookup_snapshot_errors=lookup_key_errors=temporal_mirror_disagreements=0;
    std::fill(a_opcodes.begin(),a_opcodes.end(),0);
    std::fill(c_opcodes.begin(),c_opcodes.end(),0);
    std::fill(lookup_opcodes.begin(),lookup_opcodes.end(),0);
    for(auto &m:models) m.c={};
    for(auto *v:{&valid_hist,&mshr_hist,&set_access,&set_miss,&set_full_hist}) std::fill(v->begin(),v->end(),0);
    svb_occupancy_hist.clear(); svb_depth_hist.clear();
    std::fill(had_miss.begin(),had_miss.end(),false); stop_seen=false;
  }
  void event(int kind,unsigned flags,U address,U tag,U value,unsigned set,unsigned way,unsigned occupancy) {
    if(level==1 && kind>=14 && kind<=24) { causal.event(kind,flags,address,tag,value,set,way);return; }
    if(kind>=20 && kind<=22) return; // legacy identity is intentionally not trusted
    if(kind==30) { svb_frame=true; svb_entries=flags; svb_coalesced=address;
      svb_allocated=tag; svb_completed=value; svb_discarded=set; svb_occupancy=way; max_svb_depth=occupancy; return; }
    if(kind==31) { capacity_frame=true; would_full_at_8=address; cycles_above_8=tag;
      capture_failures=value; max_svb_occupancy=set; return; }
    if(kind==32) {
      if(svb_occupancy_hist.empty()) { svb_occupancy_hist.resize(flags+1); svb_depth_hist.resize(flags+1); }
      if(enabled && way<svb_occupancy_hist.size() && occupancy<svb_depth_hist.size()) {
        ++svb_occupancy_hist[way]; ++svb_depth_hist[occupancy];
      }
      return;
    }
    if(kind==13 && level==2) {
      lookup_snapshot_mode=true;
      if(way==0) {
        if(enabled && lookup_frame_open) ++lookup_snapshot_errors;
        lookup_frame_open=true;
        lookup_set=set;
        std::fill(lookup_seen.begin(),lookup_seen.end(),false);
      }
      if(set>=sets || way>=ways || set!=lookup_set || lookup_seen[way]) {
        if(enabled) ++lookup_snapshot_errors;
        return;
      }
      lookup_seen[way]=true;
      lookup_view[way]={address,(flags&1)!=0,(flags&2)!=0};
      return;
    }
    if(kind==1) {
      if(set>=sets) { if(enabled) ++lookup_snapshot_errors; return; }
      if(level==1 && !tokens.insert(tag).second) return; // one first lookup per request token
      bool fresh=seen_lines.insert(address/block).second;
      // S0 independently replays real metadata writes instead of installing on
      // first lookup, which incorrectly turned in-flight misses into hits.
      bool s0_hit=false;
      for(unsigned w=0;w<ways;++w) {
        const auto &t=mirror[set*ways+w]; s0_hit |= t.valid && t.line==address;
      }
      if(level==2 && lookup_snapshot_mode) {
        bool complete=set==lookup_set && std::all_of(lookup_seen.begin(),lookup_seen.end(),[](bool v){return v;});
        bool read_hit=false;
        for(const auto &t:lookup_view) read_hit |= t.valid && t.line==address;
        if(enabled) {
          ++lookup_snapshots;
          lookup_snapshot_errors+=!complete;
          lookup_key_errors+=value!=address;
          temporal_mirror_disagreements+=s0_hit!=read_hit;
        }
        s0_hit=complete && read_hit;
        lookup_frame_open=false;
        std::fill(lookup_seen.begin(),lookup_seen.end(),false);
      }
      if(enabled && level==2) ++lookup_opcodes[(flags>>8)&7];
      if(enabled) { ++models[0].c.access; models[0].c.hit+=s0_hit; models[0].c.miss+=!s0_hit; }
      for(size_t i=1;i<models.size();++i) models[i].access(address,flags&2,enabled,!(flags&8));
      if(!enabled) return;
      ++actual.access; actual.hit+=(flags&4)!=0; actual.miss+=(flags&8)!=0;
      loads+=(flags&1)!=0; stores+=(flags&2)!=0; permission_miss+=(flags&16)!=0;
      if(occupancy<valid_hist.size()) ++valid_hist[occupancy];
      if(set<sets) { ++set_access[set]; if(flags&8) {
        ++set_miss[set]; compulsory_like+=fresh;
        if(occupancy==ways) { ++set_full; ++set_full_hist[set]; ++actual.set_full_miss; }
        if(had_miss[set]) { ++repeated_set_miss; repeated_line_miss+=last_miss[set]==address; }
        had_miss[set]=true; last_miss[set]=address;
      }}
    } else if(kind==5) {
      if(set>=sets || way>=ways) return;
      auto &t=mirror[set*ways+way]; bool valid=flags&1;
      if(enabled && t.valid && (!valid || t.line!=address)) {
        metadata_invalidations+=!valid; metadata_replacements+=valid;
        dirty_metadata_retirements+=t.dirty;
        if(valid) { ++models[0].c.replacement; models[0].c.dirty_victim+=t.dirty; }
      }
      t={address,valid,(flags&2)!=0};
      if(valid) for(size_t i=1;i<models.size();++i) models[i].access(address,flags&2,false,true,enabled);
    } else if(kind==3) {
      for(size_t i=1;i<models.size();++i) models[i].invalidate(address);
      if(enabled) ++probe_evictions;
    } else if(kind==12) { // ReleaseData can install L2 data without an A demand
      for(size_t i=1;i<models.size();++i) models[i].access(address,true,false,true,enabled);
      // No demand miss/replacement credit for silent fills.
      for(auto &m:models) {
        U line=address/block; unsigned s=line%m.sets;
        for(unsigned w=0;w<m.ways;++w) { auto &t=m.tags[s*m.ways+w]; if(t.valid && t.line==line) t.dirty=true; }
      }
    } else if(enabled) {
      switch(kind) {
      case 2: {
        ++actual.replacement; actual.dirty_victim+=(flags&1)!=0;
        bool full=(flags&2)!=0;
        if(level==2 && set<sets) {
          full=true;
          for(unsigned w=0;w<ways;++w) full &= mirror[set*ways+w].valid;
        }
        set_conflict_replacements+=full;
        break;
      }
      case 3: ++probe_evictions; break;
      case 4: svb_full+=(flags&1)!=0; svb_unsupported+=(flags&2)!=0; break;
      case 6:
        request_a+=(flags&1)!=0; request_c+=(flags&2)!=0;
        if(flags&1) ++a_opcodes[value&7];
        if(flags&2) ++c_opcodes[value&7];
        break;
      case 7: memory_reads+=(flags&1)!=0; memory_writes+=(flags&2)!=0;
        if(flags&1) memory_read_bytes+=value;
        if(flags&2) memory_write_bytes+=value;
        break;
      case 8: ++writebacks; break;
      default: break;
      }
    }
  }
};
static std::map<std::pair<int,int>,std::unique_ptr<Cache>> caches;
static std::string counts(const Counts &c) {
  std::ostringstream o; o<<"{\"access\":"<<c.access<<",\"hit\":"<<c.hit<<",\"miss\":"<<c.miss
    <<",\"replacement\":"<<c.replacement<<",\"dirty_victim\":"<<c.dirty_victim
    <<",\"set_full_miss\":"<<c.set_full_miss<<"}"; return o.str();
}
static std::string array(const std::vector<U> &v) {
  std::ostringstream o; o<<'['; for(size_t i=0;i<v.size();++i) { if(i)o<<',';o<<v[i]; }o<<']';return o.str();
}
static void finish(Cache &c) {
  if(c.finished || c.level==0) return;
  c.finished=true;
  U shadow_miss=c.models[0].c.miss,real_miss=c.actual.miss;
  double gap=double(shadow_miss>real_miss ? shadow_miss-real_miss:real_miss-shadow_miss)/std::max<U>(real_miss,1);
  bool replay_complete=c.level!=2 || (c.lookup_snapshot_mode &&
    c.lookup_snapshots==c.actual.access && !c.lookup_frame_open &&
    !c.lookup_snapshot_errors && !c.lookup_key_errors);
  bool sane=c.actual.access && gap<=0.10 && c.stop_seen && replay_complete;
  std::ostringstream o;
  o<<"{\"schema\":1,\"classification\":\"COUNTERFACTUAL_CACHE_TRAFFIC_ESTIMATE\",\"level\":"<<c.level
   <<",\"instance\":"<<c.id<<",\"sets\":"<<c.sets<<",\"ways\":"<<c.ways<<",\"block_bytes\":"<<c.block
   <<",\"mshrs\":"<<c.mshrs<<",\"stop_seen\":"<<(c.stop_seen?"true":"false")
   <<",\"replacement_policy\":\"random\",\"shadow_policy\":\"read_consistent_L2_snapshot_S0_L1_metadata_replay_random_alternatives\""
   <<",\"semantics\":\"L1_unique_first_S2_token_lookup_L2_nonHint_A_directory_results_including_relookups_not_C\""
   <<",\"limitations\":\"no_timing_feedback_no_cycle_exact_replacement_metadata_fill_replay_no_cycle_exact_lookup_pipeline_no_predicted_ROI\""
   <<",\"s0_replay_schema\":2,\"s0_replay_complete\":"<<(replay_complete?"true":"false")
   <<",\"read_consistent_snapshots\":"<<c.lookup_snapshots
   <<",\"snapshot_errors\":"<<c.lookup_snapshot_errors<<",\"lookup_key_errors\":"<<c.lookup_key_errors
   <<",\"temporal_mirror_disagreements\":"<<c.temporal_mirror_disagreements
   <<",\"inner_a_first_by_opcode\":"<<array(c.a_opcodes)
   <<",\"inner_c_first_by_opcode\":"<<array(c.c_opcodes)
   <<",\"directory_demand_by_opcode\":"<<array(c.lookup_opcodes)
   <<",\"causal\":"<<(c.level==1?c.causal.json():"null")
   <<",\"actual\":"<<counts(c.actual)<<",\"loads\":"<<c.loads<<",\"stores\":"<<c.stores
   <<",\"permission_miss\":"<<c.permission_miss<<",\"request_a\":"<<c.request_a<<",\"request_c\":"<<c.request_c
   <<",\"compulsory_like\":"<<c.compulsory_like<<",\"conflict_candidate\":"<<c.set_full
   <<",\"set_full_events\":"<<c.set_full<<",\"same_set_repeated_miss\":"<<c.repeated_set_miss
   <<",\"set_conflict_replacements\":"<<c.set_conflict_replacements
   <<",\"same_line_repeated_miss\":"<<c.repeated_line_miss<<",\"probe_evictions\":"<<c.probe_evictions
   <<",\"svb_full_fallback\":"<<c.svb_full<<",\"svb_unsupported_fallback\":"<<c.svb_unsupported
   <<",\"writebacks\":"<<c.writebacks<<",\"dram_facing_reads\":"<<c.memory_reads
   <<",\"dram_facing_writes\":"<<c.memory_writes<<",\"dram_facing_read_bytes\":"<<c.memory_read_bytes
   <<",\"dram_facing_write_bytes\":"<<c.memory_write_bytes<<",\"metadata_tag_replacements\":"<<c.metadata_replacements
   <<",\"metadata_invalidations\":"<<c.metadata_invalidations<<",\"dirty_metadata_retirements\":"<<c.dirty_metadata_retirements
   <<",\"cycles\":"<<c.cycles<<",\"mshr_full_cycles\":"<<c.mshr_full_cycles
   <<",\"ways_valid_histogram\":"<<array(c.valid_hist)<<",\"mshr_occupancy_histogram\":"<<array(c.mshr_hist)
   <<",\"per_set_access\":"<<array(c.set_access)<<",\"per_set_miss\":"<<array(c.set_miss)
   <<",\"per_set_full\":"<<array(c.set_full_hist)<<",\"s0_miss_relative_error\":"<<gap
   <<",\"geometry_decision_eligible\":"<<(sane?"true":"false")<<",\"models\":[";
  for(size_t i=0;i<c.models.size();++i) { const auto &m=c.models[i]; if(i)o<<',';
    o<<"{\"name\":\"S"<<i<<"\",\"sets\":"<<m.sets<<",\"ways\":"<<m.ways
     <<",\"capacity_bytes\":"<<U(m.sets)*m.ways*m.block<<",\"stats\":"<<counts(m.c)<<'}';
  }
  o<<"],\"data_fingerprints\":"<<data_summary()
   <<",\"svb_entry_accounting\":{\"observed\":"<<(c.svb_frame?"true":"false")
   <<",\"scope\":\"full_run_final\",\"entries\":"<<c.svb_entries
   <<",\"allocations\":"<<c.svb_allocated<<",\"completions\":"<<c.svb_completed
   <<",\"coalesced\":"<<c.svb_coalesced<<",\"discarded\":"<<c.svb_discarded
   <<",\"occupancy\":"<<c.svb_occupancy
   <<",\"conserved\":"<<(c.svb_allocated==c.svb_completed+c.svb_coalesced+c.svb_discarded+c.svb_occupancy?"true":"false")
   <<"},\"shadow_8_capacity\":{\"observed\":"<<(c.capacity_frame?"true":"false")
   <<",\"scope\":\"hardware_traffic_START_inclusive_STOP_exclusive\",\"would_full_at_8\":"<<c.would_full_at_8
   <<",\"cycles_above_8\":"<<c.cycles_above_8<<",\"capture_failures\":"<<c.capture_failures
   <<",\"max_occupancy\":"<<c.max_svb_occupancy<<",\"max_depth\":"<<c.max_svb_depth
   <<",\"occupancy_histogram\":"<<array(c.svb_occupancy_hist)
   <<",\"depth_histogram\":"<<array(c.svb_depth_hist)<<"}}";
  std::fprintf(stderr,"CACHE_OPPORTUNITY %s\n",o.str().c_str());
}
} // namespace

extern "C" void ec_cache_tick(int level,int id,int sets,int ways,int block_bytes,int mshrs,
    int reset_model,int reset_stats,int enabled,int stopped,int occupied,int full,unsigned long long cycle) {
  using namespace ec_observation;
  auto key=std::make_pair(level,id); auto &p=caches[key];
  if(!p) p.reset(new Cache(level,id,sets,ways,block_bytes,mshrs));
  if(reset_model) {
    if(!p->seen_reset) { p.reset(new Cache(level,id,sets,ways,block_bytes,mshrs)); p->seen_reset=true; }
    p->enabled=false; return;
  }
  p->seen_reset=false;
  if(reset_stats && !p->seen_clear) p->clear_stats();
  p->seen_clear=reset_stats; p->enabled=enabled && !reset_stats; p->cycle=cycle;
  p->stop_seen|=stopped;
  if(level==1) p->causal.tick(cycle,unsigned(occupied),full);
  if(p->enabled) { ++p->cycles; p->mshr_full_cycles+=full;
    if(occupied>=0 && unsigned(occupied)<p->mshr_hist.size()) ++p->mshr_hist[occupied];
  }
}
extern "C" void ec_cache_event(int level,int id,int kind,int flags,unsigned long long address,
    unsigned long long tag,unsigned long long value,int set,int way,int occupancy) {
  using namespace ec_observation; auto p=caches.find({level,id});
  if(p!=caches.end()) p->second->event(kind,flags,address,tag,value,set,way,occupancy);
}
extern "C" void ec_cache_finish(int level,int id) {
  using namespace ec_observation; auto p=caches.find({level,id}); if(p!=caches.end()) finish(*p->second);
}
