package boom.lsu

import chisel3._
import org.chipsalliance.cde.config.Parameters
import boom.common._

/** Local protocol only: these tokens are not TileLink image provenance. */
object CacheAdmission {
  val other = 0.U(3.W)
  val primary = 1.U(3.W)
  val upgrade = 2.U(3.W)
  val secondary = 3.U(3.W)
  val mmio = 4.U(3.W)
  val replay = 5.U(3.W)
  val conflict = 6.U(3.W)
  val hit = 7.U(3.W)
}

object CacheTerminal {
  val applied = 0.U(3.W)
  val load = 1.U(3.W)
  val noWriteSC = 2.U(3.W)
  val cancel = 3.U(3.W)
  val retry = 4.U(3.W)
}

class BoomCacheAdmission(implicit p: Parameters) extends BoomBundle {
  val kind = UInt(3.W)
  val mshr_id = UInt(8.W)
  val sdq_id = UInt(8.W)
  val transaction_token = UInt(32.W)
  val way = UInt(dcacheParams.nWays.W)
  val slot_epoch = UInt(16.W)
  val line_generation = UInt(32.W)
  val image_valid = Bool()
  val write_domain_valid = Bool()
  val write_domain_seq = UInt(freechips.rocketchip.guardiancouncil.GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
}

/** Held until its consumer acknowledges it.  RETRY never retires a request. */
class BoomCacheCompletion(implicit p: Parameters) extends BoomBundle {
  val req = new BoomDCacheReq
  val status = UInt(3.W)
  val data = UInt(xLen.W)
}

class BoomCacheInstall(implicit p: Parameters) extends BoomBundle {
  val req = new BoomDCacheReqInternal
  val new_owner = Bool()
  val image = new freechips.rocketchip.tilelink.CacheImageKey
  val has_data = Bool()
}

/** Refill routing belongs to a transaction, as well as to a physical slot. */
class BoomCacheRefill(implicit p: Parameters)
  extends freechips.rocketchip.rocket.L1DataWriteReq {
  // Inherited addr selects an array row; line_addr carries the physical identity.
  val line_addr = UInt(coreMaxAddrBits.W)
  val transaction_token = UInt(32.W)
  val mshr_id = UInt(8.W)
  val owner_context_valid = Bool()
  val image = new freechips.rocketchip.tilelink.CacheImageKey
}

/** The same predicate protects admission, replay grants and physical writes.
  * A received image already exists below; a local semantic write clears that
  * receipt. Validation changes safety only, never identity or preservation.
  */
object L1Preservation {
  def safe(key: freechips.rocketchip.tilelink.CacheImageKey, watermark: UInt): Bool =
    !key.valid || key.contentSeq === 0.U || key.contentSeq <= watermark

  def allow(present: Bool, key: freechips.rocketchip.tilelink.CacheImageKey,
    lowerPreserved: Bool, incomingSeq: UInt, watermark: UInt, incomingWriter: UInt): Bool = {
    val samePackage = freechips.rocketchip.tilelink.CacheImage.samePackageIdentity(key, incomingWriter, incomingSeq)
    !present || samePackage || (safe(key, watermark) && (incomingSeq === 0.U || lowerPreserved))
  }

  def copyAllowed(present: Bool, oldKey: freechips.rocketchip.tilelink.CacheImageKey,
    lowerPreserved: Bool, incoming: freechips.rocketchip.tilelink.CacheImageKey, watermark: UInt): Bool =
    !present || oldKey.asUInt === incoming.asUInt || (safe(oldKey, watermark) && lowerPreserved)
}
