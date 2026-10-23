- 512 开屏障
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=4512796 boom_inst=649992
[VERIFY] packages allocated=334 completed=334 passed=334 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch        60568      60519         49      95038      94741        297          -          -
[TRAFFIC] boom_strict      60568      60519         49      95038      94741        297      93022       1719
[TRAFFIC] checker_sum      60568      60519         49      95038      94741        297          -          0
[TRAFFIC] c1               20353      20346          7      26643      26601         42          -          0
[TRAFFIC] c2               19443      19425         18      26683      26575        108          -          0
[TRAFFIC] c3               16471      16468          3      24876      24858         18          -          0
[TRAFFIC] c4                4301       4280         21      16836      16707        129          -          0
[TRAFFIC] atomics hart=boom lr=0 sc_success=0 sc_fail=0 amo=4
[TRAFFIC] atomics hart=c1 lr=0 sc_success=0 sc_fail=0 amo=4
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=8
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          2431       2422            1931       1465        466        466        491 PASS  
[TRAFFIC] L2-DRAM          44         42              10         10          0          0         32 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak first_store_total first_store_peak
[ADDRESS_STATS] byte          92901         2144         3865        69722          353        13121        73153          248        55860          248        89642         2140
[ADDRESS_STATS] word4         23401          536          976        17540           90         3287        18431           62         4786           62        22580          535
[ADDRESS_STATS] word8         11907          271          561         8966           46         1655         9328           31         1663           31        11423          270
[ADDRESS_STATS] line           1939           40          198         1506            7          297         1437            5           31            4         1755           39
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        358.387       1791.938
[LATENCY] dirty_wb                      466 boom        200000000      22693.899     113469.495
[LATENCY] l2_dram_dirty_wb                0 l2          200000000            n/a            n/a reason=no_events
[BARRIER] cross_package_store    seen=2430 resolved=2430 pending=0 dropped=0 wait_cycle_sum=4732579 valid=1 status=PASS
[LATENCY] cross_package_store          2430 boom        200000000       1947.563       9737.816
[BARRIER] l1_l2_replacement      seen=459 resolved=459 pending=0 dropped=0 wait_cycle_sum=10516523 valid=1 status=PASS
[LATENCY] l1_l2_replacement             459 boom        200000000      22911.814     114559.074
[BARRIER] l2_dram_replacement    seen=7 resolved=7 pending=0 dropped=0 wait_cycle_sum=62223 valid=1 status=PASS
[LATENCY] l2_dram_replacement             7 l2          200000000       8889.000      44445.000
[END] hart=0 status=PASS


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

