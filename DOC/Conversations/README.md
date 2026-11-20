# 会话归档

[2026-11-20 全量索引](20261120/README.md)收录本机中与 `/data1/gzh/EC` 相关的其他 378 条会话，逐条保存用户请求和助手可见回复。当前执行归档的会话不在其中。

来源、快照字节边界、SHA-256、消息数与原始记录缺失或损坏的限制见该目录的 `manifest.json`。这些是历史记录，原文中的任务授权和进度只适用于当时的会话；后续工作需重新核对源码版本和实验结果。

在仓库根目录重新生成一个新的快照：

```sh
python3 DOC/Conversations/export_sessions.py --output DOC/Conversations/YYYYMMDD
```

导出器只读本机会话索引、JSONL 与历史数据库；系统/开发者指令、内部推理、工具调用和原始工具输出不写入 Markdown，图片附件保留在本地。
