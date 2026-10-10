# Skill：cache/TileLink/token tracing

以 packet seq、line address/set/way、STQ index、strict token 为主键，贯穿 S0–S3、MSHR、RPQ/replay、物理 write fire、TL A/C/D fire、metadata clear 和 safe watermark。确认 `TtoN`、writeback/meta-clear ordering、旧 replay 与新 STQ slot 不混淆，以及每个 token 只接受一次 completion。任何地址或 index 单独匹配都不足以证明同一事务。
