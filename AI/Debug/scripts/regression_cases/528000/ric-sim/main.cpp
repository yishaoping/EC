#include "VR_IC.h"
#include "verilated.h"
#include <iostream>
#include <stdexcept>
#include <string>
struct Test {
 VerilatedContext ctx; VR_IC d{&ctx};
 void require(bool v, const char*m){if(!v)throw std::runtime_error(m);}
 void eval(){d.clock=0;d.eval();}
 void tick(int n=1){while(n--){eval();d.clock=1;d.eval();ctx.timeInc(1);}}
 unsigned count(unsigned i){switch(i){case 1:return d.io_ic_counter_1;case 2:return d.io_ic_counter_2;case 3:return d.io_ic_counter_3;default:return d.io_ic_counter_4;}}
 void clear(unsigned i,bool v){switch(i){case 1:d.io_clear_ic_status_1=v;break;case 2:d.io_clear_ic_status_2=v;break;case 3:d.io_clear_ic_status_3=v;break;default:d.io_clear_ic_status_4=v;}}
 void reset(unsigned mask=15){
#include "../ric_init.h"
  d.reset=1;tick(4);d.reset=0;d.io_if_correct_process=1;d.io_big_core_id=1;
  d.io_ic_threshold=4955; d.io_checker_enable_mask=mask;d.io_checker_enable_we=1;
  d.io_if_ready_snap_shot=1;d.io_rob_empty=1; tick();d.io_checker_enable_we=0;
 }
 void waitCapture(){for(int k=0;k<100;k++){eval();if(d.io_snapshot_capture)return;tick();}throw std::runtime_error("snapshot timeout");}
 void start(){d.io_ic_run_isax=1;waitCapture(); require(d.io_active_packet_seq==0,"startup forged seq");tick();d.io_ic_run_isax=0;d.io_rsu_busy=1;tick(8);d.io_rsu_busy=0;tick();require(d.io_debug_maincore_status==2,"startup did not enter check");}
 unsigned owner(){return d.io_crnt_target&7;}
 void commits(int n){while(n){int v=n>3?3:n;d.io_ic_incr=v;tick();n-=v;}d.io_ic_incr=0;eval();}
 void freezeReady(){d.io_rob_empty=0;d.io_if_ready_snap_shot=0;}
 void drain(unsigned old,int start,int tail){for(int k=0;k<tail;){int n=tail-k>3?3:tail-k;d.io_ic_incr=n;tick();k+=n;require(count(old)==unsigned(start+k),"tail lost/wrong owner/premature final");}d.io_ic_incr=0;d.io_rob_empty=1;d.io_if_ready_snap_shot=1;waitCapture();}
 void captured(unsigned old,unsigned expected,bool alloc,bool priv){require(bool(d.io_if_dosnap_priv)==priv,"snapshot kind lost");require(count(old)==expected,"final before actual capture");tick();require(bool(d.io_packet_alloc_valid)==alloc,"wrong successor allocation");require(count(old)==expected,"final before delayed capture");require(d.io_old_crnt_target==old,"ECP wrong owner");d.io_rsu_busy=1;tick();require(count(old)==(0x8000|expected),"wrong final count");tick(8);require(d.io_closing_valid,"lost close identity while merge busy");d.io_rsu_busy=0;tick(5);require(d.io_closing_valid,"source tail wait bypassed");d.io_close_tail_ready=1;tick();d.io_close_tail_ready=0;}
 void barrierCase(bool nofree,bool priv){reset(nofree?1:15);start();unsigned old=owner();commits(558);freezeReady();d.io_barrier_force_close=1;d.io_barrier_force_close_seq=1;d.io_mode_switch=priv;tick();d.io_mode_switch=0;require(d.io_barrier_close_ack,"matching barrier not acknowledged");drain(old,558,42);captured(old,600,!nofree,priv);require(count(old)==0x8258,"600 not final");
  if(nofree){require((d.io_crnt_target&7)==0,"ECP-only has CPS target");tick(8);require(d.io_if_pipeline_stall,"no-slot gap lets target retire");d.io_if_correct_process=0;eval();require(!d.io_if_pipeline_stall,"non-target context blocked");d.io_if_correct_process=1;clear(old,1);tick(5);require(!d.io_packet_alloc_valid,"reused slot under held clear");clear(old,0);d.io_barrier_force_close=0;waitCapture();tick();require(d.io_packet_alloc_seq==2&&d.io_old_crnt_target==0,"resume duplicated old ECP");}
  else {require(d.io_debug_maincore_status==2,"barrier exited session");d.io_barrier_force_close_seq=99;d.io_barrier_force_close=0;tick();d.io_barrier_force_close=1;tick(3);require(!d.io_barrier_close_ack,"future seq ACK");}
 }
 void trigger(int kind){reset();start();unsigned old=owner();int base=kind==0?4956:30;commits(base);freezeReady();if(kind==1)d.io_icsl_na_1=1;if(kind==2)d.io_mode_ret=1;if(kind==3)d.io_ic_exit_isax=1;if(kind==4)clear(old,1);tick();d.io_icsl_na_1=0;d.io_mode_ret=0;d.io_ic_exit_isax=0;drain(old,base,42);captured(old,base+42,kind<3,kind==2);if(kind==4){tick(2);require(d.io_checker_segment_id_1==0,"cancel owner never released");}}
 void exitAt(int stage){reset();start();unsigned old=owner();commits(12);freezeReady();d.io_barrier_force_close=1;d.io_barrier_force_close_seq=1;tick();tick(stage);d.io_ic_exit_isax=1;tick();d.io_ic_exit_isax=0;drain(old,12,6);captured(old,18,false,false);require(d.io_active_packet_seq==1,"exit allocated successor");}
 void exitAfterAlloc(){reset();start();unsigned old=owner();d.io_barrier_force_close=1;d.io_barrier_force_close_seq=1;waitCapture();tick();require(d.io_packet_alloc_seq==2,"expected new package");unsigned newer=owner();d.io_rsu_busy=1;d.io_ic_exit_isax=1;tick();d.io_ic_exit_isax=0;tick(4);d.io_rsu_busy=0;d.io_close_tail_ready=1;tick();d.io_close_tail_ready=0;waitCapture();captured(newer,0,false,false);require(d.io_active_packet_seq==2,"exit allocated third package");require(count(old)==0x8000,"zero old final lost");}
};
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);try{Test t;for(bool n:{false,true})for(bool p:{false,true}){t.barrierCase(n,p);std::cout<<"PASS barrier 558+42 nofree="<<n<<" priv="<<p<<"\n";}for(int k=0;k<5;k++){t.trigger(k);std::cout<<"PASS trigger "<<k<<"\n";}for(int k=0;k<3;k++){t.exitAt(k);std::cout<<"PASS exit drain stage "<<k<<"\n";}t.exitAfterAlloc();std::cout<<"PASS exit after allocation / zero count\n";return 0;}catch(std::exception&e){std::cerr<<"FAIL "<<e.what()<<"\n";return 1;}}
