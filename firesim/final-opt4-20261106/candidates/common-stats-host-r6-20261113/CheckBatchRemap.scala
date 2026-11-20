package firrtl

import firrtl.annotations._
import firrtl.transforms.CombinationalPath
import scala.util.Try

case class BatchRemapNote(value: Int) extends NoTargetAnnotation

object CheckBatchRemap extends App {
  var checked = 0
  for (seed <- 0 until 32; variant <- 0 until 9) {
    val mt = ModuleTarget("C", "M")
    val refs = Vector.tabulate(1 + seed % 13)(i => mt.ref("p"+i))
    val nonlocal = mt.instOf("child", "Child").ref("p")
    val row = (refs ++ refs.take(2) ++ Vector(nonlocal)).toVector
    val annotations: AnnotationSeq = Vector(BatchRemapNote(seed), BatchRemapNote(seed)) ++
      refs.flatMap(r => Vector(CombinationalPath(r, row), CombinationalPath(r, row))) ++
      Vector(CombinationalPath(nonlocal, refs), BatchRemapNote(seed + 1))
    val renames = variant match {
      case 0 => RenameMap()
      case 1 => RenameMap.create(Map(CircuitTarget("C") -> Seq(CircuitTarget("D"))))
      case 2 => RenameMap.create(Map(CircuitTarget("C") -> Seq.empty))
      case 3 => RenameMap.create(Map(CircuitTarget("C") -> Seq(CircuitTarget("D"), CircuitTarget("E"))))
      case 4 => RenameMap.create(Map(refs.head -> Seq(mt.ref("changed"))))
      case 5 => RenameMap.create(Map(refs.head -> Seq.empty))
      case 6 => RenameMap.create(Map(refs.head -> Seq(mt.ref("a"), nonlocal, mt.ref("b"))))
      case 7 => RenameMap.create(Map(CircuitTarget("C") -> Seq(CircuitTarget("D")))).andThen(
        RenameMap.create(Map(CircuitTarget("D") -> Seq(CircuitTarget("E")))))
      case 8 => RenameMap.create(Map(nonlocal -> Seq(mt.ref("local"))))
    }
    val stock = Try(Transform.propagateAnnotations(annotations, Some(renames)).toSeq)
    val candidate = Try(ECBatchAnnotationRemap(annotations, renames).toSeq)
    (stock, candidate) match {
      case (scala.util.Success(a), scala.util.Success(b)) => assert(a == b, (seed, variant))
      case (scala.util.Failure(a), scala.util.Failure(b)) =>
        assert(a.getClass == b.getClass && a.getMessage == b.getMessage, (seed, variant))
      case other => sys.error(s"Different remap result: seed=$seed variant=$variant $other")
    }
    checked += 1
  }
  val mt = ModuleTarget("Dense", "Dense")
  val refs = Vector.tabulate(512)(i => mt.ref("p"+i))
  val row = refs.take(384)
  val dense: AnnotationSeq = refs.drop(384).map(ref => CombinationalPath(ref, row))
  val rename = RenameMap.create(Map(CircuitTarget("Dense") -> Seq(CircuitTarget("Renamed"))))
  val expected = Transform.propagateAnnotations(dense, Some(rename)).toSeq
  val actual = ECBatchAnnotationRemap(dense, rename).toSeq
  assert(actual == expected)
  val mapped = actual.collect { case path: CombinationalPath => path }
  assert(mapped.forall(path => path.sources.asInstanceOf[AnyRef] eq mapped.head.sources.asInstanceOf[AnyRef]))
  val changed = mapped.updated(0, mapped.head.copy(sources = mapped.head.sources.reverse))
  assert(changed != expected, "source-order mutation must be rejected")
  // A new call must observe mutations of a RenameMap; caches never cross calls.
  val mutableRename = RenameMap()
  val before = ECBatchAnnotationRemap(dense, mutableRename).toSeq
  mutableRename.record(CircuitTarget("Dense"), CircuitTarget("Later"))
  val after = ECBatchAnnotationRemap(dense, mutableRename).toSeq
  assert(before != after && after == Transform.propagateAnnotations(dense, Some(mutableRename)).toSeq)
  println(s"EC_BATCH_REMAP_REGRESSION_PASS cases=$checked dense_rows=${mapped.size} exact_order_values_distinct=true mutation_negative=true cache_scope_per_call=true")
}
