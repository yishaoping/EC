#!/usr/bin/python3
"""Composite target+host artifact certification. No FPGA operations."""
import hashlib,json,os,pathlib,re,shutil
P=pathlib.Path;W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');R=W/'runtime/Opt4-fit-mcrams-owner-r1'
C=W/'candidates/mcrams-full-host-continuation-r2-20261112'
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(P(p).read_text())
def save(p,j):
 p=P(p);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def certify():
 s=read(D/'Opt4-mcrams-shell-physical-r2-state.json')
 if s.get('status')!='PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION':return dict(status='WAITING_REAL_FULL_PHYSICAL_TIMING_DRC_BITSTREAM')
 plan=read(C/'physical-plan.json');SID=plan['host_transform_id'];HW=plan['derived_hardware'];out=P(s['bitstream']).parent
 assert s['hardware_commit']==HW and s['host_transform_id']==SID and not s['fpga_access']
 assert all(sha(p)==h for p,h in plan['immutable_inputs'].items())
 ad=read(D/'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/capacity-parity-admission.json')
 for key in ['capacity_result','target_parity_result']:assert sha(ad[key])==ad[key+'_sha256']
 assert read(ad['target_parity_result'])['captured_finite_parity_passed']
 for name in ['stub','wrapper_only','top_opt','place','route','timing_drc_bitstream']:
  r=read(out/(name+'-receipt.json'));assert r['returncode']==0 and all(sha(p)==h for p,h in r['outputs'].items())
 for k in ['CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','URAM','DSPs']:
  r=s['top_postopt_resources'][k];assert 0<=r['used']<=r['available'] and r['available']>0
 assert sha(s['bitstream'])==s['bitstream_sha256']
 logs=(out/'timing_drc_bitstream.log').read_text();m=re.search(r'MCRAMS_PHYSICAL_TIMING WNS=([-+0-9.eE]+) WHS=([-+0-9.eE]+)',logs);assert m and min(map(float,m.groups()))>=0
 ct=(out/'final-check-timing.rpt').read_text();assert re.search(r'checking no_clock \(0\)',ct) and re.search(r'checking unconstrained_internal_endpoints \(0\)',ct)
 for name in ['final-pulse.rpt','final-bus-skew.rpt']:assert 'VIOLATED' not in (out/name).read_text().upper()
 comp=read(R/'driver-compatibility.json');assert comp['host_transform_id']==SID and comp['host_rtl_sha256']==plan['host_rtl_sha256']
 for row in comp['generated_inputs']:assert sha(row['original'])==row['original_sha256'] and sha(row['derived'])==row['derived_sha256']
 bundle=read(R/'bundle.json');assert bundle['host_transform_id']==SID and all(sha(p)==h for p,h in bundle['scripts'].items()) and sha(bundle['software_suite'])==bundle['software_suite_sha256']
 # Bind unchanged target source and exact annotation-derived host separately.
 srcplan=read(W/'candidates/mcrams-dcache-owner-system-r1-20261111/plan.json');assert all(sha(p)==h for p,h in srcplan['inputs'].items())
 dest=R/'firesim.bit'
 if not dest.exists():shutil.copy2(s['bitstream'],dest)
 assert sha(dest)==s['bitstream_sha256']
 stages={name:dict(returncode=0,source_id=SID,hardware_commit=HW) for name in ['dut_synth','top_synth','implementation','timing_bitstream']}
 r=dict(s,status='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED',hardware_commit=HW,target_commit=HW,source_id=SID,host_transform_id=SID,host_rtl_sha256=plan['host_rtl_sha256'],frozen_parent_commit=plan['functional_baseline'],profile='Opt4-fit-C4-SVB32-MCRams-owner-r1',part='xcu280-fsvh2892-2L-e',configuration='DacOpt4C4',returncode=0,certified_bitstream=True,formal_admission=False,durable_bitstream=str(dest),durable_bitstream_sha256=sha(dest),stages=stages,stage_semantics='Legacy runtime admission keys wrap explicit checkpoint_reuse/stub/wrapper/topopt/place/route/timingdrccheck receipts; no DUT resynthesis claimed',actual_stage_receipts={name:str(out/(name+'-receipt.json')) for name in ['stub','wrapper_only','top_opt','place','route','timing_drc_bitstream']},deployment_admission=False)
 cert=R/'certified-build.json'
 if cert.exists():assert read(cert)==r
 else:save(cert,r)
 return r
if __name__=='__main__':
 assert read(R/'bundle.json')['board_bdf']=='0000:21:00.0';print('COMPOSITE_SOFTWARE_BUNDLE_PREPARED_WAITING_REAL_CERTIFICATION')
