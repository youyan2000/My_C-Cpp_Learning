# queue列队

## 文件关系

- queue.h：头文件，定义NODE、Queue结构体，声明所有队列操作函数，作为queue.c和main.c的接口。
- queue.c：源文件，实现queue.h中声明的所有队列操作函数，是功能核心。
- main.c：测试文件，调用queue.c中的函数，编写测试用例验证队列功能。

## 核心结构体

- NODE：存储data（元素数据）和pNext（指向后一个节点的指针）。
- Queue：存储pHead（队首指针）、pEnd（队尾指针）、size（队列大小）。

## 核心函数（声明在queue.h，实现在queue.c）

- createQueue()：创建空队列，初始化队首、队尾指针为NULL，size为0。
- createNode(int data)：创建新节点，存储指定数据，pNext初始化为NULL。
- pushQueue(Queue *pQue, int data)：入队，将新节点添加到队列尾部，更新队尾指针和size。
- popQueue(Queue *pQue)：出队，删除队首节点，更新队首指针和size，空队列时重置队尾指针。
- frontQueue(Queue *pQue)：返回队首元素的数据。
- backQueue(Queue *pQue)：返回队尾元素的数据。
- clearQueue(Queue *pQue)：清空队列，释放所有节点和队列结构体内存。

## main.c功能

调用上述函数，通过“创建队列→入队→出队→查询→清空”的流程，验证队列操作正确性并输出结果。