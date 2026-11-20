#include "VSpaceTimePair.h"
#include "verilated.h"
#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
using Data=std::array<uint32_t,3>;
VSpaceTimePair d;
std::mt19937_64 gen(8491167);
void set_r_addr(int i,uint32_t x){switch(i){
case 0: d.io_model_read_cmds_0_bits_addr=x;d.io_reference_read_cmds_0_addr=x;break;
case 1: d.io_model_read_cmds_1_bits_addr=x;d.io_reference_read_cmds_1_addr=x;break;
case 2: d.io_model_read_cmds_2_bits_addr=x;d.io_reference_read_cmds_2_addr=x;break;
case 3: d.io_model_read_cmds_3_bits_addr=x;d.io_reference_read_cmds_3_addr=x;break;
case 4: d.io_model_read_cmds_4_bits_addr=x;d.io_reference_read_cmds_4_addr=x;break;
case 5: d.io_model_read_cmds_5_bits_addr=x;d.io_reference_read_cmds_5_addr=x;break;
case 6: d.io_model_read_cmds_6_bits_addr=x;d.io_reference_read_cmds_6_addr=x;break;
case 7: d.io_model_read_cmds_7_bits_addr=x;d.io_reference_read_cmds_7_addr=x;break;
case 8: d.io_model_read_cmds_8_bits_addr=x;d.io_reference_read_cmds_8_addr=x;break;
case 9: d.io_model_read_cmds_9_bits_addr=x;d.io_reference_read_cmds_9_addr=x;break;
case 10: d.io_model_read_cmds_10_bits_addr=x;d.io_reference_read_cmds_10_addr=x;break;
case 11: d.io_model_read_cmds_11_bits_addr=x;d.io_reference_read_cmds_11_addr=x;break;
case 12: d.io_model_read_cmds_12_bits_addr=x;d.io_reference_read_cmds_12_addr=x;break;
case 13: d.io_model_read_cmds_13_bits_addr=x;d.io_reference_read_cmds_13_addr=x;break;
case 14: d.io_model_read_cmds_14_bits_addr=x;d.io_reference_read_cmds_14_addr=x;break;
case 15: d.io_model_read_cmds_15_bits_addr=x;d.io_reference_read_cmds_15_addr=x;break;
case 16: d.io_model_read_cmds_16_bits_addr=x;d.io_reference_read_cmds_16_addr=x;break;
case 17: d.io_model_read_cmds_17_bits_addr=x;d.io_reference_read_cmds_17_addr=x;break;
case 18: d.io_model_read_cmds_18_bits_addr=x;d.io_reference_read_cmds_18_addr=x;break;
case 19: d.io_model_read_cmds_19_bits_addr=x;d.io_reference_read_cmds_19_addr=x;break;
case 20: d.io_model_read_cmds_20_bits_addr=x;d.io_reference_read_cmds_20_addr=x;break;
case 21: d.io_model_read_cmds_21_bits_addr=x;d.io_reference_read_cmds_21_addr=x;break;
case 22: d.io_model_read_cmds_22_bits_addr=x;d.io_reference_read_cmds_22_addr=x;break;
case 23: d.io_model_read_cmds_23_bits_addr=x;d.io_reference_read_cmds_23_addr=x;break;
case 24: d.io_model_read_cmds_24_bits_addr=x;d.io_reference_read_cmds_24_addr=x;break;
case 25: d.io_model_read_cmds_25_bits_addr=x;d.io_reference_read_cmds_25_addr=x;break;
case 26: d.io_model_read_cmds_26_bits_addr=x;d.io_reference_read_cmds_26_addr=x;break;
case 27: d.io_model_read_cmds_27_bits_addr=x;d.io_reference_read_cmds_27_addr=x;break;
case 28: d.io_model_read_cmds_28_bits_addr=x;d.io_reference_read_cmds_28_addr=x;break;
case 29: d.io_model_read_cmds_29_bits_addr=x;d.io_reference_read_cmds_29_addr=x;break;
case 30: d.io_model_read_cmds_30_bits_addr=x;d.io_reference_read_cmds_30_addr=x;break;
case 31: d.io_model_read_cmds_31_bits_addr=x;d.io_reference_read_cmds_31_addr=x;break;
case 32: d.io_model_read_cmds_32_bits_addr=x;d.io_reference_read_cmds_32_addr=x;break;
case 33: d.io_model_read_cmds_33_bits_addr=x;d.io_reference_read_cmds_33_addr=x;break;
case 34: d.io_model_read_cmds_34_bits_addr=x;d.io_reference_read_cmds_34_addr=x;break;
}}
void set_r_en(int i,uint32_t x){switch(i){
case 0: d.io_model_read_cmds_0_bits_en=x;d.io_reference_read_cmds_0_en=x;break;
case 1: d.io_model_read_cmds_1_bits_en=x;d.io_reference_read_cmds_1_en=x;break;
case 2: d.io_model_read_cmds_2_bits_en=x;d.io_reference_read_cmds_2_en=x;break;
case 3: d.io_model_read_cmds_3_bits_en=x;d.io_reference_read_cmds_3_en=x;break;
case 4: d.io_model_read_cmds_4_bits_en=x;d.io_reference_read_cmds_4_en=x;break;
case 5: d.io_model_read_cmds_5_bits_en=x;d.io_reference_read_cmds_5_en=x;break;
case 6: d.io_model_read_cmds_6_bits_en=x;d.io_reference_read_cmds_6_en=x;break;
case 7: d.io_model_read_cmds_7_bits_en=x;d.io_reference_read_cmds_7_en=x;break;
case 8: d.io_model_read_cmds_8_bits_en=x;d.io_reference_read_cmds_8_en=x;break;
case 9: d.io_model_read_cmds_9_bits_en=x;d.io_reference_read_cmds_9_en=x;break;
case 10: d.io_model_read_cmds_10_bits_en=x;d.io_reference_read_cmds_10_en=x;break;
case 11: d.io_model_read_cmds_11_bits_en=x;d.io_reference_read_cmds_11_en=x;break;
case 12: d.io_model_read_cmds_12_bits_en=x;d.io_reference_read_cmds_12_en=x;break;
case 13: d.io_model_read_cmds_13_bits_en=x;d.io_reference_read_cmds_13_en=x;break;
case 14: d.io_model_read_cmds_14_bits_en=x;d.io_reference_read_cmds_14_en=x;break;
case 15: d.io_model_read_cmds_15_bits_en=x;d.io_reference_read_cmds_15_en=x;break;
case 16: d.io_model_read_cmds_16_bits_en=x;d.io_reference_read_cmds_16_en=x;break;
case 17: d.io_model_read_cmds_17_bits_en=x;d.io_reference_read_cmds_17_en=x;break;
case 18: d.io_model_read_cmds_18_bits_en=x;d.io_reference_read_cmds_18_en=x;break;
case 19: d.io_model_read_cmds_19_bits_en=x;d.io_reference_read_cmds_19_en=x;break;
case 20: d.io_model_read_cmds_20_bits_en=x;d.io_reference_read_cmds_20_en=x;break;
case 21: d.io_model_read_cmds_21_bits_en=x;d.io_reference_read_cmds_21_en=x;break;
case 22: d.io_model_read_cmds_22_bits_en=x;d.io_reference_read_cmds_22_en=x;break;
case 23: d.io_model_read_cmds_23_bits_en=x;d.io_reference_read_cmds_23_en=x;break;
case 24: d.io_model_read_cmds_24_bits_en=x;d.io_reference_read_cmds_24_en=x;break;
case 25: d.io_model_read_cmds_25_bits_en=x;d.io_reference_read_cmds_25_en=x;break;
case 26: d.io_model_read_cmds_26_bits_en=x;d.io_reference_read_cmds_26_en=x;break;
case 27: d.io_model_read_cmds_27_bits_en=x;d.io_reference_read_cmds_27_en=x;break;
case 28: d.io_model_read_cmds_28_bits_en=x;d.io_reference_read_cmds_28_en=x;break;
case 29: d.io_model_read_cmds_29_bits_en=x;d.io_reference_read_cmds_29_en=x;break;
case 30: d.io_model_read_cmds_30_bits_en=x;d.io_reference_read_cmds_30_en=x;break;
case 31: d.io_model_read_cmds_31_bits_en=x;d.io_reference_read_cmds_31_en=x;break;
case 32: d.io_model_read_cmds_32_bits_en=x;d.io_reference_read_cmds_32_en=x;break;
case 33: d.io_model_read_cmds_33_bits_en=x;d.io_reference_read_cmds_33_en=x;break;
case 34: d.io_model_read_cmds_34_bits_en=x;d.io_reference_read_cmds_34_en=x;break;
}}
void set_w_addr(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_addr=x;d.io_reference_write_cmds_0_addr=x;break;
}}
void set_w_en(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_en=x;d.io_reference_write_cmds_0_en=x;break;
}}
void set_w_mask(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_mask=x;d.io_reference_write_cmds_0_mask=x;break;
}}
void r_valid(int i,bool x){switch(i){
case 0: d.io_model_read_cmds_0_valid=x;break;
case 1: d.io_model_read_cmds_1_valid=x;break;
case 2: d.io_model_read_cmds_2_valid=x;break;
case 3: d.io_model_read_cmds_3_valid=x;break;
case 4: d.io_model_read_cmds_4_valid=x;break;
case 5: d.io_model_read_cmds_5_valid=x;break;
case 6: d.io_model_read_cmds_6_valid=x;break;
case 7: d.io_model_read_cmds_7_valid=x;break;
case 8: d.io_model_read_cmds_8_valid=x;break;
case 9: d.io_model_read_cmds_9_valid=x;break;
case 10: d.io_model_read_cmds_10_valid=x;break;
case 11: d.io_model_read_cmds_11_valid=x;break;
case 12: d.io_model_read_cmds_12_valid=x;break;
case 13: d.io_model_read_cmds_13_valid=x;break;
case 14: d.io_model_read_cmds_14_valid=x;break;
case 15: d.io_model_read_cmds_15_valid=x;break;
case 16: d.io_model_read_cmds_16_valid=x;break;
case 17: d.io_model_read_cmds_17_valid=x;break;
case 18: d.io_model_read_cmds_18_valid=x;break;
case 19: d.io_model_read_cmds_19_valid=x;break;
case 20: d.io_model_read_cmds_20_valid=x;break;
case 21: d.io_model_read_cmds_21_valid=x;break;
case 22: d.io_model_read_cmds_22_valid=x;break;
case 23: d.io_model_read_cmds_23_valid=x;break;
case 24: d.io_model_read_cmds_24_valid=x;break;
case 25: d.io_model_read_cmds_25_valid=x;break;
case 26: d.io_model_read_cmds_26_valid=x;break;
case 27: d.io_model_read_cmds_27_valid=x;break;
case 28: d.io_model_read_cmds_28_valid=x;break;
case 29: d.io_model_read_cmds_29_valid=x;break;
case 30: d.io_model_read_cmds_30_valid=x;break;
case 31: d.io_model_read_cmds_31_valid=x;break;
case 32: d.io_model_read_cmds_32_valid=x;break;
case 33: d.io_model_read_cmds_33_valid=x;break;
case 34: d.io_model_read_cmds_34_valid=x;break;
}}
bool r_ready(int i){switch(i){
case 0: return d.io_model_read_cmds_0_ready;
case 1: return d.io_model_read_cmds_1_ready;
case 2: return d.io_model_read_cmds_2_ready;
case 3: return d.io_model_read_cmds_3_ready;
case 4: return d.io_model_read_cmds_4_ready;
case 5: return d.io_model_read_cmds_5_ready;
case 6: return d.io_model_read_cmds_6_ready;
case 7: return d.io_model_read_cmds_7_ready;
case 8: return d.io_model_read_cmds_8_ready;
case 9: return d.io_model_read_cmds_9_ready;
case 10: return d.io_model_read_cmds_10_ready;
case 11: return d.io_model_read_cmds_11_ready;
case 12: return d.io_model_read_cmds_12_ready;
case 13: return d.io_model_read_cmds_13_ready;
case 14: return d.io_model_read_cmds_14_ready;
case 15: return d.io_model_read_cmds_15_ready;
case 16: return d.io_model_read_cmds_16_ready;
case 17: return d.io_model_read_cmds_17_ready;
case 18: return d.io_model_read_cmds_18_ready;
case 19: return d.io_model_read_cmds_19_ready;
case 20: return d.io_model_read_cmds_20_ready;
case 21: return d.io_model_read_cmds_21_ready;
case 22: return d.io_model_read_cmds_22_ready;
case 23: return d.io_model_read_cmds_23_ready;
case 24: return d.io_model_read_cmds_24_ready;
case 25: return d.io_model_read_cmds_25_ready;
case 26: return d.io_model_read_cmds_26_ready;
case 27: return d.io_model_read_cmds_27_ready;
case 28: return d.io_model_read_cmds_28_ready;
case 29: return d.io_model_read_cmds_29_ready;
case 30: return d.io_model_read_cmds_30_ready;
case 31: return d.io_model_read_cmds_31_ready;
case 32: return d.io_model_read_cmds_32_ready;
case 33: return d.io_model_read_cmds_33_ready;
case 34: return d.io_model_read_cmds_34_ready;
}return false;}
void w_valid(int i,bool x){switch(i){
case 0: d.io_model_write_cmds_0_valid=x;break;
}}
bool w_ready(int i){switch(i){
case 0: return d.io_model_write_cmds_0_ready;
}return false;}
void resp_ready(int i,bool x){switch(i){
case 0: d.io_model_read_resps_0_ready=x;break;
case 1: d.io_model_read_resps_1_ready=x;break;
case 2: d.io_model_read_resps_2_ready=x;break;
case 3: d.io_model_read_resps_3_ready=x;break;
case 4: d.io_model_read_resps_4_ready=x;break;
case 5: d.io_model_read_resps_5_ready=x;break;
case 6: d.io_model_read_resps_6_ready=x;break;
case 7: d.io_model_read_resps_7_ready=x;break;
case 8: d.io_model_read_resps_8_ready=x;break;
case 9: d.io_model_read_resps_9_ready=x;break;
case 10: d.io_model_read_resps_10_ready=x;break;
case 11: d.io_model_read_resps_11_ready=x;break;
case 12: d.io_model_read_resps_12_ready=x;break;
case 13: d.io_model_read_resps_13_ready=x;break;
case 14: d.io_model_read_resps_14_ready=x;break;
case 15: d.io_model_read_resps_15_ready=x;break;
case 16: d.io_model_read_resps_16_ready=x;break;
case 17: d.io_model_read_resps_17_ready=x;break;
case 18: d.io_model_read_resps_18_ready=x;break;
case 19: d.io_model_read_resps_19_ready=x;break;
case 20: d.io_model_read_resps_20_ready=x;break;
case 21: d.io_model_read_resps_21_ready=x;break;
case 22: d.io_model_read_resps_22_ready=x;break;
case 23: d.io_model_read_resps_23_ready=x;break;
case 24: d.io_model_read_resps_24_ready=x;break;
case 25: d.io_model_read_resps_25_ready=x;break;
case 26: d.io_model_read_resps_26_ready=x;break;
case 27: d.io_model_read_resps_27_ready=x;break;
case 28: d.io_model_read_resps_28_ready=x;break;
case 29: d.io_model_read_resps_29_ready=x;break;
case 30: d.io_model_read_resps_30_ready=x;break;
case 31: d.io_model_read_resps_31_ready=x;break;
case 32: d.io_model_read_resps_32_ready=x;break;
case 33: d.io_model_read_resps_33_ready=x;break;
case 34: d.io_model_read_resps_34_ready=x;break;
}}
bool resp_valid(int i){switch(i){
case 0: return d.io_model_read_resps_0_valid;
case 1: return d.io_model_read_resps_1_valid;
case 2: return d.io_model_read_resps_2_valid;
case 3: return d.io_model_read_resps_3_valid;
case 4: return d.io_model_read_resps_4_valid;
case 5: return d.io_model_read_resps_5_valid;
case 6: return d.io_model_read_resps_6_valid;
case 7: return d.io_model_read_resps_7_valid;
case 8: return d.io_model_read_resps_8_valid;
case 9: return d.io_model_read_resps_9_valid;
case 10: return d.io_model_read_resps_10_valid;
case 11: return d.io_model_read_resps_11_valid;
case 12: return d.io_model_read_resps_12_valid;
case 13: return d.io_model_read_resps_13_valid;
case 14: return d.io_model_read_resps_14_valid;
case 15: return d.io_model_read_resps_15_valid;
case 16: return d.io_model_read_resps_16_valid;
case 17: return d.io_model_read_resps_17_valid;
case 18: return d.io_model_read_resps_18_valid;
case 19: return d.io_model_read_resps_19_valid;
case 20: return d.io_model_read_resps_20_valid;
case 21: return d.io_model_read_resps_21_valid;
case 22: return d.io_model_read_resps_22_valid;
case 23: return d.io_model_read_resps_23_valid;
case 24: return d.io_model_read_resps_24_valid;
case 25: return d.io_model_read_resps_25_valid;
case 26: return d.io_model_read_resps_26_valid;
case 27: return d.io_model_read_resps_27_valid;
case 28: return d.io_model_read_resps_28_valid;
case 29: return d.io_model_read_resps_29_valid;
case 30: return d.io_model_read_resps_30_valid;
case 31: return d.io_model_read_resps_31_valid;
case 32: return d.io_model_read_resps_32_valid;
case 33: return d.io_model_read_resps_33_valid;
case 34: return d.io_model_read_resps_34_valid;
}return false;}
Data response(int i,bool ref){Data v{};switch(i){
case 0:
v[0]=ref ? d.io_reference_read_resps_0[0] : d.io_model_read_resps_0_bits[0];
v[1]=ref ? d.io_reference_read_resps_0[1] : d.io_model_read_resps_0_bits[1];
v[2]=ref ? d.io_reference_read_resps_0[2] : d.io_model_read_resps_0_bits[2];
break;
case 1:
v[0]=ref ? d.io_reference_read_resps_1[0] : d.io_model_read_resps_1_bits[0];
v[1]=ref ? d.io_reference_read_resps_1[1] : d.io_model_read_resps_1_bits[1];
v[2]=ref ? d.io_reference_read_resps_1[2] : d.io_model_read_resps_1_bits[2];
break;
case 2:
v[0]=ref ? d.io_reference_read_resps_2[0] : d.io_model_read_resps_2_bits[0];
v[1]=ref ? d.io_reference_read_resps_2[1] : d.io_model_read_resps_2_bits[1];
v[2]=ref ? d.io_reference_read_resps_2[2] : d.io_model_read_resps_2_bits[2];
break;
case 3:
v[0]=ref ? d.io_reference_read_resps_3[0] : d.io_model_read_resps_3_bits[0];
v[1]=ref ? d.io_reference_read_resps_3[1] : d.io_model_read_resps_3_bits[1];
v[2]=ref ? d.io_reference_read_resps_3[2] : d.io_model_read_resps_3_bits[2];
break;
case 4:
v[0]=ref ? d.io_reference_read_resps_4[0] : d.io_model_read_resps_4_bits[0];
v[1]=ref ? d.io_reference_read_resps_4[1] : d.io_model_read_resps_4_bits[1];
v[2]=ref ? d.io_reference_read_resps_4[2] : d.io_model_read_resps_4_bits[2];
break;
case 5:
v[0]=ref ? d.io_reference_read_resps_5[0] : d.io_model_read_resps_5_bits[0];
v[1]=ref ? d.io_reference_read_resps_5[1] : d.io_model_read_resps_5_bits[1];
v[2]=ref ? d.io_reference_read_resps_5[2] : d.io_model_read_resps_5_bits[2];
break;
case 6:
v[0]=ref ? d.io_reference_read_resps_6[0] : d.io_model_read_resps_6_bits[0];
v[1]=ref ? d.io_reference_read_resps_6[1] : d.io_model_read_resps_6_bits[1];
v[2]=ref ? d.io_reference_read_resps_6[2] : d.io_model_read_resps_6_bits[2];
break;
case 7:
v[0]=ref ? d.io_reference_read_resps_7[0] : d.io_model_read_resps_7_bits[0];
v[1]=ref ? d.io_reference_read_resps_7[1] : d.io_model_read_resps_7_bits[1];
v[2]=ref ? d.io_reference_read_resps_7[2] : d.io_model_read_resps_7_bits[2];
break;
case 8:
v[0]=ref ? d.io_reference_read_resps_8[0] : d.io_model_read_resps_8_bits[0];
v[1]=ref ? d.io_reference_read_resps_8[1] : d.io_model_read_resps_8_bits[1];
v[2]=ref ? d.io_reference_read_resps_8[2] : d.io_model_read_resps_8_bits[2];
break;
case 9:
v[0]=ref ? d.io_reference_read_resps_9[0] : d.io_model_read_resps_9_bits[0];
v[1]=ref ? d.io_reference_read_resps_9[1] : d.io_model_read_resps_9_bits[1];
v[2]=ref ? d.io_reference_read_resps_9[2] : d.io_model_read_resps_9_bits[2];
break;
case 10:
v[0]=ref ? d.io_reference_read_resps_10[0] : d.io_model_read_resps_10_bits[0];
v[1]=ref ? d.io_reference_read_resps_10[1] : d.io_model_read_resps_10_bits[1];
v[2]=ref ? d.io_reference_read_resps_10[2] : d.io_model_read_resps_10_bits[2];
break;
case 11:
v[0]=ref ? d.io_reference_read_resps_11[0] : d.io_model_read_resps_11_bits[0];
v[1]=ref ? d.io_reference_read_resps_11[1] : d.io_model_read_resps_11_bits[1];
v[2]=ref ? d.io_reference_read_resps_11[2] : d.io_model_read_resps_11_bits[2];
break;
case 12:
v[0]=ref ? d.io_reference_read_resps_12[0] : d.io_model_read_resps_12_bits[0];
v[1]=ref ? d.io_reference_read_resps_12[1] : d.io_model_read_resps_12_bits[1];
v[2]=ref ? d.io_reference_read_resps_12[2] : d.io_model_read_resps_12_bits[2];
break;
case 13:
v[0]=ref ? d.io_reference_read_resps_13[0] : d.io_model_read_resps_13_bits[0];
v[1]=ref ? d.io_reference_read_resps_13[1] : d.io_model_read_resps_13_bits[1];
v[2]=ref ? d.io_reference_read_resps_13[2] : d.io_model_read_resps_13_bits[2];
break;
case 14:
v[0]=ref ? d.io_reference_read_resps_14[0] : d.io_model_read_resps_14_bits[0];
v[1]=ref ? d.io_reference_read_resps_14[1] : d.io_model_read_resps_14_bits[1];
v[2]=ref ? d.io_reference_read_resps_14[2] : d.io_model_read_resps_14_bits[2];
break;
case 15:
v[0]=ref ? d.io_reference_read_resps_15[0] : d.io_model_read_resps_15_bits[0];
v[1]=ref ? d.io_reference_read_resps_15[1] : d.io_model_read_resps_15_bits[1];
v[2]=ref ? d.io_reference_read_resps_15[2] : d.io_model_read_resps_15_bits[2];
break;
case 16:
v[0]=ref ? d.io_reference_read_resps_16[0] : d.io_model_read_resps_16_bits[0];
v[1]=ref ? d.io_reference_read_resps_16[1] : d.io_model_read_resps_16_bits[1];
v[2]=ref ? d.io_reference_read_resps_16[2] : d.io_model_read_resps_16_bits[2];
break;
case 17:
v[0]=ref ? d.io_reference_read_resps_17[0] : d.io_model_read_resps_17_bits[0];
v[1]=ref ? d.io_reference_read_resps_17[1] : d.io_model_read_resps_17_bits[1];
v[2]=ref ? d.io_reference_read_resps_17[2] : d.io_model_read_resps_17_bits[2];
break;
case 18:
v[0]=ref ? d.io_reference_read_resps_18[0] : d.io_model_read_resps_18_bits[0];
v[1]=ref ? d.io_reference_read_resps_18[1] : d.io_model_read_resps_18_bits[1];
v[2]=ref ? d.io_reference_read_resps_18[2] : d.io_model_read_resps_18_bits[2];
break;
case 19:
v[0]=ref ? d.io_reference_read_resps_19[0] : d.io_model_read_resps_19_bits[0];
v[1]=ref ? d.io_reference_read_resps_19[1] : d.io_model_read_resps_19_bits[1];
v[2]=ref ? d.io_reference_read_resps_19[2] : d.io_model_read_resps_19_bits[2];
break;
case 20:
v[0]=ref ? d.io_reference_read_resps_20[0] : d.io_model_read_resps_20_bits[0];
v[1]=ref ? d.io_reference_read_resps_20[1] : d.io_model_read_resps_20_bits[1];
v[2]=ref ? d.io_reference_read_resps_20[2] : d.io_model_read_resps_20_bits[2];
break;
case 21:
v[0]=ref ? d.io_reference_read_resps_21[0] : d.io_model_read_resps_21_bits[0];
v[1]=ref ? d.io_reference_read_resps_21[1] : d.io_model_read_resps_21_bits[1];
v[2]=ref ? d.io_reference_read_resps_21[2] : d.io_model_read_resps_21_bits[2];
break;
case 22:
v[0]=ref ? d.io_reference_read_resps_22[0] : d.io_model_read_resps_22_bits[0];
v[1]=ref ? d.io_reference_read_resps_22[1] : d.io_model_read_resps_22_bits[1];
v[2]=ref ? d.io_reference_read_resps_22[2] : d.io_model_read_resps_22_bits[2];
break;
case 23:
v[0]=ref ? d.io_reference_read_resps_23[0] : d.io_model_read_resps_23_bits[0];
v[1]=ref ? d.io_reference_read_resps_23[1] : d.io_model_read_resps_23_bits[1];
v[2]=ref ? d.io_reference_read_resps_23[2] : d.io_model_read_resps_23_bits[2];
break;
case 24:
v[0]=ref ? d.io_reference_read_resps_24[0] : d.io_model_read_resps_24_bits[0];
v[1]=ref ? d.io_reference_read_resps_24[1] : d.io_model_read_resps_24_bits[1];
v[2]=ref ? d.io_reference_read_resps_24[2] : d.io_model_read_resps_24_bits[2];
break;
case 25:
v[0]=ref ? d.io_reference_read_resps_25[0] : d.io_model_read_resps_25_bits[0];
v[1]=ref ? d.io_reference_read_resps_25[1] : d.io_model_read_resps_25_bits[1];
v[2]=ref ? d.io_reference_read_resps_25[2] : d.io_model_read_resps_25_bits[2];
break;
case 26:
v[0]=ref ? d.io_reference_read_resps_26[0] : d.io_model_read_resps_26_bits[0];
v[1]=ref ? d.io_reference_read_resps_26[1] : d.io_model_read_resps_26_bits[1];
v[2]=ref ? d.io_reference_read_resps_26[2] : d.io_model_read_resps_26_bits[2];
break;
case 27:
v[0]=ref ? d.io_reference_read_resps_27[0] : d.io_model_read_resps_27_bits[0];
v[1]=ref ? d.io_reference_read_resps_27[1] : d.io_model_read_resps_27_bits[1];
v[2]=ref ? d.io_reference_read_resps_27[2] : d.io_model_read_resps_27_bits[2];
break;
case 28:
v[0]=ref ? d.io_reference_read_resps_28[0] : d.io_model_read_resps_28_bits[0];
v[1]=ref ? d.io_reference_read_resps_28[1] : d.io_model_read_resps_28_bits[1];
v[2]=ref ? d.io_reference_read_resps_28[2] : d.io_model_read_resps_28_bits[2];
break;
case 29:
v[0]=ref ? d.io_reference_read_resps_29[0] : d.io_model_read_resps_29_bits[0];
v[1]=ref ? d.io_reference_read_resps_29[1] : d.io_model_read_resps_29_bits[1];
v[2]=ref ? d.io_reference_read_resps_29[2] : d.io_model_read_resps_29_bits[2];
break;
case 30:
v[0]=ref ? d.io_reference_read_resps_30[0] : d.io_model_read_resps_30_bits[0];
v[1]=ref ? d.io_reference_read_resps_30[1] : d.io_model_read_resps_30_bits[1];
v[2]=ref ? d.io_reference_read_resps_30[2] : d.io_model_read_resps_30_bits[2];
break;
case 31:
v[0]=ref ? d.io_reference_read_resps_31[0] : d.io_model_read_resps_31_bits[0];
v[1]=ref ? d.io_reference_read_resps_31[1] : d.io_model_read_resps_31_bits[1];
v[2]=ref ? d.io_reference_read_resps_31[2] : d.io_model_read_resps_31_bits[2];
break;
case 32:
v[0]=ref ? d.io_reference_read_resps_32[0] : d.io_model_read_resps_32_bits[0];
v[1]=ref ? d.io_reference_read_resps_32[1] : d.io_model_read_resps_32_bits[1];
v[2]=ref ? d.io_reference_read_resps_32[2] : d.io_model_read_resps_32_bits[2];
break;
case 33:
v[0]=ref ? d.io_reference_read_resps_33[0] : d.io_model_read_resps_33_bits[0];
v[1]=ref ? d.io_reference_read_resps_33[1] : d.io_model_read_resps_33_bits[1];
v[2]=ref ? d.io_reference_read_resps_33[2] : d.io_model_read_resps_33_bits[2];
break;
case 34:
v[0]=ref ? d.io_reference_read_resps_34[0] : d.io_model_read_resps_34_bits[0];
v[1]=ref ? d.io_reference_read_resps_34[1] : d.io_model_read_resps_34_bits[1];
v[2]=ref ? d.io_reference_read_resps_34[2] : d.io_model_read_resps_34_bits[2];
break;
}return v;}
void set_data(int i,Data v){switch(i){
case 0:
d.io_model_write_cmds_0_bits_data[0]=v[0];
d.io_model_write_cmds_0_bits_data[1]=v[1];
d.io_model_write_cmds_0_bits_data[2]=v[2];
d.io_reference_write_cmds_0_data[0]=v[0];
d.io_reference_write_cmds_0_data[1]=v[1];
d.io_reference_write_cmds_0_data[2]=v[2];
break;
}}
int main(int argc,char**argv){
  const bool negative=argc>1; const int R=35,W=1; Data mem[512]{};
  bool initialized[512]{}; uint64_t hosts=0,compared=0,conflicts=0,resets=0,collisions=0;
  auto began=std::chrono::steady_clock::now();
  d.clock=0;d.reset=1;d.io_targetClock=0;d.io_targetReset=0;d.io_model_reset_valid=0;
  for(int i=0;i<R;i++){r_valid(i,0);resp_ready(i,0);} for(int i=0;i<W;i++)w_valid(i,0);
  for(int i=0;i<5;i++){d.clock=0;d.eval();d.clock=1;d.eval();}d.clock=0;d.reset=0;d.eval();
  for(int t=0;t<8192;t++){
    bool tr=t>=512 && t%173==0;resets+=tr;d.io_targetReset=tr;d.io_model_reset_bits=tr;
    bool rd[R]{},wr[W]{},resp[R]{},rst=false;int ra[R],wa[W];bool wen[W];Data wd[W];
    for(int i=0;i<W;i++){
      wa[i]=t<512 ? t : gen()%512; if(i>0 && t%7==0)wa[i]=wa[0];
      wen[i]=t<512 || gen()%4; wd[i]={uint32_t(gen()),uint32_t(gen()),uint32_t(gen())&131071};
      if(81<=64)wd[i][2]=0;
      set_w_addr(i,wa[i]);set_w_en(i,wen[i]);set_w_mask(i,1);set_data(i,wd[i]);
      if(i>0 && wa[i]==wa[0] && wen[i] && wen[0])collisions++;
    }
    for(int i=0;i<R;i++){
      ra[i]=t>=512 && i==0 ? wa[0] : gen()%512;
      conflicts+=t>=512 && ra[i]==wa[0] && wen[0];set_r_addr(i,ra[i]);set_r_en(i,1);
    }
    d.clock=0;d.eval();Data expected[R];
    for(int i=0;i<R;i++){expected[i]=response(i,true);if(initialized[ra[i]] && expected[i]!=mem[ra[i]])throw std::runtime_error("reference mismatch");}
    int h=0;
    while(true){
      if(++h>1000)throw std::runtime_error("watchdog");
      d.io_model_reset_valid=!rst;
      for(int i=0;i<R;i++){r_valid(i,!rd[i] && gen()%5!=0);resp_ready(i,!resp[i] && gen()%4!=0);}
      for(int i=0;i<W;i++)w_valid(i,!wr[i] && gen()%5!=0);
      d.clock=0;d.eval();
      if(d.io_model_reset_valid && d.io_model_reset_ready)rst=true;
      for(int i=0;i<R;i++){
        if(d.io_model_read_resps_0_valid){} // model evaluated above before edge
        bool valid=false;switch(i){case 0:valid=d.io_model_read_resps_0_valid;break;case 1:valid=d.io_model_read_resps_1_valid;break;case 2:valid=d.io_model_read_resps_2_valid;break;case 3:valid=d.io_model_read_resps_3_valid;break;case 4:valid=d.io_model_read_resps_4_valid;break;case 5:valid=d.io_model_read_resps_5_valid;break;case 6:valid=d.io_model_read_resps_6_valid;break;case 7:valid=d.io_model_read_resps_7_valid;break;case 8:valid=d.io_model_read_resps_8_valid;break;case 9:valid=d.io_model_read_resps_9_valid;break;case 10:valid=d.io_model_read_resps_10_valid;break;case 11:valid=d.io_model_read_resps_11_valid;break;case 12:valid=d.io_model_read_resps_12_valid;break;case 13:valid=d.io_model_read_resps_13_valid;break;case 14:valid=d.io_model_read_resps_14_valid;break;case 15:valid=d.io_model_read_resps_15_valid;break;case 16:valid=d.io_model_read_resps_16_valid;break;case 17:valid=d.io_model_read_resps_17_valid;break;case 18:valid=d.io_model_read_resps_18_valid;break;case 19:valid=d.io_model_read_resps_19_valid;break;case 20:valid=d.io_model_read_resps_20_valid;break;case 21:valid=d.io_model_read_resps_21_valid;break;case 22:valid=d.io_model_read_resps_22_valid;break;case 23:valid=d.io_model_read_resps_23_valid;break;case 24:valid=d.io_model_read_resps_24_valid;break;case 25:valid=d.io_model_read_resps_25_valid;break;case 26:valid=d.io_model_read_resps_26_valid;break;case 27:valid=d.io_model_read_resps_27_valid;break;case 28:valid=d.io_model_read_resps_28_valid;break;case 29:valid=d.io_model_read_resps_29_valid;break;case 30:valid=d.io_model_read_resps_30_valid;break;case 31:valid=d.io_model_read_resps_31_valid;break;case 32:valid=d.io_model_read_resps_32_valid;break;case 33:valid=d.io_model_read_resps_33_valid;break;case 34:valid=d.io_model_read_resps_34_valid;break;}
        bool ready=false;switch(i){case 0:ready=d.io_model_read_resps_0_ready;break;case 1:ready=d.io_model_read_resps_1_ready;break;case 2:ready=d.io_model_read_resps_2_ready;break;case 3:ready=d.io_model_read_resps_3_ready;break;case 4:ready=d.io_model_read_resps_4_ready;break;case 5:ready=d.io_model_read_resps_5_ready;break;case 6:ready=d.io_model_read_resps_6_ready;break;case 7:ready=d.io_model_read_resps_7_ready;break;case 8:ready=d.io_model_read_resps_8_ready;break;case 9:ready=d.io_model_read_resps_9_ready;break;case 10:ready=d.io_model_read_resps_10_ready;break;case 11:ready=d.io_model_read_resps_11_ready;break;case 12:ready=d.io_model_read_resps_12_ready;break;case 13:ready=d.io_model_read_resps_13_ready;break;case 14:ready=d.io_model_read_resps_14_ready;break;case 15:ready=d.io_model_read_resps_15_ready;break;case 16:ready=d.io_model_read_resps_16_ready;break;case 17:ready=d.io_model_read_resps_17_ready;break;case 18:ready=d.io_model_read_resps_18_ready;break;case 19:ready=d.io_model_read_resps_19_ready;break;case 20:ready=d.io_model_read_resps_20_ready;break;case 21:ready=d.io_model_read_resps_21_ready;break;case 22:ready=d.io_model_read_resps_22_ready;break;case 23:ready=d.io_model_read_resps_23_ready;break;case 24:ready=d.io_model_read_resps_24_ready;break;case 25:ready=d.io_model_read_resps_25_ready;break;case 26:ready=d.io_model_read_resps_26_ready;break;case 27:ready=d.io_model_read_resps_27_ready;break;case 28:ready=d.io_model_read_resps_28_ready;break;case 29:ready=d.io_model_read_resps_29_ready;break;case 30:ready=d.io_model_read_resps_30_ready;break;case 31:ready=d.io_model_read_resps_31_ready;break;case 32:ready=d.io_model_read_resps_32_ready;break;case 33:ready=d.io_model_read_resps_33_ready;break;case 34:ready=d.io_model_read_resps_34_ready;break;}
        if(valid && ready){Data got=response(i,false);if(negative && t==513 && i==0)got[0]^=1;
          if(initialized[ra[i]] && got!=expected[i]){std::cerr<<"MISMATCH target="<<t<<" read="<<i<<"\n";return 2;}
          compared+=initialized[ra[i]];resp[i]=true;
        }
        bool v=false;switch(i){case 0:v=d.io_model_read_cmds_0_valid;break;case 1:v=d.io_model_read_cmds_1_valid;break;case 2:v=d.io_model_read_cmds_2_valid;break;case 3:v=d.io_model_read_cmds_3_valid;break;case 4:v=d.io_model_read_cmds_4_valid;break;case 5:v=d.io_model_read_cmds_5_valid;break;case 6:v=d.io_model_read_cmds_6_valid;break;case 7:v=d.io_model_read_cmds_7_valid;break;case 8:v=d.io_model_read_cmds_8_valid;break;case 9:v=d.io_model_read_cmds_9_valid;break;case 10:v=d.io_model_read_cmds_10_valid;break;case 11:v=d.io_model_read_cmds_11_valid;break;case 12:v=d.io_model_read_cmds_12_valid;break;case 13:v=d.io_model_read_cmds_13_valid;break;case 14:v=d.io_model_read_cmds_14_valid;break;case 15:v=d.io_model_read_cmds_15_valid;break;case 16:v=d.io_model_read_cmds_16_valid;break;case 17:v=d.io_model_read_cmds_17_valid;break;case 18:v=d.io_model_read_cmds_18_valid;break;case 19:v=d.io_model_read_cmds_19_valid;break;case 20:v=d.io_model_read_cmds_20_valid;break;case 21:v=d.io_model_read_cmds_21_valid;break;case 22:v=d.io_model_read_cmds_22_valid;break;case 23:v=d.io_model_read_cmds_23_valid;break;case 24:v=d.io_model_read_cmds_24_valid;break;case 25:v=d.io_model_read_cmds_25_valid;break;case 26:v=d.io_model_read_cmds_26_valid;break;case 27:v=d.io_model_read_cmds_27_valid;break;case 28:v=d.io_model_read_cmds_28_valid;break;case 29:v=d.io_model_read_cmds_29_valid;break;case 30:v=d.io_model_read_cmds_30_valid;break;case 31:v=d.io_model_read_cmds_31_valid;break;case 32:v=d.io_model_read_cmds_32_valid;break;case 33:v=d.io_model_read_cmds_33_valid;break;case 34:v=d.io_model_read_cmds_34_valid;break;} if(v && r_ready(i))rd[i]=true;
      }
      for(int i=0;i<W;i++){bool v=false;switch(i){case 0:v=d.io_model_write_cmds_0_valid;break;}if(v && w_ready(i))wr[i]=true;}
      d.clock=1;d.eval();d.clock=0;d.eval();hosts++;
      bool done=rst;for(int i=0;i<R;i++)done&=rd[i]&&resp[i];for(int i=0;i<W;i++)done&=wr[i];if(done)break;
    }
    d.io_targetClock=1;d.eval();d.io_targetClock=0;d.eval();
    for(int i=0;i<W;i++)if(wen[i]&&!tr){mem[wa[i]]=wd[i];initialized[wa[i]]=true;}
  }
  double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-began).count();
  std::cout<<"{\"status\":\"PASS\",\"target_cycles\":8192,\"host_cycles\":"<<hosts
   <<",\"fmr_host_over_target\":"<<double(hosts)/8192<<",\"compared_read_values\":"<<compared
   <<",\"read_write_conflicts\":"<<conflicts<<",\"same_address_writes\":"<<collisions
   <<",\"target_reset_tokens\":"<<resets<<",\"wall_seconds\":"<<wall
   <<",\"target_cycles_per_second\":"<<8192/wall<<"}\n";
}
