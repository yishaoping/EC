"""Deterministic complete-module regression, including all bucket state."""
def generate():
    fields=['seen','resolved','pending','dropped','requestCycleSum','safeCycleSum','statsValid']
    text='''`timescale 1ns/1ps
module tb;
reg clock=0; always #5 clock=~clock;
reg reset=1, resetStats=1, event_valid=0, fatalProtocolError=0;
reg [31:0] event_bits=0, safeWatermark=0;
reg [63:0] currentCycle=0;
reg [63:0] rng=64'hd1b54a32d192ed03;
integer i, checks=0, collisions=0, immediate=0, resetEvents=0;
'''
    for variant,top in [('frozen','FrozenBarrier'),('parent','ParentBarrier'),('candidate','GHBarrierLatencyStats')]:
        for f in fields:text+=f'wire [63:0] {variant}_{f};\n'
        ports=['.clock(clock)','.reset(reset)','.io_resetStats(resetStats)',
               '.io_event_valid(event_valid)','.io_event_bits(event_bits)',
               '.io_safeWatermark(safeWatermark)','.io_currentCycle(currentCycle)',
               '.io_fatalProtocolError(fatalProtocolError)']
        ports += [f'.io_{f}({variant}_{f})' for f in fields]
        text+=f'{top} {variant}('+','.join(ports)+');\n'
    text+='task check; begin\n#1;\n'
    for f in fields:
        text+=f'if (frozen_{f} !== candidate_{f} || parent_{f} !== candidate_{f}) begin $display("OUTPUT_MISMATCH {f} cycle=%0d",i); $fatal; end\n'
    for b in ['valid','seq','count','requestCycleSum']:
        for slot in range(256):
            text+=f'if (frozen.buckets_{b}_{slot} !== candidate.buckets_{b}_{slot} || parent.buckets_{b}_{slot} !== candidate.buckets_{b}_{slot}) begin $display("BUCKET_MISMATCH {b} slot={slot} cycle=%0d",i); $fatal; end\n'
    text+='checks=checks+1; end endtask\n'
    text+='''initial begin
for (i=0;i<8192;i=i+1) begin
  @(negedge clock);
  rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);
  reset=(i<3 || i==4096);
  resetStats=(i<3 || i==1001 || i==1030 || i==2048 || i==5000 || i==6143 || i==6150);
  event_valid=1; fatalProtocolError=(i==7100);
  currentCycle=rng;
  if (i<259) begin event_bits=i-2; safeWatermark=0; end
  else if (i<515) begin event_bits=i-2; safeWatermark=0; collisions=collisions+1; end
  else if (i<601) begin event_bits=i;safeWatermark=32'hffffffff;immediate=immediate+1;end
  else if (i<1001 || (i>1001 && i<1030)) begin event_bits=511;safeWatermark=0;end
  else begin
    event_valid=rng[5];event_bits=rng[31:0];safeWatermark=rng[63:32];
    if (i%31==0) safeWatermark=0;
    if (i%37==0) safeWatermark=32'hffffffff;
  end
  if (reset || resetStats) begin event_valid=1;resetEvents=resetEvents+1;end
  if (i==1024) begin
    event_valid=1;event_bits=511;safeWatermark=0;currentCycle=64'hffffffffffffffff;
'''
    for v in ['frozen','parent','candidate']:
        text+=f"{v}.buckets_valid_255=1; {v}.buckets_seq_255=511; {v}.buckets_count_255=64'hffffffffffffffff; {v}.buckets_requestCycleSum_255=64'hffffffffffffffff; {v}.pending=64'hffffffffffffffff;\n"
    text+='end\nif (i==6144) begin\nevent_valid=1;event_bits=32\'hffffffff;safeWatermark=32\'hffffffff;currentCycle=64\'hffffffffffffffff;\n'
    for v in ['frozen','parent','candidate']:
        for slot in range(256):
            text+=f"{v}.buckets_valid_{slot}=1;{v}.buckets_seq_{slot}={256+slot};{v}.buckets_count_{slot}=64'hffffffffffffffff;{v}.buckets_requestCycleSum_{slot}=64'hffffffffffffffff;\n"
        text+=f"{v}.seen=64'hffffffffffffffff;{v}.resolved=64'hffffffffffffffff;{v}.pending=0;{v}.requestCycleSum=64'hffffffffffffffff;{v}.safeCycleSum=64'hffffffffffffffff;\n"
    text+='''end
  check;
  @(posedge clock);check;
end
if (checks!=16384 || collisions!=256 || immediate<1 || resetEvents<8) $fatal;
$display("BARRIER_COMPLETE_FROZEN_PARENT_CANDIDATE_PASS cycles=8192 observations=%0d outputs=7 bucket_fields=1024 collisions=%0d immediate=%0d reset_events=%0d overflow_seeds=2",checks,collisions,immediate,resetEvents);
$finish;
end
endmodule
'''
    return text
