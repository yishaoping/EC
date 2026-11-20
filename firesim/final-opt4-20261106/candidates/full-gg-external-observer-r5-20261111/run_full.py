#!/usr/bin/python3
"""Finite full-workload successor; old jobs are never stopped or changed."""
from pathlib import Path
import hashlib
import json
import os
import subprocess
import sys
import traceback
import controller
from validate_binary import validate
from analyze_acceptance import analyze
from analyze_svb_latency import analyze as analyze_svb

C=Path(__file__).resolve().parent
O=controller.OUT
def main():
 predecessor=controller.D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111/result.json'
 assert controller.read(predecessor)['valid_finite_observation']
 assert not (O/'full-result.json').exists(),'ADOPT_EXISTING_COMPLETE_SUCCESSOR'
 # Controller full_only has singleton lock, all old-object hashes, resource
 # caps, per-run logs, per-target-cycle consistency gates and exact old printf.
 controller.full_only()
 r=controller.read(O/'result.json')
 directory=O/'canneal-observer-on'
 acceptance=analyze(directory)
 controller.save(O/'acceptance-pairing.json',acceptance)
 structural=validate(C/'binary-layout.json',directory/'external-events.jsonl.svb-full.bin')
 events=[json.loads(l) for l in (directory/'external-events.jsonl').read_text().splitlines()]
 summary=next(e for e in events if e['kind']=='SVB_SUMMARY')
 binary_summary=next(e for e in events if e['kind']=='SVB_BINARY_SUMMARY')
 assert structural['records']==r['observer_summary']['boom_edges']==binary_summary['record_count']
 assert structural['counts']['capture_accepted']==summary['captures']
 assert structural['counts']['promote_accepted']==summary['promotions']
 assert structural['counts']['ack_accepted']==summary['acks']
 controller.save(O/'binary-integrity.json',structural)
 svb_lifetimes=analyze_svb(directory,C/'binary-layout.json')
 controller.save(O/'svb-lifetimes.json',svb_lifetimes)
 r.update(binary_integrity=structural,svb_summary=summary,
  acceptance_pairing=acceptance,
  svb_lifetimes_summary={k:v for k,v in svb_lifetimes.items() if k not in ['sample_lifetimes','censored']},
  strict_sv_replay_passed=False,
  full_original_generated_svb_ports_saved=True,
  predecessor_result_sha256=controller.sha(predecessor),
  trace_scope='Original complete GoldenGate frozen Opt4 CPU metasimulation; real SVB ports every BOOM target edge, not FPGA measurements',
  next_step='Replay this complete reset-started port stream against original SVB RTL before admitting FPGA replay')
 controller.save(O/'full-result.json',r)
if __name__=='__main__':
 try:main()
 except BaseException as e:
  controller.save(O/'full-failure.json',dict(error=repr(e),traceback=traceback.format_exc(),utc=controller.now()))
  raise
