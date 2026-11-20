#!/usr/bin/python3
"""Cycle-boundary comparison: original SVB RTL -> exact GG host model.

Write every input once per target cycle, as required by PeekPoke token channels.
All original outputs are retained and checked after deterministic initialization.
This is a directed component trace, not an application memory trace.
"""
import hashlib, importlib.util, os, pathlib, re, shutil
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-svb-trace-r3-20261111';m.S=m.L/'state.json'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
def flat(s):return re.sub(r'[.\[\]]','_',s).replace('__','_').rstrip('_')
def main():
 m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 m.ST.update(schema='ec-original-svb-target-host-cycle-comparison/1',**m.ident(os.getpid()),functional_baseline=m.BASE,
  started_utc=m.now(),fpga_access=False,complete_opt4=False,architectural_restart_tested=False)
 cfg=m.read(m.W/'candidates/dcache-field-read-system-r1-20261111/config.json')
 origin=m.D/'cycleprecise-frozen-svb-gg-r1-20261111';b=m.read(origin/'binding.json')
 fir=P(b['target_fir']);assert m.sha(fir)==b['target_fir_sha256']
 whole=fir.read_text();module=re.search(r'^  module SpeculativeVersionBuffer :\n.*?(?=^  (?:ext)?module |\Z)',whole,re.M|re.S)[0]
 assert hashlib.sha256(module.encode()).hexdigest()==b['extracted_module_sha256']
 isolated=m.L/'original.fir';isolated.write_text('FIRRTL version 1.1.0\ncircuit SpeculativeVersionBuffer :\n'+module)
 ports=b['ports'];inputs=[('reset',1)]+[(flat(p),w) for p,w,o in ports if not o];outputs=[(flat(p),w) for p,w,o in ports if o]
 java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['classpath'])]
 sv=m.L/'SpeculativeVersionBuffer.v'
 m.stage('original-rtl',java+['firrtl.stage.FirrtlMain','-i',str(isolated),'-o',str(sv),'-X','verilog'],m.L,[sv],timeout=1800)
 env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(m.V).parent)+':/usr/bin:/bin','LD_LIBRARY_PATH':''}
 # The direct RTL driver still tests all frozen lifetime contracts. It now
 # emits inputs and combinational outputs just before each target clock edge.
 base=m.D/'cycleprecise-frozen-svb-r3-20261111/recovery_component.cpp'
 direct=base.read_text().replace('#include <cstdint>','#include <cstdint>\n#include <fstream>\n#include <iomanip>')
 direct=direct.replace('unsigned cycle=0,passed=0;','unsigned cycle=0,passed=0;std::ofstream trace("target-cycles.txt");')
 old='auto tick=[&](){d.clock=0;d.io_diagnosticCycle=cycle;d.eval();d.clock=1;d.eval();cycle++;d.clock=0;d.eval();};'
 lines=['auto tick=[&](){d.clock=0;d.io_diagnosticCycle=cycle;d.eval();trace<<std::dec<<cycle;']
 for name,width in inputs+outputs:
  if width<=64:lines.append('trace<<" "<<std::hex<<uint64_t(d.'+name+');')
  else:
   lines.append('trace<<" ";')
   for i in reversed(range((width+31)//32)):lines.append('trace<<std::hex<<std::setfill(\'0\')<<std::setw(8)<<d.'+name+'['+str(i)+'];')
 lines.append('trace<<"\\n";d.clock=1;d.eval();cycle++;d.clock=0;d.eval();};')
 assert old in direct;direct=direct.replace(old,'\n'.join(lines))
 needle=' for(unsigned timing=0;timing<12;timing++){'
 warm='''
 // Deterministically initialize every payload/key row and selected index.
 // No uninitialized debug bits are used as an equivalence premise.
 reset();for(unsigned i=0;i<32;i++)capture(i+1,100+i,0xa000+i*16);
 d.io_safeWatermark=100;tick();tick();d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();
 require(d.io_occupancy==0,"warmup did not drain");
 std::cout<<"TRACE_COMPARE_FROM cycle="<<cycle<<"\\n";
'''
 assert needle in direct;direct=direct.replace(needle,warm+needle)
 cpp=m.L/'direct.cpp';cpp.write_text(direct)
 binary=m.L/'obj/VSpeculativeVersionBuffer'
 m.stage('compile-reference',[m.V,'--cc','--exe','--build','-j','2','--assert','-Wno-fatal','--top-module','SpeculativeVersionBuffer',
  '--Mdir',str(binary.parent),str(sv),str(cpp)],m.L,[binary],env=env,timeout=1800)
 m.stage('reference',[str(binary)],m.L,[m.L/'target-cycles.txt'],env=env,timeout=120)
 text=(m.L/'reference.log').read_text();h=re.search(r'TRACE_COMPARE_FROM cycle=(\d+)',text);done=re.search(r'cases=(\d+) cycles=(\d+)',text)
 assert h and done and int(done[1])==16;first=int(h[1]);cycles=int(done[2])
 trace=m.L/'target-cycles.txt';rows=trace.read_text().splitlines();assert len(rows)==cycles and all(len(s.split())==1+len(inputs)+len(outputs) for s in rows)
 out=m.L/'goldengate';out.mkdir(exist_ok=True)
 receipt=m.read(origin/'receipts/goldengate.json');assert receipt['returncode']==0
 for n in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
  p=origin/'goldengate'/n;dst=out/n
  if not dst.exists():shutil.copy2(p,dst)
  assert m.sha(dst)==m.sha(p)
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,original_module_sha256=b['extracted_module_sha256'],
  original_target_sha256=m.sha(isolated),reference_rtl_sha256=m.sha(sv),reference_driver_sha256=m.sha(cpp),
  host_rtl_sha256=m.sha(out/'FireSim-generated.sv'),host_parent_receipt_sha256=m.sha(origin/'receipts/goldengate.json'),
  trace_sha256=m.sha(trace),trace_kind='SYNTHETIC_DIRECTED_ORIGINAL_COMPONENT_TRACE_NOT_APPLICATION',
  input_ports=inputs,output_ports=outputs,compare_from_cycle=first,target_cycles=cycles,
  scope='Exact original SVB FIRRTL direct RTL versus unchanged Golden Gate host RTL, no input repoking within a target cycle.'))
 driver=m.L/'TraceTest.cc'
 source=r'''
#include "TestHarness.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
class TraceTest final:public TestHarness {
bool negative=false;
public:TraceTest(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n){for(auto&s:a)if(s=="+negative")negative=true;}
void run_test()override{log=false;
std::ifstream f("TRACEPATH");std::string text;mpz_t value,got;mpz_init(value);mpz_init(got);
uint64_t checks=0;unsigned rows=0;
const char* inputs[]={INPUTS};const char* outputs[]={OUTPUTS};
while(f>>rows){
 for(auto n:inputs){f>>text;if(!f||mpz_set_str(value,text.c_str(),16))throw std::runtime_error("input trace corruption");poke(n,value);}
 // Synchronize all output tokens, not just the first MMIO data read.
 peek("io_occupancy");
 unsigned index=0;
 for(auto n:outputs){f>>text;if(!f||mpz_set_str(value,text.c_str(),16))throw std::runtime_error("output trace corruption");
  peek(n,got);
  if(rows>=FIRST){
   if(negative&&rows==FIRST+1&&index==0)mpz_combit(value,0);
   if(mpz_cmp(got,value)){std::cerr<<"TARGET_HOST_MISMATCH cycle="<<rows<<" port="<<n<<" expected="<<mpz_get_str(nullptr,16,value)<<" actual="<<mpz_get_str(nullptr,16,got)<<"\n";throw std::runtime_error("target boundary mismatch");}
   checks++;
  }index++;
 }
 step(1);
}
std::cout<<"PASS_SVB_TRACE target_cycles="<<cycles()<<" compared_fields="<<checks<<" compare_from="<<FIRST<<"\n";
mpz_clear(value);mpz_clear(got);
}};TEST_MAIN(TraceTest)
'''
 source=source.replace('TRACEPATH',str(trace)).replace('INPUTS',','.join('"'+n+'"' for n,w in inputs)).replace('OUTPUTS',','.join('"'+n+'"' for n,w in outputs)).replace('FIRST',str(first))
 driver.write_text(source)
 inc=m.L/'external-headers';inc.mkdir(exist_ok=True);shutil.copy2('/usr/include/x86_64-linux-gnu/gmp.h',inc/'gmp.h')
 libs=m.L/'external-libs';libs.mkdir(exist_ok=True)
 if not (libs/'libgmp.so').exists():(libs/'libgmp.so').symlink_to('/usr/lib/x86_64-linux-gnu/libgmp.so')
 env.update(CXX=CLANG,CXXFLAGS='-O1 -I'+str(inc)+' -I'+str(m.FS/'src/main/cc/midasexamples'),LDFLAGS='-L'+str(libs)+' -Wl,-rpath,'+str(libs))
 m.stage('compile-host',['/usr/bin/make','-C',str(m.FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo',
  'DRIVER_NAME=SVBProbe','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated',
  'DRIVER='+str(m.FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(driver),
  'VERILATOR_FLAGS=--compiler clang -Wno-fatal -Wno-MULTIDRIVEN','CXX='+CLANG],m.L,[out/'VSVBProbe'],env=env,timeout=14400)
 m.stage('compare',[str(out/'VSVBProbe'),'+seed=8491167'],out,env=env,timeout=1800)
 good=(m.L/'compare.log').read_text();assert 'PASS_SVB_TRACE' in good and '[SVBProbe]PASS Test' in good and 'unstable value' not in good
 m.stage('negative',[str(out/'VSVBProbe'),'+seed=8491167','+negative'],out,env=env,timeout=1800,expected=-6)
 assert 'TARGET_HOST_MISMATCH' in (m.L/'negative.log').read_text()
 m.update(status='PASS_ORIGINAL_SVB_ALL_DEFINED_OUTPUT_CYCLE_TRACE_AND_MUTATION_NOT_ONBOARD',target_cycles=cycles,
  compare_from_cycle=first,output_ports=len(outputs),compared_output_values=(cycles-first)*len(outputs),negative_rejected=True)
 m.save(m.L/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
