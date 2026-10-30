# Opt4 高频观测耗尽预算并中断workload

状态：修复/Scala及离线验证通过；新版本展开及runtime unresolved。

Failure：用户run `optimization_4_svb_20261029_020351_481d089a` generation/build PASS，
simulation exit-9、SAFE_CHAIN_EVENT_BUDGET_EXCEEDED，无结束footer/checksum/ROI/cache summary。
旧前缀50,331,374bytes/164,352行；kind14/15共123,703行，约75.27%。
此前Mux first-bad未再现；本次first-bad是host Router预算检查抛异常。

根因链（已证实）：逐语义写/逐阻塞周期force→高频固定宽度SC记录→共享48MiB预算耗尽
→capture结束simulator→最终证据缺失，旧manifest保留STARTED。
协议前缀平衡不证明数据正确；本轮未定位新的hardware/data failure。

修复：source精确累计+每4096事件样例，kind14/15 producer限1024；
Opt4显式plusarg下observer超限不fatal，以SC_LIMIT/SC_LOG_STATS标记省略；
host分离协议39MiB/样例8MiB/summary1MiB，输出预算不kill workload。
可选样例丢失可继续验证；必需记录丢失、footer/producer不守恒、counter缺失、
failure marker或workload未完成/exit非0时拒绝PASS/性能发布。
I/O异常/中断更新ABORTED。工具/源码身份变化禁止resume复用。

计数窗口：traffic_enable期间，STOP边沿前值，不默认等同软件ROI。
除BOOM observation段和shared input-only logger外，其余8硬件文件相对preimage不变。

验证：BOOM Scala compile、shared SV lint-only、57offline tests通过；
旧前缀回放22,222条必需记录hash相同，输出缩到15,152,548bytes；缺footer仍判不完整。
补丁往返/隔离index/静态launcher/source-scope有独立报告。
未执行新elaboration/FIRRTL/RTL generation、Verilator build、hardware simulation/benchmark。
新的备份正确性与slowdown unresolved。

经验：诊断限额不能成为被观察系统的强制退出条件；样例预算与必需证据隔离，
精确counter独立于采样；丢失证据必须反映在validation门禁里，不能静默过滤后PASS。

报告：[observation budget fix](../../TMP/opt4_observation_budget_fix_20261029_0802a3c4/README.md)。
