#include <stdio.h>
#include <stdlib.h>
#include "note.h"

int main(void) {
    int num, pos, ret;

    // crate list
    List list = InitList();
    ret = CreateList(list);
    
    if (ret != 0) {
        if (ret == -2) {
            // 无有效数据时，允许重新输入
            printf("请重新创建链表：\n");
            CreateList(list);
        } else {
            return -1;
        }
    }

    // output initial list
    printf("\n=== 初始链表 ===");
    OutputList();

    // add elements to the specified location
    printf("\n请输入要插入的元素和位置（格式：数值 位置）：");
    while (scanf("%d %d", &num, &pos) != 2) {
        while (getchar() != '\n');
        printf("输入格式错误！请输入 数值 位置：");
    }
    AddtoList(num, pos);
    printf("\n=== 插入元素后的链表 ===");
    OutputList();

    // delete all negative numbers
    DelListData();
    printf("\n=== 删除负数后的链表 ===");
    OutputList();

    // reverse linked list
    InvertList();
    printf("\n=== 逆转后的链表 ===");
    OutputList();

    return 0;
}
