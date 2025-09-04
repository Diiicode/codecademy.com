# C Basics: Strings & Arrays

---

## Strings in C (null‑terminated `char` arrays)

In C, a **string** is a sequence of characters **ending with a null character** `\0`.

**Key points**

* A string is typically stored in a `char` array; it **must** include space for the trailing `\0`.
* String **literals** (e.g., `"hello"`) have static storage duration and are **not modifiable**; don’t write through a `char *` that points to a literal.
* `strlen(s)` returns the number of characters **before** the `\0` (not counting the terminator).

```c
// Creating strings
char s1[] = "Hello";                // array, size 6 -> {'H','e','l','l','o','\0'}
char s2[] = { 'H','i','\0' };       // explicit with terminator
const char *p = "Read‑only";        // pointer to string literal (do not modify)

// Accessing and modifying characters (arrays only)
s1[0] = 'Y'; // "Yello"
```

---

## Length: `strlen` vs `sizeof`

```c
#include <stdio.h>
#include <string.h>

char msg[] = "abc";     // 4 bytes: 'a','b','c','\0'
printf("strlen=%zu, sizeof=%zu\n", strlen(msg), sizeof msg); // 3, 4
```

* `strlen` counts characters up to `\0`.
* `sizeof array` yields the **total storage** in bytes **for arrays in the same scope**. When passed to a function, arrays **decay to pointers**, so `sizeof` no longer gives the element count.

---

## Concatenation: `strcat` / `strncat`

Ensure the destination has spare capacity for the added text **and** the null terminator.

```c
#include <string.h>
char buf[16] = "Hi";
strcat(buf, ", ");            // buf: "Hi, "
strncat(buf, "world!", sizeof buf - strlen(buf) - 1); // cap to avoid overflow
```

> ⚠️ `strcat`/`strcpy` don’t check bounds. Use the size‑capped forms (e.g., `strncat`) or `snprintf` for safer concatenation.

---

## Copying: `strcpy` / `strncpy` / `snprintf`

```c
char dst[8];
strcpy(dst, "abc");              // ok (fits)

// Safer patterns
dst[0] = '\0';
strncat(dst, "abcdef", sizeof dst - 1); // ensures null termination

// or use snprintf
snprintf(dst, sizeof dst, "%s", "abcdef");
```

> ℹ️ `strncpy` **does not always null‑terminate** when the source is too long; add `dst[n-1] = '\0'` if you use it.

---

## Arrays in C

An **array** stores many elements of the **same type** in contiguous memory.

```c
// Uninitialized
type name[ARRAY_SIZE];

// Initialized
type name[] = { element1, element2, element3 };

// First & last
first = name[0];
last  = name[arraySize - 1];
```

**Key points**

* Arrays have a **fixed length** known at creation time (not resizable).
* C performs **no bounds checks**—out‑of‑range access is **undefined behavior**.
* Use `size_t` for sizes/indices.

---

## Getting the Array Length (compile‑time scope)

```c
#define LEN(a) (sizeof(a) / sizeof *(a))

int nums[] = {1,2,3,4};
size_t n = LEN(nums); // 4 (only works where `nums` is an array, not a pointer)
```

> 🧭 When passing arrays to functions, also pass their length: arrays **decay to pointers**.

```c
void print_ints(const int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) printf("%d ", a[i]);
}
```

---

## Iterating Through Arrays

```c
int a[] = {10, 20, 30};
for (size_t i = 0; i < sizeof a / sizeof *a; ++i) {
    printf("a[%zu]=%d\n", i, a[i]);
}

// While loop variant
size_t i = 0;
while (i < sizeof a / sizeof *a) {
    // ...
    ++i;
}
```

---

## Multidimensional Arrays

C stores arrays in **row‑major** order.

```c
int m[2][3] = { {1,2,3}, {4,5,6} };       // initialized
int z[3][3] = {0};                        // zero‑initialized

printf("%d\n", m[1][2]); // 6
```

**Passing to functions**

```c
// With known 2nd dimension
void print2(int rows, int cols, int a[rows][cols]) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) printf("%d ", a[r][c]);
        puts("");
    }
}
```

> 📌 The rightmost dimension must be known to index correctly, unless you use C99 **variable length arrays** as shown (`a[rows][cols]`).

---

## Strings & Arrays Together: Accessing Characters

```c
char word[] = "pizza";
word[0] = 'P';                // modify a char in a mutable array
printf("%c %c\n", word[0], word[4]); // 'P' and 'a'
```

> ⚠️ Ensure there’s room for the terminator when building strings: `char buf[5] = "hello";` is **too small** (needs 6).

---

## Quick Tips

* Leave **one extra byte** for `\0` when allocating string buffers.
* Prefer `size_t` and the `%zu` format specifier for sizes.
* Don’t write to string literals: `const char *s = "hello";` is read‑only.
* `memset(arr, 0, sizeof arr)` zero‑fills an array.
* For dynamic/resizable sequences, consider dynamic allocation (`malloc`/`realloc`) or higher‑level containers (outside of ISO C).

```bash
gcc -Wall -Wextra -Wpedantic main.c -o arrays
```

---

### Minimal Example

```c
#include <stdio.h>
#include <string.h>

#define LEN(a) (sizeof(a) / sizeof *(a))

int main(void)
{
    // Strings
    char name[16] = "Ada";                  // room for growth
    strncat(name, " Lovelace", sizeof name - strlen(name) - 1);
    printf("name='%s' (len=%zu)\n", name, strlen(name));

    // Arrays
    int scores[] = { 10, 20, 30, 40 };
    size_t n = LEN(scores);
    printf("scores has %zu elements; first=%d last=%d\n", n, scores[0], scores[n-1]);

    // 2D array
    int grid[2][3] = { {1,2,3}, {4,5,6} };
    printf("grid[1][2]=%d\n", grid[1][2]);

    return 0;
}
```

```bash
gcc main.c -o demo && ./demo
```

---

*Happy coding!* 🚀
