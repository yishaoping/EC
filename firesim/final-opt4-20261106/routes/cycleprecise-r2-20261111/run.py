#!/usr/bin/python3
"""Bounded, restartable CPU-only Golden Gate space/time and metasim experiments."""
import datetime, fcntl, hashlib, json, os, pathlib, re, shutil, subprocess, sys, time
P = pathlib.Path
W = P('/data1/gzh/EC/firesim/final-opt4-20261106')
D = P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = P(__file__).resolve().parent
L = D/'cycleprecise-route-a-r2-20261111'
S = L/'state.json'
FS = W/'C4/chipyard/sims/firesim/sim'
V = '/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'

def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p): return json.loads(P(p).read_text()) if P(p).is_file() else {}
def sha(p):
    h=hashlib.sha256()
    with P(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()
def save(p,j):
    p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)
def ident(pid):
    try:
        a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:return {}

ST={}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def stage(name,argv,cwd,outputs=(),timeout=3600,env=None,expected=0):
    q=L/'receipts'/f'{name}.json';old=read(q)
    if old and old.get('returncode')==expected and all(P(p).is_file() and sha(p)==h for p,h in old.get('outputs',{}).items()):return old
    if old:raise RuntimeError('preserve failed receipt; versioned recovery required: '+name)
    log=L/(name+'.log');assert not log.exists(), 'partial stage must be reviewed: '+name
    update(status='RUNNING',stage=name)
    start=time.monotonic()
    with log.open('xb',buffering=0) as f:
        child=subprocess.Popen(argv,cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env)
        update(child=ident(child.pid),argv=argv)
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            # This controller owns this bounded CPU child only, never an existing CAD.
            child.terminate()
            try:rc=child.wait(timeout=20)
            except subprocess.TimeoutExpired:child.kill();rc=child.wait()
            rc='TIMEOUT'
        os.fsync(f.fileno())
    r=dict(stage=name,argv=argv,log=str(log),log_sha256=sha(log),returncode=rc,
           host_wall_seconds=time.monotonic()-start,completed_utc=now(),
           outputs={str(p):sha(p) for p in outputs if P(p).is_file()})
    save(q,r);update(child={},last_receipt=str(q))
    assert rc==expected and all(P(p).is_file() for p in outputs),(name,rc,str(log))
    return r

