# CSR replay bank regression

`run.py`独立编译实际CSRFile及夹具，使用既有Chipyard runtime classpath，不修改生产源码。当前生产实现只把普通Checker显式MSCRATCH/SSCRATCH写同时镜像至既有比较影子；原物理寄存器写和普通模式读视图保留，priv检查仍使用影子，管理软件写不污染包影子。测试先收到CPS旧栈mscratch，在normal模式执行写0，再经priv视图和真实ECP比较核验，另检查管理隔离、priv写、两种scratch及普通模式真实MPRV置位/清零。

参数：`--out`为新的AI/TMP目录，`--classpath-file`是已生成的runtime/fullClasspathAsJars export，`--scala-compiler-classpath`为匹配的compiler/library/reflect三个jar的冒号列表，`--chisel-plugin`为同版本Chisel插件。独立候选可传`--source`，所有jar/源/测试和各阶段退出码留存。输入必须全为jar，以避免目录中的未记录变化。

原RTL的真实反例是normal写未更新影子；中断完整程序在Seq23首次CSR比较也以同一mscratch差异FAIL。曾把全部represented CSR切到normal影子的宽候选在原Sv39整核触发watchdog，已否决，其两个完整IRQ程序PASS不作为最小生产实现的整核证据。当前长期入口的生产CSRFile动态实际PASS在`AI/TMP/singlecore_function_closure_20261123/csr_scratch_longterm_production/`；组件PASS不替代真实中断、Main/Checker快照和恢复整核验收。

进一步命令审查已证明仅镜像普通`wdata`仍不能覆盖CSRRS/CSRRC：该值按物理管理bank计算，而shadow应以本包CPS为旧值。`scratch_rmw_before_retry/`是真实反例；`scratch_rmw_all_commands/`独立候选的12组合和SSCRATCH真实ECP已PASS，候选尚未生产合入。长期夹具现在接受实际3bit命令（W=5、S=6、C=7），覆盖两scratch、normal/priv与management隔离。旧`csr_scratch_longterm_production/`PASS只代表其保存的旧CSRW测试输入，不升级成新增命令通过。

当前更新：上述CPS-based scratch RMW候选已精确合入生产，`scratch_rmw_longterm_production/`对当前生产源码实际动态全PASS；当前生产来源的完整normal/Fault8/Fault18组合Core及IRQ/Sv39/设备严格回归也已通过，证据见`final_integrated_closure/`。
