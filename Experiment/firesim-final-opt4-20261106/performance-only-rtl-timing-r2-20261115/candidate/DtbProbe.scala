package ectimingdtb

import java.nio.file.{Files, Paths}
import freechips.rocketchip.diplomacy.DTB

object DtbProbe extends App {
  val text = new String(Files.readAllBytes(Paths.get(args(0))), "UTF-8")
  val expected = Files.readAllBytes(Paths.get(args(1)))
  val count = args(2).toInt
  var failures = 0
  for (index <- 0 until count) {
    val actual = DTB(text).contents.toArray
    if (!java.util.Arrays.equals(actual, expected)) {
      failures += 1
      println(s"DTB_MISMATCH iteration=$index actual=${actual.length} expected=${expected.length}")
    }
  }
  println(s"DTB_FILE_OUTPUT_COMPARE iterations=$count failures=$failures")
  if (failures != 0) sys.exit(1)
}
