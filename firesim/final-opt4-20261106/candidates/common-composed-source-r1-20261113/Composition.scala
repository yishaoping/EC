package eccommoncomposition

import java.io.File
import org.chipsalliance.cde.config.Config

class ThreadedAlveoConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)

/** Linkage only: no Chisel module is constructed and no RTL is emitted. */
object CheckComposition extends App {
  val directory = new File(args(0)).getCanonicalFile
  val constructors = Seq(
    "boom.lsu.PackageAddressStats" -> 8,
    "freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats" -> 2,
    "ecstatscommon.StatsBank" -> 1)
  val classes = constructors.map(_._1) ++ Seq(
    "boom.lsu.BoomNonBlockingDCacheModule",
    "boom.lsu.AppliedEffectResultMemory",
    "freechips.rocketchip.inclusivecache.InclusiveCache",
    "ecstatscommon.BankTagRead$",
    "ecstatscommon.AddressBucketGrouped$",
    "ecstatscommon.AddressBucketUpdate$")
  for (name <- classes) {
    val cls = Class.forName(name, false, getClass.getClassLoader)
    val source = new File(cls.getProtectionDomain.getCodeSource.getLocation.toURI).getCanonicalFile
    require(source == directory, s"Wrong class origin: $name from $source")
    println(s"COMPOSED_CLASS_ORIGIN $name $source")
  }
  for ((name, count) <- constructors) {
    val cls = Class.forName(name, false, getClass.getClassLoader)
    val parameters = Seq.fill(count)(java.lang.Integer.TYPE)
    require(cls.getConstructor(parameters: _*).getParameterCount == count)
  }
  println("COMMON_COMPOSITION_LINKAGE_PASS classes=9 constructors=3 no_elaboration=true")
}
