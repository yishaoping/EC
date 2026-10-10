- 512 开屏障
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=0 parent_checksum=43363075
[PERF] boom_cycles=1475683 boom_inst=621112
[VERIFY] packages allocated=259 completed=259 passed=259 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch        61556      61507         49      84966      84669        297          -          -
[TRAFFIC] boom_strict      61556      61507         49      84966      84669        297      82965       1704
[TRAFFIC] checker_sum      61674      61625         49      85132      84835        297          -          0
[TRAFFIC] c1               19196      19182         14      26470      26383         87          -          0
[TRAFFIC] c2               18386      18368         18      24620      24512        108          -          0
[TRAFFIC] c3               18662      18647         15      22893      22803         90          -          0
[TRAFFIC] c4                5430       5428          2      11149      11137         12          -          0
[ASSERT] store arch=61556 strict=61556 checker=61674 result=FAIL
[ASSERT_DIAG] store_arch_minus_checker=-118
[ASSERT_DIAG] store_cache_arch_minus_checker=-118
[ASSERT] load arch=84966 strict=84966 checker=85132 result=FAIL
[ASSERT_DIAG] load_arch_minus_checker=-166
[ASSERT_DIAG] load_cache_arch_minus_checker=-166
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          1255       1200             728        394        334        334        472 PASS  
[TRAFFIC] L2-DRAM          37         37               3          3          0          0         34 PASS  
[ADDRESS_STATS] status=FAIL valid=0 error=0x10 pending=0
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        114.306        571.530
[LATENCY] dirty_wb                      334 boom        200000000       7650.011      38250.059
[LATENCY] l2_dram_dirty_wb                0 l2          200000000            n/a            n/a reason=no_events
[BARRIER] cross_package_store    seen=58782 resolved=58782 pending=0 dropped=0 wait_cycle_sum=185307341 valid=1 status=PASS
[LATENCY] cross_package_store         58782 boom        200000000       3152.450      15762.252
[BARRIER] l1_l2_replacement      seen=325 resolved=325 pending=0 dropped=0 wait_cycle_sum=2555182 valid=1 status=PASS
[LATENCY] l1_l2_replacement             325 boom        200000000       7862.098      39310.492
[BARRIER] l2_dram_replacement    seen=2 resolved=2 pending=0 dropped=0 wait_cycle_sum=398 valid=1 status=PASS
[LATENCY] l2_dram_replacement             2 l2          200000000        199.000        995.000
[END] hart=0 status=FAIL

- 512 未开屏障
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=1012405 boom_inst=649956
[VERIFY] packages allocated=279 completed=279 passed=279 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch        60570      60521         49      95062      94765        297          -          -
[TRAFFIC] boom_strict      60570      60521         49      95062      94765        297      93178       1587
[TRAFFIC] checker_sum      60570      60521         49      95062      94765        297          -          0
[TRAFFIC] c1               17487      17471         16      23719      23623         96          -          0
[TRAFFIC] c2               15956      15940         16      24680      24581         99          -          0
[TRAFFIC] c3               17762      17745         17      23187      23085        102          -          0
[TRAFFIC] c4                9365       9365          0      23476      23476          0          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          1162       1107             632        228        404        404        475 PASS  
[TRAFFIC] L2-DRAM          48         47               6          1          5          5         41 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak first_store_total first_store_peak
[ADDRESS_STATS] byte          92797         4296        22584        67756          925        25200        71758          660        54524          644        88301         4296
[ADDRESS_STATS] word4         23341         1074         5695        17022          233         6333        18043          167         4764           62        22206         1074
[ADDRESS_STATS] word8         11850          538         2948         8692          119         3191         9103           84         1644           31        11204          538
[ADDRESS_STATS] line           1857           73          540         1412           21          511         1345           14           26            4         1652           73
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        107.673        538.367
[LATENCY] dirty_wb                      404 boom        200000000       7007.940      35039.702
[LATENCY] l2_dram_dirty_wb                5 l2          200000000      11956.000      59780.000
[BARRIER] cross_package_store    seen=536 resolved=536 pending=0 dropped=0 wait_cycle_sum=1760848 valid=1 status=PASS
[LATENCY] cross_package_store           536 boom        200000000       3285.164      16425.820
[BARRIER] l1_l2_replacement      seen=370 resolved=370 pending=0 dropped=0 wait_cycle_sum=2758228 valid=1 status=PASS
[LATENCY] l1_l2_replacement             370 boom        200000000       7454.670      37273.351
[BARRIER] l2_dram_replacement    seen=5 resolved=5 pending=0 dropped=0 wait_cycle_sum=59800 valid=1 status=PASS
[LATENCY] l2_dram_replacement             5 l2          200000000      11960.000      59800.000
[END] hart=0 status=PASS

