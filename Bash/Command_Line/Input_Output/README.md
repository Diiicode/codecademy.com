# Shell I/O: Redirection, Pipes, `cat` & `grep`

---

## Streams & File Descriptors (FDs)

Commands communicate via three standard streams:

| FD | Name     | Description        |
| -: | -------- | ------------------ |
|  0 | `stdin`  | input to a command |
|  1 | `stdout` | normal output      |
|  2 | `stderr` | error output       |

---

## Redirecting Output

Use `>` to **overwrite** a file with a command’s `stdout`; use `>>` to **append** to it.

```bash
# overwrite (create if missing)
echo "Hello" > hello.txt

# append to end
echo "Hello World!" >> greetings.txt
```

Redirect `stderr` separately or merge it with `stdout`:

```bash
cmd > out.log           # stdout → out.log
cmd 2> err.log          # stderr → err.log
cmd > all.log 2>&1      # both → all.log (order matters)
```

> Safety: to avoid accidental overwrite, enable noclobber (`set -o noclobber`) and use `>|` to intentionally override.

---

## Redirecting Input

Feed a file to `stdin` with `<`:

```bash
wc -w < poem.txt
```

Heredoc (inline input):

```bash
cat <<EOF
first line
second line
EOF
```

---

## Pipes `|`

A **pipe** sends the `stdout` of the command on the left to the `stdin` of the command on the right.

```bash
echo "Hello World" | wc -w   # → 2

# chaining
cat access.log | grep "ERROR" | wc -l
```

> Redirection reads/writes **files**; pipes connect **commands**.

---

## `cat` — Display Files

Print one or more files to the terminal (or into a pipeline).

```bash
cat poem.txt
cat poem.txt kitties.txt
```

> For paging large files interactively, prefer `less file.txt`.

---

## `grep` — Search

Search files for lines matching a **pattern**.

```bash
grep 'sonny' names.txt         # basic search

# case‑insensitive
grep -i 'sonny' names.txt

# recursive through a directory tree (files + subdirs)
grep -R 'sonny' .

# useful flags
# -n: line numbers, -H: show filenames, -I: skip binary, -F: fixed string (no regex)
grep -nHIF 'exact text' .

# count matches
grep -R "ERROR" logs/ | wc -l
```

> Quote patterns to prevent the shell from expanding special characters before `grep` sees them.

---

## Command Line Redirection (Summary)

Redirection uses operators to hook up files to command I/O:

```bash
# write new file (overwrite)
ls > directories_list.txt

# append to existing file
ls >> directories_list.txt

# split outputs
ls > out.txt 2> err.txt
```

---

## Bonus: Capture & Tee

Use `tee` to write to a file **and** pass the output down the pipeline.

```bash
dmesg | tee logs.txt | grep -i usb
# append with -a
dmesg | tee -a logs.txt
```

---

## Quick Tips

* Combine flags: `grep -Rni pattern .`
* Use `--` to stop option parsing if filenames start with `-` (e.g., `grep pattern -- -weird.txt`).
* Prefer `cat file | grep` → `grep pattern file` (UUOC) unless you need a pipeline.

---

### Minimal Session

```bash
$ echo "Hello" > hello.txt
$ echo "World" >> hello.txt
$ cat hello.txt
Hello
World
$ echo "one two three" | wc -w
3
$ grep -ni 'world' . -R
./hello.txt:2:World
```

---

*Happy piping!* 🔧
