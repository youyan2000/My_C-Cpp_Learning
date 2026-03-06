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

List InitList();                                                  // initialize the linked list
int CreateList(List *plist);                                      // create linked list by user input
// Return value: 0 for success, -1 for initialization failure, -2 for no valid data
int Addtolist(List *plist, const int number, const int position); // add an element to the linked list at a specific position
// Return value: 0 for success, -1 for invalid number, -2 for invalid position, -3 for uninitialized list, -4 for memory allocation failure
int DelListData(List *plist);                                     // delete all negative numbers from the linked list
// Return value: 0 for success, -1 for empty list, -2 for uninitialized list
int InvertList(List *plist);                                      // reverse the linked list in place
// Return value: 0 for success, -1 for empty list, -2 for uninitialized list
Node toFind(List *plist, const int position);                     // find the element at a specific position in the linked list
void delete (List *plist, int position);                          // delete the element at a specific position in the linked list
void freeList(List *plist);                                       // free the memory of linked list
int OutputList(List *plist);                                      // print linked list

#endif 