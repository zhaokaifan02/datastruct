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

SListNode* SListFind(SListNode* phead, SLDataType val)
{
    if(phead==nullptr)
        return nullptr; //返回空
    SListNode *cur = phead; //规范化
    while(cur!=nullptr)
    {
        if(cur->data==val)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType val)
{
    //不需要检查pos是否不存在，一般都是find来的
    //找到前一个的地址
    //如果pos == phead
    if(pos ==*pphead)
    {
        SListPushFront(pphead,val);
    } else {
        //不是头的话
        SListNode* pre = *pphead;
        while(pre->next!=pos)
        {
            pre=pre->next;
        }
        SListNode *newNode = createSNode(val);
        newNode->next = pre->next;
        pre->next = newNode;
    }
}

void SListInsertAfter(SListNode* pphead, SListNode* pos, SLDataType val)
{
    assert(pos);
    SListNode* newNode = createSNode(val);
    newNode->next = pos->next;
    pos->next = newNode;
}

//之前的
void SListErase(SListNode** pphead, SListNode* pos)
{
    assert(pphead);
    assert(pos);
    if(*pphead ==pos)
    {
        free(pos);
        *pphead = nullptr;
    } else {
        SListNode* p = *pphead;
        while(p->next!=pos)
        {
            p=p->next;
        }
        p->next = pos->next;
        free(pos);
    }
}

void SListEraseAfter(SListNode** pphead, SListNode* pos)
{
    assert(pphead);
    assert(pos);
    SListNode* p = pos->next;
    pos->next = p->next;
    free(p);
}

void SListDestroy(SListNode** pphead)
{
    assert(pphead);
    SListNode* p = *pphead;
    SListNode* t = p;
    while(p->next!=nullptr)
    {
        p = p->next;
        free(t);
        t = p;
    }
    *pphead = nullptr;
}   