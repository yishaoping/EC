# Skill：deadlock/wait-for cycle

先区分纯组合环与跨寄存器状态等待环。列出节点（FSM、FIFO、LSL、ROB、CDC、result、barrier）和每条等待边，标注 valid/ready/fire、清除条件和 progress source。确认 timeout 是否被无关 xRET/interrupt 清零；确认取消是否释放真正 owner；确认“程序跑完/watchdog 变晚”不是进展证明。用最小窗口和 generated RTL 复核环。
