#!/usr/bin/env python3
"""Universal cyclic priority equivalence, independently of any FPGA task."""
from pathlib import Path
import datetime, fcntl, json, os, subprocess
from board_batch import W,D,save,sha
from job_service import proc

O=D/'build-logs/Opt4-fit-modules-20261110/priority-proof'
S=D/'Opt4-fit-priority-proof-state.json'
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-priority-proof.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    st=dict(status='RUNNING_UNIVERSAL_SAT',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
            host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),
            fpga_access=False,full_design_proof=False,input_bits=264,fit_commit='8da24a269b98a0d6a8f57b030353a310812c4344')
    save(S,st)
    v=O/'priority-proof.v'
    v.write_text('''module priority_proof(input [255:0] bad,input [7:0] low,output ok);
wire [7:0] start=low+8'd1;
wire [511:0] repeated={bad,bad};
wire [255:0] rotated=repeated>>start;
reg [8:0] old_advance;
reg [7:0] first_all,first_after;
reg after_exists;
integer i;
always @* begin
  old_advance=9'd256;
  first_all=0;first_after=0;after_exists=0;
  for(i=255;i>=0;i=i-1)begin
    if(rotated[i])old_advance=i;
    if(bad[i])first_all=i;
    if(bad[i] && i>low)begin first_after=i;after_exists=1;end
  end
end
wire [7:0] slot=after_exists?first_after:first_all;
wire [7:0] dlow=slot-low;
wire [8:0] distance=(dlow==0)?9'd256:{1'b0,dlow};
wire [8:0] new_advance=(|bad)?distance-9'd1:9'd256;
assign ok=(old_advance==new_advance);
endmodule
''')
    argv=['nice','-n','15','/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {v}; prep -top priority_proof; flatten; opt; sat -verify -prove ok 1 -show-inputs -timeout 240']
    with (O/'proof.log').open('ab',buffering=0) as f:
        p=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
        st.update(child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks'],proof_sha256=sha(v));save(S,st)
        rc=p.wait();os.fsync(f.fileno())
    text=(O/'proof.log').read_text()
    assert rc==0 and 'SUCCESS!' in text,(rc,'universal proof did not complete; evidence retained')
    st.update(status='PASS_UNIVERSAL_264_INPUT_BITS',returncode=rc,ended_utc=now(),log_sha256=sha(O/'proof.log'),
              composition='The existing 40-input-bit index SAT proves each full-sequence slot predicate matches the cyclic offset. This proof universally compares first failure in that cyclic order with two priority encoders for every 256-bit failure pattern and all 8-bit lows. Full generated-module comparisons remain separately bound.')
    save(S,st);print(json.dumps(st),flush=True)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
        raise
