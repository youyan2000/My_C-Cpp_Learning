#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node toFind(List *plist, int position){
    Node *p = plist->head;
    int curPos = 0;
    while (p->next != NULL && curPos < position - 1) {
        p = p->next;
        curPos++;
    }
    return *p;
}

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
        plist->tail = p;       // reassign tail to the new last node
    }
    if (count == 0) {
        printf("No valid data, failed to create linked list!\n");
        return -2;
    }

    printf("linkedlist created successfully,totally input %d effective nodes.\n", count);
    return 0;
}

int Addtolist(List *plist, const int number, const int position){    
    if (number == -1) {
        printf("fail to add: cannot add -1!\n");
        return -1;
    }
    if (position < 1) {
        printf("fail to add: position must be a positive integer!\n");
        return -2;
    }
    if (plist->head == NULL) {
        printf("fail to add: list not initialized!\n");
        return -3;
    }
    
    Node *p;
    *p = toFind(plist, position);
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("fail to add: memory allocation failed!\n");
        return -4;
    }
    newnode->value = number;
    newnode->prev = p;
    newnode->next = p->next;

    if (p->next != plist->tail->next) {
        p->next->prev = newnode;
    }
    p->next = newnode;

    printf("element %d has successfully added to position %d.\n", number, position);
    return 0;
}

int DelListData(List *plist) {
    if (plist->head == NULL) {
        printf("fail to delete: list not initialized!\n");
        return -2;
    }
    if (plist->head->next == NULL) {
        printf("fail to delete: list is empty!\n");
        return -1;
    }
    Node *p = plist->head->next;
    int delCount = 0;
    while (p != plist->tail->next) {
        Node *temp = p;
        p = p->next;
        
        if (temp->value < 0) { 
            temp->prev->next = temp->next; 
            if (temp->next != plist->tail->next) {
                temp->next->prev = temp->prev; 
            }
            free(temp);
            delCount++;
        }
    }
    printf("Delete successful, totally deleted %d negative nodes.\n", delCount);
    return 0;
}

int OutputList(List *plist){
    if (plist->head == NULL || plist->head->next == NULL) {
        printf("fail to output: list is empty!\n");
        return -1;
    }
    printf("Current list data: [ ");
    Node *p;
    for (p = plist->head ; p != NULL ; p = p->next){
        printf("%d ", p->value);
    }
    printf("]\n");
    return 0;
}


int InvertList(List *plist) {
    if (plist->head == NULL) {
        printf("fail to invert: list not initialized!\n");
        return -2;
    }
    if (plist->head->next == NULL) {
        printf("fail to invert: list is empty!\n");
        return -1;
    }

    Node *p = plist->head->next;
    Node *q = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = p->prev;
        p->prev = q;
        p = q;
    }

    Node *oldFirst = plist->head->next;
    plist->head->next = plist->head->prev;
    plist->tail = oldFirst;

    printf("linked list inverted successfully!\n");
    return 0;
}

void delete(List *plist, int position){
    Node *p,*q;
    *p = toFind(plist, position);
    q=NULL;
    if (p->next != plist->tail->next) {
        p->next->prev = p->prev;
    }
    p->prev->next = p->next;
    free(p);
}

void freeList(List *plist){
    Node *p,*q;
    for(p = plist->head ; p != plist->tail->next ; p = q){
        q = p->next;
        free(p);
    }
}
