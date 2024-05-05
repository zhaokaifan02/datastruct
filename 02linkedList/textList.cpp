#include "List.hpp"
void Test1()
{
    LTNode *head;
    ListInit(&head);
    ListPrint(head);
    ListPushBack(head,1);
    ListPushBack(head,2);
    ListPushBack(head,3);
    ListPushBack(head,4);
    ListPushBack(head,5);
    ListPrint(head);
    ListPopBack(head);
    ListPrint(head);
}
void Test2()
{
    LTNode *head;
    ListInit(&head);
    ListPrint(head);
    ListPushFront(head,5);
    ListPushFront(head,4);
    ListPushFront(head,3);
    ListPushFront(head,2);
    ListPushFront(head,1);
    ListPrint(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPrint(head);
    ListPopBack(head);
    ListPrint(head);
}
int main()
{
    LTNode *head;
    ListInit(&head);
    ListPrint(head);
    ListPushFront(head,5);
    ListPushFront(head,4);
    ListPushFront(head,3);
    ListPushFront(head,2);
    ListPushFront(head,1);
    ListPrint(head);
    ListInsert(head,ListFind(head,2),99);
    ListPrint(head);
    ListErase(head,ListFind(head,1));
    ListPrint(head);
}