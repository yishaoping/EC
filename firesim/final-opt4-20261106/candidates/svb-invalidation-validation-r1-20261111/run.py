#!/usr/bin/python3
from pathlib import Path
import sys,subprocess,json,os
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import *
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-svb-invalidation-validation-r1-20261111';S=D/'Opt4-svb-invalidation-validation-r1-state.json'
O.mkdir(exist_ok=True);P=D/'build-logs/Opt4-fit-svb-tree-r5-20261111/svb/SVBModuleHarness.v';st=dict(**identity(),status='COMPILING_REAL_RTL_SIMULATION',hardware_commit='f2d2ca3ea0b12c918f2ccd2d1131be2709960470',source_id='f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc',rtl=str(P),rtl_sha256=sha(P),fpga_execution=False,architectural_restart_validated=False);save(S,st)
try:
 argv=['/usr/local/bin/verilator','--cc','--exe','--build','--top-module','SVBModuleHarness','--Mdir',str(O/'obj'),'-j','8','-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',str(P),str(C/'test.cpp')]
 with (O/'compile.log').open('w') as f:r=subprocess.run(argv,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'CCACHE_DISABLE':'1'},timeout=1200)
 assert r.returncode==0,'compile failed'
 st.update(status='RUNNING_REAL_RTL_SIMULATION',updated_utc=now());save(S,st)
 with (O/'run.log').open('w') as f:r=subprocess.run([str(O/'obj/VSVBModuleHarness')],stdout=f,stderr=subprocess.STDOUT,timeout=60)
 assert r.returncode==0 and 'SVB_INVALIDATION_OWNER_DATA_LIFETIME_PASS' in (O/'run.log').read_text(),'RTL validation failed'
 st.update(status='PASS_REAL_RTL_SVB_INVALIDATION_OWNER_AND_DATA_NOT_ARCHITECTURAL_ROLLBACK',run_log_sha256=sha(O/'run.log'),completed_utc=now(),limitations='Stimulates existing SVB invalidate boundary; does not execute real checker comparison, CDC FAIL, architectural restore or instruction restart. Not a formal/FPGA sample.');save(O/'result.json',st);save(S,st)
except Exception as e:st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st);raise
