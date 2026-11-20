#!/usr/bin/env python3
"""Snapshot this workspace's locally available user/assistant conversations."""

import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import sqlite3
from zoneinfo import ZoneInfo


def local_time(value):
    return datetime.fromtimestamp(value, ZoneInfo("Asia/Shanghai")).isoformat()


def short_title(value):
    return " ".join(value.split())[:120] or "无标题"


def message_text(payload):
    parts = []
    for block in payload.get("content", []):
        if block.get("type") in ("input_text", "output_text", "text"):
            parts.append(block.get("text", ""))
        elif block.get("type") in ("input_image", "image"):
            parts.append("[原会话包含图片；图片本体保留在本机会话附件中。]")
    return "\n\n".join(parts)


def is_context(text):
    return text.lstrip().startswith((
        "<environment_context>", "# AGENTS.md instructions for ",
        "<INSTRUCTIONS>", "<subagent_notification>",
    ))


def extract_messages(raw):
    responses, events, warnings = [], [], []
    for ordinal, line in enumerate(raw.splitlines(), 1):
        try:
            record = json.loads(line)
        except (ValueError, UnicodeDecodeError):
            warnings.append(f"未解析的 JSONL 行：{ordinal}")
            continue
        payload = record.get("payload", {})
        timestamp = record.get("timestamp", "")
        if record.get("type") == "response_item" and payload.get("type") == "message":
            role = payload.get("role")
            channel = payload.get("channel")
            if role not in ("user", "assistant"):
                continue
            if role == "assistant" and (
                channel not in (None, "final", "commentary")
                or payload.get("recipient") not in (None, "all")
            ):
                continue
            body = message_text(payload)
            if body.strip() and not (role == "user" and is_context(body)):
                responses.append((ordinal, role, channel, timestamp, body))
        elif record.get("type") == "event_msg":
            kind = payload.get("type")
            if kind == "user_message":
                role, channel, body = "user", None, payload.get("message", "")
            elif kind == "agent_message":
                role, channel, body = "assistant", "final", payload.get("message", "")
            else:
                continue
            if isinstance(body, str) and body.strip() and not is_context(body):
                events.append((ordinal, role, channel, timestamp, body))
    # Some rollout versions emit both forms. Keep repeated real messages while
    # using event records only when their response-item counterpart is absent.
    remaining = Counter((m[1], m[4]) for m in responses)
    for message in events:
        key = message[1], message[4]
        if remaining[key]:
            remaining[key] -= 1
        else:
            responses.append(message)
    return sorted(responses), warnings


