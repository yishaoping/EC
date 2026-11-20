#!/usr/bin/env python3
"""Export the existing Typical analytical estimate; no RTL or synthesis runs."""
from pathlib import Path
from decimal import Decimal as D
import csv
import hashlib
import json

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.ticker import PercentFormatter

OUT = Path(__file__).resolve().parent
REV = OUT.parent
source = REV / 'results/module_area.csv'
summary_path = REV / 'results/area_summary.json'
source_rows = [row for row in csv.DictReader(source.open()) if row['sequence_bits'] == '32']
lookup = {row['component']: row for row in source_rows}
groups = [
    ('L1 Version Metadata', ['L1D metadata and selection']),
    ('L2 Version Metadata', ['L2 metadata and selection']),
    ('Version Preservation', ['Preservation controllers']),
    ('Visibility Control', ['Visibility checks', 'SW bitmap 16 (conditional new instance)']),
    ('Early LSL Reclamation', ['LSL release descriptors (conditional)']),
    ('EVT', ['EVT 16 entries / 16 queries']),
    ('Rollback Controller', ['Rollback controller']),
    ('Recovery Context Storage', ['Context 8 x 80 x 64 (conditional)']),
]
consumed = [name for _, names in groups for name in names]
assert len(consumed) == len(set(consumed)) == len(source_rows)
assert set(consumed) == set(lookup)

# Independent arithmetic check using the inherited Typical assumptions.
for row in source_rows:
    expected = (D(row['RAM_bits'])*D('0.40')*D('1.25') +
                D(row['GE_excluding_RAM'])*D('0.70')) / D('1000000')
    assert expected == D(row['typical_mm2_model']), (row['component'], expected)

total = sum(D(row['typical_mm2_model']) for row in source_rows)
summary = json.loads(summary_path.read_text())
assert total == D(str(summary['cases']['seq32']['primitive_subtotal_mm2_model']['typical']))
assert total == D('0.48842495')
rows = []
for name, names in groups:
    area = sum(D(lookup[item]['typical_mm2_model']) for item in names)
    rows.append({'component': name, 'estimated_area_mm2': area,
                 'share_of_increment_pct': area/total*100})
assert sum(row['share_of_increment_pct'] for row in rows).quantize(D('0.00000001')) == D('100')

with (OUT/'hardware_area_breakdown.csv').open('w', newline='') as fp:
    writer = csv.DictWriter(fp, fieldnames=list(rows[0]))
    writer.writeheader()
    for row in rows:
        writer.writerow({'component': row['component'],
                         'estimated_area_mm2': format(row['estimated_area_mm2'], '.8f'),
                         'share_of_increment_pct': format(row['share_of_increment_pct'], '.8f')})
    writer.writerow({'component':'Total', 'estimated_area_mm2':format(total,'.8f'),
                     'share_of_increment_pct':'100.00000000'})

peek_ref = D('3.96') + 4*D('0.27')
normalized = total/peek_ref*100
metadata_share = sum(row['share_of_increment_pct'] for row in rows[:2])

latex = [
    '% Requires \\usepackage{booktabs}. Areas are analytical estimates.',
    r'\begin{table}[t]', r'\centering', r'\small',
    r'\caption{Estimated PALIMPSEST hardware area breakdown (Typical analytical model).}',
    r'\label{tab:palimpsest-area}',
    r'\begin{tabular}{lrr}', r'\toprule',
    r'Component & Area (mm$^2$) & Share (\%) \\', r'\midrule',
]
for row in rows:
    latex.append(f"{row['component']} & {row['estimated_area_mm2']:.6f} & {row['share_of_increment_pct']:.2f} " + r'\\')
latex += [r'\midrule',
          f'Total & {total:.6f} & 100.00 ' + r'\\', r'\bottomrule',
          r'\end{tabular}', r'\par\vspace{2pt}',
          r'\begin{minipage}{\columnwidth}\footnotesize',
          r'L1/L2 metadata includes selection and store-control logic; visibility control includes the SW bitmap. '
          r'The estimate is 9.69\% of the 5.04\,mm$^2$ PEEK reference core-area sum, '
          r'not a matched-configuration, matched-process synthesis result. Values are rounded.',
          r'\end{minipage}', r'\end{table}', '']
(OUT/'hardware_area_breakdown.tex').write_text('\n'.join(latex))

