# R3 Hardware Overheads 面积复审

主审计：[area_reaudit.md](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/reports/area_reaudit.md)。固定冻结几何，只读审计和计算，未修改RTL/综合/测试/PARSEC。

- 主模型保持 **0.48842495mm²**，已证实可对PEEK净扣减的金额为0；9.69%是边界不一致的参考除法，严格百分比未知。
- 原packing解释，密度0.20–0.40：**0.28388095–0.48842495mm²**；若输入已是完整macro有效密度则为**0.24297215–0.40660735mm²**。均为假设敏感性，没有校准后的新Typical。
- 发现ASAP7 dummy及Sky130资产，未找到适用28nm SRAM宏标定；0.127只作理论参考。

产物：

- [模块CSV](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/hardware_area_breakdown.csv)；[模型对比](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/model_comparison.csv)；[密度CSV](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/sram_sensitivity.csv)。
- [面积边界CSV](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/normalization_boundaries.csv)；[新增/复用/替换清单](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/resource_ledger.csv)；[字段审计](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/metadata_fields.csv)。
- [敏感性图PDF](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/figures/sram_sensitivity.pdf)（同目录SVG/PNG）。
- [DAC英文LaTeX](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/latex/hardware_overheads.tex)；[敏感性LaTeX表](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/latex/area_models.tex)。
- [计算依据](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/calculation.json)；[搜索记录](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/evidence/macro-asset-search.json)；[保全与算术检查](/data1/gzh/EC/check/area_eval/revisions/r3-area-audit-20261113/results/verification.json)。

复算：`python3 scripts/audit_area.py`，仅读取R2计数和写本目录，不调用硬件工具。
