/*
 * Copyright 2019 SiFive, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You should have received a copy of LICENSE.Apache2 along with
 * this software. If not, you may obtain a copy at
 *
 *    https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package sifive.blocks.inclusivecache

import Chisel._
import freechips.rocketchip.tilelink._

class SinkDResponse(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val last   = Bool()
  val opcode = UInt(width = 3)
  val param  = UInt(width = 3)
  val source = UInt(width = params.outer.bundle.sourceBits)
  val sink   = UInt(width = params.outer.bundle.sinkBits)
  val denied = Bool()
  val txn = UInt(width = 64)
  val historyImage = new CacheImageKey
}

class SinkD(params: InclusiveCacheParameters) extends Module
{
  val io = new Bundle {
    val resp = Valid(new SinkDResponse(params)) // Grant or ReleaseAck
    val d = Decoupled(new TLBundleD(params.outer.bundle)).flip
    // Lookup the set+way from MSHRs
    val source = UInt(width = params.outer.bundle.sourceBits)
    val way    = UInt(width = params.wayBits).flip
    val set    = UInt(width = params.setBits).flip
    // Banked Store port
    val bs_adr = Decoupled(new BankedStoreOuterAddress(params))
    val bs_dat = new BankedStoreOuterPoison(params)
    // WaR hazard
    val grant_req = new SourceDHazard(params)
    val grant_safe = Bool().flip
    val newFill = Bool()
    val fillDone = Bool()
    val historyReady = Bool().flip
    val history = Valid(new PalimpsestHistoryLine).flip
  }

  // No restrictions on buffer
  val d = params.micro.outerBuf.d(io.d)

  val (first, last, _, beat) = params.outer.count(d)
  val hasData = params.outer.hasData(d.bits)
  io.newFill := d.valid && first && d.bits.opcode === TLMessages.GrantData && !d.bits.denied
  io.fillDone := d.fire() && last && d.bits.opcode === TLMessages.GrantData
  val allowFirst = io.grant_safe && io.historyReady

  io.source := Mux(d.valid, d.bits.source, RegEnable(d.bits.source, d.valid))
  io.grant_req.way := io.way
  io.grant_req.set := io.set

  // Also send Grant(NoData) to BS to ensure correct data ordering
  io.resp.valid := (first || last) && d.fire()
  d.ready := io.bs_adr.ready && (!first || allowFirst)
  io.bs_adr.valid := !first || (d.valid && allowFirst)
  params.ccover(d.valid && first && !io.grant_safe, "SINKD_HAZARD", "Prevented Grant data hazard with backpressure")
  params.ccover(io.bs_adr.valid && !io.bs_adr.ready, "SINKD_SRAM_STALL", "Data SRAM busy")

  io.resp.bits.last   := last
  io.resp.bits.opcode := d.bits.opcode
  io.resp.bits.param  := d.bits.param
  io.resp.bits.source := d.bits.source
  io.resp.bits.sink   := d.bits.sink
  io.resp.bits.denied := d.bits.denied
  io.resp.bits.txn := d.bits.echo.lift(CachePreserveTxn).getOrElse(UInt(0, width = 64))
  io.resp.bits.historyImage := Mux(io.history.valid,
    io.history.bits.key, 0.U.asTypeOf(new CacheImageKey))

  io.bs_adr.bits.noop := !d.valid || !hasData
  io.bs_adr.bits.way  := io.way
  io.bs_adr.bits.set  := io.set
  io.bs_adr.bits.beat := Mux(d.valid, beat, RegEnable(beat + io.bs_adr.ready.asUInt, d.valid))
  io.bs_adr.bits.mask := ~UInt(0, width = params.outerMaskBits)
  val historyBeats = io.history.bits.data.asTypeOf(Vec(
    params.cache.blockBytes / params.outer.manager.beatBytes, UInt(width = params.outer.bundle.dataBits)))
  io.bs_dat.data      := Mux(io.history.valid, historyBeats(beat), d.bits.data)

  assert (!(d.valid && d.bits.corrupt && !d.bits.denied), "Data poisoning unsupported")
}
