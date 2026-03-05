#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
    int value;
    struct _node* next;
} Node;

typedef struct _list {
    Node* head;
    Node* tail;
} List;


void add(List *plist, int number);//add to linked list
void print(List *plist);//print linked list
int toFind(List *plist, int number);//find a number in the linked list
void delete(List *plist, int number);//delete the element in linked list
void freeList(List *plist);//free the memory of linked list

#endif 