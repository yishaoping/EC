#!/usr/bin/env python3
"""Bounded offline regressions of original/fit module RTL, never FPGA."""
from pathlib import Path
import datetime,fcntl,json,os,re,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc
O=D/'build-logs/Opt4-fit-modules-20261110'
STATE=D/'Opt4-fit-verification-state.json'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def main():
 lock=(D/'.opt4-fit-verification.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 out=O/'verification';out.mkdir(exist_ok=True)
 st=dict(status='WAITING_MODULE_RTL',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),fpga_access=False,formal_admission=False,tests={});save(STATE,st)
 def command(label,argv,timeout=1800):
  with (out/(label+'.log')).open('ab',buffering=0) as f:
   p=subprocess.Popen(argv,cwd=out,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   st.update(active_step=label,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(STATE,st)
   start=time.monotonic()
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    st.update(updated_utc=now());save(STATE,st);os.fsync(f.fileno())
    if time.monotonic()-start>timeout:
     # This offline subprocess group only; no CAD/FPGA controls.
     import signal
     os.killpg(p.pid,signal.SIGTERM);p.wait();raise RuntimeError(label+' offline timeout')
   assert p.returncode==0,(label,p.returncode)
  return out/(label+'.log')
 # Universal combinational equivalence of overflow detection, all 128 inputs.
 proof=out/'carry-proof.v';proof.write_text('module carry_proof(input [63:0] a,b,output ok); wire old=(|b)&&(a>(~64\'d0-b)); wire [64:0] s={1\'b0,a}+{1\'b0,b}; assign ok=(old==s[64]); endmodule\n')
 log=command('carry-proof',['nice','-n','10','/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top carry_proof; sat -verify -prove ok 1 -show-inputs -timeout 120'])
 assert 'SUCCESS' in log.read_text()
 st['tests']['carry_identity']=dict(status='PASS_UNIVERSAL_128BIT_INPUTS',log=str(log),sha256=sha(log));save(STATE,st)
 done=set()
 while len(done)<2:
  b=json.loads((D/'Opt4-fit-modules-state.json').read_text())
  for kind in ['barrier','address']:
   if kind in done:continue
   keys=['baseline-'+kind,'fit-'+kind]
   if not all(b.get('modules',{}).get(k,{}).get('status')=='ELABORATED_MODULE_ONLY' for k in keys):continue
   src=[Path(b['modules'][k]['rtl']) for k in keys]
   top='GHBarrierLatencyStats' if kind=='barrier' else 'PackageAddressStats'
   original=out/(kind+'-original.v');candidate=out/(kind+'-fit.v')
   original.write_text(src[0].read_text().replace('module '+top+'(','module '+top+'_original(',1))
   candidate.write_bytes(src[1].read_bytes())
   if kind=='barrier':
    test=out/'barrier-tb.v';test.write_bytes((W/'candidates/capacity-exact-factor-20261110/leaf_compare_tb.v').read_bytes())
   else:
    text=src[1].read_text();ports=text[:text.index(');')]
    names=re.findall(r'output\s+(?:\[[^]]+\]\s+)?(\w+)',ports)
    assert 'io_idle' in names and 'io_counters_39' in names and 'io_firstStoreCounters_7' in names
    signals=['clock','reset','io_resetStats','io_start','io_stop','io_safeWatermark','io_sequenceBaseline','io_fatalProtocolError']
    for lane in range(3):signals += [f'io_events_{lane}_valid']+[f'io_events_{lane}_bits_{n}' for n in ['addr','size','isStore','packetSeq']]
    lines=['`timescale 1ns/1ps','module tb;','reg clock=0; always #5 clock=~clock;','reg reset=1,io_resetStats=1,io_start=0,io_stop=0,io_fatalProtocolError=0;','reg [31:0] io_safeWatermark=0,io_sequenceBaseline=0;','integer i,j,seq,phase; integer vectors=0; integer idle_edges=0; integer valid_edges=0;']
    for lane in range(3):lines += [f'reg io_events_{lane}_valid=0; reg [39:0] io_events_{lane}_bits_addr=0; reg [1:0] io_events_{lane}_bits_size=0; reg io_events_{lane}_bits_isStore=0; reg [31:0] io_events_{lane}_bits_packetSeq=0;']
    for n in names:
     width='[63:0] ' if n not in ['io_statsValid','io_idle'] else ''
     lines += [f'wire {width}a_{n},b_{n};']
    for module,prefix in [(top+'_original','a'),(top,'b')]:
     lines += [module+' '+prefix+'('+','.join('.'+n+'('+n+')' for n in signals)+','+','.join('.'+n+'('+prefix+'_'+n+')' for n in names)+');']
    lines += ['initial begin','for(i=0;i<6144;i=i+1)begin','@(negedge clock);','reset=(i<3); io_resetStats=(i<3 || i==2048 || i==4096);','phase=i%2048; io_start=(phase==4); io_stop=(phase==1400); io_fatalProtocolError=(phase==1850);','if(phase<4)begin io_safeWatermark=0;io_sequenceBaseline=0;end','else if(phase>=1300 && phase<1750) io_safeWatermark=phase-1200;','else if(phase==1800)io_safeWatermark=32\'hffff_fffe;','seq=1+phase/32;']
    for lane in range(3):
     lines += [f'io_events_{lane}_valid=(phase>=8 && phase<1250 && phase%8=={lane});',f'io_events_{lane}_bits_addr=40\'h80000000+((phase/8)%37)*64+({lane}*8);',f'io_events_{lane}_bits_size=phase%4;',f'io_events_{lane}_bits_isStore=(phase/32+{lane})%2;',f'io_events_{lane}_bits_packetSeq=seq;']
    lines += ['@(posedge clock);#1;']
    for n in names:lines += [f'if(a_{n} !== b_{n})begin $display("ADDRESS_MISMATCH {n} cycle=%0d a=%h b=%h",i,a_{n},b_{n});$fatal;end']
    lines += ['if(a_io_statsValid)valid_edges=valid_edges+1;','if(a_io_idle)idle_edges=idle_edges+1;','vectors=vectors+1;','end','if(valid_edges<100 || idle_edges<10)begin $display("INSUFFICIENT_VALID_TRAFFIC");$fatal;end','$display("ADDRESS_SEQUENTIAL_COMPARISON_PASS vectors=%0d valid_edges=%0d idle_edges=%0d",vectors,valid_edges,idle_edges);$finish;end','endmodule']
    test=out/'address-tb.v';test.write_text('\n'.join(lines)+'\n')
   exe=out/(kind+'.vvp')
   command(kind+'-compile',['nice','-n','10','/usr/bin/iverilog','-g2012','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-s','tb','-o',str(exe),str(original),str(candidate),str(test)])
   log=command(kind+'-compare',['nice','-n','10','/usr/bin/vvp',str(exe)],timeout=1800)
   assert 'COMPARISON_PASS' in log.read_text()
   st['tests'][kind]=dict(status='PASS_SAMPLED_SEQUENTIAL_NOT_FORMAL',original_rtl_sha256=sha(src[0]),fit_rtl_sha256=sha(src[1]),testbench=str(test),testbench_sha256=sha(test),log=str(log),log_sha256=sha(log),comparison_outputs='all exported ports each cycle',full_design_proof=False)
   done.add(kind);save(STATE,st)
  if b['status']=='FAILED_WITH_EVIDENCE':raise RuntimeError('module elaboration failed')
  if len(done)<2:time.sleep(30)
 st.update(status='OFFLINE_MODULE_CHECKS_PASS_NOT_FULL_DESIGN',ended_utc=now());save(STATE,st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if STATE.exists():
   s=json.loads(STATE.read_text());s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(STATE,s)
  raise
