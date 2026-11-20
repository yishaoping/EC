#!/usr/bin/python3
"""Independent paired complete-module maps after accepted proof exits."""
from pathlib import Path
import fcntl, os, re, shutil, subprocess, time
import proof

C=Path(__file__).resolve().parent
D=proof.D;W=proof.W;O=proof.O
S=D/'Opt4-fit-barrier-event-read-map-r1-state.json'

def main():
    lock=(O/'map.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=proof.read(S);assert not proof.live(old) and not proof.live(old.get('child',{}))
    cfg=proof.read(C/'config.json');b=cfg['binding'];hashes=proof.read(C/'input-hashes.json')
    assert all(proof.sha(p)==h for p,h in hashes.items())
    evidence=proof.read(O/'proof-result.json')
    assert evidence['status']=='PASS_LOCAL_SAT_AND_COMPLETE_FROZEN_8192_CYCLES_MAPPING_PENDING'
    assert evidence['hardware_commit']==b['hardware_commit'] and evidence['source_id']==b['source_id']
    assert not proof.live(evidence) and not proof.live(evidence.get('child',{}))
    for stage in evidence['stages'].values():
        assert stage['accepted_result'] and not stage['missing_outputs']
        assert all(proof.sha(p)==h for p,h in stage['outputs'].items())
    st=dict(schema='ec-opt4-barrier-event-read-maps/1',**proof.identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],started_utc=proof.now(),status='STARTING',maps={},stages=old.get('stages',{}),proof_receipt_sha256=proof.sha(O/'proof-result.json'),fpga_access=False,whole_dut_admission=False,scope='Paired complete GHBarrierLatencyStats256 OOC. Not whole-DUT physical area, FIT or timing.')
    def update(**kw):st.update(kw,updated_utc=proof.now());proof.save(S,st)
    update()
    for variant in ['parent','candidate']:
        sub=O/('map-'+variant);sub.mkdir(exist_ok=True);rp=sub/'receipt.json';r=proof.read(rp)
        rtl=O/variant/'GHBarrierLatencyStats.v';assert proof.sha(rtl)==evidence['rtl_hashes'][variant]
        if r:
            assert r['accepted_result'] and all(proof.sha(p)==h for p,h in r['outputs'].items())
        else:
            while int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))<48*2**20 or shutil.disk_usage(W).free<40*2**30:
                update(status='WAITING_RESOURCE_GATE',next_variant=variant);time.sleep(300)
            report=sub/'utilization.rpt';hier=sub/'hierarchical.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
            proof.exact(tcl,'set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\nsynth_design -top GHBarrierLatencyStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
            log=sub/'attempt-1.log';assert not log.exists(),'incomplete/failed map needs versioned recovery'
            argv=list(map(str,['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl]))
            with log.open('xb',buffering=0) as f:
                child=subprocess.Popen(argv,cwd=sub,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'4'},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
                ident=proof.identity(child.pid);st['stages'][variant]=ident
                update(status='RUNNING_MAP_'+variant.upper(),child=ident,active_stage='map-'+variant)
                while child.poll() is None:
                    try:child.wait(timeout=30)
                    except subprocess.TimeoutExpired:pass
                    update();os.fsync(f.fileno())
            outputs=[report,hier,dcp]
            r=dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],accepted_result=child.returncode==0,returncode=child.returncode,outputs={str(p):proof.sha(p) for p in outputs if p.is_file()},missing_outputs=[str(p) for p in outputs if not p.is_file()],rtl_sha256=proof.sha(rtl),tcl_sha256=proof.sha(tcl),argv=argv,log=str(log),ended_utc=proof.now())
            proof.save(rp,r);update(child={});assert r['accepted_result'] and not r['missing_outputs']
        resources={}
        for line in (sub/'utilization.rpt').read_text().splitlines():
            m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
            if m:resources.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
        assert len(resources)==5 and resources['CLB LUTs']>0
        st['maps'][variant]=dict(resources=resources,report=str(sub/'utilization.rpt'),report_sha256=proof.sha(sub/'utilization.rpt'),checkpoint=str(sub/'module.dcp'),receipt_sha256=proof.sha(rp))
        update()
    update(status='VERIFIED_AND_PAIRED_MAPPED_MODULE_ONLY_NOT_SELECTED',ended_utc=proof.now(),measured_lut_saving=st['maps']['parent']['resources']['CLB LUTs']-st['maps']['candidate']['resources']['CLB LUTs'])
    proof.save(O/'map-result.json',st)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=proof.read(S)
        if state.get('pid')==os.getpid():state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=proof.now());proof.save(S,state)
        raise
