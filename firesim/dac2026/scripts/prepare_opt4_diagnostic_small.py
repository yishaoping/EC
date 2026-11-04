#!/usr/bin/env python3
"""Independent small native rootfs. Strip debug bytes; prove PT_LOAD unchanged."""
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
from build_minimal import ROOT, ENV, sha
from prepare_boot_prerequisite import cpio_newc

WORK=ROOT/'firesim/dac2026/work/opt4-linux-v6'

def loads(path):
    b=bytearray(path.read_bytes());assert b[:6]==b'\x7fELF\x02\x01'
    # strip-debug updates only ELF section-table metadata within the first
    # PT_LOAD's file header. Loader program headers, entry and runtime bytes
    # must be identical after normalizing those non-executable header fields.
    b[40:48]=bytes(8) # e_shoff
    b[58:64]=bytes(6) # e_shentsize, e_shnum, e_shstrndx
    entry,po=struct.unpack_from('<QQ',b,24);pe,pn=struct.unpack_from('<HH',b,54)
    result=[]
    for i in range(pn):
        t,flags,off,va,pa,fs,ms,al=struct.unpack_from('<IIQQQQQQ',b,po+i*pe)
        if t==1:result.append((flags,va,pa,fs,ms,al,b[off:off+fs]))
    return entry,result

def save(path,value):path.write_text(json.dumps(value,indent=2)+'\n')

def main():
    apps=json.loads((WORK/'apps-build.json').read_text())
    root=json.loads((WORK/'native-htif/rootfs-build.json').read_text())
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out=ROOT/'firesim/dac2026/images/opt4-linux-v6/diagnostic36-small'/stamp
    out.mkdir(parents=True)
    appout=out/'apps';appout.mkdir()
    parent=Path(apps['output']);audit={}
    tool=ENV/'riscv-tools/bin/riscv64-unknown-linux-gnu-strip'
    for name,digest in apps['binaries'].items():
        assert sha(parent/name)==digest
        shutil.copy2(parent/name,appout/name)
        subprocess.run([str(tool),'--strip-debug',str(appout/name)],check=True)
        assert loads(parent/name)==loads(appout/name),name
        audit[name]={'parent_sha256':digest,'stripped_sha256':sha(appout/name),
            'parent_bytes':(parent/name).stat().st_size,'stripped_bytes':(appout/name).stat().st_size,
            'entry_program_headers_and_runtime_load_bytes_identical':True,
            'ELF_header_metadata_normalized':['e_shoff','e_shentsize','e_shnum','e_shstrndx']}
    shutil.copytree(parent/'inputs',appout/'inputs')
    modified={**apps,'output':str(appout),'output_dir':str(appout),
        'binaries':{n:sha(appout/n) for n in apps['binaries']},
        'parent_apps_receipt':str(WORK/'apps-build.json'),
        'parent_apps_receipt_sha256':sha(WORK/'apps-build.json'),
        'diagnostic_transform':'strip-debug only; all loadable bytes and entry identical',
        'elf_equivalence':audit,'slowdown_eligible':False}
    save(appout/'manifest.json',modified)
    tree=out/'rootfs'
    shutil.copytree(Path(root['output_dir'])/'rootfs',tree,symlinks=True)
    dst=tree/'opt/ec-dac'
    for name in apps['binaries']:shutil.copy2(appout/name,dst/name)
    bb=tree/'bin/busybox';before=loads(bb)
    subprocess.run([str(tool),'--strip-debug',str(bb)],check=True)
    assert loads(bb)==before
    (dst/'BUILD.json').write_bytes((appout/'manifest.json').read_bytes())
    sums=''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file() and p.name!='SHA256SUMS')
    (dst/'SHA256SUMS').write_text(sums)
    cpio_newc(tree,out/'initramfs.cpio')
    record={**root,'configuration':'C4-v6-diagnostic36-small','initramfs':str(out/'initramfs.cpio'),
        'sha256':sha(out/'initramfs.cpio'),'output_dir':str(out),
        'apps_manifest':str(appout/'manifest.json'),'apps_manifest_sha256':sha(appout/'manifest.json'),
        'image_application_files':{str(p.relative_to(tree)):sha(p) for p in sorted(dst.rglob('*')) if p.is_file()},
        'slowdown_eligible':False,'linux_memory_limit_mib':32,'ELF_PT_LOAD_equivalence':True,
        'parent_rootfs_receipt':str(WORK/'native-htif/rootfs-build.json'),
        'parent_rootfs_receipt_sha256':sha(WORK/'native-htif/rootfs-build.json')}
    save(out/'rootfs-result.json',record)
    w=WORK/'diagnostic36-small';w.mkdir(exist_ok=True)
    save(w/'apps-build.json',modified);save(w/'rootfs-build.json',record)
    print(json.dumps({'rootfs':str(out/'initramfs.cpio'),'bytes':(out/'initramfs.cpio').stat().st_size,'apps':audit},indent=2))

if __name__=='__main__':main()
