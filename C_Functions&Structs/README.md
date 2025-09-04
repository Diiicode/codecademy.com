# C Basics: Functions

---

## What Is a Function?

A **function** is a named, reusable block of code. It may accept **parameters** (inputs) and returns a single **value** (or nothing with `void`).

**Key points**

* Defined with a **return type**, **name**, and **parameter list**.
* In C, **arguments are passed by value** (the callee receives a copy). Use pointers to let functions modify caller state.
* A function must be **declared** (prototype) before it’s called, or defined earlier in the file.

---

## Standard Library Functions ("Built‑in")

Standard functions live in headers and are linked from the C standard library.

* Examples: `printf` (`<stdio.h>`), `rand`/`srand` (`<stdlib.h>`), `strlen` (`<string.h>`), `malloc`/`free` (`<stdlib.h>`)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, standard library!\n"); // from <stdio.h>
    printf("rand() = %d\n", rand());     // from <stdlib.h>
    return 0;
}
```

> ℹ️ These are library functions (not language keywords). Always include the **right header** so the compiler knows their signatures.

---

## Defining & Calling Functions

**Definition syntax**

```c
return_type function_name(parameter_declarations) {
    // body
    return value; // if non‑void
}
```

**Example**

```c
int add(int number1, int number2) {
    return number1 + number2;
}

int main(void) {
    int myNumber = add(5, 2); // call with arguments
    (void)myNumber;
    return 0;
}
```

---

## Function Signature

A signature consists of the **return type**, the **function name**, and the **typed** parameter list.

```c
// return type | name |      parameters
int            add    (int a, int b) { return a + b; }
```

* Every parameter must have a **type**. (C does not infer types.)
* To declare “no parameters”, use `void`: `int f(void);`

---

## Return Types (including `void`)

* Non‑`void` functions must `return` a value matching the declared type.
* `void` functions **return no value**; they can just use `return;` to exit early.

```c
int getOne(void) { return 1; }

void printNumber(int number) {
    printf("Your number is %d\n", number);
}
```

---

## Parameters & Arguments

* Parameters are **typed names** in the definition; arguments are the **values** passed at call‑site.
* Because C uses **pass‑by‑value**, modify caller state via **pointers**.

```c
int add(int a, int b) { return a + b; }

void increment_in_place(int *x) { // pointer parameter
    if (x) { (*x)++; }
}
```

---

## Storing Return Values

A function’s return value can be captured and reused.

```c
int sum = add(5, 2); // sum == 7
```

---

## Function Prototypes (Declarations)

A **prototype** advertises a function’s interface to the compiler.

```c
// prototype (declaration)
int add(int, int);

// ... later or in another file ...
int add(int a, int b) { return a + b; } // definition
```

* Put prototypes in headers (`.h`) and include them where needed.
* Prototypes enable type‑checking at call sites.

---

## Recursion (Optional)

Functions may call themselves. Provide a base case to stop.

```c
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
```

---

## Common Pitfalls

* **Missing headers/prototypes**: calling a function without a visible prototype is ill‑formed in modern C (compilers will error).
* **Wrong types**: mismatched argument or return types lead to UB. Match the prototype exactly.
* **Returning pointer to a local**: locals die at function exit—don’t return their addresses.
* **Modifying caller data**: remember arguments are copies; use pointers to mutate caller state.

---

## Quick Tips

* Keep functions short and focused; choose clear names.
* Place prototypes above `main` or in headers.
* Use `static` for functions intended for file‑local use (internal linkage).
* Consider `inline` (C99+) for tiny, performance‑critical helpers.

```bash
gcc -Wall -Wextra -Wpedantic main.c -o funcs
```

---

### Minimal Example

```c
#include <stdio.h>

// Prototypes
int add(int, int);
void print_sum(int, int);
void increment_in_place(int *x);

int main(void)
{
    int a = 5, b = 2;
    int s = add(a, b);          // store return value
    print_sum(a, b);            // call a void function
    increment_in_place(&a);     // mutate via pointer
    printf("s=%d, a(after)=%d\n", s, a);
    return 0;
}

// Definitions
int add(int x, int y) { return x + y; }

void print_sum(int x, int y) {
    printf("%d + %d = %d\n", x, y, add(x, y));
}

void increment_in_place(int *x) {
    if (x) { (*x)++; }
}
```

```bash
gcc main.c -o demo && ./demo
```

---

*Happy coding!* 🚀
