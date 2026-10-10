# 内容检查与分类方法

清点两个旧目录全部4938文件，记录bytes/SHA256、原始路径、备份路径和维护去向；使用实际文件头检查FST(即使.vcd后缀)、FIRRTL、生成HDL/Verilator模型、ELF与信号文本。手写脚本、测试bench、before源码/diff、Markdown分析、工具错误和验证结果另按实际内容/实例接口检查；生成目录里的C++不自动作为手写工具。

旧报告完整原文与唯一窄证据保留；相关关键源码和生成RTL接口单独核对。源码manifest记录437份BOOM/Rocket Scala及软件/当前运行/关键RTL；无需把同一生成流程的4136份SV逐条展开成Agent上下文。

`original_inventory.tsv`中的content_kind用于按内容类型检索，role是用途判断。legacy中缺少原始运行身份或最新版本的报告标记historical/unresolved；不会仅根据文件名的current/fix/verified提升证据等级。

本轮分类统计：

- build/simulation log; outcome requires full result/revision: 36
- ELF executable/object (regenerable): 60
- generated Verilator model/support: 84
- generated build/circuit collateral: 169
- handwritten source/script (inspected role): 28
- annotation/manifest/config data: 100
- inspected archive text/binary (consult exact raw content): 84
- FIRRTL intermediate circuit: 8
- generated HDL: 4171
- investigation/spec/verification markdown: 60
- waveform signal extraction: 128
- evidence summary/manifest/extraction commands: 7
- FST waveform (suffix may be .vcd): 3
