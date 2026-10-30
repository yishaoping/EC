// OBSERVATION_ONLY: no outputs and no influence on hardware handshakes.
`timescale 1ps/1ps
module CacheOpportunityObserver #(
  parameter integer LEVEL=1, SETS=1, WAYS=1, BLOCK_BYTES=64, MSHRS=1, PORTS=1
) (
  input clock, reset, clear, enable, stop,
  input [31:0] instance_id, mshr_occupancy,
  input [63:0] cycle,
  input mshr_full,
  input [PORTS-1:0] event_valid,
  input [PORTS*8-1:0] event_kind,
  input [PORTS*32-1:0] event_flags, event_set, event_way, event_occupancy,
  input [PORTS*64-1:0] event_address, event_tag, event_value
);
  // synthesis translate_off
`ifndef SYNTHESIS
  import "DPI-C" function void ec_cache_tick(input int level, id, sets, ways, block_bytes, mshrs,
    input int reset_model, reset_stats, enabled, stopped, occupied, full,
    input longint unsigned cycle_count);
  import "DPI-C" function void ec_cache_event(input int level, id, kind, flags,
    input longint unsigned address, tag, value,
    input int set_index, way, occupancy);
  import "DPI-C" function void ec_cache_finish(input int level, id);
  integer p;
  reg enabled_by_plusarg;
  initial enabled_by_plusarg = $test$plusargs("cache-opportunity");
  always @(posedge clock) if (enabled_by_plusarg) begin
    ec_cache_tick(LEVEL, instance_id, SETS, WAYS, BLOCK_BYTES, MSHRS,
      int'(reset), int'(clear), int'(enable), int'(stop), mshr_occupancy, int'(mshr_full), cycle);
    if (!reset && !clear) for (p=0; p<PORTS; p=p+1) if (event_valid[p])
      ec_cache_event(LEVEL, instance_id, int'(event_kind[p*8+:8]), event_flags[p*32+:32],
        event_address[p*64+:64], event_tag[p*64+:64], event_value[p*64+:64],
        event_set[p*32+:32], event_way[p*32+:32], event_occupancy[p*32+:32]);
  end
  final if (enabled_by_plusarg) begin
    // Final register snapshots, even when STOP precedes the simulator exit.
    // Other events are never replayed in final (that would double-count).
    for (p=0; p<PORTS; p=p+1)
      if (event_kind[p*8+:8] == 30 || event_kind[p*8+:8] == 31)
        ec_cache_event(LEVEL, instance_id, int'(event_kind[p*8+:8]), event_flags[p*32+:32],
          event_address[p*64+:64], event_tag[p*64+:64], event_value[p*64+:64],
          event_set[p*32+:32], event_way[p*32+:32], event_occupancy[p*32+:32]);
    ec_cache_finish(LEVEL, instance_id);
  end
`endif
  // synthesis translate_on
endmodule
