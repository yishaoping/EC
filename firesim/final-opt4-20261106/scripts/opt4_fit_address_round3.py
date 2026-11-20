#!/usr/bin/env python3
"""Independent address-statistics candidate: proofs, RTL comparison and mapping.

No changes to the current whole-DUT build, its sources, scheduler or FPGA.
"""
from pathlib import Path
import datetime, fcntl, json, math, os, shutil, signal, subprocess, sys, time
from board_batch import W,D,save,sha
from job_service import proc,boot
from prepare_opt4_fit_modules import JAVA,CACHE,CPFILE
from summarize_opt4_fit import resources

F=W/'Opt4-fit-address-round3-20261110'
COMMIT='aca893e0aa3f7e23e16067ab40713afea41558e8'
# Resolve only the exact commit recorded once in the candidate binding.
O=D/'build-logs/Opt4-fit-address-round3-20261110'
S=D/'Opt4-fit-address-round3-state.json'
REL='chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()

def emit_tree(path,name,n,after):
    oldmax=[64,16,8,1];newmax=[8,3,2,1];widths=[7,5,4,1]
    lines=[f'module {name}(input [{n*sum(widths)-1}:0] terms, output [255:0] result);']
    outputs=[];offset=0
    for g,(om,nm,lw) in enumerate(zip(oldmax,newmax,widths)):
        nodes=[]
        for i in range(n):
            w=math.ceil(math.log2(nm+1)) if after else math.ceil(math.log2(n*om+1))
            leaf=math.ceil(math.log2(nm+1)) if after else lw
            ident=f'g{g}_leaf{i}';lines.append(f'wire [{w-1}:0] {ident} = terms[{offset+leaf-1}:{offset}];')
            nodes.append((ident,nm,w));offset+=lw
        level=0
        while len(nodes)>1:
            out=[]
            for i in range(0,len(nodes),2):
                if i+1==len(nodes):out.append(nodes[i]);continue
                a,b=nodes[i:i+2];bound=a[1]+b[1]
                w=math.ceil(math.log2(bound+1)) if after else math.ceil(math.log2(n*om+1))
                ident=f'g{g}_l{level}_{i//2}'
                lines.append(f'wire [{w-1}:0] {ident} = {a[0]} + {b[0]};');out.append((ident,bound,w))
            nodes=out;level+=1
        outputs.append(nodes[0][0])
    for g,ident in enumerate(outputs):lines.append(f'assign result[{g*64+63}:{g*64}]={ident};')
    lines.append('endmodule');path.write_text('\n'.join(lines)+'\n')

def emit_increment(path,name,kind,lanes=16):
    lines=[f'module {name}(input [{lanes*64-1}:0] state_in, input [{lanes*10-1}:0] delta, output [{lanes*65-1}:0] result);']
    for i in range(lanes):
        lines += [f'wire [63:0] a{i}=state_in[{i*64+63}:{i*64}];',f'wire [9:0] d{i}=delta[{i*10+9}:{i*10}];']
        if kind=='wide':lines.append(f'assign result[{i*65+64}:{i*65}]={{1\'b0,a{i}}}+d{i};')
        else:
            lines.append(f'wire [10:0] low{i}={{1\'b0,a{i}[9:0]}}+d{i};')
            if kind=='split':
                lines.append(f'wire [53:0] hi{i}=a{i}[63:10]+low{i}[10];')
                lines.append(f'assign result[{i*65+64}:{i*65}]={{(low{i}[10] && (&a{i}[63:10])),hi{i},low{i}[9:0]}};')
            elif kind=='prefix':
                for bit in range(10,64):
                    carry=f'low{i}[10]' if bit==10 else f'(low{i}[10] && (&a{i}[{bit-1}:10]))'
                    lines.append(f'assign result[{i*65+bit}] = a{i}[{bit}] ^ {carry};')
                lines.append(f'assign result[{i*65+9}:{i*65}]=low{i}[9:0];')
                lines.append(f'assign result[{i*65+64}]=low{i}[10] && (&a{i}[63:10]);')
            else:raise ValueError(kind)
    lines.append('endmodule');path.write_text('\n'.join(lines)+'\n')

