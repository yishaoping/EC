#include "VR_ICSL.h"
#include "verilated.h"
#include <iostream>
#include <stdexcept>
struct Test{
 VerilatedContext ctx;VR_ICSL d{&ctx};
 void require(bool v,const char*m){if(!v)throw std::runtime_error(m);}
 void tick(int n=1){while(n--){d.clock=0;d.eval();d.clock=1;d.eval();ctx.timeInc(1);}}
 void reset(){
#include "../icsl_init.h"
 d.reset=1;tick(4);d.reset=0;tick(3);d.io_if_correct_process=1;}
 void sample(unsigned count,bool clear=false){d.io_ic_counter=count;d.io_ic_counter_valid=1;d.io_ic_counter_reset=clear;tick();d.io_ic_counter_valid=0;d.io_ic_counter_reset=0;}
 void start(bool priv){d.io_icsl_run=!priv;d.io_if_check_privrun=priv;tick();d.io_icsl_run=0;d.io_if_check_privrun=0;}
 void commits(int n){d.io_new_commit=1;tick(n);d.io_new_commit=0;tick();}
 void run(bool priv){reset();sample(558,true);start(priv);commits(priv?558:559);require(!d.io_package_exec_done&&!d.io_already_done,"live progress treated as final");sample(600);tick(3);require(!d.io_icsl_stalld,"cannot resume after live count grows");commits(42);require(d.io_debug_sl_counter==(priv?600:601),"wrong normal/priv offset");sample(0x8258);tick(4);require(!d.io_package_exec_done,"tail completion bypassed");require(d.io_icsl_stalld,"final tail not held");d.io_package_tail_drained=1;tick(3);require(d.io_package_exec_done,"600 final did not complete");
  d.io_self_xcpt=1;tick();d.io_self_xcpt=0;d.io_excpt_mode=1;d.io_if_check_completed=1;tick();d.io_if_check_completed=0;tick(4);require(!d.io_context_idle&&!d.io_if_ret_special_pc&&!d.io_if_check_privret,"completion escaped live trap");d.io_excpt_mode=0;d.io_self_ret=1;tick();d.io_self_ret=0;tick(3);require(d.io_package_exec_done,"xRET lost completed execution");std::cout<<"PASS 558 live -> 600 final, tail/trap hold priv="<<priv<<"\n";
 }
 void zero(bool priv){reset();sample(0x8000,true);start(priv);if(!priv)commits(1);tick(4);require(d.io_already_done,"zero final underflow or erased at start");require(!d.io_package_exec_done,"zero package ignored tail");d.io_package_tail_drained=1;tick(4);require(d.io_package_exec_done,"zero package failed to complete");std::cout<<"PASS zero final before start priv="<<priv<<"\n";}
};
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);try{Test t;for(bool p:{false,true}){t.run(p);t.zero(p);}return 0;}catch(std::exception&e){std::cerr<<"FAIL "<<e.what()<<"\n";return 1;}}
