# Skill：ready/valid、CDC、FIFO 协议审查

对每条通道检查：producer valid、consumer ready、fire、payload hold、queue occupancy、reset/kill、跨时钟 epoch/sequence。明确谁拥有 head，谁能 dequeue，response 是否可能在 valid 前被读取。AsyncQueue full/empty 只说明本队列，不说明其他流；多 lane packet 只有所有有效 lane 都能接受时才能整体 fire。将每个异常写成 broken invariant 和最小动态验证。