paragraph = (
    r'\noindent\textbf{Hardware Overheads.} '
    r'For the frozen configuration with a 1\,MiB, 16-way L2 and 32-bit sequence numbers, '
    f'our Typical analytical model estimates {total:.4f}' + r'\,mm$^2$ of additional PALIMPSEST hardware. '
    f'L1/L2 version metadata and its selection/store-control logic account for {metadata_share:.2f}' + r'\% of this estimate, '
    f'followed by the EVT ({rows[5]["share_of_increment_pct"]:.2f}' + r'\%) and recovery context storage '
    f'({rows[7]["share_of_increment_pct"]:.2f}' + r'\%). '
    r"Using the PEEK paper's reported BOOM area of 3.96\,mm$^2$ and "
    r'Rocket area of 0.27\,mm$^2$ per core, the reference area for one BOOM and four Rockets is '
    r'5.04\,mm$^2$; our modeled increment is therefore '
    f'{normalized:.2f}' + r'\% of that reference core-area sum. '
    r'This percentage is a reference-normalized analytical estimate, not a synthesis comparison '
    r'under matched hardware configurations and process conditions. The model combines generic logic '
    r'counts with assumed SRAM and gate densities; field widths, storage sizing, macro organization, '
    r'and omitted interface logic are the main sources of uncertainty.'
)
(OUT/'hardware_overheads.tex').write_text(paragraph+'\n')
english = (paragraph.replace(r'\noindent\textbf{Hardware Overheads.} ', '')
           .replace(r'\,', ' ').replace(r'mm$^2$', 'mm²').replace(r'\%', '%')
           .replace(r'\textquotesingle s', "'s"))
(OUT/'hardware_overheads.md').write_text(english+'\n')

plt.rcParams.update({'font.family':'DejaVu Sans', 'font.size':7.5,
                     'pdf.fonttype':42, 'ps.fonttype':42, 'svg.fonttype':'none',
                     'axes.spines.top':False, 'axes.spines.right':False,
                     'axes.spines.left':False})
fig, ax = plt.subplots(figsize=(3.5,2.85))
labels = ['L1 version metadata', 'L2 version metadata', 'Version preservation',
          'Visibility control', 'Early LSL reclamation', 'EVT',
          'Rollback controller', 'Recovery context storage']
shares = [float(row['share_of_increment_pct']) for row in rows]
colors = ['#537e9b' if i != 1 else '#214c68' for i in range(len(rows))]
ax.barh(range(len(rows)), shares, height=.56, color=colors, zorder=3)
ax.set_yticks(range(len(rows)), labels)
ax.invert_yaxis()
ax.set_xlim(0,102)
ax.set_xticks([0,25,50,75,100])
ax.xaxis.set_major_formatter(PercentFormatter(xmax=100,decimals=0))
ax.tick_params(axis='y', length=0, pad=5, labelsize=7)
ax.tick_params(axis='x', length=2.5, labelsize=7)
ax.xaxis.grid(True, color='#e6e6e6', linewidth=.55, zorder=0)
ax.set_axisbelow(True)
ax.set_xlabel('Share of modeled additional area', fontsize=7.5, labelpad=4)
for i, value in enumerate(shares):
    ax.text(value+1.8, i, f'{value:.2f}%', va='center', fontsize=7)
fig.suptitle('Hardware Area Breakdown', x=.52, y=.975, fontsize=9, fontweight='medium')
fig.text(.52,.904,f'Typical analytical estimate: {total:.4f} mm²', ha='center', fontsize=7.3)
fig.subplots_adjust(left=.455,right=.94,bottom=.18,top=.855)
for ext in ('pdf','svg','png'):
    fig.savefig(OUT/f'hardware_area_breakdown.{ext}',dpi=300,facecolor='white')
plt.close(fig)

figure_tex = r'''\begin{figure}[t]
  \centering
  \includegraphics[width=\columnwidth]{hardware_area_breakdown.pdf}
  \caption{PALIMPSEST hardware area breakdown under the Typical analytical model
  (1\,MiB, 16-way L2; 32-bit Seq). L1/L2 metadata includes selection and
  store-control logic; visibility control includes the SW bitmap.}
  \label{fig:palimpsest-area}
\end{figure}
'''
(OUT/'hardware_area_figure.tex').write_text(figure_tex)

md = ['# DAC Hardware Overheads：面积估算', '',
      '采用现有 r2 Typical 模型，仅核对和导出；未修改 RTL、未做集成、功能测试或新综合。', '',
      '| 模块 | 估算面积（mm²） | 占总新增面积 |', '|---|---:|---:|']
