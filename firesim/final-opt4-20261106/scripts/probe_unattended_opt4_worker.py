#!/usr/bin/env python3
from pathlib import Path
import os,subprocess,json,datetime
W=Path("/data1/gzh/EC/firesim/final-opt4-20261106");D=Path("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106");O=D/"unattended-opt4/preflight"
env={k:v for k,v in os.environ.items() if not k.startswith(("VSCODE_","CODEX_"))}
env["PATH"]="/usr/local/bin:/usr/bin:/bin";env["CODEX_HOME"]="/home/guozh/.codex"
connection=Path('/home/guozh/.config/ec-opt4-unattended/environment.json')
if connection.exists():env.update(json.loads(connection.read_text()))
# Existing CLI credential is consumed in memory only. Do not print or copy it
# into the service unit, prompt, journal, argv, evidence or experiment files.
if not env.get("BEEAPI_API_KEY"):
 auth=json.loads(Path("/home/guozh/.codex/auth.json").read_text())
 if auth.get("OPENAI_API_KEY"):env["BEEAPI_API_KEY"]=auth["OPENAI_API_KEY"]
command=["/usr/local/bin/codex","exec","--json","--color","never","--sandbox","danger-full-access","-c",'approval_policy="never"',"-C","/data1/gzh/EC","--output-last-message",str(O/"last-message.txt"),"-"]
prompt="""This is a narrowly scoped service preflight. Read only /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-cad-state.json and /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-address-sort-state.json. Use a shell command to write /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/preflight/worker-proof.json atomically with schema ec-headless-worker-preflight/1, hardware_commit and status from both states, current boot_id, utc timestamp, fpga_access:false, and worker_execution:true. Do not modify any other file, execute hardware/tool actions, inspect secrets or network services, or spawn any agent. Reply only PREFLIGHT_OK after successful file write."""
with (O/"events.jsonl").open("wb",buffering=0) as out,(O/"stderr.log").open("wb",buffering=0) as err:
 p=subprocess.run(command,input=prompt.encode(),stdout=out,stderr=err,env=env,timeout=240)
result={"returncode":p.returncode,"utc":datetime.datetime.now(datetime.timezone.utc).isoformat(),"proof_exists":(O/"worker-proof.json").exists(),"fpga_access":False}
(O/"result.json").write_text(json.dumps(result,indent=2)+"\n");print(json.dumps(result))
if p.returncode:raise SystemExit(p.returncode)
