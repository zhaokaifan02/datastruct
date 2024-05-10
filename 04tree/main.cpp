#include "heap.hpp"
void testHeap()
{
    HP hp;
    // printf("5\n");
    HeapInit(&hp);
    // printf("6\n");
    HeapPush(&hp,10);  
    HeapPush(&hp,15); 
    HeapPush(&hp,19);   
    HeapPush(&hp,25); 
    HeapPush(&hp,18);
    HeapPush(&hp,34); 
    HeapPush(&hp,65);
    HeapPush(&hp,27);
    HeapPush(&hp,49);
    HeapPush(&hp,37);
    HeapPush(&hp,28);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
}
int main()
{
    int a[8] = {4,2,7,8,5,1,0,6};
    HeapSort(a,8);
    for(int i = 0;i<8;++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
