#!/usr/bin/python3
"""Generate only an external C++ observer; never rewrite target RTL/model."""
from pathlib import Path
C=Path(__file__).resolve().parent
R=C.with_name('full-gg-external-observer-r2-20261111')
t=(R/'observer_main.cpp.in').read_text()
t=t.replace('#include <string>','#include <string>\n#include <array>')
extra='''
struct Image {
    uint64_t line=0;
    uint32_t generation=0,seq=0;
    uint16_t writer=0,epoch=0;
    unsigned key_valid=0,param=0;
    std::array<uint32_t,16> data{};
};
static Image entry_image(const Vemul___024root& r,unsigned idx) {
    Image im{};
    switch(idx) {
@ENTRY_CASES@
    default:break;
    }
    return im;
}
'''
cases=[]
for i in range(32):
 s=f'case {i}: im.line=BOOM(dcache__DOT__svb__DOT__line_{i});'
 for f,var in [('valid','key_valid'),('writer','writer'),('generation','generation'),('contentSeq','seq')]:
  s+=f'im.{var}=BOOM(dcache__DOT__svb__DOT__key_{i}_{f});'
 s+=f'im.epoch=BOOM(dcache__DOT__svb__DOT__epoch_{i});im.param=BOOM(dcache__DOT__svb__DOT__param_{i});'
 for row in range(4):
  for word in range(4):s+=f'im.data[{row*4+word}]=BOOM(dcache__DOT__svb__DOT__data_{i}_{row})[{word}];'
 s+='break;';cases.append(s)
