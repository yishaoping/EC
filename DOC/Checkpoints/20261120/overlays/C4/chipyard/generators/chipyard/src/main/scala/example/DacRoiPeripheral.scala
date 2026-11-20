package chipyard.example

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import freechips.rocketchip.config.{Config, Parameters}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.regmapper._
import freechips.rocketchip.subsystem.BaseSubsystem
import freechips.rocketchip.tilelink._
import freechips.rocketchip.util._

/** Control/mailbox peripheral, not a checker and not the host measurement bridge.
  * Both queues use RocketChip's real asynchronous crossing implementation.
  * ACK snapshots preserve original BOOM marker times across that crossing.
  */
class DacRoiPeripheral(address: BigInt, beatBytes: Int)(implicit p: Parameters) extends LazyModule {
  require(beatBytes == 8, "ROI ABI requires atomic RV64 MMIO")
  val device = new SimpleDevice("ec-dac-roi", Seq("ec,dac-roi-v1"))
  val node = TLRegisterNode(Seq(AddressSet(address, 4095)), device, beatBytes = beatBytes)
  lazy val module = new LazyModuleImp(this) {
    val coreClock = Wire(Clock()); coreClock := false.B.asClock
    val coreReset = WireInit(true.B)
    BoringUtils.addSink(coreClock, "ec_dac_roi_clock")
    BoringUtils.addSink(coreReset, "ec_dac_roi_reset")
    val requests = Module(new AsyncQueue(new DacRoiRequest, AsyncQueueParams(depth = 4)))
    requests.io.enq_clock := clock; requests.io.enq_reset := reset.asBool
    requests.io.deq_clock := coreClock; requests.io.deq_reset := coreReset
    val responses = Module(new AsyncQueue(new DacRoiReply, AsyncQueueParams(depth = 4)))
    responses.io.enq_clock := coreClock; responses.io.enq_reset := coreReset
    responses.io.deq_clock := clock; responses.io.deq_reset := reset.asBool

    BoringUtils.addSource(requests.io.deq.bits.asUInt, "ec_dac_roi_request_bits")
    BoringUtils.addSource(requests.io.deq.valid, "ec_dac_roi_request_valid")
    val reqReady = WireInit(false.B)
    BoringUtils.addSink(reqReady, "ec_dac_roi_request_ready")
    requests.io.deq.ready := reqReady
    val rspBits = WireInit(0.U((new DacRoiReply).getWidth.W))
    val rspValid = WireInit(false.B)
    BoringUtils.addSink(rspBits, "ec_dac_roi_reply_bits")
    BoringUtils.addSink(rspValid, "ec_dac_roi_reply_valid")
    responses.io.enq.bits := rspBits.asTypeOf(new DacRoiReply)
    responses.io.enq.valid := rspValid
    BoringUtils.addSource(responses.io.enq.ready, "ec_dac_roi_reply_ready")
    responses.io.deq.ready := true.B
    val response = RegInit(0.U.asTypeOf(new DacRoiReply))
    when(responses.io.deq.fire) { response := responses.io.deq.bits }
    val requestEpoch = RegInit(0.U(64.W))
    val requestSatp = RegInit(0.U(64.W))
    val requestHart = RegInit(0.U(64.W))
    val command = RegInit(0.U(64.W))
    requests.io.enq.bits.epoch := requestEpoch
    requests.io.enq.bits.satp := requestSatp
    requests.io.enq.bits.hart := requestHart
    val commandWrite = RegWriteFn((valid: Bool, data: UInt) => {
      requests.io.enq.valid := valid
      requests.io.enq.bits.token := data
      when(valid && requests.io.enq.ready) { command := data }
      requests.io.enq.ready
    })
    // Common + B capabilities only. No correction/execution/context claim.
    val capabilities = ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6) | (1 << 7) |
                        (1 << 8) | (1 << 9) | (1 << 10)).U(64.W)
    node.regmap(
      0x00 -> Seq(RegField.r(64, "h4543444143524f49".U(64.W))),
      0x08 -> Seq(RegField.r(64, 1.U(64.W))),
      0x10 -> Seq(RegField.r(64, capabilities)),
      0x18 -> Seq(RegField.r(64, 4.U(64.W))),
      0x20 -> Seq(RegField(64, RegReadFn(command), commandWrite)),
      0x28 -> Seq(RegField(64, requestEpoch)),
      0x30 -> Seq(RegField(64, requestSatp)),
      0x38 -> Seq(RegField(64, requestHart)),
      0x40 -> Seq(RegField.r(64, response.token)),
      0x48 -> Seq(RegField.r(64, response.error)),
      0x50 -> Seq(RegField.r(64, response.state)),
      0x58 -> Seq(RegField.r(64, response.epoch)),
      0x60 -> Seq(RegField.r(64, response.begin)),
      0x68 -> Seq(RegField.r(64, response.end)),
      0x70 -> Seq(RegField.r(64, response.drain)),
      0x78 -> Seq(RegField.r(64, response.outstanding)),
      0x80 -> Seq(RegField.r(64, response.generated)),
      0x88 -> Seq(RegField.r(64, response.completed)),
      0x90 -> Seq(RegField.r(64, response.faults)))
  }
}
trait CanHavePeripheryDacRoi { this: BaseSubsystem =>
  val dacRoi = if (p(DacRoiEnabled)) {
    val controller = LazyModule(new DacRoiPeripheral(0x10040000L, pbus.beatBytes))
    pbus.toVariableWidthSlave(Some("ec-dac-roi")) { controller.node }
    Some(controller)
  } else None
}
class WithDacRoi extends Config((site, here, up) => {
  case DacRoiEnabled => true
})
