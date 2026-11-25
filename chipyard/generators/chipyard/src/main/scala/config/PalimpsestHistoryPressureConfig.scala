package chipyard
import org.chipsalliance.cde.config.Config
/** Normal asynchronous frequency configuration; no artificial owner/ACK. */
class Palimpsest12p5MHzHistoryPressureConfig extends Config(
 new chipyard.config.WithTileFrequency(12.5,Some(1)) ++
 new chipyard.config.WithTileFrequency(12.5,Some(2)) ++
 new chipyard.config.WithTileFrequency(12.5,Some(3)) ++
 new chipyard.config.WithTileFrequency(12.5,Some(4)) ++
 new v1Config)