def main():
    lock=(D/'.opt4-fit-address-round3.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    binding=json.loads((F/'candidate-binding.json').read_text());commit=binding['git_commit']
    assert commit==COMMIT and binding['parent_commit']=='8da24a269b98a0d6a8f57b030353a310812c4344'
    source=O/'PackageAddressStats.scala'
    content=subprocess.check_output(['git','show',commit+':'+REL],cwd=F)
    if source.exists():assert source.read_bytes()==content
    else:source.write_bytes(content)
    st=dict(schema='ec-opt4-fit-address-round3/1',status='STARTING',pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=boot(),started_utc=now(),
        fit_commit=commit,source_id=binding['source_id'],parent_commit=binding['parent_commit'],
        source_snapshot=str(source),source_sha256=sha(source),full_dut_synthesis=False,
        fpga_access=False,formal_admission=False,stages={},tests={},micro_maps={},
        update_kernel_scope='Independent equivalent combinational probes only; not installed in candidate unless measured beneficial and separately versioned')
    save(S,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8'}
    def run(label,argv,cwd,outputs=(),timeout=3600):
        receipt=cwd/(label+'-result.json')
        if receipt.exists():
            r=json.loads(receipt.read_text())
            if r.get('returncode')==0 and r.get('fit_commit')==commit:
                assert all(sha(p)==h for p,h in r['outputs'].items())
                st['stages'][label]=r;save(S,st);return Path(r['log'])
        attempt=len(list(cwd.glob(label+'-attempt-*.log')))+1;log=cwd/(label+f'-attempt-{attempt}.log')
        args=list(map(str,['nice','-n','15']+argv));start=time.monotonic()
        with log.open('ab',buffering=0) as f:
            p=subprocess.Popen(args,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            r=dict(fit_commit=commit,argv=args,log=str(log),started_utc=now(),returncode=None)
            st.update(status='RUNNING_'+label.upper(),active_step=label,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks'])
            st['stages'][label]=r;save(S,st)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now(),stage_wall_seconds=time.monotonic()-start);save(S,st);os.fsync(f.fileno())
                if p.poll() is None and (time.monotonic()-start>timeout or shutil.disk_usage(O).free<60*2**30):
                    os.killpg(p.pid,signal.SIGTERM)
                    try:p.wait(timeout=30)
                    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                    raise RuntimeError((label,'private job timeout/disk guard'))
        r.update(returncode=p.returncode,ended_utc=now(),wall_seconds=time.monotonic()-start)
        st.pop('child_pid',None);st.pop('child_start_ticks',None);save(S,st)
        assert p.returncode==0,(label,p.returncode,str(log))
        assert all(Path(p).is_file() for p in outputs)
        r['outputs']={str(p):sha(p) for p in outputs};save(receipt,r);st['stages'][label]=r;save(S,st);return log

    proofs=O/'proofs';proofs.mkdir(exist_ok=True)
    hit=proofs/'hit-bounds.v'
    lines=['module hit_bounds(input [5:0] offset,input [1:0] size,input [63:0] history_byte,input [15:0] history4,input [7:0] history8,output ok);',
        "wire [63:0] base=(size==0)?64'h1:(size==1)?64'h3:(size==2)?64'hf:64'hff;",
        'wire [63:0] touch=base<<offset;','wire [15:0] touch4;wire [7:0] touch8;']
    for i in range(16):lines.append(f'assign touch4[{i}]=|touch[{i*4+3}:{i*4}];')
    for i in range(8):lines.append(f'assign touch8[{i}]=|touch[{i*8+7}:{i*8}];')
    for name,w,h,t in [('b',64,'history_byte','touch'),('w4',16,'history4','touch4'),('w8',8,'history8','touch8')]:
        lines.append(f'wire [6:0] count_{name} = '+' + '.join(f"{{6'b0,({h}[{i}] & {t}[{i}])}}" for i in range(w))+';')
    lines+=['assign ok=(count_b<=8 && count_w4<=3 && count_w8<=2);','endmodule']
    hit.write_text('\n'.join(lines)+'\n')
    log=run('hit-bounds',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {hit}; prep -top hit_bounds; sat -verify -prove ok 1 -show-inputs -timeout 180'],proofs,[hit],300)
    assert 'SUCCESS' in log.read_text();st['tests']['touch_bounds']=dict(status='PASS_UNIVERSAL_96_INPUT_BITS',log=str(log),bounds=[8,3,2,1],covers_cross_line_and_all_size_encodings=True);save(S,st)
    for n in [8,80]:
        a=proofs/f'before{n}.v';b=proofs/f'after{n}.v';emit_tree(a,'Before'+str(n),n,False);emit_tree(b,'After'+str(n),n,True)
        width=n*17;terms=[];offset=0
        for bits,bound in zip([7,5,4,1],[8,3,2,1]):
            for i in range(n):
                terms.append(f'(terms[{offset+bits-1}:{offset}]<={bits}\'d{bound})');offset+=bits
        m=proofs/f'tree-proof{n}.v';m.write_text(f'module tree_proof(input [{width-1}:0] terms,output ok);wire [255:0] a,b;Before{n} x(terms,a);After{n} y(terms,b);wire valid='+ ' && '.join(terms)+';assign ok= !valid || a==b;endmodule\n')
        log=run('tree-proof'+str(n),['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {a} {b} {m}; prep -top tree_proof -flatten; sat -verify -prove ok 1 -timeout 240'],proofs,[a,b,m],300)
        assert 'SUCCESS' in log.read_text();st['tests']['tree'+str(n)]=dict(status='PASS_UNIVERSAL_BOUNDED_INPUTS',input_bits=width,validity='Each masked touch count <= universally proved per-granule bound',log=str(log));save(S,st)

    # Compile and elaborate the full-size candidate before the small probes;
    # immutable source snapshots leave every active whole-system input alone.
    cp=CPFILE.read_text().strip();classes=O/'classes';classes.mkdir(exist_ok=True)
    compiler=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar') for n in ['scala-compiler','scala-library','scala-reflect']]
    plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    emit=O/'EmitAddress3.scala';emit.write_text('package opt4fit\nobject EmitAddress3 extends App {(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(0)))}\n')
    run('compile',[JAVA,'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(map(str,compiler)),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+str(plugin),'-d',classes,source,emit],O,[emit])
    rtl=O/'PackageAddressStats.v'
    run('elaborate',[JAVA,'-Xmx20G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',str(classes)+':'+cp,'opt4fit.EmitAddress3',O],O,[rtl])
    st.update(rtl=str(rtl),rtl_sha256=sha(rtl));save(S,st)
    compare=O/'compare';compare.mkdir(exist_ok=True)
    for old,new in [(D/'build-logs/Opt4-fit-modules-20261110/verification/address-original.v',compare/'original.v'),
                    (D/'build-logs/Opt4-fit-modules-20261110/verification/address-tb.v',compare/'tb.v')]:
        if new.exists():assert new.read_bytes()==old.read_bytes()
        else:shutil.copy2(old,new)
    tool=shutil.which('verilator');assert tool
    st['verilator_version']=subprocess.check_output([tool,'--version'],text=True).strip();save(S,st)
    exe=compare/'obj/Vtb'
    run('compare-compile',[tool,'--binary','--timing','--top-module','tb','--Mdir',compare/'obj','-j','8',
        '--output-split','10000','--output-split-cfuncs','200','--x-initial','0','--x-assign','0','-Wno-fatal',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0',compare/'original.v',rtl,compare/'tb.v'],compare,[exe])
    log=run('compare',[exe],compare,[],1800)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    st['tests']['full_address']=dict(status='PASS_FULL_SIZE_6144_CYCLES_52_OUTPUTS_NOT_FULL_FORMAL',
        log=str(log),log_sha256=sha(log),baseline_rtl_sha256=sha(compare/'original.v'),candidate_rtl_sha256=sha(rtl),testbench_sha256=sha(compare/'tb.v'));save(S,st)

    def mapping(label,top,path,cwd):
        tcl=cwd/'map.tcl'
        tcl.write_text(f'''set_param general.maxThreads 8
read_verilog {{{path}}}
synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {{{cwd/'utilization.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 20 -file {{{cwd/'hierarchical.rpt'}}}
write_checkpoint -force {{{cwd/'module.dcp'}}}
puts "EC_ADDRESS_ROUND3_MAP_COMPLETE {label}"
exit 0
''')
        run(label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',cwd/'vivado.log','-source',tcl],cwd,[cwd/'utilization.rpt',cwd/'module.dcp'],86400)
        return dict(resources=resources(cwd/'utilization.rpt'),report=str(cwd/'utilization.rpt'),report_sha256=sha(cwd/'utilization.rpt'),scope='OOC probe only; not full-system capacity',rtl_sha256=sha(path),tcl_sha256=sha(tcl))
    # These two 80-term micro maps isolate the reduction contribution. They
    # never stand in for the full address module, much less the full DUT.
    for after,label,top in [(False,'tree-before','Before80'),(True,'tree-after','After80')]:
        cwd=O/label;cwd.mkdir(exist_ok=True);path=cwd/'tree.v';emit_tree(path,top,80,after)
        st['micro_maps'][label]=mapping(label,top,path,cwd);save(S,st)
    # Test three exact implementations of the 64-bit update + overflow. Only
    # measured improvements may enter a later independently committed source.
    for kind in ['wide','split','prefix']:
        cwd=O/('increment-'+kind);cwd.mkdir(exist_ok=True);path=cwd/'increment.v'
        emit_increment(path,'Increment',kind)
        proof=proofs/('increment-'+kind+'.v');emit_increment(proof,'Candidate',kind,1)
        ref=proofs/'increment-ref.v';emit_increment(ref,'Reference','wide',1)
        m=proofs/('increment-proof-'+kind+'.v');m.write_text('module update_proof(input [63:0] a,input [9:0] d,output ok);wire [64:0] x,y;Reference r(a,d,x);Candidate c(a,d,y);assign ok=x==y;endmodule\n')
        log=run('increment-proof-'+kind,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {ref} {proof} {m}; prep -top update_proof -flatten; sat -verify -prove ok 1 -timeout 120'],proofs,[proof,m],180)
        assert 'SUCCESS' in log.read_text()
        st['tests']['increment-'+kind]=dict(status='PASS_UNIVERSAL_74_INPUT_BITS',log=str(log));save(S,st)
        st['micro_maps']['increment-'+kind]=mapping('increment-'+kind,'Increment',path,cwd);save(S,st)
    cwd=O/'full-address-map';cwd.mkdir(exist_ok=True)
    st['full_address_map']=mapping('full-address-map','PackageAddressStats',rtl,cwd)
    st.update(status='VERIFIED_AND_MAPPED_MODULE_ONLY',ended_utc=now());save(S,st);save(O/'result.json',st)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if S.exists():
            s=json.loads(S.read_text());s.update(status='FAILED_WITH_EVIDENCE',error=str(e),ended_utc=now());save(S,s)
        raise
