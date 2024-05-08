//622 Design Circular Queue 
#include "stdlib.h"
typedef struct {
    int *a;
    int head;
    int tail;
    int capacity;
} MyCircularQueue;
//空出来一个位置方便判断

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* t = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    int* ta = (int*)malloc(sizeof(int)*(k+1));
    t->a = ta;
    t->head = 0;
    t->tail = 0;
    t->capacity = k+1;
    return t;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if((obj->tail+1)%obj->capacity==obj->head)
        return false;
    obj->tail = (obj->tail+1)%obj->capacity;
    obj->a[obj->tail] = value;
    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->tail==obj->head)
        return false;
    obj->head = (obj->head+1)%obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->tail==obj->head)
        return -1;
    return obj->a[(obj->head+1)%obj->capacity];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->tail==obj->head)
        return -1;
    return obj->a[obj->tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->tail==obj->head;
}  

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail+1)%obj->capacity==obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->tail = obj->head=obj->capacity = 0;
}
int myCircularQueueSize(MyCircularQueue* obj)
{
    return (obj->tail-obj->head) %obj->capacity;
}
//len = tail-head%cap cap = k+1
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/