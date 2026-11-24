# L1 slot epoch完整事务边界回归

先用现有rollback/user_build.sh生成Hierarchy，再运行：

```bash
python3 -B AI/Debug/scripts/finite_identity/run.py \
  --generated "$hierarchy_out/generated" --generation-inputs "$generation_manifest" \
  --out "$fresh_out"
```

runner只将set64两空槽reset初值0改成0xffff，保存原生成物/加速生成物/两条
替换及哈希。C++先核验实际seed，再经真实L1/L2发起同组四条冷LOAD与替换，
每次等待install/refill及MSHR终态后再次读数据。它不修改ready、owner判断或
响应结果。原反例分配按nextSlotEpoch跳到1，但三处普通+1判断误配，触发
refill destination owner mismatch；修复必须在同一完整事务输入通过。

直接在Verilator优化模型中写内部root字段不能证明所有内部优化状态已更新，
早先此做法的PASS不计边界覆盖。必须用此处可追溯的reset加速并检查实际
resident ffff与accepted owner1；完整模型正常初值仍独立运行Hierarchy回归。

本测试不替代persistent Seq/Epoch/内容serial语义，也不涵盖物理CDC。

Epoch/CurGen近上界维护也可复用同一runner：追加`--kind generation`。只将
生产ExecutionHistory的两个reset值加速至0xffffffdd，compact零赋值保持
原样。一次真实rollback触发0xffffffde保留区；停住实际外写和matching ACK
时不得清标签或重启。释放后须取得真实维护证书、清零、发布空上下文、
恢复存活字节，并在新generation再次rollback/完整安装后读取正确。
测试没有host伪造maintenance ACK，也没有改ready/result条件。
