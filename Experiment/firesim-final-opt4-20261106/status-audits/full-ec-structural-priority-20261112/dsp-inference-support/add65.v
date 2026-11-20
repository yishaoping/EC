module FPGATop(input [63:0] value, input [63:0] delta, output [64:0] sum);
(* use_dsp = "yes" *) wire [64:0] added = {1'b0,value} + {1'b0,delta};
assign sum = added;
endmodule