extra=extra.replace('@ENTRY_CASES@','\n'.join(cases))
t=t.replace('struct Snapshot {',extra+'\nstruct Snapshot {')
fields='''
    bool capture_valid,capture_ready,promote_valid,promote_ready,ack_valid,acked;
    bool flush,invalidate,diagnostic,selected,active,sent;
    unsigned active_entry,promote_entry,ack_entry,allocated_entry,occupancy,coalesced,discarded;
    uint32_t watermark,valid_mask,ack_generation,ack_seq;
    unsigned ack_key_valid,ack_writer;
    uint64_t active_line;
    uint32_t active_generation,active_seq;
    unsigned release_blocked[4];
    uint64_t release_lines[4];
    unsigned release_entry3;
    uint64_t release_line3;
    uint32_t release_generation3,release_seq3;
    Image capture_image,promote_image;
'''
t=t.replace('    bool clk, reset_n, perf_reset, alloc;',fields+'    bool clk, reset_n, perf_reset, alloc;')
cap='''
    s.capture_valid=BOOM(dcache__DOT__wb__DOT__snapshotValid)&&!BOOM(dcache__DOT__svbCaptureDiscard);
    s.capture_ready=BOOM(dcache__DOT__svb_io_capture_ready);
    s.capture_image.line=((uint64_t(BOOM(dcache__DOT__wb__DOT__req_tag))<<8)|BOOM(dcache__DOT__wb__DOT__req_idx))<<6;
    s.capture_image.key_valid=BOOM(dcache__DOT__wb__DOT__snapshotKey_valid);
    s.capture_image.writer=BOOM(dcache__DOT__wb__DOT__snapshotKey_writer);
    s.capture_image.generation=BOOM(dcache__DOT__wb__DOT__snapshotKey_generation);
    s.capture_image.seq=BOOM(dcache__DOT__wb__DOT__snapshotKey_contentSeq);
    s.capture_image.epoch=BOOM(dcache__DOT__svbEpoch);
    s.capture_image.param=BOOM(dcache__DOT__wb__DOT__req_param);
@CAPTURE_DATA@
    s.active=BOOM(dcache__DOT__svb__DOT__active);s.sent=BOOM(dcache__DOT__svb__DOT__sent);
    s.promote_valid=s.active&&!s.sent;
    s.promote_ready=BOOM(dcache__DOT__wb_io_svb_req_ready);
    s.promote_entry=BOOM(dcache__DOT__svb__DOT__activeIdx);
    s.promote_image=entry_image(r,s.promote_entry);
    s.ack_valid=BOOM(dcache__DOT__wb_io_svb_done_valid);
    s.acked=BOOM(dcache__DOT__svb_io_acked);
    s.ack_entry=BOOM(dcache__DOT__wb__DOT__pendingEntry);
    s.ack_key_valid=BOOM(dcache__DOT__wb__DOT__pendingKey_valid);
    s.ack_writer=BOOM(dcache__DOT__wb__DOT__pendingKey_writer);
    s.ack_generation=BOOM(dcache__DOT__wb__DOT__pendingKey_generation);
    s.ack_seq=BOOM(dcache__DOT__wb__DOT__pendingKey_contentSeq);
    s.watermark=BOOM(dcache__DOT__debug_safe_packet_watermark);
    s.flush=BOOM(dcache__DOT__svb_io_flush);s.invalidate=BOOM(dcache__DOT__svb_io_invalidate_valid);
    s.diagnostic=BOOM(dcache__DOT__svb_io_diagnosticDump);
    s.selected=BOOM(dcache__DOT__svb_io_selected);
    s.active_entry=BOOM(dcache__DOT__svb_io_activeEntry);
    s.active_line=BOOM(dcache__DOT__svb_io_activeLine);
    s.active_generation=BOOM(dcache__DOT__svb_io_activeKey_generation);
    s.active_seq=BOOM(dcache__DOT__svb_io_activeKey_contentSeq);
    s.occupancy=BOOM(dcache__DOT__svb__DOT__occupancyValue);
    s.coalesced=BOOM(dcache__DOT__svb_io_coalesced);s.discarded=BOOM(dcache__DOT__svb_io_discarded);
    s.release_lines[0]=BOOM(dcache__DOT__prober__DOT__req_address)&~uint64_t(63);
    s.release_lines[1]=BOOM(dcache__DOT__svb_io_releaseLines_1);
    s.release_lines[2]=BOOM(dcache__DOT__svb_io_releaseLines_2);
    s.release_lines[3]=BOOM(dcache__DOT___svb_io_releaseLines_3_T_1);
    s.release_entry3=BOOM(dcache__DOT__svb_io_releaseBlockingEntry_3);
    s.release_line3=BOOM(dcache__DOT__svb_io_releaseBlockingLine_3);
    s.release_seq3=BOOM(dcache__DOT__svb_io_releaseBlockingSeq_3);
    s.release_generation3=BOOM(dcache__DOT__svb_io_releaseBlockingGeneration_3);
@RELEASE_BLOCKED@
@VALID_MASK@
    s.allocated_entry=s.valid_mask==0xffffffffU?0:unsigned(__builtin_ctz(~s.valid_mask));
'''
cap=cap.replace('@CAPTURE_DATA@','\n'.join(f'    s.capture_image.data[{row*4+word}]=BOOM(dcache__DOT__wb__DOT__wb_buffer_{row})[{word}];' for row in range(4) for word in range(4)))
cap=cap.replace('@RELEASE_BLOCKED@','\n'.join(f'    s.release_blocked[{i}]=BOOM(dcache__DOT__svb_io_releaseBlocked_{i});' for i in range(4)))
cap=cap.replace('@VALID_MASK@','\n'.join(f'    s.valid_mask|=uint32_t(BOOM(dcache__DOT__svb__DOT__valid_{i}))<<{i};' for i in range(32)))
t=t.replace('    return s;',cap+'    return s;')
methods=r'''
    uint64_t svb_captures=0,svb_promotions=0,svb_acks=0,svb_windows=0,svb_window_cycles=0;
    FILE* svb_file=nullptr;
    unsigned window_left=0;
    std::array<Snapshot,16> ring{};
    std::array<uint64_t,16> ring_ticks{};
    unsigned ring_pos=0,ring_size=0;
    static bool image_equal(const Image& a,const Image& b) {
        return a.line==b.line&&a.generation==b.generation&&a.seq==b.seq&&a.writer==b.writer&&a.epoch==b.epoch&&a.key_valid==b.key_valid&&a.param==b.param&&a.data==b.data;
    }
    static void image_json(FILE* f,const Image& im) {
        fprintf(f,"{\"line\":%" PRIu64 ",\"key_valid\":%u,\"writer\":%u,\"generation\":%u,\"content_seq\":%u,\"epoch\":%u,\"param\":%u,\"data_words_le\":[",im.line,im.key_valid,im.writer,im.generation,im.seq,im.epoch,im.param);
        for(unsigned j=0;j<16;++j)fprintf(f,"%s%u",j?",":"",im.data[j]);
        fprintf(f,"]}");
    }
    void svb_cycle(const Snapshot& s,uint64_t tick) {
        if(!svb_file)return;
        fprintf(svb_file,"{\"kind\":\"SVB_CYCLE\",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"reset\":%u,\"capture_valid\":%u,\"capture_ready\":%u,\"capture\":",tick,s.csr,!s.reset_n,s.capture_valid,s.capture_ready);
        image_json(svb_file,s.capture_image);
        fprintf(svb_file,",\"safe_watermark\":%u,\"diagnostic_dump\":%u,\"invalidate_valid\":%u,\"invalidate_bits\":%u,\"flush\":%u,\"promote_valid\":%u,\"promote_ready\":%u,\"promote_entry\":%u,\"promote\":",s.watermark,s.diagnostic,s.invalidate,s.watermark,s.flush,s.promote_valid,s.promote_ready,s.promote_entry);
        image_json(svb_file,s.promote_image);
        fprintf(svb_file,",\"ack_valid\":%u,\"ack_entry\":%u,\"ack_key_valid\":%u,\"ack_writer\":%u,\"ack_generation\":%u,\"ack_content_seq\":%u,\"acked\":%u,\"selected\":%u,\"active_entry\":%u,\"active_line\":%" PRIu64 ",\"active_generation\":%u,\"active_content_seq\":%u,\"occupancy\":%u,\"coalesced\":%u,\"discarded\":%u,\"release_lines\":[%" PRIu64 ",%" PRIu64 ",%" PRIu64 ",%" PRIu64 "],\"release_blocked\":[%u,%u,%u,%u],\"release_entry3\":%u,\"release_line3\":%" PRIu64 ",\"release_content_seq3\":%u,\"release_generation3\":%u}\n",s.ack_valid,s.ack_entry,s.ack_key_valid,s.ack_writer,s.ack_generation,s.ack_seq,s.acked,s.selected,s.active_entry,s.active_line,s.active_generation,s.active_seq,s.occupancy,s.coalesced,s.discarded,s.release_lines[0],s.release_lines[1],s.release_lines[2],s.release_lines[3],s.release_blocked[0],s.release_blocked[1],s.release_blocked[2],s.release_blocked[3],s.release_entry3,s.release_line3,s.release_seq3,s.release_generation3);
        ++svb_window_cycles;
    }
    void svb_event(const char* kind,const Snapshot& s,uint64_t tick,unsigned entry,const Image& im) {
        fprintf(out,"{\"kind\":\"%s\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"entry\":%u,\"payload\":",kind,++records,tick,s.csr,entry);
        image_json(out,im);fprintf(out,"}\n");
    }
    void svb_after(const Snapshot& a,const Snapshot& b,const Vemul___024root& r) {
        if(!a.reset_n||!b.reset_n)return;
        const bool cap=a.capture_valid&&a.capture_ready;
        const bool pro=a.promote_valid&&a.promote_ready;
        const bool ack=a.ack_valid&&a.acked;
        if(cap) {
            ++svb_captures;
            const auto actual=entry_image(r,a.allocated_entry);
            if(!image_equal(actual,a.capture_image))error("svb_capture_full_image_next_state",b.fastest,a.allocated_entry,0);
            if(!(b.valid_mask&(1U<<a.allocated_entry)))error("svb_capture_slot_valid",b.fastest,b.valid_mask,1U<<a.allocated_entry);
            svb_event("SVB_CAPTURE_ACCEPTED",a,b.fastest,a.allocated_entry,a.capture_image);
        }
        if(pro) {
            ++svb_promotions;
            if(!b.sent||!b.active)error("svb_promote_sent_transition",b.fastest,b.sent,1);
            svb_event("SVB_PROMOTE_ACCEPTED",a,b.fastest,a.promote_entry,a.promote_image);
        }
        if(a.ack_valid && !a.acked)error("svb_ack_not_accepted",b.fastest,a.ack_entry,0);
        if(ack) {
            ++svb_acks;
            if(b.valid_mask&(1U<<a.ack_entry))error("svb_ack_slot_still_valid",b.fastest,b.valid_mask,0);
            svb_event("SVB_ACK_ACCEPTED",a,b.fastest,a.ack_entry,entry_image(r,a.ack_entry));
        }
        // At most four contiguous 16-before/128-after windows. Every target
        // cycle in a window is retained, including idle/backpressure cycles.
        // These windows are not reset-started standalone replay certificates.
        if(!window_left && cap && svb_windows<4) {
            if(!svb_file) {
                svb_file=fopen((path+".svb-windows.jsonl").c_str(),"wx");
                if(!svb_file){perror("svb window open");std::exit(91);}
                fprintf(svb_file,"{\"kind\":\"HEADER\",\"schema\":\"ec-svb-contiguous-target-window/1\",\"scope\":\"Complete original generated SVB ports, finite windows only, pre-edge inputs/outputs; no compressed time\"}\n");
            }
            ++svb_windows;
            fprintf(svb_file,"{\"kind\":\"WINDOW_BEGIN\",\"window\":%" PRIu64 ",\"trigger_target_cycle\":%" PRIu64 ",\"pre_cycles\":%u,\"post_cycles\":128}\n",svb_windows,b.fastest,ring_size);
            for(unsigned j=0;j<ring_size;++j) {
                const auto idx=(ring_pos+16-ring_size+j)%16;
                svb_cycle(ring[idx],ring_ticks[idx]);
            }
            window_left=128;
        }
        if(window_left) {
            svb_cycle(a,b.fastest);
            if(!--window_left)fprintf(svb_file,"{\"kind\":\"WINDOW_END\",\"window\":%" PRIu64 ",\"last_target_cycle\":%" PRIu64 "}\n",svb_windows,b.fastest);
            fflush(svb_file);
        }
        ring[ring_pos]=a;ring_ticks[ring_pos]=b.fastest;
        ring_pos=(ring_pos+1)%16;if(ring_size<16)++ring_size;
    }
'''
t=t.replace('    void finish() {',methods+'\n    void finish() {')
t=t.replace('        ++nonreset_edges;','        ++nonreset_edges;\n        svb_after(a,b,r);')
t=t.replace('        fflush(out);fsync(fileno(out));fclose(out);out=nullptr;',r'''
        fprintf(out,"{\"kind\":\"SVB_SUMMARY\",\"captures\":%" PRIu64 ",\"promotions\":%" PRIu64 ",\"acks\":%" PRIu64 ",\"windows\":%" PRIu64 ",\"window_cycles\":%" PRIu64 ",\"incomplete_window_tail\":%u}\n",svb_captures,svb_promotions,svb_acks,svb_windows,svb_window_cycles,window_left);
        if(svb_file){fflush(svb_file);fsync(fileno(svb_file));fclose(svb_file);svb_file=nullptr;}
        fflush(out);fsync(fileno(out));fclose(out);out=nullptr;''')
# Keep END as the final record for the existing strict completion parser.
start=t.index('        fprintf(out,"{\\\"kind\\\":\\\"END\\\"')
end=t.index('\n',start)
line=t[start:end]
t=t[:start]+t[end:]
at=t.index('        if(svb_file){fflush(svb_file);')
t=t[:at]+line+'\n'+t[at:]
(C/'observer_main.cpp.in').write_text(t)
print(C/'observer_main.cpp.in')
