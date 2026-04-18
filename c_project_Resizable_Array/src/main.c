#include <stdio.h>
#include <stdlib.h>
#include "resizeable_array.h"

int main(){
  Array arr = array_create(5);
  printf("%d\n", array_size(&arr));
  *array_at(&arr, 0) = 42;
  printf("%d\n", *array_at(&arr, 0));

  int number=0;
  int cnt=0;
  printf("Now try to create your own array.\n");
  while (number != -1){
    printf("Enter a number (-1 to stop): ");
    scanf("%d", &number);
    if (number != -1){
      *array_at(&arr, cnt++) = number;
    }
  }
  array_print(&arr);
  array_free(&arr);
  return 0;
}