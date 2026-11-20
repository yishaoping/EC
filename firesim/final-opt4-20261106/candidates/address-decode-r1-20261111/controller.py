#!/usr/bin/python3
"""Immutable isolated one-hot candidate validation and OOC map; no FPGA access.

Stages are sequential and accept only successful, exact hash-bound checkpoints.
An existing live controller or child is never signalled, edited, or duplicated.
Failed stages require a separate reviewed recovery version, not an automatic retry.
"""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os
import shutil
import subprocess
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111'
S = D/'Opt4-fit-address-decode-r1-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()

def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def save(p,v):
    p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)

def identity(pid):
    try:
        v=(Path('/proc')/str(pid)/'stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=v[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=v[0])
    except FileNotFoundError:return {}

def live(x):
    y=identity(x.get('pid',0))
    return bool(y and y.get('start_ticks')==str(x.get('start_ticks')) and y.get('host_boot_id')==x.get('host_boot_id') and y.get('process_state') not in ['Z','X'])

def guard():
    mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
    return mem>=48*2**20 and shutil.disk_usage(W).free>=40*2**30

def main():
    O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);old=read(S)
    assert not live(old) and not live(old.get('child',{})), 'adopt existing live job'
    inputs=read(C/'input-hashes.json')
    assert all(sha(p)==h for p,h in inputs.items()),'immutable input hash mismatch'
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
    for n in ['PackageAddressStats.scala','AddressBucketAccess.scala','AddressBucketReduction.scala']:
        assert (F/REL/n).read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+REL+n],cwd=F)
    st=dict(schema='ec-opt4-address-decode-validation/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],
        status='PREPARING',started_utc=now(),input_sha256=inputs,stages=old.get('stages',{}),fpga_access=False,formal_admission=False,
        full_dut_synthesis=False,production_selected=False,proof_scope='Generated full-size access cuts and arbitrary 64-bit arithmetic; complete module finite cycle regression. No full-DUT formal equivalence.')
    save(S,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8'}
    def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
    def run(label,argv,directory,outputs=(),negative=False):
        directory.mkdir(parents=True,exist_ok=True);rp=directory/(label+'-result.json');r=read(rp)
        if r:
            assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id']
            assert r.get('accepted_result') and r.get('returncode') is not None,'failed stage retained; separate recovery required'
            assert all(sha(p)==h for p,h in r['outputs'].items()) and not r['missing_outputs']
            st['stages'][label]=r;save(S,st);return Path(r['log'])
        while not guard():update(status='WAITING_RESOURCE_GATE',next_stage=label);time.sleep(30)
        log=directory/(label+'-attempt-1.log');assert not log.exists(),'incomplete previous stage: manual evidence audit required'
        args=list(map(str,['nice','-n','10',*argv]))
        with log.open('xb',buffering=0) as f:
            p=subprocess.Popen(args,cwd=directory,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
            child=identity(p.pid);r=dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],argv=args,log=str(log),started_utc=now(),**child,returncode=None)
            st['stages'][label]=r;update(status='RUNNING_'+label.upper(),child=child,active_stage=label)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                update();os.fsync(f.fileno())
        accepted=p.returncode!=0 if negative else p.returncode==0
        r.update(returncode=p.returncode,accepted_result=accepted,negative=negative,ended_utc=now(),
            outputs={str(p):sha(p) for p in outputs if p.is_file()},missing_outputs=[str(p) for p in outputs if not p.is_file()])
        save(rp,r);st['stages'][label]=r;update(child={})
        assert accepted and not r['missing_outputs'],(label,p.returncode,str(log))
        return log
    def elaborate(mode,top):
        sub=O/mode;sub.mkdir(exist_ok=True)
        run('elaborate-'+mode,[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4decode.EmitDecode',mode,sub],sub,[sub/(top+'.v')])
        return sub/(top+'.v')
    classes=O/'classes';classes.mkdir(exist_ok=True)
    sources=[F/REL/n for n in ['PackageAddressStats.scala','AddressBucketAccess.scala','AddressBucketReduction.scala']]
    cp=str(classes)+':'+':'.join(cfg['classpath'])
    run('compile',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),
        'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,*sources,C/'EmitDecode.scala'],O,[classes/'opt4decode/EmitDecode.class'])
    rtl=elaborate('proof','AccessProof');proof=O/'proof'
    for prop in ['readOk','clearOk','arithmeticOk']:
        log=run('sat-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top AccessProof -flatten; sat -verify -prove io_{prop} 1 -timeout 240'],proof)
        assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log=run('sat-negative',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top AccessProof -flatten; sat -verify -prove io_readOk 0 -timeout 60'],proof,negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_GENERATED_256X64_ACCESS_CLEAR_AND_64BIT_OVERFLOW',negative_mutation_rejected=True)
    tb=proof/'tb.v'
    declarations='\n'.join('reg [63:0] w'+str(i)+'=0;' for i in range(256))
    ports=','.join('.io_words_'+str(i)+'(w'+str(i)+')' for i in range(256))
    init='\n'.join('w'+str(i)+"=(64'h9e3779b97f4a7c15 * "+str(i+1)+') ^ t;' for i in range(256))
    cases='\n'.join(str(i)+': chosen=w'+str(i)+';' for i in range(256))
    text='''module tb;
reg [7:0] idx=0;reg [255:0] valid=0;reg [63:0] delta=0;reg clear=0,rst=0;
wire [63:0] selected;wire [64:0] sum;wire [255:0] cleared;wire readOk,arithmeticOk,clearOk;
integer t;reg [63:0] chosen,base;reg [64:0] expected;reg [255:0] cv;
'''+declarations+'''
AccessProof dut(.io_index(idx),.io_valid(valid),.io_delta(delta),.io_clear(clear),.io_reset(rst),.io_selected(selected),.io_sum(sum),.io_cleared(cleared),.io_readOk(readOk),.io_arithmeticOk(arithmeticOk),.io_clearOk(clearOk),'''+ports+''');
initial begin
for(t=0;t<4096;t=t+1)begin
idx=t%256;valid=(t%4==0)?0:~256'b0;delta=(t%8==0)?64'hffffffffffffffff:((t%8==1)?1:((t%8==2)?0:t));clear=(t%2);rst=(t%7==0);
'''+init+'''
case(t%8)
0:begin '''+' '.join('w'+str(i)+"=64'hffffffffffffffff;" for i in range(256))+''' end
1:begin '''+' '.join('w'+str(i)+"=64'hffffffffffffffff;" for i in range(256))+''' end
endcase
case(idx)
'''+cases+'''
endcase
base=valid[idx]?chosen:0;expected={1'b0,base}+{1'b0,delta};cv=valid;if(clear)cv[idx]=0;if(rst)cv=0;
#1;if(selected!==chosen || sum!==expected || cleared!==cv || !readOk || !arithmeticOk || !clearOk)begin $display("ACCESS_BOUNDARY_FAIL t=%0d index=%0d",t,idx);$fatal;end
end
$display("ACCESS_ACTUAL_SIZE_PASS vectors=4096 slots=256 width=64 reset=1 overflow=1");$finish;end
endmodule
'''
    if tb.exists():assert tb.read_text()==text
    else:tb.write_text(text)
    exe=proof/'sim'
    run('boundary-compile',['iverilog','-g2012','-s','tb','-o',exe,rtl,tb],proof,[exe])
    log=run('boundary-run',['vvp',exe],proof)
    assert 'ACCESS_ACTUAL_SIZE_PASS' in log.read_text()
    update(actual_size_boundary='PASS_4096_VECTORS_ALL_256_SLOTS_64BIT_OVERFLOW_RESET')
    def map_rtl(label,rtl,top):
        sub=O/label;sub.mkdir(exist_ok=True);tcl=sub/'map.tcl';report=sub/'utilization.rpt';dcp=sub/'module.dcp'
        text='set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\nsynth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n'
        if tcl.exists():assert tcl.read_text()==text
        else:tcl.write_text(text)
        run(label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],sub,[report,dcp])
        resource={}
        for line in report.read_text().splitlines():
            row=[x.strip() for x in line.split('|')]
            if len(row)>3 and row[1] in ['CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','DSPs']:
                resource[row[1]]=float(row[2].replace(',',''))
        return dict(resources=resource,report=str(report),report_sha256=sha(report),rtl_sha256=sha(rtl),tcl_sha256=sha(tcl),checkpoint=str(dcp),scope='OOC only; not whole-DUT FIT')
    maps={}
    for mode in ['read-old','read-new']:
        micro=elaborate(mode,'ReadProbe');maps[mode]=map_rtl('map-'+mode,micro,'ReadProbe');update(micro_maps=maps)
    rtl=elaborate('address','PackageAddressStats');compare=O/'compare';compare.mkdir(exist_ok=True)
    for source,target in [('frozen-original.v','original.v'),('frozen-tb.v','tb.v')]:
        p=compare/target
        if p.exists():assert p.read_bytes()==(C/source).read_bytes()
        else:shutil.copy2(C/source,p)
    exe=compare/'obj/Vtb'
    run('compare-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb','--Mdir',compare/'obj','-j',8,
        '--output-split',10000,'--output-split-cfuncs',200,'--x-initial',0,'--x-assign',0,'-Wno-fatal',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',
        compare/'original.v',rtl,compare/'tb.v'],compare,[exe])
    log=run('compare',[exe],compare)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    update(full_module_regression='PASS_6144_CYCLES_52_OUTPUTS_NOT_FORMAL',rtl_sha256=sha(rtl))
    save(O/'verified-local.json',dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],local_formal=st['local_formal'],
        actual_size_boundary=st['actual_size_boundary'],full_module_regression=st['full_module_regression'],rtl_sha256=sha(rtl),full_dut_formal=False))
    mapped=map_rtl('map-full-module',rtl,'PackageAddressStats')
    update(status='VERIFIED_AND_MAPPED_MODULE_ONLY',full_module_map=mapped,ended_utc=now(),child={})
    save(O/'result.json',st)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        old=read(S)
        if old and old.get('pid')==os.getpid():old.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,old)
        raise
