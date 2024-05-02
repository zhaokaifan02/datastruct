#include "seqList.hpp"
#include <stdlib.h> 
#include <stdio.h>
#include <assert.h>
void SeqListInit(SeqList* psl)
{
    assert(psl);
    psl->a = nullptr;
    psl->size = 0;
    psl->capacity = 0;
}
void SeqListDestroy(SeqList* psl)
{
    assert(psl);
    free(psl->a);
    psl->size=0;
    psl->capacity = 0;
}
void SeqPrint(SeqList* psl)
{
    assert(psl);
    for(int i = 0;i<psl->size;i++)
    {
        printf("%d ", psl->a[i]);
    }
    printf("\n");
}


void SeqListPushBack(SeqList* psl,SLDataType val)
{
    assert(psl);
    //尾插
    //越界判断
    if(psl->size<=psl->capacity) //等号是因为一开始都是0
    {
        //越界了扩容  malloc    
        size_t newCapacity = psl->capacity==0?4:psl->capacity*2;
        SLDataType* tmp = (SLDataType*)realloc(psl->a,sizeof(SLDataType)*newCapacity); 
        //realloc (指向内存的指针，调整后新的大小) 如果当前内存美满就后面，放不下就另起一行。 最后要转成自己的数据类型 
        //原地扩效率高，后面不够用就在连续的重新开，有复制的过程，效率慢了
        //如果第一个参数是null，相当于malloc 开内存
        if(tmp==nullptr)
        {
            printf("realloc fail\n");
            return;
        }else{
            psl->a = tmp;
            psl->capacity = newCapacity;
        }
    }
    //不越界的情况
    psl->a[psl->size++] = val; 
}

void SeqListPopBack(SeqList *psl)
{  
    assert(psl);
    if(psl->size==0)
    {
        printf("seqList empty\n");
        return;
    } else 
    {
        psl->size--; //不需要删除完
    }
    
}


void seqListPushFront(SeqList *psl,SLDataType val)
{
    if(psl->size>=psl->capacity)
    {
        int newCapacity = psl->capacity==0?4:2*psl->capacity;
        SLDataType* tmp = (SLDataType*)realloc(psl->a,sizeof(SLDataType)*newCapacity);
        if(tmp!=nullptr)
        {
            psl->a = tmp;
            psl->capacity = newCapacity;
        } else {
            printf("realloc fail\n");
            return;
        }
    }
    //整型提升
    /*
    int end =  -1;
    size_t pos = 0;
    if(end>=pos) //会向上提升 int提升到size_t
    {
        end -1的机器码是 111111111全1，提升到无符号就说 2^n-1特别大，所以返回true
        或者书11111111比00000000在二进制上更大 比较器
    }
    */
    //开始插入
    
    for(int i = psl->size;i>0;i--)
    {
        psl->a[i] = psl->a[i-1];
    }
    psl->a[0] =val;
    psl->size++;
    
}

void seqListPopFront(SeqList* psl)
{
    if(psl->size<0)
    {
        printf("list empty\n");
        return;
    }
    SLDataType head = psl->a[0];
    for(int i = 0;i<psl->size-1;i++)
    {
        psl->a[i] = psl->a[i+1];
    }
    psl->size--;
}

void seqListInsert(SeqList* psl, int index,SLDataType val)
{
    assert(psl); //暴力检查 为假终止程序并报错
    if(psl->size>=psl->capacity)
    {
        int newCapacity = psl->capacity==0?4:psl->capacity*2;
        SLDataType* tmp = (SLDataType*)realloc(psl->a,sizeof(SLDataType)*newCapacity);
        if(tmp==nullptr)
        {
            printf("realloc error\n");
            return;
        } else 
        {
            psl->a = tmp;
            psl->capacity = newCapacity;
        }
    }
    if(index>psl->size)
    {
        printf("index over\n");
        return ;
    }
    //开始新增
    for(int i = psl->size;i>index ;i--)
    {
        psl->a[i] = psl->a[i-1]; //依次往后放
    }
    psl->a[index] = val;
    psl->size++;
}

void seqListErase(SeqList* psl, int index)
{
    assert(psl);
    if(psl->size==0)
    {
        printf("list empty\n");
        return;
    }
    if(index>psl->size-1)
    {
        printf("index over\n");
    }
    SLDataType val = psl->a[index];
    //for 形式
    /*
    for(int i = index;i<psl->size-1;i++)
    {
        psl->a[i] = psl->a[i+1];
    }
    psl->size--;
    */
    //while 形式
    int begin = index;
    while(begin<psl->size-1)
    {
        psl->a[begin] = psl->a[begin+1];
        begin++;
    }
    psl->size--;
}   

int seqListFind(SeqList* psl, SLDataType val)
{
    int index = -1;
    for(int i = 0;i<psl->size;i++)
    {
        if(psl->a[i]==val)
        {
            index = i;
            return index;
        }
    }
    return index;
}