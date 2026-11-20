module proof(input [63:0] a,input [9:0] d,output ok);wire [64:0] x,y;Reference r(a,d,x);Candidate c(a,d,y);assign ok=x==y;endmodule
