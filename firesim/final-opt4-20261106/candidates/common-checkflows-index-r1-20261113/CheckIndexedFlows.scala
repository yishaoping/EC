package firrtl.passes

import firrtl._
import firrtl.ir._
import scala.util.Try

/** Direct comparison against unmodified FIRRTL1.5.5, including error text. */
object CheckIndexedFlows extends App {
  var checked = 0
  var rejected = 0
  def resolve(text: String): Circuit = {
    val c = Parser.parse(text)
    ResolveFlows.run(InferTypes.run(ResolveKinds.run(c)))
  }
  def outcome(check: => Circuit): Either[(String, String), Circuit] = {
    try { Right(check) }
    catch { case scala.util.control.NonFatal(e) =>
      // Object names intentionally differ; diagnostic payload must not.
      Left((e.getClass.getName.replace("ECReferenceCheckFlows", "CheckFlows"), e.getMessage))
    }
  }
  def compare(c: Circuit, mustReject: Boolean = false): Unit = {
    val a = outcome(ECReferenceCheckFlows.run(c))
    val b = outcome(CheckFlows.run(c))
    assert(a.isLeft == b.isLeft && a.isLeft == mustReject, (a, b, mustReject))
    (a, b) match {
      case (Left(x), Left(y)) => assert(x == y, (x, y)); rejected += 1
      case (Right(x), Right(y)) =>
        assert(x.asInstanceOf[AnyRef] eq c.asInstanceOf[AnyRef])
        assert(y.asInstanceOf[AnyRef] eq c.asInstanceOf[AnyRef])
      case other => sys.error(other.toString)
    }
    checked += 1
  }
  // Nested flipped bundles, vectors, dynamic indexing and repeated field names
  // in distinct BundleType objects. All original checks remain enabled.
  for (seed <- 0 until 96) {
    val n = 2 + seed % 23
    val text = "circuit Top :\n  module Child :\n" +
      "    input clock : Clock\n    input in : UInt<8>\n    output out : UInt<8>\n    out <= in\n" +
      "  module Top :\n    input clock : Clock\n    input i : UInt<8>\n" +
      "    input idx : UInt<2>\n    output o : UInt<8>\n" +
      "    wire nested : {a : {x : UInt<8>, flip y : UInt<8>}, b : UInt<8>[4]}\n" +
      "    nested.a.x <= i\n    nested.a.y <= nested.a.x\n    nested.b[idx] <= i\n" +
      (0 until n).map(j => s"    inst c$j of Child\n    c$j.clock <= clock\n    c$j.in <= i\n").mkString +
      s"    o <= mux(UInt<1>(1), c${seed % n}.out, nested.b[idx])\n"
    val c = resolve(text)
    compare(c)
    compare(resolve(text.replace("    o <= mux", "    i <= mux")), true)
    compare(resolve(text.replace("    c0.in <= i", "    c0.out <= i")), true)
  }
  // Separate run-local caches must never carry a field orientation from an
  // identically named but different bundle into a later invocation.
  for (flip <- Seq("", "flip ")) {
    val text = s"""circuit Top :
  module Top :
    input in : {${flip}x : UInt<1>}
    output out : UInt<1>
    out <= in.x
"""
    compare(resolve(text))
  }
  // Directly exercise the original first-match semantics for duplicate fields
  // and the original exception for an absent field in malformed resolved IR.
  val duplicates = BundleType(Seq(Field("x", Default, UIntType(IntWidth(1))),
    Field("x", Flip, UIntType(IntWidth(1)))))
  def malformed(name: String): Circuit = {
    val ref = WRef("b", duplicates, WireKind, DuplexFlow)
    val select = WSubField(ref, name, UIntType(IntWidth(1)), DuplexFlow)
    val body = Block(Seq(DefWire(NoInfo, "b", duplicates), DefNode(NoInfo, "n", select)))
    Circuit(NoInfo, Seq(Module(NoInfo, "Top", Seq.empty, body)), "Top")
  }
  compare(malformed("x"))
  compare(malformed("absent"), true)
  // Wide hierarchy reproduces the profiled linear scan with no hardware change.
  val width = 8192
  val dense = "circuit Top :\n  module Leaf :\n" +
    (0 until width).map(i => s"    input i$i : UInt<1>\n").mkString +
    "    output out : UInt<1>\n    out <= i0\n  module Top :\n" +
    "    input in : UInt<1>\n    output out : UInt<1>\n    inst c of Leaf\n" +
    (0 until width).map(i => s"    c.i$i <= in\n").mkString + "    out <= c.out\n"
  val wide = resolve(dense)
  val start = System.nanoTime()
  val a = ECReferenceCheckFlows.run(wide)
  val stockMs = (System.nanoTime()-start)/1e6
  val second = System.nanoTime()
  val b = CheckFlows.run(wide)
  val indexedMs = (System.nanoTime()-second)/1e6
  assert(a.asInstanceOf[AnyRef] eq wide.asInstanceOf[AnyRef])
  assert(b.asInstanceOf[AnyRef] eq wide.asInstanceOf[AnyRef])
  compare(wide)
  println(s"EC_INDEXED_FLOWS_REGRESSION_PASS cases=$checked rejected=$rejected exact_diagnostics_and_circuit_identity=true stock_wide_ms=$stockMs indexed_wide_ms=$indexedMs cache_scope_per_run=true")
}
