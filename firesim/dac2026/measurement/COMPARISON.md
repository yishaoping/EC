# 公共 B 复用与完成标记

完成标记始终绑定整个 sample：源码清单、逻辑配置、实际产物、软件、输入、site 和 kit 的版本。
加入 C2/C8 或更新无关工具后，旧 campaign 不能在新环境中继续执行；运行门槛仍校验当前完整身份。
不要编辑旧 manifest 或把旧完成文件改名为新 sample_id。

跨 campaign 的分析允许复用原 B，但必须显式建立同一份不可变的比较上下文。当前没有已准入上下文；
`site.json` 中 `comparison_context=null`、`comparison_admissions={}`，正式运行继续阻断。
首次 link 允许在原本的严格 source/site/kit 身份内进行验证，不先要求完成正式比较准入。

比较上下文 JSON 的 schema 为 `ec-dac-comparison/1`，包含：

- `definition`：当前严格 package 执行完成至完整 PASS 定义。
- `common`：完整实验共同参数，与 sample.case.common 完全相同，包括固定 FASED 参数和软件/缓存政策。
- `baseline.configuration`：真实 B 的配置对象（去除 ready/structural_ready/deferred 状态字段）。
- `baseline.artifacts`：B 的 bitstream、driver、kernel、rootfs、rtl_manifest、observer_manifest 的准确路径和 SHA256。
- `software_manifest`、`observer_manifest`、`comparability_evidence`：共同软件政策、真实观测实现和共同配置审查证据的路径/SHA256。
- `reviewed=true`：只有上述事实已有真实证据并审核后才可填写。

上下文内容的规范 JSON SHA256 就是 context_id。**上下文不包含 C2/C4/C8 产物清单或全局 site/kit ID**；
因此增加数量扫描点不会改变 B 身份或共同上下文。B、FASED、软件、观测定义、输入或共同政策变化则失去复用资格。
输入/程序/validator/argv/cwd/线程通过独立的 comparison_key 继续逐项绑定，不可因 context_id 相同而跨输入配对。

每个配置还需单独的 admission JSON，包含 `schema`、`reviewed=true`、`context_id`、
`configuration`（同样去除状态字段）、`source_id`（本次完整源码清单 ID）、
`artifacts_id`（该配置完整产物对象的规范 JSON SHA256）和非空 `evidence` 路径/SHA256 列表。
证据必须证明此配置遵守上下文中的共同软件、BOOM、缓存、时钟、FASED 和观测政策。
site.comparison_context 与 site.comparison_admissions[配置ID] 都是对应 JSON 的路径/SHA256。

规划时核对每份证据及产物的实际文件 hash，并将上下文/admission 内容嵌入不可变 sample；
完成时仍原子提交完整 sample 身份。分析按 `(comparison_key, context_id)` 配对，不依赖后来是否修改 site。
旧记录若没有显式上下文，只在完整 source/site/kit 一致时比较；损坏或不匹配的 admission 直接报错。
同一上下文中同名配置出现不同硬件/软件产物时也报错，不能把两个 C4 实现静默求平均。

验证命令只运行宿主离线身份/持久化测试，不运行仿真或 benchmark：

```bash
cd /data1/gzh/EC
PYTHONPATH=firesim/dac2026 firesim/envs/manager-1.17.1/bin/python3 -m unittest discover -s firesim/dac2026/tests -v
```

临时 fixture 测试覆盖：新增无关 C2/C8/site/kit 后原 B 仍可复用；B、输入、内存、软件、observer 变化不能配对；
陈旧 admission 被拒绝；不同 C4 产物不能混合。它们不生成或准入任何真实实验数据。
