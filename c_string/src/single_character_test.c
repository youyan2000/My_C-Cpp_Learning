/*Single character read/write test*/
#include <stdio.h>
int main(){
  int ch;

  while ((ch=getchar())!=EOF){
    putchar(ch);
  }

  printf("END");
  return 0;
}