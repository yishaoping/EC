#!/usr/bin/python3
"""Proof of changed storage transition cut extracted from authenticated actualRTL.
Not a monolithic fullDCache proof. No source/RTL/CAD/FPGA mutation.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,subprocess,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
O=D/'build-logs/Opt4-fit-dcache-generated-owner-proof-r1-20261111';S=D/'Opt4-fit-dcache-generated-owner-proof-r1-state.json';COMMIT='2210930f510eccf5518c444dadca4a51bcf6f851';SID='548c7b8e1066ba82388ab759127e6d3b5c2a794f2f32ebcdc27b7f653b71d66c'
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
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(schema='ec-opt4-generated-owner-transition/1',**ident(os.getpid()),status='EXTRACTING_ACTUAL_GENERATED_RTL',hardware_commit=COMMIT,source_id=SID,functional_baseline_commit='8491167d84b6d9521b151a743673c1516926a1f8',fpga_access=False,whole_dut_formal=False,started_utc=now(),stages={})
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update();refs={};source={};width={};defs={};lines={}
 for label,name in [('reference','Opt4-fit-update-share-svb-rtl-state.json'),('candidate','Opt4-fit-dcache-owner-rtl-state.json')]:
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
  ls=lines[label];hits=[i for i,l in enumerate(ls) if re.match(r'\s*'+re.escape(name)+r' <=',l)]
  assert hits,name;first=hits[0];start=first-1;assert ls[start].strip()=='if (reset) begin',(name,ls[start])
  end=start+1
  while end<len(ls) and not ls[end].startswith('    if '):end+=1
  block='\n'.join(ls[start:end]);assert block.count(name+' <=')==len(hits),(name,'multiple top-levelupdates')
  return block
 raw=source['candidate'];assert 'reg [145:0] ownerMemory_flattened [0:511]' in raw
 assert len(re.findall(r'ownerMemory_flattened\[ownerMemory_flattened_MPORT_addr\] <= ownerMemory_flattened_MPORT_data;',raw))==1
 assert 'if (ownerMemory_flattened_MPORT_en & ownerMemory_flattened_MPORT_mask) begin' in raw
 wdata=expand('candidate',defs['candidate']['ownerMemory_flattened_MPORT_data'],0)
 waddr=expand('candidate',defs['candidate']['ownerMemory_flattened_MPORT_addr'],0)
 wen=expand('candidate',defs['candidate']['ownerMemory_flattened_MPORT_en'],0)
 wmask=expand('candidate',defs['candidate']['ownerMemory_flattened_MPORT_mask'],0)
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
  extra.append(f'wire [145:0] raw_next_{slot} = ({wen}) && ({wmask}) && ({waddr}) == 9\'d{slot} ? ({wdata}) : previous_raw;')
  extra.append(f'wire [145:0] effective_next_{slot} = {out} ? raw_next_{slot} : 146\'h0;')
  extra.append('wire word_equal_'+str(slot)+' = {'+', '.join(refparts)+'} == effective_next_'+str(slot)+';')
  # Authenticate all512 actual debug generation taps against exact memoryword
  # slice andwrittenmask. This fails if any tap/read is narrowed or retimed.
  tap='debug_line_generation_'+str(slot);expr=defs['candidate'][tap];norm=re.sub(r'\s+','',expr)
  suffix='' if slot==0 else '_'+str(slot);mid='ownerMemory_debug_line_generation_MPORT'+suffix+'_data_generation';pfx='ownerMemory_flattened_debug_line_generation_MPORT'+suffix
  assert norm==f'ownerWritten_{slot}?{mid}:32\'h0',(slot,norm)
  assert re.sub(r'\s+','',defs['candidate'][mid])==pfx+'_data[64:33]'
  assert re.sub(r'\s+','',defs['candidate'][pfx+'_data'])=='ownerMemory_flattened['+pfx+'_addr]'
  assert defs['candidate'][pfx+'_addr'].strip()=="9'h"+format(slot,'x')
  assert defs['candidate'][pfx+'_en'].strip()=="1'h1"
  assert defs['reference'][tap].strip()==f'lineGeneration_{sn}_{way}'
  observations.append(dict(slot=slot,width=32,async_read=True,mask_reset_relation=True))
 ports=['input '+('['+str(w-1)+':0] ' if w>1 else '')+n for n,w in CUTS.items() if n!='clock']+['input [145:0] previous_raw','input written','output legal_interface','output equivalent','output mutation_equivalent']
 rtl='module GeneratedOwnerTransition('+',\n'.join(ports)+');\n'+'\n'.join(initial+decls+register_blocks+extra)+'\nassign legal_interface = !(dataWriteArb_io_in_0_valid && dataWriteArb_io_in_1_ready && dataWriteArb_io_in_1_valid);\nassign equivalent = &{'+','.join('word_equal_'+str(i) for i in range(512))+'};\nassign mutation_equivalent = equivalent && (previous_raw[0] == !previous_raw[0]);\nendmodule\n'
 p=O/'GeneratedOwnerTransition.v';p.write_text(rtl)
 proof=read(D/'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json');assert proof['status'].startswith('PASS_ACTUAL_ARBITER2') and proof['source_id']==SID
 contract=dict(schema='ec-generated-dcache-owner-contract/1',hardware_commit=COMMIT,source_id=SID,inputs=refs,all_original_words=512,word_bits=146,read_before_and_after_edge=True,all_generation_observations=observations,generated_statements_extracted=True,closure_rejects_crossword_oldstate=True,actual_arbiter_receipt_sha256=sha(D/'Opt4-fit-dcache-owner-arbiter-proof-r3-state.json'),formal_cut_inputs=CUTS,miter_sha256=sha(p),proof_limits='Exact generated owner-register next-state blocks and actual flattened memory writer/mask. Arbitrary word state+mask lifted independently to512 words; actual Arbiter2 provides legal_interface. Unchanged remainingDCache and addressmodule require existing source composition. This is storage-cut formal, not monolithic fullDCache/fullDUT formal.')
 save(O/'extraction-contract.json',contract);update(status='RUNNING_GENERATED_TRANSITION_SAT',contract=contract)
 def run(name,argv,negative=False):
  log=O/(name+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   child=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT);update(child=ident(child.pid),active_stage=name)
   while child.poll() is None:
    try:child.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  text=log.read_text();passed=child.returncode!=0 and 'proof did fail' in text if negative else child.returncode==0 and 'SUCCESS' in text
  assert 'timed out' not in text;st['stages'][name]=dict(returncode=child.returncode,accepted=passed,log=str(log),sha256=sha(log));update(child={});assert passed,(name,child.returncode,str(log))
 ys=O/'prepare.ys';ys.write_text(f'read_verilog {p}\nhierarchy -check -top GeneratedOwnerTransition\nproc\nopt\nwrite_rtlil {O/"prepared.il"}\n')
 # Preparation performs no synthesis mapping, small Boolean SAT only.
 log=O/'prepare.log'
 with log.open('xb') as f:subprocess.run(['/usr/local/bin/yosys','-s',str(ys)],stdout=f,stderr=subprocess.STDOUT,check=True)
 for name,target,neg in [('sat-transition','equivalent',False),('sat-negative','mutation_equivalent',True)]:
  ys=O/(name+'.ys');ys.write_text(f'read_rtlil {O/"prepared.il"}\nsat -verify -timeout 600 -set legal_interface 1 -prove {target} 1 -show-inputs\n');run(name,['/usr/local/bin/yosys','-s',str(ys)],neg)
 update(status='PASS_ACTUAL_GENERATED_512WORD_146BIT_TRANSITION_AND_ALL_GENERATION_TAPS_NOT_FULL_DCACHE_FORMAL',ended_utc=now(),child={},complete_dcache_formal=False,production_admission=False);save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if S.exists():
   s=read(S)
   if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,s)
  raise
