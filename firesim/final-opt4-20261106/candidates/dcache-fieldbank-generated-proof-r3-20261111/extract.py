#!/usr/bin/python3
"""Proof of changed storage transition cut extracted from authenticated actualRTL.
Not a monolithic fullDCache proof. No source/RTL/CAD/FPGA mutation.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,subprocess,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
O=D/'build-logs/Opt4-fit-dcache-fieldbank-generated-proof-r3-20261111';S=D/'Opt4-fit-dcache-fieldbank-extraction-r3-state.json';COMMIT='d9d732622601ed792a2647546006b5aae986ab8e';SID='1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);p.parent.mkdir(exist_ok=True,parents=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid):
 try:
  s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
TOKEN=re.compile(r"\b\d+'[sS]?[hHdDbBoO][0-9a-fA-F_xXzZ?]+|[a-zA-Z_][a-zA-Z0-9_$]*")
FIELDS=[('imageKey','valid',1,145,145),('imageKey','writer',16,144,129),('imageKey','generation',32,128,97),('imageKey','contentSeq',32,96,65),('lineGeneration','',32,64,33),('dirtyPacketSeq','',32,32,1),('dirtyPacketTracked','',1,0,0)]
CUTS={'clock':1,'reset':1,'dataWriteArb_io_in_0_valid':1,'dataWriteArb_io_in_1_valid':1,'dataWriteArb_io_in_1_ready':1,'refillLastBeat':1,'refillOwnerMatch':1,'selectedRefillSlotReserved':1,'s3_req_addr':40,'s3_way':2,'refillReqSet':8,'refillReqWay':1,'debug_new_image_generation':32,'s3_req_packet_seq':32,'mshrs_io_refill_bits_image_valid':1,'mshrs_io_refill_bits_image_writer':16,'mshrs_io_refill_bits_image_generation':32,'mshrs_io_refill_bits_image_contentSeq':32}
def main():
 O.mkdir(exist_ok=True);lock=(O/'extraction.instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(schema='ec-opt4-generated-owner-transition/1',**ident(os.getpid()),status='EXTRACTING_ACTUAL_GENERATED_RTL',hardware_commit=COMMIT,source_id=SID,functional_baseline_commit='8491167d84b6d9521b151a743673c1516926a1f8',fpga_access=False,whole_dut_formal=False,started_utc=now(),stages={})
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();refs={};source={};width={};defs={};lines={}
 for label,name in [('reference','Opt4-fit-update-share-svb-rtl-state.json'),('candidate','Opt4-fit-dcache-fieldbank-rtl-state.json')]:
  receipt=read(D/name);p=Path(receipt['goldengate_dir'])/'FireSim-generated.sv';assert sha(p)==receipt['outputs'][str(p)]
  if label=='candidate':assert receipt['hardware_commit']==COMMIT and receipt['source_id']==SID
  s=p.read_text();a=s.index('module BoomNonBlockingDCache(');b=s.index('\nendmodule',a);s=re.sub(r'//[^\n]*','',s[a:b]);refs[label]=dict(path=str(p),sha256=sha(p),receipt_sha256=sha(D/name));source[label]=s;lines[label]=s.splitlines()
  width[label]={m.group(3):m.group(2) or '' for m in re.finditer(r'\b(wire|reg|input|output)\s+(\[[^\]\n]+\]\s*)?([A-Za-z_][\w$]*)',s)}
  d={m.group(2):m.group(3) for m in re.finditer(r'\bwire\s+(\[[^\]]+\]\s*)?([A-Za-z_][\w$]*)\s*=\s*([^;]+);',s)}
  d.update({m.group(1):m.group(2) for m in re.finditer(r'\bassign\s+(\w+)\s*=\s*([^;]+);',s)});defs[label]=d
 # Every state word is proved with arbitrary146bits and resetmask. The
 # syntactic closure rejects references to other oldstorage words, enabling
 # independent-word induction without assuming equal words in the real DUT.
 decls=[];visited={};reads=set();observations=[];proofs=[];register_blocks=[]
 assignment_index={}
 for label,ls in lines.items():
  index={}
  for number,line in enumerate(ls):
   m=re.match(r'\s*([A-Za-z_][\w$]*) <=',line)
   if m:index.setdefault(m.group(1),[]).append(number)
  assignment_index[label]=index
 def statefield(name):
  for stem,field,w,hi,lo in FIELDS:
   m=re.fullmatch(stem+r'_(\d+)_(\d+)'+('_'+field if field else ''),name)
   if m:return int(m.group(1))*2+int(m.group(2)),(stem+'_'+field).rstrip('_'),w,hi,lo
  return None
 def expand(label,expr,slot):
  def token(m):
   name=m.group(0)
   if "'" in name or name in ['if','else','begin','end']:return name
   if name in CUTS:return name
   sf=statefield(name)
   if sf:
    assert label=='reference' and sf[0]==slot,('crossword dependency',name,slot)
    reads.add((slot,name));return 'prev_'+sf[1]
   m0=re.fullmatch(r'ownerWritten_(\d+)',name)
   if m0:assert label=='candidate' and int(m0.group(1))==slot;return 'written'
   assert name in defs[label],('uncut generated input',label,name,slot)
   renamed=('r_' if label=='reference' else 'c_')+name
   if renamed not in visited:
    assert name in width[label],('missing width',label,name)
    visited[renamed]=slot
    rhs=expand(label,defs[label][name],slot)
    decls.append('wire '+width[label][name]+' '+renamed+' = '+rhs+';')
   return renamed
  return TOKEN.sub(token,expr)
 def block_for(name,label='reference'):
  ls=lines[label];hits=assignment_index[label].get(name,[])
  assert hits,name;first=hits[0];start=first-1;assert ls[start].strip()=='if (reset) begin',(name,ls[start])
  end=start+1
  while end<len(ls) and not ls[end].startswith('    if '):end+=1
  block='\n'.join(ls[start:end]);assert block.count(name+' <=')==len(hits),(name,'multiple top-levelupdates')
  return block
 raw=source['candidate'];writers={};memory_reads={}
 # Authenticate every physical field and its single actual generated write.
 for memory,bits,hi,lo in [('ownerImageMemory',81,145,65),('ownerGenerationMemory',32,64,33),('ownerPacketMemory',32,32,1),('ownerTrackedMemory',1,0,0)]:
  found=re.findall(r'\breg\s+'+(r'\['+str(bits-1)+r':0\]\s+' if bits>1 else r'(?:\[0:0\]\s+)?')+r'('+memory+r'(?:_flattened)?)\s+\[0:511\]',raw)
  assert len(found)==1,(memory,bits,found)
  actual=found[0]
  writes=re.findall(re.escape(actual)+r'\[([A-Za-z_][\w$]*)\] <= ([A-Za-z_][\w$]*);',raw)
  assert len(writes)==1,(memory,writes)
  addr,data=writes[0];prefix=addr.removesuffix('_addr');assert prefix+'_data'==data
  assert 'if ('+prefix+'_en & '+prefix+'_mask) begin' in raw
  writers[memory]=dict(bits=bits,hi=hi,lo=lo,memory=actual,
   data=expand('candidate',defs['candidate'][data],0),
   addr=expand('candidate',defs['candidate'][addr],0),
   en=expand('candidate',defs['candidate'][prefix+'_en'],0),
   mask=expand('candidate',defs['candidate'][prefix+'_mask'],0))
  accesses=re.findall(r'\bwire\s+(?:\[[^\]]+\]\s+)?([A-Za-z_][\w$]*)\s*=\s*'+re.escape(actual)+r'\[([A-Za-z_][\w$]*)\]\s*;',raw)
  assert accesses,(memory,'no asynchronous read')
  memory_reads[memory]=[dict(data=data,addr=addr) for data,addr in accesses]
 assert 'reg [145:0] ownerMemory_flattened' not in raw
 tap_decls=[];tap_visited=set()
 def expand_tap(expr,slot):
  memory=writers['ownerGenerationMemory']['memory']
  def replace_read(m):
   name=m[1];literal=defs['candidate'][name].strip()
   assert re.fullmatch(r"9'h[0-9a-f]+",literal) and int(literal.split("'h")[1],16)==slot,(slot,name,literal)
   prefix=name.removesuffix('_addr');assert defs['candidate'][prefix+'_en'].strip()=="1'h1"
   return 'generation_raw'
  expr=re.sub(re.escape(memory)+r'\[([A-Za-z_][\w$]*)\]',replace_read,expr)
  def token(m):
   name=m[0]
   if "'" in name or name=='generation_raw':return name
   if name=='ownerWritten_'+str(slot):return 'written'
   assert name in defs['candidate'],('uncut generation tap',slot,name)
   renamed='tap_'+str(slot)+'_'+name
   if renamed not in tap_visited:
    tap_visited.add(renamed);rhs=expand_tap(defs['candidate'][name],slot)
    tap_decls.append('wire '+width['candidate'][name]+' '+renamed+' = '+rhs+';')
   return renamed
  return TOKEN.sub(token,expr)
 initial=['wire [145:0] previous_effective = written ? previous_raw : 146\'h0;']
 for stem,field,w,hi,lo in FIELDS:
  name=(stem+'_'+field).rstrip('_');initial.append(f'wire {"["+str(w-1)+":0] " if w>1 else ""}prev_{name} = previous_effective[{hi}:{lo}];')
 extra=[]
 for slot in range(512):
  sn,way=divmod(slot,2);refparts=[]
  for stem,field,w,hi,lo in FIELDS:
   name=f'{stem}_{sn}_{way}'+('_'+field if field else '');block=block_for(name);out=f'next_{slot}_{stem}_{field}'.rstrip('_')
   rhsblock=re.sub(r'\b'+re.escape(name)+r'\s*<=',out+' =',block)
   # Expand RHS/conditions while preserving newly generated LHS names.
   chunks=[]
   for line in rhsblock.splitlines():
    left,sep,right=line.partition(out+' =')
    chunks.append(expand('reference',left,slot)+(out+' ='+expand('reference',right,slot) if sep else ''))
   register_blocks.append('reg '+('['+str(w-1)+':0] ' if w>1 else '')+out+';\nalways @* begin\n'+out+' = prev_'+(stem+'_'+field).rstrip('_')+';\n'+'\n'.join(chunks)+'\nend')
   refparts.append(out)
  # Use the exact emitted per-word written-mask transition block as well.
  own='ownerWritten_'+str(slot);b=block_for(own,'candidate');out='mask_next_'+str(slot);b=re.sub(r'\b'+own+r'\s*<=',out+' =',b)
  chunks=[]
  for line in b.splitlines():
   left,sep,right=line.partition(out+' =');chunks.append(expand('candidate',left,slot)+(out+' ='+expand('candidate',right,slot) if sep else ''))
  register_blocks.append('reg '+out+';\nalways @* begin\n'+out+' = written;\n'+'\n'.join(chunks)+'\nend')
  parts=[]
  for memory,w in writers.items():
   field='raw_next_'+str(slot)+'_'+memory
   extra.append(f"wire [{w['bits']-1}:0] {field} = ({w['en']}) && ({w['mask']}) && ({w['addr']}) == 9'd{slot} ? ({w['data']}) : previous_raw[{w['hi']}:{w['lo']}];")
   parts.append(field)
  extra.append('wire [145:0] raw_next_'+str(slot)+' = {'+', '.join(parts)+'};')
  extra.append(f'wire [145:0] effective_next_{slot} = {out} ? raw_next_{slot} : 146\'h0;')
  extra.append('wire word_equal_'+str(slot)+' = {'+', '.join(refparts)+'} == effective_next_'+str(slot)+';')
  tap='debug_line_generation_'+str(slot)
  expression=expand_tap(defs['candidate'][tap],slot)
  extra.append(f"wire tap_equal_{slot} = ({expression}) == (written ? generation_raw : 32'h0);")
  assert defs['reference'][tap].strip()==f'lineGeneration_{sn}_{way}'
  observations.append(dict(slot=slot,width=32,async_read=True,mask_reset_relation=True,actual_tap_expression=expression))
 decls+=tap_decls
 ports=['input '+('['+str(w-1)+':0] ' if w>1 else '')+n for n,w in CUTS.items() if n!='clock']+['input [145:0] previous_raw','input written','input [31:0] generation_raw','output legal_interface','output equivalent','output mutation_equivalent']
 rtl='module GeneratedOwnerTransition('+',\n'.join(ports)+');\n'+'\n'.join(initial+decls+register_blocks+extra)+'\nassign legal_interface = !(dataWriteArb_io_in_0_valid && dataWriteArb_io_in_1_ready && dataWriteArb_io_in_1_valid);\nassign equivalent = &{'+','.join('word_equal_'+str(i)+' & tap_equal_'+str(i) for i in range(512))+'};\nassign mutation_equivalent = equivalent && (previous_raw[0] == !previous_raw[0]);\nendmodule\n'
 p=O/'GeneratedOwnerTransition.v';p.write_text(rtl)
 proof=read(D/'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json');assert proof['status'].startswith('PASS_ACTUAL_ARBITER2') and proof['source_id']=='548c7b8e1066ba82388ab759127e6d3b5c2a794f2f32ebcdc27b7f653b71d66c'
 contract=dict(schema='ec-generated-dcache-owner-contract/1',hardware_commit=COMMIT,source_id=SID,inputs=refs,all_original_words=512,word_bits=146,read_before_and_after_edge=True,all_generation_observations=observations,generated_statements_extracted=True,closure_rejects_crossword_oldstate=True,actual_arbiter_receipt_sha256=sha(D/'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json'),formal_cut_inputs=CUTS,miter_sha256=sha(p),proof_limits='Exact generated owner-register next-state blocks and actual flattened memory writer/mask. Arbitrary word state+mask lifted independently to512 words; actual Arbiter2 provides legal_interface. Unchanged remainingDCache and addressmodule require existing source composition. This is storage-cut formal, not monolithic fullDCache/fullDUT formal.')
 contract.update(physical_writers=writers,all_asynchronous_memory_accesses=memory_reads,
  proof_limits='All512 actual frozen-equivalent reference owner-register transitions compared with four independent generated field writers and synchronous reset masks. All512 generation tap readaddresses, widths and expressions checked. Arbitrary146bit state relation lifted per word. Existing exactsource and Arbiter2 receipts supply unchanged composition. This is a storage-cut proof; complete DCache cycles/formal and full-module area remain separate gates.')
 save(O/'extraction-contract.json',contract)
 update(status='EXTRACTED_SOURCE_BOUND_GENERATED_FIELD_TRANSITIONS_AND_TAPS_NOT_YET_PROVED',contract_sha256=sha(O/'extraction-contract.json'),ended_utc=now(),child={})
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if S.exists():
   s=read(S)
   if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,s)
  raise
