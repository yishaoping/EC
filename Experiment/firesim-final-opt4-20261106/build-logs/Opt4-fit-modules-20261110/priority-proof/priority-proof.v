module priority_proof(input [255:0] bad,input [7:0] low,output ok);
wire [7:0] start=low+8'd1;
wire [511:0] repeated={bad,bad};
wire [255:0] rotated=repeated>>start;
reg [8:0] old_advance;
reg [7:0] first_all,first_after;
reg after_exists;
integer i;
always @* begin
  old_advance=9'd256;
  first_all=0;first_after=0;after_exists=0;
  for(i=255;i>=0;i=i-1)begin
    if(rotated[i])old_advance=i;
    if(bad[i])first_all=i;
    if(bad[i] && i>low)begin first_after=i;after_exists=1;end
  end
end
wire [7:0] slot=after_exists?first_after:first_all;
wire [7:0] dlow=slot-low;
wire [8:0] distance=(dlow==0)?9'd256:{1'b0,dlow};
wire [8:0] new_advance=(|bad)?distance-9'd1:9'd256;
assign ok=(old_advance==new_advance);
endmodule
