package boom.lsu

import chisel3._
import chisel3.util._

import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/** One architecturally committed, cacheable, ordinary load/store. */
class AddressAccessEvent(val addrBits: Int) extends Bundle {
  val addr = UInt(addrBits.W)
  val size = UInt(2.W)
  val isStore = Bool()
  val packetSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
}

class QueuedAddressAccessEvent(addrBits: Int) extends AddressAccessEvent(addrBits) {
  val safeWatermark = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
}

class PackageAddressLineState(lineTagBits: Int, maskBits: Int) extends Bundle {
  val sessionTag = UInt(64.W)
  val packetSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
  val lineTag = UInt(lineTagBits.W)
  val seen = UInt(maskBits.W)
  val storeSeen = UInt(maskBits.W)
  // First-operation candidates are retained after the package becomes safe.
  // Capacity-driven eviction converts unresolved candidates into the upper
  // bound instead of silently losing them.
  val loadFirst = UInt(maskBits.W)
  val storeFirst = UInt(maskBits.W)
}

/** Strict first-store candidates are kept independently of the package table.
  * One entry still represents one (packet,line), so all bits in the mask share
  * the packet sequence.  This is sufficient because a subsequent access to an
  * address unit invalidates the candidate before a new package can replace it.
  */
class StrictPackageLineState(lineTagBits: Int, maskBits: Int) extends Bundle {
  val sessionTag = UInt(64.W)
  val packetSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
  val lineTag = UInt(lineTagBits.W)
  val strictStoreFirst = UInt(maskBits.W)
}

/**
  * Exact online peaks plus exact and bounded package-address totals.
  *
  * Exactness is fail-closed: every associative entry carries a full physical
  * line tag.  A full ordinary/strict set, queue overflow, malformed event,
  * package-slot alias, or arithmetic error freezes the block and clears
  * statsValid instead of silently merging or dropping addresses.
  */
