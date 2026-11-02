# Episode级top20与证据可用性

**真实preservation/outer-A lock episode列表不可恢复（null，不是0笔）。** 成功B没有保存capture/Put first,last/ACK或beatsLeft状态；因而不能输出20笔“preservation episode”并填假边界。

以下20笔按**已测lastC→firstbank**排序，只是ReleaseData代理，bank均为L2 bank0。release image seq/generation属于incoming新image；preservation保存的是被覆盖resident旧image，不能将二者等同。

| Rank | Last C cycle | First bank write | Duration | Release owner/seq/gen | Line / set | Raw TSV lastC / firstbank row |
|---|---:|---:|---:|---|---|---|
| 1 | 2344648 | 2344724 | 76 | SVB/315/106942 | 0x80087fc0 / 511 | 107440 / 107442 |
| 2 | 2183969 | 2184044 | 75 | normal/270/97642 | 0x80009040 / 577 | 104883 / 104885 |
| 3 | 2279131 | 2279204 | 73 | normal/294/101866 | 0x80009f40 / 637 | 106343 / 106344 |
| 4 | 1280732 | 1280804 | 72 | normal/112/61874 | 0x80019000 / 576 | 73712 / 73713 |
| 5 | 1535014 | 1535084 | 70 | normal/29/49872 | 0x80016580 / 406 | 81164 / 81169 |
| 6 | 1038935 | 1039004 | 69 | normal/93/55790 | 0x80087e40 / 505 | 68112 / 68113 |
| 7 | 2043575 | 2043644 | 69 | normal/244/94426 | 0x80009100 / 580 | 100759 / 100760 |
| 8 | 750336 | 750404 | 68 | normal/15/48562 | 0x80016180 / 390 | 53240 / 53241 |
| 9 | 2187096 | 2187164 | 68 | normal/271/98026 | 0x80007f80 / 510 | 105035 / 105037 |
| 10 | 895417 | 895484 | 67 | normal/55/52213 | 0x80087e40 / 505 | 60949 / 60954 |
| 11 | 1463258 | 1463324 | 66 | normal/121/67955 | 0x80008f80 / 574 | 77815 / 77817 |
| 12 | 1155939 | 1156004 | 65 | normal/107/58737 | 0x800383c0 / 527 | 71450 / 71451 |
| 13 | 1461700 | 1461764 | 64 | SVB/121/67986 | 0x80008fc0 / 575 | 77730 / 77732 |
| 14 | 1574020 | 1574084 | 64 | SVB/141/74846 | 0x80008fc0 / 575 | 83174 / 83187 |
| 15 | 1023345 | 1023404 | 59 | normal/87/55241 | 0x80087f00 / 508 | 67333 / 67335 |
| 16 | 1474185 | 1474244 | 59 | normal/123/68903 | 0x80011f80 / 126 | 78574 / 78578 |
| 17 | 1538146 | 1538204 | 58 | SVB/134/72777 | 0x800090c0 / 579 | 81491 / 81493 |
| 18 | 1418027 | 1418084 | 57 | normal/117/65201 | 0x80039d00 / 628 | 76235 / 76236 |
| 19 | 1491347 | 1491404 | 57 | normal/126/70018 | 0x80009f40 / 637 | 78796 / 78797 |
| 20 | 1700387 | 1700444 | 57 | normal/163/82116 | 0x80007f80 / 510 | 88658 / 88660 |

`top20_release_proxies.json`给每笔全部要求字段。preservation txn/source/old-image、drain-ready、arb-selected、bank-grant、outer-A lock duration、blocked请求/unique misses/retries、ROB overlap、eventual critical load都显式null；start/end定义为release prebank，不暗示preservation边界。源SC20/38/21 raw行可逐笔核对，20笔均没有被标成critical。

完整B6,735笔release仍全部source6闭合；本轮复用前轮重建并重新hash/identity校验，没有重写旧报告。prebank phase union=sum=67,366，source6阶段不重叠；多个资源episode可能重叠，不可由此推广。

证据盘点：保存stdout/stderr/TSV中的L2_PRESERVE_PENDING/REQ/ACK、STAGE3_DRAIN记录数都为0；compact捕获丢弃一般diagnostic 148,429行，成功ring未dump且file=null。counter存在于RTL不代表成功日志有值；SC32–37是L1/SVB完整性链，SC38是actual bank write，均不是checkpoint状态。无保存FST可读；这不是请求重跑观察的理由。

在optional完整prefix内可恢复的水位仅能比较incoming key。分类见numeric_audit：即使incoming seq已safe，旧resident是否safe、dirty、outerPreserved仍未知；所以该关联不能证明checkpoint或安全水位gate主导。
