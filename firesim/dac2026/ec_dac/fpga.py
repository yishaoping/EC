"""Import deployment utilization only; never infer ASIC area from these counts."""
from pathlib import Path
import csv
import re
from .common import atomic_json, filehash, require, name

ALIASES={"CLB LUTs":"LUT","Slice LUTs":"LUT","CLB Registers":"FF","Slice Registers":"FF",
         "Block RAM Tile":"BRAM_tiles","DSPs":"DSP","DSP48E2":"DSP","DSP48E1":"DSP"}

def parse_utilization(text):
    result={}
    for line in text.splitlines():
        if not line.strip().startswith("|"):
            continue
        parts=[v.strip() for v in line.strip().strip("|").split("|")]
        if len(parts)<2:continue
        label=parts[0].rstrip("* ")
        if label not in ALIASES:continue
        raw=parts[1].replace(",","")
        require(re.fullmatch(r"\d+(?:\.\d+)?",raw) is not None,"invalid Vivado used count: "+line)
        count=float(raw) if "." in raw else int(raw)
        key=ALIASES[label]
        require(key not in result or result[key]==count,"conflicting utilization totals for "+key)
        result[key]=count
    require(set(result)=={"LUT","FF","BRAM_tiles","DSP"},"missing full LUT/FF/BRAM/DSP totals; supply report_utilization output")
    return result

def import_fpga(config_id, report, rtl_manifest, output):
    name(config_id)
    report,rtl_manifest=Path(report).resolve(),Path(rtl_manifest).resolve()
    resources=parse_utilization(report.read_text())
    out=Path(output).resolve();out.mkdir(parents=True,exist_ok=False)
    result={"configuration":config_id,"kind":"FPGA deployment resources; NOT ASIC area",
            "report":str(report),"report_sha256":filehash(report),
            "target_manifest":str(rtl_manifest),"target_manifest_sha256":filehash(rtl_manifest),
            "resources":resources,"timing_verified":False,
            "note":"BRAM unit is Vivado Block RAM Tile (may be fractional); no conversion to ASIC area or timing signoff."}
    atomic_json(out/"fpga-resources.json",result,replace=False)
    with open(out/"fpga-resources.csv","x",newline="") as f:
        writer=csv.writer(f);writer.writerow(["configuration","resource","used","kind"])
        for k,v in resources.items():writer.writerow([config_id,k,v,"FPGA_ONLY"])
    return result
