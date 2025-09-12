# Jupyter Notebook: Writing & Debugging (Quick Guide)

A focused walkthrough of launching, writing code, inspecting help, and debugging in Jupyter.

---

## Launching a Notebook

**From Anaconda Navigator** (GUI): open *Navigator* → *Launch* Jupyter Notebook.

**From terminal (Bash/zsh/Anaconda Prompt):**

```bash
jupyter notebook
```

* A browser tab opens to the **Notebook file browser**. Keep the terminal window open while Jupyter runs (press `Ctrl+C` in that terminal and confirm to stop the server).
* If a URL with a token prints in the terminal, open it in your browser.

---

## Creating & Renaming a Notebook

* In the file browser: **New → Python 3** (this selects the Python kernel).
* Click the title at the top to **rename** the notebook.

> Tip: Jupyter works best in Chrome, Firefox, or Safari.

---

## Cells, Running, and Output

A notebook is a list of **cells**. Each cell can be **Code** or **Markdown**.

**Run cells**

* **Shift+Enter** – run cell and go to next (inserts a new cell if needed)
* **Ctrl+Enter** – run cell, stay
* **Alt+Enter** – run cell and insert cell **below**

**Output rules**

* The value of the **last expression** in a code cell is displayed automatically.
* `print(...)` displays wherever it’s called.

```python
# Example
print("hello world")  # prints immediately
x = 2; y = 3
x + y                 # → 5 (last expression shows)

# To show both, print the first:
print(x + y)
x - y                 # →  -1
```

**Adding and editing cells**

* Toolbar **+** adds a cell. Keyboard: `A` (above), `B` (below).
* Switch type: `M` (Markdown), `Y` (Code). Enter/Exit edit vs command mode: `Enter` / `Esc`.

---

## Quick Data Play

```python
mynums = [1, 2, 3, 4, 5]
mynums          # shows the list

for n in mynums:
    print(n + 1)
```

**Pandas preview**

```python
import pandas as pd
pd.DataFrame(mynums, columns=["n"])  # small table
```

---

## Built‑in Help & Completion

**Object help** – append `?` or `??` (more detail) and run the cell:

```python
mynums?          # type, preview, docs
len?             # function docs
```

**Signature popup** – place cursor **inside parentheses** and press **Shift+Tab** (press multiple times to expand):

```python
mynums.sort()    # Shift+Tab shows arguments (e.g., reverse=True)
```

**Tab completion** – start typing then press **Tab** to see options:

```python
import pandas as pd
pd.D<Tab>        # suggests DataFrame, DatetimeIndex, ...
```

---

## Debugging

**Example error**

```python
x = 1 + 1
y = 1 - 1
z = x / y        # ZeroDivisionError
```

**Post‑mortem debugger** – run the magic in a new cell:

```python
%debug
```

An `ipdb>` prompt appears; inspect variables (`x`, `y`, `z`) and step through if needed. Exit with `exit()`.

**Common error**

```python
import panda as pd  # typo → ModuleNotFoundError: No module named 'panda'
```

Read the **last line** of the traceback for the root cause.

---

## Handy Notebook Magics (sampler)

```python
%lsmagic          # list available magics
%timeit expr      # quick timing
%pwd              # current directory
%matplotlib inline  # render plots inline (for matplotlib)
```

**Installing packages inside a notebook (modern IPython):**

```python
%pip install numpy pandas
```

---

## Kernel & Saving

* **Kernel → Restart** resets the Python state (clears variables).
* **Kernel → Interrupt** stops a long‑running cell.
* **File → Save and Checkpoint** saves the `.ipynb` and a checkpoint. Autosave runs periodically.
* **File → Download as** exports (HTML, Markdown, etc.).

---

## Close Down

* In the notebook: **File → Close and Halt**.
* In the terminal that launched Jupyter: `Ctrl+C` then confirm `y`.

---

### Mini Cheatsheet

* Run cell: `Shift+Enter` | Stay: `Ctrl+Enter` | New below: `Alt+Enter`
* New cell: `A`/`B` | Delete: `D` then `D` | Move: `Shift+K/J`
* Toggle type: `M` (Markdown) / `Y` (Code)
* Help: `?`, `??`, **Shift+Tab** | Complete: **Tab**

---

*Happy experimenting in Jupyter!* 🎯

