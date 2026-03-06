#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    int num, pos, ret;

    // crate list
    List Mylist = InitList();
    ret = CreateList(&Mylist);
    
    if (ret != 0) {
        if (ret == -2) {
            printf("Please create linked list again: \n");
            CreateList(&Mylist);
        } else {
            return -1;
        }
    }

    // output initial list
    printf("\n=== Initialized Linked List ===");
    OutputList(&Mylist);

    // add elements to the specified location
    printf("\n=== Insert Element ===");
    while (scanf("%d %d", &num, &pos) != 2) {
        while (getchar() != '\n');
        printf("Input format error! Please enter value and position: ");
    }
    AddtoList(&Mylist, num, pos);
    printf("\n=== After Inserting Element ===");
    OutputList(&Mylist);

    // delete all negative numbers
    DelListData(&Mylist);
    printf("\n=== After Deleting Negative Numbers ===");
    OutputList(&Mylist);

    // reverse linked list
    InvertList(&Mylist);
    printf("\n=== Reversed Linked List ===");
    OutputList(&Mylist);

    return 0;
}
