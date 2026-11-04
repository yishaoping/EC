from __future__ import annotations
import os
from pathlib import Path
import re
import shutil
import subprocess
from .common import KIT, ROOT, DATA, MANAGER_ENV, atomic_json, filehash, require, name, read_json
from .audit import parsec_inventory

def parsec_copy(destination, execute=False):
    src = ROOT / "Software/PARSEC"
    dest = Path(destination).resolve()
    require(src.joinpath("bin/parsecmgmt").is_file(), "canonical PARSEC copy missing")
    require(dest.is_relative_to((KIT / "work").resolve()), "work copy must be inside firesim/dac2026/work")
    require(not dest.exists(), "work copy already exists; preserving previous files")
    argv = ["rsync","-a","--no-owner","--no-group","--exclude=.git","--exclude=.metals","--exclude=.Xil",
            str(src)+"/",str(dest)+"/"]
    if not execute:
        return {"argv":argv,"source":str(src),"destination":str(dest),"executed":False}
    require(shutil.disk_usage(KIT).free > 20*2**30, "need at least 20 GiB free for work copy")
    dest.mkdir(parents=True)
    subprocess.run(argv, check=True)
    rebased=[]
    external=[]
    for f in dest.rglob("*"):
        if not f.is_symlink():
            continue
        raw=str(f.readlink())
        for original_root in ("/home/wtl/parsec_gc",str(src)):
            if raw.startswith(original_root+"/"):
                replacement=str(dest/raw[len(original_root)+1:])
                f.unlink();f.symlink_to(replacement)
                rebased.append({"path":str(f.relative_to(dest)),"before":raw,"after":replacement})
                break
        if not f.resolve().is_relative_to(dest):
            if f.name in ("libstdc++.so","libstdc++.a"):
                compiler=MANAGER_ENV/"riscv-tools/bin/riscv64-unknown-linux-gnu-g++"
                result=subprocess.run([str(compiler),"-print-file-name="+f.name],capture_output=True,text=True,check=True)
                lib=Path(result.stdout.strip()).resolve()
                require(lib.is_file() and lib.is_relative_to(MANAGER_ENV),"cannot safely resolve copied C++ library link")
                f.unlink();f.symlink_to(lib)
                rebased.append({"path":str(f.relative_to(dest)),"before":raw,"after":str(lib),"read_only_toolchain_dependency":True})
            else:
                external.append({"path":str(f.relative_to(dest)),"target":raw})
    require(not external,"unresolved external symlinks; work tree is NOT safe to build: "+str(external[:10]))
    hooks = dest / "pkgs/libs/hooks/src/hooks.c"
    original = filehash(hooks)
    code = hooks.read_text()
    require(code.count("void __parsec_roi_begin() {") == 1 and code.count("void __parsec_roi_end() {") == 1,
            "unknown PARSEC hooks ABI")
    # BEGIN goes at the end of roi_begin; END goes first in roi_end. Original
    # console/timing code is kept outside the target ROI as much as possible.
    end_start = code.index("void __parsec_roi_end() {")
    begin_start = code.index("void __parsec_roi_begin() {")
    body = code[begin_start:end_start]
    close = body.rfind("}")
    require(close >= 0, "cannot locate hooks begin closing brace")
    body = body[:close] + "  ec_dac_roi_begin();\n" + body[close:]
    code = code[:begin_start] + body + code[end_start:]
    code = code.replace("void __parsec_roi_end() {", "void __parsec_roi_end() {\n  ec_dac_roi_end();",1)
    # Include implementation into hooks.c so old automake builds cannot omit it.
    code = '#include "dac_roi.c"\n' + code
    hooks.write_text(code)
    for n in ("dac_roi.h","dac_roi.c"):
        shutil.copy2(KIT / "measurement" / n,hooks.parent/n)
    # Replace the working copy's compiler config only. Never link the unrelated
    # /home/wtl/Voyager/.../main_none.o present in the reference config.
    gcc = dest / "config/gcc.bldconf"
    old_gcc = filehash(gcc)
    gcc.write_text('''#!/bin/bash
export CC_HOME="${RISCV:?set RISCV to the installed Linux cross-toolchain prefix}"
export BINUTIL_HOME="$CC_HOME"
export GNUTOOL_HOME=/usr
export BINARY_PREFIX=riscv64-unknown-linux-gnu-
export GNU_HOST_NAME="$(gcc -dumpmachine)"
export GNU_TARGET_NAME=riscv64-unknown-linux-gnu
export HOSTCC=gcc
export M4=m4
export MAKE=make
export CC="$CC_HOME/bin/${BINARY_PREFIX}gcc"
export CXX="$CC_HOME/bin/${BINARY_PREFIX}g++"
export CPP="$CC_HOME/bin/${BINARY_PREFIX}cpp"
export CXXCPP=""
export LD="$CC_HOME/bin/${BINARY_PREFIX}ld"
export AS="$CC_HOME/bin/${BINARY_PREFIX}as"
export AR="$CC_HOME/bin/${BINARY_PREFIX}ar"
export RANLIB="$CC_HOME/bin/${BINARY_PREFIX}ranlib"
export STRIP="$CC_HOME/bin/${BINARY_PREFIX}strip"
export CFLAGS="-O3 -march=rv64gc -mabi=lp64d"
export CXXFLAGS="$CFLAGS -fpermissive -fno-exceptions -std=c++17"
export CPPFLAGS=""
export CXXCPPFLAGS=""
export LDFLAGS="-static"
export LIBS="-lpthread -lm -latomic"
export EXTRA_LIBS=""
export PARMACS_MACRO_FILE=pthreads
export JAVA_HOME=/usr
export JAVAC=/usr/bin/javac
export CC_ver="$($CC --version | head -1)"
export CXX_ver="$($CXX --version | head -1)"
export LD_ver="$($LD --version | head -1)"
export JAVAC_ver=""
''')
    # Every dependency needs the chosen local .bldconf, even libtool/hooks.
    # Reuse the real package-specific hooks config; do not invent configure flags.
    for p in dest.glob("pkgs/*/*/parsec/gcc.bldconf"):
        target = p.with_name("gcc-dac.bldconf")
        require(not target.exists(), "gcc-dac config already present")
        hooks_cfg = p.with_name("gcc-hooks.bldconf")
        target.write_text(f'source "${{PARSECDIR}}/{(hooks_cfg if hooks_cfg.exists() else p).relative_to(dest)}"\n')
    (dest / "config/gcc-dac.bldconf").write_text('source "${PARSECDIR}/config/gcc-hooks.bldconf"\n')
    manifest = {"source":str(src),"destination":str(dest),"reference_inventory":parsec_inventory(src),
                "original_hooks_sha256":original,"hooks_sha256":filehash(hooks),
                "original_gcc_sha256":old_gcc,"gcc_sha256":filehash(gcc),"rebased_symlinks":rebased,
                "status":"source prepared; NOT built; Linux /dev/ec_dac_roi implementation still required"}
    atomic_json(dest / "DAC_PREPARATION.json",manifest)
    return {"destination":str(dest),"executed":True,"status":manifest["status"]}

