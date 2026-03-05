#include <stdio.h>
#include <stdlib.h>
#include "note.h"

List InitList() {
    List list;
    list.head = (Node*)malloc(sizeof(Node));
    if (list.head == NULL) {
        printf("Fail to allocate memory!\n");
        }
    list.head->prev = NULL;
    list.head->next = NULL;
    return list;
}

int CreateList(List *plist) {
    if (plist->head!=NULL){
        printf("List already exists!\n");
        return -1;
    }
    int data, count = 0;
    Node* p = plist->head;
    printf("Please enter data (enter -1 to end, up to 10 valid entries, -1 will not be stored): \n");
    while (1) {
        if (scanf("%d", &data) != 1) {
            while (getchar() != '\n');
            printf("Format error! Please enter an integer:\n");
            continue;
        }
        if (data == -1) {
            break;
        }
        if (count >= 10) {
            printf("You have already entered 10 effective data, automatically end input!\n");
            break;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed, failed to create linked list!\n");
            return -1;
        }
        newNode->value = data; // set value of new node
        newNode->next = NULL;  // new node is the new tail, so next is NULL
        newNode->prev = p;     // link new node to the previous node
        p->next = newNode;     // link previous node to the new node
        p = newNode;           // push p to the new tail
        count++;               // add count of effective data
        plist->tail = p;         // reassign tail to the new last node
    }
    if (count == 0) {
        printf("No valid data, failed to create linked list!\n");
        return -2;
    }

    printf("linkedlist created successfully,totally input %d effective nodes.\n", count);
    return 0;
}

void add(List *plist, int number){    
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node *last = plist->tail;
    if ( last != NULL ){
        last->next = p;
        plist->tail = p;
    }else{
        plist->head = p;
        plist->tail = p;
    }
}

int OutputList(List *plist){
    if (plist->head == NULL || plist->head->next == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    printf("Current list data: ");
    Node *p;
    for (p = plist->head ; p != NULL ; p = p->next){
        printf("%d ", p->value);
    }
    printf("\n");
    return 0;
}

int toFind(List *plist, int number){
    Node *p;
    int isFound = 0;
    for (p = plist->head ; p != NULL ; p = p->next){
        if (p->value == number){
            printf("Found %d in the list.\n", number);
            isFound = 1;
            break;
        }
    }
    return isFound;
}

void delete(List *plist, int number){
    Node *p,*q;
    q=NULL;
    p=plist->head;
    for(; p != NULL ; q=p , p=p->next){
        if( p->value == number){
            if ( q != NULL ){
                q->next = p->next;
            }else{
                plist->head = p->next ;
            }
            free(p);
            break;  
        }
    }
}

void freeList(List *plist){
    Node *p,*q;
    for(p = plist->head ; p != NULL ; p = q){
        q = p->next;
        free(p);
    }
}
