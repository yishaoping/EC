只读检查：2026-11-09T03:24:06.313830+00:00

Native 首轮覆盖 9/16，三轮齐备 8/16；Opt4 首轮 0/16；有效配对 0/16。

Freqmine 三轮均通过：结果、完成标记、身份、证据哈希和日志重新核验通过。ROI instructions 未采集。

| 指标 | r1 | r2 | r3 |
| --- | --- | --- | --- |
| ROI cycles | 89,280,523,270 | 89,411,029,335 | 89,380,362,214 |
| Host wall 秒 | 5549.358126 | 5557.670074 | 5557.331869 |
| 输出/退出 | 三轮均通过，exit=0 | 三轮均通过，exit=0 | 三轮均通过，exit=0 |

ROI 平均 89,357,304,939.667，样本标准差 68,239,919.953，CV=0.076367%。

Facesim r1 已正式通过：ROI=23,266,064,819，host=2666.348823s；SHA/完成标记/重新验证结果均通过；faults=0，未超时。

当前 active 指向 native-ferret-simsmall-r1-20261109T032131Z，PID=230494，start_ticks=621183，身份活性=True，板卡=0000:21:00.0。

Coverage-first、Native、CAD、C4-first、C4-suite 服务均 active/running；Facesim 后已实际启动 Ferret test，证明自动接续工作。后续新任务仅允许21，e2历史结果仅用于核验。

CAD worker=11088；最近两条五分钟观测 CPU 增加 299.89s，仍为 wrapper synth_design，最终bitstream未产生。阶段日志自01:41:22 UTC静默，不能据此声称已完成综合或进入布局布线。

P=有效通过，R=实际运行，Q=计划待执行而非已运行，B=阻塞，—=profile未定义。Opt4的H表示等待最终认证bitstream及首验；网络程序另有软件阻塞。

| Benchmark | Native test/small/r1/r2/r3 | Opt4 test/small/r1/r2/r3 |
| --- | --- | --- |
| blackscholes | Q/Q/P/P/P | H/H/H/H/H |
| bodytrack | P/P/P/P/P | H/H/H/H/H |
| canneal | Q/P/P/P/P | H/H/H/H/H |
| dedup | P/P/P/P/P | H/H/H/H/H |
| facesim | —/P/P/Q/Q | —/H/H/H/H |
| ferret | P/R/Q/Q/Q | H/H/H/H/H |
| fluidanimate | P/P/P/P/P | H/H/H/H/H |
| freqmine | P/P/P/P/P | H/H/H/H/H |
| netdedup | B/B/B/B/B | B/B/B/B/B |
| netferret | B/B/B/B/B | B/B/B/B/B |
| netstreamcluster | B/B/B/B/B | B/B/B/B/B |
| raytrace | —/Q/Q/Q/Q | —/H/H/H/H |
| streamcluster | P/P/P/P/P | H/H/H/H/H |
| swaptions | P/P/P/P/P | H/H/H/H/H |
| vips | Q/Q/Q/Q/Q | H/H/H/H/H |
| x264 | Q/Q/Q/Q/Q | H/H/H/H/H |

三个网络程序当前没有离线修复worker推进：重连后的验证服务因候选receipt版本绑定不一致退出，原证据保留。本轮未修改或重启。

Netdedup framed候选已在QEMU Linux test/simsmall/simmedium协议及精确输出通过；Netferret protocol候选Linux test断言/超时、small/medium输出不匹配；Netstreamcluster旧绑定Linux三种输入输出精确通过。三者均尚无冻结Opt4真实checker兼容的完整原ROI运行证据，不能加入正式有效样本。

没有需要用户立即操作板卡/权限/空间的阻塞；网络软件需要后续处理，未阻塞其余13项。

完整身份、ELF/输入/软硬件哈希、证据路径及逐轮状态见 /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-checks/readonly-20261109T032406Z/report.json。
