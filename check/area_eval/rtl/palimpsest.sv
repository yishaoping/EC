// PALIMPSEST area-evaluation primitives. No Chipyard integration is implied.
// Non-wrapping sequence/epoch/generation identities; exhaustion requires a
// quiescent external rebase. See reports/implementation.md for contracts.
`default_nettype none

// Packed metadata sidecar, one synchronous read and one masked write.
// No reset of the RAM: cache valid/reset must qualify its contents.
module pal_metadata_ram #(
  parameter SETS=64, WAYS=8, SEQ_W=16, EPOCH_W=4, GEN_W=8, OWNER_W=0,
  parameter FIELD_W=SEQ_W+EPOCH_W+GEN_W+2+OWNER_W,
  parameter SET_W=(SETS>1?$clog2(SETS):1)
)(input wire clk, input wire ren, input wire [SET_W-1:0] rset,
  output reg [WAYS*FIELD_W-1:0] rdata,
  input wire wen, input wire [SET_W-1:0] wset,
  input wire [WAYS-1:0] wmask, input wire [FIELD_W-1:0] wdata);
  // Fields: Seq, Epoch, CurGen, Cur, preserved, optional producer ID.
  // Existing cache valid/coherence/dirty/tag bits are reused, not duplicated.
  reg [WAYS*FIELD_W-1:0] mem [0:SETS-1];
  integer w;
  always @(posedge clk) begin
    if (ren) rdata <= mem[rset]; // read-before-write for a same-set conflict
    if (wen) for(w=0;w<WAYS;w=w+1)
      if(wmask[w]) mem[wset][w*FIELD_W +: FIELD_W] <= wdata;
  end
endmodule

// Surviving execution history intervals [lo, hi]. Slots are never recycled
// while live cache/transaction references may exist. Stop at finite capacity.
module pal_evt #(
  parameter SEQ_W=16, EPOCH_W=4, ENTRIES=(1<<EPOCH_W), QUERIES=16
)(input wire clk, rst,
  input wire rollback_valid, input wire [SEQ_W-1:0] boundary,
  output wire rollback_ready, output reg [EPOCH_W-1:0] current_epoch,
  output wire exhausted,
  input wire [QUERIES*SEQ_W-1:0] query_seq,
  input wire [QUERIES*EPOCH_W-1:0] query_epoch,
  output reg [QUERIES-1:0] history_valid);
  reg [SEQ_W-1:0] lo[0:ENTRIES-1], hi[0:ENTRIES-1];
  reg [ENTRIES-1:0] live;
  wire [EPOCH_W:0] next_epoch={1'b0,current_epoch}+1'b1;
  assign exhausted=(next_epoch>=(EPOCH_W+1)'(ENTRIES));
  assign rollback_ready=!exhausted && boundary!=0;
  integer i,q;
  reg [EPOCH_W-1:0] e;
  reg [SEQ_W-1:0] s;
  always @* begin
    history_valid=0; e=0; s=0;
    for(q=0;q<QUERIES;q=q+1) begin
      e=query_epoch[q*EPOCH_W +: EPOCH_W];
      s=query_seq[q*SEQ_W +: SEQ_W];
      if(32'(e)<ENTRIES)
        history_valid[q]=live[e] && s>=lo[e] && s<=hi[e];
    end
  end
  always @(posedge clk) begin
    if(rst) begin
      live<=1; current_epoch<=0;
      for(i=0;i<ENTRIES;i=i+1) begin lo[i]<=0; hi[i]<={SEQ_W{1'b1}}; end
    end else if(rollback_valid && rollback_ready) begin
      for(i=0;i<ENTRIES;i=i+1) begin
        if(live[i] && lo[i]>=boundary) live[i]<=0;
        else if(live[i] && hi[i]>=boundary) hi[i]<=boundary-1'b1;
      end
      current_epoch<=next_epoch[EPOCH_W-1:0];
      live[next_epoch[EPOCH_W-1:0]]<=1;
      lo[next_epoch[EPOCH_W-1:0]]<=boundary;
      hi[next_epoch[EPOCH_W-1:0]]<={SEQ_W{1'b1}};
    end
  end
endmodule

// Normal read uses validated Current mapping. Recovery selects the maximum
// surviving Seq strictly before boundary. Existing tag/permission checks feed
// tag_match/eligible. Invoke at each level, then compare the level winners.
module pal_version_select #(
  parameter WAYS=8, SEQ_W=16, GEN_W=8,
  parameter WAY_W=(WAYS>1?$clog2(WAYS):1)
)(input wire recovery,
  input wire [WAYS-1:0] tag_match, eligible, history_valid, cur,
  input wire [WAYS*SEQ_W-1:0] seqs,
  input wire [WAYS*GEN_W-1:0] generations,
  input wire [GEN_W-1:0] global_generation,
  input wire [SEQ_W-1:0] boundary,
  output reg hit, output reg [WAY_W-1:0] way,
  output reg [SEQ_W-1:0] selected_seq,
  output reg ambiguous_current);
  integer i;
  reg candidate;
  always @* begin
    hit=0; way=0; selected_seq=0; ambiguous_current=0; candidate=0;
    for(i=0;i<WAYS;i=i+1) begin
      candidate=tag_match[i] && eligible[i] && history_valid[i] &&
        (recovery ? seqs[i*SEQ_W +: SEQ_W]<boundary :
         (cur[i] && generations[i*GEN_W +: GEN_W]==global_generation));
      if(candidate) begin
        if(!recovery && hit) ambiguous_current=1;
        if(!hit || (recovery && seqs[i*SEQ_W +: SEQ_W]>selected_seq)) begin
          hit=1; way=WAY_W'(i); selected_seq=seqs[i*SEQ_W +: SEQ_W];
        end
      end
    end
  end
endmodule

// Safe-only coherence/DRAM propagation. SW is the producer's SW. Eligibility
// for ordinary local reads still requires validated Current mapping upstream.
module pal_visibility #(
  parameter SEQ_W=16, OWNER_W=1
)(input wire valid, history_valid, own_request, external_transfer,
  input wire [OWNER_W-1:0] producer, requester,
  input wire [SEQ_W-1:0] seq, producer_sw,
  output wire safe, allow, stall);
  assign safe=valid && history_valid && seq<=producer_sw;
  assign allow=valid && history_valid &&
    ((!external_transfer && own_request && producer==requester) || safe);
  assign stall=valid && !allow;
endmodule

// Cache store policy, with existing controller-provided permission, retention
// and replacement decisions. A store from a new segment may not overwrite
// the previous Current version until it is secured or a reusable way exists.
module pal_store_policy #(
  parameter WAYS=8,SEQ_W=16,EPOCH_W=4,
  parameter WAY_W=(WAYS>1?$clog2(WAYS):1)
)(input wire store_valid,permission_ok,current_hit,
  input wire [WAY_W-1:0] current_way,
  input wire [SEQ_W-1:0] current_seq,store_seq,
  input wire [EPOCH_W-1:0] current_epoch,store_epoch,
  input wire [WAYS-1:0] reusable,
  input wire [WAY_W-1:0] victim_way,
  input wire victim_requires_history,victim_secured,
  output reg ready,in_place,allocate,clear_old_current,preserve_needed,
  output reg [WAY_W-1:0] target_way);
  integer i;
  reg found;
  always @* begin
    ready=0; in_place=0; allocate=0; clear_old_current=0;
    preserve_needed=0; target_way=0; found=0;
    if(store_valid && permission_ok) begin
      if(current_hit && current_seq==store_seq && current_epoch==store_epoch) begin
        ready=1; in_place=1; target_way=current_way;
      end else begin
        for(i=0;i<WAYS;i=i+1) if(reusable[i] && !found) begin
          found=1; target_way=WAY_W'(i);
        end
        if(!found) target_way=victim_way;
        ready=found || !victim_requires_history || victim_secured;
        preserve_needed=!ready;
        allocate=ready;
        clear_old_current=ready && current_hit;
      end
    end
  end
endmodule

// One preservation / writeback reservation. It locks the SOURCE data; it does
// not clone a cache line. WB operations are globally serialized here (stronger
// than per-address ordering); a throughput-oriented implementation needs a CAM.
module pal_preserve #(
  parameter ADDR_W=40, SEQ_W=16, EPOCH_W=4, TID_W=8,
  parameter KEY_W=ADDR_W+SEQ_W+EPOCH_W+1
)(input wire clk,rst,
  input wire start_valid, input wire [KEY_W-1:0] start_key,
  input wire required, is_writeback, visibility_allowed, cancel,
  output wire start_ready, busy, source_locked,
  output wire request_valid, input wire request_ready,
  output reg [KEY_W-1:0] request_key,
  output reg [TID_W-1:0] request_tid, output reg request_is_writeback,
  input wire ack_valid, input wire [KEY_W-1:0] ack_key,
  input wire [TID_W-1:0] ack_tid, input wire ack_is_writeback,
  output reg reuse, terminal, cancelled,
  output wire dispatch_early);
  localparam IDLE=0,SEND=1,WAIT_ACK=2;
  reg [1:0] state;
  reg killed;
  // Never recycle a transaction identity without a proven external drain.
  wire identity_exhausted=&request_tid;
  assign start_ready=state==IDLE && !identity_exhausted;
  assign busy=state!=IDLE;
  assign source_locked=busy;
  assign dispatch_early=busy || identity_exhausted;
  assign request_valid=state==SEND && !cancel &&
    (!request_is_writeback || visibility_allowed);
  wire ack_match=ack_key==request_key && ack_tid==request_tid &&
    ack_is_writeback==request_is_writeback;
  always @(posedge clk) begin
    if(rst) begin
      state<=IDLE; request_key<=0; request_tid<=0;
      request_is_writeback<=0; killed<=0;
      reuse<=0; terminal<=0; cancelled<=0;
    end else begin
      reuse<=0; terminal<=0; cancelled<=0;
      case(state)
        IDLE: if(start_valid && start_ready && !cancel) begin
          if(!required) begin reuse<=1; terminal<=1; end
          else begin
            request_key<=start_key; request_is_writeback<=is_writeback;
            request_tid<=request_tid+1'b1; killed<=0; state<=SEND;
          end
        end
        SEND: if(cancel) begin state<=IDLE; cancelled<=1; terminal<=1; end
          else if(request_valid && request_ready) state<=WAIT_ACK;
        WAIT_ACK: begin
          if(cancel) killed<=1;
          if(ack_valid && ack_match) begin
            state<=IDLE; terminal<=1;
            reuse<=!killed && !cancel; cancelled<=killed || cancel;
          end
        end
        default: state<=IDLE;
      endcase
    end
  end
endmodule

// Segment-granular log release. Log data and its allocator are external.
// Slots can complete out of order; release is a held valid/ready transaction.
// A PASS is accepted only with checking-input consumption confirmed upstream.
module pal_lsl_reclaim #(
  parameter SLOTS=8, SEQ_W=16, EPOCH_W=4, PTR_W=9, COUNT_W=9,
  parameter SLOT_W=(SLOTS>1?$clog2(SLOTS):1)
)(input wire clk,rst,
  input wire alloc_valid, output wire alloc_ready,
  input wire [SEQ_W-1:0] alloc_seq, input wire [EPOCH_W-1:0] alloc_epoch,
  input wire [PTR_W-1:0] alloc_start, input wire [COUNT_W-1:0] alloc_count,
  output reg [SLOT_W-1:0] alloc_slot,
  input wire complete_valid, input wire [SLOT_W-1:0] complete_slot,
  input wire [SEQ_W-1:0] complete_seq,
  input wire [EPOCH_W-1:0] complete_epoch, input wire complete_pass,
  input wire inputs_consumed,
  output reg release_valid, input wire release_ready,
  output reg [SLOT_W-1:0] release_slot,
  output wire [PTR_W-1:0] release_start,
  output wire [COUNT_W-1:0] release_count);
  reg [SLOTS-1:0] valid,done;
  reg [SEQ_W-1:0] seq[0:SLOTS-1];
  reg [EPOCH_W-1:0] epoch[0:SLOTS-1];
  reg [PTR_W-1:0] first[0:SLOTS-1];
  reg [COUNT_W-1:0] count[0:SLOTS-1];
  reg free_found;
  reg held_valid;
  reg [SLOT_W-1:0] held_slot;
  reg candidate_valid;
  reg [SLOT_W-1:0] candidate_slot;
  integer i;
  always @* begin
    free_found=0; alloc_slot=0; candidate_valid=0; candidate_slot=0;
    for(i=0;i<SLOTS;i=i+1) begin
      if(!valid[i] && !free_found) begin free_found=1; alloc_slot=SLOT_W'(i); end
      if(valid[i] && done[i] && !candidate_valid) begin
        candidate_valid=1; candidate_slot=SLOT_W'(i);
      end
    end
    release_valid=held_valid;
    release_slot=held_slot;
  end
  assign alloc_ready=free_found && !rst;
  assign release_start=first[release_slot];
  assign release_count=count[release_slot];
  always @(posedge clk) begin
    if(rst) begin valid<=0; done<=0; held_valid<=0; held_slot<=0; end
    else begin
      if(!held_valid && candidate_valid) begin
        held_valid<=1; held_slot<=candidate_slot;
      end
      if(alloc_valid && alloc_ready) begin
        valid[alloc_slot]<=1; done[alloc_slot]<=0;
        seq[alloc_slot]<=alloc_seq; epoch[alloc_slot]<=alloc_epoch;
        first[alloc_slot]<=alloc_start; count[alloc_slot]<=alloc_count;
      end
      if(complete_valid && 32'(complete_slot)<SLOTS && valid[complete_slot] &&
        seq[complete_slot]==complete_seq && epoch[complete_slot]==complete_epoch &&
        complete_pass && inputs_consumed) done[complete_slot]<=1;
      if(release_valid && release_ready) begin
        valid[release_slot]<=0; done[release_slot]<=0;
        held_valid<=0;
      end
    end
  end
endmodule

// Bounded verification bitmap. Only a contiguous PASS prefix advances SW.
// WINDOW must be a power of two; no Seq wrap during a live session.
// rebase is permitted ONLY after external quiescence/rollback reconciliation.
module pal_safe_watermark #(
  parameter SEQ_W=16,EPOCH_W=4,WINDOW=16,
  parameter IDX_W=$clog2(WINDOW)
)(input wire clk,rst,rebase,
  input wire [SEQ_W-1:0] base_sw,
  input wire [EPOCH_W-1:0] session_epoch,
  input wire result_valid, input wire result_pass,
  input wire [SEQ_W-1:0] result_seq,
  input wire [EPOCH_W-1:0] result_epoch,
  output wire result_ready, output reg [SEQ_W-1:0] sw);
  reg [WINDOW-1:0] passed;
  reg [EPOCH_W-1:0] epoch;
  wire [SEQ_W:0] distance={1'b0,result_seq}-{1'b0,sw};
  wire [SEQ_W-1:0] next_seq=sw+1'b1;
  wire [IDX_W-1:0] next_index=next_seq[IDX_W-1:0];
  wire advance=sw!={SEQ_W{1'b1}} && passed[next_index];
  assign result_ready=!rst && !rebase && result_epoch==epoch &&
    result_seq>sw && distance<=WINDOW;
  always @(posedge clk) begin
    if(rst || rebase) begin passed<=0; sw<=base_sw; epoch<=session_epoch; end
    else begin
      if(result_valid && result_ready && result_pass)
        passed[result_seq[IDX_W-1:0]]<=1;
      // Clear wins over a duplicate result for the segment advancing now.
      // Otherwise its old bit can survive until the bitmap index is reused.
      if(advance) begin sw<=next_seq; passed[next_index]<=0; end
    end
  end
endmodule

// Rollback orchestration, not a mock pipeline. Every external action waits
// for a real acknowledgement. EVT update precedes context restore/restart.
module pal_rollback #(
  parameter SEQ_W=16, GEN_W=8
)(input wire clk,rst,
  input wire error_valid, input wire [SEQ_W-1:0] error_seq,
  input wire history_capacity_ok, output wire error_ready,
  output wire halt,flush_valid, input wire flush_done,
  output wire history_valid, input wire history_ready,
  output wire restore_valid, input wire restore_done,
  output wire restart_valid, input wire restart_done,
  output reg [SEQ_W-1:0] recovery_boundary,
  output reg [GEN_W-1:0] global_generation,
  output wire generation_exhausted);
  localparam IDLE=0,FLUSH=1,HISTORY=2,RESTORE=3,RESTART=4;
  reg [2:0] state;
  assign generation_exhausted=&global_generation;
  assign error_ready=state==IDLE && history_capacity_ok &&
    !generation_exhausted && error_seq!=0;
  // An unaccepted fault must remain asserted by the producer. Fail closed
  // when finite epoch/generation capacity prevents accepting recovery.
  assign halt=state!=IDLE || error_valid;
  assign flush_valid=state==FLUSH;
  assign history_valid=state==HISTORY;
  assign restore_valid=state==RESTORE;
  assign restart_valid=state==RESTART;
  always @(posedge clk) begin
    if(rst) begin state<=IDLE; recovery_boundary<=0; global_generation<=0; end
    else case(state)
      IDLE: if(error_valid && error_ready) begin recovery_boundary<=error_seq; state<=FLUSH; end
      FLUSH: if(flush_done) state<=HISTORY;
      HISTORY: if(history_ready) begin global_generation<=global_generation+1'b1; state<=RESTORE; end
      RESTORE: if(restore_done) state<=RESTART;
      RESTART: if(restart_done) state<=IDLE;
      default: state<=IDLE;
    endcase
  end
endmodule

// Retained architectural contexts, streamed in order. Commit only after all
// WORDS words arrive. Release is explicit; live slots cannot be overwritten.
// Payload policy (80 words) is in config/scenarios.json, not an ISA guarantee.
module pal_context_store #(
  parameter SLOTS=8,WORDS=80,DATA_W=64,SEQ_W=16,EPOCH_W=4,
  parameter SLOT_W=(SLOTS>1?$clog2(SLOTS):1),
  parameter WORD_W=(WORDS>1?$clog2(WORDS):1),
  parameter ADDR_W=$clog2(SLOTS*WORDS)
)(input wire clk,rst,
  input wire begin_valid,output wire begin_ready,
  input wire [SLOT_W-1:0] begin_slot,
  input wire [SEQ_W-1:0] begin_seq,input wire [EPOCH_W-1:0] begin_epoch,
  input wire word_valid,output wire word_ready,input wire [DATA_W-1:0] word_data,
  output reg committed,
  input wire release_valid,input wire [SLOT_W-1:0] release_slot,
  input wire read_valid,input wire [SLOT_W-1:0] read_slot,
  input wire [WORD_W-1:0] read_word,input wire [SEQ_W-1:0] read_seq,
  input wire [EPOCH_W-1:0] read_epoch,
  output reg data_valid,output reg [DATA_W-1:0] data);
  reg [DATA_W-1:0] mem[0:SLOTS*WORDS-1];
  reg [SLOTS-1:0] live;
  reg [SEQ_W-1:0] seq[0:SLOTS-1];
  reg [EPOCH_W-1:0] epoch[0:SLOTS-1];
  reg filling;
  reg [SLOT_W-1:0] fill_slot;
  reg [WORD_W-1:0] fill_word;
  wire [ADDR_W-1:0] write_addr=ADDR_W'(32'(fill_slot)*WORDS+32'(fill_word));
  wire [ADDR_W-1:0] read_addr=ADDR_W'(32'(read_slot)*WORDS+32'(read_word));
  assign begin_ready=!filling && 32'(begin_slot)<SLOTS && !live[begin_slot] && !rst;
  assign word_ready=filling && !rst;
  always @(posedge clk) begin
    if(rst) begin
      live<=0; filling<=0; fill_slot<=0; fill_word<=0;
      data_valid<=0; committed<=0;
    end else begin
      committed<=0; data_valid<=0;
      if(release_valid && 32'(release_slot)<SLOTS) live[release_slot]<=0;
      if(begin_valid && begin_ready) begin
        filling<=1; fill_slot<=begin_slot; fill_word<=0;
        seq[begin_slot]<=begin_seq; epoch[begin_slot]<=begin_epoch;
      end
      if(word_valid && word_ready) begin
        mem[write_addr]<=word_data;
        if(32'(fill_word)==WORDS-1) begin
          live[fill_slot]<=1; filling<=0; committed<=1;
        end else fill_word<=fill_word+1'b1;
      end
      if(read_valid && 32'(read_slot)<SLOTS && 32'(read_word)<WORDS && live[read_slot] &&
        seq[read_slot]==read_seq && epoch[read_slot]==read_epoch &&
        !(release_valid && release_slot==read_slot)) begin
        data<=mem[read_addr]; data_valid<=1;
      end
    end
  end
endmodule
`default_nettype wire
