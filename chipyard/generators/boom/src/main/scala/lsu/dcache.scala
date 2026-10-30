//******************************************************************************
// Ported from Rocket-Chip
// See LICENSE.Berkeley and LICENSE.SiFive in Rocket-Chip for license details.
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

package boom.lsu

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.tile._
import freechips.rocketchip.util._
import freechips.rocketchip.rocket._
import freechips.rocketchip.guardiancouncil.{GH_GlobalParams, GHBarrierLatencyStats}

import boom.common._
import boom.exu.BrUpdateInfo
import boom.util.{IsKilledByBranch, GetNewBrMask, BranchKillableQueue, IsOlder, UpdateBrMask, AgePriorityEncoder, WrapInc, Transpose}


class BoomWritebackUnit(val svbEntries: Int)(implicit edge: TLEdgeOut, p: Parameters) extends L1HellaCacheModule()(p) {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new WritebackReq(edge.bundle)))
    val req_is_mshr = Input(Bool())
    val svb_req = Flipped(Decoupled(new SpeculativeVersionPromotion(refillCycles, encRowBits, log2Ceil(svbEntries))))
    val svb_done = Output(Valid(new SpeculativeVersionCompletion(log2Ceil(svbEntries))))
    val svb_release_done = Output(Bool())
    val pending_svb = Output(Bool())
    val pending_entry = Output(UInt(log2Ceil(svbEntries).W))
    val pending_line = Output(UInt(coreMaxAddrBits.W))
    val meta_read = Decoupled(new L1MetaReadReq)
    val resp = Output(Bool())
    val idx = Output(Valid(UInt()))
    val data_req = Decoupled(new L1DataReadReq)
    val data_resp = Input(UInt(encRowBits.W))
    val mem_grant = Input(Bool())
    val image_key = Input(new CacheImageKey)
    val pending_key = Output(new CacheImageKey)
    val debug_state = Output(UInt(3.W))
    val pending_idx = Output(Valid(UInt(idxBits.W)))
    val pending_sent = Output(Bool())
    val probe_done = Output(Bool())
    val done = Output(Valid(new CacheImageKey))
    val done_epoch = Output(UInt(16.W))
    val owner_epoch = Input(UInt(16.W))
    val image_generation = Input(UInt(32.W))
    val image_valid = Input(Bool())
    val packet_seq = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val packet_tracked = Input(Bool())
    val active_packet_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val active_packet_tracked = Output(Bool())
    val snapshot_valid = Output(Bool())
    val snapshot_ready = Input(Bool())
    val snapshot_line = Output(UInt(coreMaxAddrBits.W))
    val snapshot_key = Output(new CacheImageKey)
    val snapshot_epoch = Output(UInt(16.W))
    val snapshot_param = Output(UInt(TLPermissions.cWidth.W))
    val snapshot_data = Output(Vec(refillCycles, UInt(encRowBits.W)))
    val release = Decoupled(new TLBundleC(edge.bundle))
    val lsu_release = Decoupled(new TLBundleC(edge.bundle))
  })

  val req = Reg(new WritebackReq(edge.bundle))
  val reqIsMshr = RegInit(false.B)
  val snapshotKey = Reg(new CacheImageKey)
  val snapshotEpoch = Reg(UInt(16.W))
  val snapshotGeneration = Reg(UInt(32.W))
  val snapshotImageValid = Reg(Bool())
  dontTouch(snapshotEpoch); dontTouch(snapshotGeneration); dontTouch(snapshotImageValid)
  val s_invalid :: s_fill_buffer :: s_lsu_release :: s_active :: s_capture_hold :: Nil = Enum(5)
  val state = RegInit(s_invalid)
  io.debug_state := state
  val r1_data_req_fired = RegInit(false.B)
  val r2_data_req_fired = RegInit(false.B)
  val r1_data_req_cnt = Reg(UInt(log2Up(refillCycles+1).W))
  val r2_data_req_cnt = Reg(UInt(log2Up(refillCycles+1).W))
  val data_req_cnt = RegInit(0.U(log2Up(refillCycles+1).W))
  val (_, last_beat, all_beats_done, beat_count) = edge.count(io.release)
  val wb_buffer = Reg(Vec(refillCycles, UInt(encRowBits.W)))
  val snapshotValid = RegInit(false.B)
  io.snapshot_valid := snapshotValid
  io.snapshot_line := (Cat(req.tag, req.idx) << blockOffBits).pad(coreMaxAddrBits)
  io.snapshot_key := snapshotKey
  io.snapshot_epoch := snapshotEpoch
  io.snapshot_param := req.param
  io.snapshot_data := wb_buffer
  when (snapshotValid && io.snapshot_ready) { snapshotValid := false.B }
  // The data buffer can service probes while the single voluntary source
  // waits for D. Never reuse that source/receipt until its ACK is consumed.
  val ackPending = RegInit(false.B)
  val allSent = RegInit(false.B)
  val acked = RegInit(false.B)
  val pendingKey = Reg(new CacheImageKey)
  val pendingEpoch = Reg(UInt(16.W))
  val pendingIdx = Reg(UInt(idxBits.W))
  val pendingIsSvb = RegInit(false.B)
  val pendingEntry = Reg(UInt(log2Ceil(svbEntries).W))
  val pendingLine = Reg(UInt(coreMaxAddrBits.W))
  io.pending_svb := ackPending && pendingIsSvb
  io.pending_entry := pendingEntry
  io.pending_line := pendingLine
  io.pending_key := pendingKey
  io.pending_idx.valid := ackPending
  io.pending_idx.bits := pendingIdx
  io.pending_sent := ackPending && allSent
  io.probe_done := false.B
  val receiptDone = ackPending && allSent && acked
  io.done.valid := receiptDone && !pendingIsSvb
  io.svb_done.valid := receiptDone && pendingIsSvb
  io.svb_done.bits.entry := pendingEntry
  io.svb_done.bits.key := pendingKey
  io.svb_release_done := false.B
  io.done.bits := pendingKey
  io.done_epoch := pendingEpoch
  when (io.mem_grant) {
    assert(ackPending, "WB ACK without source owner")
    assert(allSent && !acked, "WB receipt before full C transfer or duplicate receipt")
    acked := true.B
  }
  when (receiptDone) { ackPending := false.B }

  val packet_seq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val packet_tracked = RegInit(false.B)
  io.active_packet_seq := packet_seq
  io.active_packet_tracked := packet_tracked

  io.idx.valid       := state =/= s_invalid
  io.idx.bits        := req.idx
  io.release.valid   := false.B
  io.release.bits    := DontCare
  io.req.ready       := false.B
  io.svb_req.ready := false.B
  io.meta_read.valid := false.B
  io.meta_read.bits  := DontCare
  io.data_req.valid  := false.B
  io.data_req.bits   := DontCare
  io.resp            := false.B
  io.lsu_release.valid := false.B
  io.lsu_release.bits := DontCare


  val r_address = Cat(req.tag, req.idx) << blockOffBits
  val id = cfg.nMSHRs
  val probeResponse = edge.ProbeAck(
                          fromSource = id.U,
                          toAddress = r_address,
                          lgSize = lgCacheBlockBytes.U,
                          reportPermissions = req.param,
                          data = wb_buffer(data_req_cnt))

  val voluntaryRelease = edge.Release(
                          fromSource = id.U,
                          toAddress = r_address,
                          lgSize = lgCacheBlockBytes.U,
                          shrinkPermissions = req.param,
                          data = wb_buffer(data_req_cnt))._2


  probeResponse.user.lift(CacheImage).foreach(_ := snapshotKey)
  voluntaryRelease.user.lift(CacheImage).foreach(_ := snapshotKey)

  when (state === s_invalid) {
    io.req.ready := !io.req.bits.voluntary || !ackPending
    // Existing probe/MSHR/capture/fallback arbitration retains priority.
    // Both voluntary producers acquire the same receipt before any C beat.
    io.svb_req.ready := !ackPending && !io.req.valid
    when (io.req.fire) {
      state := s_fill_buffer
      data_req_cnt := 0.U
      req := io.req.bits
      reqIsMshr := io.req_is_mshr
      snapshotKey := io.image_key
      when (io.req.bits.voluntary) {
        ackPending := true.B
        allSent := false.B
        acked := false.B
        pendingKey := io.image_key
        pendingEpoch := io.owner_epoch
        pendingIdx := io.req.bits.idx
        pendingIsSvb := false.B
        pendingLine := (Cat(io.req.bits.tag, io.req.bits.idx) << blockOffBits).pad(coreMaxAddrBits)
      }
      snapshotEpoch := io.owner_epoch
      snapshotGeneration := io.image_generation
      snapshotImageValid := io.image_valid
      packet_seq := io.packet_seq
      packet_tracked := io.packet_tracked
    }
    when (io.svb_req.fire) {
      assert(!ackPending && !io.req.fire, "SVB source allocation while busy")
      state := s_active
      data_req_cnt := 0.U
      req := 0.U.asTypeOf(new WritebackReq(edge.bundle))
      req.voluntary := true.B
      req.source := id.U
      req.tag := io.svb_req.bits.line >> untagBits
      req.idx := io.svb_req.bits.line(idxMSB, idxLSB)
      req.param := io.svb_req.bits.param
      reqIsMshr := false.B
      wb_buffer := io.svb_req.bits.data
      snapshotKey := io.svb_req.bits.key
      snapshotEpoch := io.svb_req.bits.epoch
      ackPending := true.B
      allSent := false.B
      acked := false.B
      pendingKey := io.svb_req.bits.key
      pendingEpoch := io.svb_req.bits.epoch
      pendingIdx := io.svb_req.bits.line(idxMSB, idxLSB)
      pendingLine := io.svb_req.bits.line
      pendingIsSvb := true.B
      pendingEntry := io.svb_req.bits.entry
      packet_seq := io.svb_req.bits.key.contentSeq
      packet_tracked := io.svb_req.bits.key.valid
      // Snapshot is already buffered: do not read/invalidate the younger L1
      // image, and do not produce an MSHR row-reader completion.
    }
  } .elsewhen (state === s_fill_buffer) {
    io.meta_read.valid := data_req_cnt < refillCycles.U
    io.meta_read.bits.idx := req.idx
    io.meta_read.bits.tag := req.tag

    io.data_req.valid := data_req_cnt < refillCycles.U
    io.data_req.bits.way_en := req.way_en
    io.data_req.bits.addr := (if(refillCycles > 1)
                              Cat(req.idx, data_req_cnt(log2Up(refillCycles)-1,0))
                            else req.idx) << rowOffBits

    r1_data_req_fired := false.B
    r1_data_req_cnt   := 0.U
    r2_data_req_fired := r1_data_req_fired
    r2_data_req_cnt   := r1_data_req_cnt
    when (io.data_req.fire && io.meta_read.fire) {
      r1_data_req_fired := true.B
      r1_data_req_cnt   := data_req_cnt
      data_req_cnt := data_req_cnt + 1.U
    }
    when (r2_data_req_fired) {
      wb_buffer(r2_data_req_cnt) := io.data_resp
      when (r2_data_req_cnt === (refillCycles-1).U) {
        io.resp := reqIsMshr
        when (req.svb_capture) {
          snapshotValid := true.B
          state := s_capture_hold
        }.otherwise {
          state := s_lsu_release
        }
        data_req_cnt := 0.U
      }
    }
  } .elsewhen (state === s_lsu_release) {
    io.lsu_release.valid := true.B
    io.lsu_release.bits := probeResponse
    when (io.lsu_release.fire) {
     state := s_active
    }
  } .elsewhen (state === s_active) {
    io.release.valid := data_req_cnt < refillCycles.U
    io.release.bits := Mux(req.voluntary, voluntaryRelease, probeResponse)
    io.release.bits.user.lift(CacheImage).foreach(_ := snapshotKey)

    when (io.release.fire) {
      data_req_cnt := data_req_cnt + 1.U
    }
    when ((data_req_cnt === (refillCycles-1).U) && io.release.fire) {
      when (req.voluntary) {
        allSent := true.B
        io.svb_release_done := pendingIsSvb
      }
      .otherwise { io.probe_done := true.B }
      state := s_invalid
    }
  } .elsewhen (state === s_capture_hold) {
    // Hold the snapshot until the SVB accepts it.  This is the atomicity
    // boundary: the producer cannot be reused and the predecessor cannot be
    // overwritten before the full line has a durable SVB owner.
    when (snapshotValid && io.snapshot_ready) {
      state := s_invalid
    }
  }

  when (io.req.fire && io.req.bits.voluntary) {
    assert(!ackPending, "normal WB allocated a busy release source")
  }
  when (io.release.fire && req.voluntary) {
    assert(ackPending && !allSent && !acked, "C Release without exclusive source owner")
    assert(snapshotKey.asUInt === pendingKey.asUInt && r_address === pendingLine,
      "C Release identity differs from reserved receipt")
  }
  assert(!(io.done.valid && io.svb_done.valid), "normal and SVB completion overlap")

}

class BoomProbeUnit(implicit edge: TLEdgeOut, p: Parameters) extends L1HellaCacheModule()(p) {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new TLBundleB(edge.bundle)))
    val rep = Decoupled(new TLBundleC(edge.bundle))
    val meta_read = Decoupled(new L1MetaReadReq)
    val meta_write = Decoupled(new L1MetaWriteReq)
    val wb_req = Decoupled(new WritebackReq(edge.bundle))
    val way_en = Input(UInt(nWays.W))
    val wb_rdy = Input(Bool()) // Is writeback unit currently busy? If so need to retry meta read when its done
    val wb_done = Input(Bool()) // Last ProbeAckData C beat was accepted.
    val mshr_rdy = Input(Bool()) // Is MSHR ready for this request to proceed?
    val mshr_wb_rdy = Output(Bool()) // Should we block MSHR writebacks while we finish our own?
    val block_state = Input(new ClientMetadata())
    val lsu_release = Decoupled(new TLBundleC(edge.bundle))

    val state = Output(Valid(UInt(coreMaxAddrBits.W)))
    val diagnosticState = Output(UInt(4.W))
  })

  val (s_invalid :: s_meta_read :: s_meta_resp :: s_mshr_req ::
       s_mshr_resp :: s_lsu_release :: s_release :: s_writeback_req :: s_writeback_resp ::
       s_meta_write :: s_meta_write_resp :: Nil) = Enum(11)
  val state = RegInit(s_invalid)

  val req = Reg(new TLBundleB(edge.bundle))
  val req_idx = req.address(idxMSB, idxLSB)
  val req_tag = req.address >> untagBits

  val way_en = Reg(UInt())
  val tag_matches = way_en.orR
  val old_coh = Reg(new ClientMetadata)
  val miss_coh = ClientMetadata.onReset
  val reply_coh = Mux(tag_matches, old_coh, miss_coh)
  val (is_dirty, report_param, new_coh) = reply_coh.onProbe(req.param)

  io.state.valid := state =/= s_invalid
  io.state.bits  := req.address
  io.diagnosticState := state

  io.req.ready := state === s_invalid
  io.rep.valid := state === s_release
  io.rep.bits := CacheImage.base(edge.ProbeAck(req, report_param))

  assert(!io.rep.valid || !edge.hasData(io.rep.bits),
    "ProbeUnit should not send ProbeAcks with data, WritebackUnit should handle it")

  io.meta_read.valid := state === s_meta_read
  io.meta_read.bits.idx := req_idx
  io.meta_read.bits.tag := req_tag
  io.meta_read.bits.way_en := ~(0.U(nWays.W))

  io.meta_write.valid := state === s_meta_write
  io.meta_write.bits.way_en := way_en
  io.meta_write.bits.idx := req_idx
  io.meta_write.bits.tag := req_tag
  io.meta_write.bits.data.tag := req_tag
  io.meta_write.bits.data.coh := new_coh

  io.wb_req.valid := state === s_writeback_req
  io.wb_req.bits.source := req.source
  io.wb_req.bits.idx := req_idx
  io.wb_req.bits.tag := req_tag
  io.wb_req.bits.param := report_param
  io.wb_req.bits.way_en := way_en
  io.wb_req.bits.voluntary := false.B
  io.wb_req.bits.svb_capture := false.B
  when (io.wb_done) { assert(state === s_writeback_resp, "orphan ProbeAckData completion") }


  io.mshr_wb_rdy := !state.isOneOf(s_release, s_writeback_req, s_writeback_resp, s_meta_write, s_meta_write_resp)

  io.lsu_release.valid := state === s_lsu_release
  io.lsu_release.bits  := CacheImage.base(edge.ProbeAck(req, report_param))

  // state === s_invalid
  when (state === s_invalid) {
    when (io.req.fire) {
      state := s_meta_read
      req := io.req.bits
    }
  } .elsewhen (state === s_meta_read) {
    when (io.meta_read.fire) {
      state := s_meta_resp
    }
  } .elsewhen (state === s_meta_resp) {
    // we need to wait one cycle for the metadata to be read from the array
    state := s_mshr_req
  } .elsewhen (state === s_mshr_req) {
    old_coh := io.block_state
    way_en := io.way_en
    // if the read didn't go through, we need to retry
    state := Mux(io.mshr_rdy && io.wb_rdy, s_mshr_resp, s_meta_read)
  } .elsewhen (state === s_mshr_resp) {
    state := Mux(tag_matches && is_dirty, s_writeback_req, s_lsu_release)
  } .elsewhen (state === s_lsu_release) {
    when (io.lsu_release.fire) {
      state := s_release
    }
  } .elsewhen (state === s_release) {
    when (io.rep.ready) {
      state := Mux(tag_matches, s_meta_write, s_invalid)
    }
  } .elsewhen (state === s_writeback_req) {
    when (io.wb_req.fire) {
      state := s_writeback_resp
    }
  } .elsewhen (state === s_writeback_resp) {
    // wait for the writeback request to finish before updating the metadata
    when (io.wb_done) {
      state := s_meta_write
    }
  } .elsewhen (state === s_meta_write) {
    when (io.meta_write.fire) {
      state := s_meta_write_resp
    }
  } .elsewhen (state === s_meta_write_resp) {
    state := s_invalid
  }
}

class BoomL1MetaReadReq(implicit p: Parameters) extends BoomBundle()(p) {
  val req = Vec(memWidth, new L1MetaReadReq)
}

class BoomL1DataReadReq(implicit p: Parameters) extends BoomBundle()(p) {
  val req = Vec(memWidth, new L1DataReadReq)
  val valid = Vec(memWidth, Bool())
}

abstract class AbstractBoomDataArray(implicit p: Parameters) extends BoomModule with HasL1HellaCacheParameters {
  val io = IO(new BoomBundle {
    val read  = Input(Vec(memWidth, Valid(new L1DataReadReq)))
    val write = Input(Valid(new L1DataWriteReq))
    val resp  = Output(Vec(memWidth, Vec(nWays, Bits(encRowBits.W))))
    val nacks = Output(Vec(memWidth, Bool()))
  })

  def pipeMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))

}

class BoomDuplicatedDataArray(implicit p: Parameters) extends AbstractBoomDataArray
{

  val waddr = io.write.bits.addr >> rowOffBits
  for (j <- 0 until memWidth) {

    val raddr = io.read(j).bits.addr >> rowOffBits
    for (w <- 0 until nWays) {
      val array = DescribedSRAM(
        name = s"array_${w}_${j}",
        desc = "Non-blocking DCache Data Array",
        size = nSets * refillCycles,
        data = Vec(rowWords, Bits(encDataBits.W))
      )
      when (io.write.bits.way_en(w) && io.write.valid) {
        val data = VecInit((0 until rowWords) map (i => io.write.bits.data(encDataBits*(i+1)-1,encDataBits*i)))
        array.write(waddr, data, io.write.bits.wmask.asBools)
      }
      io.resp(j)(w) := RegNext(array.read(raddr, io.read(j).bits.way_en(w) && io.read(j).valid).asUInt)
    }
    io.nacks(j) := false.B
  }
}

class BoomBankedDataArray(implicit p: Parameters) extends AbstractBoomDataArray {

  val nBanks   = boomParams.numDCacheBanks
  val bankSize = nSets * refillCycles / nBanks
  require (nBanks >= memWidth)
  require (bankSize > 0)

  val bankBits    = log2Ceil(nBanks)
  val bankOffBits = log2Ceil(rowWords) + log2Ceil(wordBytes)
  val bidxBits    = log2Ceil(bankSize)
  val bidxOffBits = bankOffBits + bankBits

  //----------------------------------------------------------------------------------------------------

  val s0_rbanks = if (nBanks > 1) VecInit(io.read.map(r => (r.bits.addr >> bankOffBits)(bankBits-1,0))) else VecInit(0.U)
  val s0_wbank  = if (nBanks > 1) (io.write.bits.addr >> bankOffBits)(bankBits-1,0) else 0.U
  val s0_ridxs  = VecInit(io.read.map(r => (r.bits.addr >> bidxOffBits)(bidxBits-1,0)))
  val s0_widx   = (io.write.bits.addr >> bidxOffBits)(bidxBits-1,0)

  val s0_read_valids    = VecInit(io.read.map(_.valid))
  val s0_bank_conflicts = pipeMap(w => (0 until w).foldLeft(false.B)((c,i) => c || io.read(i).valid && s0_rbanks(i) === s0_rbanks(w)))
  val s0_do_bank_read   = s0_read_valids zip s0_bank_conflicts map {case (v,c) => v && !c}
  val s0_bank_read_gnts = Transpose(VecInit(s0_rbanks zip s0_do_bank_read map {case (b,d) => VecInit((UIntToOH(b) & Fill(nBanks,d)).asBools)}))
  val s0_bank_write_gnt = (UIntToOH(s0_wbank) & Fill(nBanks, io.write.valid)).asBools

  //----------------------------------------------------------------------------------------------------

  val s1_rbanks         = RegNext(s0_rbanks)
  val s1_ridxs          = RegNext(s0_ridxs)
  val s1_read_valids    = RegNext(s0_read_valids)
  val s1_pipe_selection = pipeMap(i => VecInit(PriorityEncoderOH(pipeMap(j =>
                            if (j < i) s1_read_valids(j) && s1_rbanks(j) === s1_rbanks(i)
                            else if (j == i) true.B else false.B))))
  val s1_ridx_match     = pipeMap(i => pipeMap(j => if (j < i) s1_ridxs(j) === s1_ridxs(i)
                                                    else if (j == i) true.B else false.B))
  val s1_nacks          = pipeMap(w => s1_read_valids(w) && (s1_pipe_selection(w).asUInt & ~s1_ridx_match(w).asUInt).orR)
  val s1_bank_selection = pipeMap(w => Mux1H(s1_pipe_selection(w), s1_rbanks))

  //----------------------------------------------------------------------------------------------------

  val s2_bank_selection = RegNext(s1_bank_selection)
  val s2_nacks          = RegNext(s1_nacks)

  for (w <- 0 until nWays) {
    val s2_bank_reads = Reg(Vec(nBanks, Bits(encRowBits.W)))

    for (b <- 0 until nBanks) {
      val array = DescribedSRAM(
        name = s"array_${w}_${b}",
        desc = "Non-blocking DCache Data Array",
        size = bankSize,
        data = Vec(rowWords, Bits(encDataBits.W))
      )
      val ridx = Mux1H(s0_bank_read_gnts(b), s0_ridxs)
      val way_en = Mux1H(s0_bank_read_gnts(b), io.read.map(_.bits.way_en))
      s2_bank_reads(b) := array.read(ridx, way_en(w) && s0_bank_read_gnts(b).reduce(_||_)).asUInt

      when (io.write.bits.way_en(w) && s0_bank_write_gnt(b)) {
        val data = VecInit((0 until rowWords) map (i => io.write.bits.data(encDataBits*(i+1)-1,encDataBits*i)))
        array.write(s0_widx, data, io.write.bits.wmask.asBools)
      }
    }

    for (i <- 0 until memWidth) {
      io.resp(i)(w) := s2_bank_reads(s2_bank_selection(i))
    }
  }

  io.nacks := s2_nacks
}

/**
 * Top level class wrapping a non-blocking dcache.
 *
 * @param hartid hardware thread for the cache
 */
class BoomNonBlockingDCache(staticIdForMetadataUseOnly: Int)(implicit p: Parameters) extends LazyModule
{
  val staticImageWriter = staticIdForMetadataUseOnly
  private val tileParams = p(TileKey)
  protected val cfg = tileParams.dcache.get

  protected def cacheClientParameters = cfg.scratch.map(x => Seq()).getOrElse(Seq(TLMasterParameters.v1(
    name          = s"Core ${staticIdForMetadataUseOnly} DCache",
    sourceId      = IdRange(0, 1 max (cfg.nMSHRs + 1)),
    supportsProbe = TransferSizes(cfg.blockBytes, cfg.blockBytes))))

  protected def mmioClientParameters = Seq(TLMasterParameters.v1(
    name          = s"Core ${staticIdForMetadataUseOnly} DCache MMIO",
    sourceId      = IdRange(cfg.nMSHRs + 1, cfg.nMSHRs + 1 + cfg.nMMIOs),
    requestFifo   = true))

  val node = new TLClientNode(Seq(TLMasterPortParameters.v1(
    cacheClientParameters ++ mmioClientParameters,
    minLatency = 1,
    requestFields = Seq(CacheImageField()),
    responseKeys = Seq(CacheImage)))) with CacheImageClient


  lazy val module = new BoomNonBlockingDCacheModule(this)

  def flushOnFenceI = cfg.scratch.isEmpty && !node.edges.out(0).manager.managers.forall(m => !m.supportsAcquireT || !m.executable || m.regionType >= RegionType.TRACKED || m.regionType <= RegionType.IDEMPOTENT)

  require(!tileParams.core.haveCFlush || cfg.scratch.isEmpty, "CFLUSH_D_L1 instruction requires a D$")
}


class BoomDCacheBundle(implicit p: Parameters, edge: TLEdgeOut) extends BoomBundle()(p) {
  val errors = new DCacheErrors
  val lsu   = Flipped(new LSUDMemIO)
  // BOOM R_IC 的 fsm_check 状态。流量计数器只统计该状态下的访存。
  val traffic_check_state = Input(Bool())
  val traffic_reset = Input(Bool())
  val traffic_start = Input(Bool())
  val traffic_stop = Input(Bool())
  val csr_cycle = Input(UInt(64.W))
  val traffic_counter = Output(Vec(GH_GlobalParams.GH_TRAFFIC_COUNTERS, UInt(64.W)))
  val packet_alloc_valid = Input(Bool())
  val packet_alloc_seq = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val packet_seq_baseline = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val checker_results = Input(Vec(GH_GlobalParams.GH_NUM_CORES - GH_GlobalParams.GH_NUM_BIG_CORES,
    UInt(GH_GlobalParams.GH_CHECKER_RESULT_BITS.W)))
}

