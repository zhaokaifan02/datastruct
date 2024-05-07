#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//数组队列vs链式队列
//肯定链式啊。这种频繁尾插头删的，一个带头单向循环链表。就可以很丝滑的进行尾插头删
//或者记录一个尾指针，这样尾插就很方便了

typedef int QDataType;

//队列节点
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QNode;

//队列控制器
typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq,QDataType val);
void QueuePop(Queue* pq);
bool QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