def build_parsec(work, benchmarks, execute=False, jobs=2):
    work = Path(work).resolve()
    require(work.is_relative_to((KIT / "work").resolve()) and (work / "DAC_PREPARATION.json").is_file(), "not a prepared work copy")
    require(1 <= jobs <= 4,"build concurrency must be <=4")
    for b in benchmarks:
        name(b)
        require(any(work.glob("pkgs/*/"+b+"/parsec/gcc-dac.bldconf")),"unknown benchmark: "+b)
    argv = [str(work/"bin/parsecmgmt"),"-a","build","-c","gcc-dac","-p"] + benchmarks
    if execute:
        # --host/--build prevent many autoconf probes, but are not proof that
        # arbitrary package build scripts cannot launch a RISC-V conftest.
        review=read_json(work/"DAC_BUILD_REVIEW.json")
        require(review.get("cross_configure_reviewed") is True and review.get("no_target_execution") is True,
                "PARSEC configure/build effects must be reviewed; target tests may invoke binfmt/QEMU")
        require(set(benchmarks)<=set(review.get("benchmarks",[])),"unreviewed PARSEC benchmark build")
        scripts=[work/"bin/parsecmgmt"]+list((work/"config").glob("*.bldconf"))+list(work.glob("pkgs/*/*/parsec/*.bldconf"))
        for script in scripts:
            key=str(script.relative_to(work))
            require(review.get("reviewed_script_hashes",{}).get(key)==filehash(script),"unreviewed/changed build script: "+key)
        require(os.getloadavg()[0] <= 32,"shared-server load >32; build deferred")
        env = os.environ.copy()
        env.update({"PARSECDIR":str(work),"RISCV":str(MANAGER_ENV/"riscv-tools"),
                    "GNU_HOST_NAME":subprocess.check_output(["gcc","-dumpmachine"],text=True).strip(),
                    "GNU_TARGET_NAME":"riscv64-unknown-linux-gnu","PARSECPLAT":"riscv64-linux",
                    "MAKEFLAGS":"-j"+str(jobs),"OMP_NUM_THREADS":str(jobs)})
        logs = DATA/"build-logs";logs.mkdir(parents=True,exist_ok=True)
        import time
        with open(logs/("parsec-"+str(time.time_ns())+".log"),"xb") as log:
            p=subprocess.run(["nice","-n","10"]+argv,cwd=work,env=env,stdout=log,stderr=subprocess.STDOUT)
        require(p.returncode==0,"PARSEC build failed; inspect build log (no benchmark executed)")
    return {"argv":argv,"execute":execute,"warning":"compile pass does not verify ROI/driver/checker execution"}

