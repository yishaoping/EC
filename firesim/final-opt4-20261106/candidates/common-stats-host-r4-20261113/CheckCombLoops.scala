// SPDX-License-Identifier: Apache-2.0

package firrtl.transforms

import scala.collection.mutable
import java.util.BitSet

import firrtl._
import firrtl.ir._
import firrtl.passes.{Errors, PassException}
import firrtl.traversals.Foreachers._
import firrtl.annotations._
import firrtl.Utils.throwInternalError
import firrtl.graph._
import firrtl.analyses.InstanceKeyGraph
import firrtl.options.{Dependency, RegisteredTransform, ShellOption}

/**
  * A case class that represents a net in the circuit. This is necessary since combinational loop
  * checking is an analysis on the netlist of the circuit; the fields are specialized for low FIRRTL.
  * Since all wires are ground types, a given ground type net may only be a subfield of an instance
  * or a memory port. Therefore, it is uniquely specified within its module context by its name, its
  * optional parent instance (a WDefInstance or WDefMemory), and its optional memory port name.
  */
case class LogicNode(name: String, inst: Option[String] = None, memport: Option[String] = None)

object LogicNode {

  /**
    * Construct a LogicNode from a *Low FIRRTL* reference or subfield that refers to a component.
    * Since aggregate types appear in Low FIRRTL only as the full types of instances or memories,
    * the only reference-like expressions that may appear are WRefs, or trees of up to two levels of
    * WSubField field selection.
    *
    * @param e The reference-like expression to describe with a LogicNode
    * @return a LogicNode referring to e
    */
  def apply(e: Expression): LogicNode = e match {
    case r: WRef =>
      LogicNode(r.name)
    case s: WSubField =>
      s.expr match {
        case modref: WRef =>
          LogicNode(s.name, Some(modref.name))
        case memport: WSubField =>
          memport.expr match {
            case memref: WRef =>
              LogicNode(s.name, Some(memref.name), Some(memport.name))
            case _ => throwInternalError(s"LogicNode: unrecognized subsubfield expression - $memport")
          }
        case _ => throwInternalError(s"LogicNode: unrecognized subfield expression - $s")
      }
  }
}

object CheckCombLoops {
  type AbstractConnMap = DiGraph[LogicNode]
  type ConnMap = DiGraph[LogicNode] with EdgeData[LogicNode, Info]
  type MutableConnMap = MutableDiGraph[LogicNode] with MutableEdgeData[LogicNode, Info]

  class CombLoopException(info: Info, mname: String, cycle: Seq[String])
      extends PassException(s"$info: [module $mname] Combinational loop detected:\n" + cycle.mkString("\n"))
}

case object DontCheckCombLoopsAnnotation extends NoTargetAnnotation

case class ExtModulePathAnnotation(source: ReferenceTarget, sink: ReferenceTarget) extends Annotation {
  if (!source.isLocal || !sink.isLocal || source.module != sink.module) {
    throwInternalError(s"ExtModulePathAnnotation must connect two local targets from the same module")
  }

  override def getTargets: Seq[ReferenceTarget] = Seq(source, sink)

  override def update(renames: RenameMap): Seq[Annotation] = {
    val sources = renames.get(source).getOrElse(Seq(source))
    val sinks = renames.get(sink).getOrElse(Seq(sink))
    val paths = sources.flatMap { s => sinks.map((s, _)) }
    paths.collect {
      case (source: ReferenceTarget, sink: ReferenceTarget) => ExtModulePathAnnotation(source, sink)
    }
  }
}

case class CombinationalPath(sink: ReferenceTarget, sources: Seq[ReferenceTarget]) extends Annotation {
  override def update(renames: RenameMap): Seq[Annotation] = {
    val newSources = sources.flatMap { s => renames(s) }.collect { case x: ReferenceTarget if x.isLocal => x }
    val newSinks = renames(sink).collect { case x: ReferenceTarget if x.isLocal => x }
    newSinks.map(snk => CombinationalPath(snk, newSources))
  }
}

