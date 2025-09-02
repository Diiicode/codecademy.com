# C Basics: Variables, Types, Initialization & Casting

---

## Variable Names (Identifiers)

Identifiers are the names you give to variables, functions, and more.

**Key points**

* Valid characters: letters (`A–Z`, `a–z`), digits (`0–9`), and underscore (`_`).
* The first character **should** be a letter. (Technically `_` is allowed, but names that begin with `_` are reserved for the implementation in many contexts—avoid.)
* Identifiers are **case‑sensitive** (`count` ≠ `Count`).
* You **cannot** use C keywords as identifiers (`int`, `for`, `return`, ...).

```c
// ✅ valid identifiers
int total_count;
double average2;
char file_path[256];

// ❌ invalid identifiers
int 2nd;         // cannot start with a digit
int for;         // keyword
int user-name;   // hyphen not allowed

// ⚠️ avoid leading underscores
int _temp;       // allowed, but reserved patterns like __temp or _X are problematic
```

> ℹ️ The C standard doesn’t set a strict max identifier length; compilers may impose limits. Use concise, meaningful names.

---

## Data Types in C

C has several fundamental types and modifiers. Sizes are implementation‑defined—use `sizeof` to check on your platform.

**Core arithmetic types**

| Category       | Common Types                                   | Notes                                                                                          |
| :------------- | :--------------------------------------------- | :--------------------------------------------------------------------------------------------- |
| Integers       | `char`, `short`, `int`, `long`, `long long`    | Each can be `signed` or `unsigned`. `char` may be signed or unsigned (implementation‑defined). |
| Floating‑point | `float`, `double`, `long double`               | `double` is the default in most math expressions.                                              |
| Boolean        | `_Bool` (or `bool` via `#include <stdbool.h>`) | `true` / `false` macros come from `<stdbool.h>`.                                               |

**Helpful headers**

* `<limits.h>` – integer ranges (`INT_MAX`, `CHAR_MIN`, ...)
* `<float.h>` – floating‑point ranges/precision (`DBL_MAX`, `FLT_EPSILON`, ...)
* `<stdint.h>` – fixed‑width integers (`int8_t`, `uint32_t`, `size_t`, ...)

**Printing values (printf)**

| Type                  | Example                 | `printf` format             |
| :-------------------- | :---------------------- | :-------------------------- |
| `int`                 | `int x = 42;`           | `%d`                        |
| `unsigned int`        | `unsigned u = 7;`       | `%u`                        |
| `long`                | `long L = 123L;`        | `%ld`                       |
| `long long`           | `long long LL = 123LL;` | `%lld`                      |
| `size_t`              | `size_t n = 10;`        | `%zu`                       |
| `char` (as character) | `char c = 'A';`         | `%c`                        |
| `float` / `double`    | `double d = 3.14;`      | `%f` (both print as double) |
| \`lon                 |                         |                             |
