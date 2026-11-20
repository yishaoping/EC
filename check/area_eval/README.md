# PALIMPSEST area_eval

独立评估目录。未修改`check/source`、原始生成RTL或既有实验；未运行完整SoC/FPGA/PARSEC任务。

- [最终面积报告](reports/area_report.md)：资源明细、面积模型、归一化边界和发表前工作。
- [实现与配置报告](reports/implementation.md)：基线版本、实际配置、模块映射、状态与接口限制。
- [RTL](rtl/palimpsest.sv)：可综合独立原语；未自动集成Chipyard。
- [逐模块CSV](results/module_area.csv)、[综合统计](results/synthesis/summary.json)、[测试结果](results/tests.json)。
- [模块贡献图](figures/incremental_modules.pdf)、[系统参考比较图](figures/system_reference_only.pdf)、[元数据敏感性图](figures/cache_metadata_sensitivity.pdf)。

最可信的结论是RTL逻辑容量与generic资源数。Typical设计场景的面积模型约0.19mm²（工程物理敏感性0.09–0.45mm²），不是TSMC/SMIC28nm映射综合结果。对PEEK论文5.04mm²的参考归一化约3.8%，不等于当前项目的实测开销；同配置未保护体系结构总开销仍待验证。

复现：在本目录执行`python3 scripts/run_all.py`，然后`python3 scripts/report_area.py`。不依赖网络安装。所有评估输出留在本目录。
