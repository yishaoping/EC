#!/usr/bin/env python3
"""Isolated fixed-slot scanner compilation, equivalence and matched mapping."""
from pathlib import Path
import datetime,fcntl,json,os,re,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc
F=W/'Opt4-fit-20261110';O=D/'build-logs/Opt4-fit-modules-20261110/scanner';STATE=D/'Opt4-fit-scanner-state.json'
JAVA=W.parent/'envs/manager-1.17.1/bin/java'
CACHE=W.parent/'dac2026/work/opt4-minimal-v2/cache/coursier/v1/https/repo1.maven.org/maven2'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def main():
 lock=(D/'.opt4-fit-scanner.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 cp=(D/'build-logs/C4-goldengate-20261106T100436.256198Z/firesim.classpath').read_text().strip()
 comp=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar') for n in ['scala-compiler','scala-library','scala-reflect']]
 plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
 st=dict(status='RUNNING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),fit_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip(),fpga_access=False,full_dut_build=False,formal_admission=False,modules={});save(STATE,st)
 def run(label,argv,cwd=O):
  with (O/(label+'.log')).open('ab',buffering=0) as f:
   p=subprocess.Popen(list(map(str,['nice','-n','10']+argv)),cwd=cwd,env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   st.update(active_step=label,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(STATE,st)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    st.update(updated_utc=now());save(STATE,st);os.fsync(f.fileno())
   assert p.returncode==0,(label,p.returncode)
 for variant,source,top in [('baseline',O/'SafePrefixScannerBaseline.scala','SafePrefixScannerBaseline'),('fit',F/'chipyard/generators/boom/src/main/scala/lsu/SafePrefixScanner.scala','SafePrefixScanner')]:
  out=O/variant;out.mkdir(exist_ok=True);classes=out/'classes';classes.mkdir(exist_ok=True);copy=out/source.name;copy.write_bytes(source.read_bytes())
  emit=out/'EmitScanner.scala';emit.write_text('package opt4fit\nobject EmitScanner extends App { (new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.'+top+'(256,32),Array("--target-dir",args(0))) }\n')
  run(variant+'-compile',[JAVA,'-Xmx8G','-XX:ActiveProcessorCount=4','-cp',':'.join(map(str,comp)),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+str(plugin),'-d',classes,copy,emit],out)
  run(variant+'-elaborate',[JAVA,'-Xmx12G','-XX:ActiveProcessorCount=4','-cp',str(classes)+':'+cp,'opt4fit.EmitScanner',out],out)
  rtl=out/(top+'.v');assert rtl.exists();st['modules'][variant]=dict(top=top,rtl=str(rtl),rtl_sha256=sha(rtl),source_sha256=sha(source),status='ELABORATED');save(STATE,st)
 # Full 32-bit wraparound identity: slot distance and fixed expected sequence.
 proof=O/'index-proof.v';proof.write_text('''module index_proof(input [31:0] w,input [7:0] slot,output ok);
wire [7:0] dl=slot-w[7:0];wire [8:0] d=dl==0?9'd256:{1'b0,dl};
wire [23:0] hi=w[31:8]+(slot<=w[7:0]);
wire [31:0] expected={hi,slot};wire [31:0] old=w+d;
assign ok=(old==expected)&&(old[7:0]==slot)&&(d>=1)&&(d<=256);
endmodule
''')
 run('index-proof',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top index_proof; sat -verify -prove ok 1 -show-inputs -timeout 120'])
 assert 'SUCCESS' in (O/'index-proof.log').read_text()
 # Generated RTL against extracted original loop; arbitrary 32-bit sequence
 # entries plus all prefix lengths and wraparound watersheds.
 lines=['`timescale 1ns/1ps','module tb;','reg clock=0,reset=0;reg [31:0] watermark;reg [255:0] allocated,completed,passed;reg [31:0] seq[0:255];wire [8:0] a,b;integer t,i,k,idx,n;reg [31:0] expected;']
 shared='.clock(clock),.reset(reset),.io_watermark(watermark),'+','.join(f'.io_{name}_{i}({name}[{i}])' for name in ['allocated','completed','passed','seq'] for i in range(256))
 lines += ['SafePrefixScannerBaseline original('+shared+',.io_advance(a));','SafePrefixScanner candidate('+shared+',.io_advance(b));','initial begin','for(t=0;t<4096;t=t+1)begin','watermark=$random; if(t<512) watermark=32\'hffff_ff00+t;','allocated={256{1\'b1}};completed={256{1\'b1}};passed={256{1\'b1}};','for(i=1;i<=256;i=i+1)begin expected=watermark+i;idx=expected&255;seq[idx]=expected;end','n=t%257;','if(n<256)begin idx=(watermark+n+1)&255;case(t%4)0:allocated[idx]=0;1:completed[idx]=0;2:passed[idx]=0;3:seq[idx]=seq[idx]^32\'h80000000;endcase end','if(t>=1024)for(k=0;k<16;k=k+1)begin idx=$random&255;seq[idx]=$random;end','#1;if(a!==b)begin $display("SCANNER_MISMATCH t=%0d w=%h a=%0d b=%0d",t,watermark,a,b);$fatal;end','end','$display("SCANNER_GENERATED_RTL_COMPARISON_PASS vectors=4096");$finish;end','endmodule']
 tb=O/'scanner-tb.v';tb.write_text('\n'.join(lines)+'\n');exe=O/'scanner.vvp'
 run('compare-compile',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,st['modules']['baseline']['rtl'],st['modules']['fit']['rtl'],tb])
 run('compare',['/usr/bin/vvp',exe]);assert 'COMPARISON_PASS' in (O/'compare.log').read_text()
 st['proof']=dict(index_identity='SAT universal 40 input bits PASS',permutation_argument='For each watermark, offsets 1..256 bijectively cover physical slots; first failing offset equals minimum failing slot distance, or 257 when all pass, minus 1',rtl_vectors=4096,full_design_proof=False);save(STATE,st)
 jobs=[]
 for variant,r in st['modules'].items():
  out=O/variant;tcl=out/'map.tcl';tcl.write_text(f'''set_param general.maxThreads 8
read_verilog {{{r['rtl']}}}
synth_design -top {r['top']} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {{{out/'utilization.rpt'}}}
write_checkpoint -force {{{out/'scanner.dcp'}}}
puts "EC_SCANNER_MAP_OK {variant}"
exit 0
''');f=(out/'mapping.log').open('ab',buffering=0)
  p=subprocess.Popen(['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'vivado.log'),'-source',str(tcl)],cwd=out,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
  r.update(status='MAPPING',pid=p.pid,start_ticks=proc(p.pid)['start_ticks']);jobs.append((variant,p,f,out));save(STATE,st)
 while jobs:
  for variant,p,f,out in jobs[:]:
   if p.poll() is None:continue
   os.fsync(f.fileno());f.close();r=st['modules'][variant];r.update(returncode=p.returncode,status='MAPPED_MODULE_ONLY' if p.returncode==0 else 'FAILED_WITH_EVIDENCE')
   if p.returncode==0:
    rows={}
    for l in (out/'utilization.rpt').read_text().splitlines():
     a=[x.strip() for x in l.split('|')]
     if len(a)>6 and a[1] in ['CLB LUTs*','CARRY8','DSPs','CLB Registers']:
      try:rows[a[1].rstrip('*')]=float(a[2])
      except ValueError:pass
    r.update(utilization=rows,report_sha256=sha(out/'utilization.rpt'))
   jobs.remove((variant,p,f,out));save(STATE,st)
  st.update(updated_utc=now(),status='MAPPING_MODULES');save(STATE,st)
  if jobs:time.sleep(30)
 st.update(status='MODULE_VALIDATED_AND_MAPPED' if all(r['returncode']==0 for r in st['modules'].values()) else 'PARTIAL_MAPPING_FAILURE',ended_utc=now());save(STATE,st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if STATE.exists():
   s=json.loads(STATE.read_text());s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(STATE,s)
  raise
