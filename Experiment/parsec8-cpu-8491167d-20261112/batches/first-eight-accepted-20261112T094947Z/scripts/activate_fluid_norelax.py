from common import *
import subprocess,re,signal,time,sys

mp=ROOT/'software/fluidanimate_real_advanceparticles_norelax/manifest.json';mf=read(mp)
cmd=['/usr/bin/spike','-p1','-m1024','--isa=rv64gc_zicntr_zihpm',mf['elf']['native']['path']]
p=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,timeout=60,text=True)
log=ROOT/'audit/fluid-advance-norelax-functional.log';log.write_text(p.stdout)
rows=[x for x in p.stdout.splitlines() if x.startswith(('[OUTPUT]','[ROI]','[APP]','[IRQ]','[END]'))]
assert p.returncode==0 and '[END] hart=0 status=PASS' in rows and any('verified=1' in x for x in rows)
save(ROOT/'audit/fluid-advance-norelax-functional.json',dict(created_utc=now(),command=cmd,passed=True,functional_only=True,log=str(log),log_sha256=sha(log),manifest_sha256=sha(mp),rows=rows))
objdump=str(TOOLS/'riscv64-unknown-elf-objdump');dis={};mn={}
for variant in ['fluidanimate_real_advanceparticles','fluidanimate_real_advanceparticles_norelax']:
 for mode in ['native','ec']:
  key=variant+'-'+mode
  txt=subprocess.check_output([objdump,'-d','--disassemble=_Z16AdvanceParticlesv',str(ROOT/'software'/variant/(mode+'.riscv'))],text=True)
  f=ROOT/'diagnostics'/(key+'-AdvanceParticles.asm');f.write_text(txt);dis[key]={'path':str(f),'sha256':sha(f)}
  mn[key]=[m[1] for x in txt.splitlines() if (m:=re.match(r'\s*[0-9a-f]+:\s+[0-9a-f]+\s+(\S+)',x))]
assert mn['fluidanimate_real_advanceparticles_norelax-native']==mn['fluidanimate_real_advanceparticles_norelax-ec']
assert len(mn['fluidanimate_real_advanceparticles-native'])==len(mn['fluidanimate_real_advanceparticles-ec'])+1
assert sha(mp.parent/'source/capture-before.bin')==sha(ROOT/'software/fluidanimate_real_advanceparticles/source/capture-before.bin')
save(ROOT/'diagnostics/fluid-link-relaxation-mismatch.json',dict(created_utc=now(),functional_baseline=BASE,proven_finding='Original shared-object linked Native cells load uses AUIPC+LD, EC uses gp-relative LD; original static phase mnemonics differ by exactly one AUIPC. New both-no-relax phase mnemonic sequences are identical.',prior_native_instructions=31610,prior_ec_instructions=31609,prior_pair_excluded=True,disassembly=dis,static_mnemonics=mn,new_manifest=str(mp),new_manifest_sha256=sha(mp),functional_preflight=str(ROOT/'audit/fluid-advance-norelax-functional.json'),limitation='Static linked-code comparability repair, not hardware change; new cycle-exact pair still required; no old cycles reused'))
q=read(ROOT/'queue.json');save(ROOT/'audit/queue-before-fluid-norelax.json',q)
for x in q['items']:
 if x['benchmark']=='fluidanimate':x['manifest']=str(mp.relative_to(ROOT))
save(ROOT/'queue.json',q)
h=read(ROOT/'audit/fluid-norelax-scheduler-hold.json');old=h['controller'];assert ident(old['pid'])==old
os.kill(old['pid'],signal.SIGTERM);os.kill(old['pid'],signal.SIGCONT)
for i in range(20):
 try:state=Path(f'/proc/{old["pid"]}/stat').read_text().rsplit(')',1)[1].split()[0]
 except FileNotFoundError:break
 if state=='Z':break
 time.sleep(.1)
else:raise RuntimeError('Own held scheduler still live')
log=(ROOT/'campaign-v3-launch.log').open('ab')
p=subprocess.Popen([sys.executable,str(ROOT/'scripts/campaign_v3.py')],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
save(ROOT/'audit/controller-fluid-norelax-launch.json',dict(created_utc=now(),controller=ident(p.pid),retired=old,reason='Missing first Native samples take free slots before later EC repeats; all active models preserved',script_sha256=sha(ROOT/'scripts/campaign_v3.py')))
print(json.dumps({'preflight':rows,'new_static_mnemonic_sequences_match':True,'queue_updated':True,'scheduler':ident(p.pid)},indent=2))
