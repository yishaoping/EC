package firesim.bridges

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import midas.widgets._

class DacRoiBridgeIO extends Bundle {
  val clock = Input(Clock())
  val underReset = Input(Bool())
  // Fixed order: epoch, state, tick, begin, end, faults. Source BOOM cycles.
  val values = Input(Vec(6, UInt(64.W)))
}
class DacRoiBridge extends BlackBox with Bridge[HostPortIO[DacRoiBridgeIO], DacRoiBridgeModule] {
  val io = IO(new DacRoiBridgeIO)
  val bridgeIO = HostPort(io)
  val constructorArg = None
  generateAnnotations()
}
/** Observer backpressure only pauses FireSim tokens in host time. No ready,
  * valid, interrupt or other output is driven into the target machine.
  */
class DacRoiBridgeModule(implicit p: Parameters) extends BridgeModule[HostPortIO[DacRoiBridgeIO]] {
  lazy val module = new BridgeModuleImp(this) {
    val io = IO(new WidgetIO)
    val hPort = IO(HostPort(new DacRoiBridgeIO))
    val initialized = WireInit(false.B)
    val snapshotRequest = WireInit(false.B)
    val pendingSnapshot = RegInit(false.B)
    val seen = RegInit(false.B)
    val previous = RegInit(VecInit(Seq.fill(3)(0.U(64.W))))
    val sequence = RegInit(0.U(64.W))
    val overflow = RegInit(false.B)
    val resetWord = Mux(hPort.hBits.underReset, 1.U(64.W), 0.U(64.W))
    val changed = !seen || previous(0) =/= hPort.hBits.values(0) ||
      previous(1) =/= hPort.hBits.values(1) || previous(2) =/= resetWord
    val capture = changed || pendingSnapshot
    val queue = Module(new Queue(Vec(9, UInt(64.W)), 16))
    val canAccept = initialized && (!capture || queue.io.enq.ready)
    val fire = hPort.toHost.hValid && hPort.fromHost.hReady && canAccept
    hPort.toHost.hReady := hPort.fromHost.hReady && canAccept
    hPort.fromHost.hValid := true.B
    queue.io.enq.valid := fire && capture
    queue.io.enq.bits := VecInit(Seq(sequence, resetWord, Mux(changed, 1.U(64.W), 0.U(64.W))) ++ hPort.hBits.values)
    when(snapshotRequest) { pendingSnapshot := true.B }
    when(fire) {
      seen := true.B
      previous := VecInit(Seq(hPort.hBits.values(0), hPort.hBits.values(1), resetWord))
      when(capture) {
        sequence := sequence + 1.U
        when(sequence.andR) { overflow := true.B }
        when(!snapshotRequest) { pendingSnapshot := false.B }
      }
    }
    genWORegInit(initialized, "initialized", false.B)
    Pulsify(genWORegInit(snapshotRequest, "snapshot_request", false.B), 1)
    attach(queue.io.deq.valid, "available", ReadOnly)
    attach(overflow, "overflow", ReadOnly)
    queue.io.deq.bits.zipWithIndex.foreach { case (value, i) =>
      attach(value(31, 0), s"value_${i}_lo", ReadOnly)
      attach(value(63, 32), s"value_${i}_hi", ReadOnly)
    }
    Pulsify(genWORegInit(queue.io.deq.ready, "pop", false.B), 1)
    override def genHeader(base: BigInt, memoryRegions: Map[String, BigInt], sb: StringBuilder): Unit = {
      genConstructor(base, sb, "ec_dac_roi_t", "ec_dac_roi")
    }
    genCRFile()
  }
}
