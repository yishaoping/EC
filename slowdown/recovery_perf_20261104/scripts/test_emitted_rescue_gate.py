#!/usr/bin/env python3
"""Exercise the actual emitted rescue admission gate with independent vectors."""
import argparse
import hashlib
import json
import os
import re
import subprocess
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("emitted_dcache", type=Path)
    args = parser.parse_args()
    source = args.emitted_dcache.read_text()
    match = re.search(r"^  wire\s+crossPackageSvbRescue = ([^;]+);", source, re.M)
    assert match
    expression = match[1]
    for name in ["rescuePerfEvents_0", "svbEpochBoundary"]:
        rhs = re.search(r"^  wire\s+" + name + r" = ([^;]+);", source, re.M)[1]
        expression = re.sub(r"\b" + name + r"\b", "(" + rhs + ")", expression)
    leaves = sorted(set(re.findall(r"\b[A-Za-z_]\w*\b", expression)))
    names = {name: "cut" + str(i) for i, name in enumerate(leaves)}
    ports = []
    for name in leaves:
        declaration = re.search(r"^\s+(?:input|wire|reg)\s+(\[[^\]\n]+\])?\s*" + re.escape(name) + r"\s*(?:=|;|,)", source, re.M)
        if declaration:
            width = declaration[1] or ""
        else:
            position = re.search(r"^\s+" + re.escape(name) + r"\s*[,)]", source, re.M)
            assert position, name
            declarations = list(re.finditer(r"^\s+(input|output)\s+(\[[^\]\n]+\])?", source[:position.start()], re.M))
            assert declarations and declarations[-1][1] == "input", name
            width = declarations[-1][2] or ""
        ports.append("input " + width + " " + names[name])
    rtl = "module RescueGate(" + ",\n".join(ports + ["output rescue"]) + ");\n"
    rtl += "assign rescue = " + re.sub(r"\b[A-Za-z_]\w*\b", lambda m: names[m[0]], expression) + ";\nendmodule\n"
    cpp = r'''
#include "VRescueGate.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
static VRescueGate d;
static unsigned checks=0;
static void check(bool want) {d.eval();++checks;if(bool(d.rescue)!=want){std::fprintf(stderr,"FAIL rescue vector %u\n",checks);std::exit(1);}}
static void base(){
/* ZERO */
d.crossPackagePending=1;d.crossPackageRescueQualified=1;
d.crossPackageRescueEpoch=13;d.svbEpoch=13;
d.slowdown_pending_resident_match=1;d._svb_io_capture_ready=1;
d._imageValid_crossPackagePendingSet_crossPackagePendingWay_0=1;
d.slowdown_opt1_pending_live_key_valid=1;
d.slowdown_opt1_pending_live_key_contentSeq=17;d.debug_safe_packet_watermark=16;
d.crossPackageRescueSeq=18;d.crossPackagePendingSet=93;
}
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);
base();check(true);
/* NEGATIVE_GUARDS */
base();d.crossPackageRescueEpoch=12;check(false);
base();d.crossPackageRescueSeq=17;check(false);
base();d.crossPackageRescueSeq=16;check(false);
base();d.slowdown_opt1_pending_live_key_contentSeq=0;check(false);
base();d.debug_safe_packet_watermark=17;check(false);
base();d._prober_io_state_valid=1;d._prober_io_state_bits=uint64_t(93)<<6;check(false);
base();d._prober_io_state_valid=1;d._prober_io_state_bits=uint64_t(94)<<6;check(true);
uint32_t rng=0xc0ffee;
for(unsigned i=0;i<20000;++i){
 rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;
 base();
 uint32_t predecessor=rng;uint32_t incoming=(rng>>1)^0x8234abcd;uint32_t safe=(rng<<1)^0x13456789;
 d.slowdown_opt1_pending_live_key_contentSeq=predecessor;d.crossPackageRescueSeq=incoming;d.debug_safe_packet_watermark=safe;
 check(predecessor!=0 && predecessor>safe && incoming>predecessor);
}
std::printf("PASS emitted_rescue_gate checks=%u\n",checks);return 0;}
'''
    cpp = cpp.replace("/* ZERO */", "\n".join("d." + name + "=0;" for name in leaves))
    positive = {"crossPackagePending", "crossPackageRescueQualified", "slowdown_pending_resident_match",
                "_svb_io_capture_ready", "_imageValid_crossPackagePendingSet_crossPackagePendingWay_0",
                "slowdown_opt1_pending_live_key_valid"}
    negative = {"io__traffic_reset", "io__lsu_exception", "svbFlushPending", "barrierFailureAny",
                "crossPackageIssued", "crossPackageMetaClearPending", "crossPackageSlotConflict",
                "debug_cross_package_meta_clear_block", "_completionPending_crossPackagePendingSet_crossPackagePendingWay_5",
                "recoveryPerfCacheEvents_8", "svbFastLineValid"}
    assert positive | negative <= set(leaves)
    cpp = cpp.replace("/* NEGATIVE_GUARDS */", "\n".join(
        "base();d." + name + "=" + str(int(name in negative)) + ";check(false);" for name in sorted(positive | negative)))
    cpp = re.sub(r"\bd\.(\w+)", lambda m: "d." + names.get(m[1], m[1]), cpp)
    run = OUT / "build" / ("rescue_gate_" + uuid.uuid4().hex[:8])
    run.mkdir(parents=True, exist_ok=False)
    sv, driver = run / "RescueGate.sv", run / "driver.cpp"
    sv.write_text(rtl)
    driver.write_text(cpp)
    command = ["verilator", "--cc", "--exe", "--build", "--assert", "-Wno-fatal", "-j", "2",
               "--top-module", "RescueGate", "--Mdir", str(run / "obj"), str(sv), str(driver)]
    with (run / "build.log").open("xb") as stream:
        subprocess.run(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT, check=True)
    test = subprocess.run([str(run / "obj/VRescueGate")], capture_output=True, text=True)
    (run / "stdout.log").write_text(test.stdout)
    (run / "stderr.log").write_text(test.stderr)
    result = {"status": "PASS" if test.returncode == 0 else "FAIL", "stdout": test.stdout,
              "emitted_source": str(args.emitted_dcache.resolve()), "emitted_sha256": sha(args.emitted_dcache),
              "expression": expression, "cut_inputs": leaves, "driver_sha256": sha(driver),
              "scope": "Exact emitted Boolean admission cone. Independent negative guards and 20000 sequence/safety boundary vectors. Does not prove sequential descriptor transfer, whole-cache behavior or architectural rollback."}
    (run / "result.json").write_text(json.dumps(result, indent=2) + "\n")
    print("RESULT=" + str(run / "result.json"), flush=True)
    print(test.stdout, flush=True)
    return int(test.returncode != 0)


if __name__ == "__main__":
    raise SystemExit(main())
