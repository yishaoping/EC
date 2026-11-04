# 独立 FireSim Manager 配置边界

固定源码为 `../../../../firesim/upstream`，即 `/data1/gzh/EC/firesim/upstream`。
FireSim 自身的平台样例来自该安装的 `deploy/sample-backup-configs`，原 bundled FireSim
不在 PATH 中。本目录的 YAML 标为 candidate，不能提交给 manager 期待成功构建。

`config_build_recipes.candidate.yaml` 给出 native U280 的配置字段和占位 EC 类。
当前 EC 类、200 MHz FASED、观察桥和 Linux harness 还没有移植到独立 Chipyard；
不能换成上游 `FireSimRocketConfig` 后声称已构建论文 C4。
FPGA host clock 与目标 BOOM/Rocket 200/100 MHz 是不同参数，host clock 要单独记录。
不擅自指定已满足时序的 FPGA host clock。

由用户完成移植并审阅编译 recipe 后，使用 `dac.py build-hardware --recipe ...` 限制
jobs/JVM/负载执行纯构建。任何 post_build_hook、远程 shell、make 间接命令和基础设施步骤
都应审阅；不能仅凭命令里没有 `infrasetup` 就断言无副作用。构建产物须固定实际 RTL、
observer、driver、bitstream hash，然后独立配置 site 的每卡部署 adapter。

本工具包不会调用 manager 的 infrasetup/enumeratefpgas。当前上游的 Alveo 部署路径存在
全局 XDMA 操作，不适合另一张卡有任务时直接使用；没有经审查的每卡替代流程时退出。
runtime/hwdb 的 bitstream、driver、rootfs、server BDF 均不能从现有他人任务猜测或复制为
有效数据；`site.json` 和 artifact/compatibility 证据才是本工具包的实际启动门槛。
