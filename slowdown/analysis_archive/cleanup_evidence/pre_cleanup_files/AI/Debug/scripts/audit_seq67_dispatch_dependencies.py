#!/usr/bin/env python3
"""Read an EXISTING FIRRTL artifact and audit the reported Rocket/CSR loop.

No Chisel elaboration, FIRRTL compiler, RTL generation, or simulator is invoked.
The corrected cone substitutes one dependency in memory, matching the source
edit. This is a scoped structural audit, not a new full FIRRTL compiler PASS.
"""
import argparse
from collections import defaultdict, deque
import hashlib
import json
from pathlib import Path
import re

REF = re.compile(r'[A-Za-z_$][\w$]*(?:(?:\[\d+\])|(?:\.[A-Za-z_$][\w$]*))*')
MODULE = re.compile(r'^  module (\S+) :')


def refs(expr):
    expr=re.sub(r'"(?:\\.|[^"\\])*"','',expr.split('@[')[0])
    result=set()
    for m in REF.finditer(expr):
        if m.group() in {'UInt','SInt','Clock','AsyncReset','Reset'}:continue
        if expr[m.end():].lstrip().startswith('('):continue
        result.add(m.group())
    return result


def parse(lines):
    graph=defaultdict(set);registers=set();instances={};guards=[]
    for line in lines:
        text=line.strip();indent=len(line)-len(line.lstrip())
        while guards and guards[-1][0]>=indent:guards.pop()
        if text.startswith('when '):
            guards.append((indent,refs(text[5:].split(' :')[0])));continue
        reg=re.match(r'reg(?:reset)? (\S+) :',text)
        if reg:registers.add(reg[1]);continue
        inst=re.match(r'inst (\S+) of (\S+)',text)
        if inst:instances[inst[1]]=inst[2];continue
        node=re.match(r'node (\S+) = (.*)',text)
        conn=re.match(r'([\w$.[\]]+) <= (.*)',text)
        if not node and not conn:continue
        lhs,expr=(node or conn).groups()
        if lhs.split('.')[0].split('[')[0] in registers:continue
        graph[lhs].update(refs(expr))
        for _,condition in guards:graph[lhs].update(condition)
    return dict(graph),instances


def path(graph,start,target,nonempty=False):
    todo=deque([(n,[start,n]) for n in graph.get(start,())]) if nonempty else deque([(start,[start])])
    seen=set()
    while todo:
        n,route=todo.popleft()
        if n==target:return route
        if n in seen:continue
        seen.add(n)
        todo.extend((d,route+[d]) for d in graph.get(n,()))
    return None


def audit_modules(modules):
    results={}
    for name in ['Rocket','Rocket_1','Rocket_2','Rocket_3']:
        graph,instances=parse(modules[name]);csr=instances['csr']
        sub,_=parse(modules[csr])
        for key,deps in sub.items():graph['csr.'+key]={'csr.'+x for x in deps}
        old=path(graph,'check_exception','check_exception',True)
        gate='_privileged_start_ready_T_1'
        if 'csr.io.trace[0].exception' not in graph.get(gate,set()):
            raise ValueError(name+': archived failing gate differs from expected source')
        corrected={k:set(v) for k,v in graph.items()}
        corrected[gate].remove('csr.io.trace[0].exception')
        corrected[gate].add('csr.io.r_exception')
        new=path(corrected,'check_exception','check_exception',True)
        raw_retire=path(corrected,'csr.io.r_exception','csr.io.retire')
        results[name]=dict(csr_module=csr,old_reported_loop_reproduced=bool(old),
            old_dependency_cycle=old,corrected_scoped_cycle=new,
            raw_exception_to_retire_dependency=raw_retire,
            status='PASS' if old and new is None and raw_retire is None else 'FAIL')
    return results


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--fir',type=Path,required=True)
    ap.add_argument('--report',type=Path,required=True);a=ap.parse_args()
    modules={};current=None;h=hashlib.sha256()
    wanted=re.compile(r'^(Rocket(?:_[1-3])?|CSRFile_[1-4])$')
    with a.fir.open('rb') as f:
        for raw in f:
            h.update(raw);line=raw.decode();m=MODULE.match(line)
            if m:
                current=m[1] if wanted.fullmatch(m[1]) else None
                if current:modules[current]=[]
            if current:modules[current].append(line)
    checks=audit_modules(modules)
    result=dict(status='PASS' if all(x['status']=='PASS' for x in checks.values()) else 'FAIL',
        scope='Archived FIRRTL structural Rocket+CSR dependency cone, corrected gate substituted in memory only',
        fir=str(a.fir.resolve()),fir_sha256=h.hexdigest(),modules=checks,
        full_new_firrtl_check='NOT_EXECUTED',hardware_generation='NOT_EXECUTED',simulation='NOT_EXECUTED')
    (a.report/'dispatch_dependency_audit.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result,indent=2))
    return 0 if result['status']=='PASS' else 1


if __name__=='__main__':raise SystemExit(main())
