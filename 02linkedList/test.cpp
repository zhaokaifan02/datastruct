#include "stdio.h"
#include "stdlib.h"
#include "SList.hpp"

 struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = head;
    //为空的情况
    if(p==NULL)
        return p;
    while(p->next!=NULL)
    {
        //先不看第一个
        if(p->next->val == val)
        {
            p->next = p->next->next;
        } else
        {
            p = p->next;
        }
        
    }
    //检查第一个
    if(head->val ==val)
    {
        return head->next;
    } else {
        return head;
    }
}


//206. Reverse Linked List
//Given the head of a singly linked list, reverse the list, and return the reversed list.
//三指针处理边界问题的一个思路
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* p = head->next;
    struct ListNode* pre=head, *pos =NULL;
    while(p->next!=NULL)
    {
        pos = p->next;
        p->next = pre;
        pre = p;
        p = pos;
    }
    p->next = pre;
    return p;
}

//876 Middle of the Linked List
//Given the head of a singly linked list, return the middle node of the linked list.

//If there are two middle nodes, return the second middle node.

//快慢指针
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode*fast = head;
    struct ListNode* slow = head;
    if(slow->next==NULL)
        return slow;
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=NULL)
            fast = fast->next;
    }
    return slow;
}

//倒数第K个
//很简单的倒数第k个，双指针开始走
int kthToLast(struct ListNode* head, int k){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(k!=0)
    {
        if(fast==NULL) //k大于length的时候
            return -1;
        fast = fast->next;
        k--;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}
// 19 Remove Nth Node From End of List
//比较看思路
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast,*slow;
    fast = slow = head;
    n++;
    if(fast->next==NULL)
    {
        return head->next;
    } //只有一个直接排
    while(n!=0)
    {//快慢指针
        if(fast==NULL)
            return head->next; //删除第一个的情况
        fast = fast->next;
        n--;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; //删除最后一个
    return head;
}

//1721 Swapping Nodes in a Linked List
//交换倒数第k个和
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* p,*fast,*slow;
    fast = slow = head;
    while(k--)
    {
        p = fast;
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    int t = p->val;
    p->val = slow->val;
    slow->val = t;
    return head;
}

//21 Merge Two Sorted Lists
//You are given the heads of two sorted linked lists list1 and list2.

//Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

//Return the head of the merged linked list.
//思路：创建一个头，用来操作 手动创一个头出来 //哨兵节点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL||list2==NULL)
        return list1==NULL?list2:list1; 
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* p1 = list1,*p2 = list2,*p=head;
    while(p1!=NULL &&p2!=NULL)
    {
        if(p1->val<=p2->val)
        {
            p->next=p1;
            p=p->next;
            p1=p1->next;
        } else {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
    }
    //p1 = p1?p2:p1; //p1不是空的话p2,是空p1
    p1 = p1==NULL?p2:p1; //很巧妙的处理
    
    while(p1!=NULL)
    {
        p ->next = p1;
        p = p->next;
        p1 = p1->next;
    }
    return head->next;
}
//148 
//Given the head of a linked list, return the list after sorting it in ascending order. ascending 上升的
//分治思想 divide-conquer 


//86. Partition List
//分离最大值最小值
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions
//什么时候要哨兵位，对头进行大量的处理时哨兵位好用
//极端情况，所有的值都比x小。所有值都比x大。最后一个值比x小，最后一个值比x大。
//极端情况走读代码
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = NULL;
    struct ListNode*p1=head,*great = newhead, *less =newhead,*t;
    while(p1!=NULL)
    {
        if(p1->val<x)
        {
            t = p1->next; //做拼接用的 //发现这个情况
            p1->next = less->next;
            less->next = p1;
            p1= t;
            if(great==less)
            {
                great = less->next;
            }
            less = less->next;
            //great 
        } else {
            t=p1->next;
            great->next = p1;
            p1->next=NULL;
            p1 = t;
            great = great->next;
        }
    }
    return newhead->next;
}
//9 Palindrome Number
//Given an integer x, return true if x is a palindrome, and false otherwise.
//利用while提取数字
bool isPalindrome(int x) {
    if(x<0)
        return false;
    long int x1 = 0;
    long int s = x;
    while(x>0)
    {
        x1*=10; //往前挪一位
        x1+=x%10; //最后一位补上
        x/=10; //拿到x的第一位
    }
    return s==x1;
}

//234 Palindrome Linked List
//Given the head of a singly linked list, return true if it is a 
//palindrome or false otherwise. 
//回文链表 1 2 2 1这种，这个很好办，找到中间，然后逆转便利就行。找中间用n。



struct ListNode* myReverse(struct ListNode* head)
{
    if(head==NULL ||head->next==NULL)
        return head;
    struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
    t->next=NULL;
    struct ListNode* pre,*p,*post;
    pre = head;
    p = head->next;
    while(p->next!=NULL)
    {
        post = p->next;
        p->next= pre;
        pre = p;
        p = post;
    }
    p->next = pre;
    head->next = NULL;
    return p;
}
bool isPalindrome(struct ListNode* head) {
    if(head==NULL ||head->next==NULL)
        return true;
    struct ListNode* fast=head,*slow=head,*p=head;
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=NULL)
        {
            fast = fast->next;
        }
    }
    slow = myReverse(slow);
    while(slow!=NULL&&p!=NULL)
    {
        if(slow->val!=p->val)
        {
            return false;
        }
        slow= slow->next;
        p = p->next;
    }
    return true;
}

