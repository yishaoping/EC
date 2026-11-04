#!/usr/bin/env python3
"""Inspect independent install, dependencies and CLI imports; never operate FPGA."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from ec_dac.common import ROOT, FIRESIM, MANAGER_ENV, atomic_json, filehash

PIN="b473147af03edc854a5bc2a95d1bc404c8711b2a"
CHIPYARD_PIN="336f225143590f9060ebe7101e96f235f96db985"

def command(argv, env=None):
    try:
        r=subprocess.run([str(v) for v in argv],capture_output=True,text=True,timeout=90,env=env)
        return {"argv":[str(v) for v in argv],"returncode":r.returncode,"stdout":r.stdout,"stderr":r.stderr}
    except (OSError,subprocess.TimeoutExpired) as exc:
        return {"argv":[str(v) for v in argv],"error":str(exc),"returncode":-1}

def git(path, *args):
    return command(["git","--no-optional-locks","-C",path,*args])

def packages():
    # An environment cloned from another prefix need not contain conda itself.
    # Read the installed package records directly rather than invoking old conda.
    records=[]
    for path in sorted((MANAGER_ENV/"conda-meta").glob("*.json")):
        record=json.loads(path.read_text())
        records.append({k:record.get(k) for k in ("name","version","build","channel","url","sha256","md5")})
    return {"returncode":0 if records else -1,"method":"independent conda-meta records (no dependency solver invoked)","count":len(records),"records":records}

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument("--out",required=True);a=p.parse_args()
    out=Path(a.out);out.mkdir(parents=True,exist_ok=False)
    target=FIRESIM/"target-design/chipyard"
    env=os.environ.copy()
    env.update(FIRESIM_ROOT=str(FIRESIM),FIRESIM_STANDALONE="1",FIRESIM_ENV_SOURCED="1",
               RISCV=str(MANAGER_ENV/"riscv-tools"),PATH=f'{MANAGER_ENV}/bin:{MANAGER_ENV}/riscv-tools/bin:{FIRESIM}/deploy:'+env["PATH"])
    fs_head=git(FIRESIM,"rev-parse","HEAD");cy_head=git(target,"rev-parse","HEAD")
    checks={"firesim_head":fs_head,"chipyard_head":cy_head,
            "firesim_tracked_changes":git(FIRESIM,"status","--short","--untracked-files=no"),
            "chipyard_tracked_changes":git(target,"status","--short","--untracked-files=no"),
            "firesim_submodules":git(FIRESIM,"submodule","status"),
            "chipyard_submodules":git(target,"submodule","status"),
            "python":command([MANAGER_ENV/"bin/python3","--version"],env),
            "riscv_gcc":command([MANAGER_ENV/"riscv-tools/bin/riscv64-unknown-linux-gnu-gcc","--version"],env),
            "manager_help":command([FIRESIM/"deploy/firesim","--help"],env),
            "packages":packages()}
    passed=(fs_head.get("stdout","").strip()==PIN and cy_head.get("stdout","").strip()==CHIPYARD_PIN and
            all(checks[k]["returncode"]==0 for k in ("python","riscv_gcc","manager_help","packages")))
    result={"status":"PIN_AND_MANAGER_CLI_VERIFIED" if passed else "INSTALL_CHECK_FAILED",
            "firesim_root":str(FIRESIM),"environment":str(MANAGER_ENV),
            "source_environment_used_for_dependency_clone":str(ROOT/"chipyard/.conda-env"),
            "bundled_firesim_used_for_runtime":False,"checks":checks,
            "limits":"Not an EC port, elaboration, bridge, image, driver, bitstream or simulation validation. Uninitialized optional and recursive submodules are listed; build dependency closure is not claimed.",
            "evidence_hashes":{str(v):filehash(v) for v in [FIRESIM/".gitmodules",FIRESIM/"CHANGELOG.md",target/"build.sbt"]}}
    atomic_json(out/"installation.json",result,replace=False)
    print({"status":result["status"],"report":str(out),"firesim":str(FIRESIM),"environment":str(MANAGER_ENV)})
    return 0 if passed else 2

if __name__=="__main__":sys.exit(main())
