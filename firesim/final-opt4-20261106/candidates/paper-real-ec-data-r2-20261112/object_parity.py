#!/usr/bin/python3
from pathlib import Path
import hashlib,json,re,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
O=D/'matched-source-kernel-object-audit-r1-20261112';O.mkdir(exist_ok=False)
P=W/'candidates/matched-single-boom-gg-r3-20261112';plan=json.loads((P/'plan.json').read_text());tool=Path('/data1/gzh/EC/chipyard/.conda-env/riscv-tools/bin')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
rows=[]
for sw in plan['software']:
 orig=Path('/data1/gzh/EC-opt4-perf/slowdown/parsec_evaluation_20261103/build')/sw['workload'];new=Path(sw['cwd']);objs=[]
 for q in sorted(new.glob('*.o')):
  old=orig/q.name;oh=sha(old);nh=sha(q);same=oh==nh;assert same or q.name=='1.o'
  objs.append(dict(object=q.name,original=str(old),original_sha256=oh,native=str(q),native_sha256=nh,identical=same,scope='independent boot adapter test.c' if q.name=='1.o' else 'unchanged compiled source object'))
 slices=[]
 for label,elf in [('native',sw['elf']),('ec',next(x['elf'] for x in json.loads((D/'overnight-ec-evidence-audit-r4-20261112/summary.json').read_text())['workloads'] if x['benchmark']==sw['workload'].split('_')[0]))]:
  symbols=subprocess.check_output([str(tool/'riscv64-unknown-elf-nm'),'-n',elf],text=True);marks={name:int(addr,16) for addr,typ,name in re.findall(r'^(\w+)\s+(\w)\s+(\S+)$',symbols,re.M) if name in ['common_roi_start','common_roi_stop']};assert len(marks)==2
  asm=subprocess.check_output([str(tool/'riscv64-unknown-elf-objdump'),'-d','--start-address='+str(marks['common_roi_start']),'--stop-address='+str(marks['common_roi_stop']+12),elf],text=True)
  dest=O/(sw['workload']+'-'+label+'-roi-boundaries.asm');dest.write_text(asm);slices.append(dict(configuration=label,elf=elf,elf_sha256=sha(elf),symbols=marks,disassembly=str(dest),sha256=sha(dest)))
 rows.append(dict(workload=sw['workload'],unchanged_kernel_object_count=sum(x['identical'] for x in objs),objects=objs,roi_disassembly=slices))
result=dict(status='PASS_COMPILED_OBJECT_IDENTITY_EXCEPT_BOOT_ADAPTER',workloads=rows,fpga_access=False,scope='Binary object equality strengthens source parity; linked addresses/layout/boot/cache differ and are not declared identical')
(O/'result.json').write_text(json.dumps(result,sort_keys=True,indent=2)+'\n');(O/'complete.json').write_text(json.dumps(dict(result_sha256=sha(O/'result.json'),analyzer_sha256=sha(__file__)),indent=2)+'\n');print(json.dumps({x['workload']:x['unchanged_kernel_object_count'] for x in rows}))