/** Finds and detects combinational logic loops in a circuit, if any exist. Returns the input circuit with no
  * modifications.
  *
  * @throws firrtl.transforms.CheckCombLoops.CombLoopException if a loop is found
  * @note Input form: Low FIRRTL
  * @note Output form: Low FIRRTL (identity transform)
  * @note The pass looks for loops through combinational-read memories
  * @note The pass relies on ExtModulePathAnnotations to find loops through ExtModules
  * @note The pass will throw exceptions on "false paths"
  */
object ECCompactPortSummary {
  // Port reachability is represented by packed bits; no semantic pruning.
  final case class Summary(nodes: Vector[LogicNode], rows: Vector[BitSet]) {
    def toGraph: DiGraph[LogicNode] = {
      val graph = new MutableDiGraph[LogicNode]
      nodes.foreach(graph.addVertex)
      rows.indices.foreach { r =>
        var bit = rows(r).nextSetBit(0)
        while (bit >= 0) { graph.addEdge(nodes(r), nodes(bit)); bit = rows(r).nextSetBit(bit + 1) }
      }
      graph
    }
    def named: DiGraph[String] = toGraph.transformNodes(_.name)
  }
  def summarize(graph: DiGraph[LogicNode], ports: Set[LogicNode]): Summary = {
    val nodes = ports.toVector.sortBy(n => (n.name, n.inst.getOrElse(""), n.memport.getOrElse("")))
    val vertices = graph.getVertices.toVector
    val index = vertices.zipWithIndex.toMap
    val adjacency = vertices.map(v => graph.getEdges(v).iterator.map(index).toArray).toArray
    val portIndex = Array.fill(vertices.size)(-1)
    nodes.indices.foreach(p => portIndex(index(nodes(p))) = p)
    val marked = Array.fill(vertices.size)(0)
    val queue = new Array[Int](vertices.size)
    var epoch = 0
    val rows = nodes.indices.map { source =>
      epoch += 1
      val bits = new BitSet(nodes.size)
      val root = index(nodes(source))
      var head = 0; var tail = 1
      queue(0) = root; marked(root) = epoch
      while (head < tail) {
        val next = adjacency(queue(head)); head += 1
        var edge = 0
        while (edge < next.length) {
          val to = next(edge); edge += 1
          if (marked(to) != epoch) {
            marked(to) = epoch; queue(tail) = to; tail += 1
            val p = portIndex(to)
            if (p >= 0 && p != source) bits.set(p)
          }
        }
      }
      bits
    }.toVector
    Summary(nodes, rows)
  }
}

class CheckCombLoops extends Transform with RegisteredTransform with DependencyAPIMigration {

  override def prerequisites = firrtl.stage.Forms.MidForm ++
    Seq(Dependency(passes.LowerTypes), Dependency(firrtl.transforms.RemoveReset))

  override def optionalPrerequisites = Seq.empty

  override def optionalPrerequisiteOf = Seq.empty

  override def invalidates(a: Transform) = false

  import CheckCombLoops._

  val options = Seq(
    new ShellOption[Unit](
      longOption = "no-check-comb-loops",
      toAnnotationSeq = (_: Unit) => Seq(DontCheckCombLoopsAnnotation),
      helpText = "Disable combinational loop checking"
    )
  )

  private def getExprDeps(deps: MutableConnMap, v: LogicNode, info: Info)(e: Expression): Unit = e match {
    case r: WRef      => deps.addEdgeIfValid(v, LogicNode(r), info)
    case s: WSubField => deps.addEdgeIfValid(v, LogicNode(s), info)
    case _ => e.foreach(getExprDeps(deps, v, info))
  }

