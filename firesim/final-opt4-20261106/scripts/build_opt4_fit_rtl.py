#!/usr/bin/env python3
"""Pinned derived whole-system elaboration/GoldenGate; no frozen writes or FPGA."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,shutil,signal,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc
from prepare_opt4_fit_modules import JAVA,CPFILE

COMMIT='8da24a269b98a0d6a8f57b030353a310812c4344'
F=W/'Opt4-fit-20261110'
O=F/'builds'/('system-'+COMMIT[:8])
L=D/'build-logs'/('Opt4-fit-system-'+COMMIT[:8])
S=D/'Opt4-fit-rtl-state.json'
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-rtl.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(parents=True,exist_ok=True);L.mkdir(exist_ok=True)
    b=json.loads((F/'bindings'/f'{COMMIT}.json').read_text())
    compiled=json.loads((D/'Opt4-fit-integration-compile-state.json').read_text())
    assert compiled['status']=='PASS_FIVE_MODIFIED_SOURCES_COMPILE_ONLY' and compiled['fit_commit']==COMMIT
    for rel,r in compiled['source_snapshots'].items():
        assert sha(r['snapshot'])==r['sha256']
        assert Path(r['snapshot']).read_bytes()==subprocess.check_output(['git','show',COMMIT+':'+rel],cwd=F)
    classes=O/'source-classes'
    if not classes.exists():
        shutil.copytree(D/'build-logs/Opt4-fit-modules-20261110/integration-compile/classes',classes)
    class_hashes={str(p.relative_to(classes)):sha(p) for p in sorted(classes.rglob('*.class'))}
    assert len(class_hashes)==31
    cp=CPFILE.read_text().strip()
    firechip=W/'C4/chipyard/generators/firechip/target/scala-2.13/firechip_2.13-1.6.jar'
    cp=str(classes)+':'+str(firechip)+':'+cp
    jars={p:sha(p) for p in dict.fromkeys(cp.split(':')) if Path(p).is_file()}
    manifest=dict(profile='Opt4-fit-C4-SVB32-20261110',hardware_commit=COMMIT,
        frozen_parent_commit=b['frozen_commit'],source_id=b['source_id'],source_tree=str(F/'chipyard'),
        compiled_source_snapshots=compiled['source_snapshots'],private_class_hashes=class_hashes,
        classpath=cp,class_path_source_receipt_sha256=sha(CPFILE),reused_frozen_jar_hashes=jars,
        configuration='DacOpt4C4',platform_config='DacXilinxAlveoConfig',
        firesim_commit=json.loads((W/'integration.json').read_text())['firesim_checkpoint_commit'],
        fpga_access=False,formal_admission=False)
    if (O/'inputs.json').exists():assert json.loads((O/'inputs.json').read_text())==manifest
    else:save(O/'inputs.json',manifest)
    st=dict(schema='ec-opt4-fit-whole-rtl/1',status='STARTING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),
        **manifest,output_dir=str(O),log_dir=str(L),stages={})
    save(S,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8'}
    java=[str(JAVA),'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=8','-Dec.dac.firesim=true']
    def stage(name,args,expected,timeout):
        receipt=L/(name+'-result.json')
        if receipt.exists():
            r=json.loads(receipt.read_text())
            if r.get('returncode')==0 and r.get('source_id')==b['source_id']:
                assert all(sha(p)==h for p,h in r['outputs'].items())
                st['stages'][name]=r;save(S,st);return Path(r['output_dir'])
        n=len(list(O.glob(name+'-attempt-*')))+1;out=O/(name+'-attempt-'+str(n));out.mkdir()
        argv=['nice','-n','10']+java+args(out)
        log=L/(name+'-attempt-'+str(n)+'.log')
        r=dict(stage=name,source_id=b['source_id'],hardware_commit=COMMIT,argv=argv,output_dir=str(out),
            log=str(log),started_utc=now(),returncode=None)
        with log.open('ab',buffering=0) as f:
            p=subprocess.Popen(argv,cwd=F/'chipyard',env=env,stdin=subprocess.DEVNULL,
                stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            st.update(status='RUNNING_'+name.upper(),child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks'])
            st['stages'][name]=r;save(S,st);start=time.monotonic()
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now(),stage_wall_seconds=time.monotonic()-start);save(S,st);os.fsync(f.fileno())
                if time.monotonic()-start>timeout or shutil.disk_usage(O).free<60*2**30:
                    os.killpg(p.pid,signal.SIGTERM)
                    try:p.wait(timeout=20)
                    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                    raise RuntimeError((name,'private RTL stage guard'))
            r.update(returncode=p.returncode,ended_utc=now(),wall_seconds=time.monotonic()-start)
        assert p.returncode==0,(name,p.returncode,str(log))
        assert all((out/n).exists() and (out/n).stat().st_size>0 for n in expected)
        r['outputs']={str(p):sha(p) for p in sorted(out.rglob('*')) if p.is_file()}
        save(receipt,r);st['stages'][name]=r;save(S,st);return out

    params=stage('parameters',lambda out:['-cp',cp,'firesim.firesim.DacParameterAudit',
        'firesim.firesim.DacOpt4C4',str(out/'parameters.json')],['parameters.json'],300)
    original=W/'builds/C4-parameters-20261106T100204.040607Z/parameters.json'
    assert json.loads((params/'parameters.json').read_text())==json.loads(original.read_text()),'common/core/checker/cache/memory configuration changed'
    st['configuration_matches_frozen_parameters']=True;save(S,st)
    elab=stage('elaborate',lambda out:['-verbose:class','-cp',cp,'chipyard.Generator','--target-dir',str(out),
        '--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim',
        '--legacy-configs','firesim.firesim:DacOpt4C4'],
        ['firesim.firesim.FireSim.fir','firesim.firesim.FireSim.anno.json'],1800)
    text=Path(st['stages']['elaborate']['log']).read_text(errors='replace')
    names=['boom.lsu.PackageAddressStats','boom.lsu.SafePrefixScanner','boom.lsu.BoomNonBlockingDCache',
        'freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats','sifive.blocks.inclusivecache.InclusiveCache']
    origins={n:[l for l in text.splitlines() if n in l and str(classes) in l] for n in names}
    assert all(origins.values()),('modified class origin missing',origins)
    save(L/'modified-class-origins.json',origins)
    st['modified_class_origins_verified']=True;save(S,st)
    gg=stage('goldengate',lambda out:['-cp',cp,'midas.stage.GoldenGateMain',
        '-i',str(elab/'firesim.firesim.FireSim.fir'),'-td',str(out),
        '-faf',str(elab/'firesim.firesim.FireSim.anno.json'),'-ggcp','firesim.configs','-ggcs','DacXilinxAlveoConfig',
        '--output-filename-base','FireSim-generated','--no-dedup'],
        ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.defines.vh'],10800)
    # Exactly once after the successful compiler stage; keep a completion marker
    # so a reconnect cannot append blackbox resources a second time.
    marker=gg/'blackbox-append.complete.json'
    if not marker.exists():
        listing=gg/'firrtl_black_box_resource_files.f';added={}
        if listing.exists():
            with (gg/'FireSim-generated.sv').open('ab') as f:
                for line in listing.read_text().splitlines():
                    if line.strip():
                        path=Path(line.strip());f.write(path.read_bytes());f.write(b'\n');added[str(path)]=sha(path)
                f.flush();os.fsync(f.fileno())
        save(marker,dict(resources=added,output_sha256=sha(gg/'FireSim-generated.sv')))
    assert all(sha(p)==h for p,h in jars.items()),'reused frozen dependency bytecode changed'
    assert all(sha(classes/p)==h for p,h in class_hashes.items())
    outputs={str(p):sha(p) for p in sorted(gg.iterdir()) if p.is_file()}
    st.update(status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',ended_utc=now(),goldengate_dir=str(gg),
        elaboration_dir=str(elab),outputs=outputs,full_dut_synthesis=False)
    save(L/'rtl-result.json',st);save(S,st);print(json.dumps(dict(status=st['status'],source_id=b['source_id'],goldengate_dir=str(gg))),flush=True)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if S.exists():
            s=json.loads(S.read_text());s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,s)
        raise
