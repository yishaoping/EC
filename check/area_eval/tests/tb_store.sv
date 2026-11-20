`timescale 1ns/1ps
module tb_store;
reg valid=1,permission=1,current=1;
reg [1:0] current_way=1,victim=1;
reg [7:0] current_seq=7,store_seq=7;
reg [1:0] current_epoch=0,store_epoch=0;
reg [3:0] reusable=0;
reg needs=1,secured=0;
wire ready,inplace,allocate,clear,preserve;
wire [1:0] target;
pal_store_policy #(.WAYS(4),.SEQ_W(8),.EPOCH_W(2)) store
(valid,permission,current,current_way,current_seq,store_seq,current_epoch,
store_epoch,reusable,victim,needs,secured,ready,inplace,allocate,clear,preserve,target);
initial begin
 #1; if(!ready || !inplace || allocate || clear || target!=1) $fatal(1,"same segment update");
 store_seq=8; reusable=4'b0100;
 #1; if(!ready || inplace || !allocate || !clear || target!=2) $fatal(1,"new segment preserves predecessor in original way");
 reusable=0;
 #1; if(ready || !preserve || allocate || clear) $fatal(1,"cache capacity pressure cannot discard history");
 secured=1;
 #1; if(!ready || !allocate || !clear || target!=1) $fatal(1,"matching preservation permits reuse");
 store_seq=7; store_epoch=1; secured=0;
 #1; if(ready || inplace || !preserve) $fatal(1,"same Seq different Epoch creates version");
 needs=0;
 #1; if(!ready || !allocate) $fatal(1,"unneeded victim can be reclaimed");
 permission=0;
 #1; if(ready || allocate || preserve) $fatal(1,"coherence permission gate");
 $display("PASS store policy: same segment, new version, no space, preserve ACK, epoch, permission");
 $finish;
end
endmodule
