/*Maximum Allocatable Memory Test*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  void *p;
  int cnt=0;
  
  while ((p=malloc(100*1024*1024))){
    cnt++;
  }
  printf("Allocated %d00 MB of space.\n",cnt);
  free(p);

  return 0;
}