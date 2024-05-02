#include "SList.hpp"
#include "assert.h"
SListNode* createSNode(SLDataType val)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if(newNode==nullptr)
    {
        printf("malloc fail\n");
        exit(-1);//结束程序
    } else
    {
        newNode->data = val;
        newNode->next = nullptr;
    }
    return newNode;
}
void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while(cur!=nullptr)
    {
        printf("%d->",cur->data);
        cur= cur->next;
    }
    printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLDataType val) 
{
    //传的是phead
    SListNode* newNode = createSNode(val);
    if(*pphead == nullptr)
    {
        *pphead = newNode;
        return; 
    }
    SListNode* cur = *pphead;
    if(cur->next!=nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void SListPopBack(SListNode** pphead)
{
    assert(pphead);
    //为空
    if(*pphead == nullptr)
    {
        return ;
    }
    //不为空
    SListNode* cur = *pphead;
    //只有一个节点
    if(cur->next == nullptr)
    {
        *pphead = nullptr; //清空
        free(cur); //释放
    } else {
        //不止一个节点
        while(cur->next->next!=nullptr)
        {
            //下一个不是空
            cur = cur->next;
        }
        //cur拿到最后一个了，删除掉
        free(cur->next);
        cur->next = nullptr;
    }

}

void SListPushFront(SListNode** pphead, SLDataType val)
{
    assert(pphead);
    //为空的时候
    SListNode* newNode = createSNode(val);
    if(*pphead==nullptr)
    {
        *pphead = newNode;
    } else {
        newNode->next = (*pphead);
        *pphead = newNode;
    }
}

void SListPopFront(SListNode** pphead)
{
    assert(pphead);
    if(*pphead==nullptr)
    {
        return;
    }
    SListNode* p = *pphead;
    if(p->next == nullptr)
    {
        //只有一个
        *pphead = nullptr;
        free(p);
    } else {
        //不止一个
        *pphead = p->next;
        free(p);
    }
}