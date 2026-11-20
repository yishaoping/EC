package boom.lsu

import chisel3._
import chisel3.util._

/** Exact combinational scatter-sum. No state, clock enable, or latency.
  *
  * Sort (bucket, payload) pairs once, perform a segmented prefix sum, and
  * decode only the final item of each equal-key run. This replaces one full
  * N-term adder tree per destination with a shared network. Payload bounds
  * are the proven processTouch population bounds; architectural counters
  * and their carry/error checks remain 64/65 bits in PackageAddressStats.
  */
object AddressBucketReduction {
  private type Row = (UInt, Seq[UInt])
  def sortRows(keys: Seq[UInt], values: Seq[Seq[UInt]],
      leafWidths: Seq[Int], keyBits: Int): Seq[(UInt, Seq[UInt])] = {
    val n = keys.size
    val padded = 1 << log2Ceil(n)
    // The sentinel sorts strictly after every real key. Zero-valued padding
    // therefore cannot displace a real row from the first n sorted entries.
    var rows: Seq[Row] = (0 until padded).map { i =>
      if (i < n) (Cat(0.U(1.W), keys(i)(keyBits - 1, 0)),
        values(i).zip(leafWidths).map { case (x, w) => x(w - 1, 0) })
      else ((BigInt(1) << keyBits).U((keyBits + 1).W), leafWidths.map(w => 0.U(w.W)))
    }
    var span = 2
    while (span <= padded) {
      var distance = span / 2
      while (distance > 0) {
        val before = rows
        val after = collection.mutable.ArrayBuffer.from(before)
        for (i <- 0 until padded if (i ^ distance) > i) {
          val j = i ^ distance
          val a = before(i)
          val b = before(j)
          val swap = if ((i & span) == 0) a._1 > b._1 else a._1 < b._1
          after(i) = (Mux(swap, b._1, a._1),
            a._2.zip(b._2).map { case (x, y) => Mux(swap, y, x) })
          after(j) = (Mux(swap, a._1, b._1),
            a._2.zip(b._2).map { case (x, y) => Mux(swap, x, y) })
        }
        rows = after.toSeq
        distance /= 2
      }
      span *= 2
    }
    rows.take(n)
  }

  def apply(keys: Seq[UInt], values: Seq[Seq[UInt]],
      maxCounts: Seq[Int], buckets: Int): Seq[Seq[UInt]] = {
    require(keys.nonEmpty && keys.size == values.size && isPow2(buckets))
    require(maxCounts.nonEmpty && maxCounts.forall(_ > 0))
    require(values.forall(_.size == maxCounts.size))
    val n = keys.size
    val leafWidths = maxCounts.map(m => log2Ceil(m + 1))
    val sorted = sortRows(keys, values, leafWidths, log2Ceil(buckets))
    var sums = sorted.map(_._2)
    var distance = 1
    while (distance < n) {
      val before = sums
      val widths = maxCounts.map(m => log2Ceil((2 * distance min n) * m + 1))
      sums = (0 until n).map { i =>
        maxCounts.indices.map { g =>
          val value = before(i)(g).pad(widths(g))
          if (i < distance) value
          else Mux(sorted(i)._1 === sorted(i - distance)._1,
            value + before(i - distance)(g).pad(widths(g)), value)
        }
      }
      distance *= 2
    }
    val last = (0 until n).map { i =>
      if (i + 1 == n) true.B else sorted(i)._1 =/= sorted(i + 1)._1
    }
    (0 until buckets).map { b =>
      val select = (0 until n).map(i => last(i) && sorted(i)._1 === b.U)
      maxCounts.indices.map { g =>
        // Sorting implies at most one last-of-run row for any real bucket.
        Mux1H(select.zip(sums.map(_(g)))).pad(64)
      }
    }
  }
}
