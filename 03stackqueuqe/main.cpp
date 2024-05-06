// #include "stack.hpp"
// 20 Valid Parentheses
/**
 * 
*/
// void testStack()
// {
//     ST st;
//     StackInit(&st);
//     StackPush(&st, 1);
//     StackPush(&st, 2);
//     StackPush(&st, 3);
//     StackPush(&st, 4);
//     while (!StackEmpty(&st))
//     {
//         printf("%d ", StackTop(&st));
//         StackPop(&st);
//     }
//     StackDestroy(&st);
// }


#include <stdio.h>
#define MAX_DATA 5

typedef struct stack{
    char arr[MAX_DATA];
    int top;
} STACK;

void init_stack(STACK *stk)
{
    for(int i = 0;i<MAX_DATA;i++) stk->arr[i] = '?';
    stk->top = -1;
}
int push(STACK *stk, char input)
{
    printf("push: %c\n",input);
    if(stk->top==MAX_DATA-1)
    {
        printf("This Stack is full\n");
        return 0;
    } else {
        stk->arr[++stk->top] =input;
        return 1;
    }
}

char pop(STACK *stk)
{
    if(stk->top<0)
    {
        printf("no data\n");
        return '\0';
    } else {
        int top = stk->arr[stk->top];
        stk->arr[stk->top--] = '?';
        printf("pop: %c\n",top);
        return top;
    }
}

void show_stack(STACK *stk)
{
    printf("STACK: ");
    for(int i = 0;i<MAX_DATA;i++) printf("%c ", stk->arr[i]);
    printf(", top: %d\n", stk->top);
}

int check_brackets(STACK* stk, char* data)
{
    init_stack(stk);
    char top;
    printf("\ncheck: %s\n",data);
    for(int i = 0;data[i]!='\0';i++)
    {
        printf("input: %c ", data[i]);
        if(data[i]=='{'||data[i]=='[') push(stk,data[i]);
        else if(data[i]=='}'||data[i]==']')
        {
            top = pop(stk); //if is empty pop '/0'then line 99 will print no extra
            if(top=='{' && data[i]!='}' || top=='[' && data[i]!=']'){
                printf("'%c' cant be closed with '%c!' \n",top,data[i]);
                return 0;
            }
        } else
            printf("\n");
    }
    top=pop(stk);
    if(top=='\0') printf("no extra brackets!\n");
    else printf("have extra!\n");
    return 1;
}
int main()
{
    STACK stk;
    init_stack(&stk);
    show_stack(&stk);
    for(int i = 0;i<MAX_DATA+1;i++)
    {
        push(&stk,'a'+i);
        show_stack(&stk);
    }
    pop(&stk);
    show_stack(&stk);

    // check_brackets(&stk,"{[a]}");
    // check_brackets(&stk,"{[[a]}");
    // check_brackets(&stk,"{[a]}[");

    return 0;
}