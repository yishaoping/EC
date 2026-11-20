package opt4hostclockrepair

import firrtl._
import firrtl.annotations._
import midas.passes.fame._
import java.nio.file.{Files, Paths}
import java.nio.charset.StandardCharsets.UTF_8

/** Check an isolated host annotation repair with the original compiler passes.
  * This program never changes a target circuit, compiled library, or live input.
  */
object Check {
  def read(path: String): String = new String(Files.readAllBytes(Paths.get(path)), UTF_8)
  def write(path: String, text: String): Unit = {
    require(!Files.exists(Paths.get(path)), "Preserve prior evidence")
    Files.write(Paths.get(path), text.getBytes(UTF_8))
  }
  def rejected(state: CircuitState, path: String): Unit = {
    var refused = false
    try { new InferModelPorts().runTransform(state) }
    catch {
      case e: RuntimeException if Option(e.getMessage).exists(_.contains("partially overlapping ports")) =>
        val trace = new java.io.StringWriter
        e.printStackTrace(new java.io.PrintWriter(trace))
        write(path, trace.toString)
        refused = true
    }
    require(refused, "The original channel-overlap guard must reject this input")
  }
  def main(args: Array[String]): Unit = {
    require(args.length == 4)
    val circuit = Parser.parse(read(args(0)))
    val original = JsonProtocol.deserialize(read(args(1)))
    val repaired = JsonProtocol.deserialize(read(args(2)))
    require(original.size == repaired.size)
    var changed = 0
    original.zip(repaired).foreach {
      case (a: FAMEChannelConnectionAnnotation, b: FAMEChannelConnectionAnnotation) =>
        require(a.copy(clock = b.clock) == b, "Only the clock reference may change")
        if (a.clock != b.clock) changed += 1
      case (a, b) => require(a == b, "Non-channel metadata must be identical")
    }
    require(changed == 8, s"Unexpected clock metadata delta: $changed")
    require(original.count(_.isInstanceOf[FAMEChannelConnectionAnnotation]) == 1747)
    val raw = CircuitState(circuit, LowForm, original)
    val checked = new ResolveAndCheck().runTransform(raw)
    rejected(checked, args(3) + "/original-infer-rejection.txt")
    val corrected = checked.copy(annotations = repaired)
    require(corrected.circuit eq checked.circuit, "Annotation repair must retain the exact circuit object")
    val inferred = new InferModelPorts().runTransform(corrected)
    require(inferred.circuit eq corrected.circuit)
    val ports = inferred.annotations.count(_.isInstanceOf[FAMEChannelPortsAnnotation])
    require(ports > 0)
    write(args(3) + "/post-infer-model-ports.json", JsonProtocol.serialize(inferred.annotations))
    // Restore one conflicting clock: the unchanged original guard must reject it.
    var restored = false
    val mutant = repaired.zip(original).map {
      case (a: FAMEChannelConnectionAnnotation, b: FAMEChannelConnectionAnnotation)
          if !restored && a.clock != b.clock => restored = true; b
      case (a, _) => a
    }
    require(restored)
    rejected(corrected.copy(annotations = mutant), args(3) + "/mutant-infer-rejection.txt")
    println(s"ORIGINAL_INFER_MODEL_PORTS_PASS changed_clock_annotations=$changed channels=1747 model_port_annotations=$ports circuit_object_identical=true restored_clock_mutation_rejected=true")
    val host = new FAMETransform().runTransform(inferred)
    val validated = new ResolveAndCheck().runTransform(host)
    write(args(3) + "/post-fame-transform.fir", validated.circuit.serialize)
    write(args(3) + "/post-fame-transform.json", JsonProtocol.serialize(validated.annotations))
    println("ORIGINAL_FAME_TRANSFORM_AND_RESOLVE_PASS host_checkpoint_only=true full_metasim_parity=false whole_fit=false")
  }
}
