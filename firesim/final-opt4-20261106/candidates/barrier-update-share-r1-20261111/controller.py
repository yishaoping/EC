#!/usr/bin/python3
"""Bound local transition SAT, full frozen comparison, real module mapping.

No whole synthesis, promotion, device I/O, live input modification, or retry.
"""
from pathlib import Path
import datetime, fcntl, hashlib, importlib.util, json, os, re, shutil, subprocess, time

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-barrier-update-share-r1-20261111'
S=D/'Opt4-fit-barrier-update-share-r1-state.json'
FROZEN='8491167d84b6d9521b151a743673c1516926a1f8'

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
    p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)
def identity(pid):
    try:
        x=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=x[19],process_state=x[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:return {}
def live(x):
    y=identity(x.get('pid',0))
    return bool(y and all(str(x.get(k))==str(y[k]) for k in ['start_ticks','host_boot_id']) and y['process_state'] not in ['Z','X'])
def policy():
    p=read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit']==FROZEN and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and not p['fpga_access']
    return p

def main():
    policy()
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(S);assert not live(old) and not live(old.get('child',{})), 'Adopt live identity'
    assert not old, 'Preserve this attempt; recovery requires another version'
    cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);src=F/cfg['source_relative']
    hashes=read(C/'input-hashes.json')
    assert all(sha(p)==h for p,h in hashes.items()), 'immutable inputs changed'
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
    assert src.read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+cfg['source_relative']],cwd=F)
    assert set(subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines())=={cfg['source_relative'],'lineage.json'}
    for co in policy()['forbidden_extension_commits']:
        assert subprocess.run(['git','merge-base','--is-ancestor',co,b['hardware_commit']],cwd=F).returncode==1
    recipe=read(C/'reverse-recipe.json');text=src.read_text()
    assert text.count(recipe['helper'])==1 and text.count(recipe['new'])==1
    back=text.replace(recipe['helper'],'',1).replace(recipe['new'],recipe['old'],1)
    assert back==(C/'parent.scala.txt').read_text()
    assert back.encode()==subprocess.check_output(['git','show',b['parent_commit']+':'+cfg['source_relative']],cwd=F)
    assert (C/'frozen.scala.txt').read_bytes()==subprocess.check_output(['git','show',FROZEN+':'+cfg['source_relative']],cwd=F)
    # Existing matched source emissions and reference map are immutable accepted
    # checkpoints. Reuse only when the exact entire source bytes are identical.
    prior=W/'candidates/barrier-event-read-r1-20261111'
    prev=D/'build-logs/Opt4-fit-barrier-event-read-r1-20261111'
    pr=read(prev/'proof-result.json')
    assert pr['status']=='PASS_LOCAL_SAT_AND_COMPLETE_FROZEN_8192_CYCLES_MAPPING_PENDING'
    assert back==(prior/'parent.scala.txt').read_text()
    assert (C/'frozen.scala.txt').read_bytes()==(prior/'frozen.scala.txt').read_bytes()
    for label in ['frozen','parent']:
        rtl=prev/label/'GHBarrierLatencyStats.v'
        assert sha(rtl)==pr['rtl_hashes'][label]
        stage=pr['stages']['emit-'+label]
        assert stage['accepted_result'] and not stage['missing_outputs']
        assert stage['outputs'][str(rtl)]==sha(rtl)
    st=dict(schema='ec-opt4-barrier-update-share/1',**identity(os.getpid()),hardware_commit=b['hardware_commit'],source_id=b['source_id'],functional_baseline_commit=FROZEN,parent_commit=b['parent_commit'],status='STARTING',started_utc=now(),stages={},exact_parent_reversal=True,source_sha256=sha(src),fpga_access=False,full_dut_synthesis=False,full_dut_formal=False,whole_dut_admission=False,production_selected=False)
    def update(**kw):st.update(kw,updated_utc=now());save(S,st)
    update()
    save(O/'source-reconstruction.json',dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='EXACT_PARENT_RECONSTRUCTED_ONLY_EVENT_UPDATE_BLOCK_AND_HELPER_CHANGED',parent_sha256=sha(C/'parent.scala.txt'),frozen_sha256=sha(C/'frozen.scala.txt'),prior_proof_receipt=str(prev/'proof-result.json'),prior_proof_sha256=sha(prev/'proof-result.json'),reference_source_identical=True,baseline_commit=FROZEN))
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'4','CCACHE_DISABLE':'1','MAKEFLAGS':'-j4'}
    def run(label,argv,sub,outputs=(),negative=False):
        policy()
        while True:
            mem=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
            if mem>=48*2**20 and shutil.disk_usage(W).free>=40*2**30:break
            update(status='WAITING_RESOURCE_GATE',next_stage=label);time.sleep(300)
        sub.mkdir(parents=True,exist_ok=True);log=sub/(label+'-attempt-1.log')
        assert not log.exists(), 'No blind retry of partial stage'
        args=list(map(str,['nice','-n','15',*argv]))
        with log.open('xb',buffering=0) as stream:
            p=subprocess.Popen(args,cwd=sub,env=env,stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT)
            update(status='RUNNING_'+label.upper(),active_stage=label,child=identity(p.pid),stage_log=str(log))
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                update();os.fsync(stream.fileno())
        accepted=p.returncode!=0 if negative else p.returncode==0
        row=dict(argv=args,returncode=p.returncode,accepted=accepted,negative=negative,log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if Path(p).is_file()},missing_outputs=[str(p) for p in outputs if not Path(p).is_file()],ended_utc=now(),hardware_commit=b['hardware_commit'],source_id=b['source_id'])
        save(sub/(label+'-result.json'),row);st['stages'][label]=row;update(child={})
        assert accepted and not row['missing_outputs'],(label,p.returncode,str(log))
        return log
    classes=O/'classes';classes.mkdir(exist_ok=True)
    cp=':'.join(cfg['classpath']);compiler=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes]
    run('compile',compiler+[src,C/'Emit.scala'],O,[classes/'opt4barriershare/Emit.class'])
    cp=str(classes)+':'+cp
    for mode,top in [('slots','SlotWriteProof'),('arithmetic','ArithmeticProof'),('module','GHBarrierLatencyStats')]:
        sub=O/mode;rtl=sub/(top+'.v')
        run('emit-'+mode,[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',cp,'opt4barriershare.Emit',mode,sub],sub,[rtl])
        if mode!='module':
            for prop,negative in [('equivalent',False),('mutantEquivalent',True)]:
                log=run('sat-'+mode+'-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top {top} -flatten; sat -verify -prove io_{prop} 1 -timeout 180'],sub,negative=negative)
                assert ('proof did fail' if negative else 'SUCCESS') in log.read_text() and 'TIMEOUT' not in log.read_text()
    update(local_formal='PASS_ARBITRARY256_SLOT_EVENT_RESOLVE_RESET_PRIORITY_BITWISE_LIFT_AND_FULL64BIT_MODULAR_ARITHMETIC',negative_mutations_rejected=True)
    save(O/'bitwise-lifting.json',dict(slots=256,proof_payload_bits=1,production_payload_bits=[1,32,64],argument='Each static slot write has identical address and enable, no payload-dependent decode. One-bit hold/clear/write equality lifts independently to every unchanged payload bit. Full64bit allocate/increment/cycle arithmetic proved separately. Valid/seq use same selector and allocate predicate. All bucket state and all outputs also compared in full-module runtime.',source_bound_helper='GHBarrierEventUpdate',source_sha256=sha(src),not_full_dut_formal=True))
    sub=O/'comparison';sub.mkdir(exist_ok=True)
    for variant,top in [('frozen','FrozenBarrier'),('parent','ParentBarrier')]:
        (sub/(top+'.v')).write_text((prev/variant/'GHBarrierLatencyStats.v').read_text().replace('module GHBarrierLatencyStats(','module '+top+'(',1))
    spec=importlib.util.spec_from_file_location('barrier_tb',C/'generate_tb.py');module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    tb=sub/'tb.v';tb.write_text(module.generate());exe=sub/'compare.vvp'
    rtl=O/'module/GHBarrierLatencyStats.v'
    assert len(re.findall(r'^  reg \[63:0\] buckets_count_\d+;',rtl.read_text(),re.M))==256
    run('compile-comparison',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,sub/'FrozenBarrier.v',sub/'ParentBarrier.v',rtl,tb],sub,[exe])
    log=run('full-frozen-comparison',['/usr/bin/vvp',exe],sub)
    assert 'BARRIER_COMPLETE_FROZEN_PARENT_CANDIDATE_PASS cycles=8192 observations=16384 outputs=7 bucket_fields=1024' in log.read_text()
    update(complete_module_comparison='PASS8192CYCLES_16384_PRE_POST_EDGE_OBSERVATIONS_ALL7OUTPUTS_1024STATE_FIELDS_GLOBAL_STATS_RESET_OVERFLOW_COLLISION_PRIORITY')
    prior_map=read(prev/'map-result.json');reference=prior_map['maps']['parent']
    assert prior_map['status']=='VERIFIED_AND_PAIRED_MAPPED_MODULE_ONLY_NOT_SELECTED'
    assert sha(reference['report'])==reference['report_sha256']
    original_tcl=(prev/'map-parent/map.tcl').read_text()
    assert 'synth_design -top GHBarrierLatencyStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized' in original_tcl
    sub=O/'map-candidate';sub.mkdir(exist_ok=True);report=sub/'utilization.rpt';hier=sub/'hierarchical.rpt';dcp=sub/'module.dcp';tcl=sub/'map.tcl'
    tcl.write_text('set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\nsynth_design -top GHBarrierLatencyStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nset bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]\nif {{[llength $bb]}} {{error "unresolved module dependencies: $bb"}}\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    run('map-candidate',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],sub,[report,hier,dcp])
    counts={}
    for line in report.read_text().splitlines():
        m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
        if m:counts.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    assert len(counts)==5 and counts['CLB LUTs']>0 and counts['CLB Registers']==41601
    candidate=dict(resources=counts,report=str(report),report_sha256=sha(report),hierarchy=str(hier),checkpoint=str(dcp),rtl_sha256=sha(rtl),tcl_sha256=sha(tcl))
    saved=reference['resources']['CLB LUTs']-counts['CLB LUTs']
    update(status='VERIFIED_AND_MAPPED_COMPLETE_BARRIER_MODULE_NOT_WHOLE_DUT',maps=dict(reference=reference,candidate=candidate),measured_lut_saving=saved,reference_map_reuse_reason='Entire e0 source byte-identical to accepted mapped9ae source, exact prior emittedRTL hash and samepart/top/directive/maxthreads.',ended_utc=now(),child={},scope='Complete256slot GHBarrierLatencyStats OOC comparison. Not integrated DCache, postopt whole area, timing, FIT, or real FPGA result.')
    save(O/'result.json',st)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=read(S)
        if state.get('pid')==os.getpid():state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,state)
        raise
