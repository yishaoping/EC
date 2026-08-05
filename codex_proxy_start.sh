#!/bin/bash
# Codex 代理启动脚本
# 用法: source /home/gzh/EC/codex_proxy_start.sh

REMOTE="guozh@10.10.60.103"
PROXY_PORT=8899
PROXY_SCRIPT="/tmp/proxy_http.py"

echo "🔗 启动 Codex 代理..."

# 1. 检查远程代理是否在运行
if ! ssh -o ConnectTimeout=3 $REMOTE "ss -tlnp 2>/dev/null | grep -q $PROXY_PORT" 2>/dev/null; then
    echo "  → 启动远程 HTTP 代理..."
    ssh $REMOTE "nohup python3 $PROXY_SCRIPT &>/tmp/proxy.log &" 2>/dev/null
    sleep 1
fi

# 2. 检查本地 SSH 端口转发
if ! ss -tlnp 2>/dev/null | grep -q "127.0.0.1:$PROXY_PORT"; then
    echo "  → 建立 SSH 端口转发: 本地:$PROXY_PORT → 远程:$PROXY_PORT"
    ssh -f -N -L $PROXY_PORT:127.0.0.1:$PROXY_PORT -o StrictHostKeyChecking=no $REMOTE
fi

# 3. 设置环境变量
export https_proxy="http://127.0.0.1:$PROXY_PORT"
export http_proxy="http://127.0.0.1:$PROXY_PORT"
export ALL_PROXY="http://127.0.0.1:$PROXY_PORT"

echo "✅ 代理已就绪: http://127.0.0.1:$PROXY_PORT"
echo "   目标: beeapi.ai"
