# Debug 整理提交与同步

用户要求本轮整理完成后以 `debug整理` 提交，并同步 origin/main。

同步前本地 main 比远端领先一个未发布提交：`ba883dac9e9c50eca94a8a09ac8dd542457798cc`，父提交/远端 main 为 `fbca5d0c5ee2a65575ad2b283c7219103684169a`。

该未发布提交包含 7.79 GB 新 blob，其中多个旧 Debug 波形、FIRRTL 和信号提取超过 GitHub 100 MiB 单文件限制。追加删除提交仍会发送这些历史对象，因此同步时仅从该未发布提交排除 `Debug/`，保留原作者、原提交消息及所有其他文件内容。

运行 manifest 中的旧 HEAD 是取证时身份，不重写为整理后的 HEAD。硬件/软件内容通过 437 个 Scala SHA256、软件 hash 和清理前后 Git tree 对照确认一致。

整理后的 Debug 文档、工具、provenance 与 TMP 排除规则全部位于 AI 下；远端使用正常快进推送，不覆盖共享历史。

清理后的基线提交：`6cb193ef3c67beb24042bd10e5fa88fb79504eb2`。原提交作者、消息、父提交与所有非 Debug 路径内容均已逐项对照；tree/hash 映射见 git_sync_manifest.json。
