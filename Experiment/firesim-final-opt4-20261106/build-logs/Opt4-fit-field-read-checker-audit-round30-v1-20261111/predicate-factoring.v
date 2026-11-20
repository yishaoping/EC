module PredicateFactoring(input [2:0] debug_s2_type,
 input [31:0] a, b, input [15:0] c, d, input [2:0] kind,
 input [1:0] way_a, way_b, output equivalent);
 wire predicate = debug_s2_type == 3'h0;
 wire [84:0] parent = {predicate ? a : b, predicate ? b : a,
                      predicate ? c : d, predicate ? 3'h5 : kind,
                      predicate ? way_a : way_b};
 wire [84:0] candidate = {debug_s2_type == 3'h0 ? a : b,
                         debug_s2_type == 3'h0 ? b : a,
                         debug_s2_type == 3'h0 ? c : d,
                         debug_s2_type == 3'h0 ? 3'h5 : kind,
                         debug_s2_type == 3'h0 ? way_a : way_b};
 assign equivalent = parent == candidate;
 endmodule
