package nestedmodeltest
import firrtl._
import firrtl.annotations._
import firrtl.annotations.transforms.{EliminateTargetPaths, ResolvePaths}
import midas.targetutils.{FirrtlFAMEModelAnnotation, FirrtlEnableModelMultiThreadingAnnotation}
object Probe extends App {
  val circuit = Parser.parse("""circuit Top :
  module Bank :
    input in : UInt<8>
    output out : UInt<8>
    out <= in
  module Parent :
    input in : UInt<8>
    output out : UInt<8>
    inst bank of Bank
    bank.in <= in
    out <= bank.out
  module Top :
    input in : UInt<8>
    output out : UInt<8>
    inst yes of Parent
    inst no of Parent
    yes.in <= in
    no.in <= in
    out <= xor(yes.out, no.out)
""")
  val it = CircuitTarget("Top").module("Top").instOf("yes", "Parent").instOf("bank", "Bank")
  val s = CircuitState(circuit, HighForm, Seq(FirrtlFAMEModelAnnotation(it), FirrtlEnableModelMultiThreadingAnnotation(it), ResolvePaths(Seq(it.targetParent))))
  val out = (new EliminateTargetPaths).runTransform(s)
  println(out.circuit.serialize)
  println(out.annotations.mkString("\n"))
}
