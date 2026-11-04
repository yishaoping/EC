"""Pure host-side FASED argument binding checks; no driver is opened."""
import copy
from pathlib import Path
import tempfile
import unittest
from ec_dac.common import atomic_json, filehash
from ec_dac.safety import checked_memory_runtime


def fixture(path, limit=4):
    settings={"readLatency":30,"writeLatency":30,"readMaxReqs":limit,"writeMaxReqs":limit,"relaxFunctionalModel":0}
    args=[f"+mm_{k}_0={v}" for k,v in sorted(settings.items())]
    (path/"fased-common.args").write_text(" ".join(args)+"\n")
    memory={"schema":"ec-dac-memory/1","model":"LatencyBandwidthPipe","model_index":0,
            "static_register_audit":"PASSED","settings":settings,"plusargs":args,"boom_uncore_mhz":200,
            "arguments_sha256":filehash(path/"fased-common.args"),
            "evidence":{cid:{"generated_reset_defaults":{"readMaxReqs":n,"writeMaxReqs":n}} for cid,n in (("B",4),("C4",6))}}
    atomic_json(path/"manifest.json",memory)
    return {"memory_runtime":{"path":str(path/"manifest.json"),"sha256":filehash(path/"manifest.json")}}


class MemoryRuntimeTests(unittest.TestCase):
    def test_common_arguments_bound_to_manifest_and_frequency(self):
        with tempfile.TemporaryDirectory() as t:
            p=Path(t);site=fixture(p)
            common={"memory_runtime_manifest_sha256":site["memory_runtime"]["sha256"],"boom_mhz":200,"uncore_mhz":200}
            self.assertEqual(checked_memory_runtime(site,common),str(p/"manifest.json"))
            changed=copy.deepcopy(common);changed["uncore_mhz"]=100
            with self.assertRaisesRegex(ValueError,"frequency"):checked_memory_runtime(site,changed)
            changed=copy.deepcopy(common);changed["memory_runtime_manifest_sha256"]="0"*64
            with self.assertRaisesRegex(ValueError,"different FASED"):checked_memory_runtime(site,changed)
            (p/"fased-common.args").write_text("+mm_useHardwareDefaultRuntimeSettings_0\n")
            with self.assertRaisesRegex(ValueError,"argument file changed"):checked_memory_runtime(site,common)

    def test_C4_default_cannot_exceed_baseline_common_range(self):
        with tempfile.TemporaryDirectory() as t:
            site=fixture(Path(t),limit=6)
            with self.assertRaisesRegex(ValueError,"common range"):checked_memory_runtime(site)


if __name__=="__main__":unittest.main()