  // Synthetic analysis nodes subdivide exact edges; they never enter FIRRTL.
  private val summaryNodes = mutable.HashSet.empty[LogicNode]
  private var summarySerial = 0L
  private def installSummary(summary: ECCompactPortSummary.Summary, instance: String,
      deps: MutableConnMap): Unit = {
    val nodes = summary.nodes.map(n => n.copy(inst = Some(instance)))
    nodes.foreach(deps.addVertex)
    val chunks = mutable.HashMap.empty[(Int, Long), LogicNode]
    summary.rows.indices.foreach { row =>
      val words = summary.rows(row).toLongArray
      words.indices.foreach { word =>
        val value = words(word)
        if (value != 0L) {
          val factor = chunks.getOrElseUpdate((word, value), {
            var node = LogicNode("$ec_port_summary_" + summarySerial, None, Some("$ec_analysis"))
            summarySerial += 1
            while (deps.contains(node)) {
              node = LogicNode("$ec_port_summary_" + summarySerial, None, Some("$ec_analysis")); summarySerial += 1
            }
            deps.addVertex(node); summaryNodes += node
            var mask = value
            while (mask != 0L) {
              val bit = java.lang.Long.numberOfTrailingZeros(mask)
              deps.addEdge(node, nodes(word * 64 + bit))
              mask &= mask - 1L
            }
            node
          })
          deps.addEdge(nodes(row), factor)
        }
      }
    }
  }

  private def getStmtDeps(
    simplifiedModules: mutable.Map[String, ECCompactPortSummary.Summary],
    deps:              MutableConnMap
  )(s:                 Statement
  ): Unit = s match {
    case Connect(info, loc, expr) =>
      val lhs = LogicNode(loc)
      if (deps.contains(lhs)) {
        getExprDeps(deps, lhs, info)(expr)
      }
    case w: DefWire =>
      deps.addVertex(LogicNode(w.name))
    case DefNode(info, name, value) =>
      val lhs = LogicNode(name)
      deps.addVertex(lhs)
      getExprDeps(deps, lhs, info)(value)
    case m: DefMemory if (m.readLatency == 0) =>
      for (rp <- m.readers) {
        val dataNode = deps.addVertex(LogicNode("data", Some(m.name), Some(rp)))
        val addr = LogicNode("addr", Some(m.name), Some(rp))
        val en = LogicNode("en", Some(m.name), Some(rp))
        deps.addEdge(dataNode, deps.addVertex(addr), m.info)
        deps.addEdge(dataNode, deps.addVertex(en), m.info)
      }
    case i: WDefInstance =>
      installSummary(simplifiedModules(i.module), i.name, deps)
    case _ =>
      s.foreach(getStmtDeps(simplifiedModules, deps))
  }

  // Pretty-print a LogicNode with a prepended hierarchical path
  private def prettyPrintAbsoluteRef(hierPrefix: Seq[String], node: LogicNode): String = {
    (hierPrefix ++ node.inst ++ node.memport :+ node.name).mkString(".")
  }

  /*
   * Recover the full path from a path passing through simplified
   * instances. Since edges may pass through simplified instances, the
   * hierarchy that the path passes through must be recursively
   * recovered.
   */
  private def expandInstancePaths(
    m:            String,
    moduleGraphs: mutable.Map[String, ConnMap],
    moduleDeps:   Map[String, Map[String, String]],
    hierPrefix:   Seq[String],
    path:         Seq[LogicNode]
  ): Seq[String] = {
    // Recover info from edge data, add to error string
    def info(u: LogicNode, v: LogicNode): String =
      moduleGraphs(m).getEdgeData(u, v).map(_.toString).mkString("\t", "", "")
    // lhs comes after rhs
    val realPath = path.filterNot(summaryNodes.contains)
    val pathNodes = (realPath.zip(realPath.tail)).map {
      case (rhs, lhs) =>
        if (lhs.inst.isDefined && !lhs.memport.isDefined && lhs.inst == rhs.inst) {
          val child = moduleDeps(m)(lhs.inst.get)
          val newHierPrefix = hierPrefix :+ lhs.inst.get
          val subpath = moduleGraphs(child).path(lhs.copy(inst = None), rhs.copy(inst = None)).reverse
          expandInstancePaths(child, moduleGraphs, moduleDeps, newHierPrefix, subpath)
        } else {
          Seq(prettyPrintAbsoluteRef(hierPrefix, lhs) ++ info(lhs, rhs))
        }
    }
    pathNodes.flatten
  }

