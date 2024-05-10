#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int HPDataType;

typedef struct Heap
{
    HPDataType* a; 
    size_t size;
    size_t capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void AdjustUp(HPDataType* a, size_t child);
void AdjustDown(HPDataType *a, size_t size, size_t root);
void Swap(HPDataType* pa, HPDataType* pb);
void HeapPrint(HP* php);

//插入val以后，依旧是堆
void HeapPush(HP* php, HPDataType val);
//删除堆有继续是堆，对于小根堆pop就是拿顶把最小的数拿出来

void HeapPop(HP* php);
bool HeapEmpty(HP* php);
int HeapTop(HP* php);
size_t HeapSize(HP* php);

//复杂度 NlogN
//入堆和出堆地时间复杂度都是logN //对N个元素进行入堆出堆操作
void HeapSort(int* a, int size);