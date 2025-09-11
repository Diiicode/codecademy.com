# Bash Scripting: Args, Variables, `read`, Shebang, Aliases & Comparisons

---

## Bash Scripts

A **Bash script** is a text file containing commands you could type in a terminal. Save as `*.sh`, make it executable, and run it.

```bash
chmod +x saycolors.sh
./saycolors.sh
```

---

## Shebang

The first line selects the interpreter.

```bash
#!/usr/bin/env bash   # portable
# or
#!/bin/bash           # common on Linux/macOS
```

> Put the shebang on **line 1** with no leading spaces.

---

## Script Arguments (Positional Parameters)

Arguments follow the script name. Inside the script use `$1`, `$2`, `$3`, …

```bash
#!/usr/bin/env bash
# invoked as: ./saycolors.sh red green blue

echo "$1"   # red
echo "$2"   # green
echo "$3"   # blue
```

**Useful parameters**

| Token   | Meaning                                           |
| :------ | :------------------------------------------------ |
| `$0`    | script name                                       |
| `$#`    | number of args                                    |
| `$@`    | all args as separate words (preserves boundaries) |
| `$*`    | all args as one word (don’t use)                  |
| `shift` | drop `$1` and shift remaining                     |
| `$?`    | exit status of last command                       |
| `$$`    | current process ID                                |

```bash
for arg in "$@"; do echo "arg=$arg"; done
```

---

## Variables

Assign with `name=value` (no spaces). Expand with `$name`; quote to keep spaces intact.

```bash
greeting="Hello"
echo "$greeting"

# braces avoid ambiguity
echo "${greeting}, world"
```

> Prefer **double quotes** around expansions: `"$var"`.

---

## `read` — Prompting for Input

Reads a line from stdin into variables. `-p` prompts, `-r` disables backslash escapes, `-s` silent (password), `-t` timeout.

```bash
#!/usr/bin/env bash
read -p "Press Enter to continue" _
read -r -p "Enter your name: " name
read -s -p "Password: " pass; echo
```

---

## Aliases

Create shortcuts for commands (work in the current shell). Add to `~/.bashrc` (or `~/.bash_profile` on macOS) to persist.

```bash
alias saygreen='./saycolors.sh "green"'
```

> Aliases don’t expand in non‑interactive shells by default—use shell functions in scripts instead.

---

## String Comparisons

Prefer `[[ ... ]]` (Bash) over `[ ... ]` (POSIX `test`) for safer parsing.

```bash
word1="Hello"; word2="Hello"; word3="hello"

if [[ $word1 == $word2 ]]; then
  echo "Strings are equal"
fi

if [[ $word1 != $word3 ]]; then
  echo "Strings are not equal"
fi

# Pattern matching with [[ ]]
if [[ $word3 == h* ]]; then echo "starts with h"; fi
```

> With `[ ... ]`, **always quote** variables to avoid globbing/splitting: `[ "$a" = "$b" ]`.

---

## Integer Comparisons & Arithmetic

Use `-eq`, `-ne`, `-lt`, `-le`, `-gt`, `-ge` with `[ ]` / `[[ ]]`. Or use arithmetic contexts.

```bash
n=3
if [[ $n -lt 10 ]]; then echo "n<10"; fi

# Arithmetic evaluation (no $ inside (( ... )))
(( n++ ))
if (( n % 2 == 0 )); then echo "even"; fi
```

---

## Exit Status in Conditionals

Any command’s **exit code** drives `if`/`&&`/`||`.

```bash
if grep -q "ERROR" app.log; then
  echo "Found errors"
else
  echo "No errors"
fi

make build && echo "ok" || echo "failed"
```

---

## Quick Tips

* Start scripts with safety flags when appropriate:

  ```bash
  set -euo pipefail
  IFS=$'\n\t'
  ```

* Use `shellcheck` to lint your scripts.

* Keep quoting tight: `"$var"`, iterate with `"$@"`, not `$*`.

* Watch for Windows line endings; ensure scripts use **LF** (Unix), not CRLF.

---

### Minimal Example

```bash
#!/usr/bin/env bash
set -euo pipefail

main() {
  echo "Script: $0 (args: $#)"

  if [[ $# -lt 1 ]]; then
    echo "Usage: $0 <color> [name]" >&2
    exit 1
  fi

  color=$1; shift
  name=${1:-"world"}

  [[ $color == green ]] && alias saygreen='echo GREEN' || true

  read -r -p "Proceed (y/n)? " ans
  if [[ $ans == y* ]]; then
    printf "Hello, %s in %s!\n" "$name" "$color"
  else
    echo "Aborted"
  fi
}

main "$@"
```

```bash
chmod +x demo.sh
./demo.sh blue Ada
```

---

*Happy scripting!* 🧰
