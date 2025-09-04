#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *str) {
  char buffer[10];
  int limit = sizeof(buffer) - 1;
  buffer[limit + 1] = '\0';
  strncpy(buffer, str, limit);
  printf("Buffer content: %s\n", buffer);
}

int main() {
  char input[50];
  printf("Enter a string:");
  scanf("%10s", input);
  vulnerableFunction(input);
  return 0;
}
