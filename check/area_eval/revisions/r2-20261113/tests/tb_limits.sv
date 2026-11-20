// Characterizes finite-identity limits of the unchanged primitives at Seq32.
// PASS means the documented limits were observed, not proof of system liveness.
module tb_limits;
  reg clk=0; always #5 clk=~clk;
  reg rst=1;
  reg rb=0;
  wire rb_ready, exhausted;
  wire [3:0] epoch;
  pal_evt #(.SEQ_W(32), .QUERIES(16)) evt(
    .clk(clk), .rst(rst), .rollback_valid(rb), .boundary(32'd1),
    .rollback_ready(rb_ready), .current_epoch(epoch), .exhausted(exhausted),
    .query_seq(512'b0), .query_epoch(64'b0), .history_valid());

  reg start=0, ack=0;
  wire ready, busy, locked, req, req_wb, reuse, terminal, cancelled, early;
  wire [76:0] key;
  wire [7:0] tid;
  pal_preserve #(.SEQ_W(32)) preserve(
    .clk(clk), .rst(rst), .start_valid(start), .start_key(77'd123),
    .required(1'b1), .is_writeback(1'b0), .visibility_allowed(1'b1), .cancel(1'b0),
    .start_ready(ready), .busy(busy), .source_locked(locked),
    .request_valid(req), .request_ready(1'b1), .request_key(key),
    .request_tid(tid), .request_is_writeback(req_wb),
    .ack_valid(ack), .ack_key(key), .ack_tid(tid), .ack_is_writeback(req_wb),
    .reuse(reuse), .terminal(terminal), .cancelled(cancelled), .dispatch_early(early));
  task tick; begin @(posedge clk); #1; end endtask
  integer i;
  initial begin
    tick; tick;
    @(negedge clk); rst=0; rb=1;
    for(i=0;i<15;i=i+1) begin
      if(!rb_ready) $fatal(1,"EVT stopped before 15 rollbacks");
      tick; @(negedge clk);
    end
    rb=0;
    if(rb_ready || !exhausted || epoch!=15) $fatal(1,"EVT capacity mismatch");
    $display("OBSERVED_LIMIT EVT16: 15 rollbacks, then fail-closed; no GC/rebase port");
    for(i=0;i<255;i=i+1) begin
      if(!ready) $fatal(1,"preserve stopped early");
      start=1; tick;
      if(!req || !locked) $fatal(1,"missing preservation request");
      @(negedge clk); start=0; tick;
      @(negedge clk); ack=1; tick;
      if(!reuse || busy) $fatal(1,"matching ACK did not release");
      @(negedge clk); ack=0;
    end
    if(ready || busy || !early || tid!=255) $fatal(1,"TID capacity mismatch");
    repeat(4) tick;
    if(ready) $fatal(1,"unexpected autonomous identity reuse");
    $display("OBSERVED_LIMIT TID8: 255 ACKed required transfers, then blocks while idle");
    $display("PASS: primitive limits characterized; production forward progress remains unimplemented");
    $finish;
  end
endmodule
