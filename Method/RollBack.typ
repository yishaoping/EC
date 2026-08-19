

= Cache
== Paper
复制每次写入的旧值，扩展原有的LSL。
保留 VA 在回滚时候进行翻译。
Timestamp 用于检查是否已校验。

We therefore take a copy of the old value of each word written to the L1 cache and record it in the load-store log, so as to provide the ability to undo stores.
We do this for every write, extending the amount of data stored per write compared to error detection alone.
The data fields recorded for each load and store are shown in figure 2.
We also add a dedicated load/store bit, for the unroller to determine which log segments are loads or stores, which the detection mechanism infers from the instruction stream.
On detection of an error, these writes are then rolled back by walking the log in reverse order, and writing the old values back to the cache.
The virtual addresses in the load-store log are retranslated by the TLB upon a rollback, moving the translation to the uncommon, rather than the common case, as translation does not need to be performed for correct segments.
== Mine
分析我下面的这三点优化，检查是否存在问题
- Undo Log
将新的Undo Log与LSL分离。不会占用LSL有限容量，使得检验完成可以及时扔掉。
- Read-before-Write
只保存使用且修改的data，如amo。减少了数据量
- First-write compression
在seg内部进行数据压缩，只保留同一粒度最旧的数据。减少了数据量
segment-local 只能在seg内部进行，因为这是回滚的最小单位。
byte-enable merge store存在不同的粒度，按粒度进行保留。
- 缓存行压缩
