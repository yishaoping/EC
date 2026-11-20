module BucketTagProof(input [23:0] seqHigh,input [23:0] storedHigh,
                         input [7:0] slot,input valid,output io_equivalent);
wire [31:0] seq = {seqHigh, slot};
wire [31:0] stored = {storedHigh, slot};
wire fullMismatch = valid && (stored != seq);
wire highMismatch = valid && (stored[31:8] != seq[31:8]);
assign io_equivalent = fullMismatch == highMismatch;
endmodule
