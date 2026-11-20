#!/usr/bin/python3
"""Put the exact original SVB FIRRTL behind Golden Gate's PeekPoke bridge.

Module bytes are copied verbatim, not reimplemented. This first gate is CPU
metasimulation; only its separately verified host collateral can feed a later
standalone FPGA experiment. It is not a complete Opt4 implementation.
"""
import copy, importlib.util, json, os, pathlib, re, shutil
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-svb-gg-r2-20261111';m.S=m.L/'state.json'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'

def leaves(typ):
 tokens=re.findall(r'flip|UInt|SInt|[A-Za-z_]\w*|\d+|[{}:,<>\[\]]',typ);pos=0
 def take(s=None):
  nonlocal pos
  t=tokens[pos];pos+=1
  if s is not None:assert t==s,(t,s)
  return t
 def parse():
  if tokens[pos]=='{':
   take('{');fields=[]
   while tokens[pos]!='}':
    flip=0
    if tokens[pos]=='flip':take();flip=1
    name=take();take(':');node=parse();fields.append((name,flip,node))
    if tokens[pos]==',':take(',')
   take('}');node=('bundle',fields)
  else:
   take('UInt');take('<');width=int(take());take('>');node=('uint',width)
  while pos<len(tokens) and tokens[pos]=='[':
   take('[');n=int(take());take(']');node=('array',n,node)
  return node
 tree=parse();assert pos==len(tokens)
 result=[]
 def flatten(node,path,output):
  if node[0]=='uint':result.append((path,node[1],output))
  elif node[0]=='array':
   for i in range(node[1]):flatten(node[2],path+'['+str(i)+']',output)
  else:
   for name,flip,child in node[1]:flatten(child,path+'.'+name,output^bool(flip))
 flatten(tree,'io',True);return result

