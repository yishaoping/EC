package opt4packedref

import chisel3._
import chisel3.util._

/** Exact combinational histogram. All architectural registers stay outside.
  * Compact equal keys in groups of four before the 256-way scatter, sharing
  * local additions across destinations instead of repeating them per bucket.
  */
object AddressBucketGrouped {
  case class Entry(key: UInt, counts: Seq[UInt], last: Bool)

  def compact4(keys: Seq[UInt], counts: Seq[Seq[UInt]], bounds: Seq[Int]): Seq[Entry] = {
    require(keys.size == 4 && counts.size == 4 && bounds.forall(_ > 0))
    require(counts.forall(_.size == bounds.size))
    var records = keys.indices.map(i => (keys(i), bounds.indices.map(g =>
      counts(i)(g)(log2Ceil(bounds(g) + 1) - 1, 0))))
    // Five-comparator sorting network for four unsigned keys. Equal-key
    // payload order is immaterial because all equal-key counts are added.
    for ((a, b) <- Seq((0, 1), (2, 3), (0, 2), (1, 3), (1, 2))) {
      val x = records(a); val y = records(b); val ordered = x._1 <= y._1
      val lo = (Mux(ordered, x._1, y._1), bounds.indices.map(g =>
        Mux(ordered, x._2(g), y._2(g))))
      val hi = (Mux(ordered, y._1, x._1), bounds.indices.map(g =>
        Mux(ordered, y._2(g), x._2(g))))
      records = records.updated(a, lo).updated(b, hi)
    }
    var prefix = records.head._2
    records.indices.map { i =>
      if (i > 0) {
        val same = records(i - 1)._1 === records(i)._1
        prefix = bounds.indices.map { g =>
          val width = log2Ceil((i + 1) * bounds(g) + 1)
          Mux(same, prefix(g).pad(width) + records(i)._2(g).pad(width),
            records(i)._2(g).pad(width))
        }
      }
      Entry(records(i)._1, prefix,
        if (i == 3) true.B else records(i)._1 =/= records(i + 1)._1)
    }
  }

  def scatter(group: Seq[Entry], key: UInt, granule: Int, bound: Int): UInt = {
    val width = log2Ceil(4 * bound + 1)
    Mux1H(group.map(e => (e.last && e.key === key, e.counts(granule).pad(width))))
  }

  private def sum(xs: Seq[(UInt, Int)]): UInt = {
    require(xs.nonEmpty)
    if (xs.size == 1) xs.head._1
    else sum(xs.grouped(2).map {
      case Seq((a, aMax), (b, bMax)) =>
        val bound = aMax + bMax
        val width = log2Ceil(bound + 1)
        (a.pad(width) + b.pad(width), bound)
      case Seq(a) => a
    }.toSeq)
  }

  def histogram(keys: Seq[UInt], counts: Seq[Seq[UInt]], bounds: Seq[Int], slots: Int): Vec[Vec[UInt]] = {
    require(keys.nonEmpty && keys.size % 4 == 0 && keys.size == counts.size)
    require(isPow2(slots) && keys.forall(_.getWidth == log2Ceil(slots)))
    val groups = keys.indices.grouped(4).map { ids =>
      compact4(ids.map(keys(_)), ids.map(counts(_)), bounds)
    }.toSeq
    VecInit((0 until slots).map { i =>
      VecInit(bounds.indices.map { g =>
        sum(groups.map(group => (scatter(group, i.U(log2Ceil(slots).W), g, bounds(g)),
          4 * bounds(g)))).pad(64)
      })
    })
  }
}
