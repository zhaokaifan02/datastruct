#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//965. Univalued Binary Tree
//A binary tree is uni-valued if every node in the tree has the same value.

//Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.


bool checkVal(struct TreeNode* root, int val)
{
    if(root==NULL)
        return true;
    if(root->val==val)
    {
        return checkVal(root->left,val)&&checkVal(root->right,val);
    }
    return false;
}
bool isUnivalTree(struct TreeNode *root)
{
    if(root==NULL)
        return true;
    
    return checkVal(root,root->val);
}
//100 Same Tree
//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //同时为空或在不同时为空
    if(p==NULL &&q==NULL) 
        return true;
    if(p==NULL || q==NULL)
        return false;
    //根是否相同
    if(p->val!=q->val)
        return false;
    //左右子树是否相同
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

//101. Symmetric Tree

bool checkSymmetric(struct TreeNode* p,struct TreeNode* q)
{
    //两个树都为空
    if(p==NULL&&q==NULL)
        return true;
    //有一个为空 false
    if(p==NULL || q==NULL)
        return false;
    //不等 false
    if(p->val!=q->val)
        return false;
    //看看p的左树等不等q的右树，p的右树等不等q的左数 
    return checkSymmetric(p->left,q->right)&&checkSymmetric(p->right,q->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
        return true;
    return checkSymmetric(root->left,root->right);
}

//572. Subtree of Another Tree
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root==NULL || subRoot==NULL)
        return false;
    if(isSameTree(root,subRoot)) //如果这个root所在的树和subRoot相同
        return true;
    //左边有没有sub的，右边有没有sub的
    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}

//最小深度 到叶子节点的最短距离
//111. Minimum Depth of Binary Tree
//Given a binary tree, find its minimum depth
int minDepth(struct TreeNode* root) {
    if(root==NULL)
        return 0;
    if(root->left==NULL &&root->right==NULL)
        return 1;
    //这里要判断，如果不是节点且为空的话默认为最大实现一个截断
    int minLeft=INT_MAX,minRight=INT_MAX;
    if(root->left)
        minLeft = minDepth(root->left);
    if(root->right)
        minRight = minDepth(root->right);
    return minLeft>minRight?minRight+1:minLeft+1;
}


//222. Count Complete Tree Nodes
//Given the root of a complete binary tree, return the number of the nodes in the tree.

//According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


//536 
//读入一个先序遍历字符串，长度不超过100，通过字符串构建一颗树。
//并输出他的中序遍历 

struct BTNode {
    char data;
    struct BTNode* left;
    struct BTNode* right;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BTNode {
    char data;
    struct BTNode* left;
    struct BTNode* right;
};
BTNode* BinaryTreeCreate(char* a, int n, int* pi){
    //N控制的是这个数组的长度
    if(a[*pi]=='#') {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->data = a[*pi];
    (*pi)++;
    root->left = BinaryTreeCreate(a,n,pi);
    root->right = BinaryTreeCreate(a,n,pi);
    return root;
}
void Inorder(BTNode * root) {
    if(root==NULL) {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}

     