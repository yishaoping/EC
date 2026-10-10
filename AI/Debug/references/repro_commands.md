# 可复现命令入口

```sh
cd /data1/gzh/EC
AI/Debug/scripts/check_debug_invariants.py .
AI/Debug/scripts/ec_fst_trace.sh /path/to/run.fst START END 'regex'
AI/Debug/scripts/summarize_trace.py trace.txt
bash AI/Debug/scripts/trace_profile.sh /path/to/run.fst watchdog 0 2000
```

Chipyard 静态门：

```sh
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
./.conda-env/bin/sbt -batch 'project rocketchip' Compile/compile
```

整机生成和仿真命令必须把 `build_dir`、软件 hash、Git diff 和输出目录记录到 manifest；不要覆盖旧波形。
