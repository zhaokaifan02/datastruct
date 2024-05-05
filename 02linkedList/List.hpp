#pragma once
#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
//双引号""当前目录下找 <>在库里找，当前迷路好不到才从库里找
#define LTDataType int

typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* pre;
}LTNode;
LTNode* BuyLTnode(LTDataType val);
//双向链表只需要画图分析清楚明白，不需要直接丢掉head->next就行，分析明白哪个指针先操作
//初始化
void ListInit(LTNode** pphead);
LTNode* ListInit();
//打印
void ListPrint(LTNode* head);
//尾插
void ListPushBack(LTNode* head, LTDataType val);
//尾删
void ListPopBack(LTNode* head);
//首插
void ListPushFront(LTNode* head,LTDataType val);
//首删
void ListPopFront(LTNode* head);

//查找
LTNode* ListFind(LTNode* head,LTDataType val);

//插入
void ListInsert(LTNode* head,LTNode* pos, LTDataType val);

//
void ListErase(LTNode* head,LTNode* pos);