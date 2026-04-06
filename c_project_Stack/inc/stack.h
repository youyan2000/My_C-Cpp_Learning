#ifndef _STACK_H_
#define _STACK_H_

#define STACK_LEN 10

typedef struct _stack{
	int dataArr[STACK_LEN]; // array to hold the stack elements
	int top;				// top of the stack
} Stack;

Stack *stack_create();					  // Creates a new stack and returns a pointer to it
void pushStack(Stack *pStack, int value); // Pushes a value onto the stack
int fullStack(const Stack *pStack);		  // Checks if the stack is full
int emptyStack(const Stack *pStack);	  // Checks if the stack is empty
void pushStack(Stack *pStack, int value); // Pushes a value onto the stack
int popStack(Stack *pStack);			  // Pops a value from the stack and returns it
int topStack(const Stack *pStack);		  // Returns the value at the top of the stack
void clearStack(Stack **pStack);		  // Clears the stack and frees the memory
void printStack(Stack *pStack);			  // Prints the elements in the stack

#endif
