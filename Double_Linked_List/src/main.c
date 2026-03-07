#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    int num, pos, ret;

    // crate list
    printf("\n=== Create Linked List ===\n");
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
    printf("\n=== Initialized Linked List ===\n");
    OutputList(&Mylist);

    // add elements to the specified location
    printf("\n=== Insert Element ===\n");
    printf("Please enter the value and position to insert (e.g., 5 2): ");
    while (scanf("%d %d", &num, &pos) != 2) {
        while (getchar() != '\n');
        printf("Input format error! Please enter value and position: ");
    }
    Addtolist(&Mylist, num, pos);
    printf("\n=== After Inserting Element ===\n");
    OutputList(&Mylist);

    // delete all negative numbers
    printf("\n=== Delete Negative Numbers ===\n");
    DelListData(&Mylist);
    OutputList(&Mylist);

    // reverse linked list
    printf("\n=== Reverse Linked List ===\n");
    InvertList(&Mylist);
    OutputList(&Mylist);

    freeList(&Mylist);
    return 0;
}
