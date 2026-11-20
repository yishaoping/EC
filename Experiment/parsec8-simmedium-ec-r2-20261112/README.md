# 八项 PARSEC：仅 simmedium EC 首轮

本队列只运行完整冻结 EC 的正式 Linux simmedium，每项一次；禁止 Native、test、simsmall、缩小输入及组件 ROI。

八项历史 Native FPGA simmedium 各三轮已复核，原样复用。八项正式应用 ELF、输入、rootfs、线程、内存模型、频率和 Linux 内存上限的历史契约核对全部通过。CPU Golden Gate EC 与历史 FPGA Native 的跨运行后端可比性仍须独立准入；在此前不输出混合比值。

当前完整 EC 尚无认证 FPGA bitstream；这里运行的是完整 frozen `8491167d` Golden Gate **CPU 周期精确仿真**，不是 FPGA 性能。SVB-only 不进入此队列。

- 服务：`ec-parsec8-simmedium-ec-r2-20261112.service`（user systemd）
- [实时队列](campaign-state.json)
- [八项状态 CSV](coverage.csv)
- [固定输入及 SHA](inputs.json)
- [前次日志管道启动故障及修复](host-plumbing-repair.json)

当前任务：Blackscholes / Fluidanimate 在 CPU201 / CPU200 加载 EC Linux，完成 guest-ready 后仅发送本项 `simmedium 1` 命令。其余依序为 Bodytrack、Freqmine、Swaptions、Ferret、Dedup、Streamcluster。所有既有健康 CAD 保持不动，共用原 CPU 资源锁，禁止抢占独立会话。

故障或超时保存完整证据后跳下一项，不自动重复应用。日志完整 gzip，逐流绑定未压缩字节数和 SHA；UART 原文保留。只有输出校验、真实正 checker accounting、排空及完整事件审计都通过，才准入 EC ROI target cycles。Host wall-clock 与 target cycles 分开记录。

性能入口从本目录开始；此前 `parsec8-performance-audit-r2-20261112` 的缩小/阶段 ROI 图属于历史研究数据，明确排除本次 simmedium Performance。

首次接入日志 FIFO 与 observer fopen(wx) 冲突，六个模型均在首个 eval 前 rc90 退出，没有 guest/heartbeat，也没有执行应用。这批为工具启动失败，仅保留证据；当前 r2 保持原 observer 独占新建普通日志，不改模型/应用/输入。