class BoomNonBlockingDCacheModule(outer: BoomNonBlockingDCache) extends LazyModuleImp(outer)
  with HasL1HellaCacheParameters
  with HasBoomCoreParameters
{
  implicit val edge = outer.node.edges.out(0)
  val (tl_out, _) = outer.node.out(0)
  val io = IO(new BoomDCacheBundle)
  require(tl_out.c.bits.user.lift(CacheImage).nonEmpty && tl_out.d.bits.user.lift(CacheImage).nonEmpty,
    "L1 preservation requires a lower cache that negotiates CacheImage and commit-time ReleaseAck")
  require(outer.staticImageWriter >= 0 && outer.staticImageWriter < 65536)

  val trafficEnabled = RegInit(false.B)
  when (io.traffic_reset) {
    trafficEnabled := false.B
  }.elsewhen (io.traffic_start) {
    trafficEnabled := true.B
  }.elsewhen (io.traffic_stop) {
    trafficEnabled := false.B
  }
  // Include events accepted on the STOP edge. trafficEnabled is cleared by
  // that edge, so subsequent cycles are outside the measurement window.
  val trafficCounting = (trafficEnabled || io.traffic_start) && !io.traffic_reset
  BoringUtils.addSource(io.traffic_reset, GH_GlobalParams.GH_L2_STATS_RESET_BORE)
  BoringUtils.addSource(trafficCounting, GH_GlobalParams.GH_L2_STATS_ENABLE_BORE)
  val trafficStopPrev = RegNext(io.traffic_stop, false.B)
  val trafficStopPulse = io.traffic_stop && !trafficStopPrev

  private val fifoManagers = edge.manager.managers.filter(TLFIFOFixer.allVolatile)
  fifoManagers.foreach { m =>
    require (m.fifoId == fifoManagers.head.fifoId,
      s"IOMSHRs must be FIFO for all regions with effects, but HellaCache sees ${m.nodePath.map(_.name)}")
  }

  def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))

  val t_replay :: t_probe :: t_wb :: t_mshr_meta_read :: t_lsu :: t_prefetch :: Nil = Enum(6)

  val nSVBEntries = p(SVBEntries)
  val wb = Module(new BoomWritebackUnit(nSVBEntries))
  val wbOwnerType = RegInit(0.U(3.W))
  val wbOwnerSource = RegInit(0.U(log2Ceil(cfg.nMSHRs + 1).W))
  // Optimization 4: one shared snapshot reader feeds a bounded global SVB.
  // The normal writeback/probe path remains the fallback when this buffer is
  // full or the event is outside the deliberately narrow fast-path scope.
  val svb = Module(new SpeculativeVersionBuffer(entries = nSVBEntries))
  val svbCapturePending = RegInit(false.B)
  val svbCaptureIssued = RegInit(false.B)
  val svbFastLineValid = RegInit(false.B)
  val svbFastSet = Reg(UInt(idxBits.W))
  val svbFastWay = Reg(UInt(log2Ceil(nWays max 2).W))
  val svbFastTag = Reg(UInt(tagBits.W))
  val svbFastEpoch = Reg(UInt(16.W))
  val svbFastSeq = Reg(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val svbFastKey = Reg(new CacheImageKey)
  val svbFastAcquireCycle = Reg(UInt(64.W))
  val svbFastReleaseCycle = Reg(UInt(64.W))
  val svbFastLine = Wire(UInt(coreMaxAddrBits.W))
  svbFastLine := (Cat(svbFastTag, svbFastSet) << blockOffBits).pad(coreMaxAddrBits)
  val lastLsuProgressCycle = RegInit(0.U(64.W))
  val lastWatermarkProgressCycle = RegInit(0.U(64.W))
  val lastCheckerResultCycle = RegInit(0.U(64.W))
  val lastWbCompletionCycle = RegInit(0.U(64.W))
  val lastProbeCompletionCycle = RegInit(0.U(64.W))
  val lastMshrFreeCycle = RegInit(0.U(64.W))
  val lastSvbCompletionCycle = RegInit(0.U(64.W))
  val svbEpoch = RegInit(0.U(16.W))
  val svbFlush = WireDefault(false.B)
  val svbInvalidate = Wire(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
  svbInvalidate.valid := false.B
  svbInvalidate.bits := 0.U
  svb.io.currentEpoch := svbEpoch
  val svbDiagnosticDump = WireDefault(false.B)
  svb.io.diagnosticDump := svbDiagnosticDump
  svb.io.diagnosticCycle := io.csr_cycle
  svb.io.resetStats := io.traffic_reset
  svb.io.countStats := trafficCounting && !trafficStopPulse
  svb.io.flush := svbFlush
  svb.io.invalidate := svbInvalidate
  svb.io.ack := wb.io.svb_done
  val svbCaptureWbReq = Wire(Decoupled(new WritebackReq(edge.bundle)))
  val prober = Module(new BoomProbeUnit)
  val mshrs = Module(new BoomMSHRFile)
  val dcacheWatchdogSnapshot = WireDefault(false.B)
  BoringUtils.addSink(dcacheWatchdogSnapshot, "EC_PIPELINE_WATCHDOG_SNAPSHOT")
  val dcacheWatchdogSnapshotPrinted = RegInit(false.B)
  when (!dcacheWatchdogSnapshot) { dcacheWatchdogSnapshotPrinted := false.B }
  // Completion feedback for an RPQ entry is generated at the physical L1
  // effect point below.  The request remains owned by its MSHR until then.
  val replayEffectDone = WireDefault(false.B)
  val replayEffectDoneId = WireDefault(0.U(log2Ceil(cfg.nMSHRs max 2).W))
  val replayCancel = WireDefault(false.B)
  val replayCancelId = WireDefault(0.U(log2Ceil(cfg.nMSHRs max 2).W))
  val replayEffectDoneVec = WireDefault(VecInit(Seq.fill(cfg.nMSHRs)(false.B)))
  val replayCancelVec = WireDefault(VecInit(Seq.fill(cfg.nMSHRs)(false.B)))
  mshrs.io.replay_effect_done := replayEffectDone
  mshrs.io.replay_done_id := replayEffectDoneId
  mshrs.io.replay_cancel := replayCancel
  mshrs.io.replay_cancel_id := replayCancelId
  mshrs.io.replay_effect_done_vec := replayEffectDoneVec
  mshrs.io.replay_cancel_vec := replayCancelVec
  mshrs.io.clear_all    := io.lsu.force_order
  mshrs.io.brupdate       := io.lsu.brupdate
  mshrs.io.exception    := io.lsu.exception
  mshrs.io.rob_pnr_idx  := io.lsu.rob_pnr_idx
  mshrs.io.rob_head_idx := io.lsu.rob_head_idx

  // tags
  def onReset = L1Metadata(0.U, ClientMetadata.onReset)
  val meta = Seq.fill(memWidth) { Module(new L1MetadataArray(onReset _)) }
  val metaWriteArb = Module(new Arbiter(new L1MetaWriteReq, 3))
  val dirtyPacketSeq = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))))))
  val dirtyPacketTracked = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(false.B)))))
  // Functional ownership is independent of the measurement shadow above.
  // An epoch changes whenever a resident slot is invalidated/reallocated;
  // generation changes only at an actual local semantic data effect.
  val slotEpoch = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(16.W))))))
  // Mirrors atomic metadata writes for freeze/drain rechecks. Invalidating a
  // victim keeps its identity here until the incoming install commits.
  val residentTag = Reg(Vec(nSets, Vec(nWays, UInt(tagBits.W))))
  val residentCoh = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(ClientMetadata.onReset)))))
  val residentValid = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val lineGeneration = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(32.W))))))
  val appliedEffectValid = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(false.B)))))
  val appliedEffectToken = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(64.W))))))
  val appliedEffectResult = Reg(Vec(nSets, Vec(nWays, UInt(xLen.W))))
  val imageKey = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U.asTypeOf(new CacheImageKey))))))
  val lowerPreserved = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val safePacketWatermark = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  svb.io.safeWatermark := safePacketWatermark
  val imageSerial = RegInit(1.U(32.W))
  val imageValid = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val slotReserved = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val reservedEpoch = Reg(Vec(nSets, Vec(nWays, UInt(16.W))))
  val reservedTransaction = Reg(Vec(nSets, Vec(nWays, UInt(32.W))))
  val reservedMshr = Reg(Vec(nSets, Vec(nWays, UInt(8.W))))
  val reservedNewOwner = Reg(Vec(nSets, Vec(nWays, Bool())))
  val reservedTag = Reg(Vec(nSets, Vec(nWays, UInt(tagBits.W))))
  val installedImage = Reg(Vec(nSets, Vec(nWays, new CacheImageKey)))
  val installActive = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val completionPending = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
  val s3_req = Reg(new BoomDCacheReq)
  val s3_way = Reg(UInt(nWays.W))
  val s3_valid = RegInit(false.B)
  val s3_applied = RegInit(false.B)
  val s3_replay = Reg(Bool())
  val s3_result = Reg(UInt(xLen.W))
  // Observation-only AMO operands retained with the held S3 grant.  The
  // architectural return is s3_result; the physical old/new words let the
  // next run check lane selection and mask independently.
  val s3_old_value = RegInit(0.U(xLen.W))
  val s3_operand = RegInit(0.U(xLen.W))
  val s3_cancelled = RegInit(false.B)
  val s3_effect_fire = WireDefault(false.B)
  val clearFreezeValid = WireDefault(false.B)
  val clearFreezeSet = Wire(UInt(idxBits.W))
  val clearFreezeTag = Wire(UInt(tagBits.W))
  val clearFreezeWay = Wire(UInt(nWays.W))
  // Optimization 1 only relaxes the LSU *entry* during the unsafe WaitSafe
  // phase.  This wire is driven after the pending-state registers below so
  // the ingress path does not need to depend on their declaration order.
  // Snapshot issue, receipt/ACK, metadata clear, and every downstream owner
  // guard continue to use clearFreezeValid without relaxation.
  val clearFreezeReadBypassWindow = WireDefault(false.B)
  val victimDrainReady = WireDefault(true.B)
  val probeDrainReady = WireDefault(true.B)
  val replayPipelineBusy = WireDefault(false.B)
  val completionArb = Module(new Arbiter(new BoomCacheCompletion, 3))
  val completionQ = Module(new Queue(new BoomCacheCompletion, cfg.nMSHRs + nIOMSHRs + 2))
  completionQ.io.enq <> completionArb.io.out
  completionArb.io.in(2) <> mshrs.io.mmio_completion
  val replayResultQ = Seq.fill(cfg.nMSHRs)(Module(new Queue(new BoomCacheCompletion, 2)))
  for (i <- 0 until cfg.nMSHRs) {
    mshrs.io.replay_result(i) <> replayResultQ(i).io.deq
    replayResultQ(i).io.enq.valid := false.B
    replayResultQ(i).io.enq.bits := 0.U.asTypeOf(new BoomCacheCompletion)
  }
  // 0 goes to MSHR refills, 1 goes to prober
  val metaReadArb = Module(new Arbiter(new BoomL1MetaReadReq, 6))
  // 0 goes to MSHR replays, 1 goes to prober, 2 goes to wb, 3 goes to MSHR meta read,
  // 4 goes to pipeline, 5 goes to prefetcher

  metaReadArb.io.in := DontCare
  for (w <- 0 until memWidth) {
    meta(w).io.write.valid := metaWriteArb.io.out.fire
    meta(w).io.write.bits  := metaWriteArb.io.out.bits
    meta(w).io.read.valid  := metaReadArb.io.out.valid
    meta(w).io.read.bits   := metaReadArb.io.out.bits.req(w)
  }
  metaReadArb.io.out.ready  := meta.map(_.io.read.ready).reduce(_||_)
  metaWriteArb.io.out.ready := meta.map(_.io.write.ready).reduce(_||_)
  when (metaWriteArb.io.out.fire) {
    val r = metaWriteArb.io.out.bits
    for (way <- 0 until nWays) {
      when (r.way_en(way)) {
        residentValid(r.idx)(way) := r.data.coh.isValid()
        residentCoh(r.idx)(way) := r.data.coh
        when (r.data.coh.isValid()) { residentTag(r.idx)(way) := r.data.tag }
      }
    }
  }

  // data
  val data = Module(if (boomParams.numDCacheBanks == 1) new BoomDuplicatedDataArray else new BoomBankedDataArray)
  val dataWriteArb = Module(new Arbiter(new L1DataWriteReq, 2))
  // 0 goes to pipeline, 1 goes to MSHR refills
  val dataReadArb = Module(new Arbiter(new BoomL1DataReadReq, 3))
  // 0 goes to MSHR replays, 1 goes to wb, 2 goes to pipeline
  dataReadArb.io.in := DontCare

  for (w <- 0 until memWidth) {
    data.io.read(w).valid := dataReadArb.io.out.bits.valid(w) && dataReadArb.io.out.valid
    data.io.read(w).bits  := dataReadArb.io.out.bits.req(w)
  }
  dataReadArb.io.out.ready := true.B

  data.io.write.valid := dataWriteArb.io.out.fire
  data.io.write.bits  := dataWriteArb.io.out.bits
  dataWriteArb.io.out.ready := true.B

  // ------------
  // New requests

  // If an older S2 store fails while a younger store is already resident in
  // S1, the normal pipeline kill below would otherwise lose that request.
  // Keep one complete request and replay it through the normal LSU path.
  val killed_store_replay_valid = RegInit(false.B)
  val killed_store_replay_req = Reg(new BoomDCacheReq)
  val killed_store_replay_reqs = Wire(Vec(memWidth, new BoomDCacheReq))
  killed_store_replay_reqs := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  killed_store_replay_reqs(0) := killed_store_replay_req
  // A protected predecessor still excludes every same-line request, every
  // store/AMO/LR/SC/MMIO request, and all traffic after WaitSafe closes.  The
  // sole new admission class is an ordinary cacheable different-line load.
  // Its S2 lookup is explicitly hit-only below: a permission miss or cache
  // miss is nacked before it can allocate an MSHR, choose a victim, or reserve
  // any way in the protected set.
  val lsu_clear_freeze_read_bypass_lane = Wire(Vec(memWidth, Bool()))
  for (w <- 0 until memWidth) {
    val r = io.lsu.req.bits(w)
    lsu_clear_freeze_read_bypass_lane(w) := clearFreezeReadBypassWindow &&
      r.valid && r.bits.addr(idxMSB, idxLSB) === clearFreezeSet &&
      (r.bits.addr >> untagBits) =/= clearFreezeTag &&
      !slotReserved(clearFreezeSet).asUInt.orR &&
      !(prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === clearFreezeSet) &&
      edge.manager.supportsAcquireBFast(r.bits.addr, lgCacheBlockBytes.U) &&
      r.bits.uop.mem_cmd === M_XRD && r.bits.uop.uses_ldq && !r.bits.uop.uses_stq &&
      !r.bits.is_hella
  }
  val lsu_clear_freeze_read_bypass_any = lsu_clear_freeze_read_bypass_lane.asUInt.orR
  val lsu_clear_freeze_set_conflict = clearFreezeValid &&
    (0 until memWidth).map(w => io.lsu.req.bits(w).valid &&
      io.lsu.req.bits(w).bits.addr(idxMSB, idxLSB) === clearFreezeSet &&
      !lsu_clear_freeze_read_bypass_lane(w)).reduce(_ || _)
  val killed_replay_clear_freeze_set_conflict = clearFreezeValid &&
    killed_store_replay_valid &&
    killed_store_replay_req.addr(idxMSB, idxLSB) === clearFreezeSet
  val lsu_pipeline_ready = metaReadArb.io.in(4).ready && dataReadArb.io.in(2).ready
  val killed_store_replay_fire = killed_store_replay_valid && lsu_pipeline_ready &&
    !killed_replay_clear_freeze_set_conflict

  // A metadata clear writes one way but must drain all lookups to its set.
  // WaitSafe permits only the qualified hit-only reads above; all same-set
  // LSU traffic is held outside S1/S2 once the safe/clear boundary begins.
  val lsu_clear_freeze_allowed = !killed_store_replay_valid &&
    !lsu_clear_freeze_set_conflict
  val killed_replay_clear_freeze_allowed = !killed_replay_clear_freeze_set_conflict
  io.lsu.req.ready := lsu_clear_freeze_allowed && lsu_pipeline_ready
  metaReadArb.io.in(4).valid :=
    (io.lsu.req.valid && lsu_clear_freeze_allowed) ||
    (killed_store_replay_valid && killed_replay_clear_freeze_allowed)
  dataReadArb.io.in(2).valid :=
    (io.lsu.req.valid && lsu_clear_freeze_allowed) ||
    (killed_store_replay_valid && killed_replay_clear_freeze_allowed)
  for (w <- 0 until memWidth) {
    // Tag read for new requests
    metaReadArb.io.in(4).bits.req(w).idx := Mux(
      killed_store_replay_valid,
      killed_store_replay_req.addr >> blockOffBits,
      io.lsu.req.bits(w).bits.addr >> blockOffBits)
    metaReadArb.io.in(4).bits.req(w).way_en := DontCare
    metaReadArb.io.in(4).bits.req(w).tag    := DontCare
    // Data read for new requests
    dataReadArb.io.in(2).bits.valid(w) := Mux(
      killed_store_replay_valid, (w == 0).B, io.lsu.req.bits(w).valid)
    dataReadArb.io.in(2).bits.req(w).addr := Mux(
      killed_store_replay_valid, killed_store_replay_req.addr,
      io.lsu.req.bits(w).bits.addr)
    dataReadArb.io.in(2).bits.req(w).way_en := ~0.U(nWays.W)
  }

  // ------------
  // MSHR Replays
  val replay_req = Wire(Vec(memWidth, new BoomDCacheReq))
  replay_req := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  BoomDCacheReq.copyBase(replay_req(0), mshrs.io.replay.bits)
  mshrs.io.replay.ready    := metaReadArb.io.in(0).ready && dataReadArb.io.in(0).ready &&
    !replayPipelineBusy && !s3_valid && completionQ.io.count === 0.U
  // Tag read for MSHR replays
  // We don't actually need to read the metadata, for replays we already know our way
  metaReadArb.io.in(0).valid              := mshrs.io.replay.valid && !replayPipelineBusy && !s3_valid && completionQ.io.count === 0.U
  metaReadArb.io.in(0).bits.req(0).idx    := mshrs.io.replay.bits.addr >> blockOffBits
  metaReadArb.io.in(0).bits.req(0).way_en := DontCare
  metaReadArb.io.in(0).bits.req(0).tag    := DontCare
  // Data read for MSHR replays
  dataReadArb.io.in(0).valid              := mshrs.io.replay.valid && !replayPipelineBusy && !s3_valid && completionQ.io.count === 0.U
  dataReadArb.io.in(0).bits.req(0).addr   := mshrs.io.replay.bits.addr
  dataReadArb.io.in(0).bits.req(0).way_en := mshrs.io.replay.bits.way_en
  dataReadArb.io.in(0).bits.valid         := widthMap(w => (w == 0).B)

  // -----------
  // MSHR Meta read
  val mshr_read_req = Wire(Vec(memWidth, new BoomDCacheReq))
  mshr_read_req             := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  mshr_read_req(0).uop      := NullMicroOp
  mshr_read_req(0).addr     := Cat(mshrs.io.meta_read.bits.tag, mshrs.io.meta_read.bits.idx) << blockOffBits
  mshr_read_req(0).data     := DontCare
  mshr_read_req(0).is_hella := false.B
  metaReadArb.io.in(3).valid       := mshrs.io.meta_read.valid
  metaReadArb.io.in(3).bits.req(0) := mshrs.io.meta_read.bits
  mshrs.io.meta_read.ready         := metaReadArb.io.in(3).ready



  // -----------
  // Write-backs
  val wb_fire = wb.io.meta_read.fire && wb.io.data_req.fire
  val wb_req = Wire(Vec(memWidth, new BoomDCacheReq))
  wb_req             := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  wb_req(0).uop      := NullMicroOp
  wb_req(0).addr     := Cat(wb.io.meta_read.bits.tag, wb.io.data_req.bits.addr)
  wb_req(0).data     := DontCare
  wb_req(0).is_hella := false.B
  // Couple the two decoupled interfaces of the WBUnit's meta_read and data_read
  // Tag read for write-back
  metaReadArb.io.in(2).valid        := wb.io.meta_read.valid
  metaReadArb.io.in(2).bits.req(0)  := wb.io.meta_read.bits
  wb.io.meta_read.ready := metaReadArb.io.in(2).ready && dataReadArb.io.in(1).ready
  // Data read for write-back
  dataReadArb.io.in(1).valid        := wb.io.data_req.valid
  dataReadArb.io.in(1).bits.req(0)  := wb.io.data_req.bits
  dataReadArb.io.in(1).bits.valid   := widthMap(w => (w == 0).B)
  wb.io.data_req.ready  := metaReadArb.io.in(2).ready && dataReadArb.io.in(1).ready
  assert(!(wb.io.meta_read.fire ^ wb.io.data_req.fire))

  // -------
  // Prober
  val prober_fire  = prober.io.meta_read.fire
  val prober_req   = Wire(Vec(memWidth, new BoomDCacheReq))
  prober_req             := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  prober_req(0).uop      := NullMicroOp
  prober_req(0).addr     := Cat(prober.io.meta_read.bits.tag, prober.io.meta_read.bits.idx) << blockOffBits
  prober_req(0).data     := DontCare
  prober_req(0).is_hella := false.B
  // Tag read for prober
  metaReadArb.io.in(1).valid       := prober.io.meta_read.valid
  metaReadArb.io.in(1).bits.req(0) := prober.io.meta_read.bits
  prober.io.meta_read.ready := metaReadArb.io.in(1).ready
  // Prober does not need to read data array

  // -------
  // Prefetcher
  val prefetch_fire = mshrs.io.prefetch.fire
  val prefetch_req  = Wire(Vec(memWidth, new BoomDCacheReq))
  prefetch_req    := 0.U.asTypeOf(Vec(memWidth, new BoomDCacheReq))
  prefetch_req(0) := mshrs.io.prefetch.bits
  // Tag read for prefetch
  metaReadArb.io.in(5).valid              := mshrs.io.prefetch.valid
  metaReadArb.io.in(5).bits.req(0).idx    := mshrs.io.prefetch.bits.addr >> blockOffBits
  metaReadArb.io.in(5).bits.req(0).way_en := DontCare
  metaReadArb.io.in(5).bits.req(0).tag    := DontCare
  mshrs.io.prefetch.ready := metaReadArb.io.in(5).ready
  // Prefetch does not need to read data array

  val s0_valid = Mux(io.lsu.req.fire, VecInit(io.lsu.req.bits.map(_.valid)),
                 Mux(killed_store_replay_fire, VecInit(1.U(memWidth.W).asBools),
                 Mux(mshrs.io.replay.fire || wb_fire || prober_fire || prefetch_fire || mshrs.io.meta_read.fire,
                                        VecInit(1.U(memWidth.W).asBools), VecInit(0.U(memWidth.W).asBools))))
  val s0_selected_req = Mux(io.lsu.req.fire, VecInit(io.lsu.req.bits.map(_.bits)),
            Mux(killed_store_replay_fire, killed_store_replay_reqs,
            Mux(wb_fire                  , wb_req,
            Mux(prober_fire              , prober_req,
            Mux(prefetch_fire            , prefetch_req,
            Mux(mshrs.io.meta_read.fire, mshr_read_req
                                             , replay_req))))))
  val s0_req = Wire(Vec(memWidth, new BoomDCacheReq))
  s0_req := s0_selected_req
  // LSU 已按 LDQ/STQ 项锁存统计资格；DCache 只补充地址管理器给出的
  // 可缓存属性，并让两者随 MSHR/refill/replay 一直传播到完成点。
  when (io.lsu.req.fire) {
    lastLsuProgressCycle := io.csr_cycle
    for (w <- 0 until memWidth) {
      s0_req(w).traffic_cacheable := edge.manager.supportsAcquireBFast(
        io.lsu.req.bits(w).bits.addr, lgCacheBlockBytes.U)
    }
  }
  val s0_type  = Mux(io.lsu.req.fire        , t_lsu,
                 Mux(killed_store_replay_fire, t_lsu,
                 Mux(wb_fire                  , t_wb,
                 Mux(prober_fire              , t_probe,
                 Mux(prefetch_fire            , t_prefetch,
                 Mux(mshrs.io.meta_read.fire, t_mshr_meta_read
                                              , t_replay))))))

  for (w <- 0 until memWidth) {
    when (s0_valid(w) && s0_type.isOneOf(t_lsu, t_replay) && isWrite(s0_selected_req(w).uop.mem_cmd)) {
      assert(s0_selected_req(w).request_token_valid && s0_selected_req(w).effect_token_valid,
        "write request lacks stable functional identity")
    }
  }
  // Capture owner epochs with the tag-array read, not from a later S2 lookup.
  val s1_lookup_epoch = RegNext(widthMap(w => slotEpoch(s0_req(w).addr(idxMSB, idxLSB))))
  // Preserve the entry decision across the tag lookup.  s1_before_freeze is
  // intentionally still true for these different-line reads, so the existing
  // snapshot/metadata-clear drain waits for every accepted bypass request.
  val s1_clear_freeze_read_bypass = RegNext(VecInit((0 until memWidth).map(w =>
    io.lsu.req.fire && lsu_clear_freeze_read_bypass_lane(w))),
    VecInit(Seq.fill(memWidth)(false.B)))
  val s1_before_freeze = RegNext(widthMap(w => {
    val r = s0_req(w)
    val set = r.addr(idxMSB, idxLSB)
    !slotReserved(set).asUInt.orR &&
      !(clearFreezeValid && set === clearFreezeSet && (r.addr >> untagBits) === clearFreezeTag) &&
      !(prober.io.state.valid && set === prober.io.state.bits(idxMSB, idxLSB))
  }))
  // Does this request need to send a response or nack
  val s0_send_resp_or_nack = Mux(io.lsu.req.fire, s0_valid,
    Mux(killed_store_replay_fire, VecInit(1.U(memWidth.W).asBools),
      VecInit(Mux(mshrs.io.replay.fire && isRead(mshrs.io.replay.bits.uop.mem_cmd),
        1.U(memWidth.W), 0.U(memWidth.W)).asBools)))


  val s1_req          = RegNext(s0_req)
  val s2_store_failed = Wire(Bool())
  for (w <- 0 until memWidth)
    s1_req(w).uop.br_mask := GetNewBrMask(io.lsu.brupdate, s0_req(w).uop)
  val s1_valid = widthMap(w =>
                 RegNext(s0_valid(w)                                     &&
                         !IsKilledByBranch(io.lsu.brupdate, s0_req(w).uop) &&
                         !(io.lsu.exception && s0_req(w).uop.uses_ldq),
                         init=false.B))
  for (w <- 0 until memWidth)
    assert(!(io.lsu.s1_kill(w) && !RegNext(io.lsu.req.fire) && !RegNext(io.lsu.req.bits(w).valid)))
  val s1_addr         = s1_req.map(_.addr)
  val s1_nack         = s1_addr.map(a => a(idxMSB,idxLSB) === prober.io.meta_write.bits.idx && !prober.io.req.ready)
  val s1_send_resp_or_nack = RegNext(s0_send_resp_or_nack)
  val s1_type         = RegNext(s0_type)
  val s1_replay_issued = RegNext(mshrs.io.replay.fire, false.B)
  val s1_replay_killed = s1_replay_issued && s1_type === t_replay && !s1_valid(0)

  val s1_mshr_meta_read_way_en = RegNext(mshrs.io.meta_read.bits.way_en)
  val s1_replay_way_en         = RegNext(mshrs.io.replay.bits.way_en) // For replays, the metadata isn't written yet
  val s1_wb_way_en             = RegNext(wb.io.data_req.bits.way_en)

  // tag check
  def wayMap[T <: Data](f: Int => T) = VecInit((0 until nWays).map(f))
  val s1_tag_eq_way = widthMap(i => wayMap((w: Int) => meta(i).io.resp(w).tag === (s1_addr(i) >> untagBits)).asUInt)
  val s1_tag_match_way = widthMap(i =>
                         Mux(s1_type === t_replay, s1_replay_way_en,
                         Mux(s1_type === t_wb,     s1_wb_way_en,
                         Mux(s1_type === t_mshr_meta_read, s1_mshr_meta_read_way_en,
                           wayMap((w: Int) => s1_tag_eq_way(i)(w) && meta(i).io.resp(w).coh.isValid()).asUInt))))

  val s1_wb_idx_matches = widthMap(i =>
    ((s1_addr(i)(untagBits-1,blockOffBits) === wb.io.idx.bits) && wb.io.idx.valid) ||
    ((s1_addr(i)(untagBits-1,blockOffBits) === wb.io.pending_idx.bits) && wb.io.pending_idx.valid))

  // Stage-1 identity is observation-only. A miss may not have a resident way
  // yet, so retain the tag lookup result together with request ownership.
  for (w <- 0 until memWidth) {
    // The legacy tag-match Mux chain is width-inferred only after FIRRTL;
    // give the trace-only consumer an explicit one-hot width for elaboration.
    val s1_trace_way = Wire(UInt(nWays.W))
    s1_trace_way := s1_tag_match_way(w)
    when (s1_valid(w)) {
      printf("STAGE1_TX S1 source=DCACHE cycle=%x line=%x set=%x way=%x epoch=%x gen=%x mshr=%x txn=%x req=%x effect=%x pc=%x cmd=%x\n",
        io.csr_cycle, (s1_req(w).addr >> blockOffBits) << blockOffBits,
        s1_req(w).addr(idxMSB, idxLSB), OHToUInt(s1_trace_way),
        Mux1H(s1_trace_way, s1_lookup_epoch(w)), s1_req(w).line_generation,
        s1_req(w).replay_mshr_id, s1_req(w).transaction_token,
        s1_req(w).request_token, s1_req(w).effect_token,
        s1_req(w).uop.debug_pc, s1_req(w).uop.mem_cmd)
    }
  }

  val s2_raw_req = RegNext(s1_req)
  val s2_req = Wire(Vec(memWidth, new BoomDCacheReq))
  s2_req := s2_raw_req
  val s2_lookup_epoch = RegNext(widthMap(w => Mux1H(s1_tag_match_way(w), s1_lookup_epoch(w))))
  val s2_type  = RegNext(s1_type)
  val s2_before_freeze = RegNext(s1_before_freeze)
  val s2_clear_freeze_read_bypass = RegNext(s1_clear_freeze_read_bypass,
    VecInit(Seq.fill(memWidth)(false.B)))
  val s2_replay_issued = RegNext(s1_replay_issued, false.B)
  val s2_valid = widthMap(w =>
                  RegNext(s1_valid(w) &&
                         !io.lsu.s1_kill(w) &&
                         !IsKilledByBranch(io.lsu.brupdate, s1_req(w).uop) &&
                         !(io.lsu.exception && s1_req(w).uop.uses_ldq) &&
                         !(s2_store_failed && s1_type === t_lsu &&
                           s1_req(w).uop.uses_stq)))
  val s2_replay_killed = s2_replay_issued && s2_type === t_replay &&
    !s2_valid(0) && !RegNext(s1_replay_killed, false.B)
  replayPipelineBusy := s1_replay_issued || s2_replay_issued
  for (w <- 0 until memWidth)
    s2_raw_req(w).uop.br_mask := GetNewBrMask(io.lsu.brupdate, s1_req(w).uop)

  val s2_tag_match_way = RegNext(s1_tag_match_way)
  val s2_tag_match     = s2_tag_match_way.map(_.orR)
  val s2_hit_state     = widthMap(i => Mux1H(s2_tag_match_way(i), wayMap((w: Int) => RegNext(meta(i).io.resp(w).coh))))
  val s2_has_permission = widthMap(w => s2_hit_state(w).onAccess(s2_req(w).uop.mem_cmd)._1)
  val s2_new_hit_state  = widthMap(w => s2_hit_state(w).onAccess(s2_req(w).uop.mem_cmd)._3)

  val s2_hit = widthMap(w => (s2_tag_match(w) && s2_has_permission(w) && s2_hit_state(w) === s2_new_hit_state(w) && !mshrs.io.block_hit(w)) || s2_type.isOneOf(t_replay, t_wb))
  val s2_nack = Wire(Vec(memWidth, Bool()))
  assert(!(s2_type === t_replay && !s2_hit(0)), "Replays should always hit")
  assert(!(s2_type === t_wb && !s2_hit(0)), "Writeback should always see data hit")

  val s2_wb_idx_matches = RegNext(s1_wb_idx_matches)

  // lr/sc
  val debug_sc_fail_addr = RegInit(0.U)
  val debug_sc_fail_cnt  = RegInit(0.U(8.W))

  val lrsc_count = RegInit(0.U(log2Ceil(lrscCycles).W))
  val lrsc_valid = lrsc_count > lrscBackoff.U
  val lrsc_addr  = Reg(UInt())
  // Keep the most recent completed LR's accounting scope until its SC
  // completes, even if the R_IC FSM changes state between the pair.
  val lr_traffic_check = RegInit(false.B)
  val lr_traffic_check_valid = RegInit(false.B)
  val s2_lr = s2_req(0).uop.mem_cmd === M_XLR && (!RegNext(s1_nack(0)) || s2_type === t_replay)
  val s2_sc = s2_req(0).uop.mem_cmd === M_XSC && (!RegNext(s1_nack(0)) || s2_type === t_replay)
  val s2_lrsc_addr_match = widthMap(w => lrsc_valid && lrsc_addr === (s2_req(w).addr >> blockOffBits))
  val s2_sc_fail = s2_sc && !s2_lrsc_addr_match(0)
  when (lrsc_count > 0.U) { lrsc_count := lrsc_count - 1.U }
  when (s2_valid(0) && ((s2_type === t_lsu && s2_hit(0) && !s2_nack(0)) ||
                     (s2_type === t_replay && s2_req(0).uop.mem_cmd =/= M_FLUSH_ALL))) {
    when (s2_lr) {
      lrsc_count := (lrscCycles - 1).U
      lrsc_addr := s2_req(0).addr >> blockOffBits
    }
    when (lrsc_count > 0.U) {
      lrsc_count := 0.U
    }
  }
  for (w <- 0 until memWidth) {
    when (s2_valid(w)                            &&
      s2_type === t_lsu                          &&
      !s2_hit(w)                                 &&
      !(s2_has_permission(w) && s2_tag_match(w)) &&
      s2_lrsc_addr_match(w)                      &&
      !s2_nack(w)) {
      lrsc_count := 0.U
    }
  }

  when (s2_valid(0)) {
    when (s2_req(0).addr === debug_sc_fail_addr) {
      when (s2_sc_fail) {
        debug_sc_fail_cnt := debug_sc_fail_cnt + 1.U
      } .elsewhen (s2_sc) {
        debug_sc_fail_cnt := 0.U
      }
    } .otherwise {
      when (s2_sc_fail) {
        debug_sc_fail_addr := s2_req(0).addr
        debug_sc_fail_cnt  := 1.U
      }
    }
  }
  assert(debug_sc_fail_cnt < 100.U, "L1DCache failed too many SCs in a row")

  val s2_data = Wire(Vec(memWidth, Vec(nWays, UInt(encRowBits.W))))
  for (i <- 0 until memWidth) {
    for (w <- 0 until nWays) {
      s2_data(i)(w) := data.io.resp(i)(w)
    }
  }

  val s2_data_muxed = widthMap(w => Mux1H(s2_tag_match_way(w), s2_data(w)))
  val s2_word_idx   = widthMap(w => if (rowWords == 1) 0.U else s2_req(w).addr(log2Up(rowWords*wordBytes)-1, log2Up(wordBytes)))

  // replacement policy
  val replacer = cacheParams.replacement
  val s1_replaced_way_en = UIntToOH(replacer.way)
  val s2_replaced_way_en = UIntToOH(RegNext(replacer.way))
  val s2_repl_meta = widthMap(i => Mux1H(s2_replaced_way_en, wayMap((w: Int) => RegNext(meta(i).io.resp(w))).toSeq))
  val s2_selected_way = Wire(UInt(nWays.W))
  s2_selected_way := Mux(s2_tag_match(0), s2_tag_match_way(0), s2_replaced_way_en)
  val s2_selected_set = s2_req(0).addr(idxMSB, idxLSB)
  val s2_effective_req = Wire(Vec(memWidth, new BoomDCacheReqInternal))
  val s2_lookup = Wire(Vec(memWidth, new BoomDCacheReqInternal))
  for (w <- 0 until memWidth) {
    // OHToUInt needs a known width before FIRRTL infers the tag-match Mux.
    val candidateWay = Wire(UInt(nWays.W))
    candidateWay := Mux(s2_tag_match(w), s2_tag_match_way(w), s2_replaced_way_en)
    val set = s2_raw_req(w).addr(idxMSB, idxLSB)
    val way = OHToUInt(candidateWay)
    s2_lookup(w) := 0.U.asTypeOf(new BoomDCacheReqInternal)
    BoomDCacheReq.copyBase(s2_lookup(w), s2_raw_req(w))
    s2_lookup(w).tag_match := s2_tag_match(w)
    s2_lookup(w).old_meta := Mux(s2_tag_match(w),
      L1Metadata(s2_raw_req(w).addr >> untagBits, s2_hit_state(w)), s2_repl_meta(w))
    s2_lookup(w).way_en := candidateWay
    s2_lookup(w).slot_epoch := slotEpoch(set)(way) + (!s2_tag_match(w)).asUInt
    s2_lookup(w).line_generation := lineGeneration(set)(way)
    s2_lookup(w).image_valid := s2_tag_match(w) && imageValid(set)(way)
    mshrs.io.lookup(w) := s2_lookup(w)
    val a = mshrs.io.admission(w)
    s2_effective_req(w) := s2_lookup(w)
    s2_effective_req(w).admission := a.kind
    s2_effective_req(w).way_en := a.way
    s2_effective_req(w).owner_way := a.way
    s2_effective_req(w).slot_epoch := a.slot_epoch
    s2_effective_req(w).line_generation := a.line_generation
    s2_effective_req(w).image_valid := a.image_valid
    s2_effective_req(w).transaction_token := a.transaction_token
    s2_effective_req(w).replay_mshr_id := a.mshr_id
    s2_effective_req(w).sdq_id := a.sdq_id
    s2_effective_req(w).owner_context_valid := a.kind.isOneOf(
      CacheAdmission.primary, CacheAdmission.upgrade, CacheAdmission.secondary)
    when (!s2_type.isOneOf(t_lsu, t_replay, t_prefetch)) {
      s2_effective_req(w).owner_context_valid := false.B
      s2_effective_req(w).admission := CacheAdmission.other
    }
    when (s2_hit(w) && s2_type === t_lsu) {
      s2_effective_req(w).admission := CacheAdmission.hit
      s2_effective_req(w).owner_context_valid := true.B
      s2_effective_req(w).slot_epoch := s2_lookup_epoch(w)
      s2_effective_req(w).line_generation := lineGeneration(set)(way)
      s2_effective_req(w).image_valid := imageValid(set)(way)
      s2_effective_req(w).transaction_token := 0.U
    }
    when (s2_type === t_replay) {
      BoomDCacheReq.copyBase(s2_effective_req(w), s2_raw_req(w))
      s2_effective_req(w).way_en := candidateWay
      s2_effective_req(w).tag_match := true.B
      s2_effective_req(w).admission := CacheAdmission.replay
      // RPQ preserves the request and slot owner; each serialized write grant
      // depends on the current provisional image, not the primary's old image.
      s2_effective_req(w).line_generation := lineGeneration(set)(way)
      s2_effective_req(w).image_valid := imageValid(set)(way)
    }
    BoomDCacheReq.copyBase(s2_req(w), s2_effective_req(w))
  }
  for (w <- 0 until memWidth) {
    when (s2_valid(w)) {
      printf("STAGE1_TX S2 source=DCACHE cycle=%x line=%x set=%x way=%x epoch=%x gen=%x mshr=%x txn=%x req=%x effect=%x pc=%x cmd=%x admission=%x\n",
        io.csr_cycle, (s2_req(w).addr >> blockOffBits) << blockOffBits,
        s2_req(w).addr(idxMSB, idxLSB), OHToUInt(s2_effective_req(w).way_en),
        s2_effective_req(w).slot_epoch, s2_effective_req(w).line_generation,
        s2_effective_req(w).replay_mshr_id, s2_effective_req(w).transaction_token,
        s2_effective_req(w).request_token, s2_effective_req(w).effect_token,
        s2_effective_req(w).uop.debug_pc, s2_effective_req(w).uop.mem_cmd,
        s2_effective_req(w).admission)
    }
  }
  val s2_owner_block = widthMap(w => {
    val set = s2_raw_req(w).addr(idxMSB, idxLSB)
    val way = OHToUInt(s2_lookup(w).way_en)
    val stale = s2_tag_match(w) && s2_lookup_epoch(w) =/= slotEpoch(set)(way)
    val clearing = clearFreezeValid && set === clearFreezeSet &&
      (s2_raw_req(w).addr >> untagBits) === clearFreezeTag
    val frozen = slotReserved(set)(way) || completionPending(set)(way)
    // A stale permission miss must relookup just like a stale hit. A legal
    // secondary instead inherits the captured MSHR owner and may join its RPQ.
    s2_type === t_lsu && edge.manager.supportsAcquireBFast(s2_raw_req(w).addr, lgCacheBlockBytes.U) && (clearing ||
      (stale && !mshrs.io.block_hit(w)) || (s2_hit(w) && frozen) ||
      (!s2_hit(w) && slotReserved(set)(way) && !mshrs.io.block_hit(w)))
  })
  val s2_write_busy = s3_valid || completionQ.io.count =/= 0.U
  val s2_replay_owner_match = s2_raw_req(0).owner_context_valid &&
    s2_raw_req(0).owner_way === s2_tag_match_way(0) &&
    s2_raw_req(0).slot_epoch === slotEpoch(s2_raw_req(0).addr(idxMSB, idxLSB))(
      OHToUInt(s2_raw_req(0).owner_way))
  when (s2_valid(0) && s2_type === t_replay) {
    assert(s2_replay_owner_match, "replay reached a revoked slot owner")
  }

  // nack because of incoming probe
  val s2_nack_hit    = RegNext(VecInit(s1_nack))
  // Nack when we hit something currently being evicted
  val s2_nack_victim = widthMap(w => s2_valid(w) &&  s2_hit(w) && mshrs.io.secondary_miss(w))
  // MSHRs not ready for request
  val s2_nack_miss   = widthMap(w => s2_valid(w) && !s2_hit(w) && !mshrs.io.req(w).ready)
  // Bank conflict on data arrays
  val s2_nack_data   = widthMap(w => data.io.nacks(w))
  // Can't allocate MSHR for same set currently being written back
  val s2_nack_wb     = widthMap(w => s2_valid(w) && !s2_hit(w) && s2_wb_idx_matches(w))
  // A bypass request is allowed to use the normal tag/data lookup only when
  // it is already a local hit.  Nack every miss before MSHRFile sees it.
  val s2_clear_freeze_read_bypass_miss = widthMap(w => s2_valid(w) &&
    s2_type === t_lsu && s2_clear_freeze_read_bypass(w) && !s2_hit(w))
  val s2_clear_slot_conflict = widthMap(w => clearFreezeValid &&
    edge.manager.supportsAcquireBFast(s2_raw_req(w).addr, lgCacheBlockBytes.U) &&
    s2_raw_req(w).addr(idxMSB, idxLSB) === clearFreezeSet &&
    s2_lookup(w).way_en === clearFreezeWay &&
    !s2_tag_match(w))
  // Filled below once the S3 effect identity is available.  This keeps a
  // replacement miss from reallocating a way in the same cycle as an older
  // store effect to that way.
  val s2_realloc_owner_conflict = WireDefault(false.B)

  val l1CrossPackageBlocked = WireDefault(false.B)
  s2_nack           := widthMap(w =>
    ((s2_nack_miss(w) || s2_nack_hit(w) || s2_nack_victim(w) ||
      s2_nack_data(w) || s2_nack_wb(w) || s2_clear_freeze_read_bypass_miss(w) ||
      s2_owner_block(w) || s2_clear_slot_conflict(w) ||
      (isWrite(s2_raw_req(w).uop.mem_cmd) && s2_write_busy)) && s2_type =/= t_replay) ||
      ((w == 0).B && s2_realloc_owner_conflict && s2_type === t_lsu) ||
      ((w == 0).B && l1CrossPackageBlocked && s2_type === t_lsu &&
        isWrite(s2_req(0).uop.mem_cmd)))
  val s2_send_resp = widthMap(w => RegNext(s1_send_resp_or_nack(w)) &&
    !s2_nack(w) && s2_hit(w) && !isWrite(s2_req(w).uop.mem_cmd) &&
    (s2_type =/= t_replay || s2_replay_owner_match))
  val s2_send_nack = widthMap(w => (RegNext(s1_send_resp_or_nack(w)) && s2_nack(w)))
  for (w <- 0 until memWidth)
    assert(!(s2_send_resp(w) && s2_send_nack(w)))

  // A store that cannot proceed in S2 is reported through io.lsu.nack.  The
  // LSU then rewinds stq_execute_head and reissues the same STQ entry.  The
  // S2-wide kill below can discard a younger store already resident in S1;
  // that exact S1 request is retained for one compensation replay.
  s2_store_failed := s2_valid(0) && s2_nack(0) && s2_send_nack(0) && s2_req(0).uop.uses_stq
  when (killed_store_replay_fire) {
    killed_store_replay_valid := false.B
  }
  // The request lost by the S2-wide kill is the request already resident in
  // S1, not the new request entering S0.  Capture that S1 request with the
  // same predicate used above so the compensation replay preserves the
  // original STQ identity and payload.
  val killed_store_replay_candidate = s2_store_failed && s1_valid(0) &&
    !io.lsu.s1_kill(0) &&
    !IsKilledByBranch(io.lsu.brupdate, s1_req(0).uop) &&
    !(io.lsu.exception && s1_req(0).uop.uses_ldq) &&
    s1_type === t_lsu && s1_req(0).uop.uses_stq
  when (killed_store_replay_candidate) {
    killed_store_replay_req := s1_req(0)
    killed_store_replay_valid := true.B
  }

  // Miss handling
  for (w <- 0 until memWidth) {
    mshrs.io.req(w).valid := s2_valid(w)          &&
                            !s2_hit(w)            &&
                            !s2_nack_hit(w)       &&
                            !s2_nack_victim(w)    &&
                            !s2_nack_data(w)      &&
                            !s2_nack_wb(w)        &&
                            !s2_clear_freeze_read_bypass_miss(w) &&
                            !s2_owner_block(w)    &&
                            !s2_clear_slot_conflict(w) &&
                            !(isWrite(s2_raw_req(w).uop.mem_cmd) && s2_write_busy) &&
                            !((w == 0).B && isWrite(s2_raw_req(w).uop.mem_cmd) && l1CrossPackageBlocked) &&
                            ((w != 0).B || !s2_realloc_owner_conflict) &&
                             s2_type.isOneOf(t_lsu, t_prefetch)             &&
                            !IsKilledByBranch(io.lsu.brupdate, s2_req(w).uop) &&
                            !(io.lsu.exception && s2_req(w).uop.uses_ldq)   &&
                             (isPrefetch(s2_req(w).uop.mem_cmd) ||
                              isRead(s2_req(w).uop.mem_cmd)     ||
                              isWrite(s2_req(w).uop.mem_cmd))
    assert(!(mshrs.io.req(w).valid && s2_type === t_replay), "Replays should not need to go back into MSHRs")
    when (s2_valid(w) && s2_clear_freeze_read_bypass(w)) {
      assert(s2_type === t_lsu && s2_raw_req(w).uop.mem_cmd === M_XRD &&
        s2_raw_req(w).uop.uses_ldq && !s2_raw_req(w).uop.uses_stq &&
        !s2_raw_req(w).is_hella,
        "freeze bypass admitted a non-load request")
      assert(!mshrs.io.req(w).valid,
        "freeze bypass miss allocated an MSHR")
      assert(s2_before_freeze(w),
        "freeze bypass escaped the existing lookup drain")
    }
    mshrs.io.req(w).bits := s2_effective_req(w)
    mshrs.io.req(w).bits.uop.br_mask := GetNewBrMask(io.lsu.brupdate, s2_req(w).uop)
    mshrs.io.req_is_probe(w)         := s2_type === t_probe && s2_valid(w)
  }
  for (w <- 0 until memWidth) {
    val r = s2_effective_req(w)
    val set = r.addr(idxMSB, idxLSB)
    val way = OHToUInt(r.way_en)
    when (mshrs.io.req(w).fire && r.admission.isOneOf(CacheAdmission.primary, CacheAdmission.upgrade)) {
      assert(!slotReserved(set)(way), "duplicate destination reservation")
      when (r.admission === CacheAdmission.primary) {
        assert(r.slot_epoch =/= 0.U, "slot epoch exhausted")
      }
      slotReserved(set)(way) := true.B
      installActive(set)(way) := false.B
      reservedEpoch(set)(way) := r.slot_epoch
      reservedTransaction(set)(way) := r.transaction_token
      reservedMshr(set)(way) := r.replay_mshr_id
      reservedNewOwner(set)(way) := r.admission === CacheAdmission.primary
      reservedTag(set)(way) := r.addr >> untagBits
    }
  }

  mshrs.io.meta_resp.valid      := !s2_nack_hit(0) || prober.io.mshr_wb_rdy
  mshrs.io.meta_resp.bits       := Mux1H(s2_tag_match_way(0), RegNext(meta(0).io.resp))
  when (mshrs.io.req.map(_.fire).reduce(_||_)) { replacer.miss }
  tl_out.a <> mshrs.io.mem_acquire

  // probes and releases
  svb.io.releaseLines(3) := (tl_out.b.bits.address >> blockOffBits) << blockOffBits
  prober.io.req.valid   := tl_out.b.valid && !lrsc_valid && !svb.io.releaseBlocked(3)
  tl_out.b.ready        := prober.io.req.ready && !lrsc_valid && !svb.io.releaseBlocked(3)
  prober.io.req.bits    := tl_out.b.bits
  prober.io.way_en      := s2_tag_match_way(0)
  prober.io.block_state := s2_hit_state(0)
  metaWriteArb.io.in(1).valid := prober.io.meta_write.valid && probeDrainReady
  metaWriteArb.io.in(1).bits := prober.io.meta_write.bits
  prober.io.meta_write.ready := metaWriteArb.io.in(1).ready && probeDrainReady
  prober.io.mshr_rdy    := mshrs.io.probe_rdy && probeDrainReady
  prober.io.wb_rdy      := (prober.io.meta_write.bits.idx =/= wb.io.idx.bits) || !wb.io.idx.valid
  prober.io.wb_done     := wb.io.probe_done
  mshrs.io.prober_state := prober.io.state
  when (prober.io.meta_write.fire && !prober.io.meta_write.bits.data.coh.isValid()) {
    val pset = prober.io.meta_write.bits.idx
    val pway = OHToUInt(prober.io.meta_write.bits.way_en)
    when (!slotReserved(pset)(pway)) {
      assert(slotEpoch(pset)(pway) =/= ~0.U(16.W), "slot epoch exhausted")
      slotEpoch(pset)(pway) := slotEpoch(pset)(pway) + 1.U
    }
    appliedEffectValid(pset)(pway) := false.B
    when (!slotReserved(pset)(pway)) {
      imageValid(pset)(pway) := false.B
      lowerPreserved(pset)(pway) := false.B
    }
  }

  // refills
  when (tl_out.d.bits.source === cfg.nMSHRs.U) {
    // This should be ReleaseAck
    tl_out.d.ready := true.B
    mshrs.io.mem_grant.valid := false.B
    mshrs.io.mem_grant.bits  := DontCare
  } .otherwise {
    // This should be GrantData
    mshrs.io.mem_grant <> tl_out.d
  }

  val installReq = mshrs.io.install.bits.req
  val installSet = installReq.addr(idxMSB, idxLSB)
  val installWay = OHToUInt(installReq.way_en)
  val installReservationMatch = slotReserved(installSet)(installWay) &&
    reservedEpoch(installSet)(installWay) === installReq.slot_epoch &&
    reservedTransaction(installSet)(installWay) === installReq.transaction_token &&
    reservedMshr(installSet)(installWay) === installReq.replay_mshr_id &&
    reservedTag(installSet)(installWay) === (installReq.addr >> untagBits)
  val installExistingMatch = installReservationMatch && installReq.owner_context_valid &&
    slotEpoch(installSet)(installWay) === installReq.slot_epoch
  val installOwnerMatch = Mux(mshrs.io.install.bits.new_owner,
    installReservationMatch && slotEpoch(installSet)(installWay) + 1.U === installReq.slot_epoch,
    installExistingMatch)
  val installDrain = !(s3_valid && s3_req.addr(idxMSB, idxLSB) === installSet &&
    s3_way === installReq.way_en) && !completionPending(installSet)(installWay) &&
    (!wb.io.idx.valid || wb.io.idx.bits =/= installSet) &&
    (!wb.io.pending_idx.valid || wb.io.pending_idx.bits =/= installSet) &&
    !(0 until memWidth).map(w =>
      (s1_valid(w) && s1_type === t_lsu && s1_before_freeze(w) &&
        s1_req(w).addr(idxMSB, idxLSB) === installSet) ||
      (s2_valid(w) && s2_type === t_lsu && s2_before_freeze(w) &&
        s2_raw_req(w).addr(idxMSB, idxLSB) === installSet)).reduce(_ || _)
  val installPreservationAllowed = !mshrs.io.install.bits.has_data ||
    mshrs.io.install.bits.new_owner || L1Preservation.copyAllowed(
      imageValid(installSet)(installWay), imageKey(installSet)(installWay),
      lowerPreserved(installSet)(installWay), mshrs.io.install.bits.image, safePacketWatermark)
  mshrs.io.install.ready := installOwnerMatch && installDrain && installPreservationAllowed
  when (mshrs.io.install.valid && installOwnerMatch && installDrain) {
    assert(installPreservationAllowed, "same-address refill would destroy an unpreserved image")
  }
  for (i <- 0 until cfg.nMSHRs) {
    mshrs.io.install_fault(i) := mshrs.io.install.valid &&
      installReq.replay_mshr_id === i.U && !installOwnerMatch
  }
  when (mshrs.io.install.fire) {
    printf("STAGE1_TX INSTALL source=DCACHE cycle=%x line=%x set=%x way=%x epoch=%x gen=%x mshr=%x txn=%x req=%x effect=%x new_owner=%x\n",
      io.csr_cycle, (installReq.addr >> blockOffBits) << blockOffBits, installSet,
      installWay, installReq.slot_epoch, installReq.line_generation,
      installReq.replay_mshr_id, installReq.transaction_token,
      installReq.request_token, installReq.effect_token,
      mshrs.io.install.bits.new_owner)
    installActive(installSet)(installWay) := true.B
    installedImage(installSet)(installWay) := mshrs.io.install.bits.image
    when (mshrs.io.install.bits.new_owner) {
      assert(slotEpoch(installSet)(installWay) + 1.U === installReq.slot_epoch,
        "resident epoch changed under incoming reservation")
      // The resident retains its old identity during the frozen row writes.
      // The final data fire commits the incoming owner below.
    }
  }
  val refillReqSet = mshrs.io.refill.bits.addr(idxMSB, idxLSB)
  val refillReqWay = OHToUInt(mshrs.io.refill.bits.way_en)
  val selectedRefillReservedEpoch = Wire(UInt(16.W))
  val selectedRefillSlotEpoch = Wire(UInt(16.W))
  val selectedRefillSlotReserved = Wire(Bool())
  selectedRefillReservedEpoch := reservedEpoch(refillReqSet)(refillReqWay)
  selectedRefillSlotEpoch := slotEpoch(refillReqSet)(refillReqWay)
  selectedRefillSlotReserved := slotReserved(refillReqSet)(refillReqWay)
  val refillReqOwnerMatch = mshrs.io.refill.bits.owner_context_valid &&
    mshrs.io.refill.bits.line_addr(blockOffBits-1, 0) === 0.U &&
    mshrs.io.refill.bits.line_addr(idxMSB, idxLSB) === refillReqSet &&
    installActive(refillReqSet)(refillReqWay) && selectedRefillSlotReserved &&
    mshrs.io.refill.bits.image.asUInt === installedImage(refillReqSet)(refillReqWay).asUInt &&
    mshrs.io.refill.bits.slot_epoch === selectedRefillReservedEpoch &&
    mshrs.io.refill.bits.transaction_token === reservedTransaction(refillReqSet)(refillReqWay) &&
    mshrs.io.refill.bits.mshr_id === reservedMshr(refillReqSet)(refillReqWay) &&
    (mshrs.io.refill.bits.line_addr >> untagBits) === reservedTag(refillReqSet)(refillReqWay) &&
    Mux(reservedNewOwner(refillReqSet)(refillReqWay),
      selectedRefillSlotEpoch + 1.U === selectedRefillReservedEpoch,
      selectedRefillSlotEpoch === selectedRefillReservedEpoch)
  val refillPreservationAllowed = reservedNewOwner(refillReqSet)(refillReqWay) ||
    L1Preservation.copyAllowed(imageValid(refillReqSet)(refillReqWay),
      imageKey(refillReqSet)(refillReqWay), lowerPreserved(refillReqSet)(refillReqWay),
      mshrs.io.refill.bits.image, safePacketWatermark)
  dataWriteArb.io.in(1).valid := mshrs.io.refill.valid && refillReqOwnerMatch && refillPreservationAllowed
  for (name <- (new L1DataWriteReq).elements.keys) {
    dataWriteArb.io.in(1).bits.elements(name) := mshrs.io.refill.bits.elements(name)
  }
  mshrs.io.refill.ready := dataWriteArb.io.in(1).ready && refillReqOwnerMatch && refillPreservationAllowed
  when (mshrs.io.refill.valid) {
    assert(refillPreservationAllowed, "refill bypassed L1 preservation gate")
  }
  for (i <- 0 until cfg.nMSHRs) {
    mshrs.io.refill_fault(i) := mshrs.io.refill.valid &&
      mshrs.io.refill.bits.mshr_id === i.U && !refillReqOwnerMatch
  }
  when (mshrs.io.refill.valid) { assert(refillReqOwnerMatch, "active refill owner changed") }
  when (mshrs.io.refill.fire) {
    printf("STAGE1_TX REFILL source=DCACHE cycle=%x line=%x set=%x way=%x beat=%x mshr=%x txn=%x token=%x epoch=%x gen=%x addr=%x\n",
      io.csr_cycle, mshrs.io.refill.bits.line_addr, refillReqSet, refillReqWay,
      mshrs.io.refill.bits.addr(blockOffBits-1, rowOffBits),
      mshrs.io.refill.bits.mshr_id, mshrs.io.refill.bits.transaction_token,
      mshrs.io.refill.bits.transaction_token,
      mshrs.io.refill.bits.slot_epoch, mshrs.io.refill.bits.line_generation,
      mshrs.io.refill.bits.addr)
  }
  val mshrMetaSet = mshrs.io.meta_write.bits.idx
  val mshrMetaWay = mshrs.io.meta_write.bits.way_en
  val mshrMetaDrain = !(s3_valid && s3_req.addr(idxMSB, idxLSB) === mshrMetaSet &&
    s3_way === mshrMetaWay) && !completionPending(mshrMetaSet)(OHToUInt(mshrMetaWay)) &&
    !(0 until memWidth).map(w =>
      (s1_valid(w) && s1_type === t_lsu && s1_before_freeze(w) &&
        s1_req(w).addr(idxMSB, idxLSB) === mshrMetaSet) ||
      (s2_valid(w) && s2_type === t_lsu && s2_before_freeze(w) &&
        s2_req(w).addr(idxMSB, idxLSB) === mshrMetaSet)).reduce(_ || _)
  metaWriteArb.io.in(0).valid := mshrs.io.meta_write.valid && mshrMetaDrain
  metaWriteArb.io.in(0).bits := mshrs.io.meta_write.bits
  mshrs.io.meta_write.ready := metaWriteArb.io.in(0).ready && mshrMetaDrain
  when (mshrs.io.meta_write.fire && mshrs.io.meta_write.bits.data.coh.isValid()) {
    val set = mshrs.io.meta_write.bits.idx
    val way = OHToUInt(mshrs.io.meta_write.bits.way_en)
    assert(!completionPending(set)(way), "publish before functional completion")
    slotReserved(set)(way) := false.B
    installActive(set)(way) := false.B
  }

  tl_out.e <> mshrs.io.mem_finish

  // writebacks
  val wbArb = Module(new Arbiter(new WritebackReq(edge.bundle), 4))
  // 0 goes to prober, 1 to MSHR evictions, 2 to the SVB snapshot reader,
  // 3 to the legacy cross-package WaitSafe shadow writeback.
  def wbLine(r: WritebackReq): UInt = (Cat(r.tag, r.idx) << blockOffBits).pad(coreMaxAddrBits)
  svb.io.releaseLines(0) := wbLine(prober.io.wb_req.bits)
  svb.io.releaseLines(1) := wbLine(mshrs.io.wb_req.bits)
  val crossPackageWbReq = Wire(Decoupled(new WritebackReq(edge.bundle)))
  svb.io.releaseLines(2) := wbLine(crossPackageWbReq.bits)
  // Correctness ordering, independent of source allocation: ordinary WB and
  // probe data may not overtake an older snapshot on the SAME physical line.
  // Gate before arbitration so a blocked normal request cannot starve SVB.
  wbArb.io.in(0).valid := prober.io.wb_req.valid && probeDrainReady && !svb.io.releaseBlocked(0)
  wbArb.io.in(0).bits := prober.io.wb_req.bits
  prober.io.wb_req.ready := wbArb.io.in(0).ready && probeDrainReady && !svb.io.releaseBlocked(0)
  wbArb.io.in(1).valid := mshrs.io.wb_req.valid && victimDrainReady && !svb.io.releaseBlocked(1)
  wbArb.io.in(1).bits := mshrs.io.wb_req.bits
  mshrs.io.wb_req.ready := wbArb.io.in(1).ready && victimDrainReady && !svb.io.releaseBlocked(1)
  wbArb.io.in(2) <> svbCaptureWbReq
  wbArb.io.in(3).valid := crossPackageWbReq.valid && !svb.io.releaseBlocked(2)
  wbArb.io.in(3).bits := crossPackageWbReq.bits
  crossPackageWbReq.ready := wbArb.io.in(3).ready && !svb.io.releaseBlocked(2)
  for (q <- Seq(0, 1, 3)) {
    when (wbArb.io.in(q).fire) {
      assert(!svb.io.releaseBlocked(if (q == 3) 2 else q), "ORDER-1: normal WB overtook retained SVB predecessor")
    }
  }
  wb.io.req            <> wbArb.io.out
  val wbReqSet = wbArb.io.out.bits.idx
  val wbReqWay = OHToUInt(wbArb.io.out.bits.way_en)
  // This wire is constructed before the writeback unit wiring below.  The
  // actual pending sequence is driven with the barrier state later in this
  // module; avoiding a Scala forward reference is required during elaboration.
  val crossPackageWbPacketSeq = WireDefault(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val svbCapturePacketSeq = WireDefault(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  // Capture the line-level replacement acceptance point separately from the
  // later C-channel transfer. Port 1 is the MSHR dirty-victim path; probe
  // writebacks on port 0 are outside the current single-core barrier scope.
  val l1ReplacementWbEvent = wbArb.io.in(1).fire
  val l1ReplacementPacketSeq = dirtyPacketSeq(wbReqSet)(wbReqWay)
  val l1ReplacementPacketTracked = dirtyPacketTracked(wbReqSet)(wbReqWay)
  wb.io.owner_epoch := slotEpoch(wbReqSet)(wbReqWay)
  wb.io.image_generation := lineGeneration(wbReqSet)(wbReqWay)
  wb.io.image_valid := imageValid(wbReqSet)(wbReqWay)
  wb.io.image_key := imageKey(wbReqSet)(wbReqWay)
  wb.io.packet_seq := Mux(wbArb.io.chosen === 2.U,
    svbCapturePacketSeq,
    Mux(wbArb.io.chosen === 3.U,
      crossPackageWbPacketSeq, dirtyPacketSeq(wbReqSet)(wbReqWay)))
  wb.io.packet_tracked := dirtyPacketTracked(wbReqSet)(wbReqWay)
  wb.io.data_resp       := s2_data_muxed(0)
  wb.io.snapshot_ready  := svb.io.capture.ready
  wb.io.svb_req <> svb.io.promote
  wb.io.req_is_mshr := wbArb.io.chosen === 1.U
  svb.io.capture.valid := wb.io.snapshot_valid
  svb.io.capture.bits.line := wb.io.snapshot_line
  svb.io.capture.bits.key := wb.io.snapshot_key
  svb.io.capture.bits.epoch := svbEpoch
  svb.io.capture.bits.param := wb.io.snapshot_param
  svb.io.capture.bits.data := wb.io.snapshot_data
  // SVB snapshots use the same row reader but are not MSHR evictions; do not
  // let their line-read completion pulse retire an unrelated MSHR WB state.
  mshrs.io.wb_resp      := wb.io.resp
  val wbAck = tl_out.d.fire && tl_out.d.bits.source === cfg.nMSHRs.U
  val wbAckKey = tl_out.d.bits.user.lift(CacheImage).getOrElse(0.U.asTypeOf(new CacheImageKey))
  val wbAckMatches = wb.io.pending_sent && tl_out.d.bits.opcode === TLMessages.ReleaseAck &&
    !tl_out.d.bits.denied && !tl_out.d.bits.corrupt &&
    tl_out.d.bits.size === lgCacheBlockBytes.U && wbAckKey.asUInt === wb.io.pending_key.asUInt
  wb.io.mem_grant := wbAck && wbAckMatches
  // Only the shared engine consumes this source's ACK. The latched
  // receipt selects normal completion versus SVB entry completion.
  when (wbAck) {
    assert(wbAckMatches, "invalid/unmatched response on the voluntary WB source")
  }

  val lsu_release_arb = Module(new Arbiter(new TLBundleC(edge.bundle), 2))
  io.lsu.release <> lsu_release_arb.io.out
  lsu_release_arb.io.in(0) <> wb.io.lsu_release
  lsu_release_arb.io.in(1) <> prober.io.lsu_release

  TLArbiter.lowest(edge, tl_out.c, wb.io.release, prober.io.rep)

  // Count each L1->L2 C-channel transaction once, when its first C-channel
  // beat is accepted. A ReleaseData/ProbeAckData transaction is a dirty
  // writeback; this single-core design currently has no ProbeAck traffic from
  // another coherent tile, so the C-channel count is the useful total here.
  val (c_first, c_last, _, c_beat) = edge.count(tl_out.c)
  val cReleaseKey = tl_out.c.bits.user.lift(CacheImage).get
  // C arbitration covers beats; this scoreboard covers the ACK lifetime.
  val releaseBeat = tl_out.c.fire &&
    tl_out.c.bits.opcode.isOneOf(TLMessages.Release, TLMessages.ReleaseData)
  val releaseFirst = releaseBeat && c_first
  val releaseLast = releaseBeat && c_last
  when (releaseFirst || releaseLast) {
    printf("C_CHANNEL cycle=%x first=%x last=%x owner=%x line=%x source=%x opcode=%x seq=%x generation=%x\n",
      io.csr_cycle, releaseFirst, releaseLast, wb.io.pending_svb,
      tl_out.c.bits.address, tl_out.c.bits.source, tl_out.c.bits.opcode,
      cReleaseKey.contentSeq, cReleaseKey.generation)
    when (wb.io.pending_svb) {
      printf("SVB_C_FIRE cycle=%x first=%x last=%x entry=%x line=%x seq=%x generation=%x source=%x\n",
        io.csr_cycle, releaseFirst, releaseLast, wb.io.pending_entry,
        tl_out.c.bits.address, cReleaseKey.contentSeq, cReleaseKey.generation,
        tl_out.c.bits.source)
    }
  }
  when (wbAck) {
    printf("D_ACK cycle=%x line=%x source=%x opcode=%x matched=%x sent=%x owner_svb=%x entry=%x seq=%x generation=%x\n",
      io.csr_cycle, wb.io.pending_line, tl_out.d.bits.source,
      tl_out.d.bits.opcode, wbAckMatches, wb.io.pending_sent,
      wb.io.pending_svb, wb.io.pending_entry, wbAckKey.contentSeq,
      wbAckKey.generation)
  }
  val releaseSourceBusy = RegInit(false.B)
  val releaseSourceSent = RegInit(false.B)
  val sourceConflict = releaseFirst && (releaseSourceBusy ||
    !wb.io.pending_idx.valid || tl_out.c.bits.source =/= cfg.nMSHRs.U)
  val invalidReleaseAck = wbAck && (!wbAckMatches || !releaseSourceBusy || !releaseSourceSent)
  when (releaseFirst) {
    assert(!sourceConflict, "C release source reused or missing shared WB reservation")
    releaseSourceBusy := true.B
    releaseSourceSent := false.B
  }
  when (releaseLast) { releaseSourceSent := true.B }
  when (wbAck && wbAckMatches) {
    assert(releaseSourceBusy && releaseSourceSent, "ACK without complete outstanding C release")
    releaseSourceBusy := false.B
    releaseSourceSent := false.B
  }
  val releaseIssued = RegInit(0.U(64.W))
  val releaseMatched = RegInit(0.U(64.W))
  val svbReleaseIssued = RegInit(0.U(64.W))
  val svbReleaseMatched = RegInit(0.U(64.W))
  val sourceConflicts = RegInit(0.U(64.W))
  val invalidReleaseAcks = RegInit(0.U(64.W))
  when (releaseFirst) {
    releaseIssued := releaseIssued + 1.U
    when (wb.io.pending_svb) { svbReleaseIssued := svbReleaseIssued + 1.U }
  }
  when (wbAck && wbAckMatches) {
    releaseMatched := releaseMatched + 1.U
    when (wb.io.pending_svb) { svbReleaseMatched := svbReleaseMatched + 1.U }
  }
  when (sourceConflict) { sourceConflicts := sourceConflicts + 1.U }
  when (invalidReleaseAck) { invalidReleaseAcks := invalidReleaseAcks + 1.U }
  val svbSourceBusyCycles = RegInit(0.U(64.W))
  val svbQueuedCycles = RegInit(0.U(64.W))
  val svbMaxQueued = RegInit(0.U(log2Ceil(nSVBEntries + 1).W))
  val svbCoalesced = RegInit(0.U(64.W))
  val svbSourceBlocked = svb.io.promote.valid && wb.io.pending_idx.valid
  val svbSourceBlockedPrevious = RegNext(svbSourceBlocked, false.B)
  when (io.traffic_reset) {
    svbSourceBusyCycles := 0.U
    svbQueuedCycles := 0.U
    svbMaxQueued := 0.U
    svbCoalesced := 0.U
  }.elsewhen (trafficCounting) {
    when (wb.io.pending_idx.valid && (svb.io.queued =/= 0.U || wb.io.pending_svb)) { svbSourceBusyCycles := svbSourceBusyCycles + 1.U }
    when (svb.io.queued =/= 0.U) { svbQueuedCycles := svbQueuedCycles + 1.U }
    when (svb.io.queued > svbMaxQueued) { svbMaxQueued := svb.io.queued }
    svbCoalesced := svbCoalesced + svb.io.coalesced
  }

  val l1_l2_c_event = tl_out.c.fire && c_first
  val l1_l2_dirty_wb_event = l1_l2_c_event &&
    tl_out.c.bits.opcode.isOneOf(TLMessages.ReleaseData, TLMessages.ProbeAckData)
  val l1_l2_c_count = RegInit(0.U(64.W))
  val l1_l2_dirty_wb_count = RegInit(0.U(64.W))

  // Exact L1->L2 provenance travels in CacheImage on each C beat; a separate
  // address-indexed provenance CAM is no longer needed by SinkC.
  // Completion bitmap and per-package writeback buckets share the BOOM clock.
  // Thus io.csr_cycle is sampled at both the C-channel writeback and the exact
  // cycle at which an out-of-order completion advances the safe watermark.
  val statsWindow = 256
  val statsIndexBits = log2Ceil(statsWindow)
  // Keep the verification bitmap in its own Bundle so it can be reused by
  // other L1->L2 verification users without coupling their state to DCache.
  val bitmapState = RegInit(0.U.asTypeOf(new DirtyWritebackBitmap(statsWindow)))
  val bitmapAllocated = bitmapState.allocated
  val bitmapCompleted = bitmapState.completed
  val bitmapPassed = bitmapState.passed
  val bitmapSeq = bitmapState.seq
  val measurementSeqFloor = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val crossPackagePending = RegInit(false.B)
  val crossPackageIssued = RegInit(false.B)
  val crossPackageMetaClearPending = RegInit(false.B)
  val crossPackagePendingSet = RegInit(0.U(idxBits.W))
  val crossPackagePendingWay = RegInit(0.U(log2Ceil(nWays max 2).W))
  val crossPackagePendingTag = RegInit(0.U(tagBits.W))
  val crossPackagePendingSeq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val crossPackagePendingEpoch = Reg(UInt(16.W))
  val crossPackagePendingKey = Reg(new CacheImageKey)
  val crossPackageResidentMatch = residentValid(crossPackagePendingSet)(crossPackagePendingWay) &&
    residentTag(crossPackagePendingSet)(crossPackagePendingWay) === crossPackagePendingTag &&
    slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) === crossPackagePendingEpoch &&
    (!(crossPackageIssued || crossPackageMetaClearPending) ||
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).asUInt === crossPackagePendingKey.asUInt)
  clearFreezeValid := crossPackagePending || svbCapturePending
  clearFreezeSet := Mux(svbCapturePending, svbFastSet, crossPackagePendingSet)
  clearFreezeTag := Mux(svbCapturePending, svbFastTag, crossPackagePendingTag)
  clearFreezeWay := UIntToOH(Mux(svbCapturePending, svbFastWay, crossPackagePendingWay), nWays)
  // The metadata clear is a commit point.  A store already in S3 must retire
  // before that point, otherwise its old ownership check would still pass in
  // the same cycle as the clear.
  val crossPackageMetaClearBlock = WireDefault(false.B)
  crossPackageWbPacketSeq := imageKey(crossPackagePendingSet)(crossPackagePendingWay).contentSeq
  val s2_store_set = s2_req(0).addr(idxMSB, idxLSB)
  // The legacy tag-match Mux chain leaves the one-hot width unknown until
  // FIRRTL. Give it an explicit width before OHToUInt is elaborated.
  val s2_store_way_oh = Wire(UInt(nWays.W))
  s2_store_way_oh := s2_tag_match_way(0)
  val s2_store_way = OHToUInt(s2_store_way_oh)
  val s2_overwrittenPacketSeq = dirtyPacketSeq(s2_store_set)(s2_store_way)
  val s2_overwrittenPacketTracked = dirtyPacketTracked(s2_store_set)(s2_store_way)
  val s2_overwrittenKey = imageKey(s2_store_set)(s2_store_way)
  val s2_preservationAllowed = L1Preservation.allow(
    imageValid(s2_store_set)(s2_store_way), s2_overwrittenKey,
    lowerPreserved(s2_store_set)(s2_store_way), s2_req(0).packet_seq, safePacketWatermark, outer.staticImageWriter.U)
  // A fast-line lease grants permission for exactly one resident incarnation.
  // The retained SVB entry, independently, owns the predecessor until ACK.
  val svbCaptureResidentMatch = residentValid(svbFastSet)(svbFastWay) &&
    residentTag(svbFastSet)(svbFastWay) === svbFastTag &&
    slotEpoch(svbFastSet)(svbFastWay) === svbFastEpoch &&
    imageKey(svbFastSet)(svbFastWay).asUInt === svbFastKey.asUInt
  val svbFastRequestSameLine = s2_store_set === svbFastSet &&
    (s2_req(0).addr >> untagBits) === svbFastTag
  val svbFastPreservationConflict = svbFastLineValid && svbFastRequestSameLine
  val svbFastLineMatch = svbFastPreservationConflict && svbCaptureResidentMatch &&
    s2_store_way === svbFastWay && s2_req(0).packet_seq === svbFastSeq
  val crossPackageDomainWaitRaw = s2_valid(0) && s2_type.isOneOf(t_lsu, t_replay) &&
    s2_tag_match(0) && isWrite(s2_req(0).uop.mem_cmd) && !s2_preservationAllowed
  // Once the predecessor is durably in SVB, this line no longer waits for
  // the watermark. The held store still carries the fast-line identity and
  // is admitted only after the capture handshake below.
  val crossPackageDomainWait = crossPackageDomainWaitRaw && !svbFastLineMatch
  val svbEligibleCandidate = crossPackageDomainWaitRaw && !svbFastLineMatch &&
    s2_type === t_lsu && s2_req(0).uop.mem_cmd === M_XWR &&
    s2_req(0).traffic_cacheable && s2_req(0).packet_seq =/= 0.U &&
    s2_req(0).packet_seq > s2_overwrittenKey.contentSeq &&
    s2_overwrittenKey.valid && !L1Preservation.safe(s2_overwrittenKey, safePacketWatermark) &&
    // Both capture and legacy preservation use the single freeze descriptor.
    !crossPackagePending && !svbCapturePending && !svbFastLineValid
  val svbEligible = svbEligibleCandidate && svb.io.capture.ready
  val svbFullFallback = svbEligibleCandidate && !svb.io.capture.ready
  // Gate permission misses before reserving a destination as well as hits.
  // Refilled images already have a receipt; an RPQ blocked on safety retries
  // without releasing its head/SDQ. Never park a shadow clear behind that RPQ.
  when (crossPackageDomainWait && !crossPackagePending) {
    printf("STAGE2_TX BLOCK line=%x gen=%x seq=%x writer=%x valid=%x incoming=%x lower=%x safe=%x replay=%x req=%x\n",
      (s2_req(0).addr >> blockOffBits) << blockOffBits, s2_overwrittenKey.generation,
      s2_overwrittenKey.contentSeq, s2_overwrittenKey.writer, s2_overwrittenKey.valid,
      s2_req(0).packet_seq, lowerPreserved(s2_store_set)(s2_store_way),
      L1Preservation.safe(s2_overwrittenKey, safePacketWatermark), s2_type === t_replay,
      s2_req(0).request_token)
  }
  val crossPackageBlockCondition = crossPackageDomainWait && s2_type === t_lsu &&
    !slotReserved(s2_store_set)(s2_store_way) && !s2_nack_hit(0) &&
    // s2_lookup_epoch is already the epoch captured for the selected way.
    // Indexing it again treats the way number as a bit index (way 1 made
    // epoch 1 compare as bit 1 == 1), suppressing the preservation request.
    s2_lookup_epoch(0) === slotEpoch(s2_store_set)(s2_store_way) &&
    !svbEligible && !svbCapturePending && !svbFastPreservationConflict
  // A single capture descriptor remains serialized, but an unrelated legacy
  // handoff must not wait for a lease whose store may be behind it in STQ.
  val fastLineBlocksOtherLine = crossPackageDomainWait && svbFastLineValid &&
    !svbFastRequestSameLine && !crossPackageBlockCondition
  // Report only cases where the global fast-line-valid term is the sole
  // condition preventing this different line from starting preservation.
  val crossPackageBlockWithoutFastLine = crossPackageDomainWait &&
    s2_type === t_lsu && !slotReserved(s2_store_set)(s2_store_way) &&
    !s2_nack_hit(0) && s2_lookup_epoch(0) === slotEpoch(s2_store_set)(s2_store_way) &&
    !svbEligible && !svbCapturePending && !crossPackagePending
  val fastLineBlockedOtherPrevious = RegInit(false.B)
  val fastLineBlockedOtherLine = RegInit(0.U(coreMaxAddrBits.W))
  val fastLineBlockedOtherSeq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val fastLineBlockedOtherToken = RegInit(0.U(64.W))
  val fastLineBlockEvent = fastLineBlocksOtherLine && crossPackageBlockWithoutFastLine &&
    (!fastLineBlockedOtherPrevious ||
      (s2_req(0).addr >> blockOffBits) =/= (fastLineBlockedOtherLine >> blockOffBits) ||
      s2_req(0).packet_seq =/= fastLineBlockedOtherSeq ||
      s2_req(0).request_token =/= fastLineBlockedOtherToken)
  when (!fastLineBlocksOtherLine) { fastLineBlockedOtherPrevious := false.B }
  when (fastLineBlockEvent) {
    printf("FASTLINE_BLOCK_OTHER_LINE cycle=%x line=%x request_type=%x package_seq=%x request_token=%x blocked_by=svbFastLineValid owner=SVB fast_valid=%x fast_line=%x fast_set=%x fast_tag=%x fast_seq=%x fast_epoch=%x fast_generation=%x owner_state=%x acquire_cycle=%x release_cycle=%x gate_fast_valid=%x gate_other_line=%x gate_capture_pending=%x gate_fast_match=%x gate_slot_free=%x gate_nack_clear=%x gate_epoch_match=%x gate_no_pending_handoff=%x gate_would_handoff_without_fastline=%x cross_package_block_condition=%x\n",
      io.csr_cycle, (s2_req(0).addr >> blockOffBits) << blockOffBits,
      s2_req(0).uop.mem_cmd, s2_req(0).packet_seq, s2_req(0).request_token,
      svbFastLineValid, svbFastLine, svbFastSet, svbFastTag, svbFastSeq,
      svbFastEpoch, svbFastKey.generation, Mux(svbCapturePending, 1.U, 2.U),
      svbFastAcquireCycle, svbFastReleaseCycle,
      svbFastLineValid, (s2_req(0).addr(idxMSB, idxLSB) =/= svbFastSet ||
        (s2_req(0).addr >> untagBits) =/= svbFastTag),
      svbCapturePending, svbFastLineMatch, !slotReserved(s2_store_set)(s2_store_way),
      !s2_nack_hit(0), s2_lookup_epoch(0) === slotEpoch(s2_store_set)(s2_store_way),
      !crossPackagePending, crossPackageBlockWithoutFastLine, crossPackageBlockCondition)
  }
  when (fastLineBlockEvent) {
    fastLineBlockedOtherPrevious := true.B
    fastLineBlockedOtherLine := s2_req(0).addr
    fastLineBlockedOtherSeq := s2_req(0).packet_seq
    fastLineBlockedOtherToken := s2_req(0).request_token
  }
  svbCaptureWbReq.bits := 0.U.asTypeOf(new WritebackReq(edge.bundle))
  svbCaptureWbReq.bits.source := cfg.nMSHRs.U
  svbCaptureWbReq.bits.idx := svbFastSet
  svbCaptureWbReq.bits.tag := svbFastTag
  // SVB promotion keeps the younger L1 image resident. Report the
  // predecessor's permission without shrinking the actual L1 client.
  svbCaptureWbReq.bits.param := Mux(
    residentCoh(svbFastSet)(svbFastWay).state === ClientStates.Branch,
    TLPermissions.BtoB, TLPermissions.TtoT)
  svbCaptureWbReq.bits.way_en := UIntToOH(svbFastWay)
  svbCaptureWbReq.bits.voluntary := false.B
  svbCaptureWbReq.bits.svb_capture := true.B
  svbCapturePacketSeq := svbFastSeq
  when (svbEligible) {
    svbCapturePending := true.B
    svbCaptureIssued := false.B
    svbFastSet := s2_store_set
    svbFastWay := s2_store_way
    svbFastTag := s2_req(0).addr >> untagBits
    svbFastEpoch := slotEpoch(s2_store_set)(s2_store_way)
    svbFastSeq := s2_req(0).packet_seq
    svbFastKey := s2_overwrittenKey
  }
  when (svbCaptureWbReq.fire) {
    svbCaptureIssued := true.B
  }
  when (wb.io.snapshot_valid && svb.io.capture.fire) {
    assert(!svbFastLineValid, "OWNER-1: capture overwrote an outstanding fast-line lease")
    assert(svbCapturePending && svbCaptureIssued,
      "SVB snapshot arrived without an issued capture request")
    assert(wb.io.snapshot_key.asUInt === svbFastKey.asUInt &&
      wb.io.snapshot_epoch === svbFastEpoch &&
      wb.io.snapshot_line === (Cat(svbFastTag, svbFastSet) << blockOffBits),
      "SVB capture changed pre-overwrite identity")
    svbCapturePending := false.B
    svbCaptureIssued := false.B
    when (svbFastLineValid) {
      printf("FASTLINE_OWNER_CHANGE cycle=%x old_line=%x old_seq=%x old_epoch=%x old_acquire_cycle=%x new_line=%x new_seq=%x new_epoch=%x reason=unexpected_capture_overlap\n",
        io.csr_cycle, svbFastLine, svbFastSeq, svbFastEpoch, svbFastAcquireCycle,
        wb.io.snapshot_line, wb.io.snapshot_key.contentSeq, wb.io.snapshot_epoch)
    }
    printf("FASTLINE_ACQUIRE cycle=%x line=%x set=%x tag=%x seq=%x epoch=%x generation=%x owner_state=captured_waiting_store acquire_reason=unsafe_predecessor_snapshot\n",
      io.csr_cycle, wb.io.snapshot_line, svbFastSet, svbFastTag, svbFastSeq,
      svbFastEpoch, wb.io.snapshot_key.generation)
    svbFastAcquireCycle := io.csr_cycle
    svbFastLineValid := true.B
  }
  val svbFastLeaseRevoked = svbFastLineValid && !svbCaptureResidentMatch
  assert(!(svbCapturePending && crossPackagePending),
    "OWNER-1: capture and preservation overlapped the single freeze descriptor")
  when (svbFastLeaseRevoked) {
    // Replacement, probe invalidation or a new image can retire this slot
    // before the held store returns. Revoke only the bypass permission;
    // never invalidate/free the retained version or manufacture a receipt.
    svbFastLineValid := false.B
    svbFastReleaseCycle := io.csr_cycle
    printf("FASTLINE_RELEASE cycle=%x line=%x set=%x tag=%x seq=%x epoch=%x acquire_cycle=%x release_reason=resident_identity_revoked\n",
      io.csr_cycle, svbFastLine, svbFastSet, svbFastTag, svbFastSeq,
      svbFastEpoch, svbFastAcquireCycle)
  }
  when (RegNext(svbFastLeaseRevoked, false.B)) {
    assert(!svbFastLineValid, "DEADLOCK-1: stale fast-line lease survived revocation")
  }
  when (crossPackageBlockWithoutFastLine && svbFastLineValid && !svbFastRequestSameLine) {
    assert(crossPackageBlockCondition,
      "WB-1: unrelated preservation waits for a fast-line lease before WB admission")
  }
  when (svbCapturePending && !svbCaptureIssued && !svbCaptureResidentMatch) {
    // A probe/replacement won the race before snapshot admission. The
    // existing WaitSafe path will retry from the live metadata identity.
    svbCapturePending := false.B
  }
  val crossPackagePendingLine = crossPackagePending &&
    s2_type.isOneOf(t_lsu, t_replay) && isWrite(s2_req(0).uop.mem_cmd) &&
    s2_req(0).addr(idxMSB, idxLSB) === crossPackagePendingSet &&
    (s2_req(0).addr >> untagBits) === crossPackagePendingTag
  // A clear cannot revoke a slot while an MSHR still owns the same line.  The
  // owner must either finish its refill/replay or be explicitly killed by the
  // existing fence/probe machinery before the shadow handoff proceeds.
  val crossPackagePendingAddr = Wire(UInt(coreMaxAddrBits.W))
  crossPackagePendingAddr := (Cat(crossPackagePendingTag, crossPackagePendingSet) << blockOffBits).pad(coreMaxAddrBits)
  val crossPackageMshrConflict = crossPackagePending &&
    (0 until cfg.nMSHRs).map(i => mshrs.io.owner_line_valid(i) &&
      mshrs.io.owner_line_addr(i)(coreMaxAddrBits-1, blockOffBits) ===
        crossPackagePendingAddr(coreMaxAddrBits-1, blockOffBits)).reduce(_ || _)
  val crossPackageSlotConflict = crossPackagePending &&
    (0 until cfg.nMSHRs).map(i => mshrs.io.owner_line_valid(i) &&
      mshrs.io.owner_line_addr(i)(idxMSB, blockOffBits) ===
        crossPackagePendingAddr(idxMSB, blockOffBits) &&
      mshrs.io.owner_line_way(i) === UIntToOH(crossPackagePendingWay)).reduce(_ || _)
  val svbCapturePendingAddr = Wire(UInt(coreMaxAddrBits.W))
  svbCapturePendingAddr := (Cat(svbFastTag, svbFastSet) << blockOffBits).pad(coreMaxAddrBits)
  val svbCaptureMshrConflict = svbCapturePending &&
    (0 until cfg.nMSHRs).map(i => mshrs.io.owner_line_valid(i) &&
      mshrs.io.owner_line_addr(i)(coreMaxAddrBits-1, blockOffBits) ===
        svbCapturePendingAddr(coreMaxAddrBits-1, blockOffBits)).reduce(_ || _)
  val svbCaptureSlotConflict = svbCapturePending &&
    (0 until cfg.nMSHRs).map(i => mshrs.io.owner_line_valid(i) &&
      mshrs.io.owner_line_addr(i)(idxMSB, blockOffBits) ===
        svbCapturePendingAddr(idxMSB, blockOffBits) &&
      mshrs.io.owner_line_way(i) === UIntToOH(svbFastWay)).reduce(_ || _)
  val svbCaptureDrained = !(s3_valid && s3_req.addr(idxMSB, idxLSB) === svbFastSet) &&
    !completionPending(svbFastSet).asUInt.orR &&
    !(0 until memWidth).map(w =>
      (s1_valid(w) && s1_type === t_lsu && s1_req(w).addr(idxMSB, idxLSB) === svbFastSet) ||
      (s2_valid(w) && s2_type === t_lsu && s2_req(w).addr(idxMSB, idxLSB) === svbFastSet)).reduce(_ || _)
  svbCaptureWbReq.valid := svbCapturePending && !svbCaptureIssued && svbCaptureDrained &&
    svbCaptureResidentMatch && !crossPackagePending &&
    !(prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === svbFastSet) &&
    !svbCaptureMshrConflict && !svbCaptureSlotConflict
  // WaitSafe ends on the first safe watermark observation.  The conservative
  // entry relaxation is disabled before the voluntary WB can be issued and
  // remains disabled through receipt, metadata clear, and slot revocation.
  // Keeping the existing drain predicate in this window means previously
  // accepted lookups still drain before the snapshot is captured.
  clearFreezeReadBypassWindow := crossPackagePending && !svbCapturePending && crossPackageResidentMatch &&
    !crossPackageIssued && !crossPackageMetaClearPending &&
    !crossPackageSlotConflict && !crossPackageMetaClearBlock &&
    !completionPending(crossPackagePendingSet)(crossPackagePendingWay) &&
    !(prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === crossPackagePendingSet) &&
    !L1Preservation.safe(imageKey(crossPackagePendingSet)(crossPackagePendingWay), safePacketWatermark)
  l1CrossPackageBlocked := crossPackageDomainWait || crossPackagePendingLine

  crossPackageWbReq.valid := crossPackagePending &&
    crossPackageResidentMatch &&
    !crossPackageIssued &&
    !crossPackageMetaClearPending &&
    !crossPackageSlotConflict && !crossPackageMetaClearBlock &&
    !completionPending(crossPackagePendingSet)(crossPackagePendingWay) &&
    !(prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === crossPackagePendingSet) &&
    L1Preservation.safe(imageKey(crossPackagePendingSet)(crossPackagePendingWay), safePacketWatermark)
  crossPackageWbReq.bits := DontCare
  crossPackageWbReq.bits.source := cfg.nMSHRs.U
  crossPackageWbReq.bits.idx := crossPackagePendingSet
  crossPackageWbReq.bits.tag := crossPackagePendingTag
  // A shadow writeback invalidates the local copy.  Report T->N to L2 so its
  // coherence state agrees with the metadata clear performed below.
  crossPackageWbReq.bits.param :=
    residentCoh(crossPackagePendingSet)(crossPackagePendingWay).onCacheControl(M_FLUSH)._2
  crossPackageWbReq.bits.way_en := UIntToOH(crossPackagePendingWay)
  crossPackageWbReq.bits.voluntary := true.B
  crossPackageWbReq.bits.svb_capture := false.B
  val preservationWaitLine = Mux(crossPackagePending, crossPackagePendingAddr,
    (s2_req(0).addr >> blockOffBits) << blockOffBits)
  val preservationMshrSameLineMask = VecInit((0 until cfg.nMSHRs).map(i =>
    mshrs.io.owner_line_valid(i) &&
      mshrs.io.owner_line_addr(i)(coreMaxAddrBits-1, blockOffBits) ===
        preservationWaitLine(coreMaxAddrBits-1, blockOffBits))).asUInt

  // Long-stall snapshots are sparse and observational. The host collector
  // keeps only a bounded tail and writes it only when the simulator fails.
  def diagnosticAgeReached(age: UInt): Bool =
    age === 4095.U || age === 16383.U || age === 65535.U || age === 131071.U
  val preservationWaitActive = crossPackageDomainWait || crossPackagePending || svbCapturePending
  val preservationWaitAge = RegInit(0.U(32.W))
  val probeBusyAge = RegInit(0.U(32.W))
  val writebackBusy = wb.io.idx.valid || wb.io.pending_idx.valid
  val writebackBusyAge = RegInit(0.U(32.W))
  val promotionBusy = svb.io.promote.valid || wb.io.pending_svb
  val promotionBusyAge = RegInit(0.U(32.W))
  val preservationAgeReported = RegInit(false.B)
  val probeBusyAgeReported = RegInit(false.B)
  val writebackBusyAgeReported = RegInit(false.B)
  val promotionBusyAgeReported = RegInit(false.B)
  val fastLineAge = RegInit(0.U(32.W))
  val fastLineAgeReported = RegInit(false.B)
  val probeBlockedBySvb = tl_out.b.valid && svb.io.releaseBlocked(3)
  val probeBlockedAge = RegInit(0.U(32.W))
  val probeBlockedAgeReported = RegInit(false.B)
  val mshrAges = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(0.U(32.W))))
  val mshrAgeReported = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(false.B)))
  val mshrPrevValid = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(false.B)))
  val mshrPrevState = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(0.U(5.W))))
  val mshrPrevLine = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(0.U(coreMaxAddrBits.W))))
  val mshrPrevWait = RegInit(VecInit(Seq.fill(cfg.nMSHRs)(0.U(4.W))))
  when (!preservationWaitActive) { preservationWaitAge := 0.U }
    .elsewhen (preservationWaitAge =/= ~0.U(32.W)) { preservationWaitAge := preservationWaitAge + 1.U }
  when (!prober.io.state.valid) { probeBusyAge := 0.U }
    .elsewhen (probeBusyAge =/= ~0.U(32.W)) { probeBusyAge := probeBusyAge + 1.U }
  when (!writebackBusy) { writebackBusyAge := 0.U }
    .elsewhen (writebackBusyAge =/= ~0.U(32.W)) { writebackBusyAge := writebackBusyAge + 1.U }
  when (!promotionBusy) { promotionBusyAge := 0.U }
    .elsewhen (promotionBusyAge =/= ~0.U(32.W)) { promotionBusyAge := promotionBusyAge + 1.U }
  when (!preservationWaitActive) { preservationAgeReported := false.B }
  when (!prober.io.state.valid) { probeBusyAgeReported := false.B }
  when (!writebackBusy) { writebackBusyAgeReported := false.B }
  when (!promotionBusy) { promotionBusyAgeReported := false.B }
  when (preservationWaitActive && preservationWaitAge === 65535.U && !preservationAgeReported) {
    printf("LONG_STALL object=PRESERVATION cycle=%x age=%x line=%x seq=%x pending=%x fastline_valid=%x fastline=%x lower_preserved=%x watermark=%x waiting_reason=%x\n",
      io.csr_cycle, preservationWaitAge, preservationWaitLine,
      Mux(crossPackagePending, crossPackagePendingSeq, s2_req(0).packet_seq),
      crossPackagePending, svbFastLineValid, svbFastLine,
      lowerPreserved(s2_store_set)(s2_store_way), safePacketWatermark,
      Mux(svbFastLineValid && !svbFastLineMatch, 1.U,
        Mux(!L1Preservation.safe(s2_overwrittenKey, safePacketWatermark), 2.U, 3.U)))
    preservationAgeReported := true.B
  }
  when (prober.io.state.valid && probeBusyAge === 65535.U && !probeBusyAgeReported) {
    printf("LONG_STALL object=PROBE_FSM cycle=%x age=%x line=%x state=%x waiting_reason=%x wb_pending=%x wb_line=%x\n",
      io.csr_cycle, probeBusyAge, prober.io.state.bits,
      prober.io.diagnosticState, Mux(prober.io.diagnosticState === 8.U, 1.U, 2.U),
      wb.io.pending_idx.valid, wb.io.pending_line)
    probeBusyAgeReported := true.B
  }
  when (writebackBusy && writebackBusyAge === 65535.U && !writebackBusyAgeReported) {
    printf("LONG_STALL object=WB cycle=%x age=%x owner=%x owner_type=%x line=%x mshr=%x svb=%x probe=%x state=%x waiting_reason=%x sent=%x source_busy=%x\n",
      io.csr_cycle, writebackBusyAge, wb.io.pending_idx.valid, wb.io.pending_svb,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      wbArb.io.chosen === 1.U, wb.io.pending_svb, prober.io.state.valid,
      wb.io.debug_state, Mux(!wb.io.pending_sent, 1.U, 2.U), wb.io.pending_sent,
      releaseSourceBusy)
    writebackBusyAgeReported := true.B
  }
  when (promotionBusy && promotionBusyAge === 65535.U && !promotionBusyAgeReported) {
    printf("LONG_STALL object=SVB_PROMOTION cycle=%x age=%x entry=%x line=%x seq=%x state=%x safe=%x selected=%x waiting_reason=%x wb_state=%x\n",
      io.csr_cycle, promotionBusyAge, svb.io.activeEntry, svb.io.activeLine,
      svb.io.activeKey.contentSeq, wb.io.pending_svb,
      svb.io.activeKey.contentSeq <= safePacketWatermark, svb.io.selected,
      Mux(wb.io.pending_idx.valid, 1.U, Mux(!svb.io.promote.ready, 2.U, 3.U)),
      wb.io.debug_state)
    promotionBusyAgeReported := true.B
  }

  val preservationWaitPrevious = RegInit(false.B)
  when (crossPackageDomainWait && !preservationWaitPrevious) {
    printf("PRESERVATION_WAIT cycle=%x line=%x request_type=%x request_seq=%x old_seq=%x old_generation=%x watermark=%x handoff_valid=%x handoff_ready=%x handoff_fire=%x wb_valid=%x wb_ready=%x wb_fire=%x pending=%x blocked_fastline=%x fast_line=%x fast_seq=%x capture_pending=%x slot_reserved=%x nack_hit=%x lookup_epoch=%x live_epoch=%x probe_same_set=%x mshr_same_line=%x reason=%x\n",
      io.csr_cycle, (s2_req(0).addr >> blockOffBits) << blockOffBits,
      s2_req(0).uop.mem_cmd, s2_req(0).packet_seq, s2_overwrittenKey.contentSeq,
      s2_overwrittenKey.generation, safePacketWatermark,
      crossPackageDomainWait, crossPackageBlockCondition,
      crossPackageDomainWait && crossPackageBlockCondition,
      crossPackageWbReq.valid, crossPackageWbReq.ready, crossPackageWbReq.fire,
      crossPackagePending, svbFastLineValid && !svbFastLineMatch, svbFastLine,
      svbFastSeq, svbCapturePending, slotReserved(s2_store_set)(s2_store_way), s2_nack_hit(0),
      s2_lookup_epoch(0), slotEpoch(s2_store_set)(s2_store_way),
      prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === s2_store_set,
      preservationMshrSameLineMask,
      Mux(svbFastLineValid && !svbFastLineMatch, 1.U,
        Mux(slotReserved(s2_store_set)(s2_store_way), 2.U,
          Mux(s2_nack_hit(0), 3.U, Mux(s2_lookup_epoch(0) =/= slotEpoch(s2_store_set)(s2_store_way), 4.U, 0.U))))
    )
  }
  preservationWaitPrevious := crossPackageDomainWait

  val preservationPendingProbeConflict = prober.io.state.valid &&
    prober.io.state.bits(idxMSB, idxLSB) === crossPackagePendingSet
  val preservationWBBlocked = crossPackagePending && !crossPackageIssued &&
    !crossPackageMetaClearPending && !crossPackageWbReq.fire &&
    (!crossPackageWbReq.valid || !crossPackageWbReq.ready)
  val preservationWBWaitingReason = Mux(!crossPackageResidentMatch, 1.U,
    Mux(crossPackageSlotConflict, 2.U, Mux(crossPackageMetaClearBlock, 3.U,
      Mux(completionPending(crossPackagePendingSet)(crossPackagePendingWay), 4.U,
        Mux(preservationPendingProbeConflict, 5.U,
          Mux(!L1Preservation.safe(crossPackagePendingKey, safePacketWatermark), 6.U,
            Mux(crossPackageWbReq.valid && !crossPackageWbReq.ready, 7.U, 8.U)))))))
  val preservationWBBlockedPrevious = RegInit(false.B)
  val preservationWBBlockedReasonPrevious = RegInit(0.U(4.W))
  when (!preservationWBBlocked) { preservationWBBlockedPrevious := false.B }
  when (preservationWBBlocked && (!preservationWBBlockedPrevious ||
    preservationWBWaitingReason =/= preservationWBBlockedReasonPrevious)) {
    printf("PRESERVATION_BLOCKED cycle=%x line=%x seq=%x generation=%x request_valid=%x request_ready=%x request_fire=%x blocked_fastline=%x fast_line=%x slot_conflict=%x meta_clear_block=%x completion_pending=%x probe_same_set=%x mshr_same_line=%x safe=%x wb_pending=%x wb_pending_svb=%x wb_line=%x wb_source_busy=%x waiting_reason=%x\n",
      io.csr_cycle, crossPackagePendingAddr, crossPackagePendingSeq,
      crossPackagePendingKey.generation, crossPackageWbReq.valid,
      crossPackageWbReq.ready, crossPackageWbReq.fire,
      svbFastLineValid && !svbFastLineMatch, svbFastLine,
      crossPackageSlotConflict, crossPackageMetaClearBlock,
      completionPending(crossPackagePendingSet)(crossPackagePendingWay),
      preservationPendingProbeConflict,
      preservationMshrSameLineMask,
      L1Preservation.safe(crossPackagePendingKey, safePacketWatermark),
      wb.io.pending_idx.valid, wb.io.pending_svb,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      releaseSourceBusy,
      preservationWBWaitingReason)
    preservationWBBlockedPrevious := true.B
    preservationWBBlockedReasonPrevious := preservationWBWaitingReason
  }

  val blockedWbArb = wbArb.io.out.valid && !wbArb.io.out.ready
  val blockedWbPrevious = RegInit(false.B)
  when (blockedWbArb && !blockedWbPrevious) {
    printf("WB_BLOCK cycle=%x owner_type=%x line=%x mshr=%x svb=%x probe=%x wb_state=%x wb_pending=%x pending_svb=%x pending_line=%x source_busy=%x waiting_reason=%x\n",
      io.csr_cycle, wbArb.io.chosen, wbLine(wbArb.io.out.bits),
      wbArb.io.chosen === 1.U, wbArb.io.chosen === 2.U,
      wbArb.io.chosen === 0.U, wb.io.debug_state, wb.io.pending_idx.valid,
      wb.io.pending_svb, wb.io.pending_line, releaseSourceBusy,
      Mux(wb.io.debug_state === 0.U, 0.U, Mux(wb.io.pending_idx.valid, 2.U, 1.U)))
  }
  blockedWbPrevious := blockedWbArb
  val promotionSourceBlocked = svb.io.promote.valid && !svb.io.promote.ready
  val promotionSourceBlockedPrevious = RegNext(promotionSourceBlocked, false.B)
  when (promotionSourceBlocked && !promotionSourceBlockedPrevious) {
    printf("WB_BLOCK cycle=%x owner_type=SVB_PROMOTION entry=%x line=%x seq=%x wb_state=%x wb_pending=%x pending_svb=%x pending_line=%x source_busy=%x waiting_reason=shared_writeback_source\n",
      io.csr_cycle, svb.io.activeEntry, svb.io.activeLine,
      svb.io.activeKey.contentSeq, wb.io.debug_state, wb.io.pending_idx.valid,
      wb.io.pending_svb, wb.io.pending_line, releaseSourceBusy)
  }

  val probeWasValid = RegNext(prober.io.state.valid, false.B)
  val probePreviousLine = RegNext(prober.io.state.bits)
  val probeBlockedPrevious = RegInit(false.B)
  when (probeBlockedBySvb && !probeBlockedPrevious) {
    val entry = svb.io.releaseBlockingEntry(3)
    printf("PROBE_BLOCKED cycle=%x line=%x probe_valid=%x probe_state=%x blocked_retained_svb=%x fastline_valid=%x fastline_same_line=%x blocking_entry=%x blocking_line=%x blocking_seq=%x blocking_generation=%x reason=svb_release_blocked\n",
      io.csr_cycle, (tl_out.b.bits.address >> blockOffBits) << blockOffBits,
      prober.io.state.valid, prober.io.diagnosticState, svb.io.releaseBlocked(3),
      svbFastLineValid, svbFastLine === ((tl_out.b.bits.address >> blockOffBits) << blockOffBits),
      entry, svb.io.releaseBlockingLine(3), svb.io.releaseBlockingSeq(3),
      svb.io.releaseBlockingGeneration(3))
  }
  probeBlockedPrevious := probeBlockedBySvb
  when (prober.io.req.fire) {
    printf("PROBE_START cycle=%x line=%x state=%x retained_svb_block=%x fastline_valid=%x fastline_same_line=%x\n",
      io.csr_cycle, (tl_out.b.bits.address >> blockOffBits) << blockOffBits,
      prober.io.diagnosticState, svb.io.releaseBlocked(3), svbFastLineValid,
      svbFastLine === ((tl_out.b.bits.address >> blockOffBits) << blockOffBits))
  }
  when (probeWasValid && !prober.io.state.valid) {
    lastProbeCompletionCycle := io.csr_cycle
    printf("PROBE_COMPLETE cycle=%x line=%x\n", io.csr_cycle, probePreviousLine)
  }

  when (wb.io.req.fire) {
    wbOwnerType := wbArb.io.chosen
    wbOwnerSource := wbArb.io.out.bits.source
    printf("WB_START cycle=%x owner_type=%x line=%x mshr=%x svb=%x probe=%x source=%x wb_state=%x request_valid=%x\n",
      io.csr_cycle, wbArb.io.chosen, wbLine(wbArb.io.out.bits),
      wbArb.io.chosen === 1.U, wbArb.io.chosen === 2.U,
      wbArb.io.chosen === 0.U, wbArb.io.out.bits.source, wb.io.debug_state,
      wb.io.req.valid)
  }
  when (wb.io.done.valid || wb.io.svb_done.valid || wb.io.probe_done) {
    lastWbCompletionCycle := io.csr_cycle
    when (wb.io.svb_done.valid) { lastSvbCompletionCycle := io.csr_cycle }
    printf("WB_COMPLETE cycle=%x kind=%x line=%x entry=%x seq=%x generation=%x probe=%x\n",
      io.csr_cycle, Mux(wb.io.svb_done.valid, 2.U, Mux(wb.io.probe_done, 3.U, 1.U)),
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      wb.io.pending_entry, wb.io.pending_key.contentSeq, wb.io.pending_key.generation,
      wb.io.probe_done)
  }
  when (!svbFastLineValid) {
    fastLineAge := 0.U
    fastLineAgeReported := false.B
  }.otherwise {
    when (fastLineAge =/= ~0.U(32.W)) { fastLineAge := fastLineAge + 1.U }
    when (fastLineAge === 65535.U && !fastLineAgeReported) {
      printf("LONG_STALL object=FAST_LINE cycle=%x age=%x line=%x set=%x tag=%x seq=%x epoch=%x owner_state=%x acquire_cycle=%x waiting_reason=matching_semantic_write_or_epoch_flush\n",
        io.csr_cycle, fastLineAge, svbFastLine, svbFastSet, svbFastTag,
        svbFastSeq, svbFastEpoch, Mux(svbCapturePending, 1.U, 2.U), svbFastAcquireCycle)
      fastLineAgeReported := true.B
    }
  }
  when (!probeBlockedBySvb) {
    probeBlockedAge := 0.U
    probeBlockedAgeReported := false.B
  }.otherwise {
    when (probeBlockedAge =/= ~0.U(32.W)) { probeBlockedAge := probeBlockedAge + 1.U }
    when (probeBlockedAge === 65535.U && !probeBlockedAgeReported) {
      val blockedEntry = svb.io.releaseBlockingEntry(3)
      printf("LONG_STALL object=PROBE_INGRESS cycle=%x age=%x line=%x entry=%x owner_seq=%x owner_generation=%x fastline_valid=%x fastline=%x waiting_reason=retained_svb_blocks_b_ready\n",
        io.csr_cycle, probeBlockedAge,
        (tl_out.b.bits.address >> blockOffBits) << blockOffBits,
        blockedEntry, svb.io.activeKey.contentSeq, svb.io.activeKey.generation,
        svbFastLineValid, svbFastLine)
      probeBlockedAgeReported := true.B
    }
  }
  for (i <- 0 until cfg.nMSHRs) {
    val activeMshr = mshrs.io.owner_line_valid(i)
    val mshrLine = mshrs.io.owner_line_addr(i)
    val mshrStateChanged = activeMshr && (!mshrPrevValid(i) ||
      mshrs.io.debug_state(i) =/= mshrPrevState(i) || mshrLine =/= mshrPrevLine(i))
    when (mshrStateChanged) {
      printf("MSHR_STATE cycle=%x entry=%x line=%x state=%x waiting_resource=%x wb_dependency=%x probe_dependency=%x svb_dependency=%x fastline_valid=%x fastline=%x\n",
        io.csr_cycle, i.U, mshrLine, mshrs.io.debug_state(i),
        mshrs.io.debug_waiting_resource(i),
        mshrs.io.debug_state(i) === 9.U || mshrs.io.debug_state(i) === 10.U,
        prober.io.state.valid && prober.io.state.bits(coreMaxAddrBits-1, blockOffBits) ===
          mshrLine(coreMaxAddrBits-1, blockOffBits),
        svb.io.releaseBlocked(1) && svb.io.releaseLines(1) === mshrLine,
        svbFastLineValid, svbFastLine)
      mshrAges(i) := 0.U
      mshrAgeReported(i) := false.B
    }.elsewhen (!activeMshr) {
      mshrAges(i) := 0.U
      mshrAgeReported(i) := false.B
    }.otherwise {
      when (mshrAges(i) =/= ~0.U(32.W)) { mshrAges(i) := mshrAges(i) + 1.U }
      when (mshrAges(i) === 65535.U && !mshrAgeReported(i)) {
        printf("LONG_STALL object=MSHR cycle=%x age=%x entry=%x line=%x state=%x waiting_resource=%x wb_dependency=%x probe_dependency=%x svb_dependency=%x fastline_valid=%x fastline=%x\n",
          io.csr_cycle, mshrAges(i), i.U, mshrLine, mshrs.io.debug_state(i),
          mshrs.io.debug_waiting_resource(i),
          mshrs.io.debug_state(i) === 9.U || mshrs.io.debug_state(i) === 10.U,
          prober.io.state.valid && prober.io.state.bits(coreMaxAddrBits-1, blockOffBits) ===
            mshrLine(coreMaxAddrBits-1, blockOffBits),
          svb.io.releaseBlocked(1) && svb.io.releaseLines(1) === mshrLine,
          svbFastLineValid, svbFastLine)
        mshrAgeReported(i) := true.B
      }
    }
    when (mshrPrevValid(i) && !activeMshr) {
      lastMshrFreeCycle := io.csr_cycle
      printf("MSHR_FREE cycle=%x entry=%x line=%x state=%x waiting_resource=%x\n",
        io.csr_cycle, i.U, mshrPrevLine(i), mshrPrevState(i), mshrPrevWait(i))
    }
    mshrPrevValid(i) := activeMshr
    mshrPrevState(i) := mshrs.io.debug_state(i)
    mshrPrevLine(i) := mshrLine
    mshrPrevWait(i) := mshrs.io.debug_waiting_resource(i)
  }

  val preservationWaitDiagnostic = preservationWaitActive && diagnosticAgeReached(preservationWaitAge)
  val probeBusyDiagnostic = prober.io.state.valid && diagnosticAgeReached(probeBusyAge)
  val writebackBusyDiagnostic = writebackBusy && diagnosticAgeReached(writebackBusyAge)
  val promotionBusyDiagnostic = promotionBusy && diagnosticAgeReached(promotionBusyAge)
  svbDiagnosticDump := preservationWaitDiagnostic || probeBusyDiagnostic ||
    writebackBusyDiagnostic || promotionBusyDiagnostic ||
    (dcacheWatchdogSnapshot && !dcacheWatchdogSnapshotPrinted)

  when (preservationWaitDiagnostic) {
    printf("CACHE_HANG_SNAPSHOT reason=PRESERVATION_WAIT cycle=%x age=%x line=%x seq=%x old_seq=%x old_generation=%x watermark=%x lower_preserved=%x pending=%x block_condition=%x eligible=%x capture_pending=%x capture_issued=%x fast_line=%x nack_hit=%x nack=%x nack_victim=%x nack_wb=%x slot_reserved=%x lookup_epoch=%x live_epoch=%x probe_valid=%x probe_line=%x probe_phase=%x probe_same_set=%x probe_drain_ready=%x wb_active=%x wb_pending=%x wb_pending_svb=%x wb_sent=%x wb_line=%x wb_source_busy=%x mshr_active=%x mshr_same_line=%x mshr_conflict=%x svb_occupancy=%x svb_active=%x svb_active_line=%x svb_active_seq=%x\n",
      io.csr_cycle, preservationWaitAge,
      preservationWaitLine,
      Mux(crossPackagePending, crossPackagePendingSeq, s2_req(0).packet_seq),
      s2_overwrittenKey.contentSeq, s2_overwrittenKey.generation,
      safePacketWatermark, lowerPreserved(s2_store_set)(s2_store_way),
      crossPackagePending, crossPackageBlockCondition, svbEligibleCandidate,
      svbCapturePending, svbCaptureIssued, svbFastLineValid,
      s2_nack_hit(0), s2_nack(0), s2_nack_victim(0), s2_nack_wb(0),
      slotReserved(s2_store_set)(s2_store_way), s2_lookup_epoch(0),
      slotEpoch(s2_store_set)(s2_store_way), prober.io.state.valid,
      prober.io.state.bits, prober.io.diagnosticState,
      prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === s2_store_set,
      probeDrainReady, wb.io.idx.valid, wb.io.pending_idx.valid,
      wb.io.pending_svb, wb.io.pending_sent,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      releaseSourceBusy, mshrs.io.active_transactions,
      preservationMshrSameLineMask, crossPackageMshrConflict, svb.io.occupancy, svb.io.promote.valid,
      svb.io.activeLine, svb.io.activeKey.contentSeq)
  }
  when (probeBusyDiagnostic) {
    printf("CACHE_HANG_SNAPSHOT reason=PROBE_BUSY cycle=%x age=%x line=%x phase=%x drain_ready=%x wb_active=%x wb_pending=%x wb_line=%x svb_occupancy=%x svb_blocked_ingress=%x svb_blocked_wb=%x mshr_active=%x\n",
      io.csr_cycle, probeBusyAge, prober.io.state.bits, prober.io.diagnosticState,
      probeDrainReady, wb.io.idx.valid, wb.io.pending_idx.valid,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      svb.io.occupancy, svb.io.releaseBlocked(3), svb.io.releaseBlocked(0),
      mshrs.io.active_transactions)
  }
  when (writebackBusyDiagnostic) {
    printf("CACHE_HANG_SNAPSHOT reason=WB_BUSY cycle=%x age=%x active=%x pending=%x pending_svb=%x entry=%x sent=%x line=%x key_seq=%x key_generation=%x source_busy=%x probe_valid=%x probe_line=%x mshr_active=%x\n",
      io.csr_cycle, writebackBusyAge, wb.io.idx.valid, wb.io.pending_idx.valid,
      wb.io.pending_svb, wb.io.pending_entry, wb.io.pending_sent,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      wb.io.pending_key.contentSeq, wb.io.pending_key.generation,
      releaseSourceBusy, prober.io.state.valid, prober.io.state.bits,
      mshrs.io.active_transactions)
  }
  when (promotionBusyDiagnostic) {
    printf("CACHE_HANG_SNAPSHOT reason=SVB_PROMOTION cycle=%x age=%x promote_valid=%x entry=%x line=%x seq=%x generation=%x wb_active=%x wb_pending=%x wb_pending_svb=%x wb_sent=%x source_busy=%x\n",
      io.csr_cycle, promotionBusyAge, svb.io.promote.valid,
      svb.io.activeEntry, svb.io.activeLine, svb.io.activeKey.contentSeq,
      svb.io.activeKey.generation, wb.io.idx.valid, wb.io.pending_idx.valid,
      wb.io.pending_svb, wb.io.pending_sent, releaseSourceBusy)
  }
  val fastOwnerS1Present = svbFastLineValid && s1_valid(0) && s1_type === t_lsu &&
    s1_req(0).packet_seq === svbFastSeq && s1_req(0).addr(idxMSB, idxLSB) === svbFastSet &&
    (s1_req(0).addr >> untagBits) === svbFastTag
  val fastOwnerS2Present = svbFastLineValid && s2_valid(0) && s2_type.isOneOf(t_lsu, t_replay) &&
    s2_req(0).packet_seq === svbFastSeq && s2_req(0).addr(idxMSB, idxLSB) === svbFastSet &&
    (s2_req(0).addr >> untagBits) === svbFastTag
  val fastOwnerS3Present = svbFastLineValid && s3_valid &&
    s3_req.packet_seq === svbFastSeq && s3_req.addr(idxMSB, idxLSB) === svbFastSet &&
    (s3_req.addr >> untagBits) === svbFastTag
  val fastOwnerState = Mux(svbCapturePending, 1.U,
    Mux(fastOwnerS3Present, 4.U, Mux(fastOwnerS2Present, 3.U,
      Mux(fastOwnerS1Present, 2.U, 5.U))))
  when (dcacheWatchdogSnapshot && !dcacheWatchdogSnapshotPrinted) {
    dcacheWatchdogSnapshotPrinted := true.B
    printf("DCACHE_WATCHDOG_SNAPSHOT cycle=%x watermark=%x fast_valid=%x fast_line=%x fast_set=%x fast_tag=%x fast_seq=%x fast_epoch=%x fast_generation=%x fast_state=%x fast_s1=%x fast_s2=%x fast_s3=%x fast_acquire_cycle=%x fast_release_cycle=%x capture_pending=%x capture_issued=%x svb_occupancy=%x svb_active=%x svb_entry=%x svb_line=%x svb_seq=%x wb_state=%x wb_owner_type=%x wb_owner_source=%x wb_mshr_assoc=%x wb_probe_assoc=%x wb_capture_assoc=%x wb_preservation_assoc=%x wb_waiting_reason=%x wb_valid=%x wb_pending=%x wb_pending_svb=%x wb_entry=%x wb_line=%x wb_sent=%x source_busy=%x source_sent=%x probe_valid=%x probe_line=%x probe_state=%x probe_drain_ready=%x probe_svb_blocked=%x probe_block_entry=%x probe_block_line=%x probe_block_seq=%x probe_block_generation=%x mshr_active=%x mshr_same_line=%x preservation_wait=%x preservation_line=%x preservation_seq=%x preservation_pending=%x preservation_block_condition=%x promotion_valid=%x promotion_selected=%x promotion_safe=%x promotion_entry=%x promotion_line=%x promotion_seq=%x pending_target=%x pending_target_seq=%x safe_watermark=%x c_source_busy=%x c_source_sent=%x d_ack_pending=%x d_ack_matched=%x last_lsu=%x last_watermark=%x last_checker_result=%x last_wb=%x last_probe=%x last_mshr_free=%x last_svb=%x\n",
      io.csr_cycle, safePacketWatermark,
      svbFastLineValid, svbFastLine, svbFastSet, svbFastTag, svbFastSeq,
      svbFastEpoch, svbFastKey.generation, fastOwnerState,
      fastOwnerS1Present, fastOwnerS2Present, fastOwnerS3Present,
      svbFastAcquireCycle, svbFastReleaseCycle, svbCapturePending,
      svbCaptureIssued, svb.io.occupancy, svb.io.promote.valid,
      svb.io.activeEntry, svb.io.activeLine, svb.io.activeKey.contentSeq,
      wb.io.debug_state, Mux(wb.io.pending_svb, 4.U, wbOwnerType), wbOwnerSource,
      wb.io.pending_idx.valid && !wb.io.pending_svb && wbOwnerType === 1.U,
      wb.io.pending_idx.valid && !wb.io.pending_svb && wbOwnerType === 0.U,
      svbCapturePending,
      wb.io.pending_idx.valid && !wb.io.pending_svb && wbOwnerType === 3.U,
      Mux(!wb.io.pending_idx.valid, Mux(wb.io.idx.valid, 3.U, 0.U),
        Mux(wb.io.pending_sent, 2.U, 1.U)), wb.io.idx.valid,
      wb.io.pending_idx.valid, wb.io.pending_svb, wb.io.pending_entry,
      Mux(wb.io.pending_idx.valid, wb.io.pending_line, wb.io.snapshot_line),
      wb.io.pending_sent, releaseSourceBusy, releaseSourceSent,
      prober.io.state.valid, prober.io.state.bits, prober.io.diagnosticState,
      probeDrainReady, probeBlockedBySvb, svb.io.releaseBlockingEntry(3),
      svb.io.releaseBlockingLine(3), svb.io.releaseBlockingSeq(3),
      svb.io.releaseBlockingGeneration(3), mshrs.io.active_transactions,
      preservationMshrSameLineMask, preservationWaitActive, preservationWaitLine,
      s2_req(0).packet_seq, crossPackagePending, crossPackageBlockCondition,
      svb.io.promote.valid, svb.io.selected,
      svb.io.activeKey.contentSeq <= safePacketWatermark,
      svb.io.activeEntry, svb.io.activeLine,
      svb.io.activeKey.contentSeq, crossPackagePendingAddr,
      crossPackagePendingSeq, safePacketWatermark, releaseSourceBusy,
      releaseSourceSent, wb.io.pending_idx.valid, wbAckMatches,
      lastLsuProgressCycle, lastWatermarkProgressCycle, lastCheckerResultCycle,
      lastWbCompletionCycle, lastProbeCompletionCycle, lastMshrFreeCycle,
      lastSvbCompletionCycle)
    for (i <- 0 until cfg.nMSHRs) {
      when (mshrs.io.owner_line_valid(i)) {
        printf("MSHR_HANG_ENTRY cycle=%x entry=%x line=%x state=%x waiting_resource=%x wb_dependency=%x probe_dependency=%x svb_dependency=%x\n",
          io.csr_cycle, i.U, mshrs.io.owner_line_addr(i), mshrs.io.debug_state(i),
          mshrs.io.debug_waiting_resource(i),
          mshrs.io.debug_state(i) === 9.U || mshrs.io.debug_state(i) === 10.U,
          prober.io.state.valid && prober.io.state.bits(coreMaxAddrBits-1, blockOffBits) ===
            mshrs.io.owner_line_addr(i)(coreMaxAddrBits-1, blockOffBits),
          svb.io.releaseBlocked(1) && svb.io.releaseLines(1) === mshrs.io.owner_line_addr(i))
      }
    }
  }
  when (crossPackageBlockCondition && !crossPackagePending) {
    printf("PRESERVATION_START cycle=%x line=%x request_seq=%x owner_seq=%x owner_generation=%x valid=%x ready=%x fire=%x blocked_fastline=%x fast_line=%x block_condition=%x slot_reserved=%x nack_hit=%x lookup_epoch=%x live_epoch=%x\n",
      io.csr_cycle, (s2_req(0).addr >> blockOffBits) << blockOffBits,
      s2_req(0).packet_seq, s2_overwrittenKey.contentSeq,
      s2_overwrittenKey.generation, crossPackageWbReq.valid,
      crossPackageWbReq.ready, crossPackageWbReq.fire,
      svbFastLineValid && !svbFastLineMatch, svbFastLine,
      crossPackageBlockCondition, slotReserved(s2_store_set)(s2_store_way),
      s2_nack_hit(0), s2_lookup_epoch(0), slotEpoch(s2_store_set)(s2_store_way))
    crossPackagePending := true.B
    crossPackageIssued := false.B
    crossPackagePendingSet := s2_store_set
    crossPackagePendingWay := s2_store_way
    crossPackagePendingTag := (s2_req(0).addr >> untagBits)
    crossPackagePendingSeq := s2_overwrittenPacketSeq
    crossPackagePendingEpoch := slotEpoch(s2_store_set)(s2_store_way)
    crossPackagePendingKey := s2_overwrittenKey
  }
  when (crossPackagePending && !crossPackageIssued && !crossPackageMetaClearPending && crossPackageResidentMatch) {
    // Pre-freeze grants drain before snapshot admission. Their final image is
    // the predecessor to preserve, even if its generation changed while draining.
    crossPackagePendingSeq := imageKey(crossPackagePendingSet)(crossPackagePendingWay).contentSeq
  }
  when (crossPackageWbReq.fire) {
    assert(!crossPackageMetaClearBlock && !crossPackageSlotConflict &&
      imageValid(crossPackagePendingSet)(crossPackagePendingWay),
      "WB snapshot accepted before old grants/install owner drained")
    crossPackageIssued := true.B
    crossPackagePendingKey := imageKey(crossPackagePendingSet)(crossPackagePendingWay)
    printf("STAGE2_TX PRESERVE line=%x epoch=%x gen=%x seq=%x writer=%x valid=%x\n",
      crossPackagePendingAddr, crossPackagePendingEpoch,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).generation,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).contentSeq,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).writer,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).valid)
    printf("PRESERVATION_WB_FIRE cycle=%x line=%x request_seq=%x owner_seq=%x generation=%x valid=%x ready=%x fire=%x wb_state=%x wb_pending=%x\n",
      io.csr_cycle, crossPackagePendingAddr, crossPackagePendingSeq,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).contentSeq,
      imageKey(crossPackagePendingSet)(crossPackagePendingWay).generation,
      crossPackageWbReq.valid, crossPackageWbReq.ready, crossPackageWbReq.fire,
      wb.io.debug_state, wb.io.pending_idx.valid)
  }
  val crossPackageWbDone = crossPackageIssued && wb.io.done.valid &&
    wb.io.done_epoch === crossPackagePendingEpoch && wb.io.done.bits.asUInt === crossPackagePendingKey.asUInt
  val preservationRevoked = prober.io.meta_write.fire &&
    !prober.io.meta_write.bits.data.coh.isValid() &&
    prober.io.meta_write.bits.idx === crossPackagePendingSet &&
    prober.io.meta_write.bits.way_en === UIntToOH(crossPackagePendingWay, nWays)
  when (crossPackageWbDone) {
    crossPackageMetaClearPending := crossPackageResidentMatch && !preservationRevoked
    crossPackageIssued := false.B
    printf("STAGE2_TX PRESERVE_DONE line=%x epoch=%x gen=%x seq=%x writer=%x valid=%x accepted=%x\n",
      crossPackagePendingAddr, crossPackagePendingEpoch, crossPackagePendingKey.generation,
      crossPackagePendingKey.contentSeq, crossPackagePendingKey.writer, crossPackagePendingKey.valid,
      crossPackageResidentMatch && !preservationRevoked)
    printf("PRESERVATION_WB_COMPLETE cycle=%x line=%x seq=%x generation=%x valid=%x ready=%x fire=%x resident_match=%x revoked=%x\n",
      io.csr_cycle, crossPackagePendingAddr, crossPackagePendingKey.contentSeq,
      crossPackagePendingKey.generation, crossPackageWbReq.valid,
      crossPackageWbReq.ready, crossPackageWbDone, crossPackageResidentMatch,
      preservationRevoked)
    when (crossPackageResidentMatch && !preservationRevoked) {
      lowerPreserved(crossPackagePendingSet)(crossPackagePendingWay) := true.B
    }
  }
  val crossPackageMetaClear = Wire(Decoupled(new L1MetaWriteReq))
  metaWriteArb.io.in(2) <> crossPackageMetaClear
  crossPackageMetaClear.valid := crossPackageMetaClearPending &&
    crossPackageResidentMatch &&
    !crossPackageMetaClearBlock && !crossPackageSlotConflict &&
    !(prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === crossPackagePendingSet) &&
    lowerPreserved(crossPackagePendingSet)(crossPackagePendingWay)
  crossPackageMetaClear.bits := DontCare
  crossPackageMetaClear.bits.idx := crossPackagePendingSet
  crossPackageMetaClear.bits.tag := crossPackagePendingTag
  crossPackageMetaClear.bits.way_en := UIntToOH(crossPackagePendingWay)
  crossPackageMetaClear.bits.data.tag := crossPackagePendingTag
  crossPackageMetaClear.bits.data.coh := ClientMetadata.onReset
  when (crossPackageMetaClear.fire) {
    printf("PRESERVATION_COMPLETE cycle=%x line=%x seq=%x epoch=%x valid=%x ready=%x fire=%x\n",
      io.csr_cycle, crossPackagePendingAddr, crossPackagePendingSeq,
      crossPackagePendingEpoch, crossPackageMetaClear.valid,
      crossPackageMetaClear.ready, crossPackageMetaClear.fire)
    printf("STAGE1_TX CLEAR source=DCACHE cycle=%x line=%x set=%x way=%x epoch=%x gen=%x mshr=%x txn=%x token=%x token_valid=%x seq=%x\n",
      io.csr_cycle, (Cat(crossPackagePendingTag, crossPackagePendingSet) << blockOffBits).pad(coreMaxAddrBits),
      crossPackagePendingSet, crossPackagePendingWay,
      crossPackagePendingEpoch,
      lineGeneration(crossPackagePendingSet)(crossPackagePendingWay),
      reservedMshr(crossPackagePendingSet)(crossPackagePendingWay),
      reservedTransaction(crossPackagePendingSet)(crossPackagePendingWay),
      appliedEffectToken(crossPackagePendingSet)(crossPackagePendingWay),
      appliedEffectValid(crossPackagePendingSet)(crossPackagePendingWay),
      crossPackagePendingSeq)
    assert(slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) === crossPackagePendingEpoch,
      "clear descriptor lost resident owner")
    assert(slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) =/= ~0.U(16.W), "slot epoch exhausted")
    crossPackageMetaClearPending := false.B
    crossPackagePending := false.B
    crossPackagePendingSeq := 0.U
    slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) :=
      slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) + 1.U
    appliedEffectValid(crossPackagePendingSet)(crossPackagePendingWay) := false.B
    imageValid(crossPackagePendingSet)(crossPackagePendingWay) := false.B
    lowerPreserved(crossPackagePendingSet)(crossPackagePendingWay) := false.B
  }
  // A legitimate probe may retire the old resident while WaitSafe is parked.
  // Retire that pending clear only after any already-issued WB has finished.
  when (crossPackagePending &&
      !crossPackageResidentMatch &&
      !crossPackageIssued && !wb.io.idx.valid && !wb.io.pending_idx.valid && !crossPackageSlotConflict) {
    crossPackagePending := false.B
    crossPackageMetaClearPending := false.B
  }
  val allocatedNext = WireInit(bitmapAllocated)
  val completedNext = WireInit(bitmapCompleted)
  val passedNext = WireInit(bitmapPassed)
  val seqNext = WireInit(bitmapSeq)
  val allocationCollision = WireDefault(false.B)
  val measuredPacketAlloc = io.packet_alloc_valid && trafficCounting
  val functionalPacketAlloc = io.packet_alloc_valid
  when (functionalPacketAlloc) {
    val idx = io.packet_alloc_seq(statsIndexBits - 1, 0)
    when (io.packet_alloc_seq === 0.U || bitmapAllocated(idx)) {
      allocationCollision := true.B
    }.otherwise {
      allocatedNext(idx) := true.B
      completedNext(idx) := false.B
      passedNext(idx) := false.B
      seqNext(idx) := io.packet_alloc_seq
    }
  }

  val resultAccepted = Wire(Vec(io.checker_results.length, Bool()))
  val resultFailed = Wire(Vec(io.checker_results.length, Bool()))
  val resultCancelled = Wire(Vec(io.checker_results.length, Bool()))
  val resultStale = Wire(Vec(io.checker_results.length, Bool()))
  val resultHeldDuplicate = Wire(Vec(io.checker_results.length, Bool()))
  val resultLevelConsumed = RegInit(VecInit(
    Seq.fill(io.checker_results.length)(false.B)))
  val resultLevelPayload = RegInit(VecInit(Seq.fill(io.checker_results.length)(
    0.U(GH_GlobalParams.GH_CHECKER_RESULT_BITS.W))))
  for (i <- io.checker_results.indices) {
    val result = io.checker_results(i)
    val valid = result(GH_GlobalParams.GH_CHECKER_RESULT_BITS - 1)
    val status = result(GH_GlobalParams.GH_PACKET_SEQ_BITS +
      GH_GlobalParams.GH_CHECKER_STATUS_BITS - 1, GH_GlobalParams.GH_PACKET_SEQ_BITS)
    val seq = result(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, 0)
    val idx = seq(statsIndexBits - 1, 0)
    val allocatedThisCycle = functionalPacketAlloc && io.packet_alloc_seq === seq
    val statusKnown = status =/= 3.U
    val duplicateThisCycle = if (i == 0) false.B else
      (0 until i).map(j => resultAccepted(j) &&
        io.checker_results(j)(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, 0) === seq).reduce(_ || _)
    resultStale(i) := valid && seq =/= 0.U && seq <= safePacketWatermark
    resultAccepted(i) := valid && !resultStale(i) && statusKnown && seq =/= 0.U &&
      ((bitmapAllocated(idx) && bitmapSeq(idx) === seq) || allocatedThisCycle) &&
      !bitmapCompleted(idx) && !duplicateThisCycle
    // A producer may hold one accepted result level until it observes local
    // release. Only an uninterrupted, bit-identical payload on the same
    // checker channel is benign; any changed payload remains an error.
    resultHeldDuplicate(i) := valid && !resultAccepted(i) &&
      resultLevelConsumed(i) && (result === resultLevelPayload(i))
    when (!valid) {
      resultLevelConsumed(i) := false.B
    }.elsewhen (resultAccepted(i)) {
      resultLevelConsumed(i) := true.B
      resultLevelPayload(i) := result
    }
    val pass = status === GH_GlobalParams.GH_CHECKER_STATUS_PASS.U
    resultFailed(i) := resultAccepted(i) &&
      status === GH_GlobalParams.GH_CHECKER_STATUS_FAIL.U
    resultCancelled(i) := resultAccepted(i) &&
      status === GH_GlobalParams.GH_CHECKER_STATUS_CANCELLED.U
    when (resultAccepted(i)) {
      lastCheckerResultCycle := io.csr_cycle
      completedNext(idx) := true.B
      passedNext(idx) := pass
    }
    // Functional PASS/FAIL tracking remains live outside measurement windows.
  }

  val barrierFailureAny = resultFailed.asUInt.orR || resultCancelled.asUInt.orR
  val barrierFailureCandidates = VecInit(io.checker_results.map(result =>
    result(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, 0)))
  val barrierFailureOH = PriorityEncoderOH(
    VecInit(io.checker_results.indices.map(i =>
      resultFailed(i) || resultCancelled(i))).asUInt)
  val barrierFailureSeq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  when (barrierFailureSeq === 0.U && barrierFailureAny) {
    barrierFailureSeq := Mux1H(barrierFailureOH, barrierFailureCandidates)
  }
  val barrierFailureSticky = barrierFailureSeq =/= 0.U
  // Session reset/exception are epoch boundaries. A checker failure only
  // invalidates versions newer than the safe watermark, preserving a safe
  // predecessor that may still be waiting for promotion or ACK.
  svbFlush := io.traffic_reset || io.lsu.exception
  svbInvalidate.valid := barrierFailureAny
  svbInvalidate.bits := safePacketWatermark
  when (io.traffic_reset) {
    svbEpoch := 0.U
  }.elsewhen (io.lsu.exception) {
    when (svbEpoch =/= ~0.U(16.W)) { svbEpoch := svbEpoch + 1.U }
  }
  BoringUtils.addSource(barrierFailureSticky,
    GH_GlobalParams.GH_L2_BARRIER_FAILURE_BORE)
  BoringUtils.addSource(barrierFailureSeq,
    GH_GlobalParams.GH_L2_BARRIER_FAILURE_SEQ_BORE)

  var contiguous = true.B
  var safeAdvance = 0.U((statsIndexBits + 1).W)
  for (offset <- 1 to statsWindow) {
    val seq = safePacketWatermark + offset.U
    val idx = seq(statsIndexBits - 1, 0)
    val slotPass = allocatedNext(idx) && seqNext(idx) === seq &&
      completedNext(idx) && passedNext(idx)
    contiguous = contiguous && slotPass
    safeAdvance = Mux(contiguous, offset.U, safeAdvance)
  }
  val newSafePacketWatermark = safePacketWatermark + safeAdvance

  // Commit-ordered physical-address statistics use the same package bitmap
  // watermark but retain their own tagged table.  The input watermark is the
  // pre-edge value, so a store and a PASS result on the same edge are classified
  // using the safety state that existed when the store committed.
  val addressStatsFatal = WireDefault(false.B)
  val addressStats = Module(new PackageAddressStats(
    coreWidth, coreMaxAddrBits, cfg.blockBytes, statsWindow))
  addressStats.io.resetStats := io.traffic_reset
  addressStats.io.start := io.traffic_start
  addressStats.io.stop := io.traffic_stop
  addressStats.io.events := io.lsu.address_stats_event
  addressStats.io.safeWatermark := safePacketWatermark
  addressStats.io.sequenceBaseline := io.packet_seq_baseline
  addressStats.io.fatalProtocolError := addressStatsFatal

  val safeWatermarkGray = newSafePacketWatermark ^ (newSafePacketWatermark >> 1)
  BoringUtils.addSource(safeWatermarkGray,
    GH_GlobalParams.GH_L1_L2_SAFE_WATERMARK_GRAY_BORE)

  val bitmapAllocatedFinal = WireInit(allocatedNext)
  val bitmapCompletedFinal = WireInit(completedNext)
  val bitmapPassedFinal = WireInit(passedNext)
  for (i <- 0 until statsWindow) {
    when (allocatedNext(i) && seqNext(i) <= newSafePacketWatermark) {
      bitmapAllocatedFinal(i) := false.B
      bitmapCompletedFinal(i) := false.B
      bitmapPassedFinal(i) := false.B
    }
  }
  bitmapAllocated := bitmapAllocatedFinal
  bitmapCompleted := bitmapCompletedFinal
  bitmapPassed := bitmapPassedFinal
  bitmapSeq := seqNext
  when (newSafePacketWatermark =/= safePacketWatermark) {
    lastWatermarkProgressCycle := io.csr_cycle
    printf("WATERMARK_ADVANCE cycle=%x old=%x new=%x\n",
      io.csr_cycle, safePacketWatermark, newSafePacketWatermark)
  }
  safePacketWatermark := newSafePacketWatermark

  // Buckets intentionally use separate storage from the verification bitmap:
  // one package may generate multiple dirty writebacks.
  val bucketState = RegInit(0.U.asTypeOf(new DirtyWritebackBucket(statsWindow)))
  val bucketValid = bucketState.valid
  val bucketSeq = bucketState.seq
  val bucketCount = bucketState.count
  val bucketWritebackCycleSum = bucketState.writebackCycleSum
  val bucketResolve = Wire(Vec(statsWindow, Bool()))
  for (i <- 0 until statsWindow) {
    bucketResolve(i) := bucketValid(i) && bucketSeq(i) <= newSafePacketWatermark
  }
  // 256 buckets can resolve together, and one new writeback can settle on the
  // same edge. Keep a 73rd bit so that all 257 contributions are observable.
  val resolvedBucketsThisCycleWide = (0 until statsWindow).map(i =>
    Mux(bucketResolve(i), bucketCount(i), 0.U(64.W)).pad(73)).reduce(_ + _)
  val writebackCyclesResolvedFromBucketsWide = (0 until statsWindow).map(i =>
    Mux(bucketResolve(i), bucketWritebackCycleSum(i), 0.U(64.W)).pad(73)).reduce(_ + _)

  // A tracked non-zero sequence is the line-level verify_required metadata.
  // The two writeback-time classes are deliberately decided only from the
  // safe watermark sampled before this edge; completion/result details do not
  // change the meaning of "verified at writeback".
  val verifyRequiredDirtyWb = trafficCounting && l1_l2_dirty_wb_event &&
    wb.io.active_packet_tracked && wb.io.active_packet_seq =/= 0.U
  val unverifiedDirtyWb = verifyRequiredDirtyWb &&
    wb.io.active_packet_seq > safePacketWatermark
  // A result and writeback may arrive on the same BOOM edge. Classify against
  // the pre-edge watermark, then settle the new event immediately at zero
  // cycles if this edge also makes its package safe.
  val wbResolvedImmediately = unverifiedDirtyWb &&
    wb.io.active_packet_seq <= newSafePacketWatermark
  val wbBucketIdx = wb.io.active_packet_seq(statsIndexBits - 1, 0)
  val wbBucketAvailable = !bucketValid(wbBucketIdx) || bucketResolve(wbBucketIdx) ||
    bucketSeq(wbBucketIdx) === wb.io.active_packet_seq
  val wbNeedsBucket = unverifiedDirtyWb && !wbResolvedImmediately
  val wbBucketAccepted = wbNeedsBucket && wbBucketAvailable
  val wbBucketDropped = wbNeedsBucket && !wbBucketAvailable
  val verifiedDirtyWb = verifyRequiredDirtyWb &&
    wb.io.active_packet_seq <= safePacketWatermark
  val nonverifyDirtyWb = trafficCounting && l1_l2_dirty_wb_event &&
    !verifyRequiredDirtyWb

  val resolvedThisCycleWide = resolvedBucketsThisCycleWide +
    Mux(wbResolvedImmediately, 1.U(73.W), 0.U(73.W))
  val writebackCyclesResolvedThisCycleWide = writebackCyclesResolvedFromBucketsWide +
    Mux(wbResolvedImmediately, io.csr_cycle, 0.U).pad(73)
  val resolvedBucketsThisCycle = resolvedBucketsThisCycleWide(63, 0)
  val resolvedThisCycle = resolvedThisCycleWide(63, 0)
  val writebackCyclesResolvedThisCycle = writebackCyclesResolvedThisCycleWide(63, 0)
  // Every event settled by this watermark advance uses the same BOOM cycle.
  val safeCyclesResolvedThisCycleProduct = io.csr_cycle * resolvedThisCycleWide
  val safeCyclesResolvedThisCycle = safeCyclesResolvedThisCycleProduct(63, 0)
  val perCycleSumOverflow = resolvedThisCycleWide(72, 64).orR ||
    writebackCyclesResolvedThisCycleWide(72, 64).orR
  val safeCycleProductOverflow = safeCyclesResolvedThisCycleProduct(136, 64).orR

  for (i <- 0 until statsWindow) {
    when (bucketResolve(i)) {
      bucketValid(i) := false.B
      bucketCount(i) := 0.U
      bucketWritebackCycleSum(i) := 0.U
    }
  }
  when (wbBucketAccepted) {
    when (!bucketValid(wbBucketIdx) || bucketResolve(wbBucketIdx)) {
      bucketValid(wbBucketIdx) := true.B
      bucketSeq(wbBucketIdx) := wb.io.active_packet_seq
      bucketCount(wbBucketIdx) := 1.U
      bucketWritebackCycleSum(wbBucketIdx) := io.csr_cycle
    }.otherwise {
      bucketCount(wbBucketIdx) := bucketCount(wbBucketIdx) + 1.U
      bucketWritebackCycleSum(wbBucketIdx) :=
        bucketWritebackCycleSum(wbBucketIdx) + io.csr_cycle
    }
  }

  val unverifiedDirtyWbSeen = RegInit(0.U(64.W))
  val unverifiedDirtyWbResolved = RegInit(0.U(64.W))
  val unverifiedDirtyWbPending = RegInit(0.U(64.W))
  val unverifiedDirtyWbDropped = RegInit(0.U(64.W))
  val failedPackages = RegInit(0.U(64.W))
  val verifiedDirtyWbCount = RegInit(0.U(64.W))
  val nonverifyDirtyWbCount = RegInit(0.U(64.W))
  val verifyRequiredDirtyWbCount = RegInit(0.U(64.W))
  val allocatedPackages = RegInit(0.U(64.W))
  val completedPackages = RegInit(0.U(64.W))
  val passedPackages = RegInit(0.U(64.W))
  val cancelledPackages = RegInit(0.U(64.W))
  val safeCycleSum = RegInit(0.U(64.W))
  val writebackCycleSum = RegInit(0.U(64.W))
  val statsValid = RegInit(true.B)
  val packageResultDropped = RegInit(0.U(64.W))
  val statsArithmeticOverflow = RegInit(0.U(64.W))
  val resetBoundaryInvalid = io.traffic_reset &&
    (io.traffic_check_state || bitmapAllocated.asUInt.orR ||
      safePacketWatermark =/= io.packet_seq_baseline)
  val bucketArithmeticOverflow = wbBucketAccepted && bucketValid(wbBucketIdx) &&
    !bucketResolve(wbBucketIdx) &&
    (bucketCount(wbBucketIdx) === ~0.U(64.W) ||
      bucketWritebackCycleSum(wbBucketIdx) > (~0.U(64.W) - io.csr_cycle))
  val invalidResultsThisCycle = PopCount(VecInit(io.checker_results.indices.map { i =>
    io.checker_results(i)(GH_GlobalParams.GH_CHECKER_RESULT_BITS - 1) &&
      !resultAccepted(i) && !resultStale(i) && !resultHeldDuplicate(i)
  }))
  val acceptedResultsThisCycle = PopCount(resultAccepted)
  val passedResultsThisCycle = PopCount(VecInit(io.checker_results.indices.map { i =>
    resultAccepted(i) && !resultFailed(i) && !resultCancelled(i)
  }))
  addressStatsFatal := allocationCollision || invalidResultsThisCycle =/= 0.U ||
    resultFailed.asUInt.orR || resultCancelled.asUInt.orR
  when (measuredPacketAlloc) { allocatedPackages := allocatedPackages + 1.U }
  when (acceptedResultsThisCycle =/= 0.U) {
    completedPackages := completedPackages + acceptedResultsThisCycle
  }
  when (passedResultsThisCycle =/= 0.U) {
    passedPackages := passedPackages + passedResultsThisCycle
  }
  when (unverifiedDirtyWb) { unverifiedDirtyWbSeen := unverifiedDirtyWbSeen + 1.U }
  when (verifyRequiredDirtyWb) {
    verifyRequiredDirtyWbCount := verifyRequiredDirtyWbCount + 1.U
  }
  when (verifiedDirtyWb) { verifiedDirtyWbCount := verifiedDirtyWbCount + 1.U }
  when (nonverifyDirtyWb) { nonverifyDirtyWbCount := nonverifyDirtyWbCount + 1.U }
  when (resolvedThisCycle =/= 0.U) {
    unverifiedDirtyWbResolved := unverifiedDirtyWbResolved + resolvedThisCycle
    safeCycleSum := safeCycleSum + safeCyclesResolvedThisCycle
    writebackCycleSum := writebackCycleSum + writebackCyclesResolvedThisCycle
  }
  val resolvedArithmeticOverflow = resolvedThisCycle =/= 0.U &&
    (perCycleSumOverflow || safeCycleProductOverflow ||
      unverifiedDirtyWbResolved > (~0.U(64.W) - resolvedThisCycle) ||
      safeCycleSum > (~0.U(64.W) - safeCyclesResolvedThisCycle) ||
      writebackCycleSum > (~0.U(64.W) - writebackCyclesResolvedThisCycle))
  val pendingAccountingInvalid = resolvedBucketsThisCycle.pad(65) >
    (unverifiedDirtyWbPending.pad(65) + wbBucketAccepted.asUInt)
  when (bucketArithmeticOverflow || resolvedArithmeticOverflow || pendingAccountingInvalid) {
    statsArithmeticOverflow := statsArithmeticOverflow +
      bucketArithmeticOverflow.asUInt + resolvedArithmeticOverflow.asUInt +
      pendingAccountingInvalid.asUInt
  }
  unverifiedDirtyWbPending := unverifiedDirtyWbPending +
    wbBucketAccepted.asUInt - resolvedBucketsThisCycle
  when (wbBucketDropped) { unverifiedDirtyWbDropped := unverifiedDirtyWbDropped + 1.U }
  when (resultFailed.asUInt.orR) { failedPackages := failedPackages + PopCount(resultFailed) }
  when (resultCancelled.asUInt.orR) {
    cancelledPackages := cancelledPackages + PopCount(resultCancelled)
  }
  when (allocationCollision || invalidResultsThisCycle =/= 0.U) {
    packageResultDropped := packageResultDropped + allocationCollision.asUInt + invalidResultsThisCycle
  }
  when (allocationCollision || invalidResultsThisCycle =/= 0.U || wbBucketDropped ||
      resultFailed.asUInt.orR || resultCancelled.asUInt.orR ||
      bucketArithmeticOverflow || resolvedArithmeticOverflow || pendingAccountingInvalid) {
    statsValid := false.B
  }
  when (trafficCounting && l1_l2_c_event) {
    l1_l2_c_count := l1_l2_c_count + 1.U
  }
  when (trafficCounting && l1_l2_dirty_wb_event) {
    l1_l2_dirty_wb_count := l1_l2_dirty_wb_count + 1.U
  }

  when (io.traffic_reset) {
    for (i <- 0 until statsWindow) {
      bucketValid(i) := false.B
      bucketSeq(i) := 0.U
      bucketCount(i) := 0.U
      bucketWritebackCycleSum(i) := 0.U
    }
    measurementSeqFloor := io.packet_seq_baseline
    l1_l2_c_count := 0.U
    l1_l2_dirty_wb_count := 0.U
    unverifiedDirtyWbSeen := 0.U
    unverifiedDirtyWbResolved := 0.U
    unverifiedDirtyWbPending := 0.U
    unverifiedDirtyWbDropped := 0.U
    failedPackages := 0.U
    verifiedDirtyWbCount := 0.U
    nonverifyDirtyWbCount := 0.U
    verifyRequiredDirtyWbCount := 0.U
    allocatedPackages := 0.U
    completedPackages := 0.U
    passedPackages := 0.U
    cancelledPackages := 0.U
    safeCycleSum := 0.U
    writebackCycleSum := 0.U
    statsValid := !resetBoundaryInvalid
    packageResultDropped := resetBoundaryInvalid.asUInt
    statsArithmeticOverflow := 0.U
  }

  io.lsu.perf.release := edge.done(tl_out.c)
  io.lsu.perf.acquire := edge.done(tl_out.a)

  // A stale S3 store is reported as a retry in the cycle in which ownership
  // mismatch is detected.  The request is kept in a side wire so the nack
  // path does not accidentally use the younger S2 request.
  val staleS3StoreNack = WireDefault(false.B)
  val staleS3StoreReq = Wire(new BoomDCacheReq)
  staleS3StoreReq := 0.U.asTypeOf(new BoomDCacheReq)

  // load data gen
  val s2_data_word_prebypass = widthMap(w => s2_data_muxed(w) >> Cat(s2_word_idx(w), 0.U(log2Ceil(coreDataBits).W)))
  val s2_data_word = Wire(Vec(memWidth, UInt()))

  val loadgen = (0 until memWidth).map { w =>
    new LoadGen(s2_req(w).uop.mem_size, s2_req(w).uop.mem_signed, s2_req(w).addr,
                s2_data_word(w), s2_sc && (w == 0).B, wordBytes)
  }
  // Mux between cache responses and uncache responses
  val cache_resp   = Wire(Vec(memWidth, Valid(new BoomDCacheResp)))
  for (w <- 0 until memWidth) {
    cache_resp(w).valid         := s2_valid(w) && s2_send_resp(w)
    cache_resp(w).bits.uop      := s2_req(w).uop
    cache_resp(w).bits.data     := loadgen(w).data | s2_sc_fail
    cache_resp(w).bits.is_hella := s2_req(w).is_hella
    cache_resp(w).bits.traffic_check := s2_req(w).traffic_check
    cache_resp(w).bits.traffic_seen  := s2_req(w).traffic_seen
    cache_resp(w).bits.traffic_cacheable := s2_req(w).traffic_cacheable
    cache_resp(w).bits.request_token_valid := s2_req(w).request_token_valid
    cache_resp(w).bits.request_token := s2_req(w).request_token
  }

  val uncache_resp = Wire(Valid(new BoomDCacheResp))
  val responseSlotAvailable = !cache_resp.map(_.valid).reduce(_ && _)
  val terminalResponse = Wire(new BoomDCacheResp)
  terminalResponse := 0.U.asTypeOf(new BoomDCacheResp)
  terminalResponse.uop := completionQ.io.deq.bits.req.uop
  terminalResponse.data := completionQ.io.deq.bits.data
  terminalResponse.is_hella := completionQ.io.deq.bits.req.is_hella
  terminalResponse.traffic_check := completionQ.io.deq.bits.req.traffic_check
  terminalResponse.traffic_seen := completionQ.io.deq.bits.req.traffic_seen
  terminalResponse.traffic_cacheable := completionQ.io.deq.bits.req.traffic_cacheable
  terminalResponse.request_token_valid := completionQ.io.deq.bits.req.request_token_valid
  terminalResponse.request_token := completionQ.io.deq.bits.req.request_token
  val completionCancelled = completionQ.io.deq.bits.status === CacheTerminal.cancel
  io.lsu.store_done.valid := completionQ.io.deq.valid && responseSlotAvailable && !completionCancelled
  io.lsu.store_done.bits := completionQ.io.deq.bits
  completionQ.io.deq.ready := responseSlotAvailable && (completionCancelled || io.lsu.store_done.ready)
  uncache_resp.bits := Mux(completionQ.io.deq.valid, terminalResponse, mshrs.io.resp.bits)
  uncache_resp.valid := Mux(completionQ.io.deq.valid, io.lsu.store_done.fire, mshrs.io.resp.valid)
  mshrs.io.resp.ready := responseSlotAvailable && !completionQ.io.deq.valid // We can backpressure the MSHRs, but not cache hits

  val resp = WireInit(cache_resp)
  var uncache_responding = false.B
  for (w <- 0 until memWidth) {
    val uncache_respond = !cache_resp(w).valid && !uncache_responding
    when (uncache_respond) {
      resp(w) := uncache_resp
    }
    uncache_responding = uncache_responding || uncache_respond
  }

  for (w <- 0 until memWidth) {
    val staleStoreNack = (w == 0).B && staleS3StoreNack
    io.lsu.resp(w).valid := resp(w).valid &&
                            !(io.lsu.exception && resp(w).bits.uop.uses_ldq) &&
                            !IsKilledByBranch(io.lsu.brupdate, resp(w).bits.uop)
    io.lsu.resp(w).bits  := UpdateBrMask(io.lsu.brupdate, resp(w).bits)
    if (w == 0) {
      io.lsu.resp(w).bits.traffic_check := Mux(
        resp(w).bits.uop.mem_cmd === M_XSC && lr_traffic_check_valid,
        lr_traffic_check,
        resp(w).bits.traffic_check)
    }

    io.lsu.nack(w).valid := staleStoreNack || (s2_valid(w) && s2_send_nack(w) &&
                            !(io.lsu.exception && s2_req(w).uop.uses_ldq) &&
                            !IsKilledByBranch(io.lsu.brupdate, s2_req(w).uop))
    io.lsu.nack(w).bits  := UpdateBrMask(io.lsu.brupdate,
      Mux(staleStoreNack, staleS3StoreReq, s2_req(w)))
    assert(!(io.lsu.nack(w).valid && s2_type =/= t_lsu && !staleStoreNack))
  }
  when (io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.mem_cmd === M_XLR) {
    lr_traffic_check := io.lsu.resp(0).bits.traffic_check
    lr_traffic_check_valid := true.B
  } .elsewhen (io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.mem_cmd === M_XSC) {
    lr_traffic_check_valid := false.B
  }
  io.lsu.traffic_check_state := io.traffic_check_state
  io.lsu.csr_cycle := io.csr_cycle
  io.lsu.traffic_counting := trafficCounting
  io.lsu.traffic_reset := io.traffic_reset

  // Store/amo hits
  val s2_write_grant = s2_valid(0) && s2_hit(0) && isWrite(s2_req(0).uop.mem_cmd) &&
    !s2_nack(0) && !l1CrossPackageBlocked && !s3_valid &&
    (s2_type =/= t_replay || s2_replay_owner_match)
  // RISC-V AMO.W returns its loaded 32-bit value sign-extended to XLEN,
  // independently of the arithmetic/logical operation. The ALU physical
  // write value remains unchanged below.
  // LoadGen.wordData selects addr[2] for AMO.W before sign extension.  Taking
  // bits 31:0 directly is wrong for the upper word of an aligned RV64 word.
  val amoWordOldValue = new LoadGen(
    s2_req(0).uop.mem_size, true.B, s2_req(0).addr,
    s2_data_word(0), false.B, xLen / 8).wordData
  val amoArchitecturalOldValue = Mux(
    s2_req(0).uop.mem_size === 2.U, amoWordOldValue, s2_data_word(0))

  when (s2_write_grant) {
    val set = s2_req(0).addr(idxMSB, idxLSB)
    val way = OHToUInt(s2_effective_req(0).way_en)
    val duplicate = s2_req(0).effect_token_valid && appliedEffectValid(set)(way) &&
      appliedEffectToken(set)(way) === s2_req(0).effect_token
    s3_req := s2_req(0)
    s3_way := s2_effective_req(0).way_en
    s3_valid := true.B
    s3_applied := s2_sc_fail
    s3_cancelled := false.B
    s3_replay := s2_type === t_replay
    s3_old_value := s2_data_word(0)
    s3_operand := s2_req(0).data
    s3_result := Mux(duplicate, appliedEffectResult(set)(way),
      Mux(s2_sc, s2_sc_fail.asUInt,
        Mux(isAMO(s2_req(0).uop.mem_cmd), amoArchitecturalOldValue, s2_data_word(0))))
    printf("STAGE1_TX ISSUE source=DCACHE cmd=%x size=%x stq=%x req=%x effect=%x txn=%x epoch=%x gen=%x is_hella=%x cycle=%x\n",
      s2_req(0).uop.mem_cmd, s2_req(0).uop.mem_size, s2_req(0).uop.stq_idx,
      s2_req(0).request_token, s2_req(0).effect_token,
      s2_req(0).transaction_token, s2_req(0).slot_epoch,
      s2_req(0).line_generation, s2_req(0).is_hella, io.csr_cycle)
  }
  for (w <- 1 until memWidth) {
    assert(!(s2_valid(w) && s2_hit(w) && isWrite(s2_req(w).uop.mem_cmd) &&
                         !s2_sc_fail && !(s2_send_nack(w) && s2_nack(w))),
      "Store must go through 0th pipe in L1D")
  }

  // For bypassing
  val s4_req   = RegNext(s3_req)
  val s4_valid = RegNext(s3_effect_fire, false.B)
  val s5_req   = RegNext(s4_req)
  val s5_valid = RegNext(s4_valid)

  val s3_bypass = widthMap(w => s3_valid && !s3_cancelled &&
    !(s3_req.uop.mem_cmd === M_XSC && s3_result === 1.U) &&
    ((s2_req(w).addr >> wordOffBits) === (s3_req.addr >> wordOffBits)))
  val s4_bypass = widthMap(w => s4_valid && ((s2_req(w).addr >> wordOffBits) === (s4_req.addr >> wordOffBits)))
  val s5_bypass = widthMap(w => s5_valid && ((s2_req(w).addr >> wordOffBits) === (s5_req.addr >> wordOffBits)))

  // Store -> Load bypassing
  for (w <- 0 until memWidth) {
    s2_data_word(w) := Mux(s3_bypass(w), s3_req.data,
                       Mux(s4_bypass(w), s4_req.data,
                       Mux(s5_bypass(w), s5_req.data,
                                         s2_data_word_prebypass(w))))
  }
  val amoalu   = Module(new AMOALU(xLen))
  amoalu.io.mask := new StoreGen(s2_req(0).uop.mem_size, s2_req(0).addr, 0.U, xLen/8).mask
  amoalu.io.cmd  := s2_req(0).uop.mem_cmd
  amoalu.io.lhs  := s2_data_word(0)
  amoalu.io.rhs  := s2_req(0).data

  when (s2_write_grant) { s3_req.data := amoalu.io.out }

  val s3_set = s3_req.addr(idxMSB, idxLSB)
  val s3_way_idx = OHToUInt(s3_way)
  val s3_owner_match = s3_req.slot_epoch === slotEpoch(s3_set)(s3_way_idx) &&
    s3_req.owner_context_valid && s3_req.owner_way === s3_way &&
    Mux(s3_replay,
      slotReserved(s3_set)(s3_way_idx) &&
        reservedTransaction(s3_set)(s3_way_idx) === s3_req.transaction_token &&
        reservedMshr(s3_set)(s3_way_idx) === s3_req.replay_mshr_id &&
        reservedTag(s3_set)(s3_way_idx) === (s3_req.addr >> untagBits),
      residentValid(s3_set)(s3_way_idx) && residentTag(s3_set)(s3_way_idx) === (s3_req.addr >> untagBits))
  val s3_same_clear_line = crossPackageMetaClear.fire &&
    s3_set === crossPackagePendingSet && s3_way_idx === crossPackagePendingWay
  val s3_same_probe_invalidate = prober.io.meta_write.fire &&
    !prober.io.meta_write.bits.data.coh.isValid() &&
    s3_set === prober.io.meta_write.bits.idx &&
    s3_way === prober.io.meta_write.bits.way_en
  val s3_owner_revoked = s3_same_clear_line || s3_same_probe_invalidate
  s2_realloc_owner_conflict := s2_valid(0) && s2_type === t_lsu &&
    edge.manager.supportsAcquireBFast(s2_raw_req(0).addr, lgCacheBlockBytes.U) &&
    !s2_tag_match(0) && s3_valid &&
    s2_selected_set === s3_set && s2_selected_way === s3_way
  // Drain prevents owner revocation of a held grant. A real mismatch is a
  // protocol fault; ordinary retry cannot hide it or release its request.
  val s3_stale_or_revoked = s3_valid && (!s3_owner_match || s3_owner_revoked)
  staleS3StoreNack := false.B
  when (s3_valid) { assert(!s3_stale_or_revoked, "held write grant owner revoked") }
  crossPackageMetaClearBlock := (s3_valid &&
    s3_set === crossPackagePendingSet && s3_way_idx === crossPackagePendingWay) ||
    completionPending(crossPackagePendingSet)(crossPackagePendingWay) ||
    (0 until memWidth).map(w =>
      (s1_valid(w) && s1_type === t_lsu && s1_before_freeze(w) &&
        s1_req(w).addr(idxMSB, idxLSB) === crossPackagePendingSet) ||
      (s2_valid(w) && s2_type === t_lsu && s2_before_freeze(w) &&
        s2_req(w).addr(idxMSB, idxLSB) === crossPackagePendingSet)).reduce(_ || _)
  val stage1ClearS1 = (0 until memWidth).map(w => s1_valid(w) && s1_type === t_lsu &&
    s1_req(w).addr(idxMSB, idxLSB) === crossPackagePendingSet)
  val stage1ClearS2 = (0 until memWidth).map(w => s2_valid(w) && s2_type === t_lsu &&
    s2_req(w).addr(idxMSB, idxLSB) === crossPackagePendingSet)
  val stage1ClearS1Old = (0 until memWidth).map(w => stage1ClearS1(w) && s1_before_freeze(w)).reduce(_ || _)
  val stage1ClearS2Old = (0 until memWidth).map(w => stage1ClearS2(w) && s2_before_freeze(w)).reduce(_ || _)
  val stage1ClearPendingPrev = RegNext(crossPackageMetaClearPending, false.B)
  when (crossPackageMetaClear.fire || (crossPackageMetaClearPending && !stage1ClearPendingPrev)) {
    printf("STAGE1_TX CLEAR_CHECK cycle=%x set=%x way=%x fire=%x s1_any=%x s2_any=%x s1_old=%x s2_old=%x s3=%x completion=%x mshr_conflict=%x slot_conflict=%x\n",
      io.csr_cycle, crossPackagePendingSet, crossPackagePendingWay, crossPackageMetaClear.fire,
      VecInit(stage1ClearS1).asUInt.orR, VecInit(stage1ClearS2).asUInt.orR,
      stage1ClearS1Old, stage1ClearS2Old,
      s3_valid && s3_set === crossPackagePendingSet && s3_way_idx === crossPackagePendingWay,
      completionPending(crossPackagePendingSet)(crossPackagePendingWay),
      crossPackageMshrConflict, crossPackageSlotConflict)
  }
  staleS3StoreReq := s3_req
  staleS3StoreReq.replay_retry := s3_replay
  val s3_pre_effect_kill = s3_valid && !s3_applied &&
    (IsKilledByBranch(io.lsu.brupdate, s3_req.uop) ||
      (io.lsu.exception && s3_req.uop.uses_ldq))
  when (s3_pre_effect_kill) { s3_cancelled := true.B }
  when (s3_pre_effect_kill) {
    printf("STAGE1_TX KILL cycle=%x phase=S3 req=%x\n", io.csr_cycle, s3_req.request_token)
  }
  when (io.lsu.s1_kill.asUInt.orR && replayPipelineBusy ||
    s1_replay_killed || s2_replay_killed) {
    printf("STAGE1_TX RACE_OBSERVE cycle=%x kill_replay=%x s1_replay_killed=%x s2_replay_killed=%x\n",
      io.csr_cycle, io.lsu.s1_kill.asUInt.orR && replayPipelineBusy,
      s1_replay_killed, s2_replay_killed)
  }
  when (s3_valid) { s3_req.uop.br_mask := GetNewBrMask(io.lsu.brupdate, s3_req.uop) }
  val probeSet = prober.io.state.bits(idxMSB, idxLSB)
  probeDrainReady := !(s3_valid && s3_set === probeSet) &&
    !completionPending(probeSet).asUInt.orR &&
    !(0 until memWidth).map(w =>
      (s1_valid(w) && s1_type === t_lsu && s1_before_freeze(w) &&
        s1_req(w).addr(idxMSB, idxLSB) === probeSet) ||
      (s2_valid(w) && s2_type === t_lsu && s2_before_freeze(w) &&
        s2_req(w).addr(idxMSB, idxLSB) === probeSet)).reduce(_ || _)
  val victimSet = mshrs.io.wb_req.bits.idx
  victimDrainReady := !(s3_valid && s3_set === victimSet) &&
    !completionPending(victimSet).asUInt.orR
  val s3_duplicate_effect = s3_req.effect_token_valid &&
    appliedEffectValid(s3_set)(s3_way_idx) &&
    appliedEffectToken(s3_set)(s3_way_idx) === s3_req.effect_token
  val s3_image_match = s3_req.image_valid === imageValid(s3_set)(s3_way_idx) &&
    (!s3_req.image_valid || s3_req.line_generation === lineGeneration(s3_set)(s3_way_idx))
  val s3_svbOwnsPredecessor = svbFastLineValid &&
    svbCaptureResidentMatch &&
    s3_set === svbFastSet && s3_way_idx === svbFastWay &&
    (s3_req.addr >> untagBits) === svbFastTag &&
    s3_req.packet_seq === svbFastSeq &&
    s3_req.slot_epoch === svbFastEpoch &&
    s3_req.slot_epoch === slotEpoch(s3_set)(s3_way_idx)
  val s3_preservationAllowed = L1Preservation.allow(imageValid(s3_set)(s3_way_idx),
    imageKey(s3_set)(s3_way_idx), lowerPreserved(s3_set)(s3_way_idx),
    s3_req.packet_seq, safePacketWatermark, outer.staticImageWriter.U) ||
    s3_svbOwnsPredecessor
  val s3_effect_eligible = s3_valid && !s3_applied && s3_owner_match &&
    s3_image_match && s3_preservationAllowed && !s3_duplicate_effect && !s3_owner_revoked && !s3_pre_effect_kill && !s3_cancelled
  when (s3_valid && !s3_applied && !s3_duplicate_effect && !s3_cancelled && !s3_pre_effect_kill) {
    assert(s3_image_match, "write grant has stale image dependency")
    assert(s3_preservationAllowed, "write grant bypassed L1 preservation")
  }
  s3_effect_fire := dataWriteArb.io.in(0).fire
  when (svbCapturePending && svbCaptureIssued) {
    assert(!(s3_effect_fire && s3_set === svbFastSet && s3_way_idx === svbFastWay),
      "semantic write changed an in-progress SVB snapshot")
    assert(!(dataWriteArb.io.in(1).fire && refillReqSet === svbFastSet && refillReqWay === svbFastWay),
      "refill changed an in-progress SVB snapshot")
  }
  when (crossPackageIssued || crossPackageMetaClearPending) {
    assert(!(s3_effect_fire && s3_set === crossPackagePendingSet &&
      s3_way_idx === crossPackagePendingWay), "semantic write changed a frozen WB snapshot")
    assert(!(dataWriteArb.io.in(1).fire && refillReqSet === crossPackagePendingSet &&
      refillReqWay === crossPackagePendingWay), "refill changed a frozen WB snapshot")
  }
  when (s3_effect_fire) {
    printf("STAGE1_TX EFFECT cycle=%x cmd=%x size=%x stq=%x req=%x effect=%x txn=%x epoch=%x gen=%x addr=%x data=%x old=%x operand=%x new=%x returned=%x mask=%x set=%x way=%x owner_match=%x\n",
      io.csr_cycle, s3_req.uop.mem_cmd, s3_req.uop.mem_size, s3_req.uop.stq_idx, s3_req.request_token,
      s3_req.effect_token, s3_req.transaction_token, s3_req.slot_epoch,
      s3_req.line_generation, s3_req.addr, s3_req.data, s3_old_value, s3_operand,
      s3_req.data, s3_result,
      new StoreGen(s3_req.uop.mem_size, s3_req.addr, 0.U, xLen / 8).mask,
      s3_set, s3_way_idx, s3_owner_match)
  }
  when (s3_effect_fire || (s3_valid && s3_duplicate_effect)) { s3_applied := true.B }
  when (s3_valid && s3_duplicate_effect) {
    s3_result := appliedEffectResult(s3_set)(s3_way_idx)
  }
  completionArb.io.in(0).valid := s3_valid && s3_owner_match && (s3_applied || s3_cancelled)
  completionArb.io.in(0).bits.req := s3_req
  completionArb.io.in(0).bits.status := Mux(s3_cancelled, CacheTerminal.cancel,
    Mux(s3_req.uop.mem_cmd === M_XSC && s3_result === 1.U,
      CacheTerminal.noWriteSC, CacheTerminal.applied))
  completionArb.io.in(0).bits.data := s3_result
  when (completionArb.io.in(0).fire) { s3_valid := false.B; s3_applied := false.B; s3_cancelled := false.B }
  completionArb.io.in(1).valid := false.B
  completionArb.io.in(1).bits := 0.U.asTypeOf(new BoomCacheCompletion)
  when (completionArb.io.out.fire && completionArb.io.out.bits.req.owner_context_valid) {
    val r = completionArb.io.out.bits.req
    assert(!completionPending(r.addr(idxMSB, idxLSB))(OHToUInt(r.owner_way)),
      "two terminal responsibilities for one cache slot")
    completionPending(r.addr(idxMSB, idxLSB))(OHToUInt(r.owner_way)) := true.B
  }
  when (completionQ.io.deq.fire && completionQ.io.deq.bits.req.owner_context_valid) {
    val r = completionQ.io.deq.bits.req
    assert(completionPending(r.addr(idxMSB, idxLSB))(OHToUInt(r.owner_way)) &&
      slotEpoch(r.addr(idxMSB, idxLSB))(OHToUInt(r.owner_way)) === r.slot_epoch,
      "completion lost its live slot responsibility")
    completionPending(r.addr(idxMSB, idxLSB))(OHToUInt(r.owner_way)) := false.B
  }
  when (completionQ.io.deq.fire) {
    printf("STAGE1_TX TERMINAL cycle=%x status=%x cmd=%x size=%x stq=%x req=%x effect=%x txn=%x data=%x admission=%x is_hella=%x\n",
      io.csr_cycle, completionQ.io.deq.bits.status, completionQ.io.deq.bits.req.uop.mem_cmd,
      completionQ.io.deq.bits.req.uop.mem_size,
      completionQ.io.deq.bits.req.uop.stq_idx,
      completionQ.io.deq.bits.req.request_token,
      completionQ.io.deq.bits.req.effect_token,
      completionQ.io.deq.bits.req.transaction_token,
      completionQ.io.deq.bits.data,
      completionQ.io.deq.bits.req.admission,
      completionQ.io.deq.bits.req.is_hella)
  }

  dataWriteArb.io.in(0).valid       := s3_effect_eligible
  dataWriteArb.io.in(0).bits.addr   := s3_req.addr
  dataWriteArb.io.in(0).bits.wmask  := UIntToOH(s3_req.addr.extract(rowOffBits-1,offsetlsb))
  dataWriteArb.io.in(0).bits.data   := Fill(rowWords, s3_req.data)
  dataWriteArb.io.in(0).bits.way_en := s3_way
  dataWriteArb.io.in(0).bits.slot_epoch := s3_req.slot_epoch
  dataWriteArb.io.in(0).bits.line_generation := imageSerial

  replayEffectDone := false.B
  replayEffectDoneId := 0.U
  replayCancel := false.B
  replayCancelId := 0.U
  for (i <- 0 until cfg.nMSHRs) {
    replayEffectDoneVec(i) := mshrs.io.replay_result(i).fire &&
      mshrs.io.replay_result(i).bits.status.isOneOf(
        CacheTerminal.applied, CacheTerminal.load, CacheTerminal.noWriteSC)
    replayCancelVec(i) := mshrs.io.replay_result(i).fire &&
      mshrs.io.replay_result(i).bits.status === CacheTerminal.cancel
    val writeTerminal = completionQ.io.deq.fire &&
      completionQ.io.deq.bits.req.admission === CacheAdmission.replay &&
      completionQ.io.deq.bits.req.replay_mshr_id === i.U
    val loadTerminal = s2_valid(0) && s2_type === t_replay &&
      !isWrite(s2_req(0).uop.mem_cmd) && s2_send_resp(0) &&
      s2_req(0).replay_mshr_id === i.U
    mshrs.io.replay_grant(i).valid := s2_valid(0) && s2_type === t_replay &&
      s2_req(0).replay_mshr_id === i.U
    mshrs.io.replay_grant(i).bits := s2_req(0)
    when (mshrs.io.replay_grant(i).valid) {
      printf("STAGE1_TX REPLAY_GRANT cycle=%x mshr=%x cmd=%x size=%x stq=%x req=%x effect=%x txn=%x\n",
        io.csr_cycle, i.U, s2_req(0).uop.mem_cmd, s2_req(0).uop.mem_size, s2_req(0).uop.stq_idx,
        s2_req(0).request_token, s2_req(0).effect_token,
        s2_req(0).transaction_token)
    }
    when (mshrs.io.replay_result(i).fire) {
      printf("STAGE1_TX REPLAY_RESULT cycle=%x mshr=%x status=%x stq=%x req=%x effect=%x txn=%x data=%x\n",
        io.csr_cycle, i.U, mshrs.io.replay_result(i).bits.status,
        mshrs.io.replay_result(i).bits.req.uop.stq_idx,
        mshrs.io.replay_result(i).bits.req.request_token,
        mshrs.io.replay_result(i).bits.req.effect_token,
        mshrs.io.replay_result(i).bits.req.transaction_token,
        mshrs.io.replay_result(i).bits.data)
    }
    val preservationRetry = s2_valid(0) && s2_type === t_replay &&
      isWrite(s2_req(0).uop.mem_cmd) && l1CrossPackageBlocked &&
      s2_req(0).replay_mshr_id === i.U
    val killS1 = s1_replay_killed && s1_req(0).replay_mshr_id === i.U
    val killS2 = s2_replay_killed && s2_req(0).replay_mshr_id === i.U
    val cancelReq = Mux(killS1, s1_req(0), s2_req(0))
    when (writeTerminal || loadTerminal || killS1 || killS2 || preservationRetry) {
      replayResultQ(i).io.enq.valid := true.B
      replayResultQ(i).io.enq.bits := completionQ.io.deq.bits
      when (!writeTerminal) {
        replayResultQ(i).io.enq.bits.req := Mux(killS1 || killS2, cancelReq, s2_req(0))
        replayResultQ(i).io.enq.bits.status := Mux(killS1 || killS2,
          CacheTerminal.cancel, Mux(preservationRetry, CacheTerminal.retry, CacheTerminal.load))
        replayResultQ(i).io.enq.bits.data := loadgen(0).data
      }
      assert(replayResultQ(i).io.enq.ready, "replay result reservation exhausted")
    }
  }
  // Legacy waveform aliases report acknowledged results, never issue pulses.
  replayEffectDone := replayEffectDoneVec.asUInt.orR
  replayEffectDoneId := PriorityEncoder(replayEffectDoneVec.asUInt)
  replayCancel := replayCancelVec.asUInt.orR
  replayCancelId := PriorityEncoder(replayCancelVec.asUInt)

  // Read provenance before this write updates it. Successful SC and AMO
  // operations naturally reach this same physical array-write point, whereas
  // a failed SC holds only a no-write result and cannot create an event.
  val modifyingSet = s3_req.addr(idxMSB, idxLSB)
  val modifyingWay = OHToUInt(s3_way)
  val overwrittenPacketSeq = dirtyPacketSeq(modifyingSet)(modifyingWay)
  val overwrittenPacketTracked = dirtyPacketTracked(modifyingSet)(modifyingWay)
  val crossPackageWaitActive = RegInit(false.B)
  val crossPackageWaitStarted = l1CrossPackageBlocked && !crossPackageWaitActive
  when (!l1CrossPackageBlocked) {
    crossPackageWaitActive := false.B
  }.otherwise {
    crossPackageWaitActive := true.B
  }
  val crossPackageBarrierEvent = trafficCounting && Mux(
    p(GH_GlobalParams.GH_REAL_BARRIER_ENABLED).B, crossPackageWaitStarted,
    dataWriteArb.io.in(0).fire && s3_req.packet_seq =/= 0.U &&
      overwrittenPacketTracked && overwrittenPacketSeq =/= 0.U &&
      overwrittenPacketSeq =/= s3_req.packet_seq &&
      overwrittenPacketSeq > safePacketWatermark)

  // Compact SVB accounting.  These counters are observation-only and are
  // exported through the sparse event stream below; they never participate
  // in admission, watermark generation, or TileLink ordering.
  val svbEligibleCount = RegInit(0.U(64.W))
  val svbAllocationCount = RegInit(0.U(64.W))
  val svbFullFallbackCount = RegInit(0.U(64.W))
  val svbUnsupportedFallbackCount = RegInit(0.U(64.W))
  val svbBypassCount = RegInit(0.U(64.W))
  val svbPromotionCount = RegInit(0.U(64.W))
  val svbAckCount = RegInit(0.U(64.W))
  val svbRecoveryCount = RegInit(0.U(64.W))
  val svbWouldFullAt8 = RegInit(0.U(64.W))
  val svbCyclesAbove8 = RegInit(0.U(64.W))
  val svbCaptureFailures = RegInit(0.U(64.W))
  when (io.traffic_reset) {
    svbEligibleCount := 0.U
    svbAllocationCount := 0.U
    svbFullFallbackCount := 0.U
    svbUnsupportedFallbackCount := 0.U
    svbBypassCount := 0.U
    svbPromotionCount := 0.U
    svbAckCount := 0.U
    svbRecoveryCount := 0.U
    svbWouldFullAt8 := 0.U
    svbCyclesAbove8 := 0.U
    svbCaptureFailures := 0.U
  }
  val svbEligibleCandidatePrev = RegNext(svbEligibleCandidate, false.B)
  val svbFullFallbackPrev = RegNext(svbFullFallback, false.B)
  val svbUnsupportedFallback = crossPackageDomainWaitRaw && !svbFastLineMatch &&
    !svbEligibleCandidate && !svbFullFallback
  val svbUnsupportedFallbackPrev = RegNext(svbUnsupportedFallback, false.B)
  val svbEligibleEvent = svbEligibleCandidate && !svbEligibleCandidatePrev
  val svbFullFallbackEvent = svbFullFallback && !svbFullFallbackPrev
  val svbUnsupportedFallbackEvent = svbUnsupportedFallback && !svbUnsupportedFallbackPrev
  when (trafficCounting && svbEligibleEvent) { svbEligibleCount := svbEligibleCount + 1.U }
  when (trafficCounting && svbFullFallbackEvent) { svbFullFallbackCount := svbFullFallbackCount + 1.U }
  when (trafficCounting && svbUnsupportedFallbackEvent) {
    svbUnsupportedFallbackCount := svbUnsupportedFallbackCount + 1.U
  }
  when (trafficCounting && svb.io.capture.fire) { svbAllocationCount := svbAllocationCount + 1.U }
  when (trafficCounting && !trafficStopPulse && svb.io.capture.fire && svb.io.occupancy >= 8.U) {
    svbWouldFullAt8 := svbWouldFullAt8 + 1.U
  }
  when (trafficCounting && !trafficStopPulse && svb.io.occupancy > 8.U) { svbCyclesAbove8 := svbCyclesAbove8 + 1.U }
  when (trafficCounting && svbCapturePending && !svbCaptureIssued && !svbCaptureResidentMatch) {
    svbCaptureFailures := svbCaptureFailures + 1.U
  }
  when (trafficCounting && svbFastLineValid && !RegNext(svbFastLineValid, false.B)) {
    svbBypassCount := svbBypassCount + 1.U
  }
  when (trafficCounting && wb.io.svb_release_done) { svbPromotionCount := svbPromotionCount + 1.U }
  when (trafficCounting && svb.io.acked) { svbAckCount := svbAckCount + 1.U }
  when (trafficCounting && svb.io.recoveryFromSvb) { svbRecoveryCount := svbRecoveryCount + 1.U }

  // A refill installs a new tag in this set/way and must discard attribution
  // left by the evicted line before any replayed store dirties the new line.
  val refillLastBeat = dataWriteArb.io.in(1).bits.addr(blockOffBits-1, rowOffBits) ===
    (cacheDataBeats - 1).U
  val refillOwnerMatch = dataWriteArb.io.in(1).bits.slot_epoch ===
    selectedRefillReservedEpoch
  when (dataWriteArb.io.in(1).fire && refillLastBeat && refillOwnerMatch) {
    val set = refillReqSet
    val way = refillReqWay
    when (selectedRefillSlotReserved) {
      slotEpoch(set)(way) := reservedEpoch(set)(way)
      dirtyPacketSeq(set)(way) := mshrs.io.refill.bits.image.contentSeq
      dirtyPacketTracked(set)(way) := mshrs.io.refill.bits.image.valid &&
        mshrs.io.refill.bits.image.contentSeq =/= 0.U
      lineGeneration(set)(way) := mshrs.io.refill.bits.image.generation
      imageKey(set)(way) := mshrs.io.refill.bits.image
      printf("STAGE2_TX IMPORT line=%x epoch=%x gen=%x seq=%x writer=%x valid=%x\n",
        mshrs.io.refill.bits.line_addr, reservedEpoch(set)(way),
        mshrs.io.refill.bits.image.generation, mshrs.io.refill.bits.image.contentSeq,
        mshrs.io.refill.bits.image.writer, mshrs.io.refill.bits.image.valid)
      imageValid(set)(way) := true.B
      lowerPreserved(set)(way) := true.B
      appliedEffectValid(set)(way) := false.B
    }
  }

  // Identity describes exactly the bytes written, including trusted seq=0.
  // Every semantic write revokes the current receipt. Same-package writes
  // retain their already-preserved safe predecessor, not an intermediate key.
  when (dataWriteArb.io.in(0).fire) {
    assert(imageSerial =/= ~0.U(32.W), "local image serial exhausted")
    val set = s3_req.addr(idxMSB, idxLSB)
    val way = OHToUInt(s3_way)
    when (s3_svbOwnsPredecessor) {
      // The younger image now owns L1.  The SVB entry remains the recovery
      // owner until its own safe promotion receives the L2 ACK.
      printf("FASTLINE_RELEASE cycle=%x line=%x set=%x tag=%x seq=%x epoch=%x acquire_cycle=%x release_reason=matching_semantic_write\n",
        io.csr_cycle, svbFastLine, svbFastSet, svbFastTag, svbFastSeq,
        svbFastEpoch, svbFastAcquireCycle)
      svbFastReleaseCycle := io.csr_cycle
      svbFastLineValid := false.B
    }
    lineGeneration(set)(way) := imageSerial
    imageValid(set)(way) := true.B
    imageSerial := imageSerial + 1.U
    printf("STAGE2_TX MODIFY line=%x epoch=%x old_gen=%x old_seq=%x old_writer=%x old_valid=%x lower=%x safe=%x new_gen=%x new_seq=%x writer=%x replay=%x cmd=%x req=%x\n",
      (s3_req.addr >> blockOffBits) << blockOffBits, s3_req.slot_epoch,
      imageKey(set)(way).generation, imageKey(set)(way).contentSeq,
      imageKey(set)(way).writer, imageKey(set)(way).valid, lowerPreserved(set)(way),
      L1Preservation.safe(imageKey(set)(way), safePacketWatermark),
      imageSerial, s3_req.packet_seq, outer.staticImageWriter.U, s3_replay,
      s3_req.uop.mem_cmd, s3_req.request_token)
    imageKey(set)(way).valid := true.B
    imageKey(set)(way).writer := outer.staticImageWriter.U
    imageKey(set)(way).generation := imageSerial
    imageKey(set)(way).contentSeq := s3_req.packet_seq
    lowerPreserved(set)(way) := false.B
    dirtyPacketSeq(set)(way) := s3_req.packet_seq
    dirtyPacketTracked(set)(way) := s3_req.packet_seq =/= 0.U
    when (s3_req.effect_token_valid) {
      appliedEffectValid(set)(way) := true.B
      appliedEffectToken(set)(way) := s3_req.effect_token
      appliedEffectResult(set)(way) := s3_result
    }
  }
  val svbFastLeaseAcquire = wb.io.snapshot_valid && svb.io.capture.fire
  val svbFastLeaseRelease = svbFastLineValid &&
    (svbFastLeaseRevoked || (s3_effect_fire && s3_svbOwnsPredecessor) || svbFlush)
  val svbFastWasValid = RegNext(svbFastLineValid, false.B)
  val svbFastAcquiredPrevious = RegNext(svbFastLeaseAcquire, false.B)
  val svbFastReleasedPrevious = RegNext(svbFastLeaseRelease, false.B)
  when (svbFastLineValid && !svbFastWasValid) {
    assert(svbFastAcquiredPrevious, "OWNER-1: lease acquired without snapshot")
  }
  when (!svbFastLineValid && svbFastWasValid) {
    assert(svbFastReleasedPrevious, "OWNER-1: lease released without a terminal event")
  }
  // Give an epoch boundary priority over any same-cycle fast-line update.
  when (svbFlush) {
    svbCapturePending := false.B
    svbCaptureIssued := false.B
    when (svbFastLineValid) {
      printf("FASTLINE_RELEASE cycle=%x line=%x set=%x tag=%x seq=%x epoch=%x acquire_cycle=%x release_reason=epoch_flush\n",
        io.csr_cycle, svbFastLine, svbFastSet, svbFastTag, svbFastSeq,
        svbFastEpoch, svbFastAcquireCycle)
      svbFastReleaseCycle := io.csr_cycle
    }
    svbFastLineValid := false.B
  }

  // New barrier-cost measurements use independent storage and do not alter
  // the existing physical dirty-writeback counters. They never feed ready or
  // valid back into the cache pipeline; a bucket collision only invalidates
  // the corresponding measurement.
  val crossPackageBarrierStats = Module(new GHBarrierLatencyStats(statsWindow))
  crossPackageBarrierStats.io.resetStats := io.traffic_reset
  crossPackageBarrierStats.io.event.valid := crossPackageBarrierEvent
  crossPackageBarrierStats.io.event.bits := Mux(
    p(GH_GlobalParams.GH_REAL_BARRIER_ENABLED).B,
    s2_overwrittenPacketSeq, overwrittenPacketSeq)
  crossPackageBarrierStats.io.safeWatermark := newSafePacketWatermark
  crossPackageBarrierStats.io.currentCycle := io.csr_cycle
  crossPackageBarrierStats.io.fatalProtocolError := addressStatsFatal

  val l1L2BarrierStats = Module(new GHBarrierLatencyStats(statsWindow))
  l1L2BarrierStats.io.resetStats := io.traffic_reset
  l1L2BarrierStats.io.event.valid := trafficCounting &&
    l1ReplacementWbEvent && l1ReplacementPacketTracked &&
    l1ReplacementPacketSeq =/= 0.U &&
    l1ReplacementPacketSeq > safePacketWatermark
  l1L2BarrierStats.io.event.bits := l1ReplacementPacketSeq
  l1L2BarrierStats.io.safeWatermark := newSafePacketWatermark
  l1L2BarrierStats.io.currentCycle := io.csr_cycle
  l1L2BarrierStats.io.fatalProtocolError := addressStatsFatal

  // 普通 store/load 只保留架构与严格两套一致口径。严格 store 路径接受
  // 由 ROB 架构提交锁存的资格，并在真实的 DCache 完成点结算。
  val completed_strict_store_cache = dataWriteArb.io.in(0).fire && s3_owner_match &&
    s3_req.strict_store_token_valid && s3_req.traffic_cacheable &&
    s3_req.uop.uses_stq && s3_req.uop.mem_cmd === M_XWR
  val completed_strict_store_uncache = mshrs.io.traffic_strict_store_complete
  val completed_lr           = io.lsu.traffic_lr_complete
  val completed_sc_success   = io.lsu.traffic_sc_success_complete
  val completed_sc_fail      = io.lsu.traffic_sc_fail_complete
  val completed_amo_cache    = io.lsu.traffic_amo_cache_complete
  val completed_amo_uncache  = io.lsu.traffic_amo_uncache_complete
  io.lsu.traffic_store_cache_complete := completed_strict_store_cache
  io.lsu.traffic_store_uncache_complete := completed_strict_store_uncache
  io.lsu.traffic_store_cache_complete_stq_idx := s3_req.uop.stq_idx
  io.lsu.traffic_store_cache_complete_token := s3_req.strict_store_token
  io.lsu.traffic_store_uncache_complete_stq_idx :=
    mshrs.io.traffic_strict_store_complete_stq_idx
  io.lsu.traffic_store_uncache_complete_token :=
    mshrs.io.traffic_strict_store_complete_token
  val store_uncache_cycle_sum = RegInit(0.U(64.W))
  val lr_count            = RegInit(0.U(64.W))
  val sc_success_count    = RegInit(0.U(64.W))
  val sc_fail_count       = RegInit(0.U(64.W))
  val amo_cache_count     = RegInit(0.U(64.W))
  val amo_uncache_count   = RegInit(0.U(64.W))
  when (io.traffic_reset) {
    store_uncache_cycle_sum := 0.U
    lr_count := 0.U
    sc_success_count := 0.U
    sc_fail_count := 0.U
    amo_cache_count := 0.U
    amo_uncache_count := 0.U
  }
  when (completed_strict_store_uncache) {
    // 严格完成事件和 CSR 周期值在同一个 BOOM 时钟沿采样。
    store_uncache_cycle_sum := store_uncache_cycle_sum + io.csr_cycle
  }
  when (completed_lr.reduce(_|_)) {
    lr_count := lr_count + PopCount(completed_lr)
  }
  when (completed_sc_success.reduce(_|_)) {
    sc_success_count := sc_success_count + PopCount(completed_sc_success)
  }
  when (completed_sc_fail.reduce(_|_)) {
    sc_fail_count := sc_fail_count + PopCount(completed_sc_fail)
  }
  when (completed_amo_cache.reduce(_|_)) {
    amo_cache_count := amo_cache_count + PopCount(completed_amo_cache)
  }
  when (completed_amo_uncache.reduce(_|_)) {
    amo_uncache_count := amo_uncache_count + PopCount(completed_amo_uncache)
  }
  // BOOM 和 Rocket checker 共用 0..6 的软件 ABI。BOOM 的 0..5 来自
  // LSU 架构计数，6 是架构 load_cache 中由 STQ 转发完成的严格子集。
  // 严格计数位于 36..45；共享 L2 在 BOOM tile 中覆盖 46..55。
  val trafficCounterLive = Wire(Vec(GH_GlobalParams.GH_TRAFFIC_COUNTERS, UInt(64.W)))
  trafficCounterLive := VecInit(Seq.fill(GH_GlobalParams.GH_TRAFFIC_COUNTERS)(0.U(64.W)))
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STORE_TOTAL) := io.lsu.traffic_arch_counter(0)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STORE_CACHE) := io.lsu.traffic_arch_counter(1)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STORE_UNCACHE) := io.lsu.traffic_arch_counter(2)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_LOAD_TOTAL) := io.lsu.traffic_arch_counter(3)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_LOAD_CACHE) := io.lsu.traffic_arch_counter(4)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_LOAD_UNCACHE) := io.lsu.traffic_arch_counter(5)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_LOAD_FORWARD) := io.lsu.traffic_arch_counter(13)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_LR) := lr_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_SC_SUCCESS) := sc_success_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_SC_FAIL) := sc_fail_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_AMO_TOTAL) := amo_cache_count + amo_uncache_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_AMO_CACHE) := amo_cache_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_AMO_UNCACHE) := amo_uncache_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_C_TOTAL) := l1_l2_c_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_WB_DIRTY) := l1_l2_dirty_wb_count
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STORE_UNCACHE_CYCLE_SUM) :=
    store_uncache_cycle_sum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN) :=
    unverifiedDirtyWbSeen
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED) :=
    unverifiedDirtyWbResolved
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING) :=
    unverifiedDirtyWbPending
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER) :=
    unverifiedDirtyWbDropped
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_FAILED_PACKAGES) := failedPackages
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM) :=
    safeCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM) :=
    writebackCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID) :=
    statsValid.asUInt
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_SAFE_PACKET_WATERMARK) :=
    safePacketWatermark
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_PACKAGE_RESULT_DROPPED) :=
    packageResultDropped
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_VERIFIED_DIRTY_WB) :=
    verifiedDirtyWbCount
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_NONVERIFY_DIRTY_WB) :=
    nonverifyDirtyWbCount
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_ALLOCATED_PACKAGES) := allocatedPackages
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_COMPLETED_PACKAGES) := completedPackages
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_PASSED_PACKAGES) := passedPackages
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CANCELLED_PACKAGES) := cancelledPackages
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STATS_ARITHMETIC_OVERFLOW) :=
    statsArithmeticOverflow
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED) :=
    verifyRequiredDirtyWbCount
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_STORE_TOTAL) :=
    io.lsu.traffic_arch_counter(6)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_STORE_CACHE) :=
    io.lsu.traffic_arch_counter(7)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_STORE_UNCACHE) :=
    io.lsu.traffic_arch_counter(8)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_LOAD_TOTAL) :=
    io.lsu.traffic_arch_counter(9)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_LOAD_CACHE) :=
    io.lsu.traffic_arch_counter(10)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_LOAD_UNCACHE) :=
    io.lsu.traffic_arch_counter(11)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_LOAD_CACHE_RESPONSE) :=
    io.lsu.traffic_arch_counter(12)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_LOAD_FORWARD) :=
    io.lsu.traffic_arch_counter(13)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_STRICT_PENDING) :=
    io.lsu.traffic_arch_counter(14)
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_COUNTER_ASSERT_FAIL) :=
    io.lsu.traffic_arch_counter(15)
  for (i <- 0 until GH_GlobalParams.GH_ADDRESS_STATS_GRANULES *
      GH_GlobalParams.GH_ADDRESS_STATS_PER_GRANULE) {
    trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_ADDRESS_STATS_BASE + i) :=
      addressStats.io.counters(i)
  }
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_ADDRESS_STATS_VALID) :=
    addressStats.io.statsValid.asUInt
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_ADDRESS_STATS_ERROR) :=
    addressStats.io.error
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_ADDRESS_STATS_PENDING) :=
    addressStats.io.pending
  for (i <- 0 until GH_GlobalParams.GH_ADDRESS_STATS_GRANULES *
      GH_GlobalParams.GH_ADDRESS_FIRST_STORE_STRIDE) {
    trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_FIRST_STORE_BASE + i) :=
      addressStats.io.firstStoreCounters(i)
  }
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_SEEN) :=
    crossPackageBarrierStats.io.seen
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_RESOLVED) :=
    crossPackageBarrierStats.io.resolved
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_PENDING) :=
    crossPackageBarrierStats.io.pending
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_DROPPED) :=
    crossPackageBarrierStats.io.dropped
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_REQUEST_CYCLE_SUM) :=
    crossPackageBarrierStats.io.requestCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_SAFE_CYCLE_SUM) :=
    crossPackageBarrierStats.io.safeCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_CROSS_PACKAGE_STATS_VALID) :=
    crossPackageBarrierStats.io.statsValid
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_SEEN) :=
    l1L2BarrierStats.io.seen
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_RESOLVED) :=
    l1L2BarrierStats.io.resolved
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_PENDING) :=
    l1L2BarrierStats.io.pending
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_DROPPED) :=
    l1L2BarrierStats.io.dropped
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_REQUEST_CYCLE_SUM) :=
    l1L2BarrierStats.io.requestCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_SAFE_CYCLE_SUM) :=
    l1L2BarrierStats.io.safeCycleSum
  trafficCounterLive(GH_GlobalParams.GH_TRAFFIC_L1_L2_BARRIER_STATS_VALID) :=
    l1L2BarrierStats.io.statsValid
  val trafficCounterSnapshot = RegInit(VecInit(
    Seq.fill(GH_GlobalParams.GH_TRAFFIC_COUNTERS)(0.U(64.W))))
  val trafficCounterSnapshotValid = RegInit(false.B)
  val trafficStopCapturePending = RegInit(false.B)
  val outstandingMshrCount = PopCount(mshrs.io.owner_line_valid)
  val outstandingReplayResultCount = replayResultQ.map(_.io.count).reduce(_ +& _)
  // Continuously exported read-only state, sampled by emulator after final eval.
  val stage1CacheState = Seq(
    io.csr_cycle, s1_valid.asUInt, s2_valid.asUInt, mshrs.io.active_transactions,
    mshrs.io.fence_rdy.asUInt, mshrs.io.replay.valid.asUInt, replayPipelineBusy.asUInt,
    outstandingReplayResultCount, completionQ.io.count, s3_valid.asUInt,
    io.lsu.store_done.valid.asUInt, (wb.io.idx.valid || wb.io.pending_idx.valid).asUInt, prober.io.state.valid.asUInt,
    mshrs.io.refill.valid.asUInt, PopCount(installActive.map(_.asUInt.orR)),
    PopCount(completionPending.map(_.asUInt.orR)), killed_store_replay_valid.asUInt,
    PopCount(slotReserved.map(_.asUInt.orR)), crossPackagePending.asUInt,
    uncache_resp.valid.asUInt, VecInit(io.lsu.resp.map(_.valid)).asUInt,
    tl_out.e.valid.asUInt, tl_out.d.valid.asUInt, tl_out.a.valid.asUInt,
    s3_req.request_token, completionQ.io.deq.bits.req.request_token,
    mshrs.io.replay.bits.request_token, outstandingMshrCount)
  for ((value, i) <- stage1CacheState.zipWithIndex) {
    val probe = Wire(UInt(64.W))
    probe := value
    BoringUtils.addSource(probe, s"stage1_cache_${tileParams.hartId}_$i")
  }
  when (trafficStopPulse) {
    printf("STAGE1_TX EXIT_STATE snapshot=traffic_stop mshr_outstanding=%x replay_valid=%x replay_busy=%x replay_result_q=%x completion_q=%x s3_valid=%x store_done_valid=%x\n",
      outstandingMshrCount, mshrs.io.replay.valid, replayPipelineBusy,
      outstandingReplayResultCount, completionQ.io.count, s3_valid,
      io.lsu.store_done.valid)
  }
  when (io.traffic_reset || io.traffic_start) {
    trafficCounterSnapshotValid := false.B
    trafficStopCapturePending := false.B
  }.elsewhen (trafficStopPulse) {
    // Capture on the following edge so every counter update performed on the
    // inclusive STOP edge is visible in one coherent snapshot.
    trafficCounterSnapshotValid := false.B
    trafficStopCapturePending := true.B
  }.elsewhen (trafficStopCapturePending &&
              io.lsu.traffic_arch_counter(14) === 0.U &&
              addressStats.io.idle &&
              crossPackageBarrierStats.io.pending === 0.U &&
              l1L2BarrierStats.io.pending === 0.U) {
    // 等 LSU 的架构/严格计数完全收敛后再冻结快照，避免 STOP 后尾部响应
    // 尚未结算时软件读到过早的计数值。
    trafficCounterSnapshot := trafficCounterLive
    trafficCounterSnapshotValid := true.B
    trafficStopCapturePending := false.B
  }
  io.traffic_counter := Mux(trafficCounterSnapshotValid,
    trafficCounterSnapshot, trafficCounterLive)

  //===== EC watchdog diagnostics: observation only ====//
  // Preserve the complete S2 -> MSHR/replay -> S3/data-array completion
  // chain and barrier state in the waveform.  None of these probes drives
  // cache control, handshake, completion, or statistics logic.
  val debug_s2_valid = s2_valid
  val debug_s2_admission = VecInit(s2_effective_req.map(_.admission))
  val debug_owner_reservation_fire = VecInit((0 until memWidth).map(w =>
    mshrs.io.req(w).fire && s2_effective_req(w).admission.isOneOf(
      CacheAdmission.primary, CacheAdmission.upgrade)))
  val debug_s2_transaction_token = VecInit(s2_effective_req.map(_.transaction_token))
  val debug_s2_request_token = VecInit(s2_effective_req.map(_.request_token))
  val debug_s2_owner_way = VecInit(s2_effective_req.map(_.owner_way))
  val debug_install_fire = mshrs.io.install.fire
  val debug_install_fault = mshrs.io.install_fault
  val debug_refill_fault = mshrs.io.refill_fault
  val debug_store_terminal_fire = io.lsu.store_done.fire
  // Use named WireInit aliases for fields that do not otherwise drive cache
  // logic.  Direct aliases of these Bundle leaves were dropped before FIRRTL
  // emitted the DontTouch annotation in the Optimization 1 generated model.
  // The probes remain observation-only.
  val debug_store_terminal_token = WireInit(io.lsu.store_done.bits.req.request_token)
  val debug_store_terminal_status = WireInit(io.lsu.store_done.bits.status)
  val debug_new_image_generation = imageSerial
  Seq(debug_s2_admission, debug_owner_reservation_fire, debug_s2_transaction_token,
    debug_s2_request_token, debug_s2_owner_way, debug_install_fire, debug_install_fault,
    debug_refill_fault, debug_store_terminal_fire, debug_store_terminal_token,
    debug_store_terminal_status, debug_new_image_generation).foreach(dontTouch(_))
  val debug_slot_epoch = VecInit((0 until nSets).flatMap(s =>
    (0 until nWays).map(w => slotEpoch(s)(w))))
  val debug_line_generation = VecInit((0 until nSets).flatMap(s =>
    (0 until nWays).map(w => lineGeneration(s)(w))))
  val debug_applied_effect_valid = VecInit((0 until nSets).flatMap(s =>
    (0 until nWays).map(w => appliedEffectValid(s)(w))))
  val debug_applied_effect_token = VecInit((0 until nSets).flatMap(s =>
    (0 until nWays).map(w => appliedEffectToken(s)(w))))
  val debug_s2_type = s2_type
  val debug_s2_stq_idx = VecInit(s2_req.map(_.uop.stq_idx))
  val debug_s2_packet_seq = VecInit(s2_req.map(_.packet_seq))
  val debug_s2_slot_epoch = VecInit(s2_req.map(_.slot_epoch))
  val debug_s2_line_generation = VecInit(s2_req.map(_.line_generation))
  val debug_s2_effect_token_valid = VecInit(s2_req.map(_.effect_token_valid))
  val debug_s2_effect_token = VecInit(s2_req.map(_.effect_token))
  val debug_s2_token_valid = VecInit(s2_req.map(_.strict_store_token_valid))
  val debug_s2_token = VecInit(s2_req.map(_.strict_store_token))
  val debug_s2_nack = s2_nack
  val debug_s2_nack_miss = s2_nack_miss
  val debug_s2_nack_victim = s2_nack_victim
  val debug_s2_nack_wb = s2_nack_wb
  val debug_s2_nack_data = s2_nack_data
  val debug_mshr_req_valid = VecInit(mshrs.io.req.map(_.valid))
  val debug_mshr_req_ready = VecInit(mshrs.io.req.map(_.ready))
  val debug_mshr_req_fire = VecInit(mshrs.io.req.map(_.fire))
  val debug_replay_valid = mshrs.io.replay.valid
  val debug_replay_fire = mshrs.io.replay.fire
  val debug_replay_stq_idx = mshrs.io.replay.bits.uop.stq_idx
  val debug_replay_packet_seq = mshrs.io.replay.bits.packet_seq
  val debug_replay_token_valid = mshrs.io.replay.bits.strict_store_token_valid
  val debug_replay_token = mshrs.io.replay.bits.strict_store_token
  val debug_replay_slot_epoch = mshrs.io.replay.bits.slot_epoch
  val debug_replay_line_generation = mshrs.io.replay.bits.line_generation
  val debug_replay_effect_token = mshrs.io.replay.bits.effect_token
  val debug_replay_effect_done = replayEffectDone
  val debug_replay_cancel = replayCancel
  val debug_killed_store_replay_valid = killed_store_replay_valid
  val debug_killed_store_replay_fire = killed_store_replay_fire
  val debug_killed_store_replay_stq_idx = killed_store_replay_req.uop.stq_idx
  val debug_killed_store_replay_token_valid = killed_store_replay_req.strict_store_token_valid
  val debug_killed_store_replay_token = killed_store_replay_req.strict_store_token
  val debug_s3_valid = s3_valid
  val debug_s3_stq_idx = s3_req.uop.stq_idx
  val debug_s3_packet_seq = s3_req.packet_seq
  val debug_s3_token_valid = s3_req.strict_store_token_valid
  val debug_s3_token = s3_req.strict_store_token
  val debug_s3_slot_epoch = s3_req.slot_epoch
  val debug_s3_line_generation = s3_req.line_generation
  val debug_s3_effect_token = s3_req.effect_token
  val debug_s3_owner_match = s3_owner_match
  val debug_s3_effect_eligible = s3_effect_eligible
  val debug_s3_replay = s3_replay
  val debug_data_write_pipeline_fire = dataWriteArb.io.in(0).fire
  val debug_refill_valid = dataWriteArb.io.in(1).valid
  val debug_refill_fire = dataWriteArb.io.in(1).fire
  val debug_refill_owner_match = refillReqOwnerMatch
  val debug_cross_package_mshr_conflict = crossPackageMshrConflict
  val debug_cross_package_slot_conflict = crossPackageSlotConflict
  val debug_cross_package_meta_clear_block = WireInit(crossPackageMetaClearBlock)
  val debug_s2_realloc_owner_conflict = s2_realloc_owner_conflict
  val debug_cache_completion = completed_strict_store_cache
  val debug_uncache_completion = completed_strict_store_uncache
  val debug_uncache_completion_stq_idx = mshrs.io.traffic_strict_store_complete_stq_idx
  val debug_uncache_completion_token = mshrs.io.traffic_strict_store_complete_token
  val debug_l1_cross_package_blocked = l1CrossPackageBlocked
  val debug_cross_package_block_condition = crossPackageBlockCondition
  val debug_cross_package_pending = crossPackagePending
  val debug_cross_package_issued = crossPackageIssued
  val debug_cross_package_meta_clear_pending = WireInit(crossPackageMetaClearPending)
  val debug_cross_package_pending_seq = crossPackagePendingSeq
  val debug_safe_packet_watermark = safePacketWatermark
  // Keep the complete parent[] load/store provenance visible. These aliases
  // are observation-only and deliberately do not participate in cache
  // control, arbitration, or statistics.
  val debug_traffic_counting = trafficCounting
  val debug_traffic_start = io.traffic_start
  val debug_traffic_stop = io.traffic_stop
  val debug_traffic_reset = io.traffic_reset
  val debug_s0_valid = s0_valid
  val debug_s0_type = s0_type
  val debug_s0_addr = VecInit(s0_req.map(_.addr))
  val debug_s0_data = VecInit(s0_req.map(_.data))
  val debug_s0_packet_seq = VecInit(s0_req.map(_.packet_seq))
  val debug_s1_valid = s1_valid
  val debug_s1_type = s1_type
  val debug_s1_addr = VecInit(s1_req.map(_.addr))
  val debug_s1_data = VecInit(s1_req.map(_.data))
  val debug_s1_packet_seq = VecInit(s1_req.map(_.packet_seq))
  val debug_s2_addr = VecInit(s2_req.map(_.addr))
  val debug_s2_data = VecInit(s2_req.map(_.data))
  val debug_s2_data_word = s2_data_word
  val debug_s2_send_resp = s2_send_resp
  val debug_s2_send_nack = s2_send_nack
  val debug_s2_hit = s2_hit
  val debug_s2_tag_match = VecInit(s2_tag_match)
  val debug_s2_hit_state = VecInit(s2_hit_state.map(_.state))
  val debug_cache_resp_valid = VecInit(cache_resp.map(_.valid))
  val debug_cache_resp_data = VecInit(cache_resp.map(_.bits.data))
  val debug_uncache_resp_valid = uncache_resp.valid
  val debug_uncache_resp_data = uncache_resp.bits.data
  val debug_lsu_resp_valid = VecInit(io.lsu.resp.map(_.valid))
  val debug_lsu_resp_data = VecInit(io.lsu.resp.map(_.bits.data))
  val debug_data_write_valid = dataWriteArb.io.in(0).valid
  val debug_data_write_fire = dataWriteArb.io.in(0).fire
  val debug_data_write_addr = dataWriteArb.io.in(0).bits.addr
  val debug_data_write_data = dataWriteArb.io.in(0).bits.data
  val debug_data_write_wmask = dataWriteArb.io.in(0).bits.wmask
  val debug_data_write_way_en = dataWriteArb.io.in(0).bits.way_en
  // Materialize dynamic-array index/provenance probes as real named wires.
  // Directly dontTouch-ing the indexing expressions makes older FIRRTL
  // versions serialize the signal as an Index component and then attempt to
  // parse the name (for example, "debug_modifying_set") as an integer.
  val debug_modifying_set = Wire(UInt(idxBits.W))
  val debug_modifying_way = Wire(UInt(log2Ceil(nWays max 2).W))
  val debug_overwritten_packet_seq = Wire(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val debug_overwritten_packet_tracked = Wire(Bool())
  debug_modifying_set := modifyingSet
  debug_modifying_way := modifyingWay
  debug_overwritten_packet_seq := overwrittenPacketSeq
  debug_overwritten_packet_tracked := overwrittenPacketTracked
  // These handshake/status taps must be explicit wires so DontTouch survives
  // through emitted RTL, rather than a Chisel-only alias of a decoupled field.
  val debug_cross_package_wb_valid = WireInit(crossPackageWbReq.valid)
  val debug_cross_package_wb_ready = WireInit(crossPackageWbReq.ready)
  val debug_cross_package_wb_fire = crossPackageWbReq.fire
  val debug_cross_package_wb_param = crossPackageWbReq.bits.param
  val debug_cross_package_wb_done = WireInit(crossPackageWbDone)
  val debug_cross_package_meta_clear_valid = crossPackageMetaClear.valid
  val debug_cross_package_meta_clear_fire = crossPackageMetaClear.fire
  val debug_meta_write_valid = metaWriteArb.io.out.valid
  val debug_meta_write_fire = metaWriteArb.io.out.fire
  val debug_meta_write_idx = metaWriteArb.io.out.bits.idx
  val debug_meta_write_tag = metaWriteArb.io.out.bits.tag
  val debug_meta_write_coh_state = metaWriteArb.io.out.bits.data.coh.state
  val debug_tl_a_fire = tl_out.a.fire
  val debug_tl_a_opcode = tl_out.a.bits.opcode
  val debug_tl_a_address = tl_out.a.bits.address
  val debug_tl_a_data = tl_out.a.bits.data
  val debug_tl_a_source = tl_out.a.bits.source
  val debug_tl_c_fire = tl_out.c.fire
  val debug_tl_c_opcode = tl_out.c.bits.opcode
  val debug_tl_c_param = tl_out.c.bits.param
  val debug_tl_c_address = tl_out.c.bits.address
  val debug_tl_c_data = tl_out.c.bits.data
  val debug_tl_d_fire = tl_out.d.fire
  val debug_tl_d_opcode = tl_out.d.bits.opcode
  val debug_tl_d_param = tl_out.d.bits.param
  val debug_tl_d_source = tl_out.d.bits.source
  val debug_tl_d_data = tl_out.d.bits.data
  val debug_address_stats_event_valid = VecInit(io.lsu.address_stats_event.map(_.valid))
  val debug_address_stats_event_addr = VecInit(io.lsu.address_stats_event.map(_.bits.addr))
  val debug_address_stats_event_is_store = VecInit(io.lsu.address_stats_event.map(_.bits.isStore))
  val debug_address_stats_event_seq = VecInit(io.lsu.address_stats_event.map(_.bits.packetSeq))
  val debug_address_stats_valid = addressStats.io.statsValid
  val debug_address_stats_error = addressStats.io.error
  val debug_address_stats_pending = addressStats.io.pending
  dontTouch(debug_s2_valid)
  dontTouch(debug_slot_epoch)
  dontTouch(debug_line_generation)
  dontTouch(debug_applied_effect_valid)
  dontTouch(debug_applied_effect_token)
  dontTouch(debug_s2_type)
  dontTouch(debug_s2_stq_idx)
  dontTouch(debug_s2_packet_seq)
  dontTouch(debug_s2_slot_epoch)
  dontTouch(debug_s2_line_generation)
  dontTouch(debug_s2_effect_token_valid)
  dontTouch(debug_s2_effect_token)
  dontTouch(debug_s2_token_valid)
  dontTouch(debug_s2_token)
  dontTouch(debug_s2_nack)
  dontTouch(debug_s2_nack_miss)
  dontTouch(debug_s2_nack_victim)
  dontTouch(debug_s2_nack_wb)
  dontTouch(debug_s2_nack_data)
  dontTouch(debug_mshr_req_valid)
  dontTouch(debug_mshr_req_ready)
  dontTouch(debug_mshr_req_fire)
  dontTouch(debug_replay_valid)
  dontTouch(debug_replay_fire)
  dontTouch(debug_replay_stq_idx)
  dontTouch(debug_replay_packet_seq)
  dontTouch(debug_replay_token_valid)
  dontTouch(debug_replay_token)
  dontTouch(debug_replay_slot_epoch)
  dontTouch(debug_replay_line_generation)
  dontTouch(debug_replay_effect_token)
  dontTouch(debug_replay_effect_done)
  dontTouch(debug_replay_cancel)
  dontTouch(debug_killed_store_replay_valid)
  dontTouch(debug_killed_store_replay_fire)
  dontTouch(debug_killed_store_replay_stq_idx)
  dontTouch(debug_killed_store_replay_token_valid)
  dontTouch(debug_killed_store_replay_token)
  dontTouch(debug_s3_valid)
  dontTouch(debug_s3_stq_idx)
  dontTouch(debug_s3_packet_seq)
  dontTouch(debug_s3_token_valid)
  dontTouch(debug_s3_token)
  dontTouch(debug_s3_slot_epoch)
  dontTouch(debug_s3_line_generation)
  dontTouch(debug_s3_effect_token)
  dontTouch(debug_s3_owner_match)
  dontTouch(debug_s3_effect_eligible)
  dontTouch(debug_s3_replay)
  dontTouch(debug_data_write_pipeline_fire)
  dontTouch(debug_refill_valid)
  dontTouch(debug_refill_fire)
  dontTouch(debug_refill_owner_match)
  dontTouch(debug_cross_package_mshr_conflict)
  dontTouch(debug_cross_package_slot_conflict)
  dontTouch(debug_cross_package_meta_clear_block)
  dontTouch(debug_s2_realloc_owner_conflict)
  dontTouch(debug_cache_completion)
  dontTouch(debug_uncache_completion)
  dontTouch(debug_uncache_completion_stq_idx)
  dontTouch(debug_uncache_completion_token)
  dontTouch(debug_l1_cross_package_blocked)
  dontTouch(debug_cross_package_block_condition)
  dontTouch(debug_cross_package_pending)
  dontTouch(debug_cross_package_issued)
  dontTouch(debug_cross_package_meta_clear_pending)
  dontTouch(debug_cross_package_pending_seq)
  dontTouch(debug_safe_packet_watermark)
  dontTouch(debug_traffic_counting)
  dontTouch(debug_traffic_start)
  dontTouch(debug_traffic_stop)
  dontTouch(debug_traffic_reset)
  dontTouch(debug_s0_valid)
  dontTouch(debug_s0_type)
  dontTouch(debug_s0_addr)
  dontTouch(debug_s0_data)
  dontTouch(debug_s0_packet_seq)
  dontTouch(debug_s1_valid)
  dontTouch(debug_s1_type)
  dontTouch(debug_s1_addr)
  dontTouch(debug_s1_data)
  dontTouch(debug_s1_packet_seq)
  dontTouch(debug_s2_addr)
  dontTouch(debug_s2_data)
  dontTouch(debug_s2_data_word)
  dontTouch(debug_s2_send_resp)
  dontTouch(debug_s2_send_nack)
  dontTouch(debug_s2_hit)
  dontTouch(debug_s2_tag_match)
  dontTouch(debug_s2_hit_state)
  dontTouch(debug_cache_resp_valid)
  dontTouch(debug_cache_resp_data)
  dontTouch(debug_uncache_resp_valid)
  dontTouch(debug_uncache_resp_data)
  dontTouch(debug_lsu_resp_valid)
  dontTouch(debug_lsu_resp_data)
  dontTouch(debug_data_write_valid)
  dontTouch(debug_data_write_fire)
  dontTouch(debug_data_write_addr)
  dontTouch(debug_data_write_data)
  dontTouch(debug_data_write_wmask)
  dontTouch(debug_data_write_way_en)
  dontTouch(debug_modifying_set)
  dontTouch(debug_modifying_way)
  dontTouch(debug_overwritten_packet_seq)
  dontTouch(debug_overwritten_packet_tracked)
  dontTouch(debug_cross_package_wb_valid)
  dontTouch(debug_cross_package_wb_ready)
  dontTouch(debug_cross_package_wb_fire)
  dontTouch(debug_cross_package_wb_param)
  dontTouch(debug_cross_package_wb_done)
  dontTouch(debug_cross_package_meta_clear_valid)
  dontTouch(debug_cross_package_meta_clear_fire)
  dontTouch(debug_meta_write_valid)
  dontTouch(debug_meta_write_fire)
  dontTouch(debug_meta_write_idx)
  dontTouch(debug_meta_write_tag)
  dontTouch(debug_meta_write_coh_state)
  dontTouch(debug_tl_a_fire)
  dontTouch(debug_tl_a_opcode)
  dontTouch(debug_tl_a_address)
  dontTouch(debug_tl_a_data)
  dontTouch(debug_tl_a_source)
  dontTouch(debug_tl_c_fire)
  dontTouch(debug_tl_c_opcode)
  dontTouch(debug_tl_c_param)
  dontTouch(debug_tl_c_address)
  dontTouch(debug_tl_c_data)
  dontTouch(debug_tl_d_fire)
  dontTouch(debug_tl_d_opcode)
  dontTouch(debug_tl_d_param)
  dontTouch(debug_tl_d_source)
  dontTouch(debug_tl_d_data)
  dontTouch(debug_address_stats_event_valid)
  dontTouch(debug_address_stats_event_addr)
  dontTouch(debug_address_stats_event_is_store)
  dontTouch(debug_address_stats_event_seq)
  dontTouch(debug_address_stats_valid)
  dontTouch(debug_address_stats_error)
  dontTouch(debug_address_stats_pending)

  // SLOWDOWN_TRACE_BEGIN: observation-only; no functional consumers.
  val slowdown_lsu_valid = chisel3.WireInit(io.lsu.req.valid)
  chisel3.dontTouch(slowdown_lsu_valid)
  val slowdown_lsu_ready = chisel3.WireInit(io.lsu.req.ready)
  chisel3.dontTouch(slowdown_lsu_ready)
  val slowdown_lsu_lane_valid = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.valid)))
  chisel3.dontTouch(slowdown_lsu_lane_valid)
  val slowdown_lsu_addr = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.addr)))
  chisel3.dontTouch(slowdown_lsu_addr)
  val slowdown_lsu_cmd = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.uop.mem_cmd)))
  chisel3.dontTouch(slowdown_lsu_cmd)
  val slowdown_lsu_rob_idx = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.uop.rob_idx)))
  chisel3.dontTouch(slowdown_lsu_rob_idx)
  val slowdown_lsu_ldq_idx = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.uop.ldq_idx)))
  chisel3.dontTouch(slowdown_lsu_ldq_idx)
  val slowdown_lsu_stq_idx = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.uop.stq_idx)))
  chisel3.dontTouch(slowdown_lsu_stq_idx)
  val slowdown_lsu_pc = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.uop.debug_pc)))
  chisel3.dontTouch(slowdown_lsu_pc)
  val slowdown_lsu_packet_seq = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.packet_seq)))
  chisel3.dontTouch(slowdown_lsu_packet_seq)
  val slowdown_lsu_token_valid = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.request_token_valid)))
  chisel3.dontTouch(slowdown_lsu_token_valid)
  val slowdown_lsu_token = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.request_token)))
  chisel3.dontTouch(slowdown_lsu_token)
  val slowdown_lsu_is_hella = chisel3.WireInit(VecInit(io.lsu.req.bits.map(_.bits.is_hella)))
  chisel3.dontTouch(slowdown_lsu_is_hella)
  val slowdown_lsu_set = chisel3.WireInit(VecInit(io.lsu.req.bits.map(r => r.bits.addr(idxMSB, idxLSB))))
  chisel3.dontTouch(slowdown_lsu_set)
  val slowdown_lsu_tag = chisel3.WireInit(VecInit(io.lsu.req.bits.map(r => r.bits.addr >> untagBits)))
  chisel3.dontTouch(slowdown_lsu_tag)
  val slowdown_csr_cycle = chisel3.WireInit(io.csr_cycle)
  chisel3.dontTouch(slowdown_csr_cycle)
  val slowdown_pending = chisel3.WireInit(crossPackagePending)
  chisel3.dontTouch(slowdown_pending)
  val slowdown_pending_set = chisel3.WireInit(crossPackagePendingSet)
  chisel3.dontTouch(slowdown_pending_set)
  val slowdown_pending_tag = chisel3.WireInit(crossPackagePendingTag)
  chisel3.dontTouch(slowdown_pending_tag)
  val slowdown_pending_way = chisel3.WireInit(crossPackagePendingWay)
  chisel3.dontTouch(slowdown_pending_way)
  val slowdown_pending_seq = chisel3.WireInit(crossPackagePendingSeq)
  chisel3.dontTouch(slowdown_pending_seq)
  val slowdown_pending_epoch = chisel3.WireInit(crossPackagePendingEpoch)
  chisel3.dontTouch(slowdown_pending_epoch)
  val slowdown_pending_writer = chisel3.WireInit(crossPackagePendingKey.writer)
  chisel3.dontTouch(slowdown_pending_writer)
  val slowdown_pending_generation = chisel3.WireInit(crossPackagePendingKey.generation)
  chisel3.dontTouch(slowdown_pending_generation)
  val slowdown_pending_content_seq = chisel3.WireInit(crossPackagePendingKey.contentSeq)
  chisel3.dontTouch(slowdown_pending_content_seq)
  val slowdown_freeze = chisel3.WireInit(clearFreezeValid)
  chisel3.dontTouch(slowdown_freeze)
  val slowdown_freeze_set = chisel3.WireInit(clearFreezeSet)
  chisel3.dontTouch(slowdown_freeze_set)
  val slowdown_freeze_conflict = chisel3.WireInit(lsu_clear_freeze_set_conflict)
  chisel3.dontTouch(slowdown_freeze_conflict)
  val slowdown_pipeline_ready = chisel3.WireInit(lsu_pipeline_ready)
  chisel3.dontTouch(slowdown_pipeline_ready)
  val slowdown_killed_replay = chisel3.WireInit(killed_store_replay_valid)
  chisel3.dontTouch(slowdown_killed_replay)
  val slowdown_domain_wait = chisel3.WireInit(crossPackageDomainWait)
  chisel3.dontTouch(slowdown_domain_wait)
  val slowdown_block_condition = chisel3.WireInit(crossPackageBlockCondition)
  chisel3.dontTouch(slowdown_block_condition)
  val slowdown_pending_line = chisel3.WireInit(crossPackagePendingLine)
  chisel3.dontTouch(slowdown_pending_line)
  val slowdown_pending_resident_match = chisel3.WireInit(crossPackageResidentMatch)
  chisel3.dontTouch(slowdown_pending_resident_match)
  val slowdown_pending_mshr_conflict = chisel3.WireInit(crossPackageMshrConflict)
  chisel3.dontTouch(slowdown_pending_mshr_conflict)
  val slowdown_pending_slot_conflict = chisel3.WireInit(crossPackageSlotConflict)
  chisel3.dontTouch(slowdown_pending_slot_conflict)
  val slowdown_pending_issued = chisel3.WireInit(crossPackageIssued)
  chisel3.dontTouch(slowdown_pending_issued)
  val slowdown_pending_wb_done = chisel3.WireInit(crossPackageWbDone)
  chisel3.dontTouch(slowdown_pending_wb_done)
  val slowdown_meta_clear_valid = chisel3.WireInit(crossPackageMetaClear.valid)
  chisel3.dontTouch(slowdown_meta_clear_valid)
  val slowdown_meta_clear_ready = chisel3.WireInit(crossPackageMetaClear.ready)
  chisel3.dontTouch(slowdown_meta_clear_ready)
  val slowdown_mshr_active = chisel3.WireInit(mshrs.io.active_transactions)
  chisel3.dontTouch(slowdown_mshr_active)
  val slowdown_tl_a_valid = chisel3.WireInit(tl_out.a.valid)
  chisel3.dontTouch(slowdown_tl_a_valid)
  val slowdown_tl_a_ready = chisel3.WireInit(tl_out.a.ready)
  chisel3.dontTouch(slowdown_tl_a_ready)
  val slowdown_tl_a_opcode = chisel3.WireInit(tl_out.a.bits.opcode)
  chisel3.dontTouch(slowdown_tl_a_opcode)
  val slowdown_tl_a_source = chisel3.WireInit(tl_out.a.bits.source)
  chisel3.dontTouch(slowdown_tl_a_source)
  val slowdown_tl_a_size = chisel3.WireInit(tl_out.a.bits.size)
  chisel3.dontTouch(slowdown_tl_a_size)
  val slowdown_tl_a_address = chisel3.WireInit(tl_out.a.bits.address)
  chisel3.dontTouch(slowdown_tl_a_address)
  val slowdown_tl_c_valid = chisel3.WireInit(tl_out.c.valid)
  chisel3.dontTouch(slowdown_tl_c_valid)
  val slowdown_tl_c_ready = chisel3.WireInit(tl_out.c.ready)
  chisel3.dontTouch(slowdown_tl_c_ready)
  val slowdown_tl_c_opcode = chisel3.WireInit(tl_out.c.bits.opcode)
  chisel3.dontTouch(slowdown_tl_c_opcode)
  val slowdown_tl_c_source = chisel3.WireInit(tl_out.c.bits.source)
  chisel3.dontTouch(slowdown_tl_c_source)
  val slowdown_tl_c_size = chisel3.WireInit(tl_out.c.bits.size)
  chisel3.dontTouch(slowdown_tl_c_size)
  val slowdown_tl_c_address = chisel3.WireInit(tl_out.c.bits.address)
  chisel3.dontTouch(slowdown_tl_c_address)
  val slowdown_tl_d_valid = chisel3.WireInit(tl_out.d.valid)
  chisel3.dontTouch(slowdown_tl_d_valid)
  val slowdown_tl_d_ready = chisel3.WireInit(tl_out.d.ready)
  chisel3.dontTouch(slowdown_tl_d_ready)
  val slowdown_tl_d_opcode = chisel3.WireInit(tl_out.d.bits.opcode)
  chisel3.dontTouch(slowdown_tl_d_opcode)
  val slowdown_tl_d_source = chisel3.WireInit(tl_out.d.bits.source)
  chisel3.dontTouch(slowdown_tl_d_source)
  val slowdown_tl_d_size = chisel3.WireInit(tl_out.d.bits.size)
  chisel3.dontTouch(slowdown_tl_d_size)
  val slowdown_core_clock = chisel3.WireInit(clock.asBool)
  chisel3.dontTouch(slowdown_core_clock)
  val slowdown_lsu_resp_valid = chisel3.WireInit(VecInit(io.lsu.resp.map(_.valid)))
  chisel3.dontTouch(slowdown_lsu_resp_valid)
  val slowdown_lsu_resp_rob_idx = chisel3.WireInit(VecInit(io.lsu.resp.map(_.bits.uop.rob_idx)))
  chisel3.dontTouch(slowdown_lsu_resp_rob_idx)
  val slowdown_lsu_resp_token = chisel3.WireInit(VecInit(io.lsu.resp.map(_.bits.request_token)))
  chisel3.dontTouch(slowdown_lsu_resp_token)
  val slowdown_lsu_resp_token_valid = chisel3.WireInit(VecInit(io.lsu.resp.map(_.bits.request_token_valid)))
  chisel3.dontTouch(slowdown_lsu_resp_token_valid)
  // SLOWDOWN_TRACE_END

  // OPTIMIZATION_1_TRACE_BEGIN: observation-only.  These aliases distinguish
  // entry qualification, local hit/miss outcome, and the safety predecessor
  // state without participating in cache control.
  val slowdown_opt1_bypass_window = chisel3.WireInit(clearFreezeReadBypassWindow)
  chisel3.dontTouch(slowdown_opt1_bypass_window)
  val slowdown_opt1_bypass_lane = chisel3.WireInit(lsu_clear_freeze_read_bypass_lane)
  chisel3.dontTouch(slowdown_opt1_bypass_lane)
  val slowdown_opt1_bypass_any = chisel3.WireInit(lsu_clear_freeze_read_bypass_any)
  chisel3.dontTouch(slowdown_opt1_bypass_any)
  val slowdown_opt1_s1_bypass = chisel3.WireInit(s1_clear_freeze_read_bypass)
  chisel3.dontTouch(slowdown_opt1_s1_bypass)
  val slowdown_opt1_s1_valid = chisel3.WireInit(s1_valid)
  chisel3.dontTouch(slowdown_opt1_s1_valid)
  val slowdown_opt1_s1_before_freeze = chisel3.WireInit(s1_before_freeze)
  chisel3.dontTouch(slowdown_opt1_s1_before_freeze)
  val slowdown_opt1_s2_bypass = chisel3.WireInit(s2_clear_freeze_read_bypass)
  chisel3.dontTouch(slowdown_opt1_s2_bypass)
  val slowdown_opt1_s2_before_freeze = chisel3.WireInit(s2_before_freeze)
  chisel3.dontTouch(slowdown_opt1_s2_before_freeze)
  val slowdown_opt1_s2_type = chisel3.WireInit(s2_type)
  chisel3.dontTouch(slowdown_opt1_s2_type)
  val slowdown_opt1_s2_bypass_miss = chisel3.WireInit(s2_clear_freeze_read_bypass_miss)
  chisel3.dontTouch(slowdown_opt1_s2_bypass_miss)
  val slowdown_opt1_s2_hit = chisel3.WireInit(s2_hit)
  chisel3.dontTouch(slowdown_opt1_s2_hit)
  val slowdown_opt1_s2_nack = chisel3.WireInit(s2_nack)
  chisel3.dontTouch(slowdown_opt1_s2_nack)
  val slowdown_opt1_s2_send_resp = chisel3.WireInit(s2_send_resp)
  chisel3.dontTouch(slowdown_opt1_s2_send_resp)
  val slowdown_opt1_s2_valid = chisel3.WireInit(s2_valid)
  chisel3.dontTouch(slowdown_opt1_s2_valid)
  val slowdown_opt1_s2_addr = chisel3.WireInit(VecInit(s2_raw_req.map(_.addr)))
  chisel3.dontTouch(slowdown_opt1_s2_addr)
  val slowdown_opt1_s2_set = chisel3.WireInit(VecInit(s2_raw_req.map(_.addr(idxMSB, idxLSB))))
  chisel3.dontTouch(slowdown_opt1_s2_set)
  val slowdown_opt1_s2_tag = chisel3.WireInit(VecInit(s2_raw_req.map(_.addr >> untagBits)))
  chisel3.dontTouch(slowdown_opt1_s2_tag)
  val slowdown_opt1_s2_token = chisel3.WireInit(VecInit(s2_raw_req.map(_.request_token)))
  chisel3.dontTouch(slowdown_opt1_s2_token)
  val slowdown_opt1_s2_token_valid = chisel3.WireInit(VecInit(s2_raw_req.map(_.request_token_valid)))
  chisel3.dontTouch(slowdown_opt1_s2_token_valid)
  val slowdown_opt1_s2_rob_idx = chisel3.WireInit(VecInit(s2_raw_req.map(_.uop.rob_idx)))
  chisel3.dontTouch(slowdown_opt1_s2_rob_idx)
  val slowdown_opt1_s2_pc = chisel3.WireInit(VecInit(s2_raw_req.map(_.uop.debug_pc)))
  chisel3.dontTouch(slowdown_opt1_s2_pc)
  val slowdown_opt1_s2_cmd = chisel3.WireInit(VecInit(s2_raw_req.map(_.uop.mem_cmd)))
  chisel3.dontTouch(slowdown_opt1_s2_cmd)
  val slowdown_opt1_s2_uses_ldq = chisel3.WireInit(VecInit(s2_raw_req.map(_.uop.uses_ldq)))
  chisel3.dontTouch(slowdown_opt1_s2_uses_ldq)
  val slowdown_opt1_s2_uses_stq = chisel3.WireInit(VecInit(s2_raw_req.map(_.uop.uses_stq)))
  chisel3.dontTouch(slowdown_opt1_s2_uses_stq)
  val slowdown_opt1_s2_is_hella = chisel3.WireInit(VecInit(s2_raw_req.map(_.is_hella)))
  chisel3.dontTouch(slowdown_opt1_s2_is_hella)
  val slowdown_opt1_s2_send_nack = chisel3.WireInit(s2_send_nack)
  chisel3.dontTouch(slowdown_opt1_s2_send_nack)
  val slowdown_opt1_s1_kill = chisel3.WireInit(io.lsu.s1_kill)
  chisel3.dontTouch(slowdown_opt1_s1_kill)
  val slowdown_opt1_exception = chisel3.WireInit(io.lsu.exception)
  chisel3.dontTouch(slowdown_opt1_exception)
  val slowdown_opt1_recovery = chisel3.WireInit(io.lsu.exception ||
    io.lsu.brupdate.b1.mispredict_mask.orR || io.lsu.brupdate.b2.mispredict)
  chisel3.dontTouch(slowdown_opt1_recovery)
  val slowdown_opt1_mshr_req_valid = chisel3.WireInit(VecInit(mshrs.io.req.map(_.valid)))
  chisel3.dontTouch(slowdown_opt1_mshr_req_valid)
  val slowdown_opt1_mshr_req_fire = chisel3.WireInit(VecInit(mshrs.io.req.map(_.fire)))
  chisel3.dontTouch(slowdown_opt1_mshr_req_fire)
  val slowdown_opt1_safe_watermark = chisel3.WireInit(safePacketWatermark)
  chisel3.dontTouch(slowdown_opt1_safe_watermark)
  val slowdown_opt1_safe_advance = chisel3.WireInit(safeAdvance)
  chisel3.dontTouch(slowdown_opt1_safe_advance)
  val slowdown_opt1_new_safe_watermark = chisel3.WireInit(newSafePacketWatermark)
  chisel3.dontTouch(slowdown_opt1_new_safe_watermark)
  val slowdown_opt1_checker_result = chisel3.WireInit(io.checker_results)
  chisel3.dontTouch(slowdown_opt1_checker_result)
  val slowdown_opt1_result_accepted = chisel3.WireInit(resultAccepted)
  chisel3.dontTouch(slowdown_opt1_result_accepted)
  val slowdown_opt1_result_stale = chisel3.WireInit(resultStale)
  chisel3.dontTouch(slowdown_opt1_result_stale)
  val slowdown_opt1_result_failed = chisel3.WireInit(resultFailed)
  chisel3.dontTouch(slowdown_opt1_result_failed)
  val slowdown_opt1_result_cancelled = chisel3.WireInit(resultCancelled)
  chisel3.dontTouch(slowdown_opt1_result_cancelled)
  val slowdown_opt1_pending_live_key = chisel3.WireInit(imageKey(crossPackagePendingSet)(crossPackagePendingWay))
  chisel3.dontTouch(slowdown_opt1_pending_live_key)
  val slowdown_opt1_pending_safe = chisel3.WireInit(L1Preservation.safe(
    imageKey(crossPackagePendingSet)(crossPackagePendingWay), safePacketWatermark))
  chisel3.dontTouch(slowdown_opt1_pending_safe)
  val slowdown_opt1_prefix_seq = chisel3.WireInit(safePacketWatermark + 1.U)
  chisel3.dontTouch(slowdown_opt1_prefix_seq)
  val slowdown_opt1_prefix_allocated = chisel3.WireInit(allocatedNext((safePacketWatermark + 1.U)(statsIndexBits - 1, 0)))
  chisel3.dontTouch(slowdown_opt1_prefix_allocated)
  val slowdown_opt1_prefix_slot_seq = chisel3.WireInit(seqNext((safePacketWatermark + 1.U)(statsIndexBits - 1, 0)))
  chisel3.dontTouch(slowdown_opt1_prefix_slot_seq)
  val slowdown_opt1_prefix_completed = chisel3.WireInit(completedNext((safePacketWatermark + 1.U)(statsIndexBits - 1, 0)))
  chisel3.dontTouch(slowdown_opt1_prefix_completed)
  val slowdown_opt1_prefix_passed = chisel3.WireInit(passedNext((safePacketWatermark + 1.U)(statsIndexBits - 1, 0)))
  chisel3.dontTouch(slowdown_opt1_prefix_passed)
  val slowdown_opt1_packet_alloc_valid = chisel3.WireInit(functionalPacketAlloc)
  chisel3.dontTouch(slowdown_opt1_packet_alloc_valid)
  val slowdown_opt1_packet_alloc_seq = chisel3.WireInit(io.packet_alloc_seq)
  chisel3.dontTouch(slowdown_opt1_packet_alloc_seq)
  val slowdown_opt1_result_held_duplicate = chisel3.WireInit(resultHeldDuplicate)
  chisel3.dontTouch(slowdown_opt1_result_held_duplicate)
  // OPTIMIZATION_1_TRACE_END
  // SAFE_CHAIN_OBSERVATION_BEGIN — input-only simulation sinks. No protocol
  // predicate below drives cache, LSU, watermark, ACK, barrier or recovery.
  // Hardware statistics STOP precedes software ROI STOP/session completion.
  // Keep sparse observation enabled through that tail; the parser clips to
  // the unchanged software [start, stop) marker rather than guessing its end.
  val safeChainCapture = RegInit(false.B)
  when (io.traffic_reset) { safeChainCapture := false.B }
    .elsewhen (io.traffic_start) { safeChainCapture := true.B }
  val safeChainRoi = safeChainCapture || io.traffic_start
  BoringUtils.addSource(io.csr_cycle, SafeChainObservation.CycleTap)
  BoringUtils.addSource(safeChainRoi, SafeChainObservation.RoiTap)
  def safeChainLog(kind: Int, fields: Seq[UInt], key: UInt,
                   sample: Bool = true.B, force: Bool = false.B,
                   hart: UInt = 0.U): Unit =
    SafeChainObservation.emit(kind, clock, reset.asBool, io.csr_cycle,
      io.csr_cycle, hart, safeChainRoi, sample, fields, key, force)

  // OPT2B_OBSERVATION_ONLY: semantic writes and first preservation blocks.
  // Payload is identity/metadata only, never cacheline bytes. These events
  // cannot reveal younger stores that the existing serializing path never issues.
  val opt2bWriteSet = s3_req.addr(idxMSB, idxLSB)
  val opt2bWriteWay = OHToUInt(s3_way)
  val opt2bWriteKey = imageKey(opt2bWriteSet)(opt2bWriteWay)
  val opt2bWriteFire = dataWriteArb.io.in(0).fire
  // Counts cover every ROI event; address-bearing examples are sampled once
  // per 4096 events. A long WaitSafe episode must not become a cycle trace.
  val opt2bBlock = crossPackageDomainWait && !crossPackagePending
  val opt4WriteCount = RegInit(0.U(64.W))
  val opt4BlockCycles = RegInit(0.U(64.W))
  val opt4BlockEpisodes = RegInit(0.U(64.W))
  val opt4BlockPrevious = RegNext(opt2bBlock && trafficCounting, false.B)
  when (io.traffic_reset) {
    opt4WriteCount := 0.U
    opt4BlockCycles := 0.U
    opt4BlockEpisodes := 0.U
  }.elsewhen (trafficCounting) {
    when (opt2bWriteFire) { opt4WriteCount := opt4WriteCount + 1.U }
    when (opt2bBlock) { opt4BlockCycles := opt4BlockCycles + 1.U }
    when (opt2bBlock && !opt4BlockPrevious) { opt4BlockEpisodes := opt4BlockEpisodes + 1.U }
  }
  safeChainLog(14, Seq(opt2bWriteFire.asUInt, s3_req.packet_seq,
    (s3_req.addr >> blockOffBits) << blockOffBits,
    opt2bWriteKey.contentSeq, opt2bWriteKey.generation, opt2bWriteKey.writer,
    opt2bWriteKey.valid.asUInt, safePacketWatermark, s3_req.slot_epoch,
    s3_req.request_token, imageSerial, s3_req.uop.mem_cmd,
    lowerPreserved(opt2bWriteSet)(opt2bWriteWay).asUInt, s3_replay.asUInt),
    0.U, trafficCounting && opt2bWriteFire && opt4WriteCount(11, 0) === 0.U, true.B)
  safeChainLog(15, Seq(opt2bBlock.asUInt, s2_req(0).packet_seq,
    (s2_req(0).addr >> blockOffBits) << blockOffBits,
    s2_overwrittenKey.contentSeq, s2_overwrittenKey.generation,
    s2_overwrittenKey.writer, s2_overwrittenKey.valid.asUInt, safePacketWatermark,
    s2_lookup_epoch(0), s2_req(0).request_token,
    lowerPreserved(s2_store_set)(s2_store_way).asUInt, (s2_type === t_replay).asUInt),
    0.U, trafficCounting && opt2bBlock && opt4BlockCycles(11, 0) === 0.U, true.B)
  safeChainLog(31, Seq(1.U, opt4WriteCount, opt4BlockCycles, opt4BlockEpisodes, 4096.U),
    0.U, trafficStopPulse, true.B)
  val safeChainHole = newSafePacketWatermark + 1.U
  val safeChainHoleIdx = safeChainHole(statsIndexBits - 1, 0)
  val safeChainFirst = safePacketWatermark + 1.U
  val safeChainFirstIdx = safeChainFirst(statsIndexBits - 1, 0)
  val safeChainHoleFlags = VecInit(Seq(allocatedNext(safeChainHoleIdx),
    completedNext(safeChainHoleIdx), passedNext(safeChainHoleIdx))).asUInt
  val safeChainFirstFlags = VecInit(Seq(allocatedNext(safeChainFirstIdx),
    completedNext(safeChainFirstIdx), passedNext(safeChainFirstIdx))).asUInt
  val safeChainPassedBehind = PopCount((0 until statsWindow).map(i =>
    allocatedNext(i) && completedNext(i) && passedNext(i) && seqNext(i) > safeChainHole))
  val safeChainPrefixFields = Seq(safePacketWatermark, newSafePacketWatermark,
    safeChainHole, seqNext(safeChainHoleIdx), safeChainHoleFlags,
    safeChainFirst, seqNext(safeChainFirstIdx), safeChainFirstFlags,
    safeChainPassedBehind, PopCount(allocatedNext))
  safeChainLog(1, safeChainPrefixFields, Cat(safeChainPrefixFields))
  safeChainLog(2, Seq(io.packet_alloc_seq, allocationCollision.asUInt),
    io.packet_alloc_seq, functionalPacketAlloc, true.B)
  for (i <- io.checker_results.indices) {
    val result = io.checker_results(i)
    val valid = result(GH_GlobalParams.GH_CHECKER_RESULT_BITS - 1)
    val seq = result(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, 0)
    val idx = seq(statsIndexBits - 1, 0)
    val flags = VecInit(Seq(valid, resultAccepted(i), resultStale(i),
      resultHeldDuplicate(i), resultFailed(i), resultCancelled(i))).asUInt
    safeChainLog(3, Seq(result, flags, bitmapSeq(idx),
      VecInit(Seq(bitmapAllocated(idx), bitmapCompleted(idx), bitmapPassed(idx))).asUInt),
      Cat(Mux(valid, result, 0.U), flags), hart = (i + GH_GlobalParams.GH_NUM_BIG_CORES).U)
  }
  // Small ROI-entry checkpoint, not a per-cycle table dump. Exact tags for
  // both the earliest hole and the pending target are logged independently.
  val safeChainRoiPrevious = RegNext(safeChainRoi, false.B)
  for (chunk <- 0 until 32) {
    val indices = (chunk * 8 until chunk * 8 + 8)
    val fields = Seq(chunk.U, safePacketWatermark,
      VecInit(indices.map(bitmapAllocated(_))).asUInt,
      VecInit(indices.map(bitmapCompleted(_))).asUInt,
      VecInit(indices.map(bitmapPassed(_))).asUInt) ++ indices.map(bitmapSeq(_))
    safeChainLog(9, fields, chunk.U, !safeChainRoiPrevious, true.B, hart = chunk.U)
  }
  val safeChainPreviousPending = RegNext(crossPackagePending, false.B)
  val safeChainEntryCounter = RegInit(0.U(64.W))
  val safeChainNewEntry = crossPackagePending && !safeChainPreviousPending
  val safeChainEntry = Mux(safeChainNewEntry, safeChainEntryCounter + 1.U, safeChainEntryCounter)
  when (safeChainNewEntry) { safeChainEntryCounter := safeChainEntryCounter + 1.U }
  val safeChainLiveKey = imageKey(crossPackagePendingSet)(crossPackagePendingWay)
  val safeChainTargetIdx = safeChainLiveKey.contentSeq(statsIndexBits - 1, 0)
  // LSB-first, fixed bit definitions are recorded in event_schema.json.
  val safeChainReleaseBits = VecInit(Seq(crossPackagePending,
    L1Preservation.safe(safeChainLiveKey, safePacketWatermark), crossPackageResidentMatch,
    crossPackageIssued, crossPackageMetaClearPending, crossPackageMshrConflict,
    crossPackageSlotConflict, crossPackageMetaClearBlock,
    completionPending(crossPackagePendingSet)(crossPackagePendingWay),
    prober.io.state.valid && prober.io.state.bits(idxMSB, idxLSB) === crossPackagePendingSet,
    crossPackageWbReq.valid, crossPackageWbReq.ready, crossPackageWbReq.fire,
    crossPackageWbDone, lowerPreserved(crossPackagePendingSet)(crossPackagePendingWay),
    crossPackageMetaClear.valid, crossPackageMetaClear.ready, crossPackageMetaClear.fire,
    preservationRevoked, wb.io.idx.valid, wb.io.pending_idx.valid, wb.io.pending_sent,
    wb.io.mem_grant, io.lsu.exception, io.lsu.s1_kill.asUInt.orR)).asUInt
  val safeChainTargetFlags = VecInit(Seq(allocatedNext(safeChainTargetIdx),
    completedNext(safeChainTargetIdx), passedNext(safeChainTargetIdx))).asUInt
  val safeChainPendingFields = Seq(safeChainEntry, safeChainLiveKey.contentSeq,
    crossPackagePendingEpoch, crossPackagePendingSet, crossPackagePendingTag,
    crossPackagePendingWay, safeChainLiveKey.generation, safeChainLiveKey.writer,
    safeChainLiveKey.valid.asUInt, safeChainReleaseBits, seqNext(safeChainTargetIdx),
    safeChainTargetFlags, crossPackagePendingSeq, crossPackagePendingAddr)
  safeChainLog(8, safeChainPendingFields,
    Mux(crossPackagePending, Cat(safeChainPendingFields), 0.U))
  // Protocol v1: version, owner(1=SVB), entry(255=normal), line, pkg,
  // source, opcode, generation, writer, keyValid, epoch, first, last,
  // matched, sourceBusy, size. Full-run handshake events, no cache payload.
  def releaseProtocolLog(kind: Int, event: Bool, owner: Bool, entry: UInt,
      line: UInt, key: CacheImageKey, source: UInt, opcode: UInt,
      epoch: UInt, first: Bool = false.B, last: Bool = false.B,
      matched: Bool = true.B, size: UInt = lgCacheBlockBytes.U): Unit = {
    SafeChainObservation.emit(kind, clock, reset.asBool, io.csr_cycle, io.csr_cycle,
      0.U, true.B, event, Seq(1.U, owner.asUInt, Mux(owner, entry, 255.U),
        line, key.contentSeq, source, opcode, key.generation, key.writer,
        key.valid.asUInt, epoch, first.asUInt, last.asUInt, matched.asUInt,
        releaseSourceBusy.asUInt, size), 0.U, true.B)
  }
  releaseProtocolLog(19, svb.io.selected, true.B, svb.io.activeEntry,
    svb.io.activeLine, svb.io.activeKey, cfg.nMSHRs.U, TLMessages.ReleaseData, svbEpoch)
  releaseProtocolLog(20, releaseFirst || releaseLast, wb.io.pending_svb,
    wb.io.pending_entry, tl_out.c.bits.address, cReleaseKey, tl_out.c.bits.source,
    tl_out.c.bits.opcode, wb.io.done_epoch, c_first, c_last, !sourceConflict, tl_out.c.bits.size)
  releaseProtocolLog(21, wbAck, wb.io.pending_svb, wb.io.pending_entry,
    wb.io.pending_line, wbAckKey, tl_out.d.bits.source, tl_out.d.bits.opcode,
    wb.io.done_epoch, matched = !invalidReleaseAck, size = tl_out.d.bits.size)
  releaseProtocolLog(22, wb.io.svb_done.valid, true.B, wb.io.svb_done.bits.entry,
    wb.io.pending_line, wb.io.svb_done.bits.key, cfg.nMSHRs.U, TLMessages.ReleaseAck, wb.io.done_epoch)
  releaseProtocolLog(23, svbSourceBlocked && !svbSourceBlockedPrevious, true.B,
    svb.io.activeEntry, svb.io.activeLine, svb.io.activeKey, cfg.nMSHRs.U,
    TLMessages.ReleaseData, svbEpoch)
  releaseProtocolLog(24, sourceConflict || invalidReleaseAck, wb.io.pending_svb,
    wb.io.pending_entry, wb.io.pending_line, wb.io.pending_key, cfg.nMSHRs.U,
    Mux(wbAck, tl_out.d.bits.opcode, tl_out.c.bits.opcode), wb.io.done_epoch,
    first = sourceConflict, last = invalidReleaseAck, matched = false.B)
  SafeChainObservation.emit(25, clock, reset.asBool, io.csr_cycle, io.csr_cycle,
    0.U, true.B, trafficStopPulse, Seq(1.U, svbSourceBusyCycles, svbQueuedCycles,
      svbMaxQueued, sourceConflicts, invalidReleaseAcks, releaseIssued,
      releaseMatched, releaseSourceBusy.asUInt, wb.io.pending_svb.asUInt,
      wb.io.pending_entry, wb.io.pending_line, svbCoalesced, svbReleaseIssued,
      svbReleaseMatched, svb.io.occupancy), 0.U, true.B)
  // Emit the level counters once at STOP. The two histograms use separate
  // records because SafeChainObservation reserves 16 words per event.
  val svbObservationFields = Seq(
    svbEligibleCount, svbAllocationCount, svbFullFallbackCount,
    svbUnsupportedFallbackCount,
    svbBypassCount, svbPromotionCount, svbAckCount, svbRecoveryCount,
    svb.io.occupancy, svb.io.maxOccupancy, svb.io.maxDepth,
    svbFastLineValid.asUInt, svbCapturePending.asUInt, svbCaptureIssued.asUInt)
  safeChainLog(16, svbObservationFields, Cat(svbObservationFields), trafficStopPulse, true.B)
  safeChainLog(30, Seq(2.U, nSVBEntries.U, svbWouldFullAt8, svbCyclesAbove8,
    svbCaptureFailures) ++ svb.io.entryAccounting.toSeq,
    0.U, trafficStopPulse, true.B)
  // One event has at most 16 words; 16 entries need 17 histogram bins.
  for ((bins, chunk) <- svb.io.occupancyHistogram.toSeq.grouped(15).zipWithIndex) {
    safeChainLog(17, Seq(chunk.U) ++ bins, 0.U, trafficStopPulse, true.B, hart = chunk.U)
  }
  for ((bins, chunk) <- svb.io.depthHistogram.toSeq.grouped(15).zipWithIndex) {
    safeChainLog(18, Seq(chunk.U) ++ bins, 0.U, trafficStopPulse, true.B, hart = chunk.U)
  }

  // Full-run integrity evidence survives host diagnostic sampling and STOP.
  // Hash words follow increasing physical byte address, independent of bus width.
  val integrityPendingSerial = RegEnable(svb.io.observationSerial, svb.io.promote.fire)
  SafeChainObservation.emit(37, clock, reset.asBool, io.csr_cycle, io.csr_cycle,
    0.U, true.B, releaseBeat && wb.io.pending_svb,
    Seq(2.U, integrityPendingSerial, wb.io.pending_entry,
      tl_out.c.bits.address, cReleaseKey.contentSeq, cReleaseKey.generation,
      cReleaseKey.writer, wb.io.done_epoch,
      CacheOpportunityObservation.rowHash(tl_out.c.bits.data, edge.bundle.dataBits),
      c_beat * ((edge.bundle.dataBits + 63) / 64).U,
      ((edge.bundle.dataBits + 63) / 64).U, (cfg.blockBytes / 8).U), 0.U, true.B)

  // CACHE_OPPORTUNITY_OBSERVATION_ONLY. Values flow only into an input-only
  // DPI sink; no counter, shadow tag, fingerprint, or decision feeds the LSU.
  val cacheObservationEvents = (0 until memWidth).flatMap { w =>
    val r = s2_req(w)
    val set = r.addr(idxMSB, idxLSB)
    val lookupMeta = RegNext(meta(w).io.resp)
    val validWays = PopCount(lookupMeta.map(_.coh.isValid()))
    val demand = s2_valid(w) && s2_type === t_lsu && r.traffic_cacheable &&
      !IsKilledByBranch(io.lsu.brupdate, r.uop) && !(io.lsu.exception && r.uop.uses_ldq)
    val flags = VecInit(Seq(isRead(r.uop.mem_cmd), isWrite(r.uop.mem_cmd),
      s2_tag_match(w), !s2_tag_match(w), s2_tag_match(w) && !s2_hit(w))).asUInt
    val replacement = mshrs.io.req(w).fire && r.admission === CacheAdmission.primary &&
      s2_lookup(w).old_meta.coh.isValid()
    Seq(CacheOpportunityObservation.event(demand, 1, flags,
        (r.addr >> blockOffBits) << blockOffBits, r.request_token, 0.U,
        set, OHToUInt(s2_lookup(w).way_en), validWays),
      CacheOpportunityObservation.event(replacement, 2,
        VecInit(Seq(s2_lookup(w).old_meta.coh.onCacheControl(M_FLUSH)._1,
          validWays === nWays.U)).asUInt, set = set, way = OHToUInt(s2_lookup(w).way_en)))
  } ++ Seq(
    CacheOpportunityObservation.event(metaWriteArb.io.out.fire, 5,
      VecInit(Seq(metaWriteArb.io.out.bits.data.coh.isValid(),
        metaWriteArb.io.out.bits.data.coh.onCacheControl(M_FLUSH)._1)).asUInt,
      (Cat(metaWriteArb.io.out.bits.data.tag, metaWriteArb.io.out.bits.idx) << blockOffBits).pad(64),
      set = metaWriteArb.io.out.bits.idx, way = OHToUInt(metaWriteArb.io.out.bits.way_en)),
    CacheOpportunityObservation.event(prober.io.meta_write.fire &&
      !prober.io.meta_write.bits.data.coh.isValid(), 3,
      address = prober.io.state.bits),
    CacheOpportunityObservation.event(svbFullFallbackEvent || svbUnsupportedFallbackEvent, 4,
      VecInit(Seq(svbFullFallbackEvent, svbUnsupportedFallbackEvent)).asUInt),
    CacheOpportunityObservation.event(l1_l2_dirty_wb_event, 8),
    CacheOpportunityObservation.event(trafficStopPulse, 30, nSVBEntries.U,
      svb.io.entryAccounting(2), svb.io.entryAccounting(0), svb.io.entryAccounting(1),
      svb.io.entryAccounting(3)(31, 0), svb.io.occupancy, svb.io.maxDepth),
    CacheOpportunityObservation.event(trafficStopPulse, 31, address = svbWouldFullAt8,
      tag = svbCyclesAbove8, value = svbCaptureFailures, set = svb.io.maxOccupancy),
    CacheOpportunityObservation.event(trafficCounting && !trafficStopPulse, 32, nSVBEntries.U,
      way = svb.io.occupancy, occupancy = svb.io.depth))
  CacheOpportunityObservation.emit(1, nSets, nWays, cfg.blockBytes, cfg.nMSHRs,
    clock, reset.asBool, io.traffic_reset, trafficCounting && !trafficStopPulse, trafficStopPulse,
    outer.staticImageWriter.U, io.csr_cycle, PopCount(mshrs.io.owner_line_valid),
    PopCount(mshrs.io.owner_line_valid) === cfg.nMSHRs.U, cacheObservationEvents)
  // These software control bits are held levels, not one-cycle commands.
  // Observe only their rising edges: forcing a row while RESET/START stays
  // high logs every cycle (including boot) and exhausts the observer budget.
  // These registers feed only the logger; functional statistics are unchanged.
  val safeChainResetPrevious = RegNext(io.traffic_reset, false.B)
  val safeChainStartPrevious = RegNext(io.traffic_start, false.B)
  val safeChainResetPulse = io.traffic_reset && !safeChainResetPrevious
  val safeChainStartPulse = io.traffic_start && !safeChainStartPrevious
  val safeChainBoundaryPulse = safeChainResetPulse || safeChainStartPulse || trafficStopPulse
  SafeChainObservation.emit(10, clock, reset.asBool, io.csr_cycle, io.csr_cycle,
    0.U, true.B, safeChainBoundaryPulse,
    Seq(safeChainResetPulse.asUInt, safeChainStartPulse.asUInt, trafficStopPulse.asUInt),
    0.U, true.B)
  // SAFE_CHAIN_OBSERVATION_END
  io.lsu.ordered := mshrs.io.fence_rdy && !s1_valid.reduce(_||_) && !s2_valid.reduce(_||_) &&
    !s3_valid && completionQ.io.count === 0.U && replayResultQ.map(_.io.count === 0.U).reduce(_ && _) &&
    !wb.io.idx.valid && !wb.io.pending_idx.valid && !crossPackagePending
}
