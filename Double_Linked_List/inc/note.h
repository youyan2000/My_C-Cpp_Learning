#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
    int value;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _list {
    Node* head;
    Node* tail;
} List;

List InitList();                       // initialize the linked list
int CreateList(List list);             // create linked list by user input
// Return value: 0 for success, -1 for initialization failure, -2 for no valid data
void add(List *plist, int number);     // add to linked list
int OutputList(List *plist);           // print linked list
int toFind(List *plist, int number);   // find a number in the linked list
void delete (List *plist, int number); // delete the element in linked list
void freeList(List *plist);            // free the memory of linked list

#endif 