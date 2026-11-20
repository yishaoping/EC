module SelectedFieldRead(input written, input [145:0] raw, output equivalent, mutation_equivalent);
wire [145:0] bundle_observed = written ? raw : 146'h0;
wire [80:0] image = written ? raw[145:65] : 81'h0;
wire [31:0] generation = written ? raw[64:33] : 32'h0;
wire [31:0] packetSeq = written ? raw[32:1] : 32'h0;
wire tracked = written ? raw[0] : 1'h0;
assign equivalent = bundle_observed == {image,generation,packetSeq,tracked};
assign mutation_equivalent = bundle_observed == {image,generation,packetSeq,written ? !raw[0] : 1'h0};
endmodule
