#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


Stack* stack_create(){
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack == NULL) {
        fprintf(stderr, "Memory allocation failed for stack.\n");
        return NULL;
    }
    pStack->top = 0;
    return pStack;
}

int fullStack(const Stack* pStack){
    int turth = 0;
    if (pStack == NULL) {
        printf("Stack is not exist.\n");
        turth = 1;
    }
    if(pStack->top >= STACK_LEN){
        printf("Stack is full. \n");
        turth = 1;
    }
    return turth;
}

int emptyStack(const Stack* pStack){
    int turth = 0;
    if (pStack == NULL) {
        printf( "Stack is not exist.\n");
        turth = 1;
    }
    if(pStack->top == 0){
        printf("Stack is empty. \n");
        turth = 1;
    }
    return turth;
}

void pushStack(Stack* pStack, int value){
    if (fullStack(pStack)){
        printf("Cannot push value.\n");
        return;
    }
    pStack->dataArr[pStack->top++] = value;
}

int popStack(Stack* pStack){
    int currenttop;
    if (emptyStack(pStack)){
        fprintf(stderr, "Cannot pop value.\n");
    }
    currenttop = topStack(pStack);
    pStack->top--;
    return currenttop;
}

int topStack(const Stack* pStack){
    if (emptyStack(pStack)){
        fprintf(stderr, "Cannot get top value.\n");
    }
    return pStack->dataArr[pStack->top - 1];
}

void clearStack(Stack** pStack){
    if (pStack != NULL) {
        free(*pStack);
        *pStack = NULL;
    }
}

void printStack(Stack* pStack){
    printf("Stack: ");
    for (int i = 0; i < pStack->top ; i++) {
        printf("%d ", pStack->dataArr[i]);
    }
    printf("\n");
}
