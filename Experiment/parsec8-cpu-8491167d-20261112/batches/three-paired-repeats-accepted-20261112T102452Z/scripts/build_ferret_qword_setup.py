"""Reuse a captured real Ferret input; reduce only ROI-external zeroing."""
from adapter_build import *
old=ROOT/'software/ferret_serial_htif'
out=ROOT/'software/ferret_serial_htif_qword_setup'
assert not out.exists(),'Build a new profile; do not overwrite bound artifacts'
out.mkdir();shutil.copytree(old/'source',out/'source');shutil.copy2(old/'htif.ld',out/'htif.ld')
src=out/'source';p=src/'matrix-alloc.c';text=p.read_text()
assert text.count('idx[0] = calloc(row * col, size);')==1
text=text.replace('idx[0] = calloc(row * col, size);','''cass_size_t bytes = row * col * size;
 idx[0] = malloc(bytes);
 assert(idx[0] != NULL);
 /* Same zeroed allocation, same shape, outside the warm replay ROI. */
 volatile uint64_t *words = (volatile uint64_t *)idx[0];
 for (cass_size_t zero_i=0; zero_i<bytes/8; ++zero_i) words[zero_i]=0;
 for (cass_size_t zero_i=bytes/8*8; zero_i<bytes; ++zero_i) ((volatile unsigned char *)idx[0])[zero_i]=0;''')
p.write_text('#include <stdint.h>\n'+text)
metadata=read(old/'manifest.json')
metadata.update(profile='real-test-first-emd-warm-replay-qword-setup',max_target_cycles=4000000,timeout_seconds=7200,
 adaptations=metadata.get('adaptations',[])+['ROI-external allocation retains the full 257x257 double matrix, using malloc and volatile uint64_t zero stores instead of bytewise calloc; warm original EMD call remains before ROI'],
 capture_parent_manifest=str(old/'manifest.json'),capture_parent_manifest_sha256=sha(old/'manifest.json'))
build(out,['emd.c','cass_dist.c','matrix-alloc.c','ferret-adapter.c','chunk-count.c'],metadata)
print(out/'manifest.json')
