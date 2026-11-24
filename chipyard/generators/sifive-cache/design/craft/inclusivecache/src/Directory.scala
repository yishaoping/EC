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
import freechips.rocketchip.config._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import MetaData._
import freechips.rocketchip.util.DescribedSRAM
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

class DirectoryEntry(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val dirty   = Bool() // true => TRUNK or TIP
  // Sticky while the resident line has been accessed by a DCache. This lets
  // L2 eviction accounting exclude ICache-only lines after all L1 sharers have
  // released the block.
  val dcache  = Bool()
  val state   = UInt(width = params.stateBits)
  val clients = UInt(width = params.clientBits)
  val tag     = UInt(width = params.tagBits)
  val packetSeq = UInt(width = GH_GlobalParams.GH_PACKET_SEQ_BITS)
  val packetTracked = Bool()
  // Resident key, or the acknowledged baseline key while baselineObsolete.
  val image = new freechips.rocketchip.tilelink.CacheImageKey
  // Receipt for this exact key. A newer byte update revokes it.
  val outerPreserved = Bool()
  // P3-10: a newer safe history image has reached DRAM. These bytes may
  // retain coherence obligations, but must never satisfy a new A request.
  val baselineObsolete = Bool()
}

class DirectoryWrite(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val set  = UInt(width = params.setBits)
  val way  = UInt(width = params.wayBits)
  val data = new DirectoryEntry(params)
}

class DirectoryRead(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val set = UInt(width = params.setBits)
  val tag = UInt(width = params.tagBits)
  val checkerFetch = Bool() // P4-12: replay text/translation-read allocation escape
  val maintenance = Bool()
  val maintenanceWay = UInt(width = params.wayBits)
}

class DirectoryResult(params: InclusiveCacheParameters) extends DirectoryEntry(params)
{
  val hit = Bool()
  val way = UInt(width = params.wayBits)
}

class Directory(params: InclusiveCacheParameters) extends Module
{
  val io = new Bundle {
    val write  = Decoupled(new DirectoryWrite(params)).flip
    val read   = Valid(new DirectoryRead(params)).flip // sees same-cycle write
    val result = Valid(new DirectoryResult(params))
    val ready  = Bool() // reset complete; can enable access
    val observationValidWays = UInt(width = log2Ceil(params.cache.ways + 1))
  }

  val codeBits = new DirectoryEntry(params).getWidth

  val cc_dir =  DescribedSRAM(
    name = "cc_dir",
    desc = "Directory RAM",
    size = params.cache.sets,
    data = Vec(params.cache.ways, UInt(width = codeBits))
  )

  val write = Queue(io.write, 1) // must inspect contents => max size 1
  // a flow Q creates a WaR hazard... this MIGHT not cause a problem
  // a pipe Q causes combinational loop through the scheduler

  // Wiping the Directory with 0s on reset has ultimate priority
  val wipeCount = RegInit(UInt(0, width = params.setBits + 1))
  val wipeOff = RegNext(Bool(false), Bool(true)) // don't wipe tags during reset
  val wipeDone = wipeCount(params.setBits)
  val wipeSet = wipeCount(params.setBits - 1,0)

  io.ready := wipeDone
  when (!wipeDone && !wipeOff) { wipeCount := wipeCount + UInt(1) }
  assert (wipeDone || !io.read.valid)

  // Be explicit for dumb 1-port inference
  val ren = io.read.valid
  val wen = (!wipeDone && !wipeOff) || write.valid
  assert (!io.read.valid || wipeDone)

  require (codeBits <= 256)

  write.ready := !io.read.valid
  when (!ren && wen) {
    cc_dir.write(
      Mux(wipeDone, write.bits.set, wipeSet),
      Vec.fill(params.cache.ways) { Mux(wipeDone, write.bits.data.asUInt, UInt(0)) },
      UIntToOH(write.bits.way, params.cache.ways).asBools.map(_ || !wipeDone))
  }

  val ren1 = RegInit(Bool(false))
  val ren2 = if (params.micro.dirReg) RegInit(Bool(false)) else ren1
  ren2 := ren1
  ren1 := ren

  val bypass_valid = params.dirReg(write.valid)
  val bypass = params.dirReg(write.bits, ren1 && write.valid)
  val regout = params.dirReg(cc_dir.read(io.read.bits.set, ren), ren1)
  val tag = params.dirReg(RegEnable(io.read.bits.tag, ren), ren1)
  val set = params.dirReg(RegEnable(io.read.bits.set, ren), ren1)

