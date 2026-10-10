# redirect / replay / slot lifecycle

- [ ] 真实 request.fire 绑定 PC、mode、sequence、S1/S2 owner
- [ ] pending/redirect target 保持到实际接受，背压不丢 PC、不制造 ghost S2
- [ ] 新 redirect 覆盖旧 pending；接受拍 mode 已 settle；handler 不被包 clear 错杀
- [ ] reserve、FQ emit、WB commit/rollback 各只按其真实事件前推一次
- [ ] replay/exception/kill 不重复 commit，同拍 commit+rollback 保留已退休前缀
- [ ] trap matching xRET、cleanup/result-handoff/admission 的偏序闭合
- [ ] old DATA/END/result 不污染新 slot；allocation→admission 无 owner 区域明确检查
- [ ] timeout 仅按包真实进展更新，无关 xRET/interrupt 不无限续期

依据：1769000 review 第 4–6 节、528000 RCA、assert24 历史记录。allocation→admission timeout 缺口仍未修复；不得宣称已有 complete bounded cancellation。
