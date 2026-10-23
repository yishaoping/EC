# 尚未解决的证据边界

1. [UNRESOLVED] 本轮不能编译：新共同ELF、SHA256、实际ROI PC、layout gate实际结果尚不存在。所有脚本准备不是编译通过。下一步最小工作是用户手动运行一次共同软件构建并审阅反汇编。
2. [UNRESOLVED] b3和Current对相同AMO.W lane/sign-extension、BFS512、修复timer handler及checker回放的运行结果。若任一版本自测不通过，必须保留失败，不得为了性能比较删自测、改变图或关闭保护机制。
3. [UNRESOLVED] 原checker snapshot的0x7B读取/共享stores与main ROI的实际重叠区间。源码只证明其在checker release后，无“必在hart0 stop后”顺序。没有新仿真，也没有用旧波形为新共同软件填充周期。
4. [STATIC_INFERENCE] 观察者清理不改变AMO/BFS算法、输入或必要timer语义，但删除了观察者的真实RoCC/普通内存流量。不能保证新软件对旧软件全机动态请求/包切分/缓存暖态/stack frame/I-cache轨迹等价。正式比较只能用同一新ELF的两版配对运行。
5. [UNRESOLVED] 完整architectural golden、逐包checker PASS、sequenced result release以及cache/L2/DRAM drain。GHT/session完成、ready标志和tohost均不能代替这些证据。共同软件PASS严格称为AMO+BFS self-check，而不是全套保护/恢复机制PASS。
6. [DIRECT_EVIDENCE]/[UNRESOLVED] GHE所查65/66无decode，66返回默认0；保留该段并不使其成为有效ELU错误证据。应在未来运行中结合已有断言和真实日志确认检错过程，不能靠现有软件轮询声称覆盖全部checker错误。
7. [UNRESOLVED] Current实际simulator/生成模型/宏与源码的对应，尤其STAGE1_EXIT_PORTS，以及两版频率、CLINT/DRAM配置、reset/seed/实际运行命令。未指定某个未验证Current二进制为正式配对对象。
8. [UNRESOLVED] bwrap与工具链、准备脚本和新linker实际执行可用性。未运行构建脚本、启动器的任何模式或compiler版本探测；仅做源码/哈希/语法和纯文本parser检查。
9. [STATIC_INFERENCE] R-Kernel不属于本共同静态HTIF程序的必要运行依赖；历史gitlink对象本身仍缺失，未因此把完整历史依赖链状态改成已闭合。
10. [UNRESOLVED] 没有baseline_cycles/current_cycles/slowdown、冲突关键路径收益或可避免损失的新测量。本轮不修改 `RUN_PROVENANCE=UNRESOLVED`，不从旧报告的机制活动周期推算净开销。

本轮准备完成后停止。后续顺序：共同软件单次构建与静态产物复核 -> 两版身份闭合的短功能smoke -> 通过后才正式配对ROI测量。没有源码证据支持先为遗留统计恢复/移植Baseline硬件。
