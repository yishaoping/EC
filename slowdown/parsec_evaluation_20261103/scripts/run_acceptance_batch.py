#!/usr/bin/env python3
"""Five bounded private acceptance runs; never expand to the main matrix here."""
import argparse,datetime,json,subprocess,sys,time,uuid
from pathlib import Path
from run_pilot import ROOT,OUT,dump
def main():
    p=argparse.ArgumentParser();p.add_argument('candidate',type=Path);a=p.parse_args();candidate=a.candidate.resolve()
    assert subprocess.check_output(['git','status','--porcelain=v1'],cwd=ROOT,text=True)==''
    batch=OUT/'build'/('acceptance_'+datetime.datetime.now(datetime.timezone.utc).strftime('%H%M%S_')+uuid.uuid4().hex[:8]);batch.mkdir()
    scripts=OUT/'scripts';jobs=[('bfs',[sys.executable,str(scripts/'run_bfs_regression.py'),'--hardware-revision',str(candidate)])]
    for app,mode in [('blackscholes','correction'),('streamcluster','correction')]:jobs.append((app+'_'+mode,[sys.executable,str(scripts/'run_pilot.py'),app+'_simdev',mode,'--max-cycles','3000000','--hardware-revision',str(candidate),'--validation']))
    processes={};logs={};commands={}
    for label,cmd in jobs:
        logs[label]=(batch/(label+'.launch.log')).open('xb');commands[label]=cmd
        processes[label]=subprocess.Popen(cmd,cwd=ROOT,stdout=logs[label],stderr=subprocess.STDOUT)
    dump(batch/'commands.json',commands);print('BATCH_DIRECTORY='+str(batch),flush=True);results={}
    while processes:
        for label,proc in list(processes.items()):
            rc=proc.poll()
            if rc is None:continue
            logs[label].close();text=(batch/(label+'.launch.log')).read_text();paths=[line.split('=',1)[1]for line in text.splitlines()if line.startswith('RUN_DIRECTORY=')]
            result={'exit_status':rc,'run_directory':paths[-1]if paths else None,'command':commands[label]}
            if rc==0 and label!='bfs':
                cmd=[sys.executable,str(scripts/'analyze_pilot.py'),result['run_directory']]
                with(batch/(label+'.analysis.log')).open('xb')as f:r=subprocess.run(cmd,cwd=ROOT,stdout=f,stderr=subprocess.STDOUT)
                result['analysis_exit_status']=r.returncode
            results[label]=result;del processes[label];dump(batch/'results.json',results);print(label+' '+json.dumps(result),flush=True)
        if processes:print('RUNNING='+','.join(processes),flush=True);time.sleep(30)
    return any(r['exit_status']!=0 or r.get('analysis_exit_status',0)!=0 for r in results.values())
if __name__=='__main__':raise SystemExit(main())
