package chipyard

import org.chipsalliance.cde.config.Config
import freechips.rocketchip.r.PalimpsestFaultSeq

/** P5-11: one BOOM + existing four Rocket checkers, same geometry as v1Config.
  * The owning checker flips its f0 comparison snapshot once for Seq8. The
  * normal mismatch accumulator/result CDC must deliver FAIL; no PASS is masked.
  * This configuration is only for the user's explicit fault-injection run.
  */
class PalimpsestFault8Config extends Config(
  new Config((site, here, up) => { case PalimpsestFaultSeq => BigInt(8) }) ++
  new v1Config)

/** Replay the protected CLINT read in Seq40 of the compact-trap-io workload. */
class PalimpsestFault40TestConfig extends Config(
  new Config((site, here, up) => { case PalimpsestFaultSeq => BigInt(40) }) ++
  new v1Config)

/** Replay the first protected CLINT write in compact-mmio-output. */
class PalimpsestFault18TestConfig extends Config(
  new Config((site, here, up) => { case PalimpsestFaultSeq => BigInt(18) }) ++
  new v1Config)

/** A second real comparator mismatch after the first recovery has restarted. */
class PalimpsestTwoFaultTestConfig extends Config(
  new Config((site, here, up) => {
    case PalimpsestFaultSeq => BigInt(8)
    case freechips.rocketchip.r.PalimpsestAdditionalFaultSeqs => Seq(BigInt(24))
  }) ++ new v1Config)

/** Deferral of planned rebasing while Seq40 owns an unresolved device effect. */
class PalimpsestFault40Seq41TestConfig extends Config(
  new Config((site, here, up) => {
    case freechips.rocketchip.tilelink.PalimpsestSeqRebaseThreshold => BigInt(41)
    // The compact-trap-io input's first Seq40 is owned by hart1. Keep the
    // existing once bit only on that checker: after a physical Seq reset,
    // another checker seeing numerical Seq40 must not inject a new fault.
    case PalimpsestFaultSeq =>
      if (site(freechips.rocketchip.tile.TileKey).hartId == 1) BigInt(40) else BigInt(0)
  }) ++ new v1Config)

/** Exercise the production quiesce protocol before a long-running workload. */
class PalimpsestSeqRebaseTestConfig extends Config(
  new Config((site, here, up) => {
    case freechips.rocketchip.tilelink.PalimpsestSeqRebaseThreshold => BigInt(16)
  }) ++ new v1Config)
