# 已识别的版本差异、冲突与未知

| 旧说法/资料 | 本次判断 | 状态 |
|---|---|---|
| 10-08 handoff 称 latest=528000、barrier disabled | 528000 RCA 的版本匹配 RTL/FST 显示 real barrier enabled；handoff 的 latest 已过期 | historical/deprecated，仅限原版本 |
| 459000 handoff 风险：head_valid 仍指原始 SyncReadMem | 528000 audit 证实注册 payload 保持且 3201 次匹配出队；当前源码 selected_head 使用 lsl_head_payload | 旧问题在该 528000 run 消失；不外推最新 run |
| `461000 req_ready=match` 初版修复 | 当前 R_LSL response-ready 在 head valid 时可报 mismatch；仅 matching deq_fire 消费 | superseded implementation，保留初版演化 |
| 1769000 review 第 4 节“生命周期闭合” | 第 5 节以新的 459000 run 明确更正 redirect 静态结论；第 6 节实施 pending/settle 后仅静态验证 | deprecated claim；动态 unresolved |
| 最新 output `*** PASSED ***` | test.log 同时 `verified=0`、`[END] FAIL`；模拟器结束不是软件正确 | verified fact：本次功能失败 |
| Tage.scala `asBools is not a member of Data` | handoff 明确来源是 `/data1/GB/chipyard-boom-fdip/soc-generator`，不属于 EC | external reference，不能计入 EC bug |
| 口述 514000 / 部分旧同名 test.vcd | 原文件已被历史运行覆盖，缺少匹配原波形；保留报告/hash/窄证据，不重新赋予当前身份 | unresolved provenance |
| 当前 GH_REAL_BARRIER_ENABLED 注释“opt-in” vs 默认 true | 值为 true；注释是历史残留，已记录但本任务不改功能代码 | source/comment conflict，取实际参数值 |

没有把未证实的 latest root cause 选作事实。旧报告中的源码行号和同名 current path 是历史引用；维护资料通过 inventory 和外部原始备份定位其来源。
