#!/usr/bin/env python3
"""Render the configuration bound to the latest certified EC bitstream.

Read-only inputs; this script writes only its own report directory.
"""
from pathlib import Path
import csv
import hashlib
import json
import shutil
import textwrap

OUT = Path(__file__).resolve().parent
BASE = OUT.parent / 'roi-retirement-checker-repair-20261117'
SRC = Path('/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-roi-retirement-repair-20261117/chipyard')
RUNTIME = Path('/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-roi-retirement-checker-74810f4-r1')
evidence = OUT / 'evidence'
evidence.mkdir(exist_ok=True)
inputs = {
    'parameters.json': BASE / 'generation/parameters.json',
    'certified-build.json': RUNTIME / 'certified-build.json',
    'clock-contract.txt': BASE / 'physical-r1/implementation/clock-contract.txt',
    'target-clocks.txt': BASE / 'generation/elaborate/firesim.firesim.FireSim.firesimBuildTopClockGenerator.freq-summary',
    'runtime-manifest.json': BASE / 'fpga21-validation/health/manifest.json',
    'config-mixins.scala': SRC / 'generators/boom/src/main/scala/common/config-mixins.scala',
    'tage.scala': SRC / 'generators/boom/src/main/scala/ifu/bpd/tage.scala',
    'btb.scala': SRC / 'generators/boom/src/main/scala/ifu/bpd/btb.scala',
    'R_LSL.scala': SRC / 'generators/rocket-chip/src/main/scala/r/R_LSL.scala',
    'RocketCore.scala': SRC / 'generators/rocket-chip/src/main/scala/rocket/RocketCore.scala',
    'GH_GlobalParams.scala': SRC / 'generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala',
    'L2Parameters.scala': SRC / 'generators/sifive-cache/design/craft/inclusivecache/src/Parameters.scala',
}
manifest = []
for name, source in inputs.items():
    dest = evidence / name
    shutil.copy2(source, dest)
    manifest.append({'source': str(source), 'snapshot': str(dest.relative_to(OUT)),
                     'sha256': hashlib.sha256(dest.read_bytes()).hexdigest()})
params = json.loads((evidence / 'parameters.json').read_text())
cert = json.loads((evidence / 'certified-build.json').read_text())
run = json.loads((evidence / 'runtime-manifest.json').read_text())
assert cert['hardware_commit'].startswith('74810f4')
assert run['identity']['hardware_commit'] == cert['hardware_commit']
bit_hash = hashlib.sha256()
with (RUNTIME / 'firesim.bit').open('rb') as f:
    for block in iter(lambda: f.read(1 << 20), b''):
        bit_hash.update(block)
assert bit_hash.hexdigest() == cert['bitstream_sha256']
boom, *checkers = params['tiles']
assert len(checkers) == 4
core = boom['core']
assert core['numRobEntries'] == 42 and core['decodeWidth'] == 3
assert sum(i['numEntries'] for i in core['issueParams']) == 72
for t in checkers:
    for kind in ('icache', 'dcache'):
        assert t[kind]['nSets'] * t[kind]['nWays'] * t[kind]['blockBytes'] == 4096
assert params['inclusive_cache']['sets'] * params['inclusive_cache']['ways'] * 64 == 1048576
assert params['external_memory']['master']['size'] == 16 * (1 << 30)
assert params['memory_model']['params']['maxReads'] == params['memory_model']['params']['maxWrites'] == 16

