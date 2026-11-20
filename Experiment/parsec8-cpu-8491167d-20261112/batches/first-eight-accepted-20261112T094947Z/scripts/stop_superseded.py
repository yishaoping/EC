from common import *
import signal
p=ROOT/'runs/freqmine-official-test-serial-no-main-timer-lp64-native-r1';j=read(p/'state.json')
if j['status']=='RUNNING':
 assert ident(j['child']['pid'])==j['child']
 assert str(p).encode() in Path(f"/proc/{j['child']['pid']}/cmdline").read_bytes()
 save(p/'external-stop-reason.json',dict(utc=now(),identity=j['child'],reason='Superseded by smaller hot-cache profile after default-cache exact functional run completed with 31.3M ROI instructions. Existing profile cannot fit first-pass target cap and contains RV64 packing limitations. No ratio from partial run.',reference=str(ROOT/'audit/freqmine-lp64-v2-hist.log')))
 os.killpg(j['child']['pid'],signal.SIGTERM);print(j['child'])
