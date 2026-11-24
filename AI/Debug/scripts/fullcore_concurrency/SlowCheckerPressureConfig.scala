package chipyard
import org.chipsalliance.cde.config.Config
/** Normal asynchronous frequency configuration; no artificial owner/ACK. */
class PalimpsestSlowCheckerPressureTestConfig extends Config(
 new chipyard.config.WithTileFrequency(25,Some(1)) ++
 new chipyard.config.WithTileFrequency(25,Some(2)) ++
 new chipyard.config.WithTileFrequency(25,Some(3)) ++
 new chipyard.config.WithTileFrequency(25,Some(4)) ++
 new v1Config)
