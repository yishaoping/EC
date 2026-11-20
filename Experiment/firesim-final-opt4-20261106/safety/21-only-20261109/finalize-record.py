from pathlib import Path
import datetime,json,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from board_batch import D,save,sha,precheck
from job_service import proc,inspect
O=D/'safety/21-only-20261109'
active=json.loads((D/'active-0000_21_00.0.json').read_text());p=proc(active['pid'])
assert p and p['start_ticks']==active['start_ticks'] and '+bus=21 ' in p['cmdline']
check=precheck(target_bdfs=['0000:21:00.0'])
assert not any('+bus=e2 ' in x['cmd'] for x in check['other_card_simulations'])
cad=json.loads((D/'C4-runtime-cad-state.json').read_text())
proof={'observed_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'status':'COMPLETE_AND_EXPERIMENT_RESUMED',
 'active':active,'process':p,'precheck':check,'e2_previous_run':json.loads((D/'active-0000_e2_00.0.json').read_text()),
 'cad':{k:cad.get(k) for k in ['status','child_pid','certified_bitstream','updated_utc']},
 'service_audits':{n:inspect(D/'jobs'/n/'state.json') for n in ['coverage-first','native','c4-first','c4-suite','cad']},
 'tests_log':str(O/'tests.log'),'tests_sha256':sha(O/'tests.log'),
 'protected_e2_identity_unchanged':json.loads((O/'protected-e2-before.json').read_text())==json.loads((O/'protected-e2-after-deploy.json').read_text())}
save(O/'final-state.json',proof)
old=O/'transition-state.json'
s=json.loads(old.read_text());archive=O/'transition-failed-receipt-publication.json'
if not archive.exists():archive.write_bytes(old.read_bytes())
s.update(status='COMPLETE_EXISTING_SERVICES_RESUMED21',stage='NATIVE_FORMAL_SAMPLE_RUNNING21',
 completion_proof=str(O/'final-state.json'),prior_wrapper_failure=str(archive),
 resolved_without_second_programming=True,updated_utc=proof['observed_utc'])
save(old,s)
doc=Path('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106/FIRESIM_START_HERE.md');s=doc.read_text()
insert=f'''\n## 2026-11-09 单卡安全修复与恢复入口\n\n- 后续实验只允许 `0000:21:00.0` / `21770433G02LA`；`0000:e2:00.0` / `21770433G001A` 受保护。完整修复、补丁、哈希和验证收据见 [21-only REPORT]({O/'REPORT.md'})。\n- 部署入口：`python3 {W}/scripts/infrasetup.py Native`（或 `C4`），只复用认证 bitstream；拒绝双卡、e2、all-bdfs/all-serials 和 serial-only 编程。单卡维护锁：`{D}/locks/maintenance-0000_21_00.0.lock`。\n- 持续状态：[active-0000_21_00.0.json]({D/'active-0000_21_00.0.json'})；日志：各 run 的 `uart.log`、`host.log`、`roi-raw.jsonl`；服务日志：`{D}/jobs/coverage-first/console.log`。\n- 重连先核对 PID、start_ticks、boot_id 与服务 cgroup。活进程原地接管；已退出才补跑缺失样本；保留原 result/complete，不把统计快照当指令恢复点。\n- e2 Facesim 自然完成后才重载旧 coverage/native 控制器；本轮未停止 e2 活样本、未重载全局 XDMA、未全局 PCI 重扫、未中断 C4 CAD。已在 21 启动 `native-facesim-simmedium-r1-20261109T023353Z`（运行中，尚无有效完成标记）。\n- 一次性切换修复已完成，不另启调度器：[final-state.json]({O/'final-state.json'})。现有 systemd 服务继续管理实验。\n'''
if '## 2026-11-09 单卡安全修复与恢复入口' not in s:s+=insert
doc.write_text(s)
print(json.dumps({'status':proof['status'],'run_id':active['run_id'],'pid':p['pid'],'target':active['board_bdf'],
 'guest_ready':active.get('guest_ready'),'cad':proof['cad'],'e2_protected':proof['protected_e2_identity_unchanged']}))