class PackageAddressStats(
  commitWidth: Int,
  addrBits: Int,
  lineBytes: Int,
  packetWindow: Int,
  queueDepth: Int = 256,
  packageSets: Int = 1024,
  packageWays: Int = 8) extends Module {

  require(commitWidth > 0)
  require(isPow2(lineBytes) && lineBytes >= 8)
  require(isPow2(packetWindow))
  require(isPow2(queueDepth))
  require(isPow2(packageSets))
  require(packageWays > 0)

  private val blockOffBits = log2Ceil(lineBytes)
  private val lineTagBits = addrBits - blockOffBits
  private val word4Count = lineBytes / 4
  private val word8Count = lineBytes / 8
  private val byteLo = 0
  private val byteHi = lineBytes - 1
  private val word4Lo = byteHi + 1
  private val word4Hi = word4Lo + word4Count - 1
  private val word8Lo = word4Hi + 1
  private val word8Hi = word8Lo + word8Count - 1
  private val lineBit = word8Hi + 1
  private val maskBits = lineBit + 1
  private val queueIndexBits = log2Ceil(queueDepth)
  private val queueCountBits = log2Ceil(queueDepth + 1)
  private val packetIndexBits = log2Ceil(packetWindow)
  private val packageIndexBits = log2Ceil(packageSets)
  // Strict candidates have an independent associativity budget.  Keeping two
  // times the ordinary ways prevents strict write-then-read history from
  // recreating the ordinary package-table conflict pattern.
  private val strictWays = packageWays * 2
  // A global spill table handles adversarial concentration in one strict set.
  // It is exact (full packet/line key), and exhaustion remains fail-closed.
  private val strictOverflowEntries = packageWays * 8

  val io = IO(new Bundle {
    val resetStats = Input(Bool())
    val start = Input(Bool())
    // STOP is an inclusive boundary: events committed on the STOP edge are
    // still accepted, while later cycles only drain the already queued events
    // and advance the safety watermark.
    val stop = Input(Bool())
    val events = Input(Vec(commitWidth, Valid(new AddressAccessEvent(addrBits))))
    val safeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val sequenceBaseline = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val fatalProtocolError = Input(Bool())

    // Four granularities x ten existing metrics in the order documented in
    // GH_GlobalParams and AI/Design/package_address_statistics.md.
    val counters = Output(Vec(
      GH_GlobalParams.GH_ADDRESS_STATS_GRANULES *
        GH_GlobalParams.GH_ADDRESS_STATS_PER_GRANULE, UInt(64.W)))
    // The first-operation-store metrics are appended after the existing
    // validity/error/pending ABI slots, so they use a separate output vector.
    val firstStoreCounters = Output(Vec(
      GH_GlobalParams.GH_ADDRESS_STATS_GRANULES *
        GH_GlobalParams.GH_ADDRESS_FIRST_STORE_STRIDE, UInt(64.W)))
    val statsValid = Output(Bool())
    val error = Output(UInt(64.W))
    val pending = Output(UInt(64.W))
    val idle = Output(Bool())
  })

  private def packageSetOf(lineTag: UInt): UInt = {
    val low = lineTag(packageIndexBits - 1, 0)
    val high = lineTag((2 * packageIndexBits - 1) min (lineTagBits - 1), packageIndexBits)
    if (lineTagBits >= 2 * packageIndexBits) low ^ high else low
  }

  private def splitCounts(mask: UInt): Vec[UInt] = VecInit(Seq(
    PopCount(mask(byteHi, byteLo)),
    PopCount(mask(word4Hi, word4Lo)),
    PopCount(mask(word8Hi, word8Lo)),
    mask(lineBit).asUInt))

  private def addOverflows(value: UInt, delta: UInt): Bool =
    delta.orR && value > (~0.U(64.W) - delta.pad(64))

  private def touchedMask(event: QueuedAddressAccessEvent): UInt = {
    // AddressAccessEvent.size is the architectural 2-bit log2(size) encoding
    // for ordinary 1/2/4/8-byte accesses.  StoreGen(lineBytes) expects a
    // log2(lineBytes)-wide size input, so using it here would read bits that do
    // not exist when a cache line is wider than eight bytes.  Build the four
    // legal byte masks explicitly and shift them by the in-line byte offset.
    val unshiftedByteMask = MuxLookup(event.size, 1.U(lineBytes.W), Seq(
      0.U -> 0x1.U(lineBytes.W),
      1.U -> 0x3.U(lineBytes.W),
      2.U -> 0xf.U(lineBytes.W),
      3.U -> 0xff.U(lineBytes.W)))
    val byteMask = (unshiftedByteMask <<
      event.addr(blockOffBits - 1, 0))(lineBytes - 1, 0)
    val word4Mask = VecInit((0 until word4Count).map { i =>
      byteMask(4 * i + 3, 4 * i).orR
    }).asUInt
    val word8Mask = VecInit((0 until word8Count).map { i =>
      byteMask(8 * i + 7, 8 * i).orR
    }).asUInt
    Cat(byteMask.orR, word8Mask, word4Mask, byteMask)
  }

  // Error bitmap exported to software.
  private val errQueueOverflow = 0
  private val errPackageTableFull = 1
  // Error bit 2 was used by the removed cross-package history table. Keep it
  // reserved so existing diagnostic bit assignments remain stable.
  private val errPacketSlot = 3
  private val errMalformedEvent = 4
  private val errArithmetic = 5
  private val errProtocol = 6

  val running = RegInit(false.B)
  // DCache deliberately includes architecturally committed accesses on the
  // START edge in its measurement window.  Treat that edge as active here as
  // well; waiting for the registered running bit would silently lose them.
  val acceptingWindow = (running || io.start || io.stop) && !io.resetStats
  val statsValid = RegInit(true.B)
  val errorReg = RegInit(0.U(64.W))
  val processedSafeWatermark = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  // Epoch-tag SRAM entries instead of resetting set-indexed valid-bit arrays.
  // The nonzero initial value keeps power-up-zero simulation memories invalid.
  val sessionTag = RegInit("h9e3779b97f4a7c15".U(64.W))

  val queue = Reg(Vec(queueDepth, new QueuedAddressAccessEvent(addrBits)))
  val enqPtr = RegInit(0.U(queueIndexBits.W))
  val deqPtr = RegInit(0.U(queueIndexBits.W))
  val queueCount = RegInit(0.U(queueCountBits.W))
  val queueHead = queue(deqPtr)

  // One memory read can be processed while the next non-conflicting read is
  // issued. Reads that address the same package set are serialized.
  val processValid = RegInit(false.B)
  val processEvent = Reg(new QueuedAddressAccessEvent(addrBits))
  // After STOP, continue processing queued events and retiring the watermark,
  // but do not admit new events.  The watermark comparison keeps the module
  // alive until post-STOP PASS results have become visible.
  val drainingWindow = running || io.start || io.stop || processValid ||
    queueCount =/= 0.U || processedSafeWatermark =/= io.safeWatermark

  val packageMem = Seq.fill(packageWays)(SyncReadMem(
    packageSets, new PackageAddressLineState(lineTagBits, maskBits)))
  // Strict write-then-read state has a separate associativity budget.  It no
  // longer pins an otherwise recyclable package-table way.
  val strictMem = Seq.fill(strictWays)(SyncReadMem(
    packageSets, new StrictPackageLineState(lineTagBits, maskBits)))

  val packageReadData = Wire(Vec(packageWays,
    new PackageAddressLineState(lineTagBits, maskBits)))
  val strictReadData = Wire(Vec(strictWays,
    new StrictPackageLineState(lineTagBits, maskBits)))
  val strictOverflowValid = RegInit(VecInit(
    Seq.fill(strictOverflowEntries)(false.B)))
  val strictOverflowData = Reg(Vec(strictOverflowEntries,
    new StrictPackageLineState(lineTagBits, maskBits)))

  val metricStoreTotal = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStorePeak = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricLoadFirstLower = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricLoadFirstUpper = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricLoadFirstPeak = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStoreFirstLower = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStoreFirstUpper = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStoreFirstPeak = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStrictWriteReadTotal = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricStrictWriteReadPeak = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricFirstStoreTotal = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val metricFirstStorePeak = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val onlineStore = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val onlineLoadFirst = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val onlineStoreFirst = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val onlineStrictWriteRead = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))
  val onlineFirstStore = RegInit(VecInit(Seq.fill(4)(0.U(64.W))))

  val bucketValid = RegInit(VecInit(Seq.fill(packetWindow)(false.B)))
  val bucketSeq = Reg(Vec(packetWindow,
    UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
  val bucketStore = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketLoadFirst = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStoreFirst = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStrictWriteRead = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketFirstStore = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))


  val processLineTag = processEvent.addr(addrBits - 1, blockOffBits)
  val processPackageSet = packageSetOf(processLineTag)
  val processTouch = touchedMask(processEvent)
  val processSizeBytes = 1.U(5.W) << processEvent.size
  val processLineOffset = processEvent.addr(blockOffBits - 1, 0)
  val processCrossesLine = processLineOffset +& processSizeBytes > lineBytes.U
  // The checker watermark only proves that the package result is safe; it
  // does not prove that BOOM has already retired every LSQ entry carrying
  // that package tag. Equality is therefore a valid same-package tail event.
  // Events strictly older than the watermark remain malformed.
  val processMalformed = processEvent.packetSeq === 0.U ||
    processEvent.packetSeq < processEvent.safeWatermark || processCrossesLine

  val packageMatch = Wire(Vec(packageWays, Bool()))
  val packageFree = Wire(Vec(packageWays, Bool()))
  val packageEvictable = Wire(Vec(packageWays, Bool()))
  for (w <- 0 until packageWays) {
    val valid = packageReadData(w).sessionTag === sessionTag
    val live = valid &&
      packageReadData(w).packetSeq > processedSafeWatermark
    val safe = valid &&
      packageReadData(w).packetSeq <= processedSafeWatermark
    val sameLine = valid && packageReadData(w).lineTag === processLineTag
    val loadFirstRemaining = packageReadData(w).loadFirst & ~Mux(
      processEvent.isStore && sameLine, processTouch, 0.U(maskBits.W))
    val storeFirstRemaining = packageReadData(w).storeFirst & ~Mux(
      !processEvent.isStore && sameLine, processTouch, 0.U(maskBits.W))
    val remaining = loadFirstRemaining | storeFirstRemaining
    packageMatch(w) := live &&
      packageReadData(w).packetSeq === processEvent.packetSeq &&
      packageReadData(w).lineTag === processLineTag
    packageFree(w) := !valid || (safe && !remaining.orR)
    // Strict candidates live in a separate table and therefore do not pin a
    // package-table way. Loose third/fifth candidates may be evicted after
    // safety and charged to their upper bound.
    packageEvictable(w) := safe
  }
  val packageFound = packageMatch.asUInt.orR
  val packageAvailable = packageFound || packageFree.asUInt.orR ||
    packageEvictable.asUInt.orR
  val packageWayOH = Mux(packageFound,
    PriorityEncoderOH(packageMatch.asUInt),
    Mux(packageFree.asUInt.orR,
      PriorityEncoderOH(packageFree.asUInt),
      PriorityEncoderOH(packageEvictable.asUInt)))

  val currentPackageState = Wire(new PackageAddressLineState(lineTagBits, maskBits))
  currentPackageState := 0.U.asTypeOf(currentPackageState)
  for (w <- 0 until packageWays) {
    when (packageWayOH(w) && packageFound) {
      currentPackageState := packageReadData(w)
    }
  }
  val newStoreMask = Mux(processEvent.isStore,
    processTouch & ~currentPackageState.storeSeen, 0.U(maskBits.W))
  val newLoadFirstMask = Mux(!processEvent.isStore,
    processTouch & ~currentPackageState.seen, 0.U(maskBits.W))
  val newStoreFirstMask = Mux(processEvent.isStore,
    processTouch & ~currentPackageState.seen, 0.U(maskBits.W))
  val newStoreCounts = splitCounts(newStoreMask)
  // Every newly seen store is also a first-operation-store address.  This is
  // charged immediately and never depends on a later load/store.
  val newFirstStoreCounts = splitCounts(newStoreFirstMask)

  val strictMatch = Wire(Vec(strictWays, Bool()))
  val strictFree = Wire(Vec(strictWays, Bool()))
  for (w <- 0 until strictWays) {
    val valid = strictReadData(w).sessionTag === sessionTag &&
      strictReadData(w).strictStoreFirst.orR
    val sameLine = valid && strictReadData(w).lineTag === processLineTag
    val remaining = strictReadData(w).strictStoreFirst & ~Mux(
      sameLine, processTouch, 0.U(maskBits.W))
    strictMatch(w) := valid &&
      strictReadData(w).packetSeq === processEvent.packetSeq &&
      strictReadData(w).lineTag === processLineTag
    strictFree(w) := !valid || (sameLine && !remaining.orR)
  }
  val strictFound = strictMatch.asUInt.orR
  val strictOverflowMatch = Wire(Vec(strictOverflowEntries, Bool()))
  val strictOverflowFree = Wire(Vec(strictOverflowEntries, Bool()))
  for (i <- 0 until strictOverflowEntries) {
    val valid = strictOverflowValid(i) &&
      strictOverflowData(i).sessionTag === sessionTag &&
      strictOverflowData(i).strictStoreFirst.orR
    val sameLine = valid &&
      strictOverflowData(i).lineTag === processLineTag
    val remaining = strictOverflowData(i).strictStoreFirst & ~Mux(
      sameLine, processTouch, 0.U(maskBits.W))
    strictOverflowMatch(i) := valid &&
      strictOverflowData(i).packetSeq === processEvent.packetSeq &&
      strictOverflowData(i).lineTag === processLineTag
    strictOverflowFree(i) := !valid || (sameLine && !remaining.orR)
  }
  val strictOverflowFound = strictOverflowMatch.asUInt.orR
  val strictHasNewCandidates = newStoreFirstMask.orR
  val strictAnyFound = strictFound || strictOverflowFound
  val strictAvailable = !strictHasNewCandidates || strictAnyFound ||
    strictFree.asUInt.orR || strictOverflowFree.asUInt.orR
  // A key is kept in exactly one strict storage class. Existing overflow
  // matches win over a free primary way; otherwise an existing primary match
  // wins over allocation. This prevents a duplicate (packet,line) candidate
  // from being counted once in each table after a set collision.
  val strictUsePrimary = strictHasNewCandidates &&
    !strictOverflowFound && (strictFound || strictFree.asUInt.orR)
  val strictUseOverflow = strictHasNewCandidates && !strictUsePrimary
  val strictWayOH = Mux(strictFound,
    PriorityEncoderOH(strictMatch.asUInt),
    PriorityEncoderOH(strictFree.asUInt))
  val strictOverflowWayOH = Mux(strictOverflowFound,
    PriorityEncoderOH(strictOverflowMatch.asUInt),
    PriorityEncoderOH(strictOverflowFree.asUInt))

  val loadFirstHit = Wire(Vec(packageWays, UInt(maskBits.W)))
  val storeFirstHit = Wire(Vec(packageWays, UInt(maskBits.W)))
  val strictWriteReadHit = Wire(Vec(strictWays, UInt(maskBits.W)))
  val strictOverflowWriteReadHit =
    Wire(Vec(strictOverflowEntries, UInt(maskBits.W)))
  val unsafeLoadFirstHit = Wire(Vec(packageWays, UInt(maskBits.W)))
  val unsafeStoreFirstHit = Wire(Vec(packageWays, UInt(maskBits.W)))
  val unsafeStrictWriteReadHit = Wire(Vec(strictWays, UInt(maskBits.W)))
  val unsafeStrictOverflowWriteReadHit =
    Wire(Vec(strictOverflowEntries, UInt(maskBits.W)))
  for (w <- 0 until packageWays) {
    val sameLine = packageReadData(w).sessionTag === sessionTag &&
      packageReadData(w).lineTag === processLineTag
    val unsafe = packageReadData(w).packetSeq > processedSafeWatermark
    loadFirstHit(w) := Mux(processEvent.isStore && sameLine,
      processTouch & packageReadData(w).loadFirst, 0.U(maskBits.W))
    storeFirstHit(w) := Mux(!processEvent.isStore && sameLine,
      processTouch & packageReadData(w).storeFirst, 0.U(maskBits.W))
    unsafeLoadFirstHit(w) := Mux(unsafe, loadFirstHit(w), 0.U)
    unsafeStoreFirstHit(w) := Mux(unsafe, storeFirstHit(w), 0.U)
  }
  for (w <- 0 until strictWays) {
    val strictSameLine = strictReadData(w).sessionTag === sessionTag &&
      strictReadData(w).lineTag === processLineTag
    val strictUnsafe = strictReadData(w).sessionTag === sessionTag &&
      strictReadData(w).packetSeq > processedSafeWatermark
    strictWriteReadHit(w) := Mux(!processEvent.isStore && strictSameLine,
      processTouch & strictReadData(w).strictStoreFirst, 0.U(maskBits.W))
    unsafeStrictWriteReadHit(w) := Mux(strictUnsafe, strictWriteReadHit(w),
      0.U(maskBits.W))
  }
  for (i <- 0 until strictOverflowEntries) {
    val sameLine = strictOverflowValid(i) &&
      strictOverflowData(i).sessionTag === sessionTag &&
      strictOverflowData(i).lineTag === processLineTag
    val unsafe = strictOverflowValid(i) &&
      strictOverflowData(i).packetSeq > processedSafeWatermark
    strictOverflowWriteReadHit(i) := Mux(!processEvent.isStore && sameLine,
      processTouch & strictOverflowData(i).strictStoreFirst,
      0.U(maskBits.W))
    unsafeStrictOverflowWriteReadHit(i) := Mux(unsafe,
      strictOverflowWriteReadHit(i), 0.U(maskBits.W))
  }

  val loadFirstHitCounts = loadFirstHit.map(splitCounts)
  val storeFirstHitCounts = storeFirstHit.map(splitCounts)
  val strictWriteReadHitCounts = strictWriteReadHit.map(splitCounts)
  val unsafeLoadFirstHitCounts = unsafeLoadFirstHit.map(splitCounts)
  val unsafeStoreFirstHitCounts = unsafeStoreFirstHit.map(splitCounts)
  val unsafeStrictWriteReadHitCounts = unsafeStrictWriteReadHit.map(splitCounts)
  val strictOverflowWriteReadHitCounts =
    strictOverflowWriteReadHit.map(splitCounts)
  val unsafeStrictOverflowWriteReadHitCounts =
    unsafeStrictOverflowWriteReadHit.map(splitCounts)

  // Multiple package-table/strict-table ways can qualify on one store/load
  // event (for example, the same line left candidates in several packages).
  // Aggregate each hit by its owning packet slot before updating the bucket;
  // assigning a bucket once avoids last-connect loss in Chisel registers.
  val bucketLoadFirstDelta = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStoreFirstDelta = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStrictWriteReadDelta = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  for (i <- 0 until packetWindow) {
    for (g <- 0 until 4) {
      val loadTerms = (0 until packageWays).map { w =>
        val seq = packageReadData(w).packetSeq
        val idx = seq(packetIndexBits - 1, 0)
        Mux(unsafeLoadFirstHit(w).orR && idx === i.U,
          unsafeLoadFirstHitCounts(w)(g).pad(64), 0.U(64.W))
      }
      val storeTerms = (0 until packageWays).map { w =>
        val seq = packageReadData(w).packetSeq
        val idx = seq(packetIndexBits - 1, 0)
        Mux(unsafeStoreFirstHit(w).orR && idx === i.U,
          unsafeStoreFirstHitCounts(w)(g).pad(64), 0.U(64.W))
      }
      val strictTerms = (0 until strictWays).map { w =>
        val seq = strictReadData(w).packetSeq
        val idx = seq(packetIndexBits - 1, 0)
        Mux(unsafeStrictWriteReadHit(w).orR && idx === i.U,
          unsafeStrictWriteReadHitCounts(w)(g).pad(64), 0.U(64.W))
      } ++ (0 until strictOverflowEntries).map { j =>
        val seq = strictOverflowData(j).packetSeq
        val idx = seq(packetIndexBits - 1, 0)
        Mux(unsafeStrictOverflowWriteReadHit(j).orR && idx === i.U,
          unsafeStrictOverflowWriteReadHitCounts(j)(g).pad(64), 0.U(64.W))
      }
      bucketLoadFirstDelta(i)(g) := loadTerms.reduce(_ + _)
      bucketStoreFirstDelta(i)(g) := storeTerms.reduce(_ + _)
      bucketStrictWriteReadDelta(i)(g) := strictTerms.reduce(_ + _)
    }
  }
  val evictedLoadFirst = Wire(Vec(packageWays, UInt(maskBits.W)))
  val evictedStoreFirst = Wire(Vec(packageWays, UInt(maskBits.W)))
  for (w <- 0 until packageWays) {
    val evicting = !packageFound && packageWayOH(w) &&
      packageReadData(w).sessionTag === sessionTag
    evictedLoadFirst(w) := Mux(evicting,
      packageReadData(w).loadFirst & ~loadFirstHit(w), 0.U(maskBits.W))
    evictedStoreFirst(w) := Mux(evicting,
      packageReadData(w).storeFirst & ~storeFirstHit(w), 0.U(maskBits.W))
  }
  val evictedLoadFirstCounts = evictedLoadFirst.map(splitCounts)
  val evictedStoreFirstCounts = evictedStoreFirst.map(splitCounts)
  val loadFirstHitTotal = Wire(Vec(4, UInt(16.W)))
  val storeFirstHitTotal = Wire(Vec(4, UInt(16.W)))
  val strictWriteReadHitTotal = Wire(Vec(4, UInt(16.W)))
  val unsafeLoadFirstHitTotal = Wire(Vec(4, UInt(16.W)))
  val unsafeStoreFirstHitTotal = Wire(Vec(4, UInt(16.W)))
  val unsafeStrictWriteReadHitTotal = Wire(Vec(4, UInt(16.W)))
  val evictedLoadFirstTotal = Wire(Vec(4, UInt(16.W)))
  val evictedStoreFirstTotal = Wire(Vec(4, UInt(16.W)))
  for (g <- 0 until 4) {
    loadFirstHitTotal(g) := loadFirstHitCounts.map(_(g).pad(16)).reduce(_ + _)
    storeFirstHitTotal(g) := storeFirstHitCounts.map(_(g).pad(16)).reduce(_ + _)
    strictWriteReadHitTotal(g) :=
      (strictWriteReadHitCounts.map(_(g).pad(16)) ++
        strictOverflowWriteReadHit.map(splitCounts).map(_(g).pad(16)))
        .reduce(_ + _)
    unsafeLoadFirstHitTotal(g) :=
      unsafeLoadFirstHitCounts.map(_(g).pad(16)).reduce(_ + _)
    unsafeStoreFirstHitTotal(g) :=
      unsafeStoreFirstHitCounts.map(_(g).pad(16)).reduce(_ + _)
    unsafeStrictWriteReadHitTotal(g) :=
      (unsafeStrictWriteReadHitCounts.map(_(g).pad(16)) ++
        unsafeStrictOverflowWriteReadHit.map(splitCounts).map(_(g).pad(16)))
        .reduce(_ + _)
    evictedLoadFirstTotal(g) :=
      evictedLoadFirstCounts.map(_(g).pad(16)).reduce(_ + _)
    evictedStoreFirstTotal(g) :=
      evictedStoreFirstCounts.map(_(g).pad(16)).reduce(_ + _)
  }

  val currentBucketIdx = processEvent.packetSeq(packetIndexBits - 1, 0)
  val currentBucketCollision = bucketValid(currentBucketIdx) &&
    bucketSeq(currentBucketIdx) =/= processEvent.packetSeq
  val qualifiedPackageBucketError = packageReadData.indices.map { w =>
    val mask = unsafeLoadFirstHit(w) | unsafeStoreFirstHit(w)
    val seq = packageReadData(w).packetSeq
    val idx = seq(packetIndexBits - 1, 0)
    mask.orR && (!bucketValid(idx) || bucketSeq(idx) =/= seq)
  }.reduce(_ || _)
  val qualifiedStrictBucketError = strictReadData.indices.map { w =>
    val mask = unsafeStrictWriteReadHit(w)
    val seq = strictReadData(w).packetSeq
    val idx = seq(packetIndexBits - 1, 0)
    mask.orR && (!bucketValid(idx) || bucketSeq(idx) =/= seq)
  }.reduce(_ || _)
  val qualifiedStrictOverflowBucketError =
    strictOverflowData.indices.map { i =>
      val mask = unsafeStrictOverflowWriteReadHit(i)
      val seq = strictOverflowData(i).packetSeq
      val idx = seq(packetIndexBits - 1, 0)
      mask.orR && (!bucketValid(idx) || bucketSeq(idx) =/= seq)
    }.reduce(_ || _)
  val qualifiedBucketError = qualifiedPackageBucketError ||
    qualifiedStrictBucketError || qualifiedStrictOverflowBucketError

  val processStructuralError = processValid && (
    processMalformed || !packageAvailable || !strictAvailable ||
      currentBucketCollision || qualifiedBucketError)

  val processArithmeticErrorParts = collection.mutable.ArrayBuffer[Bool]()
  for (g <- 0 until 4) {
    val storeDelta = newStoreCounts(g).pad(64)
    val loadFirstLowerDelta = unsafeLoadFirstHitTotal(g).pad(64)
    val loadFirstUpperDelta =
      (loadFirstHitTotal(g) +& evictedLoadFirstTotal(g)).pad(64)
    val storeFirstLowerDelta = unsafeStoreFirstHitTotal(g).pad(64)
    val storeFirstUpperDelta =
      (storeFirstHitTotal(g) +& evictedStoreFirstTotal(g)).pad(64)
    val strictTotalDelta = strictWriteReadHitTotal(g).pad(64)
    val strictOnlineDelta = unsafeStrictWriteReadHitTotal(g).pad(64)
    processArithmeticErrorParts ++= Seq(
      addOverflows(metricStoreTotal(g), storeDelta),
      addOverflows(metricFirstStoreTotal(g), newFirstStoreCounts(g).pad(64)),
      addOverflows(metricLoadFirstLower(g), loadFirstLowerDelta),
      addOverflows(metricLoadFirstUpper(g), loadFirstUpperDelta),
      addOverflows(metricStoreFirstLower(g), storeFirstLowerDelta),
      addOverflows(metricStoreFirstUpper(g), storeFirstUpperDelta),
      addOverflows(metricStrictWriteReadTotal(g), strictTotalDelta),
      addOverflows(onlineStore(g), storeDelta),
      addOverflows(onlineFirstStore(g), newFirstStoreCounts(g).pad(64)),
      addOverflows(onlineLoadFirst(g), loadFirstLowerDelta),
      addOverflows(onlineStoreFirst(g), storeFirstLowerDelta),
      addOverflows(onlineStrictWriteRead(g), strictOnlineDelta),
      addOverflows(Mux(bucketValid(currentBucketIdx),
        bucketStore(currentBucketIdx)(g), 0.U), storeDelta))
    processArithmeticErrorParts += addOverflows(
      Mux(bucketValid(currentBucketIdx),
        bucketFirstStore(currentBucketIdx)(g), 0.U),
      newFirstStoreCounts(g).pad(64))
    for (i <- 0 until packetWindow) {
      processArithmeticErrorParts ++= Seq(
        addOverflows(bucketLoadFirst(i)(g), bucketLoadFirstDelta(i)(g)),
        addOverflows(bucketStoreFirst(i)(g), bucketStoreFirstDelta(i)(g)),
        addOverflows(bucketStrictWriteRead(i)(g),
          bucketStrictWriteReadDelta(i)(g)))
    }
  }
  val processArithmeticError = processValid &&
    processArithmeticErrorParts.reduce(_ || _)
  val processCommit = processValid && !processStructuralError &&
    !processArithmeticError && !io.fatalProtocolError

  // Safe-watermark retirement is serialized before the next event whose
  // captured watermark has advanced.  This preserves event-time membership.
  val safeTarget = Mux(queueCount =/= 0.U,
    queueHead.safeWatermark, io.safeWatermark)
  val safeAdvance = drainingWindow && !processValid &&
    processedSafeWatermark < safeTarget
  val retiringSeq = processedSafeWatermark + 1.U
  val retiringIdx = retiringSeq(packetIndexBits - 1, 0)
  val retiringSlotCollision = safeAdvance && bucketValid(retiringIdx) &&
    bucketSeq(retiringIdx) =/= retiringSeq
  val retiringUnderflow = safeAdvance && bucketValid(retiringIdx) &&
    (0 until 4).map { g =>
      bucketStore(retiringIdx)(g) > onlineStore(g) ||
      bucketFirstStore(retiringIdx)(g) > onlineFirstStore(g) ||
      bucketLoadFirst(retiringIdx)(g) > onlineLoadFirst(g) ||
      bucketStoreFirst(retiringIdx)(g) > onlineStoreFirst(g) ||
      bucketStrictWriteRead(retiringIdx)(g) > onlineStrictWriteRead(g)
    }.reduce(_ || _)
  val safeError = retiringSlotCollision || retiringUnderflow

  val headLineTag = queueHead.addr(addrBits - 1, blockOffBits)
  val headPackageSet = packageSetOf(headLineTag)
  val processSetHazard = processValid &&
    headPackageSet === processPackageSet

  val incomingCount = PopCount(io.events.map(_.valid))
  val issueReadCandidate = drainingWindow && queueCount =/= 0.U && !safeAdvance &&
    queueHead.safeWatermark <= processedSafeWatermark &&
    !processSetHazard && !processStructuralError &&
    !processArithmeticError && !safeError &&
    !io.fatalProtocolError
  val queueWouldOverflow = acceptingWindow && incomingCount =/= 0.U &&
    queueCount +& incomingCount > queueDepth.U + issueReadCandidate.asUInt
  val issueRead = issueReadCandidate && !queueWouldOverflow
  val acceptIncoming = acceptingWindow && !queueWouldOverflow && !safeError &&
    !processStructuralError && !processArithmeticError &&
    !io.fatalProtocolError

  for (lane <- 0 until commitWidth) {
    val before = if (lane == 0) 0.U else
      PopCount(VecInit(io.events.take(lane).map(_.valid)))
    val writeIndex = (enqPtr + before)(queueIndexBits - 1, 0)
    when (acceptIncoming && io.events(lane).valid) {
      queue(writeIndex).addr := io.events(lane).bits.addr
      queue(writeIndex).size := io.events(lane).bits.size
      queue(writeIndex).isStore := io.events(lane).bits.isStore
      queue(writeIndex).packetSeq := io.events(lane).bits.packetSeq
      queue(writeIndex).safeWatermark := io.safeWatermark
    }
  }

  for (w <- 0 until packageWays) {
    packageReadData(w) := packageMem(w).read(headPackageSet, issueRead)
  }
  for (w <- 0 until strictWays) {
    strictReadData(w) := strictMem(w).read(headPackageSet, issueRead)
  }

  when (processCommit) {
    val allocatingPackage = !packageFound
    for (w <- 0 until packageWays) {
      val isCurrent = packageWayOH(w)
      val old = packageReadData(w)
      val baseSeen = Mux(isCurrent && allocatingPackage, 0.U, old.seen)
      val baseStoreSeen = Mux(isCurrent && allocatingPackage, 0.U, old.storeSeen)
      val baseLoadFirst = Mux(isCurrent && allocatingPackage, 0.U, old.loadFirst)
      val baseStoreFirst = Mux(isCurrent && allocatingPackage, 0.U,
        old.storeFirst)
      val next = Wire(new PackageAddressLineState(lineTagBits, maskBits))
      next := old
      when (isCurrent) {
        next.sessionTag := sessionTag
        next.packetSeq := processEvent.packetSeq
        next.lineTag := processLineTag
        next.seen := baseSeen | processTouch
        next.storeSeen := baseStoreSeen | Mux(
          processEvent.isStore, processTouch, 0.U)
        next.loadFirst := (baseLoadFirst & ~loadFirstHit(w)) |
          newLoadFirstMask
        next.storeFirst := (baseStoreFirst & ~storeFirstHit(w)) |
          newStoreFirstMask
      }.otherwise {
        next.loadFirst := old.loadFirst & ~loadFirstHit(w)
        next.storeFirst := old.storeFirst & ~storeFirstHit(w)
      }
      when (isCurrent || loadFirstHit(w).orR || storeFirstHit(w).orR) {
        packageMem(w).write(processPackageSet, next)
      }
    }

    for (w <- 0 until strictWays) {
      val old = strictReadData(w)
      val sameLine = old.sessionTag === sessionTag &&
        old.lineTag === processLineTag
      val strictInvalidated = Mux(sameLine,
        processTouch & old.strictStoreFirst, 0.U(maskBits.W))
      val next = Wire(new StrictPackageLineState(lineTagBits, maskBits))
      next := old
      val isCurrent = strictUsePrimary && strictWayOH(w)
      when (isCurrent) {
        next.sessionTag := sessionTag
        next.packetSeq := processEvent.packetSeq
        next.lineTag := processLineTag
        next.strictStoreFirst :=
          (Mux(strictFound, old.strictStoreFirst, 0.U(maskBits.W)) &
            ~strictInvalidated) | newStoreFirstMask
      }.otherwise {
        next.strictStoreFirst := old.strictStoreFirst & ~strictInvalidated
      }
      when (isCurrent || strictInvalidated.orR) {
        strictMem(w).write(processPackageSet, next)
      }
    }
    for (i <- 0 until strictOverflowEntries) {
      val old = strictOverflowData(i)
      val sameLine = strictOverflowValid(i) &&
        old.sessionTag === sessionTag && old.lineTag === processLineTag
      val strictInvalidated = Mux(sameLine,
        processTouch & old.strictStoreFirst, 0.U(maskBits.W))
      val next = Wire(new StrictPackageLineState(lineTagBits, maskBits))
      next := old
      val isCurrent = strictUseOverflow && strictOverflowWayOH(i)
      when (isCurrent) {
        next.sessionTag := sessionTag
        next.packetSeq := processEvent.packetSeq
        next.lineTag := processLineTag
        next.strictStoreFirst :=
          (Mux(strictOverflowFound, old.strictStoreFirst,
            0.U(maskBits.W)) & ~strictInvalidated) | newStoreFirstMask
        strictOverflowValid(i) := true.B
      }.otherwise {
        next.strictStoreFirst := old.strictStoreFirst & ~strictInvalidated
        when (strictInvalidated.orR &&
            (old.strictStoreFirst & ~strictInvalidated) === 0.U) {
          strictOverflowValid(i) := false.B
        }
      }
      when (isCurrent || strictInvalidated.orR) {
        strictOverflowData(i) := next
      }
    }

    for (i <- 0 until packetWindow) {
      val isCurrent = currentBucketIdx === i.U
      when (isCurrent) {
        bucketValid(i) := true.B
        bucketSeq(i) := processEvent.packetSeq
      }
      for (g <- 0 until 4) {
        when (isCurrent) {
          val baseStore = Mux(bucketValid(i), bucketStore(i)(g), 0.U)
          val baseFirstStore = Mux(bucketValid(i), bucketFirstStore(i)(g), 0.U)
          val baseLoadFirst = Mux(bucketValid(i), bucketLoadFirst(i)(g), 0.U)
          val baseStoreFirst = Mux(bucketValid(i), bucketStoreFirst(i)(g), 0.U)
          val baseStrict = Mux(bucketValid(i),
            bucketStrictWriteRead(i)(g), 0.U)
          bucketStore(i)(g) := baseStore + newStoreCounts(g)
          bucketFirstStore(i)(g) := baseFirstStore + newFirstStoreCounts(g)
          bucketLoadFirst(i)(g) := baseLoadFirst + bucketLoadFirstDelta(i)(g)
          bucketStoreFirst(i)(g) := baseStoreFirst + bucketStoreFirstDelta(i)(g)
          bucketStrictWriteRead(i)(g) := baseStrict +
            bucketStrictWriteReadDelta(i)(g)
        }.otherwise {
          when (bucketLoadFirstDelta(i)(g) =/= 0.U) {
            bucketLoadFirst(i)(g) := bucketLoadFirst(i)(g) +
              bucketLoadFirstDelta(i)(g)
          }
          when (bucketStoreFirstDelta(i)(g) =/= 0.U) {
            bucketStoreFirst(i)(g) := bucketStoreFirst(i)(g) +
              bucketStoreFirstDelta(i)(g)
          }
          when (bucketStrictWriteReadDelta(i)(g) =/= 0.U) {
            bucketStrictWriteRead(i)(g) := bucketStrictWriteRead(i)(g) +
              bucketStrictWriteReadDelta(i)(g)
          }
        }
      }
    }

    for (g <- 0 until 4) {
      val storeDelta = newStoreCounts(g).pad(64)
      val loadFirstLowerDelta = unsafeLoadFirstHitTotal(g).pad(64)
      val loadFirstUpperDelta =
        (loadFirstHitTotal(g) +& evictedLoadFirstTotal(g)).pad(64)
      val storeFirstLowerDelta = unsafeStoreFirstHitTotal(g).pad(64)
      val storeFirstUpperDelta =
        (storeFirstHitTotal(g) +& evictedStoreFirstTotal(g)).pad(64)
      val strictTotalDelta = strictWriteReadHitTotal(g).pad(64)
      val strictOnlineDelta = unsafeStrictWriteReadHitTotal(g).pad(64)
      val firstStoreDelta = newFirstStoreCounts(g).pad(64)
      val nextOnlineStore = onlineStore(g) + storeDelta
      val nextOnlineFirstStore = onlineFirstStore(g) + firstStoreDelta
      val nextOnlineLoadFirst = onlineLoadFirst(g) + loadFirstLowerDelta
      val nextOnlineStoreFirst = onlineStoreFirst(g) + storeFirstLowerDelta
      val nextOnlineStrictWriteRead =
        onlineStrictWriteRead(g) + strictOnlineDelta

      metricStoreTotal(g) := metricStoreTotal(g) + storeDelta
      metricFirstStoreTotal(g) := metricFirstStoreTotal(g) + firstStoreDelta
      metricLoadFirstLower(g) :=
        metricLoadFirstLower(g) + loadFirstLowerDelta
      metricLoadFirstUpper(g) :=
        metricLoadFirstUpper(g) + loadFirstUpperDelta
      metricStoreFirstLower(g) :=
        metricStoreFirstLower(g) + storeFirstLowerDelta
      metricStoreFirstUpper(g) :=
        metricStoreFirstUpper(g) + storeFirstUpperDelta
      metricStrictWriteReadTotal(g) :=
        metricStrictWriteReadTotal(g) + strictTotalDelta
      onlineStore(g) := nextOnlineStore
      onlineFirstStore(g) := nextOnlineFirstStore
      onlineLoadFirst(g) := nextOnlineLoadFirst
      onlineStoreFirst(g) := nextOnlineStoreFirst
      onlineStrictWriteRead(g) := nextOnlineStrictWriteRead
      when (nextOnlineStore > metricStorePeak(g)) {
        metricStorePeak(g) := nextOnlineStore
      }
      when (nextOnlineFirstStore > metricFirstStorePeak(g)) {
        metricFirstStorePeak(g) := nextOnlineFirstStore
      }
      when (nextOnlineLoadFirst > metricLoadFirstPeak(g)) {
        metricLoadFirstPeak(g) := nextOnlineLoadFirst
      }
      when (nextOnlineStoreFirst > metricStoreFirstPeak(g)) {
        metricStoreFirstPeak(g) := nextOnlineStoreFirst
      }
      when (nextOnlineStrictWriteRead > metricStrictWriteReadPeak(g)) {
        metricStrictWriteReadPeak(g) := nextOnlineStrictWriteRead
      }
    }
  }

  when (safeAdvance && !safeError) {
    processedSafeWatermark := retiringSeq
    when (bucketValid(retiringIdx)) {
      bucketValid(retiringIdx) := false.B
      for (g <- 0 until 4) {
        onlineStore(g) := onlineStore(g) - bucketStore(retiringIdx)(g)
        onlineFirstStore(g) := onlineFirstStore(g) -
          bucketFirstStore(retiringIdx)(g)
        onlineLoadFirst(g) :=
          onlineLoadFirst(g) - bucketLoadFirst(retiringIdx)(g)
        onlineStoreFirst(g) :=
          onlineStoreFirst(g) - bucketStoreFirst(retiringIdx)(g)
        onlineStrictWriteRead(g) := onlineStrictWriteRead(g) -
          bucketStrictWriteRead(retiringIdx)(g)
        bucketStore(retiringIdx)(g) := 0.U
        bucketFirstStore(retiringIdx)(g) := 0.U
        bucketLoadFirst(retiringIdx)(g) := 0.U
        bucketStoreFirst(retiringIdx)(g) := 0.U
        bucketStrictWriteRead(retiringIdx)(g) := 0.U
      }
    }
  }

  val packageTableFull = processValid &&
    (!packageAvailable || !strictAvailable)
  val packetSlotError = processValid &&
    (currentBucketCollision || qualifiedBucketError) || retiringSlotCollision
  val malformedEvent = processValid && processMalformed
  val arithmeticError = processArithmeticError || retiringUnderflow
  val localError =
    (queueWouldOverflow.asUInt << errQueueOverflow) |
    (packageTableFull.asUInt << errPackageTableFull) |
    (packetSlotError.asUInt << errPacketSlot) |
    (malformedEvent.asUInt << errMalformedEvent) |
    (arithmeticError.asUInt << errArithmetic) |
    (io.fatalProtocolError.asUInt << errProtocol)
  val stopWithError = localError.orR

  when (io.resetStats) {
    running := false.B
    statsValid := true.B
    errorReg := 0.U
    processedSafeWatermark := io.sequenceBaseline
    enqPtr := 0.U
    deqPtr := 0.U
    queueCount := 0.U
    processValid := false.B
    sessionTag := sessionTag + 1.U
    for (i <- 0 until strictOverflowEntries) {
      strictOverflowValid(i) := false.B
      strictOverflowData(i) := 0.U.asTypeOf(
        new StrictPackageLineState(lineTagBits, maskBits))
    }
    for (i <- 0 until packetWindow) {
      bucketValid(i) := false.B
      bucketSeq(i) := 0.U
      for (g <- 0 until 4) {
        bucketStore(i)(g) := 0.U
        bucketFirstStore(i)(g) := 0.U
        bucketLoadFirst(i)(g) := 0.U
        bucketStoreFirst(i)(g) := 0.U
        bucketStrictWriteRead(i)(g) := 0.U
      }
    }
    for (g <- 0 until 4) {
      metricStoreTotal(g) := 0.U
      metricStorePeak(g) := 0.U
      metricFirstStoreTotal(g) := 0.U
      metricFirstStorePeak(g) := 0.U
      metricLoadFirstLower(g) := 0.U
      metricLoadFirstUpper(g) := 0.U
      metricLoadFirstPeak(g) := 0.U
      metricStoreFirstLower(g) := 0.U
      metricStoreFirstUpper(g) := 0.U
      metricStoreFirstPeak(g) := 0.U
      metricStrictWriteReadTotal(g) := 0.U
      metricStrictWriteReadPeak(g) := 0.U
      onlineStore(g) := 0.U
      onlineFirstStore(g) := 0.U
      onlineLoadFirst(g) := 0.U
      onlineStoreFirst(g) := 0.U
      onlineStrictWriteRead(g) := 0.U
    }
  }.elsewhen (stopWithError) {
    running := false.B
    statsValid := false.B
    errorReg := errorReg | localError
    queueCount := 0.U
    processValid := false.B
  }.otherwise {
    when (io.start) { running := true.B }
    when (io.stop) { running := false.B }
    processValid := issueRead
    when (issueRead) {
      processEvent := queueHead
      deqPtr := deqPtr + 1.U
    }
    when (acceptIncoming && incomingCount =/= 0.U) {
      enqPtr := enqPtr + incomingCount
    }
    queueCount := queueCount +
      Mux(acceptIncoming, incomingCount, 0.U) - issueRead.asUInt
  }

  for (g <- 0 until 4) {
    val base = g * GH_GlobalParams.GH_ADDRESS_STATS_PER_GRANULE
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STORE_TOTAL) :=
      metricStoreTotal(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STORE_PEAK) :=
      metricStorePeak(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_LOAD_FIRST_LOWER) :=
      metricLoadFirstLower(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_LOAD_FIRST_UPPER) :=
      metricLoadFirstUpper(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_LOAD_FIRST_PEAK) :=
      metricLoadFirstPeak(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STORE_FIRST_LOWER) :=
      metricStoreFirstLower(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STORE_FIRST_UPPER) :=
      metricStoreFirstUpper(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STORE_FIRST_PEAK) :=
      metricStoreFirstPeak(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STRICT_WRITE_READ_TOTAL) :=
      metricStrictWriteReadTotal(g)
    io.counters(base + GH_GlobalParams.GH_ADDRESS_STAT_STRICT_WRITE_READ_PEAK) :=
      metricStrictWriteReadPeak(g)
    val firstStoreBase = g * GH_GlobalParams.GH_ADDRESS_FIRST_STORE_STRIDE
    io.firstStoreCounters(firstStoreBase +
      GH_GlobalParams.GH_ADDRESS_FIRST_STORE_TOTAL) :=
      metricFirstStoreTotal(g)
    io.firstStoreCounters(firstStoreBase +
      GH_GlobalParams.GH_ADDRESS_FIRST_STORE_PEAK) :=
      metricFirstStorePeak(g)
  }
  // Export a newly detected failure combinationally as well as latching it.
  // This keeps a STOP snapshot on the same edge from recording stale success.
  io.statsValid := statsValid && !stopWithError
  io.error := errorReg | localError
  io.pending := queueCount.pad(64) + processValid.asUInt +
    (processedSafeWatermark =/= io.safeWatermark).asUInt
  io.idle := !running && queueCount === 0.U && !processValid &&
    processedSafeWatermark === io.safeWatermark
}
