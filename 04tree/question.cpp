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