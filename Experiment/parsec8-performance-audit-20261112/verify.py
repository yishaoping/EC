#!/usr/bin/python3
"""Verify the immutable publication and current original compressed log bytes."""
from pathlib import Path
import csv,hashlib,json,math
P=Path(__file__).resolve().parent
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  while b:=f.read(8*2**20):h.update(b)
 return h.hexdigest()
def rows(n):return list(csv.DictReader((P/n).open()))
def main():
 complete=json.loads((P/'complete.json').read_text());summary=json.loads((P/'summary.json').read_text())
 assert complete['status']==summary['status']=='PASS_REUSED_EXISTING_8_PROFILE_24_PAIRS'
 for name,digest in complete['files_sha256'].items():assert sha(P/name)==digest,name
 assert summary['first_round_pairs']==8 and summary['matched_repeat_pairs']==24 and summary['raw_cpu_logs_verified']==48
 assert not summary['fpga_access'] and summary['new_simulations_started']==0
 assert summary['full_application_slowdown'] is None and summary['full_ec_fpga_slowdown'] is None
 logs=json.loads((P/'cpu-raw-log-audit.json').read_text())
 assert len(logs)==48
 for r in logs:
  assert sha(r['result'])==r['result_sha256'] and sha(r['compressed_raw_log'])==r['gzip_sha256'],r['result']
 pairs=rows('paired-repeats.csv');assert len(pairs)==24
 for r in pairs:
  assert math.isclose(float(r['slowdown']),int(r['ec_roi_cycles'])/int(r['native_roi_cycles']),rel_tol=1e-14)
  assert r['method']=='CPU_GG_CYCLE_EXACT' and r['full_application_claim']=='False'
 for r in rows('coverage-status.csv'):
  assert int(r['native_fpga_valid_repeats'])==int(r['cpu_pair_repeats'])==3
  assert r['native_fpga_comparable_to_current_cpu']=='False' and r['full_ec_fpga_ready']=='False'
 print(json.dumps(dict(status='PASS_PUBLICATION_24_PAIRS_48_CURRENT_RAW_LOG_BINDINGS',native_fpga_saved_runs=24,first_round_pairs=8)))
if __name__=='__main__':main()
