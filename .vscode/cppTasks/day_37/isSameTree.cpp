#include <bits/stdc++.h>
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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        vector<int> a, b;
        bs(p, a);
        bs(q, b);
        return a == b;
    }
    void bs(TreeNode *p, vector<int> &a)
    {
        if (!p)
        {
            a.push_back(-1);
            return;
        }
        a.push_back(p->val);
        bs(p->left, a);
        bs(p->right, a);
    }
};
int main()
{
    Solution obj;

    return 0;
}