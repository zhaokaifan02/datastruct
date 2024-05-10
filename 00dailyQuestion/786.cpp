#include <stdlib.h>
#include <vector>
using namespace std;

// We need to find the kth smallest fraction formed by dividing elements at different indices of a sorted array containing only 1 and prime numbers. The task is to return an array of two elements representing the numerator and denominator of the kth smallest fraction.

// 1 2 3 5
// 0.5
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    double l = 0, r = 1.0;
    while (l < r)
    {
        // 二分开始
        double mid = 0.5;
        double max_f = 0.0;
        int total = 0;
        int j = 1;
        int p=0,q=0;
        for (int i = 0; i < arr.size() - 1; ++i) // 选择    分子
        {
            while (j < arr.size() && arr[i] > mid * arr[j]) // 这是个扫描板子
                ++j;                                        // 对于一个固定下来的分子，找到那个坟墓，使得分数 arr[i]/arr[j] <=mid //这样的话这个分母后面的所有分母构成的分数都小于mid
            total += (arr.size() - j);                      // 这一行构成的分数，小于mid的个数
            if (j == arr.size())
                break; // 扫到底了，就结束
            const double f = static_cast<double>(arr[i] / arr[j]);
            if (f > max_f)
            {
                p = i;
                q = j; //记录分子分母
                max_f = f; //记录当前最大值
            }
        }
        if(total == k) //看看是否是拿到的分数个数正好k个
            return  {arr[p],arr[q]};
        else if(total>k) //拿多了，真实的比mid大，这次的要小，所以右变小
            r=mid;
        else 
            l = mid; 
    }
    return {};
}

// 二分查找 binary search
// 在一个有序序列中，查找某一个东西
//  1 2 3 4 5 6 7 8 9 10查7 第一步拿到中间 0 + 9 /2 = 4
//  a[4] = 5 <7 prev = 4 head = 9 mid = 4+9 = 6
//  a[6] = 7 ==7 查到返回mid

// 二分查找查倒数第k个
// 1 2 3 4 5 6 7 8 9 10 查倒数第2个
// mid = 4; a[4] = 5 比5大的有 6 7 8 9 10 不是
// mid = 4+9 = 6; a[6] = 7 比7大的有 8 9 10 3个不是
// mid = 6 +9/2 = 7; a[7] = 8,比8大两个 不是
// mid = 7 + 9/2 = 8; a[8] = 9 比9大1个是
