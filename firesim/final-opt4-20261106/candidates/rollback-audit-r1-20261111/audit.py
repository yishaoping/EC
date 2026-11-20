#!/usr/bin/python3
"""Read-only source audit. No device opens, subprocess hardware commands, or auth."""
from pathlib import Path
import datetime as dt
import hashlib
import json
import os
import re
import subprocess

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
F=W/'Opt4-fit-20261110'
O=D/'build-logs/Opt4-rollback-interface-audit-r1-20261111'
COMMIT='8da24a269b98a0d6a8f57b030353a310812c4344'
SOURCE='7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1'

def sha_bytes(x):return hashlib.sha256(x).hexdigest()
def save(p,x):
    p=Path(p);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)

def main():
    O.mkdir(exist_ok=True)
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==COMMIT
    paths={
      'legacy_injector':'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filter_prfs.scala',
      'legacy_ght':'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHT.scala',
      'rocket_tile':'chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala',
      'boom_packet_producer':'chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala',
      'checker_result':'chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala',
      'result_cdc':'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala',
      'dcache_fail':'chipyard/generators/boom/src/main/scala/lsu/dcache.scala',
      'svb':'chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala',
      'l2_barrier':'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala',
      'main_snapshot':'chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala',
      'main_core':'chipyard/generators/boom/src/main/scala/exu/core.scala'}
    texts={};records={}
    for role,rel in paths.items():
        data=subprocess.check_output(['git','show',COMMIT+':'+rel],cwd=F)
        assert (F/rel).read_bytes()==data
        texts[role]=data.decode();records[role]=dict(path=str(F/rel),commit=COMMIT,sha256=sha_bytes(data))
    for role,p in {
      'firmware_api':W/'software/C4/opensbi/lib/sbi/ec_opt4.c',
      'firmware_trap':W/'software/C4/opensbi/lib/sbi/ec_opt4_entry.S',
      'linux_api':W/'software/C4/linux/drivers/misc/ec_dac_roi.c',
      'normal_validator':W/'scripts/run_isolated_sample.py'}.items():
        data=p.read_bytes();texts[role]=data.decode();records[role]=dict(path=str(p),sha256=sha_bytes(data),scope='current preserved software source; not a new firmware build')
    claims=[]
    def claim(role,needle,finding,level='proven_source_observation'):
        lines=texts[role].splitlines();hits=[dict(line=i+1,text=s.strip()) for i,s in enumerate(lines) if needle in s]
        assert hits,(role,needle)
        claims.append(dict(role=role,needle=needle,evidence=hits,finding=finding,confidence=level))
    claim('legacy_injector','val incr_fi_counters','Legacy GHT has a use_fi_mode-gated packet corruption generator.')
    claim('rocket_tile','if (outer.tileParams.hartId == 0)','Legacy GHT is created only in Rocket hart0; the running configuration has BOOM as hart0.')
    claim('boom_packet_producer','// val use_fi_mode','BOOM GH_BUF comments out the legacy injection input.')
    claim('checker_result','val package_result_status =','Checker result status is derived from actual full comparison or cancellation.')
    claim('checker_result','GH_CHECKER_STATUS_FAIL.U','A compare error produces FAIL; cancellation has a distinct status.')
    claim('result_cdc','u_result_cdc(i).io.deq.fire','Result dequeue and checker release are CDC events, distinct from architectural restore.')
    claim('dcache_fail','val barrierFailureSeq = RegInit','The first failed/cancelled sequence is latched for the L2 validation barrier.')
    claim('dcache_fail','svbInvalidate.valid := barrierFailureAny','Failure invalidates unsafe SVB images; this is not an architectural replay witness.')
    claim('dcache_fail','addressStatsFatal :=','Failed/cancelled results invalidate address-statistics evidence.')
    claim('svb','io.recoveryFromSvb := io.acked','The recoveryFromSvb signal counts a matched promotion ACK; a positive count cannot certify fault recovery.')
    claim('l2_barrier','val barrierErrorDetected =','L2 handles a failed active barrier as a barrier error.')
    claim('main_snapshot','val arfs_in = Input','R_RSU reads main-core architectural state for snapshots; its audited ports contain no restore-state input.')
    claim('main_core','rsu_master.io.arfs_in(i)','Main BOOM exports its ARF to R_RSU. This direction is not a restore path.')
    claim('firmware_api','if (fn != 1) return SBI_ENOTSUPP','OpenSBI exposes version, one-time context installation, returned/fault masks, and installed-satp queries; no injection/restart function.')
    claim('firmware_api','if (generation ||','Firmware rejects a second checker context in the same boot.')
    claim('firmware_trap','fault[hart-1], never treated as PASS','Firmware fault publication is an error report, not recovery.')
    claim('firmware_trap','wfi','After context teardown the trap path parks; it does not retry the failed application.')
    claim('linux_api','if (cmd != EC_DAC_BEGIN','Linux ioctl whitelist contains BEGIN/END/DRAIN and checker-count query; no supported injection/restart ioctl.')
    claim('normal_validator',"['outstanding','faults','failed','cancelled','dropped']",'Ordinary runtime success explicitly requires zero failure and cancellation counts.')
    rtlstate=json.loads((D/'Opt4-fit-rtl-state.json').read_text())
    assert rtlstate['hardware_commit']==COMMIT and rtlstate['source_id']==SOURCE
    generated=Path(rtlstate['goldengate_dir'])/'FireSim-generated.sv'
    wanted={'GH_BUF','GHT','GHT_FILTER_PRFS','R_RSU','BoomCore','Rocket'};mods={x:[] for x in wanted};fi=[]
    with generated.open() as f:
        for number,line in enumerate(f,1):
            m=re.match(r'module (\w+)\(',line)
            if m and m.group(1) in wanted:mods[m.group(1)].append(number)
            if 'use_fi_mode' in line:fi.append(number)
    assert mods['GH_BUF'] and mods['BoomCore'] and not mods['GHT'] and not mods['GHT_FILTER_PRFS'] and not fi
    cad=json.loads((D/'Opt4-fit-cad-state.json').read_text())
    result=dict(schema='ec-opt4-rollback-interface-audit/1',utc=dt.datetime.now(dt.timezone.utc).isoformat(),
      hardware_commit=COMMIT,source_id=SOURCE,status='SUPPORTED_ARCHITECTURAL_ROLLBACK_DIAGNOSTIC_INTERFACE_NOT_ESTABLISHED',
      sources=records,findings=claims,generated_rtl=dict(path=str(generated),bytes=generated.stat().st_size,
        source_receipt=str(D/'Opt4-fit-rtl-state.json'),module_line_numbers=mods,use_fi_mode_occurrences=fi,
        huge_artifact_rehashed=False),certified_bitstream=cad.get('certified_bitstream',False),
      rollback_runtime_validated=False,normal_strict_success_is_rollback_evidence=False,fpga_access=False,
      conclusion='No supported software-controlled injection plus architectural restart/completion interface was established in the audited C4/8da path. Legacy injection logic is absent from the generated DUT. FAIL propagation, invalidation, cleanup, and promotion ACKs do not prove restoration of the BOOM architectural state or successful re-execution.',
      limits=['Source/interface audit only; no fault injection or waveform experiment was run.',
        'No claim that every possible software/RTL path in the repository has been formally excluded.',
        'No certified bitstream exists at this audit; a runnable bitstream-bound hardware diagnostic cannot yet be certified.'],
      safest_next_verification=['Use a separate simulation harness at existing checker-result interfaces to trace an actual full-compare FAIL through CDC, L1, SVB and L2; retain exact sequence and pre/post architectural state.',
        'Require an independently identified architectural checkpoint restore, memory-version selection, restart-PC retirement, and correct final output. Existing fault/cancel counters and SVB ACK observations are insufficient.',
        'If no existing restore/restart interface can be demonstrated, keep hardware rollback validation unestablished. Any new diagnostic tap/control must be a separate immutable candidate with inactive-cycle equivalence proof, active-injection tests and its own CAD/runtime binding; never patch live/frozen hardware.'])
    save(O/'audit.json',result)
    profile=dict(schema='ec-opt4-rollback-diagnostic-profile/1',name='rollback-interface-gap-r1',hardware_commit=COMMIT,source_id=SOURCE,
      board_bdf='0000:21:00.0',board_serial='21770433G02LA',bitstream_sha256=None,
      status='NOT_RUN_NO_CERTIFIED_BITSTREAM_OR_SUPPORTED_RESTART_INTERFACE',formal=False,fpga_execution=False,
      activation_allowed=False,software_built=False,source_audit=str(O/'audit.json'),
      required_witnesses=['actual full-compare FAIL and its sequence','architectural checkpoint restoration','restart PC and retired replay','memory recovery with correct final output','checker cleanup and complete drain'],
      rejected_as_rollback_evidence=['normal zero-fault strict success','fault flag only','cancellation only','promotion ACK or recoveryFromSvb count','host/target reset and new boot'])
    save(O/'diagnostic-profile.json',profile)
    print(json.dumps(dict(status=result['status'],audit=str(O/'audit.json'),profile=str(O/'diagnostic-profile.json'),findings=len(claims),fpga_access=False)))

if __name__=='__main__':main()
