#!/usr/bin/env python3
"""Actual reverse-direction two-clock Golden Gate tokens, no FPGA/CAD."""
import json
import os
from pathlib import Path
import subprocess
import sys
C=Path(__file__).resolve().parent;T=C.parent.parent;W=T.parent
R=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');O=Path(sys.argv[1]).resolve();H=O/'host'
def run(n,args,env,negative=False,marker=None,timeout=1800):
 with (H/(n+'.log')).open('xb') as f:p=subprocess.run(list(map(str,args)),cwd=H,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env,timeout=timeout)
 s=(H/(n+'.log')).read_text(errors='replace');assert (p.returncode==0)!=negative,(n,p.returncode)
 assert marker is None or marker in s,(n,'marker');return s
def main():
 os.sched_setaffinity(0,{250,251});os.nice(19)
 assert json.loads((O/'result.json').read_text())['status']=='PASS_RESULT_CDC_CYCLES_AND_ALL_STATE_EQUIVALENCE'
 H.mkdir(exist_ok=False);classes=H/'classes';classes.mkdir();target=H/'target';target.mkdir()
 env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD','JAVA_TOOL_OPTIONS']}
 cfg=json.loads((W/'candidates/common-composed-source-r2-20261113/config.json').read_text())
 base=R/'build-logs/Opt4-performance-only-fpga-r1-20261113/classes'
 cp=':'.join([str(O/'classes'),str(base),cfg['firechip'],*cfg['classpath']])
 java=[cfg['java'],'-Xmx8G','-Xss16M','-XX:ActiveProcessorCount=2']
 run('compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,C/'ResultHost.scala'],env)
 cp=str(classes)+':'+cp
 run('emit',java+['-cp',cp,'resultcdcprobe.EmitHost',target],env)
 generated=H/'generated';generated.mkdir()
 run('goldengate',java+['-cp',cp,'midas.stage.GoldenGateMain','-i',target/'QueuePairHost.fir','-td',generated,'-faf',target/'QueuePairHost.anno.json','-ggcp','resultcdcprobe','-ggcs','PlainConfig','--output-filename-base','FireSim-generated'],env)
 listing=generated/'firrtl_black_box_resource_files.f';simulation=generated/'simulation.sv'
 simulation.write_text((generated/'FireSim-generated.sv').read_text()+''.join(Path(p).read_text() for p in (listing.read_text().splitlines() if listing.exists() else []) if p.strip()))
 clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++';verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
 fs=W/'C4/chipyard/sims/firesim/sim';deps=R/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
 env.update(CCACHE_DISABLE='1',LD_LIBRARY_PATH='',OMP_NUM_THREADS='2',PATH=str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',CXX=clang,
  CXXFLAGS='-O1 -I'+str(deps/'headers')+' -I'+str(fs/'src/main/cc/midasexamples'),LDFLAGS='-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'))
 run('build', ['make','-C',fs/'midas/src/main/cc','-j2','verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=QueuePairHost','GEN_DIR='+str(generated),'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(simulation),
  'DRIVER='+str(fs/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'ResultHost.cc'),'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],env)
 args=[generated/'VQueuePairHost','+seed=8491167','+max-cycles=10000000']
 passing=run('tokens',args,env,marker='RESULT_CDC_HOST_TOKEN_PASS tokens=8192')
 run('negative',args+['+negative'],env,negative=True,marker='RESULT_CDC_HOST_MISMATCH token=100')
 (H/'result.json').write_text(json.dumps(dict(status='PASS_RESULT_CDC_ACTUAL_REVERSE_CLOCK_HOST_TOKENS',tokens=8192,receipt=[l for l in passing.splitlines() if 'RESULT_CDC_HOST_TOKEN_PASS' in l],checker_to_BOOM_clock_ratio='1:2',release_logic_modified=False,full_system_equivalence=False),indent=2)+'\n')
if __name__=='__main__':main()