# Evidence lines refer to the independently archived input files above, except
# FIRRTL instance counts which refer to the build's immutable elaboration file.
fir = str(BASE / 'generation/elaborate/firesim.firesim.FireSim.fir')
rows = [
 ('Big Core', 'Core', '1 x 3-wide OoO SonicBOOM (RV64GC)', 'parameters.json:2; parameters.json:5'),
 ('Big Core', 'Pipeline', '42-entry ROB; 72-entry IQ (32 INT + 16 MEM + 24 FP); 16-entry LDQ and 16-entry STQ', 'parameters.json:7'),
 ('Big Core', 'Registers / execution', '128 INT / 128 FP physical registers; 3 INT execution lanes, 1 MEM lane, 1 FP lane', 'parameters.json:26; '+fir+':445034; '+fir+':336209'),
 ('Big Core', 'Branch prediction', 'TAGE-L + loop/BIM/BTB/micro-BTB; 6 TAGE tables per bank, 2-64-bit histories; 16-entry RAS; BTB: 128 sets x 2 ways per bank', 'config-mixins.scala:491; tage.scala:186; btb.scala:15; parameters.json:56'),
 ('Big Core', 'Target frequency', '200 MHz (model assignment; not a measured FPGA core frequency)', 'target-clocks.txt:2; runtime-manifest.json:68'),
 ('Memory Hierarchy', 'L1 I-Cache', '32 KiB, 8-way, 2-cycle pipeline; one outstanding refill transaction', 'parameters.json:104; '+str(SRC / 'generators/boom/src/main/scala/ifu/icache.scala')+':139'),
 ('Memory Hierarchy', 'L1 D-Cache', '32 KiB, 2-way, 6 MSHRs; fixed end-to-end hit latency not independently established', 'parameters.json:121'),
 ('Memory Hierarchy', 'Shared L2 Cache', '1 MiB, 16-way; 4 MSHRs (2 general + 2 B/C-reserved); memCycles=12 is not hit latency', 'parameters.json:653; L2Parameters.scala:311; '+fir+':56523'),
 ('Memory Hierarchy', 'Cache line', '64 B', 'parameters.json:117; parameters.json:138'),
 ('Memory Hierarchy', 'Target memory', '16 GiB address space; FASED Latency-Bandwidth Pipe (not DDR3-1066 timing)', 'parameters.json:770; runtime-manifest.json:52'),
 ('Memory Hierarchy', 'Runtime memory settings', 'readLatency=30, writeLatency=30 target-model cycles; 4 outstanding reads + 4 writes (hardware ceilings: 16 each)', 'runtime-manifest.json:15; parameters.json:784'),
 ('Little Cores', 'Cores', '4 x in-order Rocket, 5-stage pipeline; 100 MHz target model assignment', 'parameters.json:154; runtime-manifest.json:69'),
 ('Little Cores', 'Arithmetic', 'mulUnroll=8, divUnroll=8; SP/DP FMA latency: 3/4 cycles', 'parameters.json:200; parameters.json:207'),
 ('Little Cores', 'L1 Cache', '4 KiB, 2-way each for I/D; I-cache pipeline: 2 cycles; blocking D-cache (nMSHRs=0)', 'parameters.json:215; parameters.json:232'),
 ('Little Cores', 'LSL / checker', '2 x 255 x 130-bit arrays; 3.98 KiB data payload, 8.09 KiB including address/type (excluding control and CSR/RoCC queues)', 'RocketCore.scala:838; R_LSL.scala:70; '+fir+':615910; '+fir+':616035'),
 ('Little Cores', 'Package instruction limit', '5,000 configured instructions; early seal trigger at 4,955 plus ROB drain (not a cycle timeout)', 'GH_GlobalParams.scala:15; '+str(SRC / 'generators/boom/src/main/scala/exu/core.scala')+':2294'),
 ('FPGA Implementation', 'Platform / profile', 'Alveo U280; EC Performance-Only, revision 74810f4', 'certified-build.json:4'),
 ('FPGA Implementation', 'Physical host clock', '10.004 MHz (99.960 ns); target 2:1 clock relationship represented by FireSim scheduling and multicycle constraints', 'clock-contract.txt:1; target-clocks.txt:2'),
]
with (OUT / 'hardware_configuration.csv').open('w', newline='') as f:
    w = csv.writer(f)
    w.writerow(['section', 'parameter', 'configuration', 'evidence'])
    w.writerows(rows)

notes = [
    'This table describes the latest certified bitstream, not the previously failed 6fada307 build and not full PALIMPSEST.',
    '200/100 MHz are target-model frequency assignments. The routed physical host clock is 10.004 MHz; generated target clocks have the same physical period and the checker domain has a multicycle contract. Do not label the model assignments as measured FPGA frequencies or replace them by 3.2/2 GHz.',
    'L2 memCycles=12 sizes concurrency for an assumed outer round trip. It does not enforce a 12-cycle L2 hit latency. L1D end-to-end response latency also includes EC control and backpressure; no fixed measured value is asserted here.',
    'LSL array capacity is 2*255*130=66,300 bits (8.093 KiB) per checker; data-only payload is 2*255*64/8=4,080 bytes (3.984 KiB). Additional queue/control storage is excluded from these two capacities.',
    '16 GiB is the configured target address space. The current diagnostic Linux launch separately restricts usable memory to 2 GiB (mem=2G). Runtime latency/concurrency settings are not baked into the bitstream. No DDR3 timing model is instantiated.',
]
md = ['# Hardware configuration of the latest certified EC FPGA bitstream', '',
      'Revision: `'+cert['hardware_commit']+'`. Bitstream SHA256: `'+cert['bitstream_sha256']+'`.', '',
      '| Section | Parameter | Configuration | Evidence |', '|---|---|---|---|']
for section, key, value, source in rows:
    md.append('| '+ ' | '.join((section, key, value, source)) + ' |')
md += ['', *['- '+x for x in notes], '',
       'Reproduction: `python3 generate_table.py`. Inputs are read only. The exact bitstream hash is verified. PNG/PDF are rendered with Matplotlib; the LaTeX source is also supplied.']
(OUT / 'README.md').write_text('\n'.join(md)+'\n')

