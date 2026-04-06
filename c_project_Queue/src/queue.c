#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue* createQueue() {
  Queue* pQue = (Queue*)malloc(sizeof(Queue));
  if (pQue == NULL) {
    printf("Memory allocation failed for queue.\n");
    return NULL;
  }
  pQue->pHead = NULL;
  pQue->pEnd = NULL;
  pQue->size = 0;
  return pQue;
}

NODE* createNode(int data) {
  NODE* pNode = (NODE*)malloc(sizeof(NODE));
  if (pNode == NULL) {
    printf("Memory allocation failed for node.\n");
    return NULL;
  }
  pNode->data = data;
  pNode->pNext = NULL;
  return pNode;
}

void pushQueue(Queue* pQue, int data) {
  if (pQue == NULL) {
    printf("Queue is not initialized.\n");
    return;
  }
  NODE* pNode = createNode(data);
  if (pNode == NULL) {
    printf("Failed to create a new node.\n");
    return; 
  }
  if (pQue->size == 0) {
    pQue->pHead = pNode;
    pQue->pEnd = pNode;
  } else {
    pQue->pEnd->pNext = pNode;
    pQue->pEnd = pNode;
  }
  pQue->size++;
}

void popQueue(Queue* pQue) {
  if (pQue == NULL || pQue->size == 0) {
    printf("Queue is empty or not initialized.\n");
    return;
  }
  NODE* tempNode = pQue->pHead;
  pQue->pHead = pQue->pHead->pNext;
  free(tempNode);
  pQue->size--;
  if (pQue->size == 0) {
    pQue->pEnd = NULL;
  }
}

int frontQueue(Queue* pQue) {
  if (pQue == NULL || pQue->size == 0) {
    printf("Queue is empty or not initialized.\n");
    return -1;
  }
  return pQue->pHead->data;
}

int backQueue(Queue* pQue) {
  if (pQue == NULL || pQue->size == 0) {
    printf("Queue is empty or not initialized.\n");
    return -1;
  }
  return pQue->pEnd->data;
}

void clearQueue(Queue* pQue) {
  if (pQue == NULL) {
    printf("Queue is not initialized.\n");
    return;
  }
  while (pQue->size > 0) {
     popQueue(pQue);
  }
  free(pQue);
}
