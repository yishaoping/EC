#!/usr/bin/env python3
"""Private pair-selection diagnostic; never changes a formal receipt or FPGA input."""
import base64
from collections import Counter
import datetime as dt
import json
import math
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import struct
import time
from board_batch import W,D,save,sha
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

OUTPUT=D/'software/fluidanimate-pair-selection-diagnostic.json'
P=Path('/data1/gzh/EC/Software/PARSEC/pkgs/apps/fluidanimate/src')
TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def compare(a,b):
    x=a.read_bytes();y=b.read_bytes();xh=struct.unpack('<fi',x[:8]);yh=struct.unpack('<fi',y[:8])
    assert xh==yh and len(x)==len(y)==8+xh[1]*36
    rows=[dict(component=n,equal=0,different=0,nonfinite=0,max_absolute_error=0.0) for n in ['px','py','pz','hvx','hvy','hvz','vx','vy','vz']]
    same=0
    for av,bv in zip(struct.iter_unpack('<9f',x[8:]),struct.iter_unpack('<9f',y[8:])):
        same+=av==bv
        for r,u,v in zip(rows,av,bv):
            if u==v:r['equal']+=1
            else:
                r['different']+=1
                if math.isfinite(u) and math.isfinite(v):r['max_absolute_error']=max(r['max_absolute_error'],abs(u-v))
                else:r['nonfinite']+=1
    return dict(particles=xh[1],equal_records=same,exact_bytes_equal=x==y,components=rows,
        equal_particle_record_multiset=Counter(x[i:i+36] for i in range(8,len(x),36))==Counter(y[i:i+36] for i in range(8,len(y),36)))


