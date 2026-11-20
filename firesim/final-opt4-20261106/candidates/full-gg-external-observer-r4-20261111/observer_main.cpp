// External CPU-only observer. The generated model and every target input are
// read-only. Only this replacement main is compiled; the original archive is reused.
#include "verilated.h"
#include "verilated_vpi.h"
#include "Vemul.h"
#include "Vemul___024root.h"
#include "Vemul_GHBarrierLatencyStats.h"
#include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <string>
#include <array>
#include <unistd.h>
#define BOOM(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__##x
#define SYS(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__##x
#define CLOCK(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__##x
extern "C" void (*vlog_startup_routines[])() VL_ATTR_WEAK;


struct Image {
    uint64_t line=0;
    uint32_t generation=0,seq=0;
    uint16_t writer=0,epoch=0;
    unsigned key_valid=0,param=0;
    std::array<uint32_t,16> data{};
};
static Image entry_image(const Vemul___024root& r,unsigned idx) {
    Image im{};
    switch(idx) {
case 0: im.line=BOOM(dcache__DOT__svb__DOT__line_0);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_0_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_0_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_0_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_0_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_0);im.param=BOOM(dcache__DOT__svb__DOT__param_0);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_0_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_0_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_0_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_0_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_0_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_0_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_0_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_0_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_0_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_0_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_0_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_0_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_0_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_0_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_0_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_0_3)[3];break;
case 1: im.line=BOOM(dcache__DOT__svb__DOT__line_1);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_1_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_1_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_1_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_1_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_1);im.param=BOOM(dcache__DOT__svb__DOT__param_1);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_1_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_1_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_1_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_1_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_1_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_1_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_1_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_1_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_1_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_1_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_1_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_1_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_1_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_1_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_1_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_1_3)[3];break;
case 2: im.line=BOOM(dcache__DOT__svb__DOT__line_2);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_2_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_2_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_2_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_2_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_2);im.param=BOOM(dcache__DOT__svb__DOT__param_2);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_2_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_2_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_2_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_2_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_2_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_2_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_2_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_2_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_2_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_2_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_2_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_2_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_2_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_2_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_2_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_2_3)[3];break;
case 3: im.line=BOOM(dcache__DOT__svb__DOT__line_3);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_3_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_3_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_3_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_3_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_3);im.param=BOOM(dcache__DOT__svb__DOT__param_3);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_3_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_3_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_3_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_3_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_3_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_3_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_3_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_3_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_3_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_3_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_3_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_3_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_3_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_3_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_3_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_3_3)[3];break;
case 4: im.line=BOOM(dcache__DOT__svb__DOT__line_4);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_4_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_4_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_4_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_4_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_4);im.param=BOOM(dcache__DOT__svb__DOT__param_4);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_4_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_4_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_4_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_4_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_4_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_4_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_4_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_4_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_4_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_4_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_4_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_4_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_4_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_4_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_4_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_4_3)[3];break;
case 5: im.line=BOOM(dcache__DOT__svb__DOT__line_5);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_5_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_5_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_5_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_5_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_5);im.param=BOOM(dcache__DOT__svb__DOT__param_5);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_5_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_5_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_5_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_5_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_5_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_5_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_5_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_5_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_5_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_5_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_5_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_5_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_5_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_5_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_5_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_5_3)[3];break;
case 6: im.line=BOOM(dcache__DOT__svb__DOT__line_6);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_6_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_6_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_6_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_6_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_6);im.param=BOOM(dcache__DOT__svb__DOT__param_6);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_6_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_6_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_6_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_6_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_6_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_6_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_6_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_6_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_6_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_6_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_6_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_6_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_6_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_6_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_6_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_6_3)[3];break;
case 7: im.line=BOOM(dcache__DOT__svb__DOT__line_7);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_7_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_7_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_7_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_7_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_7);im.param=BOOM(dcache__DOT__svb__DOT__param_7);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_7_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_7_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_7_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_7_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_7_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_7_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_7_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_7_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_7_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_7_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_7_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_7_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_7_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_7_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_7_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_7_3)[3];break;
case 8: im.line=BOOM(dcache__DOT__svb__DOT__line_8);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_8_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_8_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_8_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_8_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_8);im.param=BOOM(dcache__DOT__svb__DOT__param_8);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_8_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_8_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_8_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_8_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_8_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_8_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_8_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_8_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_8_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_8_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_8_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_8_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_8_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_8_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_8_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_8_3)[3];break;
case 9: im.line=BOOM(dcache__DOT__svb__DOT__line_9);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_9_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_9_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_9_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_9_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_9);im.param=BOOM(dcache__DOT__svb__DOT__param_9);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_9_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_9_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_9_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_9_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_9_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_9_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_9_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_9_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_9_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_9_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_9_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_9_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_9_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_9_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_9_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_9_3)[3];break;
case 10: im.line=BOOM(dcache__DOT__svb__DOT__line_10);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_10_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_10_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_10_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_10_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_10);im.param=BOOM(dcache__DOT__svb__DOT__param_10);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_10_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_10_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_10_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_10_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_10_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_10_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_10_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_10_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_10_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_10_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_10_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_10_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_10_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_10_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_10_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_10_3)[3];break;
case 11: im.line=BOOM(dcache__DOT__svb__DOT__line_11);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_11_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_11_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_11_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_11_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_11);im.param=BOOM(dcache__DOT__svb__DOT__param_11);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_11_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_11_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_11_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_11_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_11_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_11_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_11_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_11_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_11_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_11_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_11_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_11_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_11_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_11_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_11_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_11_3)[3];break;
case 12: im.line=BOOM(dcache__DOT__svb__DOT__line_12);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_12_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_12_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_12_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_12_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_12);im.param=BOOM(dcache__DOT__svb__DOT__param_12);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_12_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_12_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_12_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_12_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_12_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_12_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_12_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_12_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_12_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_12_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_12_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_12_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_12_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_12_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_12_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_12_3)[3];break;
case 13: im.line=BOOM(dcache__DOT__svb__DOT__line_13);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_13_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_13_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_13_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_13_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_13);im.param=BOOM(dcache__DOT__svb__DOT__param_13);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_13_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_13_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_13_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_13_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_13_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_13_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_13_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_13_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_13_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_13_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_13_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_13_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_13_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_13_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_13_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_13_3)[3];break;
case 14: im.line=BOOM(dcache__DOT__svb__DOT__line_14);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_14_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_14_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_14_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_14_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_14);im.param=BOOM(dcache__DOT__svb__DOT__param_14);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_14_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_14_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_14_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_14_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_14_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_14_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_14_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_14_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_14_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_14_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_14_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_14_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_14_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_14_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_14_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_14_3)[3];break;
case 15: im.line=BOOM(dcache__DOT__svb__DOT__line_15);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_15_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_15_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_15_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_15_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_15);im.param=BOOM(dcache__DOT__svb__DOT__param_15);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_15_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_15_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_15_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_15_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_15_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_15_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_15_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_15_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_15_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_15_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_15_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_15_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_15_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_15_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_15_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_15_3)[3];break;
case 16: im.line=BOOM(dcache__DOT__svb__DOT__line_16);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_16_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_16_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_16_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_16_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_16);im.param=BOOM(dcache__DOT__svb__DOT__param_16);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_16_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_16_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_16_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_16_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_16_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_16_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_16_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_16_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_16_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_16_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_16_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_16_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_16_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_16_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_16_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_16_3)[3];break;
case 17: im.line=BOOM(dcache__DOT__svb__DOT__line_17);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_17_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_17_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_17_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_17_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_17);im.param=BOOM(dcache__DOT__svb__DOT__param_17);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_17_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_17_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_17_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_17_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_17_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_17_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_17_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_17_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_17_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_17_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_17_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_17_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_17_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_17_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_17_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_17_3)[3];break;
case 18: im.line=BOOM(dcache__DOT__svb__DOT__line_18);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_18_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_18_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_18_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_18_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_18);im.param=BOOM(dcache__DOT__svb__DOT__param_18);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_18_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_18_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_18_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_18_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_18_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_18_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_18_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_18_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_18_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_18_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_18_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_18_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_18_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_18_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_18_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_18_3)[3];break;
case 19: im.line=BOOM(dcache__DOT__svb__DOT__line_19);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_19_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_19_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_19_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_19_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_19);im.param=BOOM(dcache__DOT__svb__DOT__param_19);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_19_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_19_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_19_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_19_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_19_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_19_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_19_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_19_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_19_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_19_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_19_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_19_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_19_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_19_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_19_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_19_3)[3];break;
case 20: im.line=BOOM(dcache__DOT__svb__DOT__line_20);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_20_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_20_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_20_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_20_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_20);im.param=BOOM(dcache__DOT__svb__DOT__param_20);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_20_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_20_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_20_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_20_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_20_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_20_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_20_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_20_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_20_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_20_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_20_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_20_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_20_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_20_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_20_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_20_3)[3];break;
case 21: im.line=BOOM(dcache__DOT__svb__DOT__line_21);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_21_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_21_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_21_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_21_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_21);im.param=BOOM(dcache__DOT__svb__DOT__param_21);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_21_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_21_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_21_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_21_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_21_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_21_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_21_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_21_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_21_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_21_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_21_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_21_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_21_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_21_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_21_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_21_3)[3];break;
case 22: im.line=BOOM(dcache__DOT__svb__DOT__line_22);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_22_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_22_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_22_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_22_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_22);im.param=BOOM(dcache__DOT__svb__DOT__param_22);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_22_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_22_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_22_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_22_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_22_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_22_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_22_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_22_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_22_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_22_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_22_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_22_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_22_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_22_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_22_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_22_3)[3];break;
case 23: im.line=BOOM(dcache__DOT__svb__DOT__line_23);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_23_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_23_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_23_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_23_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_23);im.param=BOOM(dcache__DOT__svb__DOT__param_23);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_23_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_23_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_23_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_23_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_23_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_23_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_23_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_23_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_23_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_23_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_23_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_23_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_23_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_23_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_23_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_23_3)[3];break;
case 24: im.line=BOOM(dcache__DOT__svb__DOT__line_24);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_24_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_24_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_24_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_24_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_24);im.param=BOOM(dcache__DOT__svb__DOT__param_24);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_24_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_24_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_24_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_24_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_24_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_24_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_24_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_24_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_24_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_24_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_24_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_24_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_24_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_24_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_24_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_24_3)[3];break;
case 25: im.line=BOOM(dcache__DOT__svb__DOT__line_25);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_25_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_25_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_25_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_25_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_25);im.param=BOOM(dcache__DOT__svb__DOT__param_25);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_25_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_25_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_25_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_25_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_25_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_25_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_25_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_25_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_25_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_25_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_25_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_25_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_25_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_25_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_25_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_25_3)[3];break;
case 26: im.line=BOOM(dcache__DOT__svb__DOT__line_26);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_26_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_26_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_26_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_26_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_26);im.param=BOOM(dcache__DOT__svb__DOT__param_26);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_26_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_26_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_26_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_26_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_26_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_26_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_26_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_26_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_26_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_26_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_26_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_26_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_26_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_26_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_26_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_26_3)[3];break;
case 27: im.line=BOOM(dcache__DOT__svb__DOT__line_27);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_27_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_27_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_27_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_27_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_27);im.param=BOOM(dcache__DOT__svb__DOT__param_27);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_27_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_27_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_27_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_27_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_27_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_27_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_27_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_27_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_27_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_27_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_27_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_27_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_27_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_27_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_27_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_27_3)[3];break;
case 28: im.line=BOOM(dcache__DOT__svb__DOT__line_28);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_28_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_28_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_28_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_28_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_28);im.param=BOOM(dcache__DOT__svb__DOT__param_28);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_28_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_28_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_28_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_28_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_28_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_28_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_28_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_28_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_28_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_28_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_28_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_28_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_28_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_28_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_28_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_28_3)[3];break;
case 29: im.line=BOOM(dcache__DOT__svb__DOT__line_29);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_29_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_29_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_29_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_29_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_29);im.param=BOOM(dcache__DOT__svb__DOT__param_29);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_29_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_29_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_29_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_29_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_29_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_29_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_29_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_29_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_29_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_29_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_29_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_29_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_29_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_29_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_29_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_29_3)[3];break;
case 30: im.line=BOOM(dcache__DOT__svb__DOT__line_30);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_30_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_30_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_30_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_30_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_30);im.param=BOOM(dcache__DOT__svb__DOT__param_30);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_30_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_30_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_30_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_30_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_30_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_30_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_30_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_30_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_30_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_30_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_30_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_30_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_30_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_30_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_30_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_30_3)[3];break;
case 31: im.line=BOOM(dcache__DOT__svb__DOT__line_31);im.key_valid=BOOM(dcache__DOT__svb__DOT__key_31_valid);im.writer=BOOM(dcache__DOT__svb__DOT__key_31_writer);im.generation=BOOM(dcache__DOT__svb__DOT__key_31_generation);im.seq=BOOM(dcache__DOT__svb__DOT__key_31_contentSeq);im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_31);im.param=BOOM(dcache__DOT__svb__DOT__param_31);im.data[0]=BOOM(dcache__DOT__svb__DOT__data_31_0)[0];im.data[1]=BOOM(dcache__DOT__svb__DOT__data_31_0)[1];im.data[2]=BOOM(dcache__DOT__svb__DOT__data_31_0)[2];im.data[3]=BOOM(dcache__DOT__svb__DOT__data_31_0)[3];im.data[4]=BOOM(dcache__DOT__svb__DOT__data_31_1)[0];im.data[5]=BOOM(dcache__DOT__svb__DOT__data_31_1)[1];im.data[6]=BOOM(dcache__DOT__svb__DOT__data_31_1)[2];im.data[7]=BOOM(dcache__DOT__svb__DOT__data_31_1)[3];im.data[8]=BOOM(dcache__DOT__svb__DOT__data_31_2)[0];im.data[9]=BOOM(dcache__DOT__svb__DOT__data_31_2)[1];im.data[10]=BOOM(dcache__DOT__svb__DOT__data_31_2)[2];im.data[11]=BOOM(dcache__DOT__svb__DOT__data_31_2)[3];im.data[12]=BOOM(dcache__DOT__svb__DOT__data_31_3)[0];im.data[13]=BOOM(dcache__DOT__svb__DOT__data_31_3)[1];im.data[14]=BOOM(dcache__DOT__svb__DOT__data_31_3)[2];im.data[15]=BOOM(dcache__DOT__svb__DOT__data_31_3)[3];break;
    default:break;
    }
    return im;
}