def main():
 m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 m.ST.update(schema='ec-original-svb-goldengate/1',**m.ident(os.getpid()),functional_baseline=m.BASE,
  started_utc=m.now(),fpga_access=False,complete_opt4=False,architectural_restart_tested=False)
 cfg=m.read(m.W/'candidates/dcache-field-read-system-r1-20261111/config.json')
 fir=m.W/'builds/C4-elaborate-20261106T100250.032318Z/firesim.firesim.FireSim.fir'
 original=fir.read_text()
 module=re.search(r'^  module SpeculativeVersionBuffer :\n.*?(?=^  (?:ext)?module |\Z)',original,re.M|re.S)[0]
 assert not re.findall(r'^    inst ',module,re.M),'unexpected missing module dependency'
 typ=re.search(r'^    output io : (.*)$',module,re.M)[1];ports=leaves(typ)
 top='SVBProbe'
 parts=['FIRRTL version 1.1.0\ncircuit '+top+' :\n',
  '  extmodule RationalClockBridge :\n    output clocks : Clock[1]\n    defname = RationalClockBridge\n\n',module,
  '  extmodule PeekPokeBridge :\n    input io : '+typ+'\n    output reset : UInt<1>\n    input clock : Clock\n    defname = PeekPokeBridge\n\n',
  '  module '+top+' :\n    inst RationalClockBridge of RationalClockBridge\n    inst dut of SpeculativeVersionBuffer\n    inst peekPokeBridge of PeekPokeBridge\n    dut.clock <= RationalClockBridge.clocks[0]\n    dut.reset <= peekPokeBridge.reset\n    peekPokeBridge.clock <= RationalClockBridge.clocks[0]\n']
 for path,width,output in ports:
  parts.append('    '+('peekPokeBridge.'+path+' <= dut.'+path if output else 'dut.'+path+' <= peekPokeBridge.'+path)+'\n')
 target=m.L/'SVBProbe.fir';target.write_text('\n'.join(parts))
 # Byte-identical functional module is the fundamental extraction invariant.
 assert re.search(r'^  module SpeculativeVersionBuffer :\n.*?(?=^  (?:ext)?module |\Z)',target.read_text(),re.M|re.S)[0].rstrip()==module.rstrip()
 probe=m.read(m.D/'cycleprecise-metasim-r6-20261111/probe-target/Probe.anno.json')
 clk=copy.deepcopy(next(a for a in probe if a.get('target')=='~Probe|RationalClockBridge'))
 clk=json.loads(json.dumps(clk).replace('~Probe|','~'+top+'|'))
 channels=[];peeks=[];pokes=[]
 for path,width,output in [('reset',1,False)]+ports:
  name=re.sub(r'[.\[\]]','_',path).replace('__','_').rstrip('_')
  ref='~'+top+'|PeekPokeBridge>'+path
  channels.append(dict(class_='midas.widgets.PipeBridgeChannel',name=name,clock='~'+top+'|PeekPokeBridge>clock',
   sinks=[] if output else [ref],sources=[ref] if output else [],latency=0))
  channels[-1]['class']=channels[-1].pop('class_')
  (peeks if output else pokes).append(dict(name=name,tpe=dict(typeString='UInt'),fieldWidth=width))
 bridge={'class':'midas.widgets.BridgeAnnotation','target':'~'+top+'|PeekPokeBridge','bridgeChannels':channels,
  'widgetClass':'midas.widgets.PeekPokeBridgeModule','widgetConstructorKey':{'class':'midas.widgets.PeekPokeKey','peeks':peeks,'pokes':pokes,'maxChannelDecoupling':2}}
 # Constructor class name comes from this exact installed FireSim version.
 proto=next(a for a in probe if a.get('target')=='~Probe|PeekPokeBridge')
 bridge['widgetConstructorKey']['class']=proto['widgetConstructorKey']['class']
 anno=m.L/'SVBProbe.anno.json';m.save(anno,[clk,bridge])
 import hashlib
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,target_fir=str(fir),target_fir_sha256=m.sha(fir),
  extracted_module_sha256=hashlib.sha256(module.encode()).hexdigest(),module_bytes=len(module.encode()),
  extracted_module_verbatim=True,wrapper_only=True,ports=ports,target_sha256=m.sha(target),annotations_sha256=m.sha(anno),
  scope='Original complete SVB32 target module with all debug outputs retained; synthetic directed stimuli, not complete EC or architectural rollback/restart.'))
 out=m.L/'goldengate';out.mkdir(exist_ok=True)
 # Reuse this exact successful compiler output. Only the failed C++ transport
 # is repaired; no repeated GG pass and no target/host RTL modifications.
 old=m.D/'cycleprecise-frozen-svb-gg-r1-20261111'
 receipt=m.read(old/'receipts/goldengate.json');assert receipt['returncode']==0
 reused={}
 for name in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
  src=old/'goldengate'/name;dst=out/name
  if not dst.exists():shutil.copy2(src,dst)
  assert m.sha(dst)==m.sha(src);reused[str(dst)]=m.sha(dst)
 m.save(m.L/'receipts/goldengate.json',dict(stage='goldengate',returncode=0,outputs=reused,reused_from=str(old/'receipts/goldengate.json'),parent_receipt_sha256=m.sha(old/'receipts/goldengate.json'),target_fir_unchanged=True,host_rtl_unchanged=True))

 java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true','-cp',':'.join(cfg['classpath'])]
 m.stage('goldengate',java+['midas.stage.GoldenGateMain','-i',str(target),'-td',str(out),'-faf',str(anno),
  '-ggcp','firesim.configs','-ggcs','DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],m.L,
  [out/'FireSim-generated.sv',out/'FireSim-generated.const.h'],timeout=7200)
 # The test body is identical to the repaired frozen-contract direct RTL test.
 # MMIO proxies change transport only; tick alone advances target time.
 base=m.D/'cycleprecise-frozen-svb-r3-20261111'
 sim=m.read(base/'simulation-result.json');assert sim['cases']==16 and sim['target_cycles']==333
 body=(base/'recovery_component.cpp').read_text().split('unsigned cycle=0,passed=0;',1)[1].split('d.final();',1)[0]
 old='auto tick=[&](){d.clock=0;d.io_diagnosticCycle=cycle;d.eval();d.clock=1;d.eval();cycle++;d.clock=0;d.eval();};'
 assert old in body;body=body.replace(old,'auto tick=[&](){d.io_diagnosticCycle=cycle;step(1);cycle++;};').replace('d.eval();','')
 adapter=r'''
#include "TestHarness.h"
#include "bridges/clock.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
static void require(bool b,const char*s){if(!b)throw std::runtime_error(s);}
struct Signal {
 TestHarness&t;std::string name;unsigned width;mpz_t cached;
 Signal(TestHarness&t,std::string name,unsigned width):t(t),name(name),width(width){mpz_init(cached);}
 ~Signal(){mpz_clear(cached);}
 Signal&operator=(uint64_t x){mpz_import(cached,1,-1,sizeof(x),0,0,&x);if(width<=32)t.poke(name,uint32_t(x));else{t.peek("io_occupancy");t.poke(name,cached);}return *this;}
 Signal&operator=(Signal&x){return operator=(uint64_t(x));}
 operator uint64_t(){if(width<=32)return t.peek(name);t.peek("io_occupancy");mpz_t x;mpz_init(x);t.peek(name,x);uint64_t r=mpz_get_ui(x);mpz_clear(x);return r;}
 struct Word{Signal&s;int i;
  void operator=(uint32_t v){for(int b=0;b<32;b++){if((v>>b)&1)mpz_setbit(s.cached,32*i+b);else mpz_clrbit(s.cached,32*i+b);}s.t.poke(s.name,s.cached);}
  operator uint32_t(){s.t.peek("io_occupancy");mpz_t x;mpz_init(x);s.t.peek(s.name,x);mpz_fdiv_q_2exp(x,x,32*i);uint32_t r=mpz_get_ui(x);mpz_clear(x);return r;}
 };
 Word operator[](int i){return Word{*this,i};}
};
'''
 widths={'reset':1,**{re.sub(r'[.\[\]]','_',p).replace('__','_').rstrip('_'):w for p,w,_ in ports}}
 names=['reset']+[re.sub(r'[.\[\]]','_',p).replace('__','_').rstrip('_') for p,_,_ in ports]
 adapter+='struct Interface {\n'+''.join(' Signal '+n+';\n' for n in names)
 adapter+=' Interface(TestHarness&t):'+','.join(n+'(t,"'+n+'",'+str(widths[n])+')' for n in names)+'{}\n};\n'
 adapter+='class SVBTest final:public TestHarness{public:using TestHarness::TestHarness;void run_test()override{log=false;Interface d(*this);unsigned cycle=0,passed=0;\n'+body
 adapter+='''
auto&clk=get_bridge<clockmodule_t>();uint64_t start=clk.hcycle();
auto begin=std::chrono::steady_clock::now();step(10000);
double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-begin).count();
std::cout<<"SVB_HOST_MODEL_FREE_RUN target_cycles=10000 host_cycles="<<clk.hcycle()-start<<" wall_seconds="<<wall<<"\\n";
}};TEST_MAIN(SVBTest)
'''
 driver=m.L/'SVBTest.cc';driver.write_text(adapter)
 inc=m.L/'external-headers';inc.mkdir(exist_ok=True);shutil.copy2('/usr/include/x86_64-linux-gnu/gmp.h',inc/'gmp.h')
 libs=m.L/'external-libs';libs.mkdir(exist_ok=True)
 if not (libs/'libgmp.so').exists():(libs/'libgmp.so').symlink_to('/usr/lib/x86_64-linux-gnu/libgmp.so')
 env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(m.V).parent)+':/usr/bin:/bin','CXX':CLANG,
  'CXXFLAGS':'-O1 -I'+str(inc)+' -I'+str(m.FS/'src/main/cc/midasexamples'),
  'LDFLAGS':'-L'+str(libs)+' -Wl,-rpath,'+str(libs),'LD_LIBRARY_PATH':''}
 m.stage('compile',['/usr/bin/make','-C',str(m.FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo',
  'DRIVER_NAME=SVBProbe','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated',
  'DRIVER='+str(m.FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(driver),
  'VERILATOR_FLAGS=--compiler clang -Wno-fatal -Wno-MULTIDRIVEN','CXX='+CLANG],m.L,[out/'VSVBProbe'],env=env,timeout=14400)
 m.stage('run',[str(out/'VSVBProbe'),'+seed=8491167','+max-cycles=100000'],out,env=env,timeout=1800)
 log=(m.L/'run.log').read_text()
 assert 'cases=16 cycles=333' in log and '[SVBProbe]PASS Test' in log and '[SVBProbe]FAIL' not in log
 m.update(status='PASS_ORIGINAL_SVB_GOLDENGATE_DIRECTED_METASIM_NOT_ONBOARD',cases=16,target_cycles=333,
  host_rtl_sha256=m.sha(out/'FireSim-generated.sv'),driver_sha256=m.sha(driver),
  next='Measure standalone host design/shell ABI; reuse only matching 11 shell IP DCPs, require timing/DRC/certification and 21-only safety boundary before any board run. Real-event trace payload is a separate missing prerequisite.')
 m.save(m.L/'result.json',m.ST)

if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
