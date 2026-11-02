# L2 shadow accepted-write mirror与delayed read image不一致

状态：**observer invariant缺陷确认；源码修复/CPU fixture/Scala typer PASS；动态验证未运行**。
不是SVB功能数据错误。依据run `optimization_4_svb_20261030_072604_18475a92`，
Opt4 functional correctness/ROI已闭合，不受该shadow fidelity失败影响。

## Symptom与语义

同一L2非Hint A-priority directory-result流access42,225；actual misses149，shadow S0 misses40,369。
该流包含所有inner clients和reload/relookup；不是BOOM-only需求、不是C Release、不是TileLink每beat。
另外inner A first42,227、C first2,313；不能无证据将A与lookup差2解释为两个Hint。

## Causal chain与证据等级

- 已证明的直接模型问题：旧host以`directory.io.write.fire()`更新latest accepted metadata mirror。
- 已证明的源码条件：Directory有1-entry Queue、单端口仲裁、RAM/dirReg延迟和pending-write bypass；
  accepted queue input不等于每个delayed read所见的image。
- 已执行CPU反例：较新的accepted B覆盖mirror，而较早lookup A仍见A的read-consistent image，旧S0产生false miss。
- 未证明：旧run中哪笔transaction为first divergence，或40,220 excess中各原因占比；原始read/write序列未保存。
- 可能放大器：持续accepted-write/read-image错位；本run具体频次未知，不当作已证明动态链。

地址`expandAddress`后统一`restoreAddress`，以及独立scheduler key audit也已加入；
这些是模型一致性修复，不能声称已证明它们解释本次数量级。
旧warm-state在clear_stats时保留；cannot explain as blanket cold start。

## Fix与不变量

Directory新增只读row/set/tag快照，row包括与functional lookup相同的pending-write bypass。
Scheduler每个demand前发送完整way快照；host独立valid/tag比较，绝不复制actual.hit。
每个lookup全way齐全且key一致；重复、missing、orphan frame和错误set/key fail closed。
schema2输出snapshot count、errors和A/C/demand opcode。旧mirror只作temporal disagreement诊断。
analyzer分离functional validity与各层shadow sanity，S0失败的geometry delta置null。

## Validation与限制

58项offline tests、CPU native fixtures、7个Scala文件typer检查、观察区逆变换及原始hash检查PASS。
本轮禁止并未执行elaboration、RTL generation、Verilator build、硬件仿真或benchmark。
无法从旧summary/hash恢复缺失metadata顺序，不能重放旧S0，不能使用旧L2 S1–S3。
`L2_GEOMETRY_DEFERRED_UNTIL_NEXT_FUNCTIONAL_RUN`；不要求也不准备L2-only观察run。

完整源码前像、hash和报告：
[2026-10-30报告](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/l2_shadow_rootcause.md)，
[修复](../../TMP/opt4_remaining_slowdown_next_opt_20261030_e6901889/l2_shadow_fix.md)。
