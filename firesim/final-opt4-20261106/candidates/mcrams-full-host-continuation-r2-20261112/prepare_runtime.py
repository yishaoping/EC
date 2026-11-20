#!/usr/bin/python3
"""Prepare a private composite target+GG-host identity and strict runtime bundle.
The source tree is never re-labelled: target_commit and host_transform_id remain
separate. Existing FPGA result verifier/card locks/21-only deployment reused.
"""
import hashlib,json,os,pathlib,shutil,sys
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=W/'runtime/Opt4-fit-mcrams-owner-r1';GG=D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111/goldengate'
EL=W/'Opt4-fit-dcache-field-read-prune-r1-20261111/builds/system-3656aec4-r4/elaborate'
HW='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c';PROFILE='Opt4-fit-C4-SVB32-MCRams-owner-r1'
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def read(p):return json.loads(P(p).read_text())
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def main():
 R.mkdir(exist_ok=True);scripts=R/'scripts';scripts.mkdir(exist_ok=True);plan=read(C/'physical-plan.json');SID=plan['host_transform_id']
 assert SID==read(C/'runtime-registration.json')['host_transform_id']
 baseline=read(D/'unattended-opt4/runtime-template-baseline.json');files=['board_batch.py','run_isolated_sample.py','continue_opt4_fit.py','opt4_fit_runtime_guard.py']
 oldcommit='8da24a269b98a0d6a8f57b030353a310812c4344';oldsource='7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1';oldprofile='Opt4-fit-C4-SVB32-20261110'
 prefix='import sys\nfrom pathlib import Path as _BundlePath\nsys.path.insert(0,str(_BundlePath(__file__).resolve().parent))\nsys.path.insert(1,'+repr(str(W/'scripts'))+')\n'
 for name in files:
  p=W/'scripts'/name;assert sha(p)==baseline['templates'][name]
  text=p.read_text().replace(oldcommit,HW).replace(oldsource,SID).replace(oldprofile,PROFILE)
  text=text.replace("W/'runtime'/('Opt4-fit-'+COMMIT[:8])","W/'runtime/Opt4-fit-mcrams-owner-r1'")
  text=text.replace('Opt4-fit-runtime-state.json','Opt4-mcrams-owner-runtime-state.json').replace('Opt4-fit-runtime-logs','Opt4-mcrams-owner-runtime-logs')
  text=text.replace('opt4-fit-8da24a26','opt4-fit-3656aec4-mcrams')
  text=text.replace("str(W/'scripts/run_isolated_sample.py')","str(Path(__file__).resolve().parent/'run_isolated_sample.py')").replace("str(W/'scripts/board_batch.py')","str(Path(__file__).resolve().parent/'board_batch.py')")
  if name=='continue_opt4_fit.py':text=text.replace('Opt4-fit-cad-state.json','Opt4-mcrams-shell-physical-r2-state.json').replace("'BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED'","'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION'")
  if name=='opt4_fit_runtime_guard.py':
   # Require exact composite host identity and canonical certificate in
   # addition to the existing bitstream/source/software checks.
   marker="s=read(p)\n    assert s['status']=='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED'"
   assert marker in text;text=text.replace(marker,"s=read(p)\n    assert s['host_transform_id']==SOURCE and s['target_commit']==COMMIT\n    assert s['host_rtl_sha256']=="+repr(plan['host_rtl_sha256'])+"\n    assert s['status']=='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED'")
  text=prefix+text;compile(text,str(scripts/name),'exec')
  q=scripts/name
  if q.exists():assert q.read_text()==text
  else:q.write_text(text)
 # Seven inputs are all checked. Implementation XDC differs only by emitted
 # target instance spelling (FireSim_ -> FireSim__). This is not a driver ABI
 # change; exact new XDC is separately bound and checked in physical timing.
 compat=read(W/'runtime/Opt4-fit-C4-driver-compatibility.json');rows=[]
 for row in compat['generated_abi_and_target_description']:
  p=(GG if row['role'].startswith('FireSim-generated.') else EL)/row['role'];a=P(row['original']);same=sha(a)==sha(p)
  if not same:
   assert row['role']=='FireSim-generated.implementation.xdc'
   assert a.read_text().replace('FireSim_/','FireSim__/')==p.read_text(),'timing constraint differs beyond exact target rename'
  rows.append(dict(role=row['role'],original=str(a),original_sha256=sha(a),derived=str(p),derived_sha256=sha(p),byte_equal=same,kind='physical_constraints_exact_target_instance_rename' if not same else 'unchanged_driver_input'))
 parent=P(compat['parent_receipt']);assert sha(parent)==compat['parent_receipt_sha256'];dr=read(parent)
 exe=R/'FireSim-xilinx_alveo_u280';src=P(next(iter(compat['outputs'])));assert sha(src)==compat['outputs'][str(src)]
 if exe.exists():assert sha(exe)==sha(src)
 else:shutil.copy2(src,exe)
 driver=dict(dr,schema='ec-composite-target-host-compatible-driver/1',hardware_commit=HW,hardware_source_id=SID,source_id=SID,target_commit=HW,host_transform_id=SID,profile=PROFILE,output_dir=str(R),outputs={str(exe):sha(exe)},fpga_runtime_validated=False,host_code_reused=True,recompiled=False,compatibility_receipt=str(R/'driver-compatibility.json'))
 comp=dict(status='PASS_SIX_IDENTICAL_ABI_TARGET_INPUTS_AND_EXACT_GENERATED_XDC_RENAME',target_commit=HW,host_transform_id=SID,host_rtl_sha256=plan['host_rtl_sha256'],generated_inputs=rows,parent_receipt=str(parent),parent_receipt_sha256=sha(parent),outputs={str(exe):sha(exe)},fpga_access=False)
 for name,j in [('driver-compatibility.json',comp),('driver-receipt.json',driver)]:
  p=R/name
  if p.exists():assert read(p)==j
  else:save(p,j)
 old=read(W/'runtime/Opt4-fit-e0c3737f/software-suite.json');assert old['program_count']==13
 suite=dict(old,profile=PROFILE,hardware_commit=HW,source_id=SID,target_commit=HW,host_transform_id=SID,host_rtl_sha256=plan['host_rtl_sha256'],automatic_runtime_handoff_installed=False)
 for row in suite['programs']:
  row['receipts']['driver']=str(R/'driver-receipt.json');row['receipt_sha256']['driver']=sha(R/'driver-receipt.json')
 p=R/'software-suite.json'
 if p.exists():assert read(p)==suite
 else:save(p,suite)
 shutil.copy2(C/'runtime_certify.py',scripts/'prepare_opt4_fit_runtime.py')
 binding=dict(schema='ec-composite-mcrams-runtime-bundle/1',status='OFFLINE_INPUTS_PREPARED_NOT_FPGA_ADMITTED',target_commit=HW,host_transform_id=SID,profile=PROFILE,board_bdf='0000:21:00.0',board_serial='21770433G02LA',fpga_access=False,scripts={str(p):sha(p) for p in sorted(scripts.glob('*.py'))},software_suite=str(R/'software-suite.json'),software_suite_sha256=sha(R/'software-suite.json'),driver_compatibility_sha256=sha(R/'driver-compatibility.json'),final_physical_state=str(D/'Opt4-mcrams-shell-physical-r2-state.json'))
 save(R/'bundle.json',binding);print(R/'bundle.json')
if __name__=='__main__':main()
