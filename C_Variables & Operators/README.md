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



# C Basics: Operators & Expressions

---

## Arithmetic Operators (Mathematical Symbols)

C performs arithmetic on numbers and variables using these operators:

| Operator | Meaning            | Notes                                                                                                    |
| :------: | :----------------- | :------------------------------------------------------------------------------------------------------- |
|    `+`   | Addition           | Works with integer and floating‑point types.                                                             |
|    `-`   | Subtraction        | Unary `-` negates a value (e.g., `-x`).                                                                  |
|    `*`   | Multiplication     | —                                                                                                        |
|    `/`   | Division           | **Integer ÷ integer truncates toward zero**; use a float (`2.0`) for real division.                      |
|    `%`   | Remainder (modulo) | Only for integers. Result has the **same sign as the dividend** (e.g., `-7 % 3 == -1`).                  |
|   `++`   | Increment          | Prefix `++i` increments, then yields the new value. Postfix `i++` yields the old value, then increments. |
|   `--`   | Decrement          | Same prefix/postfix rules as `++`.                                                                       |

```c
int a = 7, b = 3;
printf("a+b=%d, a-b=%d, a*b=%d\n", a+b, a-b, a*b);
printf("int div=%d, real div=%.2f\n", a/b, (double)a/b); // 7/3 => 2 vs 2.33
printf("a%%b=%d\n", a % b);           // 7 % 3 => 1

int i = 5;
printf("%d %d %d\n", i, i++, ++i); // beware: side effects in one printf can confuse readers
```

> ⚠️ Avoid modifying the same variable more than once in a single expression (e.g., `i = i++ + ++i;`)—this can be undefined behavior.

---

## Assignment Operators

Assignment sets or updates variables. The expression value is the **assigned value**.

| Operator | Example   | Equivalent   |
| :------: | :-------- | :----------- |
|    `=`   | `x = 5;`  | —            |
|   `+=`   | `x += 3;` | `x = x + 3;` |
|   `-=`   | `x -= 2;` | `x = x - 2;` |
|   `*=`   | `x *= 4;` | `x = x * 4;` |
|   `/=`   | `x /= 2;` | `x = x / 2;` |
|   `%=`   | `x %= 3;` | `x = x % 3;` |

```c
int x = 10;
int y = (x += 5);   // x becomes 15; expression yields 15, so y == 15
int z;
z = y = x = 1;     // chaining: x=1, y=1, z=1 (right‑to‑left associativity)
```

> ℹ️ There are also compound bitwise/shift assignments (`&=`, `|=`, `^=`, `<<=`, `>>=`). See “Bitwise & Shift Operators” if you include that section.

---

## Comparison (Relational) Operators

These compare two values and produce **0** (false) or **1** (true). With `<stdbool.h>`, you can use `bool`, `true`, `false`.

| Operator | Meaning                  |
| :------: | :----------------------- |
|   `==`   | Equal to                 |
|   `!=`   | Not equal to             |
|    `<`   | Less than                |
|   `<=`   | Less than or equal to    |
|    `>`   | Greater than             |
|   `>=`   | Greater than or equal to |

```c
#include <stdbool.h>
int a = 5, b = 7;
bool eq = (a == b);       // 0 (false)
bool lt = (a < b);        // 1 (true)

// Beware of signed/unsigned mixes
unsigned u = 4000000000u; // large
int      s = -1;
printf("mix=%d\n", s < (int)u); // make conversions explicit

// Floating‑point equality is fragile
double d1 = 0.1 * 3;              // 0.300000...
double d2 = 0.3;
bool same = (fabs(d1 - d2) < 1e-9); // compare with a tolerance
```

---

## Logical Operators

Logical operators combine boolean‑like expressions. They use **short‑circuit** evaluation.

| Operator | Meaning     | Short‑circuit               |            |                            |
| :------: | :---------- | :-------------------------- | ---------- | -------------------------- |
|   `&&`   | Logical AND | Stops if left side is false |            |                            |
|    \`    |             | \`                          | Logical OR | Stops if left side is true |
|    `!`   | Logical NOT | —                           |            |                            |

```c
int denom = 0;
if (denom != 0 && (10 / denom) > 1) {
    // safe: right side evaluated only if denom != 0
}

// Precedence: !  >  &&  >  ||
int x = 3;
int ok = !(x < 0) && (x < 10) || (x == 42);
```

> 🔄 Don’t confuse logical operators with **bitwise** operators: `&&` vs `&`, `||` vs `|`, `!` vs `~`.

---

## Operator Precedence & Associativity (Quick View)

From higher to lower precedence (left/right associativity shown):

1. Postfix `i++`, `i--` (L→R)
2. Unary `++i`, `--i`, `!`, unary `-` (R→L)
3. `*`, `/`, `%` (L→R)
4. `+`,
