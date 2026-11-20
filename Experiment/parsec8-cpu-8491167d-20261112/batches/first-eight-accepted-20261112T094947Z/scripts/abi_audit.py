from common import *
import subprocess,re
rows=[]
for item in read(ROOT/'queue.json')['items']:
 p=ROOT/item['manifest']
 if not p.exists():continue
 mf=read(p);modes={}
 for mode in ['native','ec']:
  elf=mf['elf'][mode];cmd=[str(TOOLS/'riscv64-unknown-elf-readelf'),'-h','-A','-l',elf['path']]
  t=subprocess.check_output(cmd,text=True);log=ROOT/'audit'/f"{item['benchmark']}-{mode}-readelf.txt";log.write_text(t)
  flags=re.search(r'^\s*Flags:\s*(.+)',t,re.M)[1]
  modes[mode]=dict(elf_sha256=sha(elf['path']),elf_hash_matches=sha(elf['path'])==elf['sha256'],elf_class=re.search(r'^\s*Class:\s*(.+)',t,re.M)[1],machine=re.search(r'^\s*Machine:\s*(.+)',t,re.M)[1],flags=flags,arch=re.search(r'Tag_RISCV_arch:\s*(.+)',t)[1],interpreter_present='INTERP' in t,readelf_evidence=str(log),readelf_sha256=sha(log))
  symbols=subprocess.check_output([str(TOOLS/'riscv64-unknown-elf-nm'),'-S','--defined-only',elf['path']],text=True)
  symbols_log=ROOT/'audit'/f"{item['benchmark']}-{mode}-symbols.txt";symbols_log.write_text(symbols)
  bound={}
  for line in symbols.splitlines():
   fields=line.split()
   if len(fields)==4 and fields[3] in ['workload_prepare','workload_run','workload_verify','timer_flags']:
    address=int(fields[0],16);bound[fields[3]]=dict(address=hex(address),bytes=int(fields[1],16),offset_in_64byte_line=address%64)
  modes[mode].update(selected_symbols=bound,symbol_evidence=str(symbols_log),symbol_evidence_sha256=sha(symbols_log))
 objs=mf.get('shared_kernel_objects',{})
 rows.append(dict(benchmark=item['benchmark'],manifest=str(p),manifest_sha256=sha(p),functional_baseline=mf['functional_baseline'],modes=modes,pair_abi_match=all(modes['native'][k]==modes['ec'][k] for k in ['elf_class','machine','flags','arch','interpreter_present']),shared_objects_bound=len(objs),shared_objects_hash_match=bool(objs) and all(sha(p)==h for p,h in objs.items()),same_elf=False,remaining_layout_confound=True))
save(ROOT/'audit/abi-audit.json',dict(created_utc=now(),profiles=rows,all_abi_matched=len(rows)==8 and all(r['pair_abi_match'] and r['shared_objects_hash_match'] for r in rows),limitations=['Matching ABI and shared objects do not remove ELF address/layout/cache-state differences','Historical Linux ELF artifacts require a Linux guest/runtime and are not loaded as HTIF applications']))
print([(r['benchmark'],r['pair_abi_match'],r['shared_objects_hash_match']) for r in rows])
import csv
with (ROOT/'paper/elf-layout.csv').open('w',newline='') as f:
 columns=['benchmark','symbol','native_address','ec_address','native_line_offset','ec_line_offset','native_bytes','ec_bytes','abi_matched','shared_objects_matched','same_elf','layout_error_bound']
 writer=csv.DictWriter(f,fieldnames=columns);writer.writeheader()
 for row in rows:
  for name,n in row['modes']['native']['selected_symbols'].items():
   e=row['modes']['ec']['selected_symbols'].get(name,{})
   writer.writerow(dict(benchmark=row['benchmark'],symbol=name,native_address=n['address'],ec_address=e.get('address'),native_line_offset=n['offset_in_64byte_line'],ec_line_offset=e.get('offset_in_64byte_line'),native_bytes=n['bytes'],ec_bytes=e.get('bytes'),abi_matched=row['pair_abi_match'],shared_objects_matched=row['shared_objects_hash_match'],same_elf=False,layout_error_bound='UNMEASURED'))
