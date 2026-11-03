#!/usr/bin/env python3
"""Resume only a failed build, preserving old logs and rechecking source config.
Map private temp storage to /tmp to fit sbt's Unix socket path limit.
"""
import datetime,hashlib,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];TARGET=ROOT/'slowdown/blackscholes_validation/build/matched_check'
def main():
    manifest=TARGET/'build.manifest.json';r=json.loads(manifest.read_text());assert r['state']=='FAILED'
    for p,h in r['source_configuration_sha256'].items():assert hashlib.sha256((TARGET/'source/chipyard'/p).read_bytes()).hexdigest()==h
    env=r['environment'];env['JAVA_TOOL_OPTIONS']=env['JAVA_TOOL_OPTIONS'].replace('-Djava.io.tmpdir='+str(TARGET/'tmp'),'-Djava.io.tmpdir=/tmp');env.update(TMPDIR='/tmp',TMP='/tmp',TEMP='/tmp')
    command=r['commands'][0]['argv'][:-1];command=[('JAVA_TMP_DIR=/tmp' if x.startswith('JAVA_TMP_DIR=')else x)for x in command]
    r['state']='BUILDING';r.setdefault('build_attempts',[]).append({'previous_log':'verilog.log','reason':'sbt Unix socket path too long; use private /tmp mount'})
    for phase in ['verilog','default']:
        logfile=TARGET/(phase+'_resume_'+str(len(r['build_attempts']))+'.log')
        wrapped=['/usr/bin/bwrap','--die-with-parent','--new-session','--unshare-all','--ro-bind','/','/','--bind',str(TARGET),str(TARGET),'--bind',str(TARGET/'tmp'),'/tmp','--bind',str(TARGET/'tmp'),'/var/tmp','--dev','/dev','--chdir',str(TARGET)]
        for k,v in env.items():wrapped+=['--setenv',k,v]
        wrapped+=['--',*command,phase];r['commands'].append({'argv':command+[phase],'sandbox_argv':wrapped,'log':str(logfile)});manifest.write_text(json.dumps(r,indent=2)+'\n');print('PHASE='+phase+' LOG='+str(logfile),flush=True)
        with logfile.open('xb') as log:result=subprocess.run(wrapped,env={'PATH':'/usr/bin:/bin'},stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
        if result.returncode:r.update(state='FAILED',failed_phase=phase,returncode=result.returncode);manifest.write_text(json.dumps(r,indent=2)+'\n');raise RuntimeError('Build failed: '+phase)
    sim=TARGET/'verilator/simulator-chipyard-v1Config';r.update(state='BUILT',simulator=str(sim),simulator_sha256=hashlib.sha256(sim.read_bytes()).hexdigest(),ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());manifest.write_text(json.dumps(r,indent=2)+'\n');print('BUILT='+str(sim),flush=True)
if __name__=='__main__':main()
