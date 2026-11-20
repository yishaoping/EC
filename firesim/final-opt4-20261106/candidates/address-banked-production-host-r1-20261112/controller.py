#!/usr/bin/python3
"""Complete AddressStats production boundary and actual host token validation.

No CAD in this attempt: no estimate can substitute for the owned paired maps.
"""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
P = D/'build-logs/Opt4-address-banked-complete-module-r1-20261112'
FS = W/'C4/chipyard/sims/firesim/sim'
spec = importlib.util.spec_from_file_location('immutable_r6_tools',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m = importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.C,m.O,m.CPUS = C,O,{212,213}
from opt4_unattended_common import identity, now, read, save, sha
from prepare import prepare


def ports(path, top):
    head = re.search(r'\bmodule '+top+r'\s*\((.*?)\);',path.read_text(),re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)


def testbench(candidate):
    reference = P/'Reference-Proof/BankedProofReference.v'
    assert reference.is_file(), 'Existing owner must finish reference elaboration'
    ref_ports = ports(reference,'BankedProofReference')
    assert ref_ports == ports(candidate,'ProductionProofCandidate')
    assert sum(d=='output' for d,w,n in ref_ports) == 5684
    prior = D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v'
    text = prior.read_text().replace('PackedProofReference','BankedProofReference').replace('PackedProofCandidate','ProductionProofCandidate')
    def target(match):
        metric,slot,g = match.groups();slot=int(slot)
        return f'b.bucketBanks_{slot//16}.{metric}_{slot%16}_{g}'
    text,n = re.subn(r'\bb\.(bucket(?:Store|FirstStore|LoadFirst|StoreFirst|StrictWriteRead))_(\d+)_(\d+)',target,text)
    assert n == 5122
    text = text.replace('PACKED_MODULE_MISMATCH','PRODUCTION_MODULE_MISMATCH').replace('PACKED_COMPLETE_MODULE_PARITY_PASS','PRODUCTION_COMPLETE_MODULE_PARITY_PASS')
    # Export exact pre-edge reference public tokens from existing finite
    # stimuli. Stop export before the deliberate internal invalid-state seed
    # at3003, which cannot be reproduced through a production public input.
    inputs = [n for d,w,n in ref_ports if d=='input' and n!='clock']
    outputs = [n for d,w,n in ref_ports if d=='output' and not n.startswith('io_debug')]
    assert len(outputs)==52
    trace = O/'reference-public-tokens.txt'
    fmt = ' '.join('%h' for _ in inputs+outputs)+'\\n'
    export = f'if(i<3003)$fwrite(trace_fd,"{fmt}",'+','.join(inputs+['a_'+n for n in outputs])+');'
    assert text.count('#1; compare; @(posedge clock);#1;compare;') == 1
    text = text.replace('#1; compare; @(posedge clock);#1;compare;', '#1; compare; '+export+' @(posedge clock);#1;compare;')
    text = text.replace('integer i,phase,seq;', 'integer trace_fd;\ninteger i,phase,seq;',1)
    text = text.replace('initial begin\ni=-1;', f'initial begin\ntrace_fd=$fopen("{trace}","w");\ni=-1;',1)
    m.exact(O/'tb.v',text)
    m.exact(O/'trace-ports.h','static const char *input_ports[] = {'+', '.join(json.dumps(n) for n in inputs)+'};\n'+
        'static const char *output_ports[] = {'+', '.join(json.dumps(n) for n in outputs)+'};\n')
    save(O/'testbench-binding.json',dict(reference_RTL_sha256=sha(reference),candidate_RTL_sha256=sha(candidate),
        source_testbench_sha256=sha(prior),testbench_sha256=sha(O/'tb.v'),inputs=inputs,outputs=outputs,
        target_cycles=6144,full_state_outputs=5684,public_host_trace_tokens=3003,
        no_host_claim_for_unreproducible_internal_seed=True))
    return reference,trace


def simulate(host,name,trace):
    sim = host/'simulation.sv'
    listing = host/'firrtl_black_box_resource_files.f'
    sim.write_text((host/'FireSim-generated.sv').read_text()+''.join(Path(p).read_text() for p in listing.read_text().splitlines() if p.strip()))
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(O)+' -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    m.stage('compile-host-'+name,['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2','verilator',
        'PLATFORM=xilinx_alveo','DRIVER_NAME=CompleteAddressStats','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(sim),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestComplete.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],[host/'VCompleteAddressStats'],env=env)
    args=[host/'VCompleteAddressStats','+trace='+str(trace),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name,args,marker='COMPLETE_ADDRESS_HOST_TOKEN_PASS',env=env,timeout=3600)
    m.stage('token-negative-'+name,args+['+negative'],negative=True,
        marker='COMPLETE_ADDRESS_HOST_MISMATCH cycle=100 port=io_statsValid',env=env,timeout=600)
    line=next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines() if l.startswith('COMPLETE_ADDRESS_HOST_TOKEN_PASS '))
    result=json.loads(line.split(' ',1)[1]);assert result['checked_outputs']==3000*52
    return result


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'adopt live attempt'
    os.sched_setaffinity(0,m.CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    binding=prepare()
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    m.ST.update(schema='ec-complete-banked-production-host/1',**identity(),started_utc=now(),
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source_binding_sha256=sha(C/'source-binding.json'),cpus=sorted(m.CPUS),
        geometry=binding['geometry'],fpga_access=False,whole_synthesis=False,no_CAD=True,
        production_admission=False,full_system_fit=False,
        scope='Complete target cycle/invalid-state comparison plus actual plain/threaded complete-module GoldenGate feedback/token test. No area/FIT claim.')
    m.update('ADMITTING_PRODUCTION_BOUNDARY_AND_COMPLETE_HOST_VALIDATION')
    save(O/'admission.json',m.admission())
    pinned=[C/'prepare.py',C/'controller.py',C/'Emit.scala',C/'TestComplete.cc',C/'source-binding.json']
    pinned += [Path(p) for p in binding['generated']]
    pins={str(p):sha(p) for p in pinned}
    save(O/'inputs.json',dict(files=pins,source_binding_sha256=sha(C/'source-binding.json')))
    java=[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2']
    basecp=':'.join(cfg['classpath'])
    tokens={}
    for mode in ['Proof','Module']:
        classes=O/('classes-'+mode);classes.mkdir()
        sources=[C/n for n in ['AddressBucketUpdate.scala','SourceProjected.scala','BucketBank'+mode+'.scala','Candidate'+mode+'.scala','Emit.scala']]
        m.stage('scala-compile-'+mode,java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
            '-classpath',basecp,'-Xplugin:'+cfg['plugin'],'-d',classes,*sources],
            [classes/'opt4bankedproduction/CompleteHost.class'])
        cp=str(classes)+':'+basecp
        out=O/(mode+'-target');out.mkdir()
        rtl=out/('Production'+mode+'Candidate.v')
        m.stage('elaborate-'+mode,java+['-cp',cp,'opt4bankedproduction.Emit',mode,out],[rtl])
        if mode=='Proof':
            reference,trace=testbench(rtl)
            exe=O/'obj/Vtb'
            m.stage('compile-full-target-parity',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
                '--Mdir',O/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
                '--x-initial','0','--x-assign','0','-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",
                '-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',reference,rtl,O/'tb.v'],[exe])
            m.stage('full-target-parity',[exe],marker='PRODUCTION_COMPLETE_MODULE_PARITY_PASS cycles=6144')
            # Preserve the positive trace before the negative executable
            # opens its own trace file, then use only the positive capture.
            positive=O/'positive-reference-public-tokens.txt'
            os.link(trace,positive)
            trace.rename(O/'reference-public-tokens-before-negative.txt')
            m.stage('full-target-negative',[exe,'+EC_MUTATE'],negative=True,
                marker='PRODUCTION_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000')
            trace=positive
            m.update('PASS_FULL_TARGET_FINITE_PARITY_HOST_TRANSFORM_NEXT',finite_parity=True,
                monitor_outputs=5684,target_cycles=6144,host_trace_sha256=sha(trace),full_formal=False)
        else:
            ref=D/'build-logs/Opt4-address-packed-full-module-r1-20261112/Reference-Module/FPGATop.v'
            assert ports(ref,'FPGATop')==ports(rtl,'ProductionModuleCandidate')
            target=O/'Host-target';target.mkdir()
            m.stage('elaborate-host',java+['-cp',cp,'freechips.rocketchip.system.Generator',
                '--target-dir',target,'--name','CompleteAddressStats','--top-module','opt4bankedproduction.CompleteHost',
                '--configs','firesim.midasexamples.NoConfig'],[target/'CompleteAddressStats.fir',target/'CompleteAddressStats.anno.json'])
            selected=[a for a in read(target/'CompleteAddressStats.anno.json') if a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
            assert len(selected)==16
            for name,config in [('Threaded','ThreadedConfig'),('Plain','PlainConfig')]:
                host=O/name;host.mkdir()
                m.stage('goldengate-'+name,java+['-cp',cp,'midas.stage.GoldenGateMain',
                    '-i',target/'CompleteAddressStats.fir','-td',host,'-faf',target/'CompleteAddressStats.anno.json',
                    '-ggcp','opt4bankedproduction','-ggcs',config,'--output-filename-base','FireSim-generated'],
                    [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
                fir=(host/'post-gen-sram-models.fir').read_text()
                assert ('module BucketBank_threaded :' in fir)==(name=='Threaded')
                save(O/(name+'-threading-audit.json'),dict(selected_count=16,
                    host_RTL_sha256=sha(host/'FireSim-generated.sv'),proof_ports_absent=True,
                    transformed_bank_type='BucketBank_threaded' if name=='Threaded' else 'BucketBank'))
                tokens[name]=simulate(host,name,trace)
                save(O/'token-progress.json',tokens)
    assert tokens['Plain']['digest']==tokens['Threaded']['digest']
    assert all(sha(p)==h for p,h in pins.items())
    m.update('PASS_COMPLETE_TARGET_FINITE_PARITY_AND_COMPLETE_HOST_TOKENS_NO_AREA_OR_FIT',
        tokens=tokens,host_tokens=3003,production_public_outputs=52,full_formal=False,
        whole_EC_equivalence=False,host_area_gain_unknown=True,ended_utc=now(),
        next='Consume existing r4/DSP/packed real maps. If material gain, measure exact production host with same harness; combine accepted DCache and build one actual completehost postopt.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
