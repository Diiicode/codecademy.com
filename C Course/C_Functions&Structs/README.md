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

```bash
gcc main.c -o demo && ./demo
```
---

# C Basics: Structures (`struct`)

---

## Defining a Structure

Use the `struct` keyword followed by a name and a brace‑enclosed list of **member variables** (not initialized in the definition).

```c
// `struct` keyword and structure tag
struct Person {
    char *name; // pointer to character data (string)
    int   age;
};
```

> ℹ️ The **relative order** of members is preserved, but compilers may insert **padding** for alignment. Use `sizeof` to inspect actual size.

---

## Initializing Structures

Initialize with **designated initializers** (C99+) or **positional** order.

```c
// Structure type
struct Person {
    char *name;
    int   age;
};

// Designated (order‑independent)
struct Person person1 = { .name = "Cosmo", .age = 36 };

// Positional (must follow member order)
struct Person person2 = { "George", 29 };

// Compound literal (C99+), e.g., for on‑the‑fly values
struct Person p = (struct Person){ .name = "Elaine", .age = 35 };

// Zero‑initialize all members
struct Person empty = {0};
```

> ✅ Designated initializers improve clarity; use them when there are many fields.

---

## Custom Data Types with `typedef`

`typedef` lets you omit the `struct` keyword at use‑sites.

```c
typedef struct Person {
    char *name;
    int   age;
} Person; // now `Person` is a type name

Person kramer = { .name = "Kramer", .age = 36 };
```

---

## Grouping Heterogeneous Data

Structures group different types into a single logical unit.

```c
struct Person {
    char *name;
    int   age;
    char  middleInitial; // single character
};
```

> ⚠️ Use single quotes for single characters (e.g., `'C'`), not string literals (`"C"`).

---

## Accessing Members: Dot and Arrow

* Use the **dot** operator (`.`) with a structure **object**.
* Use the **arrow** operator (`->`) with a **pointer** to a structure. (`p->x` is the same as `(*p).x`.)

```c
struct Person person1 = { .name = "George", .age = 28, .middleInitial = 'C' };
printf("My name is %s\n", person1.name); // dot

struct Person *personPtr = &person1;
printf("Age: %d\n", personPtr->age);     // arrow
```

> 🔎 Precedence reminder: write `(*p).x`, not `*p.x`.

---

## Structure Pointers & Dynamic Allocation

Create pointers to existing objects or allocate dynamically.

```c
struct Person jerry = { "Jerry", 29 };
struct Person *pj = &jerry; // pointer to existing object

#include <stdlib.h>
struct Person *dyn = malloc(sizeof *dyn);
if (dyn) {
    dyn->name = "Newman"; // for demo; string literal has static storage duration
    dyn->age = 37;
}
// ... use dyn ...
free(dyn);
```

> 📌 If you allocate or duplicate `name` dynamically, remember to `free` it later (and include `<string.h>` for copy helpers). `strdup` is POSIX, not ISO C.

---

## Passing Structures to Functions

By **value** (copies the entire struct) or by **pointer** (lets the callee mutate the original).

```c
// By value: read‑only view of the caller's data
void print_person(struct Person p) {
    printf("%s (%d)\n", p.name, p.age);
}

// By pointer: can modify caller state; add const for read‑only
void have_birthday(struct Person *p) {
    if (p) { p->age++; }
}

void show(const struct Person *p) { // cannot modify *p
    if (p) printf("%s is %d\n", p->name, p->age);
}
```

---

## Function Prototypes with Structures

Declare functions that use structure types so calls are checked for correctness.

```c
struct Person; // optional forward declaration for pointers
void myFunc(struct Person person1);
void myFuncPtr(struct Person *person1Pointer);
```

---

## Arrays, Nested, and Self‑Referential Structures

```c
// Array of structures
struct Person people[3] = {
    { "Jerry", 29 }, { "George", 29 }, { "Elaine", 28 }
};

// Nested structure
typedef struct {
    struct Person members[10];
    size_t count;
} Team;

// Self‑referential via pointer (common in linked lists)
struct Node {
    int value;
    struct Node *next; // pointer allows recursive shape
};
```

---

## Memory Layout & Padding (Quick Note)

Compilers may insert padding between members. This affects `sizeof` and binary I/O.

```c
#include <stddef.h> // offsetof
struct Example { char c; int i; };
printf("sizeof=%zu, off(i)=%zu\n", sizeof(struct Example), offsetof(struct Example, i));
```

> 🧠 Avoid comparing whole structs with `memcmp` (padding bytes may differ). Compare member‑wise. Simple **assignment** (`a = b;`) copies all members correctly.

---

## Flexible Array Members (C99+)

Use a trailing unsized array to store variable‑length data contiguously.

```c
typedef struct {
    size_t len;
    unsigned char data[]; // flexible array member (no size)
} Buffer;

Buffer *make_buf(size_t n) {
    Buffer *b = malloc(sizeof *b + n);
    if (b) { b->len = n; }
    return b;
}
```

---

## Quick Tips

* Prefer `typedef` for ergonomics, but keep the original `struct` name for debugging clarity.
* Initialize with designated initializers for readability.
* Be explicit about ownership of pointer members (who allocates/frees?).
* Pass large structs by pointer for performance; add `const` when not mutating.
* Use single quotes for `char` members; strings are `char *` or fixed arrays `char name[32]`.

```bash
gcc -Wall -Wextra -Wpedantic main.c -o structs
```

---

### Minimal Example

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *name; // points to string literal in this demo
    int         age;
} Person;

void birthday(Person *p) {
    if (p) { p->age++; }
}

int main(void)
{
    Person p1 = { .name = "Morty", .age = 13 };
    Person p2 = { "Summer", 17 };

    printf("%s is %d\n", p1.name, p1.age);   // dot
    Person *pp = &p2;                         // pointer
    birthday(pp);                             // mutate via pointer
    printf("%s is now %d\n", pp->name, pp->age); // arrow

    return 0;
}
```

```bash
gcc main.c -o demo && ./demo
```

---

*Happy coding!* 🚀

