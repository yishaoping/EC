package nestedmodeltest

import firrtl._
import firrtl.ir._
import firrtl.annotations._
import midas.targetutils.{FirrtlFAMEModelAnnotation, FirrtlEnableModelMultiThreadingAnnotation}
import midas.passes.fame.{ExtractModel, StockExtractModel}
import java.nio.file.{Files, Paths}
import scala.collection.mutable

object Regression extends App {
  val out = Paths.get(args(0))
  def write(name: String, text: String): Unit = Files.write(out.resolve(name), text.getBytes("UTF-8"))
  def checked(s: CircuitState): CircuitState = (new ResolveAndCheck).runTransform(s)
  def insts(s: Statement): Seq[WDefInstance] = s match {
    case i: WDefInstance => Seq(i)
    case b: Block => b.stmts.flatMap(insts)
    case other =>
      val xs = mutable.ArrayBuffer[WDefInstance]()
      other.foreachStmt(x => xs ++= insts(x)); xs.toSeq
  }
  def modelAnns(ts: Seq[InstanceTarget]): Seq[Annotation] = ts.flatMap(t =>
    Seq(FirrtlFAMEModelAnnotation(t), FirrtlEnableModelMultiThreadingAnnotation(t)))
  def bankLeaves(s: CircuitState): Seq[Seq[String]] = {
    val ms = s.circuit.modules.map(m => m.name -> m).toMap
    def walk(mod: String, path: Seq[String]): Seq[Seq[String]] = ms(mod) match {
      case m: Module => insts(m.body).flatMap(i =>
        if (i.module == "Bank") Seq(path :+ i.name) else walk(i.module, path :+ i.name))
      case _ => Nil
    }
    walk(s.circuit.main, Nil)
  }
  def fixture(parents: Int, banks: Int, depth: Int): CircuitState = {
    val bank = """  module Bank :
    input clock : Clock
    input reset : UInt<1>
    input in : UInt<8>
    output out : UInt<8>
    reg count : UInt<8>, clock with :
      reset => (reset, UInt<8>(0))
    count <= add(count, in)
    out <= xor(count, in)
"""
    val widths = mutable.Map("Bank" -> 8)
    def container(name: String, child: String, n: Int): String = {
      widths(name) = n * widths(child)
      val h = s"  module $name :\n    input clock : Clock\n    input reset : UInt<1>\n    input in : UInt<8>\n    output out : UInt<${widths(name)}>\n"
      val body = (0 until n).map(i => s"    inst b$i of $child\n    b$i.clock <= clock\n    b$i.reset <= reset\n    b$i.in <= add(in, UInt<8>($i))\n").mkString
      val sum = (0 until n).map(i => s"b$i.out").reduce((a,b) => s"cat($a, $b)")
      h + body + s"    out <= $sum\n"
    }
    val layers = (0 until depth).map(i => container(s"Level$i", if (i==0) "Bank" else s"Level${i-1}", if (i==0) banks else 2)).mkString
    checked(CircuitState(Parser.parse("circuit FAMETop :\n" + bank + layers + container("Top", s"Level${depth-1}", parents) + container("FAMETop", "Top", 1)), HighForm))
  }
  var cases = 0
  var failedStock = 0
  var widenedNegative = 0
  for (depth <- 1 to 3; parents <- Seq(1,2,4); banks <- Seq(1,2,4,16)) {
    val base = fixture(parents,banks,depth)
    for (selected <- Seq(Seq(0), (0 until parents).toSeq).distinct) {
      val ts = selected.flatMap { p => (0 until banks).map { b =>
        var root: IsModule = CircuitTarget("FAMETop").module("Top").instOf(s"b$p",s"Level${depth-1}")
        for (d <- (depth-2) to 0 by -1) root = root.instOf("b0",s"Level$d")
        root.instOf(s"b$b","Bank")
      }}
      val state = base.copy(annotations=modelAnns(ts))
      try { (new StockExtractModel).runTransform(state); sys.error("Stock unexpectedly accepts nonlocal model") }
      catch { case e: AssertionError if e.getMessage.contains("must be local") => failedStock += 1 }
      val result = checked((new ExtractModel).runTransform(state))
      assert(!result.annotations.exists(_.isInstanceOf[FirrtlFAMEModelAnnotation]))
      val selectedOut = result.annotations.collect {case FirrtlEnableModelMultiThreadingAnnotation(it) => it}
      assert(selectedOut.size == ts.size, (selectedOut,ts))
      assert(selectedOut.forall(t => t.isLocal && t.module == "FAMETop" && t.ofModule == "Bank"))
      val before = bankLeaves(state)
      val after = bankLeaves(result)
      assert(before.size==after.size, (before,after))
      assert(after.count(_.size==1)==ts.size, (after,ts))
      assert(state.circuit.modules.find(_.name=="FAMETop").get.ports==result.circuit.modules.find(_.name=="FAMETop").get.ports)
      assert(result.circuit.modules.filter(_.name=="Bank")==state.circuit.modules.filter(_.name=="Bank"))
      // Emit one partial-selection, repeated-parent sequential equivalence case.
      if (depth==2 && parents==4 && banks==16 && selected.size==1) {
        write("reference.fir", state.circuit.serialize)
        write("candidate.fir", result.circuit.serialize)
      }
      if (selected.size==1 && parents>1) {
        val widened = checked((new StockExtractModel).runTransform(
          base.copy(annotations=modelAnns(ts.map(_.pathlessTarget)))))
        assert(bankLeaves(widened).count(_.size==1)>ts.size,
          "Path-stripping mutation must be rejected for selecting sibling banks")
        widenedNegative += 1
      }
      cases += 1
    }
  }
  // Existing local annotations retain exactly the stock behavior.
  val local = fixture(2,4,1)
  val lt = CircuitTarget("FAMETop").module("Level0").instOf("b0","Bank")
  val ls = local.copy(annotations=modelAnns(Seq(lt)))
  val reference = (new StockExtractModel).runTransform(ls)
  val candidate = (new ExtractModel).runTransform(ls)
  assert(reference.circuit.serialize==candidate.circuit.serialize)
  assert(JsonProtocol.serialize(reference.annotations)==JsonProtocol.serialize(candidate.annotations))
  val empty = local.copy(annotations=Nil)
  assert((new ExtractModel).runTransform(empty).circuit==empty.circuit)
  write("regression-summary.json",s"""{"PASS":true,"nested_cases":$cases,"stock_failures_reproduced":$failedStock,"path_stripping_negatives_rejected":$widenedNegative,"local_stock_equal":true,"empty_identity":true,"partial_selection_preserved":true,"target_registers_unchanged":true}
""")
  println(s"NESTED_MODEL_EXTRACTION_REGRESSION_PASS cases=$cases stock_rejections=$failedStock")
}

