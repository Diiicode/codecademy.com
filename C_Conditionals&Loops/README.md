# C Basics: Conditionals

---

## Types of Conditionals

C provides several ways to branch:

* `if`, `else if`, `else`
* Ternary operator `?:`
* `switch`/`case`/`default`

---

## `if`, `else if`, `else`

An `if` tests an expression; non‑zero is **true**, zero is **false**.

```c
if (x == 3) {
    printf("x is 3!\n");
}
```

Chain conditions with `else if`, and add a final `else` for the fallback.

```c
if (x > 3) {
    puts("x is greater than 3");
} else if (x < 3) {
    puts("x is less than 3");
} else {
    puts("x equals 3");
}
```

> ⚠️ Common bug: `=` vs `==`. `if (x = 3)` assigns 3 to `x` and tests **true**. Enable warnings!

---

## Dangling `else`

`else` always binds to the **nearest unmatched** `if`.

```c
if (x > 0)
    if (x % 2 == 0)
        puts("positive even");
    else
        puts("not positive"); // actually binds to inner if

// Disambiguate with braces
if (x > 0) {
    if (x % 2 == 0)
        puts("positive even");
    else
        puts("positive odd");
} else {
    puts("not positive");
}
```

---

## Ternary Operator `?:`

A compact `if`/`else` that **yields a value**.

```c
int min = (a < b) ? a : b;

// As an expression
printf("%d\n", (x % 2 == 0) ? 2 : 1);

// Nesting: parenthesize for clarity
int clamp01 = (v < 0) ? 0 : ((v > 1) ? 1 : v);
```

> ℹ️ The ternary’s two result expressions should be of compatible types; otherwise implicit conversions apply.

---

## `switch` Statements

`switch` compares an integral expression against **constant** `case` labels.

```c
switch (grade) {
    case 9:  puts("Freshman");  break;
    case 10: puts("Sophomore"); break;
    case 11: puts("Junior");    break;
    case 12: puts("Senior");    break;
    default: puts("Invalid");   break;
}
```

**Rules & tips**

* `switch` works with integer types and `enum`s (not strings/floats).
* `case` labels must be **compile‑time constants** (literals, `enum` values, `#define`s).
* Without `break`, control **falls through** to the next case—use intentionally and comment it.
* You can declare variables inside a `case`, but add braces to create a scope if needed.

```c
enum Day { Mon=1, Tue, Wed, Thu, Fri, Sat, Sun };

switch (d) {
    case Sat:
    case Sun:
        puts("Weekend");
        break; // shared action via fallthrough
    default: {
        int hours = 8; // scoped to this block
        printf("Workday: %d hours\n", hours);
        break;
    }
}
```

---

## Operators inside Conditionals

Use logical operators to combine tests; evaluation is **short‑circuited**.

```c
// !  (NOT),  && (AND),  || (OR)
if (ptr != NULL && *ptr > 0) { /* right side only if ptr != NULL */ }

if (!(x < 0) && (x <= 100 || flag)) { /* precedence: ! > && > || */ }
```

---

## Quick Tips

* Use braces—even for single statements—in non‑trivial code to avoid the dangling‑`else` trap.
* Prefer `else if` chains for ordered checks; use `switch` for many discrete constants.
* Don’t compare floating‑point for exact equality—use an epsilon.
* Compile with warnings: `-Wall -Wextra -Wpedantic -Wshadow -Wconversion`.

```bash
gcc -Wall -Wextra -Wpedantic main.c -o conds
```

---

