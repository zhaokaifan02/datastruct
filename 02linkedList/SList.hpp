#pragma once
#define SLDataType int
#include "stdlib.h"
#include "stdio.h"
typedef struct SListNode
{
    SLDataType data;
    struct SListNode* next; //下一个结点的地址
}SListNode;

//本质很好理解，逻辑结构是想出来的，物理结构是实际存的
//头节点和头指针
//头指针指向第一个节点
//头节点是一个不放数据的head指针1
//创建节点

//传参数的指针地址问题，画个图就懂了地址的管理方式
SListNode* createSNode(SLDataType val);
void SListPrint(SListNode* phead); 
void SListPushBack(SListNode** pphead, SLDataType val);
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** pphead, SLDataType val);
void SListPopFront(SListNode** pphead);