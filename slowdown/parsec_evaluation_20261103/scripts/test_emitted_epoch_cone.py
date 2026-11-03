#!/usr/bin/env python3
"""Exercise exact emitted controller equations with explicit datapath cut inputs.

This is a controller-cone test, not a full DCache or architectural recovery test.
No control equation is rewritten in the test: wire RHSs and register next-state
assignments are extracted from the candidate's emitted BoomNonBlockingDCache.sv.
"""
import argparse,hashlib,json,os,re,subprocess,uuid
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('emitted_dcache',type=Path);a=p.parse_args();source=a.emitted_dcache.read_text()
    names=['svbEpochBoundary','svbHeldWriteNeedsLease','svbFlush','debug_l1_cross_package_blocked','svbCaptureDiscard','s2_write_grant']
    definitions={}
    for name in names:
        match=re.search(r'^  wire\s+'+name+r' = ([^;]+);',source,re.M);assert match,name
        definitions[name]=match[1]
    states={}
    for name in ['svbFlushPending','svbResetPending']:
        assignments=re.findall(r'^\s*'+name+r' <= ([^;]+);',source,re.M);assert len(assignments)==2 and assignments[0]=="1'h0",(name,assignments)
        states[name]=assignments[1]
    formula=' '.join([*definitions.values(),*states.values()]);formula=re.sub(r"\d+'[bdho][0-9a-fA-F_xz]+",'',formula)
    leaves=sorted(set(re.findall(r'\b[A-Za-z_]\w*\b',formula))-set(names)-set(states))
    d=OUT/'build'/('emitted_epoch_cone_'+uuid.uuid4().hex[:8]);d.mkdir()
    ports=['input clock','input reset'];aliases=[];cut_names={}
    for i,leaf in enumerate(leaves):
        match=re.search(r'^\s+(?:input|wire|reg)\s+(\[[^\]\n]+\])?\s*'+re.escape(leaf)+r'\s*(?:=|;|,)',source,re.M)
        if match:width=match[1]or''
        else:
            location=re.search(r'^\s+'+re.escape(leaf)+r'\s*[,)]',source,re.M);assert location,leaf
            declarations=list(re.finditer(r'^\s+(input|output)\s+(\[[^\]\n]+\])?',source[:location.start()],re.M));assert declarations and declarations[-1][1]=='input',leaf
            width=declarations[-1][2]or''
        cut_names[leaf]='cut'+str(i)
        ports.append('input '+width+' '+cut_names[leaf])
        aliases.append('wire '+width+' '+leaf+' = '+cut_names[leaf]+';')
    ports+=['output '+('reg' if n in states else 'wire')+' '+n for n in [*names,*states]]
    rtl='module EpochCone('+',\n'.join(ports)+');\n'
    rtl+='\n'.join(aliases)+'\n'
    rtl+='\n'.join('assign '+n+' = '+rhs+';'for n,rhs in definitions.items())
    rtl+='\nalways @(posedge clock) begin\nif(reset) begin\n'+''.join(n+" <= 1'h0;\n"for n in states)+'end else begin\n'+''.join(n+' <= '+rhs+';\n'for n,rhs in states.items())+'end\nend\nendmodule\n'
    sv=d/'EpochCone.sv';sv.write_text(rtl)
    cpp=d/'driver.cpp';driver=(OUT/'scripts/emitted_epoch_cone.cpp').read_text();driver=driver.replace('/* ZERO CUT INPUTS */','\n'.join('d.'+name+'=0;'for name in leaves));driver=re.sub(r'\bd\.(\w+)',lambda m:'d.'+cut_names.get(m[1],m[1]),driver);cpp.write_text(driver)
    tool='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    cmd=[tool,'--cc','--exe','--build','-j','2','--top-module','EpochCone','--Mdir',str(d),'-Wno-fatal',str(sv),str(cpp)]
    env=dict(os.environ,PATH='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin:/usr/bin:/bin')
    with(d/'build.log').open('xb')as f:subprocess.run(cmd,cwd=ROOT,stdout=f,stderr=subprocess.STDOUT,env=env,check=True)
    run=subprocess.run([str(d/'VEpochCone')],capture_output=True,text=True,env=env);(d/'stdout.log').write_text(run.stdout);(d/'stderr.log').write_text(run.stderr)
    dest=OUT/'logs'/('epoch_cone_'+uuid.uuid4().hex[:8]+'.json');dest.write_text(json.dumps({'status':'PASS'if run.returncode==0 else'FAIL','command':cmd,'emitted_source':str(a.emitted_dcache),'emitted_source_sha256':sha(a.emitted_dcache),'generated_test_rtl_sha256':sha(sv),'driver_sha256':sha(cpp),'wire_equations':definitions,'register_next_state':states,'cut_inputs':leaves,'stdout':run.stdout,'stderr':run.stderr,'scope':'Exact emitted Boolean controller cone; datapath identity, actual array effect, LSU/MSHR retry delivery and architectural rollback are not simulated here.'},indent=2)+'\n');print(run.stdout);print(dest);run.check_returncode()
if __name__=='__main__':main()
