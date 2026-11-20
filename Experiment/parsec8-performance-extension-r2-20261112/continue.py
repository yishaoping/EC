#!/usr/bin/python3
"""Repair missing private runs directory; reuse existing built ELFs unchanged.

Both prior wrapper processes exited before launching any simulator. This is one
Native/EC execution each, not a repeated measurement. Original failure retained.
"""
from pathlib import Path
import argparse,importlib.util,json,hashlib

ROOT=Path(__file__).resolve().parent
OLD=ROOT.parent/'parsec8-performance-extension-20261112'
spec=importlib.util.spec_from_file_location('longer_roi_helpers',OLD/'extend_blackscholes.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.ROOT=ROOT
m.__file__=str(Path(__file__).resolve())

def prepare():
 assert not (ROOT/'inputs.json').exists()
 prior=m.read(OLD/'comparison.json')
 assert prior['status']=='FAILED_OR_NONCOMPARABLE_KEEP_EIGHT_EXISTING_PAIRS'
 assert not (OLD/'runs').exists(),'do not duplicate any launched target'
 for name in ['native-controller.log','ec-controller.log']:
  s=(OLD/name).read_text();assert 'FileNotFoundError' in s and 'out.mkdir' in s
 (ROOT/'runs').mkdir()
 pins=m.read(OLD/'inputs.json')
 pins.update(repeats_per_mode=1,repair='Create private parent runs directory before existing immutable runner; original attempt never started simulators.',prior_failure=str(OLD/'comparison.json'))
 pins['files'][str(Path(__file__).resolve())]=m.sha(Path(__file__))
 pins['files'][str(OLD/'comparison.json')]=m.sha(OLD/'comparison.json')
 for n in ['native-controller.log','ec-controller.log']:
  pins['files'][str(OLD/n)]=m.sha(OLD/n)
 m.save(ROOT/'inputs.json',pins)
 m.save(ROOT/'execution-policy.json',m.read(OLD/'execution-policy.json'))
 print('Versioned directory repair ready; exact previous ELFs/models unchanged; Native1/EC1.')

if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--controller',action='store_true');ap.add_argument('--run',choices=['native','ec']);a=ap.parse_args()
 if a.prepare:prepare()
 elif a.controller:m.controller()
 elif a.run:m.run(a.run)
 else:raise ValueError('action required')
