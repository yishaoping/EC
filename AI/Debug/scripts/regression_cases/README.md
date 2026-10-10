# 历史定向回归源码

这些是手写测试/生成入口，不含模型、对象文件、二进制或生成 RTL。

| 资料 | 输入/依赖 | 输出与历史验证边界 |
|---|---|---|
| 528000/EC528000Generate.scala | 当前 rocketchip sbt/chisel，输出目录参数 | R_IC/R_ICSL/GHM RTL；原验证通过，接口变化后需重新生成 |
| 528000/{ric,icsl,ghm}-sim/main.cpp + *_init.h | 该轮生成的 V 模型、Verilator/C++，header 相对路径保留 | 历史 directed run logs 有 PASS，不是整机证明 |
| 1769000/ibuf_test.cpp, bjl_test.cpp | VIBuf/VR_BJLR + 当前 Verilator 模型 | 原模块运行 PASS；覆盖 RVC prefix/owned、backpressure、commit+rollback |
| 1769000/frontend_test.cpp | VFrontend 与外部 cache responder | 原文明确只准备未执行；未验证、使用前审核 |

将生成物/编译目录放 `AI/TMP/<run-id>/`。对源码运行历史测试时先核对 ports、配置和新 RTL，不能复用旧模型冒充当前通过。精确历史 build 命令和完整日志在 `history/evidence/` 和 external raw archive；本整理仅验证脚本/工具，未重跑硬件测试。
