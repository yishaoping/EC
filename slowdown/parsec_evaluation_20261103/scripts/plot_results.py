#!/usr/bin/env python3
"""Standalone publication figures from validated primary tables only."""
import csv,hashlib,json,math,statistics
from pathlib import Path
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
OUT=Path(__file__).resolve().parents[1]
def main():
    rows=list(csv.DictReader((OUT/'RESULTS.csv').open()))
    assert rows,'No accepted primary comparisons; do not draw an empty or pilot performance figure'
    dest=OUT/'plots';dest.mkdir(exist_ok=True)
    plt.rcParams.update({'font.family':'DejaVu Sans','font.size':10,'axes.spines.top':False,'axes.spines.right':False,'pdf.fonttype':42,'svg.fonttype':'none','savefig.bbox':'tight'})
    labels=[r['benchmark']+'\n'+r['input']for r in rows]+['Geometric\nmean']
    fig,ax=plt.subplots(figsize=(7.2,3.5));width=.24
    for i,(key,label,color)in enumerate([('check_native','Check / Native','#4477AA'),('correction_native','Correction / Native','#EE6677'),('correction_check','Correction / Check','#228833')]):
        vals=[float(r[key])for r in rows];vals+=[math.exp(statistics.mean(map(math.log,vals)))]
        bars=ax.bar([j+(i-1)*width for j in range(len(labels))],vals,width,label=label,color=color)
        ax.bar_label(bars,fmt='%.3f',padding=2,fontsize=8)
    ax.axhline(1,color='.4',linewidth=.8,linestyle='--');ax.set_xticks(range(len(labels)),labels);ax.set_ylabel('Application ROI cycle ratio');ax.set_ylim(bottom=0);ax.set_axisbelow(True);ax.grid(axis='y',alpha=.2);ax.legend(frameon=False,ncol=3,loc='upper center',bbox_to_anchor=(.5,1.22));fig.tight_layout()
    for ext in ['pdf','svg','png']:fig.savefig(dest/('slowdown.'+ext),dpi=300)
    plt.close(fig)
    drain=list(csv.DictReader((OUT/'counters/DRAIN.csv').open()));fig,ax=plt.subplots(figsize=(6.5,3))
    xs=range(len(drain));app=[int(r['correction_app_ROI'])/1e6 for r in drain];tail=[int(r['correction_drain_tail'])/1e6 for r in drain]
    ax.bar(xs,app,label='Application ROI',color='#4477AA');ax.bar(xs,tail,bottom=app,label='Verification tail',color='#CCBB44');ax.set_xticks(list(xs),[r['benchmark'] for r in drain]);ax.set_ylabel('Correction BOOM cycles (millions)');ax.legend(frameon=False);ax.grid(axis='y',alpha=.2);ax.set_axisbelow(True);fig.tight_layout()
    for ext in ['pdf','svg','png']:fig.savefig(dest/('verified_completion.'+ext),dpi=300)
    plt.close(fig)
    meta={'matplotlib':matplotlib.__version__,'scope':'Accepted work-equivalent primary triplets only. Native is unprotected mode of the matched detection model without recovery datapath. No host time or recovery fault trials are included.','inputs':{str(p.relative_to(OUT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [OUT/'RESULTS.csv',OUT/'counters/DRAIN.csv']},'script_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
    (dest/'manifest.json').write_text(json.dumps(meta,indent=2)+'\n')
if __name__=='__main__':main()
