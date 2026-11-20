# 2026-11-10 Native 网络失败排查与恢复入口

C4 CAD/冻结硬件/正常FPGA任务/原coverage-first代码均未修改或重启；仅新增独立软件准备作业。执行设备仍限0000:21:00.0。Opt4认证后保留原安全边界最高优先级。

## 已证明的失败链

- Netferret simsmall：`runs/native-netferret-simsmall-r1-20261109T183156Z/`，guest应用返回124；begin存在、end缺失，样本无效。旧guest内300秒watchdog存在；host未触发7200秒上限。旧包装器把失败前两端日志留在guest，退出路径没有回传，因此现存证据不能区分计算过慢、协议等待或死锁。
- Netstreamcluster test：`runs/native-netstreamcluster-test-r1-20261109T193806Z/`，完整ROI 151,860,037周期、faults=0，但两端退出/输出校验未完成且应用返回124，故仍为无效功能样本，不能计正式。旧包装器test watchdog为guest25秒，同样缺失败端日志。
- 直接源码证据：原Netstreamcluster create_receive_threads把线程ID仅存在局部数组；streamCluster返回前没有join，receiver仍可能执行ACK/close/统计或引用栈queue。这个生命周期缺口已确认，是否导致上述FPGA故障仍待验证。

## 独立软件候选

`software/network-native-wait-diagnosis.json`绑定所有源码补丁、诊断及真实hooks ELF、rootfs、QEMU命令、日志哈希和每case原子结果。Netstreamcluster候选只保存并join原接收线程，保留全部原计算和外层ROI hook位置；join位于原ROI内部，不缩短计算/测量区间。必须用同一版本作比较。

新run-network仅增加失败时的两端日志、线程stat/wchan/syscall、输出hash和watchdog原因回传；保留现有超时，不屏蔽失败或checker。Netferret被测ELF保持不变。

QEMU使用独立guest，最多两台2GiB、nice15，复用既有诊断内核。诊断hooks仅验证原应用计算和协议，不提供真实FPGA周期或checker结论。baseline与join候选的test还用icount shift5验证时间调度敏感性；baseline也通过，故尚未在QEMU复现原FPGA故障。

## 长任务与检查点

- `ec-parsec-network-native-wait-diagnosis.service`：软件测试。状态`software/network-native-wait-diagnosis.json`，日志`jobs/network-native-wait-diagnosis/console.log`，每case保存独立result.json；保留原失败和旧ELF。
- `ec-parsec-network-native-wait-profile.service`：只等所有要求的离线正确性门通过后生成新软件payload，核对内核除initramfs外配置完全相等、ec_dac_roi.o相等，并复用原safe-FDT地址。状态`software/network-native-wait-profile.json`，日志`jobs/network-native-wait-profile/console.log`。
- 准备服务只将Netstreamcluster未来计划条目绑定到独立`netstreamcluster-receivers-joined-v2`，旧计划归档；原coverage-first动态读取并唯一执行test→simsmall→正式缺项。新签名不能复用旧profile完成标记。任何test/small失败仍跳过该版本，不放宽校验。
- Netferret的`netferret-failure-evidence-v2`准备好后先不绑定，避免抢在Netstreamcluster短验证之前。后续应在21安全边界用它取回真实FPGA等待原因，再决定是否需要软件或超时预算修复。不能仅根据QEMU成功声称原FPGA失败已修复。
- 重连先核实jobs状态中的boot_id/PID/start_ticks；活服务只接管监控；退出后才从原子case结果恢复。新服务不访问FPGA或执行部署，也不修改CAD。

C4三项网络程序仍存在完整原ROI的thread/syscall/context协议阻碍；此Native修复不使C4网络自动合格。13项普通C4仍由既有认证→21安全边界→smoke/test/simsmall→覆盖优先正式队列接管。

## 14:32 CST 真实 FPGA 失败证据及继续执行

Native 正式仍为42/48；14个程序三轮齐备。Opt4仍为0/48，无有效配对。

