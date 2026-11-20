#!/usr/bin/env python3
"""Add official Blackscholes simmedium; reuse exact current program ELF/math/ROI."""
from pathlib import Path
import datetime as dt,hashlib,json,re,shutil,subprocess,tarfile
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');P=Path('/data1/gzh/EC/Software/PARSEC')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
 parent=W/'software/apps-build.json';r=json.loads(parent.read_text());stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'software'/('apps-formal-'+stamp);logs=D/'software'/out.name;logs.mkdir()
 shutil.copytree(r['output_dir'],out)
 dest=out/'inputs/blackscholes/simmedium';dest.mkdir();archive=P/'pkgs/apps/blackscholes/inputs/input_simmedium.tar'
 with tarfile.open(archive) as tf:
  for m in tf.getmembers():
   if m.isfile():
    p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=dest/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
 conf=P/'pkgs/apps/blackscholes/parsec/simmedium.runconf';args=re.search(r'^run_args="(.*)"$',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
 ref=logs/'reference';shutil.copytree(dest,ref)
 with (ref/'stdout.log').open('wb') as f,(ref/'resource.log').open('wb') as e:
  cmd=['/usr/bin/time','-v','/usr/bin/qemu-riscv64',str(out/'blackscholes-reference'),*args];subprocess.run(cmd,cwd=ref,stdout=f,stderr=e,check=True,timeout=300)
 expected=[float(l.split()[-1]) for l in (dest/args[1]).read_text().splitlines()[1:]]
 prices=(ref/'prices.txt').read_text().splitlines();actual=list(map(float,prices[1:]));assert int(prices[0])==len(expected)==len(actual) and max(abs(x-y) for x,y in zip(expected,actual))<1e-4
 for name,b in r['binaries'].items():
  b['path']=str(out/name);b['reference_path']=str(out/(name+'-reference'));assert sha(b['path'])==b['sha256']
 r['smoke']['path']=str(out/'roi-smoke');r.update(output_dir=str(out),host_log_dir=str(logs),parent_receipt=str(parent),parent_receipt_sha256=sha(parent),formal_input_policy='Official simmedium 16384 options, original NUM_RUNS100, one thread/no warmup/fresh guest; only after FPGA small-input validation')
 c=dict(program='blackscholes',input='simmedium',argv=args,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(archive):sha(archive)},input_files={str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()},warmups=0,threads=1,fpga_validation='NOT_RUN',software_reference='QEMU_USER_ONLY',reference_outputs={str(ref/'prices.txt'):sha(ref/'prices.txt')},official_reference_max_absolute_error=max(abs(x-y) for x,y in zip(expected,actual)),output_count=len(expected),algorithm_unchanged=True)
 r['cases'].append(c);r['formal_reference_command']=cmd;r['runtime_memory_reference']=str(ref/'resource.log')
 for p in [out/'manifest.json',logs/'result.json',W/'software/formal-apps-build.json']:p.write_text(json.dumps(r,indent=2)+'\n')
 print(logs/'result.json',flush=True)
if __name__=='__main__':main()