struct Snapshot {

    bool capture_valid,capture_ready,promote_valid,promote_ready,ack_valid,acked;
    bool flush,invalidate,diagnostic,selected,active,sent;
    unsigned active_entry,promote_entry,ack_entry,allocated_entry,occupancy,coalesced,discarded;
    uint32_t watermark,valid_mask,ack_generation,ack_seq;
    unsigned ack_key_valid,ack_writer;
    uint64_t active_line;
    uint32_t active_generation,active_seq;
    unsigned release_blocked[4];
    uint64_t release_lines[4];
    unsigned release_entry3;
    uint64_t release_line3;
    uint32_t release_generation3,release_seq3;
    Image capture_image,promote_image;
    bool clk, reset_n, perf_reset, alloc;
    uint32_t alloc_seq;
    uint64_t fastest, csr, completed, passed, failed, cancelled, dropped;
    bool accepted[4];
    uint64_t payload[4];
};
static Snapshot capture(const Vemul___024root& r) {
    Snapshot s{};
    s.clk=CLOCK(clockBridge_clocks_0_buffer_O);
    s.reset_n=SYS(resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0);
    s.perf_reset=BOOM(ghe_debug_perf_ctrl)&1U;
    s.alloc=BOOM(core__DOT__ic_master__DOT__packet_alloc_valid_reg);
    s.alloc_seq=BOOM(core__DOT__ic_master__DOT__packet_alloc_seq_reg);
    s.fastest=r.emul__DOT__FPGATop__DOT__ClockBridgeModule_0__DOT__tCycleFastest;
    s.csr=r.__PVT__emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__crossPackageBarrierStats->io_currentCycle;
    s.completed=BOOM(dcache__DOT__completedPackages);
    s.passed=BOOM(dcache__DOT__passedPackages);
    s.failed=BOOM(dcache__DOT__failedPackages);
    s.cancelled=BOOM(dcache__DOT__cancelledPackages);
    s.dropped=BOOM(dcache__DOT__packageResultDropped);
    s.accepted[0]=BOOM(dcache__DOT__resultAccepted_0);
    s.accepted[1]=BOOM(dcache__DOT__resultAccepted_1);
    s.accepted[2]=BOOM(dcache__DOT__resultAccepted_2);
    s.accepted[3]=BOOM(dcache__DOT__resultAccepted_3);
    s.payload[0]=BOOM(dcache_io___05Fchecker_results_0);
    s.payload[1]=BOOM(dcache_io___05Fchecker_results_1);
    s.payload[2]=BOOM(dcache_io___05Fchecker_results_2);
    s.payload[3]=BOOM(dcache_io___05Fchecker_results_3);

    s.capture_valid=BOOM(dcache__DOT__wb__DOT__snapshotValid)&&!BOOM(dcache__DOT__svbCaptureDiscard);
    s.capture_ready=BOOM(dcache__DOT__svb_io_capture_ready);
    s.capture_image.line=((uint64_t(BOOM(dcache__DOT__wb__DOT__req_tag))<<8)|BOOM(dcache__DOT__wb__DOT__req_idx))<<6;
    s.capture_image.key_valid=BOOM(dcache__DOT__wb__DOT__snapshotKey_valid);
    s.capture_image.writer=BOOM(dcache__DOT__wb__DOT__snapshotKey_writer);
    s.capture_image.generation=BOOM(dcache__DOT__wb__DOT__snapshotKey_generation);
    s.capture_image.seq=BOOM(dcache__DOT__wb__DOT__snapshotKey_contentSeq);
    s.capture_image.epoch=BOOM(dcache__DOT__svbEpoch);
    s.capture_image.param=BOOM(dcache__DOT__wb__DOT__req_param);
    s.capture_image.data[0]=BOOM(dcache__DOT__wb__DOT__wb_buffer_0)[0];
    s.capture_image.data[1]=BOOM(dcache__DOT__wb__DOT__wb_buffer_0)[1];
    s.capture_image.data[2]=BOOM(dcache__DOT__wb__DOT__wb_buffer_0)[2];
    s.capture_image.data[3]=BOOM(dcache__DOT__wb__DOT__wb_buffer_0)[3];
    s.capture_image.data[4]=BOOM(dcache__DOT__wb__DOT__wb_buffer_1)[0];
    s.capture_image.data[5]=BOOM(dcache__DOT__wb__DOT__wb_buffer_1)[1];
    s.capture_image.data[6]=BOOM(dcache__DOT__wb__DOT__wb_buffer_1)[2];
    s.capture_image.data[7]=BOOM(dcache__DOT__wb__DOT__wb_buffer_1)[3];
    s.capture_image.data[8]=BOOM(dcache__DOT__wb__DOT__wb_buffer_2)[0];
    s.capture_image.data[9]=BOOM(dcache__DOT__wb__DOT__wb_buffer_2)[1];
    s.capture_image.data[10]=BOOM(dcache__DOT__wb__DOT__wb_buffer_2)[2];
    s.capture_image.data[11]=BOOM(dcache__DOT__wb__DOT__wb_buffer_2)[3];
    s.capture_image.data[12]=BOOM(dcache__DOT__wb__DOT__wb_buffer_3)[0];
    s.capture_image.data[13]=BOOM(dcache__DOT__wb__DOT__wb_buffer_3)[1];
    s.capture_image.data[14]=BOOM(dcache__DOT__wb__DOT__wb_buffer_3)[2];
    s.capture_image.data[15]=BOOM(dcache__DOT__wb__DOT__wb_buffer_3)[3];
    s.active=BOOM(dcache__DOT__svb__DOT__active);s.sent=BOOM(dcache__DOT__svb__DOT__sent);
    s.promote_valid=s.active&&!s.sent;
    s.promote_ready=BOOM(dcache__DOT__wb_io_svb_req_ready);
    s.promote_entry=BOOM(dcache__DOT__svb__DOT__activeIdx);
    s.promote_image=entry_image(r,s.promote_entry);
    s.ack_valid=BOOM(dcache__DOT__wb_io_svb_done_valid);
    s.acked=BOOM(dcache__DOT__svb_io_acked);
    s.ack_entry=BOOM(dcache__DOT__wb__DOT__pendingEntry);
    s.ack_key_valid=BOOM(dcache__DOT__wb__DOT__pendingKey_valid);
    s.ack_writer=BOOM(dcache__DOT__wb__DOT__pendingKey_writer);
    s.ack_generation=BOOM(dcache__DOT__wb__DOT__pendingKey_generation);
    s.ack_seq=BOOM(dcache__DOT__wb__DOT__pendingKey_contentSeq);
    s.watermark=BOOM(dcache__DOT__debug_safe_packet_watermark);
    s.flush=BOOM(dcache__DOT__svb_io_flush);s.invalidate=BOOM(dcache__DOT__svb_io_invalidate_valid);
    s.diagnostic=BOOM(dcache__DOT__svb_io_diagnosticDump);
    s.selected=BOOM(dcache__DOT__svb_io_selected);
    s.active_entry=BOOM(dcache__DOT__svb_io_activeEntry);
    s.active_line=BOOM(dcache__DOT__svb_io_activeLine);
    s.active_generation=BOOM(dcache__DOT__svb_io_activeKey_generation);
    s.active_seq=BOOM(dcache__DOT__svb_io_activeKey_contentSeq);
    s.occupancy=BOOM(dcache__DOT__svb__DOT__occupancyValue);
    s.coalesced=BOOM(dcache__DOT__svb_io_coalesced);s.discarded=BOOM(dcache__DOT__svb_io_discarded);
    s.release_lines[0]=BOOM(dcache__DOT__prober__DOT__req_address)&~uint64_t(63);
    s.release_lines[1]=BOOM(dcache__DOT__svb_io_releaseLines_1);
    s.release_lines[2]=BOOM(dcache__DOT__svb_io_releaseLines_2);
    s.release_lines[3]=BOOM(dcache__DOT___svb_io_releaseLines_3_T_1);
    s.release_entry3=BOOM(dcache__DOT__svb_io_releaseBlockingEntry_3);
    s.release_line3=BOOM(dcache__DOT__svb_io_releaseBlockingLine_3);
    s.release_seq3=BOOM(dcache__DOT__svb_io_releaseBlockingSeq_3);
    s.release_generation3=BOOM(dcache__DOT__svb_io_releaseBlockingGeneration_3);
    s.release_blocked[0]=BOOM(dcache__DOT__svb_io_releaseBlocked_0);
    s.release_blocked[1]=BOOM(dcache__DOT__svb_io_releaseBlocked_1);
    s.release_blocked[2]=BOOM(dcache__DOT__svb_io_releaseBlocked_2);
    s.release_blocked[3]=BOOM(dcache__DOT__svb_io_releaseBlocked_3);
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_0))<<0;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_1))<<1;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_2))<<2;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_3))<<3;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_4))<<4;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_5))<<5;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_6))<<6;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_7))<<7;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_8))<<8;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_9))<<9;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_10))<<10;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_11))<<11;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_12))<<12;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_13))<<13;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_14))<<14;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_15))<<15;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_16))<<16;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_17))<<17;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_18))<<18;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_19))<<19;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_20))<<20;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_21))<<21;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_22))<<22;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_23))<<23;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_24))<<24;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_25))<<25;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_26))<<26;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_27))<<27;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_28))<<28;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_29))<<29;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_30))<<30;
    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_31))<<31;
    s.allocated_entry=s.valid_mask==0xffffffffU?0:unsigned(__builtin_ctz(~s.valid_mask));
    return s;
}
struct Observer {
    FILE* out=nullptr;
    std::string path;
    uint64_t edges=0, errors=0, allocations=0, accepted=0, records=0;
    uint64_t pass=0, fail=0, cancel=0, reset_edges=0, nonreset_edges=0;
    uint64_t last_fastest=0;
    explicit Observer(const char* p) {
        if(p && *p) {
            path=p; out=fopen(p,"wx");
            if(!out) {perror("observer open"); std::exit(90);}
            setvbuf(out,nullptr,_IOFBF,64*1024);
            fprintf(out,"{\"schema\":\"ec-gg-external-events/1\",\"kind\":\"HEADER\",\"scope\":\"CPU metasim BOOM input acceptance only\",\"functional_baseline\":\"8491167d84b6d9521b151a743673c1516926a1f8\"}\n");
        }
    }
    void error(const char* reason,uint64_t tick,uint64_t got,uint64_t expected) {
        ++errors;
        if(errors<101) fprintf(out,"{\"kind\":\"SAMPLE_ERROR\",\"record\":%" PRIu64 ",\"reason\":\"%s\",\"fastest_target_cycle\":%" PRIu64 ",\"got\":%" PRIu64 ",\"expected\":%" PRIu64 "}\n",++records,reason,tick,got,expected);
    }
    void after(const Snapshot& a,const Vemul___024root& r,uint64_t host_time) {
        const auto b=capture(r);
        // The generated model's actual BUFGCE output, not host-clock changes,
        // identifies each BOOM sampling edge. Pre-eval values are validated
        // against the corresponding post-edge state transitions on every edge.
        const bool edge=!a.clk && b.clk;
        if(!edge) {
            if(a.reset_n && b.reset_n && b.completed!=a.completed)
                error("completion_counter_changed_without_boom_edge",b.fastest,b.completed,a.completed);
            return;
        }
        ++edges; last_fastest=b.fastest;
        if(b.fastest!=a.fastest+1) error("base_counter_edge_alignment",b.fastest,b.fastest,a.fastest+1);
        if(!a.reset_n || !b.reset_n || a.perf_reset) {++reset_edges;return;}
        ++nonreset_edges;
        svb_after(a,b,r);
        uint64_t n=0,np=0,nf=0,nc=0;
        for(unsigned i=0;i<4;++i) if(a.accepted[i]) {
            ++n;
            const unsigned status=(a.payload[i]>>32)&3;
            if(!(a.payload[i]>>34) || !(a.payload[i]&0xffffffffULL) || status==3)
                error("accepted_payload_invalid",b.fastest,a.payload[i],0);
            np+=status==0;nf+=status==1;nc+=status==2;
        }
        if(b.completed!=a.completed+n) error("accepted_vs_completion_counter",b.fastest,b.completed,a.completed+n);
        if(b.passed!=a.passed+np) error("accepted_vs_pass_counter",b.fastest,b.passed,a.passed+np);
        if(b.failed!=a.failed+nf) error("accepted_vs_fail_counter",b.fastest,b.failed,a.failed+nf);
        if(b.cancelled!=a.cancelled+nc) error("accepted_vs_cancel_counter",b.fastest,b.cancelled,a.cancelled+nc);
        if(n && BOOM(dcache__DOT__lastCheckerResultCycle)!=a.csr)
            error("accepted_cycle_vs_stored_timestamp",b.fastest,BOOM(dcache__DOT__lastCheckerResultCycle),a.csr);
        if(a.alloc) {
            ++allocations;
            fprintf(out,"{\"kind\":\"BOOM_ALLOC\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"host_time\":%" PRIu64 ",\"package_seq\":%u}\n",++records,b.fastest,a.csr,host_time,a.alloc_seq);
        }
        for(unsigned i=0;i<4;++i) if(a.accepted[i]) {
            ++accepted;
            fprintf(out,"{\"kind\":\"BOOM_RESULT_ACCEPTED\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"host_time\":%" PRIu64 ",\"checker\":%u,\"package_seq\":%u,\"status\":%u,\"raw_payload\":%" PRIu64 "}\n",++records,b.fastest,a.csr,host_time,i+1,unsigned(a.payload[i]&0xffffffffULL),unsigned((a.payload[i]>>32)&3),a.payload[i]);
        }
        pass+=np;fail+=nf;cancel+=nc;
        if((edges&1023)==0 || n || a.alloc) fflush(out);
    }

