package freechips.rocketchip.tilelink

import chisel3._
import freechips.rocketchip.util._

/** The block address is carried by the transaction/directory tag. A key names
  * bytes, not permissions or a validation state. BASE (valid=false) is the
  * coherent lower-level image; every local semantic write gets a fresh serial.
  * writer namespaces local serials; contentSeq=0 denotes a trusted, safe write.
  * Ordinary lineage-unaware clients may only receive validated/safe bytes.
  */
class CacheImageKey extends Bundle {
  val valid = Bool()
  val writer = UInt(16.W)
  val generation = UInt(32.W)
  val contentSeq = UInt(32.W)
}

/** Explicit endpoint contract, preserved through diplomatic nodePath. Port-wide
  * user-field negotiation is insufficient after an Xbar unions mixed clients.
  * Only endpoints that store and return CacheImage may implement this marker.
  */
trait CacheImageClient

case object CacheImage extends ControlKey[CacheImageKey]("cache_image") {
  // HintAck/AccessAck do not expose resident bytes or permissions. AMOs
  // return the pre-write value even when the final directory image is BASE.
  def exposesResident(opcode: UInt): Bool =
    opcode === TLMessages.Get || opcode === TLMessages.AcquireBlock ||
    opcode === TLMessages.AcquirePerm || opcode === TLMessages.ArithmeticData ||
    opcode === TLMessages.LogicalData
  def safe(key: CacheImageKey, watermark: UInt): Bool =
    !key.valid || key.contentSeq === 0.U || key.contentSeq <= watermark
  def samePackageIdentity(key: CacheImageKey, writer: UInt, seq: UInt): Bool =
    key.valid && key.writer === writer && seq =/= 0.U && key.contentSeq === seq
  def sameSpeculativePackage(a: CacheImageKey, b: CacheImageKey): Bool =
    a.valid && samePackageIdentity(b, a.writer, a.contentSeq)
  def samePackageSupersede(incoming: CacheImageKey, resident: CacheImageKey, watermark: UInt): Bool =
    sameSpeculativePackage(incoming, resident) && incoming.generation > resident.generation &&
      !safe(resident, watermark)
  // TLEdge constructors leave optional user fields for the caller to fill.
  def base(a: TLBundleA): TLBundleA = {
    a.user.lift(this).foreach(_ := 0.U.asTypeOf(new CacheImageKey))
    a
  }
  def base(c: TLBundleC): TLBundleC = {
    c.user.lift(this).foreach(_ := 0.U.asTypeOf(new CacheImageKey))
    c
  }
}

/** Echoed end-to-end, including across CacheCork and TLToAXI4/UserYanker.
  * A source ID alone is reusable and cannot authenticate a delayed completion.
  * The serial names one immutable snapshot; serial exhaustion is fail-stop.
  */
case object CachePreserveTxn extends ControlKey[UInt]("cache_preserve_txn")
case class CachePreserveTxnField() extends BundleField(CachePreserveTxn) {
  def data = Output(UInt(64.W))
  def default(x: UInt): Unit = { x := 0.U }
}
case class CacheImageField() extends BundleField(CacheImage) {
  def data = Output(new CacheImageKey)
  def default(x: CacheImageKey): Unit = { x := 0.U.asTypeOf(new CacheImageKey) }
}
