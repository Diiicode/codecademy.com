# Shell Basics: Navigation & Files (Bash)

---

## The Command Line

The **command line** lets you navigate the filesystem and run programs/scripts. On Unix-like systems the default shell is often **Bash**. The prompt is commonly shown as `$`.

```bash
$   # waiting for your command
```

---

## Filesystem Structure

Files are organized as a **tree** of directories. The root directory is `/`. Each directory can have files and child directories.

* **Absolute path**: starts with `/` (e.g., `/usr/bin`).
* **Relative path**: from your current directory (e.g., `docs/report.txt`).
* **Home**: `~` expands to your home directory (e.g., `~/Downloads`).
* **Parent**: `..` refers to the parent directory.

---

## `pwd` — Print Working Directory

Displays the full path to your current directory.

```bash
$ pwd
/Users/sonny/Downloads
```

---

## `ls` — List

Lists directory contents. With no args, lists the current directory. Useful flags:

* `-l` long format (permissions, owner, size, date)
* `-a` include hidden entries (those starting with `.`)
* `-h` human‑readable sizes (on GNU/macOS)

```bash
$ ls Desktop
resume.pdf  photo.png
$ ls -lah
```

---

## `cd` — Change Directory

Moves around the filesystem.

```bash
$ cd some-directory      # into a child
$ cd ..                  # up to parent
$ cd /usr/local/bin      # absolute path
$ cd ~                   # to your home
$ cd -                   # back to previous directory
```

---

## `mkdir` — Make Directory

Creates directories. Use `-p` to create parent directories as needed.

```bash
$ mkdir new-directory
$ mkdir -p projects/2025/q3
$ ls
old-directory  new-directory  projects
```

---

## `touch` — Create/Update File Timestamp

Creates an empty file **or** updates the modified time if it exists.

```bash
$ touch grocery-list.txt
```

---

## Accessing Paths with Spaces

Quote or escape spaces.

```bash
$ cd "My Documents"
$ touch notes\ 01.txt
```

---

## Hidden Files & Globbing

* Files beginning with `.` are **hidden** (e.g., `.gitignore`).
* **Globbing**: use wildcards like `*` and `?` to match filenames.

```bash
$ ls -a            # show hidden files
$ ls *.png         # all .png files
$ ls report-?.pdf  # report-a.pdf, report-b.pdf, ...
```

---

## Helper Commands

* `clear` — clear the terminal screen
* `Tab` — autocomplete paths/commands
* `↑`/`↓` — cycle through command history (also `history` to list)

---

## Quick Tips

* Use `man <cmd>` or `<cmd> --help` for built‑in docs.
* Absolute paths avoid ambiguity; relative paths are shorter when working locally.
* Combine flags: `ls -lah`.
* Be careful with destructive commands (`rm -r`); consider `-i` for interactive prompts.

---

### Minimal Session

```bash
$ pwd
/Users/sonny
$ mkdir -p projects/demo
$ cd projects/demo
$ touch README.md
$ ls -lah
$ cd .. && pwd
/Users/sonny/projects
```

---

*Happy navigating!* 🧭