    uint64_t svb_captures=0,svb_promotions=0,svb_acks=0,svb_windows=0,svb_window_cycles=0;
    FILE* svb_file=nullptr;
    unsigned window_left=0;
    std::array<Snapshot,16> ring{};
    std::array<uint64_t,16> ring_ticks{};
    unsigned ring_pos=0,ring_size=0;
    static bool image_equal(const Image& a,const Image& b) {
        return a.line==b.line&&a.generation==b.generation&&a.seq==b.seq&&a.writer==b.writer&&a.epoch==b.epoch&&a.key_valid==b.key_valid&&a.param==b.param&&a.data==b.data;
    }
    static void image_json(FILE* f,const Image& im) {
        fprintf(f,"{\"line\":%" PRIu64 ",\"key_valid\":%u,\"writer\":%u,\"generation\":%u,\"content_seq\":%u,\"epoch\":%u,\"param\":%u,\"data_words_le\":[",im.line,im.key_valid,im.writer,im.generation,im.seq,im.epoch,im.param);
        for(unsigned j=0;j<16;++j)fprintf(f,"%s%u",j?",":"",im.data[j]);
        fprintf(f,"]}");
    }
    void svb_cycle(const Snapshot& s,uint64_t tick) {
        if(!svb_file)return;
        fprintf(svb_file,"{\"kind\":\"SVB_CYCLE\",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"reset\":%u,\"capture_valid\":%u,\"capture_ready\":%u,\"capture\":",tick,s.csr,!s.reset_n,s.capture_valid,s.capture_ready);
        image_json(svb_file,s.capture_image);
        fprintf(svb_file,",\"safe_watermark\":%u,\"diagnostic_dump\":%u,\"invalidate_valid\":%u,\"invalidate_bits\":%u,\"flush\":%u,\"promote_valid\":%u,\"promote_ready\":%u,\"promote_entry\":%u,\"promote\":",s.watermark,s.diagnostic,s.invalidate,s.watermark,s.flush,s.promote_valid,s.promote_ready,s.promote_entry);
        image_json(svb_file,s.promote_image);
        fprintf(svb_file,",\"ack_valid\":%u,\"ack_entry\":%u,\"ack_key_valid\":%u,\"ack_writer\":%u,\"ack_generation\":%u,\"ack_content_seq\":%u,\"acked\":%u,\"selected\":%u,\"active_entry\":%u,\"active_line\":%" PRIu64 ",\"active_generation\":%u,\"active_content_seq\":%u,\"occupancy\":%u,\"coalesced\":%u,\"discarded\":%u,\"release_lines\":[%" PRIu64 ",%" PRIu64 ",%" PRIu64 ",%" PRIu64 "],\"release_blocked\":[%u,%u,%u,%u],\"release_entry3\":%u,\"release_line3\":%" PRIu64 ",\"release_content_seq3\":%u,\"release_generation3\":%u}\n",s.ack_valid,s.ack_entry,s.ack_key_valid,s.ack_writer,s.ack_generation,s.ack_seq,s.acked,s.selected,s.active_entry,s.active_line,s.active_generation,s.active_seq,s.occupancy,s.coalesced,s.discarded,s.release_lines[0],s.release_lines[1],s.release_lines[2],s.release_lines[3],s.release_blocked[0],s.release_blocked[1],s.release_blocked[2],s.release_blocked[3],s.release_entry3,s.release_line3,s.release_seq3,s.release_generation3);
        ++svb_window_cycles;
    }
    void svb_event(const char* kind,const Snapshot& s,uint64_t tick,unsigned entry,const Image& im) {
        fprintf(out,"{\"kind\":\"%s\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"entry\":%u,\"payload\":",kind,++records,tick,s.csr,entry);
        image_json(out,im);fprintf(out,"}\n");
    }
    void svb_after(const Snapshot& a,const Snapshot& b,const Vemul___024root& r) {
        if(!a.reset_n||!b.reset_n)return;
        const bool cap=a.capture_valid&&a.capture_ready;
        const bool pro=a.promote_valid&&a.promote_ready;
        const bool ack=a.ack_valid&&a.acked;
        if(cap) {
            ++svb_captures;
            const auto actual=entry_image(r,a.allocated_entry);
            if(!image_equal(actual,a.capture_image))error("svb_capture_full_image_next_state",b.fastest,a.allocated_entry,0);
            if(!(b.valid_mask&(1U<<a.allocated_entry)))error("svb_capture_slot_valid",b.fastest,b.valid_mask,1U<<a.allocated_entry);
            svb_event("SVB_CAPTURE_ACCEPTED",a,b.fastest,a.allocated_entry,a.capture_image);
        }
        if(pro) {
            ++svb_promotions;
            if(!b.sent||!b.active)error("svb_promote_sent_transition",b.fastest,b.sent,1);
            svb_event("SVB_PROMOTE_ACCEPTED",a,b.fastest,a.promote_entry,a.promote_image);
        }
        if(a.ack_valid && !a.acked)error("svb_ack_not_accepted",b.fastest,a.ack_entry,0);
        if(ack) {
            ++svb_acks;
            if(b.valid_mask&(1U<<a.ack_entry))error("svb_ack_slot_still_valid",b.fastest,b.valid_mask,0);
            svb_event("SVB_ACK_ACCEPTED",a,b.fastest,a.ack_entry,entry_image(r,a.ack_entry));
        }
        // At most four contiguous 16-before/128-after windows. Every target
        // cycle in a window is retained, including idle/backpressure cycles.
        // These windows are not reset-started standalone replay certificates.
        if(!window_left && cap && svb_windows<4) {
            if(!svb_file) {
                svb_file=fopen((path+".svb-windows.jsonl").c_str(),"wx");
                if(!svb_file){perror("svb window open");std::exit(91);}
                fprintf(svb_file,"{\"kind\":\"HEADER\",\"schema\":\"ec-svb-contiguous-target-window/1\",\"scope\":\"Complete original generated SVB ports, finite windows only, pre-edge inputs/outputs; no compressed time\"}\n");
            }
            ++svb_windows;
            fprintf(svb_file,"{\"kind\":\"WINDOW_BEGIN\",\"window\":%" PRIu64 ",\"trigger_target_cycle\":%" PRIu64 ",\"pre_cycles\":%u,\"post_cycles\":128}\n",svb_windows,b.fastest,ring_size);
            for(unsigned j=0;j<ring_size;++j) {
                const auto idx=(ring_pos+16-ring_size+j)%16;
                svb_cycle(ring[idx],ring_ticks[idx]);
            }
            window_left=128;
        }
        if(window_left) {
            svb_cycle(a,b.fastest);
            if(!--window_left)fprintf(svb_file,"{\"kind\":\"WINDOW_END\",\"window\":%" PRIu64 ",\"last_target_cycle\":%" PRIu64 "}\n",svb_windows,b.fastest);
            fflush(svb_file);
        }
        ring[ring_pos]=a;ring_ticks[ring_pos]=b.fastest;
        ring_pos=(ring_pos+1)%16;if(ring_size<16)++ring_size;
    }

