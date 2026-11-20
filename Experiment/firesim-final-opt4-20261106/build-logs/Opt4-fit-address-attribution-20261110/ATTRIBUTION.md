# Completed first-fit address DCP: mapped-name attribution

2026-11-10T12:54:18.808713+00:00

Disjoint primitive groups by mapped name only, not physical LUT count or proven source cones. Cross-name optimization may move logic.

| Mapped name group | LUT primitives | CARRY8 | FF | DSP |
|---|---:|---:|---:|---:|
| bucketStrictWriteRead | 939,525 | 18,016 | 65,536 | 0 |
| io | 218,784 | 3,876 | 0 | 0 |
| bucketStoreFirst | 161,641 | 16,896 | 65,536 | 0 |
| bucketLoadFirst | 158,077 | 16,896 | 65,536 | 0 |
| queue | 39,613 | 0 | 27,392 | 0 |
| metricStrictWriteReadTotal | 22,156 | 38 | 256 | 0 |
| metricStrictWriteReadPeak | 20,291 | 110 | 256 | 0 |
| bucketFirstStore | 18,116 | 32 | 65,536 | 0 |
| onlineStrictWriteRead | 17,970 | 64 | 256 | 0 |
| onlineLoadFirst | 17,950 | 64 | 256 | 0 |
| onlineStoreFirst | 17,949 | 64 | 256 | 0 |
| onlineFirstStore | 17,939 | 64 | 256 | 0 |
| bucketStore | 17,837 | 32 | 65,536 | 0 |
| onlineStore | 13,589 | 64 | 256 | 0 |
| strictOverflowData | 12,208 | 426 | 19,831 | 0 |
| strictOverflowValid | 9,511 | 256 | 190 | 0 |
| strictMem | 7,527 | 98 | 20 | 0 |
| processEvent | 7,277 | 0 | 253 | 0 |
| packageMem | 6,125 | 26 | 10 | 0 |
| metricLoadFirstUpper | 3,951 | 34 | 256 | 0 |
| metricStoreFirstUpper | 3,937 | 34 | 256 | 0 |
| bucketValid | 2,345 | 0 | 2,063 | 0 |
| metricLoadFirstLower | 1,876 | 50 | 256 | 0 |
| metricStoreFirstLower | 1,584 | 34 | 256 | 0 |
| metricStoreTotal | 527 | 32 | 256 | 0 |
| metricLoadFirstPeak | 312 | 48 | 256 | 0 |
| metricFirstStorePeak | 297 | 48 | 256 | 0 |
| metricStoreFirstPeak | 293 | 48 | 256 | 0 |
| metricStorePeak | 283 | 48 | 256 | 0 |
| metricFirstStoreTotal | 106 | 32 | 256 | 0 |
| processValid | 56 | 2 | 1 | 0 |
| processedSafeWatermark | 34 | 4 | 59 | 0 |
| deqPtr | 29 | 0 | 27 | 0 |
| enqPtr | 25 | 0 | 20 | 0 |
| queueCount | 13 | 2 | 9 | 0 |
| running | 1 | 0 | 1 | 0 |
| sessionTag | 1 | 8 | 64 | 0 |
| statsValid | 1 | 0 | 1 | 0 |
| GND | 0 | 0 | 0 | 0 |
| VCC | 0 | 0 | 0 | 0 |
