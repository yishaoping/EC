package firesim.firesim

import freechips.rocketchip.config.Config
import freechips.rocketchip.subsystem._
import org.json4s._
import org.json4s.native.JsonMethods._

// Evaluates configuration values only. Does not create or clock a simulator.
object DacParameterAudit {
  def json(value: Any): JValue = value match {
    case null => JNull
    case v: Boolean => JBool(v)
    case v: Int => JInt(v)
    case v: Long => JInt(v)
    case v: BigInt => JInt(v)
    case v: Double => JDouble(v)
    case v: String => JString(v)
    case v: Option[_] => v.map(json).getOrElse(JNull)
    case v: Seq[_] => JArray(v.map(json).toList)
    case v: Product => JObject(v.productElementNames.zip(v.productIterator).map {
      case (name, elem) => name -> json(elem)
    }.toList)
    case v => JString(v.getClass.getName.takeWhile(_ != '/').split("\\$\\$Lambda")(0))
  }
  def main(args: Array[String]): Unit = {
    require(args.length == 2, "config class, output JSON required")
    val p = Class.forName(args(0)).getConstructor().newInstance().asInstanceOf[Config].toInstance
    val result = JObject(List(
      "configuration" -> JString(args(0)),
      "tiles" -> json(p(TilesLocated(InSubsystem)).map(_.tileParams)),
      "inclusive_cache" -> json(p(InclusiveCacheKey)),
      "external_memory" -> json(p(ExtMem)),
      "memory_model" -> json(p(firesim.configs.MemModelKey))))
    val output = new java.io.PrintWriter(args(1))
    try { output.println(pretty(render(result))) } finally { output.close() }
  }
}
