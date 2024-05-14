#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//102. Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode *root)
{
    if(root==NULL)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    vector<vector<int>> ret;
    while(!q.empty())
    {
        int s = q.size();
        vector<int> a;
        for(int i = 0;i<s;i++)
        {
            a.push_back(q.front()->val);
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
            
        }
        ret.push_back(a);
    }
    return ret;
}

