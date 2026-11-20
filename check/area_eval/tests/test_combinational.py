#!/usr/bin/env python3
"""Generate deterministic random SV vectors against independent Python oracles."""
from pathlib import Path
import random, subprocess
ROOT=Path(__file__).resolve().parents[1]
rng=random.Random(20261113)
lines=['''module tb_comb;
reg recovery;
reg [3:0] tags,eligible,hv,cur;
reg [31:0] seqs;
reg [15:0] gens;
reg [3:0] gen;
reg [7:0] boundary;
wire hit,ambiguous; wire [1:0] way; wire [7:0] selected;
pal_version_select #(.WAYS(4),.SEQ_W(8),.GEN_W(4)) select_version
(recovery,tags,eligible,hv,cur,seqs,gens,gen,boundary,hit,way,selected,ambiguous);
reg valid,history,own,ext,producer,requester;
reg [7:0] seq,sw;
wire safe,allow,stall;
pal_visibility #(.SEQ_W(8)) visibility
(valid,history,own,ext,producer,requester,seq,sw,safe,allow,stall);
initial begin
''']
for case in range(2500):
    rec=rng.randrange(2); flags=[rng.randrange(16) for _ in range(4)]
    tags,eligible,hv,cur=flags
    ss=[rng.randrange(256) for _ in range(4)]
    gs=[rng.randrange(16) for _ in range(4)]
    gen=rng.randrange(16); boundary=rng.randrange(256)
    choices=[i for i in range(4) if all((f>>i)&1 for f in flags[:3]) and
             (ss[i]<boundary if rec else ((cur>>i)&1 and gs[i]==gen))]
    winner=max(choices,key=lambda i:ss[i]) if rec and choices else (choices[0] if choices else 0)
    sh=sum(s<<(8*i) for i,s in enumerate(ss)); gh=sum(g<<(4*i) for i,g in enumerate(gs))
    lines.append(f"recovery={rec}; tags={tags}; eligible={eligible}; hv={hv}; cur={cur}; seqs=32'h{sh:x}; gens=16'h{gh:x}; gen={gen}; boundary={boundary}; #1;\n")
    lines.append(f'if(hit!={int(bool(choices))} || way!={winner} || selected!={ss[winner] if choices else 0} || ambiguous!={int(not rec and len(choices)>1)}) $fatal(1,"selector case {case}");\n')
    v,h,o,e,p,r=[rng.randrange(2) for _ in range(6)]
    s,w=[rng.randrange(256) for _ in range(2)]
    safe=v and h and s<=w; allow=v and h and ((not e and o and p==r) or safe)
    lines.append(f'valid={v}; history={h}; own={o}; ext={e}; producer={p}; requester={r}; seq={s}; sw={w}; #1;\n')
    lines.append(f'if(safe!={int(safe)} || allow!={int(allow)} || stall!={int(v and not allow)}) $fatal(1,"visibility case {case}");\n')
lines.append('$display("PASS combinational: 2500 selector + 2500 visibility oracle cases"); $finish; end endmodule\n')
path=ROOT/'results/tb_comb.sv'; path.write_text(''.join(lines))
subprocess.run(['iverilog','-g2012','-s','tb_comb','-o',str(ROOT/'results/tb_comb.vvp'),str(ROOT/'rtl/palimpsest.sv'),str(path)],check=True)
subprocess.run(['vvp',str(ROOT/'results/tb_comb.vvp')],check=True)
