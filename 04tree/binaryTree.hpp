#include <vector>
#include "assert.h"
// #include <cassert>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

// struct TreeNode
// {
//     int data;
//     std::vector<struct TreeNode*> subs; // 顺序表依次存
// };

//存储树最优秀的方法
//左孩子右兄弟
// typedef int DataType;

// typedef struct TreeNode
// {
//    struct TreeNode* firstChild;
//    struct TreeNode* pNextBrother;
//    DataType data;
// };

//一个节点有多少孩子无所谓，只需要存第一个孩子，第一个孩子的兄弟指针连接第二个孩子
//这样两个指针就能全部标识出来了


typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//普通二叉树的增删查改没有意义，直接存数据不如线性表
//搜索二叉树，左子树比根小，右子树比根大，这样查找logn就找到了
//但是不平衡。平衡搜索二叉树 AVL树，红黑树等
BTNode* BuyBTNode(BTDataType val);
BTNode* CreateTree();
void BTInit(BTNode* pr); //初始化方便测试
//遍历二叉树
//前序遍历 先根遍历 根-左子树-右子树
void PrevOrder(BTNode* root);
void PrevOrderStack(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//层序遍历

//节点个数
int BTreeSize(BTNode* root);

//叶子节点个数
int BTreeLeafSize(BTNode* root);

//第k层的节点个数
int BTreeLevelSize(BTNode* root, int k);

int BTreeDepth(BTNode* root);

BTNode* BTreeFineNode(BTNode* root,int val);