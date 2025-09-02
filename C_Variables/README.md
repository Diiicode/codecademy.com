C Variables — Names, Types, Initialization & Casting

A quick, copy-friendly reference for your README.md.

✅ Naming Rules

Letters, digits, and underscores only: A–Z, a–z, 0–9, _

Must start with a letter

Technically _ is allowed, but many _... names are reserved by the implementation—avoid leading underscores.

Must not be a C keyword (e.g., int, return, for)

Examples

int count;         // ✅ valid
int count2;        // ✅ valid
int int_count;     // ✅ valid

int 2count;        // ❌ starts with a digit
int for;           // ❌ 'for' is a keyword
int _temp;         // ⚠️ allowed, but avoid leading underscore

🧱 Core Data Types

The main built-ins you’ll use most:

int — whole numbers

float — single-precision real numbers

double — double-precision real numbers

char — single byte character

Examples

int age = 21;
float price = 19.99f;           // note the 'f' suffix for float literals
double pi = 3.141592653589793;
char initial = 'D';             // single quotes for a single character

✍️ Declaring & Initializing

Variables can be initialized at declaration or assigned later.

int a = 10;        // declaration + initialization
int b;             // declaration only
b = 20;            // assignment later

int x = 1, y = 2, z = 3;  // multiple declarations (use judiciously)


Heads-up: Local variables are not auto-initialized in C. Using an uninitialized variable is undefined behavior.

🔀 Casting (Type Conversion)

C does implicit conversions in expressions and supports explicit casts.

Implicit

double d = 5;        // int 5 implicitly becomes 5.0


Explicit

int i = 3;
double d = (double)i;    // explicit cast to double

int whole = (int)3.7;    // truncates to 3 (no rounding)


Common gotcha: integer division

int sum = 7;
int n = 2;

double avg_bad = sum / n;             // 7/2 == 3 (int) → 3.0
double avg_ok  = (double)sum / n;     // 7.0/2 == 3.5

🧩 Quick Checklist

 Identifier starts with a letter, uses only letters/digits/underscores

 Not a keyword

 Initialized before use

 Use explicit casts to control numeric behavior (esp. division)

 Avoid leading underscores in names

🧪 Mini Demo
#include <stdio.h>

int main(void) {
    int count = 3;
    double total = 10.0;

    double average = total / (double)count; // 3.333...

    char letter = 'C';

    printf("count=%d, total=%.2f, average=%.3f, letter=%c\n",
           count, total, average, letter);
    return 0;
}

gcc main.c -o vars && ./vars
