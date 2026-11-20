module SelectorProof(input a,b, input [2:0] t, input [31:0] data, output equivalent, mutantEquivalent);
wire selector = a & b;
wire isZero = t == 3'h0;
wire [31:0] parent = isZero ? data : selector ? 32'h5 : 32'h7;
wire [31:0] candidate = t == 3'h0 ? data : a & b ? 32'h5 : 32'h7;
wire [31:0] mutant = t == 3'h0 ? data : a | b ? 32'h5 : 32'h7;
wire andOrParent = selector | data[0];
wire andOrCandidate = a & b | data[0];
assign equivalent = parent == candidate && andOrParent == andOrCandidate;
assign mutantEquivalent = parent == mutant;
endmodule
