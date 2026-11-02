# 下一完整实验契约：当前尚未READY

当前不存在已获GO的唯一functional optimization，因此不能诚实地说“现在只需运行一个Opt5命令”。
`slowdown/optimization_5_pending_decision/`只存决策说明，不含launcher、构建或观察-only运行入口。

下一次完整实验**必须先有独立依据确定一个主要功能改动**；不会为L2重建或这些counter单独跑一次。
若最终选择L1 64KiB/2-way，只改真实Config一项capacity/index方向，保留SVB16/6MSHR/当前correctness fixes；
若选择另一个方向则不夹带cache扩容。修好的L2 observer和kind40–45可以同时加入，不作为功能优化归因。

## 功能候选确定后的一次集成

1. 新建`slowdown/optimization_5_<chosen_name>/`，保存唯一功能diff、观察diff、全输入hash和Opt4 reference。
2. 正确集成launcher的revision/cumulative patch保护；保留旧保护，不在旧Opt4下绕过reverse-check。
3. 在该功能实验阶段做fresh elaboration、geometry/连接/SRAM/组合环与simulator build预检。
4. 用户执行一个fresh完整功能run，无observer-only前置实验；本轮未执行也未准备这个运行。
5. 该run同时产生selected optimization ROI、verified/checksum、完整406型lifecycle协议审计、Opt4对比、
   remaining slowdown、SVB16 occupancy/depth/terminal、corrected L2 S0与replacement模型限制、kind40–45精确计数。
6. 若S0或snapshot/key审计失败，只屏蔽相应cache counterfactual；若真实integrity/protocol缺失，则functional validation fail closed。

原run缺失的MSHR身份和optional suffix不可能事后补齐。新增聚合observer虽改善下一功能run的定位，
仍不保证一次run能证明所有后续geometry反事实；不对未来“绝无第二次实验”作无证据承诺。
