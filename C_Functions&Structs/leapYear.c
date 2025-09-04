#include <stdbool.h>
#include <stdio.h>

bool leapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int	main(void)
{
	bool leap = leapYear(1990);
	printf("%d\n", (int)leap);
	return (0);
}
