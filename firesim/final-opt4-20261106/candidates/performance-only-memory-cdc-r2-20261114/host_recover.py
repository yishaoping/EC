#!/usr/bin/env python3
# Resume exact successful Golden Gate output; absent blackbox listing means no extra resources.
import importlib.util, hashlib, json, os
from pathlib import Path
C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('memory_host',C/'host.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
W,R,O,FS=m.W,m.R,m.O,m.FS
H=O/'host-r2'
m.H=H
save,run=m.save,m.run

def main():
    os.sched_setaffinity(0,{246,247})
    H.mkdir(exist_ok=False)
    previous=O/'host-r1'
    assert json.loads((previous/'state.json').read_text())['error']=="FileNotFoundError(2, 'No such file or directory')"
    original=previous/'generated'
    assert (original/'FireSim-generated.sv').is_file()
    assert not (original/'firrtl_black_box_resource_files.f').exists()
    generated=H/'generated';generated.mkdir()
    for p in original.iterdir():
        if p.is_file(): (generated/p.name).symlink_to(p)
    simulation=generated/'simulation.sv'
    simulation.write_bytes((original/'FireSim-generated.sv').read_bytes())
    (H/'recovery-binding.json').write_text(json.dumps(dict(reused_rtl=str(original/'FireSim-generated.sv'),rtl_sha256=hashlib.sha256(simulation.read_bytes()).hexdigest(),cause='No extracted blackboxes, so no resource listing was emitted. Standard FireSim makefile supplies BUFGCE.v.',goldengate_repeated=False),indent=2)+'\n')
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=R/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    run('COMPILE_HOST',['make','-C',FS/'midas/src/main/cc','-j2','verilator','PLATFORM=xilinx_alveo',
        'DRIVER_NAME=QueuePairHost','GEN_DIR='+str(generated),'GEN_FILE_BASENAME=FireSim-generated',
        'DESIGN_V='+str(simulation),'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestQueue.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],env=env,timeout=7200)
    exe=generated/'VQueuePairHost'
    args=[exe,'+seed=8491167','+max-cycles=10000000']
    run('TOKENS',args,env=env,marker='LOCAL_CDC_HOST_TOKEN_PASS tokens=8192')
    run('NEGATIVE_CONTROL',args+['+negative'],env=env,negative=True,marker='LOCAL_CDC_HOST_MISMATCH token=100')
    save('PASS_TWO_CLOCK_GOLDENGATE_FINITE_TOKENS_AND_NEGATIVE_CONTROL',tokens=8192,capacity=256,payload_bits=305,
        scope='Both actual queue implementations in one generated host, exact public output token boundary; whole-system validation and routability remain unproved.')

if __name__=='__main__':
    try:main()
    except Exception as e:
        if H.is_dir():save('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
