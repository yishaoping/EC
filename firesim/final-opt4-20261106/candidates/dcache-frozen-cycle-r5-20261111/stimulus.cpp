#include "VDCacheCyclePair.h"
#include "verilated.h"
#include "clear-inputs.h"
#include "mismatch-names.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <map>
#include <stdexcept>

struct Reply {
    unsigned opcode, param, source, size, beats, beat, delay;
    uint64_t address;
};

static uint64_t rng = 0x8491167d9d732622ULL;
static uint64_t random64() {
    rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng;
}
static std::map<uint64_t, std::array<uint32_t, 16>> memory;
static std::array<uint32_t, 16> &line(uint64_t address) {
    const uint64_t base = address & ~uint64_t(63);
    auto pos = memory.find(base);
    if (pos == memory.end()) {
        std::array<uint32_t, 16> value{};
        for (unsigned i = 0; i < 16; ++i)
            value[i] = uint32_t((base + i*4) ^ 0x1234567887654321ULL);
        pos = memory.emplace(base, value).first;
    }
    return pos->second;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VDCacheCyclePair d;
    std::deque<Reply> replies;
    bool pending = false, accepted = false;
    bool store = false;
    uint64_t address = 0, token = 0;
    unsigned serial = 0, retry = 0, release_beat = 0, last_reset = 0;
    uint64_t requests = 0, acquires = 0, grants = 0, loads = 0, stores = 0;
    uint64_t nacks = 0, observations = 0, reset_edges = 0, packet_events = 0;
    uint64_t c_beats = 0, e_acks = 0, quiet_edges = 0;
    auto compare = [&](unsigned cycle, const char *phase) {
        for (unsigned i = 0; i < (sizeof(mismatch_names)/sizeof(*mismatch_names)); ++i) {
            if ((d.cycle_mismatch[i/32] >> (i%32)) & 1) {
                std::fprintf(stderr, "FULL_DCACHE_CYCLE_MISMATCH cycle=%u phase=%s signal=%s index=%u\n",
                             cycle, phase, mismatch_names[i], i);
                return false;
            }
        }
        ++observations;
        return true;
    };
    for (unsigned cycle = 0; cycle < 8192; ++cycle) {
        const bool reset = cycle < 300 || (cycle >= 4096 && cycle < 4396);
        const unsigned since = cycle < 4096 ? cycle : cycle - 4096;
        if (reset && !last_reset) {
            replies.clear(); pending = accepted = false; retry = release_beat = 0;
        }
        last_reset = reset;
        clear_inputs(d);
        d.reset = reset;
        d.io___05Fcsr_cycle = cycle;
        d.auto_out_a_ready = (random64() % 8) != 0;
        d.auto_out_c_ready = (random64() % 8) != 0;
        d.auto_out_e_ready = 1;
        d.io___05Flsu_release_ready = 1;
        d.io___05Ftraffic_check_state = 1;
        d.io___05Ftraffic_start = since == 600;
        d.io___05Fpacket_alloc_valid = since == 604;
        d.io___05Fpacket_alloc_seq = 1;
        d.io___05Fpacket_seq_baseline = 0;
        packet_events += d.io___05Fpacket_alloc_valid;
        // The final window drains the actual cache before checker release.
        if (since == 3850) d.io___05Fchecker_results_0 = (uint64_t(1) << 34) | 1;
        if (since == 3860) d.io___05Flsu_exception = 1;
        if (since == 3900) d.io___05Ftraffic_stop = 1;
        if (!reset && since >= 640 && since < 3400 && !pending && replies.empty() && retry == 0) {
            pending = true; accepted = false;
            store = (serial % 4) == 1;
            // Read, write, then read the same line, plus many different sets.
            address = 0x80000000ULL + uint64_t(serial / 4 % 128) * 64;
            token = ++serial;
        }
        if (retry) --retry;
        if (pending && !accepted && !reset && !retry) {
            d.io___05Flsu_req_valid = 1;
            d.io___05Flsu_req_bits_0_valid = 1;
            d.io___05Flsu_req_bits_0_bits_addr = address;
            d.io___05Flsu_req_bits_0_bits_data = 0xace0000000000000ULL | token;
            d.io___05Flsu_req_bits_0_bits_uop_mem_cmd = store ? 1 : 0;
            d.io___05Flsu_req_bits_0_bits_uop_mem_size = 3;
            d.io___05Flsu_req_bits_0_bits_uop_uses_stq = store;
            d.io___05Flsu_req_bits_0_bits_uop_uses_ldq = !store;
            d.io___05Flsu_req_bits_0_bits_uop_ctrl_is_sta = store;
            d.io___05Flsu_req_bits_0_bits_uop_ctrl_is_std = store;
            d.io___05Flsu_req_bits_0_bits_uop_ctrl_is_load = !store;
            d.io___05Flsu_req_bits_0_bits_request_token_valid = 1;
            d.io___05Flsu_req_bits_0_bits_request_token = token;
            d.io___05Flsu_req_bits_0_bits_effect_token_valid = 1;
            d.io___05Flsu_req_bits_0_bits_effect_token = token;
            d.io___05Flsu_req_bits_0_bits_packet_seq = 1;
            d.io___05Flsu_req_bits_0_bits_write_domain_valid = store;
            d.io___05Flsu_req_bits_0_bits_write_domain_seq = 1;
            d.io___05Flsu_req_bits_0_bits_traffic_cacheable = 1;
        }
        if (!reset && !replies.empty()) {
            auto &r = replies.front();
            if (r.delay) --r.delay;
            else {
                d.auto_out_d_valid = 1;
                d.auto_out_d_bits_opcode = r.opcode;
                d.auto_out_d_bits_param = r.param;
                d.auto_out_d_bits_source = r.source;
                d.auto_out_d_bits_size = r.size;
                d.auto_out_d_bits_sink = 0;
                d.auto_out_d_bits_user_cache_image_valid = r.opcode == 5;
                d.auto_out_d_bits_user_cache_image_writer = 1;
                d.auto_out_d_bits_user_cache_image_generation = 1;
                d.auto_out_d_bits_user_cache_image_contentSeq = 0;
                auto &data = line(r.address);
                for (unsigned i = 0; i < 4; ++i)
                    d.auto_out_d_bits_data[i] = data[(r.beat * 4 + i) % 16];
            }
        }
        d.clock = 0; d.eval();
        if (cycle && !compare(cycle, "pre")) return 2;
        const bool a = d.auto_out_a_valid && d.auto_out_a_ready && !reset;
        const bool c = d.auto_out_c_valid && d.auto_out_c_ready && !reset;
        const bool e = d.auto_out_e_valid && d.auto_out_e_ready && !reset;
        const bool g = d.auto_out_d_valid && d.auto_out_d_ready && !reset;
        const bool req = d.io___05Flsu_req_valid && d.io___05Flsu_req_ready && !reset;
        const bool nack = d.io___05Flsu_nack_0_valid && !reset;
        const bool load = d.io___05Flsu_resp_0_valid && !reset;
        const bool done = d.io___05Flsu_store_done_valid && !reset;
        Reply ar{};
        if (a) {
            const unsigned op = d.auto_out_a_bits_opcode;
            if (op != 6 && op != 7 && op != 4)
                throw std::runtime_error("unexpected A opcode; extend versioned memory model");
            ar = Reply{op == 6 ? 5U : op == 7 ? 4U : 1U,
                       op == 6 || op == 7 ? (d.auto_out_a_bits_param == 0 ? 1U : 0U) : 0U,
                       d.auto_out_a_bits_source, d.auto_out_a_bits_size,
                       op == 7 ? 1U : 4U, 0, unsigned(2 + random64()%5),
                       d.auto_out_a_bits_address};
        }
        Reply cr{};
        bool release_last = false;
        if (c) {
            ++c_beats;
            const unsigned op = d.auto_out_c_bits_opcode;
            const bool data = op == 5 || op == 7;
            if (data) {
                auto &value = line(d.auto_out_c_bits_address);
                for (unsigned i = 0; i < 4; ++i)
                    value[release_beat * 4 + i] = d.auto_out_c_bits_data[i];
                release_beat = (release_beat + 1) % 4;
            }
            release_last = (op == 6 || op == 7) && (!data || release_beat == 0);
            if (release_last) cr = Reply{6,0,d.auto_out_c_bits_source,d.auto_out_c_bits_size,1,0,2,d.auto_out_c_bits_address};
        }
        d.clock = 1; d.eval();
        if (!compare(cycle, "post")) return 2;
        if (reset) ++reset_edges;
        if (req) { accepted = true; ++requests; }
        if (nack) { accepted = false; retry = 12; ++nacks; }
        if (load) { pending = accepted = false; retry = 3; ++loads; }
        if (done) { pending = accepted = false; retry = 3; ++stores; }
        if (g) {
            auto &r = replies.front(); ++grants;
            if (++r.beat == r.beats) replies.pop_front();
        }
        if (a) { replies.push_back(ar); ++acquires; }
        if (release_last) replies.push_back(cr);
        if (e) ++e_acks;
        if (!pending && replies.empty()) ++quiet_edges;
        // A clockless input change must retain same-cycle equality as well.
        d.clock = 0; d.io___05Fcsr_cycle = cycle ^ 0x80000000U; d.eval();
        if (!compare(cycle, "clockless")) return 2;
        Verilated::timeInc(1);
    }
    d.final();
    std::printf("FULL_DCACHE_CYCLE_COUNTS cycles=8192 observations=%llu reset_edges=%llu requests=%llu acquires=%llu grants=%llu loads=%llu stores=%llu nacks=%llu c_beats=%llu e_acks=%llu packet_events=%llu quiet_edges=%llu pending=%u replies=%zu\n",
        (unsigned long long)observations, (unsigned long long)reset_edges,
        (unsigned long long)requests,(unsigned long long)acquires,(unsigned long long)grants,
        (unsigned long long)loads,(unsigned long long)stores,(unsigned long long)nacks,
        (unsigned long long)c_beats,(unsigned long long)e_acks,(unsigned long long)packet_events,
        (unsigned long long)quiet_edges,pending,replies.size());
    if (loads < 16 || stores < 16 || acquires < 8 || grants < 32 ||
        reset_edges != 600 || packet_events != 2 || pending || !replies.empty()) {
        std::fprintf(stderr,"COVERAGE_INCOMPLETE no cycle-admission receipt\n");
        return 3;
    }
    std::puts("COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192 all_outputs_and_donttouch=1 assertions_enabled=1 NOT_FULL_FORMAL_NOT_WHOLE_ADMITTED");
    return 0;
}
