# Post-run correctness audit

> 即使输出 Completed/PASSED，仍独立核对 benchmark verified/checksum、检查覆盖范围、架构提交与 checker stream、count/DATA/END、结果/release/safe、token 和 barrier/TL。确认相应功能真实 exercised，写出未覆盖的参数/边界；package 计数与模拟器退出状态只作为部分证据。