  /*
   * An SCC may contain more than one loop. In this case, the sequence
   * of nodes forming the SCC cannot be interpreted as a simple
   * cycle. However, it is desirable to print an error consisting of a
   * loop rather than an arbitrary ordering of the SCC. This function
   * operates on a pruned subgraph composed only of the SCC and finds
   * a simple cycle by performing an arbitrary walk.
   */
  private def findCycleInSCC[T](sccGraph: DiGraph[T]): Seq[T] = {
    val walk = new mutable.ArrayBuffer[T]
    val visited = new mutable.HashSet[T]
    var current = sccGraph.getVertices.head
    while (!visited.contains(current)) {
      walk += current
      visited += current
      current = sccGraph.getEdges(current).head
    }
    walk.drop(walk.indexOf(current)).toSeq :+ current
  }

  /*
   * This implementation of combinational loop detection avoids ever
   * generating a full netlist from the FIRRTL circuit. Instead, each
   * module is converted to a netlist and analyzed locally, with its
   * subinstances represented by trivial, simplified subgraphs. The
   * overall outline of the process is:
   *
   * 1. Create a graph of module instance dependances

   * 2. Linearize this acyclic graph
   *
   * 3. Generate a local netlist; replace any instances with
   * simplified subgraphs representing connectivity of their IOs
   *
   * 4. Check for nontrivial strongly connected components
   *
   * 5. Create a reduced representation of the netlist with only the
   * module IOs as nodes, where output X (which must be a ground type,
   * as only low FIRRTL is supported) will have an edge to input Y if
   * and only if it combinationally depends on input Y. Associate this
   * reduced graph with the module for future use.
   */
  private def run(state: CircuitState) = {
    summaryNodes.clear(); summarySerial = 0L
    val c = state.circuit
    val errors = new Errors()
    val extModulePaths = state.annotations.groupBy {
      case ann: ExtModulePathAnnotation => ModuleTarget(c.main, ann.source.module)
      case ann: Annotation              => CircuitTarget(c.main)
    }
    val moduleMap = c.modules.map({ m => (m.name, m) }).toMap
    val iGraph = InstanceKeyGraph(c).graph
    val moduleDeps =
      iGraph.getEdgeMap.map({ case (k, v) => (k.module, (v.map { i => (i.name, i.module) }).toMap) }).toMap
    val topoSortedModules = iGraph.transformNodes(_.module).linearize.reverse.map { moduleMap(_) }
    val moduleGraphs = new mutable.HashMap[String, ConnMap]
    val simplifiedModuleGraphs = new mutable.HashMap[String, ECCompactPortSummary.Summary]
    topoSortedModules.foreach {
      case em: ExtModule =>
        val portSet = em.ports.map(p => LogicNode(p.name)).toSet
        val extModuleDeps = new MutableDiGraph[LogicNode] with MutableEdgeData[LogicNode, Info]
        portSet.foreach(extModuleDeps.addVertex(_))
        extModulePaths.getOrElse(ModuleTarget(c.main, em.name), Nil).collect {
          case a: ExtModulePathAnnotation =>
            extModuleDeps.addPairWithEdge(LogicNode(a.sink.ref), LogicNode(a.source.ref))
        }
        moduleGraphs(em.name) = extModuleDeps
        simplifiedModuleGraphs(em.name) = ECCompactPortSummary.summarize(extModuleDeps, portSet)
      case m: Module =>
        val portSet = m.ports.map(p => LogicNode(p.name)).toSet
        val internalDeps = new MutableDiGraph[LogicNode] with MutableEdgeData[LogicNode, Info]
        portSet.foreach(internalDeps.addVertex(_))
        m.foreach(getStmtDeps(simplifiedModuleGraphs, internalDeps))
        moduleGraphs(m.name) = internalDeps
        simplifiedModuleGraphs(m.name) = ECCompactPortSummary.summarize(moduleGraphs(m.name), portSet)
        println(s"EC_COMPACT_PORT_SUMMARY module=${m.name} ports=${portSet.size} packed_bytes=${simplifiedModuleGraphs(m.name).rows.map(_.toLongArray.length.toLong * 8L).sum}")
        // Find combinational nodes with self-edges; this is *NOT* the same as length-1 SCCs!
        for (unitLoopNode <- internalDeps.getVertices.filter(v => internalDeps.getEdges(v).contains(v))) {
          errors.append(new CombLoopException(m.info, m.name, Seq(unitLoopNode.name)))
        }
        for (scc <- internalDeps.findSCCs.filter(_.length > 1)) {
          val sccSubgraph = internalDeps.subgraph(scc.toSet)
          val cycle = findCycleInSCC(sccSubgraph)
          (cycle.zip(cycle.tail)).foreach({ case (a, b) => require(internalDeps.getEdges(a).contains(b)) })
          // Reverse to make sure LHS comes after RHS, print repeated vertex at start for legibility
          val intuitiveCycle = cycle.reverse.filterNot(summaryNodes.contains)
          val repeatedInitial = prettyPrintAbsoluteRef(Seq(m.name), intuitiveCycle.head)
          val expandedCycle = expandInstancePaths(m.name, moduleGraphs, moduleDeps, Seq(m.name), intuitiveCycle)
          errors.append(new CombLoopException(m.info, m.name, repeatedInitial +: expandedCycle))
        }
      case m => throwInternalError(s"Module ${m.name} has unrecognized type")
    }
    val mt = ModuleTarget(c.main, c.main)
    val summary = simplifiedModuleGraphs(c.main)
    val annos = summary.nodes.indices.filter(r => !summary.rows(r).isEmpty).map { row =>
      val sink = mt.ref(summary.nodes(row).name)
      val sources = Vector.newBuilder[ReferenceTarget]
      var bit = summary.rows(row).nextSetBit(0)
      while (bit >= 0) {
        sources += mt.ref(summary.nodes(bit).name)
        bit = summary.rows(row).nextSetBit(bit + 1)
      }
      CombinationalPath(sink, sources.result())
    }
    (state.copy(annotations = state.annotations ++ annos), errors, simplifiedModuleGraphs, moduleGraphs)
  }