def main():
    old=json.loads(OUTPUT.read_text()) if OUTPUT.exists() else {}
    if old.get('status')=='COMPLETE_DIAGNOSTIC_ONLY':return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    work=W/'software'/('fluidanimate-pair-diagnostic-'+stamp);work.mkdir()
    logs=D/'software'/work.name;logs.mkdir()
    apps=json.loads((W/'software/fluidanimate-apps-build.json').read_text());base=Path(apps['output_dir'])
    system=json.loads((D/'software/fluidanimate-linux-reference-diagnostic.json').read_text())
    assert system['status']=='COMPLETE_RECOVERED_FROM_EVIDENCE'
    user=Path(apps['host_log_dir'])/'reference-simsmall/out.fluid';linux=Path(system['output_file'])
    state=dict(status='BUILDING_PRIVATE_DIAGNOSTIC',diagnostic_only=True,formal_eligible=False,fpga_operations=False,
        log_dir=str(logs),output_dir=str(work),started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        original_apps_receipt_sha256=sha(W/'software/fluidanimate-apps-build.json'),
        user_reference=str(user),user_reference_sha256=sha(user),linux_reference=str(linux),linux_reference_sha256=sha(linux),
        reference_difference=compare(user,linux),no_formal_inputs_changed=True,commands=[])
    save(OUTPUT,state)
    def call(argv,cwd=work,timeout=600,label='command',env=None):
        argv=list(map(str,argv));log=logs/(label+'.log')
        state.update(stage=label,argv=argv);save(OUTPUT,state)
        with log.open('wb',buffering=0) as f:
            rc=subprocess.run(argv,cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=timeout,
                env=env or {**os.environ,'LD_LIBRARY_PATH':''}).returncode
            os.fsync(f.fileno())
        state['commands'].append(dict(argv=argv,cwd=str(cwd),returncode=rc,log=str(log)));save(OUTPUT,state)
        return rc,log
    # Run the original official comparator with explicit zero tolerance.
    # Without test options fluidcmp performs no numerical tests at all.
    rc,_=call(['g++','-O2',P/'fluidcmp.cpp','-o',work/'fluidcmp'],label='build-official-fluidcmp');assert rc==0
    rc,log=call([work/'fluidcmp',linux,user,'--ptol','0','--vtol','0','--bbox','0'],label='official-fluidcmp')
    state['official_fluidcmp']=dict(source=str(P/'fluidcmp.cpp'),source_sha256=sha(P/'fluidcmp.cpp'),
        binary_sha256=sha(work/'fluidcmp'),returncode=rc,tests='position/velocity/bounding-box, exact zero tolerance',
        log=str(log),formal_gate_changed=False);save(OUTPUT,state)
    src=work/'src';shutil.copytree(base/'src/fluidanimate',src)
    target=src/'serial.cpp';text=target.read_text()
    start=text.index('void ComputeForces()');end=text.index('// ProcessCollisions()',start)
    region=text[start:end]
    condition='if(&neigh->p[iparNeigh % PARTICLES_PER_CELL] < &cell->p[ipar % PARTICLES_PER_CELL])'
    assert region.count(condition)==2
    prefix='''
static unsigned long long ec_pair_seen[2],ec_cross_rejected[2],ec_cross_in_radius[2],ec_pair_selected[2];
static unsigned ec_force_frame;
'''
    region=region.replace('void ComputeForces()\n{','void ComputeForces()\n{\n  for(int ep=0;ep<2;ep++)ec_pair_seen[ep]=ec_cross_rejected[ep]=ec_cross_in_radius[ep]=ec_pair_selected[ep]=0;')
    for phase in range(2):
        instrument='''
              ++ec_pair_seen[PHASE];
              if(&neigh->p[iparNeigh % PARTICLES_PER_CELL] < &cell->p[ipar % PARTICLES_PER_CELL]) ++ec_pair_selected[PHASE];
              else if(cindexNeigh < cindex) {
                ++ec_cross_rejected[PHASE];
                if((cell->p[ipar % PARTICLES_PER_CELL]-neigh->p[iparNeigh % PARTICLES_PER_CELL]).GetLengthSq()<hSq)
                  ++ec_cross_in_radius[PHASE];
              }
              '''.replace('PHASE',str(phase))
        # Advance the search beyond our inserted diagnostic copy of the predicate.
        pos=region.find(condition,0 if phase==0 else previous_end)
        assert pos>=0
        region=region[:pos]+instrument+region[pos:];previous_end=pos+len(instrument)+len(condition)
    pos=region.rfind('\n}')
    region=region[:pos]+'''
  for(int ep=0;ep<2;ep++) fprintf(stderr,"EC_PAIR frame=%u phase=%d seen=%llu selected=%llu cross_rejected=%llu cross_rejected_in_radius=%llu cells=%p pool=%p\\n",
    ec_force_frame,ep,ec_pair_seen[ep],ec_pair_selected[ep],ec_cross_rejected[ep],ec_cross_in_radius[ep],(void*)cells,(void*)pool.datablocks);
  ++ec_force_frame;
'''+region[pos:]
    after=text[:start]+prefix+region+text[end:];target.write_text(after)
    import difflib
    patch=logs/'diagnostic-only.patch';patch.write_text(''.join(difflib.unified_diff(text.splitlines(True),after.splitlines(True),fromfile=str(base/'src/fluidanimate/serial.cpp'),tofile=str(target))))
    state.update(diagnostic_patch=str(patch),diagnostic_patch_sha256=sha(patch),instrumentation='counts only, no pair predicate or numerical update changed');save(OUTPUT,state)
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-D_XOPEN_SOURCE=600','-Wno-invalid offsetof'.replace(' ', '-'),'-I'+str(base/'src/hooks'),'-I'+str(src),'-std=gnu++17','-DENABLE_PARSEC_HOOKS']
    rc,_=call([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,src/'serial.cpp',src/'cellpool.cpp',base/'diagnostic-hooks.o','-lm','-pthread','-o',work/'fluidanimate-pair-diagnostic'],label='build-pair-diagnostic');assert rc==0
    userdir=work/'user';userdir.mkdir();shutil.copy2(base/'inputs/fluidanimate/simsmall/in_35K.fluid',userdir/'in_35K.fluid')
    rc,userlog=call(['/usr/bin/qemu-riscv64',work/'fluidanimate-pair-diagnostic','1','5','in_35K.fluid','out.fluid'],cwd=userdir,label='qemu-user');assert rc==0
    state.update(user_diagnostic_output_sha256=sha(userdir/'out.fluid'),user_original_exact=sha(userdir/'out.fluid')==sha(user));save(OUTPUT,state)
    original_root=Path(json.loads(Path(system['rootfs_receipt']).read_text())['path']).parent/'tree'
    tree=work/'tree';shutil.copytree(original_root,tree,symlinks=True)
    shutil.copy2(work/'fluidanimate-pair-diagnostic',tree/'opt/ec-fpga/fluidanimate-pair-diagnostic')
    init=(tree/'init').read_text().replace('/opt/ec-fpga/fluidanimate-reference 1 5','/opt/ec-fpga/fluidanimate-pair-diagnostic 1 5')
    # Bounded logs only; full numerical output is already recovered from the original run.
    begin=init.index('size=$(');end=init.index('echo EC_LINUX_REFERENCE_DONE',begin)
    init=init[:begin]+init[end:];(tree/'init').write_text(init)
    cpio_newc(tree,work/'initramfs.cpio')
    root=work/'rootfs-build.json';save(root,dict(path=str(work/'initramfs.cpio'),sha256=sha(work/'initramfs.cpio'),diagnostic_only=True))
    kernel=work/'kernel-build.json'
    rc,_=call(['python3',W/'scripts/build_earlyconsole.py','Native','--parent-receipt',W/'software/Native/fluidanimate-kernel-build.json',
        '--rootfs-receipt',root,'--output-receipt',kernel,'--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],label='build-private-kernel');assert rc==0
    image=Path(json.loads(kernel.read_text())['output_dir'])/'arch/riscv/boot/Image';assert 0x80200000+image.stat().st_size<0x82200000
    qemu='/data1/gzh/EC/chipyard/.conda-env/bin/qemu-system-riscv64'
    rc,linuxlog=call([qemu,'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
        '-kernel',image,'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G'],label='qemu-linux');assert rc==0
    raw=linuxlog.read_text().replace('\r','');assert 'EC_LINUX_REFERENCE_EXIT=0' in raw and 'EC_LINUX_REFERENCE_DONE' in raw
    digest=next(line.split()[0] for line in raw.splitlines() if re.fullmatch(r'[0-9a-f]{64}  out\.fluid',line))
    def records(log):
        return [dict(zip(['frame','phase','seen','selected','cross_rejected','cross_rejected_in_radius'],map(int,m.groups())))
            for m in re.finditer(r'EC_PAIR frame=(\d+) phase=(\d+) seen=(\d+) selected=(\d+) cross_rejected=(\d+) cross_rejected_in_radius=(\d+)',log.read_text())]
    ur=records(userlog);lr=records(linuxlog);assert len(ur)==len(lr)==10
    first=next((dict(user=u,linux=l) for u,l in zip(ur,lr) if any(u[k]!=l[k] for k in ['seen','selected','cross_rejected','cross_rejected_in_radius'])),None)
    state.update(status='COMPLETE_DIAGNOSTIC_ONLY',user_pair_records=ur,linux_pair_records=lr,first_observed_pair_count_divergence=first,
        linux_diagnostic_output_sha256=digest,linux_original_exact=digest==sha(linux),
        user_in_radius_omissions=sum(r['cross_rejected_in_radius'] for r in ur if r['phase']==0),
        linux_in_radius_omissions=sum(r['cross_rejected_in_radius'] for r in lr if r['phase']==0),
        conclusion='Lower-index neighbor pairs rejected by pointer-address order are never visited in the opposite direction. Diagnostic only; no algorithm fix or correctness override applied.',
        completed_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(OUTPUT,state)
    print(json.dumps({k:state[k] for k in ['status','user_original_exact','linux_original_exact','first_observed_pair_count_divergence','user_in_radius_omissions','linux_in_radius_omissions']}),flush=True)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=json.loads(OUTPUT.read_text()) if OUTPUT.exists() else {}
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),diagnostic_only=True,formal_eligible=False)
        save(OUTPUT,state)
        raise
