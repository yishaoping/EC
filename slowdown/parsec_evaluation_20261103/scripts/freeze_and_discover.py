#!/usr/bin/env python3
"""Read-only identity/support inventory; never execute historical PARSEC scripts."""
import hashlib,json,re,subprocess,tarfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=ROOT/'slowdown/parsec_evaluation_20261103'
PARSEC=Path('/data1/gzh/EC/Software/PARSEC')
FINAL='1532923803d7451b0c7843e9abad1c90ef9eb9ed'
FIX='83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d'
def git(*args):return subprocess.check_output(['git',*args],cwd=ROOT,text=True).strip()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,indent=2)+'\n')
def main():
    for commit in [FIX,'5343ea33f7ccc1b4d140eef09e2d07ab775ae72c']:
        subprocess.run(['git','merge-base','--is-ancestor',commit,FINAL],cwd=ROOT,check=True)
    assert git('rev-parse','opt4-final-corrected-20261103^{}')==FINAL
    assert not git('diff',FINAL,'--','chipyard')
    seal=json.loads((ROOT/'slowdown/blackscholes_validation/evidence/capture_fix_build.manifest.json').read_text())['source']
    for rel,h in seal['hardware_sha256'].items():assert sha(ROOT/rel)==h,rel
    record={'canonical_final_commit':FINAL,'last_hardware_fix_commit':FIX,'tag':'opt4-final-corrected-20261103','branch':'opt4/final-eval-20261103','worktree':str(ROOT),'evaluation_head':git('rev-parse','HEAD'),'git_status':git('status','--porcelain=v1'),'parent_history':git('log','-8','--format=%H %P %s',FINAL).splitlines(),'hardware_tree':git('rev-parse',FINAL+':chipyard'),'hardware_source_sha256':seal['hardware_sha256'],'restored_resource_sha256':seal['restored_resource_sha256'],'checker_harts':[1,2,3,4],'clocks_MHz':{'boom':200,'checker_each':100,'system':200,'memory':200,'gc_bus':100},'core':{'ROB':42,'integer_PRF':128,'FP_PRF':128,'LQ':16,'SQ':16,'checker_decode_retire_width':1,'checker_fetch_bytes':8},'caches':{'boom_L1D':{'bytes':32768,'sets':256,'ways':2,'line':64,'MSHR':6},'checker_L1I':{'bytes':2048,'sets':32,'ways':1},'checker_L1D':{'bytes':4096,'sets':32,'ways':2},'L2':{'bytes':1048576,'sets':1024,'ways':16,'outerLatencyCycles':12},'SVB_entries':16},'build_config':'chipyard.v1Config,assertions,1simulator_thread,DRAMSim2,seed1,no waveform,no verbose','tool_evidence':str(ROOT/'slowdown/blackscholes_validation/evidence/tool_version_audit.json'),'reused_builds':{'correction':'overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6','check':'blackscholes_validation/build/matched_check_v5048'},'compiler':{'target':'GCC12.2.0,rv64imafd/lp64d,-O2,no-fastmath,newlib','host_model':'Clang16.0.6,-O3 plus generated-Os','verilator':'5.048'},'isolation':'No writes to main/FPGA or canonical check source'}
    dump(OUT/'reproducibility_manifest.json',record)
    names=['blackscholes','bodytrack','canneal','dedup','facesim','ferret','fluidanimate','freqmine','raytrace','streamcluster','swaptions','vips','x264'];rows=[]
    for name in names:
        paths=list((PARSEC/'pkgs').glob('*/'+name));p=paths[0]if paths else None
        row={'benchmark':name,'source':str(p),'installed_binaries':[],'inputs':{},'verilator_baremetal':'verified_test4'if name=='blackscholes'else 'UNPROVEN','ROI':'shared baremetal harness available'if name=='blackscholes'else 'Linux PARSEC hooks only; adaptation required','native':'PENDING_UNPROTECTED_MODE','check':'PASS_test4'if name=='blackscholes'else 'NOT_RUN','correction':'PASS_test4'if name=='blackscholes'else 'NOT_RUN'}
        if p:
            for b in(p/'inst').glob('*/bin/'+('rtview'if name=='raytrace'else name)):
                row['installed_binaries'].append({'path':str(b),'file':subprocess.check_output(['file',str(b)],text=True).strip(),'sha256':sha(b)})
            for size in ['test','simdev','simsmall','simmedium']:
                q=p/'parsec'/(size+'.runconf')
                if q.exists():
                    txt=q.read_text();m=re.search(r'^run_args="(.*)"',txt,re.M);row['inputs'][size]=m[1]if m else None
            row['constraint']='Installed binaries require Linux syscalls/filesystem and different ROI hooks; no booted Verilator Linux/checker image is established. Do not treat installed RISC-V as Verilator support.'
        rows.append(row)
    dump(OUT/'support_inventory.json',rows)
    md=['# PARSEC support matrix (discovery, before pilot)','','Installed Linux binaries are build artifacts, not proof of execution under the frozen Verilator configuration. Existing FireSim scripts contain absolute paths and destructive image operations; none are executed.','','| Benchmark | Builds/artifact | Runs | ROI identifiable | Native | Check | Correction |','|---|---|---|---|---|---|---|']
    for r in rows:md.append('|'+r['benchmark']+'|'+('RISC-V Linux ELF exists'if r['installed_binaries']else 'source only')+'|'+r['verilator_baremetal']+'|'+r['ROI']+'|'+r['native']+'|'+r['check']+'|'+r['correction']+'|')
    md+=['','Pilot candidates: blackscholes (floating-point compute), streamcluster (distance calculations/cache/load-store), canneal (irregular graph/control). Start from official sources with narrow baremetal I/O adaptations. simsmall feasibility is measured before selecting a smaller explicit project-equivalent input. No synthetic replacement kernels.','']
    (OUT/'SUPPORT_MATRIX.md').write_text('\n'.join(md));print('Final corrected source identity and 13-workload support inventory recorded')
if __name__=='__main__':main()
