#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构体
typedef struct Node {
    int data;               // 节点数据
    struct Node *prev;      // 指向前驱节点的指针
    struct Node *next;      // 指向后继节点的指针
} DNode, *DLinkList;

DLinkList head = NULL;  // 全局头节点指针，方便各函数操作

// 函数功能：初始化双向链表（创建头节点）
// 入口参数：无
// 返回值：成功返回头节点指针，失败返回NULL
DLinkList InitList() {
    head = (DLinkList)malloc(sizeof(DNode));
    if (head == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    head->prev = NULL;
    head->next = NULL;
    return head;
}

// 函数功能：从键盘输入数据创建双向链表（-1结束，最多10个有效数据）
// 入口参数：无
// 返回值：0表示成功，-1表示初始化失败，-2表示无有效数据
int CreateList() {
    // 初始化头节点
    if (InitList() == NULL) {
        return -1;
    }

    int data, count = 0;
    DLinkList p = head;  // 指向尾节点的指针
    printf("请输入数据（输入-1结束，最多10个有效数据，-1不存入）：\n");
    
    while (1) {
        // 输入合法性检查
        if (scanf("%d", &data) != 1) {
            // 清空输入缓冲区
            while (getchar() != '\n');
            printf("输入格式错误！请输入整数：\n");
            continue;
        }

        if (data == -1) {
            break;  // 结束输入
        }

        if (count >= 10) {
            printf("已输入10个有效数据，自动结束输入！\n");
            break;
        }

        // 创建新节点
        DLinkList newNode = (DLinkList)malloc(sizeof(DNode));
        if (newNode == NULL) {
            printf("内存分配失败，创建链表失败！\n");
            return -1;
        }

        // 赋值并挂载节点
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = p;  // 新节点前驱指向当前尾节点
        p->next = newNode;  // 当前尾节点后继指向新节点
        p = newNode;        // 尾指针后移
        count++;
    }

    if (count == 0) {
        printf("无有效数据，链表创建失败！\n");
        return -2;
    }

    printf("链表创建成功，共输入%d个有效数据！\n", count);
    return 0;
}

// 函数功能：遍历输出双向链表的所有数据
// 入口参数：无
// 返回值：0表示成功，-1表示链表为空
int OutputList() {
    if (head == NULL || head->next == NULL) {
        printf("链表为空！\n");
        return -1;
    }

    DLinkList p = head->next;  // 跳过表头，指向第一个数据节点
    printf("当前链表数据：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

// 函数功能：在指定位置插入元素（位置从1开始）
// 入口参数：num：要插入的元素值（不能为-1）；position：插入位置
// 返回值：0成功，-1位置无效，-2输入数据非法，-3内存分配失败，-4链表未初始化
int AddtoList(int num, int position) {
    // 合法性检查
    if (num == -1) {
        printf("插入失败：不能插入-1！\n");
        return -2;
    }
    if (position < 1) {
        printf("插入失败：位置必须大于等于1！\n");
        return -1;
    }
    if (head == NULL) {
        printf("插入失败：链表未初始化！\n");
        return -4;
    }

    // 找到插入位置的前驱节点
    DLinkList p = head;
    int curPos = 0;
    while (p != NULL && curPos < position - 1) {
        p = p->next;
        curPos++;
    }

    // 位置超出链表长度（比如链表只有2个节点，插入位置4）
    if (p == NULL) {
        printf("插入失败：指定位置%d超出链表范围！\n", position);
        return -1;
    }

    // 创建新节点
    DLinkList newNode = (DLinkList)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("插入失败：内存分配失败！\n");
        return -3;
    }

    newNode->data = num;
    // 调整指针（核心：双向链表插入）
    newNode->prev = p;                // 新节点前驱指向p
    newNode->next = p->next;          // 新节点后继指向p的原后继
    if (p->next != NULL) {            // 如果p不是尾节点
        p->next->prev = newNode;      // p原后继的前驱指向新节点
    }
    p->next = newNode;                // p的后继指向新节点

    printf("元素%d已成功插入到位置%d！\n", num, position);
    return 0;
}

// 函数功能：删除链表中所有的负数
// 入口参数：无
// 返回值：0成功，-1链表为空，-2链表未初始化
int DelListData() {
    if (head == NULL) {
        printf("删除失败：链表未初始化！\n");
        return -2;
    }
    if (head->next == NULL) {
        printf("删除失败：链表为空！\n");
        return -1;
    }

    DLinkList p = head->next;  // 遍历指针
    int delCount = 0;          // 记录删除的节点数

    while (p != NULL) {
        DLinkList temp = p;    // 保存当前节点（防止删除后丢失指针）
        p = p->next;           // 先移动指针，避免删除后无法遍历
        
        if (temp->data < 0) {  // 是负数则删除
            // 调整指针
            temp->prev->next = temp->next;  // 前驱节点的后继指向当前节点的后继
            if (temp->next != NULL) {       // 如果不是尾节点
                temp->next->prev = temp->prev;  // 后继节点的前驱指向当前节点的前驱
            }
            free(temp);        // 释放内存
            delCount++;
        }
    }

    printf("删除完成，共删除%d个负数节点！\n", delCount);
    return 0;
}

// 函数功能：原地逆转双向链表（不创建新节点，仅调整指针）
// 入口参数：无
// 返回值：0成功，-1链表为空，-2链表未初始化
int InvertList() {
    if (head == NULL) {
        printf("逆转失败：链表未初始化！\n");
        return -2;
    }
    if (head->next == NULL) {
        printf("逆转失败：链表为空！\n");
        return -1;
    }

    DLinkList p = head->next;  // 遍历指针
    DLinkList q = NULL;        // 临时保存后继指针

    // 遍历调整每个节点的prev和next
    while (p != NULL) {
        q = p->next;           // 保存当前节点的后继
        // 交换prev和next指针
        p->next = p->prev;
        p->prev = q;
        // 移动到下一个节点（原后继）
        p = q;
    }

    // 调整头节点的后继（指向原尾节点）
    q = head->next;            // 原第一个节点（现在的尾节点）
    head->next = head->next->prev;  // 头节点指向原尾节点

    printf("链表已成功原地逆转！\n");
    return 0;
}

// 函数功能：修正函数（兼容实验要求的ReviseList，此处复用逆转功能）
// 入口参数：无
// 返回值：同InvertList
int ReviseList() {
    return InvertList();
}
