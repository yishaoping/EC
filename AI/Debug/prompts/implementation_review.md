# Implementation / static review prompt

> 对照 Fix Design 检查真实源码、接口宿主、所有实例连接、宽度/类型/API、reset 优先级和 generated target。执行 parser/compile、elaboration、FIRRTL initialization/CheckCombLoops、RTL 复查；动态 dontTouch、SyncReadMem payload、ready 反向依赖和组合环单独审查。静态 PASS 不替代 simulation。
