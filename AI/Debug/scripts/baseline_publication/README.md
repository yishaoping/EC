# 同址多版本发布与owner退休验收

此套件使用生产L2、History、Scheduler、preservation和真实TileLink协议。
memory/client agent只提供请求和终态，不代替硬件选择版本。每个接受的外写beat
都核对完整行数据，并等待实际ACK后才允许下一阶段。

先使用现有`rollback/user_build.sh`生成Baseline或Pressure。然后执行：

```bash
python3 -B AI/Debug/scripts/baseline_publication/run.py \
  --generated "$component_out/generated" \
  --manifest "$component_out/sources.before.json" --out "$fresh_out"
```

三个用例覆盖3/5/7同址历史、ACK3背压时SW3→7、可信Put和迟到C6竞争，
以及ACK3背压期间capture安全9的合并。检查旧owner的key/txn/bytes不变、
中间未持有版本可合并、最终查询无泄漏、可信后继成为最后基线。

脚本核验生成时的所有生产Scala和Stage3夹具来源；自身脚本及bench、生成物、
共用memory agent另以inputs.json保存哈希。build/run/result分别保留，任一失败
非零退出。此套件不声称覆盖完整Core或物理CDC/时序。

第四用例在同址3/5/7迁移、迟到C6与已接受Seq3外写ACK背压时安装EVT5..8，
随后推进SW至8。检查原Seq3 owner保持key/txn/bytes、死5/7及C6不外写、
真实ACK后读/DRAM仍为3、最后查询无历史槽泄漏。它将安装、扫描、迟到C、
安全发布和退休放在同一次真实L2事务链中验收。

同组C/BC抢占与History发布排空的前进性测试：

```bash
python3 -B AI/Debug/scripts/baseline_publication/run.py \
  --generated "$component_out/generated" \
  --manifest "$component_out/sources.before.json" --out "$fresh_out" \
  --suite grantack-preemption
```

`grantack_preemption_test.cpp` 先接受真实外层refill，延迟其响应，允许另一way的
ReleaseData在同组嵌套，再返回完整Grant。最终激励先真实Acquire取得T，经SVB归档Pending3，再以C7与SW3更新交叠；要求3先得到安全外写/ACK，SW7后才可发布7。检查外层E能排空、History完整发布、
内层Grant与ReleaseAck均完成、新BASE数据正确、真实peer权限归还及flush最终排空。
旧Scheduler在C/History/外层E循环处稳定失败。测试不强制内部状态或ACK。
