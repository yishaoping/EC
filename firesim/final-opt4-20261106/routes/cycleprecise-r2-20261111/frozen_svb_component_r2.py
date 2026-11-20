#!/usr/bin/python3
"""Fresh original SVB simulation + area, explicitly excludes architectural restart."""
import importlib.util,os,pathlib,json,re,shutil
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-svb-r2-20261111';m.S=m.L/'state.json'
ROOT=P('/data1/gzh/EC/slowdown/streamcluster_aggressive/variants/preservation_svb32_permission')
def main():
 m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 m.ST.update(schema='ec-original-svb-component/1',**m.ident(os.getpid()),functional_baseline=m.BASE,started_utc=m.now(),fpga_access=False,full_architectural_rollback=False)
 generated=ROOT/'experiments/build/overlap_c2_svb32_permission_private_20261105_175448_d37fdde7/generated/gen-collateral'
 recipe=m.read(P('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106/data/BUILD_RECIPE.json'))
 assert recipe['source']['git_head']==m.BASE and recipe['source']['n_svb_entries']==32
 for n in ['chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala','chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v']:
  assert m.sha(ROOT/n)==recipe['source']['hardware_sha256'][n]
 source=generated/'SpeculativeVersionBuffer.sv';assert re.search(r'reg\s+valid_31\s*;',source.read_text())
 for n in ['SpeculativeVersionBuffer.sv','SafeChainEventLogger.v']:
  dest=m.L/n
  if not dest.exists():shutil.copy2(generated/n,dest)
  assert m.sha(dest)==m.sha(generated/n)
 driver=ROOT/'slowdown/parsec_evaluation_20261103/scripts/recovery_component.cpp';dst=m.L/'recovery_component.cpp'
 text=driver.read_text()
 # The actual frozen emitted module has optimized out unused currentEpoch.
 assert 'io_currentEpoch' not in source.read_text() and text.count('d.io_currentEpoch=1;')==1
 text=text.replace('d.io_currentEpoch=1;','')
 if not dst.exists():dst.write_text(text)
 assert dst.read_text()==text
 m.save(m.L/'harness-adaptation.json',{'original_driver':str(driver),'original_sha256':m.sha(driver),'actual_driver_sha256':m.sha(dst),'change':'Remove only assignment to unused currentEpoch port absent from exact emitted RTL; no DUT or executed stimulus change.'})
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,source_and_driver_sha256={str(p):m.sha(p) for p in [source,generated/'SafeChainEventLogger.v',driver]},SVB_entries=32,scope='Full original emitted SVB; original input stimulus. Invalidation/flush/ACK ownership tests, no checker error injection or architectural rollback/restart. Synthetic directed workload, not application performance.'))
 binary=m.L/'obj/VSpeculativeVersionBuffer'
 env={**os.environ,'PATH':'/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin:/usr/bin:/bin','LD_LIBRARY_PATH':''}
 m.stage('compile',[m.V,'--cc','--exe','--build','-j','2','--assert','-Wno-fatal','--top-module','SpeculativeVersionBuffer','--Mdir',str(binary.parent),str(m.L/'SpeculativeVersionBuffer.sv'),str(m.L/'SafeChainEventLogger.v'),str(dst)],m.L,[binary],timeout=1800,env=env)
 m.stage('run',[str(binary)],m.L,timeout=60,env=env)
 log=(m.L/'run.log').read_text();hit=re.search(r'PASS emitted_SVB_component cases=(\d+) cycles=(\d+)',log);assert hit and 'integrated_fault_recovery=NOT_TESTED' in log
 m.update(status='PASS_ORIGINAL_SVB_DIRECTED_COMPONENT',cases=int(hit[1]),target_cycles=int(hit[2]),limitations=[s for s in log.splitlines() if s.startswith('OBSERVED_LIMITATION')])
 m.save(m.L/'simulation-result.json',m.ST)
 # This real unchanged SVB is a prospective standalone FPGA target; only area
 # here, no shell or board claim, and no disabled assertions used as a pass.
 tcl=m.L/'map.tcl';report=m.L/'utilization.rpt'
 tcl.write_text('set_param general.maxThreads 2\nread_verilog -sv {'+str(m.L/'SafeChainEventLogger.v')+'}\nread_verilog -sv {'+str(m.L/'SpeculativeVersionBuffer.sv')+'}\nsynth_design -mode out_of_context -top SpeculativeVersionBuffer -part xcu280-fsvh2892-2L-e\nset bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]\nif {[llength $bb]} {error "unresolved dependencies"}\nreport_utilization -file {'+str(report)+'}\nwrite_checkpoint -force {'+str(m.L/'module.dcp')+'}\nexit 0\n')
 m.stage('area',['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(m.L/'vivado.log'),'-source',str(tcl)],m.L,[report,m.L/'module.dcp'],env=env,timeout=3600)
 m.update(status='PASS_ORIGINAL_SVB_COMPONENT_AND_OOC_AREA_NOT_ONBOARD',resources=m.parse_area(report),report_sha256=m.sha(report))
 m.save(m.L/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
