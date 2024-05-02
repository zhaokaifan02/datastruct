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
}