"""Exclude host-serviced progress IO from the measured FP-growth ROI."""
from adapter_build import *
old=ROOT/'software/freqmine_serial_htif_hot4'
out=ROOT/'software/freqmine_serial_htif_hot4_quiet'
assert not out.exists(),'Do not overwrite a bound profile'
out.mkdir();shutil.copytree(old/'source',out/'source');shutil.copy2(old/'htif.ld',out/'htif.ld')
p=out/'source/data.cpp';s=p.read_text();progress='printf("transaction number is %d\\n", TRANSACTION_NO);'
assert s.count(progress)==1;p.write_text(s.replace(progress,'/* Progress IO excluded from computation ROI; transaction count verified after ROI. */'))
metadata=read(old/'manifest.json')
metadata.update(profile='test-input-hot4-lp64-quiet-roi',adaptations=metadata.get('adaptations',[])+['Successful input parser progress printf removed from ROI in both modes; count is still independently checked and printed after ROI. This eliminates HTIF fromhost spin loops dependent on host service timing.'],parent_manifest=str(old/'manifest.json'),parent_manifest_sha256=sha(old/'manifest.json'))
build(out,['fpmax-globals.cpp','data.cpp','fp_tree.cpp','buffer.cpp','fsout.cpp','fp_node.cpp','wtime.cpp','freqmine-adapter.cpp'],metadata)
print(out/'manifest.json')
