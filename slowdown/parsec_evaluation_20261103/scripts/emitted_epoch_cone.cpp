#include "VEpochCone.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static unsigned checks=0,cases=0;
static void require(bool value,const char* message){++checks;if(!value){std::fprintf(stderr,"FAIL: %s\n",message);std::exit(1);}}
static void edge(VEpochCone& d){d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();}
static void clear(VEpochCone& d){
  /* ZERO CUT INPUTS */
  d.reset=1;edge(d);d.reset=0;d.eval();
  d._s2_write_grant_T=1;
  d._cacheObservationEvents_flags_T_25=1;
  d.debug_s2_type=4;
  d.s2_replay_owner_match=1;
  d.eval();
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);VEpochCone d;
  clear(d);require(d.s2_write_grant,"ordinary eligible S2 grant must remain possible");
  // GHE initializes observer reset HIGH. Firmware must execute ordinary stores
  // before it can clear that register; reset alone cannot stop those stores.
  clear(d);d.io__traffic_reset=1;
  for(int i=0;i<32;++i){d.eval();require(d.svbFlush,"default reset still flushes SVB");require(d.s2_write_grant,"default observer reset cannot deadlock boot stores");edge(d);}++cases;
  // The observed failure: eligible S2 request shares the exception/flush edge.
  for(int reset=0;reset<2;++reset){
    clear(d);d.svbFastLineValid=1;d.io__lsu_exception=!reset;d.io__traffic_reset=reset;d.eval();
    require(d.svbFlush,"boundary without held S3 lease must flush immediately");
    require(d.debug_l1_cross_package_blocked,"boundary must use the existing nack/retry blocker");
    require(!d.s2_write_grant,"same-edge new write grant must be blocked");
    require(d.svbCaptureDiscard,"same-edge snapshot must be discarded");
    edge(d);require(!d.svbFlushPending,"immediate flush must not remain pending");++cases;
  }
  // An already committed/granted store may wait arbitrarily for its effect.
  // Keep the datapath obligation live through the effect edge; release it only
  // on the following edge, as registered s3_applied does in the real pipeline.
  for(int delay=1;delay<=16;++delay)for(int useReset=0;useReset<2;++useReset)for(int repeated=0;repeated<2;++repeated){
    clear(d);d.svbFastLineValid=1;d.debug_s3_valid=1;d.s3_svbOwnsPredecessor=1;
    d.io__lsu_exception=!useReset;d.io__traffic_reset=useReset;d.eval();
    require(!d.svbFlush,"held unapplied store must retain its predecessor");edge(d);
    d.io__lsu_exception=0;d.io__traffic_reset=0;
    for(int i=0;i<delay;++i){
      d.io__lsu_exception=repeated&&i==delay/2;d.eval();
      require(d.svbFlushPending,"one-cycle boundary cannot be forgotten");
      require(!d.svbFlush,"backpressured live write cannot lose predecessor");
      require(!d.s2_write_grant,"new grants cannot cross a deferred boundary");
      require(d.svbCaptureDiscard,"late snapshot cannot enter deferred epoch");
      if(useReset)require(d.svbResetPending,"reset priority must survive pulse");
      edge(d);
    }
    d.io__lsu_exception=0;d.s3_applied=1;d.svbFastLineValid=0;d.eval();
    require(d.svbFlush,"physical effect must allow the pending flush to drain");
    if(useReset)require(d.svbResetPending,"reset reason must survive until actual flush");
    edge(d);require(!d.svbFlushPending&&!d.svbResetPending,"drained boundary must clear exactly once");
    d.s3_applied=0;d.debug_s3_valid=0;d.eval();require(d.s2_write_grant,"new writes must resume after drain");++cases;
  }
  // These terminal states carry no unique live predecessor obligation.
  for(int terminal=0;terminal<5;++terminal){
    clear(d);d.debug_s3_valid=1;d.s3_svbOwnsPredecessor=1;
    if(terminal==0)d.s3_cancelled=1;
    if(terminal==1)d.s3_pre_effect_kill=1;
    if(terminal==2)d.s3_duplicate_effect=1;
    if(terminal==3)d.s3_applied=1;
    if(terminal==4)d.s3_l1PreservationAllowed=1;
    d.io__lsu_exception=1;d.eval();require(d.svbFlush,"terminal or independently preserved write must not hold epoch forever");++cases;
  }
  std::printf("PASS: %u directed epoch cases, %u ownership checks\n",cases,checks);d.final();
}
