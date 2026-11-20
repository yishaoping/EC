#!/usr/bin/python3
"""Original mixed-host simulator, bound to this immutable continuation."""
from pathlib import Path
import json
import os
C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
FS = W/'C4/chipyard/sims/firesim/sim'
O = None
m = None

def simulate(host,name,trace):
    listing=host/'firrtl_black_box_resource_files.f'
    sim=host/'simulation.sv'
    m.exact(sim,(host/'FireSim-generated.sv').read_text()+''.join(Path(p).read_text() for p in listing.read_text().splitlines() if p.strip()))
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(O)+' -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    exe=host/'VMixedStats'
    m.stage('compile-host-'+name,['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2','verilator',
        'PLATFORM=xilinx_alveo','DRIVER_NAME=MixedStats','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(sim),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestMixed.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],[exe],env=env)
    args=[exe,'+trace='+str(trace),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name,args,marker='MIXED_STATS_HOST_TOKEN_PASS',env=env,timeout=3600)
    m.stage('token-negative-'+name,args+['+negative'],negative=True,
        marker='MIXED_STATS_HOST_MISMATCH cycle=100 port=io_address_statsValid',env=env,timeout=600)
    s=next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines() if l.startswith('MIXED_STATS_HOST_TOKEN_PASS '))
    r=json.loads(s.split(' ',1)[1]);assert r['target_tokens']==3003 and r['checked_outputs']==3000*73
    return r

