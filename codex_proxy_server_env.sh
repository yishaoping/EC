#!/bin/bash
# 让【服务器】上的 codex（含 VS Code Codex 扩展）走反向隧道代理 127.0.0.1:8899
# 用法: bash /data1/gzh/EC/codex_proxy_server_env.sh   (在服务器上运行，普通用户即可)

PROXY="http://127.0.0.1:8899"
NO_PROXY="localhost,127.0.0.1,10.0.0.0/8,172.16.0.0/12,192.168.0.0/16,.local"

echo "🛠  配置服务器端 codex 代理环境..."

# 1. 写入默认 shell 的启动文件（VS Code 远端扩展宿主会探测默认 shell 的环境变量）
for f in "$HOME/.zshrc" "$HOME/.zprofile" "$HOME/.bashrc" "$HOME/.profile"; do
    if grep -q '# codex_proxy' "$f" 2>/dev/null; then
        echo "  → $f 已配置，跳过"
        continue
    fi
    cat >> "$f" <<EOF

# >>> codex_proxy 本地中转 (autogen) >>>
export https_proxy=$PROXY http_proxy=$PROXY HTTPS_PROXY=$PROXY HTTP_PROXY=$PROXY
export NO_PROXY=$NO_PROXY no_proxy=$NO_PROXY
# <<< codex_proxy <<<
EOF
    echo "  → 已写入 $f"
done

# 2. VS Code 扩展自身的 http 请求也走代理
mkdir -p "$HOME/.vscode-server/data/User"
cat > "$HOME/.vscode-server/data/User/settings.json" <<EOF
{
  "http.proxy": "$PROXY"
}
EOF
echo "  → 已写入 ~/.vscode-server/data/User/settings.json"

echo "✅ 配置完成。请在 VS Code 中 Reload Window（Ctrl+Shift+P → Reload Window）"
echo "   之后 codex 的模型请求将经 127.0.0.1:8899 → 本地网络"
