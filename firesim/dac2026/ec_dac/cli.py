from __future__ import annotations
import argparse
from collections import Counter
import datetime as dt
import json
from pathlib import Path
import sys
import time
from .common import KIT, ROOT, DATA, atomic_json, read_json, name

def campaign_path(value):
    return DATA / "campaigns" / name(value)

def main(argv=None):
    parser=argparse.ArgumentParser(description="DAC preparation; execution is opt-in and fails closed")
    sub=parser.add_subparsers(dest="command",required=True)
    a=sub.add_parser("audit",help="read-only host/source/PARSEC inspection; write a new report")
    a.add_argument("--out")
    a=sub.add_parser("preflight",help="static readiness; no deployment/build/simulation")
    a.add_argument("--out")
    a=sub.add_parser("prepare-parsec",help="copy/instrument PARSEC under FireSim work only")
    a.add_argument("--destination",required=True);a.add_argument("--execute",action="store_true")
    a=sub.add_parser("build-parsec",help="compile only; never runs a target executable")
    a.add_argument("--work",required=True);a.add_argument("--benchmarks",nargs="+",required=True)
    a.add_argument("--jobs",type=int,default=2);a.add_argument("--execute",action="store_true")
    a=sub.add_parser("candidates",help="emit unvalidated Scala/config candidates; no elaboration")
    a.add_argument("--out",required=True)
    a=sub.add_parser("plan",help="freeze an immutable campaign and per-config guest jobs")
    a.add_argument("--campaign",required=True);a.add_argument("--stage",choices=["link","recovery","main","scan","ablation","all"],required=True)
    a.add_argument("--reps",type=int,default=3)
    a.add_argument("--configs",nargs="+");a.add_argument("--benchmarks",nargs="+");a.add_argument("--repeats",type=int,nargs="+")
    for cmd in ("status","recover","pending"):
        a=sub.add_parser(cmd);a.add_argument("--campaign",required=True)
        if cmd=="pending":
            a.add_argument("--configs",nargs="+");a.add_argument("--benchmarks",nargs="+");a.add_argument("--repeats",nargs="+",type=int)
    a=sub.add_parser("deploy",help="preview/manual programming through a reviewed per-card adapter")
    a.add_argument("--config",required=True);a.add_argument("--execute",action="store_true")
    a.add_argument("--phase",choices=["link","main"],default="main")
    a=sub.add_parser("run",help="one manually launched boot per hardware config; drain and sample sequencing in guest")
    a.add_argument("--campaign",required=True);a.add_argument("--config",required=True)
    a.add_argument("--benchmarks",nargs="+");a.add_argument("--repeats",nargs="+",type=int)
    a.add_argument("--interrupt-after",type=int,help="manual recovery test: interrupt after this many completions and next start")
    a.add_argument("--execute",action="store_true")
    a=sub.add_parser("stage",help="preview or manually run a phase (deploy + boot per configuration)")
    a.add_argument("--campaign",required=True);a.add_argument("--stage",choices=["link","recovery","main","scan","ablation"],required=True)
    a.add_argument("--repeats",nargs="+",type=int);a.add_argument("--execute",action="store_true")
    a=sub.add_parser("collect",help="ingest adapter aggregate JSONL from a HOST file, not guest-only storage")
    a.add_argument("--campaign",required=True);a.add_argument("--input",required=True)
    a.add_argument("--follow",action="store_true");a.add_argument("--seconds",type=float,default=20)
    a=sub.add_parser("analyze")
    a.add_argument("--campaigns",nargs="+",required=True);a.add_argument("--out",required=True)
    a.add_argument("--area-results",nargs="+");a.add_argument("--no-plots",action="store_true")
    a=sub.add_parser("area-prepare")
    a.add_argument("--config",required=True);a.add_argument("--out",required=True);a.add_argument("--execute",action="store_true")
    a=sub.add_parser("area-import");a.add_argument("--directory",required=True)
    a=sub.add_parser("fpga-import",help="import Vivado deployment resources separately from ASIC area")
    a.add_argument("--config",required=True);a.add_argument("--report",required=True)
    a.add_argument("--rtl-manifest",required=True);a.add_argument("--out",required=True)
    a=sub.add_parser("build-hardware",help="compile/elaborate/synthesize ONLY from a reviewed build recipe")
    a.add_argument("--recipe",required=True);a.add_argument("--execute",action="store_true")
    args=parser.parse_args(argv)
    result={};exit_code=0
    if args.command in ("audit","preflight"):
        from .audit import inventory
        inventory_data=inventory()
        stamp=dt.datetime.now(dt.timezone(dt.timedelta(hours=8))).strftime("%Y%m%d-%H%M%S")
        out=Path(args.out) if args.out else DATA/"preparation"/(stamp+"-"+str(time.time_ns()%1000000))
        out.mkdir(parents=True,exist_ok=False)
        atomic_json(out/"environment.json",inventory_data)
        blockers=read_json(KIT/"config/readiness.json")
        atomic_json(out/"readiness.json",blockers)
        result={"report":str(out),"occupancy":inventory_data["hardware"]["occupancy"],
                "fpga_process_count":len(inventory_data["hardware"]["fpga_processes"]),
                "source_id":inventory_data["source"]["id"],"parsec_version":inventory_data["parsec"]["version"],
                "riscv_binaries":inventory_data["parsec"]["riscv_binary_count"],"readiness":blockers}
        if args.command=="preflight":exit_code=2 if blockers["formal_run_ready"] is False else 0
    elif args.command=="prepare-parsec":
        from .prepare import parsec_copy
        result=parsec_copy(args.destination,args.execute)
    elif args.command=="build-parsec":
        from .prepare import build_parsec
        result=build_parsec(args.work,args.benchmarks,args.execute,args.jobs)
    elif args.command=="candidates":
        from .prepare import candidates
        result=candidates(args.out)
    elif args.command=="plan":
        from .planning import make_manifest
        result=make_manifest(args.campaign,args.stage,args.reps,args.configs,args.benchmarks,args.repeats)
        exit_code=2 if result["blockers"] else 0
    elif args.command=="status":
        from .ledger import status
        rows,issues=status(campaign_path(args.campaign))
        result={"states":dict(Counter(x["state"] for x in rows)),"samples":rows,"journal_issues":issues}
    elif args.command=="recover":
        from .ledger import recover
        result=recover(campaign_path(args.campaign))
    elif args.command=="pending":
        from .planning import select_pending
        samples,issues=select_pending(campaign_path(args.campaign),args.configs,args.benchmarks,args.repeats)
        result={"pending":samples,"journal_issues":issues}
    elif args.command=="deploy":
        from .runner import deploy
        result=deploy(args.config,args.execute,args.phase)
    elif args.command=="run":
        from .runner import launch
        result=launch(campaign_path(args.campaign),args.config,args.execute,args.benchmarks,args.repeats,args.interrupt_after)
        exit_code=2 if result.get("returncode",0)!=0 else 0
    elif args.command=="stage":
        from .runner import deploy,launch
        from .planning import select_pending
        from .common import require
        require(bool(read_json(campaign_path(args.campaign)/"manifest.json")["samples"]),
                "campaign has no admitted samples; complete benchmark admission before running a stage")
        ids=read_json(KIT/"config/experiment.json")["stages"][args.stage]
        results=[]
        for cid in ids:
            pending,_=select_pending(campaign_path(args.campaign),[cid],None,args.repeats)
            if not pending:
                results.append({"config":cid,"state":"no pending samples"});continue
            deployment=deploy(cid,args.execute,args.stage)
            results.append({"config":cid,"deployment":deployment,
                            "run":launch(campaign_path(args.campaign),cid,args.execute,repeats=args.repeats)})
        result={"stage":args.stage,"results":results,"executed":args.execute}
        exit_code=2 if any(r.get("run",{}).get("returncode",0)!=0 for r in results) else 0
    elif args.command=="collect":
        from .collector import Collector
        from .common import require
        require(1<=args.seconds<=300,"snapshot interval must be 1..300 seconds")
        c=Collector(campaign_path(args.campaign));buffer=bytearray();last=time.monotonic()
        try:
            with open(args.input,"rb") as f:
                while True:
                    block=f.read(65536)
                    if block:
                        buffer.extend(block)
                        require(len(buffer)<=8*1024*1024,"record exceeds limit")
                        while b"\n" in buffer:
                            line,_,rest=buffer.partition(b"\n");buffer[:]=rest
                            if line:c.event(json.loads(line))
                    if time.monotonic()-last>=args.seconds:
                        c.heartbeat(max_age=3*args.seconds,enforce_fresh=args.follow);last=time.monotonic()
                    if not block:
                        if not args.follow:break
                        time.sleep(.2)
            if buffer:c.journal.append({"kind":"partial_adapter_tail","bytes_hex":buffer.hex()})
            c.interrupted("input EOF")
        except BaseException:
            c.interrupted("collector stopped before completion");raise
        finally:c.close()
        result={"collected":True}
    elif args.command=="analyze":
        from .analysis import summarize
        result=summarize([campaign_path(x) for x in args.campaigns],args.out,args.area_results,not args.no_plots)
    elif args.command=="area-prepare":
        from .area import prepare_area
        result=prepare_area(args.config,args.out,args.execute)
    elif args.command=="area-import":
        from .area import import_area
        result=import_area(args.directory)
    elif args.command=="fpga-import":
        from .fpga import import_fpga
        result=import_fpga(args.config,args.report,args.rtl_manifest,args.out)
    elif args.command=="build-hardware":
        from .build import hardware_build
        result=hardware_build(args.recipe,args.execute)
    print(json.dumps(result,ensure_ascii=False,indent=2))
    return exit_code

if __name__=="__main__":
    try:sys.exit(main())
    except (ValueError,OSError,KeyError,TimeoutError) as e:
        print(json.dumps({"status":"BLOCKED_OR_FAILED","reason":str(e)},ensure_ascii=False),file=sys.stderr)
        sys.exit(2)
