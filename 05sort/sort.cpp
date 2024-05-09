#include "sort.hpp"
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void ArrayPrint(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void InsertSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        // 0 - end-有序，现在是把end插进去
        int end = i;
        int temp = a[end];
        while (end >= 0)
        {
            if (temp < a[end - 1])
            {
                a[end] = a[end - 1];
                --end;
            }
            else
            {
                a[end] = temp;
                break;
            }
        }
    }
}

void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool exchange = false;
        for (int j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                exchange = true;
                Swap(&a[j - 1], &a[j]);
            }
        }
        if (!exchange)
            break; // 没交换过说明已经有后续了直接停止
    }
}

void ShellSort(int *a, int n)
{
    // 预排序 当gap==1的时候，就是一般插入排序
    // 同理我们可以对原始的insertSort加一个gap
    // gap不能给一个固定地址，
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1; // 确保最后是1
        for (int i = gap; i < n; i++)
        {
            // 每次拿到的是要插入的后一个
            int end = i;
            int temp = a[end];
            while (end - gap >= 0)
            {
                if (temp < a[end - gap])
                {
                    a[end] = a[end - gap];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end] = temp;
        }
    }
}

void SelectSort(int *a, int n)
{
    int end = n - 1;
    while (end >= 0)
    {
        int p = 0;//当前最大值的下标
        for (int i = 0; i <=end; ++i)
        {
            if (a[p] < a[i])
                p = i;
        }
        Swap(&a[p], &a[end]);
        end--;
    }
}
void SelectSortImprove(int *a ,int n)
{
    //改良了同时找最小和最大
    int end = n-1;
    int head = 0;
    while(head<end)
    {
        int small = head,big = end;
        for(int i = head;i<=end;i++)
        {
            if(a[small]>a[i])
                small = i;
            if(a[big]<a[i])
                big = i;
        }
        Swap(&a[small],&a[head]);
        Swap(&a[big],&a[end]);
        end--;
        head++;
    }
}