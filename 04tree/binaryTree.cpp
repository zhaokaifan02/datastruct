#include "binaryTree.hpp"

BTNode *BuyBTNode(BTDataType val)
{
    BTNode *t = (BTNode *)malloc(sizeof(BTNode));
    if (t == NULL)
    {
        printf("malloc fail");
        exit(-1);
    }
    else
    {
        t->val = val;
        t->left = t->right = NULL;
        return t;
    }
}
BTNode *CreateTree()
{
    BTNode *A = BuyBTNode(1);
    BTNode *B = BuyBTNode(2);
    BTNode *C = BuyBTNode(3);
    BTNode *D = BuyBTNode(4);
    BTNode *E = BuyBTNode(5);
    BTNode *F = BuyBTNode(6);
    A->left = B;
    B->left = C;
    A->right = D;
    D->left = E;
    D->right = F;
    return A;
}

void BTInit(BTNode *pr)
{
}

void PrevOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", root->val);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

void PrevOrderStack(BTNode *root)
{
    // 模拟函数栈帧
    assert(root);

    stack<BTNode *> s;
    BTNode *current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            printf("%d ", current->val); // 先序遍历的操作
            s.push(current);
            current = current->left;
        }

        if (!s.empty())
        {
            current = s.top();
            s.pop();
            current = current->right;
        }
    }
}

void InOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

void PostOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->val);
}

int BTreeSize(BTNode *root)
{
    if(root==NULL)
        return 0;
    
    //左树节点个数+右数节点个数
    return 1+BTreeSize(root->left)+BTreeSize(root->right);
    //分治要求一个总数，分成求左子树的个数和右子树的个数。然后不断分
    //把复杂的问题，分成更小规模的子问题，子问题再分成更小规模的子问题。子问题不可再分割得出结果
}

int BTreeLeafSize(BTNode* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

int BTreeLevelSize(BTNode *root, int k)
{
    if(root==NULL)
        return 0; //空的话返回0
    if(k==1)
        return 1; //k等于1的话第一层一定为1
    //k大于1的话，等价于求左子树的第k-1层+右子树的k-1层
    return BTreeLevelSize(root->left,k-1)+BTreeLevelSize(root->right,k-1);
}

//深度
int BTreeDepth(BTNode* root)
{
    //空树高度是0
    if(root==NULL)
        return 0;
    
    int left = BTreeDepth(root->left);
    int right = BTreeDepth(root->right);
    return left>right?1+left:1+right;
}

BTNode *BTreeFineNode(BTNode *root, int val)
{
    if(root==NULL)
        return NULL;
    if(root->val==val)
        return root;
    BTNode* left =BTreeFineNode(root->left,val);
    BTNode* right = BTreeFineNode(root->right,val);
    if(left!=NULL)
        return left;
    if(right!=NULL)
        return right;
    return NULL;
}
