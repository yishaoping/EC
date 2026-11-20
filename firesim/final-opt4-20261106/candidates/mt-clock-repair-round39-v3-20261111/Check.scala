package opt4hostclockrepair

import firrtl._
import firrtl.annotations._
import firrtl.ir._
import firrtl.traversals.Foreachers._
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
    require(changed == 12, s"Unexpected clock metadata delta: $changed")
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
    // Pre-excision proof binds each extracted feedback input to one exact
    // master-clock wire. Preserve that alias to its FAME gated output, never
    // the ungated host clock and never the other target clock domain.
    val provenAliases = Map(
      "lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_auto_clock_sr_out" -> "clockBridge_clocks_1",
      "lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_auto_clock_sr_out" -> "clockBridge_clocks_1",
      "lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_auto_clock_sr_out" -> "clockBridge_clocks_1",
      "lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_auto_clock_sr_out" -> "clockBridge_clocks_1",
      "lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_auto_clock_sr_out" -> "clockBridge_clocks_0",
      "lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_clock_0" -> "clockBridge_clocks_0")
    var repairedModules = 0
    val withAliases = host.copy(circuit = host.circuit.copy(modules = host.circuit.modules.map {
      case m: Module if m.name == "FireSim" =>
        val instances = scala.collection.mutable.ArrayBuffer.empty[WDefInstance]
        val declarations = scala.collection.mutable.Set.empty[String]
        def collect(stmt: Statement): Unit = {
          stmt match {
            case i: WDefInstance => instances += i; declarations += i.name
            case d: DefWire => declarations += d.name
            case d: DefNode => declarations += d.name
            case d: DefRegister => declarations += d.name
            case _ =>
          }
          stmt.foreachStmt(collect)
        }
        collect(m.body)
        require(provenAliases.keys.forall(k => !declarations(k) && !m.ports.exists(_.name == k)))
        val aliases = provenAliases.toSeq.sortBy(_._1).flatMap { case (name, master) =>
          val gates = instances.filter(_.name == master + "_buffer")
          require(gates.size == 1 && gates.head.module.contains("ClockGate"), "Unproved or ambiguous gated master clock")
          val gate = gates.head
          val definition = host.circuit.modules.find(_.name == gate.module).get
          require(definition.ports.exists(p => p.name == "O" && p.direction == Output && p.tpe == ClockType))
          Seq(DefWire(NoInfo, name, ClockType),
              Connect(NoInfo, WRef(name, ClockType, WireKind, SinkFlow),
                      WSubField(WRef(gate.name), "O", ClockType, SourceFlow)))
        }
        require(aliases.size == 12)
        repairedModules += 1
        m.copy(body = Block(Seq(m.body) ++ aliases))
      case m => m
    }))
    require(repairedModules == 1)
    write(args(3) + "/post-fame-before-validation.fir", withAliases.circuit.serialize)
    println("PROVEN_PRE_EXCISION_GATED_CLOCK_ALIASES_RESTORED aliases=6 checker_clock=clockBridge_clocks_1 boom_clock=clockBridge_clocks_0")
    val validated = new ResolveAndCheck().runTransform(withAliases)
    write(args(3) + "/post-fame-transform.fir", validated.circuit.serialize)
    write(args(3) + "/post-fame-transform.json", JsonProtocol.serialize(validated.annotations))
    println("ORIGINAL_FAME_TRANSFORM_AND_RESOLVE_PASS host_checkpoint_only=true full_metasim_parity=false whole_fit=false")
  }
}
