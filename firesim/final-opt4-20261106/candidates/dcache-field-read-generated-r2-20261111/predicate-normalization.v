module PredicateNormalization(input [2:0] a,b,input c,d,v,input [63:0] l,r,z,output equivalent,mutated);
wire cmp = a == b;
wire both = c & d;
wire [63:0] original = cmp ? l : both ? r : z;
wire [63:0] candidate = a == b ? l : c & d ? r : z;
wire context_old = both | v;
wire context_new = c & d | v;
assign equivalent = original == candidate && context_old == context_new;
assign mutated = original == (a == b ? l : c | d ? r : z);
endmodule
