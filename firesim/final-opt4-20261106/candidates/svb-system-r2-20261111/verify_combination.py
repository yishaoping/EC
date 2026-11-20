#!/usr/bin/python3
"""Source-bound compositional delta proof, not a whole-DUT formal result."""
from pathlib import Path
import sys,subprocess,json,hashlib
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import *
C=Path(__file__).resolve().parent
cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);parent=b['parent_commit'];commit=b['hardware_commit'];rel='chipyard/generators/boom/src/main/scala/lsu/'
delta=subprocess.check_output(['git','diff','--name-only',parent,commit],cwd=F,text=True).splitlines();assert delta==[rel+'NewestSafeEntry.scala',rel+'speculative-version-buffer.scala']
original=subprocess.check_output(['git','show',parent+':'+rel+'speculative-version-buffer.scala'],cwd=F).decode();a=original.index('  val chooseValid = WireDefault(false.B)');z=original.index('\n  val occupancyValue',a)
expected=original[:a]+'  // Same total order (package, generation, slot), balanced combinational max.\n  // All comparisons and selection remain in this cycle; no state is added.\n  val (chooseValid, chooseIdx) = NewestSafeEntry(\n    entrySafe.toSeq, key.map(_.contentSeq).toSeq, key.map(_.generation).toSeq)\n'+original[z:]

assert (F/rel/'speculative-version-buffer.scala').read_text()==expected
svb=read(cfg['svb_result']);assert svb['status']=='VERIFIED_SELECTION_SUBSTITUTION_AND_MAPPED_NOT_WHOLE_DUT_ADMITTED' and svb['hardware_commit']==commit and svb['source_id']==b['source_id']
p=Path(svb['compositional_proof']);local=read(p);assert local['status']=='PASS_LOCAL_SAT_AND_ACTUAL_32_LEAF_31_MERGE_TOPOLOGY' and local['hardware_commit']==commit and sha(local['candidate_rtl'])==local['candidate_rtl_sha256']
assert svb['actual_size_boundary']=='PASS_8192_VECTORS_32_SLOTS'
assert sha(F/rel/'NewestSafeEntry.scala')==read(W/'candidates/svb-tree-r7-20261111/input-hashes.json')[str(F/rel/'NewestSafeEntry.scala')]
parent_local=read(cfg['verified_local']);parent_map=read(cfg['mapped_result']);assert parent_local['hardware_commit']==parent and parent_map['hardware_commit']==parent
assert parent_local['full_module_regression']['status']=='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
assert all((F/rel/n).read_bytes()==subprocess.check_output(['git','show',parent+':'+rel+n],cwd=F) for n in ['PackageAddressStats.scala','AddressBucketGrouped.scala','SafePrefixScanner.scala','dcache.scala'])
result=dict(schema='ec-opt4-compositional-delta-equivalence/1',status='PASS_SOURCE_BOUND_COMPOSITIONAL_SVB_DELTA_TO_VERIFIED_9AE_PARENT',hardware_commit=commit,source_id=b['source_id'],parent_commit=parent,parent_address_proof=str(cfg['verified_local']),parent_address_map=str(cfg['mapped_result']),svb_proof=str(p),svb_proof_sha256=sha(p),change_files=delta,reason='Only SVB combinational selection is substituted; arbitrary valid/seq32/generation32/unique-slot merge proof guarantees identical chooseValid/chooseIdx for every input/state. All surrounding state, update priority, outputs and other source files are identical to 9ae parent. Sequential equivalence of this delta follows by same-state induction. Inherited parent proof limits remain.',full_dut_formal=False,whole_system_fit=False,fpga_access=False,architectural_restart_added=False)
O=D/'build-logs/Opt4-fit-svb-system-r2-20261111';save(O/'combined-equivalence.json',result);print(result['status'])
