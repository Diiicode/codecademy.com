#include <stdio.h>
#include <string.h>

int main(void) {
    int counter1[4] = {0, 0, 0, 0};
    int counter2[4] = {0, 0, 0, 0};

    char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
    char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

    /* Count for s1 */
    int i = 0;
    int n1 = (int)strlen(s1);
    while (i < n1) {
        char ch = s1[i];
        if (ch == 'a') counter1[0]++;
        else if (ch == 'b') counter1[1]++;
        else if (ch == 'c') counter1[2]++;
        else if (ch == 'd') counter1[3]++;
        /* spaces ignored */
        i++;
    }

    /* Count for s2 */
    i = 0;
    int n2 = (int)strlen(s2);
    while (i < n2) {
        char ch = s2[i];
        if (ch == 'a') counter2[0]++;
        else if (ch == 'b') counter2[1]++;
        else if (ch == 'c') counter2[2]++;
        else if (ch == 'd') counter2[3]++;
        /* spaces ignored */
        i++;
    }

    /* Compare counters */
    int flag = 0;
    int j = 0;
    while (j < 4) {
        if (counter1[j] != counter2[j]) {
            flag = 1;
            break;
        }
        j++;
    }

    if (flag == 0)
        printf("Anagram!\n");
    else
        printf("Not Anagram!\n");

    return 0;
}
