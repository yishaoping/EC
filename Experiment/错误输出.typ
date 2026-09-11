[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=1013429 boom_inst=649956
[TRAFFIC] hart  store[total/cache/unc]       load[total/cache/unc/fwd]
[TRAFFIC] boom  60566/60517/49                 94965/93101/297/1567
[TRAFFIC] c1    17680/17664/16                 24466/24370/96/0
[TRAFFIC] c2    16082/16065/17                 24177/24075/102/0
[TRAFFIC] c3    15246/15231/15                 24994/24901/93/0
[TRAFFIC] c4    11562/11561/1                 21425/21419/6/0
[TRAFFIC] checker_sum store=60570 load=95062
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=0
[TRAFFIC] dcache l1_l2_c=1140 wb_dirty=1084 verify_required=613
[TRAFFIC] dram l2_wb_total=807 l2_wb_dirty=807
[LATENCY] clock=boom:200000000Hz checker:100000000Hz
[LATENCY] store_uncache events=boom=49 checker=49 average=147.163cycles/735.816ns
[VERIFY] packages allocated=280 completed=280 passed=280 failed=0 cancelled=0 status=PASS
[VERIFY] dirty_wb total=613 verified=246 unverified=367 resolved=367 pending=0 other=0 status=PASS
[LATENCY] dirty_wb events=367 average=7269.446cycles/36347.234ns
[END] hart=0 status=PASS
