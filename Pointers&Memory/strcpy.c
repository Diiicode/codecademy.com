#include<stdio.h>
#include<string.h>
 
void copy(char* dst, char* src){
  while (*src != '\0')
  {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
  printf("%s", dst);
}
 
int main(){
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
  char dstString[sizeof(srcString) + 1];
  copy(dstString, srcString);
  printf("%s", dstString);
}
