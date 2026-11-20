module index_proof(input [31:0] w,input [7:0] slot,output ok);
wire [7:0] dl=slot-w[7:0];wire [8:0] d=dl==0?9'd256:{1'b0,dl};
wire [23:0] hi=w[31:8]+(slot<=w[7:0]);
wire [31:0] expected={hi,slot};wire [31:0] old=w+d;
assign ok=(old==expected)&&(old[7:0]==slot)&&(d>=1)&&(d<=256);
endmodule
