#!/usr/bin/env python3
"""Test the emitted qualification register, including pulses that have ended.

Conditions and assignments come from generated RTL; datapath inputs are cut.
This is not a whole-cache or architectural rollback test.
"""
import argparse
import hashlib
import json
import re
import subprocess
import uuid
from pathlib import Path
from seal_candidate import ROOT, OUT


def assignments(source, target):
    """Keep ordered nonblocking assignments with their emitted if/else guards.

    FIRRTL emits each condition on one line and indents its body. Reject an
    unfamiliar form instead of substituting a handwritten next-state equation.
    """
    active, branches, found = {}, {}, []
    for number, raw in enumerate(source.splitlines(), 1):
        line = raw.split("//", 1)[0].rstrip()
        if not line.strip():
            continue
        indent = len(line) - len(line.lstrip())
        active = {i: expression for i, expression in active.items() if i < indent}
        statement = line.strip()
        match = re.fullmatch(r"(else )?if \((.*)\)(?: begin)?", statement)
        if match:
            alternatives = branches.get(indent, []) if match[1] else []
            guard = " & ".join("~(" + x + ")" for x in alternatives)
            active[indent] = (guard + " & " if guard else "") + "(" + match[2] + ")"
            branches[indent] = alternatives + [match[2]]
        elif statement in ("else", "else begin"):
            assert branches.get(indent), (number, statement)
            active[indent] = " & ".join("~(" + x + ")" for x in branches[indent])
        match = re.fullmatch(re.escape(target) + r" <= ([^;]+);", statement)
        if match:
            assert active, (number, "unguarded assignment")
            found.append({"line": number, "guard": " & ".join(
                "(" + value + ")" for _, value in sorted(active.items())), "rhs": match[1]})
    assert len(found) >= 2, (target, found)
    return found


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("emitted_dcache", type=Path)
    args = parser.parse_args()
    source = args.emitted_dcache.read_text()
    target = "crossPackageRescueQualified"
    updates = assignments(source, target)
    equation = re.search(r"^  wire\s+crossPackageSvbRescue = ([^;]+);", source, re.M)[1]
    formulas = [equation] + [x[key] for x in updates for key in ("guard", "rhs")]
    # These are control definitions, not datapath cuts. In particular the
    # allocation pulse must not be allowed to ignore the pending descriptor.
    for name in ["rescuePerfEvents_0", "svbEpochBoundary"]:
        rhs = re.search(r"^  wire\s+" + name + r" = ([^;]+);", source, re.M)[1]
        formulas = [re.sub(r"\b" + name + r"\b", "(" + rhs + ")", value) for value in formulas]
    allocation = re.search(r"^  wire\s+(\w+) = crossPackageBlockCondition & ~crossPackagePending;", source, re.M)
    assert allocation
    formulas = [re.sub(r"\b" + allocation[1] + r"\b", "(crossPackageBlockCondition & ~crossPackagePending)", value)
                for value in formulas]
    equation = formulas[0]
    for i, update in enumerate(updates):
        update["expanded_guard"], update["expanded_rhs"] = formulas[1+2*i:3+2*i]
    identifiers = re.sub(r"\d+'[bdho][0-9a-fA-F_xz]+", "", " ".join(formulas))
    leaves = sorted(set(re.findall(r"\b[A-Za-z_]\w*\b", identifiers)) - {target, "reset", "crossPackageSvbRescue"})
    names, ports, aliases = {}, ["input clock", "input reset"], []
    for i, leaf in enumerate(leaves):
        match = re.search(r"^\s+(?:input|wire|reg)\s+(\[[^\]\n]+\])?\s*" + re.escape(leaf) + r"\s*(?:=|;|,)", source, re.M)
        if match:
            width = match[1] or ""
        else:
            location = re.search(r"^\s+" + re.escape(leaf) + r"\s*[,)]", source, re.M)
            assert location, leaf
            declarations = list(re.finditer(r"^\s+(input|output)\s+(\[[^\]\n]+\])?", source[:location.start()], re.M))
            assert declarations and declarations[-1][1] == "input", leaf
            width = declarations[-1][2] or ""
        names[leaf] = "cut" + str(i)
        ports.append("input " + width + " " + names[leaf])
        aliases.append("wire " + width + " " + leaf + " = " + names[leaf] + ";")
    ports += ["output rescue", "output qualified"]
    rtl = "module RescuePulses(" + ",\n".join(ports) + ");\n" + "\n".join(aliases)
    rtl += "\nreg " + target + ";\nassign qualified = " + target + ";\nwire crossPackageSvbRescue = " + equation + ";\nassign rescue = crossPackageSvbRescue;\n"
    rtl += "always @(posedge clock) begin\n" + "\n".join(
        "if (" + x["expanded_guard"] + ") " + target + " <= " + x["expanded_rhs"] + ";" for x in updates) + "\nend\nendmodule\n"
    cpp = r'''
#include "VRescuePulses.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static VRescuePulses d;
static unsigned checks=0,cases=0;
static void require(bool value,const char* message){++checks;if(!value){std::fprintf(stderr,"FAIL case=%u check=%u: %s\n",cases,checks,message);std::exit(1);}}
static void edge(){d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();}
static void base(){
/* ZERO */
d.reset=1;edge();d.reset=0;
d.crossPackageRescueEpoch=13;d.svbEpoch=13;
d.slowdown_pending_resident_match=1;
d._imageValid_crossPackagePendingSet_crossPackagePendingWay_0=1;
d.slowdown_opt1_pending_live_key_valid=1;
d.slowdown_opt1_pending_live_key_contentSeq=17;d.debug_safe_packet_watermark=16;
d.crossPackageRescueSeq=18;d.crossPackagePendingSet=93;d.eval();
}
static void allocate(){
d.crossPackageBlockCondition=1;d.recoveryPerfCacheEvents_12=1;edge();
d.crossPackageBlockCondition=0;d.crossPackagePending=1;d.eval();
require(d.qualified,"full fallback must remember original qualification");
require(!d.rescue,"no capture when SVB is still full");
}
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);
base();allocate();
for(unsigned i=0;i<64;++i){edge();require(d.qualified&&!d.rescue,"full SVB must retain qualification while waiting");}
d._svb_io_capture_ready=1;d.eval();require(d.rescue,"available slot must admit an eligible frozen predecessor");
edge();require(!d.qualified&&!d.rescue,"handoff must consume qualification exactly once");++cases;
/* PULSE CASES */
base();d.crossPackageBlockCondition=1;d.recoveryPerfCacheEvents_12=0;edge();
d.crossPackageBlockCondition=0;d.crossPackagePending=1;d._svb_io_capture_ready=1;d.eval();
require(!d.qualified&&!d.rescue,"ordinary fallback must not acquire speculative permission");++cases;
std::printf("PASS emitted_rescue_pulses cases=%u checks=%u\n",cases,checks);return 0;}
'''
    cpp = cpp.replace("/* ZERO */", "\n".join("d." + leaf + "=0;" for leaf in leaves))
    pulses = ["io__traffic_reset", "io__lsu_exception", "svbFlushPending", "barrierFailureAny"]
    assert set(pulses) <= set(leaves)
    cases = []
    for pulse in pulses:
        cases.append("base();allocate();d._svb_io_capture_ready=1;d." + pulse + "=1;d.eval();\n"
                     "require(!d.rescue,\"live cancellation blocks handoff\");edge();\n"
                     "require(!d.qualified,\"cancellation permanently revokes qualification\");d." + pulse + "=0;\n"
                     "for(unsigned i=0;i<64;++i){edge();require(!d.qualified&&!d.rescue,\"ended pulse cannot requalify surviving descriptor\");}\n"
                     "d.crossPackagePending=0;d._svb_io_capture_ready=0;allocate();++cases;\n")
        cases.append("base();d.crossPackageBlockCondition=1;d.recoveryPerfCacheEvents_12=1;d." + pulse + "=1;edge();\n"
                     "require(!d.qualified,\"cancellation has priority over same-edge qualification\");++cases;\n")
    cpp = cpp.replace("/* PULSE CASES */", "\n".join(cases))
    cpp = re.sub(r"\bd\.(\w+)", lambda m: "d." + names.get(m[1], m[1]), cpp)
    run = OUT / "build" / ("rescue_pulses_" + uuid.uuid4().hex[:8])
    run.mkdir(parents=True, exist_ok=False)
    sv, driver = run / "RescuePulses.sv", run / "driver.cpp"
    sv.write_text(rtl)
    driver.write_text(cpp)
    command = ["verilator", "--cc", "--exe", "--build", "-j", "2", "-Wno-fatal",
               "--top-module", "RescuePulses", "--Mdir", str(run / "obj"), str(sv), str(driver)]
    with (run / "build.log").open("xb") as stream:
        subprocess.run(command, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT, check=True)
    test = subprocess.run([str(run / "obj/VRescuePulses")], cwd=run, capture_output=True, text=True)
    (run / "stdout.log").write_text(test.stdout)
    (run / "stderr.log").write_text(test.stderr)
    result = {"status": "PASS" if test.returncode == 0 else "FAIL",
              "emitted_source": str(args.emitted_dcache.resolve()),
              "emitted_sha256": hashlib.sha256(source.encode()).hexdigest(),
              "ordered_emitted_assignments": updates, "cut_inputs": leaves,
              "stdout": test.stdout, "stderr": test.stderr,
              "scope": "Exact emitted qualification-register updates and admission cone; cancellation pulses, allocation priority, delayed space and one-shot handoff. Descriptor datapath transfer and architectural rollback are not simulated."}
    (run / "result.json").write_text(json.dumps(result, indent=2) + "\n")
    print("RESULT=" + str(run / "result.json"), flush=True)
    print(test.stdout + test.stderr, flush=True)
    return int(test.returncode != 0)


if __name__ == "__main__":
    raise SystemExit(main())
