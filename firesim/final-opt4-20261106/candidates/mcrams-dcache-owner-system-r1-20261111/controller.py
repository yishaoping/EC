#!/usr/bin/python3
"""CPU-only exact-emitted-target host transform; never a production admission."""
import argparse, datetime, fcntl, hashlib, json, os, pathlib, re, subprocess, time
P = pathlib.Path
C = P(__file__).resolve().parent
W = P('/data1/gzh/EC/firesim/final-opt4-20261106')
D = P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L = D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111'
S = D/'Opt4-mcrams-dcache-owner-system-r1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ROOT = W/'Opt4-fit-dcache-field-read-prune-r1-20261111'
BUILD = ROOT/'builds/system-3656aec4-r4'
RAW = BUILD/'elaborate/firesim.firesim.FireSim.fir'
ANNO = RAW.with_suffix('.anno.json')
LOW = BUILD/'goldengate/post-bridge-extraction.fir'
SOURCE = ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
ADD = {'class':'midas.targetutils.FirrtlMemModelAnnotation',
       'target':'~FireSim|BoomNonBlockingDCache>ownerImageMemory'}
ST = {}
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
    h=hashlib.sha256()
    with P(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()
def read(p): return json.loads(P(p).read_text())
def save(p,x):
    p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)
def identity(pid=None):
    pid=pid or os.getpid()
    try:
        a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:return {}
def live(i): return bool(i) and identity(i['pid'])==i
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST);save(L/'state.json',ST)
def module(text):
    return re.search(r'^  module BoomNonBlockingDCache :\n.*?(?=^  (?:ext)?module |\Z)',text,re.M|re.S)[0]
def blocks(m):
    out={}
    for b in re.finditer(r'^    mem (owner(?:Image|Generation|Packet|Tracked)Memory(?:_flattened)?) :[^\n]*\n(?:      [^\n]*\n)+',m,re.M):
        body=b[0];get=lambda k:re.search(r'^      '+k+r' => (.+)$',body,re.M)[1]
        out[b[1]]=dict(width=int(re.search(r'UInt<(\d+)>',get('data-type'))[1]),depth=int(get('depth')),
          read_latency=int(get('read-latency')),write_latency=int(get('write-latency')),read_under_write=get('read-under-write'),
          readers=re.findall(r'^      reader => (.+)$',body,re.M),writers=re.findall(r'^      writer => (.+)$',body,re.M),
          readwriters=re.findall(r'^      readwriter => (.+)$',body,re.M),block_sha256=hashlib.sha256(body.encode()).hexdigest())
    return out
def audit():
    plan=read(C/'plan.json')
    for p,h in plan['inputs'].items():assert sha(p)==h,'input version mismatch: '+p
    for p,h in plan['evidence_sources'].items():assert sha(p)==h,'completed evidence mismatch: '+p
    original=read(ANNO);candidate=read(C/'owner-only.anno.json')
    assert candidate==original+[ADD], 'exact one-annotation delta violated'
    assert len([a for a in original if 'FirrtlMemModelAnnotation' in a.get('class','')])==10
    assert len([a for a in original if 'EnableModelMultiThreadingAnnotation' in a.get('class','')])==5
    assert ADD not in original
    raw=RAW.read_text();assert raw.count('cmem ownerImageMemory :')==1
    assert '{ valid : UInt<1>, writer : UInt<16>, generation : UInt<32>, contentSeq : UInt<32>}[512]' in raw or re.search(r'cmem ownerImageMemory :.*\[512\]',raw)
    m=module(LOW.read_text());mem=blocks(m)
    for n,w,r in [('ownerImageMemory_flattened',81,35),('ownerGenerationMemory',32,518),('ownerPacketMemory',32,4),('ownerTrackedMemory',1,4)]:
        x=mem[n];assert (x['width'],x['depth'],x['read_latency'],x['write_latency'],x['read_under_write'])==(w,512,0,1,'undefined')
        assert len(x['readers'])==r and len(x['writers'])==1 and not x['readwriters']
    source=SOURCE.read_text()
    for s in ['when (ownerWriteEnable && !reset.asBool)',
      'ownerWritten = RegInit(VecInit(Seq.fill(nSets * nWays)(false.B)))',
      'Mux(ownerWritten(index), ownerImageMemory.read(index), 0.U.asTypeOf(new CacheImageKey))']:
        assert s in source
    # These connections include 512 generation/debug observations, all reads,
    # the reset-gated writer, and each original address/en/clock/data path.
    lines=[x for x in m.splitlines() if any(n in x for n in mem)]
    conn='\n'.join(lines)+'\n'
    bind=dict(schema='ec-exact-owner-only-host-annotation-audit/1',utc=now(),functional_baseline=BASE,derived_hardware=HW,
      raw_target_unchanged=True,rtl_unchanged=True,source_unchanged=True,original_annotations=len(original),
      new_annotations=len(candidate),preserved_existing_memory_annotations=10,preserved_MT_annotations=5,
      exactly_added_annotation=ADD,memories=mem,target_module_sha256=hashlib.sha256(m.encode()).hexdigest(),
      memory_connections_sha256=hashlib.sha256(conn.encode()).hexdigest(),fpga_access=False,production_admission=False,
      proof_scope='Finite actual memory interface proof only; not a full derived-DUT equivalence claim',
      area_scope='Paired actual isolated memory host-entry only; not whole-system FIT')
    save(L/'preflight.json',bind);return bind
