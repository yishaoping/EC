#!/usr/bin/env python3
"""Software-only boot diagnostic; separate source/output; not a performance image."""
import datetime as dt,difflib,hashlib,json,os,shutil,subprocess,time
from pathlib import Path
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');E=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
 stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'software/Native/builds'/('Native-boot-diagnostic-'+stamp);logs=D/'system-builds'/out.name;logs.mkdir()
 parent=W/'software/Native/earlyconsole-kernel-build.json';r=json.loads(parent.read_text());old=Path(r['output_dir']);shutil.copytree(old,out,symlinks=True)
 source=out/'diagnostic-memset.S';original=Path(r['source_tree'])/'arch/riscv/lib/memset.S';before=original.read_text()
 regs=['ra','a0','a1','a2','a3','a4','a5','a6','a7','t0','t1','t2','t3','t4','t5','t6']
 pre='\tli a3, 1048576\n\tbltu a2,a3,88f\n\taddi sp,sp,-128\n'+''.join(f'\tsd {reg},{8*i}(sp)\n' for i,reg in enumerate(regs))
 for label,reg,offset in [('ra','ra',0),('dst','a0',8),('bytes','a2',24)]:
  for c in 'EC_MEMSET '+label+'=' if label=='ra' else ' '+label+'=':pre+=f'\tli a0,{ord(c)}\n\tli a7,1\n\tecall\n'
  pre+=f'\tld t1,{offset}(sp)\n\tli t0,60\n77:\n\tsrl t2,t1,t0\n\tandi t2,t2,15\n\tli a0,48\n\tadd a0,a0,t2\n\tli t3,10\n\tbltu t2,t3,76f\n\taddi a0,a0,39\n76:\n\tli a7,1\n\tecall\n\taddi t0,t0,-4\n\tbgez t0,77b\n'
 pre+='\tli a0,10\n\tli a7,1\n\tecall\n'+''.join(f'\tld {reg},{8*i}(sp)\n' for i,reg in enumerate(regs))+'\taddi sp,sp,128\n88:\n'
 text=before.replace('WEAK(memset)\n','WEAK(memset)\n'+pre);source.write_text(text)
 (logs/'memset-diagnostic.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),text.splitlines(True),fromfile=str(original),tofile=str(source))))
 previous=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/system-builds')/old.name/'build.log'
 # Recover the exact assembler invocation from the kernel-generated .cmd.
 cmdfile=out/'arch/riscv/lib/.memset.o.cmd';line=next(x for x in cmdfile.read_text().splitlines() if x.startswith('cmd_') and ':=' in x)
 command=line.split(':=',1)[1].strip().replace(str(old),str(out)).replace(' -c -o ', ' -c -o ')
 command=command.replace(str(original),str(source))
 # Kbuild command uses an absolute source path, as verified above.
 assert str(source) in command
 env=os.environ.copy();env.update(PATH=str(E/'bin')+':'+str(E/'riscv-tools/bin')+':/usr/bin:/bin',MAKEFLAGS='-j2');env.pop('LD_LIBRARY_PATH',None)
 commands=[]
 with (logs/'build.log').open('wb',buffering=0) as f:
  commands.append(command);subprocess.run(command,cwd=out,shell=True,executable='/bin/bash',env=env,stdout=f,stderr=subprocess.STDOUT,check=True,timeout=120)
  # Keep the custom object newer than its inputs; make must not replace it.
  assert source.stat().st_mtime <= (out/'arch/riscv/lib/memset.o').stat().st_mtime
  argv=['nice','-n','15','make','-j2','O='+str(out),'ARCH=riscv','CROSS_COMPILE='+str(E/'riscv-tools/bin/riscv64-unknown-linux-gnu-'),'HOSTCC=/usr/bin/gcc','Image','vmlinux']
  commands.append(argv);subprocess.run(argv,cwd=r['source_tree'],env=env,stdout=f,stderr=subprocess.STDOUT,check=True,timeout=600)
 rr={**r,'output_dir':str(out),'outputs':{str(out/p):sha(out/p) for p in ['vmlinux','arch/riscv/boot/Image','.config','drivers/misc/ec_dac_roi.o']},'commands':commands,'diagnostic_only':True,'formal_eligible':False,'memset_diagnostic_source':str(source),'memset_diagnostic_sha256':sha(source)}
 (logs/'result.json').write_text(json.dumps(rr,indent=2)+'\n');(W/'software/Native/boot-diagnostic-kernel.json').write_text(json.dumps(rr,indent=2)+'\n');print(logs/'result.json',flush=True)
if __name__=='__main__':main()
