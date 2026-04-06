#include <stdio.h>
#include <stdlib.h>
#include "note.h"

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

void print(List *plist){
    Node *p;
    for (p = plist->head ; p != NULL ; p = p->next){
        printf("%d ", p->value);
    }
    printf("\n");
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
