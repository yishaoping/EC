#!/usr/bin/env python3
"""Audit generated FASED registers and write common candidate arguments; never run a driver."""
import argparse
import hashlib
import json
from pathlib import Path
import re

KEYS = {"readLatency", "writeLatency", "readMaxReqs", "writeMaxReqs", "relaxFunctionalModel"}


def sha(path):
    h=hashlib.sha256()
    with open(path,"rb") as f:
        for block in iter(lambda:f.read(1024*1024),b""):h.update(block)
    return h.hexdigest()


def inspect(path, config):
    result=json.loads(path.read_text())
    if result.get("returncode")!=0 or result.get("phase")!="goldengate" or result.get("config")!=config:
        raise ValueError("need a successful matching GoldenGate result: "+str(path))
    out=Path(result["output_dir"])
    files={name:out/name for name in ("FireSim-generated.sv", "FireSim-generated.const.h")}
    for f in files.values():
        if sha(f)!=result["outputs"][str(f)]:raise ValueError("generated artifact hash changed: "+str(f))
    text=files["FireSim-generated.const.h"].read_text()
    sections=text.split("registry.add_widget(new FASEDMemoryTimingModel(")[1:]
    if len(sections)!=1:raise ValueError("expected exactly one memory model")
    section=sections[0].split("));",1)[0]
    vectors=section.split("std::vector<std::pair<std::string, uint32_t>>{")
    if len(vectors)!=3:raise ValueError("unknown generated FASED AddressMap format")
    pattern=r'R"ESC\((\w+)\)ESC", (\d+)'
    readable={k:int(v) for k,v in re.findall(pattern,vectors[1])}
    writable={k:int(v) for k,v in re.findall(pattern,vectors[2])}
    if set(writable)!=KEYS:raise ValueError("unexpected FASED settings: "+str(writable))
    defaults={}
    with open(files["FireSim-generated.sv"]) as f:
        for line in f:
            m=re.search(r"\b("+"|".join(sorted(KEYS))+r") <= 32'h([0-9a-f]+);",line)
            if m:
                if m[1] in defaults:raise ValueError("ambiguous generated setting "+m[1])
                defaults[m[1]]=int(m[2],16)
    if set(defaults)!=KEYS:raise ValueError("incomplete generated reset defaults")
    return {"result":str(path.resolve()), "result_sha256":sha(path), "source_id":result["source_id"],
            "generated_sha256":{str(f):sha(f) for f in files.values()},
            "readable_registers":readable, "writable_registers":writable, "generated_reset_defaults":defaults}


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--baseline-result",type=Path,required=True)
    p.add_argument("--c4-result",type=Path,required=True)
    p.add_argument("--out",type=Path,required=True)
    p.add_argument("--latency",type=int,default=30)
    p.add_argument("--max-requests",type=int,default=4)
    a=p.parse_args()
    evidence={"B":inspect(a.baseline_result,"DacBaseline"), "C4":inspect(a.c4_result,"DacOpt4C4")}
    if evidence["B"]["writable_registers"]!=evidence["C4"]["writable_registers"]:
        raise ValueError("FASED register maps differ")
    bound=min(e["generated_reset_defaults"][k] for e in evidence.values() for k in ("readMaxReqs","writeMaxReqs"))
    if not 1<=a.max_requests<=bound or not 1<=a.latency<2**31:
        raise ValueError("runtime request limit/latency outside audited common range")
    settings={"readLatency":a.latency, "writeLatency":a.latency,
              "readMaxReqs":a.max_requests, "writeMaxReqs":a.max_requests, "relaxFunctionalModel":0}
    plusargs=[f"+mm_{k}_0={v}" for k,v in sorted(settings.items())]
    a.out.mkdir(parents=True,exist_ok=False)
    args=a.out/"fased-common.args";args.write_text(" ".join(plusargs)+"\n")
    manifest={"schema":"ec-dac-memory/1", "model":"LatencyBandwidthPipe", "model_index":0,
              "settings":settings,"plusargs":plusargs,"arguments_sha256":sha(args), "evidence":evidence,
              "boom_uncore_mhz":200,"requested_latency_ns":a.latency*5,
              "bandwidth_policy":"AXI data width and R/W beat acceptance from generated target/model; no separate bandwidth runtime register exists",
              "static_register_audit":"PASSED", "runtime_readback":"NOT_RUN", "target_execution":"NOT_RUN",
              "warning":"B resets to max requests 4, C4 to 6. Use all explicit common arguments; hardware defaults are not comparable. These arguments are not runtime-validation evidence."}
    (a.out/"manifest.json").write_text(json.dumps(manifest,indent=2)+"\n")
    print(a.out/"manifest.json")


if __name__=="__main__":main()
