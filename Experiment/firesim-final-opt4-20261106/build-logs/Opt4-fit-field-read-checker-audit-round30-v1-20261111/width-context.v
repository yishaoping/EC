module WidthContext(input a, output parent, candidate, equivalent);
 wire t = ~a;
 assign parent = (t == 2'h2);
 assign candidate = (~a == 2'h2);
 assign equivalent = parent == candidate;
 endmodule
