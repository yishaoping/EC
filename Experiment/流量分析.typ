= gapbs
- 512
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=1011467 boom_inst=649956
[TRAFFIC] hart  store[total/cache/unc]       load[total/cache/unc/fwd]
[TRAFFIC] boom  60372/60323/49                 94926/93063/297/1566
[TRAFFIC] c1    19054/19038/16                 23637/23541/96/0
[TRAFFIC] c2    17566/17549/17                 23564/23462/102/0
[TRAFFIC] c3    13734/13719/15                 25773/25680/93/0
[TRAFFIC] c4    10216/10215/1                 22088/22082/6/0
[TRAFFIC] checker_sum store=60570 load=95062
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=0
[TRAFFIC] dcache l1_l2_c=1135 wb_dirty=1080 verify_required=605
[TRAFFIC] dram l2_wb_total=43 l2_wb_dirty=43
[TRAFFIC] dram_verify required=9 verified=7 unverified=2 resolved=2 pending=0 other=34 status=PASS
[TRAFFIC] dram_verify_cycle_sum writeback=258181 verification=265526
[TRAFFIC_ARCH] boom store=60570 load=95062
[TRAFFIC_ARCH] store_cache=60521 store_uncache=49 load_cache=94765 load_uncache=297
[TRAFFIC_STRICT] boom store=60570 load=95062
[TRAFFIC_STRICT] store_cache=60521 store_uncache=49 load_cache=94765 load_uncache=297 load_cache_response=93184 load_forward=1581 pending=0
[TRAFFIC_CHECKER] sum store=60570 load=95062
[TRAFFIC_CHECKER] store_cache=60521 store_uncache=49 load_cache=94765 load_uncache=297 load_forward=0
[ASSERT] store arch=60570 strict=60570 checker=60570 result=PASS
[ASSERT] load arch=95062 strict=95062 checker=95062 result=PASS
[ASSERT] traffic_counter_fail=0 pending=0 result=PASS
[LATENCY] clock=boom:200000000Hz checker:100000000Hz
[LATENCY] store_uncache events=boom=49 checker=49 average=145.204cycles/726.020ns
[VERIFY] packages allocated=280 completed=280 passed=280 failed=0 cancelled=0 status=PASS
[VERIFY] dirty_wb total=605 verified=263 unverified=342 resolved=342 pending=0 other=0 status=PASS
[VERIFY] dirty_wb_cycle_sum writeback_cycle_sum=190891038 verification_cycle_sum=193643746
[SOFTWARE_VERIFY] dirty_wb required=605 verified_at_writeback=263 unverified_at_writeback=342 writeback_cycle_sum=190891038 verification_cycle_sum=193643746
[LATENCY] dirty_wb events=342 average=8048.853cycles/40244.269ns
[SOFTWARE_VERIFY] l2_dram_dirty_wb required=9 verified_at_writeback=7 unverified_at_writeback=2 other=34 writeback_cycle_sum=258181 verification_cycle_sum=265526
[LATENCY] clock=l2:200000000Hz
[LATENCY] l2_dram_dirty_wb events=2 average=3672.500cycles/18362.500ns
[END] hart=0 status=PASS
