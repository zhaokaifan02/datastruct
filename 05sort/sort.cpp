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



int Quick_Sort(int* a, int start,int end)
{

    int key = start; //左边是key
    int left = start;
    int right = end;
    while(left<right)
    {
        //右边找小
        while(left<right && a[right]>=a[start]) //找小，这种递归式的
        {
            --right;
        }
        //要带等号，原因在于如果left和right都等于key的话，就会死循环
        //left<right有两个作用
        //1. 防止right--越界
        //2. 确保是left撞的right，保证right是里存的是left上一次换过来的小的，从而保证key换到a[0]里是小的
        //左边找大
        while(left<right && a[left]<=a[start])
        {
            ++left;
        }
        Swap(&a[left],&a[right]);
    }
    Swap(&a[key],&a[left]); //这里left等于right，排完后放到正确的位置
    return left; //key的洗标返回来
}
int PartSort2(int* a, int start,int end)
{
    int key = a[start]; //坑
    int pit = start;
    int left = start,right = end;
    while(left<right)
    {
        //找小
        while(left<right&&a[left]>=key)
        {
            --left;
        }
        a[pit] = a[right];
        pit = a[right];
        //空变成这个小的位置
        while(left<right&&a[left]<=right)
        {
            ++right;
        }
        //找一个大的填成小
        a[pit] = a[left];
        pit = left;
    }
    a[pit] = key; //最后剩下的坑就是key的位置
    return left;
}
int PartSort3(int* a, int start,int end)
{
    //前后指针法
    int key = a[start];
    int cur = start+1;
    int prev = start;
    while(cur<=end)
    {
        while(cur<=end&&a[cur]>=key)
        {
            cur++;
            prev++; //往后直到cur<key，找到一个小的
        }
        
        
    }

}
void QuickSort(int *a, int begin,int end)
{
//快速排序
    if(begin>=end) //子区间为空或者子区间只有一个时，递归结束
        return; //左边大于右边一定报错
    int key = Quick_Sort(a,begin,end);
    QuickSort(a,begin,key-1); //左边快排
    QuickSort(a,key+1,end); //右边快排
}

void QuickSort(int *a, int n)
{
    QuickSort(a,0,n-1);
}
