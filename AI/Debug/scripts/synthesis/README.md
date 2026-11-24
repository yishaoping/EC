# 同步器物理约束

`synchronizers.xdc`对应Rocket `SynchronizerPrimitiveShiftReg`预留的后端实现约束。
它只匹配primitive中`output_chain/.../sync_N_reg`，为既有寄存器设置ASYNC_REG和
SHREG_EXTRACT=NO，防止未复位同步链被映射为SRL或合并。

必须在`synth_design`前`read_xdc`；若没有匹配即失败，不能静默认为已保护。
实际施加数量和层次见Vivado日志中的Applied set_property记录。现用firtool会
忽略普通`firrtl.AttributeAnnotation`，因此仅在Scala里添加该注解并不足以证明
最终同步器正确映射。该约束不改变RTL数字功能。

本批实际验证使用从Scala候选经生产ExtraLowTransforms、barstools及firtool生成
的SeqTransportHarness。GHM被该夹具的InlineAnnotation内联，不能用不存在的
GHM模块作为综合top。更早旧生成物的GHM独立报告与新Harness报告有不同裁剪
边界，资源数不可混作同一个面积增量。

此文件不豁免AsyncQueue数据CE路径，也不替代Gray指针总线偏斜/最大延时约束、
reset解除、布局布线或完整Core STA。当前源端组合维护请求还需要注册，数字
四相回归必须同时覆盖。已确认的物理问题和实际结果在
`AI/Debug/bugs/bug-palimpsest-ghm-physical-cdc.md`及验证矩阵。
