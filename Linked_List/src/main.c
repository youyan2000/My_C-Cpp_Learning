#include <stdio.h>
#include <stdlib.h>
#include "note.h"

int main(){
    List list;
    list.head = NULL;
    list.tail = NULL;

    int number;
    do{
        scanf_s("%d", &number);
        if(number != -1){
            add(&list, number);
        }
    }while (number != -1);

    print(&list);

    printf("Please enter a number to find: ");
    scanf_s("%d", &number);
    toFind(&list, number);

    printf("Please enter a number to delete: ");
    scanf_s("%d", &number);
    delete(&list, number);
    print(&list);
    
    freeList(&list);
    return 0;
}
