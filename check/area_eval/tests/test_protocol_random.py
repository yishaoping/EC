#!/usr/bin/env python3
"""Random stateful tests: repeated EVT truncation and duplicate-aware SW."""
from pathlib import Path
import random,subprocess
ROOT=Path(__file__).resolve().parents[1];rng=random.Random(13112026)
out=['''`timescale 1ns/1ps
module tb_protocol_random;
reg clk=0; always #5 clk=~clk;
reg rst=1,rb=0; reg [7:0] boundary=0;
wire ready,full; wire [2:0] epoch;
reg [31:0] qs=0; reg [11:0] qe=0; wire [3:0] hv;
pal_evt #(.SEQ_W(8),.EPOCH_W(3),.QUERIES(4)) evt
(clk,rst,rb,boundary,ready,epoch,full,qs,qe,hv);
reg rebase=0; reg [7:0] base=0; reg [2:0] session=0;
reg valid=0,pass=0; reg [7:0] seq=0; reg [2:0] ep=0;
wire result_ready;wire [7:0] sw;
pal_safe_watermark #(.SEQ_W(8),.EPOCH_W(3),.WINDOW(8)) water
(clk,rst,rebase,base,session,valid,pass,seq,ep,result_ready,sw);
task tick; begin @(posedge clk); #1; @(negedge clk); #1; end endtask
initial begin tick; rst=0;
''']
# Epoch oracle explicitly keeps a SET of surviving identities, not intervals.
valid={(e,s):False for e in range(8) for s in range(256)}
for s in range(256):valid[0,s]=True
for e in range(1,8):
 b=rng.randrange(1,240)
 for key in valid:
  if key[1]>=b:valid[key]=False
 for s in range(b,256):valid[e,s]=True
 out.append(f'rb=1; boundary={b}; tick; rb=0;\n')
 for n in range(150):
  seqs=[rng.randrange(256) for _ in range(4)];eps=[rng.randrange(8) for _ in range(4)]
  qs=sum(s<<(8*i) for i,s in enumerate(seqs));qe=sum(ep<<(3*i) for i,ep in enumerate(eps))
  expected=sum(int(valid[ep,s])<<i for i,(ep,s) in enumerate(zip(eps,seqs)))
  out.append(f'qs=32\'h{qs:x}; qe=12\'h{qe:x}; #1; if(hv!=4\'h{expected:x}) $fatal(1,"history {e}/{n}");\n')
out.append('if(!full || ready) $fatal(1,"EVT capacity");\n')
# Bitmap oracle uses an unbounded sequence SET for the admitted live window.
# Sw advances by at most one per clock, based on prior PASS observations.
sw=0;passed=set()
for n in range(900):
 if sw>235:
  out.append('rebase=1; base=0; session=session+1; tick; rebase=0;\n');sw=0;passed=set()
 isvalid=rng.random()<.85;ispass=rng.random()<.9
 seq=max(0,min(255,sw+rng.randrange(-1,12))); matching=rng.random()<.9
 admitted=matching and sw<seq<=sw+8
 advance=(sw+1 in passed)
 if isvalid and admitted and ispass:passed.add(seq)
 if advance:sw+=1;passed.discard(sw)
 ep_expr='session' if matching else 'session+1'
 out.append(f'valid={int(isvalid)}; pass={int(ispass)}; seq={seq}; ep={ep_expr}; tick; if(sw!={sw}) $fatal(1,"SW set oracle {n}");\n')
out.append('$display("PASS stateful oracle: 4200 EVT identities + 900 SW cycles"); $finish; end\ninitial begin #1000000; $fatal(1,"timeout"); end\nendmodule\n')
p=ROOT/'results/tb_protocol_random.sv';p.write_text(''.join(out))
subprocess.run(['iverilog','-g2012','-s','tb_protocol_random','-o',str(ROOT/'results/tb_protocol_random.vvp'),str(ROOT/'rtl/palimpsest.sv'),str(p)],check=True)
subprocess.run(['vvp',str(ROOT/'results/tb_protocol_random.vvp')],check=True)
