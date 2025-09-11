# Shell Basics: File Operations (`cp`, `mv`, `rm`, `ls`)

---

## Command Options (Flags)

Most shell commands accept **options** that modify behavior, usually as short flags (e.g., `-r`, `-v`) and often long forms (e.g., `--recursive`, `--verbose`). Options come **before** positional arguments.

```bash
cmd -a -v source dest
cmd --all --verbose source dest
```

> Use `--` to end option parsing if a filename begins with `-` (e.g., `rm -- -weird.txt`).

---

## `cp` — Copy

Copy files or directories.

```bash
# Basic copies
cp file1 file1_copy
cp file1 file2 destination_folder/

# Copy directories (recursive)
cp -R src_dir dest_dir        # `-R` or `-r` (platform dependent)

# Preserve metadata & attributes (archive mode)
cp -a src_dir backup_dir      # recursive, preserves perms/ownership/timestamps

# Safety/utility flags
cp -i file.txt dest/          # interactive: prompt before overwrite
cp -n file.txt dest/          # no-clobber: do not overwrite
cp -u file.txt dest/          # update: copy if source is newer/nonexistent
cp -v file.txt dest/          # verbose output
```

> ⚠️ Copying into an existing directory places files **inside** it. Copying to a non‑existent path may create that path as a file (for single‑file copies).

---

## `mv` — Move/Rename

Move files into directories or **rename** files/dirs.

```bash
mv index.html website/        # move into directory
mv draft.txt final.txt        # rename
mv -i file.txt dest/          # prompt before overwrite
mv -n file.txt dest/          # no overwrite
mv -v file.txt dest/          # verbose
```

> ℹ️ On the same filesystem, `mv` is typically an atomic rename. Across filesystems, it behaves like copy‑then‑delete (may be slower).

---

## `rm` — Remove (Delete)

Delete files and (with recursion) directories.

```bash
rm file.txt                   # remove file
rm -r bad_selfies             # remove directory tree
rm -ri folder                 # recursive + interactive prompts
rm -f file.txt                # force (no prompt, ignore missing)
rm -rf dir                    # ⚠️ DANGEROUS: recursive + force
```

> ⚠️ `rm` permanently deletes. There is no trash/recycle bin by default. Double‑check paths; consider `-i` for safety.

---

## `ls` — List (Useful Options)

List directory contents.

```bash
ls -a    # include hidden files (dotfiles)
ls -l    # long format (perms, owner, size, time)
ls -t    # sort by modification time (newest first)
ls -lah  # common combo: long + all + human sizes
ls -lt   # long, sorted by time
```

Examples:

```bash
ls Desktop
resume.pdf
photo.png
```

---

## Globbing & Multiple Sources

Use wildcards to select multiple files.

```bash
cp *.png images/
mv report-??.pdf archive/
rm -- *.tmp
```

> Quote patterns if you want the shell to **not** expand them (e.g., pass the literal `*` to a command).

---

## Quick Tips

* Quote paths with spaces: `cp "My File.txt" dest/`.
* On macOS/BSD, prefer `-R` for recursive `cp`; GNU accepts `-r`/`-R`.
* For safer syncing/copies with progress and filtering, consider `rsync -av --progress src/ dest/`.
* Use `man cp`, `man mv`, `man rm`, `man ls` (or `--help`) for full docs.

---

### Minimal Session

```bash
$ mkdir -p demo/src demo/dst
$ echo hello > demo/src/a.txt
$ cp demo/src/a.txt demo/dst/
$ ls -l demo/dst
$ mv demo/dst/a.txt demo/dst/renamed.txt
$ rm -i demo/dst/renamed.txt
```

---

*Happy file wrangling!* 🗂️
