#!/usr/bin/python3
"""Bound, CPU-only, nonresident check; submit a unique runtime after receipts."""
import argparse,datetime,fcntl,hashlib,json,os,pathlib,subprocess,sys
C=pathlib.Path(__file__).resolve().parent
def sha(p):
 h=hashlib.sha256()
 with pathlib.Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--binding-sha',required=True);p.add_argument('--verify-only',action='store_true');a=p.parse_args()
 manifest=C/'timer-input-binding.json';assert sha(manifest)==a.binding_sha,'timer manifest version mismatch'
 lock=(C/'dispatch.lock').open('a')
 try:fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 except BlockingIOError:print('ADOPT_EXISTING_DISPATCH_LOCK');return
 binding=json.loads(manifest.read_text())
 for name,digest in binding['immutable_inputs'].items():assert sha(name)==digest,'timer immutable input changed: '+name
 assert binding['fpga_access'] is False and binding['no_compile'] is True
 print(json.dumps(dict(status='TIMER_BOUND_INPUTS_PASS',utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),binding_sha256=a.binding_sha)),flush=True)
 if a.verify_only:return
 result=subprocess.run(['/usr/bin/python3',str(C/'continue.py'),'--prepare-when-ready'],cwd=C,stdin=subprocess.DEVNULL)
 assert result.returncode==0,'continuation failed with evidence; next timer retries unchanged prerequisites'
if __name__=='__main__':main()