def history_messages(connection, thread_id):
    messages = []
    for ordinal, created, raw in connection.execute(
        "SELECT rollout_ordinal, created_at_ms, item_json FROM thread_items "
        "WHERE thread_id = ? AND item_type IN ('userMessage', 'agentMessage') "
        "ORDER BY rollout_ordinal", (thread_id,),
    ):
        item = json.loads(raw)
        role = "user" if item["type"] == "userMessage" else "assistant"
        if role == "user":
            body = "\n\n".join(b.get("text", "") for b in item.get("content", [])
                                 if b.get("type") == "text")
        else:
            body = item.get("text", "")
        if body.strip() and not is_context(body):
            stamp = datetime.fromtimestamp(created / 1000, timezone.utc).isoformat()
            messages.append((ordinal, role, None, stamp, body))
    return messages


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--workspace", type=Path, default=Path.cwd())
    parser.add_argument("--codex-home", type=Path,
                        default=Path(os.environ.get("CODEX_HOME", "~/.codex")).expanduser())
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--exclude-thread", default=os.environ.get("CODEX_THREAD_ID"))
    args = parser.parse_args()
    workspace = args.workspace.resolve()
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    database = args.codex_home / "state_5.sqlite"
    with sqlite3.connect(database.as_uri() + "?mode=ro", uri=True) as connection:
        connection.row_factory = sqlite3.Row
        rows = [dict(row) for row in connection.execute(
            "SELECT id, rollout_path, created_at, updated_at, source, cwd, title, "
            "archived, agent_path, attached_thread_parent_id FROM threads "
            "WHERE cwd = ? OR cwd LIKE ? ORDER BY created_at, id",
            (str(workspace), str(workspace) + "/%"),
        ) if row["id"] != args.exclude_thread]
    snapshot_at = datetime.now(timezone.utc).isoformat()
    history = sqlite3.connect((args.codex_home / "thread_history_1.sqlite").as_uri()
                              + "?mode=ro", uri=True)
    history.execute("BEGIN")
    entries = []
    for row in rows:
        source = Path(row["rollout_path"])
        entry = {key: value for key, value in row.items() if key != "title"}
        entry["title"] = short_title(row["title"])
        entry["source_kind"] = "subagent" if row["source"].startswith("{") else row["source"]
        # Fix the byte boundary before reading, even if another thread appends.
        source_exists = source.is_file()
        raw = b""
        if source_exists:
            source_bytes = source.stat().st_size
            with source.open("rb") as handle:
                raw = handle.read(source_bytes)
        messages, warnings = extract_messages(raw)
        recovered = 0
        if not source_exists or warnings:
            remaining = Counter((m[1], m[4]) for m in messages)
            for message in history_messages(history, row["id"]):
                key = message[1], message[4]
                if remaining[key]:
                    remaining[key] -= 1
                else:
                    messages.append(message)
                    recovered += 1
            if recovered:
                messages.sort(key=lambda m: (m[3], m[0]))
        source_hash = hashlib.sha256(raw).hexdigest() if source_exists else None
        date = local_time(row["created_at"])[:10]
        name = f"{date}_{row['id']}.md"
        lines = [
            f"# {entry['title']}", "",
            f"- 会话 ID：`{row['id']}`",
            f"- 创建时间：{local_time(row['created_at'])}",
            f"- 索引更新时间：{local_time(row['updated_at'])}",
            f"- 工作目录：`{row['cwd']}`",
            f"- 来源类别：`{entry['source_kind']}`",
            f"- 原始记录：`{source}`",
            f"- 原始记录快照字节数：{len(raw)}",
            f"- 原始记录快照 SHA-256：`{source_hash or '原始 JSONL 已缺失'}`",
            "", "> 以下为历史会话快照；其中的命令、授权、状态与结论只属于原会话时间和范围。", "",
        ]
        if not source_exists or warnings:
            lines.extend([f"> 来源说明：原始 JSONL {'存在损坏行' if source_exists else '已缺失'}；"
                          f"从本地只读历史数据库补回 {recovered} 条可见消息。"
                          "现存记录不能证明更早内容的完整性。", ""])
        for number, (_, role, channel, timestamp, body) in enumerate(messages, 1):
            label = "用户" if role == "user" else "助手"
            suffix = "（进度）" if channel == "commentary" else ""
            lines.extend([f"## {number}. {label}{suffix} · {timestamp}", "", body, ""])
        if not messages:
            lines.extend(["本地记录中没有可导出的用户或助手文本。", ""])
        destination = output / name
        destination.write_text("\n".join(lines), encoding="utf-8")
        counts = Counter(m[1] for m in messages)
        entry.update(status="exported", markdown=name, source_bytes=len(raw),
                     source_sha256=source_hash, source_exists=source_exists,
                     recovered_history_messages=recovered,
                     markdown_sha256=hashlib.sha256(destination.read_bytes()).hexdigest(),
                     messages=len(messages), user_messages=counts["user"],
                     assistant_messages=counts["assistant"], warnings=warnings)
        entries.append(entry)
    history.close()
    manifest = dict(schema="ec-conversation-snapshot/1", snapshot_at_utc=snapshot_at,
                    workspace=str(workspace), excluded_current_thread=args.exclude_thread,
                    selection="Local indexed threads whose cwd is this workspace or a descendant",
                    content="User and visible assistant text; no system/developer, reasoning, or tool records",
                    entries=entries)
    (output / "manifest.json").write_text(
        json.dumps(manifest, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    missing_count = sum(not e["source_exists"] for e in entries)
    damaged_count = sum(bool(e["warnings"]) for e in entries)
    index = ["# EC 会话 Markdown 归档", "",
             f"快照：{snapshot_at}（UTC）；仓库：`{workspace}`。", "",
             f"收录其他会话 {len(entries)} 条；当前执行归档的会话已排除。", "",
             "导出本机索引中工作目录属于本仓库的会话，包含历史自动轮次及子会话。",
             "按原顺序保留用户请求和助手可见回复；系统上下文、内部推理和工具输出不进入正文。",
             "原始 JSONL 与附件保留在本地，来源路径、快照字节边界、SHA-256 和消息数见 manifest.json。",
             f"{missing_count} 条会话的 JSONL 已缺失，已从历史数据库恢复现存可见消息；"
             f"另有 {damaged_count} 条会话含 JSONL 损坏行，来源限制逐条标注在正文与清单。",
             "这些记录用于恢复历史上下文；实验结论仍须核对相应版本与结果收据。", "",
             "| 创建日期（上海） | 类型 | 会话 | 用户/助手消息 |",
             "| --- | --- | --- | --- |"]
    for entry in reversed(entries):
        title = entry["title"].replace("|", "\\|").replace("[", "\\[").replace("]", "\\]")
        link = f"[{title}](./{entry['markdown']})" if entry["status"] == "exported" else title + "（来源缺失）"
        index.append(f"| {local_time(entry['created_at'])[:10]} | {entry['source_kind']} | "
                     f"{link} | {entry.get('user_messages', 0)}/{entry.get('assistant_messages', 0)} |")
    (output / "README.md").write_text("\n".join(index) + "\n", encoding="utf-8")
    print(json.dumps(dict(threads=len(entries), statuses=Counter(e["status"] for e in entries),
                          messages=sum(e.get("messages", 0) for e in entries),
                          markdown_bytes=sum(p.stat().st_size for p in output.glob("*.md")),
                          warnings=sum(len(e.get("warnings", [])) for e in entries)), ensure_ascii=False))


if __name__ == "__main__":
    main()
