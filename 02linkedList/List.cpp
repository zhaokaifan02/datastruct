#include "List.hpp"


LTNode* BuyLTnode(LTDataType val)
{
     LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
     if(newNode==NULL)
     {
        printf("malloc fail\n");
        exit(-1);
     }
     newNode->data = val;
     newNode->pre = NULL;
     newNode->next = NULL;
     return newNode;
}

void ListInit(LTNode** pphead)
{
    //指针的地址，要修改元素了
    *pphead = BuyLTnode(-1);
    (*pphead)->next = *pphead;
    (*pphead)->pre = *pphead;
}
LTNode* ListInit()
{
    LTNode* head = BuyLTnode(01);
    head->next = head;
    head->pre = head;
    return head;
}
void ListPrint(LTNode* head)
{
    assert(head);
    printf("head<->");
    LTNode*p = head;
    while(p->next!=head)
    {
        printf("%d<->",p->next->data);
        p = p->next;
    }
    printf("head\n");
}

void ListPushBack(LTNode* head, LTDataType val)
{
    assert(head);
    LTNode* newNode = BuyLTnode(val);
    newNode->next = head; //后连头
    newNode->pre = head->pre; //前连原来的尾
    head->pre->next = newNode; //尾接新尾
    head->pre = newNode; //头接新尾
}

void ListPopBack(LTNode* head)
{
    assert(head);
    if(head->next ==head)
    {
        printf("list empty\n");
        return;
    }
    LTNode* dt = head->pre;
    dt->pre->next = head;
    head->pre = dt->pre;
    free(dt);   
}

void ListPushFront(LTNode* head,LTDataType val)
{
    assert(head);
    // LTNode* newNode = BuyLTnode(val);
    // //记住改四个就行了
    // newNode->next = head->next;
    // newNode->pre = head;
    // head->next->pre = newNode;
    // head->next = newNode;
    ListInsert(head,head->next,val);
}
void ListPopFront(LTNode* head)
{
    assert(head);
    if(head->next==head)
    {
        printf("list empty\n");
        return;
    }
    LTNode* dt = head->next;
    //一般删除
    head->next = dt->next;
    dt->next->pre = head;
    
}

LTNode* ListFind(LTNode* head,LTDataType val)
{
    assert(head);
    LTNode* p = head;
    while(p->next!=head)
    {
        p = p->next;
        if(p->data ==val)
            return p;
    }
    return NULL;
}

void ListInsert(LTNode* head,LTNode* pos, LTDataType val)
{
    assert(pos);
    assert(head);
    
    LTNode* newNode = BuyLTnode(val);
    newNode->next = pos;
    newNode->pre = pos->pre;
    pos->pre->next = newNode;
    pos->pre = newNode;
}
void ListErase(LTNode* head,LTNode* pos)
{
    assert(head);
    assert(pos);
    LTNode* dt = pos;
    pos->pre->next = dt->next;
    dt->next->pre = pos->pre;
    free(pos);
    pos=NULL;
}