#!/usr/bin/env bash

# Activate the EC Nix/Chipyard environment in the current shell.
# This file is intended to be sourced from ~/.zshrc or ~/.bashrc.

ec_env_fail() {
    echo "EC environment: $1" >&2
    return 1 2>/dev/null || exit 1
}

if [ -n "${BASH_SOURCE[0]:-}" ]; then
    ec_env_source="${BASH_SOURCE[0]}"
elif [ -n "${ZSH_VERSION:-}" ]; then
    ec_env_source="${(%):-%N}"
else
    ec_env_source="$0"
fi

EC_ROOT="$(CDPATH= cd -- "$(dirname -- "$ec_env_source")" && pwd)" \
    || ec_env_fail "cannot locate repository root"

# Apply the "(EC)" prompt indicator in EVERY shell (no early-return guard):
# PROMPT/PS1 and PATH must be re-derived here, and a stale EC_ENV_ACTIVE
# inherited from a parent (e.g. the VS Code server) must not stop us from
# refreshing PATH/CC/... from the cache.
case "$-" in
    *i*)
        if [ -n "${ZSH_VERSION:-}" ]; then
            _ec_prompt_prefix() {
                case "${PROMPT:-}" in
                    "(EC) "*) ;;
                    "(chipyard) "*) PROMPT="(EC) ${PROMPT#"(chipyard) "}"; PS1="$PROMPT" ;;
                    "(firesim) "*) PROMPT="(EC) ${PROMPT#"(firesim) "}"; PS1="$PROMPT" ;;
                    *) PROMPT="(EC) ${PROMPT:-}"; PS1="$PROMPT" ;;
                esac
            }
            _ec_prompt_prefix
            (( ${precmd_functions[(I)_ec_prompt_prefix]:-0} == 0 )) && precmd_functions+=("_ec_prompt_prefix")
        else
            _ec_prompt_prefix() {
                case "${PS1:-}" in
                    "(EC) "*) ;;
                    "(chipyard) "*) PS1="(EC) ${PS1#"(chipyard) "}" ;;
                    "(firesim) "*) PS1="(EC) ${PS1#"(firesim) "}" ;;
                    *) PS1="(EC) ${PS1:-}" ;;
                esac
            }
            _ec_prompt_prefix
            case ";${PROMPT_COMMAND:-};" in
                *";_ec_prompt_prefix;"*) ;;
                *) PROMPT_COMMAND="_ec_prompt_prefix${PROMPT_COMMAND:+;$PROMPT_COMMAND}" ;;
            esac
        fi
        ;;
esac

# nix develop starts bash even when the caller is zsh. Export only the runtime
# variables needed by this project instead of evaluating its Bash setup code in
# zsh (which would collide with zsh read-only variables such as LINENO). The
# cache is generated explicitly by ec-refresh-env.sh so opening a terminal
# never starts a nested shell or waits on Nix/network activity.
ec_env_cache_dir="${XDG_CACHE_HOME:-$HOME/.cache}/ec-env"
ec_env_cache="$ec_env_cache_dir/runtime.env"
if [ ! -r "$ec_env_cache" ]; then
    if command -v nix >/dev/null 2>&1 && [ -x "$EC_ROOT/ec-refresh-env.sh" ]; then
        "$EC_ROOT/ec-refresh-env.sh" >/dev/null 2>&1 || true
    fi
    if [ ! -r "$ec_env_cache" ]; then
        if ! command -v nix >/dev/null 2>&1; then
            echo "EC environment: install Nix, then run 'source $EC_ROOT/ec-refresh-env.sh'" >&2
        else
            echo "EC environment: run 'source $EC_ROOT/ec-refresh-env.sh' to initialise Nix tools" >&2
        fi
        unset ec_env_source ec_env_cache_dir ec_env_cache
        unset -f ec_env_fail 2>/dev/null || true
        return 0 2>/dev/null || exit 0
    fi
fi

ec_env_dump="$(cat "$ec_env_cache")"

while IFS='=' read -r ec_var ec_value; do
    case "$ec_var" in
        PATH|CC|CXX|OBJCACHE|CCACHE_BASEDIR|CCACHE_DIR|RISCV|JAVA_HOME|SBT_BIN|FIRTOOL_BIN|CPLUS_INCLUDE_PATH|LIBRARY_PATH|IN_NIX_SHELL)
            export "$ec_var=$ec_value"
            ;;
    esac
done <<EOF
$ec_env_dump
EOF

export EC_ROOT
export EC_ENV_NAME=EC
# Not exported: keeps the activation flag local to this shell so every new
# terminal re-reads the runtime cache and applies the "(EC)" prompt above.
EC_ENV_ACTIVE=1

unset ec_env_source ec_env_dump ec_var ec_value
unset ec_env_cache_dir ec_env_cache
unset -f ec_env_fail 2>/dev/null || true
true
