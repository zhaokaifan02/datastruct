#include "seqList.hpp"
void test()
{
    SeqList S;
    SeqListInit(&S);
    SeqListPushBack(&S, 1);
    SeqListPushBack(&S, 2);
    SeqListPushBack(&S, 3);
    SeqListPushBack(&S, 4);
    SeqListPushBack(&S, 5);
    SeqPrint(&S);
    SeqListPopBack(&S);
    SeqPrint(&S);
    seqListPushFront(&S, 0);
    seqListPushFront(&S, -1);
    SeqPrint(&S);

    seqListPopFront(&S);
    SeqPrint(&S);

    seqListInsert(&S, 3, 999);
    SeqPrint(&S);

    seqListErase(&S, 2);
    SeqPrint(&S);
}

// question
//  leetcode 27
/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

/*** Explanation
 * in-place means 原地的，不开辟空间
 */
int removeElement(int *nums, int numsSize, int val)
{
    // 首尾指针
    int begin = 0;
    int end = numsSize - 1;
    while (begin <= end)
    {
        // 等号是陷阱，要判断
        if (nums[begin] == val)
        {
            int t = nums[end];
            nums[end] = nums[begin];
            nums[begin] = t;
            end--;
        }
        else
        {
            begin++;
        }
    }
    return begin;
}

// leetcode 26 Remove Duplicates from Sorted Array
/**
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k=.
*/
int removeDuplicates(int* nums, int numsSize) {
    int pre = 0;
    int next = pre+1;
    while(next<numsSize)
    {
        if(nums[pre]==nums[next])
            next++;
        else if(nums[pre]!=nums[next]){
            nums[pre+1] = nums[next];
            pre++;
            next++;
        }
    }
    return pre+1;
}

//  88 merge sorted array
/**
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
//合并非递减数组 1 2 3 9 0 0 0 、、 2 5 6
// 1 memmove + sort NlogN
// 2. 归并，开开一个新数组，每次把小的往下放
// 3. in-place算法，本地放。不开额外数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //怎么思考临界的。两种情况，谁先空了两种情况
    int p1 = m-1;int p2 = n-1;
    int p = nums1Size-1;
    while(p1>=0&&p2>=0)
    {
        if(nums1[p1]<nums2[p2])
        {
            nums1[p] = nums2[p2];
            p--;
            p2--;
        } else {
            nums1[p] = nums1[p1];
            p--;
            p1--;
        }
    }
    //p1先结束
    if(p1<0)
    {
        for(int i = 0;i<=p2;i++)
        {
            nums1[i] = nums2[i];
        }
    }
}
//
int main()
{
    
    return 0;
}