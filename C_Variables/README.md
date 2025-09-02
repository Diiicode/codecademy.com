C Variables: Naming, Types, Initialization, and Casting

Variable Names in C

Identifiers must follow C’s naming rules.

Key points

Use only letters, digits, and underscores: A–Z, a–z, 0–9, _

Must start with a letter

_ is technically allowed, but leading underscores are often reserved—avoid them.

Must not be a C keyword (e.g., int, return, for, …)

// ✅ valid
int count;
int count2;
int int_count;

// ❌ invalid
int 2count;   // starts with a digit
int for;      // 'for' is a keyword

// ⚠️ allowed but discouraged (leading underscore)
int _temp;

Data Types in C

The most common fundamental types you’ll use:

Type	Meaning
int	Integer (whole number)
float	Single-precision floating-point
double	Double-precision floating-point
char	Single byte character
int age = 21;
float price = 19.99f;            // note the 'f' suffix for float literals
double pi = 3.141592653589793;
char initial = 'D';              // single quotes for a single character

Setting (Declaring & Initializing) Variables

Variables can be initialized at declaration or assigned later.

int a = 10;        // declaration + initialization
int b;             // declaration only
b = 20;            // assignment later

int x = 1, y = 2, z = 3;  // multiple declarations (OK, but keep readable)


⚠️ Local (non-static) variables are not auto-initialized.
Using an uninitialized variable is undefined behavior.

Variable Casting (Type Conversion)

C performs implicit conversions in expressions and supports explicit casts.

Implicit conversion

double d = 5;      // int 5 implicitly becomes 5.0


Explicit cast

int i = 3;
double d = (double)i;     // explicit cast to double

int whole = (int)3.7;     // truncates to 3 (no rounding)


Common gotcha: integer division

int sum = 7;
int n = 2;

double avg_bad = sum / n;         // 7/2 == 3 (int division) → 3.0
double avg_ok  = (double)sum / n; // 7.0/2 == 3.5

Quick Tips

Prefer descriptive names: packet_count, user_age.

Avoid leading underscores; never use keywords as names.

Initialize variables before use.

Use explicit casts to control numeric behavior (especially in divisions).

Keep declarations close to where variables are used for clarity.

Minimal Example
#include <stdio.h>

int main(void)
{
    int count = 3;
    double total = 10.0;

    double average = total / (double)count; // 3.333...

    char letter = 'C';

    printf("count=%d, total=%.2f, average=%.3f, letter=%c\n",
           count, total, average, letter);
    return 0;
}

gcc main.c -o vars && ./vars


Happy coding! 🚀