### Minimal Example

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x = 3, a = 5, b = 2;

    // if / else if / else
    if (x > 3) {
        puts("x > 3");
    } else if (x < 3) {
        puts("x < 3");
    } else {
        puts("x == 3");
    }

    // ternary
    int min = (a < b) ? a : b;
    printf("min=%d\n", min);

    // switch
    int grade = 11;
    switch (grade) {
        case 9:  puts("Freshman");  break;
        case 10: puts("Sophomore"); break;
        case 11: puts("Junior");    break;
        case 12: puts("Senior");    break;
        default: puts("Invalid");   break;
    }

    // logical operators
    bool ok = (min >= 0) && (min <= 10);
    printf("ok=%d\n", ok);

    return 0;
}
```

```bash
gcc main.c -o demo && ./demo
```

---

# C Basics: Loops

---

## Types of Loops

C provides three looping constructs:

* `while` — **pre‑check** loop (checks condition before each iteration)
* `do…while` — **post‑check** loop (executes body once, then checks)
* `for` — compact form with init, condition, and increment in one header

---

## `while` Loops (pre‑check)

Repeat **while** the condition is true; body may execute zero times.

```c
while (a < 10) {
    a++;
}
```

> 🧭 Ensure `a` changes or the loop can run forever.

---

## `do…while` Loops (post‑check)

Execute body **at least once**, then repeat while the condition is true. Note the **semicolon** after `while`.

```c
do {
    puts("running once, then checking…");
} while (2 == 3); // false → runs exactly once
```

---

## `for` Loops

A `for` packs **initialization**, **condition**, and **iteration** together.

```c
for (int i = 0; i <= 10; i++) {
    printf("Hello!\n");
}
```

Common pattern for arrays:

```c
#include <stddef.h>
int arr[] = {1,2,3,4,5};
for (size_t i = 0; i < sizeof arr / sizeof *arr; i++) {
    printf("%d\n", arr[i]);
}
```

> ℹ️ The parts are optional. `for (;;)` is a deliberate **infinite loop**.

---

## Loop Keywords: `break` and `continue`

* `break` — exit the **innermost** loop (or `switch`).
* `continue` — skip to the next iteration (in a `for`, it jumps to the increment step, then tests the condition).

```c
for (int i = 0; i < 10; i++) {
    if (i == 3) continue; // skip 3
    if (i == 7) break;    // stop entirely at 7
    printf("%d ", i);
}
```

---

## Rewriting Loops

Any `for` can be written as a `while`, and most `while`s can be written as a `for`.

```c
// for → while
for (int i = 0; i < n; i++) body(i);
{
    int i = 0;
    while (i < n) { body(i); i++; }
}

// while → for
while (cond) { work(); update(); }
// equivalent
for (; cond; update()) { work(); }
```

---

## Nested Loops & `break`

`break` exits only **one** level. To exit multiple levels, use a flag or refactor.

```c
for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
        if (found) { break; } // leaves inner loop only
    }
    if (found) { break; }     // now leaves outer
}
```

---

## Common Pitfalls

* **Off‑by‑one** errors: `i <= n-1` vs `i < n`.
* **Signed/unsigned** mixes in conditions: prefer `size_t` for sizes and `%zu` when printing.
* Forgetting the `do…while` **trailing semicolon**.
* Mutating the loop variable inside complex expressions; keep updates in one place.
* Non‑progressing conditions → infinite loops.

---

## Quick Tips

* Prefer `i < n` rather than `i <= n-1` for clarity.
* Use braces even for single‑statement bodies in non‑trivial code.
* Extract complex conditions into well‑named helper functions.
* For intentional infinite loops, provide a clear `break` path.

```bash
gcc -Wall -Wextra -Wpedantic main.c -o loops
```

---

### Minimal Example

```c
#include <stdio.h>
#include <stddef.h>

int main(void)
{
    // while
    int a = 0;
    while (a < 3) { printf("a=%d\n", a); a++; }

    // do…while (runs once)
    int flag = 0;
    do { puts("do body once"); } while (flag);

    // for over array
    int v[] = {10,20,30};
    for (size_t i = 0; i < sizeof v / sizeof *v; i++) {
        printf("v[%zu]=%d\n", i, v[i]);
    }

    // break & continue
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue; // odds only
        if (i > 5) break;         // stop at 7
        printf("i=%d\n", i);
    }

    return 0;
}
```

```bash
gcc main.c -o demo && ./demo
```

---

*Happy coding!* 🚀
