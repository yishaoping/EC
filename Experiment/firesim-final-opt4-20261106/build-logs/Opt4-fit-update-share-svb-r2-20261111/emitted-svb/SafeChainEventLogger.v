// OBSERVATION_ONLY. Input-only, simulation-only event sink; no protocol output.
// 16 fixed hex words, no cache payload. Change detection excludes cycle labels.
// stderr is separate from byte-stream UART stdout; capture routes to ONE TSV.
// Pinned Verilator fdToFpList maps standard descriptor 0x80000002 to stderr.
// Match simulator precision so $time never rounds several core edges together.
`timescale 1ps/1ps
module SafeChainEventLogger #(
  parameter integer KIND = 0,
  parameter integer MAX_EVENTS = 200000
) (
  input clock,
  input reset,
  input roi,
  input sample,
  input force_event,
  input [63:0] core_cycle,
  input [63:0] local_cycle,
  input [15:0] hart,
  input [1023:0] change_key,
  input [1023:0] data
);
  // synthesis translate_off
`ifndef SYNTHESIS
  reg enabled;
  reg budgeted;
  reg limit_reported;
  reg seen;
  reg previous_roi;
  reg previous_reset;
  reg [1023:0] previous_key;
  integer reset_episode;
  integer emitted;
  integer omitted;
  integer event_limit;
  reg critical;
  initial begin
    enabled = $test$plusargs("safe-chain-events");
    // Opt4 opts in explicitly. Other experiments retain their original policy.
    budgeted = $test$plusargs("safe-chain-budgeted");
    limit_reported = 0;
    seen = 0;
    previous_roi = 0;
    previous_reset = 1;
    previous_key = 0;
    reset_episode = 0;
    emitted = 0;
    omitted = 0;
    event_limit = (budgeted && (KIND == 14 || KIND == 15)) ? 1024 : MAX_EVENTS;
    critical = 1;
  end
  always @(posedge clock) begin
    if (reset) begin
      seen = 0;
      previous_roi = 0;
      previous_reset = 1;
    end else begin
      if (previous_reset) reset_episode = reset_episode + 1;
      previous_reset = 0;
      if (enabled && roi && sample &&
          (!seen || !previous_roi || force_event || change_key !== previous_key)) begin
        critical = !(KIND == 1 || (KIND >= 4 && KIND <= 15 && KIND != 10) || (KIND == 16 && hart != 0));
        if (emitted >= event_limit) begin
          if (!budgeted) begin
            $fwrite(32'h80000002,
              "SC_OVERFLOW kind=%0d hart=%0d emitted=%0d limit=%0d\n",
              KIND, hart, emitted, MAX_EVENTS);
            $fatal(1, "safe-chain per-observer event budget exhausted");
          end
          // Keep the workload running. The host records loss explicitly and
          // refuses correctness/performance PASS if mandatory evidence is lost.
          if (!limit_reported)
            $fwrite(32'h80000002, "SC_LIMIT\t%0d\t%0d\t%0d\t%0d\t%0d\n",
              KIND, hart, emitted, event_limit, critical);
          limit_reported = 1;
          omitted = omitted + 1;
        end else begin
        $fwrite(32'h80000002, "SC1\t%0d\t%0d\t%0d\t%0d\t%0d\t%0d\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\t%016h\n",
          $time, core_cycle, local_cycle, reset_episode, KIND, hart,
          data[63:0], data[127:64], data[191:128], data[255:192],
          data[319:256], data[383:320], data[447:384], data[511:448],
          data[575:512], data[639:576], data[703:640], data[767:704],
          data[831:768], data[895:832], data[959:896], data[1023:960]);
        emitted = emitted + 1;
        end
        previous_key = change_key;
        seen = 1;
      end
      previous_roi = roi;
    end
  end
  final begin
    if (enabled && seen) begin
      $fwrite(32'h80000002, "SC_END\t%0d\t%0d\t%0d\t%0d\t%0d\t%0d\t%0d\n",
        $time, core_cycle, local_cycle, reset_episode, KIND, hart, emitted);
      if (budgeted)
        $fwrite(32'h80000002, "SC_LOG_STATS\t%0d\t%0d\t%0d\t%0d\t%0d\t%0d\n",
          KIND, hart, emitted + omitted, emitted, omitted, event_limit);
    end
  end
`endif
  // synthesis translate_on
endmodule
