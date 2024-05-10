#include "heap.hpp"

void HeapInit(HP *php)
{
    assert(php);
    // free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}
void HeapPrint(HP *php)
{
    assert(php);    
    for (size_t i = 0; i <(php->size); i++)
    {
        printf("%d ", php->a[i]);
    }
    printf("\n");
}
void Swap(HPDataType *pa, HPDataType *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}
void AdjustUp(HPDataType *a, size_t child)
{
    // 每个根都是他说在当前的那棵树里最小的
    // 小根堆向上调整完后，目前头是最小的
    size_t parent = (child - 1) / 2;
    while (child > 0) // child等于0时就到根了
    {
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break; // 不换说明调整结束了
    }
}
void HeapPush(HP *php, HPDataType val)
{
    // 插入的时候影响的是他的祖先，如果比父亲小，就向上调整。然后依次调整直到比父亲小。
    assert(php);
    if (php->size == php->capacity)
    {
        int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
        HPDataType *t = (HPDataType *)realloc(php->a, sizeof(HPDataType) * newCapacity);
        if (t == NULL){
            printf("realloc fail\n");
            exit(-1);
            
        }
        else{
            php->capacity = newCapacity;
            php->a = t;
        }
    }

    // 尽可能地不影响其他结构
    php->a[php->size] = val;
    php->size++;
    // 开始向上调整
    AdjustUp(php->a, php->size - 1); // 这里的堆就确认出来了
}

void AdjustDown(HPDataType *a, size_t size, size_t root)
{
   
    size_t parent = root, leftChild = parent * 2 + 1,rightChild;
    while (leftChild < size)
    {
         // 找到左右孩子中小的那个
        rightChild = leftChild+1<size?leftChild+1:leftChild;
        leftChild = a[leftChild]<a[rightChild]?leftChild:rightChild;//很帅地技巧 
        // if(leftChild+1<size && a[leftChild+1]<a[leftChild])
        //     leftChild++;// 也是一个很帅拿较小child地技巧
        if(a[leftChild]<a[parent])
        {
            Swap(&a[leftChild],&a[parent]);
            parent = leftChild;
            leftChild = parent*2+1;
        } else 
            break;
    }
    // 和父亲比，比父亲小交换
    // 交换位置变成新的父亲
}
void HeapPop(HP *php)
{
    assert(php);
    if (php->size <= 0)
    {
        printf("heap Empty\n");
        return;
    }
    // 根与最后一个位置进行交换
    int t = php->a[0];
    Swap(&php->a[0], &php->a[php->size - 1]);

    // 删除最后一个数据
    --php->size;
    // 向下调整算法 
    AdjustDown(php->a,php->size,0);
}

bool HeapEmpty(HP* php)
{
    assert(php);
    return php->size==0;
}

int HeapTop(HP* php)
{
    assert(php);
    if(php->size==0)
    {
        printf("Heap Empty\n"); 
        return -1;
    }
    return php->a[0];
}
size_t HeapSize(HP* php)
{
    return php->size;
}

void HeapSort(int* a, int size)
{
    HP hp;
    HeapInit(&hp);
    for(int i = 0;i<size;i++)
    {
        HeapPush(&hp,a[i]);
        printf("insert: %d  ", a[i]);
        HeapPrint(&hp);
    }
    size_t j = 0;
    while(!HeapEmpty(&hp))
    {
        a[j] = HeapTop(&hp);
        j++;       
        HeapPop(&hp);
        printf("pop: %d  ", a[j-1]);
        HeapPrint(&hp);
    }
}