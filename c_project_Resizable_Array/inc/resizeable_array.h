#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
	int *array;      // Pointer to the array data
	int size;       // Current number of elements in the array
} Array;

Array array_create(int init_size);            // Creates a new array
void array_append(Array *arr, int more_size); // Appends a value to the end of the array
void array_free(Array *arr);                  // Frees the memory allocated for the array
int array_size(const Array *arr);             // Returns the current size of the array
int *array_at(Array *arr, int index);         // Retrieves the value at a specific index
void array_print(const Array *arr);           // Prints the contents of the array

#endif
