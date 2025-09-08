# C Basics: Pointers

---

## What Is a Pointer?

A **pointer** is a variable that stores the **memory address** of another object (or `NULL`). Addresses are typically printed in **hexadecimal**, but a pointer’s value is the address itself, not a number to do arithmetic on freely.

```c
int x = 42;          // an int object
int *px = &x;        // px holds the address of x
printf("x=%d, &x=%p, px=%p\n", x, (void*)&x, (void*)px);
```

> Use the `%p` format to print pointers and cast to `(void*)` per the C standard.

---

## Declaring Pointers

You can write `type *name;` or `type* name;`—the `*` binds to the **declarator**, not the type keyword.

```c
int* a;    // stylistic choice
int *b;    // same meaning
int *p, q; // p is pointer to int; q is int (watch out!)
```

> Prefer `int *p;` style and **one declarator per line** to avoid mistakes.

---

## Getting Addresses: `&`

Use the **address‑of** operator `&` to take an object’s address.

```c
int x = 7;
int *p = &x; // p points to x
```

---

## Dereferencing: `*`

The unary `*` operator **dereferences** a pointer (accesses the pointed‑to object).

```c
*p = 10;           // write through the pointer (changes x to 10)
int y = *p;        // read through the pointer
```

> Precedence tip: `(*p).member` accesses a struct member via pointer; `p->member` is shorthand.

---

## Null Pointers

A null pointer points to **no object**.

```c
#include <stddef.h>
int *p = NULL;            // or 0 in older code
if (p == NULL) { /* ... */ }
```

Always **check for `NULL`** before dereferencing pointers you didn’t allocate or initialize.

---

## Pointer Arithmetic

Adding/subtracting an integer to/from a pointer moves it by **that many elements** (scaled by `sizeof(*p)`).

```c
int a[3] = {10, 20, 30};
int *p = a;        // points to a[0]
int *q = p + 2;    // points to a[2]
printf("%d %d\n", *p, *q); // 10 30

ptrdiff_t d = q - p; // number of elements between pointers (type: ptrdiff_t)
```

> ⚠️ Pointer arithmetic is only defined **within the same array object** (or one‑past‑the‑end). Do not walk beyond.

---

## Arrays & Pointer Decay

Array expressions often **decay** to pointers to their first element.

```c
int a[4] = {1,2,3,4};
int *p = a;               // same as &a[0]
printf("%d %d\n", p[1], *(p + 1)); // both access a[1]

// sizeof difference
printf("sizeof a = %zu, sizeof p = %zu\n", sizeof a, sizeof p);
```

> `sizeof a` is the whole array in bytes (in this scope). `sizeof p` is the size of a pointer.

---

## Accessing Arrays with Pointers

```c
void print_ints(const int *p, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", *(p + i)); // or p[i]
    }
    puts("");
}
```

Pass both the **pointer** and the **length**; C does not carry array sizes.

---

## `const` and Pointers

`const` can apply to the **pointee**, the **pointer**, or both.

| Declaration           | Meaning                                                    |
| :-------------------- | :--------------------------------------------------------- |
| `const int *p`        | pointer to **const int** (can’t modify `*p`, can move `p`) |
| `int * const p`       | **const pointer** to int (can modify `*p`, can’t move `p`) |
| `const int * const p` | const pointer to const int                                 |

```c
const int v = 3; const int *cp = &v; // *cp is read‑only
int w = 5; int * const pinned = &w; // pinned always points to w
```

---

## `void *` (Generic Pointers) & Casting

`void *` can hold the address of any object type, but you must cast back to the proper type before dereferencing.

```c
void *buf = malloc(128);
// ... cast when using as a typed pointer
char *bytes = buf; // implicit in C (explicit cast optional)
free(buf);
```

---

## Pointer Comparisons

Pointers to the same array/object can be compared with `==`, `!=`, `<`, `>`, etc. Comparisons between unrelated objects are only defined for `==`/`!=`.

---

## Common Pitfalls

* **Uninitialized pointers** (wild pointers) — always initialize to a valid address or `NULL`.
* **Dangling pointers** — don’t use a pointer after the object goes out of scope or after `free`.
* **Double free** — never free the same allocation twice.
* **Mismatched allocation/ownership** — document who allocates/frees.
* **Pointer/array confusion** — remember `sizeof` and decay rules.
* **Aliasing/alignment** — don’t cast between unrelated pointer types; may violate strict aliasing or alignment.

---

## Quick Tips

* Use `%p` and cast to `(void*)` for printing addresses.
* Prefer `size_t`/`ptrdiff_t` for sizes and pointer differences.
* Keep pointer expressions simple; add parentheses to make order of operations clear.
* Check pointers against `NULL` when appropriate; validate lengths before dereferencing.

```bash
gcc -Wall -Wextra -Wpedantic main.c -o pointers
```

---

### Minimal Example

```c
#include <stdio.h>
#include <stddef.h>

void print_ints(const int *p, size_t n) {
    for (size_t i = 0; i < n; ++i) printf("%d ", p[i]);
    puts("");
}

int main(void)
{
    int a[3] = {10, 20, 30};
    int *p = a;               // &a[0]
    printf("a=%p p=%p\n", (void*)a, (void*)p);

    *p = 11;                  // change a[0]
    printf("first=%d second=%d third=%d\n", *p, *(p+1), p[2]);

    print_ints(a, sizeof a / sizeof *a);
    return 0;
}
```

```bash
gcc main.c -o demo && ./demo
```

---

*Happy coding!* 🚀
