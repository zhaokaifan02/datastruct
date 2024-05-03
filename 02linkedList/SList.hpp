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
SListNode* SListFind(SListNode* phead, SLDataType val);
//在pos之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType val);
//pos之后插入
void SListInsertAfter(SListNode* pphead, SListNode* pos, SLDataType val);
//删除pos的
void SListErase(SListNode** pphead, SListNode* pos);
//删除pos之后的
void SListEraseAfter(SListNode** pphead, SListNode* pos);
//删除
void SListDestroy(SListNode** pphead);
//单链表结构适合头插头删 O（1）
//  尾删尾删或中间删 要O（n）不适合，要便利一遍

//链表单独存储数据，双向链表更适合

//单链表的意义在于，单链表是复杂数据结构的子结构。
//如临接表和哈希桶
//单链表会出很多练习题


//203 Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
