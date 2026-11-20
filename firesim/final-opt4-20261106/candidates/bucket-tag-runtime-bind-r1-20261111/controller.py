#!/usr/bin/python3
"""Bind the existing driver using the pinned generator's real seven-file audit.

Only compatibility() is called: no runtime request, unit manipulation, device
opening, driver execution, deployment, or sample collection is possible here.
"""
from pathlib import Path
import datetime, fcntl, hashlib, importlib.util, json, os, subprocess, sys

sys.dont_write_bytecode=True
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-bucket-tag-runtime-bind-r1-20261111'
S=O/'state.json'
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(2**20),b''):h.update(x)
 return h.hexdigest()
def save(p,x):
 q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (O/'result.json').exists(),'reuse successful exact receipt'
 cfg=read(C/'config.json');inputs=read(C/'input-hashes.json')
 assert all(sha(p)==h for p,h in inputs.items()),'input changed'
 stat=Path(f'/proc/{os.getpid()}/stat').read_text().rsplit(')',1)[1].split()
 st=dict(status='RUNNING_OFFLINE_ABI_BINDING',pid=os.getpid(),start_ticks=stat[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),hardware_commit=cfg['hardware_commit'],source_id=cfg['source_id'],fpga_access=False)
 save(S,st)
 sys.path.insert(0,str(W/'scripts'))
 spec=importlib.util.spec_from_file_location('pinned_runtime_generator',cfg['generator']);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
 x=module.descriptor(cfg['descriptor']);assert x['commit']==cfg['hardware_commit'] and x['source_id']==cfg['source_id']
 out=Path(cfg['runtime_dir']);assert read(out/'bundle.json')['hardware_commit']==x['commit']
 # Independently compare real bytes before calling the unchanged generator.
 audit=read(cfg['seven_file_audit']);assert audit['hardware_commit']==x['commit'] and audit['source_id']==x['source_id']
 assert len(audit['rows'])==7
 for row in audit['rows']:
  assert Path(row['original']).read_bytes()==Path(row['derived']).read_bytes(),row['role']
  assert sha(row['original'])==row['original_sha256']==row['derived_sha256']==sha(row['derived'])
 module.compatibility(x,out)
 compatibility=read(out/'driver-compatibility.json')
 assert compatibility['hardware_commit']==x['commit'] and compatibility['hardware_source_id']==x['source_id']
 assert len(compatibility['generated_abi_and_target_description'])==7
 assert compatibility['host_code_reused'] is True and compatibility['recompiled'] is False
 binary=Path(next(iter(compatibility['outputs'])))
 assert sha(binary)==compatibility['outputs'][str(binary)]
 elf=subprocess.run(['/usr/bin/readelf','-h',str(binary)],text=True,capture_output=True,check=True)
 assert 'ELF64' in elf.stdout and 'X86-64' in elf.stdout
 (O/'driver-readelf-header.txt').write_text(elf.stdout)
 assert all(sha(p)==h for p,h in inputs.items()),'input changed during binding'
 st.update(status='HOST_DRIVER_BOUND_7_REAL_ABI_FILES_EQUAL_NOT_FPGA_VALIDATED',ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),compatibility_receipt=str(out/'driver-compatibility.json'),compatibility_sha256=sha(out/'driver-compatibility.json'),driver=str(binary),driver_sha256=sha(binary),real_abi_byte_comparisons=7,driver_executed=False,recompiled=False,full_software_suite_prepared=False,fpga_runtime_validated=False,limits='Source/ABI binding and static ELF validation only. The broker must still certify the actual bitstream, prepare the 13-app suite, and validate smoke/checkers/recovery/drain/output. Architectural rollback remains unvalidated.')
 save(S,st);save(O/'result.json',st)
if __name__=='__main__':main()
