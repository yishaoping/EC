"""Read-only audit of existing matched-model source and elaboration evidence."""
from common import *
import re,csv
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
native=W/'Native/chipyard'
protected=W/'C4/chipyard'
nbuild=EC/'firesim/dac2026/work/opt4-roi-v5/builds/B-elaborate-20261102T092109.491588Z'
ebuild=W/'builds/C4-elaborate-20261106T100250.032318Z'
params_path=W/'builds/C4-parameters-20261106T100204.040607Z/parameters.json'
params=read(params_path);boom=params['tiles'][0]
ns=native/'generators/boom/src/main/scala/common/config-mixins.scala'
fragment=ns.read_text().split('class WithDacMatchedBoom(',1)[1]
fields=['fetchWidth','decodeWidth','numRobEntries','numIntPhysRegisters','numFpPhysRegisters','numLdqEntries','numStqEntries','maxBrCount','numFetchBufferEntries','numRasEntries']
checks={};rows=[]
for key in fields:
 value=int(re.search(r'\b'+key+r'\s*=\s*(\d+)',fragment)[1]);actual=boom['core'][key]
 checks['core_'+key]=value==actual;rows.append(dict(parameter=key,native=value,ec=actual,matched=value==actual,evidence=str(ns)+';'+str(params_path)))
issues=[dict(dispatchWidth=int(d),issueWidth=int(w),numEntries=int(n),iqType=t) for w,n,t,d in re.findall(r'IssueParams\(issueWidth=(\d+), numEntries=(\d+), iqType=IQT_(\w+)\.litValue\s*, dispatchWidth=(\d+)\)',fragment)]
codes={'MEM':2,'INT':1,'FP':4}
checks['issue_queues']=len(issues)==3 and [{**x,'iqType':codes[x['iqType']]} for x in issues]==boom['core']['issueParams']
for cache,label in [('dcache','DCacheParams'),('icache','ICacheParams')]:
 text=re.search(label+r'\(([^\n]+)\)',fragment)[1]
 for key,raw in re.findall(r'(\w+)\s*=\s*(\d+(?:\*\d+)?)',text):
  value=1
  for factor in raw.split('*'):value*=int(factor)
  checks[cache+'_'+key]=value==boom[cache][key]
  rows.append(dict(parameter=cache+'.'+key,native=value,ec=boom[cache][key],matched=checks[cache+'_'+key],evidence=str(ns)+';'+str(params_path)))
native_cfg=native/'generators/chipyard/src/main/scala/config/DacBaselineConfig.scala'
config=native_cfg.read_text();l2=params['inclusive_cache']
checks['l2_shape_latency']=all(x in config for x in ['nWays=16','capacityKB=1024','outerLatencyCycles=12']) and l2['ways']==16 and l2['sets']==1024 and l2['memCycles']==12
clocks={}
for mode,build in [('native',nbuild),('ec',ebuild)]:
 p=build/'firesim.firesim.FireSim.firesimBuildTopClockGenerator.freq-summary'
 text=p.read_text();clocks[mode]={'path':str(p),'sha256':sha(p),'outputs':re.findall(r'Output clock ([^,]+), requested: ([\d.]+) MHz, actual: ([\d.]+) MHz',text)}
checks['boom_and_bus_200MHz']=all(any(n=='implicit_clock' and r==a=='200.0' for n,r,a in clocks[m]['outputs']) for m in ['native','ec'])
checks['four_checkers_100MHz']=sum(n.startswith('tileClockGroup_tile_') and r==a=='100.0' for n,r,a in clocks['ec']['outputs'])==4
plans=[W/'candidates/matched-single-boom-gg-r1-20261112/plan.json',W/'candidates/full-gg-external-observer-r2-20261111/plan.json']
checks['frozen_baseline_receipts']=all(read(p)['functional_baseline']==BASE for p in plans)
artifacts=[ns,native_cfg,params_path,*plans,native/'generators/firechip/src/main/scala/DacCommonPolicy.scala',protected/'generators/firechip/src/main/scala/DacCommonPolicy.scala']
for build in [nbuild,ebuild]:artifacts.append(build/'firesim.firesim.FireSim.dts')
checks['common_measurement_policy']=sha(artifacts[-4])==sha(artifacts[-3])
save(ROOT/'audit/platform-audit.json',dict(created_utc=now(),functional_baseline=BASE,passed=all(checks.values()),checks=checks,core_parameters=rows,issue_queues_native=issues,clocks=clocks,memory_runtime_plusargs=MEM,models={m:{'path':str(p),'sha256':sha(p)} for m,p in [('native',NATIVE),('ec',PROTECTED)]},evidence={str(p):sha(p) for p in artifacts},limitations=['Read-only comparison of explicit Native core/cache settings with saved frozen EC parameter evaluation and clock summaries; no new elaboration or formal equivalence proof','EC adds its intended checker/cache protection machinery, while Native uses clean BOOM; this audit does not assert RTL identity','Distinct linked application addresses/cache initial state remain a confound recorded separately in elf-layout.csv','No FPGA, CAD or bitstream command executed']))
with (ROOT/'paper/platform-parameters.csv').open('w',newline='') as f:
 writer=csv.DictWriter(f,fieldnames=list(rows[0]));writer.writeheader();writer.writerows(rows)
print(checks)
assert all(checks.values()),'Platform audit mismatch'
