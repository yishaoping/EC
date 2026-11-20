#!/usr/bin/python3
"""Exact original SVB-port binary layout, no generated-model modifications."""
from pathlib import Path
import hashlib
import json
C=Path(__file__).resolve().parent
R=C.with_name('full-gg-external-observer-r4-20261111')
mapping=json.loads((R/'svb-port-map.json').read_text())
plain={
 'clock':'1','reset':'!s.reset_n','io_diagnosticCycle':'s.csr',
 'io_capture_valid':'s.capture_valid','io_capture_ready':'s.capture_ready',
 'io_safeWatermark':'s.watermark','io_diagnosticDump':'s.diagnostic',
 'io_invalidate_valid':'s.invalidate','io_invalidate_bits':'s.watermark',
 'io_flush':'s.flush','io_promote_ready':'s.promote_ready',
 'io_promote_valid':'s.promote_valid','io_promote_bits_entry':'s.promote_entry',
 'io_ack_valid':'s.ack_valid','io_ack_bits_entry':'s.ack_entry',
 'io_ack_bits_key_valid':'s.ack_key_valid','io_ack_bits_key_writer':'s.ack_writer',
 'io_ack_bits_key_generation':'s.ack_generation','io_ack_bits_key_contentSeq':'s.ack_seq',
 'io_acked':'s.acked','io_selected':'s.selected','io_activeEntry':'s.active_entry',
 'io_activeLine':'s.active_line','io_activeKey_generation':'s.active_generation',
 'io_activeKey_contentSeq':'s.active_seq','io_occupancy':'s.occupancy',
 'io_coalesced':'s.coalesced','io_discarded':'s.discarded',
 'io_releaseBlockingEntry_3':'s.release_entry3','io_releaseBlockingLine_3':'s.release_line3',
 'io_releaseBlockingSeq_3':'s.release_seq3','io_releaseBlockingGeneration_3':'s.release_generation3',
}
for group in ['capture','promote']:
 for name,field in [('line','line'),('key_valid','key_valid'),('key_writer','writer'),('key_generation','generation'),('key_contentSeq','seq'),('epoch','epoch'),('param','param')]:
  plain[f'io_{group}_bits_{name}']=f's.{group}_image.{field}'
for i in range(4):
 plain[f'io_releaseLines_{i}']=f's.release_lines[{i}]'
 plain[f'io_releaseBlocked_{i}']=f's.release_blocked[{i}]'

fields=[];code=[];offset=0
for name,expr in [('fastest_target_cycle','tick'),('boom_csr_cycle','s.csr'),('host_time','host_time')]:
 fields.append(dict(name=name,width=64,word_offset=offset,word_count=2))
 code.append(f'        push64({expr},64);');offset+=2
for port in mapping['ports']:
 name=port['port'];width=port['width'];words=(width+31)//32
 fields.append(dict(name=name,direction=port['direction'],width=width,word_offset=offset,word_count=words))
 if '_bits_data_' in name:
  group=name.split('_')[1];row=int(name[-1]);assert width==128
  for word in range(4):code.append(f'        push64(s.{group}_image.data[{row*4+word}],32);')
 else:code.append(f'        push64({plain[name]},{width});')
 offset+=words
layout=dict(schema='ec-svb-full-original-port-binary/1',functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
 generated_sv_sha256=mapping['generated_sv_sha256'],source_port_map_sha256=hashlib.sha256((R/'svb-port-map.json').read_bytes()).hexdigest(),
 header_bytes=16,header_ascii='ECSVBFULLBINv1',header_padding='NUL to16bytes',record_words=offset,record_bytes=4*offset,
 encoding='little-endian uint32 words, values low-word-first; unused high bits zero',fields=fields,
 sampling='Stable pre-eval original SVB ports, committed at actual BOOM BUFGCE posedge; all target edges including reset, idle and backpressure. Fixed record interval is one BOOM edge.',
 clock_port='1 denotes sampled posedge, not waveform reconstruction',
 completeness='A partial final record or missing END receipt is invalid; compare record count to boom_edges; verify every consecutive target index and same ELF original prints before replay admission',
 unobserved='Other DUT state outside SVB; no complete-system state equivalence or architectural rollback/restart claim',fpga_access=False)
(C/'binary-layout.json').write_text(json.dumps(layout,indent=2,sort_keys=True)+'\n')
methods=r'''
    FILE* full_svb_file=nullptr;
    uint64_t full_svb_records=0;
    void svb_binary_cycle(const Snapshot& s,uint64_t tick,uint64_t host_time) {
        if(!full_svb_file) {
            full_svb_file=fopen((path+".svb-full.bin").c_str(),"wx");
            if(!full_svb_file){perror("full svb trace open");std::exit(92);}
            setvbuf(full_svb_file,nullptr,_IOFBF,256*1024);
            const char magic[16]="ECSVBFULLBINv1";
            if(fwrite(magic,1,16,full_svb_file)!=16)std::exit(93);
        }
        uint32_t words[@WORDS@]{};unsigned pos=0;
        auto push64=[&](uint64_t value,unsigned width) {
            for(unsigned j=0;j<(width+31)/32;++j) {
                words[pos++]=uint32_t(value&0xffffffffULL);value>>=32;
            }
        };
@FIELDS@
        if(pos!=@WORDS@ || fwrite(words,sizeof(uint32_t),pos,full_svb_file)!=pos)std::exit(94);
        ++full_svb_records;
        if((full_svb_records&1023)==0)fflush(full_svb_file);
    }
'''.replace('@WORDS@',str(offset)).replace('@FIELDS@','\n'.join(code))
t=(C/'observer_base.cpp.in').read_text()
t=t.replace('    void finish() {',methods+'\n    void finish() {')
t=t.replace('        if(svb_file){fflush(svb_file);',r'''
        fprintf(out,"{\"kind\":\"SVB_BINARY_SUMMARY\",\"record_count\":%" PRIu64 ",\"record_bytes\":@BYTES@}\n",full_svb_records);
        if(full_svb_file){fflush(full_svb_file);fsync(fileno(full_svb_file));fclose(full_svb_file);full_svb_file=nullptr;}
        if(svb_file){fflush(svb_file);'''.replace('@BYTES@',str(offset*4)))
# END must remain last, after the binary receipt.
start=t.index('        fprintf(out,"{\\\"kind\\\":\\\"END\\\"');end=t.index('\n',start)
line=t[start:end];t=t[:start]+t[end:]
at=t.index('        fflush(out);fsync(fileno(out));fclose(out);out=nullptr;')
t=t[:at]+line+'\n'+t[at:]
(C/'observer_main.cpp.in').write_text(t)
print(json.dumps(dict(record_words=offset,record_bytes=offset*4,original_ports=len(mapping['ports']),full_1759002_cycles_bytes=16+offset*4*1759002)))
