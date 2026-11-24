# L1 slot epoch边界分配与安装规则不一致

生产DCache nextSlotEpoch在0xffff时跳过0，分配下一owner为1；installOwnerMatch、
install.fire assertion和refillReqOwnerMatch仍比较普通16bit +1，得到0。
因此匹配reservation无法安装，触发MSHR install_fault断言。

证据singlecore_function_closure_20261123/slot_epoch_seeded_before/：只把实际
生成RTL中set64两空槽的reset初值改为0xffff以加速达到有限标签边界，
不修改协议准入/结果逻辑。bench先检查两真实空槽=0xffff，再发真实LOAD，
L1/L2取得Grant并分配epoch1，cycle0x154进入install，345触发
refill destination owner mismatch。run.exit1、输入与修改前生成物哈希保存。

首次直接C++写内部root字段没有触发Verilator对所有优化内部状态的重算，
错误地使用正常0→1路径，其PASS不是边界覆盖，保留记录明确排除。首次
独立重链接缺cache_opportunity.o的失败是夹具链接问题，不是硬件反例。

最小修复：三处统一调用已有nextSlotEpoch，不改变标签宽度、队列、owner或
分配策略。候选dcache.scala独立Scala编译/真实Hierarchy生成中。生产来源
冻结的四配置Core运行另行回收；P4-06从CODE_READY回IN_PROGRESS，原标签
allocator小宽度测试不能替代缓存reservation完整终态。

候选dcache.scala已在独立classpath实际Scala编译exit0，完整Hierarchy真实
Chisel/FIRRTL生成exit0。长期finite_identity/run.py正在对该生成物执行
相同空槽边界加速、四条同组冷LOAD和MSHR安装终态。候选只替换三处普通
加一为既有nextSlotEpoch，生产原始分配、owner宽度、token和响应路径均不变。

修后长期finite_identity边界runner实际exit0：四同组冷LOAD/替换，每次等
完整安装终态并再次读。随后原整套Hierarchy benchmark重新编译并链接同一
候选模型（相同空槽边界seed）全部通过。覆盖AMO/byte mask/相邻字、
Pending7、满C、旧外写ACK、FAIL8→FAIL7和EVT维护，见slot_epoch_candidate_result。
候选没有新增寄存器或状态，生产合入及后续生成尚未执行，任务继续未关闭。
