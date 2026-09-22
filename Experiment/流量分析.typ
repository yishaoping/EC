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

- 1024
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=1024 source=0 reached=1024 edges=16384 verified=1 parent_checksum=351572336
[PERF] boom_cycles=2127321 boom_inst=1499780
[TRAFFIC] hart  store[total/cache/unc]       load[total/cache/unc/fwd]
[TRAFFIC] boom  184539/184490/49                 175200/171825/297/3078
[TRAFFIC] c1    49473/49457/16                 44957/44861/96/0
[TRAFFIC] c2    48793/48777/16                 44349/44253/96/0
[TRAFFIC] c3    47284/47267/17                 45190/45085/105/0
[TRAFFIC] c4    39468/39468/0                 41014/41014/0/0
[TRAFFIC] checker_sum store=185018 load=175510
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=0
[TRAFFIC] dcache l1_l2_c=2364 wb_dirty=2311 verify_required=1856
[TRAFFIC] dram l2_wb_total=64 l2_wb_dirty=64
[TRAFFIC] dram_verify required=8 verified=4 unverified=4 resolved=4 pending=0 other=55 status=PASS
[TRAFFIC] dram_verify_cycle_sum writeback=3760314 verification=3814122
[TRAFFIC_ARCH] boom store=185018 load=175510
[TRAFFIC_ARCH] store_cache=184969 store_uncache=49 load_cache=175213 load_uncache=297
[TRAFFIC_STRICT] boom store=185018 load=175510
[TRAFFIC_STRICT] store_cache=184969 store_uncache=49 load_cache=175213 load_uncache=297 load_cache_response=172096 load_forward=3117 pending=0
[TRAFFIC_CHECKER] sum store=185018 load=175510
[TRAFFIC_CHECKER] store_cache=184969 store_uncache=49 load_cache=175213 load_uncache=297 load_forward=0
[ASSERT] store arch=185018 strict=185018 checker=185018 result=PASS
[ASSERT] load arch=175510 strict=175510 checker=175510 result=PASS
[ASSERT] traffic_counter_fail=0 pending=0 result=PASS
[LATENCY] clock=boom:200000000Hz checker:100000000Hz
[LATENCY] store_uncache events=boom=49 checker=49 average=143.285cycles/716.428ns
[VERIFY] packages allocated=537 completed=537 passed=537 failed=0 cancelled=0 status=PASS
[VERIFY] dirty_wb total=1856 verified=1175 unverified=681 resolved=681 pending=0 other=0 status=PASS
[VERIFY] dirty_wb_cycle_sum writeback_cycle_sum=630782700 verification_cycle_sum=637021359
[SOFTWARE_VERIFY] dirty_wb required=1856 verified_at_writeback=1175 unverified_at_writeback=681 writeback_cycle_sum=630782700 verification_cycle_sum=637021359
[LATENCY] dirty_wb events=681 average=9161.026cycles/45805.132ns
[SOFTWARE_VERIFY] l2_dram_dirty_wb required=8 verified_at_writeback=4 unverified_at_writeback=4 other=55 writeback_cycle_sum=3760314 verification_cycle_sum=3814122
[LATENCY] clock=l2:200000000Hz
[LATENCY] l2_dram_dirty_wb events=4 average=13452.000cycles/67260.000ns
[END] hart=0 status=PASS

