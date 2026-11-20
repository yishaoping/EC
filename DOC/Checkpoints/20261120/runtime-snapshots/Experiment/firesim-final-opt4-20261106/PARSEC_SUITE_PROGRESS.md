# 本地完整 PARSEC Native / 最终 Opt4 C4 配对进度

全套共 16 个程序；Native 正式通过 15/16；Opt4 正式通过 0/16；有效配对 0/16。

正式通过要求同一版本三轮有效原子提交。test/simsmall 仅功能验证。完整 ELF、runconf、输入哈希、ROI 行号、参考与逐样本路径见同名 JSON。

|程序|Native 正式轮数|Opt4 正式轮数|正式命令（线程1）|当前具体阻碍|
|---|---:|---:|---|---|
|blackscholes|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-formal-20261106T123109Z/blackscholes 1 in_16K.txt prices.txt`|Native formal3 valid. Waiting final frozen C4 bitstream and real checker validation.|
|bodytrack|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-bodytrack-staged-output-20261107T052920Z/bodytrack sequenceB_2 4 2 2000 5 0 1`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|canneal|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-formal-20261106T123109Z/canneal 1 15000 2000 200000.nets 64`|Native formal3 valid. Waiting final frozen C4 bitstream and real checker validation.|
|dedup|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-dedup-staged-20261107T051530Z/dedup -c -p -v -t 1 -i media.dat -o output.dat.ddp`|Old firmware DTB overlapped initramfs; safe-fdt firmware passed QEMU boot/integrity only. Directed FPGA repair waits for current Native queue idle. C4 not yet validated.|
|facesim|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-facesim-staged-resident-20261107T063015Z/facesim -timing -threads 1`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|ferret|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/ferret-stable-order-20261109T123400Z/ferret corel lsh queries 10 20 1 output.txt`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|fluidanimate|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-fluidanimate-stable-candidate-20261107T083942Z/fluidanimate 1 5 in_100K.fluid out.fluid`|Authorized repaired software: Native formal3 valid. Final C4 real checker/output/drain and formal sampling pending.|
|freqmine|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-freqmine-staged-resident-20261107T052259Z/freqmine kosarak_500k.dat 410`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|netdedup|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/network-runtime-candidates-20261109T044453Z/netdedup/server/netdedup -c -v -t 1 -o out.ddp`|Original ROI contains network/thread/blocking paths; current C4 trap/context validity contract and original user TCP RISC-V port are unresolved. Default path uses user TCP/shared memory; CONFIG_NET=n alone is not proof of incompatibility. Official simmedium.runconf invokes bin/netdedup directly with -p and -i media.dat, but the actual server getopt string cuvo:w:t:h does not accept p or i. The source wrapper starts a distinct client/server pair and maps simmedium client to test.dat. This is a concrete upstream CLI/input mismatch, not a claimed runtime or cross-compile test; no silent substitution authorized. Actual RISC-V make failed on missing include/riscv64; separate statistics translation unit failed on x86 register names in inline assembly. Logs are bound in actual_dependency_build_probe.|
|netferret|0|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/network-complete-roi-20261109T124132Z/netferret-runtime/server/parsec/bin/ferret-pthreads corel lsh 10 20 1`|Original ROI contains network/thread/blocking paths; current C4 trap/context validity contract and original user TCP RISC-V port are unresolved. Default path uses user TCP/shared memory; CONFIG_NET=n alone is not proof of incompatibility.  Actual RISC-V make failed on missing include/riscv64; separate statistics translation unit failed on x86 register names in inline assembly. Logs are bound in actual_dependency_build_probe.|
|netstreamcluster|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/network-native-wait-20261110T043100Z/netstreamcluster-real-hooks 10 20 128 16384 16384 1000 none output.txt 1`|Original ROI contains network/thread/blocking paths; current C4 trap/context validity contract and original user TCP RISC-V port are unresolved. Default path uses user TCP/shared memory; CONFIG_NET=n alone is not proof of incompatibility. Official simmedium.runconf literally invokes run.sh 1 simlarge. Preserve that actual workload or explicitly resolve the upstream label; do not silently use standalone simmedium. Actual RISC-V make failed on missing include/riscv64; separate statistics translation unit failed on x86 register names in inline assembly. Logs are bound in actual_dependency_build_probe.|
|raytrace|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-raytrace-headless-20261107T065042Z/raytrace happy_buddha.obj -automove -nthreads 1 -frames 3 -res 960 540`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|streamcluster|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-streamcluster-staged-20261107T032414Z/streamcluster 10 20 64 8192 8192 1000 none output.txt 1`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|swaptions|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-swaptions-preallocated-20261107T050149Z/swaptions -ns 32 -sm 20000 -nt 1`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|vips|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-vips-20261107T060302Z/vips im_benchmark vulture_2336x2336.v output.v`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|
|x264|3|0|`/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-x264-20261107T063229Z/x264 --no-progress --quiet --qp 20 --partitions b8x8,i4x4 --ref 5 --direct auto --b-pyramid normal --weightb --mixed-refs --no-fast-pskip --me umh --subme 7 --analyse b8x8,i4x4 --threads 1 -o eledream.264 eledream_640x360_32.y4m`|C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.|

## blackscholes

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-formal-20261106T123109Z/blackscholes
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/blackscholes/inputs/input_simmedium.tar', 'sha256': 'cb50267d053cb4bb841125aa5efa4fa915662817fbff3fe336dd092a7dd94147'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/blackscholes/src/blackscholes.c:439,489; /data1/gzh/EC/Software/PARSEC/pkgs/apps/blackscholes/src/blackscholes.simd.c:507,557
集成补丁：无已绑定软件补丁
正确性：prices.txt byte hash vs RISC-V reference; official option values also checked within1e-4
功能样本（不计正式）：无有效提交

## bodytrack

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-bodytrack-staged-output-20261107T052920Z/bodytrack
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/bodytrack/inputs/input_simmedium.tar', 'sha256': 'bd768bd4c13e1cdde18f2c2657d8c5cae9fc9970d9bbe4866431bb63107ea725'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/bodytrack/src/TrackingBenchmark/main.cpp:192,206,253,270,350,365
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-bodytrack-staged-output-20261107T052920Z/software-integration.patch
正确性：{'files': {'sequenceB_2/Result0000.bmp': '69b2c2f7004ed149c3c5241be6c0ebcfb6211629e6e2a72a142999fbe4b5596e', 'sequenceB_2/Result0001.bmp': 'be9234c6aac6b7e5ab435daa24a93acd06c3d220897988c4b8b4e62fc0e43322', 'sequenceB_2/poses.txt': 'd0bb8539fef22e7c7d0c528731e61430b4e7376a2763af6215690f0f4f3e426d'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 898805472 cycles, Native test 202333243 cycles

## canneal

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-formal-20261106T123109Z/canneal
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/kernels/canneal/inputs/input_simmedium.tar', 'sha256': '90e184af6f8357c37e5fb797fa6d26519660bbb7dff545d7bc9c369d989f817b'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/kernels/canneal/src/main.cpp:110,125
集成补丁：无已绑定软件补丁
正确性：Final routing exact value vs deterministic serial RISC-V reference
功能样本（不计正式）：Native simsmall 426541923 cycles

## dedup

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-dedup-staged-20261107T051530Z/dedup
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/kernels/dedup/inputs/input_simmedium.tar', 'sha256': '9daba6f32da1082a4e29a49c4f95dbc819ef999e715bacdcc7ca8a40bf046d1a'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/kernels/dedup/src/encoder.c:1475,1524,1562,1569; /data1/gzh/EC/Software/PARSEC/pkgs/kernels/dedup/src/decoder.c:210,253
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-dedup-staged-20261107T051530Z/software-integration.patch
正确性：{'files': {'output.dat.ddp': '6e24ba26d52c6732eccaff5aa665b6acb40621c4e7fc89f84ea55fcc70ef7fd7'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 2147874830 cycles, Native test 133508 cycles

## facesim

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-facesim-staged-resident-20261107T063015Z/facesim
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/facesim/inputs/input_simmedium.tar', 'sha256': 'a1700a08a043ae6e94f02e5f159b8f999051809bc42830fc6614d94b3a75d9bb'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/facesim/src/Public_Library/Solids_And_Fluids/SOLIDS_FLUIDS_DRIVER.cpp:24,28
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-facesim-staged-resident-20261107T063015Z/software-integration.patch
正确性：{'files': {'Storytelling/output/controls.1': '2c70eb5ec6b1d6c4b923ec347481627a59050df7547dfdc2020cd1e0254ead7b', 'Storytelling/output/deformable_object_1_particle_class_state.1': 'caab01d0e1869080a3fbaaab034183decbc864ca198ef8610549e1dc5e2b02bf', 'Storytelling/output/deformable_object_1_particle_mass.1': '423035271bbe1dd077e07d30367d1376a2cf852f5f34765b13c45a2c284672c0', 'Storytelling/output/deformable_object_1_position.1': '8a48ab599db702e0ed1691a17fbc7cc099a9210d236dab2ce52e852f6ec9999f', 'Storytelling/output/rigid_bodies.1': '9e435601cf835951272863003b4ff2427a468d8ed3cd1b9248e28264f5fc3483', 'Storytelling/output/rigid_body_active_ids.1': '152ee596bba99ecfcde4a6fce299dacc88ec7f6592f760f4d827431300a2692c', 'Storytelling/output/rigid_body_implicit_surface_1.phi': '8831ff700a40712abfe4ae9e772e0086a621f47261e979afeaed3a2d20e6f579', 'Storytelling/output/rigid_body_implicit_surface_2.phi': '8c15ee723d21e2f7376fc861926d3c5e10c6efb761526967b820ba46f46da353', 'Storytelling/output/rigid_body_implicit_surface_active_ids.1': '152ee596bba99ecfcde4a6fce299dacc88ec7f6592f760f4d827431300a2692c', 'Storytelling/output/rigid_body_implicit_surface_key': 'ea8af56c091b08cd89859ec2b8041a5e12bbb5560cd890528013ea04d0413308', 'Storytelling/output/rigid_body_key': 'aa81387eddc72587f28e9329d6001d080aaa00877aad7d0f33889f7cbe6d5726', 'Storytelling/output/rigid_body_names': '471a23a4caf523b5dffe9b5e01aaa6796a8c827f058bc2165da8f429d938aeb3', 'Storytelling/output/rigid_body_triangulated_surface_1.tri': '9f407e7748555faa9e72c764abffa93ffc58cabe7d190a1191d26e2838a33af3', 'Storytelling/output/rigid_body_triangulated_surface_2.tri': 'c03b966b20fc31b7c061871ede005ce6ff8b0936242b47e12d62994042e66f9f', 'Storytelling/output/rigid_body_triangulated_surface_active_ids.1': '152ee596bba99ecfcde4a6fce299dacc88ec7f6592f760f4d827431300a2692c'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 23253122169 cycles

## ferret

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/ferret-stable-order-20261109T123400Z/ferret
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/ferret/inputs/input_simmedium.tar', 'sha256': '91ee10d3f47afdaf36d016f422ea0c217f5f4f93359e87a276ad5eccf61fd759'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/ferret/src/benchmark/ferret-tbb.cpp:522,533; /data1/gzh/EC/Software/PARSEC/pkgs/apps/ferret/src/benchmark/ferret-pthreads.c:551,568
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/ferret-order-recovery-20261109T123400Z/stable-directory-order.patch
正确性：{'files': {'output.txt': '3102067fb39cc04e71e4ffd5acb17e87688a4f92430882c07f6c632338c72784'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 1887901090 cycles, Native test 24112674 cycles

## fluidanimate

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-fluidanimate-stable-candidate-20261107T083942Z/fluidanimate
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/fluidanimate/inputs/input_simmedium.tar', 'sha256': '3f4a4b2014282f7db29e2cd8ec307f4c291eb35ce43f8bef2dece2857445bf7b'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/fluidanimate/src/tbb.cpp:1373,1380; /data1/gzh/EC/Software/PARSEC/pkgs/apps/fluidanimate/src/serial.cpp:1135,1140; /data1/gzh/EC/Software/PARSEC/pkgs/apps/fluidanimate/src/pthreads.cpp:1244,1266
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-fluidanimate-stable-candidate-20261107T083942Z/stable-pair-order.patch
正确性：{'files': {'out.fluid': '6309876f3a874fec3f0ae8ab96499026050746e70d9a0cc864b6adb8cbbc58a7'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 1364786789 cycles, Native test 28657448 cycles

## freqmine

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-freqmine-staged-resident-20261107T052259Z/freqmine
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/freqmine/inputs/input_simmedium.tar', 'sha256': '5d3d9e97fe7806009d278ef726bbf65dd0b7a791bfadade60618d2be2825ccbf'}
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/freqmine/src/fpmax.cpp:153,189
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-freqmine-staged-resident-20261107T052259Z/software-integration.patch
正确性：{'kind': 'stdout_integer_hash', 'reference': '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-freqmine-staged-resident-20261107T052259Z/reference-simmedium/counts.txt', 'reference_sha256': '9ee9457ee5393858423d6f665bc9a673c89312edfbb67fa6e1f0e4c85b064da5'}
功能样本（不计正式）：Native simsmall 19950377291 cycles, Native test 21366691 cycles

## netdedup

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/network-runtime-candidates-20261109T044453Z/netdedup/server/netdedup
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/kernels/dedup/inputs/input_simmedium.tar', 'sha256': '9daba6f32da1082a4e29a49c4f95dbc819ef999e715bacdcc7ca8a40bf046d1a'}
ROI：Full original server __parsec_roi_begin/end sites; includes original network/compute/thread/syscall work and elapsed target cycles
集成补丁：无已绑定软件补丁
正确性：{'files': {'decoded.dat': '3af825d1a6a6b7308b9c265e807ace1f13489f3758d35ed9cb3e79d93e876d5b', 'out.ddp': '6e24ba26d52c6732eccaff5aa665b6acb40621c4e7fc89f84ea55fcc70ef7fd7'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 36323953648 cycles, Native test 5435376 cycles

## netferret

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/network-complete-roi-20261109T124132Z/netferret-runtime/server/parsec/bin/ferret-pthreads
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/ferret/inputs/input_simmedium.tar', 'sha256': '91ee10d3f47afdaf36d016f422ea0c217f5f4f93359e87a276ad5eccf61fd759'}
ROI：Full original server __parsec_roi_begin/end sites; includes original network/compute/thread/syscall work and elapsed target cycles
集成补丁：无已绑定软件补丁
正确性：{'files': {'output.txt': '3102067fb39cc04e71e4ffd5acb17e87688a4f92430882c07f6c632338c72784'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native test 4962410208 cycles

## netstreamcluster

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/network-native-wait-20261110T043100Z/netstreamcluster-real-hooks
输入：None
ROI：Full original server __parsec_roi_begin/end sites; includes original network/compute/thread/syscall work and elapsed target cycles
集成补丁：无已绑定软件补丁
正确性：{'files': {'output.txt': 'd049ad6c0d8b708568d0bd52a9df1aec8f1b89de7f0eb550b672c87774a83590'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 5156726029 cycles, Native test 182537088 cycles

## raytrace

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-raytrace-headless-20261107T065042Z/raytrace
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/raytrace/inputs/input_simmedium.tar', 'sha256': '267a8e9a1a66c49727c6d473a8d0d0d2cfacf8b0f5051fc5d6faca06588ef16d'}
ROI：original complete multi-frame render and automove loop, plus identical per-frame output copy observation
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-raytrace-headless-20261107T065042Z/software-integration.patch
正确性：{'files': {'frames.rgba': '703a523dd36f791a496a05c358bac72c79e56519759a95a506a0fae1594631cd', 'frames.shape': 'b1c1aa6444bf4bdf0d27007d3783a0f8a3efab261af091a8b13ede260b5a986f'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 859156997 cycles

## streamcluster

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-streamcluster-staged-20261107T032414Z/streamcluster
输入：original synthetic deterministic generation
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/kernels/streamcluster/src/streamcluster.cpp:2031,2037
集成补丁：无已绑定软件补丁
正确性：output.txt byte hash vs unmodified reference; staged IO labelled separately
功能样本（不计正式）：Native simsmall 1436993042 cycles, Native test 127267 cycles

## swaptions

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-swaptions-preallocated-20261107T050149Z/swaptions
输入：original synthetic deterministic generation
ROI：/data1/gzh/EC/Software/PARSEC/pkgs/apps/swaptions/src/HJM_Securities.cpp:288,317
集成补丁：无已绑定软件补丁
正确性：{'kind': 'stdout_prefix_hash', 'prefix': 'Swaption ', 'reference': '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-swaptions-preallocated-20261107T050149Z/reference-simmedium/validation.txt', 'reference_sha256': '0c4033c2965f42b0759d50334032a14bf3d5d254858e598e2b82307228b15b4f'}
功能样本（不计正式）：Native simsmall 1253797248 cycles, Native test 142991 cycles

## vips

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-vips-20261107T060302Z/vips
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/vips/inputs/input_simmedium.tar', 'sha256': 'a9a2525c26a7d5219f526e33da88aed0a97d91a6231603401e0912ba5bc89487'}
ROI：Full original im_benchmarkn(in,out,1), eager IM_SETBUF/vips_sink_memory completes every output pixel inside ROI
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-vips-20261107T060302Z/software-integration.c
正确性：{'files': {'output.pixels': '3345ad21d60059e61248f25299d34cc06c57c49f5c9cf272d01c2b40d053c407', 'output.shape': 'fd7f4e21f80db6ef8fb94b317fd001e80fd31e02d8792c0852df293a1333d474'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 2668393167 cycles, Native test 205258452 cycles

## x264

ELF：/data1/gzh/EC/firesim/final-opt4-20261106/software/apps-x264-20261107T063229Z/x264
输入：{'path': '/data1/gzh/EC/Software/PARSEC/pkgs/apps/x264/inputs/input_simmedium.tar', 'sha256': '0f4287eccdaf1179f0f33dbd603eccd5e0a0ab6354589b66af83270ce33aecee'}
ROI：encoder open/initialization, headers, every input frame encode and full delayed-frame drain; cleanup/report/external flush outside
集成补丁：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/software/apps-x264-20261107T063229Z/software-integration.patch
正确性：{'files': {'eledream.264': 'cf6fa8b7369adbb1700b787d2c54cf881b7f754d3fee3257562ac07385ab0841'}, 'kind': 'files_sha256'}
功能样本（不计正式）：Native simsmall 2771389425 cycles, Native test 5963191 cycles
