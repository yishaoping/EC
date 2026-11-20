`timescale 1ns/1ps
module tb_stateful;
reg clk=0; always #5 clk=~clk;
reg rst=1;
task tick; begin @(posedge clk); #1; @(negedge clk); #1; end endtask
task check(input bit ok,input string msg); begin if(!ok) $fatal(1,"%s",msg); end endtask

reg rb=0; reg [7:0] boundary=0;
wire rbready, exhausted; wire [1:0] epoch;
reg [15:0] qseq=0; reg [3:0] qepoch=0; wire [1:0] hv;
pal_evt #(.SEQ_W(8),.EPOCH_W(2),.QUERIES(2)) evt
(clk,rst,rb,boundary,rbready,epoch,exhausted,qseq,qepoch,hv);

reg start=0,required=1,iswb=0,visibility=0,cancel=0;
reg [16:0] key=0; wire ready,busy,locked,req;
reg reqready=0; wire [16:0] reqkey; wire [3:0] tid; wire reqwb;
reg ack=0,ackwb=0; reg [16:0] ackkey=0; reg [3:0] acktid=0;
wire reuse,terminal,cancelled,early;
pal_preserve #(.ADDR_W(6),.SEQ_W(8),.EPOCH_W(2),.TID_W(4)) preserve
(clk,rst,start,key,required,iswb,visibility,cancel,ready,busy,locked,req,reqready,
reqkey,tid,reqwb,ack,ackkey,acktid,ackwb,reuse,terminal,cancelled,early);

reg av=0; wire ar; reg [7:0] as=0; reg [1:0] ae=0;
reg [3:0] ap=0,ac=0; wire [1:0] slot;
reg cv=0; reg [1:0] cs=0; reg [7:0] cseq=0;
reg [1:0] ce=0; reg pass=0,consumed=0;
wire rv; reg rr=0; wire [1:0] rs; wire [3:0] rp,rc;
pal_lsl_reclaim #(.SLOTS(4),.SEQ_W(8),.EPOCH_W(2),.PTR_W(4),.COUNT_W(4)) lsl
(clk,rst,av,ar,as,ae,ap,ac,slot,cv,cs,cseq,ce,pass,consumed,rv,rr,rs,rp,rc);

reg rebase=0; reg [7:0] basesw=0; reg [1:0] se=0;
reg resultv=0,resultpass=1; reg [7:0] resultseq=0; reg [1:0] resultepoch=0;
wire resultready; wire [7:0] sw;
pal_safe_watermark #(.SEQ_W(8),.EPOCH_W(2),.WINDOW(4)) watermark
(clk,rst,rebase,basesw,se,resultv,resultpass,resultseq,resultepoch,resultready,sw);

reg err=0; reg [7:0] errseq=0; reg capacity=1;
wire errready,halt,flush,hist,restore,restart,genfull;
reg flushed=0,histready=0,restored=0,restarted=0;
wire [7:0] rb_boundary; wire [1:0] generation;
pal_rollback #(.SEQ_W(8),.GEN_W(2)) rollback
(clk,rst,err,errseq,capacity,errready,halt,flush,flushed,hist,histready,
restore,restored,restart,restarted,rb_boundary,generation,genfull);

reg bv=0; wire br; reg [0:0] bs=0; reg [7:0] bseq=0;
reg [1:0] be=0; reg wv=0; wire wr; reg [15:0] wd=0; wire commit;
reg rel=0; reg [0:0] relslot=0; reg readv=0;
reg [0:0] readslot=0; reg [1:0] readword=0;
reg [7:0] readseq=0; reg [1:0] readepoch=0;
wire dv; wire [15:0] data;
pal_context_store #(.SLOTS(2),.WORDS(3),.DATA_W(16),.SEQ_W(8),.EPOCH_W(2)) context_mem
(clk,rst,bv,br,bs,bseq,be,wv,wr,wd,commit,rel,relslot,readv,readslot,readword,
readseq,readepoch,dv,data);

reg ren=0,wen=0; reg [0:0] rset=0,wset=0; reg [1:0] mask=0;
reg [8:0] meta=0; wire [17:0] metaout;
pal_metadata_ram #(.SETS(2),.WAYS(2),.SEQ_W(4),.EPOCH_W(1),.GEN_W(2)) metadata
(clk,ren,rset,metaout,wen,wset,mask,meta);

integer i;
initial begin
 tick; rst=0;
 // Metadata masked writes preserve the other way; synchronous read latency.
 wen=1; mask=3; meta=9'h123; tick;
 mask=2; meta=9'h045; tick; wen=0; ren=1; tick;
 check(metaout=={9'h045,9'h123},"metadata per-way mask"); ren=0;
 // Roll back at 8: A8 invalid, A7 survives in old epoch. Repeated rollback at
 // 5 also kills the previously allocated epoch with lower bound 8.
 rb=1; boundary=8; tick; rb=0;
 qepoch=0; qseq={8'd8,8'd7}; #1;
 check(hv==1 && epoch==1,"EVT strict truncation");
 qepoch={2'd1,2'd1}; qseq={8'd7,8'd8}; #1; check(hv==1,"EVT new epoch lower bound");
 rb=1; boundary=5; tick; rb=0;
 qepoch={2'd1,2'd0}; qseq={8'd8,8'd4}; #1; check(hv==1,"EVT repeated rollback");
 rb=1; boundary=9; tick; rb=0;
 check(exhausted && !rbready,"epoch exhaustion cannot alias live history");
 rb=1; boundary=3; tick; rb=0; check(epoch==3,"epoch does not wrap");
 // Preserve request held under backpressure. Wrong/stale identities cannot
 // unlock the source; terminal matching ACK does.
 key=17'h15; start=1; tick; start=0;
 repeat(3) begin tick; check(req && locked && reqkey==17'h15,"preserve hold"); end
 reqready=1; tick; reqready=0;
 ack=1; ackkey=reqkey; acktid=tid-1'b1; tick;
 check(busy && !reuse,"stale ACK transaction");
 acktid=tid; ackkey=reqkey+1'b1; tick; check(busy,"stale ACK version");
 ackkey=reqkey; ackwb=1; tick; check(busy,"ACK class mismatch");
 ackwb=0; tick; ack=0; check(reuse && !busy,"matching Preserve ACK");
 // Unsafe DRAM writeback waits for SW. Cancelled issued requests drain their
 // exact terminal acknowledgement before releasing reservations.
 start=1; iswb=1; tick; start=0; tick;
 check(busy && !req && early,"unsafe writeback backpressure/early dispatch");
 visibility=1; reqready=1; tick; reqready=0;
 cancel=1; tick; cancel=0; check(busy && !reuse,"cancel drains issued transfer");
 ack=1; ackkey=reqkey; acktid=tid; ackwb=1; tick; ack=0;
 check(cancelled && terminal && !reuse && !busy,"cancelled ACK cannot install");
 // Slot capacity; out-of-order completion frees checking input without SW.
 for(i=0;i<4;i=i+1) begin
   #1; check(ar && slot==i,"LSL allocate unique slot");
   av=1; as=i+1; ap=i*3; ac=3; tick;
 end
 av=0; #1; check(!ar,"LSL full backpressure");
 cv=1; cs=2; cseq=3; ce=1; pass=1; consumed=1; tick;
 ce=0; consumed=0; tick; check(!rv,"LSL rejects stale/unconsumed result");
 consumed=1; tick; cv=0; tick;
 check(rv && rs==2 && rp==6 && rc==3,"LSL independent OOO release");
 // New lower priority index completion must not change a held release.
 cv=1; cs=0; cseq=1; tick; cv=0; tick;
 check(rv && rs==2,"LSL release stable while stalled");
 rr=1; tick; rr=0; tick;
 check(rv && rs==0,"LSL next completed slot");
 rr=1; tick; rr=0; tick; check(ar,"LSL storage returns to allocator");
 // Out-of-order PASS may reclaim its LSL but cannot advance SW past a hole.
 resultv=1; resultseq=2; tick; resultv=0; tick; check(sw==0,"SW hole");
 resultv=1; resultseq=1; tick; resultv=0; tick; tick;
 check(sw==2,"SW contiguous prefix");
 resultv=1; resultseq=3; resultepoch=1; tick; resultv=0; tick;
 check(sw==2,"SW rejects stale epoch");
 resultepoch=0; resultseq=7; #1; check(!resultready,"SW bounded window");
 resultseq=3; resultpass=0; resultv=1; tick; resultv=0; tick;
 check(sw==2,"SW FAIL cannot pass");
 // A duplicate coincident with prefix advancement must not leave a stale bit
 // at the same circular index in the next window.
 resultpass=1; resultv=1; resultseq=3; tick; tick; resultv=0;
 resultv=1; resultseq=4; tick; resultv=0; tick;
 resultv=1; resultseq=5; tick; resultv=0; tick;
 resultv=1; resultseq=6; tick; resultv=0; tick; tick;
 check(sw==6,"SW duplicate cannot validate unreported Seq7");
 // Rollback handshakes ordered and persistent. No cache walk is performed.
 err=1; errseq=8; tick; err=0;
 repeat(2) begin tick; check(flush && halt && !hist,"flush waits for ACK"); end
 flushed=1; tick; flushed=0; check(hist,"history follows pipeline flush");
 tick; check(generation==0,"generation waits for EVT ACK");
 histready=1; tick; histready=0;
 check(generation==1 && restore && rb_boundary==8,"generation/restore ordering");
 restored=1; tick; restored=0; check(restart,"restart follows context ACK");
 restarted=1; tick; restarted=0; check(!halt,"rollback completes");
 capacity=0; err=1; #1; check(!errready && halt,"exhaustion fails closed"); err=0;
 // Context cannot be read before complete, overwritten while retained, or
 // retrieved by a stale sequence/epoch. WORDS=3 checks non-power-of-two depth.
 bv=1; bs=1; bseq=8; be=2; tick; bv=0;
 readv=1; readslot=1; readseq=8; readepoch=2;
 wv=1; wd=16'h1111; tick; check(!dv && !commit,"partial context hidden");
 wd=16'h2222; tick; wd=16'h3333; tick; wv=0;
 check(commit,"context atomic commit");
 readword=2; tick; check(dv && data==16'h3333,"context read");
 bv=1; bs=1; #1; check(!br,"retained context cannot overwrite"); bv=0;
 readepoch=1; tick; check(!dv,"context rejects stale epoch");
 readepoch=2; rel=1; relslot=1; tick; rel=0; tick;
 check(!dv && br,"context explicit release");
 // Drain all remaining transaction identities. Stop before wrap so an old
 // acknowledgement can never alias a freshly allocated reservation.
 iswb=0; ackwb=0; reqready=1;
 for(i=0;i<13;i=i+1) begin
   #1; check(ready,"transaction capacity before last ID");
   start=1; key=key+1'b1; tick; start=0; tick;
   ack=1; ackkey=reqkey; acktid=tid; tick; ack=0;
   check(reuse && !busy,"transaction terminal drain");
 end
 check(tid==15 && !ready && early,"transaction exhaustion cannot wrap");
 start=1; tick; start=0; check(!busy && tid==15,"no allocation after exhaustion");
 $display("PASS stateful: metadata, EVT, preserve, LSL, SW, rollback, context");
 $finish;
end
initial begin #100000; $fatal(1,"timeout"); end
endmodule
