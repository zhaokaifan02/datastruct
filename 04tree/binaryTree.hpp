#include <vector>
#include <stdlib.h>

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

