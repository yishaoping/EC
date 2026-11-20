快照 2026-11-09T05:07:40.411611+00:00；发布来源 2026-11-09T05:03:50.468498+00:00。正式轮次不含 test/simsmall。Native/C4 样本数 {'Native': 26, 'C4': 0}。

|程序|Native test|small|正式 r1 / r2 / r3|Opt4 test / small / r1 / r2 / r3|阻碍/下一步|
|---|---|---|---|---|---|
|blackscholes|待执行|待执行|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|bodytrack|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|canneal|待执行|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|dedup|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|facesim|未定义|通过|通过 / 待执行 / 待执行|未定义 / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|ferret|通过|失败|待执行 / 待执行 / 待执行|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|Native simsmall 输出 SHA 不符；其他项继续|
|fluidanimate|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|freqmine|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|netdedup|软件阻塞|软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞|独立软件候选；原 ROI checker/context 协议尚未支持，未正式入队|
|netferret|软件阻塞|软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞|独立软件候选；原 ROI checker/context 协议尚未支持，未正式入队|
|netstreamcluster|软件阻塞|软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞|软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞 / 软件阻塞|独立软件候选；原 ROI checker/context 协议尚未支持，未正式入队|
|raytrace|未定义|通过|通过 / 待执行 / 待执行|未定义 / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|streamcluster|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|swaptions|通过|通过|通过 / 通过 / 通过|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|
|vips|失败|待执行|待执行 / 待执行 / 待执行|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|Native test Kernel stack overflow；其他项继续|
|x264|通过|通过|运行中 / 待执行 / 待执行|等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream / 等待bitstream|等待认证最终 bitstream 和 C4 首验|

待执行只表示未来任务；失败功能门之后的正式轮次不会越过功能门。Blackscholes/Canneal 的当前 profile 小输入缺项不以其他历史 profile 冒记通过。
完整逐样本目标周期、宿主时间、有效性、身份与原始证据见 accepted-formal-samples.json / .csv；原样本未修改。