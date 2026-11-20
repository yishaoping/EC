# C4 VHDL 导出热点诊断，2026-11-10 14:55 CST

C4仍在执行VHDL导出器内部运算，但尚未证实导出前进或有限收敛。Native正式42/48，没有新增正式样本；Opt4正式0/48、有效配对0/16。未停止、重启或修改现有CAD/FPGA/调度服务，未执行板卡或驱动操作。所有后续执行仍限0000:21:00.0。

## 直接证据

- Vivado PID11088/start_ticks10629、线程11091，boot_id `d6c6e410-10ad-4326-86ba-79b657eabd96`与既有状态相符。
- `design_1_firesim_wrapper_0_0_sim_netlist.vhdl`为3,518,722,048字节，最后写出12:45:01 CST。14:55距最后写出130.68分钟，文件尾截断，FD19写位置等于文件大小。I/O计数与14:22、14:32、14:41快照一致。
- CPU累计105456.69秒（14:50初检），热线程运行，其他线程主要等待futex/select。日志仍停在08:24的write_verilog结束；没有DUT结束标记、顶层综合begin、impl_1或最终firesim.bit。
- 已存在的DCP 3,339,470,089字节属于当前DUT的IP缓存生成步骤；不能把它当成最终bitstream或伪造run完成。当前Tcl位于IP cache的`write_vhdl -mode funcsim`。随后还须完成DUT其余导出、顶层综合、实现/时序门槛、bitstream和原始认证。

## 20秒非停止式采样

原命令：`perf record -e cpu-clock:u -F 19 -t 11091 --call-graph dwarf,8192 -o perf.data -- /bin/sleep 20`。仅对既有目标线程采样，没有ptrace attach、信号、Tcl注入或工具参数改变；379个样本，丢样0，3.107MB。

可识别调用链：`HANWVhdlWrite::writeCell → HANWVhdlIoAnalyzer::analyze → std::__find_if<...HANWNetSpan...EqualCI> → HANWNetSpan::equivalentCI → getName / memmove / strcasecmp`。

| CPU热点 | 样本占比 |
| --- | ---: |
| memmove | 38.52% |
| HANWNetSpan::equivalentCI | 10.03% |
| strcasecmp | 9.50% |
| new[] | 9.23% |
| memcmp | 8.97% |
| delete[] | 8.18% |

**已证明**：线程在网名/端口名的复制、大小写不敏感比较及线性查找中运算；不是单纯futex死锁或阻塞写盘。
**有依据的解释**：反复对网名vector扫描并构造长字符串可能导致很高的计算复杂度；实际算法阶数和当前单元迭代进度没有被证明。
**未证明**：当前单元一定能结束、是否存在工具内部病态循环、具体剩余时间。CPU热点不能替代导出完成标记。

`perf-report.txt`含离线addr2line的DWARF解析警告；这是分析工具读调试信息的警告，不是Vivado运行错误。符号调用链与原始perf.data均保存，未据此声称源码行号完整可靠。

## 资源与加速判断

- RSS31.41GiB，MemAvailable约394.8GiB；CAD卷余约300.9GiB、data1余约441.6GiB。进程虽有旧换出页，vmstat观测si/so均0，不能将累计VmSwap当作当前换页瓶颈。
- cgroup CPU quota=-1，nr_throttled=0，允许CPU0–255。热线程累计调度等待约0.075%，单核已经基本得到运行时间；提高nice优先级的可见收益上限很小。
- I/O pressure avg10/60/300为0，Writeback=0；没有磁盘等待证据。08:00以来内核日志未匹配Vivado OOM/segfault。
- **未找到可安全加速当前活导出的措施**：更多jobs、放宽线程数、迁盘或增加内存不能解决已采样的串行名称分析。未修改这些配置，也未改变当前CAD认证输入。
- 跳过可选funcsim导出不能靠修改已执行到的Tcl或伪造end标记。若以后确需检查点恢复，应在独立副本验证该缓存DCP的命名和顶层绑定、保留原作业证据并重新建立CAD输入认证；本轮未启动第二个CAD或修改活项目。

## 自动实验衔接

- Netferret新test有效通过：4,962,410,208 ROI cycles，Host498.852782958秒；原队列正在执行simsmall `native-netferret-simsmall-r1-20261110T063425Z`，PID1930051/start_ticks10418594。14:55 heartbeat已增加至1,005,175,117,138 target tick；只是存活进展，不代表功能通过。
- Netstreamcluster graceful-close-v3已完成全部三项QEMU、Native镜像及内核/ROI对象一致性核验，06:40 UTC原子更新未来profile。原队列动态读取，Netferret安全结束后即可运行该候选test；当前样本输入未改变。
- 只读调用原`coverage_first.catalog/results/next_jobs`确认缺项队列包含Netferret simsmall和Netstreamcluster test；验证成功后正式r1→缺失r2/r3，失败版本跳过。不存在启动第二套执行器的需要。
- C4-first仍`WAITING_FOR_EXACT_C4_BITSTREAM`，目标21，deployment_count=0；13项普通C4软件READY不代表FPGA通过。认证后原链路在21安全边界优先首验，再覆盖13项r1并补重复。

细节与原始时间点见`diagnosis.json`、`scope.json`、`perf.data`、`perf-record.log`、`perf-report.txt`及`perf-symbols-compact.json`。
