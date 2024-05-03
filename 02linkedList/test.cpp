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