for row in rows:
    md.append(f"| {row['component']} | {row['estimated_area_mm2']:.6f} | {row['share_of_increment_pct']:.2f}% |")
md += [f'| **Total** | **{total:.6f}** | **100.00%** |', '',
       '![Hardware Area Breakdown](hardware_area_breakdown.png)', '',
       'CSV保留未显示的精度。L1/L2 Version Metadata包含对应selector与store policy；'
       'Visibility Control合并原visibility checks（0.0003374 mm²）和SW bitmap（0.0008176 mm²），无遗漏或重复。', '',
       '参考归一化：`A_PEEK,ref = 3.96 + 4×0.27 = 5.04 mm²`；'
       f'`0.48842495 / 5.04 × 100% = {normalized:.8f}% ≈ 9.69%`。'
       '分母是PEEK论文的核面积参考和，不是本项目同配置系统面积，也没有在该分母额外加入共享L2。'
       '不得称为同配置、同工艺的实际综合开销。', '',
       '## English paragraph', '', english, '',
       '## 估算方法与关键假设', '',
       '`A = (B_RAM × 0.40 × 1.25 + GE × 0.70) / 10^6 mm²`，其中'
       '`B_RAM=818,176 bit`、`GE=113,338.5`；0.40为假设SRAM密度（μm²/bit），'
       '1.25为packing系数，0.70为假设NAND2等效面积（μm²/GE）。'
       '得到RAM项0.409088 mm²、逻辑项0.07933695 mm²，合计0.48842495 mm²。'
       'DFF已经包含在GE内，没有再按SRAM计费。未加入旧模型额外buffer和15%接口余量。', '',
       '- 几何：Main L1D 32 KiB/2-way；L2 1 MiB/16-way；64 B/cache line。',
       '- 字段假设：Seq32 + Recovery Epoch4 + CurGen8 + Cur1 + preserved1 = 46 bit/line；'
       'L1D 512行、L2 16,384行，对应777,216 bit版本元数据。该46位是模型假设，不是冻结接口完整81位image key的实测实现。',
       '- 上下文：8×80×64=40,960 bit；EVT：16 entries、16 queries；LSL回收：每checker 8个descriptor，共4核；SW window16。'
       '这些沿用现有r2设计假设，本次不重新论证容量。',
       '- 边界：估算的是新增元数据/控制/恢复上下文原语；既有L1/L2 Data/Tag、PEEK原有checkpoint和LSL payload未再次计入。'
       '本场景将SW和reclaim描述符作为新增项；最终复用或替换会改变净增量。',
       '- 主要误差来自SRAM密度和端口/宏组织、GE折算、元数据位宽和context/descriptor容量，以及未计入的接口逻辑。'
       '该模型没有28 nm标准单元库或SRAM宏映射标定，不是完整系统实测面积。', '',
       '## 输入与导出', '',
       f'- 资源与逐模块值：[module_area.csv]({source})。',
       f'- Typical参数与小计：[area_summary.json]({summary_path})。',
       f'- 核面积参考：[Micro26_PEEK.txt]({REV.parents[1]/"evidence/Micro26_PEEK.txt"}:941)。',
       '- 图：hardware_area_breakdown.pdf / .svg / .png；表：hardware_area_breakdown.csv / .tex。',
       '- 正文：hardware_overheads.tex / .md；图插入片段：hardware_area_figure.tex。',
       '- 复现：在本目录执行 `python3 export.py`，仅读取现有资源结果并导出本目录文件。', '']
(OUT/'README.md').write_text('\n'.join(md))

verification = {
    'arithmetic_status':'PASS', 'source_rows_consumed_once':len(consumed),
    'exported_groups':len(rows), 'total_estimated_area_mm2':str(total),
    'PEEK_reference_area_mm2':str(peek_ref), 'reference_normalized_percentage':str(normalized),
    'RAM_area_model_mm2':'0.409088', 'logic_area_model_mm2':'0.07933695',
    'source_sha256':{str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in (source,summary_path)},
    'source_breakdown':{name:names for name,names in groups},
    'area_evidence':'ANALYTICAL_MODEL_NOT_MATCHED_PROCESS_OR_CONFIGURATION_SYNTHESIS',
}
(OUT/'calculation.json').write_text(json.dumps(verification,indent=2)+'\n')
print(json.dumps({k:v for k,v in verification.items() if k not in ('source_sha256','source_breakdown')},indent=2))
