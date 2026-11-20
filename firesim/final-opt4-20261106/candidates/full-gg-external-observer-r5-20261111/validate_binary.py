#!/usr/bin/python3
"""Validate a saved full SVB port stream, without estimating missing events."""
from pathlib import Path
import hashlib
import json
import struct
import sys

def validate(layout_path,trace_path):
 layout=json.loads(Path(layout_path).read_text());trace=Path(trace_path)
 assert layout['schema']=='ec-svb-full-original-port-binary/1','LAYOUT_SCHEMA_MISMATCH'
 assert layout['functional_baseline']=='8491167d84b6d9521b151a743673c1516926a1f8','FUNCTIONAL_BASELINE_MISMATCH'
 assert layout['generated_sv_sha256']=='27362c56925b674288d37039c749ec9fbdd1a2e62141aac6d072022fd4d60885','GENERATED_MODEL_VERSION_MISMATCH'
 assert layout['header_bytes']==16 and layout['record_words']==101 and layout['record_bytes']==404,'LAYOUT_RECORD_SIZE_MISMATCH'
 assert len(layout['fields'])==65,'LAYOUT_FIELD_COUNT_MISMATCH'
 offset=0
 for field in layout['fields']:
  assert field['word_offset']==offset and field['word_count']==(field['width']+31)//32,'LAYOUT_FIELD_OFFSET_MISMATCH'
  offset+=field['word_count']
 assert offset==layout['record_words'],'LAYOUT_TOTAL_WORDS_MISMATCH'
 words=layout['record_words'];size=layout['record_bytes'];fmt=struct.Struct('<'+'I'*words)
 assert fmt.size==size and trace.stat().st_size>=16
 assert (trace.stat().st_size-16)%size==0,'INCOMPLETE_BINARY_RECORD'
 by={f['name']:f for f in layout['fields']}
 fields=layout['fields'];count=0;previous=None;first=None;last=None
 counts=dict(reset_cycles=0,capture_accepted=0,promote_accepted=0,ack_accepted=0,capture_blocked_cycles=0,promote_blocked_cycles=0,invalidate_cycles=0,flush_cycles=0)
 h=hashlib.sha256();padding_errors=0;first_reset=None;first_nonreset=None
 def value(row,name):
  field=by[name];v=0
  for j in range(field['word_count']-1,-1,-1):v=(v<<32)|row[field['word_offset']+j]
  return v
 with trace.open('rb') as f:
  header=f.read(16);h.update(header)
  assert header==b'ECSVBFULLBINv1'.ljust(16,b'\0'),'WRONG_BINARY_MAGIC'
  while chunk:=f.read(size*4096):
   h.update(chunk)
   assert len(chunk)%size==0,'PARTIAL_CHUNK'
   for row in struct.iter_unpack(fmt.format,chunk):
    count+=1;tick=value(row,'fastest_target_cycle')
    if first is None:first=tick
    if previous is not None:assert tick==previous+1,('MISSING_OR_DUPLICATE_TARGET_EDGE',previous,tick)
    previous=last=tick
    for field in fields:
     if field['width']%32:
      high=row[field['word_offset']+field['word_count']-1]
      padding_errors+=high>>(field['width']%32)!=0
    assert value(row,'clock')==1,'CLOCK_PORT_NOT_POSEDGE'
    reset=value(row,'reset')
    if reset:
     counts['reset_cycles']+=1
     if first_reset is None:first_reset=tick
    else:
     if first_nonreset is None:first_nonreset=tick
     cv=value(row,'io_capture_valid');cr=value(row,'io_capture_ready')
     pv=value(row,'io_promote_valid');pr=value(row,'io_promote_ready')
     av=value(row,'io_ack_valid');acked=value(row,'io_acked')
     counts['capture_accepted']+=cv and cr
     counts['promote_accepted']+=pv and pr
     counts['ack_accepted']+=av and acked
     counts['capture_blocked_cycles']+=cv and not cr
     counts['promote_blocked_cycles']+=pv and not pr
     counts['invalidate_cycles']+=value(row,'io_invalidate_valid')
     counts['flush_cycles']+=value(row,'io_flush')
 assert padding_errors==0,('NONZERO_PADDING',padding_errors)
 assert count>0 and first_reset is not None,'RESET_START_NOT_CAPTURED'
 return dict(schema='ec-full-svb-binary-integrity/1',status='PASS_BINARY_STRUCTURE_AND_CONTIGUOUS_TARGET_EDGES',
  file=str(trace),sha256=h.hexdigest(),layout_sha256=hashlib.sha256(Path(layout_path).read_bytes()).hexdigest(),
  bytes=trace.stat().st_size,records=count,first_target_cycle=first,last_target_cycle=last,
  first_reset_target_cycle=first_reset,first_nonreset_target_cycle=first_nonreset,counts=counts,
  padding_errors=padding_errors,fpga_access=False,
  limitations=['Structure/continuity only; captured ports need independent SVB replay comparison before hardware replay admission','Entire run is CPU metasimulation, not an FPGA sample'])

if __name__=='__main__':
 print(json.dumps(validate(sys.argv[1],sys.argv[2]),indent=2,sort_keys=True))
