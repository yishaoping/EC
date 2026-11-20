import sys, json, shutil, subprocess, datetime, os
from pathlib import Path
sys.path.insert(0,"/data1/gzh/EC/firesim/final-opt4-20261106/scripts")
from board_batch import D, save, sha
from job_service import audit, read, proc, S, boot
assert os.geteuid()==0
s=read(D/"C4-runtime-cad-state.json");j=read(D/"jobs/cad/state.json")
assert s["host_boot_id"]==boot() and s["pid"]==85085 and s["start_ticks"]=="85991"
assert proc(s["pid"])["start_ticks"]==s["start_ticks"]
assert proc(j["pid"])["start_ticks"]==j["start_ticks"]
unit="ec-parsec-cad.service"
assert subprocess.check_output(["systemctl","show",unit,"-p","MainPID","--value"],text=True).strip()==str(j["pid"])
log=Path(s["log_dir"])/"build.log"
assert "File not found:" in log.read_text() and "Aborted" in log.read_text()
where=D/"interruptions"/("authorized-failed-cad-"+datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%dT%H%M%SZ"));where.mkdir()
na=audit(read(S/"native.json"));save(where/"native-before.json",na)
for p in [D/"C4-runtime-cad-state.json",D/"jobs/cad/state.json",Path("/etc/systemd/system")/unit]:shutil.copy2(p,where/p.name)
shutil.copytree(Path(s["log_dir"]),where/"failed-logs")
(where/"cgroup-before.txt").write_text(subprocess.check_output(["systemd-cgls","--no-pager","--unit",unit],text=True))
subprocess.run(["systemctl","stop",unit],check=True,timeout=110)
assert not proc(s["pid"]) and not proc(j["pid"])
s.update(status="INTERRUPTED",interruption_reason="User explicitly authorized stopping this confirmed failed CAD service after its run-launch child aborted; repair recovery without changing hardware inputs",ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
save(D/"C4-runtime-cad-state.json",s)
nb=audit(read(S/"native.json"));save(where/"native-after.json",nb)
a0=na["states"][-1]["processes"][0];a1=nb["states"][-1]["processes"][0]
assert a0["identity_live"] and a1["identity_live"] and a0["observed"]==a1["observed"]
save(where/"receipt.json",dict(user_authorized=True,stopped_unit=unit,boot_id=boot(),native_identity_unchanged=True,fpga_actions=False,log_sha256=sha(log)))
print(where)