def tex(s):
    for a,b in [ ('\\',r'\textbackslash{}'),('&',r'\&'),('%',r'\%'),('_',r'\_'),('#',r'\#') ]:
        s=s.replace(a,b)
    return s
latex = [r'% Requires array, tabularx; uses the surrounding document font.',
         r'\begin{table}[t]', r'\centering', r'\scriptsize',
         r'\caption{Hardware configuration of the EC Performance-Only FPGA prototype (revision \texttt{74810f4}). Target-model frequencies are distinct from the physical host clock.}',
         r'\label{tab:ec-hardware-config}', r'\setlength{\tabcolsep}{3pt}',
         r'\begin{tabularx}{\columnwidth}{@{}>{\bfseries}p{0.23\columnwidth}X@{}}', r'\hline']
previous = None
for section, key, value, _ in rows:
    if section != previous:
        if previous is not None:latex.append(r'\hline')
        latex.append(r'\multicolumn{2}{c}{\textbf{'+tex(section)+r'}} \\ \hline')
        previous = section
    latex.append(tex(key)+' & '+tex(value)+r' \\')
latex += [r'\hline', r'\end{tabularx}',r'\vspace{2pt}',
          r'\parbox{\columnwidth}{\scriptsize '+tex('Runtime settings are from the diagnostic launch manifest. L2 memCycles is not hit latency; LSL capacities exclude auxiliary queues and control. The target address space is 16 GiB; the diagnostic Linux launch uses mem=2G. This prototype does not establish full-PALIMPSEST validation.')+'}',r'\end{table}']
(OUT / 'hardware_configuration.tex').write_text('\n'.join(latex)+'\n')

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
plt.rcParams.update({'font.family':'DejaVu Serif','pdf.fonttype':42,'ps.fonttype':42})
blocks=[]
last=None
for section,key,value,_ in rows:
    if section != last:
        blocks.append(('section',section,''));last=section
    lines = textwrap.wrap(value,width=69,break_long_words=False,break_on_hyphens=False)
    keylines = textwrap.wrap(key,width=19,break_long_words=False)
    blocks.append(('row','\n'.join(keylines),'\n'.join(lines)))
height = 0.62 + sum(0.29 if t=='section' else 0.13+0.155*max(a.count('\n')+1,b.count('\n')+1) for t,a,b in blocks)+1.00
fig = plt.figure(figsize=(7.6,height))
ax = fig.add_axes([0,0,1,1]);ax.set_xlim(0,7.6);ax.set_ylim(0,height);ax.axis('off')
y=height-0.25
ax.text(3.8,y,'Hardware Configuration of the Latest EC FPGA Bitstream',ha='center',va='top',fontsize=12,fontweight='bold');y-=0.25
ax.text(3.8,y,'EC Performance-Only | 74810f4 | generated 18 November 2026',ha='center',va='top',fontsize=8.5);y-=0.23
for typ,a,b in blocks:
    if typ=='section':
        ax.plot([0.15,7.45],[y,y],color='black',lw=0.8)
        ax.text(3.8,y-0.14,a,ha='center',va='center',fontsize=10,fontweight='bold')
        y-=0.29;ax.plot([0.15,7.45],[y,y],color='black',lw=0.5)
    else:
        h=0.13+0.155*max(a.count('\n')+1,b.count('\n')+1)
        ax.text(0.20,y-0.065,a,ha='left',va='top',fontsize=8.5,fontweight='bold',linespacing=1.25)
        ax.text(1.95,y-0.065,b,ha='left',va='top',fontsize=8.3,linespacing=1.25)
        y-=h
ax.plot([0.15,7.45],[y,y],color='black',lw=0.8);y-=0.13
for note in [
 'Model frequency is not a measured FPGA core frequency. The routed host clock is 10.004 MHz.',
 'memCycles=12 is not L2 hit latency. LSL raw bits include address/type, but exclude auxiliary queues.',
 '16 GiB is target address space; the diagnostic Linux launch uses 2 GiB. Memory timing is not DDR3.'
]:
    ax.text(0.20,y,note,va='top',fontsize=7.0);y-=0.17
assert y>0, y
fig.savefig(OUT / 'hardware_configuration.png',dpi=220,facecolor='white')
fig.savefig(OUT / 'hardware_configuration.pdf',facecolor='white')
plt.close(fig)
(OUT / 'evidence_manifest.json').write_text(json.dumps({'audit_date':'2026-11-18','bitstream_sha256_verified':bit_hash.hexdigest(),'inputs':manifest},indent=2)+'\n')
print(json.dumps({'rows':len(rows),'bitstream_sha256_verified':True,'output':str(OUT),'LSL_raw_bits_per_checker':2*255*130,'LSL_data_bytes_per_checker':2*255*8},indent=2))
