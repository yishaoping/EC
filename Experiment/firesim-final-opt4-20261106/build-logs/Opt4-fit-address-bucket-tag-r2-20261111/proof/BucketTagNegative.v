module BucketTagProof(input [31:0] seq,input [31:0] stored,input valid,output io_equivalent);
wire slotInvariant = !valid || stored[7:0] == seq[7:0];
wire fullMatch = stored == seq;
wire highMatch = stored[31:8] == (seq[31:8] + 24'd1);
assign io_equivalent = !slotInvariant || (fullMatch == highMatch);
endmodule
