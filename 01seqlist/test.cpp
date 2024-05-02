#include "seqList.hpp"

int main()
{
    SeqList S;
    SeqListInit(&S);
    SeqListPushBack(&S,1);
    SeqListPushBack(&S,2);
    SeqListPushBack(&S,3);
    SeqListPushBack(&S,4);
    SeqListPushBack(&S,5);
    SeqPrint(&S);
    SeqListPopBack(&S);
    SeqPrint(&S);
    seqListPushFront(&S,0);
    seqListPushFront(&S,-1);
    SeqPrint(&S);

    seqListPopFront(&S);
    SeqPrint(&S);

    seqListInsert(&S,3,999);
    SeqPrint(&S);

    seqListErase(&S,2);
    SeqPrint(&S);
}