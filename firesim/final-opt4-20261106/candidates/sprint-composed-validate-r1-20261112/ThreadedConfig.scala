package ecsprint
import org.chipsalliance.cde.config.Config

class ThreadedAlveoConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)