- joined-v2 的真实 FPGA test `runs/native-netstreamcluster-test-r1-20261110T044235Z/` 已失败结束，没有complete标记：客户端发送40字节并收到应用ACK，输出SHA256精确为`df19d532b26216389f8f6f12139376aa48e81a12ffad0fb25b3685d92ef2e804`。主线程37在futex join等待线程50，线程50仍在clock_nanosleep；无ROI end，guest原25秒watchdog令应用返回124。输出正确不等于有效样本。UART及result原件保留。
- 已证明即时阻塞为接收线程未退出；上游原因尚未证明。源码`uptcpip/freebsd.kern/uipc_syscalls.c:bsd_syscall_shutdown`在`snd_una < snd_max`时反复usleep，客户端原实现收到应用ACK后调用close并退出、销毁用户态TCP线程，存在未完成协议收尾的竞争假设。不能用客户端已收到应用ACK推定服务端TCP累计ACK已处理，也没有通过跳过close/排空来处理。
- Netferret失败回传profile的server/client ELF、input和原ROI不变；14:22在未来条目锁下绑定`netferret-failure-evidence-v2`，旧计划及收据分别在`../plan-history/before-netferret-failure-evidence-20261110T062232Z.json`与`netferret-failure-evidence-admission.json`。原coverage-first于14:26实际启动`runs/native-netferret-test-r1-20261110T062604Z/`，PID1852282，start_ticks10368474，当前boot_id与日志匹配。未启动第二套FPGA执行器；结果以原子result/complete为准。
- 新独立软件作业`ec-parsec-netstreamcluster-graceful-close.service`于14:30启动，服务PID1907600，软件worker1907602，start_ticks10395508。只在新客户端副本中增加等待服务端EOF，保留原joined-v2服务端ELF、原全部输入/计算、外层ROI、ACK等待和超时标准。EOF异常或额外数据直接判失败。候选修复的效果与因果解释均需实测；QEMU不是FPGA/checker通过。
- 状态`netstreamcluster-graceful-close.json`绑定补丁/新client ELF哈希、原server ELF、test(icount5)/simsmall/simmedium三项QEMU结果。最多2台2GiB QEMU、nice15。全部离线门槛通过后才增量构建Native软件payload，核对除initramfs外内核配置和ROI driver对象相等，保留safe-FDT地址。只更新未运行的Netstreamcluster未来profile；21实际运行与C4优先级仍由原coverage-first管理。任何失败都保留，不能计正式。

## C4 导出观察

14:32快照`../observations/cad-network-20261110T063213Z/snapshot.json`：DUT综合成功，DCP 3,339,470,089字节已写出；VHDL 3,518,722,048字节，自12:45:01 CST以来107分钟未写出，尾部截断在port映射行，尚无.vivado.end.rst。Vivado11088及热线程11091仍消耗CPU，RSS31.41GiB，但I/O计数自14:22观察未变化；不能确认导出在前进，也没有据此认定死锁。顶层synth_1尚无begin标记，impl_1和最终firesim.bit不存在。未重启/修改CAD、冻结源码或Tcl。原DUT完成标记→顶层综合→实现/时序门槛→bitstream→源码/输入哈希认证→21安全边界首验链仍在。

## 14:37 CST Netferret 新功能结果

`native-netferret-test-r1-20261110T062604Z`现已有效通过，`result.json`的valid=true、formal=false、issues=[]、timedout=false；complete中的result SHA和identity均已核对一致。真实ROI 4,962,410,208 cycles，Host 498.852782958秒；两端零退出、输出精确匹配、完整ROI且faults=0。原调度器14:34自动启动simsmall `native-netferret-simsmall-r1-20261110T063425Z`，PID1930051/start_ticks10418594，14:37 heartbeat继续增长；未因test通过将formal补记。核验收据见`../observations/cad-network-20261110T063213Z/netferret-test-verified.json`。Native正式42/48、Opt4正式0/48不变。

## 14:39—14:41 CST 离线候选与 C4 后续观察

Netstreamcluster graceful-close-v3 的test(icount5)、simsmall、simmedium三项QEMU均已通过：两端零退出、精确输出、完整原诊断ROI及真实服务端EOF全部满足；Host耗时分别3.024、31.570、550.069秒，仅用于软件验证，绝非体系结构性能或FPGA/checker通过。持久服务进入BUILDING_NATIVE_PAYLOAD，完成后按原门槛接入唯一coverage-first。独立补充绑定`netstreamcluster-graceful-close-bindings-20261110T063034Z.json`记录QEMU、诊断内核、双方ELF、脚本及补丁SHA256；未改任何活任务输入。

14:41后续快照`../observations/cad-network-20261110T063213Z/cad-followup-20261110T064114Z.json`显示Vivado CPU由104347.37增至104887.55秒，RSS31.41GiB；VHDL仍3,518,722,048字节，距最后写出116.21分钟，全部I/O计数与14:32相同。DUT end标记、顶层begin标记、impl目录和最终bitstream仍缺失。可确认仍在计算，不能确认导出收敛进展；内核日志08:00以来未匹配Vivado OOM/segfault。保持原CAD进程，未中断或重启。

## 14:55 CST 更新

Netstreamcluster graceful-close-v3于14:40完成镜像构建及原子入队，状态为`OFFLINE_PASSED_NATIVE_PROFILE_ADMITTED`，原计划SHA变为`5b3d64ca9b5d39be5bc12f89c57dd535c8a44f363a23dcef6e99457cd7699587`。Netferret simsmall仍实际运行，heartbeat持续增长；Native正式42/48未增加，Opt4正式0/48。

本轮对Vivado热线程做了19Hz、20秒非停止式采样，379个样本/丢样0，热点明确为VHDL IO网名大小写比较、线性查找与字符串复制。VHDL距最后写出130.68分钟；没有CPU配额、换页或I/O压力证据。当前不能证明导出收敛，也没有找到能安全加速活导出的措施。没有修改/重启活项目或另启CAD。完整报告和原始采样见 [C4导出热点诊断](../observations/c4-export-20261110T065207Z/REPORT.md)。
