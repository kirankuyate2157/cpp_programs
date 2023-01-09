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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        bs(root);
        return ans;
    }

    void bs(TreeNode *root)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        bs(root->left);
        bs(root->right);
    }
};

int main()
{

    return 0;
}