#!/usr/bin/env python3
"""Matched guest memory budget, preserving hardware 16GiB mapping and original DTs."""
from pathlib import Path
import json,datetime as dt,subprocess,hashlib
from normalize_isa import normalize_dts
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');records=[]
for cfg in ['Native','C4']:
 parent=W/'software'/cfg/'fdt-build.json';r=json.loads(parent.read_text());out=W/'software'/cfg/('fdt-mem2g-'+stamp);out.mkdir()
 before=Path(r['dts']).read_text();args=r['bootargs'].replace('console=ttySIF0,115200','console=ttySIF0,3686400')+' mem=2G';text=before.replace(r['bootargs'],args).replace('serial0:115200n8','serial0:3686400n8');assert text!=before
 text,isa_normalization=normalize_dts(text)
 dts=out/(cfg+'.dts');dtb=out/(cfg+'.dtb');dts.write_text(text)
 cmd=[str(W.parent/'envs/manager-1.17.1/bin/dtc'),'-I','dts','-O','dtb','-p','4096','-o',str(dtb),str(dts)]
 with (out/'dtc.log').open('wb') as f:subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT,check=True)
 rr={**r,'dts':str(dts),'dts_sha256':sha(dts),'fdt':str(dtb),'sha256':sha(dtb),'command':cmd,'bootargs':args,'linux_mem_cap':2*2**30,'parent_receipt':str(parent),'parent_receipt_sha256':sha(parent),'profile':'matched-guest-mem2g-phys36-canonical-isa','isa_normalization':isa_normalization,'normalizer_sha256':sha(Path(__file__).with_name('normalize_isa.py')),'runtime_validation':'NOT_RUN'}
 (out/'manifest.json').write_text(json.dumps(rr,indent=2)+'\n');(W/'software'/cfg/'fdt-mem2g-build.json').write_text(json.dumps(rr,indent=2)+'\n');records.append(rr)
r=dict(schema='ec-matched-guest-memory/1',profile='matched-guest-mem2g-phys36',guest_ram_bytes=2*2**30,guest_visible_interval=[0x80200000,0x100200000],interval_definition='Linux early memory after OpenSBI 2MiB reservation, as actually observed in Native UART; C4 requires same runtime verification',hardware_ram_bytes=16*2**30,MAX_PHYSMEM_BITS=36,SECTION_SIZE_BITS=27,changes='Identical mem=2G and UART3686400 boot parameters, canonical ISA metadata in both DTs; hardware layout, kernel and application instructions unchanged',first_inputs=['Blackscholes test/simsmall/simmedium','Canneal test/simsmall','Streamcluster synthetic test/simsmall'],budget_reason='2 GiB exceeds first workload buffers and the 24.9MB immutable initramfs by a wide margin; no workload algorithm/input reduction. Native/Correction must use this exact profile for paired results.',runtime_peak_memory_validation='REQUIRED; not yet observed',not_combinable_with='16GiB/no-cap boot attempts or diagnostic32MiB profiles',records=records)
(D/'matched-guest-mem2g.json').write_text(json.dumps(r,indent=2)+'\n');print(D/'matched-guest-mem2g.json')
