#!/usr/bin/python3
"""Independent recovery: use Verilator's configured Clang compiler consistently.
Preserve the first GCC/Clang flag failure and all live boundary area jobs.
"""
import importlib.util, json, os, pathlib, shutil
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-metasim-r4-20261111';m.S=m.L/'state.json'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'

def main():
    m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
    m.ST.update(schema='ec-opt4-goldengate-metasim/1',**m.ident(os.getpid()),functional_baseline=m.BASE,
        fpga_access=False,started_utc=m.now(),scope='Actual Golden Gate host RTL metasimulation; memory prototypes are not complete EC performance or proof.')
    cfg=m.read(m.W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    classes=m.D/'cycleprecise-route-a-r2-20261111/classes'
    cp=str(classes)+':'+':'.join(cfg['classpath']);java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',cp]
    target=m.L/'probe-target';target.mkdir(exist_ok=True)
    m.stage('probe-target',java+['freechips.rocketchip.system.Generator','--target-dir',str(target),'--name','Probe','--top-module','opt4spacetime.Probe','--configs','firesim.midasexamples.NoConfig'],C,[target/'Probe.fir',target/'Probe.anno.json'])
    driver=m.L/'TestProbe.cc'
    driver.write_text(r'''#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <chrono>
#include <iostream>
class TestProbe final: public TestHarness {
public: using TestHarness::TestHarness;
void run_test() override {
 log=false; target_reset(); mpz_t value;mpz_init(value);
 for(unsigned a=0;a<512;a++){
  poke("io_writeAddress",a);mpz_set_ui(value,0x10000000u+a);mpz_setbit(value,80);
  poke("io_writeData",value);poke("io_writeEnable",1);step(1);
 }
 poke("io_writeEnable",0);
 for(unsigned t=0;t<64;t++){
  std::array<unsigned,35> addresses;
  for(int i=0;i<35;i++){addresses[i]=random()%512;poke("io_address_"+std::to_string(i),addresses[i]);}
  step(1);
  for(int i=0;i<35;i++){mpz_set_ui(value,0x10000000u+addresses[i]);mpz_setbit(value,80);expect("io_data_"+std::to_string(i),value);}
 }
 auto &clk=get_bridge<clockmodule_t>();uint64_t host0=clk.hcycle();
 auto start=std::chrono::steady_clock::now();step(10000);
 double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
 uint64_t hosts=clk.hcycle()-host0;
 std::cout<<"SPACE_TIME_RESULT {\"checked_values\":2240,\"free_target_cycles\":10000,\"measured_host_cycles\":"<<hosts<<",\"fmr_including_counter_read_overhead\":"<<double(hosts)/10000<<",\"free_step_wall_seconds\":"<<wall<<",\"target_cycles_per_second\":"<<10000/wall<<"}\n";
 mpz_clear(value);
}};
TEST_MAIN(TestProbe)
''')
    for cfgname in ['PlainConfig','MCConfig']:
        out=m.L/cfgname;out.mkdir(exist_ok=True)
        m.stage('gg-'+cfgname,java+['midas.stage.GoldenGateMain','-i',str(target/'Probe.fir'),'-td',str(out),'-faf',str(target/'Probe.anno.json'),'-ggcp','opt4spacetime','-ggcs',cfgname,'--output-filename-base','FireSim-generated','--no-dedup'],C,[out/'FireSim-generated.sv',out/'FireSim-generated.const.h'])
        if not (out/'blackboxes-appended.json').exists():
            f=out/'firrtl_black_box_resource_files.f'
            if f.exists():
                with (out/'FireSim-generated.sv').open('a') as g:
                    for n in f.read_text().splitlines():
                        if n.strip():g.write(P(n).read_text())
            m.save(out/'blackboxes-appended.json',{'sha256':m.sha(out/'FireSim-generated.sv')})
        env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(m.V).parent)+':/usr/bin:/bin','CXX':CLANG,'LD_LIBRARY_PATH':'',
            'CXXFLAGS':'-O1 -I/usr/include/x86_64-linux-gnu -I'+str(m.FS/'src/main/cc/midasexamples'),'LDFLAGS':'-L/usr/lib/x86_64-linux-gnu -Wl,-rpath,/usr/lib/x86_64-linux-gnu'}
        m.stage('compile-'+cfgname,['/usr/bin/make','-C',str(m.FS/'midas/src/main/cc'),'-j2','verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=Probe','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated',
            'DRIVER='+str(m.FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(driver),
            'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+CLANG],C,[out/'VProbe'],env=env)
        m.stage('run-'+cfgname,[str(out/'VProbe'),'+seed=8491167','+max-cycles=100000'],out,timeout=900,env=env)
        log=(m.L/('run-'+cfgname+'.log')).read_text()
        assert '[Probe]PASS Test' in log and '[Probe]FAIL' not in log
        line=next(s for s in log.splitlines() if s.startswith('SPACE_TIME_RESULT '))
        m.ST.setdefault('results',{})[cfgname]=dict(metrics=json.loads(line.split(' ',1)[1]),target_fir_sha256=m.sha(target/'Probe.fir'),target_anno_sha256=m.sha(target/'Probe.anno.json'),host_rtl_sha256=m.sha(out/'FireSim-generated.sv'))
        m.update()
    assert m.ST['results']['PlainConfig']['target_fir_sha256']==m.ST['results']['MCConfig']['target_fir_sha256']
    m.update(status='PASS_SAME_TARGET_GOLDENGATE_BOTH_HOST_CONFIGS_NOT_FULL_OPT4')
    m.save(m.L/'result.json',m.ST)

if __name__=='__main__':
    try:main()
    except Exception as e:
        m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
