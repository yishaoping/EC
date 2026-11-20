package firesim.firesim
import freechips.rocketchip.config.Config
// Preserve target frequency/cache/core parameters; no WithTestChipBusFreqs/1GHz override.
class DacOpt4C4 extends Config(
  new chipyard.example.WithDacRoi ++
  new WithDacMeasurementPolicy ++
  new WithDefaultFireSimBridges ++
  new WithFireSimDesignTweaks ++
  new chipyard.v1Config)
