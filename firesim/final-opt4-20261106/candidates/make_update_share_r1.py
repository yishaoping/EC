#!/usr/bin/python3
from pathlib import Path
import ast,json,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106'); F=W/'Opt4-fit-address-update-share-r1-20261111'; C=W/'candidates/address-update-share-r1-20261111'; C.mkdir(exist_ok=True)
R=Path('chipyard/generators/boom/src/main/scala/lsu'); p=F/R/'PackageAddressStats.scala'; old=p.read_text()
s=old.replace('''    currentStoreNextWide(g) := Mux(bucketValid(currentBucketIdx),
      bucketStore(currentBucketIdx)(g), 0.U(64.W)) +& newStoreCounts(g).pad(64)
    currentFirstStoreNextWide(g) := Mux(bucketValid(currentBucketIdx),
      bucketFirstStore(currentBucketIdx)(g), 0.U(64.W)) +& newFirstStoreCounts(g).pad(64)''','''    currentStoreNextWide(g) := bucketStore(currentBucketIdx)(g) +& newStoreCounts(g).pad(64)
    currentFirstStoreNextWide(g) := bucketFirstStore(currentBucketIdx)(g) +& newFirstStoreCounts(g).pad(64)''')
a=s.index('''          bucketLoadFirst(i)(g) := Mux(bucketValid(i),''',s.index('    for (i <- 0 until packetWindow) {',s.index('  when (processCommit)')))
b=s.index('\n      }\n    }\n\n    for (g <- 0 until 4)',a)
s=s[:a]+'''        }
        // Invalid slots have zero payload after reset/retirement. The same
        // exact sum therefore handles allocation and a qualified delta hit.
        when (AddressBucketUpdate.enabled(isCurrent, bucketLoadFirstDelta(i)(g))) {
          bucketLoadFirst(i)(g) := loadFirstNextWide(i)(g)(63, 0)
        }
        when (AddressBucketUpdate.enabled(isCurrent, bucketStoreFirstDelta(i)(g))) {
          bucketStoreFirst(i)(g) := storeFirstNextWide(i)(g)(63, 0)
        }
        when (AddressBucketUpdate.enabled(isCurrent, bucketStrictWriteReadDelta(i)(g))) {
          bucketStrictWriteRead(i)(g) := strictWriteReadNextWide(i)(g)(63, 0)
        }'''+s[b:]
assert s!=old and 'currentStoreNextWide(g) := bucketStore' in s
p.write_text(s)
(F/R/'AddressBucketUpdate.scala').write_text('''package boom.lsu

import chisel3._
import chisel3.util._

/** Counter state remains 64 bits; allocation and delta hits share the update. */
object AddressBucketUpdate {
  def enabled(current: Bool, delta: UInt): Bool = current || delta.orR
}
''')
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Independent candidate sharing allocation and delta counter update under invalid-zero invariant.',branch='opt4/address-update-share-r1-20261111',source_tree=str(F/'chipyard'));(F/'lineage.json').write_text(json.dumps(line,indent=2)+'\n')
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',str(R/'PackageAddressStats.scala'),str(R/'AddressBucketUpdate.scala'),'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Share exact bucket allocation and delta update under zero invariant'],cwd=F,check=True)
print(subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip())
