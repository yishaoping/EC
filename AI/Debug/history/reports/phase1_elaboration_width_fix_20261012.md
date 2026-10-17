# Phase-1 candidateWay elaboration 位宽修复（2026-10-12）

用户终端的 `java.lang.reflect.InvocationTargetException` 是外层异常。原 `v1Config` chisel.log（15:10:23 +08）首次实际错误为：

```text
chisel3.internal.ChiselException:
Width of BoomNonBlockingDCache.candidateWay: OpResult[UInt] is unknown!
at chisel3.util.OHToUInt$.apply(OneHot.scala:23)
at boom.lsu.BoomNonBlockingDCacheModule ... (dcache.scala:916)
```

`candidateWay` 原来直接来自 hit-way/replacement-way 的 Mux，Chisel elaboration 时宽度仍未知；`OHToUInt` 立即调用 `getWidth`，尚未进入 FIRRTL 宽度推导便失败。该因果链由原错误栈与源码直接确认，不属于 Java 环境或仿真运行错误。

修复仅在 `chipyard/generators/boom/src/main/scala/lsu/dcache.scala` 将 candidateWay 声明为 `Wire(UInt(nWays.W))`，再连接原 Mux。这样输入保持 cache way mask 的既定位宽和原选择条件，owner、admission、refill 与 terminal 行为不变。本轮没有修改 AMO 返回值或其他 Phase-1 功能。

验证在独立 `AI/TMP/phase1_elaboration_fix_20261012_151358/generated` 目录进行，保留默认 generated-src、原 simulator 和旧波形作为旧证据：

- `make ... CONFIG=v1Config firrtl`：退出码 0，Chisel elaboration 通过（15:15:55 +08）。
- `make ... CONFIG=v1Config verilog`：退出码 0；Scala FIRRTL low lowering、firtool `--verify-each=true`、`CheckCombLoops`、Verilog emission、top/model MacroCompiler 均通过。
- `git diff --check`：通过。
- 未构建新 Verilator executable，未运行仿真；不据此声称 Phase-1 功能或原 264000 regression 已通过。

证据目录保存原 chisel.log、修改前源码/diff、命令、elaboration/lowering 日志、生成物和 SHA256 manifest。环境使用仓库本地 sbt 和 Java 17，完整命令见 [commands.json](../../../TMP/phase1_elaboration_fix_20261012_151358/commands.json)。用户可以在默认目录重跑原 make 命令，源码时间戳会触发重新生成。
