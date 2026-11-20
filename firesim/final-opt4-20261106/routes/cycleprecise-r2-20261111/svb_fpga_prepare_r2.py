#!/usr/bin/python3
"""Independent original-SVB FPGA artifact path. No board access.

Reuse the known shell only after an identical physical port ABI and a metasim
trace pass. Bound this small component job; keep both whole-DUT CADs untouched.
"""
import hashlib, importlib.util, json, os, pathlib, re, shutil
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-svb-fpga-r2-20261111';m.S=m.L/'state.json'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
def ports(text):
 h=re.search(r'^module FPGATop\s*\((.*?)\);',text,re.M|re.S);assert h
 result={};direction=width=''
 for chunk in h[1].split(','):
  s=re.sub(r'//[^\n]*','',chunk).strip();hit=re.match(r'(input|output|inout)\s+(.*)',s,re.S)
  if hit:direction=hit[1];s=hit[2];width=''
  hit=re.match(r'(\[[^\]]+\])\s*(.*)',s,re.S)
  if hit:width=hit[1];s=hit[2]
  name=s.strip();assert re.fullmatch(r'\w+',name),(chunk,name)
  assert name not in result;result[name]=(direction,re.sub(r'\s+','',width))
 return h,result
def main():
 m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 m.ST.update(schema='ec-original-svb-fpga-preparation/1',**m.ident(os.getpid()),functional_baseline=m.BASE,
  started_utc=m.now(),fpga_access=False,complete_opt4=False)
 parent=m.D/'cycleprecise-frozen-svb-trace-r4-20261111';r=m.read(parent/'result.json');binding=m.read(parent/'binding.json')
 assert r['status'].startswith('PASS_') and r['negative_rejected'] and r['compared_output_values']==42291
 assert binding['functional_baseline']==m.BASE
 raw=parent/'goldengate';producer=m.D/'cycleprecise-frozen-svb-gg-r1-20261111/goldengate';text=(raw/'FireSim-generated.sv').read_text()
 assert m.sha(raw/'FireSim-generated.sv')==binding['host_rtl_sha256']
 shell=m.W/'dcp-work/C4-dcp-20261110T071734Z'
 reference=(shell/'design/FireSim-generated.sv').read_text();header,abi=ports(reference);small_header,small=ports(text)
 assert all(k in abi and abi[k]==v for k,v in small.items())
 assert all(k in small for k in abi if k.startswith('ctrl_') or k in ['clock','reset'])
 assert all(k.startswith(('mem_0_','cpu_managed_axi4_')) for k in abi if k not in small)
 # A host-shell adapter only: unchanged generated model on the control port;
 # unused external memory/DMA initiators remain idle. No target RTL change.
 text=text[:small_header.start()]+text[small_header.start():].replace('module FPGATop','module SVBHostFPGATop',1)
 wrapper='\n'+header[0]+'\n SVBHostFPGATop model('+', '.join('.'+k+'('+k+')' for k in small)+');\n'
 tied=[]
 for k,(direction,width) in abi.items():
  if k not in small and direction=='output':wrapper+=' assign '+k+" = '0;\n";tied.append(k)
 wrapper+='endmodule\n'
 # F1Shim has a fixed external ABI but its internal memory/DMA wiring differs.
 # Reuse the full shell shim verbatim to connect the idle adapter ports.
 old_shim=re.search(r'^module F1Shim\b.*?^endmodule',text,re.M|re.S);assert old_shim
 full_shim=re.search(r'^module F1Shim\b.*?^endmodule',reference,re.M|re.S);assert full_shim
 assert re.sub(r'\s+','',old_shim[0].split(');',1)[0])==re.sub(r'\s+','',full_shim[0].split(');',1)[0])
 text=text[:old_shim.start()]+full_shim[0]+text[old_shim.end():]
 out=m.L/'goldengate';out.mkdir(exist_ok=True);(out/'FireSim-generated.sv').write_text(text+wrapper)
 for name in ['FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
  shutil.copy2(raw/name,out/name)
 # Collateral comes from the original, hash-identical GG producer. The extra
 # host-only adapter hierarchy requires an explicit constraint-path relocation.
 assert m.sha(producer/'FireSim-generated.sv')==binding['host_rtl_sha256']
 for name in ['FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']:
  constraints=(producer/name).read_text()
  if name.endswith('implementation.xdc'):
   assert constraints.count('top/sim/target/')==1
   constraints=constraints.replace('top/sim/target/','top/model/sim/target/')
  (out/name).write_text(constraints)
 m.save(m.L/'host-adapter-constraints.json',dict(original_collateral=str(producer),
  producer_rtl_sha256=m.sha(producer/'FireSim-generated.sv'),full_shell_shim_sha256=hashlib.sha256(full_shim[0].encode()).hexdigest(),
  changes='Host-only wrapper model hierarchy, full ABI shim, unused AXI outputs idle; target module unchanged',
  original_xdc_sha256={n:m.sha(producer/n) for n in ['FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']},
  adapted_xdc_sha256={n:m.sha(out/n) for n in ['FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']}))
 assert ports((out/'FireSim-generated.sv').read_text())[1]==abi
 assert (out/'FireSim-generated.defines.vh').read_bytes()==(shell/'design/FireSim-generated.defines.vh').read_bytes()
 manifest=dict(functional_baseline=m.BASE,profile='OriginalSVB32-component-trace',complete_opt4=False,
  target_binding_sha256=m.sha(parent/'binding.json'),cycle_proof_sha256=m.sha(parent/'result.json'),
  original_host_rtl_sha256=binding['host_rtl_sha256'],adapted_host_rtl_sha256=m.sha(out/'FireSim-generated.sv'),
  physical_shell_abi_identical=True,all_original_control_connections_direct=True,unused_shell_outputs_tied_idle=tied,
  fpga_access=False,large_whole_dut_job=False,cpu_quota=2,memory_limit_gib=32,
  deployment_admission=False,trace_kind='DIRECTED_COMPONENT_TRACE_NOT_APPLICATION')
 sid=hashlib.sha256(json.dumps(manifest,sort_keys=True).encode()).hexdigest();manifest['source_id']=sid;m.save(m.L/'binding.json',manifest)
 inc=m.L/'external-headers';inc.mkdir(exist_ok=True);shutil.copy2('/usr/include/x86_64-linux-gnu/gmp.h',inc/'gmp.h')
 libs=m.L/'external-libs';libs.mkdir(exist_ok=True)
 if not (libs/'libgmp.so').exists():(libs/'libgmp.so').symlink_to('/usr/lib/x86_64-linux-gnu/libgmp.so')
 env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(m.V).parent)+':/usr/bin:/bin','CXX':CLANG,
  'CXXFLAGS':'-O1 -I'+str(inc)+' -I'+str(m.FS/'src/main/cc/midasexamples'),
  'LDFLAGS':'-L'+str(libs)+' -Wl,-rpath,'+str(libs),'LD_LIBRARY_PATH':'','PYTHONPATH':str(m.W/'scripts')}
 common=['/usr/bin/make','-C',str(m.FS/'midas/src/main/cc'),'-j2','PLATFORM=xilinx_alveo_u280',
  'DRIVER_NAME=SVBProbe','GEN_DIR='+str(out),'GEN_FILE_BASENAME=FireSim-generated',
  'DRIVER='+str(m.FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(parent/'TraceTest.cc'),'CXX='+CLANG]
 m.stage('adapter-metasim',common+['verilator','VERILATOR_FLAGS=--compiler clang -Wno-fatal -Wno-MULTIDRIVEN'],m.L,[out/'VSVBProbe'],env=env,timeout=3600)
 m.stage('adapter-compare',[str(out/'VSVBProbe'),'+seed=8491167'],out,env=env,timeout=1800)
 log=(m.L/'adapter-compare.log').read_text();assert 'compared_fields=42291' in log and '[SVBProbe]PASS Test' in log and 'unstable value' not in log
 # Guard the hardware driver before any mmap/open of a PCI endpoint. Never run
 # it here; matching trace/driver/source hashes are recorded for later admission.
 driver=m.FS/'midas/src/main/cc/simif_xilinx_alveo_u280.cc';source=driver.read_text()
 needle='  fpga_setup(*domain_id,';assert source.count(needle)==1
 source=source.replace('#include <cassert>','#include <cassert>\n#include <stdexcept>')
 source=source.replace(needle,'  if (*domain_id != 0 || *bus_id != 0x21 || *device_id != 0 || *pf_id != 0 || *bar_id != 0) throw std::runtime_error("Only 0000:21:00.0 BAR0 is allowed");\n'+needle)
 guarded=m.L/'simif_xilinx_alveo_u280_21_only.cc';guarded.write_text(source)
 obj=out/'simif_xilinx_alveo_u280.o'
 m.stage('guarded-driver-object',[CLANG,'-O1','-std=c++20','-I'+str(inc),'-I'+str(m.FS/'midas/src/main/cc'),'-I'+str(out),
  '-include',str(out/'FireSim-generated.const.h'),'-c',str(guarded),'-o',str(obj)],m.L,[obj],env=env)
 objhash=m.sha(obj)
 m.stage('hardware-driver',common+['driver','MAIN=xilinx_alveo_u280'],m.L,[out/'SVBProbe-xilinx_alveo_u280'],env=env)
 assert m.sha(obj)==objhash,'Make unexpectedly replaced guarded platform object'
 m.save(m.L/'hardware-driver.json',dict(profile=manifest['profile'],source_id=sid,binary=str(out/'SVBProbe-xilinx_alveo_u280'),
  binary_sha256=m.sha(out/'SVBProbe-xilinx_alveo_u280'),guarded_source_sha256=m.sha(guarded),original_source_sha256=m.sha(driver),
  control_header_sha256=m.sha(out/'FireSim-generated.const.h'),trace_sha256=m.sha(parent/'target-cycles.txt'),board_allowlist=['0000:21:00.0'],executed=False))
 # Reuse the established shell/DCP/capacity/timing/DRC sequence in a separately
 # labelled component profile. It cannot be mistaken for a whole Opt4 receipt.
 project=m.L/'project';(project/'bindings').mkdir(parents=True,exist_ok=True)
 m.save(project/'bindings'/f'{m.BASE}.json',dict(source_id=sid,frozen_commit=m.BASE,profile=manifest['profile'],complete_opt4=False))
 outputs={str(out/n):m.sha(out/n) for n in ['FireSim-generated.sv','FireSim-generated.defines.vh','FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']}
 m.save(m.L/'rtl-state.json',dict(status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',hardware_commit=m.BASE,source_id=sid,goldengate_dir=str(out),
  outputs=outputs,configuration_matches_frozen_parameters=True,modified_class_origins_verified=True,
  configuration_scope='SVB32 component only, exact original module and cycle proof; not full C4'))
 template=m.W/'scripts/build_opt4_fit_cad.py';code=template.read_text()
 replacements={'COMMIT':repr(m.BASE),'F':'Path('+repr(str(project))+')','O':'Path('+repr(str(project/'cad'))+')',
  'L':'Path('+repr(str(m.L/'cad-logs'))+')','S':'Path('+repr(str(m.L/'cad-state.json'))+')','R':'Path('+repr(str(m.L/'rtl-state.json'))+')'}
 for key,value in replacements.items():
  code,count=re.subn(r'^'+key+r' = .*$',key+' = '+value,code,count=1,flags=re.M);assert count==1,key
 code=code.replace("D/'.opt4-fit-cad.lock'",'Path('+repr(str(m.L/'cad.instance.lock'))+')')
 code=code.replace("schema='ec-opt4-fit-whole-cad/1'","schema='ec-original-svb-component-cad/1'")
 code=code.replace("profile='Opt4-fit-C4-SVB32-20261110', configuration='DacOpt4C4'","profile='OriginalSVB32-component-trace', configuration='OriginalSVB32-component'")
 code=code.replace('general.maxThreads 2','general.maxThreads 2').replace("'OMP_NUM_THREADS':'8'","'OMP_NUM_THREADS':'2'")
 needle="    stage('implementation',f'source {{{bound}}}\\nputs \"EC_FIT_ROUTED\"\\nexit 0\\n',impldir,[routed,L/'top-postopt-utilization.rpt'])"
 assert needle in code
 wait='''    # Serialize physical implementation after the current whole-DUT opt pass.
    while True:
        active=[]
        for name in ['Opt4-fit-bucket-tag-cad-state.json','Opt4-fit-update-share-svb-cad-state.json']:
            p=D/name
            x=read(p) if p.exists() else {}
            if x.get('status') in ['RUNNING_IMPLEMENTATION','RUNNING_TIMING_BITSTREAM']:
                live=proc(x.get('pid',0))
                if live and live.get('start_ticks')==x.get('start_ticks'):active.append(name)
        if not active:break
        st.update(status='WAITING_FOR_WHOLE_IMPLEMENTATION_SAFE_CAD_BOUNDARY',blocking_states=active,updated_utc=now());save(S,st)
        time.sleep(300)
'''
 code=code.replace(needle,wait+needle)
 code=code.replace("admission='Separate derived profile; requires matching new host driver, 21-only safe boundary, smoke/checker/drain/correctness before formal sampling'", "admission='Original SVB32 component only. Not full Opt4. Matching guarded driver, component proof, 21-only safe deployment and correct trace replay required; no architectural rollback or PARSEC claim'")
 code=code.replace('general.maxThreads 8','general.maxThreads 2')
 code=code.replace("prefix=prefix.replace('set_param general.maxThreads 2','set_param general.maxThreads 2')","prefix=prefix.replace('set_param general.maxThreads 2','set_param general.maxThreads 2')")
 script=m.L/'component_cad.py';script.write_text(code);compile(code,str(script),'exec')
 m.save(m.L/'cad-adaptation.json',dict(template=str(template),template_sha256=m.sha(template),derived_script_sha256=m.sha(script),source_id=sid,
  separate_component_profile=True,complete_opt4=False,unchanged_shell_ip_count=11,no_fpga_operations=True,
  capacity_before_place=True,timing_and_drc_before_bitstream=True,serialize_physical_after_current_whole=True))
 m.update(status='RUNNING_STANDALONE_ORIGINAL_SVB_CAD_NO_FPGA_ACCESS',source_id=sid,component_cad_state=str(m.L/'cad-state.json'))
 m.stage('component-cad',['/usr/bin/python3',str(script)],m.L,[m.L/'cad-logs/result.json'],env=env,timeout=172800)
 m.update(status='COMPONENT_BITSTREAM_BUILT_NOT_DEPLOYED',cad_result=str(m.L/'cad-logs/result.json'))
 m.save(m.L/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
