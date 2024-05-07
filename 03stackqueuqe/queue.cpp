#include "queue.hpp"

void QueueInit(Queue* pq)
{
    pq->head = NULL;
    pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType val)
{
    assert(pq);
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(!newNode)
        exit(-1);
    newNode->data = val;
    if(pq->tail!=NULL)
        pq->tail->next = newNode;
    else{
        pq->tail  = newNode;
        pq->head = newNode;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq);
    if(pq->head==NULL)
    {
        printf("queue empty\n");
        return;
    }
    QueueNode *dt = pq->head;
    //只有一个的情况
    if(pq->head==pq->tail)
    {
        pq->head=pq->tail = NULL;
    } else {
        pq->head = dt->next;
    }
    free(dt);
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head==NULL || pq->tail==NULL;
}

size_t QueueSize(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    size_t len = 0;
    while(cur!=NULL)
    {
        cur= cur->next;
        len++;
    }
    return 0;
}
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    if(QueueEmpty(pq)){
        printf("Queue Empty\n");
        return;
    }
    return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    if(QueueEmpty(pq)){
        printf("Queue Empty\n");
        return;
    }
    return pq->tail->data;
}