  // Compute the victim way in case of an evicition
  val victimLFSR = LFSR16(params.dirReg(ren))(InclusiveCacheParameters.lfsrBits-1, 0)
  val victimSums = Seq.tabulate(params.cache.ways) { i => UInt((1 << InclusiveCacheParameters.lfsrBits)*i / params.cache.ways) }
  val victimLTE  = Cat(victimSums.map { _ <= victimLFSR }.reverse)
  val victimSimp = Cat(UInt(0, width=1), victimLTE(params.cache.ways-1, 1), UInt(1, width=1))
  val rawVictimWayOH = victimSimp(params.cache.ways-1,0) & ~(victimSimp >> 1)
  // P4-12/U-D09: reuse one physical way for non-image-aware read/permission
  // misses. Replay text and coherent page-table reads must progress even if
  // all data history is occupied. Main D misses cannot allocate this way.
  // Hits still search every way and all coherence obligations are unchanged.
  val checkerFetch = params.dirReg(RegEnable(io.read.bits.checkerFetch, ren), ren1)
  val escape = params.p(PalimpsestCheckerEscapeWay)
  require(!escape || params.cache.ways > 1, "checker escape way requires at least two ways")
  val victimWayOH = if (escape) {
    val ordinary = rawVictimWayOH & UInt((BigInt(1) << (params.cache.ways - 1)) - 1,
      width = params.cache.ways)
    Mux(checkerFetch, UInt(BigInt(1) << (params.cache.ways - 1), width = params.cache.ways),
      Mux(ordinary.orR, ordinary, UInt(1, width = params.cache.ways)))
  } else rawVictimWayOH
  val victimWay = OHToUInt(victimWayOH)
  assert (!ren2 || victimLTE(0) === UInt(1))
  assert (!ren2 || ((victimSimp >> 1) & ~victimSimp) === UInt(0)) // monotone
  assert (!ren2 || PopCount(victimWayOH) === UInt(1))

  val setQuash = bypass_valid && bypass.set === set
  val tagMatch = bypass.data.tag === tag
  val wayMatch = bypass.way === victimWay

  val ways = Vec(regout.map(d => new DirectoryEntry(params).fromBits(d)))
  // Input to a host counter only; include the same pending-write bypass used
  // by the functional directory lookup. Never participates in replacement.
  io.observationValidWays := PopCount(ways.zipWithIndex.map { case (w, i) =>
    Mux(setQuash && bypass.way === UInt(i), bypass.data.state, w.state) =/= INVALID
  })
  val hits = Cat(ways.zipWithIndex.map { case (w, i) =>
    w.tag === tag && w.state =/= INVALID && (!setQuash || UInt(i) =/= bypass.way)
  }.reverse)
  val hit = hits.orR

  io.result.valid := ren2
  io.result.bits := Mux(hit, Mux1H(hits, ways), Mux(setQuash && (tagMatch || wayMatch), bypass.data, Mux1H(victimWayOH, ways)))
  io.result.bits.hit := hit || (setQuash && tagMatch && bypass.data.state =/= INVALID)
  io.result.bits.way := Mux(hit, OHToUInt(hits), Mux(setQuash && tagMatch, bypass.way, victimWay))
  // U-D07: rare capacity maintenance enumerates physical metadata using the
  // existing directory port. Normal accesses retain the original hit path.
  val maintenance = params.dirReg(RegEnable(io.read.bits.maintenance, ren), ren1)
  val maintenanceWay = params.dirReg(RegEnable(io.read.bits.maintenanceWay, ren), ren1)
  val maintenanceEntry = Mux(setQuash && bypass.way === maintenanceWay, bypass.data, ways(maintenanceWay))
  when (maintenance) {
    for (name <- (new DirectoryEntry(params)).elements.keys) {
      io.result.bits.elements(name) := maintenanceEntry.elements(name)
    }
    io.result.bits.hit := maintenanceEntry.state =/= INVALID
    io.result.bits.way := maintenanceWay
  }

  params.ccover(ren2 && setQuash && tagMatch, "DIRECTORY_HIT_BYPASS", "Bypassing write to a directory hit")
  params.ccover(ren2 && setQuash && !tagMatch && wayMatch, "DIRECTORY_EVICT_BYPASS", "Bypassing a write to a directory eviction")

  def json: String = s"""{"clients":${params.clientBits},"mem":"${cc_dir.pathName}","clean":"${wipeDone.pathName}"}"""
}
