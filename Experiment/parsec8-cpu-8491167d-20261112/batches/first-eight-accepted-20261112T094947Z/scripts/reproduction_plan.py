"""Write a reviewable replay plan for the exact bound models and ELF images."""
from common import *
import shlex

entries=[]
for item in read(ROOT/'queue.json')['items']:
 mp=ROOT/item['manifest'];mf=read(mp)
 for mode in ['native','ec']:
  result,rp=selected_result(mf,mode)
  if not result or not result.get('valid'):continue
  binding=read(rp.parent/'binding.json')
  entries.append(dict(benchmark=mf['benchmark'],profile=mf['profile'],mode=mode,expected_roi_cycles=result['roi_cycles'],expected_roi_instructions=result['roi_instructions'],expected_output=result['output'],original_run=str(rp.parent),bound_manifest=str(mp),manifest_sha256=sha(mp),binary=str(NATIVE if mode=='native' else PROTECTED),binary_sha256=binding['binary_sha256'],elf=binding['elf'],original_argv=binding['args'],example_runner_argv=['/data1/gzh/EC/chipyard/.conda-env/bin/python3',str(ROOT/'scripts/run_one.py'),str(mp),mode,'--repeat','1','--attempt','3'],example_runner_command=shlex.join(['/data1/gzh/EC/chipyard/.conda-env/bin/python3',str(ROOT/'scripts/run_one.py'),str(mp),mode,'--repeat','1','--attempt','3'])))
save(ROOT/'paper/reproduction-plan.json',dict(schema='parsec8-exact-artifact-reproduction/1',created_utc=now(),functional_baseline=BASE,execution_performed_by_this_script=False,entries=entries,instructions=['Use original bound binaries/ELFs/manifests and verify all recorded SHA-256 values first. These files, raw logs and receipts are retained at the absolute paths.', 'Commands are reviewable examples only; do not launch them alongside the active campaign outside its four CPU locks and resource policy. A new attempt directory is required and must not overwrite previous evidence.', 'For an independent campaign copy the scripts, queue and corresponding complete software trees into a fresh experiment directory, preserve paths to the original immutable binary/ELF/shared objects, and let the scheduler assign locked slots. The source common.py defines ROOT relative to its location. Keep the original campaign inactive when sharing its selected host CPUs.', 'Rerun export.py to perform the full raw/output/ABI/source/input/strict-event audits before computing ratios. A new run is accepted on correctness/comparability, not on equality to the expected cycle count.', 'Rebuilding from source is separate from replaying the measured artifacts. The original ELF hash is authoritative; the currently retained linker-script hash is supplemental and does not establish clean-build identity.']))
