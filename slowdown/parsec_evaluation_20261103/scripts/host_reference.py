#!/usr/bin/env python3
"""Independent host execution of the same official serial source + I/O adapter.
Host cycles/timing are never architectural results. Integer canneal cost is exact;
floating-point outputs may vary between host and target libm implementations.
"""
import argparse,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
def main():
    p=argparse.ArgumentParser();p.add_argument('workload');a=p.parse_args();d=OUT/'build'/a.workload;s=d/'source'
    m=json.loads((d/'build.manifest.json').read_text());app=m['benchmark'];cpp=app!='blackscholes'
    units=[s/('adapter.cpp'if cpp else'adapter.c')]
    if app=='canneal':units += [s/(n+'.cpp') for n in ['annealer_thread','rng','netlist','netlist_elem']]
    driver=d/('host_main.cpp'if cpp else'host_main.c')
    driver.write_text(('extern "C" {\n'if cpp else'')+'void workload_prepare(void);void workload_run(void);int workload_verify(void);'+('}\n'if cpp else'\n')+'int main(void){workload_prepare();workload_run();return !workload_verify();}\n')
    cmd=['/usr/bin/g++'if cpp else'/usr/bin/gcc','-O2','-ffunction-sections','-fdata-sections','-Wl,--gc-sections',*map(str,units),str(driver),'-lm','-o',str(d/'host_reference')]
    r=subprocess.run(cmd,capture_output=True,text=True);(d/'host_build.log').write_text(r.stdout+r.stderr);r.check_returncode()
    r=subprocess.run([str(d/'host_reference')],capture_output=True,text=True,timeout=60)
    (d/'host_reference.json').write_text(json.dumps(dict(command=cmd,exit_status=r.returncode,stdout=r.stdout,stderr=r.stderr,scope='Host correctness reference only; not performance evidence'),indent=2)+'\n');print(r.stdout);r.check_returncode()
if __name__=='__main__':main()
