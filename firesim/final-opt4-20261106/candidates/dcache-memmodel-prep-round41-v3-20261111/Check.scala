package opt4memmodelprep

import firrtl._
import firrtl.ir._
import firrtl.annotations.JsonProtocol
import midas.targetutils.FirrtlMemModelAnnotation
import org.json4s._
import org.json4s.native.JsonMethods.parse
import java.nio.file.{Files, Paths}
import java.nio.charset.StandardCharsets.UTF_8

/** Resolve host memory metadata against the unchanged emitted target AST.
  * This program never executes a target or host transformation.
  */
object Check {
  def read(p: String): String = new String(Files.readAllBytes(Paths.get(p)), UTF_8)
  def main(args: Array[String]): Unit = {
    require(args.length == 3)
    val circuit = Parser.parse(read(args(0)))
    require(circuit.main == "FireSim")
    val original = JsonProtocol.deserialize(read(args(1)))
    val staged = JsonProtocol.deserialize(read(args(2)))
    def canonical(v: JValue): JValue = v match {
      case JObject(fields) => JObject(fields.sortBy(_._1).map { case (name, value) => name -> canonical(value) })
      case JArray(values) => JArray(values.map(canonical))
      case other => other
    }
    val originalJSON = parse(read(args(1))).asInstanceOf[JArray].arr
    val stagedJSON = parse(read(args(2))).asInstanceOf[JArray].arr
    require(canonical(JArray(stagedJSON.take(originalJSON.size))) == canonical(JArray(originalJSON)), "Existing metadata JSON changed")
    val expected = Set("ownerImageMemory", "ownerGenerationMemory", "ownerPacketMemory", "ownerTrackedMemory")
    val memories = circuit.modules.collect { case m: Module =>
      val names = scala.collection.mutable.Set.empty[String]
      def visit(s: Statement): Unit = {
        s match {
          case d: CDefMemory => names += d.name
          case d: DefMemory => names += d.name
          case _ =>
        }
        s.foreachStmt(visit)
      }
      visit(m.body)
      m.name -> names.toSet
    }.toMap
    def validate(annotations: AnnotationSeq): Unit = {
      val added = annotations.drop(original.size).map {
        case a: FirrtlMemModelAnnotation => a
        case _ => throw new IllegalArgumentException("Unexpected annotation class")
      }
      require(added.size == 4 && added.map(_.target.ref).toSet == expected)
      require(added.forall(a => a.target.module == "BoomNonBlockingDCache"))
      val all = annotations.collect { case a: FirrtlMemModelAnnotation => a }
      require(all.size == 14 && all.map(_.target).distinct.size == 14)
      all.foreach { a =>
        val t = a.target
        require(t.circuit == circuit.main && t.path.isEmpty && t.component.isEmpty)
        require(memories.getOrElse(t.module, Set.empty).contains(t.ref), "Unresolved memory target: " + t.serialize)
      }
    }
    validate(staged)
    val added = staged.drop(original.size).map(_.asInstanceOf[FirrtlMemModelAnnotation])
    val bad = Seq(
      staged.dropRight(1),
      staged :+ added.head,
      original ++ (added.head.copy(target=added.head.target.copy(ref="ownerMissingMemory")) +: added.tail),
      original.dropRight(1) ++ added)
    bad.zipWithIndex.foreach { case (candidate, index) =>
      val rejected = try { validate(candidate); false } catch { case _: IllegalArgumentException => true }
      require(rejected, "Annotation mutation accepted: " + index)
    }
    println("PASS_UNCHANGED_TARGET_AST_MEMORY_ANNOTATION_RESOLUTION original=10 staged=14 added=4 negatives=4 transformations=0")
  }
}
