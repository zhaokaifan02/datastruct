#include "sort.hpp"
void testInsertSort()
{
    int arr[10] = {9 ,1 ,2 ,5 ,7 ,4 ,8 ,6 ,3, 5};
    InsertSort(arr,10);
    ArrayPrint(arr,10);
}
void testBubbleSort()
{
    int arr[10] = {9 ,1 ,2 ,5 ,7 ,4 ,8 ,6 ,3, 5};
    BubbleSort(arr,10);
    ArrayPrint(arr,10);
}
void testShellSort()
{
    int arr[10] = {9 ,1 ,2 ,5 ,7 ,4 ,8 ,6 ,3, 5};
    ShellSort(arr,10);
    ArrayPrint(arr,10);
}
void testSelectSort()
{
    int arr[10] = {9 ,1 ,2 ,5 ,7 ,4 ,8 ,6 ,3, 5};
    SelectSort(arr,10);
    ArrayPrint(arr,10);
}
void testSelectISort()
{
    int arr[10] = {9 ,1 ,2 ,5 ,7 ,4 ,8 ,6 ,3, 5};
    SelectSort(arr,10);
    ArrayPrint(arr,10);
}
int main()
{
    testSelectISort();
}
