#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _node
{
	int data;			 // The value stored in the array
	struct _node *pNext; // Pointer to the next node in the queue

} NODE;

typedef struct _queue
{
	NODE *pHead; // Pointer to the front of the queue
	NODE *pEnd;	 // Pointer to the rear of the queue
	int size;	 // The current size of the queue
} Queue;

Queue *createQueue();				   // Function to create a new queue and initialize its members
NODE *createNode(int data);			   // Function to create a new node with the given data
void pushQueue(Queue *pQue, int data); // Function to add an element to the rear of the queue
void popQueue(Queue *pQue);			   // Function to remove an element from the front of the queue
int frontQueue(Queue *pQue);		   // Function to get the value of the front element in the queue
int backQueue(Queue *pQue);			   // Function to get the value of the rear element in the queue
void clearQueue(Queue *pQue);		   // Function to clear all elements from the queue and free memory

#endif
