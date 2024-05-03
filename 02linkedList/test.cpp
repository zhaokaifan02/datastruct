#include "stdio.h"
#include "stdlib.h"
#include "SList.hpp"

int main()
{
    SListNode *phead = nullptr;
    SListPrint(phead);
    SListPushBack(&phead, 1);
    SListPushBack(&phead, 2);
    SListPushBack(&phead, 3);
    SListPrint(phead);
    SListPopBack(&phead);
    SListPrint(phead);
    SListPushFront(&phead,0);
    SListPushFront(&phead,-1);
    SListPrint(phead);
    SListPopFront(&phead);
    SListPrint(phead);

    SListNode* pos =SListFind(phead,2);
    if(pos)
    {
        printf("find!\n");
    }
    pos->data = 3;//可以修改
    SListPrint(phead);
    SListInsert(&phead,pos,99);
    SListPrint(phead);
    SListNode* pos1 =SListFind(phead,0);
    SListInsertAfter(phead,pos1,12);
    SListPrint(phead);

    SListErase(&phead,SListFind(phead,3));
    SListPrint(phead);
    SListDestroy(&phead);
    SListPrint(phead);
}