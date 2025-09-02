C Basics: Variable Names, Data Types, Assignment, and Casting
C Variable Names (Identifiers)

Identifiers must follow specific rules.

Key points

Use only letters, digits, and underscores (_).

The first character must be a letter (A–Z or a–z) or underscore.

Keywords are not allowed as full names (int ❌, int_count ✅).

// ✅ valid identifiers
int total;
double average_score;
char _temp;
int count2;

// ❌ invalid identifiers
int 2ndPlace;     // cannot start with a digit
int total-score;  // hyphen not allowed
int float;        // keyword 'float' not allowed

// ✅ keyword used as a prefix/suffix is fine
int int_count;


💡 Stick to snake_case for readability (e.g., max_value, user_id).

Data Types in C

Common fundamental types you’ll use often:

Type	Typical Use	Example Literals
int	Whole numbers	-3, 0, 42
float	Single-precision decimals	3.14f, -0.5f
double	Double-precision decimals	2.71828, 1e-3
char	Single byte character/code	'A', '\n', 65
int    age = 30;
float  ratio = 0.75f;   // note the 'f' suffix for float literals
double pi = 3.141592653589793;
char   initial = 'J';


⚠️ Sizes are implementation-dependent (e.g., int is commonly 4 bytes). Use <stdint.h> (int32_t, uint8_t, etc.) when exact sizes matter.

Setting Variables in C

Variables can be initialized at declaration or assigned later.

// Initialize at declaration
int count = 0;
double tax_rate = 0.23;

// Declare first, set later
char grade;
grade = 'A';

// Multiple declarations (use sparingly for clarity)
int x = 1, y = 2, z;   // z is uninitialized

// ⚠️ Uninitialized local variables have indeterminate values
int n;        // do not read before writing!
n = 10;       // now safe to use

// Constants
const double GRAVITY = 9.80665;  // cannot be modified after initialization

Variable Casting in C

Casting converts a value from one type to another. It can be implicit (automatic) or explicit (you request it).

Implicit casting (usual promotions/conversions)

int m = 5;
double d = m;   // int -> double (implicit), d becomes 5.0


Explicit casting (you control it)

double val = 5.9;
int truncated = (int)val;   // becomes 5 (fraction dropped)

// Avoid integer division: cast one operand to get floating-point math
int a = 7, b = 2;
double q1 = a / b;            // 3 (integer division, then promoted to 3.0)
double q2 = (double)a / b;    // 3.5 (desired)


Storing after cast

char c = 'A';         // typically 65
int code = (int)c;    // 65

double big = 1e20;
float smaller = (float)big;   // possible precision loss


⚠️ Casting does not change the original variable’s type—only the produced value. Watch for overflow and precision loss when narrowing (e.g., double → float, int → char).

Quick Tips

Prefer descriptive names (items_in_cart over iic).

Initialize locals when you can; it prevents bugs.

Use <stdint.h> for fixed-width integers in systems code.

When mixing integers and floats, cast intentionally to control the kind of arithmetic.

Minimal Example
#include <stdio.h>

int main(void)
{
    // Variable names & data types
    int    item_count = 3;
    double price_each = 19.99;
    char   currency = '$';

    // Setting later
    double total;
    total = item_count * price_each;        // int * double -> double (implicit)

    // Casting examples
    int    rounded_total = (int)total;      // explicit cast (truncate)
    double avg = (double)item_count / 2;    // avoid integer division

    printf("Items: %d\n", item_count);
    printf("Price each: %c%.2f\n", currency, price_each);
    printf("Total (double): %.2f\n", total);
    printf("Total (truncated int): %d\n", rounded_total);
    printf("Average (double): %.2f\n", avg);

    return 0;
}

gcc main.c -Wall -Wextra -Werror -o shop && ./shop


Happy coding! 🚀
