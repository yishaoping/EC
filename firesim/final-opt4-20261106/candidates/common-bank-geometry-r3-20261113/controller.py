#!/usr/bin/python3
"""Full-state geometry prerequisite; deterministic and isolated, no CAD/FPGA IO."""
from pathlib import Path
import fcntl, hashlib, importlib.util, json, os, re, resource, subprocess, sys
C=Path(__file__).resolve().parent
W=C.parent.parent
T=W/'Opt4-area-common-bank-geometry-r3-20261113'
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-common-bank-geometry-r3-20261113'
Q=D/'build-logs/Opt4-common-query-bank-closure-r1-20261113'
P2=D/'build-logs/Opt4-common-bank-geometry-r2-20261113'
R='chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ecstatscommon/'
CPUS={204,205}
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha

def load(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
m=load('geometry_stage',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m.C,m.O,m.CPUS=C,O,CPUS
p=load('geometry_cones',W/'candidates/common-stats-transition-proof-r1-20261113/controller.py')

def members(unit):
 found=[]
 for path in Path('/proc').iterdir():
  if not path.name.isdigit():continue
  try:
   if any(line.split(':',2)[-1].endswith('/'+unit) or '/'+unit+'/' in line.split(':',2)[-1] for line in (path/'cgroup').read_text().splitlines()):found.append(identity(int(path.name)))
  except OSError:pass
 return found

def query(lanes,rtl):
 prefix=f'read_verilog -sv {rtl}\nprep -top QueryContract\nflatten\nopt_clean\ncheck -assert\n'
 script=O/f'query-{lanes}.ys';m.exact(script,prefix+'sat -verify -timeout 180 -prove io_same 1 -show-inputs -show-outputs\n')
 m.stage(f'query-contract-{lanes}',['/usr/local/bin/yosys','-Q','-T','-s',script],marker='SAT proof finished - no model found: SUCCESS!')
 neg=O/f'query-negative-{lanes}.ys';m.exact(neg,prefix+'sat -timeout 60 -prove io_same 0 -show-inputs -show-outputs\n')
 m.stage(f'query-negative-{lanes}',['/usr/local/bin/yosys','-Q','-T','-s',neg],marker='SAT proof finished - model found: FAIL!')
 save(O/f'query-contract-{lanes}.json',dict(lanes=lanes,arbitrary_base_including_wrap=True,arbitrary_full_tag_valid_payload=True,RTL_sha256=sha(rtl),local_combinational_only=True))

def target(lanes,rtl):
 head=re.search(r'\bmodule Partition\s*\((.*?)\);',rtl.read_text(),re.S).group(1)
 ports=re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)
 inputs=[(w,n) for d,w,n in ports if d=='input']
 assert [(d,w,n) for d,w,n in ports if d=='output']==[('output','','io_same')]
 lines=['module tb;','integer cycle;',"reg [63:0] rng=64'hc831873933ea45bd;",'wire io_same;']
 lines+=['reg '+w+' '+n+';' for w,n in inputs]
 lines+=['Partition dut('+','.join('.'+n+'('+n+')' for w,n in inputs)+',.io_same(io_same));',
  'task check; begin if(io_same !== 1\'b1) begin $display("GEOMETRY_STATE_MISMATCH cycle=%0d",cycle); $fatal(1); end end endtask',
  'initial begin','cycle=-1;']
 lines += [n+"='0;" for w,n in inputs]
 lines += ['reset=1; io_resetStats=1; io_barrierResetStats=1; #1; clock=1; #1; clock=0; #1;',
  'for(cycle=0;cycle<8192;cycle=cycle+1) begin']
 for w,n in inputs:
  if n in ['clock','reset','io_resetStats','io_barrierResetStats']:continue
  lines+=['rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',n+'=rng;']
 lines += ['reset=(cycle<3 || cycle==3072);',
  'io_resetStats=(cycle<3 || cycle%1024==0);',
  'io_barrierResetStats=(cycle<3 || cycle%1024==0);',
  '// Every 8-bit base, including unaligned and modular wrap cases, recurs.',
  'io_base=cycle%256; io_barrierBase=(cycle*3)%256;',
  'io_processSeq=io_base+(cycle%32); io_retiringSeq=io_processSeq;',
  'io_barrierEvent_bits=io_barrierBase+(cycle%32);',
  'if(cycle%4==0) io_barrierSafeWatermark=0;',
  'if(cycle%4==1) io_barrierSafeWatermark=io_barrierEvent_bits;',
  'if(cycle%8==0) begin io_processCommit=1; io_safeAdvance=1; io_safeError=0; end',
  'if(cycle==4097) begin']
 for lane in [0,31]:
  for bank,i in [(f'dut.reference_{lane//16}',lane%16),(f'dut.candidate_{lane//lanes}',lane%lanes)]:
   lines += [f'{bank}.bucketValid_{i}=1;',f'{bank}.bucketSeq_{i}=32\'d17;']
   for metric in ['bucketStore','bucketFirstStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']:
    for g in range(4):lines.append(f'{bank}.{metric}_{i}_{g}=64\'hffffffffffffffff;')
   for name,val in [('valid',"1'b1"),('seq',"32'd17"),('count',"64'hffffffffffffffff"),('requestCycleSum',"64'hffffffffffffffff")]:lines.append(f'{bank}.buckets_{name}_{i}={val};')
 lines += ['end','#1; check; clock=1; #1; clock=0; #1;',
  'if($test$plusargs("EC_MUTATE") && cycle==1000) begin force dut.candidate_0.bucketStore_0_0=64\'hdeadbeef12345678; #1; end',
  'check; end',f'$display("GEOMETRY_FULL_STATE_PASS lanes={lanes} cycles=8192 state_bits=47168"); $finish;',
  'end endmodule']
 tb=O/f'tb-{lanes}.v';m.exact(tb,'\n'.join(lines)+'\n')
 binary=O/f'obj-{lanes}/Vtb'
 m.stage(f'compile-target-{lanes}',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb','--Mdir',binary.parent,'-j','2',
  '--output-split','10000','--output-split-cfuncs','200','--x-initial','0','--x-assign','0','-Wno-fatal',
  '-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtl,tb],[binary])
 m.stage(f'full-state-target-{lanes}',[binary],marker=f'GEOMETRY_FULL_STATE_PASS lanes={lanes} cycles=8192',timeout=1800)
 m.stage(f'negative-state-{lanes}',[binary,'+EC_MUTATE'],negative=True,marker='GEOMETRY_STATE_MISMATCH cycle=1000',timeout=300)
 save(O/f'target-validation-{lanes}.json',dict(lanes=lanes,cycles=8192,compared_span=32,state_bits=47168,production_slots=256,
  every_8bit_base_tested=True,all_state_including_invalid_payload=True,all_public_bank_outputs=True,
  seeded_overflow_and_source_priority=True,negative_state_mutation_rejected=True,
  complete_caller_or_host_equivalence=False,testbench_sha256=sha(tb),RTL_sha256=sha(rtl)))

def default_contract(rtl):
 script=O/'default-state.ys';m.exact(script,f'read_verilog -sv {rtl}\nhierarchy -top GeometryBankProof\nproc\nopt_clean\nwrite_json {O}/default-state.json\n')
 m.stage('extract-default-state',['/usr/local/bin/yosys','-Q','-T','-s',script],[O/'default-state.json'])
 prior=read(Q/'bank-state-boundary.json')['modules']['StatsBankProof']
 current=read(O/'default-state.json')['modules']['GeometryBankProof']
 a,b=p.Cones(prior,'common'),p.Cones(current,'common')
 at,bt=a.transitions(),b.transitions()
 assert at==bt,('Default geometry state changed',len(at),len(bt))
 assert a.initial()==b.initial() and a.outputs()==b.outputs(),'Default geometry output/reset/init changed'
 save(O/'default16-state-contract.json',dict(state_bits=len(at),output_ports=len(a.outputs()),
  arbitrary_state_input_cones_equal=True,reset_init_clock_equal=True,
  predecessor_netlist_sha256=sha(Q/'bank-state-boundary.json'),current_netlist_sha256=sha(O/'default-state.json')))

def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (O/'state.json').exists(),'Adopt existing owner'
 units=['ec-opt4-common-bank-geometry-r2-20261113.service','ec-opt4-common-bank-geometry-r1-20261113.service','ec-opt4-common-query-select-r1-20261113.service','ec-opt4-common-query-bank-closure-r1-20261113.service','ec-opt4-common-stats-transition-proof-r1-20261113.service']
 assert all(not members(u) for u in units),'Exact predecessor cgroup still owns resources'
 save(O/'predecessor-release.json',dict(units=units,all_released=True,utc=now()))
 os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(32*2**30,)*2)
 binding=read(C/'source-binding.json');commit=binding['hardware_commit']
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==commit
 assert all(sha(path)==h for path,h in binding['files'].items())
 for rel,h in binding['committed_files'].items():
  assert hashlib.sha256(subprocess.check_output(['git','show',commit+':'+rel],cwd=T)).hexdigest()==h
 ledger=read(C/'source-ledger.json')
 for rel,entry in ledger.items():
  s=(T/rel).read_text()
  for e in reversed(entry['edits']):
   at=e['offset'];assert s[at:at+len(e['new'])]==e['new'];s=s[:at]+e['old']+s[at+len(e['new']):]
  assert s==subprocess.check_output(['git','show',binding['hardware_parent']+':'+rel],cwd=T,text=True)
 m.ST.update(schema='ec-common-bank-geometry-prerequisite/1',**identity(),started_utc=now(),hardware_commit=commit,
  hardware_parent=binding['hardware_parent'],functional_baseline=binding['functional_baseline'],cpus=sorted(CPUS),memory_limit_gib=32,
  fpga_access=False,no_CAD=True,host_transform=False,production_admission=False,full_system_fit=False,
  source_binding_sha256=sha(C/'source-binding.json'),scope='Production256-slot parameterized common-bank 8/16/32-lane compile, local32-slot all-state parity, default16 arbitrary-state cone identity, arbitrary-base query contracts, actual caller elaboration. No area/host/whole-EC equivalence or shell FIT.')
 m.update('ADMITTING_GEOMETRY_PREREQUISITE');save(O/'admission.json',m.admission())
 cfg=read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
 java=[cfg['java'],'-Xmx20G','-Xss32M','-XX:ActiveProcessorCount=2']
 prod=D/'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
 composed=D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
 base=':'.join(map(str,[prod,composed]))+':'+':'.join(cfg['classpath'])
 # Recovery changes artifact receipt selection only. Reuse accepted exact r2
 # compile/default16/8-lane results; production and proof bytes are unchanged.
 reuse=read(C/'adopted-r2-inputs.json')
 assert all(sha(path)==h for path,h in reuse['files'].items())
 for name in reuse['accepted_stages']:
  rec=read(P2/(name+'-receipt.json'))
  assert rec['accepted'] and not rec['missing_outputs'],name
  assert sha(rec['log'])==rec['log_sha256'],name
  assert all(sha(path)==h for path,h in rec['outputs'].items()),name
 assert read(P2/'default16-state-contract.json')['state_bits']==23584
 assert read(P2/'target-validation-8.json')['negative_state_mutation_rejected']
 assert read(P2/'query-contract-8.json')['arbitrary_base_including_wrap']
 save(O/'adopted-r2-inputs.json',reuse)
 classes=P2/'classes'
 cp=str(classes)+':'+base
 def emit(kind,lanes):
  out=O/f'{kind}-{lanes}';out.mkdir()
  m.stage(f'emit-{kind}-{lanes}',java+['-cp',cp,'geometrytest.Emit',kind,str(lanes),out],[out/(kind+'.v')])
  return out/(kind+'.v')
 for lanes in [8,32]:
  if lanes==8:
   rtl=P2/'Mixed-8/Mixed.v'
  else:
   query(lanes,emit('QueryContract',lanes))
   target(lanes,emit('Partition',lanes))
   rtl=emit('Mixed',lanes)
  # Chisel output-file renames Verilog only; annotations use circuit name.
  annopath=rtl.parent/'MixedGeometry.anno.json'
  assert annopath.is_file(),('Missing actual circuit annotations',str(annopath))
  anno=json.loads(annopath.read_text())
  selected=[a for a in anno if a.get('class')=='midas.targetutils.FirrtlEnableModelMultiThreadingAnnotation']
  expected={f'~MixedGeometry|MixedGeometry/{role}:{typ}/bucketBanks_{i}:StatsBank'
    for role,typ in [('address','PackageAddressStats')]+[(f'barriers_{j}','GHBarrierLatencyStats') for j in range(3)]
    for i in range(256//lanes)}
  assert len(selected)==1024//lanes,(lanes,len(selected))
  assert {a['target'] for a in selected}==expected,('Actual target selection mismatch',lanes)
  assert len(selected)>0 and len(selected)&(len(selected)-1)==0
  save(O/f'caller-geometry-{lanes}.json',dict(production_address_slots=256,production_barrier_slots_each=256,
   barriers=3,lanes=lanes,selected_banks=len(selected),expected_single_type='StatsBank',one_type_after_GoldenGate_dedup_pending=True,
   actual_annotation_path=str(annopath),exact_selected_targets=sorted(expected),annotation_schema_strict=True,
   public_ports=73,generated_RTL_sha256=sha(rtl),annotation_sha256=sha(annopath),host_tokens_validated=False))
 assert all(sha(path)==h for path,h in binding['files'].items())
 m.update('PASS_PARAMETERIZED_COMMON_BANK_GEOMETRY_PREREQUISITES_NOT_HOST_OR_AREA',child={},ended_utc=now(),
  source_inverse_parent_bytes_equal=True,default16_arbitrary_state_cones_equal=True,
  geometries=[dict(lanes=n,banks_per256=256//n,selected_mixed_banks=1024//n) for n in [8,16,32]],
  validated_local_cycles_each=8192,local_state_bits_compared_each=47168,
  complete_caller_equivalence=False,host_equivalence=False,area_gain_unknown=True,
  next='Consume original16-lane production/mixed host tokens and measured area; use verified8/32 geometry only for immutable resource-gated distinct host/area screens. Actual complete-target/caller/frozenDCache/host/ABI and shell gates remain mandatory. No extrapolated savings.')
 save(O/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if m.ST:
   m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now());save(O/'failure.json',m.ST)
  raise