def stage(name,args,outputs):
    q=L/'receipts'/f'{name}.json';log=L/(name+'.log');active=L/(name+'-active.json')
    if q.exists():
        r=read(q);assert r['returncode']==0 and all(P(p).is_file() and sha(p)==h for p,h in r['outputs'].items())
        assert all(P(p).is_file() for p in outputs);return r
    if active.exists():
        old=read(active)
        if live(old['identity']):
            update(status='ADOPTED_LIVE_CHILD_NO_DUPLICATE',stage=name,child=old['identity'])
            while live(old['identity']):time.sleep(60)
        raise RuntimeError('Interrupted stage requires independent recovery version; raw outputs preserved: '+name)
    assert not log.exists(),'unreviewed partial log preserved'
    start=time.monotonic();update(status='RUNNING',stage=name)
    with log.open('xb',buffering=0) as f:
        p=subprocess.Popen(args,cwd=C,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
          env={**os.environ,'OMP_NUM_THREADS':'2','LD_LIBRARY_PATH':''})
        save(active,dict(identity=identity(p.pid),argv=args,started_utc=now()))
        update(child=identity(p.pid),argv=args)
        # Remain alive across SSH disconnect. No log-silence or wall timeout kill.
        rc=p.wait();os.fsync(f.fileno())
    r=dict(stage=name,returncode=rc,host_wall_seconds=time.monotonic()-start,completed_utc=now(),argv=args,
      log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if P(p).is_file()})
    save(q,r);update(child={},last_receipt=str(q))
    assert rc==0 and all(P(p).is_file() for p in outputs),(name,rc)
    return r
def post_audit(out,pre):
    # Before host transformation Golden Gate must preserve all target memory
    # ports and observations; equality is checked on the complete target module.
    emitted=module((out/'post-bridge-extraction.fir').read_text())
    assert hashlib.sha256(emitted.encode()).hexdigest()==pre['target_module_sha256'],'target DCache changed before host transform'
    assert blocks(emitted)==pre['memories'],'memory ports changed'
    allfir=sorted(out.glob('*.fir'))
    matched=[]
    for p in allfir:
        if p.name=='post-bridge-extraction.fir':continue
        text=p.read_text()
        if 'ownerImageMemory' in text and ('RamModel' in text or 'read_cmds_34' in text):
            matched.append(dict(path=str(p),sha256=sha(p),has_ownerImageMemory=True,
              has_read_cmds_34='read_cmds_34' in text,has_RamModel='RamModel' in text))
    assert matched,'no extracted ownerImageMemory host model evidence'
    # Do not silently call a model-level structural audit full target parity.
    save(L/'post-transform-audit.json',dict(status='HOST_TRANSFORM_STRUCTURAL_AUDIT_ONLY',
      target_DCache_module_exact=True,all_original_35_image_and_518_generation_reads_preserved=True,
      original_target_input_hashes_unchanged=all(sha(p)==h for p,h in read(C/'plan.json')['inputs'].items()),
      host_model_checkpoints=matched,production_admission=False,full_target_parity='REQUIRED_NOT_YET_PASSED'))
def main():
    p=argparse.ArgumentParser();p.add_argument('--run',action='store_true');p.add_argument('--audit',action='store_true');a=p.parse_args();assert a.run or a.audit
    L.mkdir(parents=True,exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    permitted=set(os.sched_getaffinity(0));pin={250,251};assert pin<=permitted;os.sched_setaffinity(0,pin)
    ST.update(schema='ec-mcrams-full-emitted-owner-only/1',**identity(),started_utc=now(),functional_baseline=BASE,
      derived_hardware=HW,fpga_access=False,production_admission=False,cpus=sorted(pin),no_new_whole_cad=True)
    pre=audit();update(status='PREFLIGHT_PASSED',stage='exact-target-audit',preflight=str(L/'preflight.json'))
    if a.audit:return
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json');out=L/'goldengate';out.mkdir(exist_ok=True)
    java=[cfg['java'],'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true','-cp',':'.join(cfg['classpath'])]
    stage('goldengate-owner-only',java+['midas.stage.GoldenGateMain','-i',str(RAW),'-td',str(out),'-faf',str(C/'owner-only.anno.json'),
      '-ggcp','firesim.configs','-ggcs','MCRams_DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],
      [out/'FireSim-generated.sv',out/'FireSim-generated.const.h',out/'post-bridge-extraction.fir'])
    post_audit(out,pre)
    sv=out/'FireSim-generated.sv';bb=out/'firrtl_black_box_resource_files.f';mark=out/'blackboxes-appended.json'
    if not mark.exists():
        with sv.open('a') as f:
            for name in bb.read_text().splitlines() if bb.exists() else []:
                if name.strip():f.write(P(name).read_text())
        save(mark,dict(sha256=sha(sv)))
    else:assert sha(sv)==read(mark)['sha256']
    update(status='HOST_RTL_GENERATED_REQUIRES_FULL_TARGET_PARITY_AND_AREA',stage='complete',completed_utc=now(),
      host_rtl=str(sv),host_rtl_sha256=sha(sv),next_gates=str(C/'next-gates.json'))
    save(L/'result.json',ST)
if __name__=='__main__':
    try:main()
    except Exception as e:
        if L.exists():update(status='FAILED_WITH_EVIDENCE',error=repr(e));save(L/'failure.json',ST)
        raise
