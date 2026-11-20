`timescale 1ns/1ps
module tb;
reg clock=0; always #5 clock=~clock;
reg reset=1,io_resetStats=1,io_start=0,io_stop=0,io_fatalProtocolError=0;
reg [31:0] io_safeWatermark=0,io_sequenceBaseline=0;
integer i,j,seq,phase; integer vectors=0; integer idle_edges=0; integer valid_edges=0;
reg io_events_0_valid=0; reg [39:0] io_events_0_bits_addr=0; reg [1:0] io_events_0_bits_size=0; reg io_events_0_bits_isStore=0; reg [31:0] io_events_0_bits_packetSeq=0;
reg io_events_1_valid=0; reg [39:0] io_events_1_bits_addr=0; reg [1:0] io_events_1_bits_size=0; reg io_events_1_bits_isStore=0; reg [31:0] io_events_1_bits_packetSeq=0;
reg io_events_2_valid=0; reg [39:0] io_events_2_bits_addr=0; reg [1:0] io_events_2_bits_size=0; reg io_events_2_bits_isStore=0; reg [31:0] io_events_2_bits_packetSeq=0;
wire [63:0] a_io_counters_0,b_io_counters_0;
wire [63:0] a_io_counters_1,b_io_counters_1;
wire [63:0] a_io_counters_2,b_io_counters_2;
wire [63:0] a_io_counters_3,b_io_counters_3;
wire [63:0] a_io_counters_4,b_io_counters_4;
wire [63:0] a_io_counters_5,b_io_counters_5;
wire [63:0] a_io_counters_6,b_io_counters_6;
wire [63:0] a_io_counters_7,b_io_counters_7;
wire [63:0] a_io_counters_8,b_io_counters_8;
wire [63:0] a_io_counters_9,b_io_counters_9;
wire [63:0] a_io_counters_10,b_io_counters_10;
wire [63:0] a_io_counters_11,b_io_counters_11;
wire [63:0] a_io_counters_12,b_io_counters_12;
wire [63:0] a_io_counters_13,b_io_counters_13;
wire [63:0] a_io_counters_14,b_io_counters_14;
wire [63:0] a_io_counters_15,b_io_counters_15;
wire [63:0] a_io_counters_16,b_io_counters_16;
wire [63:0] a_io_counters_17,b_io_counters_17;
wire [63:0] a_io_counters_18,b_io_counters_18;
wire [63:0] a_io_counters_19,b_io_counters_19;
wire [63:0] a_io_counters_20,b_io_counters_20;
wire [63:0] a_io_counters_21,b_io_counters_21;
wire [63:0] a_io_counters_22,b_io_counters_22;
wire [63:0] a_io_counters_23,b_io_counters_23;
wire [63:0] a_io_counters_24,b_io_counters_24;
wire [63:0] a_io_counters_25,b_io_counters_25;
wire [63:0] a_io_counters_26,b_io_counters_26;
wire [63:0] a_io_counters_27,b_io_counters_27;
wire [63:0] a_io_counters_28,b_io_counters_28;
wire [63:0] a_io_counters_29,b_io_counters_29;
wire [63:0] a_io_counters_30,b_io_counters_30;
wire [63:0] a_io_counters_31,b_io_counters_31;
wire [63:0] a_io_counters_32,b_io_counters_32;
wire [63:0] a_io_counters_33,b_io_counters_33;
wire [63:0] a_io_counters_34,b_io_counters_34;
wire [63:0] a_io_counters_35,b_io_counters_35;
wire [63:0] a_io_counters_36,b_io_counters_36;
wire [63:0] a_io_counters_37,b_io_counters_37;
wire [63:0] a_io_counters_38,b_io_counters_38;
wire [63:0] a_io_counters_39,b_io_counters_39;
wire [63:0] a_io_firstStoreCounters_0,b_io_firstStoreCounters_0;
wire [63:0] a_io_firstStoreCounters_1,b_io_firstStoreCounters_1;
wire [63:0] a_io_firstStoreCounters_2,b_io_firstStoreCounters_2;
wire [63:0] a_io_firstStoreCounters_3,b_io_firstStoreCounters_3;
wire [63:0] a_io_firstStoreCounters_4,b_io_firstStoreCounters_4;
wire [63:0] a_io_firstStoreCounters_5,b_io_firstStoreCounters_5;
wire [63:0] a_io_firstStoreCounters_6,b_io_firstStoreCounters_6;
wire [63:0] a_io_firstStoreCounters_7,b_io_firstStoreCounters_7;
wire a_io_statsValid,b_io_statsValid;
wire [63:0] a_io_error,b_io_error;
wire [63:0] a_io_pending,b_io_pending;
wire a_io_idle,b_io_idle;
PackageAddressStats_original a(.clock(clock),.reset(reset),.io_resetStats(io_resetStats),.io_start(io_start),.io_stop(io_stop),.io_safeWatermark(io_safeWatermark),.io_sequenceBaseline(io_sequenceBaseline),.io_fatalProtocolError(io_fatalProtocolError),.io_events_0_valid(io_events_0_valid),.io_events_0_bits_addr(io_events_0_bits_addr),.io_events_0_bits_size(io_events_0_bits_size),.io_events_0_bits_isStore(io_events_0_bits_isStore),.io_events_0_bits_packetSeq(io_events_0_bits_packetSeq),.io_events_1_valid(io_events_1_valid),.io_events_1_bits_addr(io_events_1_bits_addr),.io_events_1_bits_size(io_events_1_bits_size),.io_events_1_bits_isStore(io_events_1_bits_isStore),.io_events_1_bits_packetSeq(io_events_1_bits_packetSeq),.io_events_2_valid(io_events_2_valid),.io_events_2_bits_addr(io_events_2_bits_addr),.io_events_2_bits_size(io_events_2_bits_size),.io_events_2_bits_isStore(io_events_2_bits_isStore),.io_events_2_bits_packetSeq(io_events_2_bits_packetSeq),.io_counters_0(a_io_counters_0),.io_counters_1(a_io_counters_1),.io_counters_2(a_io_counters_2),.io_counters_3(a_io_counters_3),.io_counters_4(a_io_counters_4),.io_counters_5(a_io_counters_5),.io_counters_6(a_io_counters_6),.io_counters_7(a_io_counters_7),.io_counters_8(a_io_counters_8),.io_counters_9(a_io_counters_9),.io_counters_10(a_io_counters_10),.io_counters_11(a_io_counters_11),.io_counters_12(a_io_counters_12),.io_counters_13(a_io_counters_13),.io_counters_14(a_io_counters_14),.io_counters_15(a_io_counters_15),.io_counters_16(a_io_counters_16),.io_counters_17(a_io_counters_17),.io_counters_18(a_io_counters_18),.io_counters_19(a_io_counters_19),.io_counters_20(a_io_counters_20),.io_counters_21(a_io_counters_21),.io_counters_22(a_io_counters_22),.io_counters_23(a_io_counters_23),.io_counters_24(a_io_counters_24),.io_counters_25(a_io_counters_25),.io_counters_26(a_io_counters_26),.io_counters_27(a_io_counters_27),.io_counters_28(a_io_counters_28),.io_counters_29(a_io_counters_29),.io_counters_30(a_io_counters_30),.io_counters_31(a_io_counters_31),.io_counters_32(a_io_counters_32),.io_counters_33(a_io_counters_33),.io_counters_34(a_io_counters_34),.io_counters_35(a_io_counters_35),.io_counters_36(a_io_counters_36),.io_counters_37(a_io_counters_37),.io_counters_38(a_io_counters_38),.io_counters_39(a_io_counters_39),.io_firstStoreCounters_0(a_io_firstStoreCounters_0),.io_firstStoreCounters_1(a_io_firstStoreCounters_1),.io_firstStoreCounters_2(a_io_firstStoreCounters_2),.io_firstStoreCounters_3(a_io_firstStoreCounters_3),.io_firstStoreCounters_4(a_io_firstStoreCounters_4),.io_firstStoreCounters_5(a_io_firstStoreCounters_5),.io_firstStoreCounters_6(a_io_firstStoreCounters_6),.io_firstStoreCounters_7(a_io_firstStoreCounters_7),.io_statsValid(a_io_statsValid),.io_error(a_io_error),.io_pending(a_io_pending),.io_idle(a_io_idle));
PackageAddressStats b(.clock(clock),.reset(reset),.io_resetStats(io_resetStats),.io_start(io_start),.io_stop(io_stop),.io_safeWatermark(io_safeWatermark),.io_sequenceBaseline(io_sequenceBaseline),.io_fatalProtocolError(io_fatalProtocolError),.io_events_0_valid(io_events_0_valid),.io_events_0_bits_addr(io_events_0_bits_addr),.io_events_0_bits_size(io_events_0_bits_size),.io_events_0_bits_isStore(io_events_0_bits_isStore),.io_events_0_bits_packetSeq(io_events_0_bits_packetSeq),.io_events_1_valid(io_events_1_valid),.io_events_1_bits_addr(io_events_1_bits_addr),.io_events_1_bits_size(io_events_1_bits_size),.io_events_1_bits_isStore(io_events_1_bits_isStore),.io_events_1_bits_packetSeq(io_events_1_bits_packetSeq),.io_events_2_valid(io_events_2_valid),.io_events_2_bits_addr(io_events_2_bits_addr),.io_events_2_bits_size(io_events_2_bits_size),.io_events_2_bits_isStore(io_events_2_bits_isStore),.io_events_2_bits_packetSeq(io_events_2_bits_packetSeq),.io_counters_0(b_io_counters_0),.io_counters_1(b_io_counters_1),.io_counters_2(b_io_counters_2),.io_counters_3(b_io_counters_3),.io_counters_4(b_io_counters_4),.io_counters_5(b_io_counters_5),.io_counters_6(b_io_counters_6),.io_counters_7(b_io_counters_7),.io_counters_8(b_io_counters_8),.io_counters_9(b_io_counters_9),.io_counters_10(b_io_counters_10),.io_counters_11(b_io_counters_11),.io_counters_12(b_io_counters_12),.io_counters_13(b_io_counters_13),.io_counters_14(b_io_counters_14),.io_counters_15(b_io_counters_15),.io_counters_16(b_io_counters_16),.io_counters_17(b_io_counters_17),.io_counters_18(b_io_counters_18),.io_counters_19(b_io_counters_19),.io_counters_20(b_io_counters_20),.io_counters_21(b_io_counters_21),.io_counters_22(b_io_counters_22),.io_counters_23(b_io_counters_23),.io_counters_24(b_io_counters_24),.io_counters_25(b_io_counters_25),.io_counters_26(b_io_counters_26),.io_counters_27(b_io_counters_27),.io_counters_28(b_io_counters_28),.io_counters_29(b_io_counters_29),.io_counters_30(b_io_counters_30),.io_counters_31(b_io_counters_31),.io_counters_32(b_io_counters_32),.io_counters_33(b_io_counters_33),.io_counters_34(b_io_counters_34),.io_counters_35(b_io_counters_35),.io_counters_36(b_io_counters_36),.io_counters_37(b_io_counters_37),.io_counters_38(b_io_counters_38),.io_counters_39(b_io_counters_39),.io_firstStoreCounters_0(b_io_firstStoreCounters_0),.io_firstStoreCounters_1(b_io_firstStoreCounters_1),.io_firstStoreCounters_2(b_io_firstStoreCounters_2),.io_firstStoreCounters_3(b_io_firstStoreCounters_3),.io_firstStoreCounters_4(b_io_firstStoreCounters_4),.io_firstStoreCounters_5(b_io_firstStoreCounters_5),.io_firstStoreCounters_6(b_io_firstStoreCounters_6),.io_firstStoreCounters_7(b_io_firstStoreCounters_7),.io_statsValid(b_io_statsValid),.io_error(b_io_error),.io_pending(b_io_pending),.io_idle(b_io_idle));
initial begin
for(i=0;i<6144;i=i+1)begin
@(negedge clock);
reset=(i<3); io_resetStats=(i<3 || i==2048 || i==4096);
phase=i%2048; io_start=(phase==4); io_stop=(phase==1400); io_fatalProtocolError=(phase==1850);
if(phase<4)begin io_safeWatermark=0;io_sequenceBaseline=0;end
else if(phase>=1300 && phase<1750) io_safeWatermark=phase-1200;
else if(phase==1800)io_safeWatermark=32'hffff_fffe;
seq=1+phase/32;
io_events_0_valid=(phase>=8 && phase<1250 && phase%8==0);
io_events_0_bits_addr=40'h80000000+((phase/8)%37)*64+(0*8);
io_events_0_bits_size=phase%4;
io_events_0_bits_isStore=(phase/32+0)%2;
io_events_0_bits_packetSeq=seq;
io_events_1_valid=(phase>=8 && phase<1250 && phase%8==1);
io_events_1_bits_addr=40'h80000000+((phase/8)%37)*64+(1*8);
io_events_1_bits_size=phase%4;
io_events_1_bits_isStore=(phase/32+1)%2;
io_events_1_bits_packetSeq=seq;
io_events_2_valid=(phase>=8 && phase<1250 && phase%8==2);
io_events_2_bits_addr=40'h80000000+((phase/8)%37)*64+(2*8);
io_events_2_bits_size=phase%4;
io_events_2_bits_isStore=(phase/32+2)%2;
io_events_2_bits_packetSeq=seq;
@(posedge clock);#1;
if(a_io_counters_0 !== b_io_counters_0)begin $display("ADDRESS_MISMATCH io_counters_0 cycle=%0d a=%h b=%h",i,a_io_counters_0,b_io_counters_0);$fatal;end
if(a_io_counters_1 !== b_io_counters_1)begin $display("ADDRESS_MISMATCH io_counters_1 cycle=%0d a=%h b=%h",i,a_io_counters_1,b_io_counters_1);$fatal;end
if(a_io_counters_2 !== b_io_counters_2)begin $display("ADDRESS_MISMATCH io_counters_2 cycle=%0d a=%h b=%h",i,a_io_counters_2,b_io_counters_2);$fatal;end
if(a_io_counters_3 !== b_io_counters_3)begin $display("ADDRESS_MISMATCH io_counters_3 cycle=%0d a=%h b=%h",i,a_io_counters_3,b_io_counters_3);$fatal;end
if(a_io_counters_4 !== b_io_counters_4)begin $display("ADDRESS_MISMATCH io_counters_4 cycle=%0d a=%h b=%h",i,a_io_counters_4,b_io_counters_4);$fatal;end
if(a_io_counters_5 !== b_io_counters_5)begin $display("ADDRESS_MISMATCH io_counters_5 cycle=%0d a=%h b=%h",i,a_io_counters_5,b_io_counters_5);$fatal;end
if(a_io_counters_6 !== b_io_counters_6)begin $display("ADDRESS_MISMATCH io_counters_6 cycle=%0d a=%h b=%h",i,a_io_counters_6,b_io_counters_6);$fatal;end
if(a_io_counters_7 !== b_io_counters_7)begin $display("ADDRESS_MISMATCH io_counters_7 cycle=%0d a=%h b=%h",i,a_io_counters_7,b_io_counters_7);$fatal;end
if(a_io_counters_8 !== b_io_counters_8)begin $display("ADDRESS_MISMATCH io_counters_8 cycle=%0d a=%h b=%h",i,a_io_counters_8,b_io_counters_8);$fatal;end
if(a_io_counters_9 !== b_io_counters_9)begin $display("ADDRESS_MISMATCH io_counters_9 cycle=%0d a=%h b=%h",i,a_io_counters_9,b_io_counters_9);$fatal;end
if(a_io_counters_10 !== b_io_counters_10)begin $display("ADDRESS_MISMATCH io_counters_10 cycle=%0d a=%h b=%h",i,a_io_counters_10,b_io_counters_10);$fatal;end
if(a_io_counters_11 !== b_io_counters_11)begin $display("ADDRESS_MISMATCH io_counters_11 cycle=%0d a=%h b=%h",i,a_io_counters_11,b_io_counters_11);$fatal;end
if(a_io_counters_12 !== b_io_counters_12)begin $display("ADDRESS_MISMATCH io_counters_12 cycle=%0d a=%h b=%h",i,a_io_counters_12,b_io_counters_12);$fatal;end
if(a_io_counters_13 !== b_io_counters_13)begin $display("ADDRESS_MISMATCH io_counters_13 cycle=%0d a=%h b=%h",i,a_io_counters_13,b_io_counters_13);$fatal;end
if(a_io_counters_14 !== b_io_counters_14)begin $display("ADDRESS_MISMATCH io_counters_14 cycle=%0d a=%h b=%h",i,a_io_counters_14,b_io_counters_14);$fatal;end
if(a_io_counters_15 !== b_io_counters_15)begin $display("ADDRESS_MISMATCH io_counters_15 cycle=%0d a=%h b=%h",i,a_io_counters_15,b_io_counters_15);$fatal;end
if(a_io_counters_16 !== b_io_counters_16)begin $display("ADDRESS_MISMATCH io_counters_16 cycle=%0d a=%h b=%h",i,a_io_counters_16,b_io_counters_16);$fatal;end
if(a_io_counters_17 !== b_io_counters_17)begin $display("ADDRESS_MISMATCH io_counters_17 cycle=%0d a=%h b=%h",i,a_io_counters_17,b_io_counters_17);$fatal;end
if(a_io_counters_18 !== b_io_counters_18)begin $display("ADDRESS_MISMATCH io_counters_18 cycle=%0d a=%h b=%h",i,a_io_counters_18,b_io_counters_18);$fatal;end
if(a_io_counters_19 !== b_io_counters_19)begin $display("ADDRESS_MISMATCH io_counters_19 cycle=%0d a=%h b=%h",i,a_io_counters_19,b_io_counters_19);$fatal;end
if(a_io_counters_20 !== b_io_counters_20)begin $display("ADDRESS_MISMATCH io_counters_20 cycle=%0d a=%h b=%h",i,a_io_counters_20,b_io_counters_20);$fatal;end
if(a_io_counters_21 !== b_io_counters_21)begin $display("ADDRESS_MISMATCH io_counters_21 cycle=%0d a=%h b=%h",i,a_io_counters_21,b_io_counters_21);$fatal;end
if(a_io_counters_22 !== b_io_counters_22)begin $display("ADDRESS_MISMATCH io_counters_22 cycle=%0d a=%h b=%h",i,a_io_counters_22,b_io_counters_22);$fatal;end
if(a_io_counters_23 !== b_io_counters_23)begin $display("ADDRESS_MISMATCH io_counters_23 cycle=%0d a=%h b=%h",i,a_io_counters_23,b_io_counters_23);$fatal;end
if(a_io_counters_24 !== b_io_counters_24)begin $display("ADDRESS_MISMATCH io_counters_24 cycle=%0d a=%h b=%h",i,a_io_counters_24,b_io_counters_24);$fatal;end
if(a_io_counters_25 !== b_io_counters_25)begin $display("ADDRESS_MISMATCH io_counters_25 cycle=%0d a=%h b=%h",i,a_io_counters_25,b_io_counters_25);$fatal;end
if(a_io_counters_26 !== b_io_counters_26)begin $display("ADDRESS_MISMATCH io_counters_26 cycle=%0d a=%h b=%h",i,a_io_counters_26,b_io_counters_26);$fatal;end
if(a_io_counters_27 !== b_io_counters_27)begin $display("ADDRESS_MISMATCH io_counters_27 cycle=%0d a=%h b=%h",i,a_io_counters_27,b_io_counters_27);$fatal;end
if(a_io_counters_28 !== b_io_counters_28)begin $display("ADDRESS_MISMATCH io_counters_28 cycle=%0d a=%h b=%h",i,a_io_counters_28,b_io_counters_28);$fatal;end
if(a_io_counters_29 !== b_io_counters_29)begin $display("ADDRESS_MISMATCH io_counters_29 cycle=%0d a=%h b=%h",i,a_io_counters_29,b_io_counters_29);$fatal;end
if(a_io_counters_30 !== b_io_counters_30)begin $display("ADDRESS_MISMATCH io_counters_30 cycle=%0d a=%h b=%h",i,a_io_counters_30,b_io_counters_30);$fatal;end
if(a_io_counters_31 !== b_io_counters_31)begin $display("ADDRESS_MISMATCH io_counters_31 cycle=%0d a=%h b=%h",i,a_io_counters_31,b_io_counters_31);$fatal;end
if(a_io_counters_32 !== b_io_counters_32)begin $display("ADDRESS_MISMATCH io_counters_32 cycle=%0d a=%h b=%h",i,a_io_counters_32,b_io_counters_32);$fatal;end
if(a_io_counters_33 !== b_io_counters_33)begin $display("ADDRESS_MISMATCH io_counters_33 cycle=%0d a=%h b=%h",i,a_io_counters_33,b_io_counters_33);$fatal;end
if(a_io_counters_34 !== b_io_counters_34)begin $display("ADDRESS_MISMATCH io_counters_34 cycle=%0d a=%h b=%h",i,a_io_counters_34,b_io_counters_34);$fatal;end
if(a_io_counters_35 !== b_io_counters_35)begin $display("ADDRESS_MISMATCH io_counters_35 cycle=%0d a=%h b=%h",i,a_io_counters_35,b_io_counters_35);$fatal;end
if(a_io_counters_36 !== b_io_counters_36)begin $display("ADDRESS_MISMATCH io_counters_36 cycle=%0d a=%h b=%h",i,a_io_counters_36,b_io_counters_36);$fatal;end
if(a_io_counters_37 !== b_io_counters_37)begin $display("ADDRESS_MISMATCH io_counters_37 cycle=%0d a=%h b=%h",i,a_io_counters_37,b_io_counters_37);$fatal;end
if(a_io_counters_38 !== b_io_counters_38)begin $display("ADDRESS_MISMATCH io_counters_38 cycle=%0d a=%h b=%h",i,a_io_counters_38,b_io_counters_38);$fatal;end
if(a_io_counters_39 !== b_io_counters_39)begin $display("ADDRESS_MISMATCH io_counters_39 cycle=%0d a=%h b=%h",i,a_io_counters_39,b_io_counters_39);$fatal;end
if(a_io_firstStoreCounters_0 !== b_io_firstStoreCounters_0)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_0 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_0,b_io_firstStoreCounters_0);$fatal;end
if(a_io_firstStoreCounters_1 !== b_io_firstStoreCounters_1)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_1 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_1,b_io_firstStoreCounters_1);$fatal;end
if(a_io_firstStoreCounters_2 !== b_io_firstStoreCounters_2)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_2 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_2,b_io_firstStoreCounters_2);$fatal;end
if(a_io_firstStoreCounters_3 !== b_io_firstStoreCounters_3)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_3 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_3,b_io_firstStoreCounters_3);$fatal;end
if(a_io_firstStoreCounters_4 !== b_io_firstStoreCounters_4)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_4 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_4,b_io_firstStoreCounters_4);$fatal;end
if(a_io_firstStoreCounters_5 !== b_io_firstStoreCounters_5)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_5 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_5,b_io_firstStoreCounters_5);$fatal;end
if(a_io_firstStoreCounters_6 !== b_io_firstStoreCounters_6)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_6 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_6,b_io_firstStoreCounters_6);$fatal;end
if(a_io_firstStoreCounters_7 !== b_io_firstStoreCounters_7)begin $display("ADDRESS_MISMATCH io_firstStoreCounters_7 cycle=%0d a=%h b=%h",i,a_io_firstStoreCounters_7,b_io_firstStoreCounters_7);$fatal;end
if(a_io_statsValid !== b_io_statsValid)begin $display("ADDRESS_MISMATCH io_statsValid cycle=%0d a=%h b=%h",i,a_io_statsValid,b_io_statsValid);$fatal;end
if(a_io_error !== b_io_error)begin $display("ADDRESS_MISMATCH io_error cycle=%0d a=%h b=%h",i,a_io_error,b_io_error);$fatal;end
if(a_io_pending !== b_io_pending)begin $display("ADDRESS_MISMATCH io_pending cycle=%0d a=%h b=%h",i,a_io_pending,b_io_pending);$fatal;end
if(a_io_idle !== b_io_idle)begin $display("ADDRESS_MISMATCH io_idle cycle=%0d a=%h b=%h",i,a_io_idle,b_io_idle);$fatal;end
if(a_io_statsValid)valid_edges=valid_edges+1;
if(a_io_idle)idle_edges=idle_edges+1;
vectors=vectors+1;
end
if(valid_edges<100 || idle_edges<10)begin $display("INSUFFICIENT_VALID_TRAFFIC");$fatal;end
$display("ADDRESS_SEQUENTIAL_COMPARISON_PASS vectors=%0d valid_edges=%0d idle_edges=%0d",vectors,valid_edges,idle_edges);$finish;end
endmodule