    void finish() {
        if(!out)return;


        fprintf(out,"{\"kind\":\"SVB_SUMMARY\",\"captures\":%" PRIu64 ",\"promotions\":%" PRIu64 ",\"acks\":%" PRIu64 ",\"windows\":%" PRIu64 ",\"window_cycles\":%" PRIu64 ",\"incomplete_window_tail\":%u}\n",svb_captures,svb_promotions,svb_acks,svb_windows,svb_window_cycles,window_left);
        fprintf(out,"{\"kind\":\"END\",\"record\":%" PRIu64 ",\"boom_edges\":%" PRIu64 ",\"last_fastest_target_cycle\":%" PRIu64 ",\"nonreset_edges\":%" PRIu64 ",\"reset_edges\":%" PRIu64 ",\"sample_errors\":%" PRIu64 ",\"allocations\":%" PRIu64 ",\"accepted\":%" PRIu64 ",\"passed\":%" PRIu64 ",\"failed\":%" PRIu64 ",\"cancelled\":%" PRIu64 "}\n",++records,edges,last_fastest,nonreset_edges,reset_edges,errors,allocations,accepted,pass,fail,cancel);
        if(svb_file){fflush(svb_file);fsync(fileno(svb_file));fclose(svb_file);svb_file=nullptr;}
        fflush(out);fsync(fileno(out));fclose(out);out=nullptr;
    }
};
static Observer* exit_observer=nullptr;
static void external_observer_atexit() { if(exit_observer) exit_observer->finish(); }
int main(int argc,char** argv,char**) {
    Verilated::debug(0);
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->threads(1);contextp->commandArgs(argc,argv);
    const std::unique_ptr<Vemul> topp{new Vemul{contextp.get(),""}};
    Observer observer(std::getenv("EC_EXTERNAL_OBSERVER_FILE"));
    exit_observer=&observer;std::atexit(external_observer_atexit);
    if(vlog_startup_routines) for(auto routinep=&vlog_startup_routines[0];*routinep;routinep++)(*routinep)();
    VerilatedVpi::callCbs(cbStartOfSimulation);
    while(VL_LIKELY(!contextp->gotFinish())) {
        VerilatedVpi::callTimedCbs();
        VerilatedVpi::callCbs(cbNextSimTime);
        VerilatedVpi::callCbs(cbAtStartOfSimTime);
        Snapshot before{};
        if(observer.out)before=capture(*topp->rootp);
        topp->eval();
        if(observer.out)observer.after(before,*topp->rootp,contextp->time());
        VerilatedVpi::callValueCbs();
        VerilatedVpi::callCbs(cbAtEndOfSimTime);
        VerilatedVpi::callCbs(cbReadWriteSynch);
        VerilatedVpi::callCbs(cbReadOnlySynch);
        if(!topp->eventsPending())break;
        contextp->time(std::min(topp->nextTimeSlot(),VerilatedVpi::cbNextDeadline()));
    }
    topp->final();VerilatedVpi::callCbs(cbEndOfSimulation);
    observer.finish();exit_observer=nullptr;contextp->statsPrintSummary();return 0;
}