def bench_cpp(reads,writes,width):
    # Wide data always represented by three words in scoreboard, including all 81 bits.
    words=(width+31)//32
    def word(expr,k):return expr if width<=32 else (f'uint32_t({expr} >> {32*k})' if width<=64 else f'{expr}[{k}]')
    lines=['#include "VSpaceTimePair.h"','#include "verilated.h"','#include <array>','#include <chrono>','#include <iostream>','#include <random>','#include <stdexcept>','using Data=std::array<uint32_t,3>;','VSpaceTimePair d;','std::mt19937_64 gen(8491167);']
    for kind,fields,n in [('r',['addr','en'],reads),('w',['addr','en','mask'],writes)]:
        for field in fields:
            lines.append(f'void set_{kind}_{field}(int i,uint32_t x){{switch(i){{')
            for i in range(n):
                a=f'd.io_model_{"read" if kind=="r" else "write"}_cmds_{i}_bits_{field}'
                b=f'd.io_reference_{"read" if kind=="r" else "write"}_cmds_{i}_{field}'
                lines.append(f'case {i}: {a}=x;{b}=x;break;')
            lines.append('}}')
    for kind,n in [('r',reads),('w',writes)]:
        for field,direction in [('valid','set'),('ready','get')]:
            lines.append(f'{"void" if direction=="set" else "bool"} {kind}_{field}(int i'+(',bool x' if direction=='set' else '')+'){switch(i){')
            for i in range(n):lines.append(f'case {i}: '+(f'd.io_model_{"read" if kind=="r" else "write"}_cmds_{i}_{field}=x;break;' if direction=='set' else f'return d.io_model_{"read" if kind=="r" else "write"}_cmds_{i}_{field};'))
            lines.append('}}' if direction=='set' else '}return false;}')
    lines.append('void resp_ready(int i,bool x){switch(i){')
    for i in range(reads):lines.append(f'case {i}: d.io_model_read_resps_{i}_ready=x;break;')
    lines.append('}}\nbool resp_valid(int i){switch(i){')
    for i in range(reads):lines.append(f'case {i}: return d.io_model_read_resps_{i}_valid;')
    lines.append('}return false;}\nData response(int i,bool ref){Data v{};switch(i){')
    for i in range(reads):
        lines.append(f'case {i}:')
        for k in range(words):lines.append(f'v[{k}]=ref ? {word(f"d.io_reference_read_resps_{i}",k)} : {word(f"d.io_model_read_resps_{i}_bits",k)};')
        lines.append('break;')
    lines.append('}return v;}\nvoid set_data(int i,Data v){switch(i){')
    for i in range(writes):
        lines.append(f'case {i}:')
        for f in [f'd.io_model_write_cmds_{i}_bits_data',f'd.io_reference_write_cmds_{i}_data']:
            if width<=64:lines.append(f'{f}=uint64_t(v[0]) | (uint64_t(v[1])<<32);')
            else:
                for k in range(words):lines.append(f'{f}[{k}]=v[{k}];')
        lines.append('break;')
    lines.append('}}')
    body=r'''
int main(int argc,char**argv){
  const bool negative=argc>1; const int R=READS,W=WRITES; Data mem[512]{};
  bool initialized[512]{}; uint64_t hosts=0,compared=0,conflicts=0,resets=0,collisions=0;
  auto began=std::chrono::steady_clock::now();
  d.clock=0;d.reset=1;d.io_targetClock=0;d.io_targetReset=0;d.io_model_reset_valid=0;
  for(int i=0;i<R;i++){r_valid(i,0);resp_ready(i,0);} for(int i=0;i<W;i++)w_valid(i,0);
  for(int i=0;i<5;i++){d.clock=0;d.eval();d.clock=1;d.eval();}d.clock=0;d.reset=0;d.eval();
  for(int t=0;t<8192;t++){
    bool tr=t>=512 && t%173==0;resets+=tr;d.io_targetReset=tr;d.io_model_reset_bits=tr;
    bool rd[R]{},wr[W]{},resp[R]{},rst=false;int ra[R],wa[W];bool wen[W];Data wd[W];
    for(int i=0;i<W;i++){
      wa[i]=t<512 ? t : gen()%512; if(i>0 && t%7==0)wa[i]=wa[0];
      wen[i]=t<512 || gen()%4; wd[i]={uint32_t(gen()),uint32_t(gen()),uint32_t(gen())&TOPMASK};
      if(WIDTH<=64)wd[i][2]=0;
      set_w_addr(i,wa[i]);set_w_en(i,wen[i]);set_w_mask(i,1);set_data(i,wd[i]);
      if(i>0 && wa[i]==wa[0] && wen[i] && wen[0])collisions++;
    }
    for(int i=0;i<R;i++){
      ra[i]=t>=512 && i==0 ? wa[0] : gen()%512;
      conflicts+=t>=512 && ra[i]==wa[0] && wen[0];set_r_addr(i,ra[i]);set_r_en(i,1);
    }
    d.clock=0;d.eval();Data expected[R];
    for(int i=0;i<R;i++){expected[i]=response(i,true);if(initialized[ra[i]] && expected[i]!=mem[ra[i]])throw std::runtime_error("reference mismatch");}
    int h=0;
    while(true){
      if(++h>1000)throw std::runtime_error("watchdog");
      d.io_model_reset_valid=!rst;
      for(int i=0;i<R;i++){r_valid(i,!rd[i] && gen()%5!=0);resp_ready(i,!resp[i] && gen()%4!=0);}
      for(int i=0;i<W;i++)w_valid(i,!wr[i] && gen()%5!=0);
      d.clock=0;d.eval();
      if(d.io_model_reset_valid && d.io_model_reset_ready)rst=true;
      for(int i=0;i<R;i++){
        if(d.io_model_read_resps_0_valid){} // model evaluated above before edge
        bool valid=false;switch(i){VALID_SWITCH}
        bool ready=false;switch(i){READY_SWITCH}
        if(valid && ready){Data got=response(i,false);if(negative && t==513 && i==0)got[0]^=1;
          if(initialized[ra[i]] && got!=expected[i]){std::cerr<<"MISMATCH target="<<t<<" read="<<i<<"\n";return 2;}
          compared+=initialized[ra[i]];resp[i]=true;
        }
        bool v=false;switch(i){RVALID_SWITCH} if(v && r_ready(i))rd[i]=true;
      }
      for(int i=0;i<W;i++){bool v=false;switch(i){WVALID_SWITCH}if(v && w_ready(i))wr[i]=true;}
      d.clock=1;d.eval();d.clock=0;d.eval();hosts++;
      bool done=rst;for(int i=0;i<R;i++)done&=rd[i]&&resp[i];for(int i=0;i<W;i++)done&=wr[i];if(done)break;
    }
    d.io_targetClock=1;d.eval();d.io_targetClock=0;d.eval();
    for(int i=0;i<W;i++)if(wen[i]&&!tr){mem[wa[i]]=wd[i];initialized[wa[i]]=true;}
  }
  double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-began).count();
  std::cout<<"{\"status\":\"PASS\",\"target_cycles\":8192,\"host_cycles\":"<<hosts
   <<",\"fmr_host_over_target\":"<<double(hosts)/8192<<",\"compared_read_values\":"<<compared
   <<",\"read_write_conflicts\":"<<conflicts<<",\"same_address_writes\":"<<collisions
   <<",\"target_reset_tokens\":"<<resets<<",\"wall_seconds\":"<<wall
   <<",\"target_cycles_per_second\":"<<8192/wall<<"}\n";
}
'''
    replaces={'READS':str(reads),'WRITES':str(writes),'WIDTH':str(width),'TOPMASK':str((1<<max(0,width-64))-1),
      'VALID_SWITCH':''.join(f'case {i}:valid=d.io_model_read_resps_{i}_valid;break;' for i in range(reads)),
      'READY_SWITCH':''.join(f'case {i}:ready=d.io_model_read_resps_{i}_ready;break;' for i in range(reads)),
      'RVALID_SWITCH':''.join(f'case {i}:v=d.io_model_read_cmds_{i}_valid;break;' for i in range(reads)),
      'WVALID_SWITCH':''.join(f'case {i}:v=d.io_model_write_cmds_{i}_valid;break;' for i in range(writes))}
    for k in sorted(replaces,key=len,reverse=True):body=body.replace(k,replaces[k])
    return '\n'.join(lines)+body

