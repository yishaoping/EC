module Tiny(input ca,cb,d,output reg q); reg a; always @(posedge ca) a<=d; always @(posedge cb) q<=a; endmodule
