# 计数对照：没有有效paired delta

|Exact-ROI counter|A|B|A−B|
|---|---:|---:|---:|
|ROB_HEAD_LOAD_BLOCK_AND_SCHEDULER_UNAVAILABLE_CYCLES|17|UNAVAILABLE|UNAVAILABLE|
|ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_BUSY_CYCLES|139,500|UNAVAILABLE|UNAVAILABLE|
|ROB_HEAD_WAITING_ON_LOAD_MISS_AND_MSHR_FULL_CYCLES|0|UNAVAILABLE|UNAVAILABLE|
|ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES|139,694|UNAVAILABLE|UNAVAILABLE|
|SCHEDULER_UNAVAILABLE_AND_MSHR_BUSY_CYCLES|154|UNAVAILABLE|UNAVAILABLE|
|SCHEDULER_UNAVAILABLE_AND_MSHR_FULL_CYCLES|0|UNAVAILABLE|UNAVAILABLE|
|alloc_refill_samples|2,162|UNAVAILABLE|UNAVAILABLE|
|alloc_refill_sum|274,470|UNAVAILABLE|UNAVAILABLE|
|any_ldq_miss_pending_cycles|145,926|UNAVAILABLE|UNAVAILABLE|
|completed_miss_head_episode_cycles|139,694|UNAVAILABLE|UNAVAILABLE|
|completed_misses_ever_head|409|UNAVAILABLE|UNAVAILABLE|
|detect_alloc_samples|1,380|UNAVAILABLE|UNAVAILABLE|
|detect_alloc_sum|447,552|UNAVAILABLE|UNAVAILABLE|
|detect_data_samples|1,530|UNAVAILABLE|UNAVAILABLE|
|detect_data_sum|532,192|UNAVAILABLE|UNAVAILABLE|
|load_miss_lookup_attempts|112,461|UNAVAILABLE|UNAVAILABLE|
|load_nack_cycles|111,557|UNAVAILABLE|UNAVAILABLE|
|load_nack_retries|111,548|UNAVAILABLE|UNAVAILABLE|
|load_nack_retry_cycles|111,548|UNAVAILABLE|UNAVAILABLE|
|load_nacks|111,557|UNAVAILABLE|UNAVAILABLE|
|load_permission_miss_requests|9|UNAVAILABLE|UNAVAILABLE|
|load_rpq_replay_and_mshr_busy_events|321|UNAVAILABLE|UNAVAILABLE|
|load_rpq_replay_and_mshr_full_events|0|UNAVAILABLE|UNAVAILABLE|
|load_rpq_replay_cycles|321|UNAVAILABLE|UNAVAILABLE|
|load_rpq_replays|321|UNAVAILABLE|UNAVAILABLE|
|load_tag_miss_requests|1,533|UNAVAILABLE|UNAVAILABLE|
|miss_returns_still_head|409|UNAVAILABLE|UNAVAILABLE|
|mshr_busy_cycles|313,150|UNAVAILABLE|UNAVAILABLE|
|mshr_full_cycles|0|UNAVAILABLE|UNAVAILABLE|
|mshr_merges|952|UNAVAILABLE|UNAVAILABLE|
|mshr_primary_allocations|2,162|UNAVAILABLE|UNAVAILABLE|
|mshr_request_rejects|47,064|UNAVAILABLE|UNAVAILABLE|
|mshr_upgrade_allocations|115|UNAVAILABLE|UNAVAILABLE|
|nack_data|0|UNAVAILABLE|UNAVAILABLE|
|nack_hit|0|UNAVAILABLE|UNAVAILABLE|
|nack_mshr_not_ready|111,074|UNAVAILABLE|UNAVAILABLE|
|nack_victim|474|UNAVAILABLE|UNAVAILABLE|
|nack_writeback|3,885|UNAVAILABLE|UNAVAILABLE|
|recycled_pending_slots|2,565|UNAVAILABLE|UNAVAILABLE|
|refill_completions|2,162|UNAVAILABLE|UNAVAILABLE|
|rob_head_load_pending_cycles|151,352|UNAVAILABLE|UNAVAILABLE|
|sample_cycles|1,707,863|UNAVAILABLE|UNAVAILABLE|
|scheduler_unavailable_cycles|318,150|UNAVAILABLE|UNAVAILABLE|
|store_miss_lookup_attempts|6,898|UNAVAILABLE|UNAVAILABLE|
|store_permission_miss_requests|103|UNAVAILABLE|UNAVAILABLE|
|store_tag_miss_requests|2,478|UNAVAILABLE|UNAVAILABLE|

A MSHR occupancy bins0–6：`[1394713, 312184, 953, 13, 0, 0, 0]`；sum=1,707,863。

load detect→accept: A samples=1380, mean=324.3130 cycles；B unavailable

MSHR alloc→refill: A samples=2162, mean=126.9519 cycles；B unavailable

load detect→data: A samples=1530, mean=347.8379 cycles；B unavailable

三类是completion-in-ROI不同cohort，不能相乘/相减推算收益。

B aborted，缺少final summaries，不以0或shadow1,301补齐。Native首次失败lookup与legacy首次lookup的定义不同，详见causal_counter_schema.md。
