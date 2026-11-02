
= Store_uncache
== Boom
BoomTile
csr->core `io.csr_cycle := csr.io.time`
core->dcache `outer.dcache.module.io.csr_cycle := core.io.csr_cycle`
dcache `store_uncache_cycle_sum + io.csr_cycle`

```
when (completed_store_uncache) {
  store_uncache_cycle_sum := store_uncache_cycle_sum + io.csr_cycle
}
```

```
io.traffic_counter := VecInit(Seq(
  store_cache_count + store_uncache_count,
  store_cache_count,
  store_uncache_count,
  load_cache_count + load_uncache_count + load_forward_count,
  load_cache_count,
  load_uncache_count,
  load_forward_count,
  lr_count,
  sc_success_count,
  sc_fail_count,
  amo_cache_count + amo_uncache_count,
  amo_cache_count,
  amo_uncache_count,
  l1_l2_wb_total_count,
  l1_l2_wb_dirty_count,
  0.U(64.W),
  0.U(64.W),
  store_uncache_cycle_sum))
```
== Rocket
```
  val st_uncache_count_at_packet_completion      = debug_perf_num_st_uncache_in_packet + io.st_uncache_deq
  val st_uncache_packet_cycle_contribution       = io.csr_cycle * st_uncache_count_at_packet_completion
  when (io.debug_perf_reset.asBool) {
    debug_perf_num_st_uncache_in_packet          := 0.U
    debug_perf_st_uncache_cycle_sum              := 0.U
  }.elsewhen (io.if_check_completed.asBool) {
    debug_perf_num_st_uncache_in_packet          := 0.U
    debug_perf_st_uncache_cycle_sum              := debug_perf_st_uncache_cycle_sum + st_uncache_packet_cycle_contribution(63, 0)
  }.elsewhen (io.st_uncache_deq.asBool) {
    debug_perf_num_st_uncache_in_packet          := st_uncache_count_at_packet_completion
  }
```
