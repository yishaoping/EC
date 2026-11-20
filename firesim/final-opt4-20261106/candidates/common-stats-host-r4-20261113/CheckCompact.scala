package firrtl.transforms
import firrtl._
import firrtl.annotations._
import firrtl.graph._
import scala.util.Random

object CheckCompact extends App {
  def state(text: String, annos: Seq[Annotation] = Seq.empty): CircuitState =
    CircuitState(Parser.parse(text), LowForm, annos)
  def paths(state: CircuitState): Set[(String, Set[String])] =
    state.annotations.collect { case CombinationalPath(s, from) =>
      s.serialize -> from.map(_.serialize).toSet
    }.toSet
  def graph(g: collection.Map[String, DiGraph[LogicNode]]) = g.map { case (m, d) =>
    m -> d.getVertices.map(n => n -> d.getEdges(n).toSet).toMap
  }.toMap
  var passed=0; var rejected=0
  def check(s: CircuitState, loop: Boolean = false): Unit = {
    val reference = new ECReferenceCheckCombLoops
    val compact = new CheckCombLoops
    def run(t: () => CircuitState): Either[String, CircuitState] = try { Right(t()) }
      catch { case scala.util.control.NonFatal(e) => Left(e.getClass.getName + ": " + e.getMessage) }
    val a=run(() => reference.execute(s)); val b=run(() => compact.execute(s))
    assert(a.isLeft == b.isLeft, (a,b))
    assert(a.isLeft == loop, ("unexpected loop result", loop,a,b))
    if (loop) {
      // Stock1.5.5 can throw PathNotFound while expanding a validly
      // detected hierarchical loop. Both implementations must still reject.
      val recognized = Seq("Combinational loop detected", "firrtl.graph.PathNotFoundException")
      assert(recognized.exists(a.left.get.contains), a)
      assert(recognized.exists(b.left.get.contains), b)
      assert(!b.left.get.contains("ec_port_summary"), b)
      rejected+=1
    } else {
      assert(a.toOption.get.circuit.serialize==s.circuit.serialize)
      assert(b.toOption.get.circuit.serialize==s.circuit.serialize)
      assert(paths(a.toOption.get)==paths(b.toOption.get))
      assert(graph(reference.analyzeFull(s))==graph(compact.analyzeFull(s)))
      val ac=reference.analyze(s).map {case(m,g)=>m->g.getEdgeMap.map{case(n,e)=>n->e.toSet}.toMap}.toMap
      val bc=compact.analyze(s).map {case(m,g)=>m->g.getEdgeMap.map{case(n,e)=>n->e.toSet}.toMap}.toMap
      assert(ac==bc)
      passed+=1
    }
  }
  for(seed <- 0 until 256) {
    val random=new Random(seed)
    val inputs=(0 until 8).map(i=>"i"+i)
    val body=new StringBuilder
    for(i <- 0 until 48) {
      val prior=inputs++(0 until i).map(j=>"n"+j)
      val a=prior(random.nextInt(prior.size)); val b=prior(random.nextInt(prior.size))
      body.append(s"    node n$i = xor($a, $b)\n")
    }
    val leaf="""circuit Top :
  module Leaf :
"""+inputs.map(i=>s"    input $i : UInt<1>\n").mkString+
      (0 until 16).map(i=>s"    output o$i : UInt<1>\n").mkString+body.toString+
      (0 until 16).map(i=>s"    o$i <= n${random.nextInt(48)}\n").mkString
    val top="  module Top :\n    input in : UInt<1>\n    output out : UInt<1>\n"+
      (0 until 4).map(i=>s"    inst c$i of Leaf\n"+inputs.map(p=>s"    c$i.$p <= in\n").mkString).mkString+
      "    out <= xor(c0.o0, xor(c1.o1, xor(c2.o2, c3.o3)))\n"
    check(state(leaf+top))
  }
  val direct="""circuit Top :
  module Leaf :
    input i : UInt<1>
    output o : UInt<1>
    o <= i
  module Top :
    output o : UInt<1>
    inst c of Leaf
    c.i <= c.o
    o <= c.o
"""
  check(state(direct),true)
  val local="""circuit Top :
  module Top :
    output out : UInt<1>
    wire w : UInt<1>
    w <= w
    out <= w
"""
  check(state(local),true)
  val register="""circuit Top :
  module Leaf :
    input clock : Clock
    input i : UInt<1>
    output o : UInt<1>
    reg r : UInt<1>, clock
    r <= i
    o <= r
  module Top :
    input clock : Clock
    output out : UInt<1>
    inst c of Leaf
    c.clock <= clock
    c.i <= c.o
    out <= c.o
"""
  check(state(register))
  val external="""circuit Top :
  extmodule Leaf :
    input i : UInt<1>
    output o : UInt<1>
    defname = Leaf
  module Top :
    output out : UInt<1>
    inst c of Leaf
    c.i <= c.o
    out <= c.o
"""
  val mt=ModuleTarget("Top","Leaf")
  check(state(external))
  check(state(external,Seq(ExtModulePathAnnotation(mt.ref("i"), mt.ref("o")))),true)
  val memory="""circuit Top :
  module Top :
    input clock : Clock
    output out : UInt<1>
    mem m :
      data-type => UInt<1>
      depth => 2
      read-latency => 0
      write-latency => 1
      reader => r
      read-under-write => undefined
    m.r.clk <= clock
    m.r.en <= UInt<1>(1)
    m.r.addr <= m.r.data
    out <= m.r.data
"""
  check(state(memory),true)
  check(state(memory.replace("read-latency => 0","read-latency => 1")))
  // Exercise >64-port factoring and many distinct masks, including bit63.
  val dense="circuit Top :\n  module Leaf :\n"+
    (0 until 130).map(i=>s"    input i$i : UInt<1>\n").mkString+
    (0 until 80).map(i=>s"    output o$i : UInt<1>\n").mkString+
    (0 until 80).map {i=>
      val terms=(0 until 130).filter(j=>(i+j)%5!=0).map(j=>s"i$j")
      s"    o$i <= "+terms.reduce((a,b)=>s"xor($a, $b)")+"\n"
    }.mkString+
    "  module Top :\n    input in : UInt<1>\n    output out : UInt<1>\n    inst c of Leaf\n"+
    (0 until 130).map(i=>s"    c.i$i <= in\n").mkString+"    out <= c.o0\n"
  check(state(dense))
  // Negative test creates a hierarchical combinational cycle through a dense row.
  check(state(dense.replace("c.i63 <= in","c.i63 <= c.o0")),true)
  println(s"EC_COMPACT_CHECKER_REGRESSION_PASS passed=$passed rejected=$rejected stock_paths_fullgraphs_and_circuit_identity=true")
}
