#include "stack.hpp"

void StackInit(ST* ps)
{
    assert(ps);
    ps->a=NULL;
    ps->top=0; //栈顶的后一个位置，下一个要放的地方top++;先放后++
    //栈顶的前一个文职，++top，先++后放
    ps->capacity =0;
}

void StackPush(ST* ps,STDataType val)
{
    //top下一个要放的地方
    if(ps->top>=ps->capacity)
    {
        int newCapacity = ps->capacity==0?4:2*ps->capacity;
        STDataType* t = (STDataType*)realloc(ps->a,sizeof(STDataType)*newCapacity);
        if(t==NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = t;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = val;
    ps->top++;
}
void StackPop(ST *ps)
{
    assert(ps);
    if(ps->top<=0)
    {
        printf("stack empty\n");
        return;
    }
    ps->top--;
}

bool StackEmpty(ST *ps)
{
    assert(ps);
    return ps->top==0;
}

STDataType StackTop(ST *ps)
{
    assert(ps);
    if(ps->top<=0)
    {
        printf("stack empty\n");
        return -1;
    }
    return ps->a[ps->top-1];
}

void StackDestroy(ST *ps)
{
    free(ps->a);
    ps->a=NULL;
    ps->top = 0;
    ps->capacity = 0;
}