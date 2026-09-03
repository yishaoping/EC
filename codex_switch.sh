#!/usr/bin/env bash
# Codex 网络通道开关（服务器端）：在【本地转发 relay】与【直连 direct】之间切换
#
# 用法（在服务器上运行，普通用户即可）:
#   bash /data1/gzh/EC/codex_switch.sh relay     # 走本地转发通道 (127.0.0.1:2731 反向隧道)
#   bash /data1/gzh/EC/codex_switch.sh direct    # 直连 beeapi.ai（不走代理）
#   bash /data1/gzh/EC/codex_switch.sh privoxy   # 走本机 Privoxy (127.0.0.1:8118 → Clash 节点)
#   bash /data1/gzh/EC/codex_switch.sh status    # 查看当前通道
#
# 说明:
#   - relay   需要本地机器上的反向隧道已建立（服务器 127.0.0.1:2731 → 本地网络）。
#   - direct  服务器直连 beeapi.ai，不依赖任何隧道。
#   - privoxy 走本机 Privoxy HTTP 代理 (127.0.0.1:8118)，其上游为 Clash SOCKS5 127.0.0.1:7890。
#   - 修改的是 ~/.zshrc ~/.zprofile ~/.bashrc ~/.profile 以及
#     ~/.vscode-server/data/User/settings.json 中的 http.proxy。
set -euo pipefail

MODE="${1:-status}"
case "$MODE" in
  relay|direct|privoxy|status) ;;
  *) echo "用法: bash $0 {relay|direct|privoxy|status}" >&2; exit 2 ;;
esac

export CODEX_SWITCH_MODE="$MODE"
python3 - <<'PY'
import os, re, json

mode = os.environ['CODEX_SWITCH_MODE']
port = os.environ.get('CODEX_PROXY_PORT', '2731')
privoxy_port = os.environ.get('CODEX_PRIVOXY_PORT', '8118')
relay_proxy = f"http://127.0.0.1:{port}"
privoxy_proxy = f"http://127.0.0.1:{privoxy_port}"
no_proxy = "localhost,127.0.0.1,10.0.0.0/8,172.16.0.0/12,192.168.0.0/16,.local"
home = os.path.expanduser('~')

START = '# >>> codex_proxy'
END = '# <<< codex_proxy <<<'

def block_for(mode):
    if mode == 'relay':
        return '\n'.join([
            '# >>> codex_proxy (autogen) >>>',
            f'export https_proxy={relay_proxy} http_proxy={relay_proxy} HTTPS_PROXY={relay_proxy} HTTP_PROXY={relay_proxy}',
            f'export NO_PROXY={no_proxy} no_proxy={no_proxy}',
            '# <<< codex_proxy <<<',
        ])
    if mode == 'privoxy':
        return '\n'.join([
            '# >>> codex_proxy (autogen) >>>',
            f'export https_proxy={privoxy_proxy} http_proxy={privoxy_proxy} HTTPS_PROXY={privoxy_proxy} HTTP_PROXY={privoxy_proxy}',
            f'export NO_PROXY={no_proxy} no_proxy={no_proxy}',
            '# <<< codex_proxy <<<',
        ])
    return '\n'.join([
        '# >>> codex_proxy (autogen) >>>',
        'unset https_proxy http_proxy HTTPS_PROXY HTTP_PROXY ALL_PROXY all_proxy',
        'unset NO_PROXY no_proxy',
        '# <<< codex_proxy <<<',
    ])

def replace_block(text, block):
    """原位替换标记块；若不存在则追加到文件末尾。"""
    lines = text.split('\n')
    out, i, replaced = [], 0, False
    while i < len(lines):
        if lines[i].startswith(START):
            out.append(block)
            replaced = True
            while i < len(lines) and not lines[i].startswith(END):
                i += 1
            i += 1  # 跳过 END 行
            continue
        out.append(lines[i])
        i += 1
    if not replaced:
        if text and not text.endswith('\n'):
            text += '\n'
        return text + '\n' + block + '\n'
    new = '\n'.join(out)
    if new and not new.endswith('\n'):
        new += '\n'
    return new

if mode != 'status':
    for name in ('.zshenv', '.zshrc', '.zprofile', '.bashrc', '.profile'):
        path = os.path.join(home, name)
        block = block_for(mode)
        if os.path.exists(path):
            with open(path) as f:
                text = f.read()
            new = replace_block(text, block)
        else:
            new = block + '\n'
        with open(path, 'w') as f:
            f.write(new)

    spath = os.path.join(home, '.vscode-server', 'data', 'User', 'settings.json')
    os.makedirs(os.path.dirname(spath), exist_ok=True)
    new_proxy = relay_proxy if mode == 'relay' else (privoxy_proxy if mode == 'privoxy' else '')
    if os.path.exists(spath):
        with open(spath) as f:
            raw = f.read()
        try:
            data = json.loads(raw)
        except Exception:
            # 非纯 JSON（可能含注释）：文本级替换
            s = raw
            if re.search(r'"http\.proxy"\s*:', s):
                s = re.sub(r'("http\.proxy"\s*:\s*)"[^"]*"',
                           lambda m: m.group(1) + json.dumps(new_proxy), s)
            elif s.strip().endswith('}'):
                s = re.sub(r'\}\s*$',
                           ',\n  "http.proxy": ' + json.dumps(new_proxy) + '\n}\n',
                           s, count=1)
            with open(spath, 'w') as f:
                f.write(s)
        else:
            data['http.proxy'] = new_proxy
            with open(spath, 'w') as f:
                json.dump(data, f, indent=2, ensure_ascii=False)
                f.write('\n')
    else:
        with open(spath, 'w') as f:
            json.dump({'http.proxy': new_proxy}, f, indent=2, ensure_ascii=False)
            f.write('\n')

# —— 读取当前模式用于输出 ——
cur = 'unknown'
spath = os.path.join(home, '.vscode-server', 'data', 'User', 'settings.json')
if os.path.exists(spath):
    try:
        with open(spath) as f:
            hp = json.load(f).get('http.proxy', '')
        if hp == relay_proxy:
            cur = 'relay'
        elif hp == privoxy_proxy:
            cur = 'privoxy'
        else:
            cur = 'direct'
    except Exception:
        pass
if cur == 'unknown':
    zsh = os.path.join(home, '.zshrc')
    if os.path.exists(zsh):
        with open(zsh) as f:
            text = f.read()
        if privoxy_proxy in text:
            cur = 'privoxy'
        elif 'unset https_proxy' in text:
            cur = 'direct'
        else:
            cur = 'relay'

label = {
    'relay': f'本地转发 (127.0.0.1:{port} → 本地网络 → beeapi.ai)',
    'privoxy': f'Privoxy (http://127.0.0.1:{privoxy_port} → Clash 节点 → beeapi.ai)',
    'direct': '直连 (服务器直接访问 beeapi.ai)',
    'unknown': '未知',
}[cur]

print(f'当前通道: {label}')
if mode != 'status':
    print(f'已切换为: {label}')
    print('生效方式: 新开终端，或在 VS Code 中 Reload Window（Ctrl+Shift+P → Reload Window）')
PY
