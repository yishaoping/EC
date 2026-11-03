#!/usr/bin/env python3
"""Compile existing frozen emitted module; never elaborate or mutate RTL."""
import datetime,hashlib,json,os,subprocess,uuid
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    d=OUT/'build'/('recovery_component_'+uuid.uuid4().hex[:8]);d.mkdir(parents=True)
    g=ROOT/'slowdown/optimization_6_overlap/build/overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6/generated/gen-collateral'
    sources=[g/'SpeculativeVersionBuffer.sv',g/'SafeChainEventLogger.v',OUT/'scripts/recovery_component.cpp']
    tool='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    cmd=[tool,'--cc','--exe','--build','-j','2','--assert','-Wno-fatal','--top-module','SpeculativeVersionBuffer','--Mdir',str(d),*map(str,sources)]
    env=dict(os.environ,PATH='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin:/usr/bin:/bin')
    with (d/'build.log').open('xb') as f:subprocess.run(cmd,cwd=ROOT,env=env,stdout=f,stderr=subprocess.STDOUT,check=True)
    cmdrun=[str(d/'VSpeculativeVersionBuffer')];r=subprocess.run(cmdrun,capture_output=True,text=True,env=env)
    (d/'stdout.log').write_text(r.stdout);(d/'stderr.log').write_text(r.stderr)
    evidence=OUT/'recovery';evidence.mkdir(exist_ok=True)
    p=evidence/('component_'+datetime.datetime.now(datetime.timezone.utc).strftime('%H%M%S')+'.json')
    p.write_text(json.dumps(dict(command=cmd,run_command=cmdrun,source_sha256={str(p):sha(p)for p in sources},exit_status=r.returncode,stdout=r.stdout,stderr=r.stderr,scope='Frozen emitted SVB only; FAIL/invalidate stimulus at component interface; no architectural rollback'),indent=2)+'\n')
    print(r.stdout[-1800:]);print(r.stderr[-1800:]);r.check_returncode()
if __name__=='__main__':main()