- 2048
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=2048 source=0 reached=2048 edges=32768 verified=1 parent_checksum=2835089264
[PERF] boom_cycles=4982237 boom_inst=4182469
[TRAFFIC] hart  store[total/cache/unc]       load[total/cache/unc/fwd]
[TRAFFIC] boom  629062/629013/49                 433703/427288/297/6118
[TRAFFIC] c1    194222/194207/15                 84842/84749/93/0
[TRAFFIC] c2    153235/153219/16                 120574/120478/96/0
[TRAFFIC] c3    113408/113392/16                 145694/145598/96/0
[TRAFFIC] c4    169657/169655/2                 83600/83588/12/0
[TRAFFIC] checker_sum store=630522 load=434710
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=0
[TRAFFIC] dcache l1_l2_c=4439 wb_dirty=4382 verify_required=4002
[TRAFFIC] dram l2_wb_total=104 l2_wb_dirty=103
[TRAFFIC] dram_verify required=37 verified=29 unverified=8 resolved=8 pending=0 other=66 status=PASS
[TRAFFIC] dram_verify_cycle_sum writeback=8691235 verification=8772978
[TRAFFIC_ARCH] boom store=630522 load=434710
[TRAFFIC_ARCH] store_cache=630473 store_uncache=49 load_cache=434413 load_uncache=297
[TRAFFIC_STRICT] boom store=630522 load=434710
[TRAFFIC_STRICT] store_cache=630473 store_uncache=49 load_cache=434413 load_uncache=297 load_cache_response=428224 load_forward=6189 pending=0
[TRAFFIC_CHECKER] sum store=630522 load=434710
[TRAFFIC_CHECKER] store_cache=630473 store_uncache=49 load_cache=434413 load_uncache=297 load_forward=0
[ASSERT] store arch=630522 strict=630522 checker=630522 result=PASS
[ASSERT] load arch=434710 strict=434710 checker=434710 result=PASS
[ASSERT] traffic_counter_fail=0 pending=0 result=PASS
[LATENCY] clock=boom:200000000Hz checker:100000000Hz
[LATENCY] store_uncache events=boom=49 checker=49 average=141.510cycles/707.551ns
[VERIFY] packages allocated=1385 completed=1385 passed=1385 failed=0 cancelled=0 status=PASS
[VERIFY] dirty_wb total=4002 verified=2619 unverified=1383 resolved=1383 pending=0 other=0 status=PASS
[VERIFY] dirty_wb_cycle_sum writeback_cycle_sum=2394805962 verification_cycle_sum=2409532795
[SOFTWARE_VERIFY] dirty_wb required=4002 verified_at_writeback=2619 unverified_at_writeback=1383 writeback_cycle_sum=2394805962 verification_cycle_sum=2409532795
[LATENCY] dirty_wb events=1383 average=10648.469cycles/53242.346ns
[SOFTWARE_VERIFY] l2_dram_dirty_wb required=37 verified_at_writeback=29 unverified_at_writeback=8 other=66 writeback_cycle_sum=8691235 verification_cycle_sum=8772978
[LATENCY] clock=l2:200000000Hz
[LATENCY] l2_dram_dirty_wb events=8 average=10217.875cycles/51089.375ns
[END] hart=0 status=PASS

- 4096
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=4096 source=0 reached=4096 edges=65536 verified=1 parent_checksum=22787322736
[PERF] boom_cycles=13102551 boom_inst=13480004
[TRAFFIC] hart  store[total/cache/unc]       load[total/cache/unc/fwd]
[TRAFFIC] boom  2302934/2302885/49                 1342520/1330051/297/12172
[TRAFFIC] c1    588107/588092/15                 338241/338151/90/0
[TRAFFIC] c2    587478/587462/16                 338463/338367/96/0
[TRAFFIC] c3    589064/589048/16                 336696/336597/99/0
[TRAFFIC] c4    543313/543311/2                 332926/332914/12/0
[TRAFFIC] checker_sum store=2307962 load=1346326
[TRAFFIC] atomics total lr=0 sc_success=0 sc_fail=0 amo=0
[TRAFFIC] dcache l1_l2_c=9485 wb_dirty=9420 verify_required=9219
[TRAFFIC] dram l2_wb_total=215 l2_wb_dirty=214
[TRAFFIC] dram_verify required=140 verified=105 unverified=35 resolved=35 pending=0 other=73 status=PASS
[TRAFFIC] dram_verify_cycle_sum writeback=99313129 verification=99765749
[TRAFFIC_ARCH] boom store=2307962 load=1346326
[TRAFFIC_ARCH] store_cache=2307913 store_uncache=49 load_cache=1346029 load_uncache=297
[TRAFFIC_STRICT] boom store=2307962 load=1346326
[TRAFFIC_STRICT] store_cache=2307913 store_uncache=49 load_cache=1346029 load_uncache=297 load_cache_response=1333696 load_forward=12333 pending=0
[TRAFFIC_CHECKER] sum store=2307962 load=1346326
[TRAFFIC_CHECKER] store_cache=2307913 store_uncache=49 load_cache=1346029 load_uncache=297 load_forward=0
[ASSERT] store arch=2307962 strict=2307962 checker=2307962 result=PASS
[ASSERT] load arch=1346326 strict=1346326 checker=1346326 result=PASS
[ASSERT] traffic_counter_fail=0 pending=0 result=PASS
[LATENCY] clock=boom:200000000Hz checker:100000000Hz
[LATENCY] store_uncache events=boom=49 checker=49 average=140.857cycles/704.285ns
[VERIFY] packages allocated=4388 completed=4388 passed=4388 failed=0 cancelled=0 status=PASS
[VERIFY] dirty_wb total=9219 verified=6341 unverified=2878 resolved=2878 pending=0 other=0 status=PASS
[VERIFY] dirty_wb_cycle_sum writeback_cycle_sum=10909803846 verification_cycle_sum=10938698240
[SOFTWARE_VERIFY] dirty_wb required=9219 verified_at_writeback=6341 unverified_at_writeback=2878 writeback_cycle_sum=10909803846 verification_cycle_sum=10938698240
[LATENCY] dirty_wb events=2878 average=10039.747cycles/50198.738ns
[SOFTWARE_VERIFY] l2_dram_dirty_wb required=140 verified_at_writeback=105 unverified_at_writeback=35 other=73 writeback_cycle_sum=99313129 verification_cycle_sum=99765749
[LATENCY] clock=l2:200000000Hz
[LATENCY] l2_dram_dirty_wb events=35 average=12932.000cycles/64660.000ns
[END] hart=0 status=PASS


