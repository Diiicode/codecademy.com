# C Basics: Syntax, Escape Sequences, Comments, and `gcc`

A quick, copy‑friendly reference for C newcomers. Drop this into your `README.md`.

---

## Syntax in C

The rules that dictate the correct format of code for a specific programming language are known as **syntax**.

**Key points**

* Every statement ends with a semicolon `;`.
* C is **case‑sensitive** (keywords, identifiers, functions, etc.).
* The compiler raises **errors** when syntax is incorrect.

```c
// Statements must end in a semicolon (;)
// ✅ correct
printf("Hello World!");

// ❌ error (missing semicolon)
printf("Hello World!")

// Code elements are case sensitive
// ✅ correct
printf("Hello World!");

// ❌ error (PRINTF is not the same as printf)
PRINTF("Hello World!");
```

---

## Escape Sequences

In C, an **escape sequence** is a non‑visual character embedded in a string.

Common sequences:

| Sequence | Meaning        |
| :------: | -------------- |
|   `\n`   | Newline        |
|   `\t`   | Horizontal tab |
|   `\\`   | Backslash      |
|   `\"`   | Double quote   |
|   `\0`   | Null character |

```c
// "\n" acts as a newline in a string
printf("Hello\nWorld!");
// Output:
// Hello
// World!

// "\t" acts as a tab in a string
printf("Hello\tWorld!");
// Output: Hello    World!
```

---

## Comments in C

Comments are ignored by the compiler and are useful for documenting code.

* **Line comments** start with `//` and continue to the end of the line.
* **Block comments** start with `/*` and end with `*/` and can span multiple lines.

```c
// Comments

/* This review content is
about comments and how they
can be used to document code */

// This is a line comment

/* This is a
block comment */
```

> ⚠️ Avoid nesting block comments (`/* ... /* ... */ ... */`) as this is not supported in C.

---

## Compiling C Code with `gcc`

`gcc` (GNU Compiler Collection) compiles C source files into executables.

* Without flags, the output executable is named **`a.out`**.
* Use `-o <name>` to set a custom output name.

```bash
# Compile to default output (./a.out)
gcc script.c

# Compile to a named executable
gcc script.c -o myProgram

# (Optional) add common warnings for better feedback
gcc -Wall -Wextra -Werror script.c -o myProgram
```

---

## Quick Tips

* Save files with a `.c` extension.
* Include headers you use (e.g., `#include <stdio.h>` for `printf`).
* Keep code formatted consistently for readability.

---

### Minimal Example

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, C!\n");
    return 0;
}
```

```bash
gcc main.c -o hello && ./hello
```

---

*Happy coding!* 🚀
