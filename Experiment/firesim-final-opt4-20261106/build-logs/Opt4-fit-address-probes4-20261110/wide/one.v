(* use_dsp = "yes" *) module Candidate(input [63:0] state_in, input [9:0] delta, output [64:0] result);
wire [63:0] a0=state_in[63:0];
wire [9:0] d0=delta[9:0];
assign result[64:0]={1'b0,a0}+d0;
endmodule
