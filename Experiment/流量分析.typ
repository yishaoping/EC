[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=905862 boom_inst=649956
[VERIFY] packages allocated=32 completed=32 passed=32 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch         3713       3698         15        723        633         90          -          -
[TRAFFIC] boom_strict       3713       3698         15        723        633         90        618         15
[TRAFFIC] checker_sum       3713       3698         15        723        633         90          -          0
[TRAFFIC] c1                1910       1905          5        243        213         30          -          0
[TRAFFIC] c2                 874        869          5        237        207         30          -          0
[TRAFFIC] c3                 929        924          5        243        213         30          -          0
[TRAFFIC] c4                   0          0          0          0          0          0          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          1097       1045             203        157         46         46        842 PASS  
[TRAFFIC] L2-DRAM          33         33               1          1          0          0         32 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak first_store_total first_store_peak
[ADDRESS_STATS] byte          12352         3564           60           60            4         3720         4272          248         4272          248        12292         3564
[ADDRESS_STATS] word4          3108          891           15           15            1          930         1068           62         1068           62         3093          891
[ADDRESS_STATS] word8          1575          446           15           15            1          465          535           31          465           31         1560          446
[ADDRESS_STATS] line            260           60           15           15            1           75           86            5            0            0          245           60
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  15 boom_eq     200000000        109.733        548.666
[LATENCY] dirty_wb                       46 boom        200000000       3922.347      19611.739
[LATENCY] l2_dram_dirty_wb                0 l2          200000000            n/a            n/a reason=no_events
[BARRIER] cross_package_store    seen=1183 resolved=1183 pending=0 dropped=0 wait_cycle_sum=2076227 valid=1 status=PASS
[LATENCY] cross_package_store          1183 boom        200000000       1755.052       8775.262
[BARRIER] l1_l2_replacement      seen=45 resolved=45 pending=0 dropped=0 wait_cycle_sum=180576 valid=1 status=PASS
[LATENCY] l1_l2_replacement              45 boom        200000000       4012.800      20064.000
[BARRIER] l2_dram_replacement    seen=1 resolved=1 pending=0 dropped=0 wait_cycle_sum=216 valid=1 status=PASS
[LATENCY] l2_dram_replacement             1 l2          200000000        216.000       1080.000
[END] hart=0 status=PASS
