# 共用 benchmark 准备结果

**`COMMON_BENCHMARK_READY_TO_BUILD`**。共用源码和未来软件构建脚本已准备，未编译、未生成硬件、未运行仿真/workload。此分类不是runtime PASS或smoke就绪认证。`RUN_PROVENANCE=UNRESOLVED`。

## 本轮实际产物

- `/data1/gzh/EC/baseline/software_common/`：独立共同软件；原AMO/BFS、timer64修复与必要checker协议保留，移除遗留读回/报告依赖。
- `/data1/gzh/EC/baseline/build_common_benchmark.sh`、`prepare_common_build.py`：未来只构建一次共同ELF/loadmem；尚未执行。
- `/data1/gzh/EC/baseline/common_benchmark_contract.py`：同一ROI/结果/失败文本契约。
- 更新baseline已有shell/Python启动器：明确schema2软件身份和ROI，退出总cycles降为辅助；没有运行启动器。
- 本目录的 `common_benchmark_plan.md`、`abi_classification.md`、`roi_and_completion_contract.md`、`manual_build_and_run.md`、`unresolved_evidence.md`、`evidence_index.md` 和机器可读保全/哈希证据。

## 对任务十个问题的明确回答

1. [DIRECT_EVIDENCE] 历史测试指标主要是0x7B流量/valid/统计drain、0x55指令计数报告、未实现interval0x79，以及相关snapshot/timeout/旧详细report。0x76只部分清理，保留共享初始化和main ROI外observer控制，不把它误认成checking STOP。
2. [STATIC_INFERENCE] 0x7B可从新的共同performance profile移除；本轮已移除。理由是其结果只供旧报告，**不是“所有调用都在主ROI外”**。checker读写可能重叠主ROI，所以新旧profile的cycle数不能直接比较。
3. [DIRECT_EVIDENCE] 同类可移除项包括0x55和0x79；mask7D/7E、上下文记录75/73/72/64、copy/replay/status/release不属于可顺手删除的统计。
4. [DIRECT_EVIDENCE] 保留算法/输入/AMO、timer/interrupt/CLINT、harts、GHT配置、monitor/checking START/STOP、RSU/JLR/release和必要HTIF。两次rdcycle是共同测量必需接口。
5. [STATIC_INFERENCE] 目前不需要修改Baseline硬件。b3没有7B；移植后来的统计并非恢复其原貌，也无助于统一已可用的软件ROI。
6. [UNRESOLVED] 未发现真正workload-required ABI必须通过新硬件兼容解决的证据。未来若任一版本计算失败，需单独定位，不得通过删AMO、改图或关barrier强行通过。
7. [STATIC_INFERENCE] 方案支持同一次生成的ELF/loadmem给两版使用；当前还没有新二进制。真正同哈希与可执行性必须在未来构建和smoke中确认。
8. [DIRECT_EVIDENCE] ROI为hart0 start rdcycle之后AMO+BFS，保留STOP/26NOP循环/GHT session等待，再stop rdcycle；主指标严格stop-start。旧PC只是参考，新PC从最终符号/反汇编记录。
9. [DIRECT_EVIDENCE]/[UNRESOLVED] 共同验收采用AMO+BFS result self-check、两版一致的结果/parent_checksum、四checker软件ready、无ERROR/FAIL及正常HTIF退出；不把这些升级为逐包/缓存drain/全部检错机制验证。65/66有效诊断和完整硬件correctness另列缺口。
10. [STATIC_INFERENCE] 下一步先由用户手动构建共同软件并审阅产物；不应先恢复legacy统计硬件。此后才分阶段安排两版匹配身份的功能smoke和成对性能运行。本轮不继续构建或仿真。

## 重要限制

[DIRECT_EVIDENCE] AMO/timer/BFS源文件字节保留；linker和后处理固定关键可变数据地址及heap/stack。删除观察者流量会改变旧软件全机动态trace，不能宣称没有观察者效应。本轮不保证尚未生成的ELF布局已通过门禁。

[UNRESOLVED] 没有新ROI cycles、net slowdown、可信运行provenance或完整drain证据。详情和未来命令见 `manual_build_and_run.md`。共同软件不依赖缺失R-Kernel。