def parse_area(p):
    out={}
    for line in P(p).read_text().splitlines():
        m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)\s*\|',line)
        if m:out.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    assert out.get('CLB LUTs',0)>0
    return out

def main():
    L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    bind=read(C/'input-hashes.json');assert bind and all(sha(p)==h for p,h in bind.items())
    ST.update(schema='ec-opt4-cycleprecise-route-a/1',**ident(os.getpid()),started_utc=now(),
              functional_baseline=BASE,fpga_access=False,target_function_changed=False,results={})
    update(status='STARTED')
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    classes=L/'classes';classes.mkdir(exist_ok=True)
    java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2']
    cp=str(classes)+':'+':'.join(cfg['classpath'])
    stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',str(classes),str(C/'Prototype.scala')],C,[classes/'opt4spacetime/EmitPair.class'])
    for label,reads,writes,width in [('4r2w64',4,2,64),('35r1w81',35,1,81)]:
        root=L/label;root.mkdir(exist_ok=True)
        stage(label+'-emit',java+['-cp',cp,'opt4spacetime.EmitPair',str(root),str(reads),str(writes),str(width)],C,[root/'pair/SpaceTimePair.v',root/'model/AsyncMemChiselModel.v',root/'reference/AsyncMemChiselRTL.v'])
        cpp=root/'test.cpp';text=bench_cpp(reads,writes,width)
        if cpp.exists():assert cpp.read_text()==text
        else:cpp.write_text(text)
        binary=root/'obj_dir/VSpaceTimePair'
        stage(label+'-verilate',[V,'--cc','--exe','--build','-j','2','-Wno-fatal','--top-module','SpaceTimePair','--Mdir',str(binary.parent),str(root/'pair/SpaceTimePair.v'),str(cpp),'-CFLAGS','-O1 -std=c++17'],root,[binary])
        stage(label+'-cycles',[str(binary)],root)
        stage(label+'-negative',[str(binary),'negative'],root,expected=2)
        run=json.loads((L/(label+'-cycles.log')).read_text().strip().splitlines()[-1]);run['negative_rejected']=True
        save(root/'cycle-result.json',run);ST['results'][label]=dict(cycle=run)
        update()
    # Actual Golden Gate compiler / metasimulation, using its upstream Regfile test.
    # Keep separate failures from the completed boundary measurements.
    try:
        g=L/'regfile-target';g.mkdir(exist_ok=True)
        stage('gg-target',java+['-cp',cp,'freechips.rocketchip.system.Generator','--target-dir',str(g),'--name','Regfile','--top-module','firesim.midasexamples.Regfile','--configs','firesim.midasexamples.NoConfig'],C,[g/'Regfile.fir',g/'Regfile.anno.json'])
        for config in ['PlainConfig','MCConfig']:
            out=L/('regfile-'+config);out.mkdir(exist_ok=True)
            stage('gg-'+config,java+['-cp',cp,'midas.stage.GoldenGateMain','-i',str(g/'Regfile.fir'),'-td',str(out),'-faf',str(g/'Regfile.anno.json'),'-ggcp','opt4spacetime','-ggcs',config,'--output-filename-base','FireSim-generated','--no-dedup'],C,[out/'FireSim-generated.sv',out/'FireSim-generated.const.h'])
            bb=out/'firrtl_black_box_resource_files.f'
            if bb.is_file():
                sv=out/'FireSim-generated.sv'
                # Append exactly once with a durable receipt.
                if not (out/'blackboxes-appended.json').is_file():
                    with sv.open('a') as f:
                        for name in bb.read_text().splitlines():
                            if name.strip():f.write(P(name).read_text())
                    save(out/'blackboxes-appended.json',{'sha256':sha(sv)})
            env={**os.environ,'PATH':str(P(V).parent)+':/usr/bin:/bin','CXX':'/usr/bin/g++',
                 'CXXFLAGS':'-O1 -I'+str(FS/'src/main/cc/midasexamples'),'LDFLAGS':'', 'LD_LIBRARY_PATH':''}
            argv=['/usr/bin/make','-C',str(FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=Regfile',
                  'GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated',
                  'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(FS/'src/main/cc/midasexamples/TestRegfile.cc'),
                  'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX=/usr/bin/g++']
            stage('metasim-build-'+config,argv,C,[out/'VRegfile'],timeout=3600,env=env)
            stage('metasim-run-'+config,[str(out/'VRegfile'),'+seed=8491167','+max-cycles=100000'],out,timeout=600,env=env)
        ST['metasimulation']='PASS_UPSTREAM_REGFILE_BOTH_PLATFORMS_NOT_FULL_OPT4'
    except Exception as e:
        ST['metasimulation']='FAILED_WITH_EVIDENCE';ST['metasimulation_error']=repr(e)
    # Measure all 4 raw boundaries with identical U280 OOC synthesis conditions.
    for label in ['4r2w64','35r1w81']:
        root=L/label
        for kind,top in [('reference','AsyncMemChiselRTL'),('model','AsyncMemChiselModel')]:
            out=root/kind;tcl=out/'map.tcl';report=out/'utilization.rpt'
            tcl.write_text('set_param general.maxThreads 2\nread_verilog {'+str(out/(top+'.v'))+'}\nsynth_design -mode out_of_context -top '+top+' -part xcu280-fsvh2892-2L-e\nreport_utilization -file {'+str(report)+'}\nreport_utilization -hierarchical -file {'+str(out/'hierarchical.rpt')+'}\nwrite_checkpoint -force {'+str(out/'module.dcp')+'}\nexit 0\n')
            stage(label+'-map-'+kind,['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'vivado.log'),'-source',str(tcl)],out,[report,out/'module.dcp'],timeout=3600,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
            ST['results'][label][kind]=dict(resources=parse_area(report),report=str(report),sha256=sha(report))
            update()
        r=ST['results'][label];r['lut_saved']=r['reference']['resources']['CLB LUTs']-r['model']['resources']['CLB LUTs']
        r['scope']='Actual Golden Gate library RAM boundary, not complete EC/DCache/whole FIT; randomized target-boundary comparison, not universal formal equivalence.'
        save(root/'result.json',r)
    update(status='COMPLETE_LOCAL_PROTOTYPES',completed_utc=now())
    save(L/'result.json',ST)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        if L.exists():update(status='FAILED_WITH_EVIDENCE',error=repr(exc));save(L/'failure.json',ST)
        raise
