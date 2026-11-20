package chipyard
import freechips.rocketchip.config.Config
class DacBaselineConfig extends Config(
  new chipyard.config.WithTileFrequency(200, Some(0)) ++
  new chipyard.config.WithSystemBusFrequency(200) ++
  new chipyard.config.WithMemoryBusFrequency(200) ++
  new chipyard.config.WithPeripheryBusFrequency(200) ++
  new chipyard.config.WithSystemBusFrequencyAsDefault ++
  new freechips.rocketchip.subsystem.WithInclusiveCache(nWays=16,capacityKB=1024,outerLatencyCycles=12) ++
  new boom.common.WithDacMatchedBoom(1,overrideIdOffset=Some(0)) ++
  new chipyard.config.AbstractConfig)
