# Skill：Scala/Chisel/FIRRTL 检查

顺序执行：Scala parser/API/type compile → target Chisel elaboration → FIRRTL initialization/width/connectivity → CheckCombLoops/lowering → generated RTL review → dynamic test。特别检查 Bundle 新字段每个实例连接、Bool/UInt 宽度、dynamic Vec/Memory `dontTouch` target、SyncReadMem latency/payload、Mux 类型和 reset 初始化。出现 compile PASS 不能跳过 elaboration；elaboration PASS 不能替代运行验证。
