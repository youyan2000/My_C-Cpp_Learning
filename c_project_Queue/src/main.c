#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
  Queue *pQue = createQueue();
  pushQueue(pQue, 10);
  pushQueue(pQue, 20);
  popQueue(pQue);
  pushQueue(pQue, 30);

  int f = frontQueue(pQue);
  int b = backQueue(pQue);
  printf("Front element: %d\n", f);
  printf("Back element: %d\n", b);

  clearQueue(pQue);
  return 0;
}
