package midas.passes

import firrtl._
import firrtl.annotations._
import firrtl.options.{Dependency, TargetDirAnnotation}
import firrtl.stage.Forms
import firrtl.stage.transforms.Compiler
import midas.stage._
import midas.stage.phases._
import java.nio.file.{Files, Paths}
import java.nio.charset.StandardCharsets.UTF_8

/** Resume only an authenticated host checkpoint; use the existing compiler passes. */
object FrozenMTContinue {
  def read(p: String): String = new String(Files.readAllBytes(Paths.get(p)), UTF_8)
  def write(p: String, text: String): Unit = {
    require(!Files.exists(Paths.get(p)), "Preserve previous output")
    Files.write(Paths.get(p), text.getBytes(UTF_8))
  }
  def main(args: Array[String]): Unit = {
    require(args.length == 3)
    val out = args(2)
    val saved = JsonProtocol.deserialize(read(args(1)))
    require(saved.count(_.isInstanceOf[fame.FAMEChannelConnectionAnnotation]) == 1747)
    require(saved.count(_.isInstanceOf[midas.targetutils.FirrtlEnableModelMultiThreadingAnnotation]) == 5)
    val options: AnnotationSeq = Seq(
      ConfigPackageAnnotation("firesim.configs"),
      ConfigStringAnnotation("MTModels_MCRams_DacXilinxAlveoConfig"),
      TargetDirAnnotation(out), OutputBaseFilenameAnnotation("FireSim-generated"),
      firrtl.transforms.BlackBoxTargetDirAnno(out))
    val configured = new CreateParametersInstancePhase().transform(options)
    val annotations = AddDerivedAnnotations.transform(configured) ++ saved
    var state = CircuitState(Parser.parse(read(args(0))), HighForm, annotations)
    val originalCircuit = state.circuit
    require(originalCircuit.main == "FAMETop")
    state = fame.AddRemainingFanoutAnnotations.runTransform(state)
    state = new ResolveAndCheck().runTransform(state)
    val beforeMT = state.circuit
    val oldDefs = beforeMT.modules.map(m => m.name -> m).toMap
    val beforeTop = oldDefs(beforeMT.main).asInstanceOf[firrtl.ir.Module]
    val instances = scala.collection.mutable.ArrayBuffer.empty[WDefInstance]
    def gather(s: firrtl.ir.Statement): Unit = {
      s match { case i: WDefInstance => instances += i; case _ => }
      s.foreachStmt(gather)
    }
    gather(beforeTop.body)
    val tileClasses = state.annotations.collect {
      case midas.targetutils.FirrtlEnableModelMultiThreadingAnnotation(t) => t.ofModule
    }.toSet
    require(tileClasses.size == 5)
    require(tileClasses.forall(m => instances.count(_.module == m) == 1))
    state = fame.MultiThreadFAME5Models.runTransform(state)
    // The original pass adds unused one-thread module definitions even when
    // all five classes are singletons. Prove existing definitions unchanged
    // and only transparent Block/EmptyStmt wrapping on the actual top.
    def flatten(s: firrtl.ir.Statement): Seq[firrtl.ir.Statement] = s match {
      case firrtl.ir.Block(stmts) => stmts.flatMap(flatten)
      case firrtl.ir.EmptyStmt => Seq.empty
      case other => Seq(other)
    }
    val afterDefs = state.circuit.modules.map(m => m.name -> m).toMap
    oldDefs.foreach { case (name, old) =>
      require(afterDefs.contains(name), "Original module removed")
      if (name == beforeMT.main) {
        val afterTop = afterDefs(name).asInstanceOf[firrtl.ir.Module]
        require(old.asInstanceOf[firrtl.ir.Module].copy(body=afterTop.body) == afterTop)
        require(flatten(beforeTop.body) == flatten(afterTop.body), "Existing top statement changed")
      } else require(afterDefs(name) == old, "Original module changed during singleton MT")
    }
    val added = afterDefs.keySet -- oldDefs.keySet
    require(added.forall(n => n.contains("threaded")), "Unexpected new MT module class")
    write(out + "/mt-singleton-inventory.txt", tileClasses.toSeq.sorted.map(m => m + " instances=1").mkString("\n") +
      "\nadded_unused_definitions=" + added.size + "\nexisting_top_statements_and_module_definitions_identical=true\n")
    println("EXACT_SINGLETON_MT_EXISTING_MODULES_AND_TOP_STATEMENTS_IDENTICAL_PASS")
    state = new ResolveAndCheck().runTransform(state)
    state = new firrtl.passes.InlineInstances().runTransform(state)
    state = firrtl.passes.ResolveKinds.runTransform(state)
    state = new fame.EmitAndWrapRAMModels().runTransform(state)
    write(out + "/post-gen-sram-models.fir", state.circuit.serialize)
    write(out + "/post-gen-sram-models.json", JsonProtocol.serialize(state.annotations))
    println("ORIGINAL_EMIT_AND_WRAP_RAM_MODELS_PASS")
    state = new ResolveAndCheck().runTransform(state)
    state = new SimulationMapping("FireSim").runTransform(state)
    state = xilinx.HostSpecialization.runTransform(state)
    state = new ResolveAndCheck().runTransform(state)
    write(out + "/host-mapped.fir", state.circuit.serialize)
    write(out + "/host-mapped.json", JsonProtocol.serialize(state.annotations))
    println("ORIGINAL_SIMULATION_MAPPING_AND_HOST_SPECIALIZATION_PASS")
    // Preserve the original GoldenGateCompilerPhase ordering and its actual
    // backend input. Do not silently change compiler behavior in this recovery.
    val simulator = new Compiler(Forms.LowForm, Forms.HighForm).execute(state)
    val p = annotations.collectFirst { case ConfigParametersAnnotation(x) => x }.get
    val hostLowering = new Compiler(
      Seq(Dependency(AutoILATransform), Dependency(HostClockWiring)) ++ Forms.LowForm ++ p(midas.HostTransforms),
      Forms.LowForm)
    hostLowering.execute(simulator)
    val backend = new Compiler(Seq(
      Dependency[firrtl.passes.memlib.SeparateWriteClocks],
      Dependency[firrtl.passes.memlib.SetDefaultReadUnderWrite],
      Dependency[firrtl.transforms.SimplifyMems]) ++ Forms.LowForm, Forms.LowForm)
    val lowered = backend.execute(simulator)
    val emitter = new Compiler(Seq(Dependency(WriteXDCFile), Dependency[firrtl.SystemVerilogEmitter]), Forms.LowForm)
    val emitted = emitter.execute(lowered)
    var rtlCount = 0
    emitted.annotations.foreach {
      case EmittedVerilogCircuitAnnotation(v) =>
        write(out + "/FireSim-generated.sv", v.value); rtlCount += 1
      case GoldenGateOutputFileAnnotation(body, suffix) =>
        require(suffix.nonEmpty && !suffix.contains("/") && !suffix.contains(".."))
        write(out + "/FireSim-generated" + suffix, body)
      case XDCOutputAnnotation(body, suffix) =>
        val extension = suffix.get
        require(extension.nonEmpty && !extension.contains("/") && !extension.contains(".."))
        write(out + "/FireSim-generated" + extension, body)
      case _ =>
    }
    require(rtlCount == 1)
    write(out + "/final-annotations.json", JsonProtocol.serialize(emitted.annotations))
    println("FROZEN_MT_MCRAMS_HOST_RTL_EMITTED_RUNTIME_PARITY_REQUIRED")
  }
}
