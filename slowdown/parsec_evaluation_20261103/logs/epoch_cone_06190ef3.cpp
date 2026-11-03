#include "VEpochCone.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static unsigned checks=0,cases=0;
static void require(bool value,const char* message){++checks;if(!value){std::fprintf(stderr,"FAIL: %s\n",message);std::exit(1);}}
static void edge(VEpochCone& d){d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();}
static void clear(VEpochCone& d){
  d.cut0=0;
d.cut1=0;
d.cut2=0;
d.cut3=0;
d.cut4=0;
d.cut5=0;
d.cut6=0;
d.cut7=0;
d.cut8=0;
d.cut9=0;
d.cut10=0;
d.cut11=0;
d.cut12=0;
d.cut13=0;
d.cut14=0;
d.cut15=0;
d.cut16=0;
d.cut17=0;
d.cut18=0;
d.cut19=0;
d.cut20=0;
d.cut21=0;
d.cut22=0;
d.cut23=0;
d.cut24=0;
d.cut25=0;
d.cut26=0;
d.cut27=0;
  d.reset=1;edge(d);d.reset=0;d.eval();
  d.cut12=1;
  d.cut0=1;
  d.cut14=4;
  d.cut18=1;
  d.eval();
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);VEpochCone d;
  clear(d);require(d.s2_write_grant,"ordinary eligible S2 grant must remain possible");
  // The observed failure: eligible S2 request shares the exception/flush edge.
  for(int reset=0;reset<2;++reset){
    clear(d);d.cut16=!reset;d.cut17=reset;d.eval();
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
    clear(d);d.cut15=1;d.cut24=1;
    d.cut16=!useReset;d.cut17=useReset;d.eval();
    require(!d.svbFlush,"held unapplied store must retain its predecessor");edge(d);
    d.cut16=0;d.cut17=0;
    for(int i=0;i<delay;++i){
      d.cut16=repeated&&i==delay/2;d.eval();
      require(d.svbFlushPending,"one-cycle boundary cannot be forgotten");
      require(!d.svbFlush,"backpressured live write cannot lose predecessor");
      require(!d.s2_write_grant,"new grants cannot cross a deferred boundary");
      require(d.svbCaptureDiscard,"late snapshot cannot enter deferred epoch");
      if(useReset)require(d.svbResetPending,"reset priority must survive pulse");
      edge(d);
    }
    d.cut16=0;d.cut19=1;d.eval();
    require(d.svbFlush,"physical effect must allow the pending flush to drain");
    if(useReset)require(d.svbResetPending,"reset reason must survive until actual flush");
    edge(d);require(!d.svbFlushPending&&!d.svbResetPending,"drained boundary must clear exactly once");
    d.cut19=0;d.cut15=0;d.eval();require(d.s2_write_grant,"new writes must resume after drain");++cases;
  }
  // These terminal states carry no unique live predecessor obligation.
  for(int terminal=0;terminal<5;++terminal){
    clear(d);d.cut15=1;d.cut24=1;
    if(terminal==0)d.cut20=1;
    if(terminal==1)d.cut23=1;
    if(terminal==2)d.cut21=1;
    if(terminal==3)d.cut19=1;
    if(terminal==4)d.cut22=1;
    d.cut16=1;d.eval();require(d.svbFlush,"terminal or independently preserved write must not hold epoch forever");++cases;
  }
  std::printf("PASS: %u directed epoch cases, %u ownership checks\n",cases,checks);d.final();
}