//160 Intersection of Two Linked Lists
//链表交点
//本质上还是求出他们两个相交后的差，让长的先走他们两个的差
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1=headA,*p2 = headB;
    bool pt1=false,pt2=false;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1==p2)
            return p1;
        p1=p1->next;
        p2=p2->next;
        if(p1==NULL && !pt1){
            p1 = headB;
            pt1 = true;
        }
        if(p2==NULL && !pt2)
        {
            p2 = headA;
            pt2 = true;
        }
    }
    return NULL;
}

//141 Linked list cycle
bool hasCycle(struct ListNode *head) {
    if(head==NULL)
        return false;
    struct ListNode *slow,*fast;
    slow = fast = head;
    while(slow->next!=NULL &&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==NULL)
            break;//走完了直接报错
        if(slow==fast)
            return true;
    }
    return false;
}
// 142. Linked List Cycle II
//返回环的开始点
//数学推导slow x. fast kx
//设环长为R，环前为L 设相遇时走的距离为r
//有slow走的距离为 L+r； fast走的距离为L+nR+r //slow进环前fast可能已经转了n圈了
//相同时间，所以fast走的距离时slow的k被 k(L+r) = L+nR+r
//(k-1)L + (k-1)r = nR; n>=1 
//另k = 2；有L+r = nR  因为slow在里面走不到一圈，所以0<r<R 所以L = nR -R +p
//L = (n-1)R+p p为相遇点到入环点的距离，所以直接走就行
//所以有一个点从起点走，另一个点从碰到走，相遇的地方就是对应点
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL)
        return head;
    struct ListNode *slow,*fast,*p = head;
    slow = fast = head;
    while(slow->next!=NULL &&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==NULL)
            break;//走完了直接报错
        if(slow==fast)
        {
            while(p!=slow)
            {
                p=p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}

//287. Find the Duplicate Number
//找到一个数组中重复的数字
//数组是 有n+1个元素，每个元素为1-n
//思考：这东西不就是一个没有元素data的链表,把数组的值看成地址地址
// [1,3,4,2,2] //n+1个元素，每个元素是n 
//0->1->3->2->4->2->4->2 这就有环了
//这就和上面142一样,找环，如果有环在反过来走
//因为题目说了有n+1个元素，每个元素为1-n,说明一定有重复的抽屉原理
int findDuplicate(int* nums, int numsSize) {
    int fast = 0;
    int slow = 0;
    while(true)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if(fast==slow)
            break;
    }
    int p = 0;
    while(p!=slow)
    {
        p = nums[p];
        slow = nums[slow];
    }
    return p;
}
//237 Delete Node in a Linked List
//没有头节点的前提下，删除当前节点
void deleteNode(struct ListNode* node) {
    //not a tail
    struct ListNode* p =node,*p1 = node->next;
    int t = p ->val;
    p->val = p1->val;
    p1->val = t;
    p->next = p1->next;
    free(p1);
    //比较激进的思路
    // struct ListNode* p =node,*p1 = node->next;
    // p->val = p->next->val;
    // p->next = p->next->next; 


}
//138 copy List with a random Pointer
//顺藤摸瓜
 struct Node {
      int val;
      struct Node *next;
     struct Node *random;
 };
struct Node* copyRandomList(struct Node* head) {
	struct Node* p = head;
    //第一遍辅助添加一个node
    while(p!=NULL)
    {
        struct Node* newCode = (struct Node*)malloc(sizeof(struct Node));
        newCode->val = p->val;
        newCode->next = p->next;
        p->next = newCode;
        p = newCode->next; //插入N1和N2中间
    }
    struct Node* cur = head,*pos;
    //顺藤摸瓜，相对位置不变
    while(cur!=NULL)
    {
        pos = cur->next;  
        pos->random = cur->random==NULL?NULL:cur->random->next;
        cur=pos->next;
        pos->next = cur==NULL?NULL:cur->next;
    }
    return head->next;

}
int main()
{
    SListNode *phead = nullptr;
    SListPrint(phead);
    SListPushBack(&phead, 1);
    SListPushBack(&phead, 2);
    SListPushBack(&phead, 3);
    SListPrint(phead);
    SListPopBack(&phead);
    SListPrint(phead);
    SListPushFront(&phead,0);
    SListPushFront(&phead,-1);
    SListPrint(phead);
    SListPopFront(&phead);
    SListPrint(phead);

    SListNode* pos =SListFind(phead,2);
    if(pos)
    {
        printf("find!\n");
    }
    pos->data = 3;//可以修改
    SListPrint(phead);
    SListInsert(&phead,pos,99);
    SListPrint(phead);
    SListNode* pos1 =SListFind(phead,0);
    SListInsertAfter(phead,pos1,12);
    SListPrint(phead);

    SListErase(&phead,SListFind(phead,3));
    SListPrint(phead);
    SListDestroy(&phead);
    SListPrint(phead);
}