  /**
    * Returns a Map from Module name to port connectivity
    */
  def analyze(state: CircuitState): collection.Map[String, DiGraph[String]] = {
    val (result, errors, connectivity, _) = run(state)
    connectivity.map {
      case (k, v) => (k, v.named)
    }
  }

  /**
    * Returns a Map from Module name to complete netlist connectivity
    */
  def analyzeFull(state: CircuitState): collection.Map[String, DiGraph[LogicNode]] = {
    val graphs = run(state)._4
    graphs.map { case (name, graph) =>
      val expanded = new MutableDiGraph[LogicNode]
      val real = graph.getVertices.filterNot(summaryNodes.contains)
      real.foreach(expanded.addVertex)
      real.foreach { from =>
        graph.getEdges(from).foreach { to =>
          if (summaryNodes.contains(to)) graph.getEdges(to).foreach(expanded.addEdge(from, _))
          else expanded.addEdge(from, to)
        }
      }
      name -> expanded
    }
  }

  def execute(state: CircuitState): CircuitState = {
    val dontRun = state.annotations.contains(DontCheckCombLoopsAnnotation)
    if (dontRun) {
      logger.warn("Skipping Combinational Loop Detection")
      state
    } else {
      val (result, errors, connectivity, _) = run(state)
      errors.trigger()
      result
    }
  }
}
