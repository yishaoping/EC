package opt4barrierports143

import org.chipsalliance.cde.config.{Config, Parameters}

// Elaborate the unchanged private candidate at its actual 256-slot size.
class Harness(implicit p: Parameters)
  extends firesim.midasexamples.PeekPokeMidasExampleHarness(
    () => new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256))

class MCConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
