#include <stdio.h>

int main(void) {
    int month, day, year;

    // Read input like 01/01/2021
    if (scanf("%d/%d/%d", &month, &day, &year) != 3) {
        return 1; // bad input
    }

    // Print the month name (no newline here)
    switch (month) {
        case 1:  printf("January");   break;
        case 2:  printf("February");  break;
        case 3:  printf("March");     break;
        case 4:  printf("April");     break;
        case 5:  printf("May");       break;
        case 6:  printf("June");      break;
        case 7:  printf("July");      break;
        case 8:  printf("August");    break;
        case 9:  printf("September"); break;
        case 10: printf("October");   break;
        case 11: printf("November");  break;
        case 12: printf("December");  break;
        default:
            return 1; // invalid month
    }

    // Space + day number (still no newline)
    printf(" %d", day);

    // Suffix using grouped switch cases
    switch (day) {
        case 11: case 12: case 13:
            printf("th");
            break;
        case 1: case 21: case 31:
            printf("st");
            break;
        case 2: case 22:
            printf("nd");
            break;
        case 3: case 23:
            printf("rd");
            break;
        default:
            printf("th");
            break;
    }

    // Year with comma, space, period, and newline
    printf(", %d.\n", year);

    return 0;
}
