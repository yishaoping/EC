#!/usr/bin/python3
"""Pair exact full SVB modules; directed ownership and random legal-cycle checks."""
from pathlib import Path
import sys,re,subprocess,os,json
C=Path(__file__).resolve().parent;O=Path(sys.argv[1]);R=Path(sys.argv[2]);A=Path(sys.argv[3]);L=Path(sys.argv[4]);O.mkdir(exist_ok=True)
ref=R.read_text();cand=A.read_text();names=re.findall(r'^module\s+(\w+)\(',ref,re.M)
for name in sorted(names,key=len,reverse=True):ref=re.sub(r'\b'+re.escape(name)+r'\b','Ref'+name,ref)
header=cand.split('module SVBModuleHarness(',1)[1].split(');',1)[0]
ports=re.findall(r'\b(input|output)\s*(\[[^\]]+\])?\s*(\w+)',header)
assert len(ports)>100 and len({n for d,w,n in ports})==len(ports)
inputs=[(w,n) for d,w,n in ports if d=='input'];outputs=[(w,n) for d,w,n in ports if d=='output']
refhead=R.read_text().split('module SVBModuleHarness(',1)[1].split(');',1)[0];assert re.findall(r'\b(input|output)\s*(\[[^\]]+\])?\s*(\w+)',refhead)==ports
combined=ref+'\n'+cand+'\nmodule SVBCombined(\n'+',\n'.join(d+' '+w+' '+n for d,w,n in ports)+',\noutput equivalent\n);\n'
combined+='\n'.join('wire '+w+' ref_'+n+';' for w,n in outputs)+'\n'
combined+='RefSVBModuleHarness reference_instance('+','.join('.'+n+'('+n+')' for w,n in inputs)+','+','.join('.'+n+'(ref_'+n+')' for w,n in outputs)+');\n'
combined+='SVBModuleHarness candidate_instance('+','.join('.'+n+'('+n+')' for w,n in inputs+outputs)+');\n'
combined+='assign equivalent = '+ ' && '.join('('+n+' == ref_'+n+')' for w,n in outputs)+';\nendmodule\n'
rtl=O/'combined.v';rtl.write_text(combined)
cpp=(C/'directed-template.cpp').read_text().replace('VSVBModuleHarness','VSVBCombined')
cpp=cpp.replace('d.eval();d.clock=1;d.eval();d.clock=0;d.eval();cycle++;','d.eval();check(d.equivalent,"paired combinational outputs");d.clock=1;d.eval();check(d.equivalent,"paired clock-edge outputs");d.clock=0;d.eval();check(d.equivalent,"paired settled outputs");cycle++;')
assert 'paired settled outputs' in cpp
cpp=cpp.replace('static unsigned cycle=0;','static unsigned cycle=0;\nstatic uint64_t rng=0xf2d2ca3e9ae9a7fcULL;\nstatic unsigned rnd(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}')
start=cpp.index(' puts("SVB_INVALIDATION_OWNER_DATA_LIFETIME_PASS')
cpp=cpp[:start]+r"""
 bool pending=false;unsigned savedEntry=0,savedValid=0,savedWriter=0,savedSeq=0,savedGeneration=0;
 for(unsigned t=0;t<4096;t++){
  if(t%1024==0){dut.io_ack_valid=0;dut.io_capture_valid=0;dut.io_invalidate_valid=0;dut.io_safeWatermark=0;dut.reset=1;tick(dut);tick(dut);dut.reset=0;pending=false;}
  const unsigned wm=(t%1024)/4;dut.io_safeWatermark=wm;dut.io_flush=t%97==0;dut.io_countStats=1;dut.io_resetStats=t%1024==0;
  dut.io_invalidate_valid=t%71==0;dut.io_invalidate_bits=wm;
  dut.io_capture_valid=rnd()%4!=0;dut.io_capture_bits_line=0x1000+64*(rnd()%32);dut.io_capture_bits_key_valid=1;dut.io_capture_bits_key_writer=1;dut.io_capture_bits_key_contentSeq=wm+rnd()%32;dut.io_capture_bits_key_generation=rnd();dut.io_capture_bits_epoch=t;dut.io_capture_bits_param=1;
  for(unsigned k=0;k<4;k++){dut.io_capture_bits_data_0[k]=rnd();dut.io_capture_bits_data_1[k]=rnd();dut.io_capture_bits_data_2[k]=rnd();dut.io_capture_bits_data_3[k]=rnd();}
  dut.io_promote_ready=t%3!=0;dut.io_ack_valid=pending&&t%4!=0;dut.io_ack_bits_entry=savedEntry;dut.io_ack_bits_key_valid=savedValid;dut.io_ack_bits_key_writer=savedWriter;dut.io_ack_bits_key_contentSeq=savedSeq;dut.io_ack_bits_key_generation=savedGeneration;dut.eval();check(dut.equivalent,"paired randomized inputs");
  bool ack=dut.io_ack_valid;bool promotion=dut.io_promote_valid&&dut.io_promote_ready;
  if(ack)check(dut.io_acked,"stress ACK exact ownership");
  if(promotion){check(!pending,"one outstanding owner");savedEntry=dut.io_promote_bits_entry;savedValid=dut.io_promote_bits_key_valid;savedWriter=dut.io_promote_bits_key_writer;savedSeq=dut.io_promote_bits_key_contentSeq;savedGeneration=dut.io_promote_bits_key_generation;}
  tick(dut);if(ack)pending=false;if(promotion)pending=true;
 }
 puts("SVB_COMBINED_EQUIV_PASS directed_invalidation_owner_payload=1 random_cycles=4096 reset_episodes=4 all_output_ports=1 assertions=1 architectural_restart_validated=0");return 0;}
"""
cpppath=O/'test.cpp';cpppath.write_text(cpp)
argv=['/usr/local/bin/verilator','--cc','--exe','--build','--assert','--top-module','SVBCombined','--Mdir',str(O/'obj'),'-j','8','-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',str(rtl),str(L),str(cpppath)]
with (O/'compile.log').open('xb') as f:r=subprocess.run(argv,cwd=O,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'CCACHE_DISABLE':'1','CCACHE_DIR':str(O/'ccache')})
assert r.returncode==0,('compile',r.returncode,str(O/'compile.log'))
with (O/'run.log').open('xb') as f:r=subprocess.run([str(O/'obj/VSVBCombined')],cwd=O,stdout=f,stderr=subprocess.STDOUT,timeout=120)
assert r.returncode==0 and 'SVB_COMBINED_EQUIV_PASS' in (O/'run.log').read_text(),('comparison',r.returncode,str(O/'run.log'))
(O/'result.json').write_text(json.dumps(dict(status='PASS_FULL_SVB_DIRECTED_AND_4096_RANDOM_CYCLES_ALL_OUTPUTS',reference_rtl=str(R),candidate_rtl=str(A),output_ports=len(outputs),fpga_execution=False,whole_dut_formal=False,architectural_restart_validated=False),indent=2)+'\n')
print('PASS_FULL_SVB_DIRECTED_AND_4096_RANDOM_CYCLES_ALL_OUTPUTS')
