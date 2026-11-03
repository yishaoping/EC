#!/usr/bin/env python3
"""Build a private b3 detection design with final Opt4's core/cache parameters.
Reuses historical launcher isolation, source copy, resource restoration and make flow.
Only three configuration definitions differ; no detection datapath/protocol edits.
"""
import datetime,hashlib,importlib.util,json,os,re,shutil,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/blackscholes_validation'
CHECK=Path('/data1/gzh/EC/check');TARGET=OUT/'build/matched_check'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.write_text(json.dumps(x,indent=2)+'\n')
def main():
    s=importlib.util.spec_from_file_location('historical_launcher',CHECK/'launch_baseline.py');old=importlib.util.module_from_spec(s);s.loader.exec_module(old)
    old.source_identity();environment=old.configured_environment();TARGET.mkdir(parents=True,exist_ok=True)
    assert not (TARGET/'build.manifest.json').exists(), 'Never overwrite a started build'
    src=TARGET/'source';print('COPY_SOURCE='+str(src),flush=True)
    if not src.exists():
        shutil.copytree(CHECK/'source/chipyard',src/'chipyard',symlinks=True)
        shutil.copytree(CHECK/'source/.git',src/'.git',symlinks=True)
    assert not subprocess.check_output(['git','diff','--name-only','--','chipyard'],cwd=src,text=True)
    # Restore the original five recorded missing resources using the established helper.
    _,resources,_=old.resource_checks().restored_inputs(old)
    for relative,payload in resources.items():
        target=src/'chipyard'/relative
        assert not target.is_symlink()
        target.parent.mkdir(parents=True,exist_ok=True)
        if not target.exists():shutil.copy2(payload,target)
        assert sha(target)==sha(payload)
    changed={}
    rel='generators/boom/src/main/scala/common/config-mixins.scala';p=src/'chipyard'/rel
    final=(ROOT/'chipyard'/rel).read_text();a=final.index('class WithNParaMedicBooms(');b=final.index('\n/**',a)
    p.write_text(p.read_text()+'\n'+final[a:b]+'\n');changed[rel]='Append identical frozen WithNParaMedicBooms config definition (no datapath changes).'
    rel='generators/chipyard/src/main/scala/config/RocketConfigs.scala';p=src/'chipyard'/rel;text=p.read_text();a=text.index('class v1Config');b=text.index('//===== EC Config: End',a)
    config=text[a:b].replace('new boom.common.WithNLargeBooms','new boom.common.WithNParaMedicBooms').replace('  new freechips.rocketchip.guardiancouncil.WithGHE ++','  new freechips.rocketchip.subsystem.WithInclusiveCache(\n    nWays = 16, capacityKB = 1024, outerLatencyCycles = 12) ++\n  new freechips.rocketchip.guardiancouncil.WithGHE ++')
    p.write_text(text[:a]+config+text[b:]);changed[rel]='Select matched BOOM and L2 dimensions/latency.'
    rel='generators/rocket-chip/src/main/scala/subsystem/Configs.scala';p=src/'chipyard'/rel;text=p.read_text();a=text.index('class WithNGCCheckers(');b=text.index('//===== GuardianCouncil Function: End',a);block=text[a:b]
    # Only replace the active I$ section; preserve historical fetch4 and detection behavior.
    start=block.index('      icache = Some(ICacheParams(',block.index('  case TilesLocated'))
    block=block[:start]+block[start:].replace('nSets = 64,','nSets = 32,',1).replace('nWays = 8,','nWays = 1,',1)
    p.write_text(text[:a]+block+text[b:]);changed[rel]='Match checker I$ capacity/sets/ways; retain historical fetch and protocol.'
    patch=subprocess.check_output(['git','diff','--','chipyard'],cwd=src,text=True);(TARGET/'configuration_only.patch').write_text(patch)
    files=subprocess.check_output(['git','diff','--name-only','--','chipyard'],cwd=src,text=True).splitlines();assert set(files)=={'chipyard/'+r for r in changed},files
    for name in ['sbt','coursier','native-zlib']:shutil.copytree(CHECK/'cache'/name,TARGET/'cache'/name,symlinks=True)
    for name in ['ivy2','tmp','home']: (TARGET/'cache'/name).mkdir(parents=True,exist_ok=True)
    for name in ['tmp','verilator','generated','dramsim']: (TARGET/name).mkdir(exist_ok=True)
    # Historical make writes DRAMSim in its copied source; all mutations stay private.
    env=environment['environment'];env.update(HOME=str(TARGET/'home'),TMPDIR='/tmp',TMP='/tmp',TEMP='/tmp',CCACHE_DISABLE='1',GIT_CONFIG_NOSYSTEM='1',GIT_CONFIG_GLOBAL='/dev/null',COURSIER_CACHE=str(TARGET/'cache/coursier/v1'),JAVA_TOOL_OPTIONS=' '.join(['-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=8','-Dsbt.supershell=false','-Dsbt.log.noformat=true','-Dsbt.color=false','-Dsbt.ivy.home='+str(TARGET/'cache/ivy2'),'-Dsbt.global.base='+str(TARGET/'cache/sbt'),'-Dsbt.boot.directory='+str(TARGET/'cache/sbt/boot'),'-Dcoursier.cache='+str(TARGET/'cache/coursier/v1'),'-Dsbt.offline=true','-Dsbt.server.autostart=false','-Djava.io.tmpdir=/tmp']))
    native=TARGET/'cache/native-zlib';env['CPLUS_INCLUDE_PATH']=str(native/'include');env['LIBRARY_PATH']=str(native/'lib');env['LDFLAGS']='-Wl,-rpath,'+str(native/'lib')
    make=[environment['tools']['make'],'-C',str(TARGET/'verilator'),'-f',str(src/'chipyard/sims/verilator/Makefile'),'base_dir='+str(src/'chipyard'),'sim_dir='+str(TARGET/'verilator'),'gen_dir='+str(TARGET/'generated'),'build_dir='+str(TARGET/'generated'),'output_dir='+str(TARGET/'make-output'),'CONFIG=v1Config','VERILATOR_THREADS=1','SBT_BIN='+env['JAVA_HOME']+'/bin/java -jar '+environment['sbt_launch_jar'],'JAVA_TMP_DIR=/tmp','-j16']
    record={'base_commit':old.REV,'source_identity':old.source_identity(),'changed_configuration_files':changed,'configuration_patch_sha256':sha(TARGET/'configuration_only.patch'),'environment':env,'commands':[],'started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'state':'BUILDING','source_configuration_sha256':{r:sha(src/'chipyard'/r) for r in changed}}
    dump(TARGET/'build.manifest.json',record)
    for phase in ['verilog','default']:
        command=make+[phase];wrapped=['/usr/bin/bwrap','--die-with-parent','--new-session','--unshare-all','--ro-bind','/','/','--bind',str(TARGET),str(TARGET),'--bind',str(TARGET/'tmp'),'/tmp','--bind',str(TARGET/'tmp'),'/var/tmp','--dev','/dev','--chdir',str(TARGET)]
        for k,v in env.items():wrapped+=['--setenv',k,v]
        wrapped+=['--',*command];record['commands'].append({'argv':command,'sandbox_argv':wrapped});dump(TARGET/'build.manifest.json',record)
        print('PHASE='+phase,flush=True)
        with (TARGET/(phase+'.log')).open('xb') as log:r=subprocess.run(wrapped,env={'PATH':'/usr/bin:/bin'},stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
        if r.returncode:record.update(state='FAILED',failed_phase=phase,returncode=r.returncode);dump(TARGET/'build.manifest.json',record);raise RuntimeError('Build failed: '+phase)
    sim=TARGET/'verilator/simulator-chipyard-v1Config';record.update(state='BUILT',simulator=str(sim),simulator_sha256=sha(sim),ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());dump(TARGET/'build.manifest.json',record);print('BUILT='+str(sim),flush=True)
if __name__=='__main__':main()
