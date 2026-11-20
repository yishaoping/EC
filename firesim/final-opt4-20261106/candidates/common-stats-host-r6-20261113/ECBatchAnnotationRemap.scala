package firrtl

import firrtl.annotations._
import firrtl.transforms.CombinationalPath
import scala.collection.mutable

/** Same ordered update/distinct operation as Transform.propagateAnnotations.
  * Caches are confined to one invocation with one completed RenameMap.
  */
object ECBatchAnnotationRemap {
  def apply(annotations: AnnotationSeq, renames: RenameMap): AnnotationSeq = {
    val targets = mutable.HashMap.empty[ReferenceTarget, Vector[ReferenceTarget]]
    val rows = new java.util.IdentityHashMap[Seq[ReferenceTarget], Vector[ReferenceTarget]]()
    def target(ref: ReferenceTarget): Vector[ReferenceTarget] = targets.getOrElseUpdate(ref,
      renames(ref).collect { case r: ReferenceTarget if r.isLocal => r }.toVector)
    def sources(old: Seq[ReferenceTarget]): Vector[ReferenceTarget] = {
      val found = rows.get(old)
      if (found != null) found
      else {
        val result = old.iterator.flatMap(ref => target(ref).iterator).toVector
        rows.put(old, result)
        result
      }
    }
    val seen = mutable.HashSet.empty[Annotation]
    val result = Vector.newBuilder[Annotation]
    annotations.toSeq.iterator.foreach { annotation =>
      val renamed: Seq[Annotation] = annotation match {
        case CombinationalPath(sink, oldSources) =>
          val newSources = sources(oldSources)
          target(sink).map(ref => CombinationalPath(ref, newSources))
        case other => other.update(renames)
      }
      renamed.foreach { value =>
        if (!seen(value)) { seen += value; result += value }
      }
    }
    val answer = result.result()
    println(s"EC_BATCH_ANNOTATION_REMAP input=${annotations.toSeq.size} output=${answer.size} source_rows=${rows.size} target_values=${targets.size}")
    answer
  }
}
