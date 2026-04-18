#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resizeable_array.h"

const int BLOCK_SIZE = 10;

Array array_create(int init_size){
	Array arr;
	arr.size = init_size;
	arr.array = (int *)malloc(sizeof(int) * arr.size);
	return arr;
}

void array_append(Array *arr, int more_size){
  int *p = (int *)malloc(sizeof(int) * (arr->size + more_size));
  memset(p, 0, (sizeof(int) * (arr->size + more_size))); 
  memcpy(p, arr->array, sizeof(int) * arr->size);
  free(arr->array);
  arr->array = p;
  arr->size += more_size;
}

void array_free(Array *arr){
  free(arr->array);
  arr->array = NULL;
  arr->size = 0;
}

int array_size(const Array *arr){
  return arr->size;
}

int* array_at(Array *arr, int index){
  if (index >= arr->size){
    array_append(arr, (index+BLOCK_SIZE) - arr->size);
  }
  if (index < 0){
    fprintf(stderr, "Index out of bounds: %d\n", index);
    exit(EXIT_FAILURE);
  }
  return &(arr->array[index]);
}

void array_print(const Array *arr) {
  if (arr == NULL || arr->array == NULL) {
    printf("Array is empty or invalid.\n");
    return;
  }
  printf("[");
  for (int i = 0; i < arr->size-1; i++) {
    printf("%d", arr->array[i]);
    if (i < arr->size - 2) {
      printf(", ");
    }
  }
  printf("]\n"); 
}