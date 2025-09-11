# Shell Basics: Navigation & Files (Cheat Sheet)

---

## The Command Line

The command line lets you navigate the filesystem and run built‑in programs or scripts. On Unix, the interface is typically **Bash** and the prompt is `$`.

```bash
$
```

---

## Filesystem Structure

A computer’s filesystem is a **tree**. The root directory is `/`. Parents can have many children.

* **Absolute path**: starts with `/` (e.g., `/Users/sonny/Downloads`).
* **Relative path**: from the current working directory.
* **Parent**: `..` refers to the parent directory.

---

## `pwd` — Print Working Directory

```bash
$ pwd
/Users/sonny/Downloads
```

Shows the path from the root to your current directory.

---

## `mkdir` — Make Directory

Create a new directory at the given path (or in the current directory if no path is given).

```bash
$ mkdir new-directory
$ ls
old-directory    new-directory
```

> Tip: `mkdir -p path/to/nested/dir` creates parents as needed.

---

## `ls` — List

List the contents of a directory. With no arguments, lists the current directory.

```bash
$ ls Desktop
resume.pdf
photo.png
```

> Useful flags: `-l` (long), `-a` (hidden files), `-h` (human sizes): `ls -lah`.

---

## `cd` — Change Directory

Move around the filesystem using full paths, child names, or `..` for parent.

```bash
$ cd some-directory
$ cd ..
```

Other handy forms: `cd ~` (home), `cd -` (previous directory).

---

## `touch` — Create New File

Create an empty file (or update its timestamp if it exists) in the current directory.

```bash
$ touch grocery-list.txt
```

---

## Helper Commands & Shortcuts

* `clear` — clear the terminal screen
* **Tab** — autocomplete the current token
* **↑** / **↓** — cycle through command history

---

## Quick Tips

* Quote paths with spaces: `cd "My Files"` or escape: `My\ Files`.
* Hidden files start with a dot; show them with `ls -a`.
* Use absolute paths for scripts/automation; relative paths for convenience.

---

### Minimal Session

```bash
$ pwd
/Users/sonny
$ mkdir projects && cd projects
$ mkdir new-directory && ls
new-directory
$ touch notes.txt && ls -l
$ cd .. && pwd
/Users/sonny
```

---

*Happy navigating!* 🧭