object EmitVerilog extends App {
  val stage = new firrtl.stage.FirrtlStage
  stage.execute(Array("-i",args(0),"-o",args(1),"-X","verilog","-td",args(2)),Seq.empty)
}

object Production extends App {
  val dir = Paths.get(args(0))
  val source = Paths.get(args(1))
  val circuit = Parser.parse(scala.io.Source.fromFile(source.toFile).mkString)
  val json = scala.io.Source.fromFile(args(2)).mkString
  val selected = JsonProtocol.deserialize(json).collect {
    case FirrtlEnableModelMultiThreadingAnnotation(it) => it.copy(circuit="FAMETop")
  }
  assert(selected.size==16)
  val annotations = selected.flatMap(t => Seq(FirrtlFAMEModelAnnotation(t),FirrtlEnableModelMultiThreadingAnnotation(t)))
  val rawState = CircuitState(circuit,HighForm,annotations)
  val state = (new ResolveAndCheck).runTransform(rawState)
  val result = (new ResolveAndCheck).runTransform((new ExtractModel).runTransform(state))
  val found = result.annotations.collect {case FirrtlEnableModelMultiThreadingAnnotation(t) => t}
  assert(found.size==16 && found.forall(t => t.module=="FAMETop" && t.isLocal && t.ofModule=="BucketBank"))
  val bankBefore = state.circuit.modules.filter(_.name=="BucketBank")
  val rawBank = circuit.modules.filter(_.name=="BucketBank")
  assert(bankBefore==result.circuit.modules.filter(_.name=="BucketBank"))
  assert(state.circuit.modules.find(_.name=="FAMETop").get.ports==result.circuit.modules.find(_.name=="FAMETop").get.ports)
  assert(rawBank.map(_.serialize)==bankBefore.map(_.serialize), "Reference resolution must not change bank hardware text")
  assert(rawBank!=bankBefore, "Retain the diagnosed parser metadata mismatch evidence")
  Files.write(dir.resolve("production-extracted.fir"),result.circuit.serialize.getBytes("UTF-8"))
  Files.write(dir.resolve("production-extracted.anno.json"),JsonProtocol.serialize(result.annotations).getBytes("UTF-8"))
  Files.write(dir.resolve("production-summary.json"),s"""{"PASS":true,"actual_completed_production_artifact":true,"selected_banks":16,"original_bank_body_equal":true,"same_reference_resolution_both_sides":true,"raw_vs_resolved_serialized_bank_equal":true,"raw_IR_metadata_differs":true,"top_ports_equal":true,"host_tokens_validated":false,"whole_EC_equivalence":false,"FIT":false}
""".getBytes("UTF-8"))
  println("ACTUAL_PRODUCTION_NESTED_MODEL_EXTRACTION_PASS selected=16 bank_body_equal=true top_ports_equal=true")
}
