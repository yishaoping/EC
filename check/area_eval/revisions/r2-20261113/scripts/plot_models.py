#!/usr/bin/env python3
"""Standalone model figures, explicitly not physical synthesis results."""
from pathlib import Path
import json,csv
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

R=Path(__file__).resolve().parents[1]
plt.rcParams.update({'font.size':8,'font.family':'DejaVu Sans','pdf.fonttype':42})
rows=[r for r in csv.DictReader((R/'results/module_area.csv').open()) if r['sequence_bits']=='32']
fig,ax=plt.subplots(figsize=(8.2,3.9))
names=[r['component'].replace(' (conditional new instance)','').replace(' (conditional)','') for r in rows]
storage=[int(r['RAM_bits'])*.4*1.25/1e6 for r in rows]
logic=[float(r['GE_excluding_RAM'])*.7/1e6 for r in rows]
idx=list(range(len(rows)))
ax.barh(idx,storage,label='Assumed SRAM density / packing',color='#4c78a8')
ax.barh(idx,logic,left=storage,label='Generic GE x assumed GE area',color='#f58518')
ax.set_yticks(idx,names);ax.invert_yaxis()
ax.set_xlabel('Typical conditional primitive budget (mm²); no PDK mapping')
ax.set_title('1 MiB L2; reduced identity Seq32/Epoch4/CurGen8; missing integration excluded',fontsize=8)
ax.legend(loc='lower right',fontsize=7)
fig.tight_layout()
for ext in ('pdf','svg','png'):fig.savefig(R/f'figures/primitive_budget.{ext}',dpi=200)
plt.close(fig)

s=json.loads((R/'results/area_summary.json').read_text())
old=json.loads((R/'results/legacy_arithmetic_audit.json').read_text())
data=[old['area_mm2_model'],s['cases']['seq16']['old_style_with_2_optional_SRAM_buffers_and_margin_mm2_model'],s['cases']['seq32']['old_style_with_2_optional_SRAM_buffers_and_margin_mm2_model']]
fig,ax=plt.subplots(figsize=(6.4,3.6))
for label,offset,color in [('low',-.23,'#72b7b2'),('typical',0,'#4c78a8'),('high',.23,'#e45756')]:
    vals=[r[label] for r in data]
    bars=ax.bar([i+offset for i in range(3)],vals,width=.22,label=label,color=color)
    ax.bar_label(bars,fmt='%.3f',fontsize=7,padding=2)
ax.set_xticks(range(3),['Legacy 512 KiB / Seq16','1 MiB / Seq16 hypothesis','1 MiB / Seq32 reduced identity'])
ax.tick_params(axis='x',labelsize=7)
ax.set_ylabel('Analytical budget (mm²); not system delta')
ax.set_ylim(0,1.4)
ax.set_title('Same old pricing rule: 2 optional buffers + 5/15/30% logic allowance',fontsize=8)
ax.legend(ncol=3,loc='upper left',title='Physical assumptions; not bounds or confidence intervals',fontsize=7,title_fontsize=7)
fig.tight_layout()
for ext in ('pdf','svg','png'):fig.savefig(R/f'figures/model_scenarios.{ext}',dpi=200)
plt.close(fig)
print('Wrote two standalone figures (PDF/SVG/PNG)')
