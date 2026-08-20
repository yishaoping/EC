#!/bin/bash
# Codex 反向中转：让【远端服务器】上的 Codex 走【本地】网络访问 beeapi.ai / chatgpt.com
# 与 codex_proxy_start.sh 方向相反：代理跑在本地，用 -R 反向隧道把远端 8899 指到本地 8899
# 用法: bash /home/gzh/EC/codex_proxy_remote_relay.sh   (在【本地】机器上运行)

REMOTE="guozh@10.10.60.103"
SSH_PORT=2222   # 主机连入服务器的 SSH 端口（当前会话 SSH_CONNECTION 末尾为 2222）
PROXY_PORT=8899
PROXY_SCRIPT="/tmp/proxy_http.py"

echo "🔗 建立本地中转（远端 Codex → 本地网络）..."

# 1. 本地准备代理脚本（没有就从服务器拉一份）
if [ ! -f "$PROXY_SCRIPT" ]; then
    echo "  → 从服务器复制 proxy_http.py 到本地"
    scp -P "$SSH_PORT" -q "$REMOTE:$PROXY_SCRIPT" "$PROXY_SCRIPT" 2>/dev/null \
      || { echo "  ✗ 拉取失败：请手动把服务器 /tmp/proxy_http.py 拷到本地 $PROXY_SCRIPT"; exit 1; }
fi

# 2. 启动本地 HTTP CONNECT 代理（本地网络能直连 beeapi.ai）
if ! ss -tlnp 2>/dev/null | grep -q "127.0.0.1:$PROXY_PORT"; then
    echo "  → 启动本地代理 127.0.0.1:$PROXY_PORT"
    nohup python3 "$PROXY_SCRIPT" &>/tmp/proxy_http.log &
    sleep 1
fi

# 3. 清理远端可能残留的自我回环转发（避免 8899 被占用）
ssh -p "$SSH_PORT" -o ConnectTimeout=3 "$REMOTE" \
  "pkill -f 'ssh.*-L $PROXY_PORT:127.0.0.1:$PROXY_PORT' 2>/dev/null; true"

# 4. 建立反向隧道：远端 127.0.0.1:8899 ← 本地 127.0.0.1:8899
if ! ssh -p "$SSH_PORT" -o ConnectTimeout=3 "$REMOTE" \
  "ss -tlnp 2>/dev/null | grep -q '127.0.0.1:$PROXY_PORT'" 2>/dev/null; then
    echo "  → 建立反向隧道 远端:$PROXY_PORT ← 本地:$PROXY_PORT"
    ssh -p "$SSH_PORT" -f -N -R "127.0.0.1:$PROXY_PORT:127.0.0.1:$PROXY_PORT" \
      -o StrictHostKeyChecking=no "$REMOTE"
fi

echo "✅ 隧道就绪：远端 127.0.0.1:$PROXY_PORT → 本地 127.0.0.1:$PROXY_PORT"
echo "   下一步：在【服务器】上运行 codex_proxy_server_env.sh 让 codex 走该代理"
