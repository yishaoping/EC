# PALIMPSEST 面积评估 r2

修订日期2026-11-13。保留上一轮所有成果；不覆盖原RTL，不启动SoC/FPGA/PARSEC。

- [area_audit.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/area_audit.md)：配置核对、位数、去重、三基线、逐模块及Low/Typical/High、发表判断。
- [rtl_coverage.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/rtl_coverage.md)：10个原语与论文Section IV机制覆盖、未实现项。
- [integration_plan.md](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/reports/integration_plan.md)：最小接点、接口、顺序和功能/物理验证计划。
- [matched_profiles.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/config/matched_profiles.json)：三种同几何声明配置，尚未生成系统RTL。
- [module_area.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/module_area.csv)、[area_scenarios.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/area_scenarios.csv)、[cache_metadata.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/cache_metadata.csv)：可复算资源预算。
- [accounting_ledger.csv](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/accounting_ledger.csv)：基线保留、新增、复用/替换及遗漏项归属。
- [primitive_budget.pdf](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/figures/primitive_budget.pdf)、[model_scenarios.pdf](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/figures/model_scenarios.pdf)：带假设标签的独立导出图。
- [provenance-checks.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/evidence/provenance-checks.json)、[limits-test.json](/data1/gzh/EC/check/area_eval/revisions/r2-20261113/results/limits-test.json)：哈希与短验证证据。

旧0.1923mm²算术成立，但针对512KiB/Seq16和不完整原语。冻结实验为1MiB/16-way；Seq32缩减标识设计的条件原语预算Typical0.488425mm²，旧缓冲/余量规则0.500837mm²。完整同配置PAL−PEEK面积和百分比未知，所有mm²均为分析模型，未取得28nm映射综合结果。
