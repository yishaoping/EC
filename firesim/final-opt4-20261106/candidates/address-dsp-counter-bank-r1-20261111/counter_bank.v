// Area experiment only. No state, clock, reset or added cycle.
// Split a full unsigned 64+64 addition at bit 47 so the low carry is
// retained in a 48-bit DSP ALU result. The high addition retains bit 64.
module AddressDspCounterAdd(input [63:0] a, input [63:0] b, output [64:0] sum);
  (* use_dsp = "yes" *) wire [47:0] low_sum;
  assign low_sum = {1'b0,a[46:0]} + {1'b0,b[46:0]};
  (* use_dsp = "no" *) wire [17:0] high_sum;
  assign high_sum = {1'b0,a[63:47]} + {1'b0,b[63:47]} + low_sum[47];
  assign sum = {high_sum,low_sum[46:0]};
endmodule

module CounterAdderProof(input [63:0] a, input [63:0] b,
                         output equivalent, output mutation_equivalent);
  wire [64:0] candidate;
  AddressDspCounterAdd dut(a,b,candidate);
  wire [64:0] reference = {1'b0,a} + {1'b0,b};
  assign equivalent = candidate == reference;
  assign mutation_equivalent = (candidate ^ 65'b1) == reference;
endmodule

// 64 independent complete arithmetic cells. Delta width 10 covers the
// largest 80*8=640 address-hit total, including the exact 65-bit carry.
module CounterBankReference(input [4095:0] values,input [639:0] deltas,
                             output [4159:0] sums);
  genvar i;
  generate for(i=0;i<64;i=i+1) begin:g
    assign sums[65*i+:65] = {1'b0,values[64*i+:64]} + {55'b0,deltas[10*i+:10]};
  end endgenerate
endmodule

module CounterBankCandidate(input [4095:0] values,input [639:0] deltas,
                             output [4159:0] sums);
  genvar i;
  generate for(i=0;i<64;i=i+1) begin:g
    AddressDspCounterAdd add(values[64*i+:64],{54'b0,deltas[10*i+:10]},sums[65*i+:65]);
  end endgenerate
endmodule
