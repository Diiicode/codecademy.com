# Git Essentials & Workflow (Cheat Sheet)

A practical, copy‑ready guide to the most useful Git commands and how they fit together.

---

## 1) What is Git?

A **distributed version control system**: every clone is a full repository with complete history. Work locally, then sync via remotes (e.g., GitHub, GitLab, Bitbucket).

---

## 2) Install & First‑Time Setup

```bash
# macOS
brew install git

# Ubuntu/Debian
sudo apt update && sudo apt install -y git

# Windows (winget)
winget install Git.Git
```

Configure your identity (once per machine):

```bash
git config --global user.name  "Your Name"
git config --global user.email "you@example.com"

# Helpful defaults
git config --global init.defaultBranch main
git config --global core.editor "code --wait"   # VS Code as editor
git config --global pull.rebase false            # use merge on pull (safe default)
```

View config:

```bash
git config --list --show-origin
```

---

## 3) Create or Clone a Repo

```bash
# New repo in current directory
git init

echo "# Project" > README.md
git add README.md
git commit -m "chore: initial commit"

# Clone existing
git clone https://github.com/org/repo.git
cd repo
```

Connect a remote later:

```bash
git remote add origin https://github.com/org/repo.git
git push -u origin main
```

---

## 4) Daily Flow (Typical)

```bash
git switch -c feature/login          # create & switch to a new branch
# ... edit files ...
git status                           # see changes
git add -A                           # stage all edits (or pathspecs)
git commit -m "feat(auth): add login form"

git fetch origin                     # update remote refs
git rebase origin/main               # (optional) replay on latest main
# resolve conflicts if prompted

git push -u origin feature/login     # first push sets upstream
```

Open a Pull Request/Merge Request on your platform, get review, then merge.

---

## 5) Staging & Ignoring

```bash
git add <file>        # stage changes
git restore --staged <file>   # unstage

echo "venv/\n*.log\n.DS_Store\n" >> .gitignore
git rm -r --cached venv        # stop tracking a previously committed path
```

> `.gitignore` rules apply only to **untracked** files. To ignore already‑tracked files, remove them with `git rm --cached` and commit.

---

## 6) Inspecting Changes & History

```bash
git status
git diff                 # unstaged vs working tree
git diff --staged        # staged vs HEAD
git log --oneline --graph --decorate --all

git show HEAD~1          # show a commit (or file at that commit)
```

---

## 7) Branching

```bash
git branch                         # list local branches
git branch -r                      # list remotes

# create/switch
git switch -c feature/x            # (modern) create and switch
git switch main                    # switch branches
# older style: git checkout -b feature/x
```

Rename branch:

```bash
git branch -m oldname newname
```

---

## 8) Merge vs Rebase (Quick)

**Merge** preserves history shape (safe, default):

```bash
git switch main
git fetch origin
git merge origin/main             # fast-forward if possible
```

**Rebase** rewrites your branch to replay on top of a base (clean linear history):

```bash
git switch feature/x
git fetch origin
git rebase origin/main
# resolve conflicts → git rebase --continue
```

> **Never rebase public/shared commits** others depend on. If needed, force‑push with safety: `git push --force-with-lease`.

---

## 9) Remotes, Fetch/Pull/Push

```bash
git remote -v                      # list remotes

git fetch origin                   # update remote tracking branches

# pull = fetch + merge (or rebase if configured)
git pull                           # from upstream of current branch

# push to upstream (set on first push with -u)
git push -u origin feature/x
```

Change upstream tracking:

```bash
git branch --set-upstream-to=origin/main main
```

---

## 10) Tags & Releases

```bash
git tag v1.0.0                     # lightweight tag
git tag -a v1.0.0 -m "release"      # annotated tag
git push origin v1.0.0
```

---

## 11) Stash (Shelve WIP)

```bash
git stash push -m "wip: half-done form"
git switch main
git stash list
git stash show -p stash@{0}
git stash apply stash@{0}          # keep in stash
git stash pop                      # apply + drop
```

---

## 12) Undoing & Recovery

```bash
# Discard local edits (dangerous)
git restore path/to/file           # to last committed version

# Unstage but keep changes
git restore --stage path

# New commit that reverses another (safe for shared history)
git revert <commit>

# Move branch pointer (local history rewrite)
git reset --soft  <commit>  # keep index & working tree
git reset --mixed <commit>  # default; keep working tree
git reset --hard  <commit>  # discard everything to that commit (danger!)

# Lifesaver: reflog tracks HEAD/branch movements
git reflog
```

---

## 13) Collaboration & Branching Models

* **Trunk‑based**: short‑lived feature branches → merge to `main` behind small PRs.
* **Git Flow** (heavier): `develop`, `release/*`, `hotfix/*`. Use only if you truly need it.

Commit message style (common conventions):

```
feat(ui): add dark mode toggle
fix(api): handle 401 on refresh
chore: bump dependencies
```

---

## 14) Useful Tools

```bash
# Pick specific commits onto your branch
git cherry-pick <commit>

# Find the first bad commit
git bisect start

# Who last changed each line
git blame path/to/file

# Move/rename tracked files
git mv old new

# Remove tracked files
git rm path
```

---

## 15) SSH Keys (GitHub/GitLab)

```bash
ssh-keygen -t ed25519 -C "you@example.com"
# press Enter to accept default path; set a passphrase
cat ~/.ssh/id_ed25519.pub   # copy to web UI → SSH keys

# test
ssh -T git@github.com
```

Use SSH remote URLs:

```bash
git remote set-url origin git@github.com:org/repo.git
```

---

## 16) .gitignore Basics

```
# Python
__pycache__/
*.pyc
.venv/

# Node
node_modules/

# OS
.DS_Store
Thumbs.db
```

Global ignore (machine‑wide):

```bash
echo "*.log\n.DS_Store" > ~/.gitignore_global
git config --global core.excludesfile ~/.gitignore_global
```

---

## 17) Submodules (if you must)

```bash
git submodule add https://github.com/org/other.git vendor/other
git submodule update --init --recursive
```

> Submodules pin a repo at a specific commit; they require explicit updates in clones and CI.

---

## 18) Troubleshooting

* **Detached HEAD**: `git switch -c fix/branch` to save work to a branch.
* **Accidentally committed secrets**: rotate the secret, then purge history with `git filter-repo` (or `git filter-branch`), force‑push, and notify consumers.
* **Permission denied (publickey)**: ensure your SSH agent has the key: `ssh-add ~/.ssh/id_ed25519`.
* **Ref rejected**: `git fetch --all --prune` → rebase/merge → push. Use `--force-with-lease` only when you know you rewrote history.

---

## 19) Minimal Sessions

**New project**

```bash
mkdir demo && cd demo
git init -b main
echo "# Demo" > README.md
git add README.md
git commit -m "chore: init"
git remote add origin git@github.com:me/demo.git
git push -u origin main
```

**Feature flow**

```bash
git switch -c feat/task-123
# edit files
git add -A && git commit -m "feat: implement"
git push -u origin HEAD
```

**Fix last commit message**

```bash
git commit --amend -m "fix: correct edge case"
```

---

*Happy versioning!* 🧭
