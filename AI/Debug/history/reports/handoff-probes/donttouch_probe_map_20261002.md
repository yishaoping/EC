# Remaining-failure waveform probes

The source now retains observation-only aliases for the unresolved `verified=0`
data path and for the checker/BOOM traffic-window boundary. The aliases are
marked with Chisel `dontTouch`; they do not drive any control, arbitration,
completion, or statistics logic.

## BOOM DCache

Source: `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`

- Window: `debug_traffic_counting`, `debug_traffic_start`,
  `debug_traffic_stop`, `debug_traffic_reset`.
- Pipeline identity: `debug_s0_*`, `debug_s1_*`, `debug_s2_addr`,
  `debug_s2_data`, `debug_s2_packet_seq`, `debug_s2_send_resp`,
  `debug_s2_send_nack`.
- Data return: `debug_cache_resp_*`, `debug_uncache_resp_*`,
  `debug_lsu_resp_*`.
- Physical completion: `debug_data_write_valid`,
  `debug_data_write_fire`, `debug_data_write_addr`,
  `debug_data_write_data`, `debug_data_write_wmask`,
  `debug_data_write_way_en`.
- Hit and metadata state: `debug_s2_hit`, `debug_s2_tag_match`,
  `debug_s2_hit_state`, `debug_meta_write_*`.
- TileLink memory path: `debug_tl_a_*`, `debug_tl_c_*`, and `debug_tl_d_*`
  retain fire, opcode, address/source, permission parameter, and data.
- Line attribution: `debug_modifying_set`, `debug_modifying_way`,
  `debug_overwritten_packet_seq`, `debug_overwritten_packet_tracked`.
- Cross-package barrier: `debug_cross_package_wb_valid`,
  `debug_cross_package_wb_ready`, `debug_cross_package_wb_fire`,
  `debug_cross_package_wb_param`, `debug_cross_package_wb_done`,
  `debug_cross_package_meta_clear_valid`,
  `debug_cross_package_meta_clear_fire`, plus the existing
  `debug_cross_package_*` state probes.
- Address statistics: `debug_address_stats_event_*`,
  `debug_address_stats_valid`, `debug_address_stats_error`,
  `debug_address_stats_pending`.

For a suspected `parent[node]` mismatch, correlate the same address and packet
sequence through S0/S1/S2, `debug_data_write_*`, and the response signals. A
store is physically complete only when `debug_data_write_fire` is high; a
nack/replay alone is not completion.

## BOOM LSU

Source: `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`

- Architectural and strict event vectors: `debug_arch_*_events` and
  `debug_strict_*_events`.
- Address event payload: `debug_address_stats_event_valid`,
  `debug_address_stats_event_addr`,
  `debug_address_stats_event_is_store`,
  `debug_address_stats_event_seq`.
- Window and accounting snapshot: `debug_traffic_counting`,
  `debug_traffic_reset`, `debug_traffic_arch_counter`.
- Existing queue/request probes retain STQ head identity, packet sequence,
  strict token, DMem request/nack, and cache/uncache completion matching.

Use the saved STQ token and `packet_seq` together when deciding whether a
completion belongs to a request. A reused STQ index by itself is ambiguous.

## Rocket checker FSM

Source: `chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala`

The retained probes include `fsm_state`, `fsm_state_delay`,
`trafficEnabled`, `trafficCounting`, package completion latches,
`instruction_completion`, `waiting_for_package_tail`, completion pulses,
stall conditions, and the local cache/uncache/LR/SC/AMO counters.

The intended boundary is `fsm_checking`, `fsm_checking_priv`,
`fsm_postchecking`, or `fsm_postchecking_priv` while `trafficCounting` is high.
Events in `fsm_nonchecking` should not be attributed to the checker package.

## Verification performed

```text
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

The compile passed on 2026-10-02. No Verilator simulation and no RTL/hardware
generation were run. The next simulation should first inspect the first
address/data mismatch, then the corresponding writeback/replay and checker
window signals using the categories above.

## FIRRTL annotation fix

The generator error

```text
java.lang.NumberFormatException: For input string: "debug_modifying_set"
```

came from `chisel3.dontTouch` converting a probe that was a direct alias of a
dynamic cache-array index expression. The older FIRRTL target parser treated
that alias as an `Index` component and attempted to parse its name as an
integer. `debug_modifying_set`, `debug_modifying_way`,
`debug_overwritten_packet_seq`, and `debug_overwritten_packet_tracked` are now
explicit named `Wire`s before `dontTouch` is applied. This is an annotation-only
change and does not alter cache behavior.
