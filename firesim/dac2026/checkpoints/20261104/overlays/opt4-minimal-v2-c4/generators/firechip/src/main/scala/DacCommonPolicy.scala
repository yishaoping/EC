package firesim.firesim
import freechips.rocketchip.config.Config
import freechips.rocketchip.subsystem._
import boom.common.BoomTileAttachParams

// Both systems use Opt4's normal BOOM counter count and the same debug policy.
class WithDacMeasurementPolicy extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => up(TilesLocated(InSubsystem), site).map {
    case b: BoomTileAttachParams => b.copy(tileParams = b.tileParams.copy(
      core = b.tileParams.core.copy(nPerfCounters = 29,
        enableCommitLogPrintf = false, enableBranchPrintf = false, enableMemtracePrintf = false)))
    case other => other
  }
})
