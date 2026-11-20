from pathlib import Path
import datetime,json,os,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from board_batch import D,save,sha,precheck
from job_service import proc
O=D/'safety/21-only-20261109';batch=D/'batches/Native-single-20261109T022232Z'
def protected():
 p=Path('/sys/bus/pci/devices/0000:e2:00.0')
 return {'endpoint':str(p.resolve()),'driver':str((p/'driver').resolve()),'endpoint_inode':p.stat().st_ino,
  'resource0_inode':(p/'resource0').stat().st_ino,'xdma_module_inode':Path('/sys/module/xdma').stat().st_ino,
  'device_nodes':{str(x):{'inode':x.stat().st_ino,'rdev':x.stat().st_rdev} for x in Path('/dev').glob('xdma1_*')}}
before=json.loads((O/'protected-e2-before.json').read_text());after=protected();save(O/'protected-e2-after-deploy.json',after)
assert before==after,'e2 identity changed'
s=json.loads((batch/'deployment.json').read_text());card=s['cards'][0];assert s['bdfs']==['0000:21:00.0'] and s['global_operations']==[]
assert sha(card['bitstream'])==card['bitstream_sha256']
log=batch/'program-Xilinx_21770433G02LA.log';lines=log.read_text().splitlines()
witness='EC_FPGA_PROGRAMMED serial=Xilinx/21770433G02LA file='+card['bitstream']+' device=xcu280_u55c_0'
assert lines.count(witness)==1
assert not any(line.lstrip().startswith('ERROR:') for line in lines)
assert any(line.startswith('INFO: [Common 17-206] Exiting Vivado') for line in lines)
deploylog=(batch/'deployment.log').read_text()
assert ':INFO: Writing to /sys/devices/pci0000:20/0000:20:03.1/rescan: 1' in deploylog
assert '/sys/bus/pci/rescan' not in deploylog and 'rmmod' not in deploylog and 'insmod' not in deploylog
check=precheck(target_bdfs=['0000:21:00.0']);assert not check['open_devices'] and not check['simulation_processes']
assert check['mapping'][0]['driver']=='xdma'
expected_e2_start='32740'; e2_now=proc(13546); assert e2_now is None or e2_now['start_ticks']==expected_e2_start
original=batch/'deployment-before-reconciliation.json'
if not original.exists():original.write_bytes((batch/'deployment.json').read_bytes())
s.update(status='DEPLOYED_NOT_RUN',completed_cards=[card],ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),postcheck=check,
 control_plane_reconciliation={'reason':'Vivado actually programmed target successfully; legacy call_vivado rejected echoed Tcl source containing ERROR: literals. Corrected guard strings and accepted exact completion witness; no second programming.',
 'raw_witness':witness,'program_log':str(log),'program_log_sha256':sha(log),'original_receipt':str(original),
 'original_failure_preserved':str(batch/'FAILED.json'),'e2_identity_unchanged':True,'revalidated_utc':datetime.datetime.now(datetime.timezone.utc).isoformat()})
save(batch/'deployment.json',s);save(D/'latest-deployment.json',s)
print(json.dumps({'status':s['status'],'bdfs':s['bdfs'],'reprogrammed_again':False,'e2_identity_unchanged':True}))
