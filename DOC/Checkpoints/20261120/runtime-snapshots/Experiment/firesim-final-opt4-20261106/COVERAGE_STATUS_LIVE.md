# PARSEC 逐轮真实状态

2026-11-10T16:27:09.101683+00:00

全套 16；Native 三轮完成 15；C4 三轮完成 0；配对 0。Native 至少一轮 15；C4 至少一轮 0。

P=有效原子提交；R=真实活进程；Q=待执行；B=依赖阻塞；F=失败；—=该profile无此test。test与simsmall不计正式轮次。

| 程序 | Native test/small/r1/r2/r3 | Native状态 | C4 test/small/r1/r2/r3 | C4状态 |
| --- | --- | --- | --- | --- |
| blackscholes | Q / Q / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| bodytrack | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| canneal | Q / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| dedup | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| facesim | — / P / P / P / P | COMPLETE | — / Q / Q / Q / Q | PENDING |
| ferret | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| fluidanimate | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| freqmine | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| netdedup | P / P / P / P / P | COMPLETE | B / B / B / B / B | BLOCKED_SOFTWARE |
| netferret | P / F / Q / Q / Q | FAILED_STAGE_OTHER_PROGRAMS_CONTINUE | B / B / B / B / B | BLOCKED_SOFTWARE |
| netstreamcluster | P / P / P / P / P | COMPLETE | B / B / B / B / B | BLOCKED_SOFTWARE |
| raytrace | — / P / P / P / P | COMPLETE | — / Q / Q / Q / Q | PENDING |
| streamcluster | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| swaptions | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| vips | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |
| x264 | P / P / P / P / P | COMPLETE | Q / Q / Q / Q / Q | PENDING |

完整ELF、输入、命令、ROI、正确性、版本及完成证据：[coverage-status-live.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/coverage-status-live.json)。
当前单实例调度器：[coverage-first-state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/coverage-first-state.json)。
