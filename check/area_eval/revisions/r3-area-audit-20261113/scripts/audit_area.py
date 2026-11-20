#!/usr/bin/env python3
"""Audit existing R2 counts and export arithmetic only. Never invokes RTL tools."""
from pathlib import Path
from decimal import Decimal as D
import csv, json, hashlib
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

R=Path(__file__).resolve().parents[1]
B=R.parents[3]
R2=R.parent/'r2-20261113'
AREA=R.parents[1]
F=B/'firesim/final-opt4-20261106/C4/chipyard/generators'
raw=[x for x in csv.DictReader((R2/'results/module_area.csv').open()) if x['sequence_bits']=='32']
syn=json.loads((R2/'results/synthesis/seq32/summary.json').read_text())
prior=list(csv.DictReader((R2/'dac_hardware_overheads/hardware_area_breakdown.csv').open()))
M=D(1000000); REF=D('5.04'); LOGIC=D('.7'); PACK=D('1.25'); DENS=D('.4')
def save(name,obj):
    (R/name).write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n')
def csvout(name,rows):
    with (R/name).open('w',newline='') as fp:
        w=csv.DictWriter(fp,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
def href(p,n=None,label=None):
    p=Path(p);return f'[{label or p.name}]({p}'+(f':{n}' if n else '')+')'
def f(p,n):return href(F/p,n)
def ar(bits,ge,density=DENS,packing=PACK):
    return (D(bits)*density*packing+D(str(ge))*LOGIC)/M

lookup={x['component']:x for x in raw}
groups=[
 ('L1 Version Metadata',['L1D metadata and selection'], [('l1_metadata',1),('selector_l1',1),('store_l1',1)]),
 ('L2 Version Metadata',['L2 metadata and selection'], [('l2_metadata',1),('selector_l2',1),('store_l2',1)]),
 ('Version Preservation',['Preservation controllers'],[('preserve',2)]),
 ('Visibility Control',['Visibility checks','SW bitmap 16 (conditional new instance)'],[('visibility',2),('sw',1)]),
 ('Early LSL Reclamation',['LSL release descriptors (conditional)'],[('reclaim',4)]),
 ('EVT',['EVT 16 entries / 16 queries'],[('evt',1)]),
 ('Rollback Controller',['Rollback controller'],[('rollback',1)]),
 ('Recovery Context Storage',['Context 8 x 80 x 64 (conditional)'],[('context',1)]),
]
seen=[]; modules=[]; counted=[]
for component,names,terms in groups:
    seen+=names;bits=sum(int(lookup[n]['RAM_bits']) for n in names)
    ge=sum(D(lookup[n]['GE_excluding_RAM']) for n in names)
    for name,mult in terms:counted.append((name,mult))
    assert bits==sum(syn[n]['memory_bits']*m for n,m in terms)
    assert ge==sum(D(str(syn[n]['total_ge_excluding_ram']))*m for n,m in terms)
    value=ar(bits,ge)
    assert value==sum(D(lookup[n]['typical_mm2_model']) for n in names)
    assert value==next(D(x['estimated_area_mm2']) for x in prior if x['component']==component)
    row={'component':component,'RAM_bits':bits,'GE_including_DFF_excluding_RAM':str(ge),
         'original_R2_mm2':str(value),'audited_primary_mm2':str(value),
         'applied_reuse_credit_mm2':'0','storage_R2_mm2':str(D(bits)*DENS*PACK/M),
         'logic_R2_mm2':str(ge*LOGIC/M),
         'adjustment_reason':'No proven net credit against matched PEEK; retain R2 resource assumptions',
         'evidence':'; '.join(f'r2-20261113/results/synthesis/seq32/{n}/result.json x{m}' for n,m in terms)}
    for rho in ['0.127','0.20','0.30','0.40']:
        row[f'density_{rho}_packing_1.25_mm2']=str(ar(bits,ge,D(rho),PACK))
        row[f'effective_density_{rho}_no_extra_packing_mm2']=str(ar(bits,ge,D(rho),D(1)))
    modules.append(row)
assert len(set(seen))==len(seen)==len(raw)
assert len(set(n for n,m in counted))==len(counted)
bits=sum(x['RAM_bits'] for x in modules);ge=sum(D(x['GE_including_DFF_excluding_RAM']) for x in modules)
total=sum(D(x['audited_primary_mm2']) for x in modules)
assert (bits,ge,total)==(818176,D('113338.5'),D('.48842495'))
for row in modules:row['share_of_primary_pct']=str(D(row['audited_primary_mm2'])/total*100)
csvout('results/hardware_area_breakdown.csv',modules)

sensitivity=[]
for rho in ['0.127','0.20','0.30','0.40']:
    for packing in [PACK,D(1)]:
        area=ar(bits,ge,D(rho),packing)
        sensitivity.append({'input_unit_area_um2_per_bit':rho,'extra_factor':str(packing),
          'effective_unit_area_um2_per_bit':str(D(rho)*packing),
          'RAM_mm2':str(D(bits)*D(rho)*packing/M),'logic_mm2':str(ge*LOGIC/M),
          'total_mm2':str(area),'division_by_5p04_REFERENCE_ONLY_pct':str(area/REF*100),
          'reduction_from_R2_mm2':str(total-area),
          'meaning':'THEORETICAL_BITCELL_REFERENCE_NOT_MACRO' if rho=='0.127' else
                    'ASSUMED_DENSITY_PLUS_25_PERCENT' if packing==PACK else
                    'ASSUMED_EFFECTIVE_MACRO_DENSITY_NO_SECOND_FACTOR',
          'measured_28nm_macro':False,'strict_matched_overhead_pct':None})
csvout('results/sram_sensitivity.csv',sensitivity)

# Structural reuse can be discussed for already protected frozen EC, not credited
# to a PEEK comparison: source presence does not establish old/new mapped area.
potential_bits=16896*(32+1)
assert potential_bits==557568
reuse_storage_proxy=D(potential_bits)*DENS*PACK/M
sw_proxy=D(str(syn['sw']['total_ge_excluding_ram']))*LOGIC/M
reuse_model=total-reuse_storage_proxy-sw_proxy
models=[
 {'model':'Original R2 Typical','area_mm2':str(total),'reference_only_pct':str(total/REF*100),
  'strict_matched_pct':None,'adjustment_mm2':'0','status':'REPRODUCED_ANALYTICAL_BUDGET'},
 {'model':'R3 primary after accounting audit','area_mm2':str(total),'reference_only_pct':str(total/REF*100),
  'strict_matched_pct':None,'adjustment_mm2':'0','status':'NO_SUPPORTED_PEEK_REUSE_OR_MACRO_RECALIBRATION_CREDIT'},
 {'model':'0.40 interpreted as already effective macro density','area_mm2':str(ar(bits,ge,D('.4'),D(1))),
  'reference_only_pct':str(ar(bits,ge,D('.4'),D(1))/REF*100),'strict_matched_pct':None,
  'adjustment_mm2':str(total-ar(bits,ge,D('.4'),D(1))),
  'status':'CONDITIONAL_SEMANTIC_SENSITIVITY_NOT_CALIBRATION'},
 {'model':'Frozen EC extension: reuse Seq32 + receipt1 + existing SW','area_mm2':str(reuse_model),
  'reference_only_pct':None,'strict_matched_pct':None,'adjustment_mm2':str(total-reuse_model),
  'status':'STRUCTURAL_OVERLAP_PROXY_ONLY_DIFFERENT_BASELINE_NOT_APPLIED_TO_PEEK'}]
csvout('results/model_comparison.csv',models)

local_core=ar(23552,D('1347')) + ar(0,D(str(syn['preserve']['total_ge_excluding_ram']))) + ar(0,D(str(syn['visibility']['total_ge_excluding_ram']))) + ar(0,D(str(syn['reclaim']['total_ge_excluding_ram']))*4)+sw_proxy
shared=ar(0,D(str(syn['evt']['total_ge_excluding_ram'])))+ar(0,D(str(syn['rollback']['total_ge_excluding_ram'])))+ar(40960,D(str(syn['context']['total_ge_excluding_ram'])))
l2=ar(753664,D('9933'))+ar(0,D(str(syn['preserve']['total_ge_excluding_ram'])))+ar(0,D(str(syn['visibility']['total_ge_excluding_ram'])))
assert local_core+shared+l2==total
boundaries=[
 {'scope':'Core-local modeled subtotal','area_mm2':str(local_core),'reference_denominator_mm2':str(REF),
  'division_REFERENCE_ONLY_pct':str(local_core/REF*100),'strict_matched_pct':None,
  'meaning':'L1 group + one preserve + one visibility + checker reclaim + SW; central/shared excluded'},
 {'scope':'Shared recovery subsystem modeled subtotal','area_mm2':str(shared),'reference_denominator_mm2':None,
  'division_REFERENCE_ONLY_pct':None,'strict_matched_pct':None,'meaning':'EVT + rollback + context, placement and attribution not proven'},
 {'scope':'Core-attributed model if all central recovery charged to cores','area_mm2':str(local_core+shared),
  'reference_denominator_mm2':str(REF),'division_REFERENCE_ONLY_pct':str((local_core+shared)/REF*100),
  'strict_matched_pct':None,'meaning':'Accounting alternative, not measured core-only overhead or an uncertainty bound'},
 {'scope':'L2 and one lower-level preserve/visibility','area_mm2':str(l2),'reference_denominator_mm2':None,
  'division_REFERENCE_ONLY_pct':None,'strict_matched_pct':None,'meaning':'Exclude from core-only numerator'},
 {'scope':'Full SoC','area_mm2':None,'reference_denominator_mm2':None,'division_REFERENCE_ONLY_pct':None,
  'strict_matched_pct':None,'meaning':'Matched PEEK L2/macro/interconnect and PAL net area unavailable'},
 {'scope':'Incremental Hardware PAL minus matched PEEK','area_mm2':None,'reference_denominator_mm2':None,
  'division_REFERENCE_ONLY_pct':None,'strict_matched_pct':None,'meaning':'Missing same-boundary replaced/reused area; modeled budget remains '+str(total)}]
csvout('results/normalization_boundaries.csv',boundaries)

fields=[
 ('Seq',32,'Producing segment and SW comparison; required with Epoch for reused execution histories',
  'Frozen GH_PACKET_SEQ_BITS32 and CacheImageKey.contentSeq32','Potential single-storage reuse, not an additional copy; PEEK ownership not established',
  f'rtl/palimpsest.sv:9; {F.relative_to(B)}/rocket-chip/src/main/scala/tilelink/CacheImage.scala:16'),
 ('Recovery Epoch',4,'Distinguish surviving and discarded histories with reused Seq',
  '4 is prototype assumption, not frozen session/slot epoch16','Cannot merge with slot/session epoch without semantics proof',
  'rtl/palimpsest.sv:29; revisions/r2-20261113/config/design_assumptions.json'),
 ('Current Generation',8,'Invalidate old Current mappings lazily across rollback',
  '8 is prototype assumption, not image writer generation32','Cannot substitute CacheImageKey.generation; different update lifetimes',
  'rtl/palimpsest.sv:75; frozen dcache.scala:718'),
 ('Current flag',1,'Distinguish ongoing Current from historical ways with equal address',
  '1 proposed bit','Coherence-valid does not encode Current; derived encoding would change model/control',
  'rtl/palimpsest.sv:79; frozen Directory.scala:35'),
 ('Preserved receipt',1,'Exact-key predecessor retained elsewhere before reuse',
  '1 proposed bit; frozen outerPreserved/lowerPreserved have related semantics','Existing receipt is a reuse candidate; dirty/safe status cannot replace it',
  f'{F.relative_to(B)}/sifive-cache/design/craft/inclusivecache/src/Directory.scala:40'),
]
csvout('results/metadata_fields.csv',[{'field':a,'bits_per_line':b,'purpose':c,'width_evidence':d,
 'reuse_or_reduction_assessment':e,'evidence':q,'applied_reduction_bits':0} for a,b,c,d,e,q in fields])

ledger=[
 ('Native cores, ordinary Cache data/tag/coherence, shared interconnect','REUSED_COMMON','Not charged in R2 increment','No duplication found',None,'check/source/.../Directory.scala:27; palimpsest.sv:17'),
 ('L1/L2 Seq32','POTENTIALLY_DUPLICATED_IF_ADDED_TO_FROZEN_EC','Present once in modeled46-bit sidecar','Frozen image.contentSeq already exists; keep one copy, but not proof PEEK owns it','Candidate part of 557568 overlap bits','CacheImage.scala:12; Directory.scala:38; dcache.scala:734'),
 ('Recovery Epoch4 and CurGen8 and Cur1','NEW_DESIGN_RESOURCE','13 bits per modeled cache line','No demonstrated semantically equivalent frozen fields',None,'palimpsest.sv:29,75; CacheImage.scala:12'),
 ('Preserve receipt1 per line','REUSE_OR_MODIFY','Charged once in46-bit sidecar','Existing frozen exact-key receipt; do not stack both','Candidate part of 557568 overlap bits','Directory.scala:42; dcache.scala:736'),
 ('L1/L2 selection/store logic','NEW_OR_REPLACES_CONTROL','1347 and9933 GE including sidecar wrapper','Appears once; subtract old controller only with actual evidence',None,'R2 results/synthesis/seq32/*/result.json'),
 ('SW bitmap','REUSE_OR_MODIFY','1168 GE prototype charged in R2','Frozen bitmap256 exists; WINDOW16 recovery behavior is different','0.0008176 proxy only; not applied to PEEK','dcache.scala:737,1745; palimpsest.sv:285'),
 ('Version preservation and visibility controllers','MODIFY_OR_REPLACE','Two instances each in R2','Existing frozen contracts overlap; keep actual old/new differential unknown',None,'dcache.scala:26; CacheImage.scala:25; palimpsest.sv:107,159'),
 ('PEEK snapshot capture/checker CPS/ECP and LSL data','REUSED_COMMON','No second payload in R2 increment','8 retained contexts are distinct lifetime, not duplicate free checkpoint slots',None,'R_RSU.scala:60; R_RSUSL.scala:81; R_LSL.scala:63'),
 ('Recovery context pool','NEW_CONDITIONAL','40960 RAM +4034.5 GE','8x80x64 sizing assumption retained; no unsupported capacity cut',None,'palimpsest.sv:357'),
 ('LSL reclaim descriptors','NEW_CONDITIONAL_OR_REDUNDANT','22162 GE','FIFO already consumes; evidence does not prove whole new block can be deleted',None,'R_LSL.scala:119; palimpsest.sv:219'),
 ('EVT and rollback controller','NEW_DESIGN_RESOURCE','70647 and499 GE','Register/logic counted as GE, not SRAM bits',None,'palimpsest.sv:29,317'),
 ('Frozen SVB data/key and existing wide image/slot state','EXISTING_EC_NOT_PEEK','Not included as independent extra block in R2','Not a valid PEEK credit; may be omitted actual PAL resource if retained',None,'speculative-version-buffer.scala:15,107; CacheImage.scala:12'),
 ('SRAM macro internal periphery/packing','ASSUMED_NOT_MEASURED','25 percent uplift applied once','Could overlap if0.40 was already full effective macro density; no such source established',None,'config/scenarios.json:14,17'),
 ('Copy/data adapters and arbitration etc','OMITTED_FROM_PRIMITIVE_MODEL','No area charged','Recognize estimation uncertainty only; no implementation work this round',None,'R2 reports/rtl_coverage.md'),
]
csvout('results/resource_ledger.csv',[{'resource':a,'classification':b,'R2_treatment':c,'audit_conclusion':d,
 'possible_credit_not_applied':e,'evidence':q} for a,b,c,d,e,q in ledger])

citations=[
 ('metadata bit layout and reuse of ordinary cache state',AREA/'rtl/palimpsest.sv',8),
 ('frozen packet sequence width',F/'rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala',20),
 ('frozen exact image key semantics',F/'rocket-chip/src/main/scala/tilelink/CacheImage.scala',12),
 ('frozen L2 tag/coherence and added image/receipt',F/'sifive-cache/design/craft/inclusivecache/src/Directory.scala',28),
 ('old ordinary L2 directory',B/'check/source/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala',27),
 ('frozen L1 image/slot identity',F/'boom/src/main/scala/lsu/dcache.scala',713),
 ('frozen SW and bitmap',F/'boom/src/main/scala/lsu/dcache.scala',1738),
 ('frozen SVB depth and data storage',F/'boom/src/main/scala/lsu/speculative-version-buffer.scala',15),
 ('frozen SVB data storage',F/'boom/src/main/scala/lsu/speculative-version-buffer.scala',107),
 ('PEEK existing main checkpoint',B/'check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala',60),
 ('PEEK existing checker checkpoints',B/'check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala',81),
 ('PEEK LSL payload',B/'check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala',63),
 ('PEEK input consumption',B/'check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala',119),
 ('uncharacterized physical assumptions',AREA/'config/scenarios.json',14),
 ('PEEK/MEEK paper table',AREA/'evidence/Micro26_PEEK.txt',869),
 ('ASAP7 dummy memories not usable as 28nm area evidence',B/'firesim/conda-env/lib/python3.10/site-packages/hammer/technology/asap7/README.md',29),
]
csvout('evidence/source_index.csv',[{'claim':c,'path':str(p),'line':n} for c,p,n in citations])

save('results/calculation.json',{'original_and_audited_primary_mm2':str(total),'RAM_bits':bits,
 'GE':str(ge),'RAM_mm2':str(D(bits)*DENS*PACK/M),'logic_mm2':str(ge*LOGIC/M),
 'RAM_share_pct':str(D(bits)*DENS*PACK/M/total*100),'applied_matched_PEEK_reuse_credit_mm2':'0',
 'reference_percentage_points':{'RAM':str(D(bits)*DENS*PACK/M/REF*100),'generic_logic':str(ge*LOGIC/M/REF*100)},
 'reference_only_pct':str(total/REF*100),'strict_core_full_soc_and_matched_increment_pct':None,
 'packing_uplift_mm2':str(D(bits)*DENS*(PACK-1)/M),
 'packing_uplift_ref_percentage_points':str(D(bits)*DENS*(PACK-1)/M/REF*100),
 'conditional_frozen_extension':{'overlapping_seq_and_receipt_bits':potential_bits,
 'storage_proxy_credit_mm2':str(reuse_storage_proxy),'SW_prototype_proxy_mm2':str(sw_proxy),
 'remaining_model_mm2':str(reuse_model),'is_PAL_minus_PEEK':False,
 'status':'NOT_APPLIED_STRUCTURAL_SENSITIVITY_NO_NEW_MAPPING'},
 'evidence':'Existing R2 generic counts, no 28nm mapped cells/macros',
 'scope':'Audit/calculation only; no RTL changes or synthesis/simulation'})

# Two interpretations kept separate: no fabricated macro calibration.
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':8,'pdf.fonttype':42,'svg.fonttype':'none'})
fig,ax=plt.subplots(figsize=(6.4,3.7))
x=[.127,.2,.3,.4]
for factor,label,color,style in [(D('1.25'),'Input density × 1.25 (R2 convention)','#235c7d','-'),
                                (D(1),'Effective macro density; no extra factor','#b36b24','--')]:
    y=[float(ar(bits,ge,D(str(z)),factor)) for z in x]
    ax.plot(x[1:],y[1:],style,marker='o',label=label,color=color,linewidth=1.7)
    ax.plot(x[:2],y[:2],':',color=color,linewidth=1.3)
    ax.scatter(x[0],y[0],facecolors='white',edgecolors=color,marker='D',s=36,zorder=4)
ax.annotate('R2: 0.4884 mm²',(.4,float(total)),xytext=(-8,9),textcoords='offset points',ha='right',fontsize=8)
ax.axhline(float(ge*LOGIC/M),color='#777777',linestyle=':',linewidth=.9)
ax.text(.14,float(ge*LOGIC/M)+.009,'Fixed generic-logic model: 0.07934 mm²',fontsize=7,color='#555555')
ax.axvspan(.115,.15,color='#eeeeee',alpha=.8)
ax.set_xlim(.115,.417);ax.set_ylim(.06,.545)
ax.set_xticks(x,['0.127†','0.20','0.30','0.40'])
ax.set_xlabel('Assumed SRAM unit area (µm²/bit)')
ax.set_ylabel('Modeled additional area (mm²)')
ax.grid(axis='y',alpha=.25);ax.spines[['top','right']].set_visible(False)
ax.legend(loc='upper left',fontsize=7)
fig.text(.5,.025,'† Bitcell-only theoretical reference; not a measured complete SRAM macro. All points are analytical.',ha='center',fontsize=7)
fig.tight_layout(rect=(0,.065,1,1))
for ext in ['pdf','svg','png']:fig.savefig(R/f'figures/sram_sensitivity.{ext}',dpi=220)
plt.close(fig)

md=['# PALIMPSEST Hardware Overheads：R3 面积口径审计','',
'**主结论：0.48842495 mm²及9.69097%的算术无误；没有证据支持将其改成一个更低的已校准点估计。** '
'9.69%是“含L2的条件原语预算 / PEEK论文核面积参考和”，不能称统一边界的面积开销。'
'R3保留原预算，修正解释并给出密度敏感性；没有以降低百分比为目标。','',
'## 1. 输入、范围与证据级别','',
f'已读取 {href(R2/"reports/area_audit.md")}、{href(R2/"reports/rtl_coverage.md")}、'
f'{href(R2/"dac_hardware_overheads/hardware_area_breakdown.csv")}。'
'固定L2 1MiB/16-way、Seq32、Main L1D32KiB/2-way、line64B；其余Epoch4/CurGen8、context8、EVT16×16query等均沿用R2假设，不能称全部来自冻结配置。'
'本轮没有修改RTL、没有综合/功能测试/PARSEC、没有操作U280/FireSim任务。','',
'现有generic综合提供逻辑计数和抽象RAM位数；mm²依赖假设换算。PEEK论文3.96/0.27来自其TSMC28nm综合报告的论文数值，'
'不是项目当前网表实测。未找到适用28nm SRAM macro/Memory Compiler面积资料。','',
'## 2. 46bit/line审核','',
'| 字段 | 位数 | 必要语义 / 复用判断 |','|---|---:|---|']
for a,b,c,d,e,q in fields:md.append(f'| {a} | {b} | {c}；{e} |')
md += ['',
f'来源：原型 {href(AREA/"rtl/palimpsest.sv",8)}、:29、:75；冻结 '
f'{f("rocket-chip/src/main/scala/tilelink/CacheImage.scala",12)}；'
f'{f("sifive-cache/design/craft/inclusivecache/src/Directory.scala",28)}。'
'Seq32有冻结依据；恢复Epoch4、CurrentGeneration8是设计假设。slotEpoch16、会话epoch、image generation32的更新事件不同，不能据名字相似合并。'
'Cur不是coherence-valid；preserved不是dirty或Seq≤SW：后者分别描述权限/脏状态和验证安全，不证明对应历史数据已经在其他位置保存。','',
'普通Tag/dirty/state/clients已在Cache基线，46位没有再包含它们；冻结image.valid/writer/generation等也没有在原预算逐项额外加入。'
'模型更像一种缩减身份的设计方案，而非冻结实现所有字段的完整清单。当前所有“可复用”判断仅防止再叠加一份，不证明这份字段本来属于PEEK。','',
'每way配置完整字段是当前dense sidecar结构：L2`1024sets×16ways×46=753664bit`，L1D`512×46=23552bit`。'
'invalid/safe状态下不用某些值，只能降低活动率，不能减少已分配SRAM。对于任一时刻任意way可含版本的设计，没有占用上界就不能按平均speculative比例删位。'
'字典编码、per-segment共享、稀疏记录或状态复用需要指针/epoch/valid/map/溢出处理，当前无此实现或面积证据，因此不计压缩收益。'
'EVT已将历史区间集中存储，每行仍需索引；GlobalCurGen是全局比较值，每行generation是版本标签，二者不属于重复记录。','',
'## 3. L2计费无重复，0.3837851的展开','',
'`L2 = 753664×0.40×1.25/1e6 + (912+8615+406)×0.70/1e6`','',
'| 项目 | mm² | 依据 |','|---|---:|---|',
f'| 元数据RAM | 0.3768320 | {href(R2/"results/synthesis/seq32/l2_metadata/result.json",21)} |',
f'| metadata wrapper，912GE | 0.0006384 | 同result:11 |',
f'| version selector，8615GE | 0.0060305 | {href(R2/"results/synthesis/seq32/selector_l2/result.json",22)} |',
f'| store policy，406GE | 0.0002842 | {href(R2/"results/synthesis/seq32/store_l2/result.json",22)} |',
'| **合计** | **0.3837851** | RAM一次，三个逻辑形态各一次 |','',
'selector/store未作为另一个模块行再次计费。EVT在独立行负责history-valid，selector消费其结果并选winner，并不是同一逻辑。'
'Wrapper mask gates与未来macro端口外围有潜在边界重叠，但没有选定宏，不能直接扣掉912GE或任何外围金额。','',
'## 4. SRAM单位面积与packing','',
'项目搜索包含ignored/hidden候选文件；详见 '+href(R/'evidence/macro-asset-search.json')+'。'
'发现ASAP7和Sky130资产，未发现适用28nm宏面积标定。ASAP7自带SRAM甚至明确是blank dummy且4×缩放：'+
href(B/'firesim/conda-env/lib/python3.10/site-packages/hammer/technology/asap7/README.md',29)+'；'
'不能从这些LEF尺寸推导28nm密度，也没有运行任何compiler。搜索不代表检查了项目外/未挂载的PDK。','',
'Bitcell area仅为存储单元；完整macro还含译码、sense amp、write driver、mux、控制、冗余/repair等。'
'已知macro时应直接用macro边界面积（LEF宽×高或compiler area）及实际实例数，外围不能再加一遍。'
'standard-cell/FF array则应按实际映射cell及端口逻辑计费，不能套SRAM bitcell单价。','',
f'原始 {href(AREA/"config/scenarios.json",14)} 只给0.40和packing1.25，没有说明0.40的物理来源、外围是否已含，或1.25如何分摊。'
'R2未另加periphery金额，也未加旧15%interface margin，因此**没有已证实的外围重复收费**；但0.40若本来代表完整macro有效单位面积，1.25就会构成第二次加成。'
'不能把这个“若”当成事实，故并列两种解释：','',
'- R2解释：`A(rho)=0.07933695+818176×rho×1.25/1e6`；1.25为一次性未标定的packing/外围余量，不再另加外围。',
'- 已含外围的有效密度解释：`A(rho_eff)=0.07933695+0.818176×rho_eff`；不再乘1.25。',
'- 0.127仅为用户指定理论bitcell参考，未作独立工艺验证；即使乘1.25也不证明足以组成真实macro。0.20/0.30/0.40同样只是敏感性点。','',
'| 输入μm²/bit | 再乘1.25：mm² | ÷5.04参考% | 已含外围不再乘：mm² | ÷5.04参考% |',
'|---|---:|---:|---:|---:|']
for rho in ['0.127','0.20','0.30','0.40']:
    a=ar(bits,ge,D(rho),PACK);b=ar(bits,ge,D(rho),D(1))
    md.append(f'| {rho}'+('（仅理论）' if rho=='0.127' else '')+f' | {a:.8f} | {a/REF*100:.2f} | {b:.8f} | {b/REF*100:.2f} |')
md += ['',f'![SRAM sensitivity]({R}/figures/sram_sensitivity.png)','',
'**83.7566%的原预算是RAM面积假设**（0.409088mm²），其余16.2434%是generic逻辑换算（0.07933695mm²）；'
'换算成原5.04分母分别贡献8.1168和1.5741个百分点，均不是已测量的真实净增量。这不是“83.76%被高估”。若0.40已经是完整macro密度，取消额外1.25会减少0.0818176mm²、'
'即旧参考归一化的1.6234个百分点，预算变为0.40660735mm²/8.0676%；当前没有证据确认应作此扣减。','',
'## 5. 资源复用和净增量','',
'新增/复用/替换/潜在重复/遗漏完整清单：'+href(R/'results/resource_ledger.csv')+'。'
'PEEK checkpoint、LSL payload、普通Cache/Tag均未在原增量重复收费。'
'冻结EC的SW256、SVB、contentSeq32、receipt已存在，禁止在它们上面重复叠加同义资源；'
'但冻结EC本身已经包含PAL/EC机制，不能把这些都划给PEEK然后作为PAL−PEEK减项。','',
'可量化的**结构重叠参考**：若只是给冻结EC新增恢复标记，并证明复用原contentSeq32和exact-key receipt1，'
f'则16,896行的33位共557,568bit不用再分配，按原密度的代理金额为{reuse_storage_proxy}mm²；'
f'再不增加一份SW原型，少{sw_proxy}mm²，剩余{reuse_model}mm²。'
'该数字保留原所有其他逻辑计数，不是重新综合后面积；它依赖身份/receipt接口能够共享，'
'更换了比较基线，**不是PAL−PEEK、不是可以报告的4%左右开销，未应用到主结果**。'
'Epoch/CurGen等未删，LSL描述符整块也没有因“看起来可能不需要”而扣除。'
'被替换控制逻辑面积没有同配置cell/macro证据，因此主模型的已应用复用/替换扣减为0。','',
'## 6. Core-only / Full SoC / Incremental 三种口径','',
f'PEEK论文 {href(AREA/"evidence/Micro26_PEEK.txt",869)} 给出3.96、0.27，和为5.04mm²；'
'MEEK参考3.89+4×0.26=4.93mm²，所以(5.04−4.93)/4.93=2.2312%。'
'这是两个论文核心实现的对比，不是约束PAL估计上限，不能把2.23%与9.69%直接相加、相减或类比其系统边界。','',
'| 统计边界 | 本模型可算量 | 参考除法 | 严格统一配置/工艺开销 |',
'|---|---|---|---|',
f'| Core-local | L1组、1个preserve、1个visibility、4个reclaim、SW：{local_core:.8f}mm² | {local_core/REF*100:.4f}% | 未知；PEEK具体macro边界及相同网表无证据 |',
f'| Core-attributed，若全把中央恢复归核 | 再加EVT/context/rollback，合计{local_core+shared:.8f}mm² | {(local_core+shared)/REF*100:.4f}% | 仅分摊方案，不是实际core-only结果 |',
f'| L2相关预算 | L2组+下层preserve/visibility：{l2:.8f}mm² | 不除核心面积 | 不属于core-only分子 |',
'| Full SoC | 共同L1/L2 Data/Tag、macro、互连、控制+各自保护 | 无可用分母 | **无法计算** |',
'| Incremental Hardware | 相同配置PAL新/改逻辑−PEEK被替换逻辑，已有只计一次 | 无完整同边界P及净差值 | **无法计算** |','',
f'中央EVT/context/rollback小计{shared:.8f}mm²，分摊未由真实集成hierarchy确定。两个core参考数不是误差上下界。'
'无论选哪个分摊，9.69%都不是core-only，因其分子仍含L2。'
'如果未来确认5.04完全不含L2且为相同配置，Full SoC公式才可写Δ/(5.04+L2+interconnect+other)；'
'当前连L1/macro包含范围也不完全确定，不填造一个L2数字。R3所有严格百分比字段均留空。','',
'## 7. 修订模块明细和建议值','',
'| 模块 | R2 / R3主预算mm² | 占主预算% | 已证明可扣的PEEK重叠 |',
'|---|---:|---:|---:|']
for row in modules:md.append(f'| {row["component"]} | {D(row["audited_primary_mm2"]):.8f} | {D(row["share_of_primary_pct"]):.2f} | 0 |')
md += ['| **合计** | **0.48842495** | **100.00** | **0** |','',
'0表示没有可依据同配置PEEK边界应用的扣减，不表示没有复用可能。CSV包含每模块两种密度解释的全部敏感性列。'
'原0.4884不是计量单位算错，也不是已证明metadata重复，而是高度依赖SRAM假设且参照边界不统一。','',
'**证据允许的建议：保留0.4884mm²作为未校准的条件设计预算；在原packing解释下，0.20–0.40敏感性为0.2839–0.4884mm²。** '
'若密度参数被定义为已含外围的完整macro有效密度，对应0.2430–0.4066mm²。'
'这两组不是可信区间，不能以0.30中点或最低值替换“Typical”声称更准确。'
'尚不能将9.69%的某几个百分点认定为真实过高；可以确定的只有该数的公式组成、潜在25%RAM加成效应以及分子分母不一致。','',
'## 8. 可写论文的证据区分','',
'- **已有证据**：R2独立generic资源计数、冻结源码/生成物字段、RAM位数、原预算算术；PEEK论文报告其28nm核心面积。',
'- **分析假设**：所有PAL mm²、SRAM单位面积及packing、NAND2 GE单价、dense46-bit设计和context/EVT/descriptor规模、本文结构复用代理值。',
'- **没有证据**：PAL/PEEK同配置28nm映射面积、适用SRAM macro面积与外围分解、实际替换cell节省、严格core-only或FullSoC净开销。',
'',f'更新LaTeX：{href(R/"latex/hardware_overheads.tex")}；表：{href(R/"latex/area_models.tex")}。'
'本轮仅修订估算表述，没有开展新的硬件工作。','']
(R/'reports/area_reaudit.md').write_text('\n'.join(md))

tex=r'''\noindent\textbf{Hardware Overheads.}
For the 1\,MiB, 16-way L2 configuration with 32-bit sequence numbers,
our conditional analytical budget is 0.4884\,mm$^2$: 0.4091\,mm$^2$ for
818,176 abstract SRAM bits and 0.0793\,mm$^2$ for generic logic.
The model assumes 0.40\,$\mu$m$^2$/bit, a 1.25 packing factor, and
0.70\,$\mu$m$^2$/GE. The accounting audit found no duplicate charge for
ordinary tags/coherence state or version-selection/store-control logic.
No applicable characterized 28\,nm SRAM macro data were available.
With the factor retained, densities of 0.20--0.40\,$\mu$m$^2$/bit give
0.2839--0.4884\,mm$^2$; if density already includes macro periphery,
omitting the factor gives 0.2430--0.4066\,mm$^2$.
These are sensitivity scenarios, not measured bounds; 0.127\,$\mu$m$^2$/bit
is only a theoretical bitcell reference.
The original 9.69\% ratio divides the L2-inclusive budget by PEEK's
5.04\,mm$^2$ reference core-area sum, whose shared-cache boundary is
unspecified, and is therefore not a matched core-only or full-SoC overhead.
Existing frozen-EC sequence fields, receipts, and SW logic are reuse
candidates, but do not establish a net credit against PEEK.
The available data do not support a strict matched PALIMPSEST--PEEK percentage.
'''
(R/'latex/hardware_overheads.tex').write_text(tex)
table=[r'% Requires booktabs.',r'\begin{table}[t]',r'\centering\small',
 r'\caption{Analytical SRAM area sensitivity; the 1.25 factor is applied only in the middle column.}',
 r'\label{tab:palimpsest-area-sensitivity}',r'\begin{tabular}{rrr}',r'\toprule',
 r'Unit area & Density $\times1.25$ & Effective macro density \\',
 r'($\mu$m$^2$/bit) & (mm$^2$) & (mm$^2$; no extra factor) \\',r'\midrule']
for rho in ['0.127','0.20','0.30','0.40']:
    label=rho+(r'$^{\dagger}$' if rho=='0.127' else '')
    table.append(f'{label} & {ar(bits,ge,D(rho),PACK):.4f} & {ar(bits,ge,D(rho),D(1)):.4f} '+r'\\')
table += [r'\bottomrule',r'\end{tabular}',r'\par\footnotesize $\dagger$ Theoretical bitcell reference only; not a measured macro.',r'\end{table}','']
(R/'latex/area_models.tex').write_text('\n'.join(table))
brief=f'''# R3 Hardware Overheads 面积复审

主审计：[area_reaudit.md]({R}/reports/area_reaudit.md)。固定冻结几何，只读审计和计算，未修改RTL/综合/测试/PARSEC。

- 主模型保持 **0.48842495mm²**，已证实可对PEEK净扣减的金额为0；9.69%是边界不一致的参考除法，严格百分比未知。
- 原packing解释，密度0.20–0.40：**0.28388095–0.48842495mm²**；若输入已是完整macro有效密度则为**0.24297215–0.40660735mm²**。均为假设敏感性，没有校准后的新Typical。
- 发现ASAP7 dummy及Sky130资产，未找到适用28nm SRAM宏标定；0.127只作理论参考。

产物：

- [模块CSV]({R}/results/hardware_area_breakdown.csv)；[模型对比]({R}/results/model_comparison.csv)；[密度CSV]({R}/results/sram_sensitivity.csv)。
- [面积边界CSV]({R}/results/normalization_boundaries.csv)；[新增/复用/替换清单]({R}/results/resource_ledger.csv)；[字段审计]({R}/results/metadata_fields.csv)。
- [敏感性图PDF]({R}/figures/sram_sensitivity.pdf)（同目录SVG/PNG）。
- [DAC英文LaTeX]({R}/latex/hardware_overheads.tex)；[敏感性LaTeX表]({R}/latex/area_models.tex)。
- [计算依据]({R}/results/calculation.json)；[搜索记录]({R}/evidence/macro-asset-search.json)；[保全与算术检查]({R}/results/verification.json)。

复算：`python3 scripts/audit_area.py`，仅读取R2计数和写本目录，不调用硬件工具。
'''
(R/'README.md').write_text(brief)

inputs=[R2/'reports/area_audit.md',R2/'reports/rtl_coverage.md',R2/'results/module_area.csv',
R2/'results/synthesis/seq32/summary.json',R2/'dac_hardware_overheads/hardware_area_breakdown.csv',AREA/'rtl/palimpsest.sv',
AREA/'config/scenarios.json',AREA/'evidence/Micro26_PEEK.txt',
F/'rocket-chip/src/main/scala/tilelink/CacheImage.scala',
F/'sifive-cache/design/craft/inclusivecache/src/Directory.scala',F/'boom/src/main/scala/lsu/dcache.scala',
B/'firesim/conda-env/lib/python3.10/site-packages/hammer/technology/asap7/README.md']
save('evidence/input-sha256.json',{str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs})
previous=json.loads((R/'evidence/r2-before-sha256.json').read_text())
changed=[p for p,h in previous.items() if hashlib.sha256((B/p).read_bytes()).hexdigest()!=h]
assert not changed,changed
save('results/verification.json',{'status':'PASS','R2_files_preserved':len(previous),'changed_R2_files':changed,
 'arithmetic_reproduced_exactly':str(total),'unique_original_module_rows':len(seen),
 'unique_synthesis_shapes_counted':len(counted),'new_synthesis_or_simulation':False,
 'PDK_calibrated_area':False,'strict_matched_percentage_available':False})
print(json.dumps({'primary_mm2':str(total),'core_local_model_mm2':str(local_core),
 'shared_recovery_model_mm2':str(shared),'L2_model_mm2':str(l2),
 'frozen_overlap_proxy_only_mm2':str(reuse_model),'R2_unchanged_files':len(previous)},indent=2))