= GAP 新版
[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=512 source=0 reached=512 edges=8192 verified=1 parent_checksum=43439728
[PERF] boom_cycles=1012854 boom_inst=649956
[VERIFY] packages allocated=280 completed=280 passed=280 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch        60570      60521         49      95062      94765        297          -          -
[TRAFFIC] boom_strict      60570      60521         49      95062      94765        297      93181       1584
[TRAFFIC] checker_sum      60570      60521         49      95062      94765        297          -          0
[TRAFFIC] c1               17572      17556         16      23387      23291         96          -          0
[TRAFFIC] c2               15729      15713         16      24747      24648         99          -          0
[TRAFFIC] c3               15982      15965         17      25202      25100        102          -          0
[TRAFFIC] c4               11287      11287          0      21726      21726          0          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          1128       1073             600        233        367        367        473 PASS  
[TRAFFIC] L2-DRAM          41         41               7          3          4          4         34 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak
[ADDRESS_STATS] byte          92811         4304        22616        68016          911        25056        71919          663        54760          663
[ADDRESS_STATS] word4         23355         1076         5701        17089          229         6308        18096          167         4766           62
[ADDRESS_STATS] word8         11875          541         2950         8731          117         3181         9142           85         1647           31
[ADDRESS_STATS] line           1884           73          538         1417           21          518         1365           14           23            4
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        137.326        686.632
[LATENCY] dirty_wb                      367 boom        200000000       7087.937      35439.686
[LATENCY] l2_dram_dirty_wb                4 l2          200000000      11367.250      56836.250
[END] hart=0 status=PASS

[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=1024 source=0 reached=1024 edges=16384 verified=1 parent_checksum=351572336
[PERF] boom_cycles=2129711 boom_inst=1499780
[VERIFY] packages allocated=539 completed=539 passed=539 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch       185018     184969         49     175510     175213        297          -          -
[TRAFFIC] boom_strict     185018     184969         49     175510     175213        297     172098       3115
[TRAFFIC] checker_sum     185018     184969         49     175510     175213        297          -          0
[TRAFFIC] c1               48444      48428         16      45036      44940         96          -          0
[TRAFFIC] c2               48901      48885         16      44397      44301         96          -          0
[TRAFFIC] c3               49378      49363         15      44178      44085         93          -          0
[TRAFFIC] c4               38295      38293          2      41899      41887         12          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          2392       2336            1883       1156        727        727        453 PASS  
[TRAFFIC] L2-DRAM          78         78              12          5          7          7         66 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak
[ADDRESS_STATS] byte         238525         8192        75019       145350         1108        65066       196780          943       131607          943
[ADDRESS_STATS] word4         59981         2048        18867        36504          277        16395        49500          237         6369           62
[ADDRESS_STATS] word8         30391         1027         9649        18542          141         8314        24995          119         1715           31
[ADDRESS_STATS] line           4560          136         1616         2895           25         1302         3600           19           43            3
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        144.551        722.755
[LATENCY] dirty_wb                      727 boom        200000000       8548.235      42741.176
[LATENCY] l2_dram_dirty_wb                7 l2          200000000       5853.142      29265.714
[END] hart=0 status=PASS

[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=2048 source=0 reached=2048 edges=32768 verified=1 parent_checksum=2835089264
[PERF] boom_cycles=5010949 boom_inst=4182469
[VERIFY] packages allocated=1383 completed=1383 passed=1383 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch       630522     630473         49     434710     434413        297          -          -
[TRAFFIC] boom_strict     630522     630473         49     434710     434413        297     428227       6186
[TRAFFIC] checker_sum     630522     630473         49     434710     434413        297          -          0
[TRAFFIC] c1              125940     125924         16     138236     138140         96          -          0
[TRAFFIC] c2              193963     193948         15      84897      84804         93          -          0
[TRAFFIC] c3              140580     140563         17     128606     128504        102          -          0
[TRAFFIC] c4              170039     170038          1      82971      82965          6          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          4471       4413            4012       2605       1407       1407        401 PASS  
[TRAFFIC] L2-DRAM         107        106              20         13          7          7         86 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak
[ADDRESS_STATS] byte         726660         8528       145191       416207          658        44757       647856          615       383090          599
[ADDRESS_STATS] word4        182716         2132        36537       104493          165        11461       162936          155         9680           62
[ADDRESS_STATS] word8         92366         1070        18731        52910           84         5930        82137           78         1933           31
[ADDRESS_STATS] line          13372          141         3180         7764           14         1193        11494           12           83            4
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        145.428        727.142
[LATENCY] dirty_wb                     1407 boom        200000000      10090.667      50453.336
[LATENCY] l2_dram_dirty_wb                7 l2          200000000      16429.571      82147.857
[END] hart=0 status=PASS

[UART] UART0 is here (stdin/stdout).
[INIT] checker_mask=0xf status=ready
[INIT] software_interrupt=pass
[RUN] hart=0 status=started
[CONFIG] big_core_perf=off checker_perf=on interval_cycles=5000 sample_readback=not_collected
[RUN] benchmark=gapbs_bfs nodes=4096 source=0 reached=4096 edges=65536 verified=1 parent_checksum=22787322736
[PERF] boom_cycles=13089740 boom_inst=13480004
[VERIFY] packages allocated=4411 completed=4411 passed=4411 status=PASS
[TRAFFIC] source        st_total   st_cache st_uncache   ld_total   ld_cache ld_uncache ld_response ld_forward
[TRAFFIC] boom_arch      2307962    2307913         49    1346326    1346029        297          -          -
[TRAFFIC] boom_strict    2307962    2307913         49    1346326    1346029        297    1333693      12336
[TRAFFIC] checker_sum    2307962    2307913         49    1346326    1346029        297          -          0
[TRAFFIC] c1              591126     591110         16     336431     336335         96          -          0
[TRAFFIC] c2              587633     587617         16     338073     337977         96          -          0
[TRAFFIC] c3              587130     587120         10     337001     336938         63          -          0
[TRAFFIC] c4              542073     542066          7     334821     334779         42          -          0
[TRAFFIC] path          total      dirty verify_required   verified unverified   resolved  nonverify status
[TRAFFIC] L1-L2          9426       9368            9150       6315       2835       2835        218 PASS  
[TRAFFIC] L2-DRAM         210        210             129        105         24         24         81 PASS  
[ADDRESS_STATS] unit    store_total   store_peak     lf_lower     lf_upper      lf_peak     sf_lower     sf_upper      sf_peak    swr_total     swr_peak
[ADDRESS_STATS] byte        2489188        12648        34336      1413813          136        29364      2345700          248      1273232          248
[ADDRESS_STATS] word4        625597         3162         8584       355314           34         7471       589574           62        16232           62
[ADDRESS_STATS] word8        315546         1584         4790       179516           20         3945       296977           31         2250           31
[ADDRESS_STATS] line          44408          206         1477        26064            7          922        41084            6          190            4
[LATENCY] metric                     events clock    frequency_hz     avg_cycles         avg_ns
[LATENCY] store_uncache                  49 boom_eq     200000000        133.346        666.734
[LATENCY] dirty_wb                     2835 boom        200000000      10034.402      50172.010
[LATENCY] l2_dram_dirty_wb               24 l2          200000000      13326.750      66633.750
[END] hart=0 status=PASS

= 写回总结
