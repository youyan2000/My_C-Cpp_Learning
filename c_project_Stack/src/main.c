#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack* pStack = stack_create();
    
    pushStack(pStack, 1);
    pushStack(pStack, 2);
    popStack(pStack);
    pushStack(pStack, 3);

    printStack(pStack);

    clearStack(&pStack);
    return 0;
}