def candidates(output):
    """Emit only B/C structural candidates; B/C4 have real isolated work trees."""
    output=Path(output)
    require(not output.exists(),"candidate directory exists")
    output.mkdir(parents=True)
    work=KIT/"work/opt4-minimal-v2"
    baseline=work/"B/chipyard/generators/chipyard/src/main/scala/config/DacBaselineConfig.scala"
    shutil.copy2(baseline,output/"B.scala.candidate")
    configs=[{"id":"B","physical_rockets":0,"source_tree":str(work/"B/chipyard"),"certified":False}]
    for n in (2,4,8):
        cid="C"+str(n)
        text=f"""package chipyard
import freechips.rocketchip.config.Config
import freechips.rocketchip.diplomacy.AsynchronousCrossing
// Use a PRIVATE copy of the frozen opt4 hardware, never a check source.
// GH_NUM_CORES must be {n+1} in that copy. C8 encoding/protocol changes are
// required BEFORE elaboration. C2/C8 builds are deferred until B/C4 is stable.
class Dac{cid} extends Config(
  new chipyard.config.WithTileFrequency(200,Some(0)) ++
  {''.join(f'new chipyard.config.WithTileFrequency(100,Some({i})) ++ ' for i in range(1,n+1))}
  new chipyard.config.WithGCBusFrequency(100) ++
  new chipyard.config.WithSystemBusFrequency(200) ++
  new chipyard.config.WithMemoryBusFrequency(200) ++
  new chipyard.config.WithPeripheryBusFrequency(200) ++
  new chipyard.config.WithSystemBusFrequencyAsDefault ++
  new freechips.rocketchip.subsystem.WithInclusiveCache(nWays=16,capacityKB=1024,outerLatencyCycles=12) ++
  new freechips.rocketchip.guardiancouncil.WithGHE ++
  new freechips.rocketchip.guardiancouncil.WithDisableROBDebug ++
  new freechips.rocketchip.subsystem.WithAsynchronousRocketTiles(AsynchronousCrossing().depth,AsynchronousCrossing().sourceSync) ++
  new boom.common.WithNParaMedicBooms(1,overrideIdOffset=Some(0)) ++
  new freechips.rocketchip.subsystem.WithNGCCheckers({n},overrideIdOffset=Some(1)) ++
  new chipyard.config.AbstractConfig)
"""
        (output/(cid+".scala.candidate")).write_text(text)
        configs.append({"id":cid,"physical_rockets":n,"certified":False,"deferred":n!=4,
                        "blockers":["hart8 requires 4-bit IDs plus control/mask/software protocol audit"] if n==8 else []})
    atomic_json(output/"candidates.json",{"logical_primary_configs":4,"certified_bitstreams":0,
                "reuse_verified":False,"configurations":configs,"ablation":"deferred; must follow real opt4 structure",
                "physical_build_policy":"B/C4 first; no checker-disabled replacement for B",
                "runtime_execution":"NOT_RUN"})
    return {"output":str(output),"certified":False,"primary_logical_configurations":4}
