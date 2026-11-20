module carry_proof(input [63:0] a,b,output ok); wire old=(|b)&&(a>(~64'd0-b)); wire [64:0] s={1'b0,a}+{1'b0,b}; assign ok=(old==s[64]); endmodule
