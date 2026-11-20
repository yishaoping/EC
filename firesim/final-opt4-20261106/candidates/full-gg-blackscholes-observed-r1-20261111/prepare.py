#!/usr/bin/python3
from pathlib import Path
import hashlib,json,math,os
C=Path(__file__).resolve().parent;W=C.parents[1]
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
DOC=Path('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106')
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
entry=next(v for v in read(DOC/'data/FINAL_RUNS.json') if v['workload']=='blackscholes_project64' and v['mode']=='correction')
manifest=Path(entry['manifest']['absolute_path']);assert sha(manifest)==entry['manifest']['sha256']
old=read(manifest);base='8491167d84b6d9521b151a743673c1516926a1f8'
assert old['canonical_hardware_commit']==base and old['software_correct']
elf=manifest.parent/'test.riscv';assert sha(elf)==entry['elf_sha256']==old['elf_sha256']
source_dir=C/'software';source_dir.mkdir(exist_ok=True);target=source_dir/'blackscholes-project64.riscv'
if not target.exists():target.write_bytes(elf.read_bytes())
assert sha(target)==sha(elf)
assert old['software']['options']==64 and old['software']['iterations']==100 and old['software']['threads']==1
assert old['output']==entry['authoritative_final_gate']['output']==['benchmark=blackscholes checksum=1187d037cad2df6f verified=1 options=64 runs=100']
prior=D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111';pr=read(prior/'result.json');assert pr['valid_finite_observation'] and pr['original_prints_and_application_and_target_count_match']
assert read(prior/'strict-acceptance-analysis-r1.json')['passed']
binding=read(prior/'canneal-observer-on/binding.json');binary=Path(binding['args'][0]);assert sha(binary)==binding['binary_sha256']
obs_plan_path=C.with_name('full-gg-external-observer-r2-20261111')/'plan.json';obsplan=read(obs_plan_path)
assert obsplan['functional_baseline']==base
external={str(p):sha(p) for p in [manifest,elf,prior/'result.json',prior/'strict-acceptance-analysis-r1.json',prior/'canneal-observer-on/binding.json',obs_plan_path,binary,D/'cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv']}
# Reuse original bound model/object evidence; no new elaboration or model compile.
external.update(obsplan['external_inputs'])
for p,h in external.items():assert sha(p)==h,('CHANGED_SOURCE_ORIGINAL_MODEL',p)
args=[a for a in binding['args'] if not a.startswith('+prog0=') and not a.startswith('+print-file=') and not a.startswith('+max-cycles=')]
args.insert(2,'+max-cycles=16000000')
# Print prefix/prog are inserted immediately before permissive-off by the runtime.
assert all(v in args for v in ['+mm_readLatency_0=30','+mm_writeLatency_0=30','+mm_readMaxReqs_0=4','+mm_writeMaxReqs_0=4','+mm_relaxFunctionalModel_0=0'])
budget=math.ceil(3*pr['full']['host_wall_seconds']*old['total_harness_cycles']/pr['full']['target_cycles']+600)
assert budget<=24*3600
plan=dict(schema='ec-frozen-full-gg-blackscholes-observed/1',functional_baseline=base,source_id=pr['source_id'],benchmark='blackscholes',input='project64',elf=str(target),elf_sha256=sha(target),binary=str(binary),binary_sha256=sha(binary),base_args=args,external_inputs=external,expected_output=old['output'],software=old['software'],plain_target_reference=dict(run=str(manifest.parent),manifest_sha256=sha(manifest),roi_cycles=old['roi_cycles'],roi_instructions=old['roi_instret'],total_cycles=old['total_harness_cycles'],memory_model='+dramsim; differs from GG FASED LatencyPipe30/max4'),target_cycle_limit=16000000,host_timeout_seconds=budget,budget_derivation=dict(reference_real_gg_host_seconds=pr['full']['host_wall_seconds'],reference_real_gg_target_cycles=pr['full']['target_cycles'],plain_blackscholes_total_cycles=old['total_harness_cycles'],safety_factor=3,additive_seconds=600),cpu_affinity_limit=2,address_space_limit_gib=24,owned_output_limit_bytes=4*2**30,fpga_access=False,model_objects_rebuilt=False,target_or_host_rtl_modified=False,observer='ExistingCannealvalidatedr2 acceptance-only; SVBbinarynotcapturedhere; Cannealr5collectsfullSVBports independently',output='Original stdout/stderr stream complete gzip1 plus SHA256 of every rawbyte and compressedfile; compact filtered noninstruction live log separate',scope='Full original baremetal project64, noROIshrink, CPU originalGG simulation; not formalLinuxPARSEC/FPGAmeasurement/cycleequivalenceagainst+dramsim')
(C/'plan.json').write_text(json.dumps(plan,indent=2,sort_keys=True)+'\n')
# Preserve small immutable old evidence under W, satisfying broker root guard.
cap=C/'evidence';cap.mkdir(exist_ok=True)
for p in [manifest,prior/'result.json',prior/'strict-acceptance-analysis-r1.json',prior/'canneal-observer-on/binding.json']:
 dest=cap/(sha(p)[:16]+'-'+p.name)
 if not dest.exists():dest.write_bytes(p.read_bytes())
 assert sha(dest)==sha(p)
print(json.dumps(dict(plan=str(C/'plan.json'),elf_sha256=plan['elf_sha256'],max_target_cycles=16000000,host_timeout_seconds=budget,model_binary_sha256=plan['binary_sha256'],runtime_started=False),indent=2))
