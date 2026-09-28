[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=1012429 boom_inst=649956
[VERIFY] packages allocated=279 completed=279 passed=279 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch        60570      60521         49      95062      94765        297          -          -
[TRAFFIC] boom_strict      60570      60521         49      95062      94765        297      93181       1584
[TRAFFIC] checker_sum      60570      60521         49      95062      94765        297          -          0
[TRAFFIC] c1               17684      17668         16      23566      23470         96          -          0
[TRAFFIC] c2               15854      15838         16      24392      24293         99          -          0
[TRAFFIC] c3               15486      15469         17      24394      24292        102          -          0
[TRAFFIC] c4               11546      11546          0      22710      22710          0          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          1147       1093             620        237        383        383        473 PASS  
[TRAFFIC] L2-DRAM          37         37               7          2          5          5         30 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak first_store_total first_store_peak
[ADDRESS_STATS] byte          92808         4296        22621        67866          958        24992        71877          824        54630          808        88383         4296
[ADDRESS_STATS] word4         23336         1074         5697        17045          240         6289        18067          208         4758           62        22217         1074
[ADDRESS_STATS] word8         11858          540         2943         8698          122         3182         9129          106         1640           31        11224          540
[ADDRESS_STATS] line           1876           73          540         1407           22          523         1363           18           24            3         1670           73
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        106.040        530.204
[LATENCY] dirty_wb                      383 boom        200000000       7520.618      37603.093
[LATENCY] l2_dram_dirty_wb                5 l2          200000000       7066.800      35334.000
[BARRIER] cross_package_store    seen=562 resolved=562 pending=0 dropped=0 wait_cycle_sum=1866241 valid=1 status=PASS
[LATENCY] cross_package_store           562 boom        200000000       3320.713      16603.567
[BARRIER] l1_l2_replacement      seen=361 resolved=361 pending=0 dropped=0 wait_cycle_sum=2838844 valid=1 status=PASS
[LATENCY] l1_l2_replacement             361 boom        200000000       7863.833      39319.168
[BARRIER] l2_dram_replacement    seen=5 resolved=5 pending=0 dropped=0 wait_cycle_sum=35354 valid=1 status=PASS
[LATENCY] l2_dram_replacement             5 l2          200000000       7070.800      35354.000
[END] hart=0 status=PASS
