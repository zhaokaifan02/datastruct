#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STDataType int


typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps,STDataType val);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);
STDataType StackTop(ST* ps);