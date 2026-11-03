#!/usr/bin/env python3
"""Launch only an explicit reviewed plan after hardware and pilot acceptance."""
import argparse,datetime,json,subprocess,sys,time,uuid
from pathlib import Path
from run_pilot import ROOT,OUT,dump,sha
def main():
    p=argparse.ArgumentParser();p.add_argument('plan',type=Path);a=p.parse_args();plan=json.loads(a.plan.read_text())
    assert subprocess.check_output(['git','status','--porcelain=v1'],cwd=ROOT,text=True)==''
    revision=json.loads((OUT/'hardware_revision.json').read_text());assert revision['status']=='ACCEPTED'
    pilots=json.loads((OUT/'pilot_acceptance.json').read_text());assert pilots['status']=='PASS' and pilots['canonical_hardware_commit']==revision['canonical_hardware_commit']
    assert 1<=len(plan)<=12 and len({r['label']for r in plan})==len(plan)
    batch=OUT/'build'/('measurements_'+datetime.datetime.now(datetime.timezone.utc).strftime('%H%M%S_')+uuid.uuid4().hex[:8]);batch.mkdir();scripts=OUT/'scripts';processes={};logs={};commands={};results={}
    for case in plan:
        assert case['design']in ['native','check','correction'] and 0<case['max_cycles']<=10000000
        label=case['label'];cmd=[sys.executable,str(scripts/'run_pilot.py'),case['workload'],case['design'],'--max-cycles',str(case['max_cycles'])]
        logs[label]=(batch/(label+'.launch.log')).open('xb');commands[label]=cmd;processes[label]=subprocess.Popen(cmd,cwd=ROOT,stdout=logs[label],stderr=subprocess.STDOUT)
    dump(batch/'plan.json',{'plan':plan,'plan_sha256':sha(a.plan),'revision':revision,'commands':commands});print('BATCH_DIRECTORY='+str(batch),flush=True)
    while processes:
        for label,proc in list(processes.items()):
            rc=proc.poll()
            if rc is None:continue
            logs[label].close();text=(batch/(label+'.launch.log')).read_text();paths=[s.split('=',1)[1]for s in text.splitlines()if s.startswith('RUN_DIRECTORY=')];r={'exit_status':rc,'run_directory':paths[-1]if paths else None}
            if rc==0:
                with(batch/(label+'.analysis.log')).open('xb')as f:v=subprocess.run([sys.executable,str(scripts/'analyze_pilot.py'),r['run_directory']],cwd=ROOT,stdout=f,stderr=subprocess.STDOUT)
                r['analysis_exit_status']=v.returncode
            results[label]=r;del processes[label];dump(batch/'results.json',results);print(label+' '+json.dumps(r),flush=True)
        if processes:print('RUNNING='+','.join(processes),flush=True);time.sleep(30)
    return any(r['exit_status']!=0 or r.get('analysis_exit_status',0)!=0 for r in results.values())
if __name__=='__main__':raise SystemExit(main())
