`timescale 1ns/1ps
module tb;
reg clock=0;always #5 clock=~clock;
reg reset=1, resetStats=1,event_valid=0,fatalProtocolError=0;
reg [31:0] event_bits=0,safeWatermark=0;
reg [63:0] currentCycle=0;
integer i;integer vectors=0;integer x;
wire [63:0] a_seen, b_seen;
wire [63:0] a_resolved, b_resolved;
wire [63:0] a_pending, b_pending;
wire [63:0] a_dropped, b_dropped;
wire [63:0] a_requestCycleSum, b_requestCycleSum;
wire [63:0] a_safeCycleSum, b_safeCycleSum;
wire [63:0] a_statsValid, b_statsValid;
GHBarrierLatencyStats_original original(.clock(clock),.reset(reset),.io_resetStats(resetStats),.io_event_valid(event_valid),.io_event_bits(event_bits),.io_safeWatermark(safeWatermark),.io_currentCycle(currentCycle),.io_fatalProtocolError(fatalProtocolError),.io_seen(a_seen),.io_resolved(a_resolved),.io_pending(a_pending),.io_dropped(a_dropped),.io_requestCycleSum(a_requestCycleSum),.io_safeCycleSum(a_safeCycleSum),.io_statsValid(a_statsValid));
GHBarrierLatencyStats candidate(.clock(clock),.reset(reset),.io_resetStats(resetStats),.io_event_valid(event_valid),.io_event_bits(event_bits),.io_safeWatermark(safeWatermark),.io_currentCycle(currentCycle),.io_fatalProtocolError(fatalProtocolError),.io_seen(b_seen),.io_resolved(b_resolved),.io_pending(b_pending),.io_dropped(b_dropped),.io_requestCycleSum(b_requestCycleSum),.io_safeCycleSum(b_safeCycleSum),.io_statsValid(b_statsValid));

task check;
begin
#1;
if(a_seen !== b_seen)begin $display("MISMATCH seen %d",i);$fatal;end
if(a_resolved !== b_resolved)begin $display("MISMATCH resolved %d",i);$fatal;end
if(a_pending !== b_pending)begin $display("MISMATCH pending %d",i);$fatal;end
if(a_dropped !== b_dropped)begin $display("MISMATCH dropped %d",i);$fatal;end
if(a_requestCycleSum !== b_requestCycleSum)begin $display("MISMATCH requestCycleSum %d",i);$fatal;end
if(a_safeCycleSum !== b_safeCycleSum)begin $display("MISMATCH safeCycleSum %d",i);$fatal;end
if(a_statsValid !== b_statsValid)begin $display("MISMATCH statsValid %d",i);$fatal;end
vectors=vectors+1;
end
endtask
initial begin
for(i=0;i<2048;i=i+1)begin
@(negedge clock);
reset=(i<3);resetStats=(i<3 || i==700 || i==1200 || i==1700);
if(i<520)begin event_valid=(i>=3);event_bits=i-2;safeWatermark=(i>260)?i-260:0;end
else if(i<700)begin event_valid=0;safeWatermark=32'hffff_fffe;end
else begin
x=$random;event_valid=x&1;
event_bits=i%1024;
if((i%11)==0)safeWatermark=i%1024;
if((i%29)==0)safeWatermark=0;
end
currentCycle=currentCycle+64'h0100000000000001;
fatalProtocolError=(i==1161);
@(posedge clock);check;
end
$display("CANDIDATE_LEAF_SEQUENTIAL_COMPARISON_PASS vectors=%d",vectors);$finish;
end
endmodule
