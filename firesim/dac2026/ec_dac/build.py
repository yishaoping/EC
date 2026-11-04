from __future__ import annotations
import os
from pathlib import Path
import re
import shutil
import subprocess
import time
from .common import ROOT, KIT, DATA, read_json, atomic_json, require, filehash
from .audit import source_identity

def hardware_build(path, execute=False):
    spec=read_json(path)
    require(spec.get("ready") is True,"hardware recipe is not ready: "+spec.get("reason","unspecified"))
    require(spec["kind"] in ("target-rtl","firesim-verilog","driver","bitstream"),"not a compile/synthesis task")
    require(spec.get("no_device_access") is True and spec.get("source_reviewed") is True,"compile/synthesis recipe effects unreviewed")
    require(spec["source_id"]==source_identity()["id"],"source changed since recipe audit")
    require(1<=spec["jobs"]<=4 and 1<=spec["jvm_gib"]<=16,"resource limits exceeded")
    cwd=Path(spec["cwd"]).resolve()
    require(cwd.is_relative_to((KIT/"work").resolve()),"hardware builds must run in an isolated FireSim work copy")
    argv=spec["argv"]
    require(argv and all(isinstance(a,str) for a in argv),"missing argv")
    joined=" ".join(argv)
    require(not re.search(r"infrasetup|enumeratefpgas|runworkload|run-binary|rmmod|modprobe|program_hw|open_hw|reset|rescan|unbind",joined,re.I),"device/simulation operation denied")
    require(Path(argv[0]).name in ("make","sbt","java","vivado"),"unsupported build executable")
    for argument in argv:
        if re.fullmatch(r"-j[0-9]+",argument):
            require(int(argument[2:])<=spec["jobs"],"argv bypasses concurrency limit")
    for p,sha in spec["reviewed_scripts"].items():
        require(filehash(p)==sha,"reviewed build script changed: "+p)
    require(bool(spec["reviewed_scripts"]),"no reviewed build scripts")
    require(bool(spec.get("expected_outputs")),"build output inventory required")
    if not execute:
        return {"dry_run":True,"argv":argv,"cwd":str(cwd),"kind":spec["kind"]}
    require(shutil.disk_usage(ROOT).free>=80*2**30,"need >=80 GiB free disk")
    require(os.getloadavg()[0]<=32,"shared-server load >32; compilation deferred")
    run=DATA/"build-logs"/("hardware-"+str(time.time_ns()));run.mkdir(parents=True)
    env=os.environ.copy()
    env.update({"MAKEFLAGS":"-j"+str(spec["jobs"]),"OMP_NUM_THREADS":str(spec["jobs"]),
                "JAVA_TOOL_OPTIONS":f'-Xmx{spec["jvm_gib"]}G -XX:ActiveProcessorCount={spec["jobs"]} -Dsbt.supershell=false'})
    with open(run/"build.log","xb") as f:
        p=subprocess.run(["nice","-n","10"]+argv,cwd=cwd,env=env,stdout=f,stderr=subprocess.STDOUT)
    result={"spec":spec,"returncode":p.returncode,"source_id":spec["source_id"],"outputs":{}}
    if p.returncode==0:
        for out in spec["expected_outputs"]:
            require(Path(out).is_file() and Path(out).stat().st_size>0,"expected build output missing/empty: "+out)
            result["outputs"][out]=filehash(out)
    atomic_json(run/"build.json",result)
    require(p.returncode==0,"hardware build failed; inspect "+str(run))
    return result
