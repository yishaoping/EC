from pathlib import Path
import hashlib,json,subprocess
C=Path(__file__).resolve().parent
cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);source=json.loads((C/'evidence/source-validation.json').read_text())
assert source['status']=='PASS_SOURCE_BOUND_SELECTED_FIELD_READS_TYPECHECK_FROZEN_PARAMETERS_NOT_GENERATED_OR_AREA_ADMITTED'
assert source['hardware_commit']==b['hardware_commit'] and source['source_id']==b['source_id'] and source['exact_parent_reversal'] and source['frozen_parameters_match']
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
rel='chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
assert hashlib.sha256((F/rel).read_bytes()).hexdigest()==source['source_sha256']
result=dict(source,status='PASS_EXACT_D9_PARENT_FIELD_READ_COMPOSITION_NOT_GENERATED_EQUIVALENT_OR_AREA_ADMITTED',whole_admission=False)
Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-field-read-system-r1-20261111/combined-equivalence.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
